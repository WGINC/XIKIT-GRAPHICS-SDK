// color_filter_core.cpp -- the matrices, the copy of the frame and the drawing of color_filter (Windows and the MinGW-w64
// Direct3D 8 headers only).
#include <windows.h>
#include <d3d8.h>
#include <string.h>
#include "color_filter_core.h"

// Simulation of dichromacy, severity 1.0: Machado, Oliveira and Fernandes, "A Physiologically-based Model for
// Simulation of Color Vision Deficiency" (IEEE TVCG 2009), the published table, for linear RGB: color_filter.cpp's
// shader decodes each pixel from sRGB before the matrix and encodes it after (25 Nov)
static const float kSim[3][9] = {
  { 0.152286f, 1.052583f, -0.204868f,   0.114503f, 0.786281f, 0.099216f,   -0.003882f, -0.048116f, 1.051998f },   // protanopia
  { 0.367322f, 0.860646f, -0.227968f,   0.280085f, 0.672501f, 0.047413f,   -0.011820f, 0.042940f, 0.968881f },    // deuteranopia
  { 1.255528f, -0.076749f, -0.178779f,  -0.078411f, 0.930809f, 0.147602f,   0.004733f, 0.691367f, 0.303900f },    // tritanopia
};
// Correction ("daltonize", Fidaner, Lin and Ozguven): what the simulation loses, err = c - S c, shifted into the
// channels that remain: c' = c + E err, with E = [0 0 0; 0.7 1 0; 0.7 0 1]
static const float kErr[9] = { 0, 0, 0,   0.7f, 1, 0,   0.7f, 0, 1 };

extern "C" void cf_matrix(int mode, int strength, int simulate, float out[12]) {
  float m[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };
  if (mode >= 1 && mode <= 3) {
    const float *s = kSim[mode - 1], k = strength / 100.0f;
    if (simulate) for (int i = 0; i < 9; i++) m[i] = (i % 4 == 0 ? 1 - k : 0.0f) + k * s[i];   // (1 - k) I + k S
    else {
      float d[9]; for (int i = 0; i < 9; i++) d[i] = (i % 4 == 0 ? 1.0f : 0.0f) - s[i];   // I - S
      for (int r = 0; r < 3; r++) for (int c = 0; c < 3; c++) {
        float e = 0; for (int j = 0; j < 3; j++) e += kErr[r * 3 + j] * d[j * 3 + c];
        m[r * 3 + c] = (r == c ? 1.0f : 0.0f) + k * e;
      }
    }
  }
  for (int r = 0; r < 3; r++) { out[r * 4] = m[r * 3]; out[r * 4 + 1] = m[r * 3 + 1]; out[r * 4 + 2] = m[r * 3 + 2]; out[r * 4 + 3] = 0; }
}

static IDirect3DTexture8 *g_a, *g_b; static UINT g_w, g_h; static D3DFORMAT g_f;
extern "C" void cf_release(void) { if (g_a) g_a->Release(); if (g_b) g_b->Release(); g_a = g_b = nullptr; g_w = g_h = 0; }

