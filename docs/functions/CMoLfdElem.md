# CMoLfdElem

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoLfdElem.cpp`.

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoLfdElem::Constructor` | 0x10053030 | 27 | yes | - | Constructs a CMoLfdElem on top of its CMoElem base and sets its type field. (reviewed as sub_10053030) | medium |
| `CMoLfdElem::IsKind12` | 0x10053050 | 15 | yes | - | Returns whether the argument is 12, the kind this element class answers to. (reviewed as sub_10053050) | medium |
| `CMoLfdElem::ScalarDeletingDtor` | 0x10053060 | 30 | yes | - | - | - |
| `CMoLfdElem::GetRuntimeClass` | 0x100548B0 | 6 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoLfdElem::Constructor` calls `CMoElem::Constructor`
- `CMoLfdElem::IsKind12` calls nothing directly
- `CMoLfdElem::ScalarDeletingDtor` calls `sub_100548C0`, `SharedDeleteHelper`
- `CMoLfdElem::GetRuntimeClass` calls nothing directly
