# CMoKeyFrameRes

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoKeyFrameRes.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoKeyFrameRes::SetupNop` | 0x10054480 | 1 | yes | - | Setup that does nothing. (reviewed as game_10054480) | high |
| `CMoKeyFrameRes::Slot9Nop` | 0x10054490 | 1 | yes | - | Does nothing. (reviewed as game_10054490) | high |
| `CMoKeyFrameRes::ScalarDeletingDtor` | 0x10071C40 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoKeyFrameRes::SetupNop` calls nothing directly
- `CMoKeyFrameRes::Slot9Nop` calls nothing directly
- `CMoKeyFrameRes::ScalarDeletingDtor` calls `CMoResource::Destructor`, `SharedDeleteHelper`
