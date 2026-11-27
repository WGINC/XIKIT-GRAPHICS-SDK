/* host.c -- a stand-in for pol.exe to test xikit under Wine (test_xikit.py runs it).

   It maps the real FFXiMain.dll without running its DllMain (DONT_RESOLVE_DLL_REFERENCES; the loader still
   applies its relocations), optionally after occupying 0x10000000 so the DLL is loaded elsewhere, gives the game a
   fake CDx whose device has a fake vtable, loads xikit.dll and then plays the render thread: it calls the
   device's Present (which the kit hooks) and calls game functions through their original entries. Each check
   prints "ok: ..." or "FAIL: ...". */
#define COBJMACROS
#include <windows.h>
#include <d3d8.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include <math.h>

#define G_PCDX 0x1045666Cu
/* an analysed address -> the mapped game's, as the kit translates it: on another build its manifest's !shift ranges
   (kit/xikit/manifest_for_build.py; code and, since build 6AE818B4, data). !no_swap: that build swaps nothing in, unless
   the manifest also says !swap_set (15 Nov): then the functions of flag 32 keep the game's code and the rest swap;
   g_keep32 is the first of them, with its entry's 5 bytes in that build (EXPECTED's bytes 4-8). */
static uint32_t g_hrel; static int32_t g_hshift[1 + 3 * 64]; static int g_no_swap, g_swap_set;
static uint32_t g_keep32; static uint8_t g_keep32_bytes[5];
static uintptr_t ga(uint32_t a) {
  int32_t d = 0;
  for (int i = 0; i < g_hshift[0]; i++) if (a >= (uint32_t)g_hshift[1 + 3 * i] && a < (uint32_t)g_hshift[2 + 3 * i]) { d = g_hshift[3 + 3 * i]; break; }
  return (uintptr_t)a + g_hrel + d;
}
static void load_shifts(HMODULE g) {
  IMAGE_NT_HEADERS *nt = (IMAGE_NT_HEADERS *)((char *)g + ((IMAGE_DOS_HEADER *)g)->e_lfanew);
  char p[64], line[512]; snprintf(p, sizeof p, "xikit_manifest_%08lX.txt", (unsigned long)nt->FileHeader.TimeDateStamp);
  FILE *f = fopen(p, "r"); if (!f) return;
  while (fgets(line, sizeof line, f)) { unsigned lo, hi; int d;
    if (!strncmp(line, "!no_swap", 8)) g_no_swap = 1;
    if (!strncmp(line, "!swap_set", 9)) g_swap_set = 1;
    { unsigned rva; int fl; char ex[64], hex[64];
      if (!g_keep32 && line[0] != '#' && line[0] != '!' && sscanf(line, "%x %d %63s %63s", &rva, &fl, ex, hex) == 4 && (fl & 32) && strlen(hex) == 40) {
        g_keep32 = 0x10000000u + rva;
        for (int k = 0; k < 5; k++) { unsigned b; sscanf(hex + 8 + 2 * k, "%2x", &b); g_keep32_bytes[k] = (uint8_t)b; } } }
    if (sscanf(line, "!shift %x %x %d", &lo, &hi, &d) == 3 && g_hshift[0] < 64) { int i = g_hshift[0]++; g_hshift[1 + 3 * i] = (int32_t)lo; g_hshift[2 + 3 * i] = (int32_t)hi; g_hshift[3 + 3 * i] = d; } }
  fclose(f);
  if (g_swap_set) g_no_swap = 0;
  printf("note: build %08lX: %d shift ranges%s from %s\n", (unsigned long)nt->FileHeader.TimeDateStamp, g_hshift[0], g_no_swap ? ", no_swap" : g_swap_set ? ", swap_set" : "", p);
}
#define SETCOLOR 0x100A4830u          /* CXiSkeletonActor::SetColor: this+0x660 = arg */
#define GETCOLOR 0x100A4840u          /* CXiSkeletonActor::GetColor: returns this+0x660 */
#define GAMMA    0x1025D750u          /* FontGlyphCache_GetDevice: returns [g_pCDx+0xC] (mov eax, [g_pCDx]: a relocated operand at +1) */
#define PUSHRT1  0x1000A800u          /* CDx::PushRenderTargetRet1: calls the original CDx_PushRenderTarget, returns 1 */
#define FRAME_RENDER 0x10011A00u      /* Frame_Render: manifest flag 4 (its compared gate trials ran 53 of 1424 instructions) */

typedef void (__attribute__((thiscall)) *SetColorFn)(void *, uint32_t);
typedef uint32_t (__attribute__((thiscall)) *GetColorFn)(void *);
typedef void *(*GammaFn)(void);
typedef char (__attribute__((thiscall)) *PushRt1Fn)(void *, int, int, int);

static int presents, fails;
/* three PeekMessage calls a frame inside the device's Present: kernel_calls=2 must count them on the render thread
   (Wine's win32u NtUserPeekMessage is an x86 system-call stub) */
static HRESULT __stdcall fake_present(void *d, const RECT *a, const RECT *b, HWND w, const void *r) { (void)d; (void)a; (void)b; (void)w; (void)r; presents++;
  MSG m; for (int k = 0; k < 3; k++) PeekMessageA(&m, NULL, 0, 0, PM_NOREMOVE); return 0; }
static void __stdcall other_slot(void) { printf("FAIL: a device method other than Present was called\n"); ExitProcess(3); }
static void *g_vtbl[97];
static struct { void **vt; } g_dev = { g_vtbl };
/* trace pictures (profile mode): a 64x32 X8R8G8B8 back buffer the host paints each frame, read back by the kit
   through GetBackBuffer, CreateImageSurface, CopyRects and the surface's GetDesc/LockRect/UnlockRect */
#define PW 64
#define PH 32
typedef struct { void **vt; uint32_t *pix; } FakeSurf;
static uint32_t g_bbpix[PW * PH], g_imgpix[PW * PH]; static void *g_svt[11];
static FakeSurf g_bb = { g_svt, g_bbpix }, g_img = { g_svt, g_imgpix };
static ULONG __stdcall s_release(void *t) { (void)t; return 0; }
static HRESULT __stdcall s_desc(void *t, uint32_t *d) { (void)t; memset(d, 0, 32); d[0] = 22; d[6] = PW; d[7] = PH; return 0; }
static HRESULT __stdcall s_lock(void *t, int32_t *lr, const RECT *r, DWORD fl) { (void)r; (void)fl; lr[0] = PW * 4; lr[1] = (int32_t)(uintptr_t)((FakeSurf *)t)->pix; return 0; }
static HRESULT __stdcall s_unlock(void *t) { (void)t; return 0; }
static HRESULT __stdcall d_getbb(void *d, UINT i, UINT ty, void **pp) { (void)d; (void)i; (void)ty; *pp = &g_bb; return 0; }
static HRESULT __stdcall d_createimg(void *d, UINT w, UINT h, UINT f, void **pp) { (void)d; (void)w; (void)h; (void)f; *pp = &g_img; return 0; }
static HRESULT __stdcall d_copyrects(void *d, void *src, const RECT *r, UINT n, void *dst, const POINT *pt) { (void)d; (void)r; (void)n; (void)pt; memcpy(((FakeSurf *)dst)->pix, ((FakeSurf *)src)->pix, sizeof g_bbpix); return 0; }
static uint8_t *g_paint_site;
static int tcl_calls, bs_calls;     /* facts mode: the device methods CDx::TestCooperativeLevel and CDx::BeginScene call (slots 3, 34) */
static void __stdcall d_texmethod(void) {}
static void (__stdcall *const g_texvt[19])(void) = { d_texmethod, d_texmethod, d_texmethod, d_texmethod, d_texmethod, d_texmethod, d_texmethod,
  d_texmethod, d_texmethod, d_texmethod, d_texmethod, d_texmethod, d_texmethod, d_texmethod, d_texmethod, d_texmethod, d_texmethod, d_texmethod, d_texmethod };
static uint32_t g_faketex[4] = { 0 };   /* profile mode: resources created through the hooked device (d3dprof's wrappers log them); [0]: its vtable, set in main */
static HRESULT __stdcall d_createtex(void *d, UINT w, UINT h, UINT lv, DWORD us, DWORD fmt, DWORD pool, void **pp) { (void)d; (void)w; (void)h; (void)lv; (void)us; (void)fmt; (void)pool; *pp = g_faketex; return 0; }
static HRESULT __stdcall d_createvs(void *d, const DWORD *decl, const DWORD *fn, DWORD *h, DWORD usage) { (void)d; (void)decl; (void)fn; (void)usage; *h = 0x1234; return 0; }
static HRESULT __stdcall d_tcl(void *d) { (void)d; tcl_calls++; return 0; }
static HRESULT __stdcall d_beginscene(void *d) { (void)d; bs_calls++; return 0; }   /* GetColor's entry: the band it "draws" is bright while it is swapped */
static uint8_t g_cdx[0x1000];

/* (staterun) a stand-in actor's vtable +0xCC: the name the game draws (GetEnglishName's slot) */
static const char *__attribute__((thiscall)) actor_drawn_name(void *self) { (void)self; return "Alice"; }
/* (staterun, xianim) a stand-in actor's vtable slot 0, GetRuntimeClass, as CYyObject_IsKindOf (0x1002C8F0) calls it:
   the player's stand-in is a CXiSkeletonActor (the game's own class descriptor 0x10330EBC); the other one is a class
   whose chain ends at once (+8 NULL), like a door's actor (27 Nov: the owner's crash at prishe.dll+0x10F20) */
static uint8_t g_other_class[16];
static void *__attribute__((thiscall)) runtime_class_skeleton(void *self) { (void)self; return (void *)ga(0x10330EBCu); }
static void *__attribute__((thiscall)) runtime_class_other(void *self) { (void)self; return g_other_class; }
static const char *__attribute__((thiscall)) actor_drawn_name_bob(void *self) { (void)self; return "Bob"; }
/* (prishert) a stand-in actor's vtable slot that returns 0 (GetModelPartWord's +0x3B4 test: the record path) */
static int __attribute__((thiscall)) vt_zero(void *self) { (void)self; return 0; }
static void check(int cond, const char *what) { printf("%s: %s\n", cond ? "ok" : "FAIL", what); if (!cond) fails++; }
static void paint(void) {        /* the top band animates smoothly (a triangle wave); the bottom band is GetColor's */
  int t = presents % 400; uint32_t a = (uint32_t)(t < 200 ? t : 400 - t), b = g_paint_site && g_paint_site[0] == 0xE9 ? 200 : 50;
  for (int y = 0; y < PH; y++) for (int x = 0; x < PW; x++) g_bbpix[y * PW + x] = y < PH / 2 ? a * 0x010101u : (b << 16);
}
/* (staterun, 27 Nov) call a game entry so that it returns to a chosen game address, as if that site had called it:
   the site's first 5 bytes become a jmp back here for the call, then are put back. ECX and up to one stack argument. */
uintptr_t cf_saved_esp;
extern void cf_stub(uintptr_t entry, uintptr_t ret_site, void *ecx_, int nargs, uint32_t arg);
extern char cf_back[];
__asm__(".globl _cf_stub\n_cf_stub:\n"
        "  pushl %ebp\n  movl %esp, %ebp\n  pushl %ebx\n  pushl %esi\n  pushl %edi\n"
        "  movl %esp, _cf_saved_esp\n"
        "  movl 16(%ebp), %ecx\n"
        "  cmpl $0, 20(%ebp)\n  je 1f\n  pushl 24(%ebp)\n"
        "1:\n  pushl 12(%ebp)\n  jmp *8(%ebp)\n"
        ".globl _cf_back\n_cf_back:\n"
        "  movl _cf_saved_esp, %esp\n  popl %edi\n  popl %esi\n  popl %ebx\n  popl %ebp\n  ret\n");
static void call_returning_to(uintptr_t entry, uintptr_t site, void *ecx_, int nargs, uint32_t arg) {
  uint8_t save[5]; DWORD old; VirtualProtect((void *)site, 5, PAGE_EXECUTE_READWRITE, &old); memcpy(save, (void *)site, 5);
  uint8_t *p = (uint8_t *)site; p[0] = 0xE9; *(int32_t *)(p + 1) = (int32_t)((uintptr_t)cf_back - (site + 5));
  FlushInstructionCache(GetCurrentProcess(), (void *)site, 5);
  cf_stub(entry, site, ecx_, nargs, arg);
  memcpy((void *)site, save, 5); VirtualProtect((void *)site, 5, old, &old); FlushInstructionCache(GetCurrentProcess(), (void *)site, 5);
}
/* (29 Nov) the game's area allocator (Mem_AllocFromArea) is not set up in this host: while a test runs game code that
   allocates, its allocate and free entries (cdecl, tree/src/MathVector.cpp, MemAllocDefault.cpp) jump to the host's */
static void *__cdecl t_alloc2(int n, int a) { (void)a; return calloc(1, n > 0 ? n : 1); }
static void *__cdecl t_alloc1(int n) { return calloc(1, n > 0 ? n : 1); }
static void __cdecl t_free(void *p) { free(p); }
static const uint32_t k_mem_fn[4] = { 0x10028640u, 0x1002C890u, 0x10028700u, 0x1002C8B0u };   /* Mem_AllocObject, Mem_AllocDefault, Mem_FreeObject, thunk_sub_10028AA0 */
static uint8_t g_mem_save[4][5];
static void host_allocator(int on) {
  void *to[4] = { (void *)t_alloc2, (void *)t_alloc1, (void *)t_free, (void *)t_free };
  for (int i = 0; i < 4; i++) {
    uint8_t *p = (uint8_t *)ga(k_mem_fn[i]); DWORD old; VirtualProtect(p, 5, PAGE_EXECUTE_READWRITE, &old);
    if (on) { memcpy(g_mem_save[i], p, 5); p[0] = 0xE9; *(int32_t *)(p + 1) = (int32_t)((uintptr_t)to[i] - ((uintptr_t)p + 5)); }
    else memcpy(p, g_mem_save[i], 5);
    VirtualProtect(p, 5, old, &old); FlushInstructionCache(GetCurrentProcess(), p, 5);
  }
}
static void present(int n) { for (int i = 0; i < n; i++) { paint(); ((HRESULT (__stdcall *)(void *, const RECT *, const RECT *, HWND, const void *))g_dev.vt[15])(&g_dev, 0, 0, 0, 0); } }
static void touch_ini(const char *ini, const char *body) {
  Sleep(20); FILE *f = fopen(ini, "w"); fputs(body, f); fclose(f);
}

static jmp_buf jb; static volatile int armed; static uintptr_t landing_sp;
static void landing(void) { longjmp(jb, 1); }
static LONG CALLBACK host_veh(EXCEPTION_POINTERS *e) {
  if (armed && e->ExceptionRecord->ExceptionCode == EXCEPTION_ACCESS_VIOLATION) {
    armed = 0; e->ContextRecord->Eip = (DWORD)(uintptr_t)landing; e->ContextRecord->Esp = (DWORD)landing_sp;
    return EXCEPTION_CONTINUE_EXECUTION;
  }
  return EXCEPTION_CONTINUE_SEARCH;
}

/* ------------------------------------------------------------------------------------------------ measure mode
   The game's import table filled as the loader would (this load mode leaves it unfilled), then the kit's call timing
   wraps its slots (imports=2) and three call sites in game functions this host can run (callsites=1, from the test's
   own xikit_measure.txt): a dot product's x87 result through the wrapped call (0x10027600 -> 0x10027530), a thiscall
   copy (0x1001E3B0 -> 0x10026EB0, ECX in, ret 4) and a thiscall with no stack arguments (0x100142A0 -> 0x10010D00) */
static void fill_iat(HMODULE g) {
  IMAGE_NT_HEADERS *nt = (IMAGE_NT_HEADERS *)((char *)g + ((IMAGE_DOS_HEADER *)g)->e_lfanew);
  IMAGE_DATA_DIRECTORY dd = nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
  int n = 0, miss = 0;
  for (IMAGE_IMPORT_DESCRIPTOR *d = (IMAGE_IMPORT_DESCRIPTOR *)((char *)g + dd.VirtualAddress); d->Name; d++) {
    HMODULE m = LoadLibraryA((char *)g + d->Name);
    uint32_t *names = (uint32_t *)((char *)g + (d->OriginalFirstThunk ? d->OriginalFirstThunk : d->FirstThunk)), *iat = (uint32_t *)((char *)g + d->FirstThunk);
    DWORD old; VirtualProtect(iat, 4096, PAGE_READWRITE, &old);
    for (int i = 0; names[i]; i++) {
      FARPROC f = !m ? NULL : (names[i] & 0x80000000u) ? GetProcAddress(m, (LPCSTR)(uintptr_t)(names[i] & 0xFFFF)) : GetProcAddress(m, (char *)g + names[i] + 2);
      if (f) { iat[i] = (uint32_t)(uintptr_t)f; n++; } else miss++;
    }
  }
  printf("note: filled %d import slots (%d not found)\n", n, miss);
}
static uint32_t g_rel_m;
static void *iat_fn(uint32_t ea) { return *(void **)ga(ea); }   /* (ga: the load delta and the build's shift for that address, data ranges included; until 16 Nov the delta only) */
static uint32_t g_slot_sleep, g_slot_gfa, g_slot_tgt, g_slot_dispatch, g_slot_heapalloc, g_slot_heapfree;
static volatile int g_wndproc_sleeps, g_jump_out;
static jmp_buf g_mjb;
static volatile int g_wndproc_in;
static LRESULT CALLBACK m_wndproc(HWND w, UINT msg, WPARAM wp, LPARAM lp) {
  if (msg == WM_USER + 1) { g_wndproc_in++; ((void (WINAPI *)(DWORD))iat_fn(g_slot_sleep))(1); g_wndproc_sleeps++; if (g_jump_out) longjmp(g_mjb, 1); return 77; }
  return DefWindowProcA(w, msg, wp, lp);
}
static volatile int g_other_stop; static volatile LONG g_other_allocs;
static DWORD WINAPI m_other(LPVOID u) {      /* another thread: heap calls through the game's slots, and CPU to sample */
  (void)u; HANDLE hp = GetProcessHeap();
  while (!g_other_stop) {
    for (int i = 0; i < 200; i++) {
      void *p = ((LPVOID (WINAPI *)(HANDLE, DWORD, SIZE_T))iat_fn(g_slot_heapalloc))(hp, 0, 32);
      ((BOOL (WINAPI *)(HANDLE, DWORD, LPVOID))iat_fn(g_slot_heapfree))(hp, 0, p); InterlockedIncrement(&g_other_allocs);
    }
    volatile double x = 1; for (int i = 0; i < 20000; i++) x = x * 1.0000001 + 0.5;
  }
  return 0;
}
static int measure_run(HMODULE g, uint32_t rel) {
  g_rel_m = rel;
  g_slot_sleep = (uint32_t)strtoul(getenv("SLOT_SLEEP"), NULL, 16); g_slot_gfa = (uint32_t)strtoul(getenv("SLOT_GFA"), NULL, 16);
  g_slot_tgt = (uint32_t)strtoul(getenv("SLOT_TGT"), NULL, 16); g_slot_dispatch = (uint32_t)strtoul(getenv("SLOT_DISPATCH"), NULL, 16);
  g_slot_heapalloc = (uint32_t)strtoul(getenv("SLOT_HEAPALLOC"), NULL, 16); g_slot_heapfree = (uint32_t)strtoul(getenv("SLOT_HEAPFREE"), NULL, 16);
  void *sleep0 = iat_fn(g_slot_sleep);
  uint8_t *lsite = (uint8_t *)(uintptr_t)ga(0x10027606u); int32_t lrel0; memcpy(&lrel0, lsite + 1, 4);   /* the dot product's call */
  static float ment[0x40];                       /* frames_player=1: a fake entity in slot 3 of the table, moving 0.25 a frame in x */
  *(int16_t *)(uintptr_t)ga(0x10485F7Au) = 3; *(uint32_t *)(uintptr_t)(ga(0x10480AF0u) + 12) = (uint32_t)(uintptr_t)ment;
  touch_ini("xikit.ini", "[xikit]\nlog_folder=0\nswap=0\ncount_calls=0\nreport_every=60\nhotkey=0\nframes=1\nframes_player=1\nimports=2\ncallsites=1\nsample=3\nsample_other_ms=2\nsysstats=1\nenv=1\n");
  if (!LoadLibraryA("xikit.dll")) { printf("FAIL: xikit.dll not loaded (%lu)\n", GetLastError()); return 2; }
  for (int t = 0; t < 400 && g_dev.vt == g_vtbl; t++) Sleep(50);
  check(g_dev.vt != g_vtbl, "measure: the kit hooked the device");
  for (int t = 0; t < 500 && iat_fn(g_slot_sleep) == sleep0; t++) { present(1); Sleep(20); }   /* the kit's measure_start runs after its hook; the next frame puts the wrapped calls in place */
  check(iat_fn(g_slot_sleep) != sleep0, "imports=2: the game's Sleep slot now goes through the kit's stub");
  WNDCLASSA wc; memset(&wc, 0, sizeof wc); wc.lpfnWndProc = m_wndproc; wc.hInstance = GetModuleHandleA(NULL); wc.lpszClassName = "xm"; RegisterClassA(&wc);
  HWND w = CreateWindowA("xm", "xm", 0, 0, 0, 10, 10, NULL, NULL, wc.hInstance, NULL);
  { MSG cm; while (PeekMessageA(&cm, NULL, 0, 0, PM_REMOVE)) DispatchMessageA(&cm); }   /* the window's own creation messages first
     (twice, before this, the first dispatch of the test's message returned 0 under Wine; the line below says why if it recurs) */
  HANDLE oth = CreateThread(NULL, 0, m_other, NULL, 0, NULL);
  typedef float (*LenFn)(const float *); typedef void (__attribute__((thiscall)) *CopyFn)(void *, const void *); typedef char (__attribute__((thiscall)) *IncFn)(void *);
  LenFn len = (LenFn)(uintptr_t)ga(0x10027600u); CopyFn cp = (CopyFn)(uintptr_t)ga(0x1001E3B0u); IncFn inc = (IncFn)(uintptr_t)ga(0x100142A0u);
  int okf = 1, okc = 1, oki = 1, okle = 1, okd = 1;
  for (int f = 0; f < 300; f++) {
    ((void (WINAPI *)(DWORD))iat_fn(g_slot_sleep))(2);
    DWORD t = ((DWORD (WINAPI *)(void))iat_fn(g_slot_tgt))(); (void)t;
    SetLastError(0);
    DWORD a = ((DWORD (WINAPI *)(LPCSTR))iat_fn(g_slot_gfa))("C:\\no\\such\\file.xyz");
    if (a != INVALID_FILE_ATTRIBUTES || (GetLastError() != ERROR_FILE_NOT_FOUND && GetLastError() != ERROR_PATH_NOT_FOUND)) okle = 0;
    float v[3] = {3.0f, 4.0f, 0.0f}; float r = len(v); if (r < 4.999f || r > 5.001f) okf = 0;
    uint8_t obj[0x40]; memset(obj, 0, sizeof obj); uint32_t src[3] = {0x11111111u, 0x22222222u, (uint32_t)f}; cp(obj, src);
    if (memcmp(obj + 0x24, src, 12)) okc = 0;
    uint16_t o2[4] = {5, 0, 0, 9}; char rr = inc(o2); if (rr != 1 || o2[2] != 1 || o2[3] != 0) oki = 0;
    MSG pm; PostMessageA(w, WM_USER + 1, 0, 0); int got = PeekMessageA(&pm, w, WM_USER + 1, WM_USER + 1, PM_REMOVE);
    int before = g_wndproc_sleeps;
    LRESULT lr = got ? ((LRESULT (WINAPI *)(const MSG *))iat_fn(g_slot_dispatch))(&pm) : -1;
    if (lr != 77 || g_wndproc_sleeps != before + 1) { if (okd) printf("  (DispatchMessageA returned %ld, frame %d, message %d %04X hwnd %p/%p, window procedure entered %d, error %lu)\n", (long)lr, f, got, pm.message, (void *)pm.hwnd, (void *)w, g_wndproc_in, GetLastError()); okd = 0; }
    if (f == 100) { FILE *mk = fopen("xikit_mark.txt", "w"); if (mk) { fputs("plaza\n", mk); fclose(mk); } }   /* mark.bat's file */
    if (f == 200) for (int i = 0; i < 700; i++) len(v);   /* 700 calls in one frame: over callsite_max (500), put back */
    if (f == 150) {                                 /* a wrapped call left by longjmp: its entry must be dropped later */
      g_jump_out = 1;
      PostMessageA(w, WM_USER + 1, 0, 0);
      if (PeekMessageA(&pm, w, WM_USER + 1, WM_USER + 1, PM_REMOVE) && !setjmp(g_mjb)) ((LRESULT (WINAPI *)(const MSG *))iat_fn(g_slot_dispatch))(&pm);
      g_jump_out = 0;
    }
    ment[1] += 0.25f;                              /* +0x04 */
    present(1);
  }
  { int32_t now; memcpy(&now, lsite + 1, 4); FILE *lg = fopen("xikit.log", "r"); char l[600]; int said = 0;
    if (lg) { while (fgets(l, sizeof l, lg)) if (strstr(l, "call site 10027606") && strstr(l, "put back")) said = 1; fclose(lg); }
    check(said && now == lrel0, "callsites: the site called 700 times in one frame was put back (its call instruction is the game's again) and logged"); }
  check(okf, "callsites: the dot product's x87 result comes back through the wrapped call (|(3,4,0)| = 5)");
  check(okc, "callsites: a thiscall copy through the wrapped call (ECX and the stack argument intact, ret 4)");
  check(oki, "callsites: a thiscall without stack arguments (ECX intact, AL returned)");
  check(okle, "imports: the last-error value a wrapped call set is what the caller reads");
  check(okd, "imports: DispatchMessageA through its slot reaches the window procedure, which calls Sleep through its slot (nested), and returns its value");
  {   /* the clock test's arithmetic (measure_read.py): Frame_Render's this with the step +0x28 = 1.0; a reference segment
         moving 0.25 a frame (a tick a frame) and a test segment moving 15 a second of real time: the ratio must be 1 */
    static float cam[0x40]; cam[0x28 / 4] = 1.0f; *(uint32_t *)(uintptr_t)ga(0x104568FCu) = (uint32_t)(uintptr_t)cam;
    /* (28 Nov) the camera object at [this+0x50]: its eye +0x44 moves 0.5 a frame in x below (the frame log's cex..ctz) */
    static float vcam[0x20]; vcam[0x50 / 4] = 7.0f; *(uint32_t *)&cam[0x50 / 4] = (uint32_t)(uintptr_t)vcam;
    LARGE_INTEGER fq, a, b, last; QueryPerformanceFrequency(&fq);
    for (int seg = 0; seg < 2; seg++) {
      FILE *mk = fopen("xikit_mark.txt", "w"); if (mk) { fputs(seg ? "clock test\n" : "clock reference\n", mk); fclose(mk); }
      for (int i = 0; i < 40; i++) present(1);                       /* the kit reads the mark within 30 frames */
      QueryPerformanceCounter(&a); last = a;
      do { QueryPerformanceCounter(&b);
           ment[1] += seg ? (float)(15.0 * (double)(b.QuadPart - last.QuadPart) / (double)fq.QuadPart) : 0.25f; last = b;
           vcam[0x44 / 4] += 0.5f; present(1); Sleep(7); } while ((double)(b.QuadPart - a.QuadPart) / (double)fq.QuadPart < 9.0);
    }
    FILE *mk = fopen("xikit_mark.txt", "w"); if (mk) { fputs("clock done\n", mk); fclose(mk); }
  }
  g_other_stop = 1; WaitForSingleObject(oth, 5000);
  for (int f = 0; f < 70; f++) present(1);           /* a report window after the work */
  Sleep(1500);                                      /* the writer thread's last flush; the sampler and sys threads' lines */
  char name[MAX_PATH], line[2048]; DWORD pid = GetCurrentProcessId();
  snprintf(name, sizeof name, "xikit_frames_%lu.csv", pid); FILE *fr = fopen(name, "r"); int rows = 0, pace = 0, waitcol = 0;
  if (fr) { while (fgets(line, sizeof line, fr)) { if (line[0] >= '0' && line[0] <= '9') { rows++; char *c = line; for (int k = 0; k < 34 && c; k++) c = strchr(c + 1, ',');   /* field 34: wait_ms (after frames_player's 6 and the camera's 6) */ if (c && atof(c + 1) > 1.5) waitcol++; }
                                                  if (strstr(line, ",p28,p2c,p30,")) pace = 1; } fclose(fr); }
  printf("  (frames rows %d, header %d, rows with wait_ms > 1.5 %d)\n", rows, pace, waitcol);
  check(rows >= 300 && pace, "frames=1: xikit_frames_<pid>.csv has a line per frame and the pacing columns");
  { FILE *fp = fopen(name, "r"); char l2[2048]; int col = -1, steps = 0, good = 0; float prev = -1;
    if (fp) { while (fgets(l2, sizeof l2, fp)) {
        if (!strncmp(l2, "frame,", 6)) { int c = 0; for (char *t = strtok(l2, ",\n"); t; t = strtok(NULL, ",\n"), c++) if (!strcmp(t, "me4")) col = c; continue; }
        if (col < 0 || l2[0] < '0' || l2[0] > '9') continue;
        int c = 0; char *t = l2, *f = NULL; for (char *q = l2; ; q++) { if (*q == ',' || !*q) { if (c == col) { f = t; break; } c++; t = q + 1; if (!*q) break; } }
        if (!f || *f == ',') continue;
        uint32_t u = (uint32_t)strtoul(f, NULL, 16); float v; memcpy(&v, &u, 4);
        if (prev >= 0 && v > prev) { steps++; if (v - prev > 0.24f && v - prev < 0.26f) good++; } prev = v; } fclose(fp); }
    printf("  (frames_player: me4 column %d, %d increases, %d of them by 0.25)\n", col, steps, good);
    check(col > 0 && good >= 295, "frames_player=1: the entity's +0x04 in the frame log moves by the 0.25 a frame the host writes"); }
  { FILE *fp = fopen(name, "r"); char l2[2048]; int col = -1, tcol = -1, steps = 0, good = 0, tgt = 0; float prev = -1;
    if (fp) { while (fgets(l2, sizeof l2, fp)) {
        if (!strncmp(l2, "frame,", 6)) { int c = 0; for (char *t = strtok(l2, ",\n"); t; t = strtok(NULL, ",\n"), c++) { if (!strcmp(t, "cex")) col = c; if (!strcmp(t, "ctx")) tcol = c; } continue; }
        if (col < 0 || l2[0] < '0' || l2[0] > '9') continue;
        char *fld[64]; int nf = 0; char *q = l2; fld[nf++] = q; for (; *q && nf < 64; q++) if (*q == ',') { *q = 0; fld[nf++] = q + 1; }
        if (col >= nf || !*fld[col]) continue;
        uint32_t u = (uint32_t)strtoul(fld[col], NULL, 16); float v; memcpy(&v, &u, 4);
        if (tcol < nf && *fld[tcol]) { uint32_t w = (uint32_t)strtoul(fld[tcol], NULL, 16); float tv; memcpy(&tv, &w, 4); if (tv == 0.0f) tgt++; }
        if (prev >= 0 && v > prev) { steps++; if (v - prev > 0.49f && v - prev < 0.51f) good++; } prev = v; } fclose(fp); }
    printf("  (camera: cex column %d, %d increases, %d of them by 0.5)\n", col, steps, good);
    check(col > 0 && good >= 500 && good >= steps * 9 / 10, "frames_player=1: the camera's eye (+0x44 of [this+0x50]) in the frame log moves by the 0.5 a frame the host writes"); }
  { FILE *lg = fopen("xikit.log", "r"); char l[600]; int said = 0;
    if (lg) { while (fgets(l, sizeof l, lg)) if (strstr(l, "measure: mark 1 at frame") && strstr(l, "(mark.bat): plaza")) said = 1; fclose(lg); }
    check(said && GetFileAttributesA("xikit_mark.txt") == INVALID_FILE_ATTRIBUTES, "frames=1: xikit_mark.txt (mark.bat) is a mark, with its name, and is deleted"); }
  check(waitcol >= 250, "frames=1: the render thread's wrapped Sleep(2) each frame shows in its wait_ms column");
  snprintf(name, sizeof name, "xikit_probes_%lu.csv", pid); FILE *pr = fopen(name, "r"); int sleep_r = 0, heap_o = 0, site_r = 0;
  if (pr) { while (fgets(line, sizeof line, pr)) { if (strstr(line, ",Sleep,") && strstr(line, ",render,")) sleep_r = 1; if (strstr(line, ",HeapAlloc,") && strstr(line, ",other,")) heap_o = 1;
                                                  if (strstr(line, ",S,") && strstr(line, ",render,")) site_r++; } fclose(pr); }
  check(sleep_r && heap_o && site_r >= 3, "imports/callsites: xikit_probes_<pid>.csv has Sleep on the render thread, HeapAlloc on the other, and the three call sites");
  printf("%s\n", "measure: done (the reader checks the raw samples)");
  return 0;
}


/* ------------------------------------------------------------------------------------------------ texmod mode
   sdk/examples/texture_replace.dll through the kit, with the game's own TexObj_Create (0x10039A80) and TexObj_Upload
   (0x10039E50, hooked by the mod) on a real Direct3D 8 device. Three texture objects (docs/FORMATS.md 5.3: name +0x0C,
   pixels +0x20, width/height +0x24/+0x26, bpp +0x28, format +0x29, levels +0x2A, class (+0x2C >> 4) 9 = uncompressed),
   8x8 32-bit: "trtest01" (textures\trtest01.dds, 16x16, no mips: replaced, with a generated chain), "trtest02"
   (textures\trtest02_<crc>.dds, 32x32 with 6 levels: replaced by its key), "trtest03" (no file: the game's). tex_dump=1:
   textures_dump\ gets each as the game uploaded it. The test (test_xikit.py) wrote the files and the CRCs. */
typedef uint8_t (__thiscall *TexCreateFn)(void *);
static int texmod_run(IDirect3DDevice8 *dev) {
  static uint32_t px[3][64]; static uint8_t obj[3][0x48];
  const char *names[3] = { "trtest01", "trtest02", "trtest03" };
  for (int i = 0; i < 3; i++) {
    for (int k = 0; k < 64; k++) px[i][k] = 0xFF000000u | (uint32_t)(i * 0x400000 + k * 0x0301);   /* deterministic, per object */
    memset(obj[i], 0, sizeof obj[i]); memset(obj[i] + 0x0C, ' ', 16); memcpy(obj[i] + 0x0C, names[i], strlen(names[i]));
    *(uint32_t *)(obj[i] + 0x04) = 1; *(void **)(obj[i] + 0x20) = px[i];
    *(uint16_t *)(obj[i] + 0x24) = 8; *(uint16_t *)(obj[i] + 0x26) = 8; obj[i][0x28] = 32; obj[i][0x29] = 32; obj[i][0x2A] = 1;
    *(uint32_t *)(obj[i] + 0x2C) = 9u << 4;
  }
  for (int t = 0; t < 400 && *(uint8_t *)ga(0x10039E50u) != 0xE9; t++) {   /* (the kit loads mods on the render thread: frames) */
    IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF000000u, 1.0f, 0); IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL); Sleep(50);
  }
  check(*(uint8_t *)ga(0x10039E50u) == 0xE9, "texmod: TexObj_Upload's entry jumps (the mod's hook)");
  TexCreateFn create = (TexCreateFn)(void *)ga(0x10039A80u);
  unsigned want_w[3] = { 16, 32, 8 }, want_l[3] = { 5, 6, 0 };
  for (int i = 0; i < 3; i++) {
    uint8_t r = create(obj[i]);
    IDirect3DTexture8 *tx = *(IDirect3DTexture8 **)(obj[i] + 0x40);
    D3DSURFACE_DESC sd; memset(&sd, 0, sizeof sd);
    int ok = r && tx && SUCCEEDED(IDirect3DTexture8_GetLevelDesc(tx, 0, &sd));
    char what[160]; snprintf(what, sizeof what, "texmod: %s: the game's TexObj_Create succeeded and +0x40 is %ux%u (%s)", names[i], ok ? sd.Width : 0, ok ? sd.Height : 0,
                             i < 2 ? "the replacement's size" : "the game's own, no file");
    check(ok && sd.Width == want_w[i] && sd.Height == want_w[i], what);
    if (ok && want_l[i]) { snprintf(what, sizeof what, "texmod: %s: %lu mip levels", names[i], (unsigned long)IDirect3DTexture8_GetLevelCount(tx)); check(IDirect3DTexture8_GetLevelCount(tx) == want_l[i], what); }
    if (ok && i < 2) {                                         /* level 0's first texel is the file's (written as 0xFF000000 | 0x10101 * (i + 1)) */
      D3DLOCKED_RECT lr; uint32_t v = 0;
      if (SUCCEEDED(IDirect3DTexture8_LockRect(tx, 0, &lr, NULL, D3DLOCK_READONLY))) { v = *(uint32_t *)lr.pBits; IDirect3DTexture8_UnlockRect(tx, 0); }
      snprintf(what, sizeof what, "texmod: %s: level 0 holds the file's pixels (%08lx)", names[i], (unsigned long)v);
      check(v == (0xFF000000u | 0x10101u * (uint32_t)(i + 1)), what);
    }
    if (ok && i == 0) {                                        /* the generated chain: the file is two colours in columns, so level 1 is their mean */
      D3DLOCKED_RECT lr; uint32_t v = 0;
      if (SUCCEEDED(IDirect3DTexture8_LockRect(tx, 1, &lr, NULL, D3DLOCK_READONLY))) { v = *(uint32_t *)lr.pBits; IDirect3DTexture8_UnlockRect(tx, 1); }
      snprintf(what, sizeof what, "texmod: trtest01: level 1 is the 2x2 mean of level 0 (%08lx)", (unsigned long)v);
      check(v == 0xFF808080u, what);
    }
  }
  /* the dumps: each object's texture as the game uploaded it, 8x8 A8R8G8B8, the source's rows bottom-up (FORMATS.md 5.1) */
  for (int i = 0; i < 3; i++) {
    char pat[MAX_PATH], what[200]; snprintf(pat, sizeof pat, "textures_dump\\%s_*.dds", names[i]);
    WIN32_FIND_DATAA fd; HANDLE h = FindFirstFileA(pat, &fd); int ok = 0; char path[MAX_PATH] = "";
    if (h != INVALID_HANDLE_VALUE) {
      snprintf(path, sizeof path, "textures_dump\\%s", fd.cFileName); FindClose(h);
      FILE *f = fopen(path, "rb"); uint32_t hd[32], row[8]; int good = f && fread(hd, 4, 32, f) == 32 && hd[3] == 8 && hd[4] == 8 && hd[22] == 32;
      for (int y = 0; good && y < 8; y++) good = fread(row, 4, 8, f) == 8 && !memcmp(row, &px[i][(7 - y) * 8], 32);
      if (f) fclose(f); ok = good;
    }
    snprintf(what, sizeof what, "texmod: %s: dumped as the game uploaded it (%s)", names[i], path[0] ? path : "no file");
    check(ok, what);
  }
  return 0;
}

