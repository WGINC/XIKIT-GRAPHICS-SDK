# CMoResType5E

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoResType5E.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoResType5E::SetupNop` | 0x10038920 | 1 | yes | - | Setup that does nothing. (reviewed as game_10038920) | high |
| `CMoResType5E::Slot9Nop` | 0x10071A10 | 1 | yes | - | Does nothing. (reviewed as game_10071A10) | high |
| `CMoResType5E::ScalarDeletingDtor` | 0x10071B00 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoResType5E::SetupNop` calls nothing directly
- `CMoResType5E::Slot9Nop` calls nothing directly
- `CMoResType5E::ScalarDeletingDtor` calls `CMoResource::Destructor`, `SharedDeleteHelper`
