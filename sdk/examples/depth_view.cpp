// depth_view.cpp -- an example and a probe (docs/SDK.md, "Shader passes"; docs/DEVKIT.md D3c): which depth surface the
// game draws its world with, and that surface's depth shown in the top-left quarter of the world picture.
// Build:  sdk/build_mod.sh depth_view.dll sdk/examples/depth_view.cpp      Needs d3d8on11.ini depth_reads=1.
//
// What is not assumed: which depth surface is the world's. The world is drawn into the scene texture
// (CDx::CompositeSceneToBackBuffer's a1 + 4: docs/SDK.md, "Between the world and the interface"). A device hook on
// SetRenderTarget records the depth surface the game binds together with that texture's level 0: that pairing, seen in
// the game, is the answer, and the log names it (its size and format) every 600 frames, with how many different depth
// surfaces were bound with the world's target in that time.
//
// What it then draws: at the composite, a shader pass over the scene texture in place: the top-left quarter shows the
// recorded surface's depth as grey (near dark, far bright: z^8, to spread the far end where most of a 0..1 depth is),
// the rest of the picture as it was.
#include "xikit_sdk.hpp"
#include "xikit_render.h"
XIKIT_MOD_GLOBALS

struct SurfDesc8 { unsigned Format, Type, Usage, Pool, Size, MultiSampleType, Width, Height; };   // d3d8types.h D3DSURFACE_DESC

static const XikitHost *g_host;
static XikitRender g_r; static unsigned g_shader;
static IDirect3DSurface8 *volatile g_scene_lv;    // the scene texture's level 0, as last seen at the composite (not referenced)
static IDirect3DSurface8 *volatile g_world_z;     // the depth bound with it most recently (not referenced)
static IDirect3DSurface8 *g_seen[8]; static int g_nseen;
static volatile long g_shown, g_nodepth;

static const char *k_hlsl =
  "Texture2D src : register(t0); Texture2D<float> dep : register(t1); SamplerState smp : register(s0);\n"
  "float4 ps(float4 pos : SV_Position, float2 uv : TEXCOORD0) : SV_Target {\n"
  "  if (uv.x < 0.5 && uv.y < 0.5) { uint w, h; dep.GetDimensions(w, h); float z = dep.Load(int3(uv * 2 * float2(w, h), 0));\n"
  "    float g = pow(saturate(z), 8); return float4(g, g, g, 1); }\n"
  "  return src.Sample(smp, uv);\n"
  "}\n";

static XI_DEVICE_FN(SetRenderTarget) prev_SetRenderTarget;
static int __stdcall my_SetRenderTarget(IDirect3DDevice8 *dev, IDirect3DSurface8 *rt, IDirect3DSurface8 *z) {
  if (rt && rt == g_scene_lv) {
    g_world_z = z;
    int known = 0; for (int i = 0; i < g_nseen; i++) known |= g_seen[i] == z;
    if (!known && g_nseen < 8) g_seen[g_nseen++] = z;
  }
  return prev_SetRenderTarget(dev, rt, z);
}

static xikit::fn<decltype(&CDx::CompositeSceneToBackBuffer)> prev_Composite;
static int __thiscall my_Composite(CDx *self, int a1, int a2, int a3, int a4) {
  IDirect3DTexture8 *scene = a1 ? *reinterpret_cast<IDirect3DTexture8 **>(a1 + 4) : nullptr;
  IDirect3DSurface8 *lv = nullptr;
  if (scene && orig::sub_1000D660(g_pEnv) != 1 && scene->GetType() == D3DRTYPE_TEXTURE && scene->GetSurfaceLevel(0, &lv) >= 0 && lv) {
    g_scene_lv = lv;                                       // (compared by address in the hook; the texture keeps it alive)
    IDirect3DSurface8 *z = g_world_z;
    if (z && g_r.PassDepth && g_r.PassDepth(g_shader, scene, z, lv, nullptr, 0)) g_shown++; else g_nodepth++;
    lv->Release();
  }
  return prev_Composite(self, a1, a2, a3, a4);
}

extern "C" __declspec(dllexport) void xikit_mod_frame(void *) {
  static unsigned n;
  if (++n % 600) return;
  IDirect3DSurface8 *z = g_world_z; SurfDesc8 d = {};
  if (z) z->GetDesc(&d);
  g_host->log("depth_view: the world's target was bound with %d different depth surface(s) so far; the last %p (%ux%u, D3DFORMAT %u); "
              "shown %ld, not shown %ld (no depth seen yet, or depth_reads=0 in d3d8on11.ini) in the last 600 frames",
              g_nseen, (void *)z, d.Width, d.Height, d.Format, (long)g_shown, (long)g_nodepth);
  g_shown = g_nodepth = 0;
}

extern "C" __declspec(dllexport) int xikit_mod_init(const XikitHost *host) {
  g_host = host;
  if (!xikit_render_load(&g_r) || !g_r.PassDepth) { host->log("depth_view: the d3d8.dll in use has no depth passes (not d3d8on11): nothing done"); return 0; }
  g_shader = g_r.PassShader(k_hlsl, (unsigned)strlen(k_hlsl));
  if (!g_shader) { host->log("depth_view: the shader did not compile (d3d8on11.log says why): nothing done"); return 0; }
  if (XI_DEVICE_HOOK(host, SetRenderTarget, my_SetRenderTarget, prev_SetRenderTarget) != XIKIT_OK) return 1;
  return XI_HOOK(host, CDx::CompositeSceneToBackBuffer, my_Composite, prev_Composite);
}
