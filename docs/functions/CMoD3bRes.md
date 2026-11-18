# CMoD3bRes

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoD3bRes.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoD3bRes::Slot9Nop` | 0x1003F430 | 1 | yes | - | Does nothing. (reviewed as sub_1003F430) | high |
| `CMoD3bRes::ScalarDeletingDtor` | 0x10071B90 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoD3bRes::Slot9Nop` calls nothing directly
- `CMoD3bRes::ScalarDeletingDtor` calls `CMoResource::Destructor`, `SharedDeleteHelper`
