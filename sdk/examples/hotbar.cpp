// hotbar.cpp -- action bars for the game, drawn in the game's menu layer with its own font; XIVhotbar2's job files,
// icons and keybinds read directly. Build:
//   sdk/build_mod.sh hotbar.dll sdk/examples/hotbar.cpp sdk/examples/hotbar_core.cpp -- -lwindowscodecs -lole32
//
// What it does: up to 10 bars of up to 12 slots (across, or down with "v"), laid out in <kit folder>\hotbar.txt
// (written with examples the first time; read again when it changes). A slot holds one command line, or several
// separated by ';' with "wait N" (seconds) between them, as a game macro does; or an XIVhotbar2 entry (ma, ja, ws, pet,
// item, ra, input, macro, ct) from its job files (General.lua's Root, <job>.lua's Base, its subjob's table, and any
// sets named). Pressing the slot's key or clicking it runs it through the game's own command line, exactly as typing
// it and pressing Enter does, one line per press except a macro's own lines. The mod sends nothing itself.
// "hb ..." lines are the hotbar's own: hb env [field|battle] (the field and battle sets, as XIVhotbar2's), hb job <job>
// [<subjob>], hb set <name> (a set on or off), hb reload, hb hide.
//
// What the game's code shows (build 6A995428; the same functions unchanged in 6AE818B4; docs/HOTBAR_CURSOR.md):
// - Command_RunLine (0x10080DC0, cdecl: line, mode): the chat line's Enter runs it with mode 0 (Input_HandleChar,
//   tree/src/InputDevices.cpp:304); the mod uses mode 0.
// - A typed character goes into the chat line's text at [0x10578490]+0x14 (Input_HandleChar). A slot key runs a few
//   frames after its press, and not at all if that text changed meanwhile (the key was typed into the chat line).
//   Whether the chat line is open is not read (xikit_ui.hpp, chat_line_text).
// - Text: FontGlyphs::FontGlyphs_DrawString (0x1011C080, this = [0x104E1B90]) with flags 0x44, as the game's wrapper
//   0x10129F00 (125 calls); colours as Menu_DrawWindowItems: 0x80808080 normal, 0x80805020 focused. It sets its alpha
//   operation and blending but not the colour operation: the game's states are put back before text.
// - Sizes: the screen rectangle [0x106218B4] (left, top) and [0x106218B8] (right, bottom), the menu manager's
//   +0x7C..+0x82; the game scales its menus' parts by +0x80/640 and +0x82/480 (TargetMenu_GetScaledPos80). The cursor,
//   g_pCursor ([0x104E1D4C]) +4/+8, is in the same units.
// - The interface hidden: Menu_DrawLayers draws a window only if Menu_IsStateB4Eq1 is false (the menu manager's byte
//   +0xB4 is not 1) or the window has flag 0x40. While +0xB4 is 1 the bars are not drawn and take no clicks; keys work.
// - Clicks: the window procedure (0x100016C0) turns WM_LBUTTONDOWN into Cursor_EnterMode1 (0x10124930) and
//   WM_LBUTTONUP into Cursor_ToggleFlag1 (0x101249E0); DirectInput's left button goes to the same two
//   (Input_DispatchButtons). Over a bar the mod handles the press and keeps both from the game, so the game sees no
//   click there (no target pick, no menu). The world pick under a bar (Target_PickNearestToPoint) finds nothing, so
//   hovering a bar does not target what is behind it.
// Not read yet (so not done): the player's job, engagement, weapon and pet (XIVhotbar2 switches sets on them; here
// "hb job", "hb env", "hb set" or hotbar.txt choose them), recasts, learned spells (XIVhotbar2 drops unlearned
// entries; here the last entry for a slot shows, as XIVhotbar2's merge does), inventory counts, skillchains.
//
// - The game's macro palettes (tree/src/TextInputFiles.cpp): its macro key handler (around 0x101A2E80) tests the
//   game's own key commands (NetCellFont_TestCommand36CF60, commands 0x6C-0x75 for one palette's ten macros and
//   0x62-0x6B for the other's) and calls TextInputFiles_ApplyKeyAction (0x101A3500), which calls
//   TextInputFiles_SetSlot (0x101A3300) with the palette (1 or 2) and the macro (0-9); SetSlot calls
//   TextInputFiles_QueueEntry (0x101A1C60, thiscall, one argument: ret 4, data/purges.json) with the macro for palette 1
//   and the macro + 10 for palette 2. QueueEntry copies that entry to the running one (+0x2048) and starts it
//   (+0x21C4 = 0); TextInputFiles_StepScript then runs its lines through Command_RunLine, mode 2. SetSlot is
//   QueueEntry's only caller in the tree. Which palette Ctrl and Alt open is the game's key configuration (commands
//   0x76, 0x77): not read here.
// - The mode (hb_mode, "/hb mode"): 1 hotbar (the default): the game's macro palettes are never shown (the hook of
//   MenuMng_OpenByName below), and a macro the game starts runs the hotbar's slot instead,
//   palette 1's macro N on bar 2 slot N, palette 2's on bar 3 (N 1-10; 0 is slot 10); an empty slot there, or the
//   bars hidden, leaves the game's macro to run. Bars 2 and 3 then have no keys of their own for slots 1-10 (the
//   game's macro keys are theirs), so a press runs one slot. 0 macros: the game's macros run as always; of the default
//   keys only bar 1's are on (keys bound in hotbar.txt stay on).
//
// Settings ([hotbar] in xikit_mods.ini): hb_show, hb_dry (log instead of run), hb_log, hb_scale (percent),
// hb_empty (1: draw empty slots), hb_tips (1: a tooltip over a hovered slot), hb_mode (1 hotbar, 0 macros).
// Tested offline (kit/xikit/test, mode hbmod). Not run in the game in this version.
#include "xikit_sdk.hpp"
#include "xikit_ui.hpp"
#include "xikit_cmd.hpp"
#include "hotbar_core.h"
XIKIT_MOD_GLOBALS
XIKIT_MOD_INFO("hotbar", "2", 4, "action bars from XIVhotbar2's files, drawn with the game's font")

