# ResourceIter

Group: `Resource` (by the file name only). Source: `sdk/tree_src/ResourceIter.cpp`.

Why the file has this name (data/unit_names.json): ResourceIter_*, MeshResourceMng_AllocHandle / Evict, NodePool_ReleaseNode

14 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `MoRes_FreeIfUnreferenced` | 0x10073B20 | 95 | yes | - | - | - |
| `ResourceIter_FindById` | 0x10073BA0 | 141 | yes | - | Finds the resource with a given id within a type's chain and returns it. | medium |
| `ResourceIter_FindOrStartTask` | 0x10073D80 | 204 | yes | - | Finds a task for a resource, or starts one. | low |
| `MeshResourceMng_Evict` | 0x100740C0 | 74 | yes | - | - | - |
| `ResourceIter_PopFreeNode` | 0x10074110 | 36 | yes | - | Pops a node from the free list and returns it. | medium |
| `MeshResourceMng_AllocHandle` | 0x10074140 | 61 | yes | - | - | - |
| `NodePool_ReleaseNode` | 0x10074180 | 83 | yes | - | - | - |
| `ResourceIter_InPoolRange` | 0x100741E0 | 62 | yes | - | Tests whether a pointer and the node it links to lie within the iterator's pool. | low |
| `ResourceIter_SetCurrentGlobal` | 0x10074280 | 10 | yes | - | Stores a value in the current-iterator global at DAT_1047D114. | low |
| `ResourceIter_FindFirst` | 0x100742B0 | 90 | yes | - | - | - |
| `ResourceIter_Start` | 0x10074310 | 99 | yes | - | Starts a resource iteration for a type and id and advances it to the first match. | medium |
| `ResourceIter_MatchCurrent` | 0x10074380 | 67 | yes | - | Tests whether the current node matches the iterator's type and mask. | medium |
| `ResourceIter_Advance` | 0x100743D0 | 466 | yes | - | Advances a resource iterator to the next matching node. | medium |
| `ResourceIter_FindNext` | 0x100745C0 | 15 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `MoRes_FreeIfUnreferenced` calls `Resource_FindSelfLinkedNode`, `CMoResource_Destroy`
- `ResourceIter_FindById` calls nothing directly
- `ResourceIter_FindOrStartTask` calls `TaskAndTextArgs_FindTask`, `Mem_AllocFromArea`, `CMoTask::ResetFields`, `CMoTask::Constructor`, `game_10074A00`, `ResourceLoadTask_Start`
- `MeshResourceMng_Evict` calls `Resource_FindSelfLinkedNode`, `MoRes_FreeIfUnreferenced`
- `ResourceIter_PopFreeNode` calls nothing directly
- `MeshResourceMng_AllocHandle` calls nothing directly
- `NodePool_ReleaseNode` calls nothing directly
- `ResourceIter_InPoolRange` calls nothing directly
- `ResourceIter_SetCurrentGlobal` calls nothing directly
- `ResourceIter_FindFirst` calls `ResourceIter_MatchCurrent`, `ResourceIter_Advance`
- `ResourceIter_Start` calls `ResourceIter_MatchCurrent`, `ResourceIter_Advance`
- `ResourceIter_MatchCurrent` calls nothing directly
- `ResourceIter_Advance` calls `CMoResource::GetParent`
- `ResourceIter_FindNext` calls `ResourceIter_Advance`
