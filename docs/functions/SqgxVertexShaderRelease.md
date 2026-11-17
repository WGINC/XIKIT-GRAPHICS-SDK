# SqgxVertexShaderRelease

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqgxVertexShaderRelease.cpp`.

Why the file has this name (data/unit_names.json): sqgxVertexShaderRelease

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqgxVertexShaderRelease_NoOp` | 0x10284EB0 | 1 | yes | - | Does nothing. | low |
| `sqgxVertexShaderRelease` | 0x10284EF0 | 47 | yes | 0 | - | - |
| `SqgxVertexShaderRelease_GetFloat20` | 0x10284F20 | 8 | yes | - | Returns the float at +0x20 of its argument. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqgxVertexShaderRelease_NoOp` calls nothing directly
- `sqgxVertexShaderRelease` calls nothing directly
- `SqgxVertexShaderRelease_GetFloat20` calls nothing directly
