> Paths in this document are the development repository's: tree/src/ is sdk/tree_src/ here, kit/xikit/ and kit/d3d8on11/ are src/xikit/ and src/d3d8on11/, sdk/examples/ is sdk/examples/; docs/HISTORY.md and kit/sessions/ are not published.

# The game's sound volumes: categories, factors, the music track

How FFXiMain.dll sets the volume of each kind of sound, read from its code (analysed build 6A995428). Sources: the
tree's C (tree/src/SoundElem.cpp, tree/src/MusicFont.cpp, tree/src/TextInputFiles.cpp) and the disassembly of the
unpacked DLL where the tree has no source. **Not known** marks what is not read.

## 1. The two configured factors

`[0x103516FC]` and `[0x103516F8]` (floats) are the game's configured volumes: `SoundElem_SetFactor103516FC` and
`SoundElem_SetFactor103516F8` write them, called from `TextInputFiles_ApplyConfigSetting` (0x101AA650,
tree/src/TextInputFiles.cpp:6811) when a setting changes; after writing, each calls the four setters below with level
1.0 (tree/src/SoundElem.cpp:12-15 and :26-29). The sound system's start (0x100355F0) sets both
to 1.0. Which of the game's options is which factor: **not read**.

## 2. The categories and their setters

| Category | Value | Setter | Who reads it |
|---|---|---|---|
| interface | float at 0x10351700 | `SoundElem_SetScaled10351700` (0x100360A0): factor x factor x level | the menu and target sounds (`MusicTrack_SetVolumeId0009` and its siblings; their callers `Target_Select`, `Target_ApplyAction`, `NetCellFont_MenuMoveSelection`, ...) |
| effects | float at 0x10351704 | `SoundElem_SetScaled10351704` (0x10036050) | `CYySoundElem::UpdateTimerAndPosition`: the effect elements' sounds |
| ambient | float at 0x10351708, and the zone loop's track | `SoundElem_SetScaled10351708` (0x10035FB0): also sends the track's volume through 0x10038470 | the zone's looped sound (`SoundElem_SetCurrent10463914`, from XiZone) |
| music | the music track `[0x10463920]` | `Music_ApplyVolume` (0x100360F0) | the sound thread (4) |

The level argument comes from the volume-change tasks (`CMoVolumeChangeTask`) or the 1.0 of a settings change.

## 3. The music path (disassembly of 0x100360F0 and 0x10038470)

`Music_ApplyVolume(float level)`: v = [0x103516FC] x [0x103516F8] x level x 127.0 (the float at 0x1032A34C). If music
is on (byte 0x104638F5): with level > 0.0 (0x103295D8) it calls 0x10038470(track [0x10463920], (int)v, 0); with
level 0 it sends command 0 (stop) for [0x1046391C], [0x10463920] when the sound thread exists ([0x1046393C]). It then
sets the byte 0x10463909.

0x10038470(track, volume, third): returns at once for a negative track; **clamps the volume to 0..127**; when the
sound thread exists, queues command 4 (track, volume & 0x7F, third). So the music can be lowered from the game's
level but not raised above 127; at the game's full volume v is already 127 (sdk/examples/audio_mix.cpp stops its
music setting at 100 for this).

The track is chosen by 0x10035B00 (which then calls `Music_ApplyVolume`); 0x100355F0 resets it at the start. In the
game's code read, every music volume goes through `Music_ApplyVolume`. 0x10036C10 also sets a track's volume directly
(as given), but nothing calls it and no pointer to it is in the game's data: as far as read, it is not used.

## 4. The sound thread's command ring

0x1024C060 writes 32-byte records {command, 7 arguments} into the 0x2000-byte ring at 0x106690E8 (write pointer
0x106690C4, read pointer 0x106690F0), refusing when full; command 7 also copies 8 more blocks. Its callers queue
music files, sound commands, stream files, volumes and stops (the functions named `LobbyThread_SendCmd0/3/4/6/8/9/11`,
`LobbyThread_QueueMusicFile`, `LobbyThread_QueueSoundCmd`, `LobbyThread_QueueStreamFile`); 0x1024B990 and 0x1024C170
read it. **The repo's name "LobbyThread" for this unit is from low- and medium-confidence evidence (data/names/
316_unit_10244EA0_LobbyThread.json); everything that writes the ring is sound or music, and none of it is in the
security set (data/security_set.json).** A better name, from what the reader does: not given until the reader is read.

## 5. What a mod uses

- Scale a category: hook its setter and scale the level (they read registers their declarations do not carry:
  manifest flag 8; sdk/examples/audio_mix.cpp's stubs keep every register).
- Re-apply after a change: call each setter again with the game's last level.
- Music above the game's level: not possible through the track volume (the clamp); it would need the mixer's own
  volume, which is **not read**.
