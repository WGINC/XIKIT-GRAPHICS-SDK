# JpegTables

Group: `Jpeg` (by the file name only). Source: `sdk/tree_src/JpegTables.cpp`.

Why the file has this name (data/unit_names.json): BuildCodeTable, BuildTables; called only from YkJpeg (Encode, InitTables)

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `JpegTables_BuildTables` | 0x101CF660 | 435 | yes | - | Builds the fade lookup tables from a level. | low |
| `JpegTables_BuildCodeTable` | 0x101CF820 | 72 | yes | - | Builds a canonical prefix-code table from code lengths. | low |
| `JpegTables_Reset` | 0x101D0860 | 22 | yes | - | Resets a bit buffer's fields. | low |
| `JpegTables_Free` | 0x101D0880 | 51 | yes | - | Frees a bit buffer's two allocations. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `JpegTables_BuildTables` calls `JpegScreenshot_PutFFThenByte`, `JpegScreenshot_PutWordBE`, `JpegScreenshot_PutByte`
- `JpegTables_BuildCodeTable` calls nothing directly
- `JpegTables_Reset` calls nothing directly
- `JpegTables_Free` calls `thunk_Mem_FreeBlockMergeNeighbours_as_v0`, `operator_delete`
