# CXiControlActor

Group: `CXi` (by the file name only). Source: `sdk/tree_src/CXiControlActor.cpp`.

14 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CXiControlActor_GetGroundMaterial` | 0x100A45D0 | 7 | yes | - | - | - |
| `CXiControlActor::AmIControlActor` | 0x100A4640 | 24 | yes | - | - | - |
| `CXiControlActor_IsFreeRun` | 0x100A4670 | 7 | yes | - | - | - |
| `CXiControlActor_IsWalkLock` | 0x100A4690 | 7 | yes | - | - | - |
| `CXiControlActor_IsParallelMove` | 0x100A46B0 | 7 | yes | - | - | - |
| `CXiControlActor_IsControlLock` | 0x100A46C0 | 7 | yes | - | - | - |
| `CXiControlActor::FillHistory` | 0x100A5770 | 69 | yes | - | Writes one vector into all four entries of the actor's history ring. (reviewed as game_100A5770) | medium |
| `CXiControlActor_SetVec4` | 0x100A57C0 | 42 | yes | - | Stores a four-component vector in the actor. | low |
| `CXiControlActor::Constructor` | 0x100A89E0 | 544 | yes | - | Constructs a control actor and initialises its state. (reviewed as game_100A89E0) | medium |
| `CXiControlActor_CallTargetSlot207With0` | 0x100A8C20 | 27 | yes | - | Resolves the target actor handle and, if there is an actor, calls its virtual slot 207 with 0. | medium |
| `CXiControlActor_CallTargetSlot207With1` | 0x100A8C40 | 27 | yes | - | Resolves the target actor handle and, if there is an actor, calls its virtual slot 207 with 1. | medium |
| `CXiControlActor::GetSpeed` | 0x100AAEF0 | 54 | yes | - | Returns the length of the actor's two-component velocity, scaled by 0.8. (reviewed as game_100AAEF0) | low |
| `CXiControlActor::Slot137_Set388` | 0x100AAF50 | 20 | yes | - | - | - |
| `CXiControlActor::Slot138_Scan3F0` | 0x100AAF70 | 60 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CXiControlActor_GetGroundMaterial` calls nothing directly
- `CXiControlActor::AmIControlActor` calls `ActorHandle_Resolve`
- `CXiControlActor_IsFreeRun` calls nothing directly
- `CXiControlActor_IsWalkLock` calls nothing directly
- `CXiControlActor_IsParallelMove` calls nothing directly
- `CXiControlActor_IsControlLock` calls nothing directly
- `CXiControlActor::FillHistory` calls `Vec3_Copy`
- `CXiControlActor_SetVec4` calls nothing directly
- `CXiControlActor::Constructor` calls `CXiActor::ConstructBase`, `ActorHandle_Constructor`, `Actor_SetSlotTableEntry`, `game_100814F0`, `ActorHandle_Resolve`, `CXiControlActor::FillHistory`
- `CXiControlActor_CallTargetSlot207With0` calls `ActorHandle_Resolve`
- `CXiControlActor_CallTargetSlot207With1` calls `ActorHandle_Resolve`
- `CXiControlActor::GetSpeed` calls nothing directly
- `CXiControlActor::Slot137_Set388` calls `game_100AAFB0`
- `CXiControlActor::Slot138_Scan3F0` calls `game_100AAFB0`
