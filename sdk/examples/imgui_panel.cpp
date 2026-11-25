// imgui_panel.cpp -- Dear ImGui in the game (sdk/xiimgui): a small window over the interface showing what the SDK's
// readers say (the target's name, the interface units, the cursor), with a setting and a button. The ImGui calls are
// in imgui_panel_ui.cpp: a file that includes "imgui.h" cannot include the game's headers too. Build:
//   sdk/build_mod.sh imgui_panel.dll sdk/examples/imgui_panel.cpp sdk/examples/imgui_panel_ui.cpp
//     sdk/xiimgui/xiimgui_game.cpp sdk/xiimgui/xiimgui_d3d8.cpp sdk/imgui/imgui.cpp sdk/imgui/imgui_draw.cpp \
//     sdk/imgui/imgui_tables.cpp sdk/imgui/imgui_widgets.cpp
// Settings ([imgui_panel] in xikit_mods.ini): ip_show. Compiled; not run in the game.
#include "xikit_sdk.hpp"
#include "xikit_ui.hpp"
#include "xikit_state.hpp"
#include "../xiimgui/xiimgui_game.h"
#include "imgui_panel_ui.h"
XIKIT_MOD_GLOBALS
XIKIT_MOD_INFO("imgui_panel", "1", 4, "a Dear ImGui window over the interface (the xiimgui example)")

static const XikitHost *g_host;
static IpView g_view;

static void fill_view() {                      // the game's side, read here and handed to the ImGui file as plain data
  xistate::actor_name(xistate::target_actor(), g_view.target, sizeof g_view.target);
  g_view.unit_x = xiui::unit_x(); g_view.unit_y = xiui::unit_y();
  g_view.have_cursor = xiui::cursor(&g_view.cursor_x, &g_view.cursor_y);
  g_view.rt_ok = xiui::render_target_size(&g_view.rt_w, &g_view.rt_h);
  const char *ct = xiui::chat_line_text(); size_t k = 0;
  if (ct) while (ct[k] && k < sizeof g_view.chat - 1) { g_view.chat[k] = ct[k]; k++; }
  g_view.chat[k] = 0;
}
static void draw() {
  if (!g_host->setting_int("ip_show", 1)) return;
  fill_view();
  IpAction a = ip_draw(&g_view);
  if (a.run_line[0]) xiui::run_line(a.run_line);
  if (a.close) g_host->set_int("ip_show", 0);
}

extern "C" __declspec(dllexport) int xikit_mod_init(const XikitHost *host) {
  g_host = host;
  host->declare_int("ip_show", 1, 0, 1, "1: show the panel");
  return xiimgui_game_install(host, draw, 1);
}
extern "C" __declspec(dllexport) void xikit_mod_unload(void) { xiimgui_game_unload(); }
// for the offline test (kit/xikit/test, mode igmod)
extern "C" __declspec(dllexport) long ip_test_frames(void) { return xiimgui_game_frames(); }
extern "C" __declspec(dllexport) int ip_test_had_mouse(void) { return xiimgui_game_had_mouse(); }
extern "C" __declspec(dllexport) void ip_test_force_focus(int on) { xiimgui_game_force_focus(on); }
extern "C" __declspec(dllexport) void ip_test_clicks(long *kept, long *passed) { xiimgui_game_clicks(kept, passed); }
