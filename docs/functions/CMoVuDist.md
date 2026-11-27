# CMoVuDist

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoVuDist.cpp`.

5 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoVuDist::GetRuntimeClass` | 0x100430C0 | 6 | yes | - | - | - |
| `CMoVuDist::Construct` | 0x10052DA0 | 48 | yes | - | Constructs the VU distortion element and sets its vtable and defaults. (reviewed as game_10052DA0) | medium |
| `CMoVuDist::IsKind10` | 0x10052DD0 | 15 | yes | - | Returns whether the argument is 10, the kind this element class answers to. (reviewed as game_10052DD0) | medium |
| `CMoVuDist::Slot8CallSlot10` | 0x10052DE0 | 5 | yes | - | Slot 8: calls the object's slot 10. (reviewed as game_10052DE0) | high |
| `CMoVuDist::ScalarDeletingDtor` | 0x10052DF0 | 43 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoVuDist::GetRuntimeClass` calls nothing directly
- `CMoVuDist::Construct` calls `CMoElem::Constructor`
- `CMoVuDist::IsKind10` calls nothing directly
- `CMoVuDist::Slot8CallSlot10` calls nothing directly
- `CMoVuDist::ScalarDeletingDtor` calls `game_10063C60`, `CMoElem::CMoElemFamily_SharedCleanup`, `SharedDeleteHelper`
