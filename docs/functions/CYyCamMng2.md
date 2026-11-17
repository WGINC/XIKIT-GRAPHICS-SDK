# CYyCamMng2

Group: `CYy` (by the file name only). Source: `sdk/tree_src/CYyCamMng2.cpp`.

7 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CYyCamMng2_SetGlobalFlags` | 0x1001E2F0 | 48 | yes | - | Sets the camera manager's global flag bytes. | low |
| `CYyCamMng2::CreateGlobal` | 0x1001E470 | 53 | yes | - | - | - |
| `CYyCamMng2_CallGlobalVfunc1` | 0x1001E4B0 | 21 | yes | - | - | - |
| `CYyCamMng2::GetYaw` | 0x1001E4D0 | 25 | yes | - | Returns the camera yaw from two camera fields. (reviewed as sub_1001E4D0) | low |
| `CYyCamMng2::Reset` | 0x1001E4F0 | 149 | yes | - | Resets the camera manager's position and state vectors to their defaults. (reviewed as sub_1001E4F0) | low |
| `CYyCamMng2::SetDefaultDistances` | 0x1001E590 | 30 | yes | - | Resets the camera and sets its default distances. (reviewed as sub_1001E590) | low |
| `CYyCamMng2::Construct` | 0x1001E600 | 146 | yes | - | Constructs the camera manager and clears its global state. (reviewed as sub_1001E600) | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CYyCamMng2_SetGlobalFlags` calls nothing directly
- `CYyCamMng2::CreateGlobal` calls `Mem_AllocDefault`, `CYyCamMng2::Construct`, `CYyCamMng2::SetDefaultDistances`, `Camera_Call100151A0OnGlobal`
- `CYyCamMng2_CallGlobalVfunc1` calls nothing directly
- `CYyCamMng2::GetYaw` calls `Camera_GetField50`
- `CYyCamMng2::Reset` calls `Vec3_Copy`, `Camera_SetField2F8OnGlobal`, `Vec3_Set`
- `CYyCamMng2::SetDefaultDistances` calls `CYyCamMng2::Reset`
- `CYyCamMng2::Construct` calls `MathVector_ReturnThis`, `CYyCamMng2::SetDefaultDistances`, `CYyCamMng2_SetGlobalFlags`
