# SqskBuild

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqskBuild.cpp`.

Why the file has this name (data/unit_names.json): SqskSkeleton_BuildBinary / BuildSQO

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqskSkeleton_BuildSQO` | 0x1029ADF0 | 298 | yes | - | Builds a skeleton from an SQLE-tagged binary block. | high |
| `SqskSkeleton_BuildBinary` | 0x1029AF20 | 465 | yes | - | Builds a skeleton's bones from its binary data. | high |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqskSkeleton_BuildSQO` calls `SqScriptRead_ReadBlock`, `sqDebugPrintf`, `SqskSkeleton_BuildBinary`
- `SqskSkeleton_BuildBinary` calls `sqDebugPrintf`, `SqScriptRead_ReadBlock`, `SqskSkeleton_Create`, `SqskSkeleton_SetNodeCount`, `SqNibbleSwap_SwapNibblesXor`, `SqScriptRead_ReturnZero`, `SqIO_SwapBytes`, `SqVec_SetXyz`, `SqSkelNode_CopyVec3At5C`, `SqQuat_Set`, `SqSkelNode_CopyQuatAt68`, `SqSkelNode_CopyVec3At78`, `SqSkelNode_SetTripleAt84`, `SqSkelNode_SetFloatAt94`, `SqSkelNode_SetFloatAt98`, `SqhiNode_AppendChild`
