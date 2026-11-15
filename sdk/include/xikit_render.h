/* xikit_render.h -- shader passes through d3d8on11 (docs/SDK.md, "Shader passes"; docs/DEVKIT.md D3b, D3c).
 *
 * d3d8on11's d3d8.dll exports these; any other d3d8.dll (dgVoodoo's, Wine's, Microsoft's) does not, and
 * xikit_render_load() then returns 0, so a mod can fall back to plain Direct3D 8 drawing.
 *
 *   unsigned PassShader(const char *hlsl, unsigned bytes)
 *     A pixel shader, compiled by the executor (Direct3D 12: ps_5_0, Direct3D 11: ps_4_0; write for ps_4_0). Its entry is
 *       float4 ps(float4 pos : SV_Position, float2 uv : TEXCOORD0) : SV_Target
 *     with t0 the source texture (Texture2D), s0 a LINEAR / CLAMP sampler, b0 the constants (float4 c[64]), and with
 *     PassDepth t1 the depth (Texture2D<float>: 0..1). pos is the destination pixel (its centre), uv 0..1 across the
 *     destination from its top left. Returns the shader's id, 0 when it does not compile (d3d8on11.log has the
 *     compiler's message and the source).
 *   int Pass(unsigned shader, IDirect3DTexture8 *src, IDirect3DSurface8 *dst, const float *c, unsigned n)
 *     One draw of the shader over the whole of dst (a render-target texture's level or a render target; not the back
 *     buffer), with t0 a copy of src's level 0 as it is at that point of the stream, so src may be dst's texture (the
 *     usual case: a post effect in place). n float4 constants (at most 64). In order with the mod's other device calls.
 *     1: done; 0: refused.
 *   int PassDepth(unsigned shader, IDirect3DTexture8 *src, IDirect3DSurface8 *depth, IDirect3DSurface8 *dst,
 *                 const float *c, unsigned n)
 *     Pass, with a depth-stencil surface read at t1. Refused (0) unless d3d8on11.ini has depth_reads=1, which makes
 *     every depth surface readable from the device's creation on (off by default: the game's depth is then made as
 *     before).
 *
 * Tested offline (kit/d3d8on11/test, t8 scenes shader_pass and depth_pass, on both executors): the pictures equal
 * Wine's d3d8 drawing the expected values directly. */
#pragma once
/* (gfx_globals.hpp defines GetProcAddress as the game's own import slot; the system's is declared and used here) */
#pragma push_macro("GetProcAddress")
#undef GetProcAddress
#ifndef _WINDEF_   /* (the SDK's headers declare the game's own DWORD and others, which windows.h would contradict) */
extern "C" __declspec(dllimport) void *__stdcall GetModuleHandleA(const char *);
extern "C" __declspec(dllimport) void *__stdcall GetProcAddress(void *, const char *);
#endif

struct IDirect3DTexture8; struct IDirect3DSurface8;
typedef unsigned (__stdcall *xikit_pass_shader_fn)(const char *hlsl, unsigned bytes);
typedef int (__stdcall *xikit_pass_fn)(unsigned shader, struct IDirect3DTexture8 *src, struct IDirect3DSurface8 *dst, const float *c, unsigned n);
typedef int (__stdcall *xikit_pass_depth_fn)(unsigned shader, struct IDirect3DTexture8 *src, struct IDirect3DSurface8 *depth,
                                             struct IDirect3DSurface8 *dst, const float *c, unsigned n);
typedef struct { xikit_pass_shader_fn PassShader; xikit_pass_fn Pass; xikit_pass_depth_fn PassDepth; } XikitRender;

/* 1 when the d3d8.dll in the process is d3d8on11 with shader passes (PassDepth may still be NULL on an older one) */
static inline int xikit_render_load(XikitRender *r) {
  auto m = GetModuleHandleA("d3d8.dll");
  r->PassShader = m ? (xikit_pass_shader_fn)(void *)GetProcAddress(m, "D8ON11_PassShader") : 0;
  r->Pass = m ? (xikit_pass_fn)(void *)GetProcAddress(m, "D8ON11_Pass") : 0;
  r->PassDepth = m ? (xikit_pass_depth_fn)(void *)GetProcAddress(m, "D8ON11_PassDepth") : 0;
  return r->PassShader && r->Pass;
}
#pragma pop_macro("GetProcAddress")
