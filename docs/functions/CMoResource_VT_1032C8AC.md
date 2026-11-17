# CMoResource_VT_1032C8AC

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoResource_VT_1032C8AC.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoResource_VT_1032C8AC::ReleaseTexture` | 0x1001DBD0 | 72 | yes | - | Finds the texture named by the resource's 16-byte name, drops one reference and releases the texture when none remain. (reviewed as sub_1001DBD0) | medium |
| `CMoResource_VT_1032C8AC::vf004` | 0x1001DC20 | 12 | yes | - | Stores the argument through the object's pointer at +0x14 and returns it. (reviewed as sub_1001DC20) | low |
| `CMoResource_VT_1032C8AC::ScalarDeletingDtor` | 0x10071A40 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoResource_VT_1032C8AC::ReleaseTexture` calls `Util_Copy16Bytes`, `TexMgr_FindByName`, `TexObj_Release`
- `CMoResource_VT_1032C8AC::vf004` calls nothing directly
- `CMoResource_VT_1032C8AC::ScalarDeletingDtor` calls `CMoResource::Destructor`, `SharedDeleteHelper`
