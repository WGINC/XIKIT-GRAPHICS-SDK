# sqgxTexture

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqgxTexture.cpp`.

14 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `sqgxTextureAdd` | 0x10281830 | 388 | yes | 1 | - | - |
| `SqgxTexture_ClearPaletteUsed` | 0x102819C0 | 12 | yes | - | Marks the texture palette slot at the index as unused. | low |
| `sqgxTextureClutAdd` | 0x102819D0 | 139 | yes | 0 | - | - |
| `SqgxTexture_FreeSlot` | 0x10281A70 | 101 | yes | - | Releases a texture slot's Direct3D objects and marks it free. | medium |
| `sqgxTextureGetSize` | 0x10281B60 | 35 | yes | - | - | - |
| `sqgxTextureSet` | 0x10281C20 | 46 | yes | - | - | - |
| `sqgxTextureDecal` | 0x10281C50 | 33 | yes | - | - | - |
| `sqgxTextureClamp` | 0x10281C80 | 51 | yes | - | - | - |
| `sqgxTextureClut` | 0x10281D60 | 78 | yes | 0 | - | - |
| `sqgxTextureUpdate` | 0x10281DB0 | 600 | yes | 0 | - | - |
| `sqgxTextureStencilClear` | 0x10282010 | 30 | yes | 0 | - | - |
| `sqgxTextureClear` | 0x10282030 | 166 | yes | 0 | - | - |
| `sqgxTextureDrawZ` | 0x102820E0 | 167 | yes | 0 | - | - |
| `sqgxTextureDraw` | 0x10282190 | 261 | yes | 0 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `sqgxTextureAdd` calls `sqDebugPrintf`, `sqgxCeilLog2`, `sqgxTextureCreateFromImage`
- `SqgxTexture_ClearPaletteUsed` calls nothing directly
- `sqgxTextureClutAdd` calls nothing directly
- `SqgxTexture_FreeSlot` calls nothing directly
- `sqgxTextureGetSize` calls nothing directly
- `sqgxTextureSet` calls nothing directly
- `sqgxTextureDecal` calls nothing directly
- `sqgxTextureClamp` calls nothing directly
- `sqgxTextureClut` calls nothing directly
- `sqgxTextureUpdate` calls nothing directly
- `sqgxTextureStencilClear` calls nothing directly
- `sqgxTextureClear` calls `sub_10311C2C`
- `sqgxTextureDrawZ` calls nothing directly
- `sqgxTextureDraw` calls `sqgxPixelSize`, `sqgxViewport`
