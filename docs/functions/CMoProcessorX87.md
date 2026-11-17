# CMoProcessorX87

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoProcessorX87.cpp`.

10 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoProcessorX87::Vec3AddScaled` | 0x1006D3B0 | 47 | yes | - | Adds a scaled 3-vector to another in place. (reviewed as sub_1006D3B0) | high |
| `CMoProcessorX87::Vec3Dot` | 0x1006D4D0 | 31 | yes | - | Dot product of two 3-vectors. (reviewed as sub_1006D4D0) | high |
| `CMoProcessorX87::Vec3Add` | 0x1006D680 | 39 | yes | - | Sums two 3-vectors into a1. (reviewed as sub_1006D680) | high |
| `CMoProcessorX87::Vec3MulComponents` | 0x1006D6B0 | 39 | yes | - | Multiplies two 3-vectors component by component into a1. (reviewed as sub_1006D6B0) | high |
| `CMoProcessorX87::TransformPoint` | 0x1006D720 | 94 | yes | - | Transforms a 3-component point by a 4x4 matrix, translation included, without a w divide. (reviewed as sub_1006D720) | medium |
| `CMoProcessorX87::Vec3Lerp` | 0x1006D980 | 59 | yes | - | Linear interpolation of two 3-vectors. (reviewed as sub_1006D980) | high |
| `CMoProcessorX87::RotationFromAnglesZYX` | 0x1006DCF0 | 758 | yes | - | Builds rotation matrices about X, Y and Z from three angles and combines them through vtable slot 9 in Z, Y, X order into arg1. (reviewed as sub_1006DCF0) | medium |
| `CMoProcessorX87::RotationY` | 0x1006E140 | 262 | yes | - | Writes the rotation matrix about the Y axis for an angle. (reviewed as sub_1006E140) | medium |
| `CMoProcessorX87::RotationZ` | 0x1006E260 | 262 | yes | - | Writes the rotation matrix about the Z axis for an angle. (reviewed as sub_1006E260) | medium |
| `CMoProcessorX87::RotationFromAnglesXYZ` | 0x1006E380 | 758 | yes | - | Builds rotation matrices about X, Y and Z from three angles and combines them through vtable slot 9 in X, Y, Z order into arg1. (reviewed as sub_1006E380) | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoProcessorX87::Vec3AddScaled` calls nothing directly
- `CMoProcessorX87::Vec3Dot` calls nothing directly
- `CMoProcessorX87::Vec3Add` calls nothing directly
- `CMoProcessorX87::Vec3MulComponents` calls nothing directly
- `CMoProcessorX87::TransformPoint` calls nothing directly
- `CMoProcessorX87::Vec3Lerp` calls nothing directly
- `CMoProcessorX87::RotationFromAnglesZYX` calls `sub_10313486`
- `CMoProcessorX87::RotationY` calls `sub_10313486`
- `CMoProcessorX87::RotationZ` calls `sub_10313486`
- `CMoProcessorX87::RotationFromAnglesXYZ` calls `sub_10313486`
