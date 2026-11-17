# CXiActorDraw

Group: `CXi` (by the file name only). Source: `sdk/tree_src/CXiActorDraw.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CXiActorDraw::Update` | 0x100817E0 | 8 | yes | - | - | - |
| `CXiActorDraw::UpdateDrawList` | 0x10082D70 | 324 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CXiActorDraw::Update` calls `CXiActorDraw::UpdateDrawList`
- `CXiActorDraw::UpdateDrawList` calls `Settings_GetValue`
