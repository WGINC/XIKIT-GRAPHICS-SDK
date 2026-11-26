# CYyTexMng

Group: `CYy` (by the file name only). Source: `sdk/tree_src/CYyTexMng.cpp`.

5 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CYyTexMng::GetRuntimeClass` | 0x1003AA40 | 6 | yes | - | - | - |
| `CYyTexMng_Init` | 0x1003AA50 | 24 | yes | - | Initialises the texture manager's vtable and its fields to empty. | medium |
| `CYyTexMng::ScalarDeletingDtor` | 0x1003AA70 | 30 | yes | - | - | - |
| `CYyTexMng::FindByName` | 0x1003AC80 | 80 | yes | - | - | - |
| `CYyTexMng::FindByNameInResource` | 0x1003AF10 | 202 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CYyTexMng::GetRuntimeClass` calls nothing directly
- `CYyTexMng_Init` calls nothing directly
- `CYyTexMng::ScalarDeletingDtor` calls `game_1003AA90`, `thunk_Mem_FreeBlockMergeNeighbours_as_v0`
- `CYyTexMng::FindByName` calls `TexMgr_GetField8`
- `CYyTexMng::FindByNameInResource` calls `CMoResource_FindInScope`, `TexMgr_GetField8`
