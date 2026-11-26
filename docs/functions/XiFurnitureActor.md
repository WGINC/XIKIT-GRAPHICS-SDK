# XiFurnitureActor

Group: `Xi` (by the file name only). Source: `sdk/tree_src/XiFurnitureActor.cpp`.

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `XiFurnitureActor::Release` | 0x100C3E70 | 79 | yes | - | Removes the furniture actor from the list and releases its model object. (reviewed as game_100C3E70) | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `XiFurnitureActor::Release` calls `game_10085240`, `game_10085270`, `CXiActor::Destroy`, `thunk_Mem_FreeBlockMergeNeighbours_as_v0`
