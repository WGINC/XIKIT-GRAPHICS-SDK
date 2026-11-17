# SqScriptRead

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqScriptRead.cpp`.

Why the file has this name (data/unit_names.json): sqScript_TokenEquals, ReadBlock, Sq_PrintIndent

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Sq_PrintIndent` | 0x1028A0B0 | 27 | yes | - | Prints n spaces of indentation for a debug dump. | medium |
| `SqScriptRead_ReturnZero` | 0x1028A0E0 | 3 | yes | - | Returns 0. | low |
| `SqScriptRead_ReadBlock` | 0x1028A0F0 | 96 | yes | - | Reads a block from a stream into a buffer and returns the position after it. | medium |
| `sqScript_TokenEquals` | 0x1028A150 | 123 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Sq_PrintIndent` calls `sqDebugPrintf`
- `SqScriptRead_ReturnZero` calls nothing directly
- `SqScriptRead_ReadBlock` calls `SqNibbleSwap_SwapNibblesXor`, `SqScriptRead_ReturnZero`, `SqIO_SwapBytes`
- `sqScript_TokenEquals` calls `sub_103145A4`
