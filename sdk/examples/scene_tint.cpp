// scene_tint.cpp -- an example mod (docs/SDK.md, "Between the world and the interface"): it tints the finished world
// picture and leaves the interface alone. Build:  sdk/build_mod.sh scene_tint.dll sdk/examples/scene_tint.cpp
//
// Where: CDx::CompositeSceneToBackBuffer (0x1000C0B0). Frame_Render calls it after the world pass and the post
// effects and before the interface (docs/RENDERER.md section 2: steps 4, 5, 6). Its gate-verified source
// (tree/src/CDx.cpp) shows what its first argument holds: outside stereo mode it draws the texture at a1 + 4 over the
// bound target as a screen quad (CDx_DrawTexturedScreenQuad), and in stereo mode it passes the same value to the
// device's vtable +244, slot 61, IDirect3DDevice8::SetTexture. So before the game's own code runs, a1 + 4 is the
// world picture as it will be shown, and nothing of the interface is in it yet.
//
// What this does there: it draws one full-screen quad into that texture's level 0 with the blend dest = dest * colour
// (D3DBLEND_ZERO, D3DBLEND_SRCCOLOR), then lets the game composite it. A mod that wants a real post effect does the
// same with its own drawing; one that wants a modern shader needs d3d8on11's extension (docs/DEVKIT.md, D3b).
//
// What is checked at run time rather than assumed: the value at a1 + 4 is a texture (GetType() == D3DRTYPE_TEXTURE);
// stereo mode is skipped (the game's own test, sub_1000D660(g_pEnv) == 1). The render target, the depth surface
// and the viewport are put back as they were: setting a render target resets the viewport in Direct3D 8, and the game
// set its own just before this call (CDx_SetViewport, step 5).
#include "xikit_sdk.hpp"
XIKIT_MOD_GLOBALS

// values from the DirectX 8 SDK header d3d8types.h that xi_d3d8.hpp does not name
enum : unsigned { FVF_XYZRHW = 0x004, FVF_DIFFUSE = 0x040, TOP_SELECTARG1 = 2, TA_DIFFUSE = 0, BLEND_ZERO = 1,
                  BLEND_SRCCOLOR = 3, CULL_NONE = 1 };
// D3DSURFACE_DESC of Direct3D 8 (d3d8types.h): Format, Type, Usage, Pool, Size, MultiSampleType, Width, Height
struct SurfDesc8 { unsigned Format, Type, Usage, Pool, Size, MultiSampleType, Width, Height; };

static const XikitHost *g_host;
static volatile long g_done, g_skipped;