extern "C" int cf_frame(void *device, cf_pass_fn pass, unsigned shader, const float m[12], void (*log)(const char *)) {
  IDirect3DDevice8 *dev = (IDirect3DDevice8 *)device;
  IDirect3DSurface8 *bb = nullptr, *rt = nullptr, *sa = nullptr, *sb = nullptr; D3DSURFACE_DESC d = {}; int ok = 0;
  if (FAILED(dev->GetRenderTarget(&rt)) || !rt) return 0;
  if (FAILED(dev->GetBackBuffer(0, D3DBACKBUFFER_TYPE_MONO, &bb)) || !bb) { rt->Release(); return 0; }
  bb->GetDesc(&d);
  if (rt != bb) { rt->Release(); bb->Release(); return 0; }          // (the frame is drawn into the back buffer itself)
  if (!g_a || d.Width != g_w || d.Height != g_h || d.Format != g_f) {
    cf_release();
    if (FAILED(dev->CreateTexture(d.Width, d.Height, 1, D3DUSAGE_RENDERTARGET, d.Format, D3DPOOL_DEFAULT, &g_a)) ||
        FAILED(dev->CreateTexture(d.Width, d.Height, 1, D3DUSAGE_RENDERTARGET, d.Format, D3DPOOL_DEFAULT, &g_b))) {
      cf_release(); if (log) log("color_filter: the device refused the two frame-sized textures; nothing done"); rt->Release(); bb->Release(); return 0;
    }
    g_w = d.Width; g_h = d.Height; g_f = d.Format;
  }
  g_a->GetSurfaceLevel(0, &sa); g_b->GetSurfaceLevel(0, &sb);
  if (sa && sb && SUCCEEDED(dev->CopyRects(bb, nullptr, 0, sa, nullptr)) && pass(shader, g_a, sb, m, 3)) {
    DWORD blk = 0;
    if (SUCCEEDED(dev->CreateStateBlock(D3DSBT_ALL, &blk))) {
      IDirect3DBaseTexture8 *old = nullptr; dev->GetTexture(0, &old);
      dev->BeginScene();
      dev->SetRenderState(D3DRS_ZENABLE, FALSE); dev->SetRenderState(D3DRS_ZWRITEENABLE, FALSE); dev->SetRenderState(D3DRS_LIGHTING, FALSE);
      dev->SetRenderState(D3DRS_FOGENABLE, FALSE); dev->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE); dev->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
      dev->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE); dev->SetRenderState(D3DRS_COLORWRITEENABLE, 0xF);
      dev->SetTexture(0, g_b);
      dev->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1); dev->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
      dev->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_DISABLE); dev->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_DISABLE);
      dev->SetTextureStageState(0, D3DTSS_MINFILTER, D3DTEXF_POINT); dev->SetTextureStageState(0, D3DTSS_MAGFILTER, D3DTEXF_POINT);
      dev->SetTextureStageState(0, D3DTSS_MIPFILTER, D3DTEXF_NONE);
      dev->SetPixelShader(0); dev->SetVertexShader(D3DFVF_XYZRHW | D3DFVF_TEX1);
      struct V { float x, y, z, w, u, v; }; float w = (float)d.Width, h = (float)d.Height;
      V q[4] = { { -0.5f, -0.5f, 0, 1, 0, 0 }, { w - 0.5f, -0.5f, 0, 1, 1, 0 }, { -0.5f, h - 0.5f, 0, 1, 0, 1 }, { w - 0.5f, h - 0.5f, 0, 1, 1, 1 } };
      dev->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, q, sizeof(V));
      dev->EndScene();
      dev->SetTexture(0, old); if (old) old->Release();
      dev->ApplyStateBlock(blk); dev->DeleteStateBlock(blk);
      ok = 1;
    }
  }
  if (sa) sa->Release();
  if (sb) sb->Release();
  rt->Release(); bb->Release();
  return ok;
}

extern "C" long cf_check(void *device) {
  IDirect3DDevice8 *dev = (IDirect3DDevice8 *)device; IDirect3DSurface8 *s = nullptr, *img = nullptr; long v = -1;
  if (!g_b || FAILED(g_b->GetSurfaceLevel(0, &s)) || !s) return -1;
  if (SUCCEEDED(dev->CreateImageSurface(g_w, g_h, g_f, &img)) && SUCCEEDED(dev->CopyRects(s, nullptr, 0, img, nullptr))) {
    D3DLOCKED_RECT lr = {};
    if (SUCCEEDED(img->LockRect(&lr, nullptr, D3DLOCK_READONLY))) { v = (long)(((unsigned *)lr.pBits)[(g_h / 2) * (lr.Pitch / 4) + g_w / 2] & 0xFFFFFF); img->UnlockRect(); }
  }
  if (img) img->Release();
  s->Release();
  return v;
}
