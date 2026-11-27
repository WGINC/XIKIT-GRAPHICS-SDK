// hotbar_core.cpp -- the hotbar's Windows side (Windows headers only; the tree's headers define some Windows names
// themselves): hotbar.txt, XIVhotbar2's job files, resource tables and keybinds, key state, images (WIC), the clock.
#include <windows.h>
#include <wincodec.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <sys/stat.h>
#include "hotbar_core.h"

extern "C" {
void hb_copy(char *dst, int n, const char *src) { if (n > 0) snprintf(dst, n, "%s", src ? src : ""); }
int hb_fmt(char *dst, int n, const char *fmt, ...) { va_list a; va_start(a, fmt); int r = vsnprintf(dst, n, fmt, a); va_end(a); return r; }
int hb_ieq(const char *a, const char *b) { return _stricmp(a, b) == 0; }
static int g_clock_add;                                              // (tests: hb_clock_add moves the clock on)
unsigned hb_now_ms(void) { return GetTickCount() + (unsigned)g_clock_add; }
extern "C" void hb_clock_add(int ms) { g_clock_add += ms; }
int hb_write_file(const char *dir, const char *name, const char *text) {
  char path[MAX_PATH]; snprintf(path, sizeof path, "%s\\%s", dir, name);
  FILE *f = fopen(path, "w"); if (!f) return 0;
  fputs(text, f); fclose(f); return 1;
}
}

// ---------------------------------------------------------------------------------------------------------- keys
static int vk_of(const char *k) {
  if (!k[0]) return 0;
  if (!k[1]) {
    char c = k[0];
    if (c >= '0' && c <= '9') return c;
    if (c >= 'a' && c <= 'z') return c - 32;
    if (c >= 'A' && c <= 'Z') return c;
    switch (c) { case '-': return VK_OEM_MINUS; case '=': return VK_OEM_PLUS; case '[': return VK_OEM_4; case ']': return VK_OEM_6;
                 case ';': return VK_OEM_1; case '\'': return VK_OEM_7; case ',': return VK_OEM_COMMA; case '.': return VK_OEM_PERIOD;
                 case '/': return VK_OEM_2; case '`': return VK_OEM_3; case '\\': return VK_OEM_5; }
    return 0;
  }
  if (!_stricmp(k, "eq")) return VK_OEM_PLUS;
  if ((k[0] == 'f' || k[0] == 'F') && k[1] >= '1' && k[1] <= '9') { int n = atoi(k + 1); if (n >= 1 && n <= 12) return VK_F1 + n - 1; }
  if (!_stricmp(k, "num0")) return VK_NUMPAD0;
  if (!_strnicmp(k, "num", 3) && k[3] >= '1' && k[3] <= '9' && !k[4]) return VK_NUMPAD0 + (k[3] - '0');
  return 0;
}
// "c-1", "a-s-f2", "1", "none"
static void parse_key(const char *s, HbKey *k) {
  memset(k, 0, sizeof *k);
  if (!_stricmp(s, "none") || !strcmp(s, "-") || !*s) return;
  while (s[0] && s[1] == '-' && s[2]) {
    switch (s[0] | 32) { case 'c': k->ctrl = 1; break; case 'a': k->alt = 1; break; case 's': k->shift = 1; break; default: return; }
    s += 2;
  }
  k->vk = vk_of(s);
  if (k->vk) snprintf(k->name, sizeof k->name, "%s%s%s%s", k->ctrl ? "^" : "", k->alt ? "!" : "", k->shift ? "+" : "", s);
}
// XIVhotbar2's (Windower's) form: "#1", "ALT + 1", "CTRL + SHIFT + EQ", "`"
static void parse_windower_key(const char *s, HbKey *k) {
  memset(k, 0, sizeof *k);
  char buf[64]; snprintf(buf, sizeof buf, "%s", s);
  char *last = nullptr, *tok = buf;                     // (split by hand: callers are inside strtok loops)
  while (tok) {
    char *nx = strchr(tok, '+'); if (nx) *nx++ = 0;
    while (*tok == ' ') tok++;
    char *e = tok + strlen(tok); while (e > tok && e[-1] == ' ') *--e = 0;
    if (!_stricmp(tok, "alt")) k->alt = 1; else if (!_stricmp(tok, "ctrl")) k->ctrl = 1; else if (!_stricmp(tok, "shift")) k->shift = 1;
    else if (*tok) last = tok;
    tok = nx;
  }
  if (!last) return;
  if (last[0] == '#') last++;
  k->vk = vk_of(last);
  if (k->vk) snprintf(k->name, sizeof k->name, "%s%s%s%s", k->ctrl ? "^" : "", k->alt ? "!" : "", k->shift ? "+" : "", !_stricmp(last, "eq") ? "=" : last);
}

extern "C" int hb_key_down(const HbKey *k) {
  if (!k->vk) return 0;
  if (!(GetAsyncKeyState(k->vk) & 0x8000)) return 0;
  int c = (GetAsyncKeyState(VK_CONTROL) & 0x8000) != 0, a = (GetAsyncKeyState(VK_MENU) & 0x8000) != 0,
      s = (GetAsyncKeyState(VK_SHIFT) & 0x8000) != 0;
  return c == k->ctrl && a == k->alt && s == k->shift;
}
// ---- key presses from window messages (hotbar.cpp, poll_keys)
// Why messages: polling GetAsyncKeyState for every bound key every frame is a system call per key per frame, and a
// system call is a switch out of the x86 emulation on the owner's Mac (XIKit docs/HISTORY.md, the 22 Nov profile:
// small per-frame calls such as GetCurrentThreadId were percents of the game thread's samples).
// What reaches the window procedure: the owner's 23 Nov run typed into xiimgui's field (xitest G3), so WM_CHAR reaches a
// subclassed window procedure; WM_KEYDOWN, from which TranslateMessage makes it, is expected there too but not shown:
// the first one seen is logged by hotbar.cpp, and hb_keys_poll=1 brings polling back.
// Win32: lParam bit 30 is the key's previous state (set on auto-repeat); bit 29, in WM_SYSKEYDOWN, is the context code
// (Alt held). Ctrl and Shift are tracked from their own key messages and cleared when the window loses focus.
static WNDPROC g_hb_prev; static HWND g_hb_wnd; static unsigned (*g_hb_stamp)(void);
static volatile LONG g_hb_head, g_hb_tail, g_hb_seen; static HbPress g_hb_ring[64];
static int g_hb_ctrl, g_hb_shift;
static LRESULT CALLBACK hb_proc(HWND w, UINT m, WPARAM wp, LPARAM lp) {
  switch (m) {
  case WM_KEYDOWN: case WM_SYSKEYDOWN: {
    InterlockedIncrement(&g_hb_seen);
    if (wp == VK_CONTROL) g_hb_ctrl = 1; else if (wp == VK_SHIFT) g_hb_shift = 1;
    else if (wp != VK_MENU && !(lp & (1L << 30))) {
      LONG h = g_hb_head;
      if (h - g_hb_tail < 64) {
        HbPress &p = g_hb_ring[h & 63]; memset(&p, 0, sizeof p);
        p.key.vk = (int)wp; p.key.ctrl = g_hb_ctrl; p.key.shift = g_hb_shift; p.key.alt = m == WM_SYSKEYDOWN && (lp & (1L << 29)) ? 1 : 0;
        p.stamp = g_hb_stamp ? g_hb_stamp() : 0;
        InterlockedExchange(&g_hb_head, h + 1);
      }
    }
    break; }
  case WM_KEYUP: case WM_SYSKEYUP:
    if (wp == VK_CONTROL) g_hb_ctrl = 0; else if (wp == VK_SHIFT) g_hb_shift = 0;
    break;
  case WM_KILLFOCUS: g_hb_ctrl = g_hb_shift = 0; break;
  case WM_ACTIVATEAPP: if (!wp) g_hb_ctrl = g_hb_shift = 0; break;
  }
  return CallWindowProcW(g_hb_prev, w, m, wp, lp);
}
extern "C" int hb_msg_install(void *hwnd, unsigned (*stamp)(void)) {
  if (g_hb_prev) return 1;
  if (!hwnd || !IsWindow((HWND)hwnd)) return 0;
  g_hb_stamp = stamp; g_hb_wnd = (HWND)hwnd;
  g_hb_prev = (WNDPROC)SetWindowLongPtrW(g_hb_wnd, GWLP_WNDPROC, (LONG_PTR)hb_proc);
  return g_hb_prev != nullptr;
}
extern "C" void hb_msg_uninstall(void) {             // only when this subclass is on top; otherwise it stays, passing on
  if (g_hb_prev && (WNDPROC)GetWindowLongPtrW(g_hb_wnd, GWLP_WNDPROC) == hb_proc) { SetWindowLongPtrW(g_hb_wnd, GWLP_WNDPROC, (LONG_PTR)g_hb_prev); g_hb_prev = nullptr; }
}
extern "C" int hb_msg_next(HbPress *out) {
  LONG t = g_hb_tail;
  if (t == g_hb_head) return 0;
  *out = g_hb_ring[t & 63]; InterlockedExchange(&g_hb_tail, t + 1);
  return 1;
}
extern "C" long hb_msg_seen(void) { return g_hb_seen; }

extern "C" int hb_is_foreground(void *hwnd) {
  if (!hwnd) return 0;
  HWND fg = GetForegroundWindow();
  return fg == (HWND)hwnd || (fg && GetAncestor(fg, GA_ROOTOWNER) == (HWND)hwnd);
}

// ---------------------------------------------------------------------------------------------------------- text
static char *trim(char *s) {
  while (*s == ' ' || *s == '\t') s++;
  char *e = s + strlen(s);
  while (e > s && (e[-1] == ' ' || e[-1] == '\t' || e[-1] == '\r' || e[-1] == '\n')) *--e = 0;
  return s;
}
static char *read_file(const char *path, long *len) {
  FILE *f = fopen(path, "rb"); if (!f) return nullptr;
  fseek(f, 0, SEEK_END); long n = ftell(f); fseek(f, 0, SEEK_SET);
  if (n < 0 || n > 32 * 1024 * 1024) { fclose(f); return nullptr; }
  char *b = (char *)malloc(n + 1); if (!b) { fclose(f); return nullptr; }
  long r = (long)fread(b, 1, n, f); fclose(f); b[r] = 0; if (len) *len = r; return b;
}
static int file_exists(const char *p) { DWORD a = GetFileAttributesA(p); return a != INVALID_FILE_ATTRIBUTES && !(a & FILE_ATTRIBUTE_DIRECTORY); }

