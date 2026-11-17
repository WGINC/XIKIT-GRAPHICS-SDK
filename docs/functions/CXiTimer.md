# CXiTimer

Group: `CXi` (by the file name only). Source: `sdk/tree_src/CXiTimer.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CXiTimer_Constructor` | 0x10019210 | 20 | yes | - | Constructs a CXiTimer and sets its two scale fields to 1.0. | medium |
| `CXiTimer_GetFloat08` | 0x10019230 | 4 | yes | - | Returns the timer's float at +8. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CXiTimer_Constructor` calls nothing directly
- `CXiTimer_GetFloat08` calls nothing directly
