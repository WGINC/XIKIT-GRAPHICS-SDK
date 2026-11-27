// effect_comfort.cpp -- an example mod for comfort and accessibility: a limit on full-screen flashes, and an intensity
// setting for spell and ability effects. Build:  sdk/build_mod.sh effect_comfort.dll sdk/examples/effect_comfort.cpp
//
// Flashes. CDx::DrawFadeQuad (0x1000A820, gate-verified source in tree/src/CDx.cpp) is the game's full-screen colour
// pass: Frame_Render calls it once a frame with the frame's screen colour (tree/src/FrameRender.cpp), the colour the
// Lfd element's screen colouring adds into (CMoLfdElem_Draw -> 0x10014F90). Its code: 0x80808080 draws nothing; an
// alpha byte up to 0x80 darkens the picture (INVSRCALPHA, SRCALPHA); above 0x80 it adds light (SRCALPHA, ONE):
// colour * alpha is added to every pixel. That added light is the flash. This mod scales the colour of the adding
// case by flash_limit (percent; alpha is kept above 0x80 so the game's code stays in the adding case), and with
// flash_rise_ms > 0 lets the added light rise no faster than from nothing to full in that many milliseconds; it falls
// as fast as the game lets it. The darkening case (fades) is left alone.
//
// Effects. YmElem_SetupDevice (0x100467E0) sets the device up for an effect element's draw and YmElem_RestoreDevice
// (0x100472F0) puts it back (tree/src/CMoElem.cpp); its blend modes are SRCALPHA with ONE (adding) or INVSRCALPHA,
// ONE/ZERO, and ZERO/INVSRCALPHA. Between the two, each draw with blending on is drawn with one more texture stage
// after the element's own (the first disabled one), which multiplies by the texture factor: the alpha for SRCALPHA
// source blending, the colour for ONE. So fx_intensity percent scales what each effect adds or covers, linearly. A
// draw is left as it is when a stage before it already reads the texture factor, a pixel shader is set, or the
// device has no free stage (its MaxTextureBlendStages). (25 Nov) A draw whose own stages multiply by the texture factor
// (the game's model draw, CYyModelDt: docs/EFFECTS_DRAW.md) is scaled through the factor instead (its colour for ONE,
// its alpha for SRCALPHA). fx_all_blended=1 applies the same to every blended draw
// (the interface too); it is meant for checking the mod.
//
// Per effect. An element's +0xFC is a handle to the resource it was made from (CMoElem.hpp: listAResourceHandle; the
// damage number's draw reads that resource's CMoAttachments at +0x30, where CMoGeneratorRes keeps its own), and every
// resource holds its chunk id at +0x20, its type at +0x24 & 0x7F and its parent's handle at +0x28 (docs/FORMATS.md 1;
// CMoResource::FindWorker climbs the same way). The mod names an effect by the chunk ids from the topmost parent down
// to the element's resource, "id/id/id" (four printable characters each, or eight hex digits), and effects.txt next
// to the kit gives lines "<path prefix> <percent>": the first line whose prefix starts the path applies, on top of
// fx_intensity; 0 leaves the element's draws out altogether. fx_list=1 logs each path once when it is first drawn, to
// find them. What a path's ids mean (which spell, which part of it) is the effect files' own naming: not read here.
// What each command number of the effect generator and scheduler does is in docs/EFFECT_COMMANDS.md (read from the
// game's two switches); which PS2 tag name goes with which number is not known (it would take the PS2 executable).
//
// The file an effect came from. ResourceLoadTask_Step (0x10072A70, tree/src/ResourceLoadTask.cpp) loads a file by the
// number at task +0x34 (ResourceLoadTask_Start: its argument), handing that number to the file manager's open and
// read (0x101C4BC0, 0x101C46D0); when the file's resources are resolved (MeshResourceMng_ResolveTree) it writes the
// same number to the root resource's +0x34 and sets bit 1 of its +0x1A. ResourceIter_FindOrStartTask (0x10073D80)
// finds a loaded file again by that number. So the mod takes, up the element's chain, the resource with +0x1A bit 1
// and logs its +0x34 as the file number ("effect <path> from file <n>"), and effects.txt also takes "file:<n>
// <percent>" lines for every effect of that file. (An element whose chain has no such resource logs no number.)
// The game turns a file number into a path in XiFileImpl_getFileName (0x101C3A90): with the ROM tables in use, the
// ROM is byte n of the table read from VTABLE.DAT (0: no such file) and v is word n of the table read from FTABLE.DAT;
// ROM 1 gives ROM\<v / 128>\<v % 128>.DAT, ROM k gives ROM<k>\<v / 128>\<v % 128>.DAT. How the expansions' own
// ROM<k>\VTABLE<k>.DAT and FTABLE<k>.DAT are merged into those tables (0x101C3400) was not read: the tables in
// memory are the merged ones. Swapping one effect for another is file_overlay's: the effect's DAT file replaced by
// another's.
//
// Tested offline (kit/xikit/test, mode fx2mod): the game's own YmElem_SetupDevice and YmElem_RestoreDevice on an
// element whose resource path is spel/fire, effects.txt "spel/fire 0": a draw between them is left out, the same draw
// after them is drawn, and fx_list logs the path; an element under a file's root (+0x1A bit 1, file 4321 at +0x34, as
// the load task leaves it) is left out by "file:4321 0", and fx_list logs "efct/wind from file 4321".
// Tested offline (kit/xikit/test, mode fxmod): the game's own DrawFadeQuad with the limit, on Wine's Direct3D 8,
// and the stage on a real draw read back. The bracketing by YmElem_SetupDevice/RestoreDevice has not run (an element
// needs the game running). Not yet run in the game.
#include "xikit_sdk.hpp"
XIKIT_MOD_GLOBALS

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);   // kernel32 (windows.h clashes with the tree's types)

