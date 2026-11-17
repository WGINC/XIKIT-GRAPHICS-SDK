# AfterimageTask

Group: `Afterimage` (by the file name only). Source: `sdk/tree_src/AfterimageTask.cpp`.

Why the file has this name (data/unit_names.json): AfterimageTask_Execute / Kill / SetCaster / SetTarget, the g_afterimage* textures

7 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `AfterimageTask_FindFirstKind` | 0x10062770 | 81 | yes | - | Returns the first object of the expected kind in the chain from the task's +0x34 link. | low |
| `Scheduler_ResolveOwner` | 0x100627D0 | 81 | yes | - | Follows a chain of handle objects of one class to the owner. | low |
| `AfterimageTask_SetCaster` | 0x10062830 | 76 | yes | - | Sets the caster of the afterimage task, notifying the old and new objects. | medium |
| `AfterimageTask_SetTarget` | 0x10062880 | 76 | yes | - | Sets the target of the afterimage task, notifying the old and new objects. | medium |
| `AfterimageTask_Execute` | 0x10062E20 | 83 | yes | - | Runs the afterimage scheduler entry for a resource. | medium |
| `AfterimageTask_Kill` | 0x10062E80 | 76 | yes | - | Stops the afterimage scheduler entry for a resource. | medium |
| `AfterimageTask_IsResourceMoving` | 0x10062ED0 | 109 | yes | - | Returns true for a resource still loading, else whether the type-7 child found by the id is moving (Scheduler_IsMoving), else false. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `AfterimageTask_FindFirstKind` calls `CMoAttachments::GetCaster`, `CYyObject_IsKindOf`
- `Scheduler_ResolveOwner` calls `CMoAttachments::GetTarget`, `CYyObject_IsKindOf`, `CMoAttachments::GetCaster`
- `AfterimageTask_SetCaster` calls `CMoAttachments::GetCaster`, `CMoAttachments::SetCaster`
- `AfterimageTask_SetTarget` calls `CMoAttachments::GetTarget`, `CMoAttachments::SetTarget`
- `AfterimageTask_Execute` calls `sub_100731B0`, `CMoResource::FindByTypeAndId`, `Scheduler_Execute`
- `AfterimageTask_Kill` calls `ResourceIter_FindOrStartTask`, `CMoResource::FindByTypeAndId`, `Scheduler_Kill`
- `AfterimageTask_IsResourceMoving` calls `ResourceIter_FindOrStartTask`, `ResourceHandle_IsResident`, `CMoResource::FindByTypeAndId`, `Scheduler_IsMoving`
