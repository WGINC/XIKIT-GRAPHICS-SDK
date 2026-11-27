# ModelBaseDraw

Group: `Model` (by the file name only). Source: `sdk/tree_src/ModelBaseDraw.cpp`.

Why the file has this name (data/unit_names.json): CYyModelBase::DrawLit / RefreshParts / FindPartIndex, Part_* translations

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ModelBaseDraw_ApplyToVec4` | 0x1002A780 | 162 | yes | - | Applies a part's rotation and translation to a 4-component vector. | low |
| `Part_CopyTranslation` | 0x1002A890 | 24 | yes | - | Copies a part's translation vector to the output. | medium |
| `Part_AddTranslation` | 0x1002A8B0 | 65 | yes | - | Adds a part's translation to a vector in place. | low |
| `ModelBaseDraw_ClampPointToLocalEllipse` | 0x1002B140 | 564 | yes | - | Clamps a point to an ellipse in a local frame; AL 1 when it was outside and moved. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ModelBaseDraw_ApplyToVec4` calls `MathVector_ReturnThis`, `Skel_GetRecordAt`, `Mat4_SetIdentity`, `Mat4_PostRotateX`, `Mat4_PostRotateY`, `Mat4_PostRotateZ`, `Part_CopyTranslation`, `Mat4_SetTranslation`, `Mat4_PostMultiply`, `Mat4_TransformVec4InPlace`, `MathVector_Nop`
- `Part_CopyTranslation` calls `Vec3_Copy`
- `Part_AddTranslation` calls `MathVector_ReturnThis`, `Skel_GetRecordAt`, `Vec3_AddInPlace`, `MathVector_Nop`
- `ModelBaseDraw_ClampPointToLocalEllipse` calls `MathVector_ReturnThis`, `game_102D8141`, `Mat4_TransformNormal`, `Vec3_ScaleInPlace`, `Mat4_InvertOrthonormal`, `Mat4_TransformNormalInPlace`, `game_100274B0`, `MathVector_Nop`, `Vec3_Copy`
