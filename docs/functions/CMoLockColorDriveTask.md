# CMoLockColorDriveTask

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoLockColorDriveTask.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoLockColorDriveTask::GetRuntimeClass` | 0x10056960 | 6 | yes | - | - | - |
| `CMoLockColorDriveTask::Slot11CallGetRuntimeClass` | 0x100630F0 | 8 | yes | - | Returns what CMoLockLookAtDriveTask_GetRuntimeClass returns. (reviewed as game_100630F0) | low |
| `CMoLockColorDriveTask::Slot12ThunkDeletingDtor` | 0x10063100 | 8 | yes | - | Moves this back 0x34 bytes and calls the scalar deleting destructor with the flags argument. (reviewed as game_10063100) | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoLockColorDriveTask::GetRuntimeClass` calls nothing directly
- `CMoLockColorDriveTask::Slot11CallGetRuntimeClass` calls `CMoLockLookAtDriveTask::GetRuntimeClass`
- `CMoLockColorDriveTask::Slot12ThunkDeletingDtor` calls `game_1005F660`
