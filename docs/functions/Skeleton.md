# Skeleton

Group: `Skeleton` (by the file name only). Source: `sdk/tree_src/Skeleton.cpp`.

Why the file has this name (data/unit_names.json): Skel_* (bones, chains, rotation and translation)

11 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Skel_LoadBoneRotTrans` | 0x10034620 | 318 | yes | - | - | - |
| `Skel_ComposeMode` | 0x100347D0 | 931 | yes | - | - | - |
| `Skel_ComposeFromBone` | 0x10034B80 | 236 | yes | - | - | - |
| `Skel_OffsetAllTranslations` | 0x10035170 | 126 | yes | - | - | - |
| `Skel_GetRecordAt` | 0x100351F0 | 29 | yes | - | Returns the 0x1A-byte record at an index of the skeleton's table. | low |
| `Skel_GetBoneTableBase` | 0x10035210 | 58 | yes | - | Returns the base of the skeleton's bone table from its resource handle. | low |
| `Skel_GetTableAfterBones` | 0x10035250 | 26 | yes | - | Returns the address of the table that follows the bone table. | low |
| `Skel_GetEntryAt` | 0x10035270 | 26 | yes | - | Returns the entry at an index of the table after the bones. | low |
| `Skel_ClearMarks` | 0x100352A0 | 72 | yes | - | Clears the per-bone mark bytes for the skeleton. | low |
| `Skel_MarkMarkedChains` | 0x100352F0 | 63 | yes | - | Runs the chain mark on each bone that is already marked. | low |
| `Skel_MarkChain` | 0x10035330 | 61 | yes | - | Marks a bone and its parent chain in the skeleton's mark table. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Skel_LoadBoneRotTrans` calls `Quat_SetIdentityChained`, `Quat_Multiply`, `BoneShadow_Nop`, `Quat_NormalizeInPlace`, `MathVector_ReturnThis`, `Mat4_SetIdentity`, `Mat4_PostRotateY`, `Mat4_TransformPointInPlace`, `MathVector_Nop`
- `Skel_ComposeMode` calls `Vec3_Copy`, `Vec3_MulComponents`, `MathVector_ReturnThis`, `Mat4_SetScale`, `Mat4_PreMultiply`, `MathVector_Nop`, `Mat4_Copy`, `BoneShadow_FromQuat`, `Mat4_PostMultiply`, `Vec3_MulInPlace`, `Mat4_SetTranslation`
- `Skel_ComposeFromBone` calls `Vec3_MulComponents`, `BoneShadow_FromQuat`, `Mat4_PostMultiply`
- `Skel_OffsetAllTranslations` calls `ResourceHandle_Deref`
- `Skel_GetRecordAt` calls `Skel_GetBoneTableBase`
- `Skel_GetBoneTableBase` calls `ResourceHandle_IsResident`, `ResourceHandle_Deref`
- `Skel_GetTableAfterBones` calls `Skel_GetBoneTableBase`
- `Skel_GetEntryAt` calls `Skel_GetTableAfterBones`
- `Skel_ClearMarks` calls `ResourceHandle_Deref`
- `Skel_MarkMarkedChains` calls `ResourceHandle_Deref`, `Skel_MarkChain`
- `Skel_MarkChain` calls nothing directly
