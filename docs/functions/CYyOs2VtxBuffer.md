# CYyOs2VtxBuffer

Group: `CYy` (by the file name only). Source: `sdk/tree_src/CYyOs2VtxBuffer.cpp`.

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CYyOs2VtxBuffer::CreateBuffersStep` | 0x1002CCB0 | 332 | yes | 1 | - | - |
| `CYyOs2VtxBuffer_ScalarDeletingDtor` | 0x1002D660 | 30 | yes | 1 | Runs the vertex buffer object's destructor and frees it when bit 0 of the argument is set. | high |
| `CYyOs2VtxBuffer::Constructor` | 0x1002D680 | 126 | yes | 0 | - | - |
| `CYyOs2VtxBuffer::CYyOs2VtxBuffer_Destructor` | 0x1002D700 | 227 | yes | 0 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CYyOs2VtxBuffer::CreateBuffersStep` calls `Mem_AllocObject`, `CYyVbMng::AcquireVertexBuffer`, `Mem_FreeObject`, `CYyVbMng::ReleaseVertexBuffer`
- `CYyOs2VtxBuffer_ScalarDeletingDtor` calls `CYyOs2VtxBuffer::CYyOs2VtxBuffer_Destructor`, `SharedDeleteHelper`
- `CYyOs2VtxBuffer::Constructor` calls `CMoTask::Constructor`, `sub_10071F50`
- `CYyOs2VtxBuffer::CYyOs2VtxBuffer_Destructor` calls `Mem_FreeObject`, `CYyVbMng::ReleaseVertexBuffer`, `CMoTask::Destructor`
