# CMoSchOp1DTask

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoSchOp1DTask.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoSchOp1DTask::Slot11GetPathDriveActorRuntimeClass` | 0x10063130 | 8 | yes | - | Returns CMoPathDriveActorTask's class descriptor. (reviewed as game_10063130) | high |
| `CMoSchOp1DTask::Slot12DeletePathDriveActorTask` | 0x10063140 | 8 | yes | - | Deletes the CMoPathDriveActorTask this is a member of. (reviewed as game_10063140) | high |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoSchOp1DTask::Slot11GetPathDriveActorRuntimeClass` calls `CMoPathDriveActorTask::GetRuntimeClass`
- `CMoSchOp1DTask::Slot12DeletePathDriveActorTask` calls `game_1005F2C0`
