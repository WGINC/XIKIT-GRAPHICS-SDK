# sqmdSnap

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqmdSnap.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqmdSnap_Create` | 0x1028DC00 | 32 | yes | - | Allocates and initialises a model snapshot record. | medium |
| `SqmdSnap_Init` | 0x1028DC20 | 78 | yes | - | Initialises a model snapshot record and its function table. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqmdSnap_Create` calls `sub_10275D80`, `SqmdSnap_Init`
- `SqmdSnap_Init` calls nothing directly
