> Paths in this document are the development repository's: tree/src/ is sdk/tree_src/ here, kit/xikit/ and kit/d3d8on11/ are src/xikit/ and src/d3d8on11/, sdk/examples/ is sdk/examples/; docs/HISTORY.md and kit/sessions/ are not published.

# The game's sound: settings, categories, the music, the sound thread

How FFXiMain.dll sets the volume of each kind of sound and hands it to its sound thread, read from its code
(analysed build 6A995428). Sources: the tree's C (tree/src/SoundElem.cpp, tree/src/MusicFont.cpp,
tree/src/TextInputFiles.cpp) and the disassembly of the unpacked DLL where the tree has no source. **Not known** marks
what is not read.

## 1. The settings and their factors

The game's settings live in a table (`TextInputFiles_CreateConfigObjects` registers a callback per setting with
`TextInputFiles_AddPairChecked`; registering calls the callback at once with the stored value,
`TextInputFiles_AddPairAndCall`; `Settings_GetValue(key)` returns the stored value, entry +8). Three settings set
volumes:

| Setting | Callback | What it writes |
|---|---|---|
| 9 | `TextInputFiles_ApplyConfigSetting` (0x101AA650, tree/src/TextInputFiles.cpp:6821) | `[0x103516F8]` = v/100 (0 when v < 1), `[0x103516FC]` = 1.0 (`SoundElem_SetFactor103516F8/FC`; each then calls the four category setters of 2 with level 1.0) |
| 10 | the same (:6828) | `[0x103517F4]` = v/100 (0 when v < 1) by 0x100372A0, `[0x103517F8]` = 1.0 by 0x100372E0; each sends the music's new volume (3) |
| 0xA8 | 0x1019DF20 -> 0x1019DE50 (disassembly) | both pairs from the one value: `[0x103516FC]` = 1.0, `[0x103517F8]` = 1.0, `[0x103516F8]` and `[0x103517F4]` = v x 0.01 (0x10329A18); 0 for v <= 0 |

0xA8 is registered after 9 and 10 (0x101A9E26, after 0x101A97F0 and 0x101A97FD), so at the table's creation its value
is the last written to both pairs. Which options of the game's menus these keys are: **not read** (the menus' text
for them is not traced).

The two factors that settings 9 and 10 reset to 1.0 are the typed mutes (25 Nov): `Command_RunLine` dispatches
through the table 0x10356E30 (216 entries of {command, handler, flag}) after looking the typed word up in the table
0x10355408 (277 entries of {name[20], command, ...}): **`/mutebgm`** is command 0x99, handler 0x1007F680, which
toggles `[0x103517F8]` between 0 (chat message 0x147) and 1.0 (0x148) through 0x100372E0; **`/mutese`** is 0x9A,
0x1007F750, which toggles `[0x103516FC]` the same way (messages 0x149, 0x14A) through `SoundElem_SetFactor103516FC`.

## 2. The categories of the effects' sounds and their setters

| Category | Value | Setter | Who reads it |
|---|---|---|---|
| interface | float at 0x10351700 | `SoundElem_SetScaled10351700` (0x100360A0): factor x factor x level | the menu and target sounds (`MusicTrack_SetVolumeId0009` and its siblings; their callers `Target_Select`, `Target_ApplyAction`, `NetCellFont_MenuMoveSelection`, ...) |
| effects | float at 0x10351704 | `SoundElem_SetScaled10351704` (0x10036050) | `CYySoundElem::UpdateTimerAndPosition`: the effect elements' sounds |
| ambient | float at 0x10351708, and the zone loop's track | `SoundElem_SetScaled10351708` (0x10035FB0): also sends the track's volume through 0x10038470 | the zone's looped sound (`SoundElem_SetCurrent10463914`, from XiZone) |
| scheduled | the track `[0x10463920]` | `Music_ApplyVolume` (0x100360F0) | the sound an effect's scheduler plays: `CMoSchedularTask`'s interpreter (0x10057FB0) writes the track at 0x1005B959 (through 0x1005E610) for its commands 0x60 and 0x8A (docs/EFFECT_COMMANDS.md), after `SoundVolume_SetVolumeScalar` on a resource of type 0x3D; command 0x8B stops it |

