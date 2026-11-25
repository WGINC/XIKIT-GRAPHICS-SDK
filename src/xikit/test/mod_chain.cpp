// mod_chain.cpp -- the second mod of test_xikit.py's "chain" run (host.c): it hooks CXiSkeletonActor::GetColor, which
// mod_test.dll hooks too, adding 100 to what its previous returns. With API 5 the kit chains it in front of
// mod_test.dll's hook: its previous runs mod_test.dll's hook, which runs the game's code.
#include "xikit_sdk.hpp"
XIKIT_MOD_GLOBALS
XIKIT_MOD_INFO("mod_chain", "1", 5, "the chain test's second mod")

static xikit::fn<decltype(&CXiSkeletonActor::GetColor)> prev_GetColor;
static unsigned int __thiscall my_GetColor(CXiSkeletonActor *self) { return prev_GetColor(self) + 100; }
extern "C" {
__declspec(dllexport) volatile long chain_result = -99, chain_api;
__declspec(dllexport) void *chain_prev;
__declspec(dllexport) int xikit_mod_init(const XikitHost *host) {
  chain_api = (long)host->version;
  chain_result = XI_HOOK(host, CXiSkeletonActor::GetColor, my_GetColor, prev_GetColor);
  chain_prev = (void *)prev_GetColor;
  return 0;
}
}
