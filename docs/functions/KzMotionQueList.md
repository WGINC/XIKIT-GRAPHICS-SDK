# KzMotionQueList

Group: `Kz` (by the file name only). Source: `sdk/tree_src/KzMotionQueList.cpp`.

Why the file has this name (data/unit_names.json): KzMotionQueList_AdvanceAll / NotifyAll, CYyMotionQue::AppendSync; called from MotionQueue

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `KzMotionQueList_AdvanceAll` | 0x1001B170 | 33 | yes | - | Advances every node of the motion queue list by a time step. | low |
| `KzMotionQueList_NotifyAll` | 0x1001B1F0 | 53 | yes | - | Calls a notification method on every node of the motion queue list. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `KzMotionQueList_AdvanceAll` calls `QueTimeStep_StepStateByTime`
- `KzMotionQueList_NotifyAll` calls `sub_10084620`
