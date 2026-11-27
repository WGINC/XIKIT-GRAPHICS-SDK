/* mod_host.c -- a test host for mod authors (DEVKIT_COMPLETE.md gap 6; ISSUES 2.3): runs the kit and one mod against
   the player's own FFXiMain.dll and a real Direct3D 8 device, outside the game, on Windows or under Wine.

     mod_host.exe MOD.dll [FRAMES]

   In its folder: FFXiMain.dll (a copy of your game's; it is mapped, never run), xikit.dll and the kit's files
   (xikit_manifest*.txt), and MOD.dll. It:
     1. maps FFXiMain.dll without running it (LoadLibraryEx, DONT_RESOLVE_DLL_REFERENCES), applies its base relocations
        when Windows put it away from 0x10000000, and fills its import table, as the game's loader would;
     2. makes a window and a Direct3D 8 device (whichever d3d8.dll loads: Windows', Wine's, or d3d8on11 beside it) and
        puts it where the game's CDx object keeps it ([g_pCDx] + 0xC; g_pCDx is 0x1045666C in build 6A995428 and
        0x1045781C in 6AE818B4, the two builds the kit knows; the build is told by the file's TimeDateStamp);
     3. writes xikit.ini with mods=MOD.dll and swap=0 (the game's own code; no reconstruction), loads xikit.dll and
        waits for the kit to hook the device;
     4. presents FRAMES frames (default 120), so the mod's xikit_mod_frame runs;
     5. calls the mod's export `int xikit_mod_selftest(void *device)` when it has one (0: passed), and prints the
        kit's log (xikit.log).
   The game's code does not run (there is no game): a mod's hooks are installed but its hooked functions are called
   only when a mod's self test calls them. What this checks is that the mod loads, declares its settings, hooks what
   it asks for, draws without faulting, and passes its own checks.
   Exit code: 0 all passed, 1 a check failed, 2 the host could not set up. */
#include <windows.h>
#include <d3d8.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

static int fails;
static void check(int ok, const char *what) { printf("%s: %s\n", ok ? "ok" : "FAIL", what); if (!ok) fails++; }

static void apply_relocs(HMODULE g, uint32_t delta) {
  IMAGE_NT_HEADERS *nt = (IMAGE_NT_HEADERS *)((char *)g + ((IMAGE_DOS_HEADER *)g)->e_lfanew);
  IMAGE_SECTION_HEADER *sh = IMAGE_FIRST_SECTION(nt), *rs = NULL;
  for (int k = 0; k < nt->FileHeader.NumberOfSections; k++) if (!memcmp(sh[k].Name, ".reloc", 7)) rs = &sh[k];
  if (!rs) { printf("note: no .reloc section\n"); return; }
  DWORD old; VirtualProtect(g, nt->OptionalHeader.SizeOfImage, PAGE_EXECUTE_READWRITE, &old);
  uint8_t *p = (uint8_t *)g + rs->VirtualAddress, *end = p + rs->Misc.VirtualSize; int n = 0;
  while (p + 8 <= end) {                 /* (the whole .reloc section: the unpacked file's directory covers only part) */
    IMAGE_BASE_RELOCATION *b = (IMAGE_BASE_RELOCATION *)p;
    if (b->SizeOfBlock < 8 || b->SizeOfBlock % 2 || p + b->SizeOfBlock > end) break;
    WORD *e = (WORD *)(b + 1);
    for (DWORD k = 0; k < (b->SizeOfBlock - sizeof *b) / 2; k++)
      if ((e[k] >> 12) == IMAGE_REL_BASED_HIGHLOW) { *(uint32_t *)((uint8_t *)g + b->VirtualAddress + (e[k] & 0xFFF)) += delta; n++; }
    p += b->SizeOfBlock;
  }
  printf("note: applied %d base relocations\n", n);
}
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

