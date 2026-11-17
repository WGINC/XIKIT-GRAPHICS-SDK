# ModelCodeIndex

Group: `Model` (by the file name only). Source: `sdk/tree_src/ModelCodeIndex.cpp`.

Why the file has this name (data/unit_names.json): MapCodeIndex, AddOffset*: read from the code

5 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ModelCodeIndex_MapCodeIndex` | 0x100C51C0 | 142 | yes | - | Maps a code and index to a table offset. | low |
| `ModelCodeIndex_AddOffset996B` | 0x100C5260 | 10 | yes | - | Adds 0x996B to its argument. | low |
| `ModelCodeIndex_AddOffset19131` | 0x100C5270 | 10 | yes | - | Adds 0x19131 to its argument. | low |
| `ModelCodeIndex_AddOffset1889B` | 0x100C5280 | 10 | yes | - | Adds 0x1889B to its argument. | low |
| `ModelCodeIndex_ForwardToCce00` | 0x100C5290 | 5 | yes | - | Forwards its argument to FUN_101cce00. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ModelCodeIndex_MapCodeIndex` calls `ModelCodeIndex_AddOffset996B`, `ModelCodeIndex_ForwardToCce00`, `ModelCodeIndex_AddOffset1889B`, `ModelCodeIndex_AddOffset19131`
- `ModelCodeIndex_AddOffset996B` calls nothing directly
- `ModelCodeIndex_AddOffset19131` calls nothing directly
- `ModelCodeIndex_AddOffset1889B` calls nothing directly
- `ModelCodeIndex_ForwardToCce00` calls `Yk_MapCodeOffset`