/* ------------------------------------------------------------------------------------------------ fxmod mode
   sdk/examples/effect_comfort.dll through the kit on a real Direct3D 8 device, with flash_limit=50, fx_intensity=50,
   fx_all_blended=1 (xikit_mods.ini, written below). 1: the game's own CDx::DrawFadeQuad (0x1000A820) on the host's
   CDx: the colour it writes into its quad's vertices (g_fadeQuadVerts_v0_color, 0x1034FE00) is the limited one for
   an adding colour (alpha above 0x80) and the game's for a darkening one. 2: an adding draw (SRCALPHA, ONE) of white
   onto black, read back: half as bright; the device's stage and factor states are as they were afterwards. */
typedef int (__thiscall *FadeFn)(void *, int, int);
static int fxmod_run(IDirect3DDevice8 *dev) {
  for (int t = 0; t < 400 && *(uint8_t *)ga(0x1000A820u) != 0xE9; t++) {
    IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF000000u, 1.0f, 0); IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL); Sleep(50);
  }
  check(*(uint8_t *)ga(0x1000A820u) == 0xE9, "fxmod: CDx::DrawFadeQuad's entry jumps (the mod's hook)");
  FadeFn fade = (FadeFn)(void *)ga(0x1000A820u); char what[200];
  IDirect3DDevice8_BeginScene(dev);
  fade(g_cdx, 0, (int)0xFFFFFFFFu); uint32_t v = *(uint32_t *)ga(0x1034FE00u);
  snprintf(what, sizeof what, "fxmod: the game's DrawFadeQuad, an adding white flash: its quad colour is %08lx (half the light)", (unsigned long)v);
  check(v == 0xFF7F7F7Fu, what);
  fade(g_cdx, 0, 0x40FFFFFF); v = *(uint32_t *)ga(0x1034FE00u);
  snprintf(what, sizeof what, "fxmod: a darkening fade is the game's (%08lx: alpha 0x40, the game's code drops the colour)", (unsigned long)v);
  check(v == 0x40000000u, what);
  IDirect3DDevice8_EndScene(dev);
  IDirect3DSurface8 *rt = NULL, *old = NULL, *oldz = NULL;
  HRESULT hr = IDirect3DDevice8_CreateRenderTarget(dev, 4, 4, D3DFMT_A8R8G8B8, D3DMULTISAMPLE_NONE, TRUE, &rt);
  check(SUCCEEDED(hr) && rt, "fxmod: a lockable 4x4 render target");
  if (!rt) return 1;
  IDirect3DDevice8_GetRenderTarget(dev, &old); IDirect3DDevice8_GetDepthStencilSurface(dev, &oldz);
  IDirect3DDevice8_SetRenderTarget(dev, rt, NULL);
  IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF000000u, 1.0f, 0);
  IDirect3DDevice8_SetRenderState(dev, D3DRS_ZENABLE, FALSE); IDirect3DDevice8_SetRenderState(dev, D3DRS_LIGHTING, FALSE);
  IDirect3DDevice8_SetRenderState(dev, D3DRS_CULLMODE, D3DCULL_NONE); IDirect3DDevice8_SetRenderState(dev, D3DRS_FOGENABLE, FALSE);
  IDirect3DDevice8_SetRenderState(dev, D3DRS_ALPHABLENDENABLE, TRUE);
  IDirect3DDevice8_SetRenderState(dev, D3DRS_SRCBLEND, D3DBLEND_SRCALPHA); IDirect3DDevice8_SetRenderState(dev, D3DRS_DESTBLEND, D3DBLEND_ONE);
  IDirect3DDevice8_SetRenderState(dev, D3DRS_TEXTUREFACTOR, 0x12345678);
  IDirect3DDevice8_SetTexture(dev, 0, NULL);
  IDirect3DDevice8_SetTextureStageState(dev, 0, D3DTSS_COLOROP, D3DTOP_SELECTARG1); IDirect3DDevice8_SetTextureStageState(dev, 0, D3DTSS_COLORARG1, D3DTA_DIFFUSE);
  IDirect3DDevice8_SetTextureStageState(dev, 0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1); IDirect3DDevice8_SetTextureStageState(dev, 0, D3DTSS_ALPHAARG1, D3DTA_DIFFUSE);
  IDirect3DDevice8_SetTextureStageState(dev, 1, D3DTSS_COLOROP, D3DTOP_DISABLE);
  IDirect3DDevice8_SetTextureStageState(dev, 2, D3DTSS_COLOROP, D3DTOP_MODULATE);    /* stale, beyond the disabled stage: must stay ignored */
  IDirect3DDevice8_SetVertexShader(dev, D3DFVF_XYZRHW | D3DFVF_DIFFUSE);
  struct { float x, y, z, w; DWORD c; } q[4] = { { -0.5f, -0.5f, 0, 1, 0xFFFFFFFFu }, { 3.5f, -0.5f, 0, 1, 0xFFFFFFFFu }, { -0.5f, 3.5f, 0, 1, 0xFFFFFFFFu }, { 3.5f, 3.5f, 0, 1, 0xFFFFFFFFu } };
  IDirect3DDevice8_BeginScene(dev);
  IDirect3DDevice8_DrawPrimitiveUP(dev, D3DPT_TRIANGLESTRIP, 2, q, sizeof q[0]);
  IDirect3DDevice8_EndScene(dev);
  D3DLOCKED_RECT lr; uint32_t px = 0;
  if (SUCCEEDED(IDirect3DSurface8_LockRect(rt, &lr, NULL, D3DLOCK_READONLY))) { px = ((uint32_t *)lr.pBits)[1 * lr.Pitch / 4 + 1]; IDirect3DSurface8_UnlockRect(rt); }
  unsigned g = (px >> 8) & 0xFF;
  snprintf(what, sizeof what, "fxmod: an adding white draw onto black with fx_intensity=50 reads back %08lx (green %u: half, 126..129)", (unsigned long)px, g);
  check(g >= 126 && g <= 129, what);
  DWORD s1 = 0, s2 = 0, tf = 0;
  IDirect3DDevice8_GetTextureStageState(dev, 1, D3DTSS_COLOROP, &s1); IDirect3DDevice8_GetTextureStageState(dev, 2, D3DTSS_COLOROP, &s2);
  IDirect3DDevice8_GetRenderState(dev, D3DRS_TEXTUREFACTOR, &tf);
  check(s1 == D3DTOP_DISABLE && s2 == D3DTOP_MODULATE && tf == 0x12345678, "fxmod: stages 1 and 2 and the texture factor are as they were after the draw");
  /* (25 Nov) a draw set up as the game's model draw (CYyModelDt): stage 1 multiplies by the texture factor (colour
     MODULATE2X, alpha MODULATE4X), the factor holding the element's colour and alpha (0x20808080: alpha 0x20 x 4 = half,
     colour 0x80 x 2 = full). White, SRCALPHA onto ONE, onto black: the game's draw adds half (green about 128); with
     fx_intensity=50 the mod scales the factor's alpha, so a quarter (about 64); the factor is the game's again after */
  IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF000000u, 1.0f, 0);
  IDirect3DDevice8_SetRenderState(dev, D3DRS_TEXTUREFACTOR, 0x20808080u);
  IDirect3DDevice8_SetTextureStageState(dev, 1, D3DTSS_COLOROP, D3DTOP_MODULATE2X); IDirect3DDevice8_SetTextureStageState(dev, 1, D3DTSS_COLORARG1, D3DTA_CURRENT);
  IDirect3DDevice8_SetTextureStageState(dev, 1, D3DTSS_COLORARG2, D3DTA_TFACTOR);
  IDirect3DDevice8_SetTextureStageState(dev, 1, D3DTSS_ALPHAOP, D3DTOP_MODULATE4X); IDirect3DDevice8_SetTextureStageState(dev, 1, D3DTSS_ALPHAARG1, D3DTA_CURRENT);
  IDirect3DDevice8_SetTextureStageState(dev, 1, D3DTSS_ALPHAARG2, D3DTA_TFACTOR);
  IDirect3DDevice8_SetTextureStageState(dev, 2, D3DTSS_COLOROP, D3DTOP_DISABLE);
  IDirect3DDevice8_BeginScene(dev);
  IDirect3DDevice8_DrawPrimitiveUP(dev, D3DPT_TRIANGLESTRIP, 2, q, sizeof q[0]);
  IDirect3DDevice8_EndScene(dev);
  px = 0; if (SUCCEEDED(IDirect3DSurface8_LockRect(rt, &lr, NULL, D3DLOCK_READONLY))) { px = ((uint32_t *)lr.pBits)[1 * lr.Pitch / 4 + 1]; IDirect3DSurface8_UnlockRect(rt); }
  g = (px >> 8) & 0xFF; IDirect3DDevice8_GetRenderState(dev, D3DRS_TEXTUREFACTOR, &tf);
  snprintf(what, sizeof what, "fxmod: a draw that multiplies by its own texture factor (the game's model draw), fx_intensity=50: %08lx (green %u: a quarter, 60..68; the game's half 128); the factor after %08lx (20808080)", (unsigned long)px, g, (unsigned long)tf);
  check(g >= 60 && g <= 68 && tf == 0x20808080u, what);
  IDirect3DDevice8_SetRenderTarget(dev, old, oldz); if (old) IDirect3DSurface8_Release(old); if (oldz) IDirect3DSurface8_Release(oldz); IDirect3DSurface8_Release(rt);
  return 0;
}

/* ------------------------------------------------------------------------------------------------ cammod mode
   sdk/examples/camera_view.dll through the kit (fov_deg=90, far_percent=200, draw_percent=200), with the game's own
   Camera_BuildPerspectiveFov (0x10015490) on a camera object: the projection at +0x154 (D3DXMatrixPerspectiveFovLH:
   _22 = 1 / tan(fov / 2), _33 = -far / (far - near), as run) has the mod's field of view and far distance; building twice does
   not compound the far scaling; a far value the game writes afterwards is the new base. */
typedef void (__thiscall *BuildFn)(void *);
static int cammod_run(IDirect3DDevice8 *dev) {
  for (int t = 0; t < 400 && *(uint8_t *)ga(0x10015490u) != 0xE9; t++) {
    IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF000000u, 1.0f, 0); IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL); Sleep(50);
  }
  check(*(uint8_t *)ga(0x10015490u) == 0xE9, "cammod: Camera_BuildPerspectiveFov's entry jumps (the mod's hook)");
  static uint8_t cam[0x300]; memset(cam, 0, sizeof cam);
  float *f = (float *)cam; char what[200];
  f[0x2F4 / 4] = 411.7f; f[0x2E8 / 4] = 1.0f; f[0x2F0 / 4] = 0.75f; f[0x2DC / 4] = 0.5f; f[0x2E0 / 4] = 100.0f;
  BuildFn build = (BuildFn)(void *)ga(0x10015490u);
  build(cam); float m22 = f[0x154 / 4 + 5], m33 = f[0x154 / 4 + 10];
  snprintf(what, sizeof what, "cammod: fov_deg=90: the game's matrix has _22 %.5f (1), its focal field %.3f (192)", m22, f[0x2F4 / 4]);
  check(m22 > 0.9999f && m22 < 1.0001f && f[0x2F4 / 4] > 191.99f && f[0x2F4 / 4] < 192.01f, what);
  /* (the game's routine gives _33 = -far / (far - near) and _34 = -1: the right-handed form, whatever its tree name says) */
  snprintf(what, sizeof what, "cammod: far_percent=200: _33 %.6f (-200 / 199.5), _34 %.1f, far field %.1f", m33, f[0x154 / 4 + 11], f[0x2E0 / 4]);
  check(m33 < -1.00250f + 1e-5f && m33 > -1.00250f - 1e-5f && f[0x2E0 / 4] == 200.0f, what);
  build(cam);
  snprintf(what, sizeof what, "cammod: built again: the far field is still %.1f (not compounded)", f[0x2E0 / 4]);
  check(f[0x2E0 / 4] == 200.0f, what);
  f[0x2E0 / 4] = 50.0f; build(cam); m33 = f[0x154 / 4 + 10];
  snprintf(what, sizeof what, "cammod: the game writes far 50: the mod's far is %.1f, _33 %.6f (-100 / 99.5)", f[0x2E0 / 4], m33);
  check(f[0x2E0 / 4] == 100.0f && m33 < -1.005025f + 1e-5f && m33 > -1.005025f - 1e-5f, what);
  /* draw_percent=200 with the game's own XiZone::ComputeFogDistance (0x1018B8F0) on a zone object: no zone record
     (+0x1C 0) and env -0x1C not 1, so Env_FogDistanceFactor gives its constant 1.0 (0x1032961C); +0x1D0 0: the game's
     100 alone; +0x1D0 300: the game's max(1.0 * 100, 300) */
  check(*(uint8_t *)ga(0x1018B8F0u) == 0xE9, "cammod: XiZone::ComputeFogDistance's entry jumps (the mod's hook)");
  static uint8_t zbuf[0x40 + 0x200]; memset(zbuf, 0, sizeof zbuf); uint8_t *zone = zbuf + 0x40;
  typedef float (__thiscall *DistFn)(void *, int);
  DistFn dist = (DistFn)(void *)ga(0x1018B8F0u);
  float d0 = dist(zone, 1);
  *(float *)(zone + 0x1D0) = 300.0f; float d1 = dist(zone, 0);
  snprintf(what, sizeof what, "cammod: draw_percent=200: the zone's draw distance is %.1f (200: the game's 100), %.1f with the floor 300 (600)", d0, d1);
  check(d0 == 200.0f && d1 == 600.0f, what);
  return 0;
}

/* ------------------------------------------------------------------------------------------------ ovlmod mode
   sdk/examples/file_overlay.dll through the kit: opens through the game's own import slot of CreateFileA (0x103291EC
   in the analysed build: the C runtime's open and the other openers call [slot]). test_xikit.py made ROM\1\2.DAT
   ("orig2"), ROM\1\3.DAT ("orig3"), overlay\10_a\ROM\1\2.DAT ("packA"), overlay\20_b\ROM\1\2.DAT ("packB"). */
typedef HANDLE (WINAPI *CFA)(LPCSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE);
static void read5(CFA cf, const char *path, DWORD access, char *out) {
  HANDLE h = cf(path, access, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL); DWORD n = 0; out[0] = 0;
  if (h != INVALID_HANDLE_VALUE) { ReadFile(h, out, 5, &n, NULL); out[n] = 0; CloseHandle(h); }
}
static int ovlmod_run(IDirect3DDevice8 *dev, HMODULE g) {
  CFA *slot = (CFA *)ga(0x103291ECu); void *orig = (void *)GetProcAddress(GetModuleHandleA("kernel32.dll"), "CreateFileA");
  for (int t = 0; t < 400 && *(void **)slot == orig; t++) {
    IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF000000u, 1.0f, 0); IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL); Sleep(50);
  }
  check(*(void **)slot != orig, "ovlmod: the game's CreateFileA import slot goes to the mod");
  char dir[MAX_PATH], p[MAX_PATH + 32], b[8], what[300]; GetModuleFileNameA(g, dir, sizeof dir); *strrchr(dir, '\\') = 0;
  snprintf(p, sizeof p, "%s/ROM/1/2.DAT", dir); read5(*slot, p, GENERIC_READ, b);      /* the game's spelling: "%s%s" with "/ROM/1/2.DAT" */
  snprintf(what, sizeof what, "ovlmod: %s through the game's slot reads \"%s\" (the later pack's)", p, b); check(!strcmp(b, "packB"), what);
  snprintf(p, sizeof p, "%s\\rom\\1\\3.dat", dir); read5(*slot, p, GENERIC_READ, b);
  snprintf(what, sizeof what, "ovlmod: a file no pack has reads \"%s\" (the game's)", b); check(!strcmp(b, "orig3"), what);
  snprintf(p, sizeof p, "%s\\ROM\\1\\2.DAT", dir); read5(*slot, p, GENERIC_READ | GENERIC_WRITE, b);
  snprintf(what, sizeof what, "ovlmod: a write open reads \"%s\" (the game's file, not redirected)", b); check(!strcmp(b, "orig2"), what);
  return 0;
}

/* ------------------------------------------------------------------------------------------------ audmod mode
   sdk/examples/audio_mix.dll through the kit (vol_interface=50, vol_effects=150, vol_ambient=25): the game's own
   SoundElem_SetScaled10351700/04/08 called with level 1.0 and the configured factors [0x103516FC], [0x103516F8] at 1:
   the category values (0x10351700, 0x10351704, 0x10351708) are the mod's share of the game's. Then xikit_mods.ini
   says vol_interface=200: the kit reads it again and the mod sets the interface value from the game's last level.
   The music (vol_music=50), on a ring the host gives the sound thread's writer (0x106690E8/C4/F0) and a sound object
   ([0x1046393C], only tested for non-zero there) with the music on ([0x104638F5] = 1): the game's own
   TextInputFiles_ApplyConfigSetting (0x101AA650) with setting 10 at 100 sends command 8 for all channels (-1) at
   127 x 50% = 63 through the mod's LobbyThread_SendCmd8 hook (the ring's last record); the game's
   Music_LoadTrackIfRunning (0x100382A0) called with volume 100 leaves its argument at 50 (the mod's stub; the queue
   function returns at once on the host's empty file table [0x10669108]). Then vol_music=100 in the file: the mod
   sends the game's last volume again, 127. */
typedef void (__cdecl *SetFn)(float);
typedef int (__cdecl *CfgSetFn)(int, int);
/* call a cdecl (int, int) function and return its second argument's slot as the callee left it */
static int call_arg2_after(void *fn, int a1, int a2) {
  int out;
  __asm__ volatile("pushl %3\n\tpushl %2\n\tcall *%1\n\tmovl 4(%%esp), %0\n\taddl $8, %%esp"
                   : "=&b"(out) : "S"(fn), "D"(a1), "r"(a2) : "eax", "ecx", "edx", "memory", "cc");
  return out;
}
static uint32_t *ring_last(void) {             /* the record before the ring's write pointer */
  uint8_t *b = *(uint8_t **)ga(0x106690E8u), *w = *(uint8_t **)ga(0x106690C4u);
  return (uint32_t *)(w == b ? b + 0x2000 - 0x20 : w - 0x20);
}
static int audmod_run(IDirect3DDevice8 *dev) {
  for (int t = 0; t < 400 && *(uint8_t *)ga(0x100360A0u) != 0xE9; t++) {
    IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF000000u, 1.0f, 0); IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL); Sleep(50);
  }
  check(*(uint8_t *)ga(0x100360A0u) == 0xE9 && *(uint8_t *)ga(0x10036050u) == 0xE9 && *(uint8_t *)ga(0x10035FB0u) == 0xE9 && *(uint8_t *)ga(0x100360F0u) == 0xE9,
        "audmod: the four volume setters' entries jump (the mod's stubs)");
  *(float *)ga(0x103516FCu) = 1.0f; *(float *)ga(0x103516F8u) = 1.0f; *(uint32_t *)ga(0x10463914u) = 0;
  ((SetFn)(void *)ga(0x100360A0u))(1.0f); ((SetFn)(void *)ga(0x10036050u))(1.0f); ((SetFn)(void *)ga(0x10035FB0u))(1.0f);
  float a = *(float *)ga(0x10351700u), b = *(float *)ga(0x10351704u), c = *(float *)ga(0x10351708u); char what[200];
  snprintf(what, sizeof what, "audmod: the game's setters at level 1.0 leave interface %.3f, effects %.3f, ambient %.3f (0.5, 1.5, 0.25)", a, b, c);
  check(a == 0.5f && b == 1.5f && c == 0.25f, what);
  static uint8_t ring[0x2000], files[0x200]; static uint32_t sound_obj[16];
  *(uint8_t **)ga(0x106690E8u) = ring; *(uint8_t **)ga(0x106690C4u) = ring; *(uint8_t **)ga(0x106690F0u) = ring;
  *(void **)ga(0x1046393Cu) = sound_obj; *(void **)ga(0x10669108u) = files; *(uint8_t *)ga(0x104638F5u) = 1;
  *(float *)ga(0x103517F8u) = 1.0f;
  ((CfgSetFn)(void *)ga(0x101AA650u))(10, 100);
  uint32_t *r = ring_last();
  snprintf(what, sizeof what, "audmod: the game's setting 10 at 100 with vol_music=50: the ring's last record is command %u, track %d, volume %u (8, -1, 63)", r[0], (int)r[1], r[2]);
  check(r[0] == 8 && (int)r[1] == -1 && r[2] == 63, what);
  int lv = call_arg2_after(ga(0x100382A0u), 5, 100);
  snprintf(what, sizeof what, "audmod: Music_LoadTrackIfRunning(5, 100) with vol_music=50: its volume argument is %d (50, the mod's stub)", lv);
  check(lv == 50, what);
  FILE *mf = fopen("xikit_mods.ini", "w"); if (mf) { fputs("[audio_mix]\nvol_interface=200\nvol_effects=150\nvol_ambient=25\nvol_music=100\n", mf); fclose(mf); }
  for (int f = 0; f < 120 && (*(float *)ga(0x10351700u) != 2.0f || ring_last()[2] != 127); f++) {
    IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF000000u, 1.0f, 0); IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL); Sleep(30);
  }
  a = *(float *)ga(0x10351700u);
  snprintf(what, sizeof what, "audmod: vol_interface=200 in xikit_mods.ini while running: the interface value is %.3f (2.0, from the game's last level)", a);
  check(a == 2.0f, what);
  r = ring_last();
  snprintf(what, sizeof what, "audmod: vol_music=100 in xikit_mods.ini while running: the ring's last record is command %u, track %d, volume %u (8, -1, 127: the game's last volume again)", r[0], (int)r[1], r[2]);
  check(r[0] == 8 && (int)r[1] == -1 && r[2] == 127, what);
  *(void **)ga(0x1046393Cu) = NULL; *(uint8_t *)ga(0x104638F5u) = 0;
  return 0;
}

/* ------------------------------------------------------------------------------------------------ envmod mode
   sdk/examples/world_light.dll through the kit (fog_distance=50, fog_r=200, ambient=150, light=200), with the game's own
   Env_ComputeFog (0x10189120) and Env_ComputeAmbient (0x10188E00) on an environment object: a zone record (env -0x1C
   = 1) without fog data (env +0x18 = 0) gives 0x808080, 400, 300 in the game's code; the ambient floats at +0x104
   (0.5) and +0x84 (0.25) give 0x404040 and 0x202020 (128 = 1.0) with g_windowMode 0. */
typedef void (__thiscall *FogFn)(void *, uint32_t *, float *, float *, int);
typedef uint32_t *(__thiscall *AmbFn)(void *, uint32_t *, int);
static int envmod_run(IDirect3DDevice8 *dev) {
  for (int t = 0; t < 400 && *(uint8_t *)ga(0x10189120u) != 0xE9; t++) {
    IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF000000u, 1.0f, 0); IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL); Sleep(50);
  }
  check(*(uint8_t *)ga(0x10189120u) == 0xE9 && *(uint8_t *)ga(0x10188E00u) == 0xE9, "envmod: Env_ComputeFog's and Env_ComputeAmbient's entries jump (the mod's hooks)");
  static uint8_t buf[0x400]; memset(buf, 0, sizeof buf); uint8_t *env = buf + 0x40; char what[200];
  *(int *)(env - 0x1C) = 1; *(int *)(env + 0x18) = 0;
  for (int i = 0; i < 3; i++) { ((float *)(env + 0x104))[i] = 0.5f; ((float *)(env + 0x84))[i] = 0.25f; }
  *(int *)ga(0x10456A7Cu) = 0;
  uint32_t col = 0; float end = 0, start = 0;
  ((FogFn)(void *)ga(0x10189120u))(env, &col, &end, &start, 0);
  snprintf(what, sizeof what, "envmod: the game's fog 0x808080, 400, 300 comes out %06lx, end %.1f, start %.1f (ff8080, 200, 150)", (unsigned long)col, end, start);
  check(col == 0xFF8080u && end == 200.0f && start == 150.0f, what);
  uint32_t a0 = 0, a1 = 0;
  ((AmbFn)(void *)ga(0x10188E00u))(env, &a0, 0); ((AmbFn)(void *)ga(0x10188E00u))(env, &a1, 1);
  snprintf(what, sizeof what, "envmod: ambient %06lx (0x404040 * 1.5 = 606060), light %06lx (0x202020 * 2 = 404040)", (unsigned long)a0, (unsigned long)a1);
  check(a0 == 0x606060u && a1 == 0x404040u, what);
  return 0;
}

/* ------------------------------------------------------------------------------------------------ phomod mode
   sdk/examples/photo_mode.dll through the kit (photo=1, photo_yaw=90, photo_dist=200, photo_shot=1, photo_hide_ui=1).
   1: the game's own Camera_SnapshotState (0x10021B70) on a controller with its eye at (0,0,-10) and look-at point at
   the origin: the view it builds at +4 is the look-at from the mod's eye (-20,0,0) (its forward axis, the third column,
   is +x; the eye 20 from the origin along it), and the game's eye is back at +0x44. 2: the game's own
   CDx::CompositeSceneToBackBuffer (0x1000C0B0) with a world texture filled with 0xFF336699: the picture in
   screenshots\ is 8x8 of that colour, and photo_shot is 0 again. 3: a frame: the cover draws that texture over the
   render target (a lockable one here), read back. */
typedef int (__thiscall *SnapFn)(void *);
typedef int (__thiscall *CompFn)(void *, int, int, int, int);
static int phomod_run(IDirect3DDevice8 *dev) {
  for (int t = 0; t < 400 && *(uint8_t *)ga(0x10021B70u) != 0xE9; t++) {
    IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF000000u, 1.0f, 0); IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL); Sleep(50);
  }
  check(*(uint8_t *)ga(0x10021B70u) == 0xE9 && *(uint8_t *)ga(0x1000C0B0u) == 0xE9, "phomod: Camera_SnapshotState's and the composite's entries jump (the mod's hooks)");
  static uint8_t ctl[0x200]; memset(ctl, 0, sizeof ctl); float *c = (float *)ctl; char what[260];
  c[0x44 / 4 + 2] = -10.0f; c[0xA8 / 4 + 1] = 1.0f;
  ((SnapFn)(void *)ga(0x10021B70u))(ctl);
  float *m = c + 1;                                           /* the view at +4, row-major 4x4 */
  snprintf(what, sizeof what, "phomod: the game's view has forward (%.3f %.3f %.3f) and _43 %.3f (|forward| along x, |_43| 20); the game's eye is back (%.1f %.1f %.1f)",
           m[2], m[6], m[10], m[14], c[0x44 / 4], c[0x44 / 4 + 1], c[0x44 / 4 + 2]);
  check(fabsf(fabsf(m[2]) - 1.0f) < 1e-4f && fabsf(m[6]) < 1e-4f && fabsf(m[10]) < 1e-4f && fabsf(fabsf(m[14]) - 20.0f) < 1e-3f &&
        c[0x44 / 4] == 0 && c[0x44 / 4 + 2] == -10.0f, what);
  { /* (28 Nov) the game's own Camera_ApplyViewProjection (0x10015510) on a camera that has not moved: its saved copies
       (+0x60 eye, +0x6C look-at, +0x78 roll) equal the current ones and +0xF4 is 0. First without the mod's frame: the
       game builds no view (Camera_DiffersFromSaved is false), so the mod's hook is never reached (the owner's "the
       camera features do nothing"). Then a Present (the mod's frame sets +0xF4, the game's own request) and the same
       call: the view is built from the mod's eye, and the game has cleared +0xF4. */
    static uint8_t cam[0x400], ctl2[0x200]; memset(cam, 0, sizeof cam); memset(ctl2, 0, sizeof ctl2);
    float *d = (float *)ctl2; d[0x44 / 4 + 2] = -10.0f; d[0x60 / 4 + 2] = -10.0f; d[0xA8 / 4 + 1] = 1.0f;
    *(float *)(cam + 0x28) = 1.0f; *(void **)(cam + 0x50) = ctl2; void *was = *(void **)ga(0x104568FCu); *(void **)ga(0x104568FCu) = cam;   /* g_pCamera */
    typedef void (__cdecl *ApplyFn)(void);
    ((ApplyFn)(void *)ga(0x10015510u))();
    float *v = d + 1; int none = 1; for (int i = 0; i < 16; i++) none &= v[i] == 0.0f;
    check(none && ctl2[0xF4] == 0, "phomod: a camera that has not moved: the game's Camera_ApplyViewProjection builds no view (the hook is not reached)");
    IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF000000u, 1.0f, 0); IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL);
    int asked = ctl2[0xF4];
    ((ApplyFn)(void *)ga(0x10015510u))();
    snprintf(what, sizeof what, "phomod: after the mod's frame (+0xF4 = %d): the game's Camera_ApplyViewProjection builds the view from the mod's eye: forward (%.3f %.3f %.3f), _43 %.3f; +0xF4 now %d; the game's eye back (%.1f %.1f %.1f)",
             asked, v[2], v[6], v[10], v[14], ctl2[0xF4], d[0x44 / 4], d[0x44 / 4 + 1], d[0x44 / 4 + 2]);
    check(asked == 1 && fabsf(fabsf(v[2]) - 1.0f) < 1e-4f && fabsf(v[6]) < 1e-4f && fabsf(v[10]) < 1e-4f && fabsf(fabsf(v[14]) - 20.0f) < 1e-3f &&
          ctl2[0xF4] == 0 && d[0x44 / 4] == 0 && d[0x44 / 4 + 2] == -10.0f, what);
    *(void **)ga(0x104568FCu) = was; }
  IDirect3DTexture8 *tex = NULL; IDirect3DSurface8 *ts = NULL, *old = NULL, *oldz = NULL, *rt = NULL;
  HRESULT hr = IDirect3DDevice8_CreateTexture(dev, 8, 8, 1, D3DUSAGE_RENDERTARGET, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &tex);
  check(SUCCEEDED(hr) && tex, "phomod: an 8x8 render-target texture for the world");
  if (!tex) return 1;
  IDirect3DTexture8_GetSurfaceLevel(tex, 0, &ts);
  IDirect3DDevice8_GetRenderTarget(dev, &old); IDirect3DDevice8_GetDepthStencilSurface(dev, &oldz);
  IDirect3DDevice8_SetRenderTarget(dev, ts, NULL); IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF336699u, 1.0f, 0);
  IDirect3DDevice8_SetRenderTarget(dev, old, oldz);
  static uint8_t env[0x200]; memset(env, 0, sizeof env); *(void **)ga(0x104566E8u) = env;   /* g_pEnv: not stereo */
  void *a1[2] = { NULL, tex }; int r3[4] = { 0, 0, 64, 64 }, r4[4] = { 0, 0, 64, 64 };
  IDirect3DDevice8_BeginScene(dev);
  ((CompFn)(void *)ga(0x1000C0B0u))(g_cdx, (int)(uintptr_t)a1, (int)0x80808080u, (int)(uintptr_t)r3, (int)(uintptr_t)r4);
  IDirect3DDevice8_EndScene(dev);
  WIN32_FIND_DATAA fd; HANDLE h = FindFirstFileA("screenshots\\photo_*.bmp", &fd); int good = 0; char path[MAX_PATH] = "";
  if (h != INVALID_HANDLE_VALUE) {
    snprintf(path, sizeof path, "screenshots\\%s", fd.cFileName); FindClose(h);
    FILE *f = fopen(path, "rb"); uint8_t hd[54], px[3];
    if (f && fread(hd, 1, 54, f) == 54 && *(int32_t *)(hd + 18) == 8 && *(int32_t *)(hd + 22) == 8 && fread(px, 1, 3, f) == 3) good = px[0] == 0x99 && px[1] == 0x66 && px[2] == 0x33;
    if (f) fclose(f);
  }
  snprintf(what, sizeof what, "phomod: the game's composite with photo_shot=1 wrote %s, 8x8, 336699", path[0] ? path : "no picture");
  check(good, what);
  char line[256]; int reset = 0; FILE *mi = fopen("xikit_mods.ini", "r");
  if (mi) { while (fgets(line, sizeof line, mi)) if (!strncmp(line, "photo_shot=0", 12)) reset = 1; fclose(mi); }
  check(reset, "phomod: photo_shot is 0 again in xikit_mods.ini");
  { /* the chat command: "/photo turn 30" through the game's Command_RunLine entry is taken and writes photo_yaw (90 -> 120) */
    typedef int (__cdecl *RunFn)(char *, uint32_t); char cl[] = "/photo turn 30";
    int rr = ((RunFn)(void *)ga(0x10080DC0u))(cl, 0); char cwd[MAX_PATH], ini[MAX_PATH + 20];
    GetCurrentDirectoryA(sizeof cwd, cwd); snprintf(ini, sizeof ini, "%s\\xikit_mods.ini", cwd);
    int yaw = GetPrivateProfileIntA("photo_mode", "photo_yaw", -999, ini);
    snprintf(what, sizeof what, "phomod: \"/photo turn 30\" through Command_RunLine: returned %d (0); photo_yaw in xikit_mods.ini %d (120)", rr, yaw);
    check(*(uint8_t *)ga(0x10080DC0u) == 0xE9 && rr == 0 && yaw == 120, what); }
  hr = IDirect3DDevice8_CreateRenderTarget(dev, 16, 16, D3DFMT_A8R8G8B8, D3DMULTISAMPLE_NONE, TRUE, &rt);
  if (SUCCEEDED(hr) && rt) {
    IDirect3DDevice8_SetRenderTarget(dev, rt, NULL); IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF000000u, 1.0f, 0);
    IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL);                      /* the mod's frame: the cover */
    D3DLOCKED_RECT lr; uint32_t v = 0;
    if (SUCCEEDED(IDirect3DSurface8_LockRect(rt, &lr, NULL, D3DLOCK_READONLY))) { v = ((uint32_t *)lr.pBits)[8 * lr.Pitch / 4 + 8]; IDirect3DSurface8_UnlockRect(rt); }
    snprintf(what, sizeof what, "phomod: photo_hide_ui=1: the frame's render target holds the world texture after the mod's frame (%08lx)", (unsigned long)v);
    check((v & 0xFFFFFF) == 0x336699u, what);
    IDirect3DDevice8_SetRenderTarget(dev, old, oldz); IDirect3DSurface8_Release(rt);
  } else check(0, "phomod: a lockable render target");
  if (old) IDirect3DSurface8_Release(old); if (oldz) IDirect3DSurface8_Release(oldz); IDirect3DSurface8_Release(ts);
  return 0;
}

/* ------------------------------------------------------------------------------------------------ cfmod mode
   sdk/examples/color_filter.dll through the kit on kit/d3d8on11's d3d8.dll (cb_mode=2, cb_simulate=1, cb_strength=100):
   a frame cleared to pure red, Present (the mod's frame runs before it: copy, pass, drawn back); the back buffer
   (D3DSWAPEFFECT_COPY, lockable) read back is the deuteranopia simulation's first column, 0.367322 0.280085 -0.011820
   (Machado et al. 2009) times 255: 94, 71, 0 (within 2). */
static int cfmod_run(IDirect3DDevice8 *dev) {
  int ok = 0; char what[200]; uint32_t v = 0;
  for (int f = 0; f < 60; f++) {                              /* (the kit loads the mod on the render thread: frames) */
    IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFFFF0000u, 1.0f, 0);
    if (f == 0) { IDirect3DSurface8 *bb0 = NULL, *im0 = NULL; uint32_t v0 = 0;        /* the control: the clear read back before Present */
      if (SUCCEEDED(IDirect3DDevice8_GetBackBuffer(dev, 0, D3DBACKBUFFER_TYPE_MONO, &bb0)) && SUCCEEDED(IDirect3DDevice8_CreateImageSurface(dev, 64, 64, D3DFMT_X8R8G8B8, &im0)) &&
          SUCCEEDED(IDirect3DDevice8_CopyRects(dev, bb0, NULL, 0, im0, NULL))) { D3DLOCKED_RECT l0; if (SUCCEEDED(IDirect3DSurface8_LockRect(im0, &l0, NULL, D3DLOCK_READONLY))) { v0 = ((uint32_t *)l0.pBits)[32 * l0.Pitch / 4 + 32]; IDirect3DSurface8_UnlockRect(im0); } }
      printf("  (control: before Present the back buffer reads %08lx)\n", (unsigned long)v0); if (im0) IDirect3DSurface8_Release(im0); if (bb0) IDirect3DSurface8_Release(bb0); }
    IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL); Sleep(30);
    IDirect3DSurface8 *bb = NULL, *img = NULL;
    if (SUCCEEDED(IDirect3DDevice8_GetBackBuffer(dev, 0, D3DBACKBUFFER_TYPE_MONO, &bb)) && bb &&
        SUCCEEDED(IDirect3DDevice8_CreateImageSurface(dev, 64, 64, D3DFMT_X8R8G8B8, &img)) && SUCCEEDED(IDirect3DDevice8_CopyRects(dev, bb, NULL, 0, img, NULL))) {
      D3DLOCKED_RECT lr; if (SUCCEEDED(IDirect3DSurface8_LockRect(img, &lr, NULL, D3DLOCK_READONLY))) { v = ((uint32_t *)lr.pBits)[32 * lr.Pitch / 4 + 32]; IDirect3DSurface8_UnlockRect(img); }
    }
    if (img) IDirect3DSurface8_Release(img); if (bb) IDirect3DSurface8_Release(bb);
    int r = (v >> 16) & 0xFF, g = (v >> 8) & 0xFF, b = v & 0xFF;
    if (abs(r - 94) <= 2 && abs(g - 71) <= 2 && b <= 2) { ok = 1; break; }
  }
  (void)ok; (void)what;                                  /* (after Present d3d8on11's back buffer is not kept: the mod's cb_check line is read instead) */
  return 0;
}

