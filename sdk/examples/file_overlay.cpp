// file_overlay.cpp -- an example mod: load files from overlay folders instead of the game's own, by their path.
// Models, textures, zones, sound effects, music: every file the game reads. Build:
//   sdk/build_mod.sh file_overlay.dll sdk/examples/file_overlay.cpp
//
// Where: the game's import of kernel32's CreateFileA (FFXiMain.dll's import table, found at run time by name, so no
// game address and every build). The game's files are opened through it:
// - the DAT files: XiFileImpl::_getFileName (0x101C3A90; named by the PS2 build's symbol, a confirmed match in
//   data/ps2_matches.json) turns a file number into "/ROM%d/%d/%d.DAT" (the ROM number a byte of the table at
//   +0xBC, the folder and file the word at +0xC4: word >> 7, word & 0x7F), TextInputFiles_FormatPathByKind
//   (0x101C3E90, tree source) puts the game's folder in front ("%s%s"), and the reads open that path;
// - the sound effects ("se%6.6u.spw" in \sound*\win\se\se%3.3u\, 0x10004A80) and the music ("\sound*\win\music\data",
//   music%03d.bgw): their own names, the same import.
// The C runtime's open (0x10315E96) and the other openers in the game call CreateFileA through the same import slot
// (`call [0x103291EC]` in the analysed build); this mod replaces the slot's pointer and calls the one it found there.
//
// The overlay: <kit folder>\overlay\<pack>\<the file's path below the FINAL FANTASY XI folder>, for example
// overlay\my_hd_pack\ROM\117\52.DAT or overlay\quiet_music\sound\win\music\data\music101.bgw. Packs are taken in
// name order and the last one that has the file wins (name them 10_..., 20_... to choose). Only opens for reading
// are redirected (no GENERIC_WRITE, OPEN_EXISTING), so the game's own saved files are never touched. The overlay is
// listed once at start and again when a setting changes; opening a file the overlay lacks costs a lookup in memory.
//
// Settings: overlay (1 on), overlay_log (1: log each redirected path).
//
// The game's folder is the folder of FFXiMain.dll (GetModuleFileName of the module at host->game_base). Paths the
// game passes in another spelling of that folder (8.3 short names, a different drive letter for the same place) are
// not matched; the log says how many opens were seen and how many redirected.
//
// Tested offline (kit/xikit/test, mode ovlmod): opens through the game's own import slot, with the game DLL mapped:
// an overlaid DAT, a file in two packs (the later pack's), a file no pack has (the game's), a write open (the game's).
// Not yet run in the game.
#include <windows.h>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "xikit_mod.h"
XIKIT_MOD_GLOBALS        // (no game address of its own; the exports let the kit use it on a build whose code moved)

static const XikitHost *g_host;
static std::string g_game_dir, g_overlay;               // lower case, '\\', no trailing '\\'
static std::map<std::string, std::string> g_files;      // relative path (lower case) -> full path of the winning pack's file
static SRWLOCK g_lock = SRWLOCK_INIT;
static volatile LONG g_opens, g_redirected;
typedef HANDLE (WINAPI *CreateFileA_t)(LPCSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE);
static CreateFileA_t g_prev;
static CreateFileA_t *g_slot;

