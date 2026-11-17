# SqgxVertexShader

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqgxVertexShader.cpp`.

Why the file has this name (data/unit_names.json): sqgxVertexShaderCreate / Select

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `sqgxVertexShaderCreate` | 0x10284950 | 302 | yes | 0 | - | - |
| `sqgxVertexShaderSelect` | 0x10284A80 | 155 | yes | 0 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `sqgxVertexShaderCreate` calls nothing directly
- `sqgxVertexShaderSelect` calls `sqgxVertexShaderCreate`
