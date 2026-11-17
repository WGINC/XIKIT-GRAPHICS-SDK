# sqshPoints

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqshPoints.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqshPoints_Create` | 0x102ACB60 | 32 | yes | - | Allocates a Squirrel points-shape object and initialises it. | medium |
| `SqshPoints_Init` | 0x102ACB80 | 74 | yes | - | Sets the points shape's type code, callbacks and defaults. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqshPoints_Create` calls `SqMem_AllocZeroed`, `SqshPoints_Init`
- `SqshPoints_Init` calls `SqBounds_Reset`
