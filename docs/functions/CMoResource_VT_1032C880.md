# CMoResource_VT_1032C880

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoResource_VT_1032C880.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoResource_VT_1032C880::vf004` | 0x1001E050 | 12 | yes | - | Stores its argument through the resource's +0x14 pointer. (reviewed as sub_1001E050) | low |
| `CMoResource_VT_1032C880::vf005` | 0x1001E060 | 3 | yes | - | - | - |
| `CMoResource_VT_1032C880::ScalarDeletingDtor` | 0x10071A60 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoResource_VT_1032C880::vf004` calls nothing directly
- `CMoResource_VT_1032C880::vf005` calls nothing directly
- `CMoResource_VT_1032C880::ScalarDeletingDtor` calls `CMoResource::Destructor`, `SharedDeleteHelper`
