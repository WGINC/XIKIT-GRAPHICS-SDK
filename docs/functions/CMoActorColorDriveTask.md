# CMoActorColorDriveTask

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoActorColorDriveTask.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoActorColorDriveTask::GetRuntimeClass` | 0x100569A0 | 6 | yes | - | - | - |
| `CMoActorColorDriveTask::Slot11CallGetRuntimeClass` | 0x10062FE0 | 8 | yes | - | Returns what CMoActorRotationDriveTask_GetRuntimeClass returns. (reviewed as game_10062FE0) | low |
| `CMoActorColorDriveTask::Slot12ThunkDeletingDtor` | 0x10062FF0 | 8 | yes | - | Moves this back 0x34 bytes and calls the scalar deleting destructor with the flags argument. (reviewed as game_10062FF0) | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoActorColorDriveTask::GetRuntimeClass` calls nothing directly
- `CMoActorColorDriveTask::Slot11CallGetRuntimeClass` calls `CMoActorRotationDriveTask::GetRuntimeClass`
- `CMoActorColorDriveTask::Slot12ThunkDeletingDtor` calls `game_1005FE30`