The factors are `[0x103516FC]` x `[0x103516F8]` (setting 9, or 0xA8). The level comes from the volume-change tasks:
`CMoVolumeChangeTask`'s end (0x10035B00, disassembly) applies its last level to the setter of its kind (+0x34: 1
interface, 2 effects, 3 ambient, 4 scheduled) and for kind 4 clears `[0x1046391C]` and `[0x10463920]`.

`Music_ApplyVolume(level)`: v = `[0x103516FC]` x `[0x103516F8]` x level x 127.0 (0x1032A34C); with the sound on
(byte 0x104638F5) and level > 0.0 it calls `Music_SetTrackVolume` (0x10038470: returns for a negative track, clamps v
to 0..127, sends command 4 (track, v, 0)); with level 0, command 0 (stop) for `[0x1046391C]`, `[0x10463920]`.

(Until 25 Nov this document called `Music_ApplyVolume`'s track "the music" and 0x10035B00 the function that chooses
it. Both were wrong: the background music is section 3, and 0x10035B00 is the task's end.)

## 3. The background music

The music files are `%s\music%3.3u.bgw` (0x103888DC), the stream kind "BGMStream" (0x103888D0).
`CYyMusicLoadTask::StartTrack` (0x100378B0) starts a track: command 9 to the stream channels if another track
plays, then `Music_LoadTrackIfRunning(track, v)` (0x100382A0 -> `LobbyThread_QueueMusicFile` -> command 7) and
`LobbyThread_SendCmd8(-1, v, 0)`, with v = `[0x103517F8]` x `[0x103517F4]` x 127.0. Every other music volume goes
through `LobbyThread_SendCmd8(-1, v, fade)` too (its callers: 0x100372A0 and 0x100372E0 (the settings), 0x10037400,
0x10037A30 (volume x the two factors), StartTrack, 0x10017690 (volume 0), 0x10250030 (volume 0 over 0x2D)).
`LobbyThread_SendCmd8` keeps the volume & 0x7F (0x10246784).

## 4. The sound thread and its command ring

**The thread.** `0x10245DE0` (called from the sound system's start 0x100355F0) creates DirectSound
(0x1026A890 -> `[0x106690F4]`), sets its cooperative level (`IDirectSound::SetCooperativeLevel`, vtable +0x18, level 2:
DSSCL_PRIORITY in dsound.h) and starts the thread 0x10245C20 at priority 2 (THREAD_PRIORITY_HIGHEST). The thread
loops while its object's +8 is set: 0x1024C020, then `Sleep(16)`. 0x1024C020 runs, in order: 0x102489A0 (the 20
effect channels' tick), 0x10248AE0 (the stream channels' tick), 0x1024C170 (the ring's reader). Commands 3, 4 and 5
take the critical section 0x106690CC, which the ticks share.

**The ring.** `LobbyThread_PushCmd` (0x1024C060) writes 32-byte records {command, 7 arguments} into the 0x2000-byte
ring at `[0x106690E8]` (write pointer 0x106690C4, read pointer 0x106690F0), refusing when full; command 7 also copies 8
more blocks (the file name). It takes no lock: the game's thread is its one writer. The ring and the channel pools are
made by 0x1024B990 (called from 0x10245C60). The reader 0x1024C170 calls `[0x10388C18 + 4 x command]` for each record
below command 14.

**The two pools.** 20 effect channels at `[0x106690C8]`, 0xF4 bytes each (id +0xC0, second id +0xC4, its
DirectSound buffer +4, a playing thread's handle +0x3C, the level: steps +0x6C, value +0x70, step +0x74, stop at the end
+0x78; the pan: steps +0x7C, value +0x80, step +0x84). 3 stream channels at `[0x106690B8]`, 0x1C0 bytes each (buffer
+4, thread +0x38, steps +0x48, level +0x4C, step +0x50, stop at the end +0x54, track id +0x94, position +0x98).

**The tick** (0x102489A0, the effect channels; disassembly): each channel's level and pan step toward their targets;
a level that has finished with "stop at the end" set clears +0x48 (stops it). Then 0x10248900 turns them into
DirectSound units: pan p (0..127, 64 the centre) -> (|p - 64| scaled to 0..10000, negative left of 64); level
(0..4096) x the side's attenuation `[0x103888F0 + 4 x (p or 127 - p)]` / 4096 -> volume = that x 10000 / 4096 -
10000, in hundredths of a dB; `IDirectSoundBuffer::SetVolume` (vtable +0x3C) clamped to -10000..0 and `SetPan`
(+0x40) to -10000..10000 (0x102468E0, 0x10246910). A channel whose thread has ended (`WaitForSingleObject(+0x3C, 0)`)
is closed: `Stop` (+0x48), its buffer released, +0xC0 cleared. 0 is DSBVOLUME_MAX in dsound.h: **at a level of 4096
a channel is at DirectSound's full volume; no volume the game sends makes it louder.**

The level table `[0x103889F0]` (128 entries, read from the file): 0, 2340, 2511, 2633, ... 4092, 4096 (entry 127).

| Command | Sender | Handler | What it does |
|---|---|---|---|
| 0 | `LobbyThread_SendCmd0` (track, id2) | 0x1024A720 | stop the effect channels with that id (all for a negative id; by id2 when id is 0): +0x48 = 0; also clears `[stream pool + 0x434]` |
| 1 | `LobbyThread_QueueSoundCmd` (data not named "SeSep") | 0x1024AB50 | play a sound from a data block: blocks starting "SeWave" (0x10388C8C) go to 0x1024A7A0, others to 0x1024A440; each starts a playing thread 0x102480C0 |
| 2 | `LobbyThread_QueueSoundCmd` ("SeSep" blocks), 0x102460A0, 0x102460E0 | 0x1024AB80 | play a sound by number: looked up (0x10249D10) or loaded (0x10249E00), then 0x1024A7A0. 0x102460E0 picks one of 4 entries of `[0x10669104]` |
| 3 | `LobbyThread_SendCmd3` (track, pan & 0x7F, fade), from `LobbyThread_SendCmd3FromFloat` | 0x1024AE50 | **pan** of the effect channels with that id, over fade x 50 / 60 steps (it reaches `SetPan`) |
| 4 | `LobbyThread_SendCmd4` (track, 0, volume & 0x7F, fade) | 0x1024ABD0 | **volume** of the effect channels with that id: level = table[volume] << 12 over fade x 50 / 60 steps |
| 5 | 0x10246350 (track, fade), called from 0x10036BE0 | 0x1024AD00 | fade the effect channels with that id to table[1] and stop them at the end |
| 6 | `LobbyThread_SendCmd6` (track) | 0x1024B820 -> 0x1024AF80 | forget a stream track id: the first two stream channels whose +0x94 is it (or any, for a negative id) get -1 |
| 7 | `LobbyThread_QueueMusicFile` (music%3.3u.bgw), `LobbyThread_QueueStreamFile`, 0x102464A0 ("BGM" names) | 0x1024B830 -> 0x1024AFC0 | play a stream on **stream channel 0** (always the pool's first): read the file's 0x30-byte header ("BGMStream", or parsed by 0x10249AD0); stop what plays there; make a DirectSound buffer (`IDirectSound::CreateSoundBuffer`, +0xC); start at the position saved for its track id (command 10), else at the header's length x command 12's fraction (then cleared); start the stream thread 0x10247940 (priority 1); fade in from table[1] to table[volume] over fade steps |
| 8 | `LobbyThread_SendCmd8` (track, volume & 0x7F, fade) | 0x1024B8B0 -> 0x1024B440 | volume of the first two stream channels whose +0x94 is the track or is negative (both for a negative track): level = table[volume] << 12 at +0x4C, over fade x 50 / 60 steps |
| 9 | `LobbyThread_SendCmd9` (track, fade) | 0x1024B8D0 -> 0x1024B4E0 | fade the stream channels with that track to table[1] and stop them at the end |
| 10 | 0x102467D0 | 0x1024B8F0 | save stream channel 0's position (+0x98) for its track id in the 1024-entry table `[0x106690BC]` (command 7 resumes from it) |
| 11 | `LobbyThread_SendCmd11` (track) | 0x1024B920 | clear a track's saved position (all 1024 for a negative track) |
| 12 | 0x10246820 (float x 4096) | 0x1024B960 | the next stream's start, as a fraction of its length: `[0x106690EC]` = argument / 4096 |
| 13 | 0x102468B0 (a buffer) | 0x1024B980 -> 0x1024B580 | copy each effect channel's `GetVolume`, `GetPan`, `GetFrequency`, `GetStatus` (vtable +0x18..+0x24) into the buffer |

**The stream tick** (0x10248AE0) reads only stream channel 0: its level steps as the effect channels' do; the
volume is the level x the stream's own volume (the header's byte +0x2C, kept at +0xB8; 0x7F when the header has none)
at the centre pan, sent with `SetVolume`; a fade-out with "stop at the end" sets its track id to -1, and once the
stream thread has ended the buffer is stopped and released.

**The playing threads.** The stream thread 0x10247940 (command 7) and the effect sound thread 0x102480C0 (commands
1 and 2) do the same (their calls, disassembly): read the file through the C runtime (0x102CA030..0x102CA1C0),
decode a block (0x10246D30 for streams, 0x10247230 for effect sounds), write it into the DirectSound buffer
(`Lock` +0x2C, `Unlock` +0x4C), `Play` (+0x30), `SetCurrentPosition` (+0x34), poll `GetCurrentPosition` (+0x10), and
`Sleep(1)` between polls; `Stop` (+0x48) at the end. The decoders' formats: **not read line by line**.

0x102466F0 answers questions about stream channel 0 without the ring: (0, id) whether that id plays, (1, id) its level
(+0x4C >> 12), (3, id) its fade steps left. The music therefore plays on stream channel 0, the only one command 7
fills and the tick drives; channels 1 and 2 are made (0x1024B990) and commands 6 and 8 loop over channel 1, but no
code starts a stream on them.

**The repo's name "LobbyThread" for this unit is from low- and medium-confidence evidence (data/names/
316_unit_10244EA0_LobbyThread.json); everything that writes the ring is sound or music, and none of it is in the
security set (data/security_set.json).** It is the sound thread; the names stay until the unit is renamed with the
naming pipeline.

## 5. What a mod uses

- Scale a category of 2: hook its setter and scale the level (they read registers their declarations do not carry:
  manifest flag 8; sdk/examples/audio_mix.cpp's stubs keep every register). Re-apply: call the setter again with the
  game's last level.
- Scale the music: scale the volume in `LobbyThread_SendCmd8` (track -1) and `Music_LoadTrackIfRunning`, where every
  music volume ends whichever setting wrote the factors (audio_mix.cpp since 25 Nov). Re-apply: send the game's last
  command-8 volume again. Never above 127 (the & 0x7F). Louder than the game's full volume is not possible at all:
  volume 127 is level 4096, which the tick sends as 0, DirectSound's maximum (section 4).

## 6. Not known

- Which options in the game's menus settings 9, 10 and 0xA8 are (their labels are the game's data files).
- Commands 1 and 2 past their dispatch (the sound data blocks' layout), the two decoders, and the field
  `[stream pool + 0x434]` (cleared by commands 0, 1 and 2).
