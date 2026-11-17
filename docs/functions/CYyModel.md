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
| `CYyModel::TailLink` | 0x1002B5E0 | 21 | yes | - | Returns the address of the last link in a model's list. (reviewed as sub_1002B5E0) | low |
| `CYyModel::AppendBase` | 0x1002B630 | 14 | yes | - | Appends a model base to the end of a model's list. (reviewed as sub_1002B630) | medium |
| `CYyModel::CreateModelBase` | 0x1002B6A0 | 49 | yes | - | - | - |
| `CYyModel::ApplyToParts` | 0x1002C270 | 41 | yes | - | Calls the part handler on every part of the model, passing the model and zero. (reviewed as sub_1002C270) | medium |
| `CYyModel::ForEachPart130` | 0x1002C2A0 | 41 | yes | - | Calls the part handler FUN_1002A130 on every part of the model. (reviewed as sub_1002C2A0) | low |
| `CYyModel::GetPartOffset` | 0x1002C400 | 253 | yes | - | Adds the transformed offset of a part to the given vector. (reviewed as sub_1002C400) | low |
| `CYyModel::CallPartIndex` | 0x1002C600 | 58 | yes | - | Calls the handler on the part at an index. (reviewed as sub_1002C600) | low |
| `sub_1002C710` | 0x1002C710 | 21 | no | - | Returns FUN_1002B3F0 of the argument when the model has parts. | low |
| `sub_1002C750` | 0x1002C750 | 21 | no | - | Returns FUN_1002B470 of the argument when the model has parts. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CYyModel::GetRuntimeClass` calls nothing directly
- `CYyModel::Constructor` calls `BoneShadow_Construct`, `ModelTranslucent_Construct`, `EnvMapProjTex_ClearCounter`, `ProjTexTarget_Init`, `PostCapture_Init`
- `CYyModel::ScalarDeletingDtor` calls `CYyModel::Destructor`, `thunk_sub_10028AA0`
- `CYyModel::Destructor` calls `sub_10038A60`, `sub_100252F0`, `sub_10025C30`, `sub_1001D1F0`, `sub_100337C0`
- `CYyModel::GetField44Addr` calls nothing directly
- `CYyModel::TailLink` calls nothing directly
- `CYyModel::AppendBase` calls `CYyModel::TailLink`
- `CYyModel::CreateModelBase` calls `Mem_AllocDefault`, `CYyModelBase::Construct`, `CYyModel::AppendBase`
- `CYyModel::ApplyToParts` calls `CYyModel::GetField44Addr`, `CYyModelBase::CallPartsSlot20`
- `CYyModel::ForEachPart130` calls `CYyModel::GetField44Addr`, `sub_1002A130`
- `CYyModel::GetPartOffset` calls `CYyModel::GetField44Addr`, `Part_AddTranslation`, `Vec3_MulInPlace`, `Vec3_AddInPlace`, `CYyModelBase::TransformVec4ByPart`
- `CYyModel::CallPartIndex` calls `CYyModel::GetField44Addr`, `sub_1002A9E0`
- `sub_1002C710` calls `CYyModel::GetField44Addr`, `CYyModelBase::GetPartList`, `ModelDtBase_GetField20`
- `sub_1002C750` calls `CYyModel::GetField44Addr`, `CYyModelBase::GetPartList`