enum : unsigned { FVF_XYZRHW = 0x004, FVF_DIFFUSE = 0x040, FVF_TEX1 = 0x100, TOP_SELECTARG1 = 2, TOP_MODULATE = 4, TA_DIFFUSE = 0,
                  TA_TEXTURE = 2, BLEND_SRCALPHA = 5, BLEND_INVSRCALPHA = 6, CULL_NONE = 1, TEXF_LINEAR = 2 };
static const XikitHost *g_host;
static HbConfig g_cfg, g_ovr; static int g_have_ovr;
static HbLayout g_lay;
static long long g_mtime; static long g_frame;
static int g_env;                                                   // 0 field, 1 battle
static int g_hidden_by_cmd;
static char g_last[200]; static volatile long g_runs;
static int g_prev_key[HB_BARS][HB_SLOTS], g_prev_env_key, g_flash[HB_BARS][HB_SLOTS];
static int g_queue_b = -1, g_queue_s = -1, g_queue_tag;
static const char *g_queue_how = "(key)";
static int g_swallow;                                              // a press the mod kept from the game; its release too


static const int S = 22, G = 3, P = 4;        // slot, gap, padding (640x480 units, before hb_scale)

static float unit_x() { return xiui::unit_x(); }
static float unit_y() { return xiui::unit_y(); }
static float scale() { return g_host->setting_int("hb_scale", 100) / 100.0f; }
static int ui_hidden() { return xiui::interface_hidden() || g_hidden_by_cmd; }

static void bar_rect(const HbBar &b, float r[4]) {
  float k = scale(), len = (P * 2 + b.slots * S + (b.slots - 1) * G) * k, th = (P * 2 + S) * k;
  float w = b.vertical ? th : len, h = b.vertical ? len : th;
  float x = b.x < 0 ? 640 + b.x - w : b.x, y = b.y < 0 ? 480 + b.y - h : b.y;
  r[0] = x * unit_x(); r[1] = y * unit_y(); r[2] = (x + w) * unit_x(); r[3] = (y + h) * unit_y();
}
static void slot_rect(const HbBar &b, int i, float r[4]) {
  float br[4]; bar_rect(b, br); float k = scale(), o = (P + i * (S + G)) * k;
  r[0] = br[0] + (b.vertical ? P * k : o) * unit_x(); r[1] = br[1] + (b.vertical ? o : P * k) * unit_y();
  r[2] = r[0] + S * k * unit_x(); r[3] = r[1] + S * k * unit_y();
}
// the environment tag, left of bar 1 (click: field <-> battle)
static int tag_rect(float r[4]) {
  if (!g_cfg.bar[0].used) return 0;
  float b[4]; bar_rect(g_cfg.bar[0], b); float k = scale();
  r[2] = b[0] - 2 * unit_x(); r[0] = r[2] - 34 * k * unit_x(); r[1] = b[1]; r[3] = b[1] + 14 * k * unit_y();
  return 1;
}
static int cursor(int *x, int *y) { return xiui::cursor(x, y); }
// bar*100+slot (both from 1) under the point, -bar over a bar's frame, 1000 the environment tag, 0 elsewhere
static int over(int x, int y) {
  if (ui_hidden()) return 0;
  float t[4]; if (tag_rect(t) && x >= t[0] && x < t[2] && y >= t[1] && y < t[3]) return 1000;
  for (int b = 0; b < HB_BARS; b++) {
    const HbBar &bar = g_cfg.bar[b]; if (!bar.used) continue;
    float r[4]; bar_rect(bar, r);
    if (x < r[0] || x >= r[2] || y < r[1] || y >= r[3]) continue;
    for (int i = 0; i < bar.slots; i++) { float s[4]; slot_rect(bar, i, s); if (x >= s[0] && x < s[2] && y >= s[1] && y < s[3]) return (b + 1) * 100 + i + 1; }
    return -(b + 1);
  }
  return 0;
}

// ---------------------------------------------------------------------------------------------- icons (textures)
struct Tex { char path[260]; IDirect3DTexture8 *tex; int state; };   // state 0 not tried, 1 made, -1 failed
static Tex g_tex[512]; static int g_ntex, g_made_this_frame;
static IDirect3DDevice8 *g_dev;
static Tex *tex_for(const char *path) {
  if (!path[0]) return nullptr;
  for (int i = 0; i < g_ntex; i++) if (!strcmp(g_tex[i].path, path)) return &g_tex[i];
  if (g_ntex == 512) return nullptr;
  Tex *t = &g_tex[g_ntex++]; hb_copy(t->path, sizeof t->path, path); t->tex = nullptr; t->state = 0; return t;
}
static IDirect3DTexture8 *texture(const char *path) {
  Tex *t = tex_for(path); if (!t) return nullptr;
  if (t->state) return t->tex;
  if (!g_dev || g_made_this_frame >= 4) return nullptr;          // a few a frame: no hitch when a set changes
  g_made_this_frame++;
  int w, h; unsigned *px;
  t->state = -1;
  if (!hb_image_load(path, &w, &h, &px)) { g_host->log("hotbar: icon not read: %s", path); return nullptr; }
  IDirect3DTexture8 *tx = nullptr;
  if (g_dev->CreateTexture(w, h, 1, 0, (D3DFORMAT)21 /* A8R8G8B8 */, (D3DPOOL)1 /* MANAGED */, &tx) >= 0 && tx) {
    D3DLOCKED_RECT lr;
    if (tx->LockRect(0, &lr, nullptr, 0) >= 0) {
      for (int y = 0; y < h; y++) memcpy(static_cast<uint8_t *>(lr.pBits) + y * lr.Pitch, px + y * w, w * 4);
      tx->UnlockRect(0); t->tex = tx; t->state = 1;
    } else tx->Release();
  }
  hb_image_free(px);
  return t->tex;
}
static void textures_release() {
  for (int i = 0; i < g_ntex; i++) if (g_tex[i].tex) { g_tex[i].tex->Release(); g_tex[i].tex = nullptr; }
  g_ntex = 0;
}

