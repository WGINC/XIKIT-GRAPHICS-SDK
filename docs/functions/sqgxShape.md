# sqgxShape

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqgxShape.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `sqgxShapeIndexBufferBegin` | 0x1028AA70 | 218 | yes | 0 | - | - |
| `SqgxShape_FillBuffers` | 0x1028AB50 | 1137 | yes | 0 | Locks each shape buffer, fills it from the context arrays and unlocks it. | medium |
| `sqgxShapeBegin` | 0x1028AFE0 | 2857 | yes | 0 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `sqgxShapeIndexBufferBegin` calls `sub_10312F96`
- `SqgxShape_FillBuffers` calls `sub_10311C2C`
- `sqgxShapeBegin` calls `sub_1028BB10`, `sub_1029C950`, `sub_1028A770`, `sub_1028BB70`, `sub_1028A790`, `sub_1029C610`, `sub_1029C480`, `sub_1029BF50`, `sub_10297320`, `sub_1029BD50`, `sub_10284EC0`, `SqgxContext_NoOpA`, `sqgxMatrixUpdate`, `sqgxColorUpdate`, `sqgxTextureUpdate`, `sub_10311C2C`
