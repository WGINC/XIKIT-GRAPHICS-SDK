// xikit_ui.hpp -- the game services the mods kept finding for themselves, in one place: the game's window, its screen
// units, whether the interface is hidden, whether the chat line takes typed keys, the cursor, running a command line,
// and drawing and measuring text in the game's own font. Header only; include it after xikit_sdk.hpp.
//
// Every fact is from the game's code, build 6A995428, with the function it was read from. The addresses go through
// XI_GAME / xikit::game, so build translation applies (6AC37846 and 6AE818B4: the functions below are matched by the
// kit's build maps; hotbar and click_target, which first read them, are tested on 6A995428 and 6AE818B4).
// Call these on the render thread (xikit_mod_frame, or a hook of the game's drawing), as the game does.
#pragma once
#include <string.h>
#include "xikit_sdk.hpp"

namespace xiui {

// The game's main window: the application object [0x103D3C64] +0x18 (the window procedure 0x100016C0's owner;
// hotbar.cpp). NULL before the game has made it.
inline void *window() {
  uint8_t *app = *xikit::game<uint8_t *>(0x103D3C64u);
  return app ? *reinterpret_cast<void **>(app + 0x18) : nullptr;
}

// The interface's units. The game lays out its menus in 640x480 units and scales them by the screen rectangle's
// right/bottom over 640 and 480 (the menu manager's +0x80/+0x82 at [0x106218B8]; TargetMenu_GetScaledPos80).
// unit_x() * 640 is the drawn width in pixels. 1 when the rectangle is not set yet.
inline float unit_x() { short *r = xikit::game<short>(0x106218B8u); return r[0] > 0 ? r[0] / 640.0f : 1.0f; }
inline float unit_y() { short *r = xikit::game<short>(0x106218B8u); return r[1] > 0 ? r[1] / 480.0f : 1.0f; }

// The size of the render target being drawn, in pixels: CDx::GetRenderTargetTop (0x10009E00, this = g_pCDx
// [0x1045666C]) returns the record whose +8 and +12 are its width and height (click_target.cpp, which maps the game's
// nameplate glyphs back to the screen with it). False before the device wrapper exists.
inline bool render_target_size(float *w, float *h) {
  typedef const uint8_t *(__thiscall *RtTopFn)(void *);
  void *cdx = *xikit::game<void *>(0x1045666Cu);
  if (!cdx) return false;
  const uint8_t *rt = reinterpret_cast<RtTopFn>(XI_GAME(0x10009E00u))(cdx);
  if (!rt) return false;
  *w = (float)*reinterpret_cast<const uint32_t *>(rt + 8); *h = (float)*reinterpret_cast<const uint32_t *>(rt + 12);
  return *w > 0 && *h > 0;
}

// The interface hidden by the player: Menu_DrawLayers draws a window only while Menu_IsStateB4Eq1 is false (the menu
// manager [0x10621838]'s byte +0xB4 is not 1) or the window has flag 0x40.
inline bool interface_hidden() { return *(xikit::game<uint8_t>(0x10621838u) + 0xB4) == 1; }

// The chat line's text. [0x10578490] is the chat line's buffer: Input_HandleChar (tree/src/InputDevices.cpp) writes
// each typed character into its text at +0x14 (at the cursor, +0x114) and on Enter runs that text through
// Command_RunLine (InputDevices.cpp:304). NULL before the buffer exists.
// Not known: whether the chat line is open. (An earlier SDK offered chat_takes_keys(), [0x10578490] and [0x1062193C]
// both non-zero; read again on 24 Nov, both are objects that exist the whole time once logged in: the buffer above and
// a menu window. The owner's game showed it true throughout. It was removed.)
inline const char *chat_line_text() {
  uint8_t *b = *xikit::game<uint8_t *>(0x10578490u);
  return b ? reinterpret_cast<const char *>(b + 0x14) : nullptr;
}
// A fingerprint of the chat line's text and cursor: a key press that typed a character into the chat line changes it.
// A mod that acts on a key takes the stamp when the key goes down, waits a few frames, and acts only if the stamp is
// unchanged (sdk/examples/hotbar.cpp). 0 before the buffer exists.
inline uint32_t chat_line_stamp() {
  uint8_t *b = *xikit::game<uint8_t *>(0x10578490u);
  if (!b) return 0;
  uint32_t h = 2166136261u;                                        // FNV-1a over the 256 bytes of text and the cursor
  for (int i = 0x14; i <= 0x114; i++) { h ^= b[i]; h *= 16777619u; }
  return h ? h : 1;
}

// The game's cursor, g_pCursor ([0x104E1D4C]) +4 and +8, in pixels of the drawn interface (the same units as
// unit_x() * 640). False before the cursor object exists.
inline bool cursor(int *x, int *y) {
  uint8_t *c = *xikit::game<uint8_t *>(0x104E1D4Cu);
  if (!c) return false;
  *x = *reinterpret_cast<int *>(c + 4); *y = *reinterpret_cast<int *>(c + 8);
  return true;
}

// Run one line through the game's command line, as typing it and pressing Enter does: Command_RunLine (0x10080DC0,
// cdecl: line, mode), which the chat line's Enter calls with mode 0 (Input_HandleChar). The game's code may write
// into the line, so it is copied first; at most 199 characters. Returns what Command_RunLine returns.
inline int run_line(const char *text) {
  typedef int (__cdecl *RunLineFn)(char *, int);
  char line[200]; size_t n = strlen(text); if (n > sizeof line - 1) n = sizeof line - 1;
  memcpy(line, text, n); line[n] = 0;
  return reinterpret_cast<RunLineFn>(XI_GAME(0x10080DC0u))(line, 0);
}

// Text in the game's font: FontGlyphs::FontGlyphs_DrawString (0x1011C080, this = [0x104E1B90]) with flags 0x44, as
// the game's wrapper 0x10129F00 calls it (125 calls). Colours as Menu_DrawWindowItems: 0x80808080 normal,
// 0x80805020 focused (0x80 is full intensity: the game's text stage is MODULATE2X). x, y in pixels; scale 1 is the
// game's size. It sets ALPHAOP and the blend states but not COLOROP: a mod that changed the texture stages puts the
// game's states back first (hotbar.cpp, HISTORY 81). Draws nothing before the font object exists.
inline void text(float x, float y, const char *s, unsigned color = 0x80808080u, float scale = 1.0f) {
  typedef int (__thiscall *DrawStrFn)(void *, int, int, int, int, int, int, int, int);
  void *fg = *xikit::game<void *>(0x104E1B90u);
  if (!fg || !s || !s[0]) return;
  union { float f; int i; } u; u.f = scale;
  reinterpret_cast<DrawStrFn>(XI_GAME(0x1011C080u))(fg, (int)(x + 0.5f), (int)(y + 0.5f), (int)(uintptr_t)s, 0, (int)color, 0x44, u.i, u.i);
}
// The width of s in pixels at the game's size: Font_MeasureText (0x1011CF70, cdecl: text, 0). Before the font object
// exists, 8 pixels a character (an estimate, said as one).
inline float text_width(const char *s) {
  typedef int (__cdecl *MeasureFn)(const char *, unsigned);
  if (!*xikit::game<void *>(0x104E1B90u)) return 8.0f * (float)strlen(s);
  int w = reinterpret_cast<MeasureFn>(XI_GAME(0x1011CF70u))(s, 0);
  return w > 0 ? (float)w : 0.0f;
}

}  // namespace xiui
