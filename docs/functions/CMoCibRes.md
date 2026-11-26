# CMoCibRes

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoCibRes.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoCibRes::SetupNop` | 0x100719C0 | 1 | yes | - | Setup that does nothing. (reviewed as game_100719C0) | high |
| `CMoCibRes::Slot9Nop` | 0x100719D0 | 1 | yes | - | Does nothing. (reviewed as game_100719D0) | high |
| `CMoCibRes::ScalarDeletingDtor` | 0x10071AE0 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoCibRes::SetupNop` calls nothing directly
- `CMoCibRes::Slot9Nop` calls nothing directly
- `CMoCibRes::ScalarDeletingDtor` calls `CMoResource::Destructor`, `SharedDeleteHelper`
