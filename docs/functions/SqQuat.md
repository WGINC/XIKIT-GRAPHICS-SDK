# SqQuat

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqQuat.cpp`.

Why the file has this name (data/unit_names.json): QuatFromEuler, FromAxisAngle, FromRotationX/Y/Z, ToMatrix3

12 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqQuat_SetIdentityFwd` | 0x1027A6F0 | 5 | yes | - | Sets a transform to identity. | low |
| `SqQuat_Copy` | 0x1027A700 | 31 | yes | - | Copies a quaternion of four floats. | medium |
| `SqQuat_Set` | 0x1027A720 | 32 | yes | - | Sets the four components of a quaternion. | medium |
| `SqQuat_ToMatrix3` | 0x1027A9D0 | 258 | yes | - | Converts a quaternion to a 3 by 3 rotation matrix. | medium |
| `SqQuat_QuatFromEuler` | 0x1027AAE0 | 184 | yes | - | Builds a unit quaternion from three rotation angles about X, Y and Z. | medium |
| `SqQuat_FromRotationX` | 0x1027ABA0 | 34 | yes | - | Builds a quaternion for a rotation about the X axis. | medium |
| `SqQuat_FromRotationY` | 0x1027ABD0 | 40 | yes | - | Builds a quaternion for a rotation about the Y axis. | medium |
| `SqQuat_FromRotationZ` | 0x1027AC00 | 40 | yes | - | Builds a quaternion for a rotation about the Z axis. | medium |
| `SqQuat_FromAxisAngle` | 0x1027AC30 | 48 | yes | - | Builds a quaternion from an axis vector and an angle. | medium |
| `SqQuat_SetIdentity` | 0x1027AE50 | 22 | yes | - | Sets a quaternion to the identity rotation. | medium |
| `SqQuat_Negate` | 0x1027AEF0 | 35 | yes | - | Negates a quaternion's four components. | medium |
| `SqQuat_NormalizeVec4` | 0x1027AF20 | 129 | yes | - | Normalises a four-float vector to unit length, falling back to (1,1,1)/sqrt(3) with w 0 for a zero vector. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqQuat_SetIdentityFwd` calls `SqQuat_SetIdentity`
- `SqQuat_Copy` calls nothing directly
- `SqQuat_Set` calls nothing directly
- `SqQuat_ToMatrix3` calls nothing directly
- `SqQuat_QuatFromEuler` calls nothing directly
- `SqQuat_FromRotationX` calls nothing directly
- `SqQuat_FromRotationY` calls nothing directly
- `SqQuat_FromRotationZ` calls nothing directly
- `SqQuat_FromAxisAngle` calls nothing directly
- `SqQuat_SetIdentity` calls nothing directly
- `SqQuat_Negate` calls nothing directly
- `SqQuat_NormalizeVec4` calls nothing directly