/* ------------------------------------------------------------------------------------------------ uimod mode
   sdk/examples/ui_layout.dll through the kit (ui_dx=100; ui_layout.txt: "menuinventor 5 -3"). Two windows in the menu
   manager's own list (g_menuMng 0x10621838 +0: nodes {next +0, window +0x10, free +0x14}; a window's name at
   [+4] +0x46, its rectangle at +0x3A; visible while +0x70 is 0), on layer 9, which Menu_DrawLayers' loop (0..8) does
   not draw. The game's own Menu_DrawLayers runs (the mod moves the windows first), then the game's own hit test
   (NetCellFont_HitTest 0x10118C10) is asked about a point in the moved rectangle; then the game "rebuilds" one window
   and draws again: the offset applies to the new rectangle. */
typedef void (__thiscall *DrawLayersFn)(void *);
typedef uint32_t (__thiscall *HitFn)(void *, uint32_t *);
typedef uint32_t (__thiscall *SetRectFn)(void *, int, int, int, int, int, int, int);
static int uimod_run(IDirect3DDevice8 *dev) {
  for (int t = 0; t < 400 && !(*(uint8_t *)ga(0x1015F6A0u) == 0xE9 && *(uint8_t *)ga(0x1011A5A0u) == 0xE9); t++) {
    IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF000000u, 1.0f, 0); IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL); Sleep(50);
  }
  check(*(uint8_t *)ga(0x1015F6A0u) == 0xE9 && *(uint8_t *)ga(0x1011A5A0u) == 0xE9, "uimod: Menu_DrawLayers' and NetCellFont_SetRectAndUpdateNodes' entries jump (the mod's hooks)");
  /* (25 Nov) two windows as the game has them: the name at [+4]+0x46, a node list at +0x14 whose first node is the
     frame (kind 0); in the menu manager's list (+0) for the draw */
  static uint8_t w1[0x100], w2[0x100], md1[0x80], md2[0x80], n1[0x18], n2[0x18], f1[0x40], f2[0x40], l1[0x18], l2[0x18], cursor[0x400], resmng[0x10000];
  memset(w1, 0, sizeof w1); memset(w2, 0, sizeof w2); memset(f1, 0, sizeof f1); memset(f2, 0, sizeof f2); memset(l1, 0, sizeof l1); memset(l2, 0, sizeof l2);
  memcpy(md1 + 0x46, "menu    inventor", 16); memcpy(md2 + 0x46, "menu    equip   ", 16);
  *(void **)(w1 + 4) = md1; *(void **)(w2 + 4) = md2; w1[0x60] = 9; w2[0x60] = 9;
  /* (25 Nov) inventor's title as the game keeps it: record +8 = its frame, frame +0xC = the title text (0x1011B5BE) */
  static uint8_t uframe1[0x20]; static char utitle1[] = "Items"; memset(uframe1, 0, sizeof uframe1); *(void **)(uframe1 + 0xC) = utitle1;
  *(void **)(md1 + 8) = uframe1; *(void **)(md2 + 8) = 0;
  *(void **)(l1 + 0x10) = f1; *(void **)(l2 + 0x10) = f2; *(void **)(w1 + 0x14) = l1; *(void **)(w2 + 0x14) = l2;
  memset(n1, 0, sizeof n1); memset(n2, 0, sizeof n2); *(void **)n1 = n2; *(void **)(n1 + 0x10) = w1; *(void **)(n2 + 0x10) = w2;
  uint8_t *mng = (uint8_t *)ga(0x10621838u); uint8_t saved[0x60]; memcpy(saved, mng, sizeof saved);
  memset(mng, 0, sizeof saved); *(void **)mng = n1;
  memset(cursor, 0, sizeof cursor); memset(resmng, 0, sizeof resmng);
  void **pcur = (void **)ga(0x104E1D4Cu), **pres = (void **)ga(0x1047BFA8u); void *oc = *pcur, *orr = *pres;
  if (!*pcur) *pcur = cursor;
  if (!*pres) { *pres = resmng; *(IDirect3DDevice8 **)(resmng + 0xEBC) = dev; *(void **)(resmng + 0xDC8) = g_cdx; }
  SetRectFn place = (SetRectFn)(void *)ga(0x1011A5A0u); HitFn hit = (HitFn)(void *)ga(0x10118C10u); char what[260];
  /* the game places them (snap 0): inventor at 10,20 size 100,200; equip at 0,0 size 50,50 */
  place(w1, 10, 20, 100, 200, 0, 0, 0); place(w2, 0, 0, 50, 50, 0, 0, 0);
  short *t1 = (short *)(w1 + 0x8C), *h1 = (short *)(w1 + 0x3A), *t2 = (short *)(w2 + 0x8C), *fr1 = (short *)f1;
  snprintf(what, sizeof what, "uimod: the game's placement offset: inventor drawn at %d,%d size %d,%d (115,17 100,200: ui_dx 100 + its line 5,-3), equip at %d,%d (100,0)", t1[0], t1[1], t1[2], t1[3], t2[0], t2[1]);
  check(t1[0] == 115 && t1[1] == 17 && t1[2] == 100 && t1[3] == 200 && t2[0] == 100 && t2[1] == 0, what);
  snprintf(what, sizeof what, "uimod: the frame node there at once (snap 0): %d,%d; the hit rectangle with it: %d,%d..%d,%d (115,17..215,217)", fr1[0xd], fr1[0xe], h1[0], h1[1], h1[2], h1[3]);
  check(fr1[0xd] == 115 && fr1[0xe] == 17 && h1[0] == 115 && h1[1] == 17 && h1[2] == 215 && h1[3] == 217, what);
  uint32_t pin[2] = { 200, 30 }, pout[2] = { 50, 30 };
  check((hit(w1, pin) & 0xFF) == 1 && (hit(w1, pout) & 0xFF) == 0, "uimod: the game's hit test finds (200,30) in the moved window and not (50,30)");
  /* a settings change: ui_dx 100 -> 40; the next draw places the listed windows again from the game's base */
  { FILE *mf = fopen("xikit_mods.ini", "w"); if (mf) { fputs("[ui_layout]\nui_dx=40\nui_list=1\n", mf); fclose(mf); } }
  DrawLayersFn draw = (DrawLayersFn)(void *)ga(0x1015F6A0u);
  for (int i = 0; i < 80 && t1[0] != 55; i++) { IDirect3DDevice8_BeginScene(dev); draw(mng); IDirect3DDevice8_EndScene(dev); IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL); Sleep(25); }
  snprintf(what, sizeof what, "uimod: ui_dx 40: placed again at %d,%d (55,17), equip at %d,%d (40,0), frame node %d,%d", t1[0], t1[1], t2[0], t2[1], fr1[0xd], fr1[0xe]);
  check(t1[0] == 55 && t1[1] == 17 && t2[0] == 40 && t2[1] == 0 && fr1[0xd] == 55, what);
  { FILE *lg = fopen("xikit.log", "r"); char l[600]; int t = 0, e = 0;
    while (lg && fgets(l, sizeof l, lg)) { if (strstr(l, "window menuinventor (\"Items\")")) t = 1; if (strstr(l, "window menuequip (\"\")")) e = 1; }
    if (lg) fclose(lg);
    check(t && e, "uimod: ui_list names inventor by the title the game keeps (\"Items\"), equip (no frame) with none"); }
  memcpy(mng, saved, sizeof saved); *pcur = oc; *pres = orr;
  return 0;
}

/* ------------------------------------------------------------------------------------------------ ctmod mode
   sdk/examples/click_target.dll through the kit. (1) The hooks: FindNearestToPoint, Slot244_Unknown, and the nameplate
   pair (DrawNameIfVisible, CDx::DrawPrimitiveUP). (2) The game's own FindNearestToPoint with an empty camera (g_pCamera's
   +0x50 is 0: it returns at once): recorded, nothing picked. (3) The game's own CXiSkeletonActor::Slot244_Unknown on a
   stand-in actor (its vtable's +0x1BC position, +0x1C0 heading, +0x3C8 box are the test's) with an identity view x
   projection: the box the game computes, recorded by the mod, against the box the code's reading gives (x from the box's
   third and fourth floats, y from the first and second, negated). (4) The mod's rule on given boxes and names: a name
   wins over the game's pick; the game's pick stands otherwise; with none, the nearest centre among the boxes grown by
   ct_grow (125%); a point outside every grown box picks nothing. */
typedef int *(__cdecl *FindFn)(float *, uint32_t, uint32_t);
typedef uint32_t (__thiscall *BoxFn)(void *, float *, float *, void *);
static float pv_pos[4] = { 0.1f, 0.2f, 0.5f, 1.0f }, pv_dir[4] = { 0, 0, 0, 0 };
static float pv_tab[6] = { -0.3f, 0.4f, -0.2f, 0.25f, 0.1f, 0.2f };
static void *__attribute__((thiscall)) pv_getpos(void *self) { (void)self; return pv_pos; }
static void *__attribute__((thiscall)) pv_getdir(void *self) { (void)self; return pv_dir; }
static void *__attribute__((thiscall)) pv_gettab(void *self, int k) { (void)self; (void)k; return pv_tab; }
typedef void *(*DecideFn)(float, float, int, void **, const float *, void *, int, void **, const float *, int *);
static int ctmod_run(IDirect3DDevice8 *dev) {
  for (int t = 0; t < 400 && *(uint8_t *)ga(0x10083750u) != 0xE9; t++) {
    IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF000000u, 1.0f, 0); IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL); Sleep(50);
  }
  check(*(uint8_t *)ga(0x10083750u) == 0xE9 && *(uint8_t *)ga(0x100CFC10u) == 0xE9, "ctmod: FindNearestToPoint's and Slot244_Unknown's entries jump (the mod's hooks)");
  check(*(uint8_t *)ga(0x100D0880u) == 0xE9 && *(uint8_t *)ga(0x1000CD00u) == 0xE9, "ctmod: DrawNameIfVisible's and CDx::DrawPrimitiveUP's entries jump (the nameplate hooks)");
  HMODULE m = GetModuleHandleA("click_target.dll"); char what[300];
  int (*last)(float *, float *, int *, void **, void **) = (int (*)(float *, float *, int *, void **, void **))(void *)GetProcAddress(m, "ct_test_last");
  int (*tbox)(int, float *) = (int (*)(int, float *))(void *)GetProcAddress(m, "ct_test_box");
  void (*inpick)(int) = (void (*)(int))(void *)GetProcAddress(m, "ct_test_inpick");
  DecideFn decide = (DecideFn)(void *)GetProcAddress(m, "ct_test_decide");
  check(m && last && tbox && inpick && decide, "ctmod: the mod's test exports");
  if (!(m && last && tbox && inpick && decide)) return 0;
  float pt[4] = { 0.25f, -0.5f, 0, 0 };
  static uint8_t nocam[0x100]; memset(nocam, 0, sizeof nocam);
  void **pcam = (void **)ga(0x104568FCu), *ocam = *pcam; *pcam = nocam;
  int *won = ((FindFn)(void *)ga(0x10083750u))(pt, 0x11u, 0x22u);
  *pcam = ocam;
  float px = 0, py = 0; int n = -1; void *g = (void *)1, *w = (void *)1; int seq = last(&px, &py, &n, &g, &w);
  snprintf(what, sizeof what, "ctmod: the game's FindNearestToPoint (empty camera) returned %p; the mod recorded pick %d at %.2f,%.2f, %d boxes, result %p", (void *)won, seq, px, py, n, w);
  check(won == NULL && seq == 1 && px == 0.25f && py == -0.5f && n == 0 && w == NULL, what);
  static void *vt[0x400 / 4]; static uint8_t actor[0x800]; memset(actor, 0, sizeof actor);
  vt[0x1BC / 4] = (void *)pv_getpos; vt[0x1C0 / 4] = (void *)pv_getdir; vt[0x3C8 / 4] = (void *)pv_gettab; *(void ***)actor = vt;
  float ident[16] = { 1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1 }, mn[4] = { 0 }, mx[4] = { 0 };
  inpick(1);
  uint32_t r = ((BoxFn)(void *)ga(0x100CFC10u))(actor, mn, mx, ident);
  inpick(0);
  float b[5] = { 0 }; int ok = tbox(0, b); last(&px, &py, &n, &g, &w);
  printf("  (the game's box: min %.4f %.4f %.4f %.4f  max %.4f %.4f %.4f %.4f, returned %u)\n", mn[0], mn[1], mn[2], mn[3], mx[0], mx[1], mx[2], mx[3], (unsigned)(r & 0xFF));
  snprintf(what, sizeof what, "ctmod: the mod recorded the game's box (%d box, ok %d): %.4f,%.4f..%.4f,%.4f w %.4f = the game's output", n, ok, b[0], b[1], b[2], b[3], b[4]);
  check(n == 1 && ok == 1 && b[0] == mn[0] && b[1] == mn[1] && b[2] == mx[0] && b[3] == mx[1] && b[4] == mn[3], what);
  float ex0 = 0.1f - 0.2f, ex1 = 0.1f + 0.25f, ey0 = -(0.2f + 0.4f), ey1 = -(0.2f - 0.3f);
  snprintf(what, sizeof what, "ctmod: the game's box is the file's box moved and y negated: x %.4f..%.4f (%.4f..%.4f), y %.4f..%.4f (%.4f..%.4f)", mn[0], mx[0], ex0, ex1, mn[1], mx[1], ey0, ey1);
  check(fabsf(mn[0] - ex0) < 1e-4f && fabsf(mx[0] - ex1) < 1e-4f && fabsf(mn[1] - ey0) < 1e-4f && fabsf(mx[1] - ey1) < 1e-4f, what);
  { /* the box crossing the camera's plane (click_target's box_crosses_near): the same actor under a matrix that puts the
       box's depth in w (w = z, z kept: x, y, z of a corner over w), the actor moved to z -0.15 so its corners' z are
       -0.05 .. 0.05: the game's box divides by w <= 0 for half of them; the mod marks the box crossing (not used). The
       first box (identity, z 0.6 .. 0.7, w 1) is not crossing. */
    int (*tnear)(int) = (int (*)(int))(void *)GetProcAddress(m, "ct_test_near");
    int n0 = tnear ? tnear(0) : -2;
    float persp[16] = { 1,0,0,0, 0,1,0,0, 0,0,1,1, 0,0,0,0 }, z0 = pv_pos[2]; pv_pos[2] = -0.15f;
    inpick(1); ((BoxFn)(void *)ga(0x100CFC10u))(actor, mn, mx, persp); inpick(0); pv_pos[2] = z0;
    int n1 = tnear ? tnear(0) : -2;
    snprintf(what, sizeof what, "ctmod: a box in front of the camera: crossing %d (0); a box whose corners have w -0.05..0.05: crossing %d (1); the game's box for it x %.1f..%.1f", n0, n1, mn[0], mx[0]);
    check(n0 == 0 && n1 == 1, what); }
  /* the rule: A's box 0,0..0.2,0.2 (centre 0.1,0.1; grown 125%: -0.025..0.225), B's 0.3,0..0.5,0.2 (centre 0.4,0.1) */
  void *A = (void *)0xA0, *B = (void *)0xB0, *C = (void *)0xC0; void *acts[2] = { A, B };
  float boxes[8] = { 0, 0, 0.2f, 0.2f, 0.3f, 0, 0.5f, 0.2f };
  void *nacts[2] = { B, C }; float names[8] = { 0.3f, -0.3f, 0.5f, -0.25f, 0.6f, -0.3f, 0.8f, -0.25f };
  int how = -1; void *res;
  res = decide(0.21f, 0.1f, 2, acts, boxes, NULL, 0, NULL, NULL, &how);
  snprintf(what, sizeof what, "ctmod: the game picked nothing; 0.21,0.1 is outside A's box but inside it grown 125%%: %p (A), how %d (2)", res, how); check(res == A && how == 2, what);
  res = decide(0.26f, 0.1f, 2, acts, boxes, NULL, 0, NULL, NULL, &how);
  snprintf(what, sizeof what, "ctmod: 0.26,0.1 is in both grown boxes' reach? A's ends at 0.225, B's starts at 0.275: %p (nothing), how %d (3)", res, how); check(res == NULL && how == 3, what);
  res = decide(0.29f, 0.1f, 2, acts, boxes, NULL, 0, NULL, NULL, &how);
  snprintf(what, sizeof what, "ctmod: 0.29,0.1: B's grown box: %p (B), how %d (2)", res, how); check(res == B && how == 2, what);
  res = decide(0.1f, 0.1f, 2, acts, boxes, B, 0, NULL, NULL, &how);
  snprintf(what, sizeof what, "ctmod: the game's own pick stands: %p (B), how %d (0)", res, how); check(res == B && how == 0, what);
  res = decide(0.4f, -0.27f, 2, acts, boxes, A, 2, nacts, names, &how);
  snprintf(what, sizeof what, "ctmod: a click on B's nameplate wins over the game's pick of A: %p (B), how %d (1)", res, how); check(res == B && how == 1, what);
  res = decide(0.7f, -0.27f, 2, acts, boxes, NULL, 2, nacts, names, &how);
  snprintf(what, sizeof what, "ctmod: C's nameplate, C not among the actors the game's filter let through: %p (nothing), how %d (3)", res, how); check(res == NULL && how == 3, what);
  check(*(uint8_t *)ga(0x101585F0u) == 0xE9 && *(uint8_t *)ga(0x10158DB0u) == 0xE9, "ctmod: Target_RunActiveCommand's and Target_ApplyAction's entries jump (the click hooks)");
  int (*wd)(void *, int, int, int) = (int (*)(void *, int, int, int))(void *)GetProcAddress(m, "ct_test_would_deselect");
  static uint8_t tm[0x200]; memset(tm, 0, sizeof tm);
  if (wd) {
    int a1 = wd(tm, 1, 1, 1), a2 = wd(tm, 1, 0, 1), a3 = wd(tm, 1, 1, 0), a4 = wd(tm, 0, 1, 1);
    *(uint32_t *)(tm + 0xC4) = 0x1000; int a5 = wd(tm, 1, 1, 1); *(uint32_t *)(tm + 0xC4) = 0;
    snprintf(what, sizeof what, "ctmod: deselect only for a click (inside Target_RunActiveCommand) that picked nobody with a target selected and no command waiting: %d (1), no target %d, picked someone %d, not a click %d, a command waiting %d (0s)", a1, a2, a3, a4, a5);
    check(a1 == 1 && !a2 && !a3 && !a4 && !a5, what);
  } else check(0, "ctmod: ct_test_would_deselect");
  for (int f = 0; f < 5; f++) {          /* the mod's frame (ct_show=1 in this test) draws the recorded pick */
    IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF000000u, 1.0f, 0); IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL); Sleep(20);
  }
  check(1, "ctmod: five frames drawn with ct_show=1");
  return 0;
}

/* ------------------------------------------------------------------------------------------------ igmod mode
   sdk/examples/imgui_panel.dll (Dear ImGui through sdk/xiimgui) on Wine's Direct3D 8: its window drawn inside the game's
   own Menu_DrawLayers; a press over the window kept from the game (the cursor object's +0x58 untouched), a press
   elsewhere reaching the game's Cursor_EnterMode1; nothing drawn while the interface is hidden; pixels of the window in
   the back buffer when it can be read. */
typedef void (__thiscall *IgCurFn)(void *);
static int igmod_run(IDirect3DDevice8 *dev) {
  for (int t = 0; t < 400 && *(uint8_t *)ga(0x1015F6A0u) != 0xE9; t++) {
    IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF000000u, 1.0f, 0); IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL); Sleep(50);
  }
  check(*(uint8_t *)ga(0x1015F6A0u) == 0xE9 && *(uint8_t *)ga(0x10158D90u) == 0xE9 && *(uint8_t *)ga(0x10124930u) == 0xE9 && *(uint8_t *)ga(0x101249E0u) == 0xE9,
        "igmod: Menu_DrawLayers, Target_PickNearestToPoint and the two left-button entries jump (xiimgui's hooks)");
  HMODULE m = GetModuleHandleA("imgui_panel.dll"); char what[300];
  long (*frames)(void) = (long (*)(void))(void *)GetProcAddress(m, "ip_test_frames");
  int (*hadm)(void) = (int (*)(void))(void *)GetProcAddress(m, "ip_test_had_mouse");
  void (*clicks)(long *, long *) = (void (*)(long *, long *))(void *)GetProcAddress(m, "ip_test_clicks");
  check(m && frames && hadm && clicks, "igmod: the mod's test exports");
  if (!(m && frames && hadm && clicks)) return 0;
  long kept = 0, passed = 0;
  void (*ffocus)(int) = (void (*)(int))(void *)GetProcAddress(m, "ip_test_force_focus"); if (ffocus) ffocus(1);   /* (no game window here) */
  uint8_t *mng = (uint8_t *)ga(0x10621838u); uint8_t saved[0xC0]; memcpy(saved, mng, sizeof saved); memset(mng, 0, sizeof saved);
  short *sr = (short *)ga(0x106218B4u); sr[0] = 0; sr[1] = 0; sr[2] = 640; sr[3] = 480;
  static uint8_t cursor[0x400]; memset(cursor, 0, sizeof cursor);
  void **pcur = (void **)ga(0x104E1D4Cu), *oc = *pcur; *pcur = cursor;
  static uint8_t resmng[0x10000]; memset(resmng, 0, sizeof resmng);
  void **pres = (void **)ga(0x1047BFA8u), *orr = *pres; if (!*pres) { *pres = resmng; *(IDirect3DDevice8 **)(resmng + 0xEBC) = dev; *(void **)(resmng + 0xDC8) = g_cdx; }
  if (!*(void **)(g_cdx + 0xC)) *(IDirect3DDevice8 **)(g_cdx + 0xC) = dev;
  DrawLayersFn draw = (DrawLayersFn)(void *)ga(0x1015F6A0u);
  #define IG_FRAME() do { IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF000000u, 1.0f, 0); IDirect3DDevice8_BeginScene(dev); draw(mng); IDirect3DDevice8_EndScene(dev); } while (0)
  *(int *)(cursor + 4) = 100; *(int *)(cursor + 8) = 60;              /* inside the window (40,40, 320 wide) */
  long f0 = frames();
  for (int f = 0; f < 10; f++) IG_FRAME();
  snprintf(what, sizeof what, "igmod: 10 frames drawn through Menu_DrawLayers: %ld (10)", frames() - f0); check(frames() - f0 == 10, what);
  snprintf(what, sizeof what, "igmod: the cursor over the window: ImGui wants the mouse (%d)", hadm()); check(hadm() == 1, what);
  { IDirect3DSurface8 *bb = NULL; D3DLOCKED_RECT lr; int lit = -1;
    if (SUCCEEDED(IDirect3DDevice8_GetBackBuffer(dev, 0, D3DBACKBUFFER_TYPE_MONO, &bb)) && bb) {
      if (SUCCEEDED(IDirect3DSurface8_LockRect(bb, &lr, NULL, D3DLOCK_READONLY))) {
        uint32_t px = *(uint32_t *)((uint8_t *)lr.pBits + 100 * lr.Pitch + 100 * 4); lit = (px & 0xFFFFFF) != 0;
        IDirect3DSurface8_UnlockRect(bb);
      }
      IDirect3DSurface8_Release(bb);
    }
    if (lit < 0) printf("note: igmod: the back buffer cannot be read here (not lockable): pixels not checked\n");
    else check(lit == 1, "igmod: a pixel inside the window (100,100) is not the cleared black"); }
  *(uint32_t *)(cursor + 0x58) = 0x12340000;
  ((IgCurFn)(void *)ga(0x10124930u))(cursor); IG_FRAME(); ((IgCurFn)(void *)ga(0x101249E0u))(cursor); IG_FRAME();
  clicks(&kept, &passed);
  snprintf(what, sizeof what, "igmod: a press over the window kept from the game: kept %ld (1), passed %ld (0)", kept, passed);
  check(kept == 1 && passed == 0, what);
  *(int *)(cursor + 4) = 600; *(int *)(cursor + 8) = 450; IG_FRAME(); IG_FRAME();
  snprintf(what, sizeof what, "igmod: the cursor away from the window: ImGui does not want the mouse (%d)", hadm()); check(hadm() == 0, what);
  ((IgCurFn)(void *)ga(0x10124930u))(cursor); ((IgCurFn)(void *)ga(0x101249E0u))(cursor);
  clicks(&kept, &passed);
  snprintf(what, sizeof what, "igmod: a press away from the window passed on to the game's Cursor_EnterMode1: kept %ld (1), passed %ld (1)", kept, passed);
  check(kept == 1 && passed == 1, what);
  mng[0xB4] = 1; long f1 = frames(); IG_FRAME(); IG_FRAME();
  snprintf(what, sizeof what, "igmod: the interface hidden (+0xB4 = 1): no frame drawn (%ld)", frames() - f1); check(frames() == f1, what);
  mng[0xB4] = 0;
  memcpy(mng, saved, sizeof saved); *pcur = oc; *pres = orr;
  return 0;
}

/* ------------------------------------------------------------------------------------------------ xtmod mode
   kit/sessions/experimental_tests' in-game test (xitest.dll, xitest_b.dll) on Wine's Direct3D 8: it starts, draws
   through the game's own Menu_DrawLayers, and writes xitest_results.txt with the kit's checks passed (K1, K2, K4).
   The other checks need the game itself (a window, a cursor, a target): they are the owner's run. */
static int xtmod_run(IDirect3DDevice8 *dev) {
  for (int t = 0; t < 400 && *(uint8_t *)ga(0x1015F6A0u) != 0xE9; t++) {
    IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF000000u, 1.0f, 0); IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL); Sleep(50);
  }
  check(GetModuleHandleA("xitest.dll") && GetModuleHandleA("xitest_b.dll"), "xtmod: xitest.dll and xitest_b.dll loaded");
  uint8_t *mng = (uint8_t *)ga(0x10621838u); uint8_t saved[0xC0]; memcpy(saved, mng, sizeof saved); memset(mng, 0, sizeof saved);
  short *sr = (short *)ga(0x106218B4u); sr[0] = 0; sr[1] = 0; sr[2] = 640; sr[3] = 480;
  static uint8_t cursor[0x400]; memset(cursor, 0, sizeof cursor);       /* (the game's Menu_DrawLayers reads the cursor object) */
  void **pcur = (void **)ga(0x104E1D4Cu), *oc = *pcur; *pcur = cursor;
  static uint8_t resmng[0x10000]; memset(resmng, 0, sizeof resmng);
  void **pres = (void **)ga(0x1047BFA8u), *orr = *pres; if (!*pres) { *pres = resmng; *(IDirect3DDevice8 **)(resmng + 0xEBC) = dev; *(void **)(resmng + 0xDC8) = g_cdx; }
  if (!*(void **)(g_cdx + 0xC)) *(IDirect3DDevice8 **)(g_cdx + 0xC) = dev;
  DrawLayersFn draw = (DrawLayersFn)(void *)ga(0x1015F6A0u);
  for (int f = 0; f < 200; f++) { IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF000000u, 1.0f, 0); IDirect3DDevice8_BeginScene(dev); draw(mng); IDirect3DDevice8_EndScene(dev); if (f % 50 == 0) printf("note: xtmod: frame %d\n", f); }
  FILE *f = fopen("xitest_results.txt", "r"); static char t[1 << 16]; size_t n = f ? fread(t, 1, sizeof t - 1, f) : 0; t[n] = 0; if (f) fclose(f);
  check(n > 0, "xtmod: xitest_results.txt written (at frame 160)");
  check(strstr(t, "PASS K1") != NULL, "xtmod: K1 PASS (kit API 5)");
  check(strstr(t, "PASS K2") != NULL, "xtmod: K2 PASS (xitest's and xitest_b's hooks of Menu_DrawLayers both ran, as often)");
  check(strstr(t, "PASS K4") != NULL, "xtmod: K4 PASS (BeginScene through the device hook)");
  check(strstr(t, "PASS G1") != NULL, "xtmod: G1 PASS (xiimgui drew its window)");
  for (char *l = t; *l; ) { char *e = strchr(l, '\n'); if (!e) break; if (!strncmp(l, "FAIL", 4) || !strncmp(l, "WAIT", 4)) printf("note: xtmod: %.*s\n", (int)(e - l), l); l = e + 1; }
  memcpy(mng, saved, sizeof saved); *pres = orr; *pcur = oc;
  return 0;
}

/* ------------------------------------------------------------------------------------------------ hbmod mode
   sdk/examples/hotbar.dll through the kit (hb_dry=1: a slot's line is logged and kept, not run). hotbar.txt: bar 1 of 3
   slots at 100,100; bar 2 of 4 slots down at 10,10; XIVhotbar2's folder "xiv" (written here: General.lua's Root,
   war.lua's Base and Sword, the priv_res tables; icons copied from WGINC/XIVhotbar2 by test_xikit.py); job war, set
   Sword. The interface's size 1280x960 (two pixels a unit). Checks: the hooks (Menu_DrawLayers,
   Target_PickNearestToPoint, Cursor_EnterMode1, Cursor_ToggleFlag1); the layout; XIVhotbar2's rows resolved (a
   spell's line, cost and icon; a weapon skill only from the Sword set; a macro's lines); keys F9 and Ctrl+1 inside
   the game's own Menu_DrawLayers, none while the chat line takes characters; a left press over a slot handled by the
   mod and kept from the game (the cursor object's +0x58, which the game's Cursor_EnterMode1 sets, untouched), its
   release too; a macro's second line 200 ms after its first; the Field/Battle tag; an "hb env" slot; the bars not
   hit while the interface is hidden (menu manager +0xB4 = 1); icons made into textures (WIC). */
typedef uint32_t (__thiscall *PickFn)(void *);
typedef void (__thiscall *CurFn)(void *);
/* hbmod plays another tool that hooked Command_RunLine before the kit (as Windower's Hook.dll does in the owner's game,
   24 Nov): a jmp rel32 at its entry to this stub, written before the kit loads. The kit puts the mod's hook in front
   of it, so a line the mod does not take reaches the stub (it answers 7 and runs no game code). */
static volatile long g_fake_tool_calls;
static int __cdecl fake_tool_runline(char *line, uint32_t mode) { (void)line; (void)mode; g_fake_tool_calls++; return 7; }
/* (25 Nov) the forms another tool's hook can take at an entry (prishe_probe's jump_of): XT_TOOL_FORM = e9 (jmp rel32,
   the instruction's sixth byte left as it was), e990 (jmp rel32 and a nop over the rest of the 6-byte instruction),
   ff25 (jmp [slot]), pushret (push imm32; ret), bad (e990 with a byte after the first instruction changed: refused) */
