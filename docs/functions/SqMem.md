# SqMem

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqMem.cpp`.

Why the file has this name (data/unit_names.json): sqMemInit, sqFree, SqMem_*: the dancer libraries' memory

12 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `sqMemInit` | 0x10275150 | 50 | yes | - | - | - |
| `SqMem_InitBlock` | 0x10275190 | 21 | yes | - | Clears the fields of a memory block record. | low |
| `SqMem_ClassifyBlock` | 0x102752F0 | 46 | yes | - | Classifies an allocation by its signature word. | low |
| `SqMem_GetPayloadEnd` | 0x10275320 | 12 | yes | - | Returns the end address of a block's payload. | low |
| `SqMem_Check` | 0x10275510 | 163 | yes | - | sqMemCheck: walks the current memory pool and prints every corrupt block, or 'Memory check successful'. | high |
| `SqMem_HexDump` | 0x102755C0 | 80 | yes | - | Prints a memory range as a hex dump. | medium |
| `SqMem_FindArena` | 0x10275670 | 33 | yes | - | Finds the arena that contains an address. | low |
| `sqMemPoolRegister` | 0x10275B60 | 173 | yes | - | - | - |
| `SqMem_PrintPools` | 0x10275CC0 | 114 | yes | - | Prints name, size, head, lo and hi of each of the 8 memory pools, marking the current one. | high |
| `SqMem_AllocZeroed` | 0x10275D40 | 64 | yes | - | Allocates a zeroed block of count times size bytes. | medium |
| `SqMem_Realloc` | 0x10275E90 | 602 | yes | - | sqRealloc: resizes a pool block (in place when it is the last block), allocating when the pointer is null. | high |
| `sqFree` | 0x102760F0 | 356 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `sqMemInit` calls `SqMem_InitBlock`
- `SqMem_InitBlock` calls nothing directly
- `SqMem_ClassifyBlock` calls nothing directly
- `SqMem_GetPayloadEnd` calls nothing directly
- `SqMem_Check` calls `sqDebugPrintf`, `SqMem_ClassifyBlock`, `game_102756A0`, `SqMem_GetPayloadEnd`
- `SqMem_HexDump` calls `game_102756A0`, `sqDebugPrintf`
- `SqMem_FindArena` calls nothing directly
- `sqMemPoolRegister` calls `sqDebugPrintf`, `game_10311FF1`
- `SqMem_PrintPools` calls `sqDebugPrintf`
- `SqMem_AllocZeroed` calls `game_10275D80`
- `SqMem_Realloc` calls `game_10275D80`, `SqMem_FindArena`, `sqDebugPrintf`, `SqMem_ClassifyBlock`, `SqMem_Check`, `SqMem_HexDump`, `game_102751D0`, `sqFree`
- `sqFree` calls `sqDebugPrintf`, `SqMem_ClassifyBlock`, `SqMem_HexDump`, `SqMem_FindArena`, `SqMem_GetPayloadEnd`
