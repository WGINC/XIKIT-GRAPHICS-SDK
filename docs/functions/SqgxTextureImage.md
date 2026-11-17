# SqgxTextureImage

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqgxTextureImage.cpp`.

Why the file has this name (data/unit_names.json): sqgxTextureCreateFromImage, sqgxTextureAddZ, CompositeBlendPasses

5 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Sq_PrintFloat4x4Indented` | 0x10280D10 | 199 | yes | - | Debug-prints 16 floats as four indented lines of four. | high |
| `SqgxTextureImage_CompositeBlendPasses` | 0x102813B0 | 133 | yes | 1 | Composites a snapshot texture with a number of additive blend passes. | low |
| `sqgxTextureCreateFromImage` | 0x10281510 | 461 | yes | 0 | - | - |
| `sqgxTextureAddZ` | 0x102816E0 | 289 | yes | 0 | - | - |
| `sqgxCeilLog2` | 0x10281810 | 23 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Sq_PrintFloat4x4Indented` calls `Sq_PrintIndent`, `sqDebugPrintf`
- `SqgxTextureImage_CompositeBlendPasses` calls `sqgxTextureDecal`, `sqgxZMask`, `sqgxTextureUpdate`, `sqgxTextureGetSize`, `sqgxBlendAdd`, `SqgxContext_NoOpA`, `sqgxBlendOff`, `sqgxTextureSet`
- `sqgxTextureCreateFromImage` calls `sqDebugPrintf`
- `sqgxTextureAddZ` calls `sqDebugPrintf`, `sqgxCeilLog2`
- `sqgxCeilLog2` calls nothing directly
