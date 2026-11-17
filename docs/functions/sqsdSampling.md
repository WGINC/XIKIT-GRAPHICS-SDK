# sqsdSampling

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqsdSampling.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqsdSampling_DrawPasses` | 0x10299090 | 448 | yes | 1 | Draws a drawable in its base pass and an optional additive second pass. | medium |
| `sqsdSampling_BakeOntoShape` | 0x10299250 | 104 | yes | 1 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqsdSampling_DrawPasses` calls `SqsdPassTest_TestSeparationHalf`, `SqgxLighting_ApplyLighting`, `Sqgx_SetFloat18`, `Sqgx_CopyBlockToContext`, `sqgxBlendTrsp`, `sqgxTextureClamp`, `sqgxTextureDecal`, `sqgxTextureSet`, `sqgxTextureClut`, `sqgxShader`, `sqDrawableDraw`, `sqgxPassAdd`, `sqgxZMask`, `SqgxContext_SetInverseFactor`, `sqgxBlendAddDestAlpha`, `sqgxBlendAdd`, `sqgxBlendOff`
- `sqsdSampling_BakeOntoShape` calls `sqgxShader`, `SqgxDlist_CreateContextList`, `sqDrawableDraw`, `sqgxDlistEnd`, `SqshDispList_Create`, `SqBounds_Copy`, `SqObject_Release`
