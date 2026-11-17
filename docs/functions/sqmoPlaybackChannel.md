# sqmoPlaybackChannel

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqmoPlaybackChannel.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqmoPlaybackChannel_Create` | 0x102924F0 | 35 | yes | - | Creates a sqmoPlaybackChannel object. | medium |
| `SqmoPlaybackChannel_Init` | 0x10292520 | 103 | yes | - | Initialises a sqmoPlaybackChannel object. | medium |
| `SqmoPlaybackChannel_Update` | 0x10293000 | 30 | yes | - | Updates a playback channel from its owner's values. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqmoPlaybackChannel_Create` calls `SqMem_AllocZeroed`, `SqmoPlaybackChannel_Init`
- `SqmoPlaybackChannel_Init` calls nothing directly
- `SqmoPlaybackChannel_Update` calls `SqmoUtil_MarkSlot`