// ---------------------------------------------------------------------------------------------- reading
static void close_palettes();
static void reload(bool force) {
  const char *dir = g_host->dir ? g_host->dir : ".";
  long long m = hb_mtime(dir);
  if (!force && m == g_mtime) return;
  g_mtime = m;
  static char err[200], note[200]; static HbConfig c; static HbLayout l;
  if (!hb_read(dir, &c, &l, err, sizeof err, note, sizeof note)) { g_host->log("hotbar: %s (no bars)", err); g_cfg = HbConfig(); g_lay = HbLayout(); return; }
  int env_was_set = g_frame > 0;
  if (g_have_ovr) {                                                // "hb job" / "hb set" chose other tables: read with them
    hb_copy(c.job, sizeof c.job, g_ovr.job); hb_copy(c.sub, sizeof c.sub, g_ovr.sub);
    c.nsets = g_ovr.nsets; for (int i = 0; i < c.nsets; i++) hb_copy(c.sets[i], 32, g_ovr.sets[i]);
    hb_read(dir, &c, &l, err, sizeof err, note, sizeof note);       // (the file again, for its own lines)
    hb_copy(c.job, sizeof c.job, g_ovr.job); hb_copy(c.sub, sizeof c.sub, g_ovr.sub);
    c.nsets = g_ovr.nsets; for (int i = 0; i < c.nsets; i++) hb_copy(c.sets[i], 32, g_ovr.sets[i]);
  }
  g_cfg = c; g_lay = l;
  if (!env_was_set) g_env = c.env;
  int n[2] = { 0, 0 };
  for (int e = 0; e < 2; e++) for (int b = 0; b < HB_BARS; b++) for (int i = 0; i < HB_SLOTS; i++) n[e] += g_lay.a[e][b][i].used;
  g_host->log("hotbar: hotbar.txt read: %d bars; slots: field %d, battle %d%s%s%s%s%s%s", g_cfg.nbars, n[0], n[1],
              g_cfg.job[0] ? "; job " : "", g_cfg.job, g_cfg.sub[0] ? "/" : "", g_cfg.sub, err[0] ? "; " : "", err);
  if (note[0]) g_host->log("hotbar: %s", note);
}
// hb job / hb set: the tables to read change; the file is read again with them
static void set_override(const char *job, const char *sub, int toggle_set, const char *set) {
  if (!g_have_ovr) { g_ovr = g_cfg; g_have_ovr = 1; }
  if (job) { hb_copy(g_ovr.job, sizeof g_ovr.job, job); hb_copy(g_ovr.sub, sizeof g_ovr.sub, sub ? sub : ""); }
  if (toggle_set && set && set[0]) {
    int found = -1; for (int i = 0; i < g_ovr.nsets; i++) if (hb_ieq(g_ovr.sets[i], set)) found = i;
    if (found >= 0) { for (int i = found; i + 1 < g_ovr.nsets; i++) hb_copy(g_ovr.sets[i], 32, g_ovr.sets[i + 1]); g_ovr.nsets--; }
    else if (g_ovr.nsets < HB_SETS) hb_copy(g_ovr.sets[g_ovr.nsets++], 32, set);
  }
  reload(true);
}

// ---------------------------------------------------------------------------------------------- running
struct Seq { const HbAct *a; int next; unsigned due; int b, s; const char *how; };   // how: "(key)", "(click)", "(macro key)", "(command)"
static Seq g_seq[8];
static void run_line(const char *text, int b, int s, const char *how) {
  hb_copy(g_last, sizeof g_last, text); g_runs++;
  if (g_host->setting_int("hb_log", 1) || g_host->setting_int("hb_dry", 0))
    g_host->log("hotbar: %d.%d %s %s%s", b + 1, s + 1, how ? how : "", text, g_host->setting_int("hb_dry", 0) ? " (hb_dry: not run)" : "");
  if (g_host->setting_int("hb_dry", 0)) return;
  xiui::run_line(text);
}
static void hb_command(const char *cmd) {
  char w[4][32] = { "", "", "", "" };
  hb_fmt(w[0], 32, "%s", ""); int n = 0; const char *p = cmd;
  while (*p && n < 4) { while (*p == ' ') p++; int l = 0; while (*p && *p != ' ' && l < 31) w[n][l++] = *p++; w[n][l] = 0; if (l) n++; while (*p && *p != ' ') p++; }
  if (n < 2) return;
  if (hb_ieq(w[1], "env")) { g_env = n >= 3 ? (hb_ieq(w[2], "field") ? 0 : 1) : !g_env; g_host->log("hotbar: %s", g_env ? "battle" : "field"); }
  else if (hb_ieq(w[1], "job") && n >= 3) set_override(w[2], n >= 4 ? w[3] : "", 0, nullptr);
  else if (hb_ieq(w[1], "set") && n >= 3) set_override(nullptr, nullptr, 1, w[2]);
  else if (hb_ieq(w[1], "reload")) reload(true);
  else if (hb_ieq(w[1], "hide")) g_hidden_by_cmd = n >= 3 ? !hb_ieq(w[2], "off") : !g_hidden_by_cmd;
  else if (hb_ieq(w[1], "show")) g_hidden_by_cmd = 0;
  else if (hb_ieq(w[1], "mode")) {                          // /hb mode [hotbar|macro]: hb_mode, kept in xikit_mods.ini
    int m = n >= 3 ? (hb_ieq(w[2], "hotbar") ? 1 : hb_ieq(w[2], "macro") || hb_ieq(w[2], "macros") ? 0 : -1) : !g_host->setting_int("hb_mode", 1);
    if (m < 0) g_host->log("hotbar: /hb mode hotbar | macro");
    else { g_host->set_int("hb_mode", m); g_host->log("hotbar: mode %s (the game's macros %s)", m ? "hotbar" : "macro", m ? "run the hotbar's bars 2 and 3, their palettes hidden" : "run as always");
           if (m) close_palettes(); }
  }
  else if (hb_ieq(w[1], "run") && n >= 3) {                 // /hb run 1.3: the slot, as its key or a click runs it
    int b = 0, sl = 0; char dot = 0;
    for (const char *q = w[2]; *q; q++) { if (*q == '.') { if (dot) { b = 0; break; } dot = 1; } else if (*q >= '0' && *q <= '9') { if (dot) sl = sl * 10 + (*q - '0'); else b = b * 10 + (*q - '0'); } else { b = 0; break; } }
    if (b >= 1 && b <= HB_BARS && sl >= 1 && sl <= HB_SLOTS && g_queue_b < 0) { g_queue_b = b - 1; g_queue_s = sl - 1; g_queue_how = "(command)"; }
    else g_host->log("hotbar: /hb run %s: give <bar>.<slot>, bar 1-%d, slot 1-%d", w[2], HB_BARS, HB_SLOTS);
  }
}
static void start_slot(int b, int s, const char *how) {
  const HbAct &a = g_lay.a[g_env][b][s];
  if (!a.used) return;
  g_flash[b][s] = 8;
  if (hb_ieq(a.kind, "hb")) { if (g_host->setting_int("hb_log", 1)) g_host->log("hotbar: %d.%d %s %s", b + 1, s + 1, how, a.line[0]); hb_command(a.line[0]); return; }
  for (int i = 0; i < 8; i++) if (!g_seq[i].a) { g_seq[i] = { &a, 0, hb_now_ms() + (unsigned)a.wait_ms[0], b, s, how }; return; }
  g_host->log("hotbar: 8 macros already running: %d.%d not started", b + 1, s + 1);
}
static void run_due() {
  unsigned now = hb_now_ms();
  for (int i = 0; i < 8; i++) {
    Seq &q = g_seq[i];
    while (q.a && (int)(now - q.due) >= 0) {
      const HbAct *a = q.a;
      run_line(a->line[q.next], q.b, q.s, q.how);
      if (++q.next >= a->nlines) { q.a = nullptr; break; }
      q.due = now + (unsigned)a->wait_ms[q.next];
    }
  }
}
static void seq_clear() { for (int i = 0; i < 8; i++) g_seq[i].a = nullptr; }

