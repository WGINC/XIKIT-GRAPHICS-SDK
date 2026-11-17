# MeshResourceMng

Group: `Mesh` (by the file name only). Source: `sdk/tree_src/MeshResourceMng.cpp`.

Why the file has this name (data/unit_names.json): MeshResourceMng_LoadSystemResources / ResolveTree, CMoResource::FindOrCreateTask, ResourceHandle_Deref

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `MeshResourceMng_LoadSystemResources` | 0x10072ED0 | 220 | yes | - | - | - |
| `ResourceHandle_Deref` | 0x10072FB0 | 18 | yes | - | - | - |
| `MeshResourceMng_ResolveTree` | 0x10073430 | 766 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `MeshResourceMng_LoadSystemResources` calls `sub_10072FD0`, `sub_10071E90`, `sub_10071E50`, `sub_100731B0`, `CMoResource::FindByTypeAndId`
- `ResourceHandle_Deref` calls nothing directly
- `MeshResourceMng_ResolveTree` calls `MeshResourceMng_CreateResourceByKind`, `NodePool_ReleaseNode`, `CMoResource::RegisterInTypeList`, `sub_10071F70`, `MeshResourceMng_AllocHandle`, `MeshResourceCreate_CopyField14At4`, `MeshResourceCreate_CopyField14At0`, `Mem_AllocWithFallback`, `CMoResource_ConstructBase`, `CMoTask::SetRect30`, `CMoResource::RegisterAndMark`, `sub_10071E50`
