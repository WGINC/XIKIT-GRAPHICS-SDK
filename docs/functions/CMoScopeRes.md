# CMoScopeRes

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoScopeRes.cpp`.

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoScopeRes::ScalarDeletingDtor` | 0x10071C90 | 30 | yes | - | - | - |
| `CMoScopeRes::Slot11GetCameraRuntimeClass` | 0x100745E0 | 8 | yes | - | Returns CMoCamera's class descriptor. (reviewed as sub_100745E0) | high |
| `CMoScopeRes::Slot12DeleteOwner` | 0x100745F0 | 8 | yes | - | Deletes the object this is a member of. (reviewed as sub_100745F0) | high |
| `CMoScopeRes::SetupNop` | 0x10074610 | 1 | yes | - | Setup that does nothing. (reviewed as sub_10074610) | high |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoScopeRes::ScalarDeletingDtor` calls `CMoResource::Destructor`, `SharedDeleteHelper`
- `CMoScopeRes::Slot11GetCameraRuntimeClass` calls `CMoCamera::GetRuntimeClass`
- `CMoScopeRes::Slot12DeleteOwner` calls `sub_10071C60`
- `CMoScopeRes::SetupNop` calls nothing directly
