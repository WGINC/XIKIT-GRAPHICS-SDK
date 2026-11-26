# StChannel

Group: `St` (by the file name only). Source: `sdk/tree_src/StChannel.cpp`.

7 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `StChannelItemResolve` | 0x10250F10 | 268 | yes | - | - | - |
| `StChannel_RegisterItem` | 0x10251070 | 230 | yes | - | Registers a channel item in the model entry table and starts it at a time. | medium |
| `StChannel_ClearFlags` | 0x10251160 | 21 | yes | - | Clears the channel's flag bits and sets its index to -1. | low |
| `StChannel_MarkIfLoaded` | 0x10251180 | 43 | yes | - | Sets the channel's loaded flag when its file index resolves. | low |
| `StChannel_SetValue9C` | 0x102511B0 | 68 | yes | - | Stores a float in the channel's table entry at index*0xC0+0x9C. | low |
| `StChannel_ApplyItem` | 0x10251200 | 165 | yes | - | Applies a registered channel item once, guarding against re-entry. | low |
| `StChannelItemClear` | 0x102512B0 | 101 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `StChannelItemResolve` calls `ErrorReport_NoOpVarargsA`, `SqTimer_GetMicroseconds`, `TextInputFiles_FileMngReleaseAt1F0`, `sqmoChannelBuildSQO`, `TextInputFiles_FileMngGetValueAt1F0`, `game_10251020`, `sqFree`, `SqgxVertexShaderRelease_GetFloat20`
- `StChannel_RegisterItem` calls `ErrorReport_NoOpVarargsA`, `Mdl_ChannelRegister`, `Mdl_UpdateEntryFlags`, `game_1026F080`, `game_1026EFB0`, `Mdl_GetEntryTable`, `game_10311C2C`
- `StChannel_ClearFlags` calls nothing directly
- `StChannel_MarkIfLoaded` calls `TextInputFiles_FileMngFindFileNumKind2`
- `StChannel_SetValue9C` calls `Mdl_GetEntryTable`
- `StChannel_ApplyItem` calls `Mdl_GetEntryTable`, `Chn_ForwardIfFlag2`, `SqDebug_GetFlagByte14`, `SqDebug_SetByte14`, `SqDebug_InvokeCallback18`
- `StChannelItemClear` calls `SqObject_Release`, `sqFree`
