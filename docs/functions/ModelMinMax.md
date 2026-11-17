# ModelMinMax

Group: `Model` (by the file name only). Source: `sdk/tree_src/ModelMinMax.cpp`.

Why the file has this name (data/unit_names.json): ComputeMinMax; called from StAvatar_InitEntry

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ModelMinMax_ComputeMinMax` | 0x1026FBB0 | 165 | yes | - | Computes the minimum and maximum bounds over all entries and returns 0 when any entry was found. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ModelMinMax_ComputeMinMax` calls `SqBounds_Reset`, `Mdl_ComputeSlotBounds`
