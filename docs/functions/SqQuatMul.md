# SqQuatMul

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqQuatMul.cpp`.

Why the file has this name (data/unit_names.json): Mul, NegateInPlace, RotateVec, Sq_PrintFloat4Indented

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqQuatMul_NegateInPlace` | 0x1027B060 | 27 | yes | - | Negates a three-float vector in place. | medium |
| `SqQuatMul_RotateVec` | 0x1027B080 | 234 | yes | - | Rotates a vector by a quaternion into a four-float destination. | low |
| `SqQuatMul_Mul` | 0x1027B170 | 136 | yes | - | Multiplies two four-float quaternions into a destination. | medium |
| `Sq_PrintFloat4Indented` | 0x1027B480 | 57 | yes | - | Debug-prints four floats on one line after an indent of arg3 spaces. | high |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqQuatMul_NegateInPlace` calls nothing directly
- `SqQuatMul_RotateVec` calls `SqQuat_Copy`, `SqQuatMul_NegateInPlace`
- `SqQuatMul_Mul` calls nothing directly
- `Sq_PrintFloat4Indented` calls `Sq_PrintIndent`, `sqDebugPrintf`
