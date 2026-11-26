# CMoDisintegrateProgElem

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoDisintegrateProgElem.cpp`.

6 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoDisintegrateProgElem::GetRuntimeClass` | 0x100426B0 | 6 | yes | - | - | - |
| `CMoDisintegrateProgElem::Slot18DoNothing` | 0x100426C0 | 1 | yes | - | The default of virtual slot 18: does nothing. (reviewed as game_100426C0) | low |
| `CMoDisintegrateProgElem::Construct` | 0x100530F0 | 60 | yes | - | Constructs the disintegration program element and sets its vtable and defaults. (reviewed as game_100530F0) | medium |
| `CMoDisintegrateProgElem::IsKind13` | 0x10053130 | 15 | yes | - | Returns whether the argument is 13, the kind this element class answers to. (reviewed as game_10053130) | medium |
| `CMoDisintegrateProgElem::Slot8CallSlot10` | 0x10053140 | 5 | yes | - | Slot 8: calls the object's slot 10. (reviewed as game_10053140) | high |
| `CMoDisintegrateProgElem::ScalarDeletingDtor` | 0x10053150 | 43 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoDisintegrateProgElem::GetRuntimeClass` calls nothing directly
- `CMoDisintegrateProgElem::Slot18DoNothing` calls nothing directly
- `CMoDisintegrateProgElem::Construct` calls `CMoElem::Constructor`
- `CMoDisintegrateProgElem::IsKind13` calls nothing directly
- `CMoDisintegrateProgElem::Slot8CallSlot10` calls nothing directly
- `CMoDisintegrateProgElem::ScalarDeletingDtor` calls `game_10063C60`, `CMoElem::CMoElemFamily_SharedCleanup`, `SharedDeleteHelper`