// ---------------------------------------------------------------------------------------------------------- XIVhotbar2's resources
// (the reference is XIVhotbar2 Petit Trois Edition, WGINC/XIVhotbar2-Petit_Trois_Edition: the owner's rewrite of XIVhotbar2)
// priv_res/spells.lua, job_abilities.lua, weapon_skills.lua: lines '[n] = { id = n, en = "Name", ... mp_cost = n, ... tp_cost = n'
struct Res { char name[48], type[24], prefix[16], sc[3][16]; int id, mp, tp, recast_id, skill, element, targets, range, duration, status; float cast, recast; char damage[12]; unsigned char lv[24]; int has_lv; };
struct ResTab { Res *r; int n; };
static ResTab g_spells, g_abils, g_ws, g_blu;      // g_blu: Petit Trois's lib/blue_spells.lua (skillchain properties)
// (29 Nov) g_bp: Petit Trois's lib/bloodpacts.lua (damage = "magic" or "physical"); g_mon: Windower's res/monster_abilities.lua,
// which Petit Trois reads as resources.monster_abilities (its bstpet table and its skillchains.lua for ids of 256 and on)
static ResTab g_bp, g_mon; static char g_mon_path[MAX_PATH];
// (29 Nov) g_items: Windower's res/items.lua (id, en, targets, skill), which Petit Trois reads as resources.items (item
// slots' icons by id, autoitem, the weapon's skill for weapon switching)
static ResTab g_items; static char g_items_path[MAX_PATH]; static char g_dat_note[200];
// (29 Nov) descriptions: priv_res/spell_descriptions.lua by spell id; ability_descriptions.lua by weapon skill id, or job
// ability id + 512 (Petit Trois's database.lua; the game's own numbering of the abilities' records, xistate)
struct Desc { int id; char *en; };
static Desc *g_sdesc, *g_adesc; static int g_nsdesc, g_nadesc;
static void load_desc(Desc **d, int *n, const char *path) {
  for (int i = 0; i < *n; i++) free((*d)[i].en);
  free(*d); *d = nullptr; *n = 0;
  long len = 0; char *b = read_file(path, &len); if (!b) return;
  int cap = 4096; *d = (Desc *)calloc(cap, sizeof(Desc));
  for (char *line = strtok(b, "\n"); line && *d; line = strtok(nullptr, "\n")) {
    const char *id = strstr(line, "{ id = "), *en = strstr(line, "en = \"");
    if (!id || !en || *n >= cap) continue;
    const char *q = strrchr(en + 6, '"'); if (!q || q <= en + 6) continue;
    int l = (int)(q - (en + 6)); char *t = (char *)malloc(l + 1); if (!t) break;
    memcpy(t, en + 6, l); t[l] = 0; (*d)[*n].id = atoi(id + 7); (*d)[*n].en = t; (*n)++;
  }
  free(b);
}
static const char *desc_of(const Desc *d, int n, int id) { for (int i = 0; i < n; i++) if (d[i].id == id) return d[i].en; return ""; }
static struct { int id; char ens[8]; } g_jobs[32]; static int g_njobs;
static char g_res_dir[MAX_PATH];
static int field_int(const char *line, const char *key) { const char *p = strstr(line, key); return p ? atoi(p + strlen(key)) : 0; }
static void str_field(const char *line, const char *key, char *out, int n) {
  out[0] = 0; const char *p = strstr(line, key); if (!p) return; p += strlen(key);
  int l = 0; while (p[l] && p[l] != '"' && l < n - 1) { out[l] = p[l]; l++; } out[l] = 0;
}
// "levels = { [3] = 1, [5] = 3 }": job number -> level
static void read_levels(const char *line, struct Res *r);
static void load_res(ResTab *t, const char *path) {
  free(t->r); t->r = nullptr; t->n = 0;
  long len = 0; char *b = read_file(path, &len); if (!b) return;
  int cap = 4096; t->r = (Res *)calloc(cap, sizeof(Res));
  static char spaced[2048];
  for (char *line = strtok(b, "\n"); line && t->r; line = strtok(nullptr, "\n")) {
    // (29 Nov) Windower's resource files are written without spaces ({id=257,en="Foot Kick",...}): spaced out first
    // (outside quotes: "= " for "=", ", " for ",", "{ " for "{") so the keys below read them as Petit Trois's files
    if (strstr(line, "{id=")) {
      int o = 0, q = 0;
      for (const char *c = line; *c && o < (int)sizeof spaced - 4; c++) {
        if (*c == '"') q = !q;
        if (!q && *c == '=') { spaced[o++] = ' '; spaced[o++] = '='; spaced[o++] = ' '; }
        else if (!q && (*c == ',' || *c == '{')) { spaced[o++] = *c; spaced[o++] = ' '; }
        else spaced[o++] = *c;
      }
      spaced[o] = 0; line = spaced;
    }
    const char *id = strstr(line, "{ id = "), *en = strstr(line, "en = \"");
    if (!id || !en) continue;
    const char *q = strchr(en + 6, '"'); if (!q) continue;
    if (t->n == cap) { Res *nr = (Res *)realloc(t->r, sizeof(Res) * cap * 2); if (!nr) break; t->r = nr; cap *= 2; }
    Res &r = t->r[t->n++]; memset(&r, 0, sizeof r);
    r.id = atoi(id + 7);
    int l = (int)(q - (en + 6)); if (l > 47) l = 47; memcpy(r.name, en + 6, l); r.name[l] = 0;
    r.mp = field_int(line, "mp_cost = "); r.tp = field_int(line, "tp_cost = "); r.recast_id = strstr(line, "recast_id = ") ? field_int(line, "recast_id = ") : -1;
    // (29 Nov, for the picker) the row's type, prefix, skill, element, targets and levels = { [job] = level, ... }
    r.skill = field_int(line, " skill = "); r.element = field_int(line, "element = "); r.targets = field_int(line, "targets = ");
    str_field(line, "type = \"", r.type, sizeof r.type); str_field(line, "prefix = \"", r.prefix, sizeof r.prefix);
    read_levels(line, &r);
    // (29 Nov, for the tooltip) range (the resource's number: Petit Trois's ranges table gives yalms), cast and recast
    // times (spells), skillchain properties (weapon skills)
    r.range = strstr(line, " range = ") ? field_int(line, " range = ") : -1;
    { const char *c = strstr(line, "cast_time = "); r.cast = c ? (float)atof(c + 12) : 0; }
    { const char *c = strstr(line, " recast = "); r.recast = c ? (float)atof(c + 10) : 0; }
    r.duration = field_int(line, "duration = "); r.status = strstr(line, "status = ") ? field_int(line, "status = ") : -1;
    str_field(line, "damage = \"", r.damage, sizeof r.damage);
    str_field(line, "skillchain_a = \"", r.sc[0], 16); str_field(line, "skillchain_b = \"", r.sc[1], 16); str_field(line, "skillchain_c = \"", r.sc[2], 16);
  }
  free(b);
}
static void read_levels(const char *line, Res *r) {
  memset(r->lv, 0, sizeof r->lv); r->has_lv = 0;
  const char *p = strstr(line, "levels = {"); if (!p) return;
  const char *e = strchr(p, '}'); p += 10;
  while (p && p < e) {
    const char *b = strchr(p, '['); if (!b || b > e) break;
    int j = atoi(b + 1); const char *q = strchr(b, '='); if (!q || q > e) break;
    int v = atoi(q + 1); if (j >= 0 && j < 24) { r->lv[j] = (unsigned char)(v > 255 ? 255 : v); r->has_lv = 1; }
    p = q + 1;
  }
}
static const Res *find_res(const ResTab *t, const char *name) {
  for (int i = 0; i < t->n; i++) if (!_stricmp(t->r[i].name, name)) return &t->r[i];
  return nullptr;
}
// (29 Nov) Petit Trois's PlayingHorizonXI: the spells from priv_res/horizon_spells.lua (that server's own list) instead
// of spells.lua (action_manager.lua parse_binds); hb_set_horizon before hb_read. hb_set_learned: the game's lists
// (hotbar.cpp's xistate readers), which bstpet slots are made from.
static int g_horizon, g_res_horizon = -1; static int (*g_learned)(int, int);
extern "C" void hb_set_horizon(int on) { g_horizon = on != 0; }
extern "C" void hb_set_learned(int (*learned)(int, int)) { g_learned = learned; }
static void load_resources(const char *xiv, const char *windower) {
  // (29 Nov) Windower's monster abilities: <windower>\res\monster_abilities.lua, the folder hotbar.txt's "windower" line
  // names, else the Windower that holds XIVhotbar2 (<Windower>\addons\<it>, as Windower installs addons)
  char mp[MAX_PATH];
  if (windower && windower[0]) snprintf(mp, sizeof mp, "%s\\res\\monster_abilities.lua", windower);
  else snprintf(mp, sizeof mp, "%s\\..\\..\\res\\monster_abilities.lua", xiv);
  if (_stricmp(mp, g_mon_path)) { snprintf(g_mon_path, sizeof g_mon_path, "%s", mp); load_res(&g_mon, mp); }
  char ip[MAX_PATH]; snprintf(ip, sizeof ip, "%.*s\\items.lua", (int)(strlen(mp) - strlen("\\monster_abilities.lua")), mp);
  if (_stricmp(ip, g_items_path)) { snprintf(g_items_path, sizeof g_items_path, "%s", ip); load_res(&g_items, ip); }
  if (!xiv[0] || (!_stricmp(g_res_dir, xiv) && g_res_horizon == g_horizon)) return;
  snprintf(g_res_dir, sizeof g_res_dir, "%s", xiv); g_res_horizon = g_horizon;
  char p[MAX_PATH];
  snprintf(p, sizeof p, "%s\\priv_res\\%s.lua", xiv, g_horizon ? "horizon_spells" : "spells"); load_res(&g_spells, p);
  snprintf(p, sizeof p, "%s\\priv_res\\job_abilities.lua", xiv); load_res(&g_abils, p);
  snprintf(p, sizeof p, "%s\\priv_res\\weapon_skills.lua", xiv); load_res(&g_ws, p);
  snprintf(p, sizeof p, "%s\\lib\\blue_spells.lua", xiv); load_res(&g_blu, p);
  snprintf(p, sizeof p, "%s\\lib\\bloodpacts.lua", xiv); load_res(&g_bp, p);
  // (29 Nov) the abilities' levels: priv_res/job_abilities_levels.lua, rows by ability id (Petit Trois's own table;
  // job_abilities.lua carries none)
  ResTab lv = { nullptr, 0 };
  snprintf(p, sizeof p, "%s\\priv_res\\job_abilities_levels.lua", xiv); load_res(&lv, p);
  for (int i = 0; i < lv.n; i++) for (int k = 0; k < g_abils.n; k++)
    if (g_abils.r[k].id == lv.r[i].id) { memcpy(g_abils.r[k].lv, lv.r[i].lv, sizeof lv.r[i].lv); g_abils.r[k].has_lv = lv.r[i].has_lv; break; }
  free(lv.r);
  snprintf(p, sizeof p, "%s\\priv_res\\spell_descriptions.lua", xiv); load_desc(&g_sdesc, &g_nsdesc, p);
  snprintf(p, sizeof p, "%s\\priv_res\\ability_descriptions.lua", xiv); load_desc(&g_adesc, &g_nadesc, p);
  // the jobs' short names: priv_res/jobs.lua, {id=N,en="...",ja="...",ens="WAR",...}
  g_njobs = 0; long len = 0;
  snprintf(p, sizeof p, "%s\\priv_res\\jobs.lua", xiv);
  char *b = read_file(p, &len);
  if (b) {
    for (char *line = strtok(b, "\n"); line; line = strtok(nullptr, "\n")) {
      const char *id = strstr(line, "{id="), *ens = strstr(line, "ens=\"");
      if (!id || !ens || g_njobs >= 32) continue;
      g_jobs[g_njobs].id = atoi(id + 4); str_field(ens, "ens=\"", g_jobs[g_njobs].ens, sizeof g_jobs[g_njobs].ens); g_njobs++;
    }
    free(b);
  }
}
static int job_number(const char *ens) {
  if (!ens || !ens[0]) return 0;
  for (int i = 0; i < g_njobs; i++) if (!_stricmp(g_jobs[i].ens, ens)) return g_jobs[i].id;
  return 0;
}
// the weapon icon by weapon skill id, as XIVhotbar2's database:map_ws does
static int ws_icon(int id) {
  static const int lo[] = { 1, 16, 32, 48, 64, 80, 96, 112, 128, 144, 160, 176, 192, 208 }, hi[] = { 15, 31, 47, 61, 77, 93, 109, 125, 141, 158, 175, 191, 203, 221 };
  for (int i = 0; i < 14; i++) if (id >= lo[i] && id <= hi[i]) return i;
  if (id == 224) return 1;
  if (id > 224 && id <= 255) return 2;
  return 0;
}

