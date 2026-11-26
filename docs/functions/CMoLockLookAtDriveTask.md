# CMoLockLookAtDriveTask

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoLockLookAtDriveTask.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoLockLookAtDriveTask::GetRuntimeClass` | 0x10056980 | 6 | yes | - | - | - |
| `CMoLockLookAtDriveTask::Slot11CallGetRuntimeClass` | 0x10062F80 | 8 | yes | - | Returns what CMoActorColorDriveTask_GetRuntimeClass returns. (reviewed as game_10062F80) | low |
| `CMoLockLookAtDriveTask::Slot12ThunkDeletingDtor` | 0x10062F90 | 8 | yes | - | Moves this back 0x34 bytes and calls the scalar deleting destructor with the flags argument. (reviewed as game_10062F90) | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoLockLookAtDriveTask::GetRuntimeClass` calls nothing directly
- `CMoLockLookAtDriveTask::Slot11CallGetRuntimeClass` calls `CMoActorColorDriveTask::GetRuntimeClass`
- `CMoLockLookAtDriveTask::Slot12ThunkDeletingDtor` calls `game_1005F990`
