# sqgxContext

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqgxContext.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `sqgxContext_Create` | 0x10276260 | 35 | yes | - | - | - |
| `sqgxContext_Init` | 0x10276290 | 1241 | yes | - | - | - |
| `sqgxShader` | 0x10284B20 | 909 | yes | 0 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `sqgxContext_Create` calls `game_10275D80`, `sqgxContext_Init`
- `sqgxContext_Init` calls `PackVec4`, `SqMatrixConnect_SetIdentity`, `SqMatrixConnect_Set`, `SqVec_SetXyz`
- `sqgxShader` calls `SqgxVertexShaderRelease_NoOp`, `sqgxTextureClamp`, `sqgxTextureDecal`