static const XikitHost *g_host;
static int g_in_elem;                  // inside YmElem_SetupDevice ... YmElem_RestoreDevice (render thread)
static unsigned g_max_stages;          // D3DCAPS8::MaxTextureBlendStages, read once
static long g_scaled, g_skipped, g_flashes, g_left_out;
// (25 Nov) why a draw was left as it is (the owner's run: every effect draw left, reason not logged): a pixel shader,
// the draw's own stages read the texture factor, no free stage, a source blend other than ONE or SRCALPHA (the last seen)
static long g_sk_ps, g_sk_tf, g_sk_stage, g_sk_blend, g_sc_tf; static unsigned g_sk_src;
static int g_elem_pct = 100;           // the current element's percent from effects.txt
extern "C" int ec_read(const char *dir, char (*keys)[96], int *pct, int max);   // effect_comfort_core.cpp
static char g_keys[256][96]; static int g_pcts[256], g_nkeys;
struct Listed { void *res; unsigned id; int pct; };
static Listed g_cache[512]; static int g_ncache;
struct MemInfo { void *BaseAddress, *AllocationBase; unsigned long AllocationProtect, RegionSize, State, Protect, Type; };
extern "C" __declspec(dllimport) unsigned long __stdcall VirtualQuery(const void *, MemInfo *, unsigned long);
static bool readable(const void *p, unsigned n) {
  MemInfo mi; if (!p || !VirtualQuery(p, &mi, sizeof mi) || mi.State != 0x1000 || (mi.Protect & 0x101)) return false;
  return (const char *)p + n <= (const char *)mi.BaseAddress + mi.RegionSize;
}
static void *deref(void *handle) { return readable(handle, 4) ? *(void **)handle : nullptr; }
// the element's effect path and its percent (cached by resource and id)
static int elem_percent(void *e) {
  void *res = readable((char *)e + 0xFC, 4) ? deref(*(void **)((char *)e + 0xFC)) : nullptr;
  if (!res || !readable((char *)res + 0x20, 12)) return 100;
  unsigned id0 = *(unsigned *)((char *)res + 0x20);
  for (int i = 0; i < g_ncache; i++) if (g_cache[i].res == res && g_cache[i].id == id0) return g_cache[i].pct;
  unsigned ids[16]; int n = 0; long file = -1;
  for (void *r = res; r && n < 16 && readable((char *)r + 0x20, 12); n++) {
    ids[n] = *(unsigned *)((char *)r + 0x20);
    if (readable((char *)r + 0x1A, 0x1E) && (*((unsigned char *)r + 0x1A) & 1)) file = (long)*(unsigned *)((char *)r + 0x34);   // (the file's root: see above)
    void *ph = *(void **)((char *)r + 0x28); r = ph ? deref(ph) : nullptr;
  }
  char path[16 * 9 + 1]; int k = 0;
  for (int i = n - 1; i >= 0; i--) {
    unsigned char b[4]; memcpy(b, &ids[i], 4); bool pr = true;
    for (int j = 0; j < 4; j++) if (b[j] < 0x20 || b[j] > 0x7E || b[j] == '/' || b[j] == ' ') pr = false;
    if (pr) for (int j = 0; j < 4; j++) path[k++] = (char)(b[j] >= 'A' && b[j] <= 'Z' ? b[j] + 32 : b[j]);
    else { static const char hx[] = "0123456789abcdef"; for (int j = 7; j >= 0; j--) path[k++] = hx[(ids[i] >> (4 * j)) & 15]; }
    if (i) path[k++] = '/';
  }
  path[k] = 0;
  char fkey[24] = "";
  if (file >= 0) { char d[12]; int m = 0; unsigned long v = (unsigned long)file; do d[m++] = (char)('0' + v % 10); while (v /= 10);
                   memcpy(fkey, "file:", 5); for (int i = 0; i < m; i++) fkey[5 + i] = d[m - 1 - i]; fkey[5 + m] = 0; }
  int pct = 100;
  for (int i = 0; i < g_nkeys; i++)
    if ((fkey[0] && !strcmp(fkey, g_keys[i])) || !strncmp(path, g_keys[i], strlen(g_keys[i]))) { pct = g_pcts[i]; break; }
  if (g_host->setting_int("fx_list", 0)) {
    if (file >= 0) g_host->log("effect_comfort: effect %s from file %ld (%d%%)", path, file, pct);
    else g_host->log("effect_comfort: effect %s (%d%%)", path, pct);
  }
  if (g_ncache == 512) g_ncache = 0;
  g_cache[g_ncache++] = { res, id0, pct };
  return pct;
}
static void read_effects() { g_nkeys = ec_read(g_host->dir ? g_host->dir : ".", g_keys, g_pcts, 256); g_ncache = 0; }
// values from d3d8types.h that the tree does not name
enum : unsigned { TSS_COLOROP = 1, TSS_COLORARG1 = 2, TSS_COLORARG2 = 3, TSS_ALPHAOP = 4, TSS_ALPHAARG1 = 5, TSS_ALPHAARG2 = 6,
                  TOP_DISABLE = 1, TOP_SELECTARG1 = 2, TOP_MODULATE = 4, TA_CURRENT = 1, TA_TFACTOR = 3, TA_SELECTMASK = 0xF,
                  RS_SRCBLEND = 19, RS_DESTBLEND = 20, RS_ALPHABLENDENABLE = 27, RS_TEXTUREFACTOR = 60, BLEND_ONE = 2, BLEND_SRCALPHA = 5 };

