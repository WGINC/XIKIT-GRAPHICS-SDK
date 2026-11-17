# sqsdGeneric

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqsdGeneric.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqsdGeneric_Init` | 0x10290910 | 230 | yes | - | Initialises a sqsdGeneric object's header, callbacks, default values, arrays and embedded material. | medium |
| `SqsdGeneric_DrawPasses` | 0x10290B60 | 1106 | yes | 1 | Draws a drawable with the generic shader: a base pass and one blended pass for each extra texture the shader has. | medium |
| `sqsdGeneric_BakeOntoShape` | 0x10290FC0 | 233 | yes | 1 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqsdGeneric_Init` calls `SqrdMaterial_Init`
- `SqsdGeneric_DrawPasses` calls `SqsdPassTest_TestSeparationHalf`, `Sqgx_ResetCounter`, `sqgxTextureDecal`, `sqgxTextureClamp`, `sqgxPassAdd`, `SqgxLighting_ApplyLighting`, `sqgxTextureSet`, `sqgxTextureClut`, `sqgxBlendTrsp`, `sqgxBlendLin`, `sqgxShader`, `sqDrawableDraw`, `Sqgx_SetParam9cc`, `sqgxBlendAddDestAlpha`, `sqgxBlendAdd`, `sqgxBlendOff`, `sqgxFBMask`, `sqgxZMask`, `SqgxContext_SetInverseFactor`, `SqgxContext_SetMultiplyAdd`
- `sqsdGeneric_BakeOntoShape` calls `sqDebugPrintf`, `sqgxShader`, `SqgxDlist_CreateContextList`, `sqDrawableDraw`, `sqgxDlistEnd`, `Sqgx_ResetCounter`, `SqshDispList_Create`, `SqBounds_Copy`, `SqObject_Release`
