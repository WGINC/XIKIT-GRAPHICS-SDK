# sqmoUtil

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqmoUtil.cpp`.

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqmoUtil_MarkSlot` | 0x1027D650 | 97 | yes | - | Marks a slot of a slot array as used and reports whether any slot is still free. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqmoUtil_MarkSlot` calls `sqDebugPrintf`