// ---- flashes
static unsigned g_last_light, g_last_tick;
static xikit::fn<decltype(&CDx::DrawFadeQuad)> prev_Fade;
static int __thiscall my_Fade(CDx *self, int a1, int a2) {
  unsigned c = (unsigned)a2, a = c >> 24;
  int lim = g_host->setting_int("flash_limit", 100), rise = g_host->setting_int("flash_rise_ms", 0);
  unsigned now = GetTickCount(), dt = now - g_last_tick; g_last_tick = now;
  if (c == 0x80808080u || a <= 0x80) { g_last_light = 0; return prev_Fade(self, a1, a2); }   // nothing, or a darkening
  unsigned r = (c >> 16) & 0xFF, g = (c >> 8) & 0xFF, b = c & 0xFF;
  r = r * lim / 100; g = g * lim / 100; b = b * lim / 100;
  unsigned m = r > g ? (r > b ? r : b) : (g > b ? g : b), light = m * a / 255;      // what the brightest channel adds
  if (rise > 0) {
    unsigned allowed = g_last_light + (unsigned)((unsigned long long)255 * (dt ? dt : 1) / (unsigned)rise);
    if (light > allowed && light) { r = r * allowed / light; g = g * allowed / light; b = b * allowed / light; light = allowed; }
  }
  g_last_light = light;
  if (lim < 100 || rise > 0) g_flashes++;
  return prev_Fade(self, a1, (int)(a << 24 | r << 16 | g << 8 | b));
}

