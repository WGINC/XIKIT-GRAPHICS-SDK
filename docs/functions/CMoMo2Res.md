# CMoMo2Res

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoMo2Res.cpp`.

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoMo2Res::Slot4StoreInHandle` | 0x10019A30 | 12 | yes | - | Stores a value in the slot the object's handle points to. (reviewed as sub_10019A30) | high |
| `CMoMo2Res::Slot5Nop` | 0x10019A40 | 3 | yes | - | Does nothing. (reviewed as sub_10019A40) | high |
| `CMoMo2Res::Slot9Nop` | 0x10071A00 | 1 | yes | - | Does nothing. (reviewed as sub_10071A00) | high |
| `CMoMo2Res::ScalarDeletingDtor` | 0x10071AC0 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoMo2Res::Slot4StoreInHandle` calls nothing directly
- `CMoMo2Res::Slot5Nop` calls nothing directly
- `CMoMo2Res::Slot9Nop` calls nothing directly
- `CMoMo2Res::ScalarDeletingDtor` calls `CMoResource::Destructor`, `SharedDeleteHelper`
