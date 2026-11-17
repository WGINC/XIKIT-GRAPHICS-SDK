# XiModelActor

Group: `Xi` (by the file name only). Source: `sdk/tree_src/XiModelActor.cpp`.

5 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `XiModelActor_GetPtr734` | 0x100C3FB0 | 7 | yes | - | Returns the address of the actor's +0x734 sub-object. | low |
| `XiModelActor_GetPtr744` | 0x100C3FC0 | 7 | yes | - | Returns the address of the actor's +0x744 sub-object. | low |
| `XiModelActor::CopyRectFromSlot` | 0x100C4B00 | 75 | yes | - | Copies four dwords from the record returned by virtual slot 0x1BC into the output. (reviewed as sub_100C4B00) | low |
| `XiModelActor::BuildWorldMatrix` | 0x100C4B50 | 102 | yes | - | Builds the actor's world matrix from its rotation and translation. (reviewed as sub_100C4B50) | medium |
| `XiModelActor::BuildMatrixAndDraw` | 0x100C4C20 | 190 | yes | 1 | Builds the model actor's world matrix from its angles and position and draws its model through ModelActor_Draw, after an optional frame delay. (reviewed as sub_100C4C20) | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `XiModelActor_GetPtr734` calls nothing directly
- `XiModelActor_GetPtr744` calls nothing directly
- `XiModelActor::CopyRectFromSlot` calls nothing directly
- `XiModelActor::BuildWorldMatrix` calls `Mat4_SetIdentity`, `Mat4_PostRotateZ`, `Mat4_PostRotateY`, `Mat4_PostRotateX`, `Mat4_SetTranslation`
- `XiModelActor::BuildMatrixAndDraw` calls `Mat4_SetIdentity`, `Mat4_PostRotateZ`, `Mat4_PostRotateY`, `Mat4_PostRotateX`, `Mat4_SetTranslation`, `ModelActor_Draw`
