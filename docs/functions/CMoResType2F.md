# CMoResType2F

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoResType2F.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoResType2F::ScalarDeletingDtor` | 0x101893D0 | 30 | yes | - | - | - |
| `CMoResType2F::SetupNop` | 0x101893F0 | 1 | yes | - | Setup that does nothing. (reviewed as sub_101893F0) | high |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoResType2F::ScalarDeletingDtor` calls `CMoResource::Destructor`, `SharedDeleteHelper`
- `CMoResType2F::SetupNop` calls nothing directly
