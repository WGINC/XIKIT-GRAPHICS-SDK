# sqmoFrameChannel

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqmoFrameChannel.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqmoFrameChannel_Create` | 0x10293F80 | 32 | yes | - | Allocates and initialises a motion frame channel. | medium |
| `SqmoFrameChannel_Init` | 0x10293FA0 | 79 | yes | - | Initialises a motion frame channel and its function table. | medium |
| `SqmoFrameChannel_Apply` | 0x102944E0 | 30 | yes | - | Applies a frame channel's value to its target. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqmoFrameChannel_Create` calls `SqMem_AllocZeroed`, `SqmoFrameChannel_Init`
- `SqmoFrameChannel_Init` calls nothing directly
- `SqmoFrameChannel_Apply` calls `SqmoUtil_MarkSlot`
