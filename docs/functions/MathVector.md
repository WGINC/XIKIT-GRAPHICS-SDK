# MathVector

Group: `Math` (by the file name only). Source: `sdk/tree_src/MathVector.cpp`.

Why the file has this name (data/unit_names.json): Mat4_*, Vec3_*, Gfx_ProjectWorldToClip, Gfx_NdcToScreen: the vector and matrix code

56 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Vec3_SetZero` | 0x10026E00 | 15 | yes | - | Sets a 3-component vector to zero. | medium |
| `Quat_SetIdentity` | 0x10026E10 | 22 | yes | - | - | - |
| `Vec4_Set` | 0x10026E30 | 32 | yes | - | - | - |
| `Vec3_Set` | 0x10026E50 | 25 | yes | - | Sets a 3-component vector from three floats and returns it. | medium |
| `Vec4_Copy` | 0x10026E90 | 31 | yes | - | - | - |
| `Vec3_Copy` | 0x10026EB0 | 25 | yes | - | - | - |
| `Vec3_AddInPlace` | 0x10026F20 | 33 | yes | - | - | - |
| `Vec3_Add_10026FA0` | 0x10026FA0 | 37 | yes | - | - | - |
| `Vec2_Add` | 0x10026FD0 | 28 | yes | - | - | - |
| `Vec3_SubInPlace` | 0x100270A0 | 33 | yes | - | Subtracts one 3-component vector from another in place. | medium |
| `Vec3_Sub` | 0x10027120 | 37 | yes | - | - | - |
| `Vec3_ScaleInPlace` | 0x100272B0 | 33 | yes | - | Multiplies a 3-component vector by a scalar in place. | medium |
| `Vec3_Scale` | 0x100272E0 | 37 | yes | - | - | - |
| `Vec3_MulInPlace` | 0x10027310 | 33 | yes | - | - | - |
| `Vec3_MulComponents` | 0x10027340 | 37 | yes | - | Writes the component-wise product of two 3-component vectors. | medium |
| `Vec3_CopyThen100274B0` | 0x10027510 | 27 | yes | - | Copies a vector and applies 0x100274B0 to the copy. | low |
| `Vec3_Cross` | 0x10027550 | 80 | yes | - | Writes the cross product of two 3-component vectors. | medium |
| `MathVector_Distance3` | 0x100275D0 | 44 | yes | - | Returns the distance between two three-float points. | high |
| `MathVector_Length3` | 0x10027600 | 17 | yes | - | Returns the length of a three-float vector. | high |
| `Vec3_Call100275D0` | 0x10027620 | 19 | yes | - | Returns the float 0x100275D0 computes from two vectors. | low |
| `Gfx_ProjectWorldToClip` | 0x100276F0 | 200 | yes | - | - | - |
| `Gfx_TransformWorldToView` | 0x100277E0 | 138 | yes | - | - | - |
| `Gfx_ProjectViewToClip` | 0x10027870 | 73 | yes | - | - | - |
| `Gfx_NdcToScreen` | 0x100278E0 | 72 | yes | - | - | - |
| `Gfx_ScreenDeltaToNdc` | 0x10027930 | 81 | yes | 0 | - | - |
| `MathVector_ReturnThis` | 0x10027990 | 3 | yes | - | Returns its this pointer; a shared trivial method. | low |
| `MathVector_Nop` | 0x100279A0 | 1 | yes | - | Does nothing; a shared empty function. | low |
| `Mat4_SetIdentity` | 0x100279B0 | 55 | yes | - | - | - |
| `Mat4_Copy` | 0x100279F0 | 101 | yes | - | - | - |
| `Mat4_PostScale` | 0x10027A60 | 63 | yes | - | - | - |
| `Mat4_BuildScale` | 0x10027AE0 | 67 | yes | - | - | - |
| `Mat4_SetScale` | 0x10027B30 | 68 | yes | - | - | - |
| `Mat4_PostRotateX` | 0x10027B80 | 66 | yes | - | - | - |
| `Mat4_PostRotateY` | 0x10027BD0 | 66 | yes | - | - | - |
| `Mat4_PostRotateZ` | 0x10027C20 | 66 | yes | - | - | - |
| `Mat4_SetRow3` | 0x10027CD0 | 30 | yes | - | - | - |
| `Mat4_SetTranslation` | 0x10027CF0 | 24 | yes | - | - | - |
| `Mat4_PostMultiply` | 0x10027D10 | 193 | yes | - | - | - |
| `Mat4_PreMultiply` | 0x10027E90 | 193 | yes | - | - | - |
| `Mat4_TransformVec4InPlace` | 0x10028140 | 46 | yes | - | - | - |
| `Mat4_TransformVec4` | 0x10028170 | 137 | yes | - | Multiplies a 4-component row vector by the 4x4 matrix at this. | medium |
| `Mat4_TransformPointInPlace` | 0x10028200 | 46 | yes | - | - | - |
| `Mat4_TransformPoint` | 0x10028230 | 90 | yes | - | Transforms a 3-component point by the 4x4 matrix at this, translation included. | medium |
| `Mat4_TransformNormalInPlace` | 0x10028290 | 46 | yes | - | - | - |
| `Mat4_TransformNormal` | 0x100282C0 | 81 | yes | - | - | - |
| `Mat4_TransformCoordInPlace` | 0x10028320 | 68 | yes | - | - | - |
| `Mat4_InvertOrthonormal` | 0x100283C0 | 148 | yes | - | - | - |
| `Mem_AllocObject` | 0x10028640 | 85 | yes | - | - | - |
| `Mem_AllocWithFallback` | 0x100286B0 | 73 | yes | - | - | - |
| `Mem_FreeObject` | 0x10028700 | 16 | yes | - | - | - |
| `SharedDeleteHelper` | 0x10028710 | 5 | yes | - | - | - |
| `MathVector_Call10029150` | 0x10028720 | 5 | yes | - | Calls the list range chosen by a kind. | low |
| `Mem_GetPtrMinus0x20` | 0x10028730 | 8 | yes | - | Returns its pointer argument minus 0x20. | low |
| `MemBlock_AllocFromFront` | 0x10028850 | 211 | yes | - | Allocates from the first free block that fits, walking forward. | medium |
| `MemBlock_AllocFromBack` | 0x10028930 | 179 | yes | - | Allocates from the end of a free block that fits, walking backward. | medium |
| `sub_100289F0` | 0x100289F0 | 53 | no | - | Returns the size of the largest block with a clear in-use word in a block list range. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Vec3_SetZero` calls nothing directly
- `Quat_SetIdentity` calls nothing directly
- `Vec4_Set` calls nothing directly
- `Vec3_Set` calls nothing directly
- `Vec4_Copy` calls nothing directly
- `Vec3_Copy` calls nothing directly
- `Vec3_AddInPlace` calls nothing directly
- `Vec3_Add_10026FA0` calls nothing directly
- `Vec2_Add` calls nothing directly
- `Vec3_SubInPlace` calls nothing directly
- `Vec3_Sub` calls nothing directly
- `Vec3_ScaleInPlace` calls nothing directly
- `Vec3_Scale` calls nothing directly
- `Vec3_MulInPlace` calls nothing directly
- `Vec3_MulComponents` calls nothing directly
- `Vec3_CopyThen100274B0` calls `Vec3_Copy`, `sub_100274B0`
- `Vec3_Cross` calls `Vec3_Copy`
- `MathVector_Distance3` calls `Vec3_Sub`, `sub_10027530`
- `MathVector_Length3` calls `sub_10027530`
- `Vec3_Call100275D0` calls `MathVector_Distance3`
- `Gfx_ProjectWorldToClip` calls `MathVector_ReturnThis`, `CDx::GetTransformCached`, `Mat4_PostMultiply`, `Vec4_Copy`, `Mat4_TransformCoordInPlace`, `MathVector_Nop`
- `Gfx_TransformWorldToView` calls `MathVector_ReturnThis`, `CDx::GetTransformCached`, `Mat4_PostMultiply`, `Vec4_Copy`, `Mat4_TransformVec4InPlace`, `MathVector_Nop`
- `Gfx_ProjectViewToClip` calls `MathVector_ReturnThis`, `CDx::GetTransformCached`, `Vec4_Copy`, `Mat4_TransformCoordInPlace`, `MathVector_Nop`
- `Gfx_NdcToScreen` calls `CDx::GetRenderTargetTop`
- `Gfx_ScreenDeltaToNdc` calls nothing directly
- `MathVector_ReturnThis` calls nothing directly
- `MathVector_Nop` calls nothing directly
- `Mat4_SetIdentity` calls nothing directly
- `Mat4_Copy` calls nothing directly
- `Mat4_PostScale` calls `Mat4_SetIdentity`, `Mat4_PostMultiply`
- `Mat4_BuildScale` calls nothing directly
- `Mat4_SetScale` calls nothing directly
- `Mat4_PostRotateX` calls `Mat4_SetIdentity`, `Mat4_PostMultiply`
- `Mat4_PostRotateY` calls `Mat4_SetIdentity`, `Mat4_PostMultiply`
- `Mat4_PostRotateZ` calls `Mat4_SetIdentity`, `Mat4_PostMultiply`
- `Mat4_SetRow3` calls nothing directly
- `Mat4_SetTranslation` calls nothing directly
- `Mat4_PostMultiply` calls `Mat4_Copy`
- `Mat4_PreMultiply` calls `Mat4_Copy`
- `Mat4_TransformVec4InPlace` calls `Vec4_Copy`, `Mat4_TransformVec4`
- `Mat4_TransformVec4` calls nothing directly
- `Mat4_TransformPointInPlace` calls `Vec3_Copy`, `Mat4_TransformPoint`
- `Mat4_TransformPoint` calls nothing directly
- `Mat4_TransformNormalInPlace` calls `Vec3_Copy`, `Mat4_TransformNormal`
- `Mat4_TransformNormal` calls nothing directly
- `Mat4_TransformCoordInPlace` calls `Mat4_TransformVec4InPlace`
- `Mat4_InvertOrthonormal` calls `Vec4_Copy`, `Mat4_TransformVec4InPlace`, `Mat4_Copy`
- `Mem_AllocObject` calls `sub_10313486`, `Mem_AllocFromArea`
- `Mem_AllocWithFallback` calls `Mem_AllocFromArea`, `_exit_0`
- `Mem_FreeObject` calls `Mem_FreeBlockMergeNeighbours`
- `SharedDeleteHelper` calls `Mem_FreeBlockMergeNeighbours`
- `MathVector_Call10029150` calls `MemArea_CallListByKind`
- `Mem_GetPtrMinus0x20` calls nothing directly
- `MemBlock_AllocFromFront` calls `MemBlock_GetSize`
- `MemBlock_AllocFromBack` calls `MemBlock_GetSize`
- `sub_100289F0` calls `MemBlock_GetSize`
