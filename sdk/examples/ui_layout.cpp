// ui_layout.cpp -- an example mod: move the game's interface windows, each by name or all together.
// Build:  sdk/build_mod.sh ui_layout.dll sdk/examples/ui_layout.cpp sdk/examples/ui_layout_core.cpp
//
// What the game's code shows (tree/src/TargetMenu.cpp, tree/src/NetCellFont.cpp), with the PS2 build's names for the
// same fields (DancingMad ps2_types.json: CTkMenuMng, CTkMenuCtrlData, CTkMenuData, CTkNode):
// - the menu manager g_menuMng (0x10621838) keeps its windows in a list at +0 (CTkMenuMng::m_DrawDatas); Menu_DrawLayers
//   (0x1015F6A0) walks it with NetCellFont_GetHead and Menu_NextVisibleItem and draws each window by its layer +0x60
//   (m_Priority) with Menu_DrawWindowItems;
// - a window's rectangle is the four shorts at +0x3A (left, top, right, bottom: m_WinRect): Menu_DrawWindowItems draws
//   from them, and the game's hit test (NetCellFont_HitTest 0x10118C10, called by Menu_TrackCursor and the menus)
//   compares the cursor with the same four. So a window moved there is drawn and clicked where it is moved to;
// - its name is the 16 characters at (window +4) +0x46 (CTkMenuData::m_ID): the game looks windows up by it with
//   strncmp(name, [window + 4] + 0x46, 16) (0x10160xxx; tree/src/TargetMenu.cpp).
//
// This mod hooks Menu_DrawLayers. Before the game's code runs, each visible window is moved by its offset: ui_dx and
// ui_dy (settings) for all, plus a line of <kit folder>\ui_layout.txt for that window: "<name> <dx> <dy>", the name
// being the window's 16 characters with the spaces left out (ui_list=1 logs each window's name and rectangle once, to
// find them). The game's own rectangle is kept as the base: when a window's rectangle holds something other than what
// the mod last wrote, the game moved or rebuilt it, and the offset applies to that.
// Units are the interface's own (the 512x448 layout the menu resolution scales). Not known: whether some window
// clamps itself to the screen or reads its position from somewhere else as well (its parts are drawn relative to the
// rectangle, as far as Menu_DrawWindowItems shows).
//
// Tested offline (kit/xikit/test, mode uimod): the game's own Menu_DrawLayers over a menu list built in memory: the
// windows are moved by name and by the global offset, the game's own hit test finds a point in the moved rectangle,
// and a rectangle the game changes becomes the new base. Not yet run in the game.
#include "xikit_sdk.hpp"
XIKIT_MOD_GLOBALS

extern "C" int ul_read(const char *dir, char (*keys)[17], short *dx, short *dy, int max);   // ui_layout_core.cpp

static const XikitHost *g_host;
struct Rule { char key[17]; short dx, dy; };
static Rule g_rules[128]; static int g_nrules;
struct Seen { void *w; short rect[4]; bool listed; };
static Seen g_seen[256]; static int g_nseen;

static void key_of(const char *name16, char out[17]) {
  int k = 0; for (int i = 0; i < 16 && name16[i]; i++) if (name16[i] != ' ') { char c = name16[i]; out[k++] = c >= 'A' && c <= 'Z' ? c + 32 : c; }
  out[k] = 0;
}
static void read_rules() {
  static char k[128][17]; static short dx[128], dy[128];
  g_nrules = ul_read(g_host->dir ? g_host->dir : ".", k, dx, dy, 128);
  for (int i = 0; i < g_nrules; i++) { memcpy(g_rules[i].key, k[i], 17); g_rules[i].dx = dx[i]; g_rules[i].dy = dy[i]; }
  g_host->log("ui_layout: %d windows in ui_layout.txt", g_nrules);
}
static Seen *seen(void *w) {
  for (int i = 0; i < g_nseen; i++) if (g_seen[i].w == w) return &g_seen[i];
  if (g_nseen == 256) g_nseen = 0;                       // (forget the oldest set: the bases are found again)
  Seen *s = &g_seen[g_nseen++]; s->w = w; s->rect[0] = s->rect[1] = s->rect[2] = s->rect[3] = (short)0x8000; s->listed = false; return s;
}
static short g_base[256][4];

static void move_windows() {
  int gdx = g_host->setting_int("ui_dx", 0), gdy = g_host->setting_int("ui_dy", 0), list = g_host->setting_int("ui_list", 0);
  int pos = (int)orig::NetCellFont_GetHead(&g_menuMng_as_v0);
  while (pos) {
    void *w = (void *)(uintptr_t)(uint32_t)orig::Menu_NextVisibleItem(&pos);
    if (!w) continue;
    char *md = *reinterpret_cast<char **>(reinterpret_cast<char *>(w) + 4);
    char key[17] = ""; if (md) key_of(md + 0x46, key);
    short *rc = reinterpret_cast<short *>(reinterpret_cast<char *>(w) + 0x3A);
    Seen *s = seen(w); short *base = g_base[s - g_seen];
    if (rc[0] != s->rect[0] || rc[1] != s->rect[1] || rc[2] != s->rect[2] || rc[3] != s->rect[3]) for (int i = 0; i < 4; i++) base[i] = rc[i];   // the game's
    int dx = gdx, dy = gdy;
    for (int i = 0; i < g_nrules; i++) if (!strcmp(g_rules[i].key, key)) { dx += g_rules[i].dx; dy += g_rules[i].dy; break; }
    rc[0] = (short)(base[0] + dx); rc[2] = (short)(base[2] + dx); rc[1] = (short)(base[1] + dy); rc[3] = (short)(base[3] + dy);
    for (int i = 0; i < 4; i++) s->rect[i] = rc[i];
    if (list && !s->listed) { s->listed = true; g_host->log("ui_layout: window %s at %d,%d .. %d,%d (the game's)", key, base[0], base[1], base[2], base[3]); }
  }
}

static xikit::fn<decltype(&Menu_DrawLayers)> prev_Draw;
static void __thiscall my_Draw(void *mng) { move_windows(); prev_Draw(mng); }

extern "C" __declspec(dllexport) void xikit_mod_settings(void) { read_rules(); }
extern "C" __declspec(dllexport) int xikit_mod_init(const XikitHost *host) {
  g_host = host;
  host->declare_int("ui_dx", 0, -640, 640, "move every interface window right (interface units)");
  host->declare_int("ui_dy", 0, -480, 480, "move every interface window down (interface units)");
  host->declare_int("ui_list", 0, 0, 1, "1: log each window's name and rectangle once (the names for ui_layout.txt)");
  read_rules();
  return XI_HOOK(host, Menu_DrawLayers, my_Draw, prev_Draw);
}
