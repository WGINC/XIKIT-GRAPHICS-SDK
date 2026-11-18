// effect_comfort_core.cpp -- reads effects.txt for effect_comfort.cpp (Windows headers only)
#include <windows.h>
#include <stdio.h>
#include <string.h>
extern "C" int ec_read(const char *dir, char (*keys)[96], int *pct, int max) {
  char path[MAX_PATH]; snprintf(path, sizeof path, "%s\\effects.txt", dir);
  FILE *f = fopen(path, "r"); if (!f) return 0;
  char line[256]; int n = 0;
  while (n < max && fgets(line, sizeof line, f)) {
    char k[96]; int p;
    if (line[0] == '#' || sscanf(line, "%95s %d", k, &p) != 2) continue;
    for (char *c = k; *c; c++) if (*c >= 'A' && *c <= 'Z') *c += 32;
    strcpy(keys[n], k); pct[n] = p < 0 ? 0 : p > 100 ? 100 : p; n++;
  }
  fclose(f); return n;
}
