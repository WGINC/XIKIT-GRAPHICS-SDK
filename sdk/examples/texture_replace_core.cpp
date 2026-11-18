// texture_replace_core.cpp -- the files, the DDS reading and writing and the Direct3D 8 textures of texture_replace
// (texture_replace.cpp has the hook and says what the texture object's fields are, from docs/FORMATS.md 5.3).
// Windows and the MinGW-w64 Direct3D 8 headers only: no tree headers.
#include <windows.h>
#include <d3d8.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <set>
#include <map>
#include <vector>
#include "texture_replace_core.h"

static std::string g_dir;
static void (*g_log)(const char *);
static std::set<std::string> g_files, g_dumped;
static std::map<std::string, std::vector<unsigned char>> g_cache;
static long g_seen, g_replaced, g_dumpedn, g_failed, g_last;

static void logf(const char *fmt, ...) {
  char b[512]; va_list a; va_start(a, fmt); vsnprintf(b, sizeof b, fmt, a); va_end(a); if (g_log) g_log(b);
}
static unsigned crc32_update(unsigned c, const unsigned char *p, size_t n) {
  static unsigned t[256]; static bool init;
  if (!init) { for (unsigned i = 0; i < 256; i++) { unsigned k = i; for (int j = 0; j < 8; j++) k = k & 1 ? 0xEDB88320u ^ (k >> 1) : k >> 1; t[i] = k; } init = true; }
  c = ~c; while (n--) c = t[(c ^ *p++) & 0xFF] ^ (c >> 8); return ~c;
}
static bool readable(const void *p, size_t n) {           // the source bytes are the game's chunk data: checked, not assumed
  MEMORY_BASIC_INFORMATION mi; const char *a = (const char *)p, *e = a + n;
  while (a < e) {
    if (!VirtualQuery(a, &mi, sizeof mi) || mi.State != MEM_COMMIT || (mi.Protect & (PAGE_NOACCESS | PAGE_GUARD))) return false;
    a = (const char *)mi.BaseAddress + mi.RegionSize;
  }
  return true;
}
template <class T> static T at(void *o, int off) { return *reinterpret_cast<T *>(reinterpret_cast<char *>(o) + off); }
static std::string lower(std::string s) { for (auto &c : s) c = (char)tolower((unsigned char)c); return s; }

extern "C" int tr_key(void *t, TrKey *out) {
  char raw[17]; memcpy(raw, reinterpret_cast<char *>(t) + 0x0C, 16); raw[16] = 0;
  std::string name; for (int i = 0; i < 16 && raw[i]; i++) { char c = raw[i]; name += isalnum((unsigned char)c) ? c : '_'; }
  while (!name.empty() && name.back() == '_') name.pop_back();
  if (name.empty()) name = "unnamed";
  unsigned w = at<unsigned short>(t, 0x24), h = at<unsigned short>(t, 0x26), bpp = at<unsigned char>(t, 0x28), fmt = at<unsigned char>(t, 0x29);
  const unsigned char *pal = at<const unsigned char *>(t, 0x1C), *pix = at<const unsigned char *>(t, 0x20);
  if (!w || !h || w > 4096 || h > 4096 || !pix) return 0;
  unsigned crc = 0;
  if (fmt & 0x80) {                                      // a DXT block: +0x20 is the block, its data at +8 (FORMATS.md 5.2)
    unsigned idx = fmt & 0x7F, bb = idx == 0 ? 8 : idx == 2 ? 16 : 0;
    if (!bb) return 0;
    size_t n = (size_t)((w + 3) / 4) * ((h + 3) / 4) * bb;
    if (!readable(pix + 8, n)) return 0;
    crc = crc32_update(0, pix + 8, n);
  } else {                                               // palette and pixels (FORMATS.md 5.1)
    size_t pn = 0, xn;
    if (bpp == 4) pn = 16 * (fmt / 8), xn = ((size_t)w * h + 1) / 2;
    else if (bpp == 8) pn = 256 * (fmt / 8), xn = (size_t)w * h;
    else if (bpp == 16 || bpp == 24 || bpp == 32) xn = (size_t)w * h * (bpp / 8);
    else return 0;
    if (pn) { if (!pal || !readable(pal, pn)) return 0; crc = crc32_update(crc, pal, pn); }
    if (!readable(pix, xn)) return 0;
    crc = crc32_update(crc, pix, xn);
  }
  snprintf(out->name, sizeof out->name, "%s", name.c_str());
  snprintf(out->key, sizeof out->key, "%s_%08X", name.c_str(), crc);
  return 1;
}

