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

static void check(int cond, const char *what) { printf("%s: %s\n", cond ? "ok" : "FAIL", what); if (!cond) fails++; }
static void paint(void) {        /* the top band animates smoothly (a triangle wave); the bottom band is GetColor's */
  int t = presents % 400; uint32_t a = (uint32_t)(t < 200 ? t : 400 - t), b = g_paint_site && g_paint_site[0] == 0xE9 ? 200 : 50;
  for (int y = 0; y < PH; y++) for (int x = 0; x < PW; x++) g_bbpix[y * PW + x] = y < PH / 2 ? a * 0x010101u : (b << 16);
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
  IDirect3DDevice8_SetRenderTarget(dev, old, oldz); if (old) IDirect3DSurface8_Release(old); if (oldz) IDirect3DSurface8_Release(oldz); IDirect3DSurface8_Release(rt);
  return 0;
}

/* ------------------------------------------------------------------------------------------------ cammod mode
   sdk/examples/camera_view.dll through the kit (fov_deg=90, far_percent=200), with the game's own
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
   says vol_interface=200: the kit reads it again and the mod sets the interface value from the game's last level. */
typedef void (__cdecl *SetFn)(float);
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
  FILE *mf = fopen("xikit_mods.ini", "w"); if (mf) { fputs("[audio_mix]\nvol_interface=200\nvol_effects=150\nvol_ambient=25\n", mf); fclose(mf); }
  for (int f = 0; f < 120 && *(float *)ga(0x10351700u) != 2.0f; f++) {
    IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF000000u, 1.0f, 0); IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL); Sleep(30);
  }
  a = *(float *)ga(0x10351700u);
  snprintf(what, sizeof what, "audmod: vol_interface=200 in xikit_mods.ini while running: the interface value is %.3f (2.0, from the game's last level)", a);
  check(a == 2.0f, what);
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
static int uimod_run(IDirect3DDevice8 *dev) {
  for (int t = 0; t < 400 && *(uint8_t *)ga(0x1015F6A0u) != 0xE9; t++) {
    IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET, 0xFF000000u, 1.0f, 0); IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL); Sleep(50);
  }
  check(*(uint8_t *)ga(0x1015F6A0u) == 0xE9, "uimod: Menu_DrawLayers' entry jumps (the mod's hook)");
  static uint8_t w1[0x100], w2[0x100], md1[0x80], md2[0x80], n1[0x18], n2[0x18], cursor[0x400], resmng[0x10000];
  memset(w1, 0, sizeof w1); memset(w2, 0, sizeof w2);
  memcpy(md1 + 0x46, "menu    inventor", 16); memcpy(md2 + 0x46, "menu    equip   ", 16);
  *(void **)(w1 + 4) = md1; *(void **)(w2 + 4) = md2; w1[0x60] = 9; w2[0x60] = 9;
  short r1[4] = { 10, 20, 110, 220 }, r2[4] = { 0, 0, 50, 50 }; memcpy(w1 + 0x3A, r1, 8); memcpy(w2 + 0x3A, r2, 8);
  memset(n1, 0, sizeof n1); memset(n2, 0, sizeof n2); *(void **)n1 = n2; *(void **)(n1 + 0x10) = w1; *(void **)(n2 + 0x10) = w2;
  uint8_t *mng = (uint8_t *)ga(0x10621838u); uint8_t saved[0x60]; memcpy(saved, mng, sizeof saved);
  memset(mng, 0, sizeof saved); *(void **)mng = n1;
  memset(cursor, 0, sizeof cursor); memset(resmng, 0, sizeof resmng);
  void **pcur = (void **)ga(0x104E1D4Cu), **pres = (void **)ga(0x1047BFA8u); void *oc = *pcur, *orr = *pres;
  if (!*pcur) *pcur = cursor;
  if (!*pres) { *pres = resmng; *(IDirect3DDevice8 **)(resmng + 0xEBC) = dev; *(void **)(resmng + 0xDC8) = g_cdx; }
  DrawLayersFn draw = (DrawLayersFn)(void *)ga(0x1015F6A0u); HitFn hit = (HitFn)(void *)ga(0x10118C10u); char what[220];
  IDirect3DDevice8_BeginScene(dev); draw(mng); IDirect3DDevice8_EndScene(dev);
  short *a = (short *)(w1 + 0x3A), *b = (short *)(w2 + 0x3A);
  snprintf(what, sizeof what, "uimod: menuinventor moved by 105,-3 to %d,%d..%d,%d; menuequip by 100,0 to %d,%d..%d,%d", a[0], a[1], a[2], a[3], b[0], b[1], b[2], b[3]);
  check(a[0] == 115 && a[1] == 17 && a[2] == 215 && a[3] == 217 && b[0] == 100 && b[1] == 0 && b[2] == 150 && b[3] == 50, what);
  uint32_t pin[2] = { 200, 30 }, pout[2] = { 50, 30 };
  check((hit(w1, pin) & 0xFF) == 1 && (hit(w1, pout) & 0xFF) == 0, "uimod: the game's hit test finds (200,30) in the moved window and not (50,30)");
  short rb[4] = { 0, 0, 10, 10 }; memcpy(w1 + 0x3A, rb, 8);       /* the game rebuilds it */
  IDirect3DDevice8_BeginScene(dev); draw(mng); IDirect3DDevice8_EndScene(dev);
  snprintf(what, sizeof what, "uimod: rebuilt to 0,0..10,10 by the game: now %d,%d..%d,%d (105,-3..115,7)", a[0], a[1], a[2], a[3]);
  check(a[0] == 105 && a[1] == -3 && a[2] == 115 && a[3] == 7, what);
  IDirect3DDevice8_BeginScene(dev); draw(mng); IDirect3DDevice8_EndScene(dev);
  check(a[0] == 105 && a[1] == -3, "uimod: drawn again: not moved twice");
  memcpy(mng, saved, sizeof saved); *pcur = oc; *pres = orr;
  return 0;
}

