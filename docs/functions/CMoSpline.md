# CMoSpline

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoSpline.cpp`.

12 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoSpline::GetRuntimeClass` | 0x10063450 | 6 | yes | - | - | - |
| `CMoSpline_Construct` | 0x10063460 | 26 | yes | - | Constructs a spline and clears its fields. | medium |
| `CMoSpline::ScalarDeletingDtor` | 0x10063480 | 30 | yes | - | - | - |
| `CMoSpline::Destructor` | 0x100634A0 | 11 | yes | - | - | - |
| `CMoSpline::Init` | 0x100634B0 | 150 | yes | - | Initialises a spline with its channel and sample buffers. (reviewed as game_100634B0) | medium |
| `CMoSpline::FreeBuffers` | 0x10063550 | 90 | yes | - | Frees a spline's channel and sample buffers. (reviewed as game_10063550) | medium |
| `CMoSpline::BuildSegmentTables` | 0x100635B0 | 731 | yes | - | Builds the spline's per-segment lengths (normalized by the total) and per-segment 4x4 basis matrices. (reviewed as game_100635B0) | medium |
| `CMoSpline::ReleaseRef` | 0x10063B20 | 35 | yes | - | Releases one reference to a spline's cached object, freeing it at zero. (reviewed as game_10063B20) | low |
| `CMoSpline::GetWrapped` | 0x10063B50 | 18 | yes | - | Returns the table entry at an index that wraps around the count. (reviewed as game_10063B50) | low |
| `CMoSpline::GetData` | 0x10063B70 | 4 | yes | - | Returns the address of a spline's data block at +0x10. (reviewed as game_10063B70) | low |
| `CMoSpline::EnsureSamples` | 0x10063B80 | 171 | yes | - | Builds the spline's sample table on first use and returns it. (reviewed as game_10063B80) | medium |
| `CMoSpline::SetValue` | 0x10063C30 | 25 | yes | - | Sets a value on the spline's sample table. (reviewed as game_10063C30) | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoSpline::GetRuntimeClass` calls nothing directly
- `CMoSpline_Construct` calls nothing directly
- `CMoSpline::ScalarDeletingDtor` calls `CMoSpline::Destructor`, `thunk_Mem_FreeBlockMergeNeighbours_as_v0`
- `CMoSpline::Destructor` calls `CMoSpline::FreeBuffers`
- `CMoSpline::Init` calls `CMoSpline::FreeBuffers`, `Mem_AllocObject`
- `CMoSpline::FreeBuffers` calls `Mem_FreeObject`
- `CMoSpline::BuildSegmentTables` calls nothing directly
- `CMoSpline::ReleaseRef` calls nothing directly
- `CMoSpline::GetWrapped` calls nothing directly
- `CMoSpline::GetData` calls nothing directly
- `CMoSpline::EnsureSamples` calls `Mem_AllocDefault`, `CMoSpline_Construct`, `CMoSpline::Init`, `CMoSpline::GetWrapped`, `CMoSpline::BuildSegmentTables`
- `CMoSpline::SetValue` calls `CMoSpline::EnsureSamples`, `game_10063A60`
