# CMoOT

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoOT.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoOT::GetRuntimeClass` | 0x10055290 | 6 | yes | - | - | - |
| `CMoOT::Constructor` | 0x100552A0 | 18 | yes | - | Constructs a CMoOT object and sets its vtable. (reviewed as sub_100552A0) | medium |
| `CMoOT::ScalarDeletingDtor` | 0x100552C0 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoOT::GetRuntimeClass` calls nothing directly
- `CMoOT::Constructor` calls `OtLink_ClearLink`
- `CMoOT::ScalarDeletingDtor` calls `sub_100552E0`, `thunk_sub_10028AA0`