extern "C" void tr_rescan(void) {
  g_files.clear(); g_cache.clear();
  WIN32_FIND_DATAA fd; HANDLE h = FindFirstFileA((g_dir + "\\textures\\*.dds").c_str(), &fd);
  if (h == INVALID_HANDLE_VALUE) return;
  do g_files.insert(lower(fd.cFileName)); while (FindNextFileA(h, &fd));
  FindClose(h);
}
extern "C" void tr_init(const char *dir, void (*log)(const char *)) {
  g_dir = dir; g_log = log; tr_rescan();
  logf("texture_replace: %u DDS files in textures\\", (unsigned)g_files.size());
}
static bool read_file(const std::string &p, std::vector<unsigned char> &out) {
  FILE *f = fopen(p.c_str(), "rb"); if (!f) return false;
  fseek(f, 0, SEEK_END); long n = ftell(f); fseek(f, 0, SEEK_SET);
  out.resize(n > 0 ? (size_t)n : 0); bool ok = n > 0 && fread(out.data(), 1, (size_t)n, f) == (size_t)n; fclose(f); return ok;
}

// DDS, the DirectX SDK's dds.h layout: "DDS ", a 124-byte header (flags +8, height +12, width +16, mip count +28), the
// pixel format at +76 (flags +80, FourCC +84, bit count +88, masks +92..+104), caps +108
enum : unsigned { PF_ALPHAPIXELS = 1, PF_FOURCC = 4, PF_RGB = 0x40, SD_MIPMAPCOUNT = 0x20000 };
struct DdsInfo { unsigned w, h, levels; D3DFORMAT fmt; size_t data; };
static bool block_fmt(D3DFORMAT f) { return f == D3DFMT_DXT1 || f == D3DFMT_DXT3 || f == D3DFMT_DXT5; }
static size_t level_bytes(D3DFORMAT f, unsigned w, unsigned h) {
  if (block_fmt(f)) return (size_t)((w + 3) / 4) * ((h + 3) / 4) * (f == D3DFMT_DXT1 ? 8 : 16);
  return (size_t)w * h * (f == D3DFMT_A1R5G5B5 ? 2 : 4);
}
static size_t row_bytes(D3DFORMAT f, unsigned w) { return block_fmt(f) ? level_bytes(f, w, 4) : level_bytes(f, w, 1); }
static unsigned row_count(D3DFORMAT f, unsigned h) { return block_fmt(f) ? (h + 3) / 4 : h; }
static bool parse_dds(const std::vector<unsigned char> &b, DdsInfo *o) {
  if (b.size() < 128 || memcmp(b.data(), "DDS ", 4)) return false;
  auto u = [&](size_t off) { unsigned v; memcpy(&v, &b[off], 4); return v; };
  if (u(4) != 124) return false;
  o->h = u(12); o->w = u(16); o->levels = (u(8) & SD_MIPMAPCOUNT) && u(28) ? u(28) : 1; o->data = 128;
  unsigned pf = u(80), cc = u(84), bits = u(88), rm = u(92), gm = u(96), bm = u(100), am = u(104);
  if (pf & PF_FOURCC) {
    if (cc == MAKEFOURCC('D', 'X', 'T', '1')) o->fmt = D3DFMT_DXT1; else if (cc == MAKEFOURCC('D', 'X', 'T', '3')) o->fmt = D3DFMT_DXT3;
    else if (cc == MAKEFOURCC('D', 'X', 'T', '5')) o->fmt = D3DFMT_DXT5; else return false;
  } else if ((pf & PF_RGB) && bits == 32 && rm == 0xFF0000 && gm == 0xFF00 && bm == 0xFF)
    o->fmt = (pf & PF_ALPHAPIXELS) && am == 0xFF000000u ? D3DFMT_A8R8G8B8 : D3DFMT_X8R8G8B8;
  else if ((pf & PF_RGB) && bits == 16 && rm == 0x7C00 && gm == 0x3E0 && bm == 0x1F) o->fmt = D3DFMT_A1R5G5B5;
  else return false;
  if (!o->w || !o->h || o->w > 8192 || o->h > 8192) return false;
  size_t need = o->data; unsigned w = o->w, h = o->h, n = 0;
  for (; n < o->levels && need + level_bytes(o->fmt, w, h) <= b.size(); n++) { need += level_bytes(o->fmt, w, h); w = w > 1 ? w / 2 : 1; h = h > 1 ? h / 2 : 1; }
  o->levels = n;                                          // the levels the file really holds
  return n > 0;
}
static unsigned full_chain(unsigned w, unsigned h) { unsigned n = 1; while (w > 1 || h > 1) { w = w > 1 ? w / 2 : 1; h = h > 1 ? h / 2 : 1; n++; } return n; }

