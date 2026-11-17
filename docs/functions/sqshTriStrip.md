# sqshTriStrip

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqshTriStrip.cpp`.

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqshTriStrip_Create` | 0x102AA2D0 | 32 | yes | - | Creates a sqshTriStrip object. | medium |
| `SqshTriStrip_Init` | 0x102AA2F0 | 107 | yes | - | Initialises a sqshTriStrip object. | medium |
| `SqshTriStrip_GetGlobal` | 0x102ABEB0 | 6 | yes | - | Returns the value of a global shape-strip setting. | low |
| `SqshTriStrip_ForEachTriangle` | 0x102ABEC0 | 254 | yes | - | Visits every triangle of a tristrip shape's index groups (lists and strips), calling a callback for each and counting them. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqshTriStrip_Create` calls `SqMem_AllocZeroed`, `SqshTriStrip_Init`
- `SqshTriStrip_Init` calls `SqBounds_Reset`
- `SqshTriStrip_GetGlobal` calls nothing directly
- `SqshTriStrip_ForEachTriangle` calls nothing directly
