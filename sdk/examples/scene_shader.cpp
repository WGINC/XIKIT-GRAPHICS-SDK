// scene_shader.cpp -- an example mod (docs/SDK.md, "Shader passes"): an HLSL pixel shader over the finished world
// picture, between the world and the interface, through d3d8on11's shader passes (sdk/include/xikit_render.h).
// Build:  sdk/build_mod.sh scene_shader.dll sdk/examples/scene_shader.cpp
//
// Where: CDx::CompositeSceneToBackBuffer, as examples/scene_tint.cpp (docs/SDK.md, "Between the world and the
// interface": a1 + 4 is the world picture before the game copies it to the screen). What: a warm grade and a
// vignette (the "Halloween" look): colour * (1.0, 0.62, 0.30), darkened towards the corners by the distance from the
// centre. The interface is drawn after this, so it is untouched.
//
// On a Direct3D 8 that is not d3d8on11 (dgVoodoo's), or if the shader does not compile, nothing is changed and the
// log says why.
#include "xikit_sdk.hpp"
#include "xikit_render.h"
XIKIT_MOD_GLOBALS

static const XikitHost *g_host;
static XikitRender g_r; static unsigned g_shader; static volatile long g_done, g_skipped;

static const char *k_hlsl =
  "Texture2D src : register(t0); SamplerState smp : register(s0); cbuffer C : register(b0) { float4 c[64]; };\n"
  "float4 ps(float4 pos : SV_Position, float2 uv : TEXCOORD0) : SV_Target {\n"
  "  float3 col = src.Sample(smp, uv).rgb * c[0].rgb;\n"
  "  float2 d = uv - 0.5; float v = saturate(1.0 - dot(d, d) * c[1].x);\n"
  "  return float4(col * v, 1);\n"
  "}\n";

static volatile int g_warm = 1, g_vig = 90;            // the settings (a kit before version 4: these defaults)
extern "C" __declspec(dllexport) void xikit_mod_settings(void) {   // (version 4 only: an older kit never calls it)
  g_warm = g_host->setting_int("warm", 1); g_vig = g_host->setting_int("vignette", 90);
  g_host->log("scene_shader: settings now warm=%d vignette=%d", g_warm, g_vig);
}

static xikit::fn<decltype(&CDx::CompositeSceneToBackBuffer)> prev_Composite;
static int __thiscall my_Composite(CDx *self, int a1, int a2, int a3, int a4) {
  IDirect3DTexture8 *scene = a1 ? *reinterpret_cast<IDirect3DTexture8 **>(a1 + 4) : nullptr;
  IDirect3DSurface8 *lv = nullptr;
  if (g_shader && scene && orig::CEnv_IsStereoMode(g_pEnv) != 1 && scene->GetType() == D3DRTYPE_TEXTURE && scene->GetSurfaceLevel(0, &lv) >= 0 && lv) {
    // c[0]: the grade (warm=1) or none (warm=0); c[1].x: the vignette's strength (vignette, in percent of 1.0)
    int warm = g_warm, vig = g_vig;
    float k[8] = {1.0f, warm ? 0.62f : 1.0f, warm ? 0.30f : 1.0f, 1.0f,   vig / 100.0f, 0, 0, 0};
    if (g_r.Pass(g_shader, scene, lv, k, 2)) g_done++; else g_skipped++;
    lv->Release();
  } else g_skipped++;
  return prev_Composite(self, a1, a2, a3, a4);           // the game's own composite, unchanged
}

extern "C" __declspec(dllexport) void xikit_mod_frame(void *) {
  static unsigned n;
  if (++n % 600 == 0) g_host->log("scene_shader: %ld passes, %ld skipped in the last 600 frames", (long)g_done, (long)g_skipped), g_done = g_skipped = 0;
}

extern "C" __declspec(dllexport) int xikit_mod_init(const XikitHost *host) {
  g_host = host;
  if (!xikit_render_load(&g_r)) { host->log("scene_shader: the d3d8.dll in use has no shader passes (not d3d8on11): nothing done"); return 0; }
  g_shader = g_r.PassShader(k_hlsl, (unsigned)strlen(k_hlsl));
  if (!g_shader) { host->log("scene_shader: the shader did not compile (d3d8on11.log says why): nothing done"); return 0; }
  // settings (xikit_mods.ini, [scene_shader]; read again while the game runs: docs/SDK.md, "Settings")
  if (host->version >= 4) {
    g_warm = host->declare_int("warm", 1, 0, 1, "1: the warm grade; 0: colours as they are");
    g_vig = host->declare_int("vignette", 90, 0, 400, "the corners' darkening, in percent (0: none)");
  }
  return XI_HOOK(host, CDx::CompositeSceneToBackBuffer, my_Composite, prev_Composite);
}