// ---- effect intensity
struct Saved { unsigned stage, tf, op[2][3], nextop; bool on, tf_only; };
// false: leave the draw out (an element at 0 percent)
static bool begin_draw(IDirect3DDevice8 *dev, Saved *s) {
  s->on = false; s->tf_only = false;
  int k = g_host->setting_int("fx_intensity", 100);
  if (g_in_elem) k = k * g_elem_pct / 100;
  if (g_in_elem && k <= 0) { g_left_out++; return false; }
  if (k >= 100 || !(g_in_elem || g_host->setting_int("fx_all_blended", 0))) return true;
  unsigned v = 0;
  dev->GetRenderState(D3DRENDERSTATETYPE(RS_ALPHABLENDENABLE), &v); if (!v) return true;
  unsigned ps = 0; dev->GetPixelShader(&ps); if (ps) { g_skipped++; g_sk_ps++; return true; }
  if (!g_max_stages) { D3DCAPS8 caps = {}; g_max_stages = dev->GetDeviceCaps(&caps) >= 0 && caps.MaxTextureBlendStages ? caps.MaxTextureBlendStages : 1; }
  unsigned st = 0, op = 0; bool reads_tf = false, tf_mul = true;
  for (; st < 8 && st < g_max_stages; st++) {
    dev->GetTextureStageState(st, D3DTEXTURESTAGESTATETYPE(TSS_COLOROP), &op);
    if (op == TOP_DISABLE) break;
    unsigned aop = 0; dev->GetTextureStageState(st, D3DTEXTURESTAGESTATETYPE(TSS_ALPHAOP), &aop);
    static const unsigned args[4] = { TSS_COLORARG1, TSS_COLORARG2, TSS_ALPHAARG1, TSS_ALPHAARG2 };
    for (int a = 0; a < 4; a++) {
      unsigned arg = 0; dev->GetTextureStageState(st, D3DTEXTURESTAGESTATETYPE(args[a]), &arg);
      if ((arg & TA_SELECTMASK) != TA_TFACTOR) continue;
      reads_tf = true;
      unsigned o = a < 2 ? op : aop;                     // MODULATE, MODULATE2X, MODULATE4X (D3DTOP 4, 5, 6): a product
      if (o < TOP_MODULATE || o > TOP_MODULATE + 2 || (arg & ~TA_SELECTMASK)) tf_mul = false;
    }
  }
  // (25 Nov) the game's model draw (CYyModelDt, tree/src/CYyModelDt.cpp:285 and :773) multiplies stage 1 by the
  // texture factor (colour MODULATE2X, alpha MODULATE4X) and the effect elements put their colour and alpha there
  // (D3DRS_TEXTUREFACTOR in D3aElem, CMoDistModelElem, CMoDistMorphElem, CMoDamValueProgElem): the factor already
  // multiplies all the draw adds or covers. Such a draw is scaled through the factor itself (its colour for source
  // ONE, its alpha for SRCALPHA); where the 2X/4X product was already at full it can stay brighter than k (the
  // product is clamped after the factor). Any other use of the factor: left as it is.
  if (reads_tf && !tf_mul) { g_skipped++; g_sk_tf++; return true; }
  unsigned src = 0; dev->GetRenderState(D3DRENDERSTATETYPE(RS_SRCBLEND), &src);
  bool colour = src == BLEND_ONE;                                              // ONE: the colour is what is added
  if (!colour && src != BLEND_SRCALPHA) { g_skipped++; g_sk_blend++; g_sk_src = src; return true; }          // (no other source blend is the element's)
  if (reads_tf) {                                                              // through the draw's own factor
    dev->GetRenderState(D3DRENDERSTATETYPE(RS_TEXTUREFACTOR), &s->tf);
    unsigned t = s->tf, kk = (unsigned)(k < 0 ? 0 : k);
    auto sc = [&](int sh) { unsigned c = (t >> sh) & 0xFF; return (c * kk / 100) << sh; };
    unsigned nt = colour ? (t & 0xFF000000u) | sc(16) | sc(8) | sc(0) : (t & 0x00FFFFFFu) | sc(24);
    dev->SetRenderState(D3DRENDERSTATETYPE(RS_TEXTUREFACTOR), nt);
    s->on = true; s->tf_only = true; g_scaled++; g_sc_tf++;
    return true;
  }
  if (st == 0 || st >= g_max_stages || st >= 8) { g_skipped++; g_sk_stage++; return true; }
  s->stage = st; s->on = true;
  dev->GetRenderState(D3DRENDERSTATETYPE(RS_TEXTUREFACTOR), &s->tf);
  const unsigned ts[2][3] = { { TSS_COLOROP, TSS_COLORARG1, TSS_COLORARG2 }, { TSS_ALPHAOP, TSS_ALPHAARG1, TSS_ALPHAARG2 } };
  for (int i = 0; i < 2; i++) for (int j = 0; j < 3; j++) dev->GetTextureStageState(st, D3DTEXTURESTAGESTATETYPE(ts[i][j]), &s->op[i][j]);
  s->nextop = TOP_DISABLE; if (st + 1 < 8) dev->GetTextureStageState(st + 1, D3DTEXTURESTAGESTATETYPE(TSS_COLOROP), &s->nextop);
  unsigned f = (unsigned)(k < 0 ? 0 : k) * 255 / 100;
  dev->SetRenderState(D3DRENDERSTATETYPE(RS_TEXTUREFACTOR), f << 24 | f << 16 | f << 8 | f);
  dev->SetTextureStageState(st, D3DTEXTURESTAGESTATETYPE(TSS_COLOROP), colour ? TOP_MODULATE : TOP_SELECTARG1);
  dev->SetTextureStageState(st, D3DTEXTURESTAGESTATETYPE(TSS_COLORARG1), TA_CURRENT);
  dev->SetTextureStageState(st, D3DTEXTURESTAGESTATETYPE(TSS_COLORARG2), TA_TFACTOR);
  dev->SetTextureStageState(st, D3DTEXTURESTAGESTATETYPE(TSS_ALPHAOP), colour ? TOP_SELECTARG1 : TOP_MODULATE);
  dev->SetTextureStageState(st, D3DTEXTURESTAGESTATETYPE(TSS_ALPHAARG1), TA_CURRENT);
  dev->SetTextureStageState(st, D3DTEXTURESTAGESTATETYPE(TSS_ALPHAARG2), TA_TFACTOR);
  if (st + 1 < 8) dev->SetTextureStageState(st + 1, D3DTEXTURESTAGESTATETYPE(TSS_COLOROP), TOP_DISABLE);
  g_scaled++;
  return true;
}
static void end_draw(IDirect3DDevice8 *dev, const Saved *s) {
  if (!s->on) return;
  if (s->tf_only) { dev->SetRenderState(D3DRENDERSTATETYPE(RS_TEXTUREFACTOR), s->tf); return; }
  const unsigned ts[2][3] = { { TSS_COLOROP, TSS_COLORARG1, TSS_COLORARG2 }, { TSS_ALPHAOP, TSS_ALPHAARG1, TSS_ALPHAARG2 } };
  for (int i = 0; i < 2; i++) for (int j = 0; j < 3; j++) dev->SetTextureStageState(s->stage, D3DTEXTURESTAGESTATETYPE(ts[i][j]), s->op[i][j]);
  if (s->stage + 1 < 8) dev->SetTextureStageState(s->stage + 1, D3DTEXTURESTAGESTATETYPE(TSS_COLOROP), s->nextop);
  dev->SetRenderState(D3DRENDERSTATETYPE(RS_TEXTUREFACTOR), s->tf);
}
static XI_DEVICE_FN(DrawPrimitive) prev_DP;
static XI_DEVICE_FN(DrawIndexedPrimitive) prev_DIP;
static XI_DEVICE_FN(DrawPrimitiveUP) prev_DPUP;
static XI_DEVICE_FN(DrawIndexedPrimitiveUP) prev_DIPUP;
static int __stdcall my_DP(IDirect3DDevice8 *d, D3DPRIMITIVETYPE t, unsigned sv, unsigned n) {
  Saved s; if (!begin_draw(d, &s)) return 0; int r = prev_DP(d, t, sv, n); end_draw(d, &s); return r;
}
static int __stdcall my_DIP(IDirect3DDevice8 *d, D3DPRIMITIVETYPE t, unsigned mi, unsigned nv, unsigned si, unsigned n) {
  Saved s; if (!begin_draw(d, &s)) return 0; int r = prev_DIP(d, t, mi, nv, si, n); end_draw(d, &s); return r;
}
static int __stdcall my_DPUP(IDirect3DDevice8 *d, D3DPRIMITIVETYPE t, unsigned n, void *v, unsigned st) {
  Saved s; if (!begin_draw(d, &s)) return 0; int r = prev_DPUP(d, t, n, v, st); end_draw(d, &s); return r;
}
static int __stdcall my_DIPUP(IDirect3DDevice8 *d, D3DPRIMITIVETYPE t, unsigned mi, unsigned nv, unsigned n, void *ix, D3DFORMAT f, void *v, unsigned st) {
  Saved s; if (!begin_draw(d, &s)) return 0; int r = prev_DIPUP(d, t, mi, nv, n, ix, f, v, st); end_draw(d, &s); return r;
}
static xikit::fn<decltype(&YmElem_SetupDevice)> prev_Setup;
static xikit::fn<decltype(&YmElem_RestoreDevice)> prev_Restore;
static void enter_elem(void *e) { g_in_elem = 1; g_elem_pct = e && (g_nkeys || g_host->setting_int("fx_list", 0)) ? elem_percent(e) : 100; }
static int __thiscall my_Setup(void *e, int a1) { int r = prev_Setup(e, a1); enter_elem(e); return r; }
static int __thiscall my_Restore(uint16_t *e, short a4) { g_in_elem = 0; return prev_Restore(e, a4); }
extern "C" __declspec(dllexport) void xikit_mod_frame(void *) {
  static unsigned n;
  if (++n % 1800 == 0 && (g_scaled || g_skipped || g_flashes || g_left_out))
    g_host->log("effect_comfort: %ld effect draws scaled (%ld through their own texture factor), %ld left as they are (pixel shader %ld, own stages use the texture factor otherwise %ld, no free stage %ld, source blend %ld, the last D3DBLEND %u), %ld left out, %ld flash frames limited; fx_intensity %d, flash_limit %d",
                g_scaled, g_sc_tf, g_skipped, g_sk_ps, g_sk_tf, g_sk_stage, g_sk_blend, g_sk_src, g_left_out, g_flashes, g_host->setting_int("fx_intensity", 100), g_host->setting_int("flash_limit", 100)),
    g_scaled = g_skipped = g_left_out = g_flashes = g_sk_ps = g_sk_tf = g_sk_stage = g_sk_blend = g_sc_tf = 0;
}
extern "C" __declspec(dllexport) void xikit_mod_settings(void) { read_effects(); }
extern "C" __declspec(dllexport) int xikit_mod_init(const XikitHost *host) {
  g_host = host;
  host->declare_int("fx_list", 0, 0, 1, "1: log each effect's path (for effects.txt) when it is first drawn");
  host->declare_int("flash_limit", 100, 0, 100, "percent of the light a full-screen flash adds (100: the game's; fades to dark are not changed)");
  host->declare_int("flash_rise_ms", 0, 0, 2000, "0: off; else the added light rises from nothing to full in no less than this many ms");
  host->declare_int("fx_intensity", 100, 0, 100, "percent of what each effect draw adds or covers (100: the game's)");
  host->declare_int("fx_all_blended", 0, 0, 1, "1: apply fx_intensity to every blended draw, the interface too (for checking)");
  read_effects();
  int r = XI_HOOK(host, CDx::DrawFadeQuad, my_Fade, prev_Fade);
  r |= XI_HOOK(host, YmElem_SetupDevice, my_Setup, prev_Setup);
  r |= XI_HOOK(host, YmElem_RestoreDevice, my_Restore, prev_Restore);
  r |= XI_DEVICE_HOOK(host, DrawPrimitive, my_DP, prev_DP);
  r |= XI_DEVICE_HOOK(host, DrawIndexedPrimitive, my_DIP, prev_DIP);
  r |= XI_DEVICE_HOOK(host, DrawPrimitiveUP, my_DPUP, prev_DPUP);
  r |= XI_DEVICE_HOOK(host, DrawIndexedPrimitiveUP, my_DIPUP, prev_DIPUP);
  return r;
}
