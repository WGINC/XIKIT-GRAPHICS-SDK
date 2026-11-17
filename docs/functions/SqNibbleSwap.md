# SqNibbleSwap

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqNibbleSwap.cpp`.

Why the file has this name (data/unit_names.json): SwapNibblesXor; called from the readers (sqIO, sqimImage)

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqNibbleSwap_SwapNibblesXor` | 0x10292490 | 48 | yes | - | Scrambles a buffer by XOR with a key and swapping nibbles. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqNibbleSwap_SwapNibblesXor` calls nothing directly
