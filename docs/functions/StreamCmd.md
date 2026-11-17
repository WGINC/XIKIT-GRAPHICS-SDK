# StreamCmd

Group: `Stream` (by the file name only). Source: `sdk/tree_src/StreamCmd.cpp`.

Why the file has this name (data/unit_names.json): calls only the stream thread commands (SendCmd6, 8, 9: the thread at 0x10245650 reads files, never the network)

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `LobbyThread_SendCmd6IfRunning` | 0x10037A10 | 18 | yes | - | Sends command 6 to the lobby thread when it is running. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `LobbyThread_SendCmd6IfRunning` calls `LobbyThread_SendCmd6`