// ---------------------------------------------------------------------------------------------------------- actions
static const char *target_of(const char *t, char *out, int n) {
  if (!t || !*t) { out[0] = 0; return out; }
  if (t[0] == '<') snprintf(out, n, " %s", t); else snprintf(out, n, " <%s>", t);
  return out;
}
// "input /a;wait 2;input /b" or "/a; wait 2; /b" into lines and waits
static void split_macro(HbAct *a, const char *text) {
  char buf[1024]; snprintf(buf, sizeof buf, "%s", text);
  int wait = 0;
  for (char *part = buf, *nx; part && a->nlines < HB_LINES; part = nx) {   // (split by hand: callers are inside strtok loops)
    nx = strchr(part, ';'); if (nx) *nx++ = 0;
    char *p = trim(part);
    if (!*p) continue;
    if (!_strnicmp(p, "wait", 4) && (p[4] == ' ' || p[4] == 0)) { wait += (int)(atof(p + 4) * 1000); continue; }
    if (!_strnicmp(p, "input ", 6)) p = trim(p + 6);
    snprintf(a->line[a->nlines], sizeof a->line[0], "%s", p);
    a->wait_ms[a->nlines] = wait; wait = 0; a->nlines++;
  }
}
static void icon_path(char *out, int n, const char *rel) {
  if (g_res_dir[0]) snprintf(out, n, "%s\\%s", g_res_dir, rel); else out[0] = 0;
  for (char *c = out; *c; c++) if (*c == '/') *c = '\\';
  if (out[0] && !file_exists(out)) out[0] = 0;
}
static const Res *res_by_id(const ResTab *t, int id) { for (int i = 0; i < t->n; i++) if (t->r[i].id == id) return &t->r[i]; return nullptr; }
// ---------------------------------------------------------------------------------------------------------- the game's item files
// (29 Nov) Item names, targets, a weapon's skill and icons from the game's own item DATs, for when Windower's items.lua
// is not there. Opening a file by its number is the game's rule (Prishe's core/game_files.cpp, from XIKit's reading:
// FTABLE.DAT's words, VTABLE.DAT's ROM bytes, ROM2..13's own tables winning; folder = word >> 7, file = word & 0x7F).
// The files' numbers, their id ranges and the record layouts are Windower 5's client_data (types/items.lua, items.lua:
// a lead, from files.windower.net/5/packages): 0x40 records of 0xC00 bytes to a 0x30000 block, each byte's bits
// rotated (decrypted as (b >> 5) | (b << 3)), word +0 the id, +0xC the targets (Windower's target bits), +0x22 a
// weapon's skill, a string table at a per-kind offset (count, then {offset, type} entries; text at the table + offset
// + 0x1C), the icon's size at +0x280 and its bytes at +0x284 (0x97C at most). Not checked against the game's files in
// this repository (none of the item files is here): the first use logs what it read.
struct ItemDat { int first, last, base, file, str; };
static const ItemDat k_item_dats[] = {
  { 0x0000, 0x0FFF, 0x0000, 0x0049, 0x18 }, { 0x1000, 0x1FFF, 0x1000, 0x004A, 0x1C }, { 0x2000, 0x21FF, 0x2000, 0x004D, 0x18 },
  { 0x2200, 0x27FF, 0x2200, 0xD977, 0x18 }, { 0x2800, 0x3FFF, 0x2800, 0x004C, 0x2C }, { 0x4000, 0x59FF, 0x4000, 0x004B, 0x38 },
  { 0x5A00, 0x6FFF, 0x5A00, 0xD974, 0x2C }, { 0x7000, 0x73FF, 0x7000, 0xD973, 0x54 }, { 0x7400, 0x77FF, 0x7400, 0xD976, 0x28 },
  { 0xF000, 0xF1FF, 0xF000, 0xD975, 0x70 }, { 0xFFFF, 0xFFFF, 0xFFFF, 0x005B, 0x10 } };
