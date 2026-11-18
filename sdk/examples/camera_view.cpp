// camera_view.cpp -- an example mod: the camera's field of view, far clip distance and the draw distance.
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
// far_percent: 100 the game's; else the far clip distance in percent of the game's. The far plane only clips what
// is drawn: the zone and the actors have a distance limit of their own (draw_percent).
//
// draw_percent: 100 the game's; else XiZone::ComputeFogDistance (0x1018B8F0, tree/src/XiZone.cpp) scaled. That
// function gives the zone's draw distance (its disassembly, 0x1018B8F0..0x1018B95B): the zone's value (100 without a
// zone record, zone +0x1C 0); when the zone's +0x1D0 is above 0, that value times the time-of-day factor
// (Env_FogDistanceFactor, 0x101892B0) but not less than +0x1D0; when +0x1D0 is 0 or below, the value alone. The game's
// code uses it:
// - XiZone_Draw (0x1017BF35) keeps it at zone +0x39420 and its square at +0x39424. ZoneMap_DrawMeshById,
//   XiZone_DrawElement and 0x1017DE20 draw a mesh only when its squared distance from the eye is below that square
//   (or below a smaller per-mesh value, Env_FogDistanceFactor times mesh +0xD0). It is also the far distance of the
//   zone's own culling frustum (ZoneMap_BuildPerspective at 0x1017BFB4, kept at zone +0x38FDC and read by
//   0x10181BB0 before each mesh draw);
// - CXiSkeletonActor_OnMove (0x100C7D47) and 0x100AC5A0 compare it with the actor's depth in the view. Beyond it,
//   they set bit 1 of the actor's flags word +0xB2. CXiActorDraw::UpdateDrawList (0x10082DC7) calls the actor's slot
//   +0x288 only while that word is 0. 0x100496F0 also compares it with a distance (what that one does is not read).
// The mod scales the game's result (the floor at +0x1D0 included). Not known: what +0x1D0 and the zone's value are
// set from, and whether models stay loaded at that distance. The fog colour and distances are a separate
// computation (Env_ComputeFog, sdk/examples/world_light.cpp). So with draw_percent above 100, things past the game's
// distance draw inside the fog's end unless fog_distance is raised as well; the far plane (far_percent) must cover them.
//
// The view these limits use. The zone's frustum and the actors' depth come from the view last set on the device
// (CDx::GetTransformCached(2), the copy CDx::SetTransform keeps at +0x97C: 0x1017BEFC, 0x100C7C3C).
// Camera_ApplyViewProjection sets it at the end of Frame_Render (0x10012E1E), before XiZone::DrawScene
// (0x10011C97) the next frame. So the free camera of photo_mode, built there, is the view the game culls with.
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

static xikit::fn<decltype(&XiZone::ComputeFogDistance)> prev_Dist;
static long double __thiscall my_Dist(void *zone, undefined4 kind) {
  long double d = prev_Dist(zone, kind);
  int p = g_host->setting_int("draw_percent", 100);
  return p != 100 ? d * p / 100.0L : d;
}

static xikit::fn<decltype(&Camera_BuildPerspectiveFov)> prev_Build;
static void __thiscall my_Build(void *cam) { if (cam) apply(cam); prev_Build(cam); }

extern "C" __declspec(dllexport) int xikit_mod_init(const XikitHost *host) {
  g_host = host;
  host->declare_int("fov_deg", 0, 0, 120, "0: the game's field of view; else the vertical field of view in degrees");
  host->declare_int("far_percent", 100, 25, 400, "the far clip distance in percent of the game's (100: the game's)");
  host->declare_int("draw_percent", 100, 25, 400, "the zone's and actors' draw distance in percent of the game's (100: the game's)");
  int r = XI_HOOK(host, Camera_BuildPerspectiveFov, my_Build, prev_Build);
  r |= XI_HOOK(host, XiZone::ComputeFogDistance, my_Dist, prev_Dist);
  return r;
}
