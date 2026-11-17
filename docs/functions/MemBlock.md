# MemBlock

Group: `Mem` (by the file name only). Source: `sdk/tree_src/MemBlock.cpp`.

Why the file has this name (data/unit_names.json): MemBlock_GetSize, Mem_FreeBlockMergeNeighbours: the block allocator

8 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Mem_FreeBlockMergeNeighbours` | 0x10028AA0 | 22 | yes | - | Marks the heap block before the pointer as unused and merges it with unused neighbouring blocks. | medium |
| `Mem_FreeHeaderMergeNeighbours` | 0x10028AC0 | 175 | yes | - | Marks a heap block header as unused and merges it with unused neighbouring blocks. | medium |
| `MemBlock_GetSize` | 0x10028B90 | 16 | yes | - | - | - |
| `MemBlock_CallEnabledEntries` | 0x10028BF0 | 51 | yes | - | Calls a method with the given argument on each enabled entry of a list range. | low |
| `MemBlock_CallEnabledList0` | 0x10028C30 | 27 | yes | - | Calls the enabled entries of the list at 0x104570B4. | low |
| `MemBlock_CallEnabledList1` | 0x10028C50 | 27 | yes | - | Calls the enabled entries of the list at 0x104570BC. | low |
| `MemBlock_CallEnabledList2` | 0x10028C70 | 27 | yes | - | Calls the enabled entries of the list at 0x104570C4. | low |
| `MemBlock_CallEnabledList3` | 0x10028C90 | 27 | yes | - | Calls the enabled entries of the list at 0x104570CC. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Mem_FreeBlockMergeNeighbours` calls `Mem_GetPtrMinus0x20`, `Mem_FreeHeaderMergeNeighbours`
- `Mem_FreeHeaderMergeNeighbours` calls nothing directly
- `MemBlock_GetSize` calls nothing directly
- `MemBlock_CallEnabledEntries` calls nothing directly
- `MemBlock_CallEnabledList0` calls `MemBlock_CallEnabledEntries`
- `MemBlock_CallEnabledList1` calls `MemBlock_CallEnabledEntries`
- `MemBlock_CallEnabledList2` calls `MemBlock_CallEnabledEntries`
- `MemBlock_CallEnabledList3` calls `MemBlock_CallEnabledEntries`
