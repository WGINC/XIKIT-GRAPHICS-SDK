# CMoSk2Res

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoSk2Res.cpp`.

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoSk2Res::Slot4StoreInHandle` | 0x10034170 | 12 | yes | - | Stores a value in the slot the object's handle points to. (reviewed as sub_10034170) | high |
| `CMoSk2Res::Slot5Nop` | 0x10034180 | 3 | yes | - | Does nothing. (reviewed as sub_10034180) | high |
| `CMoSk2Res::Slot9Nop` | 0x100719E0 | 1 | yes | - | Does nothing. (reviewed as sub_100719E0) | high |
| `CMoSk2Res::ScalarDeletingDtor` | 0x10071AA0 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoSk2Res::Slot4StoreInHandle` calls nothing directly
- `CMoSk2Res::Slot5Nop` calls nothing directly
- `CMoSk2Res::Slot9Nop` calls nothing directly
- `CMoSk2Res::ScalarDeletingDtor` calls `CMoResource::Destructor`, `SharedDeleteHelper`
