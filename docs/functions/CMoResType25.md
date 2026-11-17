# CMoResType25

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoResType25.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoResType25::Slot9Nop` | 0x1003F430 | 1 | yes | - | Does nothing. (reviewed as sub_1003F430) | high |
| `CMoResType25::ScalarDeletingDtor` | 0x10071B90 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoResType25::Slot9Nop` calls nothing directly
- `CMoResType25::ScalarDeletingDtor` calls `CMoResource::Destructor`, `SharedDeleteHelper`
