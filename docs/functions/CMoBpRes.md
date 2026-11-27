# CMoBpRes

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoBpRes.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoBpRes::Slot4StoreInHandle` | 0x1001E050 | 12 | yes | - | Stores a value in the slot the object's handle points to. (reviewed as game_1001E050) | high |
| `CMoBpRes::Slot5Nop` | 0x1001E060 | 3 | yes | - | Does nothing. (reviewed as game_1001E060) | high |
| `CMoBpRes::ScalarDeletingDtor` | 0x10071A60 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoBpRes::Slot4StoreInHandle` calls nothing directly
- `CMoBpRes::Slot5Nop` calls nothing directly
- `CMoBpRes::ScalarDeletingDtor` calls `CMoResource::Destructor`, `SharedDeleteHelper`
