# sqmdSort

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqmdSort.cpp`.

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqmdSort_Create` | 0x1029B100 | 32 | yes | - | Allocates a Squirrel sort object and initialises it. | medium |
| `SqmdSort_Init` | 0x1029B120 | 69 | yes | - | Sets the sort object's type code, callbacks and defaults. | medium |
| `SqmdSort_AllocLists` | 0x1029B310 | 133 | yes | - | Allocates the sort lists a model's data describes. | medium |
| `SqmdSort_CreateForStrips` | 0x1029B3A0 | 111 | yes | - | Creates a triangle-strip sort updater for a shape. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqmdSort_Create` calls `sub_10275D80`, `SqmdSort_Init`
- `SqmdSort_Init` calls nothing directly
- `SqmdSort_AllocLists` calls `sub_10275D80`
- `SqmdSort_CreateForStrips` calls `sqDebugPrintf`, `SqmdSort_Create`, `SqmdSort_AllocLists`
