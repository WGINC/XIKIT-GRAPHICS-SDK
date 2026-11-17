# sqVtx

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqVtx.cpp`.

6 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqVtx_Create` | 0x102A9520 | 35 | yes | - | Allocates and initialises a vertex record. | medium |
| `SqVtx_Init` | 0x102A9550 | 62 | yes | - | Initialises a vertex record and sets its function table. | medium |
| `SqVtx_AllocateField` | 0x102A9980 | 97 | yes | - | Allocates one field (slot) of a vertex buffer. | high |
| `SqVtx_ClearEntries` | 0x102A9EF0 | 63 | yes | - | Clears the vertex entries of the first table. | low |
| `SqVtx_ClearEntriesAlt` | 0x102A9F30 | 63 | yes | - | Clears the vertex entries of the second table. | low |
| `SqVtx_PackFloatsToBytes` | 0x102A9FB0 | 228 | yes | - | Packs float channel values into bytes and replaces the stored buffer. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqVtx_Create` calls `SqMem_AllocZeroed`, `SqVtx_Init`
- `SqVtx_Init` calls nothing directly
- `SqVtx_AllocateField` calls `sqDebugPrintf`, `SqMem_AllocZeroed`
- `SqVtx_ClearEntries` calls `SqVtx_AllocateField`
- `SqVtx_ClearEntriesAlt` calls `SqVtx_AllocateField`
- `SqVtx_PackFloatsToBytes` calls `sub_10275D80`, `sub_10311C2C`, `sqFree`
