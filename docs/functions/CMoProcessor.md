# CMoProcessor

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoProcessor.cpp`.

9 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoProcessor::InitRotationMatrices` | 0x1006CE70 | 286 | yes | - | - | - |
| `CMoProcessor::TransposeInPlace` | 0x1006D3E0 | 119 | yes | - | Transposes a 4x4 matrix in place. (reviewed as game_1006D3E0) | medium |
| `CMoProcessor::LengthSafe` | 0x1006D580 | 65 | yes | - | Returns the length of a 3-component vector, or 0 when it is zero. (reviewed as game_1006D580) | medium |
| `CMoProcessor::ScratchMatrixOp` | 0x1006E6B0 | 91 | yes | - | - | - |
| `CMoProcessor::CalcScreenBounds` | 0x1006E970 | 499 | yes | - | - | - |
| `CMoProcessor::CalcScreenBoundsAndVisible` | 0x1006ED10 | 605 | yes | - | - | - |
| `CMoProcessor::MulPointVec3` | 0x1006F800 | 104 | yes | - | Transforms a point by a 4x4 matrix, writing the three-float result. (reviewed as game_1006F800) | medium |
| `CMoProcessor::BuildRotationXYZ` | 0x1006FAE0 | 159 | yes | - | Builds the processor's three-axis rotation from three angles. (reviewed as game_1006FAE0) | medium |
| `CMoProcessor::SetRotationFromAngles` | 0x1006FC40 | 159 | yes | - | Builds three sine/cosine rotation blocks from its three float arguments and combines them through two calls to vtable slot 9. (reviewed as game_1006FC40) | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoProcessor::InitRotationMatrices` calls `game_10313486`
- `CMoProcessor::TransposeInPlace` calls nothing directly
- `CMoProcessor::LengthSafe` calls nothing directly
- `CMoProcessor::ScratchMatrixOp` calls nothing directly
- `CMoProcessor::CalcScreenBounds` calls nothing directly
- `CMoProcessor::CalcScreenBoundsAndVisible` calls nothing directly
- `CMoProcessor::MulPointVec3` calls nothing directly
- `CMoProcessor::BuildRotationXYZ` calls nothing directly
- `CMoProcessor::SetRotationFromAngles` calls nothing directly
