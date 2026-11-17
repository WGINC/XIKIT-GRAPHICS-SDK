# ControlActorView

Group: `Control` (by the file name only). Source: `sdk/tree_src/ControlActorView.cpp`.

Why the file has this name (data/unit_names.json): XiControlActor_UpdateCamera / UpdateView / SetAutoRunning / NormalizeInput

5 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `XiControlActor_UpdateCamera` | 0x100A5E10 | 173 | yes | - | Updates the camera for the control actor, first-person or following. | medium |
| `ControlActorView_CallUnlessFlag` | 0x100A5EC0 | 40 | yes | - | Calls 0x100A6240 unless a flag is set or slot 196 declines. | low |
| `XiControlActor_UpdateView` | 0x100A5EF0 | 284 | yes | - | Updates the control actor's view mode from its model state. | low |
| `XiControlActor_SetAutoRunning` | 0x100A6070 | 105 | yes | - | Sets the auto-run flag; clearing it restores four saved values and resolves the actor handle at 0x10487F74, then calls sub_10129DE0 on sub_10578158 when it resolves. | medium |
| `XiControlActor_NormalizeInput` | 0x100A78D0 | 203 | yes | - | Normalises a 2D input direction and stores its magnitude factor. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `XiControlActor_UpdateCamera` calls `Camera_GetField50`, `sub_10021110`, `XiControlActor_UpdateView`, `sub_1025E090`, `Vec3_Add_10026FA0`, `Camera_SetPosition`, `sub_1001EE60`
- `ControlActorView_CallUnlessFlag` calls `sub_100A6240`
- `XiControlActor_UpdateView` calls `NetCellFont_TestCommand36CF60`, `XiControlActor_SetAutoRunning`, `CXiActor::GetModelField170`, `sub_100A8CC0`, `Settings_GetValue`, `Camera_SetField2F8OnGlobal`, `sub_10037EF0`
- `XiControlActor_SetAutoRunning` calls `ActorHandle_Resolve`, `ChatLog_AddMessage9Code379`, `sub_100814F0`
- `XiControlActor_NormalizeInput` calls nothing directly
