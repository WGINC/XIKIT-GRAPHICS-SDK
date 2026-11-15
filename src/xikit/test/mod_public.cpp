// mod_public.cpp -- the test mod of the public kit (host.c "public", test_public.py): built with the cut SDK's own
// build_mod.sh and headers (sdk/public_prune.py's output), no reconstruction to link against. Hooks CDx::EndClearBegin
// (in the cut manifest) with a pass-through, BeginScene at the device, and declares one setting.
#include "xikit_sdk.hpp"
XIKIT_MOD_GLOBALS

extern "C" {
__declspec(dllexport) volatile long mod_frames, mod_init_rel, mod_hook_result = -99, mod_dev_result = -99, mod_begins;
__declspec(dllexport) void *mod_prev_ecb;
__declspec(dllexport) volatile long mod_set_v0 = -1, mod_set_told, mod_set_val = -1;
}
static xikit::fn<decltype(&CDx::EndClearBegin)> prev_EndClearBegin;
static int __thiscall my_EndClearBegin(CDx *self, int a1, int a2, int a3, int a4, int a5, int a6) {
  return prev_EndClearBegin(self, a1, a2, a3, a4, a5, a6);
}
static XI_DEVICE_FN(BeginScene) prev_BeginScene;
static int __stdcall my_BeginScene(IDirect3DDevice8 *dev) { mod_begins++; return prev_BeginScene(dev); }
static const XikitHost *g_h;
extern "C" {
__declspec(dllexport) void xikit_mod_settings(void) { mod_set_told++; mod_set_val = g_h->setting_int("mp_level", -1); }
__declspec(dllexport) int xikit_mod_init(const XikitHost *host) {
  g_h = host; mod_init_rel = (long)xi_rel;
  mod_set_v0 = host->declare_int("mp_level", 3, 0, 9, "a test setting (host.c public)");
  mod_hook_result = XI_HOOK(host, CDx::EndClearBegin, my_EndClearBegin, prev_EndClearBegin);
  mod_prev_ecb = (void *)prev_EndClearBegin;
  mod_dev_result = XI_DEVICE_HOOK(host, BeginScene, my_BeginScene, prev_BeginScene);
  return 0;
}
__declspec(dllexport) void xikit_mod_frame(void *device) { (void)device; mod_frames++; }
}
