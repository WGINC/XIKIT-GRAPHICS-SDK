// imgui_panel_ui.cpp -- imgui_panel's window (Dear ImGui calls only; no game headers here)
#include <stdio.h>
#include <string.h>
#include "../imgui/imgui.h"
#include "imgui_panel_ui.h"

IpAction ip_draw(const IpView *v) {
  IpAction a; memset(&a, 0, sizeof a);
  static char line[128] = "/wave";
  ImGui::SetNextWindowPos(ImVec2(40, 40), ImGuiCond_FirstUseEver);
  ImGui::SetNextWindowSize(ImVec2(320, 0), ImGuiCond_FirstUseEver);
  bool open = true;
  if (ImGui::Begin("xiimgui panel", &open)) {
    ImGui::Text("Target: %s", v->target[0] ? v->target : "(none)");
    ImGui::Text("Interface units: %.3f x %.3f", v->unit_x, v->unit_y);
    if (v->rt_ok) ImGui::Text("Render target: %.0f x %.0f", v->rt_w, v->rt_h); else ImGui::TextUnformatted("Render target: (not known yet)");
    if (v->have_cursor) ImGui::Text("Cursor: %d, %d", v->cursor_x, v->cursor_y); else ImGui::TextUnformatted("Cursor: (none)");
    ImGui::Text("Chat line text: \"%s\"", v->chat);
    ImGui::Separator();
    ImGui::InputText("line", line, sizeof line);
    if (ImGui::Button("Run it")) snprintf(a.run_line, sizeof a.run_line, "%s", line);
  }
  ImGui::End();
  if (!open) a.close = 1;
  return a;
}
