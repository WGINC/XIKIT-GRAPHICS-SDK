// imgui_panel_ui.h -- what imgui_panel.cpp hands its ImGui file (plain data both sides can include)
#pragma once
struct IpView { char target[64]; float unit_x, unit_y; int have_cursor, cursor_x, cursor_y; int rt_ok; float rt_w, rt_h; char chat[64]; };   // chat: the chat line's text (xiui::chat_line_text), "" when none
struct IpAction { char run_line[128]; int close; };
IpAction ip_draw(const IpView *v);
