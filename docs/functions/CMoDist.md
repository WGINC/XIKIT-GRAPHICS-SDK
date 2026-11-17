# CMoDist

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoDist.cpp`.

6 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoDist::GetRuntimeClass_variant0` | 0x100426E0 | 6 | yes | - | - | - |
| `CMoDist::GetRuntimeClass_variant1` | 0x100430B0 | 6 | yes | - | - | - |
| `CMoDist::Init` | 0x10052D40 | 27 | yes | - | Constructs the base element and sets the CMoDist vtable and its field at 0x176. (reviewed as sub_10052D40) | medium |
| `CMoDist::IsKind1` | 0x10052D60 | 15 | yes | - | Returns whether the argument is 1, the kind this class answers to. (reviewed as sub_10052D60) | medium |
| `CMoDist::set_field_194` | 0x10052D70 | 13 | yes | - | - | - |
| `CMoDist::ScalarDeletingDtor` | 0x10052D80 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoDist::GetRuntimeClass_variant0` calls nothing directly
- `CMoDist::GetRuntimeClass_variant1` calls nothing directly
- `CMoDist::Init` calls `CMoElem::Constructor`
- `CMoDist::IsKind1` calls nothing directly
- `CMoDist::set_field_194` calls nothing directly
- `CMoDist::ScalarDeletingDtor` calls `CMoElem::CMoElemFamily_SharedCleanup`, `SharedDeleteHelper`
