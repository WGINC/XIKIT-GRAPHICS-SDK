# sqrdTexture

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqrdTexture.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqrdTexture_Create` | 0x10298B30 | 32 | yes | - | Allocates and initialises a texture render record. | medium |
| `SqrdTexture_Init` | 0x10298B90 | 49 | yes | - | Initialises a texture render record and its function table. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqrdTexture_Create` calls `game_10275D80`, `SqrdTexture_Init`
- `SqrdTexture_Init` calls nothing directly