static char g_game_dir[MAX_PATH], g_mod_dir[MAX_PATH];
static unsigned char *g_ft, *g_vt; static long g_nft;                          // FTABLE words, VTABLE ROM bytes (merged)
static int game_dir() {
  if (g_game_dir[0]) return 1;
  HMODULE m = GetModuleHandleA("FFXiMain.dll"); if (!m || !GetModuleFileNameA(m, g_game_dir, MAX_PATH)) { g_game_dir[0] = 0; return 0; }
  char *sl = strrchr(g_game_dir, '\\'); if (sl) *sl = 0;
  return 1;
}
static void file_tables() {
  if (g_ft || !game_dir()) return;
  char p[MAX_PATH]; long n = 0, nv = 0;
  snprintf(p, sizeof p, "%s\\FTABLE.DAT", g_game_dir); char *f = read_file(p, &n); if (!f) return;
  snprintf(p, sizeof p, "%s\\VTABLE.DAT", g_game_dir); char *v = read_file(p, &nv);
  g_nft = n / 2; g_ft = (unsigned char *)f; g_vt = (unsigned char *)calloc(g_nft + 1, 1);
  for (long i = 0; i < g_nft; i++) g_vt[i] = v ? (i < nv ? (unsigned char)v[i] : 0) : 1;   // (the game: all 1 without VTABLE)
  free(v);
  for (int r = 2; r <= 13; r++) {
    long fn = 0, vn = 0; char *fr = nullptr, *vr = nullptr;
    snprintf(p, sizeof p, "%s\\FTABLE%d.DAT", g_game_dir, r); fr = read_file(p, &fn);
    if (!fr) { snprintf(p, sizeof p, "%s\\ROM%d\\FTABLE%d.DAT", g_game_dir, r, r); fr = read_file(p, &fn); }
    snprintf(p, sizeof p, "%s\\VTABLE%d.DAT", g_game_dir, r); vr = read_file(p, &vn);
    if (!vr) { snprintf(p, sizeof p, "%s\\ROM%d\\VTABLE%d.DAT", g_game_dir, r, r); vr = read_file(p, &vn); }
    if (fr && vr) for (long i = 0; i < g_nft && i < vn && 2 * i + 1 < fn; i++) if ((unsigned char)vr[i] == r) { g_vt[i] = (unsigned char)r; g_ft[2 * i] = fr[2 * i]; g_ft[2 * i + 1] = fr[2 * i + 1]; }
    free(fr); free(vr);
  }
}
static int dat_path(long number, char *out, int n) {
  file_tables(); if (!g_ft || number < 0 || number >= g_nft || !g_vt[number]) return 0;
  unsigned w = g_ft[2 * number] | g_ft[2 * number + 1] << 8, rom = g_vt[number];
  if (rom == 1) snprintf(out, n, "%s\\ROM\\%u\\%u.DAT", g_game_dir, w >> 7, w & 0x7F);
  else snprintf(out, n, "%s\\ROM%u\\%u\\%u.DAT", g_game_dir, rom, w >> 7, w & 0x7F);
  return file_exists(out);
}
static void unrotate(unsigned char *b, int n) { for (int i = 0; i < n; i++) b[i] = (unsigned char)((b[i] >> 5) | (b[i] << 3)); }
static unsigned u32le(const unsigned char *p) { return p[0] | p[1] << 8 | p[2] << 16 | (unsigned)p[3] << 24; }
// the record of item id, decrypted into rec (0xC00 bytes); 0 when there is none
static int item_record(int id, unsigned char *rec) {
  for (const ItemDat &d : k_item_dats) {
    if (id < d.first || id > d.last) continue;
    char p[MAX_PATH]; if (!dat_path(d.file, p, sizeof p)) return 0;
    FILE *f = fopen(p, "rb"); if (!f) return 0;
    int ok = fseek(f, (long)(id - d.base) * 0xC00, SEEK_SET) == 0 && fread(rec, 1, 0xC00, f) == 0xC00; fclose(f);
    if (!ok) return 0;
    unrotate(rec, 0xC00);
    return (rec[0] | rec[1] << 8) == id ? d.str : 0;
  }
  return 0;
}
static int record_name(const unsigned char *rec, int so, char *out, int n) {
  out[0] = 0; unsigned cnt = u32le(rec + so); if (!cnt || cnt >= 0x40) return 0;
  unsigned off = u32le(rec + so + 4), type = u32le(rec + so + 8); if (type != 0 || off >= 0x270) return 0;
  const unsigned char *t = rec + so + off + 0x1C; int l = 0;
  while (l < n - 1 && so + off + 0x1C + l < 0xC00 && t[l]) { out[l] = (char)t[l]; l++; }
  out[l] = 0; return l > 0;
}
// every item's name, targets and skill from the game's files (when Windower's items.lua is not there)
static int g_dat_items_tried;
static void load_item_dats() {
  if (g_dat_items_tried || g_items.n) return;
  g_dat_items_tried = 1;
  int cap = 1024; g_items.r = (Res *)calloc(cap, sizeof(Res)); g_items.n = 0;
  int files = 0;
  static unsigned char rec[0xC00];
  for (const ItemDat &d : k_item_dats) {
    char p[MAX_PATH]; if (!dat_path(d.file, p, sizeof p)) continue;
    FILE *f = fopen(p, "rb"); if (!f) continue; files++;
    for (int id = d.first; id <= d.last && fread(rec, 1, 0xC00, f) == 0xC00; id++) {
      unrotate(rec, 0xC00);
      if ((rec[0] | rec[1] << 8) != id) continue;
      char nm[48]; if (!record_name(rec, d.str, nm, sizeof nm) || !strcmp(nm, ".")) continue;
      if (g_items.n == cap) { Res *nr = (Res *)realloc(g_items.r, sizeof(Res) * cap * 2); if (!nr) break; g_items.r = nr; cap *= 2; }
      Res &r = g_items.r[g_items.n++]; memset(&r, 0, sizeof r);
      r.id = id; snprintf(r.name, sizeof r.name, "%s", nm); r.targets = rec[0x0C]; r.skill = d.file == 0x004B ? rec[0x22] : 0;
    }
    fclose(f);
  }
  snprintf(g_dat_note, sizeof g_dat_note, "the game's item files: %d of %d read, %d items", files, (int)(sizeof k_item_dats / sizeof k_item_dats[0]), g_items.n);
}
// an item's icon from its record, as 32-bit BGRA written to <mod dir>\item_icons\<id>.xicon (hb_image_load reads it);
// the bitmap's header is looked for in the icon's first 0x40 bytes (a BITMAPINFOHEADER: size 40, 1 plane, 8 or 32
// bits, 1..64 square), as the bytes before it are not read here; an 8-bit icon's palette follows the header (BMP's
// rule), rows bottom-up. Alpha: as stored (whether the game's range is 0..0x80, as POLUtils reads it, is not
// settled here: the first icon made logs its largest alpha).
static int dat_icon(int id, char *out, int n) {
  out[0] = 0; if (!g_mod_dir[0]) return 0;
  snprintf(out, n, "%s\\item_icons\\%d.xicon", g_mod_dir, id);
  if (file_exists(out)) return 1;
  static unsigned char rec[0xC00]; if (!item_record(id, rec)) { out[0] = 0; return 0; }
  unsigned size = u32le(rec + 0x280); const unsigned char *d = rec + 0x284; if (size > 0x97C) size = 0x97C;
  for (unsigned i = 0; i + 40 <= size && i < 0x40; i++) {
    unsigned hs = u32le(d + i); int w = (int)u32le(d + i + 4), h = (int)u32le(d + i + 8); unsigned pl = d[i + 12] | d[i + 13] << 8, bpp = d[i + 14] | d[i + 15] << 8;
    if (hs != 40 || pl != 1 || (bpp != 8 && bpp != 32) || w < 1 || w > 64 || h < 1 || h > 64) continue;
    unsigned used = u32le(d + i + 32); if (bpp == 8 && (!used || used > 256)) used = 256;
    const unsigned char *pal = d + i + 40, *px = pal + (bpp == 8 ? used * 4 : 0);
    if ((unsigned)(px - d) + (unsigned)(w * h * (bpp / 8)) > size) continue;
    static unsigned buf[64 * 64]; unsigned amax = 0;
    for (int y = 0; y < h; y++) for (int x = 0; x < w; x++) {
      const unsigned char *c = bpp == 8 ? pal + 4 * px[(h - 1 - y) * w + x] : px + 4 * ((h - 1 - y) * w + x);
      buf[y * w + x] = c[0] | c[1] << 8 | c[2] << 16 | (unsigned)c[3] << 24; if (c[3] > amax) amax = c[3];
    }
    char dir2[MAX_PATH]; snprintf(dir2, sizeof dir2, "%s\\item_icons", g_mod_dir); CreateDirectoryA(dir2, nullptr);
    FILE *f = fopen(out, "wb"); if (!f) { out[0] = 0; return 0; }
    unsigned hd[3] = { 0x43494958u, (unsigned)w, (unsigned)h }; fwrite(hd, 4, 3, f); fwrite(buf, 4, (size_t)(w * h), f); fclose(f);
    snprintf(g_dat_note, sizeof g_dat_note, "item %d's icon from the game's file: %dx%d, %u bits, its header at +%u, largest alpha 0x%02X", id, w, h, bpp, i, amax);
    return 1;
  }
  out[0] = 0; return 0;
}
// (29 Nov) the inventory as hotbar.cpp reads it from the game (hb_set_inventory), and what Petit Trois builds from it
static HbInvItem g_inv[2 * 0x51]; static int g_ninv;
extern "C" void hb_set_inventory(const HbInvItem *items, int n) { g_ninv = n > (int)(sizeof g_inv / sizeof g_inv[0]) ? (int)(sizeof g_inv / sizeof g_inv[0]) : n; memcpy(g_inv, items, sizeof(HbInvItem) * g_ninv); }
static const Res *autoitem_pick(const char *filter) {
  load_item_dats();
  int nth = atoi(filter), k = 0; bool is_num = filter[0] && strspn(filter, "0123456789") == strlen(filter);
  for (int i = 0; i < g_ninv; i++) {
    const Res *r = res_by_id(&g_items, g_inv[i].id); if (!r || !r->targets) continue;
    k++;
    if (is_num ? k == nth : strstr(r->name, filter) != nullptr) return r;
  }
  return nullptr;
}
// player.lua update_inventory_items' target rule, by Windower's target bits (1 self, 2 player, 4 party, 8 ally, 16 NPC,
// 32 enemy, 64 object, 128 corpse: Windower's numbering, a lead; Windower 5's client_data target_flags has the same order)
static const char *item_target(int t) {
  if ((t & 1) && !(t & (2 | 4 | 8 | 32 | 64 | 128))) return "me";
  if ((t & (2 | 4 | 8)) && !(t & (32 | 64 | 128))) return "stpc";
  if ((t & (32 | 16)) && !(t & (64 | 128))) return "stnpc";
  return "st";
}
// xivhotbar2.lua shorten_ability_name: each word's first letter upper case, then of the rest the first vowel and the
// consonants until 3 letters; spaces dropped; 6 characters at most
static void shorten_name(const char *name, char *out, int n) {
  int o = 0;
  for (const char *p = name; *p && o < n - 1;) {
    if (!((*p | 32) >= 'a' && (*p | 32) <= 'z')) { if (*p != ' ' && *p != '\t') out[o++] = *p; p++; continue; }
    out[o++] = (char)toupper((unsigned char)*p++);
    int kept = 0, vowel = 0;
    while (((*p | 32) >= 'a' && (*p | 32) <= 'z')) {
      if (kept < 3 && o < n - 1) { bool v = strchr("aeiouAEIOU", *p) != nullptr; if (!v || !vowel) { out[o++] = *p; kept++; if (v) vowel = 1; } }
      p++;
    }
  }
  out[o < 6 ? o : 6] = 0;
}
extern "C" int hb_item_id(const char *name) { load_item_dats(); const Res *r = find_res(&g_items, name); return r ? r->id : 0; }
// the weapon's skill (items.lua skill) and Petit Trois's set name for it (action_manager.lua weaponskill_types)
extern "C" const char *hb_weapon_set(int item_id) {
  load_item_dats(); const Res *r = res_by_id(&g_items, item_id); if (!r) return "";
  switch (r->skill) {
    case 1: return "Hand-to-hand"; case 2: return "Dagger"; case 3: return "Sword"; case 4: return "Great Sword"; case 5: return "Axe";
    case 6: return "Great Axe"; case 7: return "Scythe"; case 8: return "Polearm"; case 9: return "Katana"; case 10: return "Great Katana";
    case 11: return "Club"; case 12: return "Staff"; case 25: return "Bow"; case 26: return "Marksmanship"; default: return "";
  }
}
// an XIVhotbar2 entry {type, action, target, alias, icon} into a slot action; 0 if it cannot be run here
static int make_xiv(HbAct *a, const char *type, const char *action, const char *target, const char *alias, const char *icon, const char *src, char *note, int notelen) {
  memset(a, 0, sizeof *a);
  char tgt[32]; target_of(target, tgt, sizeof tgt);
  snprintf(a->kind, sizeof a->kind, "%s", type);
  snprintf(a->label, sizeof a->label, "%s", alias && *alias ? alias : action);
  snprintf(a->source, sizeof a->source, "%s", src);
  char rel[200] = "";
  if (!_stricmp(type, "ma") || !_stricmp(type, "ja") || !_stricmp(type, "ws") || !_stricmp(type, "pet") || !_stricmp(type, "item") || !_stricmp(type, "ra")) {
    snprintf(a->line[0], sizeof a->line[0], "/%s \"%s\"%s", type, action, tgt); a->nlines = 1;
    const Res *r = !_stricmp(type, "ma") ? find_res(&g_spells, action) : !_stricmp(type, "ja") || !_stricmp(type, "pet") ? find_res(&g_abils, action)
                 : !_stricmp(type, "ws") ? find_res(&g_ws, action) : nullptr;
    if (r) {
      a->mp = r->mp; a->tp = r->tp; a->id = r->id; a->recast_id = r->recast_id;
      if (!_stricmp(type, "ma")) snprintf(rel, sizeof rel, "images/icons/spells/%05d.png", r->id);
      else if (!_stricmp(type, "ws")) snprintf(rel, sizeof rel, "images/icons/weapons/%02d.png", ws_icon(r->id));
      // (28 Nov) abilities' icons are named by their recast_id: XIVhotbar2 Petit Trois Edition (the reference,
      // WGINC/XIVhotbar2-Petit_Trois_Edition) sets an ability's icon to its recast_id (priv_res/database.lua,
      // parse_abilities_lua: new_abil.icon = new_abil.id = recast_id) and builds images/icons/abilities/%05d.png from it
      // (lib/ui.lua 1288, lib/action_picker.lua 814); a spell's icon is its id
      else snprintf(rel, sizeof rel, "images/icons/abilities/%05d.png", r->recast_id >= 0 ? r->recast_id : r->id);
    }
    if (!_stricmp(type, "item")) {
      // (29 Nov) Petit Trois's setup_item_slot_icons: images/icons/items/<id>.bmp when it is there, else custom/item.png;
      // the id by name from Windower's items.lua
      load_item_dats();
      const Res *it = find_res(&g_items, action);
      char ir[64]; snprintf(ir, sizeof ir, "images/icons/items/%d.bmp", it ? it->id : -1);
      char full[MAX_PATH]; icon_path(full, sizeof full, ir);
      char di[MAX_PATH] = "";
      if (it && !full[0] && dat_icon(it->id, di, sizeof di)) { snprintf(a->icon, sizeof a->icon, "%s", di); rel[0] = 0; }   // the game's own icon
      else snprintf(rel, sizeof rel, "%s", it && full[0] ? ir : "images/icons/custom/item.png");
      if (it) a->id = it->id;
    }
  } else if (!_stricmp(type, "bstpet")) {
    // (29 Nov) Petit Trois's bstpet N (action_manager.lua parse_binds and the slot loader): the N-th of the learned job
    // abilities whose prefix is /pet and type is not PetCommand (a BST pet's Ready moves), in the order of their ids (as
    // Windower's get_abilities lists them); it becomes that ability (type ja), its label the name shortened. The learned
    // list is the game's (xistate::ability_learned of id + 0x200, through hb_set_learned).
    int nth = atoi(action), k = 0; const Res *pick = nullptr;
    for (int id = 0; id < 0x400 && !pick; id++) {
      const Res *r = res_by_id(&g_abils, id);
      if (!r || _stricmp(r->prefix, "/pet") || !_stricmp(r->type, "PetCommand")) continue;
      if (!g_learned || g_learned(2, id) != 1) continue;
      if (++k == nth) pick = r;
    }
    if (!pick) { if (note && !note[0]) snprintf(note, notelen, "bstpet %s: no such pet ability learned", action); return 0; }
    char sh[16]; shorten_name(pick->name, sh, sizeof sh);
    return make_xiv(a, "ja", pick->name, target, sh, icon, src, note, notelen)
           && (snprintf(a->spec, sizeof a->spec, "xiv|bstpet|%s|%s|%s|%s", action, target ? target : "", alias ? alias : "", icon ? icon : ""), 1);
  } else if (!_stricmp(type, "autoitem")) {
    // (29 Nov) Petit Trois's autoitem (action_manager.lua, player.lua get_item_from_filter): a number picks that item of
    // the usable list, a name the first whose name holds it (Lua's string.find: its pattern characters are taken plainly
    // here); the slot becomes that item, its label the name shortened (shorten_ability_name), its target by the item's
    // targets. The usable list: the temporary items then the inventory, in bag order, items whose targets are not 0.
    const Res *it = autoitem_pick(action);
    if (!it) { if (note && !note[0]) snprintf(note, notelen, "autoitem '%s': no item of the inventory matches", action); return 0; }
    char sh[16]; shorten_name(it->name, sh, sizeof sh);
    return make_xiv(a, "item", it->name, item_target(it->targets), alias && *alias ? alias : sh, icon, src, note, notelen)
           && (snprintf(a->spec, sizeof a->spec, "xiv|autoitem|%s|%s|%s|%s", action, target ? target : "", alias ? alias : "", icon ? icon : ""), 1);
  } else if (!_stricmp(type, "input")) {
    split_macro(a, action);
  } else if (!_stricmp(type, "macro")) {
    split_macro(a, action);
    snprintf(rel, sizeof rel, "images/icons/custom/macro.png");
  } else if (!_stricmp(type, "ct")) {
    snprintf(a->line[0], sizeof a->line[0], "/%s%s", action, tgt); a->nlines = 1;
  } else {
    // gs and s are Windower addons; bstpet needs the pet's ability list (not read yet)
    if (note && !note[0]) snprintf(note, notelen, "type '%s' (%s) is not run by this hotbar: skipped", type, action);
    return 0;
  }
  if (icon && *icon) { snprintf(rel, sizeof rel, "images/icons/custom/%s.png", icon); }
  if (rel[0] || !a->icon[0]) icon_path(a->icon, sizeof a->icon, rel);
  if (!a->icon[0] && (rel[0] || !_stricmp(type, "input"))) icon_path(a->icon, sizeof a->icon, "images/icons/custom/gear3.png");
  snprintf(a->tip, sizeof a->tip, "%s", a->nlines ? a->line[0] : "");
  snprintf(a->spec, sizeof a->spec, "xiv|%s|%s|%s|%s|%s", type, action, target ? target : "", alias ? alias : "", icon ? icon : "");
  a->used = a->nlines > 0;
  return a->used;
}

