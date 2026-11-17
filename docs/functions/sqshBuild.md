# sqshBuild

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqshBuild.cpp`.

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqshBuild_BuildTriStrip` | 0x10299C30 | 299 | yes | - | Builds a tristrip shape from its binary data. | high |
| `SqshBuild_Read` | 0x10299D60 | 222 | yes | - | Reads a shape build block from a stream, vertex by vertex. | medium |
| `SqshBuild_BuildPoints` | 0x10299E40 | 148 | yes | - | Builds a points shape from its binary data. | high |
| `SqshBuild_BuildCurves` | 0x10299EE0 | 241 | yes | - | Builds a curves shape from its binary data. | high |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqshBuild_BuildTriStrip` calls `SqScriptRead_ReadBlock`, `sqDebugPrintf`, `SqshTriStrip_Create`, `SqshBuild_Read`, `SqMem_AllocZeroed`, `SqBounds_ComputeBounds`, `SqshTriStrip_ForEachTriangle`, `SqshTriStrip_GetGlobal`, `SqVtx_PackFloatsToBytes`
- `SqshBuild_Read` calls `SqScriptRead_ReadBlock`, `sqDebugPrintf`, `SqVtx_Create`, `SqVtx_AllocateField`
- `SqshBuild_BuildPoints` calls `SqScriptRead_ReadBlock`, `sqDebugPrintf`, `SqshPoints_Create`, `SqshBuild_Read`, `SqBounds_ComputeBounds`
- `SqshBuild_BuildCurves` calls `SqScriptRead_ReadBlock`, `sqDebugPrintf`, `SqshCurves_Create`, `SqshBuild_Read`, `SqBounds_ComputeBounds`, `SqMem_AllocZeroed`, `SqshCurves_RebuildIndex`
