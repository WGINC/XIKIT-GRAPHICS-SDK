# sqhiNode

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqhiNode.cpp`.

5 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqhiNode_Create` | 0x10291B70 | 35 | yes | - | Creates a sqhiNode object. | medium |
| `SqhiNode_Init` | 0x10291BA0 | 109 | yes | - | Initialises a sqhiNode object and its transform matrix. | medium |
| `SqhiNode_Nop` | 0x10291C50 | 1 | yes | - | Does nothing. | low |
| `SqhiNode_SetField64` | 0x10291F00 | 16 | yes | - | Sets a node's field at +0x64. | low |
| `SqhiNode_AppendChild` | 0x10291F10 | 44 | yes | - | Appends a node to the end of a node's child list. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqhiNode_Create` calls `game_10275D80`, `SqhiNode_Init`
- `SqhiNode_Init` calls `SqMatrixConnect_SetIdentity`, `SqMatrixConnect_Zero`, `game_1027EB10`
- `SqhiNode_Nop` calls nothing directly
- `SqhiNode_SetField64` calls nothing directly
- `SqhiNode_AppendChild` calls nothing directly
