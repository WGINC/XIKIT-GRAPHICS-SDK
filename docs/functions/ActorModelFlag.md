# ActorModelFlag

Group: `Actor` (by the file name only). Source: `sdk/tree_src/ActorModelFlag.cpp`.

Why the file has this name (data/unit_names.json): GetModelFlag130Bit21 (one model flag); called from actor and skeleton code

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ActorModelFlag_GetModelFlag130Bit21` | 0x10083340 | 23 | yes | - | Returns bit 21 of the model's flags word at offset 0x130. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ActorModelFlag_GetModelFlag130Bit21` calls nothing directly
