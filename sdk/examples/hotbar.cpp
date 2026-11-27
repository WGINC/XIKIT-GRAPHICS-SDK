// hotbar.cpp -- action bars for the game, drawn in the game's menu layer with its own font; XIVhotbar2's job files
// (the reference: XIVhotbar2 Petit Trois Edition, WGINC/XIVhotbar2-Petit_Trois_Edition, the owner's rewrite),
// icons and keybinds read directly. Build:
//   sdk/build_mod.sh hotbar.dll sdk/examples/hotbar.cpp sdk/examples/hotbar_core.cpp -- -lwindowscodecs -lole32
//
// What it does: up to 10 bars of up to 12 slots (across, or down with "v"), laid out in <kit folder>\hotbar.txt
// (written with examples the first time; read again when it changes). A slot holds one command line, or several
// separated by ';' with "wait N" (seconds) between them, as a game macro does; or an XIVhotbar2 entry (ma, ja, ws, pet,
// item, ra, input, macro, ct) from its job files (General.lua's Root, <job>.lua's Base, its subjob's table, and any
// sets named). Pressing the slot's key or clicking it runs it through the game's own command line, exactly as typing
// it and pressing Enter does, one line per press except a macro's own lines. The mod sends nothing itself.
// "htb ..." lines are the hotbar's own, typed as /htb (Petit Trois's //htb; one slash, as there is no Windower): htb env
// [field|battle] (the field and battle sets, as XIVhotbar2's), htb job <job> [<subjob>], htb set <name> (a set on or
// off), htb reload, htb hide; and Petit Trois's (29 Nov): htb move (layout mode and the action picker, below), htb set
// <row> <slot> <type> <action> [target] [alias], htb clear|delete <row> <slot>, htb rename <row> <slot> <label>
// (underscores for spaces), htb execute <row> <slot>; and htb bar <n> <slots> [h|v], htb bar <n> off. A slot line
// "hb ..." (hotbar.txt files before 29 Nov) still runs as "htb ...".
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
// Recasts: shown since 28 Nov (hb_recasts); the job followed since 28 Nov; the learned spells read since 29 Nov (the
// picker lists them; xistate::spell_learned). Not read yet (so not done): engagement, weapon and pet (XIVhotbar2
// switches sets on them; here "htb env", "htb set" or hotbar.txt choose them), the abilities and weapon skills a
// character has, inventory counts, skillchains. Unlearned entries in the job files still show (XIVhotbar2 drops them).
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
// - The mode (hb_mode, "/htb mode"): 1 hotbar (the default): the game's macro palettes are never shown (the hook of
//   MenuMng_OpenByName below), and a macro the game starts runs the hotbar's slot instead,
//   palette 1's macro N on bar 2 slot N, palette 2's on bar 3 (N 1-10; 0 is slot 10); an empty slot there, or the
//   bars hidden, leaves the game's macro to run. Bars 2 and 3 then have no keys of their own for slots 1-10 (the
//   game's macro keys are theirs), so a press runs one slot. 0 macros: the game's macros run as always; of the default
//   keys only bar 1's are on (keys bound in hotbar.txt stay on).
//
// Settings ([hotbar] in xikit_mods.ini): hb_show, hb_dry (log instead of run), hb_log, hb_scale (percent),
// hb_empty (1: draw empty slots), hb_tips (1: a tooltip over a hovered slot), hb_mode (1 hotbar, 0 macros); (29 Nov,
// also in the picker's Cfg tab) hb_gap, hb_names, hb_costs, hb_keys, hb_bg (backdrop), hb_alpha.
// (29 Nov) Each slot shows what the game's own menus show (the analysis repository's HOTBAR_CURSOR.md 2, 2a, 2b): the
// recast from the game's countdowns, the charges (BST Ready, SCH Stratagems, COR Quick Draw) from MenuPanels_GetSlotInfo,
// and the game's own usability checks (dimmed when they say no; the reason in the tooltip); the picker lists what the
// character has (the game's spell and ability lists). FFXIV's parts: the cooldown sweep, charges, bar shapes, shared bars.
// Tested offline (kit/xikit/test, modes hbmod and staterun). Not run in the game in this version.
#include "xikit_sdk.hpp"
#include "xikit_state.hpp"
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


static const int S = 22, P = 4;               // slot, padding (640x480 units, before hb_scale)
static int gap();                              // between slots: hb_gap (Petit Trois's SlotSpacing), 3 by default
static int g_edit;                             // (29 Nov) layout mode (/htb move): bars and slots dragged, the picker open
static int edit_over(int x, int y);            // in layout mode: the picker (5000 + its part) or a bar's handle (2000 + ...)
static unsigned target_id();                   // (29 Nov) skillchains: the target's id; the test's target; the hook's counts
static unsigned g_test_target; static long g_sc_seen, g_sc_used; static int g_sc_hooked;

static float unit_x() { return xiui::unit_x(); }
static float unit_y() { return xiui::unit_y(); }
static float scale() { return g_host->setting_int("hb_scale", 100) / 100.0f; }
static int ui_hidden() { return xiui::interface_hidden() || g_hidden_by_cmd; }
static int gap() { int g = g_host->setting_int("hb_gap", 3); return g < 0 ? 0 : g > 12 ? 12 : g; }

