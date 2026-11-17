# sqdfShape

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqdfShape.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqdfShape_Create` | 0x102AEE90 | 32 | yes | - | Creates a sqdfShape object. | medium |
| `SqdfShape_Init` | 0x102AEEB0 | 68 | yes | - | Initialises a sqdfShape object's vtable and fields. | medium |
| `SqdfShape_InitCallbacks` | 0x102AF170 | 66 | yes | - | Initialises a shape record with its three handlers. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqdfShape_Create` calls `sub_10275D80`, `SqdfShape_Init`
- `SqdfShape_Init` calls nothing directly
- `SqdfShape_InitCallbacks` calls `SqVec_ZeroDwords`
