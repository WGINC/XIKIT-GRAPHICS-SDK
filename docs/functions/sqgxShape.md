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

- `sqgxShapeIndexBufferBegin` calls `game_10312F96`
- `SqgxShape_FillBuffers` calls `game_10311C2C`
- `sqgxShapeBegin` calls `game_1028BB10`, `game_1029C950`, `game_1028A770`, `game_1028BB70`, `game_1028A790`, `game_1029C610`, `game_1029C480`, `game_1029BF50`, `game_10297320`, `game_1029BD50`, `game_10284EC0`, `SqgxContext_NoOpA`, `sqgxMatrixUpdate`, `sqgxColorUpdate`, `sqgxTextureUpdate`, `game_10311C2C`
