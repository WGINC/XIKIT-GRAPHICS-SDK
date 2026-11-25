// photo_mode_core.h -- the part of photo_mode that needs no tree headers (photo_mode.cpp explains the mod)
#pragma once
#ifdef __cplusplus
extern "C" {
#endif
void ph_init(const char *dir, void (*log)(const char *line));
// the free camera's eye: the game's eye orbited about its look-at point by yaw and pitch (degrees, about the game's
// Y axis and the horizontal one), its distance scaled by dist_pct, then raised by `raise` along the game's Y
void ph_orbit(const float eye[3], const float at[3], float yaw_deg, float pitch_deg, float dist_pct, float raise, float out_eye[3]);
// a picture of the texture (the world as composited, before the interface) as a 24-bit BMP in <dir>\screenshots
int ph_shot(void *device, void *texture);
// the texture drawn over the whole render target (after the game's frame: the interface covered)
void ph_cover(void *device, void *texture);
#ifdef __cplusplus
}
#endif
