// ui_layout.cpp -- an example mod: move the game's interface windows, each by name or all together.
// Build:  sdk/build_mod.sh ui_layout.dll sdk/examples/ui_layout.cpp sdk/examples/ui_layout_core.cpp
//
// What the game's code shows (tree/src/NetCellFont.cpp, tree/src/TargetMenu.cpp, and the disassembly of 0x10117520;
// XIKit docs/MENUS.md):
// - the menu manager g_menuMng (0x10621838) keeps its windows in a list at +0 (head pointer; a node: +0 next, +0x10 the
//   window, +0x14 a skip byte); Menu_DrawLayers (0x1015F6A0) draws each visible one with Menu_DrawWindowItems;
// - a window has its own node list at +0x14; node kind 0 is its frame. Where it is drawn comes from the window's
//   target position and size, the shorts at +0x8C, +0x8E, +0x90, +0x92: each frame 0x10117520 (the first call of
//   Menu_DrawWindowItems) eases the frame node's position (+0x1A, +0x1C) toward +0x8C/+0x8E;
// - the shorts at +0x3A..+0x40 (left, top, right, bottom) are the hit rectangle (NetCellFont_HitTest 0x10118C10);
// - all four groups are written by one game function, NetCellFont_SetRectAndUpdateNodes (0x1011A5A0; thiscall:
//   window, x, y, width, height, (unused), snap (0: the frame node jumps there at once; else it eases), a byte kept at
//   +0x9A); in the tree's source it is the only writer of +0x8C and +0x3A, and 40 of the game's functions call it to
//   place their windows;
// - a window's name is the 16 characters at (window +4) +0x46: the game looks windows up by it.
// - (25 Nov) its title: window +4 is its layout record (NetCellFont_Rebuild, tree/src/NetCellFont.cpp:13645, from
//   MenuMng_OpenByName's Menu_FindItemByNameAt1C); the record's +8 is its frame (0x1011B06D) and the frame's +0xC the
//   title text the game took from message table 13 (0x1011B5BE), or 0 (docs/DATA_FILES.md section 4). ui_list logs it
//   (its printable characters; the text's inline codes are left out), so the log names windows the way the game shows them.
//
// (25 Nov) The first version wrote +0x3A..+0x40 before each draw: that moved only the hit rectangle, never what is
// drawn (the owner's run: "does not work at all"). This one hooks NetCellFont_SetRectAndUpdateNodes: each time the
// game places a window, its position is offset by ui_dx/ui_dy (settings, for all) plus the window's line in
// <kit folder>\ui_layout.txt ("<name> <dx> <dy>", the name being its 16 characters without spaces, lower case). What
// the game asked for is kept as the window's base; when the settings or the file change, the windows still in the
// menu manager's list are placed again (in the next Menu_DrawLayers, through the same game function, snap on) at
// base + the new offset. ui_list=1 logs each window's name and the rectangle the game gave it, once.
// Units: the game's own (the rectangles it passes; the owner's log shows screen pixels at 1512x949, not 512x448).
// Not known: whether some window is placed by code that writes the fields without this function (none in the tree's
// source; the functions without source are not read); whether a moved window is clamped to the screen by its own
// code.
//
// Tested offline (kit/xikit/test, mode uimod): the game's own SetRectAndUpdateNodes on windows built in memory with a
// frame node, through its entry (hooked): moved by name and by the global offset, the hit rectangle and the frame node
// with it; a settings change places a visible window again; the game's own hit test finds a point in the moved window.
// Not yet run in the game.
#include "xikit_sdk.hpp"
XIKIT_MOD_GLOBALS

extern "C" int ul_read(const char *dir, char (*keys)[17], short *dx, short *dy, int max);   // ui_layout_core.cpp

static const XikitHost *g_host;
struct Rule { char key[17]; short dx, dy; };
static Rule g_rules[128]; static int g_nrules;
struct Win { void *w; int bx, by, bw, bh, p5, p7; int dx, dy; bool listed; };
static Win g_win[256]; static int g_nwin; static volatile bool g_replace;

