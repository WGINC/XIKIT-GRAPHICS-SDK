# MotionQueue

Group: `Motion` (by the file name only). Source: `sdk/tree_src/MotionQueue.cpp`.

Why the file has this name (data/unit_names.json): MotionQueue_*, MotionQueList_*, SampleAnimationTrack_*; called from CXiSkeletonActor::SetMotion and CYyMotionQue::StartMotion

6 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `MotionQueue_ApplyPolicy` | 0x10019A50 | 176 | yes | - | - | - |
| `SampleAnimationTrack_ToBuffer` | 0x10019B30 | 944 | yes | - | - | - |
| `SampleAnimationTrack_Live` | 0x10019EE0 | 970 | yes | - | - | - |
| `MotionQueList_ProcessAll` | 0x1001A3E0 | 54 | yes | - | Runs each of the seven motion queues in turn. | medium |
| `MotionQueue_UpdateAllChannels` | 0x1001A420 | 556 | yes | - | - | - |
| `MotionQueList_QueueMotion` | 0x1001A6E0 | 123 | yes | - | Appends a motion to one of the seven motion queues and starts the first queue's motion on the object. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `MotionQueue_ApplyPolicy` calls `SampleAnimationTrack_Live`, `SampleAnimationTrack_ToBuffer`
- `SampleAnimationTrack_ToBuffer` calls `game_10311C2C`, `Quat_SetIdentityChained`, `Quat_NLerp`, `BoneShadow_Nop`
- `SampleAnimationTrack_Live` calls `game_10311C2C`, `Quat_SetIdentityChained`, `Quat_NLerp`, `BoneShadow_Nop`
- `MotionQueList_ProcessAll` calls `CYyMotionQue::Update`, `game_1001AC40`, `KzMotionQueList_NotifyAll`
- `MotionQueue_UpdateAllChannels` calls `Quat_SetIdentityChained`, `game_10313486`, `Vec3_Copy`, `CYyMotionQue_IsActive`, `CYyMotionQue::SampleInto`, `Quat_NLerp`, `BoneShadow_Nop`, `Vec3_Lerp`
- `MotionQueList_QueueMotion` calls `game_10084620`, `game_1001AD00`
