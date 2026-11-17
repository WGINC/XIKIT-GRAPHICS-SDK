# MemAllocDefault

Group: `Mem` (by the file name only). Source: `sdk/tree_src/MemAllocDefault.cpp`.

Why the file has this name (data/unit_names.json): Mem_AllocDefault (data/allocators.json)

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Mem_AllocDefault` | 0x1002C890 | 18 | yes | - | - | - |
| `thunk_sub_10028AA0` | 0x1002C8B0 | 5 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Mem_AllocDefault` calls `Mem_AllocFromArea`
- `thunk_sub_10028AA0` calls `Mem_FreeBlockMergeNeighbours`
