# CMoRmpRes

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoRmpRes.cpp`.

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoRmpRes::ScalarDeletingDtor` | 0x10071C90 | 30 | yes | - | - | - |
| `CMoRmpRes::Slot11GetCameraRuntimeClass` | 0x100745E0 | 8 | yes | - | Returns CMoCamera's class descriptor. (reviewed as game_100745E0) | high |
| `CMoRmpRes::Slot12DeleteOwner` | 0x100745F0 | 8 | yes | - | Deletes the object this is a member of. (reviewed as game_100745F0) | high |
| `CMoRmpRes::SetupNop` | 0x10074610 | 1 | yes | - | Setup that does nothing. (reviewed as game_10074610) | high |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoRmpRes::ScalarDeletingDtor` calls `CMoResource::Destructor`, `SharedDeleteHelper`
- `CMoRmpRes::Slot11GetCameraRuntimeClass` calls `CMoCamera::GetRuntimeClass`
- `CMoRmpRes::Slot12DeleteOwner` calls `game_10071C60`
- `CMoRmpRes::SetupNop` calls nothing directly
