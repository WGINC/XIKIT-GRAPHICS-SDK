// audio_mix.cpp -- an example mod: a volume for each of the game's sound categories, on top of the game's own.
// Build:  sdk/build_mod.sh audio_mix.dll sdk/examples/audio_mix.cpp
//
// The categories, from the game's code (tree/src/SoundElem.cpp, tree/src/MusicFont.cpp):
// - interface (0x10351700): read by the menu and target sounds (MusicTrack_SetVolumeId0009 and its siblings find a
//   Sep chunk by id and set its volume from it; their callers are Target_Select, Target_ApplyAction,
//   NetCellFont_MenuMoveSelection and the other menus);
// - effects (0x10351704): read by CYySoundElem::UpdateTimerAndPosition, the effect elements' sounds (Sep, the
//   generator's element kind 0x3D);
// - ambient (0x10351708): the zone's looped sound (SoundElem_SetCurrent10463914, called by XiZone), whose track
//   volume SoundElem_SetScaled10351708 sets;
// - music: Music_ApplyVolume, the music track (0x10463920).
// Each is set by its setter, SoundElem_SetScaled10351700/04/08 and Music_ApplyVolume, as
// [0x103516FC] * [0x103516F8] * level: the two factors are the game's configured volumes
// (SoundElem_SetFactor103516FC/F8, from TextInputFiles_ApplyConfigSetting, which then calls all four setters with
// 1.0), and the level comes from the volume-change tasks (CMoVolumeChangeTask) or that 1.0.
//
// The mod hooks the four setters and multiplies their level by its setting. Three of them have manifest flag 8 (the
// game's code reads a register at their entry that their declaration does not carry), so the hooks are small
// assembly stubs: they record the game's level, scale the float argument where it lies on the stack and jump to
// the game's code, leaving every general register as it was (hook_keeping_registers). When a setting changes the
// mod calls each setter again with the last level the game gave it.
//
// Settings (percent, 100 the game's): vol_interface, vol_effects, vol_ambient, vol_music.
//
// Tested offline (kit/xikit/test, mode audmod): the game's own setters through the hooks, the category values read
// back, and the re-application when a setting changes. Not yet run in the game (no sound device in the test).
#include "xikit_sdk.hpp"
XIKIT_MOD_GLOBALS

static const XikitHost *g_host;
extern "C" {
float g_au_k[4] = { 1, 1, 1, 1 };          // interface, effects, ambient, music
float g_au_base[4] = { 1, 1, 1, 1 };       // the last level the game passed
void *g_au_prev[4];
void au_stub0(void); void au_stub1(void); void au_stub2(void); void au_stub3(void);
}
// each stub: base[i] = [esp+4]; [esp+4] *= k[i]; jmp prev[i]   (cdecl float argument at [esp+4]; x87 stack balanced)
#define AU_STUB(i) \
  __asm__(".globl _au_stub" #i "\n_au_stub" #i ":\n\t" \
          "flds 4(%esp)\n\tfsts _g_au_base+" #i "*4\n\tfmuls _g_au_k+" #i "*4\n\tfstps 4(%esp)\n\t" \
          "jmp *_g_au_prev+" #i "*4\n");
AU_STUB(0) AU_STUB(1) AU_STUB(2) AU_STUB(3)

static const char *const kNames[4] = { "SoundElem_SetScaled10351700", "SoundElem_SetScaled10351704", "SoundElem_SetScaled10351708", "Music_ApplyVolume" };
static const char *const kKeys[4] = { "vol_interface", "vol_effects", "vol_ambient", "vol_music" };
static void (*const kStubs[4])(void) = { au_stub0, au_stub1, au_stub2, au_stub3 };

static void read_settings() { for (int i = 0; i < 4; i++) g_au_k[i] = g_host->setting_int(kKeys[i], 100) / 100.0f; }
extern "C" __declspec(dllexport) void xikit_mod_settings(void) {
  read_settings();
  for (int i = 0; i < 4; i++)                            // again with the game's last level, through the stub (scaled there)
    if (g_au_prev[i]) reinterpret_cast<void (__cdecl *)(float)>(kStubs[i])(g_au_base[i]);
}
extern "C" __declspec(dllexport) int xikit_mod_init(const XikitHost *host) {
  g_host = host;
  host->declare_int("vol_interface", 100, 0, 200, "percent of the game's volume for menu and target sounds");
  host->declare_int("vol_effects", 100, 0, 200, "percent of the game's volume for spell and ability effect sounds");
  host->declare_int("vol_ambient", 100, 0, 200, "percent of the game's volume for the zone's ambient sound");
  host->declare_int("vol_music", 100, 0, 200, "percent of the game's volume for the music");
  read_settings();
  int r = 0;
  for (int i = 0; i < 4; i++) r |= host->hook_keeping_registers(kNames[i], (void *)kStubs[i], &g_au_prev[i]);
  return r;
}
