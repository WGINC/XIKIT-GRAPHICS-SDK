// hotbar_core.h -- shared between hotbar.cpp (the tree's headers) and hotbar_core.cpp (Windows' headers)
#pragma once
#define HB_BARS 10
#define HB_SLOTS 12
#define HB_LINES 8
#define HB_SETS 8
struct HbKey { int vk, ctrl, alt, shift; char name[16]; int dflt; };   // dflt: one of the default keys (hb_read)
// one slot's action, resolved to command lines
struct HbAct {
  int used;
  char label[48];
  char kind[12];                        // ma ja ws pet item input macro ct line hb
  char icon[260];                       // an image file, "" for none
  int nlines; char line[HB_LINES][200]; int wait_ms[HB_LINES];    // line i runs wait_ms[i] after line i-1
  int mp, tp;                           // costs from XIVhotbar2's resource tables (0: none)
  char tip[200];                        // the tooltip's second line
  char source[24];                      // where it came from: hotbar.txt, Root, Base, a job or set name
};
struct HbBar { int used, slots, x, y, vertical; HbKey key[HB_SLOTS]; };
struct HbConfig {
  int nbars; HbBar bar[HB_BARS];
  char job[16], sub[16];
  char sets[HB_SETS][32]; int nsets;
  int env;                              // 0 field, 1 battle (the starting one: hotbar.txt's env line)
  char xiv[260];                        // XIVhotbar2's folder (with data/, images/, priv_res/), "" for none
  int xiv_keys;                         // 1: keys from <xiv>/data/default_keybinds.lua
  HbKey env_key;                        // toggles field/battle
};
// the slots as shown: [env][bar][slot]
struct HbLayout { HbAct a[2][HB_BARS][HB_SLOTS]; };
extern "C" {
// hotbar.txt (and the XIVhotbar2 files it names) into cfg and the layout; err gets the first problem; 0: no hotbar.txt
int hb_read(const char *dir, HbConfig *cfg, HbLayout *lay, char *err, int errlen, char *note, int notelen);
long long hb_mtime(const char *dir);                                  // hotbar.txt's time and size, 0 without one
int hb_key_down(const HbKey *k);                                      // the key with exactly its modifiers held (polling)
// Key presses from the game window's messages (no system call per frame): the window is subclassed once; each fresh
// WM_KEYDOWN / WM_SYSKEYDOWN (not auto-repeat, not a modifier key) is queued with its modifiers and the stamp() taken
// at that moment (the chat line's text before the WM_CHAR that may follow). hb_msg_next pops one press.
struct HbPress { HbKey key; unsigned stamp; };
int hb_msg_install(void *hwnd, unsigned (*stamp)(void));             // 1: subclassed (or already)
void hb_msg_uninstall(void);
int hb_msg_next(HbPress *out);
long hb_msg_seen(void);                                               // key messages seen since install
int hb_is_foreground(void *hwnd);                                     // the game's window (or a window it owns) has focus
unsigned hb_now_ms(void);
void hb_copy(char *dst, int n, const char *src);
int hb_write_file(const char *dir, const char *name, const char *text);
int hb_fmt(char *dst, int n, const char *fmt, ...);
int hb_ieq(const char *a, const char *b);                             // equal, ignoring case
// an image file as 32-bit BGRA (straight alpha), w x h, caller frees with hb_image_free; 0 on failure
int hb_image_load(const char *path, int *w, int *h, unsigned **pixels);
void hb_image_free(unsigned *pixels);
}
