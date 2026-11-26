# CMoResource

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoResource.cpp`.

18 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoResource::GetRuntimeClass_variant0` | 0x10036B70 | 6 | yes | - | - | - |
| `CMoResource::CMoCamera_SetLinkedObject` | 0x10047FC0 | 12 | yes | - | - | - |
| `CMoResource::Slot5DoNothing` | 0x10047FD0 | 3 | yes | - | The default of virtual slot 5: does nothing (takes 4 bytes of arguments, unused). (reviewed as game_10047FD0) | low |
| `CMoResource::GetRuntimeClass_variant1` | 0x10056250 | 6 | yes | - | - | - |
| `CMoResource::GetRuntimeClass_variant2` | 0x10056290 | 6 | yes | - | - | - |
| `CMoResource::GetRuntimeClass_variant3` | 0x10071D70 | 6 | yes | - | - | - |
| `CMoResource_ConstructBase` | 0x10071D80 | 34 | yes | - | Constructs the CMoResource base of a resource object. | medium |
| `CMoResource::Slot8DoNothing` | 0x10071DB0 | 1 | yes | - | The default of virtual slot 8: does nothing. (reviewed as game_10071DB0) | low |
| `CMoResource::ScalarDeletingDtor` | 0x10071DC0 | 30 | yes | - | - | - |
| `CMoResource::Destructor` | 0x10071DE0 | 31 | yes | - | - | - |
| `CMoResource::ReleaseChain` | 0x10071EC0 | 135 | yes | - | - | - |
| `CMoResource::RegisterInTypeList` | 0x10072030 | 119 | yes | - | - | - |
| `CMoResource::GetParent` | 0x10072270 | 32 | yes | - | - | - |
| `CMoResource::FindByTypeAndId` | 0x10072290 | 39 | yes | - | - | - |
| `CMoResource::FindWorker` | 0x100722C0 | 358 | yes | - | Searches the resource tree for an entry matching a type, an id and an owner. (reviewed as game_100722C0) | medium |
| `CMoResource::FindOrCreateTask` | 0x100730E0 | 208 | yes | - | Finds the resource with the given id, or creates and registers a new task for it. (reviewed as game_100730E0) | medium |
| `CMoResource::RegisterAndMark` | 0x10073A60 | 187 | yes | - | Registers a resource in its type list and marks it when its type is in a set. (reviewed as game_10073A60) | medium |
| `CMoResource::InitAndGetFlag` | 0x10073B80 | 23 | yes | - | Initialises the resource and returns the result of its virtual query. (reviewed as game_10073B80) | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoResource::GetRuntimeClass_variant0` calls nothing directly
- `CMoResource::CMoCamera_SetLinkedObject` calls nothing directly
- `CMoResource::Slot5DoNothing` calls nothing directly
- `CMoResource::GetRuntimeClass_variant1` calls nothing directly
- `CMoResource::GetRuntimeClass_variant2` calls nothing directly
- `CMoResource::GetRuntimeClass_variant3` calls nothing directly
- `CMoResource_ConstructBase` calls `MeshResourceCreate_Reset`, `Resource_InitFieldsTakeFlag1047D12C`
- `CMoResource::Slot8DoNothing` calls nothing directly
- `CMoResource::ScalarDeletingDtor` calls `CMoResource::Destructor`, `SharedDeleteHelper`
- `CMoResource::Destructor` calls `CMoResource_Destroy`, `NodePool_ReleaseNode`
- `CMoResource::ReleaseChain` calls `ResourceIter_InPoolRange`
- `CMoResource::RegisterInTypeList` calls `MeshResourceMng_AllocHandle`, `MeshResourceCreate_CopyField14At8`
- `CMoResource::GetParent` calls nothing directly
- `CMoResource::FindByTypeAndId` calls `CMoResource::FindWorker`
- `CMoResource::FindWorker` calls `CMoResource::GetParent`
- `CMoResource::FindOrCreateTask` calls `CMoResource::GetParent`, `TaskAndTextArgs_FindTask`, `Mem_AllocFromArea`, `CMoTask::ResetFields`, `CMoTask::Constructor`, `game_10074A00`, `ResourceLoadTask_Start`
- `CMoResource::RegisterAndMark` calls `CMoResource::RegisterInTypeList`
- `CMoResource::InitAndGetFlag` calls `game_100720B0`
