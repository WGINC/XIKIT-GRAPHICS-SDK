# MusicFont

Group: `Music` (by the file name only). Source: `sdk/tree_src/MusicFont.cpp`.

Why the file has this name (data/unit_names.json): Music_SetTrackVolume, MusicTrack_SetVolumeId*, and Font_DrawString / Font_QueueText / Font_DrawPass

17 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SetMusicTrackVolume_C` | 0x10037B30 | 90 | yes | - | - | - |
| `SetMusicTrackVolume_A` | 0x10037B90 | 90 | yes | - | - | - |
| `SetMusicTrackVolume_B` | 0x10037BF0 | 90 | yes | - | - | - |
| `SetMusicTrackVolume_Tag0004` | 0x10037C50 | 90 | yes | - | Sets the level of the type-0x3D resource tagged '0004' from the value at 0x10351700, as DancingMad's SetMusicTrackVolume_A does for its tag. | medium |
| `MusicTrack_SetVolumeId0009` | 0x10037D70 | 90 | yes | - | Sets the volume of the music track with resource id 0009. | low |
| `MusicTrack_SetVolumeId0010` | 0x10037DD0 | 90 | yes | - | Sets the volume of the music track with resource id 0010. | low |
| `MusicTrack_SetVolumeId0011` | 0x10037E30 | 90 | yes | - | Sets the volume of the music track with resource id 0011. | low |
| `MusicTrack_SetVolumeId0013` | 0x10037E90 | 90 | yes | - | Sets the volume of the music track with resource id 0013. | low |
| `MusicTrack_SetVolumeId0016` | 0x10037FB0 | 90 | yes | - | Sets the volume of the music track with resource id 0016. | low |
| `MusicFont_Create` | 0x100380F0 | 216 | yes | - | Creates the music track task for a resource and sets its volume. | medium |
| `Music_LoadTrackIfRunning` | 0x100382A0 | 28 | yes | - | Asks for a music track when the sound thread runs. | low |
| `MusicFont_QueueSoundCmdIfChannelsBelowLimit` | 0x10038330 | 163 | yes | - | Queues a sound command with a clamped 0..127 value when fewer channels than the limit are active; -1 otherwise. | medium |
| `LobbyThread_SendCmd3FromFloat` | 0x10038440 | 42 | yes | - | Sends command 3 to the lobby thread with the float argument rounded to an integer, when the thread flag at 0x1046393C is set. | low |
| `Music_SetTrackVolume` | 0x10038470 | 55 | yes | - | Sets a music channel's volume (0-127). | medium |
| `Font_QueueText` | 0x100384B0 | 110 | yes | - | - | - |
| `Font_DrawPass` | 0x10038520 | 507 | yes | 0 | - | - |
| `Font_DrawString` | 0x10038720 | 502 | yes | 0 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SetMusicTrackVolume_C` calls `CMoResource::FindByTypeAndId`, `sub_10311C2C`, `SoundVolume_SetVolumeScalar`
- `SetMusicTrackVolume_A` calls `CMoResource::FindByTypeAndId`, `sub_10311C2C`, `SoundVolume_SetVolumeScalar`
- `SetMusicTrackVolume_B` calls `CMoResource::FindByTypeAndId`, `sub_10311C2C`, `SoundVolume_SetVolumeScalar`
- `SetMusicTrackVolume_Tag0004` calls `CMoResource::FindByTypeAndId`, `sub_10311C2C`, `SoundVolume_SetVolumeScalar`
- `MusicTrack_SetVolumeId0009` calls `CMoResource::FindByTypeAndId`, `sub_10311C2C`, `SoundVolume_SetVolumeScalar`
- `MusicTrack_SetVolumeId0010` calls `CMoResource::FindByTypeAndId`, `sub_10311C2C`, `SoundVolume_SetVolumeScalar`
- `MusicTrack_SetVolumeId0011` calls `CMoResource::FindByTypeAndId`, `sub_10311C2C`, `SoundVolume_SetVolumeScalar`
- `MusicTrack_SetVolumeId0013` calls `CMoResource::FindByTypeAndId`, `sub_10311C2C`, `SoundVolume_SetVolumeScalar`
- `MusicTrack_SetVolumeId0016` calls `CMoResource::FindByTypeAndId`, `sub_10311C2C`, `SoundVolume_SetVolumeScalar`
- `MusicFont_Create` calls `Mem_AllocFromArea`, `CMoTask::ResetFields`, `CMoTask::Constructor`, `CMoResource::FindByTypeAndId`, `sub_10311C2C`, `SoundVolume_SetVolumeScalar`
- `Music_LoadTrackIfRunning` calls `LobbyThread_QueueMusicFile`
- `MusicFont_QueueSoundCmdIfChannelsBelowLimit` calls `Acter_IsEvent`, `LobbyThread_QueryChannels`, `sub_10311C2C`, `LobbyThread_QueueSoundCmd`
- `LobbyThread_SendCmd3FromFloat` calls `sub_10311C2C`, `LobbyThread_SendCmd3`
- `Music_SetTrackVolume` calls `LobbyThread_SendCmd4`
- `Font_QueueText` calls nothing directly
- `Font_DrawPass` calls `Font_BindGlyphTexture`, `Font_DrawString`
- `Font_DrawString` calls `sub_10311C2C`, `Font_DecodeNextChar`, `Font_AddGlyphAdvance`, `CDx::DrawPrimitiveUP`
