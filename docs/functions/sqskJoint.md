# sqskJoint

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqskJoint.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqskJoint_Create` | 0x10291360 | 35 | yes | - | Creates and initialises a new sqskJoint object. | medium |
| `SqskJoint_Init` | 0x10291390 | 134 | yes | - | Initialises a sqskJoint object with its callbacks, sub-objects and unit scale. | medium |
| `SqskJoint_Nop` | 0x10291460 | 1 | yes | - | Does nothing. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqskJoint_Create` calls `game_10275D80`, `SqskJoint_Init`
- `SqskJoint_Init` calls `SqxfXformM_Init`, `SqVec_ZeroDwords`, `SqQuat_SetIdentityFwd`, `SqVec_SetXyz`
- `SqskJoint_Nop` calls nothing directly