// (29 Nov) a bar is cols slots a row, as many rows as it takes (FFXIV's shapes: 12x1 .. 1x12)
static int bar_cols(const HbBar &b) { return b.cols >= 1 && b.cols <= b.slots ? b.cols : b.slots; }
static int bar_rows(const HbBar &b) { int c = bar_cols(b); return (b.slots + c - 1) / c; }
static void bar_rect(const HbBar &b, float r[4]) {
  float k = scale(); int c = bar_cols(b), n = bar_rows(b);
  float w = (P * 2 + c * S + (c - 1) * gap()) * k, h = (P * 2 + n * S + (n - 1) * gap()) * k;
  float x = b.x < 0 ? 640 + b.x - w : b.x, y = b.y < 0 ? 480 + b.y - h : b.y;
  r[0] = x * unit_x(); r[1] = y * unit_y(); r[2] = (x + w) * unit_x(); r[3] = (y + h) * unit_y();
}
static void slot_rect(const HbBar &b, int i, float r[4]) {
  float br[4]; bar_rect(b, br); float k = scale(); int c = bar_cols(b);
  float ox = (P + (i % c) * (S + gap())) * k, oy = (P + (i / c) * (S + gap())) * k;
  r[0] = br[0] + ox * unit_x(); r[1] = br[1] + oy * unit_y();
  r[2] = r[0] + S * k * unit_x(); r[3] = r[1] + S * k * unit_y();
}
// the environment tag, left of bar 1 (click: field <-> battle)
static int tag_rect(float r[4]) {
  if (!g_cfg.bar[0].used) return 0;
  float b[4]; bar_rect(g_cfg.bar[0], b); float k = scale();
  r[2] = b[0] - (g_host->setting_int("hb_barnums", 1) ? 10 : 2) * unit_x(); r[0] = r[2] - 34 * k * unit_x(); r[1] = b[1]; r[3] = b[1] + 14 * k * unit_y();
  return 1;
}
static int cursor(int *x, int *y) { return xiui::cursor(x, y); }
// bar*100+slot (both from 1) under the point, -bar over a bar's frame, 1000 the environment tag, 0 elsewhere
static int over(int x, int y) {
  if (ui_hidden()) return 0;
  if (g_edit) { int e = edit_over(x, y); if (e) return e; }
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
static void inventory_read();
static int g_user_job;   // "hb job" was typed: the game's own job is not followed until "hb job game"
static void reload(bool force) {
  const char *dir = g_host->dir ? g_host->dir : ".";
  long long m = hb_mtime(dir);
  if (!force && m == g_mtime) return;
  g_mtime = m;
  static char err[200], note[200]; static HbConfig c; static HbLayout l;
  inventory_read();                                                 // (autoitem slots are made from it)
  // "htb job" / "htb set" / the game's job chose other tables: hb_read reads with them (29 Nov: before, they were set
  // here and cleared by hb_read, so the tables read stayed hotbar.txt's)
  if (!hb_read(dir, &c, &l, err, sizeof err, note, sizeof note, g_have_ovr ? &g_ovr : nullptr)) { g_host->log("hotbar: %s (no bars)", err); g_cfg = HbConfig(); g_lay = HbLayout(); return; }
  int env_was_set = g_frame > 0;
  g_cfg = c; g_lay = l;
  if (!env_was_set) g_env = c.env;
  int n[2] = { 0, 0 };
  for (int e = 0; e < 2; e++) for (int b = 0; b < HB_BARS; b++) for (int i = 0; i < HB_SLOTS; i++) n[e] += g_lay.a[e][b][i].used;
  g_host->log("hotbar: hotbar.txt read: %d bars; slots: field %d, battle %d%s%s%s%s%s%s", g_cfg.nbars, n[0], n[1],
              g_cfg.job[0] ? "; job " : "", g_cfg.job, g_cfg.sub[0] ? "/" : "", g_cfg.sub, err[0] ? "; " : "", err);
  if (note[0]) g_host->log("hotbar: %s", note);
  { static char last[200]; const char *dn = hb_dat_note(); if (dn[0] && strcmp(dn, last)) { hb_copy(last, sizeof last, dn); g_host->log("hotbar: %s", dn); } }
}
// (29 Nov) items: the game's inventory (xistate::item: the message handlers' table), as Petit Trois reads Windower's
// get_items: bag 3 (temporary items) then bag 0 (the inventory), Windower's bag numbers (a lead). An item slot's count
// is the sum over those two bags (player.lua update_inventory_items); autoitem slots are made from the same list.
static HbInvItem g_invl[2 * 0x51]; static int g_ninvl; static unsigned g_inv_hash; static int g_inv_known;
static int g_test_inv = -1;                                       // (tests: the inventory hotbar.cpp reads is a test's)
static void inventory_read() {
  int n = 0; unsigned h = 2166136261u; g_inv_known = xistate::game_state() != nullptr;
  const int bags[2] = { 3, 0 };
  for (int k = 0; k < 2; k++) for (int i = 1; i < xistate::kBagSlots && n < (int)(sizeof g_invl / sizeof g_invl[0]); i++) {
    int id, c; if (!xistate::item(bags[k], i, &id, &c)) continue;
    g_invl[n].id = id; g_invl[n].count = c; n++; h = (h ^ (unsigned)id) * 16777619u; h = (h ^ (unsigned)c) * 16777619u;
  }
  g_ninvl = n; g_inv_hash = h;
  hb_set_inventory(g_invl, n);
}
static int item_count(int id) { int c = 0; for (int i = 0; i < g_ninvl; i++) if (g_invl[i].id == id) c += g_invl[i].count; return c; }
static bool has_spec(const char *pre) { size_t n = strlen(pre); for (int e = 0; e < 2; e++) for (int b = 0; b < HB_BARS; b++) for (int i = 0; i < HB_SLOTS; i++) if (!strncmp(g_lay.a[e][b][i].spec, pre, n)) return true; return false; }
static bool has_autoitem() { return has_spec("xiv|autoitem|"); }
// (29 Nov) the game's learned abilities (0x160 bytes at game state +0x2CDE8, xistate::ability_learned): bstpet slots are
// made from them, so a change makes them again (Petit Trois reloads when an ability is learned)
static unsigned learned_hash() {
  uint8_t *g = xistate::game_state(); if (!g || !g[0x2CF49] || !g[0x2CF4A]) return 0;
  unsigned h = 2166136261u; for (int i = 0; i < 0x160; i++) h = (h ^ g[0x2CDE8 + i]) * 16777619u; return h;
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
static void toggle_edit(int on);
static void save_slot(int b, int s, const char *spec);
static void save_bars();
static int num(const char *s) { int v = 0; if (!*s) return 0; for (; *s; s++) { if (*s < '0' || *s > '9') return 0; v = v * 10 + (*s - '0'); } return v; }
static void unders(char *s) { for (; *s; s++) if (*s == '_') *s = ' '; }   // Petit Trois: underscores for spaces
static void hb_command(const char *cmd) {
  char w[8][64] = { "", "", "", "", "", "", "", "" };
  int n = 0; const char *p = cmd;
  while (*p && n < 8) { while (*p == ' ') p++; int l = 0; while (*p && *p != ' ' && l < 63) w[n][l++] = *p++; w[n][l] = 0; if (l) n++; while (*p && *p != ' ') p++; }
  if (n < 2) { g_host->log("hotbar: /htb move | set <row> <slot> <type> <action> [target] [alias] | clear <row> <slot> | rename <row> <slot> <label> | bar <n> <slots> [h|v] | bar <n> off | env | job | mode | run | execute | reload | hide | show | sc [props] | horizon [on|off]"); return; }
  // (29 Nov) Petit Trois's commands (xivhotbar2.lua): move (layout mode), set, clear / delete, rename, execute; and bar
  int r1 = n >= 3 ? num(w[2]) : 0, r2 = n >= 4 ? num(w[3]) : 0;
  bool rs = r1 >= 1 && r1 <= HB_BARS && r2 >= 1 && r2 <= HB_SLOTS;
  if (hb_ieq(w[1], "move")) { toggle_edit(-1); return; }
  if (hb_ieq(w[1], "set") && r1) {
    if (!rs || n < 6) { g_host->log("hotbar: /htb set <row> <slot> <type> <action> [target] [alias] (underscores for spaces: Cure_IV)"); return; }
    unders(w[5]); unders(w[7]); char spec[320];
    hb_fmt(spec, sizeof spec, "xiv|%s|%s|%s|%s|", w[4], w[5], n > 6 ? w[6] : "t", n > 7 ? w[7] : "");
    HbAct t; bool dyn = hb_ieq(w[4], "autoitem") || hb_ieq(w[4], "bstpet");   // (made from the inventory or the learned list: kept when nothing matches yet)
    if (!hb_make_spec(&t, spec) && !dyn) { g_host->log("hotbar: /htb set: type %s is not one this hotbar runs (ma ja ws pet item ra input macro ct autoitem bstpet)", w[4]); return; }
    save_slot(r1 - 1, r2 - 1, spec); reload(true); return;
  }
  if ((hb_ieq(w[1], "clear") || hb_ieq(w[1], "delete")) && n >= 3) {
    if (!rs) { g_host->log("hotbar: /htb %s <row> <slot>", w[1]); return; }
    save_slot(r1 - 1, r2 - 1, ""); reload(true); return;
  }
  if (hb_ieq(w[1], "rename")) {
    if (!rs || n < 5) { g_host->log("hotbar: /htb rename <row> <slot> <label> (underscores for spaces)"); return; }
    const HbAct &a = g_lay.a[g_env][r1 - 1][r2 - 1];
    if (!a.used) { g_host->log("hotbar: %d.%d is empty: nothing to rename", r1, r2); return; }
    unders(w[4]);
    // the spec with its label field (xiv: alias, the 5th; line: label, the 2nd) replaced
    char f[6][200] = {}; int k = 0, l = 0; for (const char *q = a.spec; ; q++) { if (*q == '|' || !*q) { f[k][l] = 0; k++; l = 0; if (!*q || k == 6) break; continue; } if (l < 199) f[k][l++] = *q; }
    char spec[320];
    if (!strcmp(f[0], "xiv")) hb_fmt(spec, sizeof spec, "xiv|%s|%s|%s|%s|%s", f[1], f[2], f[3], w[4], f[5]);
    else hb_fmt(spec, sizeof spec, "line|%s|%s|%s", w[4], f[2], f[3]);
    save_slot(r1 - 1, r2 - 1, spec); reload(true); return;
  }
  if (hb_ieq(w[1], "execute") && rs) { if (g_queue_b < 0) { g_queue_b = r1 - 1; g_queue_s = r2 - 1; g_queue_how = "(command)"; } return; }
  if (hb_ieq(w[1], "bar") && r1 >= 1 && r1 <= HB_BARS && n >= 4) {           // /htb bar <n> <slots> [h|v|c<cols>] [shared|own]  /  /htb bar <n> off
    HbBar &b = g_cfg.bar[r1 - 1];
    if (hb_ieq(w[3], "off")) b.used = 0;
    else {
      int k2 = num(w[3]); if (k2 < 1 || k2 > HB_SLOTS) { g_host->log("hotbar: /htb bar <n> <slots 1-%d> [h|v]", HB_SLOTS); return; }
      if (!b.used && b.slots < 1) { b.x = 165; b.y = -110 - 30 * (r1 - 1); }
      b.used = 1; b.slots = k2; if (b.cols < 1 || b.cols > k2) b.cols = k2;
      for (int q = 4; q < n; q++) {                                         // h, v, c<n>, shared, own
        if (hb_ieq(w[q], "v")) b.cols = 1; else if (hb_ieq(w[q], "h")) b.cols = k2;
        else if ((w[q][0] | 32) == 'c' && num(w[q] + 1) >= 1) b.cols = num(w[q] + 1) > k2 ? k2 : num(w[q] + 1);
        else if (hb_ieq(w[q], "shared")) b.shared = 1; else if (hb_ieq(w[q], "own")) b.shared = 0;
      }
      b.vertical = b.cols == 1 && k2 > 1;
    }
    save_bars(); return;
  }
  if (hb_ieq(w[1], "horizon")) {                             // (29 Nov) Petit Trois's PlayingHorizonXI: /htb horizon [on|off]
    int v = n >= 3 ? !hb_ieq(w[2], "off") : !g_host->setting_int("hb_horizon", 0);
    g_host->set_int("hb_horizon", v); hb_set_horizon(v); reload(true);
    g_host->log("hotbar: Horizon's spells %s", v ? "on (priv_res/horizon_spells.lua)" : "off (priv_res/spells.lua)"); return;
  }
  if (hb_ieq(w[1], "sc")) {                                  // Petit Trois's //htb sc: the target's properties; with names, applied
    unsigned tg = g_test_target ? g_test_target : target_id();
    if (!tg) { g_host->log("hotbar: /htb sc: no target"); return; }
    char inc[3][16]; int k = 0; for (int q = 2; q < n && k < 3; q++) hb_copy(inc[k++], 16, w[q]);
    if (k) hb_sc_attempt(tg, inc, k, hb_now_ms());
    char props[64]; int win = 0, mb = 0; int np = hb_sc_state(tg, hb_now_ms(), props, sizeof props, &win, &mb);
    g_host->log("hotbar: target %08X: %s%s (the chain window %d ms, burst %d ms; %ld actions seen, %ld used; the action hook %s)", tg, np ? "" : "no properties", props,
                win, mb, g_sc_seen, g_sc_used, g_sc_hooked ? "on" : "refused");
    return;
  }
  if (hb_ieq(w[1], "env")) { g_env = n >= 3 ? (hb_ieq(w[2], "field") ? 0 : 1) : !g_env; g_host->log("hotbar: %s", g_env ? "battle" : "field"); }
  else if (hb_ieq(w[1], "job") && n >= 3) { g_user_job = 1; set_override(w[2], n >= 4 ? w[3] : "", 0, nullptr); }
  else if ((hb_ieq(w[1], "set") || hb_ieq(w[1], "sets")) && n >= 3) set_override(nullptr, nullptr, 1, w[2]);   // a table set on or off
  else if (hb_ieq(w[1], "reload")) reload(true);
  else if (hb_ieq(w[1], "hide")) g_hidden_by_cmd = n >= 3 ? !hb_ieq(w[2], "off") : !g_hidden_by_cmd;
  else if (hb_ieq(w[1], "show")) g_hidden_by_cmd = 0;
  else if (hb_ieq(w[1], "mode")) {                          // /htb mode [hotbar|macro]: hb_mode, kept in xikit_mods.ini
    int m = n >= 3 ? (hb_ieq(w[2], "hotbar") ? 1 : hb_ieq(w[2], "macro") || hb_ieq(w[2], "macros") ? 0 : -1) : !g_host->setting_int("hb_mode", 1);
    if (m < 0) g_host->log("hotbar: /htb mode hotbar | macro");
    else { g_host->set_int("hb_mode", m); g_host->log("hotbar: mode %s (the game's macros %s)", m ? "hotbar" : "macro", m ? "run the hotbar's bars 2 and 3, their palettes hidden" : "run as always");
           if (m) close_palettes(); }
  }
  else if (hb_ieq(w[1], "run") && n >= 3) {                 // /htb run 1.3: the slot, as its key or a click runs it
    int b = 0, sl = 0; char dot = 0;
    for (const char *q = w[2]; *q; q++) { if (*q == '.') { if (dot) { b = 0; break; } dot = 1; } else if (*q >= '0' && *q <= '9') { if (dot) sl = sl * 10 + (*q - '0'); else b = b * 10 + (*q - '0'); } else { b = 0; break; } }
    if (b >= 1 && b <= HB_BARS && sl >= 1 && sl <= HB_SLOTS && g_queue_b < 0) { g_queue_b = b - 1; g_queue_s = sl - 1; g_queue_how = "(command)"; }
    else g_host->log("hotbar: /htb run %s: give <bar>.<slot>, bar 1-%d, slot 1-%d", w[2], HB_BARS, HB_SLOTS);
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

struct Saved; static void draw_edit(IDirect3DDevice8 *dev, const Saved &sv, int hov);
enum { DR_NONE, DR_BAR, DR_SLOT, DR_PICK, DR_PANEL };
static int g_dr, g_dr_b, g_dr_s, g_dr_pick;

// ---------------------------------------------------------------------------------------------- what the game says of a slot (29 Nov)
// What the game's own menus show, from the game's own code (xikit_state.hpp; the analysis repository's HOTBAR_CURSOR.md
// items 2, 2a, 2b):
// - spells: the recast countdown (by spell id), and the magic menu's check (xistate::spell_state: 0 castable);
// - abilities and weapon skills: the record in the abilities' table (a job ability's id + 0x200, the game's rule; a
//   weapon skill's id, a lead), its timer's countdown (the timer id the record gives), the charges and the seconds to the
//   next one (MenuPanels_GetSlotInfo), and the ability menu's check (xistate::ability_state: 0 usable).
// That Petit Trois's ids are the game's is checked for each action in the game: its record's word +0 must be the id and
// (abilities) its timer id Petit Trois's recast_id. If not (or before the table is there), the slot keeps the 28 Nov
// path (Petit Trois's recast_id as the timer id) and is not dimmed; the first result for each action is logged.
struct SlotState { int kind, id;        // 0 none, 1 spell, 2 ability (ja, pet), 3 weapon skill; the action's id
                   int rec;             // the ability record, -1 not checked or not confirmed
                   int ticks, total;    // the countdown now (1/60 s) and the most it was this recast (the sweep's whole)
                   int charges, next;   // charges there are (-1: not a charged ability) and seconds to the next
                   int state; };        // the game's check (0 usable; -1 not known)
static SlotState g_ss[2][HB_BARS][HB_SLOTS];
static unsigned char g_ss_logged[2][HB_BARS][HB_SLOTS];
static bool kind_is(const HbAct &a, const char *k) { return !_stricmp(a.kind, k); }
static void slot_update(int e, int b, int i, bool full) {
  const HbAct &a = g_lay.a[e][b][i]; SlotState &st = g_ss[e][b][i];
  int k = !a.used || a.id <= 0 ? 0 : kind_is(a, "ma") ? 1 : kind_is(a, "ja") || kind_is(a, "pet") ? 2 : kind_is(a, "ws") ? 3 : 0;
  if (k != st.kind || a.id != st.id) { memset(&st, 0, sizeof st); st.kind = k; st.id = a.id; st.rec = -2; st.charges = -1; st.state = -1; g_ss_logged[e][b][i] = 0; }
  if (!k) return;
  if (k == 1) {
    int t = xistate::spell_recast_ticks(a.id); if (t < 0) t = 0;
    if (t > st.ticks || !st.ticks) st.total = t;
    st.ticks = t;
    if (full) st.state = xistate::spell_state(a.id);
    return;
  }
  // abilities and weapon skills: the record, confirmed once
  if (st.rec == -2 && xistate::ability_record(0)) {
    int r = k == 2 ? xistate::job_ability_record(a.id) : a.id;
    int rid = xistate::ability_record_id(r), tid = xistate::ability_timer_id(r);
    bool ok = rid == a.id && (k == 3 || a.recast_id < 0 || tid == a.recast_id);
    st.rec = ok ? r : -1;
    if (!g_ss_logged[e][b][i]) {
      g_ss_logged[e][b][i] = 1;
      g_host->log("hotbar: %s \"%s\" (Petit Trois's id %d, recast_id %d): the game's record %d has id %d, timer %d: %s", a.kind, a.label, a.id, a.recast_id,
                  r, rid, tid, ok ? "the game's record, recast and check used" : "not the same: Petit Trois's recast_id used, not dimmed");
    }
  }
  int t = -1;
  if (st.rec >= 0 && k == 2) t = xistate::ability_recast_ticks(xistate::ability_timer_id(st.rec));
  else if (k == 2 && a.recast_id >= 0) t = xistate::ability_recast_ticks(a.recast_id);
  if (t < 0) t = 0;
  if (t > st.ticks || !st.ticks) st.total = t;
  st.ticks = t;
  if (full && st.rec >= 0) {
    int ch = -1, sec = xistate::ability_recast(st.rec, &ch);
    st.charges = ch; st.next = ch >= 0 ? sec : 0;
    st.state = xistate::ability_state(st.rec);
  } else if (st.rec < 0) { st.charges = -1; st.state = -1; }
}
// (29 Nov) skillchains and magic bursts on the current target: Petit Trois's rules (hotbar_core.cpp, from its
// lib/skillchains.lua), fed by the game's own parse of every action message (my_Act below). The target is the target
// menu's (xistate::target_actor), keyed by its record's +0x78: the id the game itself compares with an action's actor id
// (0x1018C940 there, FUN_1018df10 in 6AE818B4: the record's +0x78 against the parsed status's +8). The player's chain
// affinity, burst affinity and immanence: the game's own status lookup (xistate::has_status) with Petit Trois's numbers.
struct ScSlot { int chain, level, burst, element; char prop[16]; };
static ScSlot g_scs[HB_BARS][HB_SLOTS];
static unsigned target_id() { void *a = xistate::target_actor(); void *r = a ? xistate::actor_record(a) : nullptr; return r ? xistate::record_id(r) : 0; }
static int g_test_status = -1;                                     // (tests: statuses with no game; g_test_target: a target)
static bool status(int id) { return g_test_status >= 0 ? ((g_test_status >> (id == 164 ? 0 : id == 165 ? 1 : 2)) & 1) != 0 : xistate::has_status(id); }
static void chains_update() {
  memset(g_scs, 0, sizeof g_scs);
  int hsc = g_host->setting_int("hb_sc", 1), hmb = g_host->setting_int("hb_mb", 1);
  if (!hsc && !hmb) return;
  unsigned tg = g_test_target ? g_test_target : target_id(); if (!tg) return;
  unsigned now = hb_now_ms();
  int ca = status(164), ba = status(165), im = status(470);
  for (int b = 0; b < HB_BARS; b++) if (g_cfg.bar[b].used) for (int i = 0; i < g_cfg.bar[b].slots; i++) {
    const HbAct &a = g_lay.a[g_env][b][i]; if (!a.used) continue;
    ScSlot &c = g_scs[b][i];
    const char *nm = a.label; char tmp[64];
    { const char *q = strchr(a.line[0], '"'); if (q) { const char *e2 = strchr(q + 1, '"'); if (e2 && e2 - q - 1 < 63) { memcpy(tmp, q + 1, e2 - q - 1); tmp[e2 - q - 1] = 0; nm = tmp; } } }
    HbChain ch; if (hsc && hb_sc_chain(tg, a.kind, nm, ca, im, now, &ch)) { c.chain = 1; c.level = ch.level; hb_copy(c.prop, sizeof c.prop, ch.property); }
    int el = -1; if (hmb && hb_sc_burst(tg, a.kind, nm, ba, now, &el)) { c.burst = 1; c.element = el; }
  }
}
static void states_update() {
  static long n; bool full = (n++ % 6) == 0;                       // the checks every 6 frames, the countdowns every frame
  for (int b = 0; b < HB_BARS; b++) if (g_cfg.bar[b].used) for (int i = 0; i < g_cfg.bar[b].slots; i++) slot_update(g_env, b, i, full);
  chains_update();
}
// the outline's colour: by the property's (first) element, the burst's by the spell's (0 fire .. 7 dark, Petit Trois's
// numbers); the colours are this hotbar's own (Petit Trois draws an image per property)
static unsigned element_colour(int e) {
  static const unsigned k[8] = { 0xFFFF5030u, 0xFF80E0FFu, 0xFFC060FFu, 0xFFD0A050u, 0xFF60FF60u, 0xFF4080FFu, 0xFFFFFFC0u, 0xFF6040A0u };
  return e >= 0 && e < 8 ? k[e] : 0xFFFFFFFFu;
}
static unsigned prop_colour(const char *p) {
  static const char *k[] = { "Liquefaction", "Induration", "Detonation", "Scission", "Impaction", "Reverberation", "Transfixion", "Compression" };
  for (int e = 0; e < 8; e++) if (!strcmp(p, k[e])) return element_colour(e);
  static const struct { const char *p; int e; } k2[] = { { "Fusion", 0 }, { "Distortion", 5 }, { "Fragmentation", 4 }, { "Gravitation", 3 } };
  for (unsigned q = 0; q < sizeof k2 / sizeof k2[0]; q++)
    if (!strcmp(p, k2[q].p)) return element_colour(k2[q].e);
  return strstr(p, "Darkness") ? 0xFF303030u : 0xFFFFFFFFu;            // Light, Double Light: white
}
// recast-only answers of the checks (shown by the sweep, not by dimming): spells 4 and 0xC, abilities 2
static bool only_recast(const SlotState &st) { return st.kind == 1 ? st.state == 4 || st.state == 0xC : st.state == 2; }
static bool blocked(const SlotState &st) { return st.state > 0 && !only_recast(st) && !(st.charges > 0 && st.kind == 2 && st.state == 2); }
// what a check's code means, as far as the code says (xikit_state.hpp)
static const char *why(const SlotState &st) {
  if (st.kind == 1) switch (st.state) {
    case 2: return "the job or level cannot cast it"; case 3: return "the cost is not met"; case 4: case 0xC: return "recast";
    case 5: return "not set (blue magic)"; case 6: return "a timer runs"; default: return "a status or state stops it";
  }
  switch (st.state) {
    case 1: return "not there"; case 2: return "recast"; case 4: case 5: return "the cost is not met"; case 0xA: return "not in battle (engaged, a lead)";
    case 0xD: return "the level is too low"; default: return "a status or state stops it";
  }
}

// a dark sweep over the part of the slot whose recast is left, clockwise from the top (FFXIV's); frac 0..1
static void sweep(float x0, float y0, float x1, float y1, float frac, unsigned c) {
  if (frac <= 0) return;
  if (frac > 1) frac = 1;
  float cx = (x0 + x1) / 2, cy = (y0 + y1) / 2, hw = (x1 - x0) / 2, hh = (y1 - y0) / 2;
  const int N = 32; float a0 = (1 - frac) * 6.2831853f;            // the part done is clear; what is left is dark, ending at the top
  auto edge = [&](float a, float &px, float &py) {                  // where the ray at angle a (0 up, clockwise) meets the square
    float dx = (float)sin(a), dy = -(float)cos(a), ax = dx < 0 ? -dx : dx, ay = dy < 0 ? -dy : dy;
    float tx = ax > 1e-6f ? hw / ax : 1e9f, ty = ay > 1e-6f ? hh / ay : 1e9f, t = tx < ty ? tx : ty;
    px = cx + dx * t; py = cy + dy * t;
  };
  for (int k = 0; k < N; k++) {
    float a = a0 + (6.2831853f - a0) * k / N, bnext = a0 + (6.2831853f - a0) * (k + 1) / N, px, py, qx, qy;
    edge(a, px, py); edge(bnext, qx, qy);
    if (g_nv + 3 > 6000) return;
    Vtx v0 = { cx, cy, 0, 1, c }, v1 = { px, py, 0, 1, c }, v2 = { qx, qy, 0, 1, c };
    g_v[g_nv++] = v0; g_v[g_nv++] = v1; g_v[g_nv++] = v2;
  }
}
static void fmt_secs(char *c, int n, int sec) { if (sec >= 60) hb_fmt(c, n, "%d:%02d", sec / 60, sec % 60); else hb_fmt(c, n, "%d", sec); }

// the tooltip's lines: Petit Trois's (lib/text_formatter.lua: [name] and target, the description wrapped at 30 characters,
// SC for weapon skills, range, MP cost), then cast and recast (spells.lua), what the game says now
struct ScSlot; static int tip_lines(const HbAct &a, const SlotState &st, const ScSlot *sc, char out[][96], unsigned *col, int max) {
  int n = 0; HbInfo inf;
  #define add(c_, ...) do { if (n < max) { hb_fmt(out[n], 96, __VA_ARGS__); col[n++] = (c_); } } while (0)
  const char *tgt = strrchr(a.line[0], '<');
  bool info = (st.kind || kind_is(a, "ma") || kind_is(a, "ja") || kind_is(a, "pet") || kind_is(a, "ws")) && hb_action_info(a.kind, a.label, &inf);
  if (!info) { const char *q = strchr(a.line[0], '"'); char nm[64] = ""; if (q) { const char *e2 = strchr(q + 1, '"'); if (e2 && e2 - q - 1 < 63) { memcpy(nm, q + 1, e2 - q - 1); nm[e2 - q - 1] = 0; } }
               info = nm[0] && hb_action_info(a.kind, nm, &inf); }
  add(0x80805020u, "[%s]%s%s", info ? inf.name : a.label, tgt ? "   Target: " : "", tgt ? tgt : "");
  if (info) {
    if (inf.desc[0] && g_host->setting_int("hb_desc", 1)) {          // wrapped as Petit Trois's format_description: a line once past 30 characters
      char line[96] = ""; const char *p = inf.desc;
      while (*p) {
        while (*p == ' ') p++;
        const char *w0 = p;
        while (*p && *p != ' ') p++;
        char word[64]; int wl = (int)(p - w0); if (wl > 63) wl = 63; memcpy(word, w0, wl); word[wl] = 0;
        if (!wl) break;
        if (strlen(line) > 30) { add(0x80808080u, "%s", line); line[0] = 0; }
        size_t l = strlen(line); hb_fmt(line + l, (int)(sizeof line - l), "%s%s", l ? " " : "", word);
      }
      if (line[0]) add(0x80808080u, "%s", line);
    }
    if (kind_is(a, "ws")) add(0x80808080u, "SC: %s", inf.sc[0] ? inf.sc : "None");
    char rg[24]; if (inf.range == 255) hb_fmt(rg, sizeof rg, "Self"); else if (inf.range > 0) hb_fmt(rg, sizeof rg, "%.1fy", inf.range); else rg[0] = 0;
    char cost[24] = ""; if (inf.mp) hb_fmt(cost, sizeof cost, "MP Cost: %dMP", inf.mp); else if (inf.tp) hb_fmt(cost, sizeof cost, "TP Cost: %d", inf.tp);
    if (rg[0] || cost[0]) add(0x80808080u, "%s%s%s%s", rg[0] ? "Range: " : "", rg, rg[0] && cost[0] ? "    " : "", cost);
    if (kind_is(a, "ma") && (inf.cast > 0 || inf.recast > 0)) add(0x80808080u, "Cast: %.2gs    Recast: %.3gs", inf.cast, inf.recast);
  } else {
    for (int k = 0; k < a.nlines && k < 4; k++) add(0x80808080u, "%s", a.line[k]);
  }
  if (st.charges >= 0) { char c[12]; fmt_secs(c, sizeof c, st.next); add(0x80508080u, "Charges: %d%s%s", st.charges, st.next > 0 ? "   next in " : "", st.next > 0 ? c : ""); }
  else if (st.ticks > 0) { char c[12]; fmt_secs(c, sizeof c, (st.ticks + 59) / 60); add(0x80508080u, "Recast: %s", c); }
  if (blocked(st)) add(0x80803020u, "Cannot use now: %s (the game's check: %d)", why(st), st.state);
  if (sc) {                                                         // (29 Nov) what it would make on the target now
    if (sc->chain) add(0x80806040u, "Skillchain: %s (level %d)", sc->prop, sc->level);
    if (sc->burst) add(0x80406080u, "Magic burst");
  }
  #undef add
  return n;
}

static void draw(IDirect3DDevice8 *dev) {
  int cx = -1, cy = -1; cursor(&cx, &cy); int hov = over(cx, cy);
  int show_empty = g_host->setting_int("hb_empty", 1) || g_edit;
  int names = g_host->setting_int("hb_names", 1), costs = g_host->setting_int("hb_costs", 1), keys = g_host->setting_int("hb_keys", 1);
  int recasts = g_host->setting_int("hb_recasts", 1), sweeps = g_host->setting_int("hb_sweep", 1), barnums = g_host->setting_int("hb_barnums", 1);
  // (29 Nov) the backdrop (hb_bg): 0 this hotbar's own; 1.. Petit Trois's BarBackground colours (theme.lua's
  // HOTBAR_THEME_LOOKUP: none, dark, blue, skyblue, purple, yellow, pine, red, orange); slot alpha hb_alpha (SlotAlpha)
  static const unsigned k_bg[10] = { 0, 0x00000000u, 0xA50F1219u, 0x91122862u, 0x873764B4u, 0x91440F62u, 0x87C3A50Cu, 0x910C441Cu, 0x91760C0Cu, 0x919E4108u };
  int bg = g_host->setting_int("hb_bg", 0); if (bg < 0 || bg > 9) bg = 0;
  unsigned al = (unsigned)g_host->setting_int("hb_alpha", 160) & 0xFF;
  states_update();
  Saved sv; save(dev, sv);
  plain_states(dev);
  float t = unit_x() * scale();
  for (int b = 0; b < HB_BARS; b++) {
    const HbBar &bar = g_cfg.bar[b]; if (!bar.used) continue;
    float r[4]; bar_rect(bar, r);
    if (bg == 0) { quad(r[0], r[1], r[2], r[3], 0xB0182848u, 0xB0080C20u); frame(r[0], r[1], r[2], r[3], t, 0x90A8B0C8u); }   // the window: dark blue, lighter at the top
    else if (k_bg[bg] >> 24) { quad(r[0], r[1], r[2], r[3], k_bg[bg], k_bg[bg]); frame(r[0], r[1], r[2], r[3], t, 0x90A8B0C8u); }
    for (int i = 0; i < bar.slots; i++) {
      const HbAct &a = g_lay.a[g_env][b][i];
      if (!a.used && !show_empty) continue;
      float s[4]; slot_rect(bar, i, s);
      if (g_dr == DR_SLOT && g_dr_b == b && g_dr_s == i) continue;    // (dragged: drawn under the cursor)
      unsigned fill = g_flash[b][i] > 0 ? 0xC0806020u : a.used ? (al << 24) | 0x060A18u : ((al * 3 / 5) << 24) | 0x060A18u;
      quad(s[0], s[1], s[2], s[3], fill, fill);
      frame(s[0], s[1], s[2], s[3], t, hov == (b + 1) * 100 + i + 1 ? 0xFFFFA040u : 0x80707890u);
      const ScSlot &c = g_scs[b][i];                                  // a skillchain (or a burst) the action would make now
      if (a.used && (c.chain || c.burst)) {
        unsigned oc = c.chain ? prop_colour(c.prop) : element_colour(c.element);
        float pulse = 0.6f + 0.4f * (float)sin((g_frame % 60) * 6.2831853f / 60);
        unsigned al8 = (unsigned)(255 * pulse) & 0xFF; oc = (oc & 0x00FFFFFFu) | (al8 << 24);
        frame(s[0] - t, s[1] - t, s[2] + t, s[3] + t, 2 * t, oc);
      }
    }
  }
  float tg[4];
  if (tag_rect(tg)) { quad(tg[0], tg[1], tg[2], tg[3], 0xB0182848u, 0xB0080C20u); frame(tg[0], tg[1], tg[2], tg[3], t, hov == 1000 ? 0xFFFFA040u : 0x90A8B0C8u); }
  flush_quads(dev);
  // icons: as they are when usable, darker while a recast runs, dim when the game's check says no
  dev->SetVertexShader(FVF_XYZRHW | FVF_DIFFUSE | FVF_TEX1);
  dev->SetTextureStageState(0, D3DTSS_COLOROP, TOP_MODULATE); dev->SetTextureStageState(0, D3DTSS_COLORARG1, TA_TEXTURE); dev->SetTextureStageState(0, D3DTSS_COLORARG2, TA_DIFFUSE);
  dev->SetTextureStageState(0, D3DTSS_ALPHAOP, TOP_MODULATE); dev->SetTextureStageState(0, D3DTSS_ALPHAARG1, TA_TEXTURE); dev->SetTextureStageState(0, D3DTSS_ALPHAARG2, TA_DIFFUSE);
  dev->SetTextureStageState(0, D3DTSS_MAGFILTER, TEXF_LINEAR); dev->SetTextureStageState(0, D3DTSS_MINFILTER, TEXF_LINEAR);
  for (int b = 0; b < HB_BARS; b++) {
    const HbBar &bar = g_cfg.bar[b]; if (!bar.used) continue;
    for (int i = 0; i < bar.slots; i++) {
      const HbAct &a = g_lay.a[g_env][b][i]; if (!a.used || !a.icon[0]) continue;
      if (g_dr == DR_SLOT && g_dr_b == b && g_dr_s == i) continue;
      IDirect3DTexture8 *tx = texture(a.icon); if (!tx) continue;
      const SlotState &st = g_ss[g_env][b][i];
      unsigned c = blocked(st) || (kind_is(a, "item") && a.id > 0 && g_inv_known && !item_count(a.id)) ? 0xFF585858u : st.ticks > 0 && st.charges <= 0 ? 0xFFA0A0A0u : 0xFFFFFFFFu;
      float s[4]; slot_rect(bar, i, s); float m = t;
      icon(dev, tx, s[0] + m, s[1] + m, s[2] - m, s[3] - m, c);
    }
  }
  // the sweeps, over the icons
  if (sweeps && recasts) {
    plain_states(dev);
    for (int b = 0; b < HB_BARS; b++) {
      const HbBar &bar = g_cfg.bar[b]; if (!bar.used) continue;
      for (int i = 0; i < bar.slots; i++) {
        const SlotState &st = g_ss[g_env][b][i]; if (!g_lay.a[g_env][b][i].used || st.ticks <= 0 || st.total <= 0) continue;
        if (g_dr == DR_SLOT && g_dr_b == b && g_dr_s == i) continue;
        float s[4]; slot_rect(bar, i, s);
        sweep(s[0] + t, s[1] + t, s[2] - t, s[3] - t, (float)st.ticks / st.total, st.charges > 0 ? 0x60000000u : 0xA0000000u);
      }
    }
    flush_quads(dev);
  }
  // text with the game's states (FontGlyphs_DrawString leaves the colour operation to them)
  restore(dev, sv);
  for (int b = 0; b < HB_BARS; b++) {
    const HbBar &bar = g_cfg.bar[b]; if (!bar.used) continue;
    if (barnums) { float r[4]; bar_rect(bar, r); char nb[4]; hb_fmt(nb, sizeof nb, "%d", b + 1); float sc = 0.4f * unit_x() * scale();
                   text(r[0] - measure(nb) * sc - 2 * unit_x(), r[1] + (r[3] - r[1]) / 2 - 8 * sc, nb, 0x80606060u, sc); }
    for (int i = 0; i < bar.slots; i++) {
      const HbAct &a = g_lay.a[g_env][b][i]; float s[4]; slot_rect(bar, i, s);
      float w = s[2] - s[0], h = s[3] - s[1];
      const HbKey &k = bar.key[i];
      if (keys && k.name[0] && (a.used || show_empty)) text(s[0] + 1, s[1], k.name, 0x80606060u, 0.4f * unit_x() * scale());
      if (!a.used || (g_dr == DR_SLOT && g_dr_b == b && g_dr_s == i)) continue;
      const SlotState &st = g_ss[g_env][b][i];
      if (kind_is(a, "item") && a.id > 0 && g_inv_known) {              // (29 Nov) the item's count (Petit Trois: in the cost corner)
        char c[12]; int n = item_count(a.id); hb_fmt(c, sizeof c, "%d", n);
        float sc = 0.4f * unit_x() * scale(); text(s[2] - measure(c) * sc - 1, s[1], c, n ? 0x80808080u : 0x80802020u, sc);
      } else if (costs && (a.mp || a.tp)) {
        char c[12]; hb_fmt(c, sizeof c, "%d", a.mp ? a.mp : a.tp);
        bool short_of = blocked(st) && ((st.kind == 1 && st.state == 3) || (st.kind != 1 && (st.state == 4 || st.state == 5)));
        float sc = 0.4f * unit_x() * scale(); text(s[2] - measure(c) * sc - 1, s[1], c, short_of ? 0x80802020u : a.mp ? 0x80508080u : 0x80807040u, sc);
      }
      // the recast left (the game's countdowns), or for a charged ability the charges and the seconds to the next
      if (recasts && st.kind) {
        int sec = st.charges >= 0 ? st.next : (st.ticks + 59) / 60;
        if (sec > 0) {
          char c[12]; fmt_secs(c, sizeof c, sec);
          float sc = 0.6f * unit_x() * scale(), mw = measure(c) * sc;
          text(s[0] + (w - mw) / 2, s[1] + h / 2 - 10 * sc, c, 0x80809060u, sc);
        }
        if (st.charges >= 0) { char c[8]; hb_fmt(c, sizeof c, "%d", st.charges); float sc = 0.45f * unit_x() * scale();
                               text(s[2] - measure(c) * sc - 1, s[3] - 16 * sc, c, st.charges ? 0x80808080u : 0x80802020u, sc); }
      }
      if (names && a.label[0]) {
        float sc = 0.5f * unit_x() * scale(), mw = measure(a.label) * sc;
        if (mw > w - 2 && mw > 0) { sc *= (w - 2) / mw; mw = w - 2; }
        unsigned c = hov == (b + 1) * 100 + i + 1 ? 0x80805020u : blocked(st) ? 0x80585858u : 0x80808080u;
        text(s[0] + (w - mw) / 2, s[1] + h - 16 * sc - 1, a.label, c, sc);
      }
    }
  }
  if (tag_rect(tg)) {
    char tag[40]; hb_fmt(tag, sizeof tag, "%s", g_env ? "Battle" : "Field");
    float sc = 0.45f * unit_x() * scale(); text(tg[0] + 2, tg[1] + 1, tag, hov == 1000 ? 0x80805020u : 0x80808080u, sc);
  }
  if (g_edit) draw_edit(dev, sv, hov);
  // the tooltip over the hovered slot (above it, or below when there is no room)
  if (hov > 0 && hov < 1000 && g_host->setting_int("hb_tips", 1) && !g_dr) {
    int b = hov / 100 - 1, i = hov % 100 - 1; const HbAct &a = g_lay.a[g_env][b][i];
    if (a.used) {
      static char lines[16][96]; unsigned col[16]; int n = tip_lines(a, g_ss[g_env][b][i], &g_scs[b][i], lines, col, 16);
      float s[4]; slot_rect(g_cfg.bar[b], i, s); float sc = 0.5f * unit_x() * scale(), lh = 17 * sc, w = 0;
      for (int k = 0; k < n; k++) { float lw = measure(lines[k]) * sc; if (lw > w) w = lw; }
      float bw = w + 8 * sc, bh = n * lh + 4 * sc, x0 = s[0], y1 = s[1] - 2 * unit_y(), y0 = y1 - bh;
      if (y0 < 0) { y0 = s[3] + 2 * unit_y(); y1 = y0 + bh; }
      if (x0 + bw > 640 * unit_x()) x0 = 640 * unit_x() - bw;
      plain_states(dev); quad(x0, y0, x0 + bw, y1, 0xE0182848u, 0xE0080C20u); frame(x0, y0, x0 + bw, y1, t, 0x90A8B0C8u); flush_quads(dev);
      restore(dev, sv);
      for (int k = 0; k < n; k++) text(x0 + 4 * sc, y0 + 2 * sc + k * lh, lines[k], col[k], sc);
    }
  }
  restore(dev, sv);
  if (sv.tex) sv.tex->Release();                                     // GetTexture added a reference
}

// ---------------------------------------------------------------------------------------------- layout mode, the picker, Cfg (29 Nov)
// After XIVhotbar2 Petit Trois Edition (the reference): /htb move turns layout mode on and opens the action picker beside
// the bars (xivhotbar2.lua toggle_edit_mode). In layout mode: a bar's frame or its handle drags the bar; a slot dragged
// onto another swaps the two, dragged off every bar empties it; an action dragged from the picker onto a slot puts it
// there; the handle's H/V turns the bar across or down, its - and + take a slot away or add one. The picker's tabs are
// Petit Trois's: Magic, Trusts, Ability, WSkills, Cfg (lib/action_picker.lua), with a filter or two a tab: Magic by type
// and school, Ability by type, WSkills by weapon (Petit Trois's role and scope filters use name lists of its own: not
// taken). Cfg holds the settings below. Moves save at once: the bars to hotbar_layout.txt, the slots to
// hotbar_slots_<job>.txt (hotbar_core.cpp, hb_save_bars, hb_save_slot); hotbar.txt and XIVhotbar2's files are not
// written (Petit Trois writes its job files; this hotbar keeps its changes in files of its own, read last).
// What the picker lists: hotbar_core.cpp hb_pick_list. The learned spells are the game's own list (xistate::spell_learned,
// message 0xAA); the abilities and weapon skills a character has are not read (Petit Trois asks Windower's
// get_abilities), so those tabs list by the job and level tables (abilities) or every weapon skill (weapon skills).
static float g_dr_dx, g_dr_dy;
static int g_pk_x = 440, g_pk_y = 40, g_pk_tab, g_pk_scroll, g_pk_f[2];
static HbPick g_pk_all[1600]; static int g_pk_nall = -1, g_pk_built_tab = -1, g_pk_built_job = -1, g_pk_learned_seen = -2;
static int g_pk_view[1600], g_pk_nv;
static const char *g_pk_opts[2][32]; static int g_pk_nopt[2];
static const char *const k_tabs[5] = { "Magic", "Trusts", "Ability", "WSkills", "Cfg" };
static const int PK_COLS = 6, PK_ROWS = 6, PK_CELL = 27, PK_W = PK_COLS * PK_CELL + 8, PK_HEAD = 14, PK_TABS = 14, PK_STRIP = 12;
static int pk_strips() { return g_pk_tab == 0 ? 2 : g_pk_tab == 2 || g_pk_tab == 3 ? 1 : 0; }
static int pk_grid_y() { return PK_HEAD + PK_TABS + 2 * PK_STRIP + 2; }
static int pk_h() { return pk_grid_y() + PK_ROWS * PK_CELL + 28; }
static float pk_k() { return scale(); }
// a rectangle of the panel (its own units, from its top left) in pixels
static void pk_rect(float x, float y, float w, float h, float r[4]) {
  float k = pk_k(); r[0] = (g_pk_x + x * k) * unit_x(); r[1] = (g_pk_y + y * k) * unit_y(); r[2] = r[0] + w * k * unit_x(); r[3] = r[1] + h * k * unit_y();
}
static bool in(const float r[4], int x, int y) { return x >= r[0] && x < r[2] && y >= r[1] && y < r[3]; }

// the game's lists for the picker: spells by id; job abilities as record id + 0x200; weapon skills as record id
static int learned_cb(int tab, int id) {
  if (tab <= 1) return xistate::spell_learned(id);
  return xistate::ability_learned(tab == 2 ? xistate::job_ability_record(id) : id);
}
static void pk_build() {
  int lv = 0, slv = 0, m = xistate::job(0, &lv), sj = xistate::job(1, &slv);
  // the game's list, as a sum of its bytes (it changes when an ability or spell is learned without a job change)
  int learned_now = (g_pk_tab <= 1 ? xistate::spell_learned(0) : xistate::ability_learned(0)) < 0 ? -1 : 1;
  if (learned_now > 0) {
    const uint8_t *g = xistate::game_state(); unsigned sum = 0;
    if (g) { int off = g_pk_tab <= 1 ? 0x2CF54 : 0x2CDE8, n = g_pk_tab <= 1 ? 0x80 : 0x160; for (int q = 0; q < n; q++) sum = sum * 31 + g[off + q]; }
    learned_now = (int)(sum | 1u);
  }
  int key = m * 1000 + lv * 4 + sj * 400 + slv;
  if (g_pk_built_tab == g_pk_tab && g_pk_built_job == key && g_pk_learned_seen == learned_now) return;
  g_pk_built_tab = g_pk_tab; g_pk_built_job = key; g_pk_learned_seen = learned_now; g_pk_scroll = 0;
  const char *mn = m > 0 ? xistate::job_name(m) : "", *sn = sj > 0 ? xistate::job_name(sj) : "";
  g_pk_nall = g_pk_tab < 4 ? hb_pick_list(g_pk_tab, mn, lv, sn, slv, learned_cb, g_pk_all, 1600) : 0;
  // the filters: the values present, in the order they first come (the list is by name)
  for (int f = 0; f < 2; f++) {
    g_pk_nopt[f] = 0; if (f >= pk_strips()) continue;
    g_pk_opts[f][g_pk_nopt[f]++] = "All";
    for (int i = 0; i < g_pk_nall && g_pk_nopt[f] < 32; i++) {
      const char *v = f == 0 ? g_pk_all[i].group : g_pk_all[i].sub; if (!v[0]) continue;
      int seen = 0; for (int j = 1; j < g_pk_nopt[f]; j++) if (!strcmp(g_pk_opts[f][j], v)) seen = 1;
      if (!seen) g_pk_opts[f][g_pk_nopt[f]++] = v;
    }
    if (g_pk_f[f] >= g_pk_nopt[f]) g_pk_f[f] = 0;
  }
  g_host->log("hotbar: picker %s: %d actions (job %s%s%s, levels %d/%d; %s)", k_tabs[g_pk_tab], g_pk_nall, mn[0] ? mn : "not known",
              sn[0] ? "/" : "", sn, lv, slv, learned_now < 0 ? "the game's list has not come: by the tables' levels" : "the game's own list");
}
static void pk_filter() {
  pk_build(); g_pk_nv = 0;
  for (int i = 0; i < g_pk_nall; i++) {
    if (g_pk_f[0] > 0 && strcmp(g_pk_all[i].group, g_pk_opts[0][g_pk_f[0]])) continue;
    if (g_pk_f[1] > 0 && strcmp(g_pk_all[i].sub, g_pk_opts[1][g_pk_f[1]])) continue;
    g_pk_view[g_pk_nv++] = i;
  }
  int pages = (g_pk_nv + PK_COLS - 1) / PK_COLS - PK_ROWS; if (g_pk_scroll > pages) g_pk_scroll = pages > 0 ? pages : 0;
}

// Cfg: the settings (xikit_mods.ini [hotbar]) and the bar count
struct CfgRow { const char *label, *setting; int lo, hi, step; const char *off, *on; };
static const char *const k_bg_names[10] = { "Default", "None", "Dark", "Blue", "Sky Blue", "Purple", "Yellow", "Pine", "Red", "Orange" };
static const CfgRow k_cfg[] = {
  { "Hotbars", nullptr, 1, HB_BARS, 1, nullptr, nullptr },
  { "Scale %", "hb_scale", 50, 300, 10, nullptr, nullptr },
  { "Slot gap", "hb_gap", 0, 12, 1, nullptr, nullptr },
  { "Action names", "hb_names", 0, 1, 1, "Hide", "Show" },
  { "Action cost", "hb_costs", 0, 1, 1, "Hide", "Show" },
  { "Key names", "hb_keys", 0, 1, 1, "Hide", "Show" },
  { "Recasts", "hb_recasts", 0, 1, 1, "Hide", "Show" },
  { "Empty slots", "hb_empty", 0, 1, 1, "Hide", "Show" },
  { "Tooltips", "hb_tips", 0, 1, 1, "Off", "On" },
  { "Descriptions", "hb_desc", 0, 1, 1, "Off", "On" },
  { "Cooldown sweep", "hb_sweep", 0, 1, 1, "Off", "On" },
  { "Bar numbers", "hb_barnums", 0, 1, 1, "Hide", "Show" },
  { "Skillchains", "hb_sc", 0, 1, 1, "Off", "On" },
  { "Weapon switching", "hb_weapons", 0, 1, 1, "Off", "On" },
  { "Horizon spells", "hb_horizon", 0, 1, 1, "Off", "On" },
  { "Magic bursts", "hb_mb", 0, 1, 1, "Off", "On" },
  { "Backdrop", "hb_bg", 0, 9, 1, nullptr, nullptr },
  { "Slot alpha", "hb_alpha", 0, 255, 15, nullptr, nullptr },
  { "Macro keys", "hb_mode", 0, 1, 1, "Macros", "Hotbar" },
  { "Follow job", "hb_follow_job", 0, 1, 1, "Off", "On" },
};
static const int k_ncfg = sizeof k_cfg / sizeof *k_cfg;
static int used_bars() { int n = 0; for (int b = 0; b < HB_BARS; b++) n += g_cfg.bar[b].used; return n; }
static void cfg_value(int i, char *out, int n) {
  const CfgRow &c = k_cfg[i];
  if (!c.setting) { hb_fmt(out, n, "%d", used_bars()); return; }
  int v = g_host->setting_int(c.setting, 0);
  if (!strcmp(c.setting, "hb_bg")) hb_fmt(out, n, "%s", k_bg_names[v < 0 || v > 9 ? 0 : v]);
  else if (c.on) hb_fmt(out, n, "%s", v ? c.on : c.off);
  else hb_fmt(out, n, "%d", v);
}
static void save_bars();
static void cfg_step(int i, int d) {
  const CfgRow &c = k_cfg[i];
  if (!c.setting) {                                          // the bar count: the next bar on, or the last one off
    int n = used_bars();
    if (d > 0 && n < HB_BARS) for (int b = 0; b < HB_BARS; b++) if (!g_cfg.bar[b].used) {
      HbBar &bar = g_cfg.bar[b]; bar.used = 1;
      if (bar.slots < 1) { bar.slots = 12; bar.cols = 12; bar.x = 165; bar.y = -110 - 30 * b; bar.vertical = 0; }   // a new bar: over the others
      break;
    }
    if (d < 0 && n > 1) for (int b = HB_BARS - 1; b >= 0; b--) if (g_cfg.bar[b].used) { g_cfg.bar[b].used = 0; break; }
    save_bars(); return;
  }
  int v = g_host->setting_int(c.setting, 0) + d * c.step;
  if (c.on) v = !g_host->setting_int(c.setting, 0);
  if (v < c.lo) v = c.lo;
  if (v > c.hi) v = c.hi;
  g_host->set_int(c.setting, v);
}

// hit test: 1 the panel, 2 its header (drag), 3 close, 10+t a tab, 20+2f+d a filter's < or >, 30/31 the list up/down,
// 100+i a cell of the grid, 200+2i+d a Cfg row's < or >
static int pk_hit(int x, int y) {
  float r[4]; pk_rect(0, 0, PK_W, pk_h(), r); if (!in(r, x, y)) return 0;
  pk_rect(PK_W - 14, 1, 13, PK_HEAD - 2, r); if (in(r, x, y)) return 3;
  pk_rect(0, 0, PK_W, PK_HEAD, r); if (in(r, x, y)) return 2;
  float tw = (PK_W - 4) / 5.0f;
  for (int t = 0; t < 5; t++) { pk_rect(2 + t * tw, PK_HEAD, tw - 1, PK_TABS - 1, r); if (in(r, x, y)) return 10 + t; }
  if (g_pk_tab == 4) {
    for (int i = 0; i < k_ncfg; i++) for (int d = 0; d < 2; d++) {
      pk_rect(d ? PK_W - 16 : PK_W - 76, PK_HEAD + PK_TABS + 4 + i * 12, 12, 11, r); if (in(r, x, y)) return 200 + 2 * i + d;
    }
    return 1;
  }
  for (int f = 0; f < pk_strips(); f++) for (int d = 0; d < 2; d++) {
    pk_rect(d ? PK_W - 16 : 4, PK_HEAD + PK_TABS + f * PK_STRIP, 12, PK_STRIP - 1, r); if (in(r, x, y)) return 20 + 2 * f + d;
  }
  float gy = (float)pk_grid_y();
  for (int i = 0; i < PK_COLS * PK_ROWS; i++) { pk_rect(4 + (i % PK_COLS) * PK_CELL, gy + (i / PK_COLS) * PK_CELL, PK_CELL - 3, PK_CELL - 3, r); if (in(r, x, y)) return 100 + i; }
  float fy = gy + PK_ROWS * PK_CELL + 14;
  pk_rect(PK_W - 30, fy, 12, 12, r); if (in(r, x, y)) return 30;
  pk_rect(PK_W - 16, fy, 12, 12, r); if (in(r, x, y)) return 31;
  return 1;
}
// a bar's handle in layout mode, above it: its number (drag), its shape (columns x rows: click for the next),
// - and + (a slot less, a slot more), S (shared: the same slots for every job)
static const int k_hx[5] = { 0, 11, 30, 41, 52 }, k_hw[5] = { 10, 18, 10, 10, 10 };
static const int k_nparts = 5;
static void handle_rect(int b, int part, float r[4]) {
  float br[4]; bar_rect(g_cfg.bar[b], br); float k = scale();
  r[0] = br[0] + k_hx[part] * k * unit_x(); r[2] = r[0] + k_hw[part] * k * unit_x(); r[3] = br[1] - 1; r[1] = r[3] - 10 * k * unit_y();
}
// the next shape: the columns that divide the slots evenly, from one row down to one column, then round again
static int next_cols(const HbBar &b) {
  int c = bar_cols(b);
  for (int n = c - 1; n >= 1; n--) if (b.slots % n == 0) return n;
  return b.slots;
}
static int edit_over(int x, int y) {
  int p = pk_hit(x, y); if (p) return 5000 + p;
  for (int b = 0; b < HB_BARS; b++) if (g_cfg.bar[b].used) for (int part = 0; part < k_nparts; part++) { float r[4]; handle_rect(b, part, r); if (in(r, x, y)) return 2000 + b * 10 + part; }
  return 0;
}

static const char *dir_of() { return g_host->dir ? g_host->dir : "."; }
static void save_bars() { if (!hb_save_bars(dir_of(), &g_cfg)) g_host->log("hotbar: hotbar_layout.txt not written"); reload(true); }
static void save_slot(int b, int s, const char *spec) {   // b, s from 0; the slot of the environment shown
  if (!hb_save_slot(dir_of(), g_cfg.bar[b].shared ? "" : g_cfg.job, g_env, b + 1, s + 1, spec)) g_host->log("hotbar: the slots file not written");
  else g_host->log("hotbar: %s %d.%d %s%s", g_env ? "battle" : "field", b + 1, s + 1, spec && spec[0] ? "= " : "emptied", spec ? spec : "");
}
static void swap_slots(int b1, int s1, int b2, int s2) {
  static char a[320], c[320];
  hb_copy(a, sizeof a, g_lay.a[g_env][b1][s1].used ? g_lay.a[g_env][b1][s1].spec : "");
  hb_copy(c, sizeof c, g_lay.a[g_env][b2][s2].used ? g_lay.a[g_env][b2][s2].spec : "");
  save_slot(b1, s1, c); save_slot(b2, s2, a); reload(true);
}
static void toggle_edit(int on) {
  if (on < 0) on = !g_edit;
  if (on == g_edit) return;
  g_edit = on; g_dr = DR_NONE;
  if (on) { g_pk_built_tab = -1; g_host->log("hotbar: layout mode: drag bars by their frame or handle, slots onto slots to swap (off the bars to empty), actions from the picker onto slots; /htb move or the picker's x to end"); }
  else g_host->log("hotbar: layout mode ended (the bars in hotbar_layout.txt, the slots in the slots file)");
}

// the left button in layout mode (my_Down / my_Up below); o: over() at the press
static void edit_down(int x, int y, int o) {
  if (o >= 5000) {
    int p = o - 5000; float r[4]; pk_rect(0, 0, 1, 1, r);
    if (p == 2) { g_dr = DR_PANEL; g_dr_dx = x - r[0]; g_dr_dy = y - r[1]; }
    else if (p == 3) toggle_edit(0);
    else if (p >= 10 && p < 15) { g_pk_tab = p - 10; g_pk_f[0] = g_pk_f[1] = 0; g_pk_scroll = 0; }
    else if (p >= 20 && p < 24) { int f = (p - 20) / 2, d = (p - 20) % 2 ? 1 : -1; pk_filter(); int n = g_pk_nopt[f]; if (n) g_pk_f[f] = (g_pk_f[f] + d + n) % n; g_pk_scroll = 0; }
    else if (p == 30) { if (g_pk_scroll > 0) g_pk_scroll--; }
    else if (p == 31) g_pk_scroll++;
    else if (p >= 100 && p < 200) { pk_filter(); int i = g_pk_scroll * PK_COLS + (p - 100); if (i < g_pk_nv) { g_dr = DR_PICK; g_dr_pick = g_pk_view[i]; } }
    else if (p >= 200) cfg_step((p - 200) / 2, (p - 200) % 2 ? 1 : -1);
    return;
  }
  if (o >= 2000 && o < 3000) {
    int b = (o - 2000) / 10, part = (o - 2000) % 10; HbBar &bar = g_cfg.bar[b];
    if (part == 0) { float r[4]; bar_rect(bar, r); g_dr = DR_BAR; g_dr_b = b; g_dr_dx = x - r[0]; g_dr_dy = y - r[1]; }
    else if (part == 1) { bar.cols = next_cols(bar); bar.vertical = bar.cols == 1 && bar.slots > 1; save_bars(); }
    else if (part == 2 && bar.slots > 1) { int one_row = bar_cols(bar) == bar.slots; bar.slots--; if (one_row || bar.cols > bar.slots) bar.cols = bar.slots; save_bars(); }
    else if (part == 3 && bar.slots < HB_SLOTS) { int one_row = bar_cols(bar) == bar.slots; bar.slots++; if (one_row) bar.cols = bar.slots; save_bars(); }
    else if (part == 4) { bar.shared = !bar.shared; save_bars(); g_host->log("hotbar: bar %d %s", b + 1, bar.shared ? "shared: the same slots for every job (hotbar_slots.txt)" : "the job's own (hotbar_slots_<job>.txt)"); }
    return;
  }
  if (o == 1000) { g_queue_tag = 1; return; }
  if (o > 0) { int b = o / 100 - 1, s = o % 100 - 1; if (g_lay.a[g_env][b][s].used) { g_dr = DR_SLOT; g_dr_b = b; g_dr_s = s; } return; }
  if (o < 0) { int b = -o - 1; float r[4]; bar_rect(g_cfg.bar[b], r); g_dr = DR_BAR; g_dr_b = b; g_dr_dx = x - r[0]; g_dr_dy = y - r[1]; }
}
static void edit_up(int x, int y) {
  int d = g_dr; g_dr = DR_NONE;
  int o = over(x, y), slot = o > 0 && o < 1000;
  if (d == DR_SLOT) {
    if (slot) { int b = o / 100 - 1, s = o % 100 - 1; if (b != g_dr_b || s != g_dr_s) swap_slots(g_dr_b, g_dr_s, b, s); }
    else if (o == 0 || o >= 5000) { save_slot(g_dr_b, g_dr_s, ""); reload(true); }   // off the bars (or onto the picker): emptied
  } else if (d == DR_PICK && slot) {
    const HbPick &p = g_pk_all[g_dr_pick]; char spec[320];
    hb_fmt(spec, sizeof spec, "xiv|%s|%s|%s||", p.type, p.name, p.target);
    save_slot(o / 100 - 1, o % 100 - 1, spec); reload(true);
  } else if (d == DR_BAR) save_bars();
}
// each frame while a drag goes on: the bar or the panel follows the cursor
static void edit_frame() {
  int x, y; if (!g_dr || !cursor(&x, &y)) return;
  if (g_dr == DR_BAR) { HbBar &b = g_cfg.bar[g_dr_b]; b.x = (int)((x - g_dr_dx) / unit_x()); b.y = (int)((y - g_dr_dy) / unit_y()); if (b.x < 0) b.x = 0; if (b.y < 0) b.y = 0; }
  if (g_dr == DR_PANEL) { g_pk_x = (int)((x - g_dr_dx) / unit_x()); g_pk_y = (int)((y - g_dr_dy) / unit_y()); if (g_pk_x < 0) g_pk_x = 0; if (g_pk_y < 0) g_pk_y = 0; }
}

static void tex_states(IDirect3DDevice8 *dev) {
  dev->SetVertexShader(FVF_XYZRHW | FVF_DIFFUSE | FVF_TEX1);
  dev->SetTextureStageState(0, D3DTSS_COLOROP, TOP_MODULATE); dev->SetTextureStageState(0, D3DTSS_COLORARG1, TA_TEXTURE); dev->SetTextureStageState(0, D3DTSS_COLORARG2, TA_DIFFUSE);
  dev->SetTextureStageState(0, D3DTSS_ALPHAOP, TOP_MODULATE); dev->SetTextureStageState(0, D3DTSS_ALPHAARG1, TA_TEXTURE); dev->SetTextureStageState(0, D3DTSS_ALPHAARG2, TA_DIFFUSE);
  dev->SetTextureStageState(0, D3DTSS_MAGFILTER, TEXF_LINEAR); dev->SetTextureStageState(0, D3DTSS_MINFILTER, TEXF_LINEAR);
}
// layout mode's drawing, over the bars: the handles, the picker, what is dragged
static void draw_edit(IDirect3DDevice8 *dev, const Saved &sv, int hov) {
  int cx = -1, cy = -1; cursor(&cx, &cy);
  float t = unit_x() * scale(), k = pk_k(), sc = 0.5f * unit_x() * k;
  if (g_pk_tab < 4) pk_filter();
  plain_states(dev);
  for (int b = 0; b < HB_BARS; b++) if (g_cfg.bar[b].used) {
    float r[4]; bar_rect(g_cfg.bar[b], r); frame(r[0], r[1], r[2], r[3], t, 0xFF40A0FFu);
    for (int part = 0; part < k_nparts; part++) {
      float h[4]; handle_rect(b, part, h); int lit = part == 4 && g_cfg.bar[b].shared;
      quad(h[0], h[1], h[2], h[3], lit ? 0xE0406030u : 0xD0182848u, lit ? 0xE0203018u : 0xD0080C20u); frame(h[0], h[1], h[2], h[3], t, hov == 2000 + b * 10 + part ? 0xFFFFA040u : 0x90A8B0C8u);
    }
  }
  float r[4]; pk_rect(0, 0, PK_W, pk_h(), r);
  quad(r[0], r[1], r[2], r[3], 0xE0182848u, 0xE0080C20u); frame(r[0], r[1], r[2], r[3], t, 0x90A8B0C8u);
  float tw = (PK_W - 4) / 5.0f;
  for (int i = 0; i < 5; i++) { float q[4]; pk_rect(2 + i * tw, PK_HEAD, tw - 1, PK_TABS - 1, q); quad(q[0], q[1], q[2], q[3], i == g_pk_tab ? 0xE0405880u : 0xC0101830u, i == g_pk_tab ? 0xE0203050u : 0xC0080C20u); }
  float gy = (float)pk_grid_y();
  if (g_pk_tab < 4) for (int i = 0; i < PK_COLS * PK_ROWS; i++) {
    int vi = g_pk_scroll * PK_COLS + i; if (vi >= g_pk_nv) break;
    float q[4]; pk_rect(4 + (i % PK_COLS) * PK_CELL, gy + (i / PK_COLS) * PK_CELL, PK_CELL - 3, PK_CELL - 3, q);
    quad(q[0], q[1], q[2], q[3], 0xA0060A18u, 0xA0060A18u); frame(q[0], q[1], q[2], q[3], t, hov == 5100 + i ? 0xFFFFA040u : 0x80707890u);
  }
  flush_quads(dev);
  tex_states(dev);
  if (g_pk_tab < 4) for (int i = 0; i < PK_COLS * PK_ROWS; i++) {
    int vi = g_pk_scroll * PK_COLS + i; if (vi >= g_pk_nv) break;
    IDirect3DTexture8 *tx = texture(g_pk_all[g_pk_view[vi]].icon); if (!tx) continue;
    float q[4]; pk_rect(4 + (i % PK_COLS) * PK_CELL, gy + (i / PK_COLS) * PK_CELL, PK_CELL - 3, PK_CELL - 3, q);
    icon(dev, tx, q[0] + t, q[1] + t, q[2] - t, q[3] - t, 0xFFFFFFFFu);
  }
  // what is dragged, under the cursor
  const char *dicon = g_dr == DR_SLOT ? g_lay.a[g_env][g_dr_b][g_dr_s].icon : g_dr == DR_PICK ? g_pk_all[g_dr_pick].icon : "";
  if (dicon[0]) { IDirect3DTexture8 *tx = texture(dicon); float w = S * scale() * unit_x(), h = S * scale() * unit_y(); if (tx) icon(dev, tx, cx - w / 2, cy - h / 2, cx + w / 2, cy + h / 2, 0xC0FFFFFFu); }
  restore(dev, sv);
  // text
  for (int b = 0; b < HB_BARS; b++) if (g_cfg.bar[b].used) {
    static const char *const parts[5] = { "", "", "-", "+", "S" }; char n[8], shp[12];
    hb_fmt(shp, sizeof shp, "%dx%d", bar_cols(g_cfg.bar[b]), bar_rows(g_cfg.bar[b]));
    for (int part = 0; part < k_nparts; part++) {
      float h[4]; handle_rect(b, part, h);
      const char *l = part == 0 ? (hb_fmt(n, sizeof n, "%d", b + 1), n) : part == 1 ? shp : parts[part];
      float s2 = 0.4f * unit_x() * scale(); text(h[0] + (h[2] - h[0] - measure(l) * s2) / 2, h[1], l, hov == 2000 + b * 10 + part ? 0x80805020u : 0x80808080u, s2);
    }
  }
  pk_rect(4, 1, 1, 1, r); text(r[0], r[1], "Actions (layout mode)", 0x80805020u, sc);
  pk_rect(PK_W - 12, 1, 1, 1, r); text(r[0], r[1], "x", hov == 5003 ? 0x80805020u : 0x80808080u, sc);
  for (int i = 0; i < 5; i++) { float q[4]; pk_rect(2 + i * tw, PK_HEAD, tw - 1, PK_TABS - 1, q); float s2 = 0.45f * unit_x() * k; text(q[0] + (q[2] - q[0] - measure(k_tabs[i]) * s2) / 2, q[1] + 1, k_tabs[i], i == g_pk_tab ? 0x80805020u : 0x80808080u, s2); }
  if (g_pk_tab == 4) {
    for (int i = 0; i < k_ncfg; i++) {
      float y = (float)(PK_HEAD + PK_TABS + 4 + i * 12); char v[24]; cfg_value(i, v, sizeof v);
      pk_rect(6, y, 1, 1, r); text(r[0], r[1], k_cfg[i].label, 0x80808080u, sc * 0.9f);
      pk_rect(PK_W - 76, y, 1, 1, r); text(r[0], r[1], "<", hov == 5200 + 2 * i ? 0x80805020u : 0x80808080u, sc);
      float q[4]; pk_rect(PK_W - 62, y, 44, 11, q); text(q[0] + (q[2] - q[0] - measure(v) * sc * 0.9f) / 2, q[1], v, 0x80805020u, sc * 0.9f);
      pk_rect(PK_W - 14, y, 1, 1, r); text(r[0], r[1], ">", hov == 5201 + 2 * i ? 0x80805020u : 0x80808080u, sc);
    }
  } else {
    static const char *const fname[4][2] = { { "Type", "School" }, { "", "" }, { "Type", "" }, { "Weapon", "" } };
    for (int f = 0; f < pk_strips(); f++) {
      char l[64]; hb_fmt(l, sizeof l, "%s: %s", fname[g_pk_tab][f], g_pk_nopt[f] ? g_pk_opts[f][g_pk_f[f]] : "All");
      float y = (float)(PK_HEAD + PK_TABS + f * PK_STRIP);
      pk_rect(6, y, 1, 1, r); text(r[0], r[1], "<", hov == 5020 + 2 * f ? 0x80805020u : 0x80808080u, sc);
      float q[4]; pk_rect(16, y, PK_W - 32, PK_STRIP, q); text(q[0] + (q[2] - q[0] - measure(l) * sc) / 2, q[1], l, 0x80808080u, sc);
      pk_rect(PK_W - 14, y, 1, 1, r); text(r[0], r[1], ">", hov == 5021 + 2 * f ? 0x80805020u : 0x80808080u, sc);
    }
    float fy = gy + PK_ROWS * PK_CELL;
    int hi = hov >= 5100 && hov < 5200 ? g_pk_scroll * PK_COLS + hov - 5100 : -1;
    char l[96];
    if (hi >= 0 && hi < g_pk_nv) { const HbPick &p = g_pk_all[g_pk_view[hi]]; hb_fmt(l, sizeof l, "%s <%s>", p.name, p.target); }
    else hb_fmt(l, sizeof l, "%d actions%s", g_pk_nv, g_pk_learned_seen < 0 ? " (the game's list not come)" : "");
    pk_rect(6, fy, 1, 1, r); text(r[0], r[1], l, 0x80808080u, sc);
    int pages = (g_pk_nv + PK_COLS - 1) / PK_COLS; char pg[24]; hb_fmt(pg, sizeof pg, "row %d/%d", g_pk_scroll + 1, pages > 0 ? pages : 1);
    pk_rect(6, fy + 14, 1, 1, r); text(r[0], r[1], pg, 0x80606060u, sc * 0.9f);
    pk_rect(PK_W - 28, fy + 14, 1, 1, r); text(r[0], r[1], "^", hov == 5030 ? 0x80805020u : 0x80808080u, sc);
    pk_rect(PK_W - 14, fy + 14, 1, 1, r); text(r[0], r[1], "v", hov == 5031 ? 0x80805020u : 0x80808080u, sc);
  }
}

// ---------------------------------------------------------------------------------------------- hooks
static xikit::fn<decltype(&Menu_DrawLayers)> prev_Draw;
static void __thiscall my_Draw(void *mng) {
  prev_Draw(mng);                                     // the game's windows first; the bars over them
  if (!g_host->setting_int("hb_show", 1)) return;
  if (++g_frame % 30 == 0) {
    reload(false);
    // (28 Nov) follow the game's own jobs (xistate::job, job_name): when they change, read the job's tables, as
    // "hb job" would. hb_follow_job=0, or a typed "hb job", turns it off.
    static int last_m = -1, last_s = -1;
    // (29 Nov) the inventory changed: autoitem slots made again from it (Petit Trois makes them at load and on changes)
    { unsigned was = g_inv_hash; inventory_read(); if (g_inv_hash != was && has_autoitem()) reload(true); }
    { static unsigned lh; unsigned h = learned_hash(); if (h != lh) { lh = h; if (has_spec("xiv|bstpet|")) reload(true); } }
    { static int hz = -1; int h = g_host->setting_int("hb_horizon", 0); if (h != hz) { bool was = hz >= 0; hz = h; hb_set_horizon(h); if (was) reload(true); } }
    // (29 Nov) Petit Trois's weapon switching (xivhotbar2.lua set_weapon_type, action_manager.lua): the main and ranged
    // weapons' skills name tables of the job file ("Sword", "Club"...: weaponskill_types) that are read as sets.
    // Equipment slots 0 and 2 are the main and ranged weapons by Windower's slot numbers (a lead); a weapon's skill is
    // its row in Windower's items.lua. hb_weapons=0 turns it off.
    {
      static char cur[2][32];
      char now[2][32] = { "", "" };
      if (g_host->setting_int("hb_weapons", 1)) {
        hb_copy(now[0], 32, hb_weapon_set(g_test_inv >= 0 ? g_test_inv : xistate::equipped_item(0)));
        hb_copy(now[1], 32, g_test_inv >= 0 ? "" : hb_weapon_set(xistate::equipped_item(2)));
      }
      if (strcmp(now[0], cur[0]) || strcmp(now[1], cur[1])) {
        if (!g_have_ovr) { g_ovr = g_cfg; g_have_ovr = 1; }
        for (int k = 0; k < 2; k++) if (cur[k][0] && strcmp(cur[k], now[0]) && strcmp(cur[k], now[1])) set_override(nullptr, nullptr, 1, cur[k]);   // off
        for (int k = 0; k < 2; k++) if (now[k][0] && strcmp(now[k], cur[0]) && strcmp(now[k], cur[1])) {
          bool on = false; for (int i = 0; i < g_ovr.nsets; i++) on |= hb_ieq(g_ovr.sets[i], now[k]);
          if (!on) set_override(nullptr, nullptr, 1, now[k]);
        }
        g_host->log("hotbar: the weapons' sets: %s%s%s (were %s%s%s)", now[0][0] ? now[0] : "none", now[1][0] ? ", " : "", now[1],
                    cur[0][0] ? cur[0] : "none", cur[1][0] ? ", " : "", cur[1]);
        hb_copy(cur[0], 32, now[0]); hb_copy(cur[1], 32, now[1]);
      }
    }
    if (g_host->setting_int("hb_follow_job", 1) && !g_user_job) {
      int m = xistate::job(0, nullptr), sj = xistate::job(1, nullptr);
      if ((m != last_m || sj != last_s) && m > 0) {
        last_m = m; last_s = sj; const char *mn = xistate::job_name(m), *sn = sj > 0 ? xistate::job_name(sj) : "";
        if (mn[0]) { g_host->log("hotbar: the game's jobs: %s%s%s (numbers %d, %d): their tables read", mn, sn[0] ? "/" : "", sn, m, sj); set_override(mn, sn, 0, nullptr); }
      }
    }
  }
  g_made_this_frame = 0;
  for (int b = 0; b < HB_BARS; b++) for (int i = 0; i < HB_SLOTS; i++) if (g_flash[b][i] > 0) g_flash[b][i]--;
  poll_keys();
  if (g_edit) edit_frame();
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
    if (g_edit) { edit_down(x, y, o); return; }
    if (o == 1000) g_queue_tag = 1;
    else if (o > 0 && g_queue_b < 0) { g_queue_b = o / 100 - 1; g_queue_s = o % 100 - 1; g_queue_how = "(click)"; }
    return;
  }
  prev_Down(self);
}
static xikit::fn<decltype(&Cursor_ToggleFlag1)> prev_Up;
static void __thiscall my_Up(void *self) {
  if (g_swallow) { g_swallow = 0; int x, y; if (g_edit && g_dr && cursor(&x, &y)) edit_up(x, y); else g_dr = DR_NONE; return; }
  prev_Up(self);
}

// typed "/htb ..." lines (xikit_cmd.hpp): the same commands a slot can hold
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

// (29 Nov) every action message as the game parses it: fn_1018D170 (0x1018D170) is handed the parsed record (xistate::action)
// before the parser looks the actor up. Petit Trois reads the first target's first action of each (skillchains.lua
// handle_action); so does this.
static xikit::fn<decltype(&fn_1018D170)> prev_Act;
static void __thiscall my_Act(void *self, undefined4 *rec) {
  if (rec) {
    g_sc_seen++;
    namespace A = xistate::action;
    if (A::targets(rec) >= 1 && A::actions(rec, 0) >= 1 &&
        hb_sc_action(A::actor_id(rec), A::param(rec), A::target_id(rec, 0), A::message(rec, 0, 0), hb_now_ms())) g_sc_used++;
  }
  prev_Act(self, rec);
}
extern "C" __declspec(dllexport) void hb_test_sc(unsigned target, int statuses, long *seen, long *used) { g_test_target = target; g_test_status = statuses; if (seen) *seen = g_sc_seen; if (used) *used = g_sc_used; }
extern "C" __declspec(dllexport) void hb_test_clock(int ms) { hb_clock_add(ms); }
extern "C" __declspec(dllexport) void hb_test_weapon(int item_id) { g_test_inv = item_id; }   // a main weapon's item id for the test; -1 the game's
extern "C" __declspec(dllexport) int hb_test_item(int b, int s, int *id, int *count) {
  if (b < 1 || b > HB_BARS || s < 1 || s > HB_SLOTS) return 0;
  const HbAct &a = g_lay.a[g_env][b - 1][s - 1]; *id = a.id; *count = item_count(a.id); return a.used;
}
extern "C" __declspec(dllexport) int hb_test_scprops(char *out, int n) { int w, b; return hb_sc_state(g_test_target, hb_now_ms(), out, n, &w, &b); }
extern "C" __declspec(dllexport) int hb_test_scslot(int b, int s, char *prop, int n, int *level) {
  chains_update(); if (b < 1 || b > HB_BARS || s < 1 || s > HB_SLOTS) return 0;
  const ScSlot &c = g_scs[b - 1][s - 1]; hb_copy(prop, n, c.prop); *level = c.level; return c.chain | (c.burst << 1);
}
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
// (29 Nov) layout mode for the offline test: a bar handle's rectangle, the picker's parts (pk_hit's codes: 10+t a tab,
// 100+i a grid cell), the picker's list (its count and the name of the first shown), layout mode on or off
extern "C" __declspec(dllexport) int hb_test_handle(int b, int part, float *r4) { if (b < 1 || b > HB_BARS || !g_cfg.bar[b - 1].used) return 0; handle_rect(b - 1, part, r4); return 1; }
extern "C" __declspec(dllexport) int hb_test_pk_rect(int code, float *r4) {
  if (code >= 10 && code < 15) { float tw = (PK_W - 4) / 5.0f; pk_rect(2 + (code - 10) * tw, PK_HEAD, tw - 1, PK_TABS - 1, r4); return 1; }
  if (code >= 100 && code < 136) { int i = code - 100; pk_rect(4 + (i % PK_COLS) * PK_CELL, pk_grid_y() + (i / PK_COLS) * PK_CELL, PK_CELL - 3, PK_CELL - 3, r4); return 1; }
  return 0;
}
extern "C" __declspec(dllexport) int hb_test_pick(int *tab, char *first, int firstlen) { pk_filter(); *tab = g_pk_tab; hb_copy(first, firstlen, g_pk_nv ? g_pk_all[g_pk_view[0]].name : ""); return g_pk_nv; }
extern "C" __declspec(dllexport) int hb_test_edit(void) { return g_edit; }
// (29 Nov) a slot's state as the game gives it (kind, record, ticks, total, charges, next, state) and its tooltip lines
extern "C" __declspec(dllexport) int hb_test_slotstate(int b, int s, int *o7) {
  if (b < 1 || b > HB_BARS || s < 1 || s > HB_SLOTS) return 0;
  const SlotState &st = g_ss[g_env][b - 1][s - 1];
  o7[0] = st.kind; o7[1] = st.rec; o7[2] = st.ticks; o7[3] = st.total; o7[4] = st.charges; o7[5] = st.next; o7[6] = st.state; return 1;
}
extern "C" __declspec(dllexport) int hb_test_tip(int b, int s, char *out, int outlen) {
  if (b < 1 || b > HB_BARS || s < 1 || s > HB_SLOTS || !g_lay.a[g_env][b - 1][s - 1].used) return 0;
  static char lines[16][96]; unsigned col[16]; int n = tip_lines(g_lay.a[g_env][b - 1][s - 1], g_ss[g_env][b - 1][s - 1], &g_scs[b - 1][s - 1], lines, col, 16);
  out[0] = 0; for (int k = 0; k < n; k++) { size_t l = strlen(out); hb_fmt(out + l, outlen - (int)l, "%s%s", k ? "\n" : "", lines[k]); }
  return n;
}
extern "C" __declspec(dllexport) int hb_test_textures(void) { int n = 0; for (int i = 0; i < g_ntex; i++) n += g_tex[i].state == 1; return n; }

static const char *k_default =
  "# Longthinx hotbar. Changes are read while the game runs.\n"
  "#   bar <n 1-10> <slots 1-12> <x> <y> [v|h|c<cols>] [shared]   in the interface's 640x480 units; a negative x\n"
  "#                                          or y counts from the right or bottom edge; v: one column, h: one row,\n"
  "#                                          c<cols>: cols slots a row (12x1, 6x2, 4x3, ...); shared: the bar's slots\n"
  "#                                          are the same for every job\n"
  "#   [field|battle] <bar>.<slot> <key> <label> = <command line>[; wait 2; <command line>...] [| icon]\n"
  "#   key <bar>.<slot> <key>                  a key for a slot (also for XIVhotbar2's slots)\n"
  "#   xiv <folder>                            XIVhotbar2's folder (data, images, priv_res): its job files, icons, costs\n"
  "#   windower <folder>                       Windower's folder, for res\\monster_abilities.lua (pets' and monsters'\n"
  "#                                          skillchains); without it, the Windower that holds the xiv folder\n"
  "#   xiv keys                                its data\\default_keybinds.lua for the keys\n"
  "#   job <job> [<subjob>]   set <name>       which of its tables to read (General's Root, the job's Base, the subjob's\n"
  "#                                          table, the sets); \"hb job\" and \"hb set\" change them while playing\n"
  "#   env field|battle       envkey <key>     the starting set, and a key that switches field <-> battle\n"
  "# Keys: 1-0 - = [ ] ; ' , . / ` a-z f1-f12 num0-num9, with c- (Ctrl) a- (Alt) s- (Shift) in front, or none.\n"
  "# Without a key of its own, slot 1-12 of bar 1 is 1 2 3 4 5 6 7 8 9 0 - =, bar 2 the same with Ctrl, bar 3 with Alt,\n"
  "# bar 4 with Shift (\"key 1.1 none\" takes one away). A slot line's key \"none\" keeps the default.\n"
  "# /htb mode hotbar (the default): the game's macro keys run bars 2 and 3 instead of its macros (an empty slot\n"
  "# leaves the game's macro); /htb mode macro: the game's macros as always, keys for bar 1.\n"
  "# A line runs as if typed in the chat line and sent. The hotbar does not take keys away from the game; a key typed\n"
  "# into the chat line runs nothing (a slot runs 3 frames after its key, if the chat line's text did not change). Commands of the hotbar itself, typed in the chat line: /htb env [field|battle],\n"
  "# /htb run <bar>.<slot>, /htb mode [hotbar|macro], /htb job <job> [<sub>], /htb set <name>, /htb reload, /htb hide, /htb show.\n"
  "# /htb move: layout mode, as XIVhotbar2 Petit Trois Edition's: drag bars (frame or handle), slots onto slots (off\n"
  "# the bars: emptied), actions from the picker onto slots; the handle's H/V turns a bar, - and + change its slots;\n"
  "# the picker's Cfg tab holds the settings. /htb set <row> <slot> <type> <action> [target] [alias], /htb clear\n"
  "# <row> <slot>, /htb rename <row> <slot> <label> (underscores for spaces). What layout mode changes is kept in\n"
  "# hotbar_layout.txt (bars) and hotbar_slots_<job>.txt (slots), read after this file; this file is not written.\n"
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
  host->declare_int("hb_follow_job", 1, 0, 1, "1: read the tables of the job the game says you are (until \"hb job\" is typed)");
  host->declare_int("hb_recasts", 1, 0, 1, "1: the recast left over each spell and ability slot (the game's own countdowns)");
  host->declare_int("hb_tips", 1, 0, 1, "1: a tooltip (the label and the line) over the slot under the cursor");
  host->declare_int("hb_keys_poll", 0, 0, 1, "1: read keys by polling each frame (a system call per key per frame); 0: from the game window's messages");
  host->declare_int("hb_gap", 3, 0, 12, "the gap between slots (640x480 units)");
  host->declare_int("hb_names", 1, 0, 1, "1: the action's name under its slot");
  host->declare_int("hb_costs", 1, 0, 1, "1: the MP or TP cost in the slot's corner");
  host->declare_int("hb_keys", 1, 0, 1, "1: the slot's key in its corner");
  host->declare_int("hb_bg", 0, 0, 9, "the bars' backdrop: 0 the hotbar's own, 1 none, 2-9 Petit Trois's dark, blue, sky blue, purple, yellow, pine, red, orange");
  host->declare_int("hb_alpha", 160, 0, 255, "the slots' opacity (empty slots 3/5 of it)");
  host->declare_int("hb_sweep", 1, 0, 1, "1: a dark sweep over a slot while its recast runs (the part left)");
  host->declare_int("hb_barnums", 1, 0, 1, "1: each bar's number at its left");
  host->declare_int("hb_horizon", 0, 0, 1, "1: the spells of the Horizon server (Petit Trois's priv_res/horizon_spells.lua) instead of spells.lua");
  hb_set_horizon(host->setting_int("hb_horizon", 0));
  hb_set_learned(learned_cb);
  host->declare_int("hb_weapons", 1, 0, 1, "1: read the job file's tables named for the main and ranged weapons' skills (Sword, Club...) as sets (Petit Trois's weapon switching)");
  host->declare_int("hb_sc", 1, 0, 1, "1: outline the slots that would make a skillchain on the target now (Petit Trois's rules)");
  host->declare_int("hb_mb", 1, 0, 1, "1: outline the spells that would magic burst on the target now");
  host->declare_int("hb_desc", 1, 0, 1, "1: the action's description in the tooltip (XIVhotbar2's priv_res descriptions)");
  host->declare_int("hb_mode", 1, 0, 1, "1 hotbar: the game's macro keys run bars 2 and 3 and its macro palettes stay hidden; 0 macro: the game's macros run, keys for bar 1 (/htb mode)");
  const char *dir = host->dir ? host->dir : ".";
  if (!hb_mtime(dir) && hb_write_file(dir, "hotbar.txt", k_default)) host->log("hotbar: wrote an example hotbar.txt");
  reload(true);
  xicmd::add("htb", typed_hb);                                      // /htb, as Petit Trois's //htb (one slash: no Windower)
  if (xicmd::install(host) != XIKIT_OK) host->log("hotbar: Command_RunLine not hooked: typed /htb commands go to the game");
  int r = XI_HOOK(host, Menu_DrawLayers, my_Draw, prev_Draw);
  if (!r) r = XI_HOOK(host, Target_PickNearestToPoint, my_Pick, prev_Pick);
  if (r) return r;
  if (XI_HOOK(host, TextInputFiles_QueueEntry, my_Queue, prev_Queue))
    host->log("hotbar: TextInputFiles_QueueEntry not hooked: the game's macros always run (hotbar mode has no effect)");
  if (XI_HOOK(host, MenuMng_OpenByName, my_Open, prev_Open))
    host->log("hotbar: MenuMng_OpenByName not hooked: the game's macro palettes show in hotbar mode");
  g_sc_hooked = !XI_HOOK(host, fn_1018D170, my_Act, prev_Act);
  if (!g_sc_hooked) host->log("hotbar: the action message hook (fn_1018D170) was refused: no skillchains or bursts shown");
  if (XI_HOOK(host, Cursor_EnterMode1, my_Down, prev_Down) || XI_HOOK(host, Cursor_ToggleFlag1, my_Up, prev_Up))
    host->log("hotbar: the left-button hooks were refused: slots are not clickable (keys work)");
  return 0;
}
