# sqsdAniso

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqsdAniso.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqsdAniso_DrawPasses` | 0x102993B0 | 598 | yes | 1 | Draws a drawable with its base pass and a second pass using a colour texture it creates once (the sqsdAniso unit). | low |
| `sqsdAniso_BakeOntoShape` | 0x10299610 | 207 | yes | 1 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqsdAniso_DrawPasses` calls `SqsdPassTest_TestSeparationHalf`, `SqIOHooks_CallHook40`, `SqgxLighting_ApplyLighting`, `sqgxTextureSet`, `sqgxTextureClut`, `sqgxTextureDecal`, `sqgxShader`, `sqgxBlendTrsp`, `sqgxAlphaTest`, `Sqgx_IncCounter`, `SqgxContext_SetMultiplyAdd`, `Texture_CreateEntry`, `Sqgx_SetContextFieldE24`, `sqDrawableDraw`, `sqgxBlendOff`, `Sqgx_ResetCounter`
- `sqsdAniso_BakeOntoShape` calls `sqgxShader`, `SqIOHooks_CallHook40`, `SqgxDlist_CreateContextList`, `sqDrawableDraw`, `sqgxDlistEnd`, `Sqgx_ResetCounter`, `SqshDispList_Create`, `SqBounds_Copy`, `SqObject_Release`