static void *g_tool_slot;
static void fake_tool_form(const char *form) {
  uint8_t *e = (uint8_t *)ga(0x10080DC0u); DWORD o; VirtualProtect(e, 16, PAGE_EXECUTE_READWRITE, &o);
  void *to = (void *)fake_tool_runline; int32_t d = (int32_t)((uintptr_t)to - ((uintptr_t)e + 5));
  if (!strcmp(form, "ff25")) { g_tool_slot = to; void **sl = &g_tool_slot; e[0] = 0xFF; e[1] = 0x25; memcpy(e + 2, &sl, 4); }
  else if (!strcmp(form, "dyn")) {                /* (28 Nov) a jump into code no module holds: a thunk in allocated memory
                                                     that jumps on to the tool's function (Windower's hook at ChatLog_AddMessage) */
    uint8_t *th = (uint8_t *)VirtualAlloc(NULL, 16, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    int32_t d2 = (int32_t)((uintptr_t)to - ((uintptr_t)th + 5)); th[0] = 0xE9; memcpy(th + 1, &d2, 4);
    FlushInstructionCache(GetCurrentProcess(), th, 5);
    d = (int32_t)((uintptr_t)th - ((uintptr_t)e + 5)); e[0] = 0xE9; memcpy(e + 1, &d, 4); e[5] = 0xCC; }
  else if (!strcmp(form, "pushret")) { uint32_t a = (uint32_t)(uintptr_t)to; e[0] = 0x68; memcpy(e + 1, &a, 4); e[5] = 0xC3; }
  else { e[0] = 0xE9; memcpy(e + 1, &d, 4); if (strcmp(form, "e9")) e[5] = 0x90; if (!strcmp(form, "bad")) e[10] ^= 0x55; }
  VirtualProtect(e, 16, o, &o); FlushInstructionCache(GetCurrentProcess(), e, 16);
}
static void fake_tool_hook(void) {
  uint8_t *e = (uint8_t *)ga(0x10080DC0u); DWORD o; VirtualProtect(e, 5, PAGE_EXECUTE_READWRITE, &o);
  int32_t d = (int32_t)((uintptr_t)fake_tool_runline - ((uintptr_t)e + 5)); e[0] = 0xE9; memcpy(e + 1, &d, 4);
  VirtualProtect(e, 5, o, &o); FlushInstructionCache(GetCurrentProcess(), e, 5);
}

static int hbmod_run(IDirect3DDevice8 *dev) {
  for (int t = 0; t < 400 && *(uint8_t *)ga(0x1015F6A0u) != 0xE9; t++) {
    IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF000000u, 1.0f, 0); IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL); Sleep(50);
  }
  check(*(uint8_t *)ga(0x1015F6A0u) == 0xE9 && *(uint8_t *)ga(0x10158D90u) == 0xE9, "hbmod: Menu_DrawLayers' and Target_PickNearestToPoint's entries jump (the mod's hooks)");
  check(*(uint8_t *)ga(0x10124930u) == 0xE9 && *(uint8_t *)ga(0x101249E0u) == 0xE9, "hbmod: Cursor_EnterMode1's and Cursor_ToggleFlag1's entries jump (the left button)");
  HMODULE m = GetModuleHandleA("hotbar.dll"); char what[400];
  int (*over)(int, int) = (int (*)(int, int))(void *)GetProcAddress(m, "hb_test_over");
  int (*rect)(int, int, float *) = (int (*)(int, int, float *))(void *)GetProcAddress(m, "hb_test_rect");
  int (*state)(int *, int *, char *, int) = (int (*)(int *, int *, char *, int))(void *)GetProcAddress(m, "hb_test_state");
  void (*focus)(int) = (void (*)(int))(void *)GetProcAddress(m, "hb_test_force_focus");
  int (*env)(int) = (int (*)(int))(void *)GetProcAddress(m, "hb_test_env");
  int (*slot)(int, int, char *, char *, int *, int *, int *) = (int (*)(int, int, char *, char *, int *, int *, int *))(void *)GetProcAddress(m, "hb_test_slot");
  int (*texs)(void) = (int (*)(void))(void *)GetProcAddress(m, "hb_test_textures");
  check(m && over && rect && state && focus && env && slot && texs, "hbmod: the mod's test exports");
  if (!(m && over && rect && state && focus && env && slot && texs)) return 0;
  short *sr = (short *)ga(0x106218B4u); short osr[4]; memcpy(osr, sr, 8); sr[0] = 0; sr[1] = 0; sr[2] = 1280; sr[3] = 960;
  env(1);
  int nb = 0, ns = 0; char last[256] = ""; int runs = state(&nb, &ns, last, sizeof last);
  snprintf(what, sizeof what, "hbmod: hotbar.txt and the XIVhotbar2 files read: %d bars, %d battle slots (2, 7)", nb, ns); check(nb == 2 && ns == 7 && runs == 0, what);
  float b[4] = { 0 }, s1[4] = { 0 }, v1[4] = { 0 }; rect(1, 0, b); rect(1, 1, s1); rect(2, 2, v1);
  snprintf(what, sizeof what, "hbmod: bar 1 at %.0f,%.0f..%.0f,%.0f (200,200..360,260), slot 1 %.0f,%.0f..%.0f,%.0f (208,208..252,252); bar 2 (down) slot 2 %.0f,%.0f..%.0f,%.0f (28,78..72,122)",
           b[0], b[1], b[2], b[3], s1[0], s1[1], s1[2], s1[3], v1[0], v1[1], v1[2], v1[3]);
  check(b[0] == 200 && b[1] == 200 && b[2] == 360 && b[3] == 260 && s1[0] == 208 && s1[3] == 252 && v1[0] == 28 && v1[1] == 78 && v1[2] == 72 && v1[3] == 122, what);
  snprintf(what, sizeof what, "hbmod: hit test: (220,220) %d (101), (330,220) %d (103), (50,150) %d (203), (150,210) %d (1000, the tag), (10,10) %d (0)", over(220, 220), over(330, 220), over(50, 150), over(150, 210), over(10, 10));
  check(over(220, 220) == 101 && over(330, 220) == 103 && over(50, 150) == 203 && over(150, 210) == 1000 && over(10, 10) == 0, what);
  char lab[64], l0[256]; int nl = 0, ic = 0, mp = 0;
  int u = slot(2, 3, lab, l0, &nl, &ic, &mp);
  snprintf(what, sizeof what, "hbmod: XIVhotbar2 war.lua Base 'battle 2 3' ma Cure stpc: \"%s\" -> \"%s\", %d line, MP %d (8, spells.lua), icon %d", lab, l0, nl, mp, ic);
  check(u && !strcmp(lab, "Cure") && !strcmp(l0, "/ma \"Cure\" <stpc>") && nl == 1 && mp == 8 && ic, what);
  u = slot(2, 4, lab, l0, &nl, &ic, &mp);
  snprintf(what, sizeof what, "hbmod: the Sword set's 'battle 2 4' ws Fast Blade: \"%s\" -> \"%s\", icon %d (weapons/02)", lab, l0, ic);
  check(u && !strcmp(lab, "FB") && !strcmp(l0, "/ws \"Fast Blade\" <t>") && ic, what);
  u = slot(2, 2, lab, l0, &nl, &ic, &mp);
  snprintf(what, sizeof what, "hbmod: General.lua Root 'battle 2 2' macro: \"%s\", %d lines, the first \"%s\" (/sit)", lab, nl, l0);
  check(u && !strcmp(lab, "Sit") && nl == 2 && !strcmp(l0, "/sit"), what);
  u = slot(1, 2, lab, l0, &nl, &ic, &mp);
  snprintf(what, sizeof what, "hbmod: hotbar.txt's own 1.2 wins over war.lua's 'battle 1 2' Provoke: \"%s\" -> \"%s\"", lab, l0);
  check(u && !strcmp(lab, "Check") && !strcmp(l0, "/check <t>"), what);
  static uint8_t cursor[0x400], tmng[0x200]; memset(cursor, 0, sizeof cursor); memset(tmng, 0, sizeof tmng);
  void **pcur = (void **)ga(0x104E1D4Cu), *oc = *pcur; *pcur = cursor;
  void **pcam = (void **)ga(0x104568FCu), *ocam = *pcam; *pcam = NULL;
  *(int *)(cursor + 4) = 220; *(int *)(cursor + 8) = 220; tmng[0x55] = 1;
  uint32_t pk = ((PickFn)(void *)ga(0x10158D90u))(tmng);
  snprintf(what, sizeof what, "hbmod: over a slot the world pick returns %u and clears +0x55 (%d) without the game's code", (unsigned)pk, tmng[0x55]);
  check(pk == 0 && tmng[0x55] == 0, what);
  *pcam = ocam;
  uint8_t *mng = (uint8_t *)ga(0x10621838u); uint8_t saved[0xC0]; memcpy(saved, mng, sizeof saved); memset(mng, 0, sizeof saved);
  sr[0] = 0; sr[1] = 0; sr[2] = 1280; sr[3] = 960;                    /* (the screen rectangle is the manager's +0x7C..+0x82: cleared just now) */
  static uint8_t resmng[0x10000]; memset(resmng, 0, sizeof resmng);
  void **pres = (void **)ga(0x1047BFA8u), *orr = *pres; if (!*pres) { *pres = resmng; *(IDirect3DDevice8 **)(resmng + 0xEBC) = dev; *(void **)(resmng + 0xDC8) = g_cdx; }
  if (!*(void **)(g_cdx + 0xC)) *(IDirect3DDevice8 **)(g_cdx + 0xC) = dev;
  DrawLayersFn draw = (DrawLayersFn)(void *)ga(0x1015F6A0u);
  focus(1);
  #define HB_FRAME() do { IDirect3DDevice8_BeginScene(dev); draw(mng); IDirect3DDevice8_EndScene(dev); } while (0)
  for (int f = 0; f < 30; f++) HB_FRAME();
  snprintf(what, sizeof what, "hbmod: %d icons made into textures (WIC) after 30 frames (3 or more)", texs()); check(texs() >= 3, what);
  #define HB_FRAMES4() do { for (int q_ = 0; q_ < 4; q_++) HB_FRAME(); } while (0)      /* (a key runs 3 frames after its press) */
  /* keys by message (the hotbar's default since 24 Nov): the host has no game window, so the hotbar subclasses a window
     of the test's own (hb_test_msg_window), and the test sends it the messages Windows would: WM_KEYDOWN / WM_KEYUP,
     WM_SYSKEYDOWN with lParam bit 29 for Alt, bit 30 for an auto-repeat */
  int (*msgwin)(void *) = (int (*)(void *))(void *)GetProcAddress(m, "hb_test_msg_window");
  HWND kw = CreateWindowExA(0, "STATIC", "hbkeys", WS_POPUP, 0, 0, 8, 8, NULL, NULL, GetModuleHandleA(NULL), NULL);
  int kok = msgwin && kw && msgwin(kw);
  check(kok, "hbmod: the hotbar subclassed a test window for key messages");
  #define KDN(vk) SendMessageA(kw, WM_KEYDOWN, (WPARAM)(vk), 1)
  #define KUP(vk) SendMessageA(kw, WM_KEYUP, (WPARAM)(vk), (LPARAM)0xC0000001u)
  #define KREP(vk) SendMessageA(kw, WM_KEYDOWN, (WPARAM)(vk), (LPARAM)0x40000001u)
  KDN(VK_F9); HB_FRAME(); KUP(VK_F9); HB_FRAMES4();
  runs = state(&nb, &ns, last, sizeof last);
  snprintf(what, sizeof what, "hbmod: F9: %d run(s), the line \"%s\" (/heal)", runs, last); check(runs == 1 && !strcmp(last, "/heal"), what);
  KDN(VK_CONTROL); KDN('1'); HB_FRAME(); KUP('1'); KUP(VK_CONTROL); HB_FRAMES4();
  runs = state(&nb, &ns, last, sizeof last);
  snprintf(what, sizeof what, "hbmod: Ctrl+1: %d runs, the line \"%s\" (/check <t>)", runs, last); check(runs == 2 && !strcmp(last, "/check <t>"), what);
  { /* a key typed into the chat line: the chat buffer ([0x10578490], text at +0x14, cursor +0x114: Input_HandleChar) is a
       test buffer; its text changes after F9's press, as a typed character would: the slot does not run */
    long (*drops)(void) = (long (*)(void))(void *)GetProcAddress(m, "hb_test_typed_drops");
    static uint8_t chatbuf[0x200]; memset(chatbuf, 0, sizeof chatbuf);
    uint8_t **pc = (uint8_t **)ga(0x10578490u), *oc1 = *pc; *pc = chatbuf; long d0 = drops ? drops() : -1;
    KDN(VK_F9); HB_FRAME();
    chatbuf[0x14] = 'x'; chatbuf[0x114] = 1;                    /* the character the key typed */
    KUP(VK_F9); HB_FRAMES4();
    *pc = oc1;
    runs = state(&nb, &ns, last, sizeof last);
    snprintf(what, sizeof what, "hbmod: F9 typed into the chat line (its text changed): still %d runs (2), %ld dropped as typed (1)", runs, drops ? drops() - d0 : -1);
    check(runs == 2 && drops && drops() - d0 == 1, what); }
  /* a press and release over slot 1.3, through the game's entries (the mod's hooks) */
  *(int *)(cursor + 4) = 330; *(int *)(cursor + 8) = 230; *(uint32_t *)(cursor + 0x58) = 0x12340000;
  ((CurFn)(void *)ga(0x10124930u))(cursor); HB_FRAME(); ((CurFn)(void *)ga(0x101249E0u))(cursor); HB_FRAME();
  runs = state(&nb, &ns, last, sizeof last);
  snprintf(what, sizeof what, "hbmod: a left press on slot 1.3: %d runs, \"%s\" (/wave); the cursor's +0x58 %08x (12340000: the game's code did not run)", runs, last, *(uint32_t *)(cursor + 0x58));
  check(runs == 3 && !strcmp(last, "/wave") && *(uint32_t *)(cursor + 0x58) == 0x12340000u, what);
  /* a macro: 2.1 "/wave; wait 0.2; /bow" */
  *(int *)(cursor + 4) = 50; *(int *)(cursor + 8) = 50;
  ((CurFn)(void *)ga(0x10124930u))(cursor); HB_FRAME(); ((CurFn)(void *)ga(0x101249E0u))(cursor);
  runs = state(&nb, &ns, last, sizeof last); int r1 = runs; char first[64]; snprintf(first, sizeof first, "%s", last);
  for (int f = 0; f < 20; f++) { Sleep(20); HB_FRAME(); }
  runs = state(&nb, &ns, last, sizeof last);
  snprintf(what, sizeof what, "hbmod: the macro on 2.1: at once %d runs \"%s\" (4, /wave); 400 ms later %d runs \"%s\" (5, /bow)", r1, first, runs, last);
  check(r1 == 4 && !strcmp(first, "/wave") && runs == 5 && !strcmp(last, "/bow"), what);
  /* the tag, then an hb command slot in the field set */
  *(int *)(cursor + 4) = 150; *(int *)(cursor + 8) = 210;
  ((CurFn)(void *)ga(0x10124930u))(cursor); HB_FRAME(); ((CurFn)(void *)ga(0x101249E0u))(cursor); HB_FRAME();
  int e1 = env(-1);
  *(int *)(cursor + 4) = 50; *(int *)(cursor + 8) = 100;
  ((CurFn)(void *)ga(0x10124930u))(cursor); HB_FRAME(); ((CurFn)(void *)ga(0x101249E0u))(cursor); HB_FRAME();
  int e2 = env(-1);
  snprintf(what, sizeof what, "hbmod: the tag switched battle to %d (0, field); field's 2.2 \"hb env battle\" back to %d (1)", e1, e2);
  check(e1 == 0 && e2 == 1, what);
  { /* xikit_cmd.hpp: a typed "/HB env field" through the game's Command_RunLine entry reaches the mod's hook, which takes
       it (returns 0) without the game's code */
    typedef int (__cdecl *RunFn)(char *, uint32_t); char line[] = "/HTB env field";
    int rr = ((RunFn)(void *)ga(0x10080DC0u))(line, 0); int e3 = env(-1);
    snprintf(what, sizeof what, "hbmod: \"/HTB env field\" through Command_RunLine: returned %d (0), environment %d (0, field)", rr, e3);
    check(*(uint8_t *)ga(0x10080DC0u) == 0xE9 && rr == 0 && e3 == 0, what);
    /* another tool's hook was at the entry first (fake_tool_hook): a line the hotbar does not take reaches it */
    char other[] = "/wave"; long fc = g_fake_tool_calls; int ro = ((RunFn)(void *)ga(0x10080DC0u))(other, 0);
    snprintf(what, sizeof what, "hbmod: with another tool's jmp at Command_RunLine first: \"/wave\" returned %d (7: the other tool's), the other tool called %ld time(s) (1); \"/HTB env field\" did not reach it", ro, g_fake_tool_calls - fc);
    check(ro == 7 && g_fake_tool_calls - fc == 1, what);
    /* "/htb run 1.1": the slot runs as its key or a click runs it */
    int r0 = state(&nb, &ns, last, sizeof last); char l2[] = "/htb run 1.1";
    rr = ((RunFn)(void *)ga(0x10080DC0u))(l2, 0); HB_FRAME();
    runs = state(&nb, &ns, last, sizeof last);
    snprintf(what, sizeof what, "hbmod: \"/htb run 1.1\": returned %d (0), %d run(s) more (1), the line \"%s\" (/heal)", rr, runs - r0, last);
    check(rr == 0 && runs - r0 == 1 && !strcmp(last, "/heal"), what); }
  { /* the default keys: 1.3 has none of its own ("none"), so it has 3; 1.1 was given f9, so 1 runs nothing */
    int r0 = state(&nb, &ns, last, sizeof last);
    KDN('1'); HB_FRAME(); KUP('1'); HB_FRAMES4();
    int r1 = state(&nb, &ns, last, sizeof last);
    KDN('3'); HB_FRAME(); KUP('3'); HB_FRAMES4();
    runs = state(&nb, &ns, last, sizeof last);
    snprintf(what, sizeof what, "hbmod: default keys: 1 ran %d (0: 1.1 has f9); 3 ran %d (1), the line \"%s\" (/wave)", r1 - r0, runs - r1, last);
    check(r1 == r0 && runs - r1 == 1 && !strcmp(last, "/wave"), what);
    /* a held key's auto-repeat (lParam bit 30) runs nothing more */
    int r2 = state(&nb, &ns, last, sizeof last);
    KDN('3'); HB_FRAME(); KREP('3'); KREP('3'); HB_FRAMES4(); KUP('3'); HB_FRAMES4();
    runs = state(&nb, &ns, last, sizeof last);
    snprintf(what, sizeof what, "hbmod: 3 held (one press, two auto-repeats): %d run(s) (1)", runs - r2); check(runs - r2 == 1, what); }
  { /* the game's macros (hb_mode 1, the default): TextInputFiles_QueueEntry (0x101A1C60, thiscall, entry 0-19) through its
       entry. Entry 1 (palette 1, macro 2) -> bar 2 slot 2, field's "hb env battle": taken, the game's code not run (+0x21C4
       left as it was); entry 10 (palette 2, macro 1) -> bar 3, which hotbar.txt has not: the game's own QueueEntry runs
       and copies entry 10 (its first line at +4 of the entry, entry n at +4 + n * 0x17C) to the running one at +0x2048 */
    typedef uint32_t (__thiscall *QueueFn)(void *, int);
    void (*mac)(long *, long *) = (void (*)(long *, long *))(void *)GetProcAddress(m, "hb_test_macros");
    static uint8_t tif[0x2400]; memset(tif, 0, sizeof tif); *(uint32_t *)(tif + 0x21C4) = 0xFFFFFFFFu;
    strcpy((char *)tif + 4 + 10 * 0x17C + 4, "/sit");
    long t0 = 0, p0 = 0, t1 = 0, p1 = 0; if (mac) mac(&t0, &p0);
    int e0 = env(-1);
    uint32_t q1 = ((QueueFn)(void *)ga(0x101A1C60u))(tif, 1); HB_FRAME(); int e1 = env(-1); uint32_t run1 = *(uint32_t *)(tif + 0x21C4);
    uint32_t q2 = ((QueueFn)(void *)ga(0x101A1C60u))(tif, 10); if (mac) mac(&t1, &p1);
    snprintf(what, sizeof what, "hbmod: macros: QueueEntry(1) returned %u (1), the set %d -> %d (0 -> 1: bar 2 slot 2 ran), +0x21C4 %08x (ffffffff: the game's code not run); "
             "QueueEntry(10) returned %u (1), +0x21C4 %u (0), the running entry's line \"%s\" (/sit: the game's code ran); taken %ld, passed %ld (1, 1)",
             q1, e0, e1, run1, q2, *(uint32_t *)(tif + 0x21C4), (char *)tif + 0x2048 + 4, t1 - t0, p1 - p0);
    check(mac && *(uint8_t *)ga(0x101A1C60u) == 0xE9 && q1 == 1 && e0 == 0 && e1 == 1 && run1 == 0xFFFFFFFFu && q2 == 1 && *(uint32_t *)(tif + 0x21C4) == 0 &&
          !strcmp((char *)tif + 0x2048 + 4, "/sit") && t1 - t0 == 1 && p1 - p0 == 1, what);
    /* the game's macro palettes in hotbar mode: MenuMng_OpenByName (0x1015E350, thiscall) through its entry with
       "menu    mcr1pall" and "menu    mcr2pall": refused (0) by the mod, counted. (In macro mode the call goes on to the
       game's code, which the host's empty menu manager cannot run: not called here.) */
    typedef int (__thiscall *OpenFn)(void *, char *, uint32_t, uint32_t);
    long (*pal)(void) = (long (*)(void))(void *)GetProcAddress(m, "hb_test_palettes");
    char p1n[] = "menu    mcr1pall", p2n[] = "menu    mcr2pall";
    long pc0 = pal ? pal() : -1;
    int o1 = ((OpenFn)(void *)ga(0x1015E350u))(mng, p1n, 1, 0), o2 = ((OpenFn)(void *)ga(0x1015E350u))(mng, p2n, 1, 0);
    long pc1 = pal ? pal() : -1;
    snprintf(what, sizeof what, "hbmod: hotbar mode: MenuMng_OpenByName(\"%s\") returned %d, (\"%s\") %d (0, 0); refused %ld (2)", p1n, o1, p2n, o2, pc1 - pc0);
    check(pal && *(uint8_t *)ga(0x1015E350u) == 0xE9 && o1 == 0 && o2 == 0 && pc1 - pc0 == 2, what);
    typedef int (__cdecl *RunFn)(char *, uint32_t); char ml[] = "/htb mode macro"; char cwd[MAX_PATH], ini[MAX_PATH + 20];
    int rr = ((RunFn)(void *)ga(0x10080DC0u))(ml, 0); GetCurrentDirectoryA(sizeof cwd, cwd); snprintf(ini, sizeof ini, "%s\\xikit_mods.ini", cwd);
    int md = GetPrivateProfileIntA("hotbar", "hb_mode", -1, ini);
    snprintf(what, sizeof what, "hbmod: \"/htb mode macro\": returned %d (0), hb_mode in xikit_mods.ini %d (0)", rr, md); check(rr == 0 && md == 0, what);
  }
  { /* (29 Nov) Petit Trois's commands and layout mode (/htb move): set, rename, clear; slots dragged onto slots and off
       the bars; a bar's handle; the picker's tabs, list and an action dropped on a slot; a bar dragged. The slots go to
       hotbar_slots_war.txt, the bars to hotbar_layout.txt */
    typedef int (__cdecl *RunFn)(char *, uint32_t); typedef void (__attribute__((thiscall)) *CurFn2)(void *);
    int (*hnd)(int, int, float *) = (int (*)(int, int, float *))(void *)GetProcAddress(m, "hb_test_handle");
    int (*pkr)(int, float *) = (int (*)(int, float *))(void *)GetProcAddress(m, "hb_test_pk_rect");
    int (*pick)(int *, char *, int) = (int (*)(int *, char *, int))(void *)GetProcAddress(m, "hb_test_pick");
    int (*edit)(void) = (int (*)(void))(void *)GetProcAddress(m, "hb_test_edit");
    check(hnd && pkr && pick && edit, "hbmod: layout mode's test exports");
    #define RUNL(t) do { char _l[] = t; ((RunFn)(void *)ga(0x10080DC0u))(_l, 0); HB_FRAME(); } while (0)
    #define AT(x_, y_) do { *(int *)(cursor + 4) = (int)(x_); *(int *)(cursor + 8) = (int)(y_); } while (0)
    #define PRESS() do { ((CurFn2)(void *)ga(0x10124930u))(cursor); HB_FRAME(); } while (0)
    #define RELEASE() do { ((CurFn2)(void *)ga(0x101249E0u))(cursor); HB_FRAME(); } while (0)
    char lab[48], l0[200]; int nl, ic, mp;
    env(1); RUNL("/htb set 1 3 ma Cure stpc My_Cure");
    slot(1, 3, lab, l0, &nl, &ic, &mp);
    snprintf(what, sizeof what, "hbmod: \"/htb set 1 3 ma Cure stpc My_Cure\": 1.3 \"%s\" -> \"%s\", MP %d (My Cure, /ma \"Cure\" <stpc>, 8)", lab, l0, mp);
    check(!strcmp(lab, "My Cure") && !strcmp(l0, "/ma \"Cure\" <stpc>") && mp == 8, what);
    { FILE *sf = fopen("hotbar_slots_war.txt", "r"); char buf[2048] = ""; if (sf) { buf[fread(buf, 1, sizeof buf - 1, sf)] = 0; fclose(sf); }
      check(strstr(buf, "put battle 1.3 xiv|ma|Cure|stpc|My Cure|") != NULL, "hbmod: hotbar_slots_war.txt has \"put battle 1.3 xiv|ma|Cure|stpc|My Cure|\""); }
    RUNL("/htb rename 1 3 Heal_Me"); slot(1, 3, lab, l0, &nl, &ic, &mp);
    snprintf(what, sizeof what, "hbmod: \"/htb rename 1 3 Heal_Me\": 1.3 \"%s\" -> \"%s\" (Heal Me, the same line)", lab, l0);
    check(!strcmp(lab, "Heal Me") && !strcmp(l0, "/ma \"Cure\" <stpc>"), what);
    RUNL("/htb move"); check(edit() == 1, "hbmod: \"/htb move\": layout mode on");
    int runs0 = state(&nb, &ns, last, sizeof last);
    float r[4], r2[4];
    rect(1, 3, r); rect(1, 1, r2);
    AT((r[0] + r[2]) / 2, (r[1] + r[3]) / 2); PRESS(); AT((r2[0] + r2[2]) / 2, (r2[1] + r2[3]) / 2); HB_FRAME(); RELEASE();
    char la[48], lb[48]; slot(1, 1, la, l0, &nl, &ic, &mp); slot(1, 3, lb, l0, &nl, &ic, &mp);
    snprintf(what, sizeof what, "hbmod: layout mode: 1.3 dragged onto 1.1: 1.1 \"%s\", 1.3 \"%s\" (Heal Me, Heal: swapped); nothing ran", la, lb);
    check(!strcmp(la, "Heal Me") && !strcmp(lb, "Heal"), what);
    AT((r[0] + r[2]) / 2, (r[1] + r[3]) / 2); PRESS(); AT(600, 450); HB_FRAME(); RELEASE();
    int u = slot(1, 3, lb, l0, &nl, &ic, &mp);
    snprintf(what, sizeof what, "hbmod: layout mode: 1.3 dragged off the bars: emptied (%d, 0)", u); check(u == 0, what);
    float w0 = r[2] - r[0]; rect(1, 0, r); w0 = r[2] - r[0];
    hnd(1, 3, r2); AT((r2[0] + r2[2]) / 2, (r2[1] + r2[3]) / 2); PRESS(); RELEASE();
    rect(1, 0, r);
    { FILE *lf = fopen("hotbar_layout.txt", "r"); char buf[1024] = ""; if (lf) { buf[fread(buf, 1, sizeof buf - 1, lf)] = 0; fclose(lf); }
      snprintf(what, sizeof what, "hbmod: bar 1's handle +: the bar %.0f px wide (was %.0f: a slot more); hotbar_layout.txt has \"bar 1 4 100 100 c4\" (one row of 4)", r[2] - r[0], w0);
      check(r[2] - r[0] > w0 && strstr(buf, "bar 1 4 100 100 c4\n") != NULL, what); }
    int tab; char first[48];
    pkr(11, r2); AT((r2[0] + r2[2]) / 2, (r2[1] + r2[3]) / 2); PRESS(); RELEASE();
    int nt = pick(&tab, first, sizeof first);
    snprintf(what, sizeof what, "hbmod: the picker's Trusts tab: tab %d, %d action(s), the first \"%s\" (1, 1, Shantotto)", tab, nt, first);
    check(tab == 1 && nt == 1 && !strcmp(first, "Shantotto"), what);
    pkr(10, r2); AT((r2[0] + r2[2]) / 2, (r2[1] + r2[3]) / 2); PRESS(); RELEASE();
    int nm = pick(&tab, first, sizeof first);
    snprintf(what, sizeof what, "hbmod: the picker's Magic tab: %d action(s), the first \"%s\" (2, Cure: Cure and Stone, no trusts; no job known in the test, so no level filter)", nm, first);
    check(tab == 0 && nm == 2 && !strcmp(first, "Cure"), what);
    pkr(100, r2); rect(1, 4, r);
    AT((r2[0] + r2[2]) / 2, (r2[1] + r2[3]) / 2); PRESS(); AT((r[0] + r[2]) / 2, (r[1] + r[3]) / 2); HB_FRAME(); RELEASE();
    u = slot(1, 4, lb, l0, &nl, &ic, &mp);
    snprintf(what, sizeof what, "hbmod: the picker's Cure dropped on 1.4: %d \"%s\" -> \"%s\" (1, Cure, /ma \"Cure\" <t>: Cure's targets 63 hold Enemy, so Petit Trois's rule gives t)", u, lb, l0);
    check(u == 1 && !strcmp(lb, "Cure") && !strcmp(l0, "/ma \"Cure\" <t>"), what);
    rect(1, 0, r); hnd(1, 0, r2);
    AT(r2[0] + 2, r2[1] + 2); PRESS(); AT(r2[0] + 42, r2[1] + 22); HB_FRAME(); RELEASE();
    float rn[4]; rect(1, 0, rn);
    { FILE *lf = fopen("hotbar_layout.txt", "r"); char buf[1024] = ""; if (lf) { buf[fread(buf, 1, sizeof buf - 1, lf)] = 0; fclose(lf); }
      snprintf(what, sizeof what, "hbmod: bar 1 dragged by its handle 40,20 px: now at %.0f,%.0f (240,220); hotbar_layout.txt has \"bar 1 4 120 110 c4\"", rn[0], rn[1]);
      check(rn[0] == r[0] + 40 && rn[1] == r[1] + 20 && strstr(buf, "bar 1 4 120 110 c4\n") != NULL, what); }
    int runs1 = state(&nb, &ns, last, sizeof last);
    snprintf(what, sizeof what, "hbmod: in layout mode presses on slots ran nothing (%d runs, %d before)", runs1, runs0); check(runs1 == runs0, what);
    RUNL("/htb move"); check(edit() == 0, "hbmod: \"/htb move\" again: layout mode off");
    RUNL("/htb clear 1 4"); u = slot(1, 4, lb, l0, &nl, &ic, &mp);
    snprintf(what, sizeof what, "hbmod: \"/htb clear 1 4\": emptied (%d, 0)", u); check(u == 0, what);
    remove("hotbar_layout.txt"); remove("hotbar_slots_war.txt");
    /* (29 Nov) bar shapes (FFXIV's 12x1 .. 1x12): /htb bar 2 4 c2 makes bar 2 two by two; the handle's shape steps it */
    RUNL("/htb bar 2 4 c2"); float s1[4], s2[4], s3[4];
    rect(2, 1, s1); rect(2, 2, s2); rect(2, 3, s3);
    snprintf(what, sizeof what, "hbmod: \"/htb bar 2 4 c2\": slot 2 right of slot 1 (%.0f > %.0f, same row %.0f), slot 3 under slot 1 (%.0f > %.0f, same column %.0f)", s2[0], s1[0], s2[1], s3[1], s1[1], s3[0]);
    check(s2[0] > s1[0] && s2[1] == s1[1] && s3[1] > s1[1] && s3[0] == s1[0], what);
    RUNL("/htb move"); hnd(2, 1, r2); AT((r2[0] + r2[2]) / 2, (r2[1] + r2[3]) / 2); PRESS(); RELEASE(); RUNL("/htb move");
    rect(2, 1, s1); rect(2, 2, s2);
    { FILE *lf = fopen("hotbar_layout.txt", "r"); char buf[1024] = ""; if (lf) { buf[fread(buf, 1, sizeof buf - 1, lf)] = 0; fclose(lf); }
      snprintf(what, sizeof what, "hbmod: bar 2's shape handle: 2x2 -> 1x4 (slot 2 under slot 1: %.0f > %.0f, same column); hotbar_layout.txt has \"bar 2 4 10 10 c1\"", s2[1], s1[1]);
      check(s2[1] > s1[1] && s2[0] == s1[0] && strstr(buf, "bar 2 4 10 10 c1\n") != NULL, what); }
    /* shared bars: their slots go to hotbar_slots.txt, for every job */
    RUNL("/htb bar 1 4 shared"); RUNL("/htb set 1 1 ma Cure t");
    { FILE *a1 = fopen("hotbar_slots.txt", "r"), *a2 = fopen("hotbar_slots_war.txt", "r"); char b1[1024] = "", b2[1024] = "";
      if (a1) { b1[fread(b1, 1, sizeof b1 - 1, a1)] = 0; fclose(a1); } if (a2) { b2[fread(b2, 1, sizeof b2 - 1, a2)] = 0; fclose(a2); }
      slot(1, 1, lb, l0, &nl, &ic, &mp);
      snprintf(what, sizeof what, "hbmod: bar 1 shared: \"/htb set 1 1 ma Cure t\" in hotbar_slots.txt (%d), not in hotbar_slots_war.txt (%d); 1.1 \"%s\"", strstr(b1, "put battle 1.1 xiv|ma|Cure|t||") != NULL, strstr(b2, "1.1") != NULL, lb);
      check(strstr(b1, "put battle 1.1 xiv|ma|Cure|t||") != NULL && strstr(b2, "1.1") == NULL && !strcmp(lb, "Cure"), what); }
    /* tooltips: Petit Trois's lines (text_formatter.lua) from the tables and descriptions */
    int (*tip)(int, int, char *, int) = (int (*)(int, int, char *, int))(void *)GetProcAddress(m, "hb_test_tip");
    int (*sst)(int, int, int *) = (int (*)(int, int, int *))(void *)GetProcAddress(m, "hb_test_slotstate");
    check(tip && sst, "hbmod: the tooltip's and the slot state's test exports");
    RUNL("/htb set 1 2 ws Fast_Blade t"); RUNL("/htb set 1 3 ja Provoke t");
    static char tt[2048];
    tip(1, 1, tt, sizeof tt);
    snprintf(what, sizeof what, "hbmod: Cure's tooltip: [Cure], Target, the description, Range 20.4y and MP Cost 8MP, Cast 2s Recast 5s (%s)", tt);
    check(strstr(tt, "[Cure]   Target: <t>") && strstr(tt, "Restores target's HP.") && strstr(tt, "Range: 20.4y    MP Cost: 8MP") && strstr(tt, "Cast: 2s    Recast: 5s"), what);
    tip(1, 2, tt, sizeof tt);
    snprintf(what, sizeof what, "hbmod: Fast Blade's tooltip: its description (ability_descriptions [32]), SC: Scission, Range 3.4y (%s)", tt);
    check(strstr(tt, "[Fast Blade]") && strstr(tt, "Delivers a two-hit attack.") && strstr(tt, "SC: Scission") && strstr(tt, "Range: 3.4y"), what);
    tip(1, 3, tt, sizeof tt);
    snprintf(what, sizeof what, "hbmod: Provoke's tooltip: its description (ability_descriptions [35 + 512]), Range 16.4y (%s)", tt);
    check(strstr(tt, "[Provoke]") && strstr(tt, "Goads an enemy into attacking you.") && strstr(tt, "Range: 16.4y"), what);
    /* the slot state from the game's code: with no abilities' table, Provoke is not confirmed (rec -1 after the check) and
       keeps Petit Trois's recast_id; then the table with record 0x223 (35 + 0x200: id 35, type 1, timer 5) and the recast
       object 0x10666EC0 with timer 5 at 600 ticks: the game's record, its countdown, its check (2: recast) */
    int o7[7];
    HB_FRAME(); sst(1, 3, o7);
    snprintf(what, sizeof what, "hbmod: Provoke with no abilities' table: kind %d, record %d (2, -2: not checked yet); its timer by Petit Trois's recast_id", o7[0], o7[1]);
    check(o7[0] == 2 && o7[1] == -2, what);
    void **pab = (void **)ga(0x1066714Cu); void *kab = *pab; static uint8_t abt[0xB00 * 0x30]; memset(abt, 0, sizeof abt); *pab = abt;
    uint8_t *rec = abt + 0x223 * 0x30; *(uint16_t *)rec = 35; rec[2] = 1; *(uint16_t *)(rec + 8) = 5; rec[0xF] = 1;
    uint8_t *ro = (uint8_t *)ga(0x10666EC0u), kro[0x180]; memcpy(kro, ro, sizeof kro);
    for (int e = 0; e < 0x1F; e++) { ro[e * 8 + 2] = 0; ro[e * 8 + 3] = 0xFF; *(int16_t *)(ro + e * 8 + 4) = 0; }
    ro[3] = 5; *(int *)(ro + 0xF8) = 600;
    RUNL("/htb set 1 3 ja Provoke t");                              /* (the slot set again: its state checked afresh) */
    for (int f = 0; f < 7; f++) HB_FRAME();
    sst(1, 3, o7);
    /* (the game's check gives 1 here: this host has no player entry, NetCellFont_SetByte9800AndGetEntry(0); its 2 and 0 for
       a running and an ended recast are checked in staterun, which has one) */
    snprintf(what, sizeof what, "hbmod: Provoke with the game's table: kind %d, record 0x%X (0x223), ticks %d (600), total %d, charges %d (-1), state %d (1: the game's check, no player entry here)", o7[0], o7[1], o7[2], o7[3], o7[4], o7[6]);
    check(o7[0] == 2 && o7[1] == 0x223 && o7[2] == 600 && o7[3] == 600 && o7[4] == -1 && o7[6] == 1, what);
    tip(1, 3, tt, sizeof tt);
    snprintf(what, sizeof what, "hbmod: Provoke's tooltip has \"Recast: 10\" and the game's answer \"Cannot use now: not there (the game's check: 1)\" (%s)", tt);
    check(strstr(tt, "Recast: 10") && strstr(tt, "Cannot use now: not there (the game's check: 1)"), what);
    *(int *)(ro + 0xF8) = 300; for (int f = 0; f < 7; f++) HB_FRAME(); sst(1, 3, o7);
    snprintf(what, sizeof what, "hbmod: the countdown at 300: ticks %d, total %d (300, 600: the sweep half)", o7[2], o7[3]); check(o7[2] == 300 && o7[3] == 600, what);
    *(int *)(ro + 0xF8) = 0; for (int f = 0; f < 7; f++) HB_FRAME(); sst(1, 3, o7);
    snprintf(what, sizeof what, "hbmod: the countdown at 0: ticks %d (0), total %d (0: no sweep)", o7[2], o7[3]); check(o7[2] == 0 && o7[3] == 0, what);
    /* a record that does not match (id 99 at 0x223): not the game's record, not dimmed */
    *(uint16_t *)rec = 99; RUNL("/htb clear 1 3"); RUNL("/htb set 1 3 ja Provoke t"); for (int f = 0; f < 7; f++) HB_FRAME(); sst(1, 3, o7);
    snprintf(what, sizeof what, "hbmod: record 0x223 with id 99: record %d (-1: not the same, Petit Trois's recast_id kept), state %d (-1)", o7[1], o7[6]);
    check(o7[1] == -1 && o7[6] == -1, what);
    memcpy(ro, kro, sizeof kro); *pab = kab;
    /* the picker's Ability and WSkills tabs by the game's lists: game state +0x2CDE8 (one bit a record; +0x2CF49 and
       +0x2CF4A set when they came): record 0x223 (Provoke, 35 + 0x200) and 32 (Fast Blade) on; Sic (255 + 0x200) off */
    RUNL("/htb move");
    int tab2; char first2[48];
    pkr(12, r2); AT((r2[0] + r2[2]) / 2, (r2[1] + r2[3]) / 2); PRESS(); RELEASE();
    int na0 = pick(&tab2, first2, sizeof first2);
    uint8_t **gsp2 = (uint8_t **)ga(0x104DFD98u); uint8_t *kgs = *gsp2; static uint8_t gst2[0x30000]; memset(gst2, 0, sizeof gst2); *gsp2 = gst2;
    gst2[0x2CDE8 + (0x223 >> 3)] |= 1 << (0x223 & 7); gst2[0x2CDE8 + (32 >> 3)] |= 1 << (32 & 7); gst2[0x2CF49] = gst2[0x2CF4A] = 1;
    int na1 = pick(&tab2, first2, sizeof first2);
    snprintf(what, sizeof what, "hbmod: the picker's Ability tab: %d before the game's list (3: Provoke, Sic, Geocrush; not Foot Kick, a Monster row), %d after it, the first \"%s\" (1, Provoke)", na0, na1, first2);
    check(tab2 == 2 && na0 == 3 && na1 == 1 && !strcmp(first2, "Provoke"), what);
    pkr(13, r2); AT((r2[0] + r2[2]) / 2, (r2[1] + r2[3]) / 2); PRESS(); RELEASE();
    int nw = pick(&tab2, first2, sizeof first2);
    snprintf(what, sizeof what, "hbmod: the picker's WSkills tab by the game's list: %d, \"%s\" (1, Fast Blade)", nw, first2);
    check(tab2 == 3 && nw == 1 && !strcmp(first2, "Fast Blade"), what);
    gst2[0x2CDE8 + (32 >> 3)] = 0; nw = pick(&tab2, first2, sizeof first2);
    snprintf(what, sizeof what, "hbmod: Fast Blade's bit off: %d weapon skills (0)", nw); check(nw == 0, what);
    *gsp2 = kgs; RUNL("/htb move");
    /* (29 Nov) skillchains: a message 0x028 built field by field as the game's reader reads it (LSB first from byte 5:
       actor 32, targets 6, 4, category 4, param 32, 32; a target's id 32 and actions 4; an action's 3, 2, 12, 5, 5, param 17,
       message 10, 31, the added effect's and the spike's flag bits), parsed by the game's own 0x1018CA40 (thiscall (status,
       message + 4), ret 4: data/purges.json) into a status the game's 0x1018C610 made: the parser hands the record to
       fn_1018D170, which the hotbar hooks. Petit Trois's rules then: Burning Blade (Liquefaction), 3 s .. 10 s later Fast
       Blade (Scission) makes Scission (level 1); Stone (earth) bursts on it for 10 s. */
    { void (*sct)(unsigned, int, long *, long *) = (void (*)(unsigned, int, long *, long *))(void *)GetProcAddress(m, "hb_test_sc");
      int (*scs)(int, int, char *, int, int *) = (int (*)(int, int, char *, int, int *))(void *)GetProcAddress(m, "hb_test_scslot");
      void (*clk)(int) = (void (*)(int))(void *)GetProcAddress(m, "hb_test_clock");
      check(sct && scs && clk, "hbmod: the skillchain test exports");
      typedef void *(__attribute__((fastcall)) *StCtor)(void *);
      typedef int (__attribute__((thiscall)) *Parse)(void *, void *);
      RUNL("/htb set 1 1 ma Stone t"); RUNL("/htb set 1 2 ws Fast_Blade t");
      const unsigned tgt = 0x01020304u; long seen0 = 0, used0 = 0, seen1 = 0, used1 = 0;
      sct(tgt, 0, &seen0, &used0);
      int hooked_sc = 0; { FILE *lf = fopen("xikit.log", "r"); char lb2[512]; if (lf) { while (fgets(lb2, sizeof lb2, lf)) if (strstr(lb2, "fn_1018D170") && strstr(lb2, "refused")) hooked_sc = -1; fclose(lf); } }
      check(hooked_sc == 0, "hbmod: the action message hook (fn_1018D170) taken (no \"refused\" line in xikit.log)");
      #define SC_ACT(param_, msg_) do { static uint8_t pk[256]; memset(pk, 0, sizeof pk); int bp = 5 * 8; \
        uint32_t fv[] = { 0x0A0B0C0Du, 1, 0, 3, (param_), 0, tgt, 1, 0, 0, 0, 0, 0, 0, (msg_), 0, 0, 0 }; \
        int fw[] = { 32, 6, 4, 4, 32, 32, 32, 4, 3, 2, 12, 5, 5, 17, 10, 31, 1, 1 }; \
        for (int f_ = 0; f_ < (int)(sizeof fw / sizeof fw[0]); f_++) for (int k_ = 0; k_ < fw[f_]; k_++, bp++) if ((fv[f_] >> k_) & 1) pk[bp >> 3] |= (uint8_t)(1 << (bp & 7)); \
        static uint8_t st[16]; ((StCtor)(void *)ga(0x1018C610u))(st); ((Parse)(void *)ga(0x1018CA40u))(st, pk + 4); } while (0)
      host_allocator(1);
      SC_ACT(33, 185);                                                   /* Burning Blade, message 185 (a weapon skill's, Petit Trois's number) */
      sct(tgt, 0, &seen1, &used1);
      snprintf(what, sizeof what, "hbmod: the game's parser handed the record to the hook: seen %ld -> %ld, used %ld -> %ld (one more each)", seen0, seen1, used0, used1);
      check(seen1 == seen0 + 1 && used1 == used0 + 1, what);
      char pr[24]; int lvl = 0, r0 = scs(1, 2, pr, sizeof pr, &lvl);
      snprintf(what, sizeof what, "hbmod: Fast Blade at once after Burning Blade: %d (0: under 3 s, no chain)", r0); check(r0 == 0, what);
      clk(4000); r0 = scs(1, 2, pr, sizeof pr, &lvl);
      snprintf(what, sizeof what, "hbmod: Fast Blade 4 s after: %d \"%s\" level %d (1, Scission, 1)", r0, pr, lvl); check(r0 == 1 && !strcmp(pr, "Scission") && lvl == 1, what);
      tip(1, 2, tt, sizeof tt);
      snprintf(what, sizeof what, "hbmod: Fast Blade's tooltip says \"Skillchain: Scission (level 1)\" (%s)", tt); check(strstr(tt, "Skillchain: Scission (level 1)") != NULL, what);
      r0 = scs(1, 1, pr, sizeof pr, &lvl);
      snprintf(what, sizeof what, "hbmod: Stone before a chain formed: %d (0)", r0); check(r0 == 0, what);
      SC_ACT(32, 185);                                                   /* Fast Blade lands: Scission forms */
      r0 = scs(1, 1, pr, sizeof pr, &lvl);
      snprintf(what, sizeof what, "hbmod: Stone after Scission formed: %d (2: a magic burst, earth)", r0); check(r0 == 2, what);
      /* (29 Nov) the rest of Petit Trois's: a blood pact rage that bloodpacts.lua calls magic bursts by its element (Geocrush,
         earth); a BST pet's command (Foot Kick, type Monster) chains as the monster ability 3840 of that name in Windower's
         res\monster_abilities.lua (Reverberation: Scission -> Reverberation, level 1); a monster ability's id (3840)
         in a weapon skill's message applies its properties */
      RUNL("/htb set 1 3 ja Geocrush t"); RUNL("/htb set 1 4 ja Foot_Kick t");
      r0 = scs(1, 3, pr, sizeof pr, &lvl);
      snprintf(what, sizeof what, "hbmod: Geocrush after Scission formed: %d (2: a magic burst, its bloodpacts.lua row magic)", r0); check(r0 == 2, what);
      r0 = scs(1, 4, pr, sizeof pr, &lvl);
      snprintf(what, sizeof what, "hbmod: Foot Kick at once after Fast Blade: %d (0: under 3 s)", r0); check(r0 == 0, what);
      clk(4000); r0 = scs(1, 4, pr, sizeof pr, &lvl);
      snprintf(what, sizeof what, "hbmod: Foot Kick (the pet's, as Windower's monster ability 3840) 4 s after: %d \"%s\" level %d (1, Reverberation, 1)", r0, pr, lvl);
      check(r0 == 1 && !strcmp(pr, "Reverberation") && lvl == 1, what);
      SC_ACT(3840, 185);                                                 /* the pet's Foot Kick lands: Reverberation forms */
      char scp[64] = ""; int (*scprops)(char *, int) = (int (*)(char *, int))(void *)GetProcAddress(m, "hb_test_scprops");
      if (scprops) scprops(scp, sizeof scp);
      r0 = scs(1, 1, pr, sizeof pr, &lvl);
      snprintf(what, sizeof what, "hbmod: after monster ability 3840: the target's property \"%s\" (Reverberation), Stone %d (0: earth does not burst on it)", scp, r0);
      check(!strcmp(scp, "Reverberation") && r0 == 0, what);
      SC_ACT(32, 15);                                                    /* (message 15, not a weapon skill's: seen, not used) */
      host_allocator(0);
      sct(tgt, 0, &seen1, &used1);
      snprintf(what, sizeof what, "hbmod: a message 15 action: seen %ld, used %ld (seen +4, used +3)", seen1, used1); check(seen1 == seen0 + 4 && used1 == used0 + 3, what);
      RUNL("/htb sc");
      clk(11000); r0 = scs(1, 1, pr, sizeof pr, &lvl);
      snprintf(what, sizeof what, "hbmod: Stone 11 s after the chain: %d (0: the burst window is 10 s)", r0); check(r0 == 0, what);
      sct(0, -1, NULL, NULL);
      #undef SC_ACT
    }
    /* (29 Nov) items, from the game's inventory table (game state +0x9868 + (bag x 0x51 + index) x 0x2C: id, count) and
       Windower's items.lua: an item slot's count is bag 3's and bag 0's together (Petit Trois), its icon Petit Trois's
       images/icons/items/<id>.bmp; an autoitem slot is the first usable item whose name holds the filter, labelled as
       shorten_ability_name labels it; the main weapon's skill reads the job file's table of that name as a set. */
    { uint8_t **gsp = (uint8_t **)ga(0x104DFD98u); uint8_t *kgs = *gsp; static uint8_t gst[0x30000]; memset(gst, 0, sizeof gst); *gsp = gst;
      #define INV(bag_, idx_, id_, n_) do { uint8_t *e_ = gst + 0x9868 + ((bag_) * 0x51 + (idx_)) * 0x2C; *(uint16_t *)e_ = (id_); *(int32_t *)(e_ + 4) = (n_); } while (0)
      INV(0, 1, 4112, 12); INV(3, 1, 4112, 3); INV(0, 2, 16535, 1);
      int (*itm)(int, int, int *, int *) = (int (*)(int, int, int *, int *))(void *)GetProcAddress(m, "hb_test_item");
      void (*wpn)(int) = (void (*)(int))(void *)GetProcAddress(m, "hb_test_weapon");
      check(itm && wpn, "hbmod: the item test exports");
      RUNL("/htb set 1 1 item Potion me"); RUNL("/htb set 1 2 autoitem Pot");
      int iid = 0, icn = 0; itm(1, 1, &iid, &icn); slot(1, 1, lb, l0, &nl, &ic, &mp);
      { const char *ipath = NULL; (void)ipath; }
      snprintf(what, sizeof what, "hbmod: item slot Potion: id %d (4112, Windower's items.lua), count %d (15: 12 in bag 0, 3 in bag 3), icon %d", iid, icn, ic);
      check(iid == 4112 && icn == 15 && ic, what);
      itm(1, 2, &iid, &icn); slot(1, 2, lb, l0, &nl, &ic, &mp);
      snprintf(what, sizeof what, "hbmod: autoitem \"Pot\": \"%s\" runs \"%s\", id %d (Potn, /item \"Potion\" <me>, 4112)", lb, l0, iid);
      check(!strcmp(lb, "Potn") && !strcmp(l0, "/item \"Potion\" <me>") && iid == 4112, what);
      INV(0, 1, 0, 0); INV(3, 1, 0, 0); INV(0, 3, 4128, 2); for (int f = 0; f < 31; f++) HB_FRAME();
      itm(1, 2, &iid, &icn); slot(1, 2, lb, l0, &nl, &ic, &mp);
      snprintf(what, sizeof what, "hbmod: the Potions gone, an Ether there: autoitem \"Pot\" %s (none matches: the slot empty); item slot Potion count %d", nl ? l0 : "empty", (itm(1, 1, &iid, &icn), icn));
      check(nl == 0 && icn == 0, what);
      RUNL("/htb set 1 2 autoitem 1"); slot(1, 2, lb, l0, &nl, &ic, &mp);
      snprintf(what, sizeof what, "hbmod: autoitem \"1\": \"%s\" (the first usable item: Ether)", l0); check(!strcmp(l0, "/item \"Ether\" <me>"), what);
      /* weapon switching: hotbar.txt reads the Sword set; a club as the main weapon reads Club too (2.4: BS, Club's) */
      slot(2, 4, lb, l0, &nl, &ic, &mp);
      snprintf(what, sizeof what, "hbmod: 2.4 before a weapon: \"%s\" (FB, hotbar.txt's set Sword)", lb); check(!strcmp(lb, "FB"), what);
      wpn(17024); for (int f = 0; f < 31; f++) HB_FRAME(); slot(2, 4, lb, l0, &nl, &ic, &mp);
      snprintf(what, sizeof what, "hbmod: the main weapon an Ash Club (skill 11): 2.4 \"%s\" (BS: the job file's Club table read as a set)", lb); check(!strcmp(lb, "BS"), what);
      wpn(-1); for (int f = 0; f < 31; f++) HB_FRAME(); slot(2, 4, lb, l0, &nl, &ic, &mp);
      snprintf(what, sizeof what, "hbmod: no weapon again: 2.4 \"%s\" (FB: Club's table off)", lb); check(!strcmp(lb, "FB"), what);
      /* bstpet N: the N-th learned /pet ability that is not a PetCommand, by id (Foot Kick 672; Sic 255 is a PetCommand),
         by the game's learned list (game state +0x2CDE8, record id + 0x200) */
      gst[0x2CDE8 + ((672 + 0x200) >> 3)] |= 1 << ((672 + 0x200) & 7); gst[0x2CDE8 + ((255 + 0x200) >> 3)] |= 1 << ((255 + 0x200) & 7); gst[0x2CF49] = gst[0x2CF4A] = 1;
      RUNL("/htb set 1 1 bstpet 1"); slot(1, 1, lb, l0, &nl, &ic, &mp);
      snprintf(what, sizeof what, "hbmod: bstpet 1: \"%s\" runs \"%s\" (FotKic, /ja \"Foot Kick\" <t>: Sic, a PetCommand, not counted)", lb, l0);
      check(!strcmp(lb, "FotKic") && !strcmp(l0, "/ja \"Foot Kick\" <t>"), what);
      RUNL("/htb set 1 2 bstpet 2"); slot(1, 2, lb, l0, &nl, &ic, &mp);
      snprintf(what, sizeof what, "hbmod: bstpet 2: %s (empty: one pet ability learned)", nl ? l0 : "empty"); check(nl == 0, what);
      gst[0x2CDE8 + ((672 + 0x200) >> 3)] = 0; for (int f = 0; f < 31; f++) HB_FRAME(); slot(1, 1, lb, l0, &nl, &ic, &mp);
      snprintf(what, sizeof what, "hbmod: Foot Kick's bit off: bstpet 1 %s (empty, made again when the learned list changed)", nl ? l0 : "empty"); check(nl == 0, what);
      #undef INV
      RUNL("/htb clear 1 1"); RUNL("/htb clear 1 2");
      *gsp = kgs;
    }
    /* (29 Nov) Horizon's spells: /htb horizon on reads priv_res/horizon_spells.lua instead of spells.lua (the picker's
       Magic tab lists its spell "Horizon Glow"; Stone, only in spells.lua, is gone) */
    { RUNL("/htb horizon on"); RUNL("/htb move"); pkr(10, r2); AT((r2[0] + r2[2]) / 2, (r2[1] + r2[3]) / 2); PRESS(); RELEASE();
      int tabh; char firsth[48]; int nh = pick(&tabh, firsth, sizeof firsth);
      snprintf(what, sizeof what, "hbmod: Horizon's spells: the Magic tab %d action(s), the first \"%s\" (2: Cure, Horizon Glow)", nh, firsth); check(nh == 2 && !strcmp(firsth, "Cure"), what);
      RUNL("/htb move"); RUNL("/htb horizon off");
      RUNL("/htb move"); pkr(10, r2); AT((r2[0] + r2[2]) / 2, (r2[1] + r2[3]) / 2); PRESS(); RELEASE(); nh = pick(&tabh, firsth, sizeof firsth); RUNL("/htb move");
      snprintf(what, sizeof what, "hbmod: Horizon's spells off: %d (2: Cure, Stone)", nh); check(nh == 2, what); }
    RUNL("/htb bar 1 4 own");
    remove("hotbar_layout.txt"); remove("hotbar_slots_war.txt"); remove("hotbar_slots.txt");
  }
  mng[0xB4] = 1;
  snprintf(what, sizeof what, "hbmod: the interface hidden (menu manager +0xB4 = 1): (220,220) hits %d (0)", over(220, 220)); check(over(220, 220) == 0, what);
  mng[0xB4] = 0;
  focus(0); if (kw) DestroyWindow(kw);
  memcpy(mng, saved, sizeof saved); *pcur = oc; *pres = orr; memcpy(sr, osr, 8);
  return 0;
}

