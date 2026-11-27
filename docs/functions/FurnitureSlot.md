# FurnitureSlot

Group: `Furniture` (by the file name only). Source: `sdk/tree_src/FurnitureSlot.cpp`.

Why the file has this name (data/unit_names.json): Acter_DestroyAndClearSlot; called from YkFurniture::Destructor

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Acter_DestroyAndClearSlot` | 0x100AB320 | 53 | yes | - | Destroys and frees the acter held at +0x70 of the argument and clears its slot in the acter table. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Acter_DestroyAndClearSlot` calls `CXiActor::Destroy`, `thunk_Mem_FreeBlockMergeNeighbours_as_v0`
