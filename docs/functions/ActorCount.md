# ActorCount

Group: `Actor` (by the file name only). Source: `sdk/tree_src/ActorCount.cpp`.

Why the file has this name (data/unit_names.json): Actor_CountAll; called from the actor classes and the draw list

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Actor_CountAll` | 0x10082BF0 | 28 | yes | - | Returns the number of entries in the actor list. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Actor_CountAll` calls `game_10085240`, `game_10085270`
