# ResourceLoadTask

Group: `Resource` (by the file name only). Source: `sdk/tree_src/ResourceLoadTask.cpp`.

Why the file has this name (data/unit_names.json): Start and Step of the resource load task; called from ResourceIter_FindOrStartTask and CMoResource::FindOrCreateTask

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ResourceLoadTask_Step` | 0x10072A70 | 446 | yes | - | Advances a mesh load task through its file reads. | low |
| `ResourceLoadTask_Start` | 0x10072C30 | 69 | yes | - | Starts a mesh load task for a file id. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ResourceLoadTask_Step` calls `TextInputFiles_FileMngFindFileNumKind1`, `ResourceIter_SetCurrentGlobal`, `MeshResourceMng_ResolveTree`, `ErrorReport_NoOpVarargsA`, `game_101C4AD0`, `Allocator_Generic`, `game_101C46D0`, `NodePool_ReleaseNode`, `TextInputFiles_CtorVt10337C60`, `game_101C4BC0`
- `ResourceLoadTask_Start` calls `game_100749B0`, `ResourceIter_PopFreeNode`
