# sqimImage

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqimImage.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqimImage_Create` | 0x102984B0 | 32 | yes | - | Creates and initialises a new sqImage object. | medium |
| `SqimImage_Init` | 0x10298570 | 47 | yes | - | Initialises a sqImage object's header and fields. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqimImage_Create` calls `sub_10275D80`, `SqimImage_Init`
- `SqimImage_Init` calls nothing directly
