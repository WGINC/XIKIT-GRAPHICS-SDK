# Os2VtxBuffer

Group: `Os2` (by the file name only). Source: `sdk/tree_src/Os2VtxBuffer.cpp`.

Why the file has this name (data/unit_names.json): FixOffsetsAndCreateVtxBuffer, called only from the Os2 resource check; calls CYyOs2VtxBuffer::Constructor

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Os2VtxBuffer_FixOffsetsAndCreateVtxBuffer` | 0x1002D8F0 | 133 | yes | 1 | Turns the resource's six word offsets into pointers and creates its CYyOs2VtxBuffer once. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Os2VtxBuffer_FixOffsetsAndCreateVtxBuffer` calls `Mem_AllocFromArea`, `CMoTask::ResetFields`, `CYyOs2VtxBuffer::Constructor`
