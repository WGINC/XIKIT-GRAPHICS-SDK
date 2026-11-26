# CMoAfbRes

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoAfbRes.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoAfbRes::Setup` | 0x10071A20 | 8 | yes | - | Setup: checks the version and fixes up the two data offsets into pointers. (reviewed as game_10071A20) | high |
| `CMoAfbRes::Slot9UnfixPointers` | 0x10071A30 | 8 | yes | - | Turns the fixed-up pointers back into offsets. (reviewed as game_10071A30) | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoAfbRes::Setup` calls `game_10017D50`, `ErrorReport_NoOpVarargsA`
- `CMoAfbRes::Slot9UnfixPointers` calls nothing directly