// the quoted strings of one Lua table row: { 'a', "b", 'c' }
static int lua_row(const char *s, char out[][200], int max) {
  const char *p = strchr(s, '{'); if (!p) return 0;
  int n = 0; p++;
  while (*p && *p != '}' && n < max) {
    while (*p == ' ' || *p == '\t' || *p == ',') p++;
    if (*p == '\'' || *p == '"') {
      char q = *p++; int l = 0;
      while (*p && *p != q) { if (l < 199) out[n][l++] = *p; p++; }
      out[n][l] = 0; n++;
      if (*p) p++;
    } else if (*p == '}' || !*p) break;
    else { while (*p && *p != ',' && *p != '}') p++; }
  }
  return n;
}
// which table a line opens: xivhotbar_keybinds_general['Root'] = {  /  xivhotbar_keybinds_job["Base"] = {
static int lua_table(const char *s, char *name, int n) {
  const char *p = strstr(s, "xivhotbar_keybinds_"); if (!p) return 0;
  const char *b = strchr(p, '['); if (!b) return 0;
  b++; if (*b == '\'' || *b == '"') b++;
  int l = 0; while (*b && *b != '\'' && *b != '"' && *b != ']' && l < n - 1) name[l++] = *b++;
  name[l] = 0; return l > 0;
}
static int env_of(const char *e) {
  if (!_stricmp(e, "field") || !_stricmp(e, "f")) return 0;
  if (!_stricmp(e, "battle") || !_stricmp(e, "b")) return 1;
  return -1;
}
// one XIVhotbar2 file: the rows of the named tables into the layout (later rows win, as in XIVhotbar2's add_action)
static int load_xiv_file(const char *path, const char *const *tables, int ntables, HbLayout *lay, const HbConfig *cfg, char *note, int notelen) {
  long len = 0; char *b = read_file(path, &len); if (!b) return 0;
  char table[32] = ""; int rows = 0;
  for (char *line = strtok(b, "\n"); line; line = strtok(nullptr, "\n")) {
    char nm[32];
    if (lua_table(line, nm, sizeof nm)) { snprintf(table, sizeof table, "%s", nm); continue; }
    char *t = trim(line); if (*t != '{') continue;
    int want = 0; for (int i = 0; i < ntables; i++) if (!_stricmp(table, tables[i])) want = 1;
    if (!want) continue;
    static char f[8][200]; int n = lua_row(t, f, 8);
    if (n < 3) continue;
    char env[16]; int bar = 0, slot = 0;
    if (sscanf(f[0], "%15s %d %d", env, &bar, &slot) != 3) continue;
    int e = env_of(env); if (e < 0 || bar < 1 || bar > HB_BARS || slot < 1 || slot > HB_SLOTS) continue;
    if (bar > cfg->nbars) continue;
    HbAct a;
    if (make_xiv(&a, f[1], f[2], n > 3 ? f[3] : "", n > 4 ? f[4] : "", n > 5 ? f[5] : "", table, note, notelen)) { lay->a[e][bar - 1][slot - 1] = a; rows++; }
  }
  free(b);
  return rows;
}
static void load_xiv_keys(const char *xiv, HbConfig *cfg) {
  char p[MAX_PATH]; snprintf(p, sizeof p, "%s\\data\\default_keybinds.lua", xiv);
  long len = 0; char *b = read_file(p, &len); if (!b) return;
  for (char *line = strtok(b, "\n"); line; line = strtok(nullptr, "\n")) {
    int r, c; char val[64];
    if (sscanf(line, " keybinds.R%d.C%d = '%63[^']'", &r, &c, val) == 3 && r >= 1 && r <= HB_BARS && c >= 1 && c <= HB_SLOTS)
      parse_windower_key(val, &cfg->bar[r - 1].key[c - 1]);
  }
  free(b);
}

// ---------------------------------------------------------------------------------------------------------- hotbar.txt
// a native slot's command: lines split at ';' with "wait N"; "hb ..." are the hotbar's own commands
static void make_native(HbAct *a, const char *label, const char *cmd, const char *icon) {
  memset(a, 0, sizeof *a);
  snprintf(a->label, sizeof a->label, "%s", label);
  snprintf(a->source, sizeof a->source, "hotbar.txt");
  // the hotbar's own commands: "htb ..." (what is typed: /htb), or "hb ..." as hotbar.txt files before 29 Nov have
  if (!_strnicmp(cmd, "htb ", 4) || !_strnicmp(cmd, "hb ", 3) || !_stricmp(cmd, "hb") || !_stricmp(cmd, "htb")) { snprintf(a->kind, sizeof a->kind, "hb"); snprintf(a->line[0], sizeof a->line[0], "%s", cmd); a->nlines = 1; }
  else { snprintf(a->kind, sizeof a->kind, "line"); split_macro(a, cmd); }
  if (icon && *icon) {
    if (strchr(icon, '\\') || strchr(icon, ':')) snprintf(a->icon, sizeof a->icon, "%s", icon);
    else { char rel[200]; snprintf(rel, sizeof rel, "images/icons/custom/%s.png", icon); icon_path(a->icon, sizeof a->icon, rel); }
  }
  snprintf(a->tip, sizeof a->tip, "%s", cmd);
  snprintf(a->spec, sizeof a->spec, "line|%s|%s|%s", label, cmd, icon ? icon : "");
  a->used = a->nlines > 0;
}

// ---------------------------------------------------------------------------------------------------------- specs (29 Nov)
// "xiv|type|action|target|alias|icon" or "line|label|command|icon": the fields split at '|' (none of them holds one:
// a command's own '|' is hotbar.txt's icon mark, so a native slot's command never keeps one)
static int split_bars(const char *spec, char f[][200], int max) {
  int n = 0, l = 0; f[0][0] = 0;
  for (const char *p = spec; ; p++) {
    if (*p == '|' || !*p) { f[n][l] = 0; n++; l = 0; if (!*p || n == max) break; f[n][0] = 0; continue; }
    if (l < 199) f[n][l++] = *p;
  }
  return n;
}
extern "C" int hb_make_spec(HbAct *a, const char *spec) {
  memset(a, 0, sizeof *a);
  static char f[6][200]; int n = split_bars(spec, f, 6);
  if (n >= 3 && !strcmp(f[0], "xiv")) return make_xiv(a, f[1], f[2], n > 3 ? f[3] : "", n > 4 ? f[4] : "", n > 5 ? f[5] : "", "picker", nullptr, 0);
  if (n >= 3 && !strcmp(f[0], "line")) { make_native(a, f[1], f[2], n > 3 && f[3][0] ? f[3] : nullptr); return a->used; }
  return 0;
}
static void slots_path(char *out, int n, const char *dir, const char *job) {
  char lj[16]; snprintf(lj, sizeof lj, "%s", job ? job : ""); for (char *q = lj; *q; q++) *q = (char)tolower(*q);
  if (lj[0]) snprintf(out, n, "%s\\hotbar_slots_%s.txt", dir, lj); else snprintf(out, n, "%s\\hotbar_slots.txt", dir);
}
static const char *k_layout_head = "# hotbar_layout.txt -- the bars as layout mode (/htb move) left them; read after hotbar.txt, so it wins.\n"
                                   "# Delete this file to go back to hotbar.txt's bars.\n";
extern "C" int hb_save_bars(const char *dir, const HbConfig *c) {
  char p[MAX_PATH]; snprintf(p, sizeof p, "%s\\hotbar_layout.txt", dir);
  FILE *f = fopen(p, "w"); if (!f) return 0;
  fputs(k_layout_head, f);
  for (int b = 0; b < HB_BARS; b++) {
    const HbBar &bar = c->bar[b];
    if (bar.used) fprintf(f, "bar %d %d %d %d c%d%s\n", b + 1, bar.slots, bar.x, bar.y, bar.cols >= 1 ? bar.cols : bar.slots, bar.shared ? " shared" : "");
    else fprintf(f, "off %d\n", b + 1);
  }
  fclose(f); return 1;
}
extern "C" int hb_save_slot(const char *dir, const char *job, int env, int bar, int slot, const char *spec) {
  char p[MAX_PATH]; slots_path(p, sizeof p, dir, job);
  long len = 0; char *old = read_file(p, &len);
  char key[32]; snprintf(key, sizeof key, "%s %d.%d", env ? "battle" : "field", bar, slot);
  FILE *f = fopen(p, "w"); if (!f) { free(old); return 0; }
  if (!old) fprintf(f, "# hotbar_slots -- slots set in the game (layout mode, the picker, /htb set, clear, rename) for %s;\n"
                       "# read last, so they win. A line: put <field|battle> <bar>.<slot> <spec>, or empty <field|battle> <bar>.<slot>.\n", job && job[0] ? job : "no job");
  if (old) {
    for (char *line = old, *nx; line && *line; line = nx) {
      nx = strchr(line, '\n'); if (nx) *nx++ = 0;
      char *t = line; const char *rest = !strncmp(t, "put ", 4) ? t + 4 : !strncmp(t, "empty ", 6) ? t + 6 : nullptr;
      size_t kl = strlen(key);
      if (rest && !strncmp(rest, key, kl) && (rest[kl] == ' ' || rest[kl] == 0 || rest[kl] == '\r')) continue;   // this slot's old line
      fprintf(f, "%s\n", line);
    }
  }
  if (spec && spec[0]) fprintf(f, "put %s %s\n", key, spec); else fprintf(f, "empty %s\n", key);
  fclose(f); free(old); return 1;
}
// the words after a bar's x and y: v (one column), h (one row), c<n> (n slots a row), shared (29 Nov)
static void bar_shape(HbBar *bar, const char *rest) {
  bar->cols = bar->slots; bar->shared = 0;
  int w = 0;
  for (const char *p = rest; *p; ) {
    while (*p == ' ' || *p == '\t') p++;
    char t[16]; int l = 0; while (*p && *p != ' ' && *p != '\t' && l < 15) t[l++] = *p++; t[l] = 0;
    while (*p && *p != ' ' && *p != '\t') p++;
    if (!l) break;
    if (++w <= 4) continue;                              // n, slots, x, y
    if (!_stricmp(t, "v")) bar->cols = 1;
    else if (!_stricmp(t, "h")) bar->cols = bar->slots;
    else if ((t[0] | 32) == 'c' && atoi(t + 1) >= 1) bar->cols = atoi(t + 1) > bar->slots ? bar->slots : atoi(t + 1);
    else if (!_stricmp(t, "shared")) bar->shared = 1;
  }
  bar->vertical = bar->cols == 1 && bar->slots > 1;
}
// hotbar_layout.txt into the bars (after hotbar.txt's)
static void read_layout(const char *dir, HbConfig *c) {
  char p[MAX_PATH]; snprintf(p, sizeof p, "%s\\hotbar_layout.txt", dir);
  long len = 0; char *b = read_file(p, &len); if (!b) return;
  for (char *line = strtok(b, "\n"); line; line = strtok(nullptr, "\n")) {
    char *s = trim(line); int n, k, x, y; char v[8] = "";
    if (sscanf(s, "off %d", &n) == 1 && n >= 1 && n <= HB_BARS) { c->bar[n - 1].used = 0; continue; }
    int got = sscanf(s, "bar %d %d %d %d %7s", &n, &k, &x, &y, v);
    if (got >= 4 && n >= 1 && n <= HB_BARS && k >= 1 && k <= HB_SLOTS) {
      HbBar *bar = &c->bar[n - 1]; bar->used = 1; bar->slots = k; bar->x = x; bar->y = y; bar_shape(bar, s + 4);
    }
  }
  free(b);
  c->nbars = 0; for (int i = 0; i < HB_BARS; i++) if (c->bar[i].used) c->nbars = i + 1;
}
// hotbar_slots_<job>.txt into the layout (last: it wins); shared bars (29 Nov) from hotbar_slots.txt instead
static void read_slots_file(const char *dir, const char *job, const HbConfig *c, HbLayout *lay, int shared);
static void read_slots(const char *dir, const HbConfig *c, HbLayout *lay) {
  read_slots_file(dir, "", c, lay, 1);
  if (c->job[0]) read_slots_file(dir, c->job, c, lay, 0);
  else read_slots_file(dir, "", c, lay, 0);               // no job: the one file holds every bar's
}
static void read_slots_file(const char *dir, const char *job, const HbConfig *c, HbLayout *lay, int shared) {
  char p[MAX_PATH]; slots_path(p, sizeof p, dir, job);
  long len = 0; char *b = read_file(p, &len); if (!b) return;
  for (char *line = strtok(b, "\n"); line; line = strtok(nullptr, "\n")) {
    char *s = trim(line); char env[8]; int bar, slot, used = 0;
    int put = !strncmp(s, "put ", 4), emp = !strncmp(s, "empty ", 6);
    if (!put && !emp) continue;
    if (sscanf(s + (put ? 4 : 6), "%7s %d.%d %n", env, &bar, &slot, &used) < 3) continue;
    int e = env_of(env); if (e < 0 || bar < 1 || bar > HB_BARS || slot < 1 || slot > HB_SLOTS) continue;
    if (!!c->bar[bar - 1].shared != !!shared) continue;
    HbAct &a = lay->a[e][bar - 1][slot - 1];
    if (emp) { memset(&a, 0, sizeof a); continue; }
    const char *sp = used > 0 ? trim(s + (put ? 4 : 6) + used) : "";
    HbAct t; if (used > 0 && hb_make_spec(&t, sp)) { snprintf(t.source, sizeof t.source, "slots file"); a = t; }
    // (29 Nov) an autoitem (or bstpet) slot that nothing matches is empty (Petit Trois blanks it), not the slot under it; its spec is
    // kept so it fills again when the item is there
    else if (used > 0 && (!strncmp(sp, "xiv|autoitem|", 13) || !strncmp(sp, "xiv|bstpet|", 11))) { memset(&a, 0, sizeof a); snprintf(a.spec, sizeof a.spec, "%s", sp); snprintf(a.source, sizeof a.source, "slots file"); }
  }
  free(b);
}

