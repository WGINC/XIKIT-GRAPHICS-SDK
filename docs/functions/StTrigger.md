# StTrigger

Group: `St` (by the file name only). Source: `sdk/tree_src/StTrigger.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `StTrigger_ProcessOpcodesUpToTime` | 0x10252CC0 | 476 | yes | - | - | - |
| `StTrigger_FindIndexAtLeast` | 0x10252EA0 | 95 | yes | - | Finds the first trigger entry whose key is at least a given value. | low |
| `StTrigger_RegisterCallbacks` | 0x10252F00 | 103 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `StTrigger_ProcessOpcodesUpToTime` calls `sqopOpcodeGet`, `sub_10311FF1`, `CMoResource::FindByTypeAndId`, `SoundVolume_SetVolumeScalar`, `SoundVolume_CreateSoundElem`, `sqopTrackAdvance`
- `StTrigger_FindIndexAtLeast` calls nothing directly
- `StTrigger_RegisterCallbacks` calls `TextInputFiles_FileMngQueueFileNumKind2`, `ErrorReport_NoOpVarargsA`
