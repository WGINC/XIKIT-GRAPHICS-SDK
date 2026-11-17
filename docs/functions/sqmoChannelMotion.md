# sqmoChannelMotion

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqmoChannelMotion.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqmoChannelMotion_Create` | 0x10295E70 | 32 | yes | - | Creates and initialises a new sqmo channel motion object. | medium |
| `SqmoChannelMotion_Init` | 0x10295E90 | 68 | yes | - | Initialises a channel motion object's header, callbacks and fields. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqmoChannelMotion_Create` calls `SqMem_AllocZeroed`, `SqmoChannelMotion_Init`
- `SqmoChannelMotion_Init` calls nothing directly
