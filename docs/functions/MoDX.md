# MoDX

Group: `Mo` (by the file name only). Source: `sdk/tree_src/MoDX.cpp`.

Why the file has this name (data/unit_names.json): CMoDX::SetViewMatrix / SetWorldMatrix / Push / PopViewMatrix / CreateTexture, StateBlock_ApplyTSS, Batch_DrawPrimitives, Camera_SetupMatrices

14 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `MoDX_Nop` | 0x10069E90 | 1 | yes | - | Does nothing. | low |
| `MoDX_ClearByteTables` | 0x10069EA0 | 57 | yes | - | Clears two 256-byte tables in the object. | low |
| `MoDX_Update` | 0x10069F90 | 129 | yes | - | Updates the frame timer from the system clock. | medium |
| `Gfx_CreateVertexBuffer` | 0x1006A020 | 58 | yes | 0 | Creates a Direct3D vertex buffer for the given FVF and vertex count. | high |
| `Camera_SetupMatrices` | 0x1006A180 | 381 | yes | - | Builds the view and projection matrices for the camera. | low |
| `Dx_GetCachedTransform2` | 0x1006A540 | 21 | yes | - | Gets the cached transform with index 2. | low |
| `Gfx_CalcFVFStride` | 0x1006A560 | 94 | yes | - | - | - |
| `Batch_DrawPrimitives` | 0x1006AA30 | 228 | yes | 1 | Draws the batch's primitive lists through Direct3D. | medium |
| `Attach_SetTranslation` | 0x1006AD30 | 26 | yes | - | Stores an attachment's translation vector. | low |
| `Processor_ApplyPair` | 0x1006AD50 | 46 | yes | - | Applies a processor operation to a pair of entries. | low |
| `MoDX_SetInvalid` | 0x1006AD90 | 17 | yes | - | Sets a three-dword handle to its invalid value. | low |
| `MoDX_Insert` | 0x1006ADF0 | 30 | yes | - | Inserts an entry at the head of the DX status list. | low |
| `StateBlockHolder_ApplyRenderStates` | 0x1006AF00 | 142 | yes | 0 | - | - |
| `StateBlock_ApplyTSS` | 0x1006AF90 | 146 | yes | 0 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `MoDX_Nop` calls nothing directly
- `MoDX_ClearByteTables` calls nothing directly
- `MoDX_Update` calls `Camera_GetFrameScale`
- `Gfx_CreateVertexBuffer` calls `Gfx_CalcFVFStride`
- `Camera_SetupMatrices` calls `CDx::GetTransformCached`, `Processor_ApplyPair`, `CDx::GetRenderTargetTop`
- `Dx_GetCachedTransform2` calls `CDx::GetTransformCached`
- `Gfx_CalcFVFStride` calls nothing directly
- `Batch_DrawPrimitives` calls `Gfx_CalcFVFStride`, `CDx::DrawPrimitive`
- `Attach_SetTranslation` calls nothing directly
- `Processor_ApplyPair` calls nothing directly
- `MoDX_SetInvalid` calls nothing directly
- `MoDX_Insert` calls nothing directly
- `StateBlockHolder_ApplyRenderStates` calls `MoDX_Insert`
- `StateBlock_ApplyTSS` calls `MoDX_Insert`
