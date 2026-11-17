# sqmoBuild

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqmoBuild.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqmoBuild_ReadFrameChannel` | 0x102851C0 | 288 | yes | - | Reads a frame channel from a motion stream. | medium |
| `SqmoBuild_ReadKeyChannel` | 0x102852E0 | 260 | yes | - | Reads a key channel from a motion stream. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqmoBuild_ReadFrameChannel` calls `SqScriptRead_ReadBlock`, `sqDebugPrintf`, `SqmoFrameChannel_Create`, `SqMem_AllocZeroed`, `SqmoFrameChannel_Apply`
- `SqmoBuild_ReadKeyChannel` calls `SqScriptRead_ReadBlock`, `sqDebugPrintf`, `SqmoKeyChannel_Create`, `SqMem_AllocZeroed`
