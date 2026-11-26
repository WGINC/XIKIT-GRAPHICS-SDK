# SqPlaybackChannelLoad

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqPlaybackChannelLoad.cpp`.

Why the file has this name (data/unit_names.json): PlaybackChannel_Load, the string "Error: PlaybackChannel version"

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `PlaybackChannel_Load` | 0x102853F0 | 778 | yes | - | Loads a playback channel of version 3 from a stream, allocating its buffers. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `PlaybackChannel_Load` calls `SqScriptRead_ReadBlock`, `sqDebugPrintf`, `SqmoPlaybackChannel_Create`, `game_10275D80`, `SqChannelHandler_SetHandlerByType`, `SqmoPlaybackChannel_Update`
