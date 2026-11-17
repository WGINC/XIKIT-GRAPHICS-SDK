# CMoD3aElem

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoD3aElem.cpp`.

6 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoD3aElem::GetRuntimeClass_variant0` | 0x1003E6A0 | 6 | yes | - | - | - |
| `CMoD3aElem::DrawSegment` | 0x1003EB30 | 41 | yes | 1 | Draws the element's D3A segment when it has a draw handle. (reviewed as sub_1003EB30) | medium |
| `CMoD3aElem::GetRuntimeClass_variant1` | 0x1003EE50 | 6 | yes | - | - | - |
| `CMoD3aElem::GetRuntimeClass_variant2` | 0x1003EF00 | 6 | yes | - | - | - |
| `CMoD3aElem::Init` | 0x10052C90 | 18 | yes | - | Constructs the base element and sets the CMoD3aElem vtable. (reviewed as sub_10052C90) | medium |
| `CMoD3aElem::ScalarDeletingDtor` | 0x10052CB0 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoD3aElem::GetRuntimeClass_variant0` calls nothing directly
- `CMoD3aElem::DrawSegment` calls `YmElem_DrawD3ASegment`
- `CMoD3aElem::GetRuntimeClass_variant1` calls nothing directly
- `CMoD3aElem::GetRuntimeClass_variant2` calls nothing directly
- `CMoD3aElem::Init` calls `CMoElem::Constructor`
- `CMoD3aElem::ScalarDeletingDtor` calls `CMoElem::CMoElemFamily_SharedCleanup`, `SharedDeleteHelper`
