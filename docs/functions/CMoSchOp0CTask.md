# CMoSchOp0CTask

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoSchOp0CTask.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoSchOp0CTask::ScalarDeletingDtor` | 0x10043C90 | 30 | yes | - | - | - |
| `CMoSchOp0CTask::ScalarDeletingDtor_2` | 0x10043E20 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoSchOp0CTask::ScalarDeletingDtor` calls `game_10043CB0`, `SharedDeleteHelper`
- `CMoSchOp0CTask::ScalarDeletingDtor_2` calls `game_10043E40`, `operator_delete`
