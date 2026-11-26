# CYyModel

Group: `CYy` (by the file name only). Source: `sdk/tree_src/CYyModel.cpp`.

14 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CYyModel::GetRuntimeClass` | 0x100298C0 | 6 | yes | - | - | - |
| `CYyModel::Constructor` | 0x1002B4B0 | 115 | yes | 2 | - | - |
| `CYyModel::ScalarDeletingDtor` | 0x1002B530 | 30 | yes | - | - | - |
| `CYyModel::Destructor` | 0x1002B550 | 80 | yes | - | - | - |
| `CYyModel::GetField44Addr` | 0x1002B5A0 | 4 | yes | - | - | - |
| `CYyModel::TailLink` | 0x1002B5E0 | 21 | yes | - | Returns the address of the last link in a model's list. (reviewed as game_1002B5E0) | low |
| `CYyModel::AppendBase` | 0x1002B630 | 14 | yes | - | Appends a model base to the end of a model's list. (reviewed as game_1002B630) | medium |
| `CYyModel::CreateModelBase` | 0x1002B6A0 | 49 | yes | - | - | - |
| `CYyModel::ApplyToParts` | 0x1002C270 | 41 | yes | - | Calls the part handler on every part of the model, passing the model and zero. (reviewed as game_1002C270) | medium |
| `CYyModel::ForEachPart130` | 0x1002C2A0 | 41 | yes | - | Calls the part handler FUN_1002A130 on every part of the model. (reviewed as game_1002C2A0) | low |
| `CYyModel::GetPartOffset` | 0x1002C400 | 253 | yes | - | Adds the transformed offset of a part to the given vector. (reviewed as game_1002C400) | low |
| `CYyModel::CallPartIndex` | 0x1002C600 | 58 | yes | - | Calls the handler on the part at an index. (reviewed as game_1002C600) | low |
| `CYyModel::QueryPartsA` | 0x1002C710 | 21 | no | - | Returns FUN_1002B3F0 of the argument when the model has parts. (reviewed as game_1002C710) | low |
| `CYyModel::QueryPartsB` | 0x1002C750 | 21 | no | - | Returns FUN_1002B470 of the argument when the model has parts. (reviewed as game_1002C750) | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CYyModel::GetRuntimeClass` calls nothing directly
- `CYyModel::Constructor` calls `BoneShadow_Construct`, `ModelTranslucent_Construct`, `EnvMapProjTex_ClearCounter`, `ProjTexTarget_Init`, `PostCapture_Init`
- `CYyModel::ScalarDeletingDtor` calls `CYyModel::Destructor`, `thunk_Mem_FreeBlockMergeNeighbours_as_v0`
- `CYyModel::Destructor` calls `game_10038A60`, `game_100252F0`, `game_10025C30`, `game_1001D1F0`, `game_100337C0`
- `CYyModel::GetField44Addr` calls nothing directly
- `CYyModel::TailLink` calls nothing directly
- `CYyModel::AppendBase` calls `CYyModel::TailLink`
- `CYyModel::CreateModelBase` calls `Mem_AllocDefault`, `CYyModelBase::Construct`, `CYyModel::AppendBase`
- `CYyModel::ApplyToParts` calls `CYyModel::GetField44Addr`, `CYyModelBase::CallPartsSlot20`
- `CYyModel::ForEachPart130` calls `CYyModel::GetField44Addr`, `game_1002A130`
- `CYyModel::GetPartOffset` calls `CYyModel::GetField44Addr`, `Part_AddTranslation`, `Vec3_MulInPlace`, `Vec3_AddInPlace`, `CYyModelBase::TransformVec4ByPart`
- `CYyModel::CallPartIndex` calls `CYyModel::GetField44Addr`, `game_1002A9E0`
- `CYyModel::QueryPartsA` calls `CYyModel::GetField44Addr`, `CYyModelBase::GetPartList`, `ModelDtBase_GetField20`
- `CYyModel::QueryPartsB` calls `CYyModel::GetField44Addr`, `CYyModelBase::GetPartList`
