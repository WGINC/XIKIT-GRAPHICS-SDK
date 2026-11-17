# FurnitureRelease

Group: `Furniture` (by the file name only). Source: `sdk/tree_src/FurnitureRelease.cpp`.

Why the file has this name (data/unit_names.json): ReleaseSlot; called from YkFurniture::Destructor; calls CXiMannequinActor

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `FurnitureRelease_ReleaseSlot` | 0x100AB550 | 53 | yes | - | Frees the actor held at a slot and clears the slot. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `FurnitureRelease_ReleaseSlot` calls `CXiActor::Destroy`, `thunk_sub_10028AA0`
