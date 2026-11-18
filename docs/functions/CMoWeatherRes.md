# CMoWeatherRes

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoWeatherRes.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoWeatherRes::ScalarDeletingDtor` | 0x101893D0 | 30 | yes | - | - | - |
| `CMoWeatherRes::SetupNop` | 0x101893F0 | 1 | yes | - | Setup that does nothing. (reviewed as sub_101893F0) | high |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoWeatherRes::ScalarDeletingDtor` calls `CMoResource::Destructor`, `SharedDeleteHelper`
- `CMoWeatherRes::SetupNop` calls nothing directly