extern "C" long long hb_mtime(const char *dir) {
  char path[MAX_PATH]; snprintf(path, sizeof path, "%s\\hotbar.txt", dir);
  struct _stat64 st; if (_stat64(path, &st)) return 0;
  return (long long)st.st_mtime * 1000 + (long long)st.st_size;
}

static bool same_key(const HbKey &a, const HbKey &b) { return a.vk && a.vk == b.vk && a.ctrl == b.ctrl && a.alt == b.alt && a.shift == b.shift; }
// a slot still on its default key loses it when hotbar.txt (or XIVhotbar2's keybinds) gave that key to another slot or
// to envkey
static void drop_shadowed_defaults(HbConfig *c, HbKey defs[4][HB_SLOTS]) {
  for (int b = 0; b < 4; b++) for (int i = 0; i < HB_SLOTS; i++) {
    HbKey &k = c->bar[b].key[i];
    if (!same_key(k, defs[b][i])) continue;             // its own key now: not a default
    bool taken = same_key(c->env_key, k);
    for (int b2 = 0; b2 < HB_BARS && !taken; b2++) for (int j = 0; j < HB_SLOTS && !taken; j++) {
      if (b2 == b && j == i) continue;
      const HbKey &o = c->bar[b2].key[j];
      taken = same_key(o, k) && !(b2 < 4 && same_key(o, defs[b2][j]));
    }
    if (taken) memset(&k, 0, sizeof k);
  }
}

