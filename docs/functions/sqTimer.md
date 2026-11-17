# sqTimer

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqTimer.cpp`.

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqTimer_GetMicroseconds` | 0x10275090 | 175 | yes | - | Returns a running time in microseconds from the performance counter, starting it on the first call. | high |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqTimer_GetMicroseconds` calls `sqDebugPrintf`, `sub_10311C2C`
