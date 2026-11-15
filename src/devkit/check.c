/* check.c -- devkit_check.exe, the devkit release's first-run check (kit/devkit/README.md):

     devkit_check.exe [GAME_FOLDER]

   1. every file SHA256SUMS.txt (next to it) lists is there and has that SHA-256 (bcrypt's SHA-256, Windows' own);
   2. FFXiMain.dll in GAME_FOLDER (default: the usual FINAL FANTASY XI folder) is read: its TimeDateStamp names the
      game's build (the shipped file is packed, but its PE header is plain), and the kit's manifest for that build is
      looked for (kit\xikit_manifest_<stamp>.txt; the analysed build 6A995428 uses kit\xikit_manifest.txt);
   3. the PlayOnlineViewer folder's d3d8.dll: d3d8on11 (it exports D8ON11_Pass) or another.
   Exit 0 when 1 passes and the game's build has a manifest; it prints what it found either way. */
#include <windows.h>
#include <bcrypt.h>
#include <stdio.h>
#include <string.h>

static int sha256_file(const char *path, char hex[65]) {
  BCRYPT_ALG_HANDLE a = NULL; BCRYPT_HASH_HANDLE h = NULL; UCHAR d[32]; int ok = 0;
  FILE *f = fopen(path, "rb"); if (!f) return 0;
  if (BCryptOpenAlgorithmProvider(&a, BCRYPT_SHA256_ALGORITHM, NULL, 0) == 0 && BCryptCreateHash(a, &h, NULL, 0, NULL, 0, 0) == 0) {
    static UCHAR buf[1 << 16]; size_t n;
    ok = 1;
    while ((n = fread(buf, 1, sizeof buf, f)) > 0) if (BCryptHashData(h, buf, (ULONG)n, 0) != 0) { ok = 0; break; }
    if (ok && BCryptFinishHash(h, d, sizeof d, 0) == 0) for (int i = 0; i < 32; i++) sprintf(hex + 2 * i, "%02x", d[i]); else ok = 0;
  }
  if (h) BCryptDestroyHash(h);
  if (a) BCryptCloseAlgorithmProvider(a, 0);
  fclose(f); return ok;
}
static DWORD pe_stamp(const char *path) {
  FILE *f = fopen(path, "rb"); if (!f) return 0;
  IMAGE_DOS_HEADER dh; IMAGE_NT_HEADERS32 nh; DWORD ts = 0;
  if (fread(&dh, sizeof dh, 1, f) == 1 && dh.e_magic == IMAGE_DOS_SIGNATURE && fseek(f, dh.e_lfanew, SEEK_SET) == 0 &&
      fread(&nh, sizeof nh, 1, f) == 1 && nh.Signature == IMAGE_NT_SIGNATURE) ts = nh.FileHeader.TimeDateStamp;
  fclose(f); return ts;
}
int main(int argc, char **argv) {
  char here[MAX_PATH]; GetModuleFileNameA(NULL, here, sizeof here); char *sl = strrchr(here, '\\'); if (sl) *sl = 0;
  char p[MAX_PATH * 2], line[1024]; int files = 0, bad = 0;
  snprintf(p, sizeof p, "%s\\SHA256SUMS.txt", here);
  FILE *s = fopen(p, "r");
  if (!s) { printf("FAIL: no SHA256SUMS.txt next to devkit_check.exe\n"); return 1; }
  while (fgets(line, sizeof line, s)) {
    char want[65], name[MAX_PATH], got[65];
    if (sscanf(line, "%64s %259[^\r\n]", want, name) != 2) continue;
    char *nm = name; if (*nm == '*' || *nm == ' ') nm++;
    for (char *c = nm; *c; c++) if (*c == '/') *c = '\\';
    snprintf(p, sizeof p, "%s\\%s", here, nm); files++;
    if (!sha256_file(p, got)) { printf("FAIL: %s is missing or cannot be read\n", nm); bad++; }
    else if (_stricmp(got, want)) { printf("FAIL: %s differs from the release (its SHA-256 is %s)\n", nm, got); bad++; }
  }
  fclose(s);
  printf("%s: %d files checked, %d missing or different\n", bad ? "FAIL" : "ok", files, bad);
  const char *game = argc > 1 ? argv[1] : "C:\\Program Files (x86)\\PlayOnline\\SquareEnix\\FINAL FANTASY XI";
  snprintf(p, sizeof p, "%s\\FFXiMain.dll", game);
  DWORD ts = pe_stamp(p); int manifest = 0;
  if (!ts) printf("note: no FFXiMain.dll in \"%s\" (give the FINAL FANTASY XI folder as the argument)\n", game);
  else {
    if (ts == 0x6A995428u) snprintf(p, sizeof p, "%s\\kit\\xikit_manifest.txt", here);
    else snprintf(p, sizeof p, "%s\\kit\\xikit_manifest_%08lX.txt", here, (unsigned long)ts);
    manifest = GetFileAttributesA(p) != INVALID_FILE_ATTRIBUTES;
    printf("%s: the game's FFXiMain.dll is build %08lX; %s\n", manifest ? "ok" : "FAIL", (unsigned long)ts,
           manifest ? "the kit has a manifest for it" : "the kit has no manifest for it (a newer patch: the kit will not load; docs/KIT.md, build translation)");
  }
  char pov[MAX_PATH * 2]; snprintf(pov, sizeof pov, "%s\\..\\..\\PlayOnlineViewer\\d3d8.dll", game);
  HMODULE m = LoadLibraryExA(pov, NULL, DONT_RESOLVE_DLL_REFERENCES);
  if (!m) printf("note: no d3d8.dll in the PlayOnlineViewer folder (the game uses Windows' own Direct3D 8: shader passes are not there)\n");
  else { printf("note: the PlayOnlineViewer folder's d3d8.dll is %s\n", GetProcAddress(m, "D8ON11_Pass") ? "d3d8on11 (shader passes: yes)" : "another (dgVoodoo's or Microsoft's: no shader passes)"); FreeLibrary(m); }
  return bad || !manifest ? 1 : 0;
}
