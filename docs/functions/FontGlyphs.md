# FontGlyphs

Group: `Font` (by the file name only). Source: `sdk/tree_src/FontGlyphs.cpp`.

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `FontGlyphs::FontGlyphs_DrawString` | 0x1011C080 | 365 | yes | 0 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `FontGlyphs::FontGlyphs_DrawString` calls `Gfx_SetCellBlendMode`, `Gfx_SetAdditiveBlend`, `Font_BindGlyphTexture`, `Sjis_GetCharByteLen`, `Font_DecodeNextChar`, `Font_DrawChar`, `Font_AddGlyphAdvance`, `sub_10311C2C`
