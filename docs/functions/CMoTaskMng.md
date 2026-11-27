# CMoTaskMng

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoTaskMng.cpp`.

11 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoTaskMng::ScalarDeletingDtor` | 0x10011950 | 30 | yes | - | - | - |
| `CMoTaskMng::Forward10075120` | 0x10074A10 | 11 | yes | - | - | - |
| `CMoTaskMng::GetRuntimeClass` | 0x10074B50 | 6 | yes | - | - | - |
| `CMoTaskMng::InitPool` | 0x10074BA0 | 144 | yes | - | Initialises the task manager's node pool, free list and sixteen buckets. (reviewed as game_10074BA0) | medium |
| `CMoTaskMng::DrawAll` | 0x10074C30 | 111 | yes | - | - | - |
| `CMoTaskMng::RemoveByKey` | 0x10074CF0 | 55 | yes | - | Finds the task whose two keys match the arguments and removes it. (reviewed as game_10074CF0) | medium |
| `CMoTaskMng::AllocTask` | 0x10074DF0 | 107 | yes | - | Takes a task node from the free list, resets it and appends it to the task list. (reviewed as game_10074DF0) | medium |
| `CMoTaskMng::InsertIntoBucket` | 0x10074F80 | 127 | yes | - | Links a task node into one of sixteen buckets. (reviewed as game_10074F80) | medium |
| `CMoTaskMng::EnqueueTask` | 0x100750B0 | 103 | yes | - | Appends a task to the queue at +0xD4C, or to bucket 9 when the queue is empty. (reviewed as game_100750B0) | medium |
| `CMoTaskMng::InsertAfterCursor` | 0x10075120 | 138 | yes | - | Inserts a task node after the current cursor in the task list. (reviewed as game_10075120) | low |
| `CMoTaskMng::UnlinkTask` | 0x100751B0 | 107 | yes | - | Removes a task node from the doubly linked lists and repairs their head and tail pointers. (reviewed as game_100751B0) | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoTaskMng::ScalarDeletingDtor` calls `game_10074B60`, `thunk_Mem_FreeBlockMergeNeighbours_as_v0`
- `CMoTaskMng::Forward10075120` calls `CMoTaskMng::InsertAfterCursor`
- `CMoTaskMng::GetRuntimeClass` calls nothing directly
- `CMoTaskMng::InitPool` calls `CMoTask::ResetFields`, `CMoTaskMng::AllocTask`
- `CMoTaskMng::DrawAll` calls nothing directly
- `CMoTaskMng::RemoveByKey` calls `CMoTask::Release`
- `CMoTaskMng::AllocTask` calls `CMoTask::ResetFields`
- `CMoTaskMng::InsertIntoBucket` calls `CMoTaskMng::UnlinkTask`
- `CMoTaskMng::EnqueueTask` calls `CMoTaskMng::UnlinkTask`, `CMoTaskMng::InsertIntoBucket`
- `CMoTaskMng::InsertAfterCursor` calls `CMoTaskMng::UnlinkTask`
- `CMoTaskMng::UnlinkTask` calls nothing directly
