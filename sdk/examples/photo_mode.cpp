// photo_mode.cpp -- an example mod: a photo mode. A free camera that orbits the game's own, the interface hidden,
// and a picture of the world without the interface. Build:
//   sdk/build_mod.sh photo_mode.dll sdk/examples/photo_mode.cpp sdk/examples/photo_mode_core.cpp
//
// The camera. Camera_ApplyViewProjection (0x10015510, Frame_Render) asks the camera controller whether it moved
// (Camera_DiffersFromSaved, 0x10021AE0: its eye at +0x44 and look-at point at +0x50 against the copies at +0x60 and
// +0x6C), and if so Camera_SnapshotState (0x10021B70, tree/src/ActorCamera.cpp) builds the view at controller +4 with
// Camera_BuildLookAtView (eye +0x44, look-at +0x50, roll +0x5C), saves the copies, and the view goes to CDx::SetTransform
// (VIEW); MoDX_Update and Camera_SetupMatrices then cache it for the billboards and the effects. This mod hooks
// Camera_SnapshotState: while photo mode is on it puts its own eye in +0x44 for the game's build and the game's eye
// back afterwards. The saved copy then holds the mod's eye, so the controller "differs" every frame and the view is
// rebuilt every frame while photo mode is on, and once more when it is turned off.
// The mod's eye: the game's eye orbited about the game's look-at point (photo_yaw, photo_pitch in degrees), its
// distance scaled (photo_dist percent), and raised along the game's Y axis (photo_raise, hundredths of a unit; which
// sign is up was not checked). What the game culls with: the zone's culling frustum and the actors' depth test are
// built from the view last set on the device (CDx::GetTransformCached(2): 0x1017BEFC in XiZone_Draw, 0x100C7C3C in
// CXiSkeletonActor_OnMove), and Camera_ApplyViewProjection sets it at the end of Frame_Render (0x10012E1E), before
// the next frame's XiZone::DrawScene (0x10011C97). So the zone and the actors are culled with this mod's eye, not the
// game's (sdk/examples/camera_view.cpp, draw_percent, has the distances). Not read: whether any other drawing
// (effects, the sky) culls with a camera copy of its own. The camera's collision with walls is the game's eye's only.
//
// The picture and the interface. CDx::CompositeSceneToBackBuffer (0x1000C0B0) is handed the world as it will be shown,
// before the interface (sdk/examples/scene_tint.cpp says how that is known: the texture at its first argument + 4).
// photo_shot=1 (or Ctrl+Shift+P with photo_keys=1) writes that texture to <kit folder>\screenshots\photo_<time>.bmp
// and sets photo_shot back to 0. photo_hide_ui=1 draws the same texture over the whole frame after the game has
// drawn it (xikit_mod_frame, before Present), so the interface is covered; the game's interface code runs as usual.
//
// Keys (photo_keys=1; Ctrl+Shift held; the game sees these keys too): arrows turn and tilt, Page Up/Down nearer and
// farther, Home/End up and down, O photo mode on/off, H the interface hidden or shown, P a picture.
//
// Tested offline (kit/xikit/test, mode phomod): the game's own Camera_SnapshotState on a controller: the view it
// builds has the mod's eye, the game's eye is put back; a picture of a texture read back from the file; the cover
// drawn over a render target and read back. Not yet run in the game.
#include "xikit_sdk.hpp"
#include "photo_mode_core.h"
XIKIT_MOD_GLOBALS

static const XikitHost *g_host;
static float g_kyaw, g_kpitch, g_kdist, g_kraise;            // what the keys added
static int g_kon = -1, g_khide = -1;                         // the keys' toggles (-1: the settings decide)
static IDirect3DTexture8 *g_world;                           // the last world texture (a reference held)
static void log_line(const char *s) { g_host->log("%s", s); }
static bool photo_on() { return g_kon >= 0 ? g_kon : g_host->setting_int("photo", 0); }
static bool hide_on() { return g_khide >= 0 ? g_khide : g_host->setting_int("photo_hide_ui", 0); }

