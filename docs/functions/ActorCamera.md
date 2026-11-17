# ActorCamera

Group: `Actor` (by the file name only). Source: `sdk/tree_src/ActorCamera.cpp`.

Why the file has this name (data/unit_names.json): Camera_PlaceRelativeToActor, Camera_SetTargetIfMoved, Camera_BuildLookAtView, the actor percent-scale tables; called from CXiSkeletonActor and the camera code

13 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Camera_SetPosition` | 0x1001E760 | 20 | yes | - | Stores the argument as the camera's position at +0x44. | medium |
| `Camera_SetTargetIfMoved` | 0x1001E780 | 75 | yes | - | Stores the argument as the camera's target at +0x50 when it differs from the position. | medium |
| `Camera_PlaceRelativeToActor` | 0x10021680 | 636 | yes | - | Places the camera at an offset in the actor's frame looking at the actor, or at the actor's position in first-person view, and snapshots its state. | medium |
| `Camera_DiffersFromSaved` | 0x10021AE0 | 134 | yes | - | Tells whether the camera's state differs from its saved copy. | medium |
| `Camera_SnapshotState` | 0x10021B70 | 48 | yes | - | Runs the camera update and copies its position, target and value into the saved state. | low |
| `Camera_BuildLookAtView` | 0x10021C10 | 317 | yes | - | Builds the camera's view matrix with D3DXMatrixLookAtRH and stores it when valid. | high |
| `Actor_ClearIndexTable` | 0x100220E0 | 55 | yes | - | Sets the sixteen index bytes of the table to 0xFF. | low |
| `Actor_GetPercentScaleByIndex` | 0x10022120 | 71 | yes | - | - | - |
| `Actor_MapPercentScaleIndex` | 0x10022170 | 24 | yes | - | Maps the percent-scale codes 7 and 8 to indices 0 and 2, and anything else to -1. | low |
| `Actor_LookupPercentScaleA` | 0x10022190 | 66 | yes | - | - | - |
| `Actor_LookupPercentScaleB` | 0x100221E0 | 66 | yes | - | - | - |
| `Actor_InitIndexTable` | 0x10022230 | 60 | yes | - | - | - |
| `ActorCamera_LookupTable1032A41C` | 0x10022320 | 21 | yes | - | Returns entry index of a 9-byte table at 0x1032A41C, or -1 for an index of 9 or more. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Camera_SetPosition` calls `Vec3_Copy`
- `Camera_SetTargetIfMoved` calls `Vec3_Sub`, `MathVector_Length3`, `Vec3_Copy`
- `Camera_PlaceRelativeToActor` calls `MathVector_ReturnThis`, `Mat4_SetIdentity`, `Mat4_PostRotateX`, `Mat4_PostRotateY`, `Mat4_PostRotateZ`, `Mat4_SetTranslation`, `Mat4_TransformPoint`, `Vec3_Copy`, `Camera_SetPosition`, `Camera_SetTargetIfMoved`, `Mat4_SetRow3`, `Mat4_TransformPointInPlace`, `Camera_SnapshotState`, `MathVector_Nop`
- `Camera_DiffersFromSaved` calls nothing directly
- `Camera_SnapshotState` calls `Camera_BuildLookAtView`, `Vec3_Copy`
- `Camera_BuildLookAtView` calls `Vec3_Copy`, `Vec3_Sub`, `MathVector_ReturnThis`, `Mat4_SetIdentity`, `Mat4_PostRotateZ`, `Mat4_PostRotateY`, `Mat4_PostRotateX`, `Mat4_TransformNormalInPlace`, `sub_100274B0`, `Vec3_Add_10026FA0`, `sub_102D7FF9`, `Occlusion_AreAll16FloatsAccepted`, `Mat4_Copy`, `MathVector_Nop`
- `Actor_ClearIndexTable` calls nothing directly
- `Actor_GetPercentScaleByIndex` calls `ErrorReport_NoOpVarargsB`
- `Actor_MapPercentScaleIndex` calls nothing directly
- `Actor_LookupPercentScaleA` calls `Actor_MapPercentScaleIndex`
- `Actor_LookupPercentScaleB` calls `Actor_MapPercentScaleIndex`
- `Actor_InitIndexTable` calls `Actor_ClearIndexTable`
- `ActorCamera_LookupTable1032A41C` calls nothing directly
