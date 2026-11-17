# sqmoKeyChannel

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqmoKeyChannel.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqmoKeyChannel_Create` | 0x102957B0 | 32 | yes | - | Allocates a Squirrel key-channel object and initialises it. | medium |
| `SqmoKeyChannel_Init` | 0x102957D0 | 73 | yes | - | Sets the key channel's type code, callbacks and defaults. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqmoKeyChannel_Create` calls `SqMem_AllocZeroed`, `SqmoKeyChannel_Init`
- `SqmoKeyChannel_Init` calls nothing directly
