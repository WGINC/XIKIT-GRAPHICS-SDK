// color_filter_core.h -- the part of color_filter that needs no tree headers (color_filter.cpp explains the mod)
#pragma once
#ifdef __cplusplus
extern "C" {
#endif
// the 3x3 matrix (rows) for mode 1 protanopia, 2 deuteranopia, 3 tritanopia: correction at strength percent; with
// simulate, the simulation itself (for checking what a colour-blind player sees)
void cf_matrix(int mode, int strength, int simulate, float out[12]);
typedef int (__stdcall *cf_pass_fn)(unsigned shader, void *src_tex, void *dst_surf, const float *c, unsigned n);
// the finished frame (the back buffer) through the shader with the matrix, drawn back over it; 1 done
int cf_frame(void *device, cf_pass_fn pass, unsigned shader, const float m[12], void (*log)(const char *));
// the filtered frame's centre pixel (0x00RRGGBB) read back from the last cf_frame, or -1
long cf_check(void *device);
void cf_release(void);
#ifdef __cplusplus
}
#endif