extern "C" const char *hb_dat_note(void) { return g_dat_note; }
extern "C" int hb_read(const char *dir, HbConfig *c, HbLayout *lay, char *err, int errlen, char *note, int notelen, const HbConfig *ovr) {
  snprintf(g_mod_dir, sizeof g_mod_dir, "%s", dir);
  char path[MAX_PATH]; snprintf(path, sizeof path, "%s\\hotbar.txt", dir);
  memset(c, 0, sizeof *c); memset(lay, 0, sizeof *lay); err[0] = 0; if (note) note[0] = 0;
  c->env = 1;
  // The default keys: 1 2 3 4 5 6 7 8 9 0 - = for slots 1-12; bar 1 alone, bar 2 with Ctrl, bar 3 with Alt, bar 4 with
  // Shift (the owner's choice). hotbar.txt's "key" lines and slot keys, and XIVhotbar2's keybinds, replace them; a
  // default whose key another slot was given is dropped (below), so one key runs one slot.
  static const char *kDefKeys[HB_SLOTS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=" };
  static const char *kDefMods[4] = { "", "c-", "a-", "s-" };
  HbKey defs[4][HB_SLOTS];
  for (int b = 0; b < 4; b++) for (int i = 0; i < HB_SLOTS; i++) {
    char k[8]; snprintf(k, sizeof k, "%s%s", kDefMods[b], kDefKeys[i]);
    if (!strcmp(k, "-")) { memset(&defs[b][i], 0, sizeof defs[b][i]); defs[b][i].vk = VK_OEM_MINUS; snprintf(defs[b][i].name, sizeof defs[b][i].name, "-"); }
    else parse_key(k, &defs[b][i]);                     // (a lone "-" means "none" to parse_key)
    defs[b][i].dflt = 1; c->bar[b].key[i] = defs[b][i];
  }
  FILE *f = fopen(path, "r");
  if (!f) { snprintf(err, errlen, "no %s", path); return 0; }
  char line[1024]; int ln = 0;
  struct Native { int env, bar, slot; HbAct a; };
  static Native nat[2 * HB_BARS * HB_SLOTS]; int nnat = 0;
  while (fgets(line, sizeof line, f)) {
    ln++;
    char *s = trim(line);
    if (!*s || *s == '#') continue;
    int b, n, x, y; char w1[64], w2[64];
    if (!_strnicmp(s, "bar ", 4)) {
      char v[8] = "";
      int k = sscanf(s + 4, "%d %d %d %d %7s", &b, &n, &x, &y, v);
      if (k >= 4 && b >= 1 && b <= HB_BARS && n >= 1 && n <= HB_SLOTS) {
        HbBar *bar = &c->bar[b - 1]; bar->used = 1; bar->slots = n; bar->x = x; bar->y = y;
        bar_shape(bar, s + 4);
        if (b > c->nbars) c->nbars = b;
      } else if (!err[0]) snprintf(err, errlen, "line %d: bar <1-%d> <slots 1-%d> <x> <y> [v|h|c<columns>] [shared]", ln, HB_BARS, HB_SLOTS);
      continue;
    }
    if (sscanf(s, "job %15s %15s", w1, w2) >= 1 && !_strnicmp(s, "job ", 4)) {
      snprintf(c->job, sizeof c->job, "%s", w1); if (sscanf(s, "job %*s %15s", w2) == 1) snprintf(c->sub, sizeof c->sub, "%s", w2);
      continue;
    }
    if (!_strnicmp(s, "set ", 4)) { if (c->nsets < HB_SETS) snprintf(c->sets[c->nsets++], 32, "%s", trim(s + 4)); continue; }
    if (!_strnicmp(s, "env ", 4)) { int e = env_of(trim(s + 4)); if (e >= 0) c->env = e; continue; }
    if (!_strnicmp(s, "envkey ", 7)) { parse_key(trim(s + 7), &c->env_key); continue; }
    if (!_strnicmp(s, "windower ", 9)) {                 // (29 Nov) Windower's folder (res\monster_abilities.lua)
      char *p = trim(s + 9);
      if (strchr(p, ':') || p[0] == '\\') snprintf(c->windower, sizeof c->windower, "%s", p); else snprintf(c->windower, sizeof c->windower, "%s\\%s", dir, p);
      continue;
    }
    if (!_strnicmp(s, "xiv ", 4)) {
      char *p = trim(s + 4);
      if (!strcmp(p, "keys")) { c->xiv_keys = 1; continue; }
      if (strchr(p, ':') || p[0] == '\\') snprintf(c->xiv, sizeof c->xiv, "%s", p); else snprintf(c->xiv, sizeof c->xiv, "%s\\%s", dir, p);
      continue;
    }
    if (sscanf(s, "key %d.%d %63s", &b, &n, w1) == 3) {
      if (b >= 1 && b <= HB_BARS && n >= 1 && n <= HB_SLOTS) parse_key(w1, &c->bar[b - 1].key[n - 1]);
      continue;
    }
    // [field|battle] <bar>.<slot> <key> <label> = <command> [| icon]
    int env = -1; char *t = s;
    if (!_strnicmp(t, "field ", 6)) { env = 0; t = trim(t + 6); } else if (!_strnicmp(t, "battle ", 7)) { env = 1; t = trim(t + 7); }
    char key[32]; int used = 0;
    if (sscanf(t, "%d.%d %31s %n", &b, &n, key, &used) == 3 && used > 0 && b >= 1 && b <= HB_BARS && n >= 1 && n <= HB_SLOTS) {
      char *rest = t + used, *eq = strchr(rest, '=');
      if (!eq) { if (!err[0]) snprintf(err, errlen, "line %d: no '=' before the command", ln); continue; }
      *eq = 0;
      char *cmd = trim(eq + 1), *icon = nullptr, *bar = strrchr(cmd, '|');
      if (bar) { *bar = 0; icon = trim(bar + 1); cmd = trim(cmd); }
      HbKey k; parse_key(key, &k); if (k.vk) c->bar[b - 1].key[n - 1] = k;
      if (nnat < (int)(sizeof nat / sizeof *nat)) { Native &nv = nat[nnat++]; nv.env = env; nv.bar = b; nv.slot = n; make_native(&nv.a, trim(rest), cmd, icon); }
      continue;
    }
    if (!err[0]) snprintf(err, errlen, "line %d not understood: %.60s", ln, s);
  }
  fclose(f);
  // (29 Nov) "htb job" / "htb set" / the game's job: their tables instead of the file's (before 29 Nov the caller set
  // them in cfg, which this function then cleared: the override never reached the tables read)
  if (ovr) {
    snprintf(c->job, sizeof c->job, "%s", ovr->job); snprintf(c->sub, sizeof c->sub, "%s", ovr->sub);
    c->nsets = ovr->nsets; for (int i = 0; i < c->nsets; i++) snprintf(c->sets[i], 32, "%s", ovr->sets[i]);
  }
  read_layout(dir, c);
  // XIVhotbar2's files: General.lua's Root, the job file's Base, its subjob table, then the sets named; hotbar.txt's own
  // slots last (each later source wins a slot, as in XIVhotbar2)
  if (c->xiv[0]) {
    load_resources(c->xiv, c->windower);
    if (c->xiv_keys) load_xiv_keys(c->xiv, c);
    char p[MAX_PATH];
    const char *root[] = { "Root" };
    snprintf(p, sizeof p, "%s\\data\\General.lua", c->xiv);
    if (!load_xiv_file(p, root, 1, lay, c, note, notelen)) { snprintf(p, sizeof p, "%s\\data\\general.lua", c->xiv); load_xiv_file(p, root, 1, lay, c, note, notelen); }
    if (c->job[0]) {
      const char *tabs[2 + HB_SETS]; int nt = 0;
      tabs[nt++] = "Base"; if (c->sub[0]) tabs[nt++] = c->sub;
      for (int i = 0; i < c->nsets; i++) tabs[nt++] = c->sets[i];
      char lj[16]; snprintf(lj, sizeof lj, "%s", c->job); for (char *q = lj; *q; q++) *q = (char)tolower(*q);
      snprintf(p, sizeof p, "%s\\data\\%s.lua", c->xiv, lj);
      // a table's rows in the order the tables are named: load table by table
      int any = 0;
      for (int i = 0; i < nt; i++) any += load_xiv_file(p, &tabs[i], 1, lay, c, note, notelen);
      if (!any && err && !err[0]) snprintf(err, errlen, "no rows for job %s in %s", c->job, p);
    }
  }
  drop_shadowed_defaults(c, defs);                      // (after XIVhotbar2's keybinds too)
  for (int i = 0; i < nnat; i++) {
    const Native &nv = nat[i];
    if (nv.bar > c->nbars) continue;
    for (int e = 0; e < 2; e++) if (nv.env < 0 || nv.env == e) lay->a[e][nv.bar - 1][nv.slot - 1] = nv.a;
  }
  read_slots(dir, c, lay);
  return 1;
}

// ---------------------------------------------------------------------------------------------------------- the picker's lists (29 Nov)
static const char *skill_name(int s) {      // Petit Trois's SKILL_NAMES (lib/action_picker.lua), Windower's skill ids
  static const char *m[] = { "Divine", "Healing", "Enhancing", "Enfeebling", "Elemental", "Dark", "Summoning", "Ninjutsu",
                             "Singing", "String", "Wind", "Blue", "Geomancy", "Handbell" };
  static const char *w[] = { "", "Hand-to-Hand", "Dagger", "Sword", "Great Sword", "Axe", "Great Axe", "Scythe", "Polearm",
                             "Katana", "Great Katana", "Club", "Staff" };
  if (s >= 32 && s <= 45) return m[s - 32];
  if (s >= 1 && s <= 12) return w[s];
  if (s == 25) return "Archery";
  if (s == 26) return "Marksmanship";
  return "Other";
}
// Petit Trois's target rule (action_picker.lua build_actions): only Self -> me; Player/Party/Ally and not Enemy -> stpc;
// else t. The bits are Windower's resource encoding (Self 1, Player 2, Party 4, Ally 8, NPC 16, Enemy 32): a lead,
// consistent with the rows (Cure 63, Provoke 32, Mighty Strikes 1), not read in the game's code.
static const char *target_rule(int t, int self_default) {
  if (t == 1) return "me";
  if ((t & (2 | 4 | 8)) && !(t & 32)) return "stpc";
  if (!t) return self_default ? "me" : "t";
  return "t";
}
static int usable(const Res &r, int mj, int ml, int sj, int sl) {
  if (!mj) return 1;                        // no job known: everything
  if (!r.has_lv) return -1;                 // the table gives no levels
  return (mj < 24 && r.lv[mj] && r.lv[mj] <= ml) || (sj > 0 && sj < 24 && r.lv[sj] && r.lv[sj] <= sl);
}
static int pick_cmp(const void *a, const void *b) { return _stricmp(((const HbPick *)a)->name, ((const HbPick *)b)->name); }
static int has_job(const Res &r, int mj, int sj) { return !r.has_lv || (mj > 0 && mj < 24 && r.lv[mj]) || (sj > 0 && sj < 24 && r.lv[sj]) || (!mj && !sj); }
// Petit Trois's ranges (priv_res/database.lua): the resource's range number to yalms; 0 is Self (255)
static float range_yalms(int r) {
  static const float y[14] = { 255, -1, 3.40f, 4.47f, 5.76f, 6.89f, 7.80f, 8.40f, 10.40f, 12.40f, 14.50f, 16.40f, 20.40f, 23.4f };
  return r >= 0 && r < 14 ? y[r] : -1;
}
extern "C" int hb_action_info(const char *kind, const char *action, HbInfo *o) {
  memset(o, 0, sizeof *o); o->range = -1;
  int ma = !_stricmp(kind, "ma"), ws = !_stricmp(kind, "ws"), ja = !_stricmp(kind, "ja") || !_stricmp(kind, "pet");
  const Res *r = ma ? find_res(&g_spells, action) : ja ? find_res(&g_abils, action) : ws ? find_res(&g_ws, action) : nullptr;
  if (!r) return 0;
  snprintf(o->name, sizeof o->name, "%s", r->name); snprintf(o->type, sizeof o->type, "%s", r->type);
  o->mp = r->mp; o->tp = r->tp; o->range = range_yalms(r->range); o->cast = r->cast; o->recast = r->recast; o->id = r->id; o->recast_id = r->recast_id;
  snprintf(o->desc, sizeof o->desc, "%s", ma ? desc_of(g_sdesc, g_nsdesc, r->id) : ws ? desc_of(g_adesc, g_nadesc, r->id) : desc_of(g_adesc, g_nadesc, r->id + 512));
  for (int k = 0; k < 3; k++) if (r->sc[k][0]) { size_t l = strlen(o->sc); snprintf(o->sc + l, sizeof o->sc - l, "%s%s", l ? ", " : "", r->sc[k]); }
  return 1;
}
extern "C" int hb_pick_list(int tab, const char *main_job, int main_lv, const char *sub_job, int sub_lv, int (*learned)(int, int), HbPick *out, int max) {
  int mj = job_number(main_job), sj = job_number(sub_job), n = 0;
  if (main_lv <= 0) mj = 0;                 // no level known: no job filter (all listed), not a level made up
  if (sub_lv <= 0) sj = 0;
  const ResTab *t = tab <= 1 ? &g_spells : tab == 2 ? &g_abils : &g_ws;
  for (int i = 0; i < t->n && n < max; i++) {
    const Res &r = t->r[i]; HbPick &p = out[n];
    if (!r.name[0] || r.name[0] == '.') continue;
    int trust = !_stricmp(r.type, "Trust");
    if (tab <= 1 && trust != (tab == 1)) continue;
    int lr = learned ? learned(tab, r.id) : -1;
    if (lr == 0) continue;                                                // the game's list: not there
    if (tab == 0 && lr == 1 && !has_job(r, job_number(main_job), job_number(sub_job))) continue;
    if (tab == 0 && lr < 0 && usable(r, mj, main_lv, sj, sub_lv) != 1) continue;   // no list yet: by the levels
    if (tab == 2) {
      if (!_stricmp(r.name, "Stratagems")) continue;                     // Petit Trois: a menu, not an action
      if (!_stricmp(r.type, "Monster")) continue;                        // monstrosity's: not a job's
      if (lr < 0 && usable(r, mj, main_lv, sj, sub_lv) == 0) continue;   // no list yet: by Petit Trois's levels
      if (lr < 0 && mj && !r.has_lv) continue;                           // (no levels for it: not listed with a job)
    }
    memset(&p, 0, sizeof p);
    snprintf(p.name, sizeof p.name, "%s", r.name); p.id = r.id;
    char rel[64];
    if (tab <= 1) {
      snprintf(p.type, sizeof p.type, "ma"); snprintf(p.target, sizeof p.target, "%s", trust ? "me" : target_rule(r.targets, 0));
      snprintf(p.group, sizeof p.group, "%s", r.type); snprintf(p.sub, sizeof p.sub, "%s", skill_name(r.skill));
      snprintf(rel, sizeof rel, "images/icons/spells/%05d.png", r.id);
    } else if (tab == 2) {
      snprintf(p.type, sizeof p.type, "%s", !_stricmp(r.prefix, "/pet") ? "pet" : "ja"); snprintf(p.target, sizeof p.target, "%s", target_rule(r.targets, 1));
      snprintf(p.group, sizeof p.group, "%s", r.type);
      snprintf(rel, sizeof rel, "images/icons/abilities/%05d.png", r.recast_id >= 0 ? r.recast_id : r.id);
    } else {
      snprintf(p.type, sizeof p.type, "ws"); snprintf(p.target, sizeof p.target, "t");
      snprintf(p.group, sizeof p.group, "%s", skill_name(r.skill));
      // (no Physical/Magical strip: Petit Trois's get_ws_type calls a weapon skill with an element Magical, but the
      // table gives Combo and Fast Blade element 6, so the element does not tell it here)
      snprintf(rel, sizeof rel, "images/icons/weapons/%02d.png", ws_icon(r.id));
    }
    icon_path(p.icon, sizeof p.icon, rel);
    if (!p.icon[0]) icon_path(p.icon, sizeof p.icon, "images/icons/custom/gear3.png");
    n++;
  }
  qsort(out, n, sizeof *out, pick_cmp);
  return n;
}

// ---------------------------------------------------------------------------------------------------------- images
extern "C" int hb_image_load(const char *path, int *w, int *h, unsigned **pixels) {
  *pixels = nullptr; *w = *h = 0;
  { size_t l = strlen(path);                                       // (29 Nov) an icon from the game's item file (dat_icon)
    if (l > 6 && !_stricmp(path + l - 6, ".xicon")) {
      long n = 0; char *b = read_file(path, &n); if (!b) return 0;
      unsigned hd[3]; if (n < 12) { free(b); return 0; } memcpy(hd, b, 12);
      if (hd[0] != 0x43494958u || hd[1] < 1 || hd[1] > 64 || hd[2] < 1 || hd[2] > 64 || n < (long)(12 + 4 * hd[1] * hd[2])) { free(b); return 0; }
      *pixels = (unsigned *)malloc(4 * hd[1] * hd[2]); if (!*pixels) { free(b); return 0; }
      memcpy(*pixels, b + 12, 4 * hd[1] * hd[2]); *w = (int)hd[1]; *h = (int)hd[2]; free(b); return 1;
    } }
  wchar_t wp[MAX_PATH]; if (!MultiByteToWideChar(CP_ACP, 0, path, -1, wp, MAX_PATH)) return 0;
  HRESULT ci = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
  IWICImagingFactory *fac = nullptr; IWICBitmapDecoder *dec = nullptr; IWICBitmapFrameDecode *frm = nullptr; IWICFormatConverter *cv = nullptr;
  int ok = 0;
  if (SUCCEEDED(CoCreateInstance(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER, IID_IWICImagingFactory, (void **)&fac)) &&
      SUCCEEDED(fac->CreateDecoderFromFilename(wp, nullptr, GENERIC_READ, WICDecodeMetadataCacheOnDemand, &dec)) &&
      SUCCEEDED(dec->GetFrame(0, &frm)) &&
      SUCCEEDED(fac->CreateFormatConverter(&cv)) &&
      SUCCEEDED(cv->Initialize((IWICBitmapSource *)frm, GUID_WICPixelFormat32bppBGRA, WICBitmapDitherTypeNone, nullptr, 0.0, WICBitmapPaletteTypeCustom))) {
    UINT iw = 0, ih = 0;
    cv->GetSize(&iw, &ih);
    if (iw > 0 && ih > 0 && iw <= 512 && ih <= 512) {
      unsigned *px = (unsigned *)malloc((size_t)iw * ih * 4);
      if (px && SUCCEEDED(cv->CopyPixels(nullptr, iw * 4, iw * ih * 4, (BYTE *)px))) { *pixels = px; *w = (int)iw; *h = (int)ih; ok = 1; }
      else free(px);
    }
  }
  if (cv) cv->Release();
  if (frm) frm->Release();
  if (dec) dec->Release();
  if (fac) fac->Release();
  if (ci == S_OK || ci == S_FALSE) CoUninitialize();
  return ok;
}
extern "C" void hb_image_free(unsigned *pixels) { free(pixels); }

// ---------------------------------------------------------------------------------------------------------- skillchains
// (29 Nov) A port of Petit Trois's lib/skillchains.lua and ui.lua's check_if_chainable / check_if_burstable. Every rule
// here is Petit Trois's (its combos table, its 3 s .. 10 s window, the message numbers it reads, the property-to-element
// table); they are the reference's, not read from the game's code. What the game gives is the action itself: message
// 0x028 as the game parses it (hotbar.cpp's hook, xistate::action_*).
struct ScCombo { const char *old_p, *inc, *res; int level; };
static const ScCombo k_combos[] = {      // skillchains.lua sc_combos, in its order
  { "Transfixion", "Compression", "Compression", 1 }, { "Transfixion", "Reverberation", "Reverberation", 1 }, { "Transfixion", "Scission", "Distortion", 2 },
  { "Compression", "Transfixion", "Transfixion", 1 }, { "Compression", "Detonation", "Detonation", 1 },
  { "Liquefaction", "Scission", "Scission", 1 }, { "Liquefaction", "Impaction", "Fusion", 2 },
  { "Scission", "Liquefaction", "Liquefaction", 1 }, { "Scission", "Reverberation", "Reverberation", 1 }, { "Scission", "Detonation", "Detonation", 1 },
  { "Reverberation", "Induration", "Induration", 1 }, { "Reverberation", "Impaction", "Impaction", 1 },
  { "Detonation", "Scission", "Scission", 1 }, { "Detonation", "Compression", "Gravitation", 2 },
  { "Induration", "Compression", "Compression", 1 }, { "Induration", "Impaction", "Impaction", 1 }, { "Induration", "Reverberation", "Fragmentation", 2 },
  { "Impaction", "Liquefaction", "Liquefaction", 1 }, { "Impaction", "Detonation", "Detonation", 1 },
  { "Gravitation", "Distortion", "Darkness", 3 }, { "Gravitation", "Fragmentation", "Fragmentation", 3 },
  { "Distortion", "Gravitation", "Darkness", 3 }, { "Distortion", "Fusion", "Fusion", 3 },
  { "Fusion", "Gravitation", "Gravitation", 3 }, { "Fusion", "Fragmentation", "Light", 3 },
  { "Fragmentation", "Distortion", "Distortion", 3 }, { "Fragmentation", "Fusion", "Light", 3 },
  { "Light", "Light", "Double Light", 4 }, { "Darkness", "Darkness", "Double Darkness", 4 },
};
// sc_alignments: the elements a burst on the property takes (0 fire .. 7 dark, Petit Trois's numbers)
static int sc_elements(const char *p, int el) {
  static const struct { const char *p; unsigned mask; } t[] = {
    { "Transfixion", 1u << 6 }, { "Compression", 1u << 7 }, { "Liquefaction", 1u << 0 }, { "Scission", 1u << 3 },
    { "Reverberation", 1u << 5 }, { "Detonation", 1u << 2 }, { "Induration", 1u << 1 }, { "Impaction", 1u << 4 },
    { "Gravitation", (1u << 7) | (1u << 3) }, { "Distortion", (1u << 5) | (1u << 1) }, { "Fusion", (1u << 0) | (1u << 6) },
    { "Fragmentation", (1u << 2) | (1u << 4) }, { "Light", 0x55 }, { "Darkness", 0xAA }, { "Double Light", 0x55 }, { "Double Darkness", 0xAA } };
  for (unsigned i = 0; i < sizeof t / sizeof t[0]; i++) if (!strcmp(t[i].p, p)) return el >= 0 && el < 8 && ((t[i].mask >> el) & 1);
  return 0;
}
// ui.lua check_if_chainable: immanence turns a black magic spell into its element's property
static const char *k_el_prop[8] = { "Liquefaction", "Induration", "Detonation", "Scission", "Impaction", "Reverberation", "Transfixion", "Compression" };
#define SC_TGT 32
struct ScTarget { unsigned id; char props[3][16]; int n; unsigned last, formed; int used, has_formed; };
static ScTarget g_sc[SC_TGT];
struct ScBuff { unsigned actor, until; };                 // skillchains.lua target_buffs[actor][164]: chain affinity's end
static ScBuff g_sc_ca[16];
static ScTarget *sc_find(unsigned id, int make) {
  ScTarget *free_t = nullptr, *oldest = &g_sc[0];
  for (int i = 0; i < SC_TGT; i++) {
    if (g_sc[i].used && g_sc[i].id == id) return &g_sc[i];
    if (!g_sc[i].used && !free_t) free_t = &g_sc[i];
    if (g_sc[i].last < oldest->last) oldest = &g_sc[i];
  }
  if (!make) return nullptr;
  ScTarget *t = free_t ? free_t : oldest;                 // (the Lua table grows; this one drops the oldest target)
  memset(t, 0, sizeof *t); t->id = id; t->used = 1; return t;
}
static int res_props(const Res *r, char out[3][16]) {
  int n = 0; if (!r) return 0;
  for (int k = 0; k < 3; k++) if (r->sc[k][0]) snprintf(out[n++], 16, "%s", r->sc[k]);
  return n;
}
// attempt_skillchain: >= 10 s since the last: cleared; 3 s .. 10 s with properties: the first combo (old in order,
// incoming in order) forms; else the incoming replace the old
extern "C" void hb_sc_attempt(unsigned target, const char inc[][16], int ninc, unsigned now) {
  ScTarget *t = sc_find(target, 1);
  unsigned d = now - t->last;
  if (!t->last || d >= 10000) { t->n = 0; t->has_formed = 0; }
  int formed = 0;
  if (t->last && d >= 3000 && d <= 10000 && t->n > 0) {
    for (int o = 0; o < t->n && !formed; o++) for (int i = 0; i < ninc && !formed; i++)
      for (unsigned c = 0; c < sizeof k_combos / sizeof k_combos[0]; c++)
        if (!strcmp(k_combos[c].old_p, t->props[o]) && !strcmp(k_combos[c].inc, inc[i])) {
          snprintf(t->props[0], 16, "%s", k_combos[c].res); t->n = 1; t->formed = now; t->has_formed = 1; formed = 1; break;
        }
  }
  if (!formed) { t->n = ninc > 3 ? 3 : ninc; for (int i = 0; i < t->n; i++) snprintf(t->props[i], 16, "%s", inc[i]); }
  t->last = now ? now : 1;
}
// handle_action: the first target's first action, as skillchains.lua reads them
extern "C" int hb_sc_action(unsigned actor, unsigned param, unsigned target, int message, unsigned now) {
  char p[3][16]; int n = 0;
  if (message == 185 || message == 186 || message == 194 || message == 187) {            // weapon skills
    n = res_props(param < 256 ? res_by_id(&g_ws, (int)param) : res_by_id(&g_mon, (int)param), p);   // 256 on: monster abilities
  } else if (message == 100) {                                                            // uses an ability
    const Res *r = res_by_id(&g_abils, (int)param);
    if (r && r->status == 164) {                                                          // chain affinity
      ScBuff *b = &g_sc_ca[0];
      for (int i = 0; i < 16; i++) { if (g_sc_ca[i].actor == actor) { b = &g_sc_ca[i]; break; } if (g_sc_ca[i].until < b->until) b = &g_sc_ca[i]; }
      b->actor = actor; b->until = now + (unsigned)r->duration * 1000u;
    }
    return 0;
  } else if (message == 2) {                                                              // a spell's damage
    for (int i = 0; i < 16; i++) if (g_sc_ca[i].actor == actor && g_sc_ca[i].until && (int)(g_sc_ca[i].until - now) > 0) {
      const Res *s = res_by_id(&g_spells, (int)param);
      if (s && !_stricmp(s->type, "BlueMagic")) { n = res_props(res_by_id(&g_blu, (int)param), p); if (n) g_sc_ca[i].until = 0; }
      break;
    }
  } else if (message == 317) {                                                            // an ability's damage
    const Res *r = res_by_id(&g_abils, (int)param);
    if (r && !_stricmp(r->type, "BloodPactRage")) n = res_props(r, p);
  }
  if (!n) return 0;
  hb_sc_attempt(target, p, n, now);
  return 1;
}
// get_potential_skillchains for one action's properties: 1 and the property and level the first that chains would make
static int sc_potential(const ScTarget *t, char inc[][16], int ninc, unsigned now, HbChain *out) {
  if (!t || !t->n) return 0;
  unsigned d = now - t->last; if (d < 3000 || d > 10000) return 0;
  for (int i = 0; i < ninc; i++) for (int o = 0; o < t->n; o++)                 // (ui.lua: sc_a, then sc_b, then sc_c)
    for (unsigned c = 0; c < sizeof k_combos / sizeof k_combos[0]; c++)
      if (!strcmp(k_combos[c].old_p, t->props[o]) && !strcmp(k_combos[c].inc, inc[i])) {
        if (out) { snprintf(out->property, sizeof out->property, "%s", k_combos[c].res); out->level = k_combos[c].level; }
        return 1;
      }
  return 0;
}
static int enemy_target(const Res *r) { return r && (r->targets & 32); }     // targets' Enemy bit (target_rule's reading)
extern "C" int hb_sc_chain(unsigned target, const char *kind, const char *action, int chain_affinity, int immanence, unsigned now, HbChain *out) {
  const ScTarget *t = sc_find(target, 0); if (!t) return 0;
  char p[3][16]; int n = 0;
  if (!_stricmp(kind, "ws")) n = res_props(find_res(&g_ws, action), p);
  else if (!_stricmp(kind, "ja") || !_stricmp(kind, "pet")) {
    const Res *r = find_res(&g_abils, action);
    // ui.lua: a BST pet's command (prefix /pet, type Monster) chains as the monster ability the pet uses, found by name
    // among the monster abilities 3840..3962 (database.lua parse_bstpets_lua)
    if (r && !_stricmp(r->prefix, "/pet") && !_stricmp(r->type, "Monster")) {
      const Res *m = nullptr;
      for (int i = 0; i < g_mon.n && !m; i++) if (g_mon.r[i].id > 3839 && g_mon.r[i].id < 3963 && !_stricmp(g_mon.r[i].name, r->name)) m = &g_mon.r[i];
      n = res_props(m, p);
    } else n = res_props(r, p);
  }
  else if (!_stricmp(kind, "ma")) {
    const Res *s = find_res(&g_spells, action);
    if (!s || !enemy_target(s)) return 0;
    if (chain_affinity && !_stricmp(s->type, "BlueMagic")) n = res_props(res_by_id(&g_blu, s->id), p);
    else if (immanence && !_stricmp(s->type, "BlackMagic") && s->element >= 0 && s->element < 8) { snprintf(p[0], 16, "%s", k_el_prop[s->element]); n = 1; }
  }
  return n ? sc_potential(t, p, n, now, out) : 0;
}
// get_magic_burst_elements and check_if_burstable: within 10 s of a chain formed, a spell (not blue magic, unless burst
// affinity) whose targets have the Enemy bit, of an element the property takes; or a blood pact rage whose row in
// Petit Trois's bloodpacts.lua says damage = "magic", by the pact's element (ui.lua check_if_burstable).
extern "C" int hb_sc_burst(unsigned target, const char *kind, const char *action, int burst_affinity, unsigned now, int *element) {
  const ScTarget *t = sc_find(target, 0);
  if (!t || !t->n || !t->has_formed || now - t->formed > 10000) return 0;
  if (!_stricmp(kind, "ja") || !_stricmp(kind, "pet")) {             // (ui.lua) a blood pact rage whose bloodpacts.lua row says magic
    const Res *r = find_res(&g_abils, action); if (!r || _stricmp(r->prefix, "/pet") || _stricmp(r->type, "BloodPactRage")) return 0;
    const Res *b = res_by_id(&g_bp, r->id); if (!b || _stricmp(b->damage, "magic")) return 0;
    if (element) *element = r->element;
    return sc_elements(t->props[0], r->element);
  }
  if (_stricmp(kind, "ma")) return 0;
  const Res *s = find_res(&g_spells, action);
  if (!s || !enemy_target(s) || (!_stricmp(s->type, "BlueMagic") && !burst_affinity)) return 0;
  if (element) *element = s->element;
  return sc_elements(t->props[0], s->element);
}
extern "C" int hb_sc_state(unsigned target, unsigned now, char *props, int n, int *window_ms, int *burst_ms) {
  const ScTarget *t = sc_find(target, 0);
  if (props && n) props[0] = 0;
  if (window_ms) *window_ms = 0;
  if (burst_ms) *burst_ms = 0;
  if (!t || !t->n || now - t->last > 10000) return 0;
  for (int i = 0; i < t->n && props; i++) { size_t l = strlen(props); snprintf(props + l, n - l, "%s%s", l ? ", " : "", t->props[i]); }
  if (window_ms) *window_ms = (int)(10000 - (now - t->last));
  if (burst_ms && t->has_formed && now - t->formed <= 10000) *burst_ms = (int)(10000 - (now - t->formed));
  return t->n;
}
extern "C" void hb_sc_reset(void) { memset(g_sc, 0, sizeof g_sc); memset(g_sc_ca, 0, sizeof g_sc_ca); }
