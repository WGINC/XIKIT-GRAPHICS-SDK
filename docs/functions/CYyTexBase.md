# CYyTexBase

Group: `CYy` (by the file name only). Source: `sdk/tree_src/CYyTexBase.cpp`.

5 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CYyTexBase::GetRuntimeClass_variant0` | 0x10039770 | 6 | yes | - | - | - |
| `CYyTexBase::GetRuntimeClass_variant1` | 0x10039780 | 6 | yes | - | - | - |
| `CYyTexBase::Constructor` | 0x10039830 | 115 | yes | - | Constructs a texture base and gives it a numbered name. (reviewed as game_10039830) | medium |
| `CYyTexBase::ScalarDeletingDtor` | 0x100398B0 | 30 | yes | - | - | - |
| `CYyTexBase::SetName` | 0x100398E0 | 32 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CYyTexBase::GetRuntimeClass_variant0` calls nothing directly
- `CYyTexBase::GetRuntimeClass_variant1` calls nothing directly
- `CYyTexBase::Constructor` calls `Camera_GetByte0B`, `game_10311FF1`, `CYyTexBase::SetName`
- `CYyTexBase::ScalarDeletingDtor` calls `game_100398D0`, `thunk_Mem_FreeBlockMergeNeighbours_as_v0`
- `CYyTexBase::SetName` calls nothing directly
