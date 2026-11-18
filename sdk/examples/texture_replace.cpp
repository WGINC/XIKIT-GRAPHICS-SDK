// texture_replace.cpp -- an example mod: replace the game's textures with DDS files, and dump the game's textures to
// find their names. Build:
//   sdk/build_mod.sh texture_replace.dll sdk/examples/texture_replace.cpp sdk/examples/texture_replace_core.cpp
// This file is the hook; texture_replace_core.cpp (Windows and Direct3D 8 headers, no tree headers: the tree defines
// the C runtime's types itself) does the files and the textures.
//
// Where: TexObj_Upload (0x10039E50, in the manifest). Every texture of the game's Bm2 chunks (types 0x20 and 0x1B,
// docs/FORMATS.md section 5) is filled there: TexObj_Create (0x10039A80) creates the Direct3D texture at texobj +0x40
// (2D) or +0x44 (cube) and calls it, and TexObj_Reupload calls it again. The kit's hooks patch the function's entry,
// so the game's own calls reach this mod.
//
// What the mod reads of the texture object (FORMATS.md 5.3, from the game's code): +0x0C the 16-byte name,
// +0x1C/+0x20 the palette and pixels (or, for a DXT block, +0x20 = the block: its pitch at +4, the data at +8),
// +0x24/+0x26 width and height, +0x28 bits per pixel, +0x29 the format byte (16/24/32, or 0x80 | the DXT index:
// 0 DXT1, 2 DXT3), +0x2C bits 0-2 the cube-face bits (nonzero: a cube texture, left alone), +0x40 the 2D texture.
//
// A texture's key is its name (letters and digits kept, everything else '_') and the CRC-32 of the source bytes the
// game uploads (palette, then pixels), computed before the game's code runs, as "<name>_<crc>". Names are not unique
// (the same name in two zones can be two pictures); the CRC tells them apart.
//
// Replacing: put DDS files in <kit folder>\textures\. For each upload the mod looks for "<name>_<crc>.dds", then
// "<name>.dds" (every texture of that name). The folder is listed once at start and again when a setting changes, so
// an upload costs no disk access unless a file matches. Accepted DDS formats: DXT1, DXT3, DXT5, A8R8G8B8, X8R8G8B8,
// A1R5G5B5; any size (the game's texture coordinates are 0..1, so a larger picture is a sharper one). The file's mip
// levels are used; a 32-bit file without them gets a box-filtered chain, other formats get level 0 only. The game's
// texture is released and the replacement put at +0x40; the object's width and height (+0x24, +0x26) are kept.
//
// Dumping (tex_dump=1): each texture's level 0 after the game's upload is written once to <kit folder>\textures_dump
// as "<name>_<crc>.dds", in the format the game created it (A8R8G8B8, A1R5G5B5, DXT1 or DXT3). Edit one and put it in
// textures\ under the same name to replace it. The dumps are the game's own pictures: keep them on your machine.
//
// Not known: whether code outside TexObj_Upload reads the texture's surface size and expects the game's (the draw
// code binds +0x40, FORMATS.md 5.3; nothing else was found reading it). Not yet run in the game: tested offline with
// the game's own TexObj_Create and TexObj_Upload on a real Direct3D 8 device (kit/xikit/test, mode texmod).
#include "xikit_sdk.hpp"
#include "texture_replace_core.h"
XIKIT_MOD_GLOBALS

static const XikitHost *g_host;
static void log_line(const char *s) { g_host->log("%s", s); }

static xikit::fn<decltype(&TexObj_Upload)> prev_Upload;
static int __thiscall my_Upload(void *t) {
  int on = g_host->setting_int("tex_replace", 1), dmp = g_host->setting_int("tex_dump", 0);
  TrKey k; int keyed = (on || dmp) && t && tr_key(t, &k);    // before the game's code: the source bytes it uploads
  int r = prev_Upload(t);                                     // the game's own upload, unchanged
  if (keyed && r) tr_after_upload(t, &k, dmp, on, g_host->setting_int("tex_log", 0));
  return r;
}

extern "C" __declspec(dllexport) void xikit_mod_settings(void) { tr_rescan(); }
extern "C" __declspec(dllexport) void xikit_mod_frame(void *) {
  static unsigned n; char s[256];
  if (++n % 1800 == 0 && tr_stats(s, sizeof s)) g_host->log("%s", s);
}
extern "C" __declspec(dllexport) int xikit_mod_init(const XikitHost *host) {
  g_host = host;
  host->declare_int("tex_replace", 1, 0, 1, "1: replace textures with DDS files from textures\\ (<name>_<crc>.dds, else <name>.dds)");
  host->declare_int("tex_dump", 0, 0, 1, "1: write each texture the game uploads to textures_dump\\ once, as <name>_<crc>.dds");
  host->declare_int("tex_log", 0, 0, 1, "1: log every replacement");
  tr_init(host->dir ? host->dir : ".", log_line);
  return XI_HOOK(host, TexObj_Upload, my_Upload, prev_Upload);
}
