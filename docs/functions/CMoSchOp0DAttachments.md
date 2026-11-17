# CMoSchOp0DAttachments

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoSchOp0DAttachments.cpp`.

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoSchOp0DAttachments::Slot1DeleteOwner` | 0x10043DB0 | 8 | yes | - | Deletes the object this attachments member belongs to. (reviewed as sub_10043DB0) | high |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoSchOp0DAttachments::Slot1DeleteOwner` calls `CMoSchOp0DTask::ScalarDeletingDtor`
