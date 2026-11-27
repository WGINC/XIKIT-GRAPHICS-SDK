# CMoCamera

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoCamera.cpp`.

5 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoCamera::GetRuntimeClass` | 0x1003C880 | 6 | yes | - | - | - |
| `CMoCamera::Slot8DoNothing` | 0x1003C890 | 1 | yes | - | The default of virtual slot 8: does nothing. (reviewed as game_1003C890) | low |
| `CMoCamera::SetPathData` | 0x1003CB30 | 115 | yes | - | - | - |
| `CMoCamera::GetSharedInstance` | 0x10071980 | 41 | yes | - | - | - |
| `CMoCamera::Slot9DoNothing` | 0x100719F0 | 1 | yes | - | The default of virtual slot 9: does nothing. (reviewed as game_100719F0) | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoCamera::GetRuntimeClass` calls nothing directly
- `CMoCamera::Slot8DoNothing` calls nothing directly
- `CMoCamera::SetPathData` calls `CMoAttachments::Reset`
- `CMoCamera::GetSharedInstance` calls `game_10313486`
- `CMoCamera::Slot9DoNothing` calls nothing directly
