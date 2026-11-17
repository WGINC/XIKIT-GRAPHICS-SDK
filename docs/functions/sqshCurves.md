# sqshCurves

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqshCurves.cpp`.

5 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqshCurves_Create` | 0x102ACF20 | 32 | yes | - | Creates and initialises a new sqshCurves object. | medium |
| `SqshCurves_Init` | 0x102ACF40 | 109 | yes | - | Initialises a sqshCurves object's header, callbacks and default fields. | medium |
| `SqshCurves_ComputeNormals` | 0x102AD1D0 | 226 | yes | - | Computes a curve shape's normals. | high |
| `SqshCurves_ComputeTangents` | 0x102AD770 | 469 | yes | - | Computes each curve's per-point tangents from its control vertices. | high |
| `SqshCurves_RebuildIndex` | 0x102AD990 | 155 | yes | - | Rebuilds the curve index array from the largest value in its source array. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqshCurves_Create` calls `SqMem_AllocZeroed`, `SqshCurves_Init`
- `SqshCurves_Init` calls `SqBounds_Reset`
- `SqshCurves_ComputeNormals` calls `sqDebugPrintf`
- `SqshCurves_ComputeTangents` calls `sqDebugPrintf`, `SqVec_Sub`, `SqVec_ScaleVec3ByInverseOf102746C0`
- `SqshCurves_RebuildIndex` calls `sqFree`, `SqMem_AllocZeroed`, `SqVtx_ClearEntries`, `SqshCurves_ComputeNormals`, `SqVtx_ClearEntriesAlt`, `SqshCurves_ComputeTangents`
