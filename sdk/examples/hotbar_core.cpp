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
unsigned hb_now_ms(void) { return GetTickCount(); }
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
// priv_res/spells.lua, job_abilities.lua, weapon_skills.lua: lines '[n] = { id = n, en = "Name", ... mp_cost = n, ... tp_cost = n'
struct Res { char name[48]; int id, mp, tp; };
struct ResTab { Res *r; int n; };
static ResTab g_spells, g_abils, g_ws;
static char g_res_dir[MAX_PATH];
static int field_int(const char *line, const char *key) { const char *p = strstr(line, key); return p ? atoi(p + strlen(key)) : 0; }
static void load_res(ResTab *t, const char *path) {
  free(t->r); t->r = nullptr; t->n = 0;
  long len = 0; char *b = read_file(path, &len); if (!b) return;
  int cap = 4096; t->r = (Res *)calloc(cap, sizeof(Res));
  for (char *line = strtok(b, "\n"); line && t->r; line = strtok(nullptr, "\n")) {
    const char *id = strstr(line, "{ id = "), *en = strstr(line, "en = \"");
    if (!id || !en) continue;
    const char *q = strchr(en + 6, '"'); if (!q) continue;
    if (t->n == cap) { Res *nr = (Res *)realloc(t->r, sizeof(Res) * cap * 2); if (!nr) break; t->r = nr; cap *= 2; }
    Res &r = t->r[t->n++]; memset(&r, 0, sizeof r);
    r.id = atoi(id + 7);
    int l = (int)(q - (en + 6)); if (l > 47) l = 47; memcpy(r.name, en + 6, l); r.name[l] = 0;
    r.mp = field_int(line, "mp_cost = "); r.tp = field_int(line, "tp_cost = ");
  }
  free(b);
}
static const Res *find_res(const ResTab *t, const char *name) {
  for (int i = 0; i < t->n; i++) if (!_stricmp(t->r[i].name, name)) return &t->r[i];
  return nullptr;
}
static void load_resources(const char *xiv) {
  if (!xiv[0] || !_stricmp(g_res_dir, xiv)) return;
  snprintf(g_res_dir, sizeof g_res_dir, "%s", xiv);
  char p[MAX_PATH];
  snprintf(p, sizeof p, "%s\\priv_res\\spells.lua", xiv); load_res(&g_spells, p);
  snprintf(p, sizeof p, "%s\\priv_res\\job_abilities.lua", xiv); load_res(&g_abils, p);
  snprintf(p, sizeof p, "%s\\priv_res\\weapon_skills.lua", xiv); load_res(&g_ws, p);
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
      a->mp = r->mp; a->tp = r->tp;
      if (!_stricmp(type, "ma")) snprintf(rel, sizeof rel, "images/icons/spells/%05d.png", r->id);
      else if (!_stricmp(type, "ws")) snprintf(rel, sizeof rel, "images/icons/weapons/%02d.png", ws_icon(r->id));
      else snprintf(rel, sizeof rel, "images/icons/abilities/%05d.png", r->id);
    }
    if (!_stricmp(type, "item")) snprintf(rel, sizeof rel, "images/icons/custom/item.png");
  } else if (!_stricmp(type, "input")) {
    split_macro(a, action);
  } else if (!_stricmp(type, "macro")) {
    split_macro(a, action);
    snprintf(rel, sizeof rel, "images/icons/custom/macro.png");
  } else if (!_stricmp(type, "ct")) {
    snprintf(a->line[0], sizeof a->line[0], "/%s%s", action, tgt); a->nlines = 1;
  } else {
    // gs and s are Windower addons; autoitem and bstpet need the game's inventory and pet lists (not read yet)
    if (note && !note[0]) snprintf(note, notelen, "type '%s' (%s) is not run by this hotbar: skipped", type, action);
    return 0;
  }
  if (icon && *icon) { snprintf(rel, sizeof rel, "images/icons/custom/%s.png", icon); }
  icon_path(a->icon, sizeof a->icon, rel);
  if (!a->icon[0] && (rel[0] || !_stricmp(type, "input"))) icon_path(a->icon, sizeof a->icon, "images/icons/custom/gear3.png");
  snprintf(a->tip, sizeof a->tip, "%s", a->nlines ? a->line[0] : "");
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
  if (!_strnicmp(cmd, "hb ", 3) || !_stricmp(cmd, "hb")) { snprintf(a->kind, sizeof a->kind, "hb"); snprintf(a->line[0], sizeof a->line[0], "%s", cmd); a->nlines = 1; }
  else { snprintf(a->kind, sizeof a->kind, "line"); split_macro(a, cmd); }
  if (icon && *icon) {
    if (strchr(icon, '\\') || strchr(icon, ':')) snprintf(a->icon, sizeof a->icon, "%s", icon);
    else { char rel[200]; snprintf(rel, sizeof rel, "images/icons/custom/%s.png", icon); icon_path(a->icon, sizeof a->icon, rel); }
  }
  snprintf(a->tip, sizeof a->tip, "%s", cmd);
  a->used = a->nlines > 0;
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

extern "C" int hb_read(const char *dir, HbConfig *c, HbLayout *lay, char *err, int errlen, char *note, int notelen) {
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
        HbBar *bar = &c->bar[b - 1]; bar->used = 1; bar->slots = n; bar->x = x; bar->y = y; bar->vertical = k == 5 && (v[0] | 32) == 'v';
        if (b > c->nbars) c->nbars = b;
      } else if (!err[0]) snprintf(err, errlen, "line %d: bar <1-%d> <slots 1-%d> <x> <y> [v]", ln, HB_BARS, HB_SLOTS);
      continue;
    }
    if (sscanf(s, "job %15s %15s", w1, w2) >= 1 && !_strnicmp(s, "job ", 4)) {
      snprintf(c->job, sizeof c->job, "%s", w1); if (sscanf(s, "job %*s %15s", w2) == 1) snprintf(c->sub, sizeof c->sub, "%s", w2);
      continue;
    }
    if (!_strnicmp(s, "set ", 4)) { if (c->nsets < HB_SETS) snprintf(c->sets[c->nsets++], 32, "%s", trim(s + 4)); continue; }
    if (!_strnicmp(s, "env ", 4)) { int e = env_of(trim(s + 4)); if (e >= 0) c->env = e; continue; }
    if (!_strnicmp(s, "envkey ", 7)) { parse_key(trim(s + 7), &c->env_key); continue; }
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
  // XIVhotbar2's files: General.lua's Root, the job file's Base, its subjob table, then the sets named; hotbar.txt's own
  // slots last (each later source wins a slot, as in XIVhotbar2)
  if (c->xiv[0]) {
    load_resources(c->xiv);
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
  return 1;
}

// ---------------------------------------------------------------------------------------------------------- images
extern "C" int hb_image_load(const char *path, int *w, int *h, unsigned **pixels) {
  *pixels = nullptr; *w = *h = 0;
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