static void key_of(const char *name16, char out[17]) {
  int k = 0; for (int i = 0; i < 16 && name16[i]; i++) if (name16[i] != ' ') { char c = name16[i]; out[k++] = c >= 'A' && c <= 'Z' ? c + 32 : c; }
  out[k] = 0;
}
static void read_rules() {
  static char k[128][17]; static short dx[128], dy[128];
  g_nrules = ul_read(g_host->dir ? g_host->dir : ".", k, dx, dy, 128);
  for (int i = 0; i < g_nrules; i++) { memcpy(g_rules[i].key, k[i], 17); g_rules[i].dx = dx[i]; g_rules[i].dy = dy[i]; }
  g_host->log("ui_layout: %d windows in ui_layout.txt; ui_dx %d, ui_dy %d", g_nrules, g_host->setting_int("ui_dx", 0), g_host->setting_int("ui_dy", 0));
}
static void offset_of(void *w, int *dx, int *dy, char key[17]) {
  char *md = *reinterpret_cast<char **>(reinterpret_cast<char *>(w) + 4);
  key[0] = 0; if (md) key_of(md + 0x46, key);
  *dx = g_host->setting_int("ui_dx", 0); *dy = g_host->setting_int("ui_dy", 0);
  for (int i = 0; i < g_nrules; i++) if (!strcmp(g_rules[i].key, key)) { *dx += g_rules[i].dx; *dy += g_rules[i].dy; break; }
}
static void title_of(void *w, char out[64]) {                 // the window's title, as the game loaded it, or ""
  out[0] = 0;
  const char *md = *reinterpret_cast<char **>(reinterpret_cast<char *>(w) + 4); if (!md) return;
  const char *fr = *reinterpret_cast<char *const *>(md + 8); if (!fr) return;
  const char *t = *reinterpret_cast<char *const *>(fr + 0xC); if (!t) return;
  int k = 0; for (int i = 0; t[i] && i < 200 && k < 63; i++) { unsigned char c = (unsigned char)t[i]; if (c >= 0x20 && c < 0x7F) out[k++] = (char)c; }
  out[k] = 0;
}
static Win *win_of(void *w) {
  for (int i = 0; i < g_nwin; i++) if (g_win[i].w == w) return &g_win[i];
  if (g_nwin == 256) g_nwin = 0;                         // (forget the oldest set: each is recorded again when the game places it)
  Win *r = &g_win[g_nwin++]; memset(r, 0, sizeof *r); r->w = w; return r;
}

static xikit::fn<decltype(&NetCellFont_SetRectAndUpdateNodes)> prev_SetRect;
static undefined4 __thiscall my_SetRect(void *w, undefined4 x, undefined4 y, undefined4 wd, undefined4 ht, undefined4 p5, undefined4 snap, undefined4 p7) {
  int dx, dy; char key[17]; offset_of(w, &dx, &dy, key);
  Win *r = win_of(w); r->bx = (int)x; r->by = (int)y; r->bw = (int)wd; r->bh = (int)ht; r->p5 = (int)p5; r->p7 = (int)p7; r->dx = dx; r->dy = dy;
  if (g_host->setting_int("ui_list", 0) && !r->listed) { r->listed = true; char t[64]; title_of(w, t); g_host->log("ui_layout: window %s (\"%s\") placed by the game at %d,%d size %d,%d; offset %d,%d", key, t, (int)x, (int)y, (int)wd, (int)ht, dx, dy); }
  return prev_SetRect(w, (undefined4)((int)x + dx), (undefined4)((int)y + dy), wd, ht, p5, snap, p7);
}

static void replace_visible() {                             // the settings changed: the windows still listed, placed again
  int pos = (int)orig::NetCellFont_GetHead(&g_menuMng_as_v0), n = 0;
  while (pos) {
    void *w = (void *)(uintptr_t)(uint32_t)orig::Menu_NextVisibleItem(&pos);
    if (!w) continue;
    for (int i = 0; i < g_nwin; i++) if (g_win[i].w == w) {
      int dx, dy; char key[17]; offset_of(w, &dx, &dy, key);
      if (dx != g_win[i].dx || dy != g_win[i].dy) { Win r = g_win[i];
        my_SetRect(w, (undefined4)r.bx, (undefined4)r.by, (undefined4)r.bw, (undefined4)r.bh, (undefined4)r.p5, 0, (undefined4)*(reinterpret_cast<uint8_t *>(w) + 0x9A)); n++; }
      break;
    }
  }
  if (n) g_host->log("ui_layout: %d window(s) placed again for the new settings", n);
}

static xikit::fn<decltype(&Menu_DrawLayers)> prev_Draw;
static void __thiscall my_Draw(void *mng) { if (g_replace) { g_replace = false; replace_visible(); } prev_Draw(mng); }

extern "C" __declspec(dllexport) void xikit_mod_settings(void) { read_rules(); g_replace = true; }
extern "C" __declspec(dllexport) int xikit_mod_init(const XikitHost *host) {
  g_host = host;
  host->declare_int("ui_dx", 0, -2000, 2000, "move every interface window right (the game's units: screen pixels in the owner's game)");
  host->declare_int("ui_dy", 0, -2000, 2000, "move every interface window down");
  host->declare_int("ui_list", 0, 0, 1, "1: log each window's name and the rectangle the game gives it, once (the names for ui_layout.txt)");
  read_rules();
  int r = XI_HOOK(host, NetCellFont_SetRectAndUpdateNodes, my_SetRect, prev_SetRect);
  if (r != XIKIT_OK) return r;
  return XI_HOOK(host, Menu_DrawLayers, my_Draw, prev_Draw);
}
