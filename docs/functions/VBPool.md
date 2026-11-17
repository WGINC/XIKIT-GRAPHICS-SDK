# VBPool

Group: `V` (by the file name only). Source: `sdk/tree_src/VBPool.cpp`.

Why the file has this name (data/unit_names.json): VBPool_Constructor, FindMatch, Insert

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `VBPool_Constructor` | 0x1006B0C0 | 32 | yes | - | - | - |
| `VBPool_Insert` | 0x1006B120 | 170 | yes | - | Inserts a record into the dynamic vertex-buffer pool, evicting the oldest when full. | low |
| `VBPool_FindMatch` | 0x1006B1D0 | 120 | yes | - | Finds the oldest pool entry that matches a request and releases it. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `VBPool_Constructor` calls nothing directly
- `VBPool_Insert` calls nothing directly
- `VBPool_FindMatch` calls nothing directly
