# CMoProcessor_VT_1032C368

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoProcessor_VT_1032C368.cpp`.

10 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoProcessor_VT_1032C368::vf012` | 0x1006D3B0 | 47 | yes | - | Adds a scaled 3-component vector to another in place. (reviewed as sub_1006D3B0) | medium |
| `CMoProcessor_VT_1032C368::vf014` | 0x1006D4D0 | 31 | yes | - | Returns the dot product of two 3-component vectors. (reviewed as sub_1006D4D0) | medium |
| `CMoProcessor_VT_1032C368::vf042` | 0x1006D680 | 39 | yes | - | Adds two 3-component vectors into the first output. (reviewed as sub_1006D680) | medium |
| `CMoProcessor_VT_1032C368::vf043` | 0x1006D6B0 | 39 | yes | - | Multiplies two 3-component vectors component-wise. (reviewed as sub_1006D6B0) | medium |
| `CMoProcessor_VT_1032C368::TransformPoint` | 0x1006D720 | 94 | yes | - | Transforms a 3-component point by a 4x4 matrix, translation included, without a w divide. (reviewed as sub_1006D720) | medium |
| `CMoProcessor_VT_1032C368::vf021` | 0x1006D980 | 59 | yes | - | Linearly interpolates between two 3-component vectors. (reviewed as sub_1006D980) | medium |
| `CMoProcessor_VT_1032C368::RotationFromAnglesZYX` | 0x1006DCF0 | 758 | yes | - | Builds rotation matrices about X, Y and Z from three angles and combines them through vtable slot 9 in Z, Y, X order into arg1. (reviewed as sub_1006DCF0) | medium |
| `CMoProcessor_VT_1032C368::RotationY` | 0x1006E140 | 262 | yes | - | Writes the rotation matrix about the Y axis for an angle. (reviewed as sub_1006E140) | medium |
| `CMoProcessor_VT_1032C368::RotationZ` | 0x1006E260 | 262 | yes | - | Writes the rotation matrix about the Z axis for an angle. (reviewed as sub_1006E260) | medium |
| `CMoProcessor_VT_1032C368::RotationFromAnglesXYZ` | 0x1006E380 | 758 | yes | - | Builds rotation matrices about X, Y and Z from three angles and combines them through vtable slot 9 in X, Y, Z order into arg1. (reviewed as sub_1006E380) | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoProcessor_VT_1032C368::vf012` calls nothing directly
- `CMoProcessor_VT_1032C368::vf014` calls nothing directly
- `CMoProcessor_VT_1032C368::vf042` calls nothing directly
- `CMoProcessor_VT_1032C368::vf043` calls nothing directly
- `CMoProcessor_VT_1032C368::TransformPoint` calls nothing directly
- `CMoProcessor_VT_1032C368::vf021` calls nothing directly
- `CMoProcessor_VT_1032C368::RotationFromAnglesZYX` calls `sub_10313486`
- `CMoProcessor_VT_1032C368::RotationY` calls `sub_10313486`
- `CMoProcessor_VT_1032C368::RotationZ` calls `sub_10313486`
- `CMoProcessor_VT_1032C368::RotationFromAnglesXYZ` calls `sub_10313486`