static void *game_hwnd() { return xiui::window(); }

static int g_test_force;
static int hb_mode() { return g_host->setting_int("hb_mode", 1); }
// a default key not used in this mode: macros mode, every bar but bar 1; hotbar mode, slots 1-10 of bars 2 and 3
// (the game's macro keys run them, through the QueueEntry hook below)
static bool default_key_off(int b, int i) { return hb_mode() == 0 ? b >= 1 : (b == 1 || b == 2) && i < 10; }
// A key press waits kTypedWait frames (a choice) and runs only if the chat line's text did not change meanwhile
// (xiui::chat_line_stamp): a number typed into the chat line is not a slot press. Which frames the game's message loop
// writes the character in is not read; 3 covers the press frame and two after it.
static const int kTypedWait = 3;
static int g_pend_b = -1, g_pend_s, g_pend_frames; static uint32_t g_pend_stamp; static long g_typed_drops;
static unsigned stamp_now() { return xiui::chat_line_stamp(); }
static bool same_key(const HbKey &a, const HbKey &b) { return a.vk && a.vk == b.vk && a.ctrl == b.ctrl && a.alt == b.alt && a.shift == b.shift; }
static void press(int b, int i, unsigned stamp) { if (g_pend_b < 0) { g_pend_b = b; g_pend_s = i; g_pend_frames = 0; g_pend_stamp = stamp; } }
static int g_msg_ok = -1; static long g_msg_logged;
static void poll_keys() {
  // a pending press: run kTypedWait frames later, unless the chat line's text changed since the key went down
  if (g_pend_b >= 0) {
    if (xiui::chat_line_stamp() != g_pend_stamp) {
      g_typed_drops++;
      if (g_host->setting_int("hb_log", 1)) g_host->log("hotbar: %d.%d (key) not run: the key was typed into the chat line", g_pend_b + 1, g_pend_s + 1);
      g_pend_b = -1;
    } else if (++g_pend_frames >= kTypedWait) {
      if (g_queue_b < 0) { g_queue_b = g_pend_b; g_queue_s = g_pend_s; g_queue_how = "(key)"; }
      g_pend_b = -1;
    }
  }
  if (!g_host->setting_int("hb_keys_poll", 0)) {
    // keys from the window's messages (hotbar_core.cpp): no system call per frame
    if (g_msg_ok < 0 && game_hwnd()) {
      g_msg_ok = hb_msg_install(game_hwnd(), stamp_now);
      g_host->log(g_msg_ok ? "hotbar: keys from the game window's messages" : "hotbar: could not subclass the game window: set hb_keys_poll=1 for keys");
    }
    if (!g_msg_logged && hb_msg_seen()) { g_msg_logged = 1; g_host->log("hotbar: the first key message reached the window procedure (keys by message work)"); }
    HbPress p;
    while (hb_msg_next(&p)) {
      if (same_key(p.key, g_cfg.env_key)) { g_env = !g_env; continue; }
      for (int b = 0; b < HB_BARS; b++) for (int i = 0; i < HB_SLOTS; i++) {
        const HbKey &k = g_cfg.bar[b].key[i];
        if ((k.dflt && default_key_off(b, i)) || b >= g_cfg.nbars || !g_cfg.bar[b].used) continue;
        if (same_key(p.key, k)) { press(b, i, p.stamp); goto next; }
      }
      next:;
    }
    return;
  }
  // hb_keys_poll=1: the old way, a GetAsyncKeyState per bound key per frame
  int fg = g_test_force || hb_is_foreground(game_hwnd());
  for (int b = 0; b < HB_BARS; b++) for (int i = 0; i < HB_SLOTS; i++) {
    const HbKey &k = g_cfg.bar[b].key[i];
    if (k.dflt && default_key_off(b, i)) { g_prev_key[b][i] = 0; continue; }
    if (!k.vk || (b >= g_cfg.nbars) || !g_cfg.bar[b].used) { g_prev_key[b][i] = 0; continue; }
    int d = fg && hb_key_down(&k);
    if (d && !g_prev_key[b][i]) press(b, i, xiui::chat_line_stamp());
    g_prev_key[b][i] = d;
  }
  int d = g_cfg.env_key.vk && fg && hb_key_down(&g_cfg.env_key);
  if (d && !g_prev_env_key) g_env = !g_env;
  g_prev_env_key = d;
}

