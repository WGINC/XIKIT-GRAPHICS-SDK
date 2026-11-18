// ui_layout_core.cpp -- reads ui_layout.txt for ui_layout.cpp (Windows headers only; the tree's headers define some
// Windows names themselves)
#include <windows.h>
#include <stdio.h>
#include <string.h>
extern "C" int ul_read(const char *dir, char (*keys)[17], short *dx, short *dy, int max) {
  char path[MAX_PATH]; snprintf(path, sizeof path, "%s\\ui_layout.txt", dir);
  FILE *f = fopen(path, "r"); if (!f) return 0;
  char line[256]; int n = 0;
  while (n < max && fgets(line, sizeof line, f)) {
    char k[64]; int a, b;
    if (line[0] == '#' || sscanf(line, "%63s %d %d", k, &a, &b) != 3) continue;
    int j = 0; for (int i = 0; k[i] && j < 16; i++) keys[n][j++] = (char)(k[i] >= 'A' && k[i] <= 'Z' ? k[i] + 32 : k[i]);
    keys[n][j] = 0; dx[n] = (short)a; dy[n] = (short)b; n++;
  }
  fclose(f); return n;
}
