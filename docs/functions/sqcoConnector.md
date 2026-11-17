# sqcoConnector

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqcoConnector.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqcoConnector_Create` | 0x1028D6D0 | 32 | yes | - | Allocates a Squirrel connector object and initialises it. | medium |
| `SqcoConnector_Init` | 0x1028D6F0 | 60 | yes | - | Sets the connector's type code, callbacks and defaults. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqcoConnector_Create` calls `SqMem_AllocZeroed`, `SqcoConnector_Init`
- `SqcoConnector_Init` calls nothing directly
