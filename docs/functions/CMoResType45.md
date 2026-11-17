# CMoResType45

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoResType45.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoResType45::SetupNop` | 0x100719C0 | 1 | yes | - | Setup that does nothing. (reviewed as sub_100719C0) | high |
| `CMoResType45::Slot9Nop` | 0x100719D0 | 1 | yes | - | Does nothing. (reviewed as sub_100719D0) | high |
| `CMoResType45::ScalarDeletingDtor` | 0x10071AE0 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoResType45::SetupNop` calls nothing directly
- `CMoResType45::Slot9Nop` calls nothing directly
- `CMoResType45::ScalarDeletingDtor` calls `CMoResource::Destructor`, `SharedDeleteHelper`
