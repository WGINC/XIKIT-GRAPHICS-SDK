# sqshDispList

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqshDispList.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqshDispList_Create` | 0x102A2000 | 32 | yes | - | Allocates and initialises a display-list shape record. | medium |
| `SqshDispList_Init` | 0x102A2020 | 75 | yes | - | Initialises a display-list shape record and its function table. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqshDispList_Create` calls `SqMem_AllocZeroed`, `SqshDispList_Init`
- `SqshDispList_Init` calls `SqBounds_Reset`
