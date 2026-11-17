# SqChannelMotion

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqChannelMotion.cpp`.

Why the file has this name (data/unit_names.json): CreateWithOwner; calls SqmoChannelMotion_Create

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqChannelMotion_CreateWithOwner` | 0x102960A0 | 26 | yes | - | Creates an object tied to the given owner and stores its arguments. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqChannelMotion_CreateWithOwner` calls `SqmoChannelMotion_Create`
