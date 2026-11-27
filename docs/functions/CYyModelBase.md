# CYyModelBase

Group: `CYy` (by the file name only). Source: `sdk/tree_src/CYyModelBase.cpp`.

14 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CYyModelBase::AllocParts` | 0x100250F0 | 88 | yes | - | Allocates the part table for a model from its resource header counts. (reviewed as game_100250F0) | medium |
| `CYyModelBase::GetRuntimeClass` | 0x100298A0 | 6 | yes | - | - | - |
| `CYyModelBase::Construct` | 0x10029D30 | 121 | yes | - | Constructs the model base object and sets its vtable and defaults. (reviewed as game_10029D30) | medium |
| `CYyModelBase::ScalarDeletingDtor` | 0x10029DB0 | 30 | yes | - | - | - |
| `CYyModelBase::Destructor` | 0x10029DD0 | 117 | yes | - | - | - |
| `CYyModelBase::SetResourceAndRebuild` | 0x10029E50 | 29 | yes | - | - | - |
| `CYyModelBase::GetPartList` | 0x10029E70 | 4 | yes | - | - | - |
| `CYyModelBase::AddPartFromResource` | 0x10029F70 | 144 | yes | - | - | - |
| `CYyModelBase::RefreshParts` | 0x1002A0C0 | 103 | yes | - | Passes a value to every model part and marks two fixed parts. (reviewed as game_1002A0C0) | low |
| `CYyModelBase::DrawLit` | 0x1002A3B0 | 837 | yes | 0 | - | - |
| `CYyModelBase::CallPartsSlot20` | 0x1002A700 | 79 | yes | - | Calls vtable slot 0x20 of every part of the model base, passing the model, the base, a value and two shared counters. (reviewed as game_1002A700) | medium |
| `CYyModelBase::TransformVec4ByPart` | 0x1002A750 | 35 | yes | - | Resets the vector and transforms it by a part's transform. (reviewed as game_1002A750) | low |
| `CYyModelBase::FindPartIndex` | 0x1002A9B0 | 43 | yes | - | Returns the index for a model part id. (reviewed as game_1002A9B0) | low |
| `CYyModelBase::AllocMatrixBuffers` | 0x100342A0 | 142 | yes | - | Allocates the matrix buffers for a model's resource. (reviewed as game_100342A0) | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CYyModelBase::AllocParts` calls `Mem_AllocObject`
- `CYyModelBase::GetRuntimeClass` calls nothing directly
- `CYyModelBase::Construct` calls `CYySkl::Construct`, `CYyMotionQueList_Init`
- `CYyModelBase::ScalarDeletingDtor` calls `CYyModelBase::Destructor`, `thunk_Mem_FreeBlockMergeNeighbours_as_v0`
- `CYyModelBase::Destructor` calls `CMoResource::ReleaseChain`, `game_1001B140`, `game_1001AC30`, `game_10034270`
- `CYyModelBase::SetResourceAndRebuild` calls `CYyModelBase::AllocMatrixBuffers`, `CYyModelBase::RefreshParts`
- `CYyModelBase::GetPartList` calls nothing directly
- `CYyModelBase::AddPartFromResource` calls `ResourceHandle_Deref`, `Mem_AllocDefault`, `CYyModelDt::Construct`, `CYyModelBase::AllocParts`, `ModelBaseParts_AppendAtTail`, `CYyModelBase::RefreshParts`, `CYyModelDt::Init`
- `CYyModelBase::RefreshParts` calls `Skel_ClearMarks`, `CYyModelBase::GetPartList`, `CYyModelBase::FindPartIndex`, `Skel_MarkMarkedChains`
- `CYyModelBase::DrawLit` calls `CYyTexMng::FindByNameInResource`, `CDx::SetLight`, `CYyModelBase::GetPartList`, `CYyVbMng::AcquireVertexBuffer`, `CYyVbMng::ReleaseVertexBuffer`
- `CYyModelBase::CallPartsSlot20` calls `CYyModelBase::GetPartList`
- `CYyModelBase::TransformVec4ByPart` calls `Quat_SetIdentity`, `ModelBaseDraw_ApplyToVec4`
- `CYyModelBase::FindPartIndex` calls `Skel_GetRecordAt`
- `CYyModelBase::AllocMatrixBuffers` calls `ResourceHandle_Deref`, `Mem_AllocObject`, `Mat4_SetIdentity`, `Mem_FreeObject`
