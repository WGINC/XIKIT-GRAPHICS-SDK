# CMoD3aLightmapElem

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoD3aLightmapElem.cpp`.

5 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoD3aLightmapElem::GetRuntimeClass` | 0x1003EE60 | 6 | yes | - | - | - |
| `CMoD3aLightmapElem::Init` | 0x10052C30 | 27 | yes | - | Constructs the base element and sets the CMoD3aLightmapElem vtable and its field at 0x176. (reviewed as sub_10052C30) | medium |
| `CMoD3aLightmapElem::set_field_194` | 0x10052C50 | 13 | yes | - | - | - |
| `CMoD3aLightmapElem::get_field_194` | 0x10052C60 | 7 | yes | - | - | - |
| `CMoD3aLightmapElem::ScalarDeletingDtor` | 0x10052C70 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoD3aLightmapElem::GetRuntimeClass` calls nothing directly
- `CMoD3aLightmapElem::Init` calls `CMoElem::Constructor`
- `CMoD3aLightmapElem::set_field_194` calls nothing directly
- `CMoD3aLightmapElem::get_field_194` calls nothing directly
- `CMoD3aLightmapElem::ScalarDeletingDtor` calls `CMoElem::CMoElemFamily_SharedCleanup`, `SharedDeleteHelper`