// ---------------------------------------------------------------------------------------------- drawing
struct Vtx { float x, y, z, rhw; unsigned color; };
struct TVtx { float x, y, z, rhw; unsigned color; float u, v; };
static Vtx g_v[6000]; static int g_nv;
static void quad(float x0, float y0, float x1, float y1, unsigned top, unsigned bottom) {
  if (g_nv + 6 > 6000) return;
  Vtx a = { x0, y0, 0, 1, top }, b = { x1, y0, 0, 1, top }, c = { x0, y1, 0, 1, bottom }, d = { x1, y1, 0, 1, bottom };
  g_v[g_nv++] = a; g_v[g_nv++] = b; g_v[g_nv++] = c; g_v[g_nv++] = b; g_v[g_nv++] = d; g_v[g_nv++] = c;
}
static void frame(float x0, float y0, float x1, float y1, float t, unsigned c) {
  quad(x0, y0, x1, y0 + t, c, c); quad(x0, y1 - t, x1, y1, c, c); quad(x0, y0 + t, x0 + t, y1 - t, c, c); quad(x1 - t, y0 + t, x1, y1 - t, c, c);
}
static void text(float x, float y, const char *s, unsigned color, float sc) { xiui::text(x, y, s, color, sc); }
static float measure(const char *s) { return xiui::text_width(s); }

static const D3DRENDERSTATETYPE k_rs[] = { D3DRS_ZENABLE, D3DRS_ZWRITEENABLE, D3DRS_LIGHTING, D3DRS_FOGENABLE, D3DRS_CULLMODE,
                                           D3DRS_ALPHATESTENABLE, D3DRS_ALPHABLENDENABLE, D3DRS_SRCBLEND, D3DRS_DESTBLEND };
static const D3DTEXTURESTAGESTATETYPE k_ts[] = { D3DTSS_COLOROP, D3DTSS_COLORARG1, D3DTSS_COLORARG2, D3DTSS_ALPHAOP, D3DTSS_ALPHAARG1,
                                                 D3DTSS_ALPHAARG2, D3DTSS_MAGFILTER, D3DTSS_MINFILTER };
struct Saved { unsigned rs[sizeof k_rs / sizeof *k_rs], ts[sizeof k_ts / sizeof *k_ts], vs; IDirect3DBaseTexture8 *tex; };
static void save(IDirect3DDevice8 *dev, Saved &s) {
  for (unsigned i = 0; i < sizeof k_rs / sizeof *k_rs; i++) dev->GetRenderState(k_rs[i], &s.rs[i]);
  for (unsigned i = 0; i < sizeof k_ts / sizeof *k_ts; i++) dev->GetTextureStageState(0, k_ts[i], &s.ts[i]);
  s.vs = 0; dev->GetVertexShader(&s.vs); s.tex = nullptr; dev->GetTexture(0, &s.tex);
}
static void restore(IDirect3DDevice8 *dev, const Saved &s) {
  for (unsigned i = 0; i < sizeof k_rs / sizeof *k_rs; i++) dev->SetRenderState(k_rs[i], s.rs[i]);
  for (unsigned i = 0; i < sizeof k_ts / sizeof *k_ts; i++) dev->SetTextureStageState(0, k_ts[i], s.ts[i]);
  dev->SetVertexShader(s.vs); dev->SetTexture(0, s.tex);
}
static void plain_states(IDirect3DDevice8 *dev) {
  const unsigned rsn[] = { 0, 0, 0, 0, CULL_NONE, 0, 1, BLEND_SRCALPHA, BLEND_INVSRCALPHA };
  for (unsigned i = 0; i < sizeof k_rs / sizeof *k_rs; i++) dev->SetRenderState(k_rs[i], rsn[i]);
  dev->SetTextureStageState(0, D3DTSS_COLOROP, TOP_SELECTARG1); dev->SetTextureStageState(0, D3DTSS_COLORARG1, TA_DIFFUSE);
  dev->SetTextureStageState(0, D3DTSS_ALPHAOP, TOP_SELECTARG1); dev->SetTextureStageState(0, D3DTSS_ALPHAARG1, TA_DIFFUSE);
  dev->SetTexture(0, nullptr); dev->SetVertexShader(FVF_XYZRHW | FVF_DIFFUSE);
}
static void flush_quads(IDirect3DDevice8 *dev) { if (g_nv) dev->DrawPrimitiveUP(D3DPT_TRIANGLELIST, g_nv / 3, g_v, sizeof(Vtx)); g_nv = 0; }
static void icon(IDirect3DDevice8 *dev, IDirect3DTexture8 *t, float x0, float y0, float x1, float y1, unsigned c) {
  TVtx v[4] = { { x0, y0, 0, 1, c, 0, 0 }, { x1, y0, 0, 1, c, 1, 0 }, { x0, y1, 0, 1, c, 0, 1 }, { x1, y1, 0, 1, c, 1, 1 } };
  dev->SetTexture(0, reinterpret_cast<IDirect3DBaseTexture8 *>(t));
  dev->DrawPrimitiveUP((D3DPRIMITIVETYPE)5, 2, v, sizeof(TVtx));
}

