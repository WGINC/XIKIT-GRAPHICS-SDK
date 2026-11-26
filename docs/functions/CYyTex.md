# CYyTex

Group: `CYy` (by the file name only). Source: `sdk/tree_src/CYyTex.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CYyTex::GetRuntimeClass` | 0x10039790 | 6 | yes | - | - | - |
| `TexObj_Constructor` | 0x10039920 | 40 | yes | - | - | - |
| `CYyTex::ScalarDeletingDtor` | 0x10039950 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CYyTex::GetRuntimeClass` calls nothing directly
- `TexObj_Constructor` calls `CYyTexBase::Constructor`
- `CYyTex::ScalarDeletingDtor` calls `game_10039970`, `thunk_Mem_FreeBlockMergeNeighbours_as_v0`
