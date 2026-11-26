# chn

Group: `chn` (by the file name only). Source: `sdk/tree_src/chn.cpp`.

6 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Chn_ReleaseRefs` | 0x1027DB80 | 96 | yes | - | Releases the channel's referenced sub-objects. | low |
| `Chn_RegisterItem` | 0x1027DCC0 | 160 | yes | - | Registers a channel item and fills its record. | medium |
| `Chn_ForwardIfFlag2` | 0x1027DD70 | 19 | yes | - | Forwards to a handler when the channel's flag 2 is set. | low |
| `Chn_GetSubIndex` | 0x1027DF70 | 39 | yes | - | Returns the sub-index of a typed object, or -1. | low |
| `Chn_InitDefaults` | 0x1027E060 | 59 | yes | - | Sets the channel's default values. | low |
| `Chn_ReleaseIfSet` | 0x1027E0D0 | 21 | yes | - | Releases the channel's +0x1C resource when it is set. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Chn_ReleaseRefs` calls `SqObject_Release`
- `Chn_RegisterItem` calls `SqTimer_GetMicroseconds`, `SqChannelMotion_CreateWithOwner`, `SqgxVertexShaderRelease_GetFloat20`, `game_10312050`, `SqBounds_SumAxis`, `Chn_GetSubIndex`
- `Chn_ForwardIfFlag2` calls `game_1027DD90`
- `Chn_GetSubIndex` calls nothing directly
- `Chn_InitDefaults` calls `SqcoConnector_Init`
- `Chn_ReleaseIfSet` calls `SqMatrixConnect_ReleaseConnection`