static void draw(IDirect3DDevice8 *dev) {
  int cx = -1, cy = -1; cursor(&cx, &cy); int hov = over(cx, cy);
  int show_empty = g_host->setting_int("hb_empty", 1);
  Saved sv; save(dev, sv);
  plain_states(dev);
  float t = unit_x() * scale();
  for (int b = 0; b < HB_BARS; b++) {
    const HbBar &bar = g_cfg.bar[b]; if (!bar.used) continue;
    float r[4]; bar_rect(bar, r);
    quad(r[0], r[1], r[2], r[3], 0xB0182848u, 0xB0080C20u);            // the window: dark blue, lighter at the top
    frame(r[0], r[1], r[2], r[3], t, 0x90A8B0C8u);
    for (int i = 0; i < bar.slots; i++) {
      const HbAct &a = g_lay.a[g_env][b][i];
      if (!a.used && !show_empty) continue;
      float s[4]; slot_rect(bar, i, s);
      unsigned fill = g_flash[b][i] > 0 ? 0xC0806020u : a.used ? 0xA0060A18u : 0x60060A18u;
      quad(s[0], s[1], s[2], s[3], fill, fill);
      frame(s[0], s[1], s[2], s[3], t, hov == (b + 1) * 100 + i + 1 ? 0xFFFFA040u : 0x80707890u);
    }
  }
  float tg[4];
  if (tag_rect(tg)) { quad(tg[0], tg[1], tg[2], tg[3], 0xB0182848u, 0xB0080C20u); frame(tg[0], tg[1], tg[2], tg[3], t, hov == 1000 ? 0xFFFFA040u : 0x90A8B0C8u); }
  flush_quads(dev);
  // icons
  dev->SetVertexShader(FVF_XYZRHW | FVF_DIFFUSE | FVF_TEX1);
  dev->SetTextureStageState(0, D3DTSS_COLOROP, TOP_MODULATE); dev->SetTextureStageState(0, D3DTSS_COLORARG1, TA_TEXTURE); dev->SetTextureStageState(0, D3DTSS_COLORARG2, TA_DIFFUSE);
  dev->SetTextureStageState(0, D3DTSS_ALPHAOP, TOP_MODULATE); dev->SetTextureStageState(0, D3DTSS_ALPHAARG1, TA_TEXTURE); dev->SetTextureStageState(0, D3DTSS_ALPHAARG2, TA_DIFFUSE);
  dev->SetTextureStageState(0, D3DTSS_MAGFILTER, TEXF_LINEAR); dev->SetTextureStageState(0, D3DTSS_MINFILTER, TEXF_LINEAR);
  for (int b = 0; b < HB_BARS; b++) {
    const HbBar &bar = g_cfg.bar[b]; if (!bar.used) continue;
    for (int i = 0; i < bar.slots; i++) {
      const HbAct &a = g_lay.a[g_env][b][i]; if (!a.used || !a.icon[0]) continue;
      IDirect3DTexture8 *tx = texture(a.icon); if (!tx) continue;
      float s[4]; slot_rect(bar, i, s); float m = t;
      icon(dev, tx, s[0] + m, s[1] + m, s[2] - m, s[3] - m, 0xFFFFFFFFu);
    }
  }
  // text with the game's states (FontGlyphs_DrawString leaves the colour operation to them)
  restore(dev, sv);
  for (int b = 0; b < HB_BARS; b++) {
    const HbBar &bar = g_cfg.bar[b]; if (!bar.used) continue;
    for (int i = 0; i < bar.slots; i++) {
      const HbAct &a = g_lay.a[g_env][b][i]; float s[4]; slot_rect(bar, i, s);
      float w = s[2] - s[0], h = s[3] - s[1];
      const HbKey &k = bar.key[i];
      if (k.name[0] && (a.used || show_empty)) text(s[0] + 1, s[1], k.name, 0x80606060u, 0.4f * unit_x() * scale());
      if (!a.used) continue;
      if (a.mp || a.tp) {
        char c[12]; hb_fmt(c, sizeof c, "%d", a.mp ? a.mp : a.tp);
        float sc = 0.4f * unit_x() * scale(); text(s[2] - measure(c) * sc - 1, s[1], c, a.mp ? 0x80508080u : 0x80807040u, sc);
      }
      if (a.label[0]) {
        float sc = 0.5f * unit_x() * scale(), mw = measure(a.label) * sc;
        if (mw > w - 2 && mw > 0) { sc *= (w - 2) / mw; mw = w - 2; }
        unsigned c = hov == (b + 1) * 100 + i + 1 ? 0x80805020u : 0x80808080u;
        text(s[0] + (w - mw) / 2, s[1] + h - 16 * sc - 1, a.label, c, sc);
      }
    }
  }
  if (tag_rect(tg)) {
    char tag[40]; hb_fmt(tag, sizeof tag, "%s", g_env ? "Battle" : "Field");
    float sc = 0.45f * unit_x() * scale(); text(tg[0] + 2, tg[1] + 1, tag, hov == 1000 ? 0x80805020u : 0x80808080u, sc);
  }
  // the tooltip over the hovered slot: its label, then its line
  if (hov > 0 && hov < 1000 && g_host->setting_int("hb_tips", 1)) {
    int b = hov / 100 - 1, i = hov % 100 - 1; const HbAct &a = g_lay.a[g_env][b][i];
    if (a.used) {
      float s[4]; slot_rect(g_cfg.bar[b], i, s); float sc = 0.5f * unit_x() * scale();
      const char *l2 = a.tip[0] ? a.tip : a.line[0];
      float w = measure(a.label) * sc, w2 = measure(l2) * sc; if (w2 > w) w = w2;
      float x0 = s[0], y1 = s[1] - 2 * unit_y(), y0 = y1 - 34 * sc;
      plain_states(dev); quad(x0, y0, x0 + w + 8 * sc, y1, 0xD0182848u, 0xD0080C20u); frame(x0, y0, x0 + w + 8 * sc, y1, t, 0x90A8B0C8u); flush_quads(dev);
      restore(dev, sv);
      text(x0 + 4 * sc, y0 + 1, a.label, 0x80805020u, sc);
      text(x0 + 4 * sc, y0 + 17 * sc, l2, 0x80808080u, sc);
    }
  }
  restore(dev, sv);
  if (sv.tex) sv.tex->Release();                                     // GetTexture added a reference
}

// ---------------------------------------------------------------------------------------------- hooks
static xikit::fn<decltype(&Menu_DrawLayers)> prev_Draw;
static void __thiscall my_Draw(void *mng) {
  prev_Draw(mng);                                     // the game's windows first; the bars over them
  if (!g_host->setting_int("hb_show", 1)) return;
  if (++g_frame % 30 == 0) reload(false);
  g_made_this_frame = 0;
  for (int b = 0; b < HB_BARS; b++) for (int i = 0; i < HB_SLOTS; i++) if (g_flash[b][i] > 0) g_flash[b][i]--;
  poll_keys();
  CDx *cdx = *xikit::game<CDx *>(0x1045666Cu);
  if (cdx && cdx->pDevice) { g_dev = cdx->pDevice; if (!ui_hidden()) draw(cdx->pDevice); }
  if (g_queue_tag) { g_queue_tag = 0; g_env = !g_env; }
  if (g_queue_b >= 0) { int b = g_queue_b, i = g_queue_s; g_queue_b = g_queue_s = -1; start_slot(b, i, g_queue_how); }
  run_due();
}