static std::string norm(std::string s) {
  for (auto &c : s) { if (c == '/') c = '\\'; c = (char)tolower((unsigned char)c); }
  std::string o; for (char c : s) { if (c == '\\' && !o.empty() && o.back() == '\\' && o.size() > 1) continue; o += c; }   // (keeps a leading \\)
  while (o.size() > 3 && o.back() == '\\') o.pop_back();
  return o;
}
static void walk(const std::string &root, const std::string &rel, std::map<std::string, std::string> &out) {
  WIN32_FIND_DATAA fd; HANDLE h = FindFirstFileA((root + (rel.empty() ? "" : "\\" + rel) + "\\*").c_str(), &fd);
  if (h == INVALID_HANDLE_VALUE) return;
  do {
    std::string n = fd.cFileName; if (n == "." || n == "..") continue;
    std::string r = rel.empty() ? n : rel + "\\" + n;
    if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) walk(root, r, out);
    else out[norm(r)] = root + "\\" + r;                    // a later pack overwrites: it wins
  } while (FindNextFileA(h, &fd));
  FindClose(h);
}
static void rescan() {
  std::map<std::string, std::string> files; std::vector<std::string> packs;
  WIN32_FIND_DATAA fd; HANDLE h = FindFirstFileA((g_overlay + "\\*").c_str(), &fd);
  if (h != INVALID_HANDLE_VALUE) {
    do { std::string n = fd.cFileName; if (n != "." && n != ".." && (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) packs.push_back(n); } while (FindNextFileA(h, &fd));
    FindClose(h);
  }
  std::sort(packs.begin(), packs.end(), [](const std::string &a, const std::string &b) { return norm(a) < norm(b); });
  for (auto &p : packs) walk(g_overlay + "\\" + p, "", files);
  AcquireSRWLockExclusive(&g_lock); g_files.swap(files); ReleaseSRWLockExclusive(&g_lock);
  g_host->log("file_overlay: %u files in %u packs under %s", (unsigned)g_files.size(), (unsigned)packs.size(), g_overlay.c_str());
}

static HANDLE WINAPI my_CreateFileA(LPCSTR name, DWORD access, DWORD share, LPSECURITY_ATTRIBUTES sa, DWORD disp, DWORD flags, HANDLE tmpl) {
  if (name && !(access & (GENERIC_WRITE | FILE_WRITE_DATA | FILE_APPEND_DATA)) && disp == OPEN_EXISTING && g_host->setting_int("overlay", 1)) {
    InterlockedIncrement(&g_opens);
    std::string n = norm(name);
    if (n.size() > g_game_dir.size() + 1 && !n.compare(0, g_game_dir.size(), g_game_dir) && n[g_game_dir.size()] == '\\') {
      std::string rel = n.substr(g_game_dir.size() + 1), full;
      AcquireSRWLockShared(&g_lock); auto it = g_files.find(rel); if (it != g_files.end()) full = it->second; ReleaseSRWLockShared(&g_lock);
      if (!full.empty()) {
        HANDLE h = g_prev(full.c_str(), access, share, sa, disp, flags, tmpl);
        if (h != INVALID_HANDLE_VALUE) {
          InterlockedIncrement(&g_redirected);
          if (g_host->setting_int("overlay_log", 0)) g_host->log("file_overlay: %s -> %s", name, full.c_str());
          return h;
        }
      }
    }
  }
  return g_prev(name, access, share, sa, disp, flags, tmpl);
}

// the import slot of kernel32!CreateFileA in FFXiMain.dll's import table
static CreateFileA_t *find_slot(HMODULE m) {
  auto *dos = (IMAGE_DOS_HEADER *)m; auto *nt = (IMAGE_NT_HEADERS *)((char *)m + dos->e_lfanew);
  IMAGE_DATA_DIRECTORY dd = nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
  if (!dd.VirtualAddress) return nullptr;
  for (auto *d = (IMAGE_IMPORT_DESCRIPTOR *)((char *)m + dd.VirtualAddress); d->Name; d++) {
    if (lstrcmpiA((char *)m + d->Name, "kernel32.dll")) continue;
    auto *names = (IMAGE_THUNK_DATA *)((char *)m + (d->OriginalFirstThunk ? d->OriginalFirstThunk : d->FirstThunk));
    auto *iat = (IMAGE_THUNK_DATA *)((char *)m + d->FirstThunk);
    for (int i = 0; names[i].u1.AddressOfData; i++)
      if (!(names[i].u1.Ordinal & IMAGE_ORDINAL_FLAG) && !strcmp(((IMAGE_IMPORT_BY_NAME *)((char *)m + names[i].u1.AddressOfData))->Name, "CreateFileA"))
        return (CreateFileA_t *)&iat[i].u1.Function;
  }
  return nullptr;
}

extern "C" __declspec(dllexport) void xikit_mod_settings(void) { rescan(); }
extern "C" __declspec(dllexport) void xikit_mod_frame(void *) {
  static unsigned n; static LONG last;
  if (++n % 1800 == 0 && g_opens != last) { last = g_opens; g_host->log("file_overlay: %ld opens of the game's files seen, %ld from the overlay", (long)g_opens, (long)g_redirected); }
}
extern "C" __declspec(dllexport) void xikit_mod_unload(void) {
  if (g_slot && *g_slot == my_CreateFileA) { DWORD o; VirtualProtect(g_slot, 4, PAGE_READWRITE, &o); *g_slot = g_prev; VirtualProtect(g_slot, 4, o, &o); }
}
extern "C" __declspec(dllexport) int xikit_mod_init(const XikitHost *host) {
  g_host = host;
  host->declare_int("overlay", 1, 0, 1, "1: open the game's files from overlay\\<pack>\\ when a pack has them");
  host->declare_int("overlay_log", 0, 0, 1, "1: log each file opened from the overlay");
  HMODULE game = (HMODULE)host->game_base; char p[MAX_PATH];
  if (!game || !GetModuleFileNameA(game, p, sizeof p)) { host->log("file_overlay: the game's module has no file name; nothing done"); return 0; }
  g_game_dir = norm(p); g_game_dir = g_game_dir.substr(0, g_game_dir.rfind('\\'));
  g_overlay = std::string(host->dir ? host->dir : ".") + "\\overlay";
  g_slot = find_slot(game);
  if (!g_slot) { host->log("file_overlay: no CreateFileA import in the game's module; nothing done"); return 0; }
  rescan();
  DWORD o; VirtualProtect(g_slot, 4, PAGE_READWRITE, &o);
  g_prev = *g_slot; *g_slot = my_CreateFileA;
  VirtualProtect(g_slot, 4, o, &o);
  host->log("file_overlay: the game's folder is %s; its CreateFileA import goes through the overlay", g_game_dir.c_str());
  return 0;
}
