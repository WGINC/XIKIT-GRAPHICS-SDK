// world_light.cpp -- an example mod: the zone's fog (distance, colour, off) and its ambient light.
// Build:  sdk/build_mod.sh world_light.dll sdk/examples/world_light.cpp
//
// Where (gate-verified source in tree/src/EnvLight.cpp):
// - Env_ComputeFog (0x10189120): (env, &colour, &end, &start, kind) -> the fog colour (0xRRGGBB, from the zone's
//   floats * 255), its end and start distances (the zone's values times a factor of the time of day, 0x101892B0),
//   end kept above start; without a zone record (env -0x1C != 1) white, 400 and 0; with no data (env +0x18 == 0)
//   0x808080, 400 and 300. Callers: XiZone_DrawElement, ZoneMap_DrawMeshById, XiZone::GetFog, 0x1017DE20.
// - Env_ComputeAmbient (0x10188E00): (env, &colour, kind) -> 0x00RRGGBB with 128 = 1.0 (the PS2's colour scale), from
//   the floats at env +0x104 (kind 0, Env_GetAmbientColorPtr) or env +0x84 (kind 1, Env_GetColorPtr84); 0xFFFFFFFF
//   without a zone record. Env_ComputeAmbientFloat4 (0x10188FA0) gives kind 0 as floats. Callers: the zone's draw
//   (XiZone_Draw, XiZone_DrawElement, ZoneMap_DrawMeshById) and XiZone::GetAmbient.
// What colour +0x84 lights is not read here: it is called the light colour below only as a label.
//
// Settings (percent, 100 the game's): fog_distance (both distances), fog_r, fog_g, fog_b (the fog colour's channels),
// fog_off (1: start and end pushed to 100000), ambient (kind 0 and the float version), light (kind 1). The values
// the game hands back as "no zone record" (white fog, ambient 0xFFFFFFFF) keep their colour; distances still scale.
//
// Tested offline (kit/xikit/test, mode envmod): the game's own Env_ComputeFog and Env_ComputeAmbient on an
// environment object, their outputs read back. Not yet run in the game.
#include "xikit_sdk.hpp"
XIKIT_MOD_GLOBALS

static const XikitHost *g_host;
static int pc(const char *k) { return g_host->setting_int(k, 100); }
static unsigned scale_ch(unsigned v, int p, unsigned cap) { unsigned long long x = (unsigned long long)v * (unsigned)p / 100; return (unsigned)(x > cap ? cap : x); }

static xikit::fn<decltype(&Env_ComputeFog)> prev_Fog;
static void __thiscall my_Fog(void *env, uint32_t *colour, float *end, float *start, int kind) {
  prev_Fog(env, colour, end, start, kind);
  if (g_host->setting_int("fog_off", 0)) { if (start) *start = 100000.0f; if (end) *end = 100001.0f; return; }
  int d = pc("fog_distance");
  if (d != 100) { if (start) *start = *start * d / 100.0f; if (end) *end = *end * d / 100.0f; if (start && end && *end <= *start) *end = *start + 1.0f; }
  if (colour && *colour != 0xFFFFFFFFu) {
    unsigned c = *colour;
    *colour = (c & 0xFF000000u) | scale_ch((c >> 16) & 0xFF, pc("fog_r"), 255) << 16 | scale_ch((c >> 8) & 0xFF, pc("fog_g"), 255) << 8 | scale_ch(c & 0xFF, pc("fog_b"), 255);
  }
}
static xikit::fn<decltype(&Env_ComputeAmbient)> prev_Amb;
static _DWORD *__thiscall my_Amb(char *env, _DWORD *out, int kind) {
  _DWORD *r = prev_Amb(env, out, kind);
  int p = kind == 1 ? pc("light") : pc("ambient");
  if (out && *out != 0xFFFFFFFFu && p != 100) {
    unsigned c = *out;
    *out = (c & 0xFF000000u) | scale_ch((c >> 16) & 0xFF, p, 255) << 16 | scale_ch((c >> 8) & 0xFF, p, 255) << 8 | scale_ch(c & 0xFF, p, 255);
  }
  return r;
}
static xikit::fn<decltype(&Env_ComputeAmbientFloat4)> prev_Amb4;
static float *__thiscall my_Amb4(char *env, float *out) {
  float *r = prev_Amb4(env, out);
  int p = pc("ambient");
  if (out && p != 100) for (int i = 0; i < 3; i++) out[i] = out[i] * p / 100.0f;
  return r;
}

extern "C" __declspec(dllexport) int xikit_mod_init(const XikitHost *host) {
  g_host = host;
  host->declare_int("fog_distance", 100, 10, 1000, "percent of the game's fog start and end distances");
  host->declare_int("fog_r", 100, 0, 200, "percent of the fog colour's red");
  host->declare_int("fog_g", 100, 0, 200, "percent of the fog colour's green");
  host->declare_int("fog_b", 100, 0, 200, "percent of the fog colour's blue");
  host->declare_int("fog_off", 0, 0, 1, "1: no fog (start and end at 100000)");
  host->declare_int("ambient", 100, 0, 300, "percent of the zone's ambient light");
  host->declare_int("light", 100, 0, 300, "percent of the zone's second light colour (Env_ComputeAmbient kind 1)");
  int r = XI_HOOK(host, Env_ComputeFog, my_Fog, prev_Fog);
  r |= XI_HOOK(host, Env_ComputeAmbient, my_Amb, prev_Amb);
  r |= XI_HOOK(host, Env_ComputeAmbientFloat4, my_Amb4, prev_Amb4);
  return r;
}
