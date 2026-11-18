# CMoUseMagicWaitTaskAttachments

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoUseMagicWaitTaskAttachments.cpp`.

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoUseMagicWaitTaskAttachments::Slot1DeleteOwner` | 0x100AB060 | 8 | yes | - | Deletes the object this attachments member belongs to. (reviewed as sub_100AB060) | high |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoUseMagicWaitTaskAttachments::Slot1DeleteOwner` calls `CMoUseMagicWaitTask::ScalarDeletingDtor`
