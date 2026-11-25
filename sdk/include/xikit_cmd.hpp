// xikit_cmd.hpp -- chat commands of a mod's own ("/hb reload", "/mymod on"): typed in the game's chat line, or run
// by xiui::run_line, they reach the mod instead of the game. Header only; include it after xikit_sdk.hpp.
//
// How (from the game's code, build 6A995428, TextCommand.cpp and InputDevices.cpp):
// - Command_RunLine (0x10080DC0, cdecl: line, mode; in the manifest, with a trampoline) runs a line of the chat line:
//   Input_HandleChar calls it with the chat line's text when Enter is pressed (InputDevices.cpp:304), and the game's
//   own code calls it for its macros and menus.
// - On a line with nothing to run it returns 0 (`if (local_200[0] == '\0') return 0;`, after its input processing).
//   A line this mod takes returns 0 too: the answer the game's code already gives for a line it does nothing with.
//
// Each mod hooks Command_RunLine itself; with kit API 5 several mods' hooks chain, and each looks only at its own
// words. A line no hook takes goes on to the game unchanged. Words are matched without case, after a leading '/', so
// "/HB Reload" reaches "hb". A word the game has itself (/say, /ma, ...) can be taken too: choose words that are not.
#pragma once
#include <string.h>
#include "xikit_sdk.hpp"

namespace xicmd {

typedef void (*Handler)(const char *args);       // args: the rest of the line after the word and its spaces
struct Entry { char word[24]; Handler fn; };

inline Entry *table() { static Entry t[16]; return t; }
inline int &count() { static int n; return n; }
inline long &taken() { static long n; return n; }
inline xikit::fn<decltype(&Command_RunLine)> &prev() { static xikit::fn<decltype(&Command_RunLine)> p; return p; }

inline char lower(char c) { return c >= 'A' && c <= 'Z' ? (char)(c + 32) : c; }
// the word of a line ("/hb reload" -> "hb"), into w; returns where the arguments start
inline const char *split(const char *line, char *w, int n) {
  const char *p = line; while (*p == ' ') p++;
  if (*p == '/') p++;
  int k = 0; while (*p && *p != ' ' && k < n - 1) w[k++] = lower(*p++);
  w[k] = 0;
  while (*p == ' ') p++;
  return p;
}
inline int __cdecl hook(char *line, undefined4 mode) {
  if (line) {
    char w[24]; const char *args = split(line, w, sizeof w);
    for (int i = 0; i < count(); i++)
      if (w[0] && !strcmp(table()[i].word, w)) { taken()++; table()[i].fn(args); return 0; }
  }
  return prev()(line, mode);
}
// Add a command (in xikit_mod_init, before install): word without '/', any case. Up to 16 a mod.
inline bool add(const char *word, Handler fn) {
  if (count() >= 16 || !word || !fn) return false;
  Entry &e = table()[count()++]; int k = 0;
  while (word[k] && k < (int)sizeof e.word - 1) { e.word[k] = lower(word[k]); k++; }
  e.word[k] = 0; e.fn = fn;
  return true;
}
// Hook Command_RunLine (in xikit_mod_init). Returns XIKIT_OK or the kit's error (XIKIT_E_TAKEN: another mod hooks it
// and the kit is older than API 5).
inline int install(const XikitHost *host) { return XI_HOOK(host, Command_RunLine, hook, prev()); }
// Lines taken so far (for a mod's tests).
inline long lines_taken() { return taken(); }

}  // namespace xicmd
