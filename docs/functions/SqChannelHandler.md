# SqChannelHandler

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqChannelHandler.cpp`.

Why the file has this name (data/unit_names.json): SetHandlerByType; called from sqmoPlaybackChannel

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqChannelHandler_SetHandlerByType` | 0x10293F00 | 87 | yes | - | Picks a channel's handler function by its type. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqChannelHandler_SetHandlerByType` calls nothing directly
