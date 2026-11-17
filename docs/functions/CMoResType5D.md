# CMoResType5D

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoResType5D.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoResType5D::Slot4StoreInHandle` | 0x1001E050 | 12 | yes | - | Stores a value in the slot the object's handle points to. (reviewed as sub_1001E050) | high |
| `CMoResType5D::Slot5Nop` | 0x1001E060 | 3 | yes | - | Does nothing. (reviewed as sub_1001E060) | high |
| `CMoResType5D::ScalarDeletingDtor` | 0x10071A60 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoResType5D::Slot4StoreInHandle` calls nothing directly
- `CMoResType5D::Slot5Nop` calls nothing directly
- `CMoResType5D::ScalarDeletingDtor` calls `CMoResource::Destructor`, `SharedDeleteHelper`
