# sqsdCartoon

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqsdCartoon.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqsdCartoon_Draw` | 0x102997A0 | 146 | yes | 1 | Draws a cartoon-shaded drawable in two passes. | medium |
| `sqsdCartoon_BakeOntoShape_Stub` | 0x10299840 | 16 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqsdCartoon_Draw` calls `SqsdPassTest_TestSeparationHalf`, `SqgxLighting_ApplyLighting`, `Texture_BindFromObject`, `sqgxShader`, `sqDrawableDraw`, `sqgxPassAdd`, `sqgxBlendSub`, `sqgxBlendOff`
- `sqsdCartoon_BakeOntoShape_Stub` calls `sqDebugPrintf`