static IDirect3DTexture8 *make_texture(IDirect3DDevice8 *dev, const std::vector<unsigned char> &b, const DdsInfo &d) {
  bool gen = d.levels == 1 && (d.fmt == D3DFMT_A8R8G8B8 || d.fmt == D3DFMT_X8R8G8B8);
  unsigned levels = gen ? full_chain(d.w, d.h) : d.levels;
  IDirect3DTexture8 *t = nullptr;
  if (FAILED(dev->CreateTexture(d.w, d.h, levels, 0, d.fmt, D3DPOOL_MANAGED, &t)) || !t) return nullptr;
  std::vector<unsigned> prev, cur; unsigned pw = 0, ph = 0;   // the generated chain's previous level (32-bit only)
  const unsigned char *src = b.data() + d.data; unsigned w = d.w, h = d.h;
  for (unsigned lv = 0; lv < levels; lv++) {
    D3DLOCKED_RECT lr = {};
    if (FAILED(t->LockRect(lv, &lr, nullptr, 0))) { t->Release(); return nullptr; }
    if (!gen || lv == 0) {
      for (unsigned y = 0; y < row_count(d.fmt, h); y++) memcpy((char *)lr.pBits + (size_t)y * lr.Pitch, src + y * row_bytes(d.fmt, w), row_bytes(d.fmt, w));
      if (gen) { prev.assign((const unsigned *)src, (const unsigned *)src + (size_t)w * h); pw = w; ph = h; }
      src += level_bytes(d.fmt, w, h);
    } else {                                              // a 2x2 box filter of the previous level, per channel
      cur.resize((size_t)w * h);
      for (unsigned y = 0; y < h; y++) for (unsigned x = 0; x < w; x++) {
        unsigned x0 = x * 2 < pw ? x * 2 : pw - 1, x1 = x0 + 1 < pw ? x0 + 1 : x0, y0 = y * 2 < ph ? y * 2 : ph - 1, y1 = y0 + 1 < ph ? y0 + 1 : y0;
        unsigned q[4] = { prev[(size_t)y0 * pw + x0], prev[(size_t)y0 * pw + x1], prev[(size_t)y1 * pw + x0], prev[(size_t)y1 * pw + x1] }, o = 0;
        for (int s = 0; s < 32; s += 8) { unsigned a = 0; for (int k = 0; k < 4; k++) a += (q[k] >> s) & 0xFF; o |= ((a + 2) / 4) << s; }
        cur[(size_t)y * w + x] = o;
      }
      for (unsigned y = 0; y < h; y++) memcpy((char *)lr.pBits + (size_t)y * lr.Pitch, &cur[(size_t)y * w], (size_t)w * 4);
      prev.swap(cur); pw = w; ph = h;
    }
    t->UnlockRect(lv);
    w = w > 1 ? w / 2 : 1; h = h > 1 ? h / 2 : 1;
  }
  return t;
}

