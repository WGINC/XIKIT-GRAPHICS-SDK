# sqMatrix4

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqMatrix4.cpp`.

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `sqMatrix4_1027FCC0` | 0x1027FCC0 | 418 | yes | - | - | - |
| `sqMatrix4_10280140` | 0x10280140 | 532 | yes | - | - | - |
| `SqMatrix4_SetFields` | 0x10280650 | 37 | yes | - | Initialises the object and stores three values at offsets 0xC, 0x1C and 0x2C. | low |
| `SqMatrix4_ScaleAxes` | 0x102806B0 | 49 | yes | - | Scales the x, y and z axes of a 3x4 matrix block by three factors. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `sqMatrix4_1027FCC0` calls `SqMatrixSet_Set`, `SqMatrix3_Determinant`
- `sqMatrix4_10280140` calls nothing directly
- `SqMatrix4_SetFields` calls `SqMatrixConnect_SetIdentity`
- `SqMatrix4_ScaleAxes` calls nothing directly
