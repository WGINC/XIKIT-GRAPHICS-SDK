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

`[0x103517F8]` is also toggled by 0x1007F680 (a pointer to it is at 0x10357500): 0 with chat message 0x147, 1.0 with
0x148 (`ChatLog_AddMessage9Code379`); what calls it through that pointer: **not read**.

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

`LobbyThread_PushCmd` (0x1024C060) writes 32-byte records {command, 7 arguments} into the 0x2000-byte ring at
`[0x106690E8]` (write pointer 0x106690C4, read pointer 0x106690F0), refusing when full; command 7 also copies 8 more
blocks (the file name). It takes no lock: the game's thread is its one writer. The ring and the channel pools are made
by 0x1024B990 (called from 0x10245C60).

The reader is 0x1024C170, called by 0x1024C020 (from 0x10245C20; which thread runs it: **not read**). For each record
below command 14 it calls `[0x10388C18 + 4 x command]` with the arguments:

| Command | Handler | What it does (read so far) |
|---|---|---|
| 0 | 0x1024B760 -> 0x1024A720 | stop (from `LobbyThread_SendCmd0`) |
| 4 | 0x1024B7E0 -> 0x1024ABD0 | volume of the **20-channel pool** `[0x106690C8]` (0xF4 bytes each). Record (track, id2, volume, fade) from `LobbyThread_SendCmd4` (track, 0, volume & 0x7F, fade): the channels whose +0xC0 is the track (all for a negative track; with track 0, those whose +0xC4 is id2); target level = `[0x103889F0 + 4 x volume]` << 12, reached in fade x 50 / 60 steps (at once for 0) |
| 7 | 0x1024B830 -> 0x1024AFC0 | open a stream file on the **3-channel pool** `[0x106690B8]` (0x1C0 bytes each) (from `LobbyThread_QueueMusicFile` and `LobbyThread_QueueStreamFile`) |
| 8 | 0x1024B8B0 -> 0x1024B440 | volume of the 3-channel pool `[0x106690B8]`, record (track, volume & 0x7F, fade): of its **first two** channels (the loop ends at base + 0x380), those whose +0x94 is the track or is negative, or both for a negative track; level = `[0x103889F0 + 4 x volume]` << 12 at +0x4C, in fade x 50 / 60 steps |
| 10, 11 | 0x1024B8F0, 0x1024B920 | write / clear entries of the 1024-entry table `[0x106690BC]` |
| 12 | 0x1024B960 | `[0x106690EC]` = argument x the float at 0x10330250 |
| 1, 2, 3, 5, 6, 9, 13 | 0x1024AB50, 0x1024AB80, 0x1024AE50, 0x1024AD00, 0x1024AF80, 0x1024B4E0, 0x1024B580 | **not read** |

So the effects' sounds and the scheduled track play on the 20 channels (command 4) and the music on the stream
channels (commands 7 and 8); both commands turn a volume 0..127 into a level through the one 128-entry table at
0x103889F0. What plays on the third stream channel, which command 8 does not reach: **not read**.

**The repo's name "LobbyThread" for this unit is from low- and medium-confidence evidence (data/names/
316_unit_10244EA0_LobbyThread.json); everything that writes the ring is sound or music, and none of it is in the
security set (data/security_set.json).** From what the reader does it is the sound thread's command queue; the names
stay until the unit is renamed with the naming pipeline.

## 5. What a mod uses

- Scale a category of 2: hook its setter and scale the level (they read registers their declarations do not carry:
  manifest flag 8; sdk/examples/audio_mix.cpp's stubs keep every register). Re-apply: call the setter again with the
  game's last level.
- Scale the music: scale the volume in `LobbyThread_SendCmd8` (track -1) and `Music_LoadTrackIfRunning`, where every
  music volume ends whichever setting wrote the factors (audio_mix.cpp since 25 Nov). Re-apply: send the game's last
  command-8 volume again. Never above 127 (the & 0x7F): above the game's full volume it cannot go louder through the
  commands; louder would mean changing the level table at 0x103889F0, which every sound shares.

## 6. Not known

- Which options in the game's menus settings 9, 10 and 0xA8 are; who calls 0x1007F680.
- Commands 1, 2, 3, 5, 6, 9, 13; which thread runs the reader; how the level table's values reach the mixer (the
  sound device's own volume).