static void dump(IDirect3DTexture8 *t, const std::string &key) {
  D3DSURFACE_DESC sd = {}; if (FAILED(t->GetLevelDesc(0, &sd))) return;
  D3DFORMAT f = sd.Format;
  if (!(f == D3DFMT_A8R8G8B8 || f == D3DFMT_A1R5G5B5 || f == D3DFMT_DXT1 || f == D3DFMT_DXT3)) return;
  D3DLOCKED_RECT lr = {}; if (FAILED(t->LockRect(0, &lr, nullptr, D3DLOCK_READONLY))) return;
  CreateDirectoryA((g_dir + "\\textures_dump").c_str(), nullptr);
  FILE *o = fopen((g_dir + "\\textures_dump\\" + key + ".dds").c_str(), "wb");
  if (o) {
    unsigned hd[32] = {}; memcpy(hd, "DDS ", 4);
    hd[1] = 124; hd[2] = 0x1007 | (block_fmt(f) ? 0x80000 : 0x8);          // CAPS|HEIGHT|WIDTH|PIXELFORMAT, LINEARSIZE or PITCH
    hd[3] = sd.Height; hd[4] = sd.Width; hd[5] = (unsigned)(block_fmt(f) ? level_bytes(f, sd.Width, sd.Height) : row_bytes(f, sd.Width));
    hd[19] = 32;
    if (block_fmt(f)) { hd[20] = PF_FOURCC; hd[21] = f == D3DFMT_DXT1 ? MAKEFOURCC('D', 'X', 'T', '1') : MAKEFOURCC('D', 'X', 'T', '3'); }
    else if (f == D3DFMT_A8R8G8B8) { hd[20] = PF_RGB | PF_ALPHAPIXELS; hd[22] = 32; hd[23] = 0xFF0000; hd[24] = 0xFF00; hd[25] = 0xFF; hd[26] = 0xFF000000u; }
    else { hd[20] = PF_RGB | PF_ALPHAPIXELS; hd[22] = 16; hd[23] = 0x7C00; hd[24] = 0x3E0; hd[25] = 0x1F; hd[26] = 0x8000; }
    hd[27] = 0x1000;                                                         // DDSCAPS_TEXTURE
    fwrite(hd, 1, 128, o);
    for (unsigned y = 0; y < row_count(f, sd.Height); y++) fwrite((char *)lr.pBits + (size_t)y * lr.Pitch, 1, row_bytes(f, sd.Width), o);
    fclose(o); g_dumpedn++;
  }
  t->UnlockRect(0);
}

extern "C" void tr_after_upload(void *t, const TrKey *k, int dmp, int on, int log_each) {
  if (at<unsigned>(t, 0x2C) & 7) return;                  // a cube texture (+0x44): left alone
  IDirect3DTexture8 *&slot = *reinterpret_cast<IDirect3DTexture8 **>(reinterpret_cast<char *>(t) + 0x40);
  if (!slot) return;
  g_seen++;
  std::string key = k->key, name = k->name;
  if (dmp && g_dumped.insert(key).second) dump(slot, key);
  if (!on) return;
  std::string file = g_files.count(lower(key + ".dds")) ? key + ".dds" : g_files.count(lower(name + ".dds")) ? name + ".dds" : std::string();
  if (file.empty()) return;
  auto it = g_cache.find(lower(file));
  if (it == g_cache.end()) { std::vector<unsigned char> b; if (!read_file(g_dir + "\\textures\\" + file, b)) b.clear(); it = g_cache.emplace(lower(file), std::move(b)).first; }
  DdsInfo di; IDirect3DDevice8 *dev = nullptr;
  if (FAILED(slot->GetDevice(&dev)) || !dev) { g_failed++; return; }
  IDirect3DTexture8 *nt = parse_dds(it->second, &di) ? make_texture(dev, it->second, di) : nullptr;
  dev->Release();                                         // (GetDevice added a reference)
  if (!nt) { if (g_failed++ < 20) logf("texture_replace: %s: not a DDS this mod reads, or the device refused it; the game's texture kept", file.c_str()); return; }
  slot->Release(); slot = nt; g_replaced++;
  if (log_each) logf("texture_replace: %s -> %s (%ux%u, %lu levels)", key.c_str(), file.c_str(), di.w, di.h, nt->GetLevelCount());
}

extern "C" int tr_stats(char *buf, unsigned n) {
  long sum = g_seen + g_replaced + g_dumpedn + g_failed; if (sum == g_last) return 0; g_last = sum;
  snprintf(buf, n, "texture_replace: %ld uploads keyed, %ld replaced, %ld dumped, %ld failed", g_seen, g_replaced, g_dumpedn, g_failed);
  return 1;
}
