# CMoDxStatusMng

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoDxStatusMng.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoDxStatusMng::GetRuntimeClass` | 0x1006B040 | 6 | yes | - | - | - |
| `CMoDxStatusMng::Constructor` | 0x1006B050 | 19 | yes | - | - | - |
| `CMoDxStatusMng::ScalarDeletingDtor` | 0x1006B070 | 30 | yes | 2 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoDxStatusMng::GetRuntimeClass` calls nothing directly
- `CMoDxStatusMng::Constructor` calls `MoDX_SetInvalid`
- `CMoDxStatusMng::ScalarDeletingDtor` calls `sub_1006B090`, `thunk_sub_10028AA0`
