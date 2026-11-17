# CMoVuAnmElem

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoVuAnmElem.cpp`.

5 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoVuAnmElem::GetRuntimeClass` | 0x1003EF10 | 6 | yes | - | - | - |
| `CMoVuAnmElem::IsKind8` | 0x1003EF80 | 15 | yes | - | Returns whether the argument is 8, the kind this element class answers to. (reviewed as sub_1003EF80) | medium |
| `CMoVuAnmElem::vf008` | 0x1003EF90 | 5 | yes | - | Forwards to a base-class virtual method. (reviewed as sub_1003EF90) | low |
| `CMoVuAnmElem::ScalarDeletingDtor` | 0x1003EFA0 | 30 | yes | - | - | - |
| `CMoVuAnmElem::Construct` | 0x10052CD0 | 73 | yes | - | Constructs a VU animation element with its type id. (reviewed as sub_10052CD0) | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoVuAnmElem::GetRuntimeClass` calls nothing directly
- `CMoVuAnmElem::IsKind8` calls nothing directly
- `CMoVuAnmElem::vf008` calls nothing directly
- `CMoVuAnmElem::ScalarDeletingDtor` calls `sub_1003EF20`, `SharedDeleteHelper`
- `CMoVuAnmElem::Construct` calls `CMoElem::Constructor`, `DynVB_Constructor`
