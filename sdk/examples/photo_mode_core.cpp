// photo_mode_core.cpp -- the maths, picture file and drawing of photo_mode (Windows and the MinGW-w64 Direct3D 8
// headers only; photo_mode.cpp has the hooks and says what they read of the game).
#include <windows.h>
#include <d3d8.h>
#include <stdio.h>
#include <math.h>
static const double kPi = 3.14159265358979323846;
#include <string>
#include "photo_mode_core.h"

static std::string g_dir;
static void (*g_log)(const char *);
static void logf(const char *fmt, ...) { char b[512]; va_list a; va_start(a, fmt); vsnprintf(b, sizeof b, fmt, a); va_end(a); if (g_log) g_log(b); }

extern "C" void ph_init(const char *dir, void (*log)(const char *)) { g_dir = dir; g_log = log; }

extern "C" void ph_orbit(const float eye[3], const float at[3], float yaw_deg, float pitch_deg, float dist_pct, float raise, float out[3]) {
  double vx = eye[0] - at[0], vy = eye[1] - at[1], vz = eye[2] - at[2], r = sqrt(vx * vx + vy * vy + vz * vz);
  if (r < 1e-6) { for (int i = 0; i < 3; i++) out[i] = eye[i]; out[1] += raise; return; }
  double yaw = atan2(vx, vz) + yaw_deg * kPi / 180.0, pitch = asin(vy / r) + pitch_deg * kPi / 180.0;
  const double lim = 89.0 * kPi / 180.0; if (pitch > lim) pitch = lim; if (pitch < -lim) pitch = -lim;
  double rr = r * dist_pct / 100.0;
  out[0] = (float)(at[0] + rr * cos(pitch) * sin(yaw));
  out[1] = (float)(at[1] + rr * sin(pitch) + raise);
  out[2] = (float)(at[2] + rr * cos(pitch) * cos(yaw));
}

extern "C" int ph_shot(void *device, void *texture) {
  IDirect3DDevice8 *dev = (IDirect3DDevice8 *)device; IDirect3DTexture8 *tex = (IDirect3DTexture8 *)texture;
  IDirect3DSurface8 *src = nullptr, *img = nullptr; D3DSURFACE_DESC sd = {}; int ok = 0;
  if (FAILED(tex->GetSurfaceLevel(0, &src)) || !src) return 0;
  src->GetDesc(&sd);
  if ((sd.Format == D3DFMT_A8R8G8B8 || sd.Format == D3DFMT_X8R8G8B8) && SUCCEEDED(dev->CreateImageSurface(sd.Width, sd.Height, sd.Format, &img)) &&
      SUCCEEDED(dev->CopyRects(src, nullptr, 0, img, nullptr))) {
    D3DLOCKED_RECT lr = {};
    if (SUCCEEDED(img->LockRect(&lr, nullptr, D3DLOCK_READONLY))) {
      CreateDirectoryA((g_dir + "\\screenshots").c_str(), nullptr);
      SYSTEMTIME t; GetLocalTime(&t); char name[64];
      snprintf(name, sizeof name, "\\screenshots\\photo_%04u%02u%02u_%02u%02u%02u_%03u.bmp", t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond, t.wMilliseconds);
      FILE *f = fopen((g_dir + name).c_str(), "wb");
      if (f) {
        unsigned row = (sd.Width * 3 + 3) & ~3u, size = row * sd.Height;
        BITMAPFILEHEADER fh = {}; BITMAPINFOHEADER ih = {};
        fh.bfType = 0x4D42; fh.bfOffBits = sizeof fh + sizeof ih; fh.bfSize = fh.bfOffBits + size;
        ih.biSize = sizeof ih; ih.biWidth = sd.Width; ih.biHeight = sd.Height; ih.biPlanes = 1; ih.biBitCount = 24; ih.biSizeImage = size;
        fwrite(&fh, sizeof fh, 1, f); fwrite(&ih, sizeof ih, 1, f);
        unsigned char *line = (unsigned char *)calloc(row, 1);
        for (int y = (int)sd.Height - 1; y >= 0; y--) {          // BMP rows bottom-up; B, G, R from the B, G, R, A of the surface
          const unsigned char *s = (const unsigned char *)lr.pBits + (size_t)y * lr.Pitch;
          for (unsigned x = 0; x < sd.Width; x++) { line[x * 3] = s[x * 4]; line[x * 3 + 1] = s[x * 4 + 1]; line[x * 3 + 2] = s[x * 4 + 2]; }
          fwrite(line, 1, row, f);
        }
        free(line); fclose(f); ok = 1;
        logf("photo_mode: %s (%ux%u)", name + 1, sd.Width, sd.Height);
      }
      img->UnlockRect();
    }
  } else logf("photo_mode: no picture: the world texture is format %u, or the device refused the copy", (unsigned)sd.Format);
  if (img) img->Release();
  src->Release();
  return ok;
}

extern "C" void ph_cover(void *device, void *texture) {
  IDirect3DDevice8 *dev = (IDirect3DDevice8 *)device; IDirect3DTexture8 *tex = (IDirect3DTexture8 *)texture;
  IDirect3DSurface8 *rt = nullptr; D3DSURFACE_DESC rd = {};
  if (FAILED(dev->GetRenderTarget(&rt)) || !rt) return;
  rt->GetDesc(&rd); rt->Release();
  DWORD sb = 0; if (FAILED(dev->CreateStateBlock(D3DSBT_ALL, &sb))) return;     // everything put back afterwards
  IDirect3DBaseTexture8 *old = nullptr; dev->GetTexture(0, &old);
  dev->BeginScene();
  dev->SetRenderState(D3DRS_ZENABLE, FALSE); dev->SetRenderState(D3DRS_ZWRITEENABLE, FALSE); dev->SetRenderState(D3DRS_LIGHTING, FALSE);
  dev->SetRenderState(D3DRS_FOGENABLE, FALSE); dev->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE); dev->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
  dev->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
  dev->SetTexture(0, tex);
  dev->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1); dev->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
  dev->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_DISABLE); dev->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_DISABLE);
  dev->SetTextureStageState(0, D3DTSS_MINFILTER, D3DTEXF_LINEAR); dev->SetTextureStageState(0, D3DTSS_MAGFILTER, D3DTEXF_LINEAR);
  dev->SetTextureStageState(0, D3DTSS_MIPFILTER, D3DTEXF_NONE);
  dev->SetTextureStageState(0, D3DTSS_ADDRESSU, D3DTADDRESS_CLAMP); dev->SetTextureStageState(0, D3DTSS_ADDRESSV, D3DTADDRESS_CLAMP);
  dev->SetPixelShader(0); dev->SetVertexShader(D3DFVF_XYZRHW | D3DFVF_TEX1);
  struct V { float x, y, z, w, u, v; };
  float w = (float)rd.Width, h = (float)rd.Height;
  V q[4] = { { -0.5f, -0.5f, 0, 1, 0, 0 }, { w - 0.5f, -0.5f, 0, 1, 1, 0 }, { -0.5f, h - 0.5f, 0, 1, 0, 1 }, { w - 0.5f, h - 0.5f, 0, 1, 1, 1 } };
  dev->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, q, sizeof(V));
  dev->EndScene();
  dev->SetTexture(0, old); if (old) old->Release();
  dev->ApplyStateBlock(sb); dev->DeleteStateBlock(sb);
}
