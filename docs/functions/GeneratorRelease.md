# GeneratorRelease

Group: `Generator` (by the file name only). Source: `sdk/tree_src/GeneratorRelease.cpp`.

Why the file has this name (data/unit_names.json): frees resources and attachments (CMoAttachments::ResetAll, YmGenerater_Stop); called from actor destructors

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `GeneratorRelease_Get10353710` | 0x10054410 | 6 | yes | - | Returns the value of the global at 0x10353710. | low |
| `GeneratorRelease_CopyFromPtr` | 0x10054430 | 25 | yes | - | Copies a three-float vector from one address to another. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `GeneratorRelease_Get10353710` calls nothing directly
- `GeneratorRelease_CopyFromPtr` calls nothing directly
