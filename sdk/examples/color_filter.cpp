// color_filter.cpp -- an example mod for colour-blind players: a colour correction (or a simulation, for checking) of
// the whole picture, the interface included. Build:
//   sdk/build_mod.sh color_filter.dll sdk/examples/color_filter.cpp sdk/examples/color_filter_core.cpp
//
// Needs d3d8on11 (its shader passes, sdk/include/xikit_render.h); with any other d3d8.dll it logs that and does nothing.
// Each frame, after the game has drawn it (xikit_mod_frame, before Present), the back buffer is copied into a texture
// (CopyRects), a shader pass multiplies every pixel's colour by a 3x3 matrix into a second texture, and that is drawn
// back over the whole frame. Nothing of the game's is read or changed.
//
// The matrices (color_filter_core.cpp): the dichromacy simulation of Machado, Oliveira and Fernandes (2009, severity
// 1.0) for protanopia, deuteranopia and tritanopia, and the correction that shifts what the simulation loses into the
// channels that remain (the "daltonize" method). These are a standard technique, not something taken from the game;
// whether they suit a given player is the player's to judge, which is why the strength is a setting.
//
// Settings: cb_mode (0 off, 1 protanopia, 2 deuteranopia, 3 tritanopia), cb_strength (percent), cb_simulate (1: show
// the simulation instead of the correction).
//
// Tested offline (kit/xikit/test, mode cfmod, with kit/d3d8on11's d3d8.dll on Wine): a frame cleared to pure red, the
// filtered texture read back (cb_check=1) against the published matrix; the draw back over the frame is the same
// full-screen quad as photo_mode's cover, whose test reads it back. Not yet run in the game.
#include "xikit_sdk.hpp"
#include "xikit_render.h"
#include "color_filter_core.h"
XIKIT_MOD_GLOBALS

static const XikitHost *g_host;
static XikitRender g_r;
static unsigned g_shader;
static float g_m[12];
static const char k_hlsl[] =
  "Texture2D src : register(t0); SamplerState smp : register(s0); cbuffer C : register(b0) { float4 c[64]; };\n"
  "float4 ps(float4 pos : SV_Position, float2 uv : TEXCOORD0) : SV_Target {\n"
  "  float3 v = src.Sample(smp, uv).rgb;\n"
  "  return float4(saturate(float3(dot(c[0].xyz, v), dot(c[1].xyz, v), dot(c[2].xyz, v))), 1);\n"
  "}\n";
static void log_line(const char *s) { g_host->log("%s", s); }
static void settings() {
  cf_matrix(g_host->setting_int("cb_mode", 0), g_host->setting_int("cb_strength", 100), g_host->setting_int("cb_simulate", 0), g_m);
}
static int __stdcall pass(unsigned s, void *src, void *dst, const float *c, unsigned n) {
  return g_r.Pass(s, (IDirect3DTexture8 *)src, (IDirect3DSurface8 *)dst, c, n);
}
extern "C" __declspec(dllexport) void xikit_mod_settings(void) { settings(); }
extern "C" __declspec(dllexport) void xikit_mod_frame(void *device) {
  if (g_shader && device && g_host->setting_int("cb_mode", 0) && cf_frame(device, pass, g_shader, g_m, log_line) && g_host->setting_int("cb_check", 0)) {
    static unsigned n; long v = cf_check(device);
    if (n++ < 3) g_host->log("color_filter: check: the filtered frame's centre is %06lx", v);
  }
}
extern "C" __declspec(dllexport) void xikit_mod_unload(void) { cf_release(); }
extern "C" __declspec(dllexport) int xikit_mod_init(const XikitHost *host) {
  g_host = host;
  host->declare_int("cb_mode", 0, 0, 3, "0 off, 1 protanopia, 2 deuteranopia, 3 tritanopia");
  host->declare_int("cb_strength", 100, 0, 100, "percent of the correction (or of the simulation)");
  host->declare_int("cb_check", 0, 0, 1, "1: log the filtered frame's centre pixel (the first three frames; for checking)");
  host->declare_int("cb_simulate", 0, 0, 1, "1: show what the chosen type sees (for checking), instead of correcting");
  settings();
  if (!xikit_render_load(&g_r)) { host->log("color_filter: the d3d8.dll in use has no shader passes (not d3d8on11): nothing done"); return 0; }
  g_shader = g_r.PassShader(k_hlsl, (unsigned)strlen(k_hlsl));
  if (!g_shader) host->log("color_filter: the shader did not compile (d3d8on11.log says why): nothing done");
  return 0;
}
