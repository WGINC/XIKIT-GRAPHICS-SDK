# SqBounds

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqBounds.cpp`.

Why the file has this name (data/unit_names.json): ComputeBounds, GetCenter, SumAxis; called from the sqsh meshes

5 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqBounds_SumAxis` | 0x1028D990 | 11 | yes | - | Returns the sum of two bounds fields. | low |
| `SqBounds_Reset` | 0x1028D9A0 | 32 | yes | - | Resets a bounding box to empty (inverted extremes). | medium |
| `SqBounds_Copy` | 0x1028D9C0 | 43 | yes | - | Copies a bounding box. | medium |
| `SqBounds_ComputeBounds` | 0x1028DA20 | 286 | yes | - | Computes an axis-aligned bounding box (min and max corners) over a vertex array, sampling at most about 64 points. | medium |
| `SqBounds_GetCenter` | 0x1028DBB0 | 71 | yes | - | Returns the centre of a bounding box. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqBounds_SumAxis` calls nothing directly
- `SqBounds_Reset` calls nothing directly
- `SqBounds_Copy` calls nothing directly
- `SqBounds_ComputeBounds` calls nothing directly
- `SqBounds_GetCenter` calls nothing directly
