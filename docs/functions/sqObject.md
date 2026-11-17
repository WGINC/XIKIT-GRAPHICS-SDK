# sqObject

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqObject.cpp`.

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqObject_Release` | 0x10285740 | 57 | yes | - | Releases a sq object through its type's release function. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqObject_Release` calls `sqDebugPrintf`