int main(int argc, char **argv) {
  setvbuf(stdout, NULL, _IONBF, 0);
  if (argc < 2) { printf("usage: mod_host.exe MOD.dll [FRAMES]\n"); return 2; }
  const char *mod = argv[1]; int frames = argc > 2 ? atoi(argv[2]) : 120;
  HMODULE g = LoadLibraryExA("FFXiMain.dll", NULL, DONT_RESOLVE_DLL_REFERENCES);
  if (!g) { printf("FAIL: FFXiMain.dll not mapped (%lu): put a copy of your game's beside this program\n", GetLastError()); return 2; }
  IMAGE_NT_HEADERS *nt = (IMAGE_NT_HEADERS *)((char *)g + ((IMAGE_DOS_HEADER *)g)->e_lfanew);
  uint32_t stamp = nt->FileHeader.TimeDateStamp, delta = (uint32_t)(uintptr_t)g - 0x10000000u;
  uint32_t pcdx = stamp == 0x6A995428u ? 0x1045666Cu : stamp == 0x6AE818B4u ? 0x1045781Cu : 0;
  printf("FFXiMain.dll build %08X at %p\n", stamp, (void *)g);
  if (!pcdx) { printf("FAIL: build %08X is not one this host knows (6A995428, 6AE818B4)\n", stamp); return 2; }
  if (delta) apply_relocs(g, delta);
  fill_iat(g);
  WNDCLASSA wc; memset(&wc, 0, sizeof wc); wc.lpfnWndProc = DefWindowProcA; wc.hInstance = GetModuleHandleA(NULL); wc.lpszClassName = "mod_host"; RegisterClassA(&wc);
  HWND w = CreateWindowA("mod_host", "mod_host", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0, 640, 480, NULL, NULL, wc.hInstance, NULL);
  typedef IDirect3D8 *(WINAPI *Create8)(UINT);
  HMODULE d8 = LoadLibraryA("d3d8.dll"); Create8 c8 = d8 ? (Create8)(void *)GetProcAddress(d8, "Direct3DCreate8") : NULL;
  IDirect3D8 *d3d = c8 ? c8(D3D_SDK_VERSION) : NULL;
  if (!d3d) { printf("FAIL: Direct3DCreate8\n"); return 2; }
  D3DPRESENT_PARAMETERS pp; memset(&pp, 0, sizeof pp);
  pp.BackBufferWidth = 640; pp.BackBufferHeight = 480; pp.BackBufferFormat = D3DFMT_X8R8G8B8; pp.BackBufferCount = 1;
  pp.SwapEffect = D3DSWAPEFFECT_DISCARD; pp.hDeviceWindow = w; pp.Windowed = TRUE;
  pp.EnableAutoDepthStencil = TRUE; pp.AutoDepthStencilFormat = D3DFMT_D24S8;
  IDirect3DDevice8 *dev = NULL;
  HRESULT hr = IDirect3D8_CreateDevice(d3d, D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, w, D3DCREATE_HARDWARE_VERTEXPROCESSING, &pp, &dev);
  if (FAILED(hr) || !dev) { printf("FAIL: CreateDevice 0x%08lX\n", (unsigned long)hr); return 2; }
  /* the game's CDx object, as far as the kit reads it to find the device: [g_pCDx] + 0xC */
  static uint8_t cdx[0x1000]; *(void **)(cdx + 0xC) = dev;
  { DWORD old; void *slot = (void *)(uintptr_t)(pcdx + delta); VirtualProtect(slot, 4, PAGE_READWRITE, &old); *(void **)slot = cdx; }
  const char *base = strrchr(mod, '\\'); base = base ? base + 1 : mod;
  FILE *f = fopen("xikit.ini", "w");
  if (!f) { printf("FAIL: xikit.ini not written\n"); return 2; }
  fprintf(f, "[xikit]\nlog_folder=0\nswap=0\ncount_calls=0\nreport_every=60\nhotkey=0\nmods=%s\n", base); fclose(f);
  void *vt0 = *(void **)dev;
  if (!LoadLibraryA("xikit.dll")) { printf("FAIL: xikit.dll not loaded (%lu)\n", GetLastError()); return 2; }
  for (int t = 0; t < 400 && *(void **)dev == vt0; t++) Sleep(50);
  check(*(void **)dev != vt0, "the kit hooked the device");
  int okp = 1;
  for (int i = 0; i < frames; i++) {
    MSG m; while (PeekMessageA(&m, NULL, 0, 0, PM_REMOVE)) { TranslateMessage(&m); DispatchMessageA(&m); }
    IDirect3DDevice8_Clear(dev, 0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0xFF203040u, 1.0f, 0);
    okp &= SUCCEEDED(IDirect3DDevice8_Present(dev, NULL, NULL, NULL, NULL));
  }
  char what[128]; snprintf(what, sizeof what, "%d frames presented (the mod's xikit_mod_frame ran in each)", frames); check(okp, what);
  HMODULE mh = GetModuleHandleA(base);
  check(mh != NULL, "the kit loaded the mod");
  typedef int (__cdecl *SelfTest)(void *);
  SelfTest st = mh ? (SelfTest)(void *)GetProcAddress(mh, "xikit_mod_selftest") : NULL;
  if (st) { int r = st(dev); snprintf(what, sizeof what, "the mod's own xikit_mod_selftest returned %d (0: passed)", r); check(r == 0, what); }
  else printf("note: the mod has no xikit_mod_selftest export (its own checks are optional)\n");
  FILE *lg = fopen("xikit.log", "r"); char line[1024]; int refused = 0;
  printf("---- xikit.log\n");
  if (lg) { while (fgets(line, sizeof line, lg)) { fputs(line, stdout); if (strstr(line, "refused") || strstr(line, "not hooked")) refused++; } fclose(lg); }
  check(lg != NULL, "the kit wrote xikit.log");
  if (refused) printf("note: %d log lines say a hook was refused or not made (read them above)\n", refused);
  IDirect3DDevice8_Release(dev); IDirect3D8_Release(d3d);
  printf("%s\n", fails ? "FAILED" : "ALL OK");
  ExitProcess(fails ? 1 : 0);
  return 0;
}
