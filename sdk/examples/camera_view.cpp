// camera_view.cpp -- an example mod: the camera's field of view and far clip distance.
// Build:  sdk/build_mod.sh camera_view.dll sdk/examples/camera_view.cpp
//
// Where: Camera_BuildPerspectiveFov (0x10015490, gate-verified source in tree/src/WinMain.cpp). It builds the
// projection at camera +0x154 (and a copy at +0x1D4) with D3DXMatrixPerspectiveFovLH: vertical field of view
// 2 * atan(192 / [+0x2F4]), aspect 1 / ([+0x2F0] * [+0x2E8]), near [+0x2DC], far [+0x2E0]. Its callers are
// Camera_BuildProjection, Camera_SetField2E4 and 0x10015430.
//
// Other code reads the same two fields: ZoneMap_SetOverlayProjection (tree/src/CTsZoneMap.cpp) builds the zone map's
// own projection from +0x2F4 and +0x2E0, the effects' fog (tree/src/ElemFog.cpp) uses both, and Camera_GetField2F4 /
// Camera_GetFloat2E0 hand them out. So this mod does not edit the matrix: it writes the fields themselves before the
// game's code builds it, and every reader sees the same view. It keeps the game's own values: when a field holds
// something other than what the mod last wrote, the game wrote it, and that is the new base.
//
// fov_deg: 0 the game's; else the vertical field of view in degrees ([+0x2F4] = 192 / tan(fov / 2)).
// far_percent: 100 the game's; else the far clip distance in percent of the game's. Whether the game draws more at a
// larger far distance is not known: other distance limits (the zone's draw lists, the actors' and effects' own
// cut-offs) were not read for this; what the far plane clips is all this changes.
//
// Tested offline (kit/xikit/test, mode cammod): the game's own Camera_BuildPerspectiveFov on a camera object, the
// matrix read back. Not yet run in the game.
#include "xikit_sdk.hpp"
XIKIT_MOD_GLOBALS

static const XikitHost *g_host;
static float g_game_focal, g_game_far, g_set_focal, g_set_far;   // the game's values, and what the mod last wrote
static void *g_cam;

static float &field(void *cam, int off) { return *reinterpret_cast<float *>(reinterpret_cast<char *>(cam) + off); }
static void apply(void *cam) {
  float &focal = field(cam, 0x2F4), &far_ = field(cam, 0x2E0);
  if (cam != g_cam || focal != g_set_focal) g_game_focal = focal;     // the game wrote it (or a new camera object)
  if (cam != g_cam || far_ != g_set_far) g_game_far = far_;
  g_cam = cam;
  int fov = g_host->setting_int("fov_deg", 0), fp = g_host->setting_int("far_percent", 100);
  focal = fov > 0 ? (float)(192.0 / __builtin_tan(fov * 3.14159265358979323846 / 360.0)) : g_game_focal;
  far_ = fp != 100 ? g_game_far * (float)fp / 100.0f : g_game_far;
  g_set_focal = focal; g_set_far = far_;
}

static xikit::fn<decltype(&Camera_BuildPerspectiveFov)> prev_Build;
static void __thiscall my_Build(void *cam) { if (cam) apply(cam); prev_Build(cam); }

extern "C" __declspec(dllexport) int xikit_mod_init(const XikitHost *host) {
  g_host = host;
  host->declare_int("fov_deg", 0, 0, 120, "0: the game's field of view; else the vertical field of view in degrees");
  host->declare_int("far_percent", 100, 25, 400, "the far clip distance in percent of the game's (100: the game's)");
  return XI_HOOK(host, Camera_BuildPerspectiveFov, my_Build, prev_Build);
}
