# MemArea

Group: `Mem` (by the file name only). Source: `sdk/tree_src/MemArea.cpp`.

Why the file has this name (data/unit_names.json): Mem_AllocFromArea (the area allocator, data/allocators.json)

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Mem_AllocFromArea` | 0x10028FD0 | 346 | yes | - | - | - |
| `MemArea_CallListByKind` | 0x10029150 | 176 | yes | - | Calls 0x100289F0 on the list range chosen by a kind. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Mem_AllocFromArea` calls `MemBlock_AllocFromBack`, `MemBlock_AllocFromFront`, `_exit_0`
- `MemArea_CallListByKind` calls `MemBlock_FindLargestFreeSize`
