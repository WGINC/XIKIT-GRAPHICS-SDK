# Os2Resource

Group: `Os2` (by the file name only). Source: `sdk/tree_src/Os2Resource.cpp`.

Why the file has this name (data/unit_names.json): CMoResource_VT_1032C854::CheckVersionAndInit with the string "Os2 Version Error %d"

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoResource_DropObjectAt5E` | 0x1002D860 | 32 | yes | - | Calls slot 6 with 1 on the object at +0x5E and clears the pointer. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoResource_DropObjectAt5E` calls nothing directly
