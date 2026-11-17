# sqskSkeleton

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqskSkeleton.cpp`.

7 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqskSkeleton_Create` | 0x1027B580 | 32 | yes | - | Allocates and initialises a skeleton record. | medium |
| `SqskSkeleton_Init` | 0x1027B5A0 | 60 | yes | - | Initialises a skeleton record and its function table. | medium |
| `SqskSkeleton_SetNodeCount` | 0x1027C4C0 | 298 | yes | - | Resizes a skeleton's node arrays to a new count. | medium |
| `SqskSkeleton_FindBoneIndex` | 0x1027C900 | 80 | yes | - | Returns a bone's index in its skeleton. | high |
| `SqskSkeleton_GetNode` | 0x1027C980 | 78 | yes | - | Returns the skeleton node at an index, or 0 when the index is out of range. | medium |
| `SqskSkeleton_Release` | 0x1027C9D0 | 19 | yes | - | Releases the skeleton's linked object through its vtable. | low |
| `sqskSkeleton_GetNodeByIndex` | 0x1029A420 | 45 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqskSkeleton_Create` calls `sub_10275D80`, `SqskSkeleton_Init`
- `SqskSkeleton_Init` calls nothing directly
- `SqskSkeleton_SetNodeCount` calls `SqhiNode_Nop`, `SqskJoint_Nop`, `sqFree`, `SqMem_AllocZeroed`, `SqhiNode_Init`, `SqskJoint_Init`
- `SqskSkeleton_FindBoneIndex` calls `sqDebugPrintf`
- `SqskSkeleton_GetNode` calls `sqDebugPrintf`
- `SqskSkeleton_Release` calls nothing directly
- `sqskSkeleton_GetNodeByIndex` calls nothing directly