static void tint(IDirect3DDevice8 *dev, IDirect3DTexture8 *scene) {
  SurfDesc8 d = {}; IDirect3DSurface8 *dst = nullptr, *oldrt = nullptr, *oldz = nullptr; D3DVIEWPORT8 vp = {};
  if (scene->GetLevelDesc(0, &d) < 0 || scene->GetSurfaceLevel(0, &dst) < 0 || !dst) { g_skipped++; return; }
  dev->GetRenderTarget(&oldrt); dev->GetDepthStencilSurface(&oldz); dev->GetViewport(&vp);
  static const D3DRENDERSTATETYPE rs[] = { D3DRS_ZENABLE, D3DRS_ZWRITEENABLE, D3DRS_LIGHTING, D3DRS_FOGENABLE, D3DRS_CULLMODE,
                                           D3DRS_ALPHATESTENABLE, D3DRS_ALPHABLENDENABLE, D3DRS_SRCBLEND, D3DRS_DESTBLEND };
  static const D3DTEXTURESTAGESTATETYPE ts[] = { D3DTSS_COLOROP, D3DTSS_COLORARG1, D3DTSS_ALPHAOP, D3DTSS_ALPHAARG1 };
  unsigned rsv[sizeof rs / sizeof *rs], tsv[sizeof ts / sizeof *ts], vs = 0; IDirect3DBaseTexture8 *tex = nullptr;
  for (unsigned i = 0; i < sizeof rs / sizeof *rs; i++) dev->GetRenderState(rs[i], &rsv[i]);
  for (unsigned i = 0; i < sizeof ts / sizeof *ts; i++) dev->GetTextureStageState(0, ts[i], &tsv[i]);
  dev->GetVertexShader(&vs); dev->GetTexture(0, &tex);
  if (dev->SetRenderTarget(dst, nullptr) >= 0) {           // (no depth surface: the quad is not depth-tested)
    const unsigned rsn[] = { 0, 0, 0, 0, CULL_NONE, 0, 1, BLEND_ZERO, BLEND_SRCCOLOR };
    for (unsigned i = 0; i < sizeof rs / sizeof *rs; i++) dev->SetRenderState(rs[i], rsn[i]);
    dev->SetTextureStageState(0, D3DTSS_COLOROP, TOP_SELECTARG1); dev->SetTextureStageState(0, D3DTSS_COLORARG1, TA_DIFFUSE);
    dev->SetTextureStageState(0, D3DTSS_ALPHAOP, TOP_SELECTARG1); dev->SetTextureStageState(0, D3DTSS_ALPHAARG1, TA_DIFFUSE);
    dev->SetTexture(0, nullptr); dev->SetVertexShader(FVF_XYZRHW | FVF_DIFFUSE);
    struct Vtx { float x, y, z, rhw; unsigned color; };
    const unsigned c = 0xFFFFD8B0u;                      // warm: red kept, green 85%, blue 69%
    const float w = (float)d.Width, h = (float)d.Height;
    Vtx q[4] = { { -0.5f, -0.5f, 0, 1, c }, { w - 0.5f, -0.5f, 0, 1, c }, { -0.5f, h - 0.5f, 0, 1, c }, { w - 0.5f, h - 0.5f, 0, 1, c } };
    dev->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, q, sizeof(Vtx));
    g_done++;
  } else g_skipped++;
  for (unsigned i = 0; i < sizeof rs / sizeof *rs; i++) dev->SetRenderState(rs[i], rsv[i]);
  for (unsigned i = 0; i < sizeof ts / sizeof *ts; i++) dev->SetTextureStageState(0, ts[i], tsv[i]);
  dev->SetVertexShader(vs); dev->SetTexture(0, tex);
  dev->SetRenderTarget(oldrt, oldz); dev->SetViewport(&vp);
  if (tex) tex->Release();                               // the Get* calls added references
  if (oldrt) oldrt->Release();
  if (oldz) oldz->Release();
  dst->Release();
}

static xikit::fn<decltype(&CDx::CompositeSceneToBackBuffer)> prev_Composite;
static int __thiscall my_Composite(CDx *self, int a1, int a2, int a3, int a4) {
  IDirect3DTexture8 *scene = a1 ? *reinterpret_cast<IDirect3DTexture8 **>(a1 + 4) : nullptr;
  IDirect3DDevice8 *dev = *reinterpret_cast<IDirect3DDevice8 **>(reinterpret_cast<char *>(self) + 0xC);   // CDx +0x0C: the device (RENDERER.md 9)
  if (scene && dev && orig::sub_1000D660(g_pEnv) != 1 && scene->GetType() == D3DRTYPE_TEXTURE) tint(dev, scene);
  else g_skipped++;
  return prev_Composite(self, a1, a2, a3, a4);           // the game's own composite, unchanged
}

extern "C" __declspec(dllexport) void xikit_mod_frame(void *) {
  static unsigned n;
  if (++n % 600 == 0) g_host->log("scene_tint: %ld tinted, %ld skipped in the last 600 frames", (long)g_done, (long)g_skipped), g_done = g_skipped = 0;
}

extern "C" __declspec(dllexport) int xikit_mod_init(const XikitHost *host) {
  g_host = host;
  return XI_HOOK(host, CDx::CompositeSceneToBackBuffer, my_Composite, prev_Composite);
}
