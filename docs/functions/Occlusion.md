# Occlusion

Group: `Occlusion` (by the file name only). Source: `sdk/tree_src/Occlusion.cpp`.

Why the file has this name (data/unit_names.json): Occlusion_QueryScreenRect / DrawQuery / ReadbackCount, OcclusionMng_*, CreateProcessorInstance

10 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `j_OcclusionMng_CreateTarget` | 0x1006C210 | 5 | yes | - | - | - |
| `OcclusionQuery_Init` | 0x1006C260 | 12 | yes | - | - | - |
| `Occlusion_QueryScreenRect` | 0x1006C280 | 121 | yes | 1 | - | - |
| `Occlusion_QueryScreenRectImpl` | 0x1006C300 | 550 | yes | 0 | - | - |
| `Occlusion_DrawQuery` | 0x1006C530 | 849 | yes | 0 | - | - |
| `Occlusion_ReadbackCount` | 0x1006C8B0 | 252 | yes | 0 | - | - |
| `OcclusionMng_Prepare` | 0x1006C9B0 | 112 | yes | 2 | - | - |
| `Occlusion_IsFloatClassAccepted` | 0x1006CA20 | 56 | yes | - | Tells whether a float's class code is one of those accepted. | low |
| `Occlusion_AreAll16FloatsAccepted` | 0x1006CA60 | 42 | yes | - | Checks 16 consecutive floats with 0x1006CA20. | low |
| `CreateProcessorInstance` | 0x1006CB50 | 213 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `j_OcclusionMng_CreateTarget` calls `CMoOcclusionMng::OcclusionMng_CreateTarget`
- `OcclusionQuery_Init` calls nothing directly
- `Occlusion_QueryScreenRect` calls `OcclusionMng_Prepare`, `CDx::NopB`, `Occlusion_QueryScreenRectImpl`, `CDx::NopA`
- `Occlusion_QueryScreenRectImpl` calls `game_10311C2C`, `CDx::GetRenderTargetTop`, `Occlusion_DrawQuery`, `Occlusion_ReadbackCount`
- `Occlusion_DrawQuery` calls `MoDX_SetInvalid`, `game_10313486`, `game_1006AE30`, `CDx::PushRenderTargetTexture_Flag1`, `Gfx_CalcFVFStride`, `CDx::DrawPrimitiveUP`, `CDx::PopRenderTargetA`, `CDx::PushRenderTargetTexture_Flag0`, `CDx::EndAndClearBegin`, `CDx::PopRenderTargetB`
- `Occlusion_ReadbackCount` calls nothing directly
- `OcclusionMng_Prepare` calls `CMoOcclusionMng::OcclusionMng_CreateTarget`
- `Occlusion_IsFloatClassAccepted` calls `game_1031450A`
- `Occlusion_AreAll16FloatsAccepted` calls `Occlusion_IsFloatClassAccepted`
- `CreateProcessorInstance` calls `CMoProcessor_DetectCpu`, `Mem_AllocDefault`, `VectorCtorIterator_CallForEachElement`, `CMoProcessor::InitRotationMatrices`, `Processor_InitIdentityMatrices`, `ProcessorInit_InitMatrices`
