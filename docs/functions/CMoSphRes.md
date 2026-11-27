# CMoSphRes

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoSphRes.cpp`.

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoSphRes::GetRuntimeClass` | 0x100562A0 | 6 | yes | - | - | - |
| `CMoSphRes::FixupOffsetsAt30` | 0x100562B0 | 8 | yes | - | Runs CMoSphRes_FixupOffsets on the resource's data at +0x30. (reviewed as game_100562B0) | medium |
| `CMoSphRes::Slot9DoNothing` | 0x100562C0 | 1 | yes | - | The default of virtual slot 9: does nothing. (reviewed as game_100562C0) | low |
| `CMoSphRes::ScalarDeletingDtor` | 0x10071D00 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoSphRes::GetRuntimeClass` calls nothing directly
- `CMoSphRes::FixupOffsetsAt30` calls `game_10056220`
- `CMoSphRes::Slot9DoNothing` calls nothing directly
- `CMoSphRes::ScalarDeletingDtor` calls `CMoResource::Destructor`, `SharedDeleteHelper`
