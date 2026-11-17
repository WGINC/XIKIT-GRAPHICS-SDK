# SoundElem

Group: `Sound` (by the file name only). Source: `sdk/tree_src/SoundElem.cpp`.

Why the file has this name (data/unit_names.json): CYySoundElem::* (the sound queue, UpdateFromCamera), CMoTask::CreateMode*

15 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SoundElem_SetFactor103516F8` | 0x10035E80 | 55 | yes | - | Sets the first of the two factors the sound and music volumes are scaled by, and applies them again. | medium |
| `SoundElem_SetFactor103516FC` | 0x10035EC0 | 55 | yes | - | Sets the second of the two factors the sound and music volumes are scaled by, and applies them again. | medium |
| `MoTask_KillAllGlobalSlots` | 0x10035F00 | 128 | yes | - | - | - |
| `SoundElem_ClearGlobal10463930` | 0x10035F80 | 40 | yes | - | Calls a method on the object held in global 0x10463930, clears that global, then calls fn_10035FB0. | low |
| `SoundElem_SetScaled10351708` | 0x10035FB0 | 97 | yes | - | Stores its scaled float argument in global 0x10351708 and, when a current object exists and the value changed, passes the new value to its handle. | low |
| `SoundElem_Release10463928AndSetScaled` | 0x10036020 | 40 | yes | - | Releases the object at 0x10463928 and passes the argument to Unit10035B00_SetScaled10351704. | low |
| `SoundElem_SetScaled10351704` | 0x10036050 | 23 | yes | - | Stores its argument, scaled by two constants, in global 0x10351704. | low |
| `MoTask_KillGlobalSlot1` | 0x10036070 | 40 | yes | - | - | - |
| `SoundElem_SetScaled10351700` | 0x100360A0 | 23 | yes | - | Stores its argument, scaled by two constants, in global 0x10351700. | low |
| `SoundElem_ClearGlobal10463934` | 0x100360C0 | 40 | yes | - | Calls a method on the object held in global 0x10463934, clears that global, then calls fn_100360F0. | low |
| `Music_ApplyVolume` | 0x100360F0 | 125 | yes | - | Sets the current music track's volume by a factor, or stops it at 0. | low |
| `SoundElem_SetCurrent10463914` | 0x10036170 | 95 | yes | - | Replaces the object held in global 0x10463914: a zero argument releases the current one, a new pointer becomes the current one with a companion value at 0x10463910. | low |
| `SoundElem_ResetGlobals` | 0x100361D0 | 28 | yes | - | Zeroes the five globals 0x10463910 to 0x10463920 that hold the current object and its companion state. | medium |
| `SoundElem_AddUniqueId` | 0x10036460 | 57 | yes | - | Adds an id to a 20-entry list unless it is there. | low |
| `CYySoundElem_IsHandleInFrameList` | 0x100367F0 | 40 | yes | - | Searches the frame's handle array at 0x10462590 for the argument and returns whether it is present. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SoundElem_SetFactor103516F8` calls `SoundElem_SetScaled10351708`, `SoundElem_SetScaled10351704`, `SoundElem_SetScaled10351700`, `Music_ApplyVolume`
- `SoundElem_SetFactor103516FC` calls `SoundElem_SetScaled10351708`, `SoundElem_SetScaled10351704`, `SoundElem_SetScaled10351700`, `Music_ApplyVolume`
- `MoTask_KillAllGlobalSlots` calls `SoundElem_Release10463928AndSetScaled`, `SoundElem_ClearGlobal10463930`, `MoTask_KillGlobalSlot1`, `SoundElem_ClearGlobal10463934`
- `SoundElem_ClearGlobal10463930` calls `SoundElem_SetScaled10351708`
- `SoundElem_SetScaled10351708` calls `sub_10311C2C`, `Music_SetTrackVolume`
- `SoundElem_Release10463928AndSetScaled` calls `SoundElem_SetScaled10351704`
- `SoundElem_SetScaled10351704` calls nothing directly
- `MoTask_KillGlobalSlot1` calls `SoundElem_SetScaled10351700`
- `SoundElem_SetScaled10351700` calls nothing directly
- `SoundElem_ClearGlobal10463934` calls `Music_ApplyVolume`
- `Music_ApplyVolume` calls `LobbyThread_SendCmd0`, `sub_10311C2C`, `Music_SetTrackVolume`
- `SoundElem_SetCurrent10463914` calls `SoundVolume_SendStopToLobby`, `sub_10311C2C`, `SoundVolume_SetVolumeScalar`
- `SoundElem_ResetGlobals` calls nothing directly
- `SoundElem_AddUniqueId` calls nothing directly
- `CYySoundElem_IsHandleInFrameList` calls nothing directly
