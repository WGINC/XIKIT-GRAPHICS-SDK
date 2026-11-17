# ResourceDtor

Group: `Resource` (by the file name only). Source: `sdk/tree_src/ResourceDtor.cpp`.

Why the file has this name (data/unit_names.json): CMoResource::Destructor

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoResource_CopyBodyTo20` | 0x10071E00 | 45 | yes | - | Copies the block the argument heads (its size in 16-byte units from its second dword) into the resource at +0x20 and returns the byte count. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoResource_CopyBodyTo20` calls nothing directly
