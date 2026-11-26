# CAtelIdleTask

Group: `CAtel` (by the file name only). Source: `sdk/tree_src/CAtelIdleTask.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CAtelIdleTask::UpdateFrame` | 0x100106C0 | 53 | yes | 4 | Runs the per-frame update for the idle task when the camera's flag is set. (reviewed as game_100106C0) | medium |
| `CAtelIdleTask::Create` | 0x100142B0 | 123 | yes | - | Creates the idle task and registers it with the task manager. (reviewed as game_100142B0) | medium |
| `CAtelIdleTask_ScalarDeletingDtor` | 0x10014330 | 30 | yes | - | Destroys the idle task and frees its memory when bit 0 of the flags is set. | high |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CAtelIdleTask::UpdateFrame` calls `Acter_UpdateFrame`, `game_101D4A20`, `game_101D5370`
- `CAtelIdleTask::Create` calls `Menu_CloseEntry`, `TextInputFiles_ReloadAll`, `Mem_AllocFromArea`, `CMoTask::ResetFields`, `CMoTask::Constructor`, `game_100749B0`, `App_AdvanceSeqStep`
- `CAtelIdleTask_ScalarDeletingDtor` calls `CMoTask::Destructor`, `SharedDeleteHelper`
