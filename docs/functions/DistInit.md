# DistInit

Group: `Dist` (by the file name only). Source: `sdk/tree_src/DistInit.cpp`.

Why the file has this name (data/unit_names.json): CMoDist::Init; called from the generator code

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `DistInit_ReturnOne` | 0x10052D20 | 7 | yes | - | Returns 1.0. | low |
| `DistInit_ReturnSelf` | 0x10052D30 | 3 | yes | - | Returns its object. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `DistInit_ReturnOne` calls nothing directly
- `DistInit_ReturnSelf` calls nothing directly
