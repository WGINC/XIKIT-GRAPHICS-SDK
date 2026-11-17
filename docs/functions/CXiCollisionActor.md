# CXiCollisionActor

Group: `CXi` (by the file name only). Source: `sdk/tree_src/CXiCollisionActor.cpp`.

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CXiCollisionActor_IsTouchDown` | 0x100A46D0 | 7 | yes | - | - | - |
| `CXiCollisionActor_IsOnLift` | 0x100A46F0 | 7 | yes | - | - | - |
| `CXiCollisionActor_GetCurrentAreaId` | 0x100A4710 | 7 | yes | - | - | - |
| `CXiCollisionActor::Constructor` | 0x100A4C20 | 148 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CXiCollisionActor_IsTouchDown` calls nothing directly
- `CXiCollisionActor_IsOnLift` calls nothing directly
- `CXiCollisionActor_GetCurrentAreaId` calls nothing directly
- `CXiCollisionActor::Constructor` calls `CXiControlActor::Constructor`, `sub_103149A0`, `Vec4_Set`
