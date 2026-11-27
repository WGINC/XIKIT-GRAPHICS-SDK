# sqinCluster

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqinCluster.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `sqinCluster_Create` | 0x102AF540 | 38 | yes | - | - | - |
| `sqinCluster_Init` | 0x102AF570 | 83 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `sqinCluster_Create` calls `game_10275D80`, `sqinCluster_Init`
- `sqinCluster_Init` calls `SqdfShape_InitCallbacks`, `SqMatrixConnect_SetIdentity`