/* a watchdog for finding where game code stops in a test: after `ms`, the main thread's EIP and the return-looking
   dwords on its stack (inside FFXiMain.dll) are printed, then the process ends */
static HANDLE g_wd_main; static DWORD g_wd_ms;
static DWORD WINAPI wd_thread(void *p) {
  (void)p; Sleep(g_wd_ms);
  SuspendThread(g_wd_main); CONTEXT c; memset(&c, 0, sizeof c); c.ContextFlags = CONTEXT_FULL;
  GetThreadContext(g_wd_main, &c);
  printf("  watchdog: main thread at eip %08lx (analysed %08lx), esp %08lx\n", (unsigned long)c.Eip, (unsigned long)(c.Eip - g_hrel), (unsigned long)c.Esp);
  uint32_t *sp = (uint32_t *)(uintptr_t)c.Esp; int n = 0;
  for (int i = 0; i < 2048 && n < 24; i++) { uint32_t v = sp[i]; if (v - g_hrel >= 0x10001000u && v - g_hrel < 0x10330000u) { printf("    [esp+%x] %08lx\n", i * 4, (unsigned long)(v - g_hrel)); n++; } }
  ExitProcess(3); return 0;
}
static LONG WINAPI wd_fault(EXCEPTION_POINTERS *e) {
  printf("  fault: code %08lx at %08lx (analysed %08lx), address %08lx\n", (unsigned long)e->ExceptionRecord->ExceptionCode,
         (unsigned long)(uintptr_t)e->ExceptionRecord->ExceptionAddress, (unsigned long)((uintptr_t)e->ExceptionRecord->ExceptionAddress - g_hrel),
         (unsigned long)(e->ExceptionRecord->NumberParameters > 1 ? e->ExceptionRecord->ExceptionInformation[1] : 0));
  ExitProcess(4); return 0;
}
static void watchdog(DWORD ms) { SetUnhandledExceptionFilter(wd_fault); DuplicateHandle(GetCurrentProcess(), GetCurrentThread(), GetCurrentProcess(), &g_wd_main, 0, FALSE, DUPLICATE_SAME_ACCESS); g_wd_ms = ms; CreateThread(NULL, 0, wd_thread, NULL, 0, NULL); }

/* ------------------------------------------------------------------------------------------------ fx2mod mode
   sdk/examples/effect_comfort.dll's per-effect control (effects.txt: "spel/fire 0"; fx_list=1): an element whose
   resource (element +0xFC, a handle) is chunk "fire" (type 5) under the scope "spel" (type 1, its parent at +0x28);
   the game's own YmElem_SetupDevice (0x100467E0) on it, then a white draw onto black is left out; the game's own
   YmElem_RestoreDevice (0x100472F0), then the same draw is drawn. Stand-ins: the processor (g_pProcessor: the game's
   CMoProcessorX87 vtable, a scratch matrix stack) and the CMoDX (g_pResourceMng) with the real device; the element
   has no fog (+0x10C bit 0x2000000), so SetupDevice does not ask the zone. */
typedef int (__thiscall *SetupFn)(void *, int);
typedef int (__thiscall *RestoreFn)(void *, int);
static uint32_t fx2_draw(IDirect3DDevice8 *dev, IDirect3DSurface8 *rt) {
  IDirect3DDevice8_SetRenderTarget(dev, rt, NULL); IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF000000u, 1.0f, 0);
  IDirect3DDevice8_SetRenderState(dev, D3DRS_ALPHABLENDENABLE, FALSE); IDirect3DDevice8_SetRenderState(dev, D3DRS_ZENABLE, FALSE);
  IDirect3DDevice8_SetRenderState(dev, D3DRS_LIGHTING, FALSE); IDirect3DDevice8_SetRenderState(dev, D3DRS_CULLMODE, D3DCULL_NONE);
  IDirect3DDevice8_SetRenderState(dev, D3DRS_FOGENABLE, FALSE); IDirect3DDevice8_SetRenderState(dev, D3DRS_ALPHATESTENABLE, FALSE);
  IDirect3DDevice8_SetTexture(dev, 0, NULL);
  IDirect3DDevice8_SetTextureStageState(dev, 0, D3DTSS_COLOROP, D3DTOP_SELECTARG1); IDirect3DDevice8_SetTextureStageState(dev, 0, D3DTSS_COLORARG1, D3DTA_DIFFUSE);
  IDirect3DDevice8_SetTextureStageState(dev, 1, D3DTSS_COLOROP, D3DTOP_DISABLE);
  IDirect3DDevice8_SetVertexShader(dev, D3DFVF_XYZRHW | D3DFVF_DIFFUSE);
  struct { float x, y, z, w; DWORD c; } q[4] = { { -0.5f, -0.5f, 0, 1, 0xFFFFFFFFu }, { 3.5f, -0.5f, 0, 1, 0xFFFFFFFFu }, { -0.5f, 3.5f, 0, 1, 0xFFFFFFFFu }, { 3.5f, 3.5f, 0, 1, 0xFFFFFFFFu } };
  IDirect3DDevice8_BeginScene(dev); IDirect3DDevice8_DrawPrimitiveUP(dev, D3DPT_TRIANGLESTRIP, 2, q, sizeof q[0]); IDirect3DDevice8_EndScene(dev);
  D3DLOCKED_RECT lr; uint32_t v = 0;
  if (SUCCEEDED(IDirect3DSurface8_LockRect(rt, &lr, NULL, D3DLOCK_READONLY))) { v = ((uint32_t *)lr.pBits)[lr.Pitch / 4 + 1]; IDirect3DSurface8_UnlockRect(rt); }
  return v & 0xFFFFFF;
}
static int fx2mod_run(IDirect3DDevice8 *dev) {
  for (int t = 0; t < 400 && *(uint8_t *)ga(0x100467E0u) != 0xE9; t++) {
    IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF000000u, 1.0f, 0); IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL); Sleep(50);
  }
  check(*(uint8_t *)ga(0x100467E0u) == 0xE9 && *(uint8_t *)ga(0x100472F0u) == 0xE9, "fx2mod: YmElem_SetupDevice's and RestoreDevice's entries jump (the mod's hooks)");
  
  static uint8_t elem[0x400], res[0x80], scope[0x80], proc[0x1000], mats[16][64], resmng[0x10000]; static void *hres, *hscope;
  memset(elem, 0, sizeof elem); memset(res, 0, sizeof res); memset(scope, 0, sizeof scope); memset(proc, 0, sizeof proc); memset(resmng, 0, sizeof resmng);
  memcpy(res + 0x20, "fire", 4); *(uint32_t *)(res + 0x24) = 5; memcpy(scope + 0x20, "spel", 4); *(uint32_t *)(scope + 0x24) = 1;
  hres = res; hscope = scope; *(void **)(res + 0x28) = &hscope; *(void **)(elem + 0xFC) = &hres;
  for (int i = 0; i < 16; i++) { ((void **)(proc + 0xA10))[i] = mats[i]; memset(mats[i], 0, 64); }
  *(void **)proc = (void *)ga(0x1032C368u);                  /* the game's CMoProcessorX87 vtable (data/class_vtables.json) */
  *(uint32_t *)(elem + 0x10C) |= 0x2000000u;                  /* an element without fog (SetupDevice's branch: no XiZone needed) */
  *(IDirect3DDevice8 **)(resmng + 0xEBC) = dev; *(void **)(resmng + 0xDC8) = g_cdx;
  void **pp = (void **)ga(0x1047CF7Cu), **pr = (void **)ga(0x1047BFA8u); void *op = *pp, *orr = *pr; *pp = proc; *pr = resmng;
  IDirect3DSurface8 *rt = NULL, *old = NULL, *oldz = NULL; char what[160];
  IDirect3DDevice8_GetRenderTarget(dev, &old); IDirect3DDevice8_GetDepthStencilSurface(dev, &oldz);
  IDirect3DDevice8_CreateRenderTarget(dev, 4, 4, D3DFMT_A8R8G8B8, D3DMULTISAMPLE_NONE, TRUE, &rt);
  /* the two function-local statics these functions set up on first use (a guard bit, then MoDX_SetInvalid on the state
     block, then atexit for its destructor): done here as the game does them, without the atexit (this host does not run
     the DLL's C runtime start-up, and atexit waits on its lock) */
  typedef void (__thiscall *InvFn)(void *);
  static uint8_t sblist[0x40]; void **psb = (void **)ga(0x1047BFF4u), *osb = *psb; if (!*psb) *psb = sblist;   /* the state blocks' list owner (0x1006ADF0 links each block at +0xC) */
  *(uint8_t *)ga(0x1047BBE4u) |= 1; ((InvFn)(void *)ga(0x1006AD90u))((void *)ga(0x1047BBB8u));
  *(uint8_t *)ga(0x1047BBC4u) |= 1; ((InvFn)(void *)ga(0x1006AD90u))((void *)ga(0x1047BC1Cu));
  watchdog(60000);
  ((SetupFn)(void *)ga(0x100467E0u))(elem, 0);              /* the game's own; the mod's hook names the element after it */
  uint32_t in = fx2_draw(dev, rt);
  ((RestoreFn)(void *)ga(0x100472F0u))(elem, 0);
  uint32_t out = fx2_draw(dev, rt);
  snprintf(what, sizeof what, "fx2mod: inside the element (spel/fire at 0%%) the white draw is left out (%06lx); after RestoreDevice it is drawn (%06lx)", (unsigned long)in, (unsigned long)out);
  check(in == 0 && out == 0xFFFFFF, what);
  /* a second element, chunk "wind" under a scope "efct" that is a file's root as the game's ResourceLoadTask_Step
     leaves it (+0x1A bit 1, the file number 4321 at +0x34): effects.txt "file:4321 0" leaves its draw out */
  static uint8_t elem2[0x400], res2[0x80], root2[0x80]; static void *hres2, *hroot2;
  memcpy(elem2, elem, sizeof elem2); memset(res2, 0, sizeof res2); memset(root2, 0, sizeof root2);
  memcpy(res2 + 0x20, "wind", 4); *(uint32_t *)(res2 + 0x24) = 5; memcpy(root2 + 0x20, "efct", 4); *(uint32_t *)(root2 + 0x24) = 1;
  root2[0x1A] |= 1; *(uint32_t *)(root2 + 0x34) = 4321;
  hres2 = res2; hroot2 = root2; *(void **)(res2 + 0x28) = &hroot2; *(void **)(elem2 + 0xFC) = &hres2;
  ((SetupFn)(void *)ga(0x100467E0u))(elem2, 0);
  in = fx2_draw(dev, rt);
  ((RestoreFn)(void *)ga(0x100472F0u))(elem2, 0);
  out = fx2_draw(dev, rt);
  snprintf(what, sizeof what, "fx2mod: an element of file 4321 (efct/wind, \"file:4321 0\") is left out (%06lx); after RestoreDevice drawn (%06lx)", (unsigned long)in, (unsigned long)out);
  check(in == 0 && out == 0xFFFFFF, what);
  IDirect3DDevice8_SetRenderTarget(dev, old, oldz); if (old) IDirect3DSurface8_Release(old); if (oldz) IDirect3DSurface8_Release(oldz); if (rt) IDirect3DSurface8_Release(rt);
  *pp = op; *pr = orr; *psb = osb;
  return 0;
}

/* ------------------------------------------------------------------------------------------------ prishe mode
   Prishe's probe/prishe_probe.dll (WGINC/Prishe) through the kit, with this host acting as "another tool" before the probe's first
   frame: the game's CreateFileA import slot (0x103291EC in the analysed build) holds this host's function instead of
   kernel32's, and App_ForceForegroundWindow's entry (0x100014A0) starts with a jmp into this host. The probe's report
   must name host.exe as the owner of both, call the device's Present the kit's (xikit.dll, the kit's vtable copy),
   and count the jump as another module's. */
static HANDLE WINAPI other_createfile(LPCSTR a, DWORD b, DWORD c, LPSECURITY_ATTRIBUTES d, DWORD e, DWORD f, HANDLE g) { return CreateFileA(a, b, c, d, e, f, g); }
static void other_entry(void) {}
static int prishe_patch(void) {
  void **slot = (void **)ga(0x103291ECu);
  FARPROC k = GetProcAddress(GetModuleHandleA("kernel32.dll"), "CreateFileA");
  check(*slot == (void *)k, "prishe: the game's CreateFileA slot holds kernel32's before the other tool");
  DWORD old; VirtualProtect(slot, 4, PAGE_READWRITE, &old); *slot = (void *)other_createfile;
  uint8_t *e = (uint8_t *)ga(0x100014A0u);
  VirtualProtect(e, 8, PAGE_EXECUTE_READWRITE, &old);
  e[0] = 0xE9; *(int32_t *)(e + 1) = (int32_t)((uint8_t *)other_entry - (e + 5));
  return 0;
}
static int prishe_run(IDirect3DDevice8 *dev) {
  FILE *f = NULL;
  for (int t = 0; t < 400 && !(f = fopen("prishe_probe.txt", "r")); t++) {
    IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF000000u, 1.0f, 0); IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL); Sleep(50);
  }
  check(f != NULL, "prishe: the probe wrote prishe_probe.txt at the first frame");
  if (!f) return 0;
  static char txt[1 << 20]; size_t n = fread(txt, 1, sizeof txt - 1, f); txt[n] = 0; fclose(f);
  const char *ss[][2] = {
    { "[modules]", "prishe: the report lists the modules" },
    { "FFXiMain.dll", "prishe: the game's module is among them" },
    { "not d3d8on11's", "prishe: Wine's d3d8.dll is told apart from d3d8on11's" },
    { "in host.exe", "prishe: an owner outside the kit is named by its module" },
    { "something replaced it", "prishe: the CreateFileA slot is reported as replaced" },
  };
  for (size_t i = 0; i < sizeof ss / sizeof ss[0]; i++) check(strstr(txt, ss[i][0]) != NULL, ss[i][1]);
  const char *cf = strstr(txt, "FFXiMain.dll's import slot");
  check(cf && strstr(cf, "in host.exe") && strstr(cf, "in host.exe") < strstr(cf, "\n"), "prishe: the slot's owner is host.exe");
  const char *ap = strstr(txt, "App_ForceForegroundWindow ");
  check(ap && strstr(ap, "starts with a jump to") && strstr(ap, "in host.exe") < strchr(ap, '\n'), "prishe: App_ForceForegroundWindow's entry jumps into host.exe (another tool's hook)");
  const char *pr = strstr(txt, "Present ");
  check(pr && strstr(pr, "xikit.dll (ours)") && strstr(pr, "xikit.dll (ours)") < strchr(pr, '\n'), "prishe: the device's Present is the kit's (ours)");
  const char *sm = strstr(txt, "functions: ");
  check(sm && strstr(sm, " 1 jump elsewhere") && strstr(sm, " 1 jump elsewhere") < strchr(sm, '\n'), "prishe: the summary counts one jump to another module");
  check(strstr(txt, "[windows]") != NULL, "prishe: the window section is written");
  { const char *m = strstr(txt, "[manifest]"); int k = 0;   /* the jumps the probe saw, for reading */
    for (const char *l = m; l && *l && k < 40; l = strchr(l, '\n'), l = l ? l + 1 : NULL)
      if (strstr(l, "jump to") && strstr(l, "jump to") < strchr(l, '\n')) { printf("note: %.*s\n", (int)(strchr(l, '\n') - l), l); k++; } }
  return 0;
}

/* ------------------------------------------------------------------------------------------------ prishert mode
   Prishe's runtime/prishe.dll (WGINC/Prishe) through the kit, opens through the game's own CreateFileA import slot. test_xikit.py made
   ROM\1\2.DAT ("orig2"), ROM\1\3.DAT ("orig3") and three packs under prishe\packs: a_one (files\ROM\1\2.DAT "packA"),
   b_two (files\rom\1\2.dat "packB"), c_off (files\ROM\1\3.DAT "packC"); profile.json: a_one priority 20, b_two 10,
   c_off turned off. Then the profile is rewritten (b_two 30) while running: the new winner is read. */
static int prishert_run(IDirect3DDevice8 *dev, HMODULE g) {
  CFA *slot = (CFA *)ga(0x103291ECu); void *orig = (void *)GetProcAddress(GetModuleHandleA("kernel32.dll"), "CreateFileA");
  for (int t = 0; t < 400 && *(void **)slot == orig; t++) {
    IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF000000u, 1.0f, 0); IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL); Sleep(50);
  }
  check(*(void **)slot != orig, "prishert: the game's CreateFileA import slot goes to prishe.dll");
  char dir[MAX_PATH], p[MAX_PATH + 32], b[8], what[300]; GetModuleFileNameA(g, dir, sizeof dir); *strrchr(dir, '\\') = 0;
  snprintf(p, sizeof p, "%s/ROM/1/2.DAT", dir); read5(*slot, p, GENERIC_READ, b);
  snprintf(what, sizeof what, "prishert: ROM/1/2.DAT reads \"%s\" (a_one: priority 20 over b_two's 10, although b_two's folder name is later)", b); check(!strcmp(b, "packA"), what);
  snprintf(p, sizeof p, "%s\\rom\\1\\3.dat", dir); read5(*slot, p, GENERIC_READ, b);
  snprintf(what, sizeof what, "prishert: ROM/1/3.DAT reads \"%s\" (the game's: c_off is turned off)", b); check(!strcmp(b, "orig3"), what);
  snprintf(p, sizeof p, "%s\\ROM\\1\\2.DAT", dir); read5(*slot, p, GENERIC_READ | GENERIC_WRITE, b);
  snprintf(what, sizeof what, "prishert: a write open reads \"%s\" (the game's file, never redirected)", b); check(!strcmp(b, "orig2"), what);
  FILE *r = fopen("prishe\\report.txt", "r"); static char rep[1 << 16]; size_t n = r ? fread(rep, 1, sizeof rep - 1, r) : 0; rep[n] = 0; if (r) fclose(r);
  check(strstr(rep, "file rom\\1\\2.dat: a_one wins (priority 20 over 10) over b_two") != NULL, "prishert: prishe\\report.txt names the conflict and its winner");
  Sleep(1100);                                                  /* (a later last-write time than the first profile's) */
  FILE *pf = fopen("prishe\\profile.json", "w");
  if (pf) { fputs("{\"prishe\": 1, \"packs\": [{\"folder\": \"a_one\", \"priority\": 20}, {\"folder\": \"b_two\", \"priority\": 30}, {\"folder\": \"c_off\", \"enabled\": false}]}", pf); fclose(pf); }
  snprintf(p, sizeof p, "%s/ROM/1/2.DAT", dir);
  for (int t = 0; t < 600; t++) {
    read5(*slot, p, GENERIC_READ, b); if (!strcmp(b, "packB")) break;
    IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF000000u, 1.0f, 0); IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL); Sleep(20);
  }
  snprintf(what, sizeof what, "prishert: after profile.json gives b_two priority 30 while running, ROM/1/2.DAT reads \"%s\" (b_two's)", b); check(!strcmp(b, "packB"), what);
  { /* (28 Nov, live reloading) a file put into a pack while the game runs, with nothing else touched: prishe.dll sees the
       folder change and reads the packs again by itself */
    FILE *nf = fopen("prishe\\packs\\b_two\\files\\ROM\\1\\5.DAT", "wb"); if (nf) { fputs("new5x", nf); fclose(nf); }
    snprintf(p, sizeof p, "%s/ROM/1/5.DAT", dir); b[0] = 0; int t;
    for (t = 0; t < 1500; t++) {
      read5(*slot, p, GENERIC_READ, b); if (!strcmp(b, "new5x")) break;
      IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF000000u, 1.0f, 0); IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL); Sleep(20);
    }
    snprintf(what, sizeof what, "prishert: a file added to b_two while running is served without a button or a profile change: ROM/1/5.DAT reads \"%s\" (after %d frames)", b, t);
    check(!strcmp(b, "new5x"), what); }
  { int (*lg)(const char *, char *, int) = (int (*)(const char *, char *, int))(void *)GetProcAddress(GetModuleHandleA("prishe.dll"), "prishe_test_log");
    char pk[64] = "";
    if (!lg) printf("note: prishert: prishe.dll has no resource log (an older Prishe)\n");
    else { int f = lg("rom\\1\\2.dat", pk, sizeof pk); snprintf(what, sizeof what, "prishert: the resource log has rom\\1\\2.dat from \"%s\" (b_two)", f ? pk : "(not logged)"); check(f && !strcmp(pk, "b_two"), what);
           f = lg("rom\\1\\3.dat", pk, sizeof pk); snprintf(what, sizeof what, "prishert: the resource log has rom\\1\\3.dat as the game's own (\"%s\")", f ? pk : "(not logged)"); check(f && !pk[0], what); } }
  /* textures (runtime/textures.cpp): an 8x8 32-bit object named prtex01 through the game's own TexObj_Create; b_two now has
     priority 30, so its prtex01.dds (16x16, 0xFF445566) wins over a_one's (0xFF112233) */
  check(*(uint8_t *)ga(0x10039E50u) == 0xE9, "prishert: TexObj_Upload's entry jumps (Prishe's texture hook)");
  { static uint32_t px[64]; static uint8_t obj[0x48];
    for (int k = 0; k < 64; k++) px[k] = 0xFF000000u | (uint32_t)(k * 0x0301);
    memset(obj, 0, sizeof obj); memset(obj + 0x0C, ' ', 16); memcpy(obj + 0x0C, "prtex01", 7);
    *(uint32_t *)(obj + 0x04) = 1; *(void **)(obj + 0x20) = px;
    *(uint16_t *)(obj + 0x24) = 8; *(uint16_t *)(obj + 0x26) = 8; obj[0x28] = 32; obj[0x29] = 32; obj[0x2A] = 1; *(uint32_t *)(obj + 0x2C) = 9u << 4;
    uint8_t rc = ((TexCreateFn)(void *)ga(0x10039A80u))(obj);
    IDirect3DTexture8 *tx = *(IDirect3DTexture8 **)(obj + 0x40); D3DSURFACE_DESC sd; memset(&sd, 0, sizeof sd); uint32_t v = 0;
    int ok = rc && tx && SUCCEEDED(IDirect3DTexture8_GetLevelDesc(tx, 0, &sd));
    if (ok) { D3DLOCKED_RECT lr; if (SUCCEEDED(IDirect3DTexture8_LockRect(tx, 0, &lr, NULL, D3DLOCK_READONLY))) { v = *(uint32_t *)lr.pBits; IDirect3DTexture8_UnlockRect(tx, 0); } }
    snprintf(what, sizeof what, "prishert: prtex01 through the game's TexObj_Create: %ux%u, first texel %08lx (16x16, ff445566: b_two's, priority 30)", ok ? sd.Width : 0, ok ? sd.Height : 0, (unsigned long)v);
    check(ok && sd.Width == 16 && sd.Height == 16 && v == 0xFF445566u, what); }
  /* (Prishe V2) the on-screen view's two hooks by name: LoadSkeletonSync (which character) and FindOrCreateTask (which
     file number); no character is loaded here, so the view holds none */
  check(*(uint8_t *)ga(0x100730E0u) == 0xE9 && *(uint8_t *)ga(0x100D2F60u) == 0xE9, "prishert: CMoResource::FindOrCreateTask's and CXiSkeletonActor::LoadSkeletonSync's entries jump (Prishe's on-screen view)");
  { int (*os)(void) = (int (*)(void))(void *)GetProcAddress(GetModuleHandleA("prishe.dll"), "prishe_test_onscreen");
    if (os) check(os() == 0, "prishert: the on-screen view holds no character (none was loaded)"); }
  /* (Prishe C1, S1) the look override: looks\mine.json (written by test_xikit.py) gives "Alice" slot 2 word 0x2077. A
     stand-in record named Alice in the game DLL's record array, its actor's vtable +0x3B4 returning 0 (the record
     path of GetModelPartWord); a few frames for Prishe to match it; then the game's own GetModelPartWord, called on
     that actor, gives the look's word for slot 2 and the record's for slot 1 */
  check(*(uint8_t *)ga(0x10084480u) == 0xE9, "prishert: CXiActor::GetModelPartWord's entry jumps (Prishe's look override)");
  check(*(uint8_t *)ga(0x10127C00u) == 0xE9, "prishert: ChatLog_AddMessage's entry jumps (Prishe's chat events for plugins, P3)");
  { static uint8_t rec[0x300]; static void *vt[0x100]; static void *act[0x40];
    for (int k = 0; k < 0x100; k++) vt[k] = (void *)vt_zero;
    act[0] = vt; *(void **)((uint8_t *)act + 0x70) = rec; *(void **)(rec + 0xA0) = act;
    strcpy((char *)rec + 0x7C, "Alice"); rec[0xEF] = 2;
    for (int s2 = 0; s2 < 9; s2++) *(uint16_t *)(rec + 0xFC + 2 * s2) = (uint16_t)(0x1000 * s2 + 0x11);
    void **arr = (void **)(uintptr_t)ga(0x10480AF0u); arr[3] = rec;
    for (int f = 0; f < 4; f++) { IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL); Sleep(20); }
    typedef unsigned (__attribute__((thiscall)) *WordFn)(void *, int);
    unsigned w2 = ((WordFn)(uintptr_t)ga(0x10084480u))(act, 2), w1 = ((WordFn)(uintptr_t)ga(0x10084480u))(act, 1);
    long (*lk)(void) = (long (*)(void))(void *)GetProcAddress(GetModuleHandleA("prishe.dll"), "prishe_test_looks");
    { long (*st)(int) = (long (*)(int))(void *)GetProcAddress(GetModuleHandleA("prishe.dll"), "prishe_test_state");
      if (st) printf("  prishe state: %ld frames, %ld matched, %ld looks, record 3 %p (ours %p)\n", st(0), st(1), st(2), (void *)st(3), (void *)rec); }
    snprintf(what, sizeof what, "prishert: the game's GetModelPartWord on Alice's actor: slot 2 %04x (the look's 2077), slot 1 %04x (the record's 1011); %ld replaced", w2 & 0xFFFF, w1 & 0xFFFF, lk ? lk() : -1);
    check((w2 & 0xFFFF) == 0x2077 && (w1 & 0xFFFF) == 0x1011 && lk && lk() >= 1, what);
    arr[3] = NULL; for (int f = 0; f < 3; f++) { IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL); Sleep(20); }
    w2 = ((WordFn)(uintptr_t)ga(0x10084480u))(act, 2);
    snprintf(what, sizeof what, "prishert: after Alice's record left the array, slot 2 is the record's own again (%04x)", w2 & 0xFFFF);
    check((w2 & 0xFFFF) == 0x2011, what);
    /* (26 Nov) looks go only to records of kind 0 (+0xEE): an "Alice" of kind 1 (an NPC, as seen in the game) gets none */
    rec[0xEE] = 1; arr[3] = rec; for (int f = 0; f < 4; f++) { IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL); Sleep(20); }
    w2 = ((WordFn)(uintptr_t)ga(0x10084480u))(act, 2);
    snprintf(what, sizeof what, "prishert: an Alice of kind 1 keeps the record's slot 2 (%04x, not the look's 2077)", w2 & 0xFFFF);
    check((w2 & 0xFFFF) == 0x2011, what);
    arr[3] = NULL; rec[0xEE] = 0; for (int f = 0; f < 3; f++) { IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL); Sleep(20); } }
  /* (Prishe H1) host=1: the shared memory "Local\PrisheHost_<pid>" made by prishe.dll, its magic, and frames written */
  { char nm[64]; snprintf(nm, sizeof nm, "Local\\PrisheHost_%lu", GetCurrentProcessId());
    HANDLE hm = OpenFileMappingA(FILE_MAP_READ, FALSE, nm); const uint8_t *blk = hm ? (const uint8_t *)MapViewOfFile(hm, FILE_MAP_READ, 0, 0, 0x10050) : NULL;
    uint32_t f1 = blk ? *(const uint32_t *)(blk + 0x14) : 0;
    for (int f = 0; f < 3; f++) { IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL); Sleep(20); }
    uint32_t f2 = blk ? *(const uint32_t *)(blk + 0x14) : 0;
    snprintf(what, sizeof what, "prishert: host=1: %s exists, magic %.7s, version %u, size %u, frames %u then %u", nm, blk ? (const char *)blk : "-", blk ? *(const uint32_t *)(blk + 8) : 0, blk ? *(const uint32_t *)(blk + 12) : 0, f1, f2);
    check(blk && !memcmp(blk, "PRISHE1", 8) && *(const uint32_t *)(blk + 8) == 1 && *(const uint32_t *)(blk + 12) == 0x10050 && f2 >= f1 + 3, what);
    if (blk) UnmapViewOfFile(blk); if (hm) CloseHandle(hm); }
  /* (Prishe M4) dump_textures=1: the game's own prtex01 (8x8, before Prishe's replacement) written once to
     prishe\textures_dump\prtex01_<crc>.dds, when this Prishe has the dump (built with the SDK's texture_replace_core) */
  { WIN32_FIND_DATAA fd; HANDLE h = FindFirstFileA("prishe\\textures_dump\\prtex01_*.dds", &fd);
    if (h == INVALID_HANDLE_VALUE) check(0, "prishert: dump_textures=1 wrote prishe\\textures_dump\\prtex01_<crc>.dds");
    else { FindClose(h); char p[MAX_PATH]; snprintf(p, sizeof p, "prishe\\textures_dump\\%s", fd.cFileName);
      FILE *f = fopen(p, "rb"); uint8_t hd[128] = {0}; size_t n = f ? fread(hd, 1, sizeof hd, f) : 0; if (f) fclose(f);
      uint32_t w = 0, hh = 0; memcpy(&hh, hd + 12, 4); memcpy(&w, hd + 16, 4);
      snprintf(what, sizeof what, "prishert: dump_textures=1 wrote %s, a DDS of %ux%u (the game's own 8x8, not the pack's 16x16)", fd.cFileName, w, hh);
      check(n == 128 && !memcmp(hd, "DDS ", 4) && w == 8 && hh == 8, what); } }
  /* the in-game panel (runtime/panel.cpp, when Prishe was built with the SDK's xiimgui): panel_show=1 (xikit_mods.ini),
     five frames through the game's Menu_DrawLayers */
  { int (*panel)(int) = (int (*)(int))(void *)GetProcAddress(GetModuleHandleA("prishe.dll"), "prishe_test_panel");
    if (!panel) printf("note: prishert: prishe.dll has no in-game panel (built without the SDK's xiimgui)\n");
    else {
      uint8_t *mng = (uint8_t *)ga(0x10621838u); uint8_t saved[0xC0]; memcpy(saved, mng, sizeof saved); memset(mng, 0, sizeof saved);
      short *sr = (short *)ga(0x106218B4u); sr[0] = 0; sr[1] = 0; sr[2] = 640; sr[3] = 480;
      static uint8_t cursor[0x400]; memset(cursor, 0, sizeof cursor); void **pcur = (void **)ga(0x104E1D4Cu), *oc = *pcur; *pcur = cursor;
      static uint8_t resmng[0x10000]; memset(resmng, 0, sizeof resmng);
      void **pres = (void **)ga(0x1047BFA8u), *orr = *pres; if (!*pres) { *pres = resmng; *(IDirect3DDevice8 **)(resmng + 0xEBC) = dev; *(void **)(resmng + 0xDC8) = g_cdx; }
      if (!*(void **)(g_cdx + 0xC)) *(IDirect3DDevice8 **)(g_cdx + 0xC) = dev;
      DrawLayersFn draw = (DrawLayersFn)(void *)ga(0x1015F6A0u);
      int f0 = panel(1);
      for (int f = 0; f < 5; f++) { IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF000000u, 1.0f, 0); IDirect3DDevice8_BeginScene(dev); draw(mng); IDirect3DDevice8_EndScene(dev); }
      snprintf(what, sizeof what, "prishert: the in-game panel drew 5 frames through Menu_DrawLayers (%d)", panel(1) - f0); check(panel(1) - f0 == 5, what);
      memcpy(mng, saved, sizeof saved); *pcur = oc; *pres = orr;
    } }
  /* the chat command (runtime/commands.cpp): "/Prishe off b_two" through the game's Command_RunLine entry is taken
     (returns 0, the game's code not run), b_two turned off in profile.json, and the runtime follows: ROM/1/2.DAT is
     a_one's again. (replies_in_chat=0: the reply's /echo is not run in this host) */
  { long (*taken)(void) = (long (*)(void))(void *)GetProcAddress(GetModuleHandleA("prishe.dll"), "prishe_test_commands");
    if (!taken) printf("note: prishert: prishe.dll has no chat commands (an older Prishe)\n");
    else {
      typedef int (__cdecl *RunFn)(char *, uint32_t); char line[] = "/Prishe off b_two"; long t0 = taken();
      Sleep(1100);                                              /* (a later last-write time for profile.json) */
      int rr = ((RunFn)(void *)ga(0x10080DC0u))(line, 0);
      snprintf(p, sizeof p, "%s/ROM/1/2.DAT", dir);
      for (int t = 0; t < 600; t++) {
        read5(*slot, p, GENERIC_READ, b); if (!strcmp(b, "packA")) break;
        IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF000000u, 1.0f, 0); IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL); Sleep(20);
      }
      snprintf(what, sizeof what, "prishert: \"/Prishe off b_two\" through Command_RunLine: returned %d (0), %ld line taken (1); ROM/1/2.DAT then reads \"%s\" (packA: b_two off)", rr, taken() - t0, b);
      check(*(uint8_t *)ga(0x10080DC0u) == 0xE9 && rr == 0 && taken() - t0 == 1 && !strcmp(b, "packA"), what);
    } }
  return 0;
}

