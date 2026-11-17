# CMoDisintegrateProgElem

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoDisintegrateProgElem.cpp`.

6 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoDisintegrateProgElem::GetRuntimeClass` | 0x100426B0 | 6 | yes | - | - | - |
| `CMoDisintegrateProgElem::Slot18DoNothing` | 0x100426C0 | 1 | yes | - | The default of virtual slot 18: does nothing. (reviewed as sub_100426C0) | low |
| `CMoDisintegrateProgElem::Construct` | 0x100530F0 | 60 | yes | - | Constructs the disintegration program element and sets its vtable and defaults. (reviewed as sub_100530F0) | medium |
| `CMoDisintegrateProgElem::IsKind13` | 0x10053130 | 15 | yes | - | Returns whether the argument is 13, the kind this element class answers to. (reviewed as sub_10053130) | medium |
| `CMoDisintegrateProgElem::vf008` | 0x10053140 | 5 | yes | - | Forwards to the virtual method in slot 10 of the task base. (reviewed as sub_10053140) | low |
| `CMoDisintegrateProgElem::ScalarDeletingDtor` | 0x10053150 | 43 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoDisintegrateProgElem::GetRuntimeClass` calls nothing directly
- `CMoDisintegrateProgElem::Slot18DoNothing` calls nothing directly
- `CMoDisintegrateProgElem::Construct` calls `CMoElem::Constructor`
- `CMoDisintegrateProgElem::IsKind13` calls nothing directly
- `CMoDisintegrateProgElem::vf008` calls nothing directly
- `CMoDisintegrateProgElem::ScalarDeletingDtor` calls `sub_10063C60`, `CMoElem::CMoElemFamily_SharedCleanup`, `SharedDeleteHelper`
