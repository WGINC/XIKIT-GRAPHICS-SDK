# CXiSkeletonActorRes

Group: `CXi` (by the file name only). Source: `sdk/tree_src/CXiSkeletonActorRes.cpp`.

6 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CXiSkeletonActorRes::GetRuntimeClass` | 0x100C51B0 | 6 | yes | - | - | - |
| `CXiSkeletonActorRes::ScalarDeletingDtor` | 0x100D7000 | 30 | yes | - | - | - |
| `CXiSkeletonActorRes::Constructor` | 0x100D7020 | 42 | yes | - | - | - |
| `CXiSkeletonActorRes::Destructor` | 0x100D7050 | 57 | yes | - | - | - |
| `CXiSkeletonActorRes::CXiSkeletonActorRes_GetLinkedActor` | 0x100D7090 | 4 | yes | - | - | - |
| `CXiSkeletonActorRes::ProcessLoadState` | 0x100D70A0 | 145 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CXiSkeletonActorRes::GetRuntimeClass` calls nothing directly
- `CXiSkeletonActorRes::ScalarDeletingDtor` calls `CXiSkeletonActorRes::Destructor`, `SharedDeleteHelper`
- `CXiSkeletonActorRes::Constructor` calls `CMoTask::Constructor`
- `CXiSkeletonActorRes::Destructor` calls `CXiSkeletonActorRes::CXiSkeletonActorRes_GetLinkedActor`, `CMoTask::Destructor`
- `CXiSkeletonActorRes::CXiSkeletonActorRes_GetLinkedActor` calls nothing directly
- `CXiSkeletonActorRes::ProcessLoadState` calls `CXiSkeletonActorRes::CXiSkeletonActorRes_GetLinkedActor`, `CXiActor::GetModelByteEE`