static xikit::fn<decltype(&Target_PickNearestToPoint)> prev_Pick;
static bits32 __thiscall my_Pick(void *self) {
  int x, y;
  if (g_host->setting_int("hb_show", 1) && cursor(&x, &y) && over(x, y)) { *(reinterpret_cast<uint8_t *>(self) + 0x55) = 0; return 0; }
  return prev_Pick(self);
}
// the left button: kept from the game over a bar
static xikit::fn<decltype(&Cursor_EnterMode1)> prev_Down;
static void __thiscall my_Down(void *self) {
  int x, y, o;
  if (g_host->setting_int("hb_show", 1) && cursor(&x, &y) && (o = over(x, y)) != 0) {
    g_swallow = 1;
    if (o == 1000) g_queue_tag = 1;
    else if (o > 0 && g_queue_b < 0) { g_queue_b = o / 100 - 1; g_queue_s = o % 100 - 1; g_queue_how = "(click)"; }
    return;
  }
  prev_Down(self);
}
static xikit::fn<decltype(&Cursor_ToggleFlag1)> prev_Up;
static void __thiscall my_Up(void *self) {
  if (g_swallow) { g_swallow = 0; return; }
  prev_Up(self);
}

// typed "/hb ..." lines (xikit_cmd.hpp): the same commands a slot can hold
// The game's macro, started: in hotbar mode, the hotbar's slot instead (see the first comment)
static long g_macro_taken, g_macro_passed;
static xikit::fn<decltype(&TextInputFiles_QueueEntry)> prev_Queue;
static bits32 __thiscall my_Queue(void *self, int n) {
  if (hb_mode() == 1 && n >= 0 && n < 20 && g_host->setting_int("hb_show", 1) && !g_hidden_by_cmd) {
    int b = n < 10 ? 1 : 2, i = n % 10;                       // palette 1 -> bar 2, palette 2 -> bar 3 (0-based 1, 2)
    if (g_cfg.bar[b].used && i < g_cfg.bar[b].slots && g_lay.a[g_env][b][i].used) {
      if (g_queue_b < 0) { g_queue_b = b; g_queue_s = i; g_queue_how = "(macro key)"; }
      g_macro_taken++;
      return 1;                                               // what QueueEntry returns for an entry it took
    }
  }
  g_macro_passed++;
  return prev_Queue(self, n);
}
extern "C" __declspec(dllexport) void hb_test_macros(long *taken, long *passed) { *taken = g_macro_taken; *passed = g_macro_passed; }

// The game's macro palettes, never shown in hotbar mode. TextInputFiles_UpdateMenuState (0x101A2E80) is the only code
// that opens them: MenuMng_OpenByName (0x1015E350) with "menu    mcr1pall" or "menu    mcr2pall" (the requested name;
// MenuMng_BuildMenuName maps it to the window's own, e.g. mcr1long). It keeps its Ctrl/Alt state (+0xC, +0xD) whether
// or not the window opens, and the macro keys read that state, so the keys still reach TextInputFiles_QueueEntry.
static long g_pal_refused;
static bool is_palette(const char *n) {
  return n && (!strncmp(n, "menu    mcr1pall", 16) || !strncmp(n, "menu    mcr2pall", 16)) && !n[16];
}
static xikit::fn<decltype(&MenuMng_OpenByName)> prev_Open;
static int __thiscall my_Open(void *self, char *name, bits32 a, bits32 b) {
  if (hb_mode() == 1 && is_palette(name)) { g_pal_refused++; return 0; }   // 0: what it returns when it opens nothing
  return prev_Open(self, name, a, b);
}
// close an open palette (hotbar mode turned on while one shows); Menu_CloseEntry does nothing for a window not open
static void close_palettes() {
  orig::Menu_CloseEntry(&g_menuMng_as_v0, (char *)"menu    mcr1pall");
  orig::Menu_CloseEntry(&g_menuMng_as_v0, (char *)"menu    mcr2pall");
}
extern "C" __declspec(dllexport) long hb_test_palettes(void) { return g_pal_refused; }

static void typed_hb(const char *args) { char l[200]; hb_fmt(l, sizeof l, "hb %s", args); hb_command(l); }
extern "C" __declspec(dllexport) void xikit_mod_settings(void) { reload(true); if (hb_mode() == 1) close_palettes(); }
extern "C" __declspec(dllexport) void xikit_mod_unload(void) { seq_clear(); textures_release(); hb_msg_uninstall(); }

// ---------------------------------------------------------------------------------------------- for the offline test (mode hbmod)
extern "C" __declspec(dllexport) int hb_test_over(int x, int y) { return over(x, y); }
extern "C" __declspec(dllexport) int hb_test_rect(int b, int i, float *r4) {
  if (b < 1 || b > HB_BARS || !g_cfg.bar[b - 1].used) return 0;
  if (i <= 0) bar_rect(g_cfg.bar[b - 1], r4); else slot_rect(g_cfg.bar[b - 1], i - 1, r4);
  return 1;
}
extern "C" __declspec(dllexport) int hb_test_state(int *nbars, int *slots, char *last, int lastlen) {
  int n = 0; for (int b = 0; b < HB_BARS; b++) for (int i = 0; i < HB_SLOTS; i++) n += g_lay.a[g_env][b][i].used;
  *nbars = g_cfg.nbars; *slots = n; hb_copy(last, lastlen, g_last); return (int)g_runs;
}
extern "C" __declspec(dllexport) void hb_test_force_focus(int on) { g_test_force = on; }
// the offline test: key messages from a window of the test's own (the host has no game window to subclass)
extern "C" __declspec(dllexport) int hb_test_msg_window(void *hwnd) { g_msg_ok = hb_msg_install(hwnd, stamp_now); return g_msg_ok; }
extern "C" __declspec(dllexport) long hb_test_typed_drops(void) { return g_typed_drops; }
extern "C" __declspec(dllexport) int hb_test_env(int set) { if (set >= 0) g_env = set; return g_env; }
// a slot of the current environment: its label, first line, line count, icon (whether it names a file) and a texture made
extern "C" __declspec(dllexport) int hb_test_slot(int b, int s, char *label, char *line0, int *nlines, int *has_icon, int *mp) {
  if (b < 1 || b > HB_BARS || s < 1 || s > HB_SLOTS) return 0;
  const HbAct &a = g_lay.a[g_env][b - 1][s - 1];
  hb_copy(label, 48, a.label); hb_copy(line0, 200, a.line[0]); *nlines = a.nlines; *has_icon = a.icon[0] != 0; *mp = a.mp; return a.used;
}
extern "C" __declspec(dllexport) int hb_test_textures(void) { int n = 0; for (int i = 0; i < g_ntex; i++) n += g_tex[i].state == 1; return n; }

