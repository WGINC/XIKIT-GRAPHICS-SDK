# ProcessorMatrix

Group: `Processor` (by the file name only). Source: `sdk/tree_src/ProcessorMatrix.cpp`.

Why the file has this name (data/unit_names.json): CMoProcessorX87_SetIdentity, MultiplyTo

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoProcessorX87_SetIdentity` | 0x1006D0A0 | 222 | yes | - | Writes the 4x4 identity matrix to the argument. (reviewed as sub_1006D0A0) | medium |
| `ProcessorMatrix_InvertMat4InPlace` | 0x1006D190 | 216 | yes | - | Inverts the 4x4 float matrix at its argument in place (Gauss-Jordan, no row exchange; a zero pivot is replaced by a small constant). | medium |
| `ProcessorMatrix_MultiplyTo` | 0x1006D270 | 135 | yes | - | Multiplies two 4x4 matrices and writes the product to the output. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoProcessorX87_SetIdentity` calls `sub_10313486`
- `ProcessorMatrix_InvertMat4InPlace` calls nothing directly
- `ProcessorMatrix_MultiplyTo` calls nothing directly
