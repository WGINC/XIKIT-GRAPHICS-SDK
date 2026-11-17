# CMoCelestial

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoCelestial.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoCelestial::GetRuntimeClass` | 0x1003D940 | 6 | yes | - | - | - |
| `CMoCelestial::ScalarDeletingDtor` | 0x1003D960 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoCelestial::GetRuntimeClass` calls nothing directly
- `CMoCelestial::ScalarDeletingDtor` calls `sub_1003D980`, `thunk_sub_10028AA0`
