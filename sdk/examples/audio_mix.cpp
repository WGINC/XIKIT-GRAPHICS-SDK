// audio_mix.cpp -- an example mod: a volume for each of the game's sound categories, on top of the game's own.
// Build:  sdk/build_mod.sh audio_mix.dll sdk/examples/audio_mix.cpp
//
// The categories, from the game's code (docs/AUDIO.md; tree/src/SoundElem.cpp, tree/src/MusicFont.cpp,
// tree/src/TextInputFiles.cpp):
// - interface (0x10351700): read by the menu and target sounds (MusicTrack_SetVolumeId0009 and its siblings find a
//   Sep chunk by id and set its volume from it; their callers are Target_Select, Target_ApplyAction,
//   NetCellFont_MenuMoveSelection and the other menus);
// - effects (0x10351704): read by CYySoundElem::UpdateTimerAndPosition, the effect elements' sounds (Sep, the
//   generator's element kind 0x3D);
// - ambient (0x10351708): the zone's looped sound (SoundElem_SetCurrent10463914, called by XiZone), whose track
//   volume SoundElem_SetScaled10351708 sets;
// - scheduled: Music_ApplyVolume, the track 0x10463920, which is the sound an effect's scheduler plays with its
//   commands 0x60 and 0x8A (CMoSchedularTask's interpreter 0x10057FB0 writes it at 0x1005B959) -- not the music;
// - music: the background music (music%3.3u.bgw, "BGMStream"), started by CYyMusicLoadTask::StartTrack on the sound
//   thread's three stream channels, at [0x103517F8] x [0x103517F4] x 127 (the game's setting 10 sets [0x103517F4]).
// The first four are set by their setters, SoundElem_SetScaled10351700/04/08 and Music_ApplyVolume, as
// [0x103516FC] * [0x103516F8] * level: [0x103516F8] is the game's setting 9 (TextInputFiles_ApplyConfigSetting(9, v):
// v/100, [0x103516FC] = 1.0, then all four setters with 1.0); the level comes from the volume-change tasks
// (CMoVolumeChangeTask) or that 1.0.
//
// The mod hooks the four setters and multiplies their level by its setting. Three of them have manifest flag 8 (the
// game's code reads a register at their entry that their declaration does not carry), so the hooks are small
// assembly stubs: they record the game's level, scale the float argument where it lies on the stack and jump to
// the game's code, leaving every general register as it was (hook_keeping_registers). When a setting changes the
// mod calls each setter again with the last level the game gave it.
//
// The music has more than one writer of its factors (setting 10 through TextInputFiles_ApplyConfigSetting, setting
// 0xA8 through 0x1019DE50, the toggle at 0x1007F680), but every volume it ends in goes to the sound thread through
// two functions: LobbyThread_SendCmd8(-1, volume, fade) (all three stream channels: the settings, StartTrack, the
// mute at 0x10017690, the fade-out at 0x10250030) and Music_LoadTrackIfRunning(track, volume) (a track's start). The
// mod scales the volume in both and, when vol_music changes, sends the game's last command-8 volume again.
//
// Settings (percent, 100 the game's): vol_interface, vol_effects, vol_ambient, vol_scheduled, vol_music. The sound
// thread keeps a volume & 0x7F (LobbyThread_SendCmd8, 0x10246784) and turns it into a level through a 128-entry
// table (0x103889F0, in its command handlers 0x1024ABD0 and 0x1024B440), so the music is never sent above 127: above
// 100% it only raises music the game plays below its full volume.
//
// Tested offline (kit/xikit/test, mode audmod): the game's own setters, its setting 10 and Music_LoadTrackIfRunning
// through the hooks; the categories' floats and the music's volume (the sound thread's ring record) read back; the
// re-application when a setting changes. The music's path is not run in the game yet.
#include "xikit_sdk.hpp"
XIKIT_MOD_GLOBALS

