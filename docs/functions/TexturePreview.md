# TexturePreview

Group: `Texture` (by the file name only). Source: `sdk/tree_src/TexturePreview.cpp`.

Why the file has this name (data/unit_names.json): Tex_DrawNamedTexturePreview, Gfx_DrawScreenQuad256: a texture drawn to the screen by name (no caller by direct call)

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Tex_DrawNamedTexturePreview` | 0x1001DC70 | 142 | yes | 0 | - | - |
| `Gfx_DrawScreenQuad256` | 0x1001DD00 | 598 | yes | 0 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Tex_DrawNamedTexturePreview` calls `Util_Copy16Bytes`, `TexMgr_FindByName`, `Font_QueueText`, `Gfx_DrawScreenQuad256`
- `Gfx_DrawScreenQuad256` calls `CDx::DrawPrimitiveUP`
