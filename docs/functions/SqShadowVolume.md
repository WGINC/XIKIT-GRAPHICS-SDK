# SqShadowVolume

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqShadowVolume.cpp`.

Why the file has this name (data/unit_names.json): sqsnShadowVolumeBeginVB / SetPass, sqgxShadowPlaneMatrix, sqgxShadowStencilEnable

5 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqgxContext_SetCotHalfAngle` | 0x102972D0 | 32 | yes | - | Stores the cotangent of half an angle given in degrees in the rendering context. | medium |
| `sqsnShadowVolumeSetPass` | 0x10297CC0 | 505 | yes | 0 | - | - |
| `sqgxShadowStencilEnable` | 0x10297EC0 | 196 | yes | 0 | - | - |
| `sqsnShadowVolumeBeginVB` | 0x102981E0 | 180 | yes | 0 | - | - |
| `sqgxShadowPlaneMatrix` | 0x10298350 | 344 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqgxContext_SetCotHalfAngle` calls nothing directly
- `sqsnShadowVolumeSetPass` calls `sqgxZMask`, `sqgxFBMask`
- `sqgxShadowStencilEnable` calls `sqgxZMask`
- `sqsnShadowVolumeBeginVB` calls `sqDebugPrintf`
- `sqgxShadowPlaneMatrix` calls `SqVec_ScaleVec3ByInverseOf102746C0`, `sub_10274870`