static xikit::fn<decltype(&Camera_SnapshotState)> prev_Snap;
static int __thiscall my_Snap(void *ctl) {
  if (!ctl || !photo_on()) return prev_Snap(ctl);
  float *eye = reinterpret_cast<float *>(reinterpret_cast<char *>(ctl) + 0x44), *at = reinterpret_cast<float *>(reinterpret_cast<char *>(ctl) + 0x50);
  float game[3] = { eye[0], eye[1], eye[2] }, mine[3];
  ph_orbit(game, at, g_host->setting_int("photo_yaw", 0) + g_kyaw, g_host->setting_int("photo_pitch", 0) + g_kpitch,
           g_host->setting_int("photo_dist", 100) + g_kdist, g_host->setting_int("photo_raise", 0) / 100.0f + g_kraise, mine);
  for (int i = 0; i < 3; i++) eye[i] = mine[i];
  int r = prev_Snap(ctl);                                    // the game's build of the view, from the mod's eye
  for (int i = 0; i < 3; i++) eye[i] = game[i];              // (the copy at +0x60 keeps the mod's: rebuilt next frame)
  return r;
}

static xikit::fn<decltype(&CDx::CompositeSceneToBackBuffer)> prev_Comp;
static int __thiscall my_Comp(CDx *self, int a1, int a2, int a3, int a4) {
  IDirect3DTexture8 *scene = a1 ? *reinterpret_cast<IDirect3DTexture8 **>(a1 + 4) : nullptr;
  IDirect3DDevice8 *dev = *reinterpret_cast<IDirect3DDevice8 **>(reinterpret_cast<char *>(self) + 0xC);
  if (scene && dev && scene->GetType() == D3DRTYPE_TEXTURE) {
    if (g_world != scene) { scene->AddRef(); if (g_world) g_world->Release(); g_world = scene; }
    if (g_host->setting_int("photo_shot", 0)) { ph_shot(dev, scene); g_host->set_int("photo_shot", 0); }
  }
  return prev_Comp(self, a1, a2, a3, a4);
}

extern "C" __declspec(dllexport) void xikit_mod_frame(void *device) {
  if (g_host->setting_int("photo_keys", 0)) {
    int k = ph_keys(&g_kyaw, &g_kpitch, &g_kdist, &g_kraise);
    if (k & 4) g_kon = !photo_on();
    if (k & 2) g_khide = !hide_on();
    if ((k & 1) && g_world && device) ph_shot(device, g_world);
  }
  if (hide_on() && g_world && device) ph_cover(device, g_world);
}
extern "C" __declspec(dllexport) void xikit_mod_settings(void) { g_kon = g_khide = -1; }   // a setting written wins over the keys
extern "C" __declspec(dllexport) void xikit_mod_unload(void) { if (g_world) g_world->Release(), g_world = nullptr; }
extern "C" __declspec(dllexport) int xikit_mod_init(const XikitHost *host) {
  g_host = host; ph_init(host->dir ? host->dir : ".", log_line);
  host->declare_int("photo", 0, 0, 1, "1: the free camera (orbits the game's camera by photo_yaw, photo_pitch, photo_dist, photo_raise)");
  host->declare_int("photo_yaw", 0, -180, 180, "degrees about the game's look-at point, around the game's Y axis");
  host->declare_int("photo_pitch", 0, -89, 89, "degrees up or down about the look-at point");
  host->declare_int("photo_dist", 100, 10, 1000, "percent of the game's camera distance");
  host->declare_int("photo_raise", 0, -2000, 2000, "hundredths of a unit along the game's Y axis");
  host->declare_int("photo_hide_ui", 0, 0, 1, "1: cover the interface with the world picture");
  host->declare_int("photo_shot", 0, 0, 1, "1: write a picture of the world (no interface) to screenshots\\, then back to 0");
  host->declare_int("photo_keys", 0, 0, 1, "1: Ctrl+Shift+arrows/PgUp/PgDn/Home/End move, O on/off, H interface, P picture");
  int r = XI_HOOK(host, Camera_SnapshotState, my_Snap, prev_Snap);
  r |= XI_HOOK(host, CDx::CompositeSceneToBackBuffer, my_Comp, prev_Comp);
  return r;
}