static const char *k_default =
  "# Longthinx hotbar. Changes are read while the game runs.\n"
  "#   bar <n 1-10> <slots 1-12> <x> <y> [v]  in the interface's 640x480 units; a negative x or y counts from the\n"
  "#                                          right or bottom edge; v: the slots go down instead of across\n"
  "#   [field|battle] <bar>.<slot> <key> <label> = <command line>[; wait 2; <command line>...] [| icon]\n"
  "#   key <bar>.<slot> <key>                  a key for a slot (also for XIVhotbar2's slots)\n"
  "#   xiv <folder>                            XIVhotbar2's folder (data, images, priv_res): its job files, icons, costs\n"
  "#   xiv keys                                its data\\default_keybinds.lua for the keys\n"
  "#   job <job> [<subjob>]   set <name>       which of its tables to read (General's Root, the job's Base, the subjob's\n"
  "#                                          table, the sets); \"hb job\" and \"hb set\" change them while playing\n"
  "#   env field|battle       envkey <key>     the starting set, and a key that switches field <-> battle\n"
  "# Keys: 1-0 - = [ ] ; ' , . / ` a-z f1-f12 num0-num9, with c- (Ctrl) a- (Alt) s- (Shift) in front, or none.\n"
  "# Without a key of its own, slot 1-12 of bar 1 is 1 2 3 4 5 6 7 8 9 0 - =, bar 2 the same with Ctrl, bar 3 with Alt,\n"
  "# bar 4 with Shift (\"key 1.1 none\" takes one away). A slot line's key \"none\" keeps the default.\n"
  "# /hb mode hotbar (the default): the game's macro keys run bars 2 and 3 instead of its macros (an empty slot\n"
  "# leaves the game's macro); /hb mode macro: the game's macros as always, keys for bar 1.\n"
  "# A line runs as if typed in the chat line and sent. The hotbar does not take keys away from the game; a key typed\n"
  "# into the chat line runs nothing (a slot runs 3 frames after its key, if the chat line's text did not change). Commands of the hotbar itself, typed in the chat line: /hb env [field|battle],\n"
  "# /hb run <bar>.<slot>, /hb mode [hotbar|macro], /hb job <job> [<sub>], /hb set <name>, /hb reload, /hb hide, /hb show.\n"
  "# Click the Field/Battle tag left of bar 1 to switch too.\n"
  "bar 1 12 165 -110\n"
  "bar 2 12 165 -140\n"
  "1.1 none Attack = /attack <t>\n"
  "1.2 none Check = /check <t>\n"
  "1.3 none Heal = /heal\n"
  "1.4 none Follow = /follow <t>\n"
  "1.5 none Map = /map\n"
  "2.1 none Wave = /wave\n"
  "2.2 none Bow = /bow\n";

extern "C" __declspec(dllexport) int xikit_mod_init(const XikitHost *host) {
  g_host = host;
  host->declare_int("hb_show", 1, 0, 1, "1: show the hotbar (clicks work only while it shows; keys while hb_show is 1)");
  host->declare_int("hb_dry", 0, 0, 1, "1: log a slot's line instead of running it (to try a hotbar.txt)");
  host->declare_int("hb_log", 1, 0, 1, "1: a line in xikit.log each time a slot runs");
  host->declare_int("hb_scale", 100, 50, 300, "the bars' size in percent");
  host->declare_int("hb_empty", 1, 0, 1, "1: draw empty slots");
  host->declare_int("hb_tips", 1, 0, 1, "1: a tooltip (the label and the line) over the slot under the cursor");
  host->declare_int("hb_keys_poll", 0, 0, 1, "1: read keys by polling each frame (a system call per key per frame); 0: from the game window's messages");
  host->declare_int("hb_mode", 1, 0, 1, "1 hotbar: the game's macro keys run bars 2 and 3 and its macro palettes stay hidden; 0 macro: the game's macros run, keys for bar 1 (/hb mode)");
  const char *dir = host->dir ? host->dir : ".";
  if (!hb_mtime(dir) && hb_write_file(dir, "hotbar.txt", k_default)) host->log("hotbar: wrote an example hotbar.txt");
  reload(true);
  xicmd::add("hb", typed_hb);
  if (xicmd::install(host) != XIKIT_OK) host->log("hotbar: Command_RunLine not hooked: typed /hb commands go to the game");
  int r = XI_HOOK(host, Menu_DrawLayers, my_Draw, prev_Draw);
  if (!r) r = XI_HOOK(host, Target_PickNearestToPoint, my_Pick, prev_Pick);
  if (r) return r;
  if (XI_HOOK(host, TextInputFiles_QueueEntry, my_Queue, prev_Queue))
    host->log("hotbar: TextInputFiles_QueueEntry not hooked: the game's macros always run (hotbar mode has no effect)");
  if (XI_HOOK(host, MenuMng_OpenByName, my_Open, prev_Open))
    host->log("hotbar: MenuMng_OpenByName not hooked: the game's macro palettes show in hotbar mode");
  if (XI_HOOK(host, Cursor_EnterMode1, my_Down, prev_Down) || XI_HOOK(host, Cursor_ToggleFlag1, my_Up, prev_Up))
    host->log("hotbar: the left-button hooks were refused: slots are not clickable (keys work)");
  return 0;
}
