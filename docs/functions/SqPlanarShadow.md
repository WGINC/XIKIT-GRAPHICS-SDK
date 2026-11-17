# SqPlanarShadow

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqPlanarShadow.cpp`.

Why the file has this name (data/unit_names.json): sqsnPlanarShadowDraw, RenderShadowTexture, DrawShadowedShape

5 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `sqsnPlanarShadowDraw` | 0x102A2530 | 495 | yes | 0 | - | - |
| `SqPlanarShadow_RenderShadowTexture` | 0x102A2720 | 414 | yes | 1 | Draws a layer's shapes into a shadow texture from the light's view. | low |
| `Sqgx_SetTextureAt` | 0x102A2A30 | 29 | yes | - | Sets the graphics texture from the table entry at an index. | low |
| `Sqgx_CheckShadowGroupMember` | 0x102A2A50 | 48 | yes | - | Checks that a value is in a shadow group's list and reports an error when it is not. | low |
| `SqPlanarShadow_DrawShadowedShape` | 0x102A2C00 | 184 | yes | 1 | Draws a shape with the shadow texture blended over it. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `sqsnPlanarShadowDraw` calls `sqsnScene_1028F5F0`, `sqgxTextureSet`, `PackVec4`, `sqgxAmbient`, `sqgxBlendMul`, `sqgxColor`, `sqgxPassAdd`, `sqgxZMask`, `sqgxZTest`, `sqgxTextureStencilClear`, `sqgxShader`, `sqgxMatrixShape`, `sqDrawableDraw`, `sqgxAlphaDstTest`, `sqgxBlendOff`
- `SqPlanarShadow_RenderShadowTexture` calls `sqgxTextureAdd`, `sqgxColor`, `sqgxTextureDraw`, `sqgxTextureClear`, `SqgxContext_SetPerspective`, `sqgxMatrixCamera`, `sqgxShader`, `sqgxZMask`, `sqgxZTest`, `sqgxMatrixShape`, `sqgxColorUpdate`, `sqDrawableDraw`
- `Sqgx_SetTextureAt` calls `sqgxTextureSet`
- `Sqgx_CheckShadowGroupMember` calls `sqDebugPrintf`
- `SqPlanarShadow_DrawShadowedShape` calls `sqsnScene_1028F5F0`, `Sqgx_CheckShadowGroupMember`, `Sqgx_SetTextureAt`, `sqgxBlendMultAlpha`, `sqgxPassAdd`, `sqgxZMask`, `sqgxMatrixShape`, `SqgxContext_SetCotHalfAngle`, `sqgxShader`, `sqDrawableDraw`, `sqgxTextureSet`, `sqgxBlendOff`
