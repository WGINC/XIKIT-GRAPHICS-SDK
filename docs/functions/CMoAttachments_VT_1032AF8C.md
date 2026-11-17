# CMoAttachments_VT_1032AF8C

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoAttachments_VT_1032AF8C.cpp`.

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoAttachments_VT_1032AF8C::vf001` | 0x10043DC0 | 8 | yes | - | Deleting-destructor thunk: adjusts this and forwards to CMoTask_VT_1032AFA8_ScalarDeletingDtor. (reviewed as sub_10043DC0) | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoAttachments_VT_1032AF8C::vf001` calls `CMoTask_VT_1032AFA8::ScalarDeletingDtor`