/* ------------------------------------------------------------------------------------------------ fx2mod mode
   sdk/examples/effect_comfort.dll's per-effect control (effects.txt: "spel/fire 0"; fx_list=1): an element whose
   resource (element +0xFC, a handle) is chunk "fire" (type 5) under the scope "spel" (type 1, its parent at +0x28);
   the mod's test export does what its YmElem_SetupDevice hook does after the game's code (the game's own function
   did not return with stand-ins for the renderer's state), then a white draw onto black is left out; the export for
   RestoreDevice, then the same draw is drawn. */
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
  (void)(SetupFn)0; (void)(RestoreFn)0;
  static uint8_t elem[0x400], res[0x80], scope[0x80], proc[0x1000], mats[16][64], resmng[0x10000]; static void *hres, *hscope;
  memset(elem, 0, sizeof elem); memset(res, 0, sizeof res); memset(scope, 0, sizeof scope); memset(proc, 0, sizeof proc); memset(resmng, 0, sizeof resmng);
  memcpy(res + 0x20, "fire", 4); *(uint32_t *)(res + 0x24) = 5; memcpy(scope + 0x20, "spel", 4); *(uint32_t *)(scope + 0x24) = 1;
  hres = res; hscope = scope; *(void **)(res + 0x28) = &hscope; *(void **)(elem + 0xFC) = &hres;
  for (int i = 0; i < 16; i++) { ((void **)(proc + 0xA10))[i] = mats[i]; memset(mats[i], 0, 64); }
  *(IDirect3DDevice8 **)(resmng + 0xEBC) = dev; *(void **)(resmng + 0xDC8) = g_cdx;
  void **pp = (void **)ga(0x1047CF7Cu), **pr = (void **)ga(0x1047BFA8u); void *op = *pp, *orr = *pr; *pp = proc; *pr = resmng;
  IDirect3DSurface8 *rt = NULL, *old = NULL, *oldz = NULL; char what[160];
  IDirect3DDevice8_GetRenderTarget(dev, &old); IDirect3DDevice8_GetDepthStencilSurface(dev, &oldz);
  IDirect3DDevice8_CreateRenderTarget(dev, 4, 4, D3DFMT_A8R8G8B8, D3DMULTISAMPLE_NONE, TRUE, &rt);
  /* (the game's YmElem_SetupDevice does not return with these stand-ins: the mod's test exports do what its hooks do) */
  HMODULE fm = GetModuleHandleA("effect_comfort.dll");
  void (*enter)(void *) = fm ? (void (*)(void *))(void *)GetProcAddress(fm, "effect_comfort_test_enter") : NULL;
  void (*leave)(void) = fm ? (void (*)(void))(void *)GetProcAddress(fm, "effect_comfort_test_leave") : NULL;
  check(enter && leave, "fx2mod: the mod's test exports");
  if (!enter || !leave) return 1;
  enter(elem);
  uint32_t in = fx2_draw(dev, rt);
  leave();
  uint32_t out = fx2_draw(dev, rt);
  snprintf(what, sizeof what, "fx2mod: inside the element (spel/fire at 0%%) the white draw is left out (%06lx); after RestoreDevice it is drawn (%06lx)", (unsigned long)in, (unsigned long)out);
  check(in == 0 && out == 0xFFFFFF, what);
  IDirect3DDevice8_SetRenderTarget(dev, old, oldz); if (old) IDirect3DSurface8_Release(old); if (oldz) IDirect3DSurface8_Release(oldz); if (rt) IDirect3DSurface8_Release(rt);
  *pp = op; *pr = orr;
  return 0;
}

