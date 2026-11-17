# SqMatrixConnect

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqMatrixConnect.cpp`.

Why the file has this name (data/unit_names.json): M4fTransform, M4fTranspose, IsConnected, ReleaseConnection, SetCallback

14 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqMatrixConnect_UpdateMask` | 0x1027E150 | 52 | yes | - | Sets, clears or toggles a bit mask in a flag word. | medium |
| `SqMatrixConnect_SetCallback` | 0x1027E190 | 19 | yes | - | Sets the callback and its argument at +0x60/+0x64. | low |
| `SqMatrixConnect_ReleaseConnection` | 0x1027E3B0 | 82 | yes | - | Frees the object's connected resource and resets its connector. | low |
| `SqMatrixConnect_IsConnected` | 0x1027E440 | 14 | yes | - | Reports whether the flag bit 2 (connected) is set. | low |
| `SqMatrixConnect_UpdateRange` | 0x1027E450 | 61 | yes | - | Recomputes the start and end values at +8/+0xC from the linked objects. | low |
| `SqMatrixConnect_Advance` | 0x1027E490 | 199 | yes | - | Advances an animation's position by a time step and wraps it at its bounds. | low |
| `SqMatrixConnect_Forward1027EBD0` | 0x1027EAF0 | 5 | yes | - | Forwards to 0x1027EBD0. | low |
| `SqMatrixConnect_Zero` | 0x1027EB00 | 16 | yes | - | Zeroes a 4 by 4 float matrix. | medium |
| `SqMatrixConnect_Set` | 0x1027EB50 | 116 | yes | - | Sets all sixteen entries of a 4 by 4 matrix from arguments. | medium |
| `SqMatrixConnect_SetIdentity` | 0x1027EBD0 | 30 | yes | - | Sets a 4x4 float matrix to the identity. | medium |
| `M4fTransform` | 0x1027EF20 | 92 | yes | - | - | - |
| `SqMatrixConnect_TransformVec3` | 0x1027EF80 | 83 | yes | - | Multiplies a three-component vector by the matrix's upper three rows. | low |
| `Mat4x4_TransformVec4` | 0x1027EFE0 | 139 | yes | - | - | - |
| `M4fTranspose` | 0x1027F070 | 103 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqMatrixConnect_UpdateMask` calls nothing directly
- `SqMatrixConnect_SetCallback` calls nothing directly
- `SqMatrixConnect_ReleaseConnection` calls `SqObject_Release`, `SqcoConnector_Init`, `SqMatrixConnect_UpdateMask`
- `SqMatrixConnect_IsConnected` calls nothing directly
- `SqMatrixConnect_UpdateRange` calls nothing directly
- `SqMatrixConnect_Advance` calls `SqMatrixConnect_IsConnected`, `SqDebug_GetFlagByte14`, `SqDebug_SetByte14`, `sub_1027DD90`
- `SqMatrixConnect_Forward1027EBD0` calls `SqMatrixConnect_SetIdentity`
- `SqMatrixConnect_Zero` calls nothing directly
- `SqMatrixConnect_Set` calls nothing directly
- `SqMatrixConnect_SetIdentity` calls `SqMatrixConnect_Zero`
- `M4fTransform` calls nothing directly
- `SqMatrixConnect_TransformVec3` calls nothing directly
- `Mat4x4_TransformVec4` calls nothing directly
- `M4fTranspose` calls nothing directly
