# ProcessorBounds

Group: `Processor` (by the file name only). Source: `sdk/tree_src/ProcessorBounds.cpp`.

Why the file has this name (data/unit_names.json): CMoProcessor::CalcScreenBounds, Processor_InitIdentityMatrices, Mat4x4_SafeTranspose

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Processor_InitIdentityMatrices` | 0x1006EF70 | 286 | yes | - | Sets the processor's four matrices to identity. | medium |
| `Mat4x4_SafeTranspose` | 0x1006F0A0 | 355 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Processor_InitIdentityMatrices` calls `game_10313486`
- `Mat4x4_SafeTranspose` calls `CMoProcessor::TransposeInPlace`
