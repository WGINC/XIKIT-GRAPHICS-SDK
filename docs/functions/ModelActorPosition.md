# ModelActorPosition

Group: `Model` (by the file name only). Source: `sdk/tree_src/ModelActorPosition.cpp`.

Why the file has this name (data/unit_names.json): read from the code: sets a model actor's position (actor+0x734, its model +0x24, Acter_CopyPosToCached); called from XiModelActor, XiFurnitureActor and the plant menu

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ModelActorPosition_SetPosition` | 0x100C3FF0 | 90 | yes | - | Sets the actor's position (two copies), and that of the object attached at +0x70. | medium |
| `ModelActorPosition_SetAnglesWrapped` | 0x100C4050 | 260 | yes | - | Sets the actor's three angles, wrapped into -pi..pi, and those of the object attached at +0x70. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ModelActorPosition_SetPosition` calls `Acter_CopyPosToCached`, `Vec4_Copy`
- `ModelActorPosition_SetAnglesWrapped` calls `Acter_CopyPosToCached`, `Vec4_Copy`
