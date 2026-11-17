# ByteSwap

Group: `Byte` (by the file name only). Source: `sdk/tree_src/ByteSwap.cpp`.

Why the file has this name (data/unit_names.json): Swap16, Swap32, ByteSwap32 only; called by the zip, file and message readers

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ByteSwap_Swap16` | 0x1000D100 | 21 | yes | - | Swaps the bytes of a 16-bit value. | medium |
| `ByteSwap_Swap32` | 0x1000D120 | 40 | yes | - | Reverses the byte order of a 32-bit value. | medium |
| `ByteSwap_ByteSwap32` | 0x1000D150 | 40 | yes | - | Reverses the byte order of a 32-bit value. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ByteSwap_Swap16` calls nothing directly
- `ByteSwap_Swap32` calls nothing directly
- `ByteSwap_ByteSwap32` calls nothing directly
