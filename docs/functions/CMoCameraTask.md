# CMoCameraTask

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoCameraTask.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoCameraTask::GetRuntimeClass` | 0x1003CC70 | 6 | yes | - | - | - |
| `CMoCameraTask::ScalarDeletingDtor` | 0x1003D010 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoCameraTask::GetRuntimeClass` calls nothing directly
- `CMoCameraTask::ScalarDeletingDtor` calls `sub_1003D030`, `SharedDeleteHelper`
