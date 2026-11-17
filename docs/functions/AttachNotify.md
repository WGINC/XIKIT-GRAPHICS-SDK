# AttachNotify

Group: `Attach` (by the file name only). Source: `sdk/tree_src/AttachNotify.cpp`.

Why the file has this name (data/unit_names.json): CMoAttachments::NotifyCaster / NotifyTarget

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `AttachNotify_CopyFields` | 0x1003C740 | 140 | yes | - | Copies the packed flag fields of one record into another. | low |
| `AttachNotify_GetFactorFromAttachments` | 0x1003C7D0 | 159 | yes | - | Picks 1.0, 0.5 or the given value from flags and what two attached objects report. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `AttachNotify_CopyFields` calls nothing directly
- `AttachNotify_GetFactorFromAttachments` calls `CMoAttachments::FindKindInChain`, `CMoAttachments::FindKindFromRoot`
