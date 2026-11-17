# SqSkelNode

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqSkelNode.cpp`.

Why the file has this name (data/unit_names.json): CopyQuatAt68, CopyVec3At5C, SetFloatAt94: the skeleton node fields; called from sqskSkeleton

6 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqSkelNode_CopyVec3At5C` | 0x102915B0 | 16 | yes | - | Copies a three-value vector into the object's field at 0x5C. | medium |
| `SqSkelNode_CopyQuatAt68` | 0x102915E0 | 16 | yes | - | Copies a four-value quaternion into the object's field at 0x68. | low |
| `SqSkelNode_CopyVec3At78` | 0x102915F0 | 16 | yes | - | Copies a three-value vector into the object's field at 0x78. | medium |
| `SqSkelNode_SetTripleAt84` | 0x102916D0 | 55 | yes | - | Stores three values at 0x84 and their sum at 0x90. | low |
| `SqSkelNode_SetFloatAt94` | 0x10291780 | 15 | yes | - | Sets the float field at 0x94. | medium |
| `SqSkelNode_SetFloatAt98` | 0x10291790 | 15 | yes | - | Sets the float field at 0x98. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqSkelNode_CopyVec3At5C` calls `SqVec_CopyVec3`
- `SqSkelNode_CopyQuatAt68` calls `SqQuat_Copy`
- `SqSkelNode_CopyVec3At78` calls `SqVec_CopyVec3`
- `SqSkelNode_SetTripleAt84` calls nothing directly
- `SqSkelNode_SetFloatAt94` calls nothing directly
- `SqSkelNode_SetFloatAt98` calls nothing directly