int main(int argc, char **argv) {
  int reloadrun = argc > 1 && !strcmp(argv[1], "reload");
  int modrun = argc > 1 && (!strcmp(argv[1], "mod") || !strcmp(argv[1], "modrel") || reloadrun);
  int caprun = argc > 1 && !strcmp(argv[1], "capture");
  int factrun = argc > 1 && !strcmp(argv[1], "facts");
  int abrun = argc > 1 && !strcmp(argv[1], "ab");
  int texrun = argc > 1 && !strcmp(argv[1], "texmod"), fxrun = argc > 1 && !strcmp(argv[1], "fxmod");
  int camrun = argc > 1 && !strcmp(argv[1], "cammod"), ovlrun = argc > 1 && !strcmp(argv[1], "ovlmod");
  int audrun = argc > 1 && !strcmp(argv[1], "audmod"), envrun = argc > 1 && !strcmp(argv[1], "envmod");
  int phorun = argc > 1 && !strcmp(argv[1], "phomod"), cfrun = argc > 1 && !strcmp(argv[1], "cfmod");
  int uirun = argc > 1 && !strcmp(argv[1], "uimod"), fx2run = argc > 1 && !strcmp(argv[1], "fx2mod");
  int realrun = argc > 1 && (!strcmp(argv[1], "realdev") || texrun || fxrun || camrun || ovlrun || audrun || envrun || phorun || cfrun || uirun || fx2run);
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
    touch_ini(ini, texrun ? "[xikit]\nlog_folder=0\nswap=0\ncount_calls=1\nreport_every=60\nhotkey=0\nmods=texture_replace.dll\n"
                 : fx2run ? "[xikit]\nlog_folder=0\nswap=0\ncount_calls=1\nreport_every=60\nhotkey=0\nmods=effect_comfort.dll\n"
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
                  mf = fopen("effects.txt", "w"); if (mf) { fputs("# path-prefix percent\nspel/fire 0\n", mf); fclose(mf); } fill_iat(g); }
    if (uirun) { FILE *mf = fopen("xikit_mods.ini", "w"); if (mf) { fputs("[ui_layout]\nui_dx=100\nui_list=1\n", mf); fclose(mf); }
                 mf = fopen("ui_layout.txt", "w"); if (mf) { fputs("# window dx dy\nmenuinventor 5 -3\n", mf); fclose(mf); } fill_iat(g); }
    if (cfrun) { FILE *mf = fopen("xikit_mods.ini", "w"); if (mf) { fputs("[color_filter]\ncb_mode=2\ncb_simulate=1\ncb_strength=100\ncb_check=1\n", mf); fclose(mf); } }
    if (phorun) { FILE *mf = fopen("xikit_mods.ini", "w"); if (mf) { fputs("[photo_mode]\nphoto=1\nphoto_yaw=90\nphoto_dist=200\nphoto_shot=1\nphoto_hide_ui=1\n", mf); fclose(mf); } fill_iat(g); }
    if (envrun) { FILE *mf = fopen("xikit_mods.ini", "w"); if (mf) { fputs("[world_light]\nfog_distance=50\nfog_r=200\nambient=150\nlight=200\n", mf); fclose(mf); } fill_iat(g); }
    if (audrun) { FILE *mf = fopen("xikit_mods.ini", "w"); if (mf) { fputs("[audio_mix]\nvol_interface=50\nvol_effects=150\nvol_ambient=25\n", mf); fclose(mf); } fill_iat(g); }
    if (ovlrun) { FILE *mf = fopen("xikit_mods.ini", "w"); if (mf) { fputs("[file_overlay]\noverlay_log=1\n", mf); fclose(mf); } fill_iat(g); }
    if (camrun) { FILE *mf = fopen("xikit_mods.ini", "w"); if (mf) { fputs("[camera_view]\nfov_deg=90\nfar_percent=200\n", mf); fclose(mf); } fill_iat(g); }
    if (fxrun) { FILE *mf = fopen("xikit_mods.ini", "w"); if (mf) { fputs("[effect_comfort]\nflash_limit=50\nfx_intensity=50\nfx_all_blended=1\n", mf); fclose(mf); } fill_iat(g); }
    if (texrun) { FILE *mf = fopen("xikit_mods.ini", "w"); if (mf) { fputs("[texture_replace]\ntex_dump=1\ntex_log=1\n", mf); fclose(mf); } fill_iat(g); }
    if (!LoadLibraryA("xikit.dll")) { printf("FAIL: xikit.dll not loaded (%lu)\n", GetLastError()); return 2; }
    for (int t = 0; t < 400 && *(void **)dev == vt0; t++) Sleep(50);
    if (texrun || fxrun || camrun || ovlrun || audrun || envrun || phorun || cfrun || uirun || fx2run) {
      if (texrun) texmod_run(dev); else if (fxrun) fxmod_run(dev); else if (camrun) cammod_run(dev); else if (ovlrun) ovlmod_run(dev, g); else if (audrun) audmod_run(dev); else if (envrun) envmod_run(dev); else if (phorun) phomod_run(dev); else if (cfrun) cfmod_run(dev); else if (uirun) uimod_run(dev); else fx2mod_run(dev);
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
                 : abrun ? "[xikit]\nlog_folder=1\nswap=1\ninclude_untested=1\ncount_calls=1\nreport_every=60\nhotkey=0\nab=1\nab_after=0\nab_phase=1\nab_rounds=2\nab_settle=3\n"
                 : profile ? "[xikit]\nlog_folder=0\nswap=1\ninclude_untested=1\ncount_calls=1\nreport_every=60\nhotkey=0\nlog_each=1\nprofile=1\ncall_time=1\nkernel_calls=2\ntrace=1\ntrace_after=4\ntrace_count=1\nsample=1\ntrace_pictures=1\n"
                 : reloadrun ? "[xikit]\nlog_folder=0\nswap=1\ninclude_untested=1\ncount_calls=1\nreport_every=60\nhotkey=0\nlog_each=1\nmods=mod_test.dll\nmod_reload=1\n"
                 : modrun ? "[xikit]\nlog_folder=0\nswap=1\ninclude_untested=1\ncount_calls=1\nreport_every=60\nhotkey=0\nlog_each=1\nprofile=1\nmods=mod_test.dll\n"
                 : factrun ? "[xikit]\nlog_folder=0\nswap=0\ncount_calls=1\nreport_every=60\nhotkey=0\nlog_each=1\nfacts=1\n"
                 : blockrun ? "[xikit]\nlog_folder=0\nswap=1\ninclude_untested=1\ncount_calls=1\nreport_every=60\nhotkey=0\ntrace=1\ntrace_after=4\ntrace_count=1\ntrace_alternate=4\n"
                 : nativerun ? "[xikit]\nlog_folder=0\nswap=1\ninclude_untested=1\ncount_calls=1\nreport_every=60\nhotkey=0\nlog_each=1\nsample=2\nsample_ms=1\nsample_window=1\n"
                 : caprun ? "[xikit]\nlog_folder=0\nswap=0\ncount_calls=1\nreport_every=60\nhotkey=0\nlog_each=1\ncapture=CXiSkeletonActor::GetColor,CXiSkeletonActor::SetColor\ncapture_count=1\ncapture_pages=4096\n"
                         : "[xikit]\nlog_folder=0\nswap=1\ninclude_untested=1\ncount_calls=1\nreport_every=60\nhotkey=0\nlog_each=1\n");
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
    check(xs != NULL, "the reconstruction exports xi_shift and the kit filled it (its ranges: the xi_shift line)");
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
  if (!caprun && !factrun && !g_no_swap && !(set[0] == 0xE9 && gam[0] == 0xE9)) printf("note: entry bytes SetColor %02X, FontGlyphCache_GetDevice %02X\n", set[0], gam[0]);
  if (!caprun && !factrun && !g_no_swap) check(set[0] == 0xE9 && gam[0] == 0xE9, "swap=1: the entries now jump to the reconstruction");
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
    while (GetTickCount() - t < 2500) { for (int k = 0; k < 10000; k++) sink += ((GetColorFn)(uintptr_t)ga(GETCOLOR))(actor); present(1); }
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
    while (GetTickCount() - t < 2500) { for (int k = 0; k < 10000; k++) sink += ((GetColorFn)(uintptr_t)ga(GETCOLOR))(actor); present(1); }
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
      while (GetTickCount() - t < 500) for (int k = 0; k < 10000; k++) sink += ((GetColorFn)(uintptr_t)ga(GETCOLOR))(actor);
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
