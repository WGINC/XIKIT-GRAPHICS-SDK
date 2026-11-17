# CXiTimerLow

Group: `CXi` (by the file name only). Source: `sdk/tree_src/CXiTimerLow.cpp`.

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CXiTimerLow::Init` | 0x10019490 | 45 | yes | - | Constructs the low-resolution timer and starts it at the current time. (reviewed as sub_10019490) | medium |
| `CXiTimerLow::AccumulateElapsed` | 0x100194F0 | 42 | yes | - | Adds the milliseconds since the last reading, less the amount held at +0x1C, to the timer's total and restarts from now. (reviewed as sub_100194F0) | medium |
| `CXiTimerLow::GetFrameRate` | 0x10019550 | 59 | yes | - | Returns the rate in events per second, from the time since the timer was last reset. (reviewed as sub_10019550) | medium |
| `CXiTimerLow::GetElapsed` | 0x10019590 | 43 | yes | - | Returns the milliseconds elapsed on the timer, from timeGetTime. (reviewed as sub_10019590) | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CXiTimerLow::Init` calls `CXiTimer_Constructor`, `CXiTimerLow::AccumulateElapsed`
- `CXiTimerLow::AccumulateElapsed` calls nothing directly
- `CXiTimerLow::GetFrameRate` calls nothing directly
- `CXiTimerLow::GetElapsed` calls nothing directly
