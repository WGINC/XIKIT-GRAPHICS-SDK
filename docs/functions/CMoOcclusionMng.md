# CMoOcclusionMng

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoOcclusionMng.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoOcclusionMng::GetRuntimeClass` | 0x1006C130 | 6 | yes | - | - | - |
| `CMoOcclusionMng::ScalarDeletingDtor` | 0x1006C1C0 | 30 | yes | - | - | - |
| `CMoOcclusionMng::OcclusionMng_CreateTarget` | 0x1006C220 | 49 | yes | 1 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoOcclusionMng::GetRuntimeClass` calls nothing directly
- `CMoOcclusionMng::ScalarDeletingDtor` calls `game_1006C1E0`, `thunk_Mem_FreeBlockMergeNeighbours_as_v0`
- `CMoOcclusionMng::OcclusionMng_CreateTarget` calls `CDx::CreateTexture`
