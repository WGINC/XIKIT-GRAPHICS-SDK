# RabRes

Group: `Rab` (by the file name only). Source: `sdk/tree_src/RabRes.cpp`.

Why the file has this name (data/unit_names.json): CMoRabRes and CMoResource runtime classes

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `RabRes_MinOf10055F60OverIndexPairs` | 0x10056160 | 189 | yes | - | Returns the smallest value 0x10055F60 gives over the object's index pairs, and the point it gave with it. | low |
| `CMoRabRes_GetRuntimeClass` | 0x10056260 | 6 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `RabRes_MinOf10055F60OverIndexPairs` calls `sub_10055F60`
- `CMoRabRes_GetRuntimeClass` calls nothing directly
