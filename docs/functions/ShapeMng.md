# ShapeMng

Group: `Shape` (by the file name only). Source: `sdk/tree_src/ShapeMng.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ShapeMng::ShapeMng_BindFontTexture` | 0x10120590 | 205 | yes | 0 | - | - |
| `ShapeMng::ShapeMng_BindDmgNumTexture` | 0x101207B0 | 205 | yes | 0 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ShapeMng::ShapeMng_BindFontTexture` calls `ShapeMng_LoadFontTextures`
- `ShapeMng::ShapeMng_BindDmgNumTexture` calls `game_10120880`
