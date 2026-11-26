# CMoOs2Res

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoOs2Res.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoOs2Res::CheckVersionAndInit` | 0x1002D7F0 | 97 | yes | 2 | Checks the resource's Os2 version byte and, the first time, runs the set-up its kind byte selects. (reviewed as game_1002D7F0) | medium |
| `CMoOs2Res::Slot4PointersToWordOffsets` | 0x1002D880 | 90 | yes | - | Turns the Os2 data's fixed-up pointers back into word offsets. (reviewed as game_1002D880) | medium |
| `CMoOs2Res::ScalarDeletingDtor` | 0x10071A80 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoOs2Res::CheckVersionAndInit` calls `game_10017D50`, `ErrorReport_NoOpVarargsA`, `game_10022470`, `Os2VtxBuffer_FixOffsetsAndCreateVtxBuffer`
- `CMoOs2Res::Slot4PointersToWordOffsets` calls nothing directly
- `CMoOs2Res::ScalarDeletingDtor` calls `CMoResource::Destructor`, `SharedDeleteHelper`
