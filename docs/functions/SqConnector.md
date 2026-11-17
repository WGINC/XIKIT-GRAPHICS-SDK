# SqConnector

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqConnector.cpp`.

Why the file has this name (data/unit_names.json): CreateFromFields; calls SqcoConnector_Create

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqConnector_CreateFromFields` | 0x1028D870 | 45 | yes | - | Creates a node and stores five values in its fields. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqConnector_CreateFromFields` calls `SqcoConnector_Create`
