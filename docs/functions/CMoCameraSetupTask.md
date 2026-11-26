# CMoCameraSetupTask

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoCameraSetupTask.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoCameraSetupTask::Slot8SetupCameraAfterOneTick` | 0x1006B480 | 61 | yes | - | Sets up the camera matrices one tick after the task starts. (reviewed as game_1006B480) | medium |
| `CMoCameraSetupTask::Slot1NopOnMessage6` | 0x1006B4C0 | 23 | yes | - | Slot 1: does nothing visible (MoDX_Nop on message 6). (reviewed as game_1006B4C0) | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoCameraSetupTask::Slot8SetupCameraAfterOneTick` calls `game_10069EE0`, `CameraCache_CacheViewProjection`, `Camera_SetupMatrices`
- `CMoCameraSetupTask::Slot1NopOnMessage6` calls `MoDX_Nop`
