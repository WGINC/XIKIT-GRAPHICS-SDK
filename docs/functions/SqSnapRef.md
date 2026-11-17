# SqSnapRef

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqSnapRef.cpp`.

Why the file has this name (data/unit_names.json): CreateRef; calls SqmdSnap_Create

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqSnapRef_CreateRef` | 0x1028DE10 | 48 | yes | - | Creates a reference object for the owner and sets its fields. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqSnapRef_CreateRef` calls `SqmdSnap_Create`
