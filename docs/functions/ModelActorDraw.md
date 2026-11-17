# ModelActorDraw

Group: `Model` (by the file name only). Source: `sdk/tree_src/ModelActorDraw.cpp`.

Why the file has this name (data/unit_names.json): XiModelActor::BuildMatrixAndDraw / BuildWorldMatrix / CopyRectFromSlot

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ModelActorDraw_GetVec3PairIfModel` | 0x100C4BC0 | 87 | yes | - | When the actor has the object at +0x5C4, writes its two vectors at +0x734 and +0x744 out and returns that object's field at +0x30; else returns 0. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ModelActorDraw_GetVec3PairIfModel` calls nothing directly
