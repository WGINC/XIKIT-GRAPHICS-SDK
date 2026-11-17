# CMoBm2Res

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoBm2Res.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoBm2Res::ReleaseTexture` | 0x1001DBD0 | 72 | yes | - | Finds the texture named by the resource's 16-byte name, drops one reference and releases the texture when none remain. (reviewed as sub_1001DBD0) | medium |
| `CMoBm2Res::Slot4StoreInHandle` | 0x1001DC20 | 12 | yes | - | Stores a value in the slot the object's handle points to. (reviewed as sub_1001DC20) | high |
| `CMoBm2Res::ScalarDeletingDtor` | 0x10071A40 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoBm2Res::ReleaseTexture` calls `Util_Copy16Bytes`, `TexMgr_FindByName`, `TexObj_Release`
- `CMoBm2Res::Slot4StoreInHandle` calls nothing directly
- `CMoBm2Res::ScalarDeletingDtor` calls `CMoResource::Destructor`, `SharedDeleteHelper`
