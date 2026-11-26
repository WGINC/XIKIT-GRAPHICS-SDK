# CMoNullProgElem

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoNullProgElem.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoNullProgElem::GetRuntimeClass` | 0x10047560 | 6 | yes | - | - | - |
| `CMoNullProgElem::Construct` | 0x10053180 | 18 | yes | - | Constructs the null program element and sets its vtable. (reviewed as game_10053180) | medium |
| `CMoNullProgElem::Destructor` | 0x100531B0 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoNullProgElem::GetRuntimeClass` calls nothing directly
- `CMoNullProgElem::Construct` calls `CMoElem::Constructor`
- `CMoNullProgElem::Destructor` calls `CMoElem::CMoElemFamily_SharedCleanup`, `SharedDeleteHelper`
