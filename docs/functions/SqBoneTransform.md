# SqBoneTransform

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqBoneTransform.cpp`.

Why the file has this name (data/unit_names.json): ComputeTransform, TransformPoint; called from the sqmo channels

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqBoneTransform_TransformOrigin` | 0x1027CCF0 | 56 | yes | - | Transforms the chain origin by the chain's matrices. | low |
| `SqBoneTransform_ComputeTransform` | 0x1027CD30 | 205 | yes | - | Accumulates a chain's matrices and transforms a point through them. | low |
| `SqBoneTransform_TransformPoint` | 0x1027CFD0 | 166 | yes | - | Transforms a point through a chain of matrices. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqBoneTransform_TransformOrigin` calls `SqBoneTransform_TransformPoint`
- `SqBoneTransform_ComputeTransform` calls `SqskSkeleton_FindBoneIndex`, `SqMatrixConnect_Forward1027EBD0`, `sqMatrix4_10280140`, `game_1027EB10`, `M4fTransform`, `game_1027A8A0`
- `SqBoneTransform_TransformPoint` calls `SqskSkeleton_FindBoneIndex`, `SqMatrixConnect_Forward1027EBD0`, `sqMatrix4_10280140`, `game_1027EB10`, `M4fTransform`
