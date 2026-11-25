// status_text.cpp -- the tutorial's mod (sdk/TUTORIAL.md): the local time, drawn over the game's interface in the
// game's own font, hidden with the interface, the chat command /stext to show or hide it. Build:
//   sdk/build_mod.sh status_text.dll sdk/examples/status_text.cpp sdk/examples/status_text_core.cpp
//
// Where it draws: after Menu_DrawLayers (0x1015F6A0), the game's drawing of its interface windows, as hotbar.cpp does,
// so the text is over the windows and drawn with the device in the game's state for its menus. It draws no quads of
// its own, so it leaves the texture stages as the game's text expects them (xikit_ui.hpp, xiui::text).
// Settings ([status_text] in xikit_mods.ini): st_show, st_x, st_y (640x480 interface units; negative: from the right
// or bottom), st_seconds. Compiled; not run in the game.
// The command: /stext (switch), /stext show, /stext hide, /stext seconds (switch the seconds). The word is not one of
// the game's: the game's own commands are "/word" strings in FFXiMain.dll, and "/stext" is not among them.
#include "xikit_sdk.hpp"
#include "xikit_ui.hpp"
#include "xikit_cmd.hpp"
#include "status_text_core.h"
XIKIT_MOD_GLOBALS
XIKIT_MOD_INFO("status_text", "1", 4, "the local time over the interface (the SDK tutorial)")

static const XikitHost *g_host;
static void command(const char *args) {           // "/stext ..." typed in the chat line (xikit_cmd.hpp)
  if (!strcmp(args, "show")) g_host->set_int("st_show", 1);
  else if (!strcmp(args, "hide")) g_host->set_int("st_show", 0);
  else if (!strcmp(args, "seconds")) g_host->set_int("st_seconds", !g_host->setting_int("st_seconds", 0));
  else g_host->set_int("st_show", !g_host->setting_int("st_show", 1));
}

static xikit::fn<decltype(&Menu_DrawLayers)> prev_DrawLayers;
static void __thiscall my_DrawLayers(void *menus) {
  prev_DrawLayers(menus);                          // the game's windows first
  if (!g_host->setting_int("st_show", 1) || xiui::interface_hidden()) return;
  char s[32]; st_clock(s, sizeof s, g_host->setting_int("st_seconds", 0));
  float ux = xiui::unit_x(), uy = xiui::unit_y(), w = xiui::text_width(s);
  int x = g_host->setting_int("st_x", -8), y = g_host->setting_int("st_y", 4);
  float px = x < 0 ? (640 + x) * ux - w : x * ux, py = y < 0 ? (480 + y) * uy - 16 : y * uy;
  xiui::text(px, py, s);
}

extern "C" __declspec(dllexport) int xikit_mod_init(const XikitHost *host) {
  g_host = host;
  host->declare_int("st_show", 1, 0, 1, "1: show the time (/stext switches it)");
  host->declare_int("st_x", -8, -640, 640, "where, across, in 640-wide interface units; negative: from the right edge");
  host->declare_int("st_y", 4, -480, 480, "where, down, in 480-high units; negative: from the bottom");
  host->declare_int("st_seconds", 0, 0, 1, "1: with seconds");
  xicmd::add("stext", command);
  if (xicmd::install(host) != XIKIT_OK) host->log("status_text: Command_RunLine not hooked: no /stext (st_show in xikit_mods.ini still works)");
  return XI_HOOK(host, Menu_DrawLayers, my_DrawLayers, prev_DrawLayers);
}
