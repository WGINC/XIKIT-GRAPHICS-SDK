# sqQuat

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqQuat.cpp`.

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqQuat_Invert` | 0x1027AFB0 | 165 | yes | - | Inverts a quaternion (the identity for a zero one). | high |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqQuat_Invert` calls `sqDebugPrintf`, `Sq_PrintFloat4Indented`, `SqQuat_SetIdentity`