int main(int argc, char **argv) {
  int reloadrun = argc > 1 && !strcmp(argv[1], "reload"), chainrun = argc > 1 && !strcmp(argv[1], "chain");
  int faultrun = argc > 1 && !strcmp(argv[1], "modfault");   /* (27 Nov, Prishe P4) a mod that faults stays alone */
  int staterun = argc > 1 && !strcmp(argv[1], "staterun");   /* (27 Nov) xistate's record, player, zone readers and watchers */
  int toolrun = argc > 1 && !strcmp(argv[1], "toolhook");   /* (25 Nov) another tool's jump at Command_RunLine first */
  int modrun = argc > 1 && (!strcmp(argv[1], "mod") || !strcmp(argv[1], "modrel") || reloadrun);
  int caprun = argc > 1 && !strcmp(argv[1], "capture");
  int factrun = argc > 1 && !strcmp(argv[1], "facts");
  int abrun = argc > 1 && !strcmp(argv[1], "ab");
  int texrun = argc > 1 && !strcmp(argv[1], "texmod"), fxrun = argc > 1 && !strcmp(argv[1], "fxmod");
  int camrun = argc > 1 && !strcmp(argv[1], "cammod"), ovlrun = argc > 1 && !strcmp(argv[1], "ovlmod");
  int audrun = argc > 1 && !strcmp(argv[1], "audmod"), envrun = argc > 1 && !strcmp(argv[1], "envmod");
  int phorun = argc > 1 && !strcmp(argv[1], "phomod"), cfrun = argc > 1 && !strcmp(argv[1], "cfmod");
  int pvrun = argc > 1 && !strcmp(argv[1], "ctmod"), hbrun = argc > 1 && !strcmp(argv[1], "hbmod");
  int uirun = argc > 1 && !strcmp(argv[1], "uimod"), fx2run = argc > 1 && !strcmp(argv[1], "fx2mod"), igrun = argc > 1 && !strcmp(argv[1], "igmod"), xtrun = argc > 1 && !strcmp(argv[1], "xtmod");
  int prirun = argc > 1 && !strcmp(argv[1], "prishe"), prtrun = argc > 1 && !strcmp(argv[1], "prishert");
  int realrun = argc > 1 && (!strcmp(argv[1], "realdev") || texrun || fxrun || camrun || ovlrun || audrun || envrun || phorun || cfrun || uirun || pvrun || hbrun || fx2run || igrun || xtrun || prirun || prtrun);
  int nativerun = argc > 1 && !strcmp(argv[1], "native");
  int blockrun = argc > 1 && !strcmp(argv[1], "traceblock");
  int measrun = argc > 1 && !strcmp(argv[1], "measure");
  int pubrun = argc > 1 && !strcmp(argv[1], "public");   /* the public kit (sdk/public_prune.py): no reconstruction DLL, swap=0, mod_public.dll */
  g_faketex[0] = (uint32_t)(uintptr_t)g_texvt;
  int relocated = argc > 1 && (!strcmp(argv[1], "relocated") || !strcmp(argv[1], "modrel")), profile = argc > 1 && !strcmp(argv[1], "profile");
  const char *ini = "xikit.ini";
  setvbuf(stdout, NULL, _IONBF, 0);
  if (relocated && !VirtualAlloc((void *)0x10000000, 0x01000000, MEM_RESERVE, PAGE_NOACCESS)) printf("note: could not reserve 0x10000000\n");
  HMODULE g = LoadLibraryExA("FFXiMain.dll", NULL, DONT_RESOLVE_DLL_REFERENCES);
  if (!g) { printf("FAIL: FFXiMain.dll not mapped (%lu)\n", GetLastError()); return 2; }
  uint32_t rel = (uint32_t)(uintptr_t)g - 0x10000000u;
  g_hrel = rel; load_shifts(g);
  /* Wine maps a DONT_RESOLVE_DLL_REFERENCES image without applying its base relocations, and the unpacked file's
     header directory covers only the last 87 blocks of its table (not .text). In the game every relocation of
     the whole chain is applied, as the dumps show (pipeline/dump_verify.py checks every relocated dword). Apply
     the same chain, read from the .reloc section's start, so the image is as the game would have it. */
  if (rel && *(uint32_t *)(uintptr_t)(ga(GAMMA) + 1) == (uint32_t)(ga(G_PCDX) - g_hrel)) {   /* (its operand: G_PCDX where it is in this build, at the preferred base) */
    IMAGE_NT_HEADERS *nt = (IMAGE_NT_HEADERS *)((char *)g + ((IMAGE_DOS_HEADER *)g)->e_lfanew);
    IMAGE_SECTION_HEADER *sh = IMAGE_FIRST_SECTION(nt), *rs = NULL;
    for (int k = 0; k < nt->FileHeader.NumberOfSections; k++) if (!memcmp(sh[k].Name, ".reloc", 7)) rs = &sh[k];
    if (!rs) { printf("FAIL: no .reloc section\n"); return 2; }
    DWORD old; VirtualProtect(g, nt->OptionalHeader.SizeOfImage, PAGE_EXECUTE_READWRITE, &old);
    uint8_t *p = (uint8_t *)g + rs->VirtualAddress, *end = p + rs->Misc.VirtualSize; int n = 0;
    while (p + 8 <= end) {
      IMAGE_BASE_RELOCATION *b = (IMAGE_BASE_RELOCATION *)p;
      if (b->SizeOfBlock < 8 || b->SizeOfBlock % 2 || p + b->SizeOfBlock > end) break;
      WORD *e = (WORD *)(b + 1);
      for (DWORD k = 0; k < (b->SizeOfBlock - sizeof *b) / 2; k++)
        if ((e[k] >> 12) == IMAGE_REL_BASED_HIGHLOW) { *(uint32_t *)((uint8_t *)g + b->VirtualAddress + (e[k] & 0xFFF)) += rel; n++; }
      p += b->SizeOfBlock;
    }
    printf("note: applied %d base relocations (the loader's job; Wine skips it for this load mode); entry dword now %08x\n", n, *(uint32_t *)(uintptr_t)(ga(GAMMA) + 1));
  }
  printf("FFXiMain.dll at %p (delta %+ld)\n", g, (long)rel);
  check(!relocated || rel != 0, relocated ? "the game DLL was loaded away from its analysed base" : "the game DLL at its analysed base");
  uint8_t orig_set[5], orig_gam[5];
  memcpy(orig_set, (void *)(uintptr_t)ga(SETCOLOR), 5); memcpy(orig_gam, (void *)(uintptr_t)ga(GAMMA), 5);
  uint8_t orig_ecb[9]; memcpy(orig_ecb, (void *)(uintptr_t)ga(0x100096B0u), 9);     /* CDx::EndClearBegin (the mod run) */
  for (int k = 0; k < 97; k++) g_vtbl[k] = (void *)other_slot;
  g_vtbl[15] = (void *)fake_present;
  g_vtbl[3] = (void *)d_tcl; g_vtbl[34] = (void *)d_beginscene; g_vtbl[20] = (void *)d_createtex; g_vtbl[75] = (void *)d_createvs;
  g_vtbl[16] = (void *)d_getbb; g_vtbl[27] = (void *)d_createimg; g_vtbl[28] = (void *)d_copyrects;
  for (int k = 0; k < 11; k++) g_svt[k] = (void *)other_slot;
  g_svt[2] = (void *)s_release; g_svt[8] = (void *)s_desc; g_svt[9] = (void *)s_lock; g_svt[10] = (void *)s_unlock;
  g_paint_site = (uint8_t *)(uintptr_t)ga(GETCOLOR);   /* (SetColor is quarantined by the crash checks before the trace) */
  *(void **)(g_cdx + 0xC) = &g_dev; g_cdx[0x915] = 0x5A;
  *(void **)(uintptr_t)ga(G_PCDX) = g_cdx;
  if (measrun) {
    fill_iat(g);
    int r = measure_run(g, rel);
    printf("%s\n", fails || r ? "FAILED" : "ALL OK");
    ExitProcess(fails || r ? 1 : 0);
  }
  if (realrun) {
    /* a real Direct3D 8 device in the game's place (whichever d3d8.dll loads: Wine's, or kit/d3d8on11 next to this
       program): the kit must hook it as it hooks the game's (its own vtable copy) and write its frame times */
    WNDCLASSA wc; memset(&wc, 0, sizeof wc); wc.lpfnWndProc = DefWindowProcA; wc.hInstance = GetModuleHandleA(NULL); wc.lpszClassName = "xh"; RegisterClassA(&wc);
    HWND w = CreateWindowA("xh", "xh", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0, 160, 120, NULL, NULL, wc.hInstance, NULL);
    typedef IDirect3D8 *(WINAPI *Create8)(UINT);
    HMODULE d8 = LoadLibraryA("d3d8.dll"); Create8 c8 = d8 ? (Create8)(void *)GetProcAddress(d8, "Direct3DCreate8") : NULL;
    IDirect3D8 *d3d = c8 ? c8(D3D_SDK_VERSION) : NULL;
    if (!d3d) { printf("FAIL: Direct3DCreate8\n"); return 2; }
    D3DPRESENT_PARAMETERS pp; memset(&pp, 0, sizeof pp);
    pp.BackBufferWidth = 64; pp.BackBufferHeight = 64; pp.BackBufferFormat = D3DFMT_X8R8G8B8; pp.BackBufferCount = 1;
    pp.SwapEffect = cfrun ? D3DSWAPEFFECT_COPY : D3DSWAPEFFECT_DISCARD; pp.hDeviceWindow = w; pp.Windowed = TRUE;
    if (cfrun) pp.Flags = D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;
    IDirect3DDevice8 *dev = NULL;
    HRESULT hr = IDirect3D8_CreateDevice(d3d, D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, w, D3DCREATE_HARDWARE_VERTEXPROCESSING, &pp, &dev);
    if (FAILED(hr) || !dev) { printf("FAIL: CreateDevice 0x%08lX\n", (unsigned long)hr); return 2; }
    void *vt0 = *(void **)dev;
    *(void **)(g_cdx + 0xC) = dev;
    touch_ini(ini, prtrun ? "[xikit]\nlog_folder=0\nswap=0\ncount_calls=0\nreport_every=60\nhotkey=0\nmods=prishe.dll\n"
                 : prirun ? "[xikit]\nlog_folder=0\nswap=0\ncount_calls=0\nreport_every=60\nhotkey=0\nmods=prishe_probe.dll\n"
                 : texrun ? "[xikit]\nlog_folder=0\nswap=0\ncount_calls=1\nreport_every=60\nhotkey=0\nmods=texture_replace.dll\n"
                 : fx2run ? "[xikit]\nlog_folder=0\nswap=0\ncount_calls=1\nreport_every=60\nhotkey=0\nmods=effect_comfort.dll\n"
                 : hbrun ? "[xikit]\nlog_folder=0\nswap=0\ncount_calls=1\nreport_every=60\nhotkey=0\nmods=hotbar.dll\n"
                 : xtrun ? "[xikit]\nlog_folder=0\nswap=0\ncount_calls=1\nreport_every=60\nhotkey=0\nmods=xitest.dll,xitest_b.dll\n"
                 : igrun ? "[xikit]\nlog_folder=0\nswap=0\ncount_calls=1\nreport_every=60\nhotkey=0\nmods=imgui_panel.dll\n"
                 : pvrun ? "[xikit]\nlog_folder=0\nswap=0\ncount_calls=1\nreport_every=60\nhotkey=0\nmods=click_target.dll\n"
                 : uirun ? "[xikit]\nlog_folder=0\nswap=0\ncount_calls=1\nreport_every=60\nhotkey=0\nmods=ui_layout.dll\n"
                 : cfrun ? "[xikit]\nlog_folder=0\nswap=0\ncount_calls=1\nreport_every=60\nhotkey=0\nmods=color_filter.dll\n"
                 : phorun ? "[xikit]\nlog_folder=0\nswap=0\ncount_calls=1\nreport_every=60\nhotkey=0\nmods=photo_mode.dll\n"
                 : envrun ? "[xikit]\nlog_folder=0\nswap=0\ncount_calls=1\nreport_every=60\nhotkey=0\nmods=world_light.dll\n"
                 : audrun ? "[xikit]\nlog_folder=0\nswap=0\ncount_calls=1\nreport_every=60\nhotkey=0\nmods=audio_mix.dll\n"
                 : ovlrun ? "[xikit]\nlog_folder=0\nswap=0\ncount_calls=1\nreport_every=60\nhotkey=0\nmods=file_overlay.dll\n"
                 : camrun ? "[xikit]\nlog_folder=0\nswap=0\ncount_calls=1\nreport_every=60\nhotkey=0\nmods=camera_view.dll\n"
                 : fxrun ? "[xikit]\nlog_folder=0\nswap=0\ncount_calls=1\nreport_every=60\nhotkey=0\nmods=effect_comfort.dll\n"
                          : "[xikit]\nlog_folder=0\nswap=0\ncount_calls=1\nreport_every=60\nhotkey=0\n");
    if (fx2run) { FILE *mf = fopen("xikit_mods.ini", "w"); if (mf) { fputs("[effect_comfort]\nfx_list=1\n", mf); fclose(mf); }
                  mf = fopen("effects.txt", "w"); if (mf) { fputs("# path-prefix percent\nspel/fire 0\nfile:4321 0\n", mf); fclose(mf); } fill_iat(g); }
    if (uirun) { FILE *mf = fopen("xikit_mods.ini", "w"); if (mf) { fputs("[ui_layout]\nui_dx=100\nui_list=1\n", mf); fclose(mf); }
                 mf = fopen("ui_layout.txt", "w"); if (mf) { fputs("# window dx dy\nmenuinventor 5 -3\n", mf); fclose(mf); } fill_iat(g); }
    if (prtrun) { FILE *mf = fopen("xikit_mods.ini", "w"); if (mf) { fputs("[prishe]\npanel_show=1\nreplies_in_chat=0\ndump_textures=1\nhost=1\n", mf); fclose(mf); } }   /* (Prishe's in-game panel shown) */
    if (hbrun) { FILE *mf = fopen("xikit_mods.ini", "w"); if (mf) { fputs("[hotbar]\nhb_dry=1\n", mf); fclose(mf); }
                 mf = fopen("hotbar.txt", "w"); if (mf) { fputs("bar 1 3 100 100\nbar 2 4 10 10 v\nxiv xiv\nwindower win\njob war\nset Sword\n"
                   "1.1 f9 Heal = /heal\n1.2 c-1 Check = /check <t>\n1.3 none Wave = /wave\nbattle 2.1 none Seq = /wave; wait 0.2; /bow\n"
                   "field 2.2 none Tag = hb env battle\n", mf); fclose(mf); }
                 CreateDirectoryA("xiv", NULL); CreateDirectoryA("xiv\\data", NULL); CreateDirectoryA("xiv\\priv_res", NULL);
                 mf = fopen("xiv\\data\\General.lua", "w"); if (mf) { fputs("xivhotbar_keybinds_general['Root'] = {\n  { 'battle 2 2', 'macro', 'input /sit;wait 0.1;input /stand', '', 'Sit' },\n}\n", mf); fclose(mf); }
                 mf = fopen("xiv\\data\\war.lua", "w"); if (mf) { fputs("xivhotbar_keybinds_job['Base'] = {\n  { 'battle 1 2', 'ja', 'Provoke', 't', 'Prov' },\n"
                   "  { 'battle 2 3', 'ma', 'Cure', 'stpc', 'Cure' },\n}\nxivhotbar_keybinds_job['Sword'] = {\n  { 'battle 2 4', 'ws', \"Fast Blade\", 't', 'FB' },\n}\n"
                   "xivhotbar_keybinds_job['Club'] = {\n  { 'battle 2 4', 'ws', 'Brainshaker', 't', 'BS' },\n}\n", mf); fclose(mf); }
                 mf = fopen("xiv\\priv_res\\spells.lua", "w"); if (mf) { fputs("return {\n  [1] = { id = 1, en = \"Cure\", ja = \"x\", levels = { [3] = 1, [5] = 3 }, mp_cost = 8, prefix = \"/magic\", range = 12, cast_time = 2, recast = 5, recast_id = 1, skill = 33, targets = 63, type = \"WhiteMagic\" },\n"
                   "  [159] = { id = 159, en = \"Stone\", ja = \"x\", element = 3, mp_cost = 4, prefix = \"/magic\", range = 12, recast_id = 159, skill = 36, targets = 32, type = \"BlackMagic\" },\n"
                   "  [896] = { id = 896, en = \"Shantotto\", ja = \"x\", levels = { [1] = 1 }, mp_cost = 0, targets = 1, type = \"Trust\" },\n}\n", mf); fclose(mf); }
                 mf = fopen("xiv\\priv_res\\job_abilities.lua", "w"); if (mf) { fputs("return {\n  [35] = { id = 35, en = \"Provoke\", element = 1, mp_cost = 0, prefix = \"/jobability\", range = 11, recast_id = 5, targets = 32, tp_cost = 0, type = \"JobAbility\" },\n"
                   "  [255] = { id = 255, en = \"Sic\", element = 0, mp_cost = 0, prefix = \"/pet\", range = 11, recast_id = 102, targets = 32, tp_cost = 0, type = \"PetCommand\" },\n"
                   "  [600] = { id = 600, en = \"Geocrush\", element = 3, mp_cost = 0, prefix = \"/pet\", range = 4, recast_id = 173, targets = 32, tp_cost = 0, type = \"BloodPactRage\" },\n"
                   "  [672] = { id = 672, en = \"Foot Kick\", element = 0, mp_cost = 1, prefix = \"/pet\", range = 4, recast_id = 102, targets = 32, tp_cost = 0, type = \"Monster\" },\n}\n", mf); fclose(mf); }
                 mf = fopen("xiv\\priv_res\\weapon_skills.lua", "w"); if (mf) { fputs("return {\n  [32] = { id = 32, en = \"Fast Blade\", element = 0, range = 2, skill = 3, skillchain_a = \"Scission\", skillchain_b = \"\", skillchain_c = \"\", targets = 32 },\n"
                   "  [33] = { id = 33, en = \"Burning Blade\", element = 0, range = 2, skill = 3, skillchain_a = \"Liquefaction\", skillchain_b = \"\", skillchain_c = \"\", targets = 32 },\n}\n", mf); fclose(mf); }
                 CreateDirectoryA("xiv\\lib", NULL); CreateDirectoryA("win", NULL); CreateDirectoryA("win\\res", NULL);
                 mf = fopen("xiv\\lib\\bloodpacts.lua", "w"); if (mf) { fputs("return {\n  [600] = { id = 600, en = \"Geocrush\", damage = \"magic\" },\n}\n", mf); fclose(mf); }
                 /* Windower's res\monster_abilities.lua, written as Windower writes it (no spaces) */
                 mf = fopen("win\\res\\monster_abilities.lua", "w"); if (mf) { fputs("return {\n    [3840] = {id=3840,en=\"Foot Kick\",ja=\"x\",skillchain_a=\"Reverberation\",skillchain_b=\"\",skillchain_c=\"\"},\n    [3841] = {id=3841,en=\"Dust Cloud\",ja=\"x\"},\n}\n", mf); fclose(mf); }
                 /* Windower's res\items.lua (no spaces), and Petit Trois's icon for the Potion: a 2x2 BMP */
                 mf = fopen("win\\res\\items.lua", "w"); if (mf) { fputs("return {\n    [4112] = {id=4112,en=\"Potion\",ja=\"x\",category=\"Usable\",targets=1,type=7},\n"
                   "    [4128] = {id=4128,en=\"Ether\",ja=\"x\",category=\"Usable\",targets=1,type=7},\n    [16535] = {id=16535,en=\"Bronze Sword\",ja=\"x\",category=\"Weapon\",skill=3,targets=0,type=4},\n"
                   "    [17024] = {id=17024,en=\"Ash Club\",ja=\"x\",category=\"Weapon\",skill=11,targets=0,type=4},\n}\n", mf); fclose(mf); }
                 CreateDirectoryA("xiv\\images", NULL); CreateDirectoryA("xiv\\images\\icons", NULL); CreateDirectoryA("xiv\\images\\icons\\items", NULL);
                 mf = fopen("xiv\\images\\icons\\items\\4112.bmp", "wb");
                 if (mf) { static const unsigned char bmp[70] = { 'B','M',70,0,0,0,0,0,0,0,54,0,0,0, 40,0,0,0, 2,0,0,0, 2,0,0,0, 1,0, 24,0, 0,0,0,0, 16,0,0,0, 0x13,0x0B,0,0, 0x13,0x0B,0,0, 0,0,0,0, 0,0,0,0,
                     0,0,255, 0,255,0, 0,0, 255,0,0, 255,255,255, 0,0 }; fwrite(bmp, 1, sizeof bmp, mf); fclose(mf); }
                 /* (29 Nov) Horizon's spell list (Windower's no-space form): a spell only it has */
                 mf = fopen("xiv\\priv_res\\horizon_spells.lua", "w"); if (mf) { fputs("return {\n    [1] = {id=1,en=\"Cure\",ja=\"x\",levels={[3]=1,[5]=3},mp_cost=8,prefix=\"/magic\",range=12,targets=63,type=\"WhiteMagic\"},\n"
                   "    [990] = {id=990,en=\"Horizon Glow\",ja=\"x\",mp_cost=1,prefix=\"/magic\",range=12,targets=1,type=\"WhiteMagic\"},\n}\n", mf); fclose(mf); }
                 mf = fopen("xiv\\priv_res\\spell_descriptions.lua", "w"); if (mf) { fputs("return {\n  [1] = { id = 1, en = \"Restores target's HP.\" },\n}\n", mf); fclose(mf); }
                 mf = fopen("xiv\\priv_res\\ability_descriptions.lua", "w"); if (mf) { fputs("return {\n  [32] = { id = 32, en = \"Delivers a two-hit attack.\" },\n  [547] = { id = 547, en = \"Goads an enemy into attacking you.\" },\n}\n", mf); fclose(mf); }
                 fill_iat(g); fake_tool_hook(); }
    if (pvrun) { FILE *mf = fopen("xikit_mods.ini", "w"); if (mf) { fputs("[click_target]\nct_show=1\nct_log=1\n", mf); fclose(mf); } fill_iat(g); }
    if (cfrun) { FILE *mf = fopen("xikit_mods.ini", "w"); if (mf) { fputs("[color_filter]\ncb_mode=2\ncb_simulate=1\ncb_strength=100\ncb_check=1\n", mf); fclose(mf); } }
    if (phorun) { FILE *mf = fopen("xikit_mods.ini", "w"); if (mf) { fputs("[photo_mode]\nphoto=1\nphoto_yaw=90\nphoto_dist=200\nphoto_shot=1\nphoto_hide_ui=1\n", mf); fclose(mf); } fill_iat(g); }
    if (envrun) { FILE *mf = fopen("xikit_mods.ini", "w"); if (mf) { fputs("[world_light]\nfog_distance=50\nfog_r=200\nambient=150\nlight=200\n", mf); fclose(mf); } fill_iat(g); }
    if (audrun) { FILE *mf = fopen("xikit_mods.ini", "w"); if (mf) { fputs("[audio_mix]\nvol_interface=50\nvol_effects=150\nvol_ambient=25\nvol_music=50\n", mf); fclose(mf); } fill_iat(g); }
    if (ovlrun) { FILE *mf = fopen("xikit_mods.ini", "w"); if (mf) { fputs("[file_overlay]\noverlay_log=1\n", mf); fclose(mf); } fill_iat(g); }
    if (camrun) { FILE *mf = fopen("xikit_mods.ini", "w"); if (mf) { fputs("[camera_view]\nfov_deg=90\nfar_percent=200\ndraw_percent=200\n", mf); fclose(mf); } fill_iat(g); }
    if (fxrun) { FILE *mf = fopen("xikit_mods.ini", "w"); if (mf) { fputs("[effect_comfort]\nflash_limit=50\nfx_intensity=50\nfx_all_blended=1\n", mf); fclose(mf); } fill_iat(g); }
    if (texrun) { FILE *mf = fopen("xikit_mods.ini", "w"); if (mf) { fputs("[texture_replace]\ntex_dump=1\ntex_log=1\n", mf); fclose(mf); } fill_iat(g); }
    if (prtrun) fill_iat(g);
    if (prirun) { FILE *mf = fopen("xikit_mods.ini", "w"); if (mf) { fputs("[prishe_probe]\nprobe_again=0\n", mf); fclose(mf); } fill_iat(g); prishe_patch(); }
    if (!LoadLibraryA("xikit.dll")) { printf("FAIL: xikit.dll not loaded (%lu)\n", GetLastError()); return 2; }
    for (int t = 0; t < 400 && *(void **)dev == vt0; t++) Sleep(50);
    if (texrun || fxrun || camrun || ovlrun || audrun || envrun || phorun || cfrun || uirun || pvrun || hbrun || fx2run || igrun || xtrun || prirun || prtrun) {
      if (prtrun) prishert_run(dev, g); else if (prirun) prishe_run(dev); else if (texrun) texmod_run(dev); else if (fxrun) fxmod_run(dev); else if (camrun) cammod_run(dev); else if (ovlrun) ovlmod_run(dev, g); else if (audrun) audmod_run(dev); else if (envrun) envmod_run(dev); else if (phorun) phomod_run(dev); else if (cfrun) cfmod_run(dev); else if (uirun) uimod_run(dev); else if (pvrun) ctmod_run(dev); else if (hbrun) hbmod_run(dev); else if (igrun) igmod_run(dev); else if (xtrun) xtmod_run(dev); else fx2mod_run(dev);
      printf("%s\n", fails ? "FAILED" : "ALL OK");
      ExitProcess(fails ? 1 : 0);
    }
    check(*(void **)dev != vt0, "the kit hooked the real device (its own vtable copy)");
    int okp = 1;
    for (int f = 0; f < 200; f++) {                         /* through the object's vtable, as the game calls it */
      IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF000000u | (DWORD)f, 1.0f, 0);
      okp &= SUCCEEDED(IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL));
    }
    check(okp, "200 frames presented through the hooked device");
    char name[MAX_PATH], line[512]; snprintf(name, sizeof name, "xikit_timing_%lu.csv", GetCurrentProcessId());
    FILE *tm = fopen(name, "r"); int trows = 0;
    if (tm) { while (fgets(line, sizeof line, tm)) if (line[0] >= '0' && line[0] <= '9') trows++; fclose(tm); }
    check(trows >= 3, "xikit_timing_<pid>.csv has a line per 60 frames");
    IDirect3DDevice8_Release(dev); IDirect3D8_Release(d3d);
    printf("%s\n", fails ? "FAILED" : "ALL OK");
    ExitProcess(fails ? 1 : 0);
  }
  /* include_untested=1: these checks are about how the kit patches, so they use functions whatever their gate
     coverage; the default (untested functions left out) is checked below */
  uint8_t orig_frame[5]; memcpy(orig_frame, (void *)(uintptr_t)ga(FRAME_RENDER), 5);
  if (modrun && !reloadrun) { FILE *mf = fopen("xikit_mods.ini", "w"); if (mf) { fputs("[mod_test]\nmt_level=5\n", mf); fclose(mf); } }   /* (settings, below) */
  if (pubrun) { FILE *mf = fopen("xikit_mods.ini", "w"); if (mf) { fputs("[mod_public]\nmp_level=5\n", mf); fclose(mf); } }
  touch_ini(ini, pubrun ? "[xikit]\nlog_folder=0\nswap=0\ncount_calls=1\nreport_every=60\nhotkey=0\nlog_each=1\nmods=mod_public.dll\n"
                 : toolrun ? "[xikit]\nlog_folder=0\nswap=0\ncount_calls=1\nreport_every=60\nhotkey=0\nlog_each=1\nmods=mod_cmd.dll\n"
                 : chainrun ? "[xikit]\nlog_folder=0\nswap=0\ncount_calls=1\nreport_every=60\nhotkey=0\nlog_each=1\nmods=mod_test.dll,mod_chain.dll\nmod_reload=1\n"
                 : faultrun ? "[xikit]\nlog_folder=0\nswap=0\ncount_calls=1\nreport_every=60\nhotkey=0\nlog_each=1\nmods=mod_test.dll,mod_fault.dll\n"
                 : staterun ? "[xikit]\nlog_folder=0\nswap=0\ncount_calls=1\nreport_every=60\nhotkey=0\nlog_each=1\nmods=mod_state.dll\n"
                 : abrun ? "[xikit]\nlog_folder=1\nswap=1\ninclude_untested=1\ncount_calls=1\nreport_every=60\nhotkey=0\nab=1\nab_after=0\nab_phase=1\nab_rounds=2\nab_settle=3\n"
                 : profile ? "[xikit]\nlog_folder=0\nswap=1\ninclude_untested=1\ncount_calls=1\nreport_every=60\nhotkey=0\nlog_each=1\nprofile=1\ncall_time=1\nkernel_calls=2\ntrace=1\ntrace_after=4\ntrace_count=1\nsample=1\ntrace_pictures=1\n"
                 : reloadrun ? "[xikit]\nlog_folder=0\nswap=1\ninclude_untested=1\ncount_calls=1\nreport_every=60\nhotkey=0\nlog_each=1\nmods=mod_test.dll\nmod_reload=1\n"
                 : modrun ? "[xikit]\nlog_folder=0\nswap=1\ninclude_untested=1\ncount_calls=1\nreport_every=60\nhotkey=0\nlog_each=1\nprofile=1\nmods=mod_test.dll\n"
                 : factrun ? "[xikit]\nlog_folder=0\nswap=0\ncount_calls=1\nreport_every=60\nhotkey=0\nlog_each=1\nfacts=1\n"
                 : blockrun ? "[xikit]\nlog_folder=0\nswap=1\ninclude_untested=1\ncount_calls=1\nreport_every=60\nhotkey=0\ntrace=1\ntrace_after=4\ntrace_count=1\ntrace_alternate=4\n"
                 : nativerun ? "[xikit]\nlog_folder=0\nswap=1\ninclude_untested=1\ncount_calls=1\nreport_every=60\nhotkey=0\nlog_each=1\nsample=2\nsample_ms=1\nsample_window=1\n"
                 : caprun ? "[xikit]\nlog_folder=0\nswap=0\ncount_calls=1\nreport_every=60\nhotkey=0\nlog_each=1\ncapture=CXiSkeletonActor::GetColor,CXiSkeletonActor::SetColor\ncapture_count=1\ncapture_pages=4096\n"
                         : "[xikit]\nlog_folder=0\nswap=1\ninclude_untested=1\ncount_calls=1\nreport_every=60\nhotkey=0\nlog_each=1\n");
  const char *tform = getenv("XT_TOOL_FORM"); if (!tform) tform = "e9";
  if (toolrun) fake_tool_form(tform);
  if (!LoadLibraryA("xikit.dll")) { printf("FAIL: xikit.dll not loaded (%lu)\n", GetLastError()); return 2; }
  for (int t = 0; t < 400 && g_dev.vt == g_vtbl; t++) Sleep(50);
  check(g_dev.vt != g_vtbl, "the kit hooked the device (its own vtable copy)");
  if (blockrun) {
    /* trace_alternate=4: 20 frames, the swaps flipped every 4 (frames 0-3 off, 4-7 on, 8-11 off, 12-15 on, 16-19 off);
       trace_after counts from the first frame the kit sees: frames every 20 ms for 7 s, so the timer and the 28 frames
       of the trace (8 to settle, 20 recorded) fall inside them whenever the kit's start-up ends */
    for (int i = 0; i < 350; i++) { present(1); Sleep(20); }
    char name[64], line[512]; snprintf(name, sizeof name, "xikit_trace_%lu_1.txt", GetCurrentProcessId());
    FILE *tr = fopen(name, "r"); int hdr = 0, last = -1, bad = 0, seen = 0;
    if (tr) { while (fgets(line, sizeof line, tr)) { if (!strncmp(line, "# d3d trace v1: alternating", 27) && strstr(line, "; 20 frames; block 4;")) hdr = 1;
                unsigned lab, fr; if (line[0] != '#' && sscanf(line, "%u %u 15", &lab, &fr) == 2) { seen++; if (lab != ((fr / 4) & 1)) bad = 1; if ((int)fr > last) last = fr; } } fclose(tr); }
    if (!(hdr && seen >= 20 && last == 19 && !bad)) printf("  (header %d, Present lines %d, last frame %d, wrong label %d)\n", hdr, seen, last, bad);
    check(hdr && seen >= 20 && last == 19 && !bad, "trace_alternate=4: the trace has 20 frames, the swaps off in frames 0-3, 8-11, 16-19 and on in 4-7, 12-15");
    printf("%s\n", fails ? "FAILED" : "ALL OK");
    ExitProcess(fails ? 1 : 0);
  }
  check(g_vtbl[15] == (void *)fake_present, "the original vtable was not written");
  if (pubrun) {
    /* the public kit: no gfx_recon_ingame.dll and swap=0. mod_public.dll (mod_public.cpp, built against the cut SDK)
       hooks CDx::EndClearBegin (in the cut manifest) with a pass-through, and BeginScene at the device; settings */
    present(4);
    char line[256]; HMODULE m = GetModuleHandleA("mod_public.dll");
    check(GetModuleHandleA("gfx_recon_ingame.dll") == NULL, "no reconstruction DLL is loaded");
    check(m != NULL, "mods=mod_public.dll: the kit loaded the mod");
    if (!m) { printf("FAILED\n"); ExitProcess(1); }
    check(*(volatile long *)GetProcAddress(m, "mod_init_rel") == (long)rel, "the mod's xi_rel was the game's load delta when its init ran");
    check(*(volatile long *)GetProcAddress(m, "mod_hook_result") == 0, "XI_HOOK(CDx::EndClearBegin) returned XIKIT_OK");
    uint8_t *ecb = (uint8_t *)(uintptr_t)ga(0x100096B0u), *tr = *(uint8_t **)GetProcAddress(m, "mod_prev_ecb");
    IMAGE_NT_HEADERS *mnt = (IMAGE_NT_HEADERS *)((char *)m + ((IMAGE_DOS_HEADER *)m)->e_lfanew);
    int32_t d; memcpy(&d, ecb + 1, 4); uintptr_t to = (uintptr_t)ecb + 5 + d;
    check(ecb[0] == 0xE9 && to >= (uintptr_t)m && to < (uintptr_t)m + mnt->OptionalHeader.SizeOfImage, "CDx::EndClearBegin's entry jumps into the mod");
    int ok = tr != NULL;
    if (ok) {                                   /* the trampoline: 9 bytes copied, its call re-aimed, jmp entry+9 */
      int32_t dg, dt, dj; memcpy(&dt, tr + 5, 4); memcpy(&dj, tr + 10, 4); memcpy(&dg, ecb + 5, 4);
      ok = tr[4] == 0xE8 && (uintptr_t)tr + 9 + dt == (uintptr_t)ecb + 9 + dg && tr[9] == 0xE9 && (uintptr_t)tr + 14 + dj == (uintptr_t)ecb + 9
           && !memcmp(tr, orig_ecb, 4);
    }
    check(ok, "its previous is a trampoline to the game's own code (copied call re-aimed, jump back to entry+9)");
    check(!memcmp((void *)(uintptr_t)ga(SETCOLOR), orig_set, 5) && !memcmp((void *)(uintptr_t)ga(GAMMA), orig_gam, 5),
          "nothing else is patched: SetColor and FontGlyphCache_GetDevice keep the game's bytes");
    check(*(volatile long *)GetProcAddress(m, "mod_frames") >= 2, "xikit_mod_frame ran each frame");
    typedef HRESULT (__stdcall *Dev0Fn)(void *);
    volatile long *begins = (volatile long *)GetProcAddress(m, "mod_begins"); long b0 = *begins; int bs0 = bs_calls;
    HRESULT h1 = ((Dev0Fn)g_dev.vt[34])(&g_dev);
    check(*(volatile long *)GetProcAddress(m, "mod_dev_result") == 0 && *begins == b0 + 1 && bs_calls == bs0 + 1 && h1 == 0,
          "the BeginScene device hook ran, and its previous reached the device's own BeginScene");
    volatile long *v0 = (volatile long *)GetProcAddress(m, "mod_set_v0"), *told = (volatile long *)GetProcAddress(m, "mod_set_told"),
                  *val = (volatile long *)GetProcAddress(m, "mod_set_val");
    check(*v0 == 5, "settings: declare_int read 5 from xikit_mods.ini ([mod_public] mp_level)");
    Sleep(20); WritePrivateProfileStringA("mod_public", "mp_level", "7", ".\\xikit_mods.ini"); present(70);
    check(*told >= 1 && *val == 7, "settings: the file changed to 7: the kit read it and called xikit_mod_settings");
    FILE *lg = fopen("xikit.log", "r"); int norec = 0, hooked = 0;
    if (lg) { while (fgets(line, sizeof line, lg)) {
                if (strstr(line, "no gfx_recon_ingame.dll and swap=0")) norec = 1;
                if (strstr(line, "mod mod_public.dll: hooked CDx::EndClearBegin") && strstr(line, "previous = the game's code (trampoline)")) hooked = 1; } fclose(lg); }
    check(norec && hooked, "xikit.log: no reconstruction and swap=0; the hook, with the game's code as previous");
    printf("%s\n", fails ? "FAILED" : "ALL OK");
    ExitProcess(fails ? 1 : 0);
  }
  {   /* build translation: the moved code ranges the kit read from this build's manifest reach the reconstruction */
    int32_t *xs = (int32_t *)GetProcAddress(GetModuleHandleA("gfx_recon_ingame.dll"), "xi_shift");
    printf("xi_shift:");
    if (xs) for (int i = 0; i <= 3 * xs[0] && i < 1 + 3 * 64; i++) printf(" %ld", (long)xs[i]);
    printf("\n");
    int swap0 = 0; { FILE *ki = fopen("xikit.ini", "r"); char kl[256];      /* (28 Nov) this mode's kit configuration */
      if (ki) { while (fgets(kl, sizeof kl, ki)) if (!strncmp(kl, "swap=0", 6)) swap0 = 1; fclose(ki); } }
    if (swap0 && !GetModuleHandleA("gfx_recon_ingame.dll"))      /* swap=0: the kit loads no reconstruction to fill */
      printf("note: swap=0 and no reconstruction loaded, so its xi_shift is not checked here\n");
    else check(xs != NULL, "the reconstruction exports xi_shift and the kit filled it (its ranges: the xi_shift line)");
  }
  present(2);
  uint8_t *set = (uint8_t *)(uintptr_t)ga(SETCOLOR), *gam = (uint8_t *)(uintptr_t)ga(GAMMA);
  if (g_no_swap && (argc < 2 || !strcmp(argv[1], "base") || !strcmp(argv[1], "relocated"))) {     /* a build where some functions changed: nothing of the reconstruction is swapped in (the mod runs go on below: mods work there) */
    present(2); Sleep(200); present(2);
    check(!memcmp(set, orig_set, 5) && !memcmp(gam, orig_gam, 5), "no_swap build: with swap=1 the entries stay the game's code");
    FILE *lf = fopen("xikit.log", "r"); char line[600]; int said = 0;
    if (lf) { while (fgets(line, sizeof line, lf)) if (strstr(line, "this build swaps nothing in from the reconstruction")) said = 1; fclose(lf); }
    check(said, "no_swap build: xikit.log says why nothing is swapped");
    printf("%s\n", fails ? "FAILED" : "ALL OK");
    ExitProcess(fails ? 1 : 0);
  }
  if (abrun) {
    /* ab=1 with log_folder=1: 4 phases of 1 s, A B B A; the swapped entries follow the phases; everything the kit writes
       goes to one new folder under xikit_logs */
    char seq[64] = ""; int ns = 0; int last = -1; DWORD t0 = GetTickCount();
    while (GetTickCount() - t0 < 6500) {
      present(1); Sleep(5);
      int on = set[0] == 0xE9;
      if (on != last && ns < 60) { seq[ns++] = on ? 'B' : 'A'; last = on; }
    }
    seq[ns] = 0;
    check(!strncmp(seq, "BABAB", 5) || !strncmp(seq, "ABAB", 4), "ab: the swaps went off and on with the phases");
    printf("note: entry states seen in order: %s (A B B A: off, on, on, off, then on again after the test)\n", seq);
    check(GetFileAttributesA("xikit.log") == INVALID_FILE_ATTRIBUTES, "log_folder=1: no xikit.log next to xikit.dll");
    WIN32_FIND_DATAA fd; HANDLE h = FindFirstFileA("xikit_logs\\*_*", &fd); char dir[MAX_PATH] = "";
    if (h != INVALID_HANDLE_VALUE) { snprintf(dir, sizeof dir, "xikit_logs\\%s", fd.cFileName); FindClose(h); }
    check(dir[0] != 0, "log_folder=1: a folder xikit_logs\\<date>_<time>_<pid> was made");
    char p2[MAX_PATH], line[512]; int rows = 0, labels_ok = 1, summary = 0; const char *want = "ABBA";
    snprintf(p2, sizeof p2, "%s\\xikit_ab_%lu_1.csv", dir, GetCurrentProcessId());
    FILE *af = fopen(p2, "r");
    if (af) { while (fgets(line, sizeof line, af)) {
        int ph, n; char lab; double mean;
        if (sscanf(line, "%d,%c,%d,%lf", &ph, &lab, &n, &mean) == 4) { if (ph < 1 || ph > 4 || lab != want[ph - 1] || n < 1 || mean <= 0) labels_ok = 0; rows++; }
        if (!strncmp(line, "# A (off):", 10)) summary = 1; } fclose(af); }
    check(rows == 4 && labels_ok && summary, "ab: xikit_ab_<pid>_1.csv in that folder has 4 phases A B B A with frames, and the summary");
    snprintf(p2, sizeof p2, "%s\\xikit.log", dir); int done = 0; FILE *lf = fopen(p2, "r");
    if (lf) { while (fgets(line, sizeof line, lf)) if (strstr(line, "ab: done. A (off)")) done = 1; fclose(lf); }
    check(done, "ab: xikit.log (in that folder) has the comparison");
    present(1); Sleep(150); present(1);                     /* a stutter: one frame of 150 ms */
    snprintf(p2, sizeof p2, "%s\\xikit_spikes_%lu.csv", dir, GetCurrentProcessId()); int spike = 0; FILE *sf = fopen(p2, "r");
    if (sf) { while (fgets(line, sizeof line, sf)) { unsigned fr; double ms; if (sscanf(line, "%u,%lf", &fr, &ms) == 2 && ms > 140) spike = 1; } fclose(sf); }
    check(spike, "spike_ms=50: a 150 ms frame is in xikit_spikes_<pid>.csv with its frame number");
    printf(fails ? "FAILED (%d)\n" : "ALL OK\n", fails);
    ExitProcess(fails ? 1 : 0);
  }
  if (!caprun && !factrun && !toolrun && !chainrun && !faultrun && !staterun && !g_no_swap && !(set[0] == 0xE9 && gam[0] == 0xE9)) printf("note: entry bytes SetColor %02X, FontGlyphCache_GetDevice %02X\n", set[0], gam[0]);
  if (!caprun && !factrun && !toolrun && !chainrun && !faultrun && !staterun && !g_no_swap) check(set[0] == 0xE9 && gam[0] == 0xE9, "swap=1: the entries now jump to the reconstruction");
  if (g_swap_set && (argc < 2 || !strcmp(argv[1], "base"))) {      /* (at its base: the manifest's bytes are the preferred-base ones) */
    check(g_keep32 && !memcmp((uint8_t *)(uintptr_t)ga(g_keep32), g_keep32_bytes, 5), "swap_set build: a function of flag 32 keeps the game's code while the others swap");
    FILE *lf = fopen("xikit.log", "r"); char line[600]; int said = 0;
    if (lf) { while (fgets(line, sizeof line, lf)) if (strstr(line, "keep the game's code in this build")) said = 1; fclose(lf); }
    check(said, "swap_set build: xikit.log says how many functions keep the game's code");
  }
  if (g_no_swap) check(!memcmp(gam, orig_gam, 5), "no_swap build: FontGlyphCache_GetDevice stays the game's code (only the mod's own hooks change entries)");
  check(presents == 2, "Present still reaches the device's own method");
  static uint8_t actor[0xA10];
  if (factrun) {
    /* facts=1 with xikit_facts.txt listing the calls in CDx::TestCooperativeLevel (0x10009716, call [ecx+0xC], 3 bytes: the
       region starts 2 bytes earlier) and CDx::BeginScene (0x10009736, call [ecx+0x88]): the game's own code (swap=0) runs them */
    char line[256]; int k;
    typedef BOOL (__attribute__((thiscall)) *CdxFn)(void *);
    for (k = 0; k < 5; k++) { ((CdxFn)(uintptr_t)ga(0x10009710u))(g_cdx); ((CdxFn)(uintptr_t)ga(0x10009730u))(g_cdx); }
    check(tcl_calls == 5 && bs_calls == 5, "facts=1: the patched call sites still reach the device's methods");
    present(60);
    char name[96]; snprintf(name, sizeof name, "xikit_facts_%lu.csv", GetCurrentProcessId());
    FILE *fc = fopen(name, "r"); int a = 0, b = 0;
    if (fc) { while (fgets(line, sizeof line, fc)) {
                if (!strncmp(line, "0x10009716,4,5,", 15) && strstr(line, ",3,0x10009710")) a = 1;
                if (!strncmp(line, "0x10009736,4,5,", 15) && strstr(line, ",34,0x10009730")) b = 1; } fclose(fc); }
    check(a && b, "xikit_facts_<pid>.csv: both sites, 5 calls each, the callee popped 4, through vtable slots 3 and 34");
    /* kind out: 0x10027C70 makes a local identity matrix (call 0x10027C7A, ECX = the local: the callee writes 1.0f at
       its start) and passes the local to a matrix product that only reads it (call 0x10027C94, stack dword 0);
       kind jmp: 0x101AFB40's switch (0x101AFB56) for the arguments 0..13 (13 is past its bound: no jump) */
    static float m_this[32], m_arg[16];
    typedef void (__attribute__((thiscall)) *MatFn)(void *, void *);
    typedef int (__attribute__((thiscall)) *SwFn)(void *, int);
    for (k = 0; k < 5; k++) ((MatFn)(uintptr_t)ga(0x10027C70u))(m_this, m_arg);
    static uint8_t swobj[0x40];
    for (k = 0; k <= 13; k++) ((SwFn)(uintptr_t)ga(0x101AFB40u))(swobj, k);
    present(60);
    long ecxc = -1, ecxw = -1, argc_ = -1, argw = -1, jn = 0; int jt = 0;
    fc = fopen(name, "r");
    if (fc) { while (fgets(line, sizeof line, fc)) {
                long c1, c2; char cls[8];
                if (sscanf(line, "out,0x10027C7A,ecx0,%7[a-z],%ld,%ld", cls, &c1, &c2) == 3) { ecxc = c1; ecxw = c2; }
                if (sscanf(line, "out,0x10027C94,arg0,%7[a-z],%ld,%ld", cls, &c1, &c2) == 3) { argc_ = c1; argw = c2; }
                if (!strncmp(line, "0x101AFB56,jmp,", 15)) { jn += strtol(line + 15, NULL, 10); jt++; } } fclose(fc); }
    printf("out: 0x10027C7A ecx %ld calls %ld changed; 0x10027C94 arg0 %ld calls %ld changed; jmp 0x101AFB56 %ld jumps to %d targets\n", ecxc, ecxw, argc_, argw, jn, jt);
    check(ecxc == 5 && ecxw >= 1, "kind out: the local `this` the identity constructor writes is seen changed");
    check(argc_ == 5 && argw == 0, "kind out: the local the matrix product only reads is never seen changed");
    if (g_hshift[0] && ga(0x101AFB56u) != 0x101AFB56u + g_hrel) {   /* the switch moved in this build: its bytes hold a moved table address */
      FILE *lf = fopen("xikit.log", "r"); char ln[600]; int refused = 0;
      if (lf) { while (fgets(ln, sizeof ln, lf)) if (strstr(ln, "101AFB56") && (strstr(ln, "refus") || strstr(ln, "differ"))) refused = 1; fclose(lf); }
      check(jn == 0 && refused, "kind jmp: on a build where the switch moved, its site is refused (its bytes hold the moved table's address) and nothing recorded");
    } else
    check(jn == 13 && jt >= 2, "kind jmp: the switch's 13 jumps (arguments 0..12) recorded, with their targets");
    printf("%s\n", fails ? "FAILED" : "ALL OK");
    ExitProcess(fails ? 1 : 0);
  }
  if (caprun) {
    /* capture=: the first call of the game's GetColor (swap=0: the game's code) is captured; the call still returns
       the game's value; after capture_count calls the entry has its own bytes again. test_xikit.py replays the
       .xcap through the gate (pipeline/xcap.py) */
    char line[256];
    uint8_t *get = (uint8_t *)(uintptr_t)ga(GETCOLOR);
    check(get[0] == 0xE9, "capture=: GetColor's entry jumps to the capture stub");
    ((SetColorFn)(uintptr_t)ga(SETCOLOR))(actor, 0x5566AABBu);           /* captured too: one argument */
    check(*(uint32_t *)(actor + 0x660) == 0x5566AABBu, "the captured SetColor ran the game's code");
    check(((GetColorFn)get)(actor) == 0x5566AABBu, "the captured call returned the game's value");
    present(4);
    check(get[0] != 0xE9, "after capture_count calls the entry has its own bytes again");
    char name[96]; snprintf(name, sizeof name, "xikit_capture_%lu_A4840_1.xcap", GetCurrentProcessId());
    FILE *x = fopen(name, "rb"); long size = 0; uint32_t head[16] = {0};
    if (x) { fread(head, 4, 16, x); fseek(x, 0, SEEK_END); size = ftell(x); fclose(x); }
    check(x && head[0] == 0x50414358u && head[2] == GETCOLOR && head[8] > 0 && size == 64 + 36 + 72L * head[7] + 4L * head[8] + 4096L * head[8],
          "the .xcap holds the entry, the modules and the pages, sized as its header says");
    /* capture_follow (16): the pages after `this` (ECX) are taken, while readable */
    { uint32_t want = ((uint32_t)(uintptr_t)actor & ~0xFFFu) + 0x1000u; MEMORY_BASIC_INFORMATION mb; int have = 0;
      int readable = VirtualQuery((void *)(uintptr_t)want, &mb, sizeof mb) && mb.State == MEM_COMMIT && (mb.Protect & 0xEE) && !(mb.Protect & (PAGE_GUARD | PAGE_NOACCESS));
      x = fopen(name, "rb");
      if (x && head[8]) { uint32_t *pg = malloc(4 * head[8]); fseek(x, 64 + 36 + 72L * head[7], SEEK_SET);
                          if (pg && fread(pg, 4, head[8], x) == head[8]) for (uint32_t i = 0; i < head[8]; i++) have |= pg[i] == want;
                          free(pg); }
      if (x) fclose(x);
      check(!readable || have, "capture_follow: the page after the captured call's `this` is in the .xcap"); }
    FILE *lg = fopen("xikit.log", "r"); int logged = 0;
    if (lg) { while (fgets(line, sizeof line, lg)) if (strstr(line, "capture 1 of CXiSkeletonActor::GetColor")) logged = 1; fclose(lg); }
    check(logged, "xikit.log has the capture");
    printf("%s\n", fails ? "FAILED" : "ALL OK");
    ExitProcess(fails ? 1 : 0);
  }
  if (toolrun) {
    /* (25 Nov) another tool's jump was at Command_RunLine's entry before the kit (Windower's, in the owner's game):
       mod_cmd.dll hooks it through xikit_cmd.hpp. Every form but "bad" goes in front of the other tool: /xtcmd is the
       mod's, /wave reaches the other tool; "bad" is refused and the log names the bytes it saw */
    present(4);
    HMODULE c = GetModuleHandleA("mod_cmd.dll"); char what[400], l[900];
    check(c != NULL, "toolhook: mod_cmd.dll loaded");
    if (!c) { printf("FAILED\n"); ExitProcess(1); }
    long inst = *(volatile long *)GetProcAddress(c, "cmd_install");
    int said_front = 0, said_bytes = 0; FILE *lg = fopen("xikit.log", "r");
    if (lg) { while (fgets(l, sizeof l, lg)) { said_front |= strstr(l, strcmp(tform, "dyn") ? "previous = another tool's hook in host.exe" : "previous = another tool's hook in memory no module holds") != NULL; said_bytes |= strstr(l, "live bytes entry-4..+15:") != NULL; } fclose(lg); }
    typedef int (__cdecl *TRunFn)(char *, uint32_t);
    if (!strcmp(tform, "bad")) {
      snprintf(what, sizeof what, "toolhook %s: a byte after the other tool's jump differs from the game's: refused (%ld, not 0), the log names the live bytes", tform, inst);
      check(inst != 0 && said_bytes, what);
    } else {
      snprintf(what, sizeof what, "toolhook %s: the mod's hook went in front of the other tool's (%ld), logged", tform, inst);
      check(inst == 0 && said_front, what);
      char a[] = "/XTCMD hello", b[] = "/wave"; long t0 = g_fake_tool_calls, s0 = *(volatile long *)GetProcAddress(c, "cmd_seen");
      ((TRunFn)(void *)ga(0x10080DC0u))(a, 0); long t1 = g_fake_tool_calls, s1 = *(volatile long *)GetProcAddress(c, "cmd_seen");
      int rb = ((TRunFn)(void *)ga(0x10080DC0u))(b, 0); long t2 = g_fake_tool_calls;
      snprintf(what, sizeof what, "toolhook %s: /XTCMD taken by the mod (%ld) and not passed on (%ld); /wave reached the other tool (%ld, returned %d: 7)", tform, s1 - s0, t1 - t0, t2 - t1, rb);
      check(s1 - s0 == 1 && t1 == t0 && t2 - t1 == 1 && rb == 7, what);
    }
    { FILE *lg2 = fopen("xikit.log", "r"); if (lg2) { while (fgets(l, sizeof l, lg2)) if (strstr(l, "Command_RunLine")) printf("  log: %s", l); fclose(lg2); } }
    printf("%s\n", fails ? "FAILED" : "ALL OK");
    ExitProcess(fails ? 1 : 0);
  }
  if (staterun) {
    /* stand-in records in the game DLL's own record array (ActerBuffPtr 0x10480AF0, 0x900 pointers), its player
       index (0x10485F7A) and g_pXiZone (0x1065CB04, the zone number at +0x1B4): written before the first frame, then
       changed between frames; mod_state.dll reads them through xistate and counts the watchers' events */
    static uint8_t rec[2][0x300], zone[0x200]; static void *avt[0x100]; static void *act[0x40];
    void **arr = (void **)(uintptr_t)ga(0x10480AF0u); int16_t *self = (int16_t *)(uintptr_t)ga(0x10485F7Au); void **gz = (void **)(uintptr_t)ga(0x1065CB04u);
    HMODULE m = GetModuleHandleA("mod_state.dll");
    check(m != NULL, "mods=mod_state.dll: loaded");
    if (!m) { printf("FAILED\n"); ExitProcess(1); }
    const char *txt = (const char *)GetProcAddress(m, "state_text");
    volatile long *ap = (volatile long *)GetProcAddress(m, "ev_appeared"), *lf = (volatile long *)GetProcAddress(m, "ev_left"), *gr = (volatile long *)GetProcAddress(m, "ev_gear"), *zn = (volatile long *)GetProcAddress(m, "ev_zone");
    volatile long *gs = (volatile long *)GetProcAddress(m, "gear_slot"), *ga2 = (volatile long *)GetProcAddress(m, "gear_after");
    for (int k = 0; k < 0x100; k++) avt[k] = NULL;
    avt[0xCC / 4] = (void *)actor_drawn_name; avt[0] = (void *)runtime_class_skeleton; act[0] = avt;
    /* Bob's actor: another class, with junk where a skeleton actor's part list would be (actor +0x674 +0x44) */
    static void *bvt[0x100]; static uint8_t bobact[0x800];
    for (int k = 0; k < 0x100; k++) bvt[k] = NULL;
    bvt[0] = (void *)runtime_class_other; bvt[0xCC / 4] = (void *)actor_drawn_name_bob; *(void ***)bobact = bvt;
    *(uintptr_t *)(bobact + 0x674 + 0x44) = 0x10;
    strcpy((char *)rec[0] + 0x7C, "Alice"); rec[0][0xEE] = 0; rec[0][0xEF] = 2; *(uint32_t *)(rec[0] + 0x78) = 0x01000123u;
    for (int s2 = 0; s2 < 9; s2++) *(uint16_t *)(rec[0] + 0xFC + 2 * s2) = (uint16_t)(0x1000 * s2 + 0x11);
    float pos[3] = { 1.5f, 2.5f, -3.5f }, ang[3] = { 0.1f, 0.2f, 0.3f }; memcpy(rec[0] + 4, pos, 12); memcpy(rec[0] + 0x14, ang, 12);
    *(void **)(rec[0] + 0xA0) = act;
    strcpy((char *)rec[1] + 0x7C, "Bob"); *(int16_t *)(rec[1] + 0x210) = 1; strcpy((char *)rec[1] + 0x214, "Bob the Mithra"); rec[1][0xEF] = 7;
    *(void **)(rec[1] + 0xA0) = bobact;
    *(int *)(zone + 0x1B4) = 230;
    long ap0 = *ap, zn0 = *zn;                                   /* (the mod may have run frames already: counts from here) */
    /* (L21, xianim) the actor's model at +0x674: its parts' list at model +0x44; one part, its queue 0's list at part
       +0x24 +0x78 +4, holding two motions whose vtable is the game's CYyMotionQue (0x1032A1C0) */
    static uint8_t bigact[0x800], part[0x100], el1[0x40], el2[0x40];
    memcpy(bigact, act, sizeof act); *(void **)(rec[0] + 0xA0) = bigact;
    *(void **)(bigact + 0x674 + 0x44) = part; *(void **)(part + 0x24 + 0x78 + 4) = el1; *(void **)(el1 + 4) = el2;
    *(uintptr_t *)el1 = (uintptr_t)ga(0x1032A1C0u); *(uintptr_t *)el2 = (uintptr_t)ga(0x1032A1C0u);
    *(float *)(el1 + 0x24) = 10.0f; *(float *)(el1 + 0x28) = 1.0f; *(float *)(el2 + 0x24) = 3.0f; *(float *)(el2 + 0x28) = 0.5f;
    arr[5] = rec[0]; arr[7] = rec[1]; *self = 5; *gz = zone;
    present(2);
    char what[700];
    snprintf(what, sizeof what, "the readers: %s", txt); 
    check(strstr(txt, "self=Alice drawn=Alice kind=0 race=2 id=01000123 w0=0011 w8=8011 pos=1.5,2.5,-3.5 ang=0.10,0.20,0.30 zone=230 known=-2 rec7=1") != NULL, what);
    snprintf(what, sizeof what, "both stand-in records reported as appearing (%ld), the zone as one change (%ld)", *ap - ap0, *zn - zn0);
    check(*ap - ap0 == 2 && *lf == 0 && *gr == 0 && *zn - zn0 == 1, what);
    { /* (A9) the zone known only once the zone change has stored it: Actor_ResetDrawLists returning to the zone change's
         site after its store (0x1018B4D8) marks the object; SetPtr1D8FromTable returning into XiZone's constructor
         (0x1018B337) unmarks it. Both entries are the game's own, hooked by mod_state through install_zone_hooks */
      volatile long *zh = (volatile long *)GetProcAddress(m, "zone_hooks");
      snprintf(what, sizeof what, "install_zone_hooks: Actor_ResetDrawLists and XiZone::SetPtr1D8FromTable hooked (%ld)", zh ? *zh : -99);
      check(zh && *zh == 0, what);
      call_returning_to(ga(0x10081A50u), ga(0x1018B4D8u), NULL, 0, 0); present(1);
      snprintf(what, sizeof what, "the zone change's call after its store marks the zone known (%s)", txt); check(strstr(txt, "zone=230 known=230") != NULL, what);
      call_returning_to(ga(0x10081A50u), ga(0x10013B15u), NULL, 0, 0); present(1);
      check(strstr(txt, "known=230") != NULL, "Actor_ResetDrawLists from another caller changes nothing");
      call_returning_to(ga(0x1018BAE0u), ga(0x1018B337u), zone, 1, 0); present(1);
      snprintf(what, sizeof what, "XiZone's constructor (a new zone object) makes it unknown again (%s)", txt); check(strstr(txt, "zone=230 known=-2") != NULL, what);
      check(*(uintptr_t *)(zone + 0x1D8) == *(uintptr_t *)ga(0x10377C58u + 0), "and SetPtr1D8FromTable itself still ran (its +0x1D8 written from its table)");
      call_returning_to(ga(0x10081A50u), ga(0x1018B4D8u), NULL, 0, 0); present(1);
      check(strstr(txt, "known=230") != NULL, "stored again: known"); }
    { const char *at = (const char *)GetProcAddress(m, "anim_text"); volatile long *ac = (volatile long *)GetProcAddress(m, "anim_cmd");
      snprintf(what, sizeof what, "xianim: the player's actor's motions: %s", at); check(strstr(at, "motions=2 frozen=0 [q0 f=10.0 s=1.00] [q0 f=3.0 s=0.50]") != NULL, what);
      *ac = 1; present(2);
      snprintf(what, sizeof what, "xianim: frozen: both speeds 0 (%s)", at); check(strstr(at, "frozen=1 [q0 f=10.0 s=0.00] [q0 f=3.0 s=0.00]") != NULL, what);
      *ac = 3; present(1);
      snprintf(what, sizeof what, "xianim: stepped 5 frames while frozen (%s)", at); check(strstr(at, "[q0 f=15.0 s=0.00] [q0 f=8.0 s=0.00]") != NULL, what);
      *ac = 2; present(1);
      snprintf(what, sizeof what, "xianim: let go: the speeds back (%s)", at); check(strstr(at, "frozen=0 [q0 f=15.0 s=1.00] [q0 f=8.0 s=0.50]") != NULL, what); }
    *(uint16_t *)(rec[0] + 0xFC + 2 * 4) = 0x4055; present(1);
    snprintf(what, sizeof what, "gear: slot 4 changed to 0x4055: one gear event (%ld), slot %ld, word %lx", *gr, *gs, *ga2);
    check(*gr == 1 && *gs == 4 && *ga2 == 0x4055, what);
    *self = 7; present(1);
    check(strstr(txt, "self=Bob the Mithra") != NULL && strstr(txt, "race=7") != NULL, "the player index set to 7: the record's second name (+0x214, its word at +0x210 set)");
    { const char *at = (const char *)GetProcAddress(m, "anim_text");
      snprintf(what, sizeof what, "xianim: an actor that is not a CXiSkeletonActor (junk at +0x6B8) has no motions and is not walked (%s)", at);
      check(strncmp(at, "motions=0 frozen=0", 18) == 0, what); }
    arr[7] = NULL; present(1);
    check(*lf == 1 && strstr(txt, "self= ") != NULL && strstr(txt, "rec7=0") != NULL, "a record left: one event; the player's record then none (its slot empty)");
    *(int *)(zone + 0x1B4) = 231; present(1);
    check(*zn - zn0 == 2 && strstr(txt, "zone=231") != NULL, "the zone number changed: one zone event");
    *gz = NULL; present(1);
    check(*zn - zn0 == 3 && strstr(txt, "zone=-1 known=-1") != NULL, "g_pXiZone NULL (between zones): -1 (and known -1), one more event");
    arr[5] = NULL; *self = 0; present(1);
    { /* (29 Nov) the learned spells: the game's own handler of message 0xAA (0x100F00C0, cdecl: game state, -, message)
         fills game state +0x2CF54 from the message's +4 and sets +0x2CFD4; its accessor (0x100F00A0) then gives the
         block; xistate::spell_learned reads it as the magic menu does (bits[i >> 3] & (1 << (i & 7))) */
      typedef int (__cdecl *SpellLearned)(int);
      SpellLearned sl = (SpellLearned)(void *)GetProcAddress(m, "state_spell_learned");
      uint8_t **gsp = (uint8_t **)ga(0x104DFD98u); uint8_t *keep = *gsp;
      static uint8_t gstate[0x30000]; *gsp = gstate;
      check(sl && sl(1) == -1, "learned spells: before message 0xAA, xistate::spell_learned says -1 (the list has not come)");
      static uint8_t msg[0x84]; msg[4 + 0] = 0x06; msg[4 + 7] = 0x02; msg[4 + 127] = 0x80;   /* spells 1, 2, 57, 1023 */
      typedef char (__cdecl *Handler)(void *, void *, void *);
      char r = ((Handler)(void *)ga(0x100F00C0u))(gstate, NULL, msg);
      typedef uint8_t *(__cdecl *Block)(void);
      uint8_t *blk = ((Block)(void *)ga(0x100F00A0u))();
      snprintf(what, sizeof what, "learned spells: the game's 0xAA handler returned %d (1); its accessor gives game state +0x%X (+0x2CF54)", r, blk ? (unsigned)(blk - gstate) : 0);
      check(r == 1 && blk == gstate + 0x2CF54, what);
      int ok = sl && sl(1) == 1 && sl(2) == 1 && sl(57) == 1 && sl(1023) == 1 && sl(0) == 0 && sl(3) == 0 && sl(56) == 0 && sl(58) == 0 && sl(1022) == 0 && sl(1024) == -1;
      check(ok, "learned spells: after it, spells 1, 2, 57 and 1023 learned and 0, 3, 56, 58 and 1022 not, as the message's bits say");
      { /* (29 Nov) the abilities: message 0xAC's handler (0x100E6120: 0xE0 bytes to +0x2CDE8, +0x2CF49) and the id-list
           writer 0x100E6080 (cdecl: game state, ids, count; +0x2CEC8 cleared, its bits set, +0x2CF4A); then the game's
           MenuPanels_GetSlotInfo on a record of the abilities' table [0x1066714C] whose timer id has a count in the recast
           object 0x10666EC0 (entries of 8 bytes, timer id at +3; counts at +0xF8 + 4i, in 1/60 s) */
        typedef int (__cdecl *I1)(int); typedef int (__cdecl *I2)(int, int *);
        I1 al = (I1)(void *)GetProcAddress(m, "state_ability_learned"); I2 ar = (I2)(void *)GetProcAddress(m, "state_ability_recast");
        I1 as = (I1)(void *)GetProcAddress(m, "state_ability_state"); I1 ss = (I1)(void *)GetProcAddress(m, "state_spell_state");
        check(al && ar && as && ss, "abilities: mod_state's exports");
        static uint8_t m2[0xE4]; m2[4 + (0x223 >> 3)] = 1 << (0x223 & 7);          /* record 0x223: job ability 0x23 */
        ((Handler)(void *)ga(0x100E6120u))(gstate, NULL, m2);
        int b0 = al ? al(0x223) : -2;
        typedef void (__cdecl *IdList)(void *, uint16_t *, int); static uint16_t ids[1] = { 0x701 };
        ((IdList)(void *)ga(0x100E6080u))(gstate, ids, 1);
        int b1 = al(0x223), b2 = al(0x224), b3 = al(0x701), b4 = al(0x700);
        snprintf(what, sizeof what, "abilities: after 0xAC alone %d (-1: the id list not yet); after the id list too: 0x223 %d, 0x224 %d, 0x701 %d, 0x700 %d (1 0 1 0)", b0, b1, b2, b3, b4);
        check(b0 == -1 && b1 == 1 && b2 == 0 && b3 == 1 && b4 == 0, what);
        void **pab = (void **)ga(0x1066714Cu); void *kab = *pab; static uint8_t abt[0xB00 * 0x30]; *pab = abt;
        uint8_t *rec = abt + 0x223 * 0x30; *(uint16_t *)rec = 0x23; rec[2] = 1; *(uint16_t *)(rec + 8) = 5; rec[0xF] = 1;
        uint8_t *ro = (uint8_t *)ga(0x10666EC0u), kro[0x180]; memcpy(kro, ro, sizeof kro);
        for (int e = 0; e < 0x1F; e++) { ro[e * 8 + 2] = 0; ro[e * 8 + 3] = 0xFF; *(int16_t *)(ro + e * 8 + 4) = 0; }
        ro[3] = 5; *(int *)(ro + 0xF8) = 600;                                    /* timer 5: 600/60 s left */
        int ch = 7, sec = ar(0x223, &ch);
        snprintf(what, sizeof what, "abilities: the game's MenuPanels_GetSlotInfo on record 0x223 (timer 5, 600 ticks): %d s, charges %d (10, -1)", sec, ch);
        check(sec == 10 && ch == -1, what);
        uint8_t *pl = (uint8_t *)ga(0x10485638u), kpl[0x200]; memcpy(kpl, pl, sizeof kpl);
        pl[0x1EC] |= 1; pl[8] = 9; pl[9] = 30; rec[2] = 0x12; rec[0xE] = 0;     /* 0x10485824 bit 0; main job 9 at 30; type 0x12 */
        sec = ar(0x223, &ch);
        snprintf(what, sizeof what, "abilities: type 0x12 with main job 9 at level 30: %d s to the next charge, %d charges (10, 2: 3 charges in 90 s, 10 s left)", sec, ch);
        check(sec == 10 && ch == 2, what);
        memcpy(pl, kpl, sizeof kpl); rec[2] = 1;
        /* type 1's case is 2 (the table at 0x1038615A + 3 x type: 02): only the recast; 2 while it runs, 0 when it is 0 */
        int st = as(0x223); *(int *)(ro + 0xF8) = 0; int st0 = as(0x223);
        snprintf(what, sizeof what, "abilities: the game's check 0x10224B70 on record 0x223 (type 1): %d with the recast running, %d at 0 (2, 0)", st, st0);
        check(st == 2 && st0 == 0, what);
        int sp = ss(1);
        snprintf(what, sizeof what, "spells: xistate::spell_state with no spell table: %d (-1)", sp); check(sp == -1, what);
        memcpy(ro, kro, sizeof kro); *pab = kab;
      }
      *gsp = keep;
    }
    printf("%s\n", fails ? "FAILED" : "ALL OK");
    ExitProcess(fails ? 1 : 0);
  }
  if (faultrun) {
    /* mod_test.dll (game + 1) and mod_fault.dll (+ 1000, faulting in its third frame) both hook GetColor. Before the
       fault both run; the fault turns mod_fault off (hook taken off, no more frames), the game's frames go on, and
       mod_test's hook still runs */
    HMODULE m = GetModuleHandleA("mod_test.dll"), fm = GetModuleHandleA("mod_fault.dll");
    check(m && fm, "mods=mod_test.dll,mod_fault.dll: both loaded");
    if (!m || !fm) { printf("FAILED\n"); ExitProcess(1); }
    uint8_t *get = (uint8_t *)(uintptr_t)ga(GETCOLOR);
    ((SetColorFn)(uintptr_t)ga(SETCOLOR))(actor, 0x11223344u);
    check(*(volatile long *)GetProcAddress(fm, "fault_hooked") == 0 && ((GetColorFn)get)(actor) == 0x11223344u + 1001, "before the fault: both hooks run (+ 1 + 1000)");
    long before = presents;
    present(20);
    check(presents == before + 20, "the frames went on through the mod's fault (20 presents)");
    check(*(volatile long *)GetProcAddress(fm, "fault_frames") == 3, "the faulting mod's frame callback ran 3 times, then no more");
    check(((GetColorFn)get)(actor) == 0x11223344u + 1, "its hook is taken off: only mod_test's + 1 runs");
    { FILE *lg = fopen("xikit.log", "r"); char l[900]; int said = 0; if (lg) { while (fgets(l, sizeof l, lg)) said |= strstr(l, "mod mod_fault.dll turned off: exception 0xC0000005") && strstr(l, "frame callback") && strstr(l, "1 function hooks"); fclose(lg); }
      check(said, "xikit.log: the mod turned off, the exception, the callback and the hook taken off"); }
    volatile long *mf = (volatile long *)GetProcAddress(m, "mod_frames"); long f0 = mf ? *mf : -1; present(5);
    check(mf && *mf == f0 + 5, "the other mod's frame callback still runs");
    printf("%s\n", fails ? "FAILED" : "ALL OK");
    ExitProcess(fails ? 1 : 0);
  }
  if (chainrun) {
    /* API 5, hook chains: mod_test.dll (game + 1) and mod_chain.dll (+ 100) both hook CXiSkeletonActor::GetColor; the
       later one runs first, its previous runs the earlier one's hook, whose previous is the game's code. A reload of
       either re-aims the chain without breaking the other's previous */
    present(4);
    HMODULE m = GetModuleHandleA("mod_test.0.dll"), c = GetModuleHandleA("mod_chain.0.dll");
    check(m && c, "mods=mod_test.dll,mod_chain.dll (mod_reload=1): both loaded (copies .0)");
    if (!m || !c) { printf("FAILED\n"); ExitProcess(1); }
    check(*(volatile long *)GetProcAddress(c, "chain_api") == 5 && *(volatile long *)GetProcAddress(c, "chain_result") == 0,
          "the second mod's hook of the same function returned XIKIT_OK (kit API 5)");
    uint8_t *get = (uint8_t *)(uintptr_t)ga(GETCOLOR); int32_t d; memcpy(&d, get + 1, 4); uintptr_t to = (uintptr_t)get + 5 + d;
    IMAGE_NT_HEADERS *cn = (IMAGE_NT_HEADERS *)((char *)c + ((IMAGE_DOS_HEADER *)c)->e_lfanew);
    check(get[0] == 0xE9 && to >= (uintptr_t)c && to < (uintptr_t)c + cn->OptionalHeader.SizeOfImage, "GetColor's entry jumps into the mod that hooked it last");
    ((SetColorFn)(uintptr_t)ga(SETCOLOR))(actor, 0x11223344u);
    check(((GetColorFn)get)(actor) == 0x11223344u + 101, "both hooks ran: the game's value + 1 + 100");
    void *cp = *(void **)GetProcAddress(c, "chain_prev"), *mp = *(void **)GetProcAddress(m, "mod_prev");
    check(cp && ((GetColorFn)cp)(actor) == 0x11223345u, "the last mod's previous runs the first mod's hook (+ 1)");
    check(mp && ((GetColorFn)mp)(actor) == 0x11223344u, "the first mod's previous is the game's own code");
    { FILE *lg = fopen("xikit.log", "r"); char l[600]; int said = 0; if (lg) { while (fgets(l, sizeof l, lg)) said |= strstr(l, "previous = mod_test.dll's hook (chained") != NULL; fclose(lg); }
      check(said, "logged as chained"); }
    { FILE *lg = fopen("xikit.log", "r"); char l[600]; int said = 0; if (lg) { while (fgets(l, sizeof l, lg)) said |= strstr(l, "mod mod_chain.dll: mod_chain 1 (kit API 5 or later): the chain test's second mod") != NULL; fclose(lg); }
      check(said, "xikit_mod_info: the mod's name, version, API and description logged"); }
    /* only the inner mod rebuilt (mod_test2.dll: + 2): its hook comes off and goes on again, now outermost */
    check(CopyFileA("mod_test2.dll", "mod_test.dll", FALSE), "the inner mod rebuilt (mod_test2.dll written over mod_test.dll)");
    present(100);
    HMODULE m1 = GetModuleHandleA("mod_test.1.dll");
    check(m1 != NULL, "the kit loaded the inner mod's new build (mod_test.1.dll)");
    check(((GetColorFn)get)(actor) == 0x11223344u + 102, "after the reload: the game's value + 100 + 2, both hooks still run");
    check(((GetColorFn)cp)(actor) == 0x11223344u, "the other mod's previous, unchanged, now runs the game's own code (its link re-aimed)");
    memcpy(&d, get + 1, 4); to = (uintptr_t)get + 5 + d;
    IMAGE_NT_HEADERS *n1 = m1 ? (IMAGE_NT_HEADERS *)((char *)m1 + ((IMAGE_DOS_HEADER *)m1)->e_lfanew) : NULL;
    check(n1 && get[0] == 0xE9 && to >= (uintptr_t)m1 && to < (uintptr_t)m1 + n1->OptionalHeader.SizeOfImage, "the entry now jumps into the reloaded mod (outermost)");
    FILE *t = fopen("xikit_reload_now.txt", "w"); if (t) fclose(t);
    present(40);
    check(GetModuleHandleA("mod_test.2.dll") && GetModuleHandleA("mod_chain.1.dll") && ((GetColorFn)get)(actor) == 0x11223344u + 102,
          "xikit_reload_now.txt: both loaded again, both hooks run");
    printf("%s\n", fails ? "FAILED" : "ALL OK");
    ExitProcess(fails ? 1 : 0);
  }
  if (modrun) {
    /* sdk/: mod_test.dll (mod_test.cpp) hooks CXiSkeletonActor::GetColor with "the game's value + 1", its previous
       being a trampoline to the game's own code; SetColor is swapped to the reconstruction as usual */
    char line[256];
    HMODULE m = GetModuleHandleA(reloadrun ? "mod_test.0.dll" : "mod_test.dll");
    check(m != NULL, reloadrun ? "mods=mod_test.dll, mod_reload=1: the kit loaded a copy (xikit_mods_loaded\\mod_test.0.dll)" : "mods=mod_test.dll: the kit loaded the mod");
    if (!m) { printf("FAILED\n"); ExitProcess(1); }
    volatile long *frames = (volatile long *)GetProcAddress(m, "mod_frames"), *unk = (volatile long *)GetProcAddress(m, "mod_unknown_result"),
                  *irel = (volatile long *)GetProcAddress(m, "mod_init_rel");
    void **prev = (void **)GetProcAddress(m, "mod_prev");
    check(*irel == (long)rel, "the mod's xi_rel was the game's load delta when its init ran");
    uint8_t *get = (uint8_t *)(uintptr_t)ga(GETCOLOR);
    int32_t d; memcpy(&d, get + 1, 4); uintptr_t to = (uintptr_t)get + 5 + d;
    IMAGE_NT_HEADERS *mnt = (IMAGE_NT_HEADERS *)((char *)m + ((IMAGE_DOS_HEADER *)m)->e_lfanew);
    check(get[0] == 0xE9 && to >= (uintptr_t)m && to < (uintptr_t)m + mnt->OptionalHeader.SizeOfImage, "GetColor's entry jumps into the mod (not the reconstruction)");
    ((SetColorFn)set)(actor, 0x11223344u);
    check(((GetColorFn)get)(actor) == 0x11223345u, "the hook ran: the game's GetColor value + 1");
    check(*prev && ((GetColorFn)*prev)(actor) == 0x11223344u, "the hook's previous (a trampoline) runs the game's own GetColor");
    check(*prev < (void *)m || *prev >= (void *)((char *)m + mnt->OptionalHeader.SizeOfImage), "previous is outside the mod (the kit's trampoline)");
    check(*unk == -1, "hook() of a name not in the manifest returned XIKIT_E_UNKNOWN");
    /* CDx::EndClearBegin's trampoline (T=9:5): 9 bytes copied, the rel32 call at +4 re-aimed, then jmp entry+9 */
    uint8_t *ecb = (uint8_t *)(uintptr_t)ga(0x100096B0u), *tr = *(uint8_t **)GetProcAddress(m, "mod_prev_ecb");
    int ok = tr != NULL;
    if (ok) {
      int32_t dg, dt, dj; memcpy(&dt, tr + 5, 4); memcpy(&dj, tr + 10, 4);
      memcpy(&dg, (uint8_t *)(uintptr_t)(ga(0x100096B0u) + 5), 4);    /* (entry+5..8: after the kit's jmp, still the game's) */
      ok = tr[4] == 0xE8 && (uintptr_t)tr + 9 + dt == (uintptr_t)ecb + 9 + dg && tr[9] == 0xE9 && (uintptr_t)tr + 14 + dj == (uintptr_t)ecb + 9
           && !memcmp(tr, orig_ecb, 4) && ecb[0] == 0xE9;    /* the 4 bytes before the call as the game had them; the entry now the kit's jmp */
    }
    check(ok, "CDx::EndClearBegin's trampoline: its copied call reaches the game's own target, then it jumps back to entry+9");
    check(*frames >= 2, "xikit_mod_frame ran each frame");
    if (!reloadrun) {
      /* declared settings (version 4): xikit_mods.ini (written before the kit started) gave 5; a change to the file is
         read and told within 70 frames; the mod's own set_int (as an in-game command) too; out of range refused */
      volatile long *v0 = (volatile long *)GetProcAddress(m, "mod_set_v0"), *bad = (volatile long *)GetProcAddress(m, "mod_set_bad"),
                    *told = (volatile long *)GetProcAddress(m, "mod_set_told"), *val = (volatile long *)GetProcAddress(m, "mod_set_val");
      check(v0 && *v0 == 5 && bad && *bad == 0, "settings: declare_int read 5 from xikit_mods.ini ([mod_test] mt_level); set_int(12), out of 0..9, refused");
      Sleep(20); WritePrivateProfileStringA("mod_test", "mt_level", "7", ".\\xikit_mods.ini"); present(70);
      check(told && *told >= 1 && *val == 7, "settings: the file changed to 7: the kit read it and called xikit_mod_settings");
      typedef int (__cdecl *SetFn)(int); SetFn ds = (SetFn)GetProcAddress(m, "mod_do_set");
      long t0 = *told; Sleep(20); int w = ds ? ds(8) : 0; present(70);
      check(w == 1 && *told == t0 + 1 && *val == 8, "settings: the mod's set_int(8) wrote the file; read back and told");
      FILE *sl = fopen("xikit_settings.txt", "r"); int listed = 0;
      if (sl) { while (fgets(line, sizeof line, sl)) if (strstr(line, "[mod_test] mt_level = 8 (default 3, 0..9): a test setting")) listed = 1; fclose(sl); }
      check(listed, "settings: xikit_settings.txt lists the declared setting with its value, default, range and help");
      char ov[16]; GetPrivateProfileStringA("mod_test", "mt_other", "", ov, sizeof ov, ".\\xikit_mods.ini");
      check(!strcmp(ov, "4"), "settings: a declared key the file lacked was written with its default (mt_other=4)");
    }
    FILE *lg = fopen("xikit.log", "r"); int hooked = 0, refused = 0;
    if (lg) { while (fgets(line, sizeof line, lg)) {
                if (strstr(line, "mod mod_test.dll: hooked CXiSkeletonActor::GetColor") && strstr(line, "previous = the game's code (trampoline)")) hooked = 1;
                if (strstr(line, "hook(No::SuchFunction): not a function of the manifest")) refused = 1; } fclose(lg); }
    check(hooked && refused, "xikit.log has the hook and the refusal");
    /* device hooks: BeginScene passes on (the mod counts, the device's own method runs), TestCooperativeLevel
       answers 7 by itself; a hook whose slot does not match its name is refused */
    typedef HRESULT (__stdcall *Dev0Fn)(void *);
    volatile long *begins = (volatile long *)GetProcAddress(m, "mod_begins");
    long b0 = *begins; int bs0 = bs_calls, tc0 = tcl_calls;
    HRESULT h1 = ((Dev0Fn)g_dev.vt[34])(&g_dev), h2 = ((Dev0Fn)g_dev.vt[3])(&g_dev);
    check(*(volatile long *)GetProcAddress(m, "mod_dev_result") == 0, "device_hook of BeginScene and TestCooperativeLevel returned XIKIT_OK");
    check(*begins == b0 + 1 && bs_calls == bs0 + 1 && h1 == 0, "the BeginScene device hook ran, and its previous reached the device's own BeginScene");
    check(h2 == 7 && tcl_calls == tc0, "the TestCooperativeLevel device hook answered by itself (the device's method not called)");
    check(*(volatile long *)GetProcAddress(m, "mod_bad_slot_result") == -1, "device_hook(\"BeginScene\", slot 35) refused: the slot is EndScene's");
    { void *fc = *(void **)GetProcAddress(m, "mod_fork_code"); int32_t ds; memcpy(&ds, set + 1, 4);
      check(*(volatile long *)GetProcAddress(m, "mod_fork_result") == 0 && fc && set[0] == 0xE9 && (uintptr_t)set + 5 + ds == (uintptr_t)fc,
            "XI_FORK: SetColor's entry jumps to the mod's own SetColor (the fork)");
      ((SetColorFn)set)(actor, 0x0BADF00Du);
      check(*(uint32_t *)(actor + 0x660) == 0x0BADF00Du, "the fork ran: SetColor wrote this+0x660");
      ((SetColorFn)set)(actor, 0x11223344u); }
    if (reloadrun) {
      /* mod_reload=1: a rebuilt mod (mod_test2.dll: GetColor adds 2) written over mod_test.dll is loaded again, as
         xikit_mods_loaded\mod_test.1.dll: the old build's hooks off, its xikit_mod_unload called, the new ones on */
      check(CopyFileA("mod_test2.dll", "mod_test.dll", FALSE), "the rebuilt mod written over mod_test.dll (the loaded copy does not lock it)");
      present(100);
      HMODULE m1 = GetModuleHandleA("mod_test.1.dll");
      check(m1 != NULL, "the kit loaded the new build (mod_test.1.dll) within 100 frames");
      if (!m1) { printf("FAILED\n"); ExitProcess(1); }
      check(*(volatile long *)GetProcAddress(m, "mod_unloaded") == 1, "the old build's xikit_mod_unload ran");
      memcpy(&d, get + 1, 4); to = (uintptr_t)get + 5 + d;
      IMAGE_NT_HEADERS *n1 = (IMAGE_NT_HEADERS *)((char *)m1 + ((IMAGE_DOS_HEADER *)m1)->e_lfanew);
      check(get[0] == 0xE9 && to >= (uintptr_t)m1 && to < (uintptr_t)m1 + n1->OptionalHeader.SizeOfImage, "GetColor's entry now jumps into the new build");
      check(((GetColorFn)get)(actor) == 0x11223346u, "the new build's hook runs: the game's GetColor value + 2");
      check(*(void **)GetProcAddress(m1, "mod_prev") == *prev, "the new build's previous is the same trampoline (built once, from the untouched entry)");
      volatile long *b1 = (volatile long *)GetProcAddress(m1, "mod_begins"); long ob = *begins, nb = *b1; bs0 = bs_calls;
      ((Dev0Fn)g_dev.vt[34])(&g_dev);
      check(*b1 == nb + 2 && *begins == ob && bs_calls == bs0 + 1, "BeginScene now runs the new build's device hook only, then the device's own method");
      FILE *t = fopen("xikit_reload_now.txt", "w"); if (t) fclose(t);
      present(40);
      check(GetModuleHandleA("mod_test.2.dll") != NULL && ((GetColorFn)get)(actor) == 0x11223346u, "xikit_reload_now.txt: loaded again (mod_test.2.dll), hooks on");
      printf("%s\n", fails ? "FAILED" : "ALL OK");
      ExitProcess(fails ? 1 : 0);
    }
    touch_ini(ini, "[xikit]\nlog_folder=0\nswap=0\ncount_calls=1\nreport_every=60\nhotkey=0\nlog_each=1\nprofile=1\nmods=mod_test.dll\n");
    present(130);
    check(!memcmp(gam, orig_gam, 5), "swap=0: FontGlyphCache_GetDevice has its original bytes again");
    check(get[0] == 0xE9 && ((GetColorFn)get)(actor) == 0x11223345u && set[0] == 0xE9, "swap=0: the mod's hook and its fork stay");
    /* the profiler sits behind the device hooks: the BeginScene above reached it through the mod's previous, and is
       reported at the host's call site (the call the hook was handling), not at an address inside the mod */
    present(600);
    { char nm[64]; snprintf(nm, sizeof nm, "d3dprof_%lu.csv", GetCurrentProcessId()); FILE *pc = fopen(nm, "r");
      HMODULE hx = GetModuleHandleA(NULL); IMAGE_NT_HEADERS *hn = (IMAGE_NT_HEADERS *)((char *)hx + ((IMAGE_DOS_HEADER *)hx)->e_lfanew);
      int in_host = 0, in_mod = 0;
      if (pc) { while (fgets(line, sizeof line, pc)) if (!strncmp(line, "BeginScene,0x", 13)) {
                  uintptr_t a = (uintptr_t)strtoul(line + 11, NULL, 16);
                  if (a >= (uintptr_t)hx && a < (uintptr_t)hx + hn->OptionalHeader.SizeOfImage) in_host = 1;
                  if (a >= (uintptr_t)m && a < (uintptr_t)m + mnt->OptionalHeader.SizeOfImage) in_mod = 1; } fclose(pc); }
      check(in_host && !in_mod, "d3dprof reports the hooked BeginScene at the host's call site, none inside the mod");
      /* a creation through the mod's CreateTexture hook: the resource log names the host's call site too */
      void *tex = NULL; ((HRESULT (__stdcall *)(void *, UINT, UINT, UINT, DWORD, DWORD, DWORD, void **))g_dev.vt[20])(&g_dev, 64, 32, 1, 0, 21, 1, &tex);
      snprintf(nm, sizeof nm, "xikit_resources_%lu.csv", GetCurrentProcessId()); FILE *rf = fopen(nm, "r"); int r_host = 0, r_mod = 0;
      if (rf) { while (fgets(line, sizeof line, rf)) { char *q = strstr(line, "\"CreateTexture(");
                  if (!q || !(q = strstr(q, "\",0x"))) continue;
                  uintptr_t a = (uintptr_t)strtoul(q + 2, NULL, 16);
                  if (a >= (uintptr_t)hx && a < (uintptr_t)hx + hn->OptionalHeader.SizeOfImage) r_host = 1;
                  if (a >= (uintptr_t)m && a < (uintptr_t)m + mnt->OptionalHeader.SizeOfImage) r_mod = 1; } fclose(rf); }
      check(tex == g_faketex && r_host && !r_mod, "a CreateTexture through the mod's device hook: xikit_resources_<pid>.csv names the host's call site, not the mod"); }
    printf("%s\n", fails ? "FAILED" : "ALL OK");
    ExitProcess(fails ? 1 : 0);
  }
  if (g_no_swap && nativerun) {   /* a no_swap build: the sampler over the game's own GetColor (nothing is swapped in to check) */
    DWORD t = GetTickCount(); volatile uint32_t sink = 0;
    /* (20 Nov) GetColor for 50 ms between frames, not 10000 calls: under a WoW64 Wine a frame's syscalls (the message
       pump, the kit's writes) outweighed 10000 calls, and the loop sampled mostly the frame */
    GetColorFn gc_ = (GetColorFn)(uintptr_t)ga(GETCOLOR);   /* (once: on a translated build ga() searches the moved ranges, which outweighed GetColor) */
    while (GetTickCount() - t < 2500) { DWORD t2 = GetTickCount(); while (GetTickCount() - t2 < 50) for (int k = 0; k < 1000; k++) sink += gc_(actor); present(1); }
    Sleep(2500);
    printf("%s\n", fails ? "FAILED" : "ALL OK");
    ExitProcess(fails ? 1 : 0);
  }
  ((SetColorFn)set)(actor, 0x11223344u);
  check(*(uint32_t *)(actor + 0x660) == 0x11223344u, "reconstructed SetColor wrote this+0x660");
  check(((GetColorFn)(uintptr_t)ga(GETCOLOR))(actor) == 0x11223344u, "GetColor (swapped too) reads it back");
  check(((GammaFn)gam)() == (void *)&g_dev, "reconstructed FontGlyphCache_GetDevice read g_pCDx at the rebased address");
  present(60);
  FILE *csv; char name[64]; snprintf(name, sizeof name, "xikit_calls_%lu.csv", GetCurrentProcessId());
  csv = fopen(name, "r"); int seen = 0; char line[256];
  if (csv) { while (fgets(line, sizeof line, csv)) if (strstr(line, "0x100A4830,") && strstr(line, ",1,1,1")) seen = 1; fclose(csv); }
  check(seen, "the call count of SetColor is in the report (1 call)");
  if (nativerun) {         /* sample=2: the game's GetColor for 2.5 s, then time for the sampler's windows (test_xikit.py reads them) */
    DWORD t = GetTickCount(); volatile uint32_t sink = 0;
    /* (20 Nov) GetColor for 50 ms between frames, not 10000 calls: under a WoW64 Wine a frame's syscalls (the message
       pump, the kit's writes) outweighed 10000 calls, and the loop sampled mostly the frame */
    GetColorFn gc_ = (GetColorFn)(uintptr_t)ga(GETCOLOR);   /* (once: on a translated build ga() searches the moved ranges, which outweighed GetColor) */
    while (GetTickCount() - t < 2500) { DWORD t2 = GetTickCount(); while (GetTickCount() - t2 < 50) for (int k = 0; k < 1000; k++) sink += gc_(actor); present(1); }
    Sleep(2500);
  }
  touch_ini(ini, "[xikit]\nlog_folder=0\nswap=0\ncount_calls=1\nreport_every=60\nhotkey=0\nlog_each=1\n");
  present(130);
  check(!memcmp(set, orig_set, 5) && !memcmp(gam, orig_gam, 5), "swap=0 (ini re-read): the original bytes are back");
  /* the default: a function the gate's compared trials did not fully cover (manifest flag 4) is left out.
     Frame_Render's trials ran 53 of its 1424 instructions */
  uint8_t *frame = (uint8_t *)(uintptr_t)ga(FRAME_RENDER);
  touch_ini(ini, "[xikit]\nlog_folder=0\nswap=1\ninclude_untested=1\ncount_calls=1\nreport_every=60\nhotkey=0\nlog_each=1\n");
  present(130);
  check(frame[0] == 0xE9, "include_untested=1: Frame_Render (flag 4) is swapped");
  touch_ini(ini, "[xikit]\nlog_folder=0\nswap=1\ncount_calls=1\nreport_every=60\nhotkey=0\nlog_each=1\n");
  present(130);
  check(!memcmp(frame, orig_frame, 5), "the default (include_untested=0): Frame_Render, flag 4, has its original bytes");
  touch_ini(ini, "[xikit]\nlog_folder=0\nswap=1\ninclude_untested=1\nexclude=FontGlyphCache_GetDevice,CDx::PushRenderTargetTexture\ncount_calls=1\nreport_every=60\nhotkey=0\nlog_each=1\n");
  present(130);
  check(set[0] == 0xE9 && !memcmp(gam, orig_gam, 5), "swap=1 with an exclude: SetColor swapped, FontGlyphCache_GetDevice not");
  /* bisect: SetColor is the "culprit" (the screen is wrong while it is swapped); the host answers as a person would */
  if (!profile) {          /* (its extra frames would shift the profiler's per-window counts) */
  touch_ini(ini, "[xikit]\nlog_folder=0\nswap=1\ninclude_untested=1\ncount_calls=1\nreport_every=60\nhotkey=0\nlog_each=1\nbisect=1\n");
    present(130);
    ((SetColorFn)set)(actor, 1); ((GetColorFn)(uintptr_t)ga(GETCOLOR))(actor); ((GammaFn)gam)();
    present(2);
    { void (__cdecl *answer)(int) = (void (__cdecl *)(int))GetProcAddress(GetModuleHandleA("xikit.dll"), "xikit_bisect_answer");
      check(answer != NULL, "bisect: xikit_bisect_answer is exported");
      answer(1);                                   /* the screen is wrong: start */
      for (int step = 0; step < 40; step++) {
        present(2);
        int bad = set[0] == 0xE9;                  /* wrong exactly while SetColor is swapped */
        FILE *lg = fopen("xikit.log", "r"); int done = 0;
        if (lg) { while (fgets(line, sizeof line, lg)) if (strstr(line, "CULPRIT")) done = 1; fclose(lg); }
        if (done) break;
        answer(bad);
      }
      present(2);
      FILE *lg = fopen("xikit.log", "r"); int cul = 0;
      if (lg) { while (fgets(line, sizeof line, lg)) if (strstr(line, "CULPRIT: CXiSkeletonActor::SetColor")) cul = 1; fclose(lg); }
      check(cul, "bisect: narrowed to CXiSkeletonActor::SetColor and logged it");
      present(2);
      check(set[0] != 0xE9 && !memcmp(set, orig_set, 5), "bisect: the culprit stays on the original code after it is found");
      answer(2); present(2);
      check(set[0] == 0xE9, "bisect: F12 (stop) swaps everything again, the culprit included");
      /* two functions that break the screen only together (SetColor and GetColor swapped at once): no single culprit */
      uint8_t *gc = (uint8_t *)(uintptr_t)ga(GETCOLOR);
      answer(1);
      for (int step = 0; step < 60; step++) {
        present(2);
        int bad = set[0] == 0xE9 && gc[0] == 0xE9;
        FILE *lg = fopen("xikit.log", "r"); int done = 0;
        if (lg) { while (fgets(line, sizeof line, lg)) if (strstr(line, "CULPRITS TOGETHER")) done = 1; fclose(lg); }
        if (done) break;
        answer(bad);
      }
      present(2);
      lg = fopen("xikit.log", "r"); int pair = 0, both = 0;
      if (lg) { while (fgets(line, sizeof line, lg)) {
                  if (strstr(line, "CULPRITS TOGETHER: these 2 functions")) pair = 1;
                  if (strstr(line, "culprits (2):") && strstr(line, "CXiSkeletonActor::SetColor") && strstr(line, "CXiSkeletonActor::GetColor")) both = 1; }
                fclose(lg); }
      check(pair && both, "bisect: two functions that break the screen only together are found as that pair");
      check(set[0] != 0xE9 && gc[0] != 0xE9, "bisect: both stay on the original code after they are found");
      answer(2); present(2); }
    touch_ini(ini, "[xikit]\nlog_folder=0\nswap=1\ninclude_untested=1\nexclude=FontGlyphCache_GetDevice,CDx::PushRenderTargetTexture\ncount_calls=1\nreport_every=60\nhotkey=0\nlog_each=1\n");
    present(130);
  }
  /* a crash inside reconstructed code: SetColor on a null this */
  AddVectoredExceptionHandler(0, host_veh);
  volatile char room[1024]; landing_sp = ((uintptr_t)(room + 512)) & ~15u; (void)room;
  if (!setjmp(jb)) { armed = 1; ((SetColorFn)set)(NULL, 1); printf("FAIL: no exception\n"); fails++; }
  else printf("ok: the access violation inside the reconstruction was raised and passed on to the game's handlers\n");
  present(2);
  check(!memcmp(set, orig_set, 5), "the quarantined function was restored at the next frame");
  FILE *q = fopen("xikit_quarantine.txt", "r"); int quar = 0;
  if (q) { while (fgets(line, sizeof line, q)) if (strstr(line, "0x100A4830")) quar = 1; fclose(q); }
  check(quar, "it is in xikit_quarantine.txt");
  /* a fault in the game's own code, called from a reconstruction: CDx::PushRenderTargetRet1 on a null CDx calls
     CDx_PushRenderTarget (0x10009E20, swapped too), whose reconstruction calls the original
     CDx_PushRenderTargetTexture (excluded from the swap above: it is in the tree too), which faults reading the null CDx. The kit finds the reconstructions' return
     addresses on the stack and quarantines the innermost, CDx_PushRenderTarget, as suspected. */
  uint8_t *prt = (uint8_t *)(uintptr_t)ga(PUSHRT1);
  check(prt[0] == 0xE9, "CDx::PushRenderTargetRet1 is swapped");
  if (!setjmp(jb)) { armed = 1; ((PushRt1Fn)prt)(NULL, 0, 0, 0); printf("FAIL: no exception\n"); fails++; }
  else printf("ok: the access violation in the game's code it called was raised and passed on\n");
  present(2);
  uint8_t *pr = (uint8_t *)(uintptr_t)ga(0x10009E20u);
  check(pr[0] != 0xE9 && prt[0] == 0xE9, "the innermost reconstructed caller (CDx_PushRenderTarget) was restored at the next frame, its caller not");
  q = fopen("xikit_quarantine.txt", "r"); quar = 0;
  if (q) { while (fgets(line, sizeof line, q)) if (strstr(line, "0x10009E20") && strstr(line, "suspected")) quar = 1; fclose(q); }
  check(quar, "it is in xikit_quarantine.txt as suspected");
  if (profile) {
    /* d3dprof sits in front of the kit's copy: Present goes thunk -> kit_present -> the device's own method.
       Its report is rewritten every 600 frames; the host's own Present calls come from outside FFXiMain.dll */
    int before = presents; present(600);
    check(presents == before + 600, "profile=1: Present still reaches the device's own method through both hooks");
    snprintf(name, sizeof name, "d3dprof_%lu.csv", GetCurrentProcessId());
    csv = fopen(name, "r"); int head = 0, row = 0, ctime = 0, crow = 0, khook = 0, kpeek = 0, kcol = 0;
    if (csv) {
      while (fgets(line, sizeof line, csv)) {
        if (!strncmp(line, "# d3dprof v2: 600 frames", 24)) head = 1;
        if (!strncmp(line, "# call time: QueryPerformanceCounter", 36)) ctime++;
        if (strstr(line, ",primitives_per_frame,us_per_call,us_per_frame")) ctime++;
        if (strstr(line, ",us_per_frame,k_Lock2,k_Unlock2,k_WaitForSyncFromCpu,k_Render")) kcol = 1;
        if (!khook && !strncmp(line, "# kernel", 8)) printf("%s", line);   /* (the first window's: what was hooked and refused) */
        if (!strncmp(line, "# kernel calls: hooked ", 23) && !strstr(line, "hooked 0 ")) khook = 1;
        if (!kpeek && !strncmp(line, "# stub NtUserPeekMessage per frame: render thread ", 50)) { printf("%s", line); kpeek = !strncmp(line + 50, "3.00,", 5); }
        /* call_time=1: the Present row carries the time per call and per frame (two numbers after the primitives) */
        if (!strncmp(line, "Present,", 8)) { double a, b, c, d, e; char *p = strstr(line, ",host.exe+0x"); if (p) p = strchr(p + 1, ',');   /* the caller: its module */
          if (p && sscanf(p + 1, "%lf,%lf,%lf,%lf,%lf", &a, &b, &c, &d, &e) == 5 && d >= 0 && e >= 0) crow = 1; }
        /* the first window: a frame is Present to Present, so 601 Present calls over 600 frames = 1.002 */
        if (!strncmp(line, "Present,", 8) && strstr(line, ",host.exe+0x") && strstr(line, ",1.002,")) row = 1;
      }
      fclose(csv);
    }
    check(head, "profile=1: d3dprof wrote its report after 600 frames");
    check(ctime == 2 && crow, "call_time=1: the report has the timer line, the two time columns, and Present's time per call and per frame");
    check(khook && kcol, "kernel_calls=2: win32u's system-call stubs were hooked and the report has the k_ columns");
    check(kpeek, "kernel_calls=2: the three PeekMessage calls a frame inside Present are counted on the render thread");
    /* the sampler should find the render thread in game or reconstructed code when it is there: GetColor (swapped)
       called for about half a second, then a window of frames so the samples are written */
    { DWORD t = GetTickCount(); volatile uint32_t sink = 0;
      GetColorFn gc_ = (GetColorFn)(uintptr_t)ga(GETCOLOR);   /* (once, as in the native mode) */
      while (GetTickCount() - t < 500) for (int k = 0; k < 10000; k++) sink += gc_(actor);
      present(60); }
    /* resources: a texture and a vertex shader created through the device (as the game would), logged by d3dprof's
       wrappers; the shader saved as the game passed it: stream 0, v0 <- FLOAT3, v5 <- D3DCOLOR; m4x4 oPos, v0, c0; mov oD0, v5 */
    { void *tex = NULL; DWORD vsh = 0;
      static const DWORD decl[] = { 0x20000000u, 0x40020000u, 0x40040005u, 0xFFFFFFFFu };
      static const DWORD fn[] = { 0xFFFE0101u, 0x00000014u, 0xC00F0000u, 0x90E40000u, 0xA0E40000u, 0x00000001u, 0xD00F0000u, 0x90E40005u, 0x0000FFFFu };
      ((HRESULT (__stdcall *)(void *, UINT, UINT, UINT, DWORD, DWORD, DWORD, void **))g_dev.vt[20])(&g_dev, 256, 128, 1, 0, 21, 1, &tex);
      ((HRESULT (__stdcall *)(void *, const DWORD *, const DWORD *, DWORD *, DWORD))g_dev.vt[75])(&g_dev, decl, fn, &vsh, 0);
      check(tex == g_faketex && vsh == 0x1234, "CreateTexture and CreateVertexShader through the hooked device still return the device's results");
      snprintf(name, sizeof name, "xikit_resources_%lu.csv", GetCurrentProcessId());
      FILE *rf = fopen(name, "r"); int t1 = 0, v1 = 0;
      if (rf) { while (fgets(line, sizeof line, rf)) { if (strstr(line, ",\"CreateTexture(") && strstr(line, ",100,80,1,0,15,1")) t1 = 1;
                                                       if (strstr(line, ",\"CreateVertexShader(") && strstr(line, ",00001234,4,9,0")) v1 = 1; } fclose(rf); }
      check(t1 && v1, "xikit_resources_<pid>.csv logs both, with their parameters and the objects created");
      snprintf(name, sizeof name, "xikit_vtables_%lu.csv", GetCurrentProcessId());
      FILE *vf = fopen(name, "r"); int vrows = 0, vok = 0; static char vl[2048];
      if (vf) { while (fgets(vl, sizeof vl, vf)) if (!strncmp(vl, "IDirect3DTexture8,", 18)) {
                  int commas = 0; for (char *q = vl; *q; q++) commas += *q == ',';
                  vrows++; vok = commas == 20 && strstr(vl, ".exe+0x") != NULL; } fclose(vf); }
      check(vrows == 1 && vok, "xikit_vtables_<pid>.csv: the created texture's vtable once, as IDirect3DTexture8 with its 19 entries"); }
    /* timing (always) and the sampling profiler (sample=1): written every report_every (60) frames */
    snprintf(name, sizeof name, "xikit_timing_%lu.csv", GetCurrentProcessId());
    FILE *tm = fopen(name, "r"); int trows = 0;
    if (tm) { while (fgets(line, sizeof line, tm)) if (line[0] >= '0' && line[0] <= '9') trows++; fclose(tm); }
    check(trows >= 5, "xikit_timing_<pid>.csv has a line per window (frame, Present and kit times)");
    snprintf(name, sizeof name, "xikit_samples_%lu.csv", GetCurrentProcessId());
    FILE *sm = fopen(name, "r"); int shead = 0, srows = 0;
    if (sm) { while (fgets(line, sizeof line, sm)) { if (!strncmp(line, "# xikit samples:", 16)) shead = 1; if (!strncmp(line, "self,", 5)) srows++; } fclose(sm); }
    check(shead && srows > 0, "sample=1: xikit_samples_<pid>.csv holds samples of the render thread");
    sm = fopen(name, "r"); int ingame = 0;
    if (sm) { while (fgets(line, sizeof line, sm)) if (!strncmp(line, "self,recon,", 11) && strstr(line, "GetColor")) ingame = 1; fclose(sm); }
    check(ingame, "sample=1: samples taken while the thread ran the reconstructed GetColor name it");
    check(row, "profile=1: the report has Present (601 calls in 600 frames) from outside FFXiMain.dll");
  }
  if (profile) {
    /* trace_after=4 starts the trace four seconds after the first frame; trace_alternate defaults to 1: 17 frames with the
       swaps flipped at every Present (frame 0 off, 1 on, ..., 15 on, 16 off); the host's Present is the only call */
    Sleep(4500); present(100);
    snprintf(name, sizeof name, "xikit_trace_%lu_1.txt", GetCurrentProcessId());
    FILE *tr = fopen(name, "r"); int hdr = 0, l0 = 0, l1 = 0, l15 = 0, l16 = 0, bad = 0;
    if (tr) { while (fgets(line, sizeof line, tr)) { if (!strncmp(line, "# d3d trace v1: alternating", 27)) hdr = 1;
                unsigned lab, fr; if (line[0] != '#' && sscanf(line, "%u %u 15", &lab, &fr) == 2 && lab != (fr & 1)) bad = 1;
                if (!strncmp(line, "0 0 15 Present", 14)) l0 = 1;
                if (!strncmp(line, "1 1 15 Present", 14)) l1 = 1;
                if (!strncmp(line, "1 15 15 Present", 15)) l15 = 1;
                if (!strncmp(line, "0 16 15 Present", 15)) l16 = 1; } fclose(tr); }
    check(hdr && l0 && l1 && l15 && l16 && !bad, "trace: xikit_trace_<pid>_1.txt has 17 frames, the swaps off in the even ones (label 0) and on in the odd ones (label 1)");
    /* the file trigger: creating xikit_trace_now.txt starts another, and the kit deletes the file */
    FILE *tn = fopen("xikit_trace_now.txt", "w"); if (tn) fclose(tn);
    present(100);
    snprintf(name, sizeof name, "xikit_trace_%lu_2.txt", GetCurrentProcessId());
    tr = fopen(name, "r"); int two = tr != NULL; if (tr) fclose(tr);
    check(two && GetFileAttributesA("xikit_trace_now.txt") == INVALID_FILE_ATTRIBUTES, "trace: xikit_trace_now.txt started a second trace and was deleted");
  }
  printf("%s\n", fails ? "FAILED" : "ALL OK");
  ExitProcess(fails ? 1 : 0);
}
