# CMoGeneratorResAttachments

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoGeneratorResAttachments.cpp`.

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoGeneratorResAttachments::Slot1DeleteOwner` | 0x10054450 | 8 | yes | - | Deletes the object this attachments member belongs to. (reviewed as sub_10054450) | high |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoGeneratorResAttachments::Slot1DeleteOwner` calls `CMoGeneratorRes::ScalarDeletingDtor`
