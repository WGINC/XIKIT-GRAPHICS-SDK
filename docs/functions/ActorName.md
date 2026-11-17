# ActorName

Group: `Actor` (by the file name only). Source: `sdk/tree_src/ActorName.cpp`.

Why the file has this name (data/unit_names.json): CXiActor::GetName, ProjectThroughCamera; called from CXiActor::NameCalc

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ActorName_ProjectThroughCamera` | 0x10082FB0 | 265 | yes | - | Projects a world point through the camera's matrices, reporting whether it is in front. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ActorName_ProjectThroughCamera` calls `MathVector_ReturnThis`, `Vec3_Copy`, `Camera_GetViewMatrixPtr`, `Mat4_Copy`, `Mat4_TransformPointInPlace`, `MathVector_Nop`, `Camera_GetMatrix154Ptr`, `Mat4_PostMultiply`, `Mat4_TransformCoordInPlace`, `sub_10311C2C`