static const XikitHost *g_host;
extern "C" {
float g_au_k[4] = { 1, 1, 1, 1 };          // interface, effects, ambient, scheduled
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
static const char *const kKeys[4] = { "vol_interface", "vol_effects", "vol_ambient", "vol_scheduled" };
static void (*const kStubs[4])(void) = { au_stub0, au_stub1, au_stub2, au_stub3 };

// the music: the volume sent to the three stream channels the music plays on (LobbyThread_SendCmd8, command 8, track
// -1: all three) and the volume a track starts at (Music_LoadTrackIfRunning -> LobbyThread_QueueMusicFile, command 7)
extern "C" {
int g_music_pct = 100;
int g_bgm_last = -1;                                   // the last volume the game sent to all channels (-1: none yet)
void *g_bgm_load_prev;
void bgm_load_stub(void);
void __cdecl bgm_scale_arg(int *v);
}
static int bgm_scale(int v) {
  if (v <= 0) return v;
  long long s = (long long)v * g_music_pct / 100;
  return s > 127 ? 127 : (int)s;                       // the sound thread keeps volume & 0x7F: never above 127
}
extern "C" void __cdecl bgm_scale_arg(int *v) { *v = bgm_scale(*v); }
// Music_LoadTrackIfRunning(track, volume): manifest flag 8, so a stub keeps every register: scale [esp+8] in place
__asm__(".globl _bgm_load_stub\n_bgm_load_stub:\n\t"
        "pushl %eax\n\tpushl %ecx\n\tpushl %edx\n\tleal 20(%esp), %eax\n\tpushl %eax\n\t"
        "call _bgm_scale_arg\n\taddl $4, %esp\n\tpopl %edx\n\tpopl %ecx\n\tpopl %eax\n\t"
        "jmp *_g_bgm_load_prev\n");
// LobbyThread_SendCmd8(track, volume, fade): ret 0xC (its callers set ECX; it does not read it: 0x10246770)
typedef void (__stdcall *Cmd8Fn)(int track, int volume, int fade);
static Cmd8Fn g_cmd8_prev;
static void __stdcall cmd8_hook(int track, int volume, int fade) {
  if (track == -1) g_bgm_last = volume;
  g_cmd8_prev(track, bgm_scale(volume), fade);
}

static void read_settings() {
  for (int i = 0; i < 4; i++) g_au_k[i] = g_host->setting_int(kKeys[i], 100) / 100.0f;
  g_music_pct = g_host->setting_int("vol_music", 100);
  g_host->log("audio_mix: interface %d%%, effects %d%%, ambient %d%%, scheduled sounds %d%%, music %d%%", (int)(g_au_k[0] * 100 + 0.5f), (int)(g_au_k[1] * 100 + 0.5f), (int)(g_au_k[2] * 100 + 0.5f), (int)(g_au_k[3] * 100 + 0.5f), g_music_pct);
}
extern "C" __declspec(dllexport) void xikit_mod_settings(void) {
  read_settings();
  for (int i = 0; i < 4; i++)                            // again with the game's last level, through the stub (scaled there)
    if (g_au_prev[i]) reinterpret_cast<void (__cdecl *)(float)>(kStubs[i])(g_au_base[i]);
  if (g_cmd8_prev && g_bgm_last >= 0) {                // the music: the game's last volume again, scaled
    cmd8_hook(-1, g_bgm_last, 0);
    g_host->log("audio_mix: music: the game's volume %d sent as %d", g_bgm_last, bgm_scale(g_bgm_last));
  }
}
extern "C" __declspec(dllexport) int xikit_mod_init(const XikitHost *host) {
  g_host = host;
  host->declare_int("vol_interface", 100, 0, 200, "percent of the game's volume for menu and target sounds");
  host->declare_int("vol_effects", 100, 0, 200, "percent of the game's volume for spell and ability effect sounds");
  host->declare_int("vol_ambient", 100, 0, 200, "percent of the game's volume for the zone's ambient sound");
  host->declare_int("vol_scheduled", 100, 0, 200, "percent of the game's volume for the sounds an effect's scheduler plays (Music_ApplyVolume's track)");
  host->declare_int("vol_music", 100, 0, 200, "percent of the game's music volume (the background music); at most 127 of 127, so above 100% it only raises music the game plays below full");
  read_settings();
  int r = 0;
  for (int i = 0; i < 4; i++) r |= host->hook_keeping_registers(kNames[i], (void *)kStubs[i], &g_au_prev[i]);
  r |= host->hook("LobbyThread_SendCmd8", (void *)cmd8_hook, (void **)&g_cmd8_prev);
  r |= host->hook_keeping_registers("Music_LoadTrackIfRunning", (void *)bgm_load_stub, &g_bgm_load_prev);
  return r;
}
