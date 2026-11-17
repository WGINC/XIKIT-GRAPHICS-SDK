# CMoResource_VT_1032C7FC

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoResource_VT_1032C7FC.cpp`.

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoResource_VT_1032C7FC::vf004` | 0x10019A30 | 12 | yes | - | Stores the argument through the object's pointer at +0x14 and returns it. (reviewed as sub_10019A30) | low |
| `CMoResource_VT_1032C7FC::vf005` | 0x10019A40 | 3 | yes | - | Does nothing; the vtable's slot 5. (reviewed as sub_10019A40) | low |
| `CMoResource_VT_1032C7FC::vf009` | 0x10071A00 | 1 | yes | - | Does nothing; the vtable's slot 9. (reviewed as sub_10071A00) | low |
| `CMoResource_VT_1032C7FC::ScalarDeletingDtor` | 0x10071AC0 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoResource_VT_1032C7FC::vf004` calls nothing directly
- `CMoResource_VT_1032C7FC::vf005` calls nothing directly
- `CMoResource_VT_1032C7FC::vf009` calls nothing directly
- `CMoResource_VT_1032C7FC::ScalarDeletingDtor` calls `CMoResource::Destructor`, `SharedDeleteHelper`
