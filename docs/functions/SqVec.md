# SqVec

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqVec.cpp`.

Why the file has this name (data/unit_names.json): PackVec4, CopyVec3, CrossProduct, LerpFactor, the string "Error: Couldn't find link %d"

11 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqVec_Relink` | 0x102741F0 | 196 | yes | - | Moves an object to a new link id by finding the matching link entry. | low |
| `SqVec_GetInterpolated` | 0x10274370 | 106 | yes | - | Returns two interpolated values for an active track entry at a time ratio. | low |
| `SqVec_ZeroDwords` | 0x10274640 | 15 | yes | - | Sets a three-value vector to zero. | medium |
| `SqVec_CopyVec3` | 0x10274650 | 25 | yes | - | Copies three dwords (a 3-component vector) from the second argument to the first. | medium |
| `SqVec_SetXyz` | 0x10274670 | 25 | yes | - | Sets a three-float vector from its components. | medium |
| `SqVec_Length` | 0x102746C0 | 16 | yes | - | Returns the length of a three-float vector. | high |
| `SqVec_CrossProduct` | 0x10274890 | 59 | yes | - | Computes the cross product of two vectors into a destination. | medium |
| `SqVec_ScaleVec3ByInverseOf102746C0` | 0x102748F0 | 55 | yes | - | Divides the three floats at p by what 0x102746C0 returns for p, when that is non-zero, and returns it. | low |
| `SqVec_Sub` | 0x102749C0 | 37 | yes | - | Subtracts two vectors component-wise into a destination. | medium |
| `SqVec_LerpFactor` | 0x10274A20 | 57 | yes | - | Linearly interpolates between two vectors by a factor into a destination. | medium |
| `PackVec4` | 0x10274D40 | 32 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqVec_Relink` calls `sqDebugPrintf`, `Chasm_ToggleLayerState`, `SqMatrixConnect_UpdateRange`, `SqDebug_SetByte14`, `SqMatrixConnect_SetCallback`
- `SqVec_GetInterpolated` calls `SqMatrixConnect_IsConnected`, `SqmoChannel_Evaluate`
- `SqVec_ZeroDwords` calls nothing directly
- `SqVec_CopyVec3` calls nothing directly
- `SqVec_SetXyz` calls nothing directly
- `SqVec_Length` calls `sub_10274690`
- `SqVec_CrossProduct` calls nothing directly
- `SqVec_ScaleVec3ByInverseOf102746C0` calls `SqVec_Length`
- `SqVec_Sub` calls nothing directly
- `SqVec_LerpFactor` calls nothing directly
- `PackVec4` calls nothing directly
