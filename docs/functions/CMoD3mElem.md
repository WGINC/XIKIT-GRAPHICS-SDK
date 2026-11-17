# CMoD3mElem

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoD3mElem.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoD3mElem_DeletingDtor` | 0x10041130 | 36 | yes | - | - | - |
| `CMoD3mElem::Ctor` | 0x10052F00 | 18 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoD3mElem_DeletingDtor` calls `CMoElem::CMoElemFamily_SharedCleanup`, `SharedDeleteHelper`
- `CMoD3mElem::Ctor` calls `CMoElem::Constructor`
