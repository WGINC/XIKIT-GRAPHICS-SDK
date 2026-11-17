# sqxfXformTD

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqxfXformTD.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `sqxfXformTD_Init` | 0x1026DF00 | 79 | yes | - | - | - |
| `sqxfXformTD_Update` | 0x1026E1F0 | 150 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `sqxfXformTD_Init` calls `SqxfXformM_Init`, `SqVec_ZeroDwords`, `SqQuat_SetIdentityFwd`
- `sqxfXformTD_Update` calls `SqQuat_ToMatrix3`
