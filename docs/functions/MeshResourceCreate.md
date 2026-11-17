# MeshResourceCreate

Group: `Mesh` (by the file name only). Source: `sdk/tree_src/MeshResourceCreate.cpp`.

Why the file has this name (data/unit_names.json): MeshResourceMng_CreateResourceByKind, ResHandle_FreeIfUnreferenced, ResourceHandle_IsResident

8 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ResHandle_FreeIfUnreferenced` | 0x10071050 | 15 | yes | - | - | - |
| `ResourceHandle_IsResident` | 0x10071060 | 57 | yes | - | - | - |
| `MeshResourceCreate_Create` | 0x100710F0 | 130 | yes | - | Creates an attachments task with its caster and target. | medium |
| `MeshResourceCreate_Reset` | 0x100711B0 | 27 | yes | - | Resets a reference record to its empty state. | low |
| `MeshResourceCreate_CopyField14At0` | 0x100711D0 | 16 | yes | - | Copies a source record's +0x14 field into this record's first dword. | low |
| `MeshResourceCreate_CopyField14At4` | 0x100711E0 | 17 | yes | - | Copies a source record's +0x14 field into this record's +4. | low |
| `MeshResourceCreate_CopyField14At8` | 0x10071200 | 17 | yes | - | Copies a source record's +0x14 field into this record's +8. | low |
| `MeshResourceMng_CreateResourceByKind` | 0x10071270 | 1578 | yes | - | Allocates and constructs the resource object for a resource header by its kind, evicting cached mesh resources when memory runs low. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ResHandle_FreeIfUnreferenced` calls `MoRes_FreeIfUnreferenced`
- `ResourceHandle_IsResident` calls `ResourceIter_InPoolRange`, `sub_10071F80`
- `MeshResourceCreate_Create` calls `Mem_AllocFromArea`, `CMoTask::ResetFields`, `CMoTask::InitVariant12`, `CMoAttachments::Construct`, `CMoTask::InitAndRegister`, `CMoAttachments::SetCaster`, `CMoAttachments::SetTarget`
- `MeshResourceCreate_Reset` calls nothing directly
- `MeshResourceCreate_CopyField14At0` calls nothing directly
- `MeshResourceCreate_CopyField14At4` calls nothing directly
- `MeshResourceCreate_CopyField14At8` calls nothing directly
- `MeshResourceMng_CreateResourceByKind` calls `MathVector_Call10029150`, `MeshResourceMng_Evict`, `Mem_AllocWithFallback`, `CMoResource_ConstructBase`, `ZoneResWeather_Construct`, `ZoneMapLoad_ConstructResource10336698`, `ZoneResource_Construct`, `Actor_ClearIndexTable`, `ModelTranslucent_ReturnSelf`, `CMoGeneratorClone_VT_1032B114_Constructor`, `CMoAttachments::Construct`, `WeatherRes_Construct`
