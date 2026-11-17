# CMoResource_VT_1032C828

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoResource_VT_1032C828.cpp`.

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoResource_VT_1032C828::vf004` | 0x10034170 | 12 | yes | - | Stores its argument through the pointer held at +0x14 and returns it. (reviewed as sub_10034170) | low |
| `CMoResource_VT_1032C828::vf005` | 0x10034180 | 3 | yes | - | - | - |
| `CMoResource_VT_1032C828::vf009` | 0x100719E0 | 1 | yes | - | - | - |
| `CMoResource_VT_1032C828::ScalarDeletingDtor` | 0x10071AA0 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoResource_VT_1032C828::vf004` calls nothing directly
- `CMoResource_VT_1032C828::vf005` calls nothing directly
- `CMoResource_VT_1032C828::vf009` calls nothing directly
- `CMoResource_VT_1032C828::ScalarDeletingDtor` calls `CMoResource::Destructor`, `SharedDeleteHelper`
