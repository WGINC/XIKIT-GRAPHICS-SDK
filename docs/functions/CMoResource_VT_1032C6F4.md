# CMoResource_VT_1032C6F4

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoResource_VT_1032C6F4.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoResource_VT_1032C6F4::vf009` | 0x1003F430 | 1 | yes | - | Does nothing; the vtable's slot 9. (reviewed as sub_1003F430) | low |
| `CMoResource_VT_1032C6F4::ScalarDeletingDtor` | 0x10071B90 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoResource_VT_1032C6F4::vf009` calls nothing directly
- `CMoResource_VT_1032C6F4::ScalarDeletingDtor` calls `CMoResource::Destructor`, `SharedDeleteHelper`
