# SqDrawableTwoPass

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqDrawableTwoPass.cpp`.

Why the file has this name (data/unit_names.json): Drawable_DrawTwoPass

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Drawable_DrawTwoPass` | 0x102B2CA0 | 309 | yes | 1 | Draws a drawable in two passes with its colour, ambient and optional texture. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Drawable_DrawTwoPass` calls `SqsdPassTest_TestSeparationHalf`, `sqgxColor`, `sqgxAmbient`, `SqgxContext_SetFloat76C`, `SqgxContext_SetDword774AndFactor`, `sqgxTextureDecal`, `SqgxLighting_ApplyLighting`, `Texture_BindFromObject`, `sqgxTextureUpdate`, `sqgxShader`, `sqDrawableDraw`, `sqgxBlendAdd`, `sqgxPass`, `sqgxBlendOff`
