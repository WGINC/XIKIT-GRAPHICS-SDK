# SqmdDMBUpdaters

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqmdDMBUpdaters.cpp`.

Why the file has this name (data/unit_names.json): SqmdDMB_BuildUpdaters, ResolveSkelRefs

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqmdDMB_BuildUpdaters` | 0x10288FF0 | 1257 | yes | - | sqmdDMBBuildUpdaters: builds the updater list of a model into the DMB being built. | high |
| `SqmdDMBUpdaters_ResolveSkelRefs` | 0x102894E0 | 119 | yes | - | Resolves the skeleton references of a DMB entry, clearing those that fail. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqmdDMB_BuildUpdaters` calls `SqmdDMB_TraceDelta`, `sub_10314D55`, `SqmdDMB_AlignMem`, `SqmdModel_FindItemName`, `sqmdModel_GetItemName`, `SqTimer_GetMicroseconds`, `SqmdSort_CreateForStrips`, `SqmdModel_AppendPair68Flag100`, `sqDebugPrintf`, `SqskSkeleton_BuildSQO`, `SqhiNode_Create`, `SqskJoint_Create`, `SqVec_CopyVec3`, `SqQuat_Copy`, `SqhiNode_SetField64`, `SqhiNode_AppendChild`, `SqmdDMBUpdaters_ResolveSkelRefs`, `SqinBuild_BuildSQO`, `SqinSkin_InitShapeData`, `SqinSkin_ReleaseIfHasData`, `SqinSkin_PropagateValue38`
- `SqmdDMBUpdaters_ResolveSkelRefs` calls `SqskSkeleton_GetNode`, `sqDebugPrintf`
