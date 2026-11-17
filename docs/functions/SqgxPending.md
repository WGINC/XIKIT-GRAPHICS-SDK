# SqgxPending

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqgxPending.cpp`.

Why the file has this name (data/unit_names.json): Sqgx_AddPendingEntry / ResetPendingList / CopyBlockToContext

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Sqgx_CopyBlockToContext` | 0x1029BCD0 | 109 | yes | - | Copies a 16-entry block of values into the graphics context. | low |
| `Sqgx_SetFloat18` | 0x1029BD40 | 13 | yes | - | Stores a float at +0x18 of the graphics context. | low |
| `Sqgx_ResetPendingList` | 0x1029C180 | 45 | yes | - | Clears the pending-entry count and its list. | low |
| `Sqgx_AddPendingEntry` | 0x1029C1B0 | 166 | yes | - | Adds an entry to the pending list, reporting an error when the list is full. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Sqgx_CopyBlockToContext` calls nothing directly
- `Sqgx_SetFloat18` calls nothing directly
- `Sqgx_ResetPendingList` calls nothing directly
- `Sqgx_AddPendingEntry` calls `sqDebugPrintf`
