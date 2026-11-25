// status_text_core.cpp -- status_text's system calls (the clock), in a file of its own: the game's
// headers, which status_text.cpp includes, declare their own Windows and C runtime types and cannot come with
// <windows.h> or <time.h> (hotbar_core.cpp is split off for the same reason).
#include <windows.h>
#include <time.h>
#include "status_text_core.h"

void st_clock(char *out, int n, int seconds) {
  time_t t = time(NULL); struct tm *lt = localtime(&t);
  if (!lt || !strftime(out, n, seconds ? "%H:%M:%S" : "%H:%M", lt)) out[0] = 0;
}
