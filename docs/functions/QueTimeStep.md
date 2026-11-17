# QueTimeStep

Group: `Que` (by the file name only). Source: `sdk/tree_src/QueTimeStep.cpp`.

Why the file has this name (data/unit_names.json): StepStateByTime and Update, called from CYyQue and CYyMotionQue::Update; it calls only Camera_GetFrameScale (the frame time)

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `QueTimeStep_StepStateByTime` | 0x1001B520 | 81 | yes | - | Advances a motion queue node's state byte with a time value, storing the time and dropping back to state 2 when the value is at most 1. | low |
| `QueTimeStep_Update` | 0x1001B5D0 | 288 | yes | - | Advances a fade value by its rate each frame, moving between the fade states and clamping the value to 0 to 1. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `QueTimeStep_StepStateByTime` calls nothing directly
- `QueTimeStep_Update` calls `Camera_GetFrameScale`
