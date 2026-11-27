# Scheduler

Group: `Scheduler` (by the file name only). Source: `sdk/tree_src/Scheduler.cpp`.

Why the file has this name (data/unit_names.json): Scheduler_AddTask / CreateTask / Kill / RemoveTasksFor

6 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoResource_CopyHeaderAndBodyThenReset` | 0x100569D0 | 115 | yes | - | Copies a resource block's header and body into the object and resets its attachment list at +0x30. | medium |
| `Scheduler_AddTask` | 0x10056AA0 | 28 | yes | - | Adds a task to the scheduler's list. | medium |
| `Scheduler_CreateTask` | 0x10056CE0 | 172 | yes | - | Allocates and initialises a scheduler task for an owner. | medium |
| `Scheduler_RemoveTasksFor` | 0x10056EB0 | 64 | yes | - | Removes every scheduler task that belongs to the given object. | medium |
| `Scheduler_Kill` | 0x10056EF0 | 113 | yes | - | - | - |
| `Scheduler_IsMoving` | 0x10057010 | 109 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoResource_CopyHeaderAndBodyThenReset` calls `CMoAttachments::Reset`
- `Scheduler_AddTask` calls `CMoTaskMng::RemoveByKey`, `game_100720B0`
- `Scheduler_CreateTask` calls `Mem_AllocFromArea`, `CMoTask::ResetFields`, `CMoSchedularTask::Construct`, `AfterimageTask_SetCaster`, `AfterimageTask_SetTarget`
- `Scheduler_RemoveTasksFor` calls `CMoTask::Release`
- `Scheduler_Kill` calls `AfterimageTask_FindFirstKind`, `Scheduler_ResolveOwner`
- `Scheduler_IsMoving` calls `AfterimageTask_FindFirstKind`, `Scheduler_ResolveOwner`
