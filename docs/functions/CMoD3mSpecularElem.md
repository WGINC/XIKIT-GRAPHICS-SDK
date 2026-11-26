# CMoD3mSpecularElem

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoD3mSpecularElem.cpp`.

5 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoD3mSpecularElem::GetRuntimeClass` | 0x10041010 | 6 | yes | - | - | - |
| `CMoD3mSpecularElem::Ctor` | 0x10041020 | 169 | yes | - | - | - |
| `CMoD3mSpecularElem::IsKind7` | 0x100410E0 | 15 | yes | - | Returns whether the argument is 7, the kind this element class answers to. (reviewed as game_100410E0) | medium |
| `CMoD3mSpecularElem::ScalarDeletingDtor` | 0x100410F0 | 30 | yes | - | - | - |
| `CMoD3mSpecularElem::BindTintedTexture` | 0x10041160 | 336 | yes | 1 | Computes the element's tint colour from its own colour and the scratch colour and binds its texture with it. (reviewed as game_10041160) | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoD3mSpecularElem::GetRuntimeClass` calls nothing directly
- `CMoD3mSpecularElem::Ctor` calls `CMoElem::Constructor`
- `CMoD3mSpecularElem::IsKind7` calls nothing directly
- `CMoD3mSpecularElem::ScalarDeletingDtor` calls `CMoD3mElem_Dtor`, `SharedDeleteHelper`
- `CMoD3mSpecularElem::BindTintedTexture` calls `game_10311C2C`, `TextureHolder_BindTinted`, `game_10044250`
