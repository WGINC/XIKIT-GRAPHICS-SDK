# SoundVolume

Group: `Sound` (by the file name only). Source: `sdk/tree_src/SoundVolume.cpp`.

Why the file has this name (data/unit_names.json): SetVolumeScalar, SetVolumeVector, CreateSoundElem; calls Music_SetTrackVolume and the stream thread (PushCmd)

5 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SoundVolume_SendStopToLobby` | 0x10036B90 | 71 | yes | - | Sends command 0 for the object's id to the lobby thread and clears a flag for two ids. | low |
| `SoundVolume_ComputeDistanceVolumeAndPan` | 0x10036C70 | 647 | yes | - | Works out a sound's volume from its distance to the camera's target and its left-right pan (0 to 127, 64 centre) from where it is in view. | medium |
| `SoundVolume_SetVolumeScalar` | 0x10036F00 | 65 | yes | - | Sets a music track's volume from one value through the vector form 0x10036F50. | medium |
| `SoundVolume_SetVolumeVector` | 0x10036F50 | 76 | yes | - | Applies a volume vector to the object's sound when sound is active. | low |
| `SoundVolume_CreateSoundElem` | 0x10037020 | 170 | yes | - | Creates a sound element under this object with a position and its parameters. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SoundVolume_SendStopToLobby` calls `LobbyThread_SendCmd0`
- `SoundVolume_ComputeDistanceVolumeAndPan` calls `Camera_GetField50`, `sub_10027530`, `sub_10311C2C`, `Camera_GetViewMatrixPtr`, `Mat4_TransformPoint`, `Camera_GetField2F4`
- `SoundVolume_SetVolumeScalar` calls `SoundVolume_SetVolumeVector`
- `SoundVolume_SetVolumeVector` calls `SoundElem_AddUniqueId`, `MusicFont_QueueSoundCmdIfChannelsBelowLimit`
- `SoundVolume_CreateSoundElem` calls `Mem_AllocWithFallback`, `CYySoundElem::Constructor`, `sub_10071E90`
