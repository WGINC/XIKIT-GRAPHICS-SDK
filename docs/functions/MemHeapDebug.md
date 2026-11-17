# MemHeapDebug

Group: `Mem` (by the file name only). Source: `sdk/tree_src/MemHeapDebug.cpp`.

Why the file has this name (data/unit_names.json): Mem_DrawHeapUsageBar, the strings CYyDataMcb, CYyElemMcb, CYyMenuMcb...: the heaps drawn as bars

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `MemHeapDebug_ApplyFourTables` | 0x10029390 | 36 | yes | - | Runs the same operation with each of four global table pairs. | low |
| `Mem_DrawHeapUsageBar` | 0x100295A0 | 720 | yes | 0 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `MemHeapDebug_ApplyFourTables` calls `MemBlock_CallEnabledList2`, `MemBlock_CallEnabledList3`, `MemBlock_CallEnabledList1`, `MemBlock_CallEnabledList0`
- `Mem_DrawHeapUsageBar` calls `Vec4_Copy`, `MemBlock_GetSize`, `CDx::DrawPrimitiveUP`
