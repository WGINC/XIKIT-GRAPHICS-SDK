# SqShadowVolumeDraw

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqShadowVolumeDraw.cpp`.

Why the file has this name (data/unit_names.json): sqsnShadowVolumeDraw

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqShadowVolumeDraw_CopyBounds` | 0x102A2130 | 42 | yes | - | Copies a layer's bounding box and runs its follow-up step. | low |
| `SqShadowVolumeDraw_ContainsInt` | 0x102A2160 | 44 | yes | - | Tests whether a value is in a list. | low |
| `SqShadowVolumeDraw_ContainsInAnyEntry` | 0x102A2190 | 66 | yes | - | Tests whether a value appears in any of a layer's lists. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqShadowVolumeDraw_CopyBounds` calls `SqBounds_Copy`, `SqgxDlist_Nop`
- `SqShadowVolumeDraw_ContainsInt` calls nothing directly
- `SqShadowVolumeDraw_ContainsInAnyEntry` calls `SqShadowVolumeDraw_ContainsInt`
