# TimerResolution

Group: `Timer` (by the file name only). Source: `sdk/tree_src/TimerResolution.cpp`.

Why the file has this name (data/unit_names.json): timeBeginPeriod / timeEndPeriod / timeGetDevCaps, CXiTimerLow::Init; called at App create and destroy

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `TimerResolution_CreateObject` | 0x100191D0 | 43 | yes | - | Creates a 0x20-byte object and runs its initialisation method. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `TimerResolution_CreateObject` calls `Mem_AllocDefault`, `CXiTimerLow::Init`
