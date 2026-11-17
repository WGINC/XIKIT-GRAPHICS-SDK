# SqTextureBind

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqTextureBind.cpp`.

Why the file has this name (data/unit_names.json): Texture_BindFromObject, Texture_CreateEntry

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Texture_BindFromObject` | 0x10298C50 | 58 | yes | - | Binds the texture and palette stored in an object, or clears both when it is null. | medium |
| `Texture_CreateEntry` | 0x10298E10 | 113 | yes | 2 | Creates a texture entry and links it to its helper objects. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Texture_BindFromObject` calls `sqgxTextureSet`, `sqgxTextureClut`
- `Texture_CreateEntry` calls `SqimImage_Create`, `SqrdTexture_Create`, `sub_1029C260`, `sqgxTextureAdd`
