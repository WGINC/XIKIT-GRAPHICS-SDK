# sqIO

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqIO.cpp`.

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqIO_SwapBytes` | 0x10292130 | 164 | yes | - | Reverses the byte order of each element of an array in place, warning when the element size is odd. | high |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqIO_SwapBytes` calls `sqDebugPrintf`
