# StAvatar

Group: `St` (by the file name only). Source: `sdk/tree_src/StAvatar.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `StAvatar_Teardown` | 0x1024D180 | 312 | yes | 6 | - | - |
| `StAvatar_ReleaseResources` | 0x1024D2C0 | 308 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `StAvatar_Teardown` calls `StAvatar_SetPending`, `StAvatar_StopAndFreeBuffers`, `StAvatar_SetStopped`, `StAvatar_Reset`, `StAvatar_ReleaseResources`, `StAvatar_RegisterTriggers`, `StAvatar_SwitchMusicTask`, `StAvatar_SetTableValues`, `StModelItem_ReadStart`, `StAvatar_SetChannel`
- `StAvatar_ReleaseResources` calls `StModelItem_ClearModelItem`, `StChannelItemClear`, `StAvatar_ClearResource`, `sqFree`
