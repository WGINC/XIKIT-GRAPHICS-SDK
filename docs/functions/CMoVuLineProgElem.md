# CMoVuLineProgElem

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoVuLineProgElem.cpp`.

5 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoVuLineProgElem::Constructor` | 0x10052BC0 | 48 | yes | - | Constructs a CMoVuLineProgElem on top of its CMoElem base. (reviewed as game_10052BC0) | medium |
| `CMoVuLineProgElem::IsKind9` | 0x10052BF0 | 15 | yes | - | Returns whether the argument is 9, the kind this element class answers to. (reviewed as game_10052BF0) | medium |
| `CMoVuLineProgElem::ScalarDeletingDtor` | 0x10052C00 | 43 | yes | - | - | - |
| `CMoVuLineProgElem::GetRuntimeClass` | 0x10064170 | 6 | yes | - | - | - |
| `CMoVuLineProgElem::Slot18DoNothing` | 0x10064180 | 1 | yes | - | The default of virtual slot 18: does nothing. (reviewed as game_10064180) | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoVuLineProgElem::Constructor` calls `CMoElem::Constructor`
- `CMoVuLineProgElem::IsKind9` calls nothing directly
- `CMoVuLineProgElem::ScalarDeletingDtor` calls `game_10063C60`, `CMoElem::CMoElemFamily_SharedCleanup`, `SharedDeleteHelper`
- `CMoVuLineProgElem::GetRuntimeClass` calls nothing directly
- `CMoVuLineProgElem::Slot18DoNothing` calls nothing directly
