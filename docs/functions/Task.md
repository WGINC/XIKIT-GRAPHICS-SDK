# Task

Group: `Task` (by the file name only). Source: `sdk/tree_src/Task.cpp`.

Why the file has this name (data/unit_names.json): CMoTask::Clone / Release / Destructor / ResetFields, CMoTaskMng::Forward10075120

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Task_Remove` | 0x100747F0 | 83 | yes | - | Removes a task from the task list. | medium |
| `Task_RunAsCurrent` | 0x100748C0 | 37 | yes | - | Runs an object's slot-8 method with it set as the current object. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Task_Remove` calls nothing directly
- `Task_RunAsCurrent` calls nothing directly
