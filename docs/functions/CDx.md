# CDx

Group: `CDx` (by the file name only). Source: `sdk/tree_src/CDx.cpp`.

57 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CDx::GetRuntimeClass` | 0x10008F80 | 6 | yes | - | - | - |
| `CDx::ScalarDeletingDtor` | 0x10009100 | 30 | yes | - | - | - |
| `CDx::Initialize` | 0x100091B0 | 1116 | yes | 0 | - | - |
| `CDx::SetDefaultRenderTargets` | 0x10009620 | 25 | yes | - | - | - |
| `CDx::SetClearParams` | 0x10009640 | 43 | yes | - | - | - |
| `CDx::SetClearColor` | 0x10009670 | 13 | yes | - | - | - |
| `CDx::EndClearBegin` | 0x100096B0 | 83 | yes | 0 | - | - |
| `CDx::TestCooperativeLevel` | 0x10009710 | 15 | yes | 0 | - | - |
| `CDx::Present` | 0x10009720 | 11 | yes | 0 | - | - |
| `CDx::BeginScene` | 0x10009730 | 13 | yes | 0 | - | - |
| `CDx::EndScene` | 0x10009740 | 13 | yes | 0 | - | - |
| `CDx::SetHardwareCursor` | 0x10009750 | 18 | yes | - | Sets the cursor through the Win32 SetCursor call when hardware mouse is enabled. (reviewed as sub_10009750) | high |
| `SetCursorPos` | 0x10009770 | 6 | yes | - | - | - |
| `CDx::ShowCursor` | 0x10009780 | 104 | yes | - | - | - |
| `CDx::SetCursorShape` | 0x100097F0 | 98 | yes | - | - | - |
| `CDx::CreateDeviceObjectOnce` | 0x10009870 | 111 | yes | - | Creates a handle through the +0xC object's slot 57 when there is none yet. (reviewed as sub_10009870) | low |
| `CDx_EndAndApplyStateBlock` | 0x100098E0 | 58 | yes | - | Optionally ends recording a state block into the token, then applies the token's state block if it is valid. | medium |
| `CDx::AppendStateRecord` | 0x10009D20 | 159 | yes | - | Writes a state record at the current index and passes it to the device. (reviewed as sub_10009D20) | low |
| `CDx::SetViewport` | 0x10009DC0 | 53 | yes | 0 | - | - |
| `CDx::GetRenderTargetTop` | 0x10009E00 | 19 | yes | - | - | - |
| `CDx::PushRenderTarget` | 0x10009E20 | 51 | yes | 1 | - | - |
| `CDx::PushRenderTargetTexture_Flag1` | 0x10009EA0 | 50 | yes | 1 | Pushes a render target texture with the first flag set. (reviewed as sub_10009EA0) | low |
| `CDx::PushRenderTargetTexture_Flag0` | 0x10009EE0 | 49 | yes | 1 | Pushes a render target texture with the first flag clear. (reviewed as sub_10009EE0) | low |
| `CDx::PushRenderTargetTexture` | 0x10009F20 | 328 | yes | 0 | - | - |
| `CDx::Call1000A0A0Zeroed` | 0x1000A070 | 47 | yes | - | Calls 0x1000A0A0 with two zeroed outputs. (reviewed as sub_1000A070) | low |
| `CDx::SetTexture` | 0x1000A1D0 | 44 | yes | 0 | - | - |
| `CDx::PopRenderTargetA` | 0x1000A200 | 44 | yes | - | Pops the render target after the device call, with flags 1 and 0. (reviewed as sub_1000A200) | low |
| `CDx::PopRenderTargetB` | 0x1000A230 | 44 | yes | - | Pops the render target after the device call, with flags 0 and 1. (reviewed as sub_1000A230) | low |
| `CDx::PopRenderTargetDefault` | 0x1000A290 | 22 | yes | - | - | - |
| `CDx::EndAndClearBegin` | 0x1000A390 | 32 | yes | 1 | Calls CDx_EndClearBegin with zero clear arguments. (reviewed as sub_1000A390) | low |
| `CDx::DrawScreenQuadAtDepth` | 0x1000A3B0 | 306 | yes | 0 | - | - |
| `CDx::DrawTextureToViewport` | 0x1000A4F0 | 86 | yes | 3 | - | - |
| `CDx::DrawTexturedScreenQuadUnit` | 0x1000A550 | 68 | yes | 2 | Draws a textured screen quad using the unit rectangle. (reviewed as sub_1000A550) | medium |
| `CDx::DrawTexturedScreenQuad` | 0x1000A5A0 | 305 | yes | 1 | - | - |
| `CDx::CreateTexture` | 0x1000A6E0 | 243 | yes | 0 | - | - |
| `CDx::PushRenderTargetRet1` | 0x1000A800 | 25 | yes | 2 | - | - |
| `CDx::DrawFadeQuad` | 0x1000A820 | 651 | yes | 0 | - | - |
| `CDx::Post_DepthBlurComposite` | 0x1000AAB0 | 289 | yes | 0 | - | - |
| `CDx::StepFadeCounter` | 0x1000AE40 | 95 | yes | - | - | - |
| `CDx::NopA` | 0x1000BB10 | 1 | yes | - | Does nothing. (reviewed as sub_1000BB10) | low |
| `CDx::NopB` | 0x1000BB20 | 1 | yes | - | Does nothing. (reviewed as sub_1000BB20) | low |
| `CDx::DrawStereoOddFrameOverlay` | 0x1000BB90 | 437 | yes | 0 | - | - |
| `CDx::SetTransform` | 0x1000BD50 | 82 | yes | 0 | - | - |
| `CDx::GetTransformCached` | 0x1000BDB0 | 87 | yes | - | - | - |
| `CDx_SetVertexShaderCached` | 0x1000BE10 | 55 | yes | - | Sets the device's vertex shader only when it differs from the cached one at +0x9FC; 0 just clears the cache. | medium |
| `Light_ApplyTimeOfDayTint` | 0x1000BE50 | 223 | yes | - | - | - |
| `CDx::SetLight` | 0x1000BF30 | 243 | yes | 0 | - | - |
| `CDx::CompositeSceneToBackBuffer` | 0x1000C0B0 | 1569 | yes | 0 | - | - |
| `CDx::CreateStereoResources` | 0x1000C6E0 | 218 | yes | 1 | - | - |
| `CDx::ReleaseStereoResources` | 0x1000C7C0 | 141 | yes | - | - | - |
| `CDx::CreateRampTexture1x16` | 0x1000C850 | 175 | yes | 0 | - | - |
| `CDx::CreateRampTextures1024x2` | 0x1000C900 | 245 | yes | 0 | - | - |
| `CDx::DrawPrimitive` | 0x1000CB20 | 218 | yes | 0 | - | - |
| `CDx::DrawIndexedPrimitive` | 0x1000CC00 | 248 | yes | 0 | - | - |
| `CDx::DrawPrimitiveUP` | 0x1000CD00 | 233 | yes | 0 | - | - |
| `CDx::ApplyStereoEyeProjection` | 0x1000CF20 | 110 | yes | 0 | - | - |
| `CDx::RestoreProjection` | 0x1000CF90 | 22 | yes | 0 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CDx::GetRuntimeClass` calls nothing directly
- `CDx::ScalarDeletingDtor` calls `sub_10009120`, `thunk_sub_10028AA0`
- `CDx::Initialize` calls `sub_103127C0`
- `CDx::SetDefaultRenderTargets` calls nothing directly
- `CDx::SetClearParams` calls nothing directly
- `CDx::SetClearColor` calls nothing directly
- `CDx::EndClearBegin` calls `CDx::EndScene`, `CDx::BeginScene`
- `CDx::TestCooperativeLevel` calls nothing directly
- `CDx::Present` calls `ErrorReport_NoOpVarargsA`
- `CDx::BeginScene` calls nothing directly
- `CDx::EndScene` calls nothing directly
- `CDx::SetHardwareCursor` calls nothing directly
- `SetCursorPos` calls nothing directly
- `CDx::ShowCursor` calls nothing directly
- `CDx::SetCursorShape` calls `Cursor_GetHwCursorSlot`
- `CDx::CreateDeviceObjectOnce` calls nothing directly
- `CDx_EndAndApplyStateBlock` calls nothing directly
- `CDx::AppendStateRecord` calls nothing directly
- `CDx::SetViewport` calls nothing directly
- `CDx::GetRenderTargetTop` calls nothing directly
- `CDx::PushRenderTarget` calls `CDx::PushRenderTargetTexture`
- `CDx::PushRenderTargetTexture_Flag1` calls `CDx::PushRenderTargetTexture`
- `CDx::PushRenderTargetTexture_Flag0` calls `CDx::PushRenderTargetTexture`
- `CDx::PushRenderTargetTexture` calls nothing directly
- `CDx::Call1000A0A0Zeroed` calls `sub_1000A0A0`
- `CDx::SetTexture` calls `sub_1000A2B0`
- `CDx::PopRenderTargetA` calls `sub_1000A2B0`
- `CDx::PopRenderTargetB` calls `sub_1000A2B0`
- `CDx::PopRenderTargetDefault` calls `sub_1000A2B0`
- `CDx::EndAndClearBegin` calls `CDx::EndClearBegin`
- `CDx::DrawScreenQuadAtDepth` calls `CDx::GetRenderTargetTop`, `CDx::DrawPrimitiveUP`
- `CDx::DrawTextureToViewport` calls `CDx::DrawTexturedScreenQuadUnit`
- `CDx::DrawTexturedScreenQuadUnit` calls `CDx::DrawTexturedScreenQuad`
- `CDx::DrawTexturedScreenQuad` calls `CDx::DrawPrimitiveUP`
- `CDx::CreateTexture` calls nothing directly
- `CDx::PushRenderTargetRet1` calls `CDx::PushRenderTarget`
- `CDx::DrawFadeQuad` calls `CDx_SetDefaultRenderState`, `CDx::GetRenderTargetTop`, `CDx::DrawPrimitiveUP`
- `CDx::Post_DepthBlurComposite` calls `CDx_SetDefaultRenderState`, `CDx::DrawScreenQuadAtDepth`
- `CDx::StepFadeCounter` calls nothing directly
- `CDx::NopA` calls nothing directly
- `CDx::NopB` calls nothing directly
- `CDx::DrawStereoOddFrameOverlay` calls `CEnv::IsStereoMode`, `CDx::DrawPrimitiveUP`
- `CDx::SetTransform` calls nothing directly
- `CDx::GetTransformCached` calls nothing directly
- `CDx_SetVertexShaderCached` calls nothing directly
- `Light_ApplyTimeOfDayTint` calls `GammaRamp_GetChannelSamples`
- `CDx::SetLight` calls `Light_ApplyTimeOfDayTint`
- `CDx::CompositeSceneToBackBuffer` calls `CEnv::IsStereoMode`, `CDx::PushRenderTarget`, `CDx::DrawPrimitiveUP`, `CDx::SetTexture`, `CDx::DrawTexturedScreenQuad`
- `CDx::CreateStereoResources` calls `CDx::CreateRampTextures1024x2`, `CDx::CreateRampTexture1x16`, `CDx::CreateTexture`, `CEnv::Nop`, `CDx::ReleaseStereoResources`
- `CDx::ReleaseStereoResources` calls nothing directly
- `CDx::CreateRampTexture1x16` calls `sub_102D2FB9`
- `CDx::CreateRampTextures1024x2` calls `sub_102D2FB9`
- `CDx::DrawPrimitive` calls `CDx_GetStereoSecondEyeTarget`, `CDx::ApplyStereoEyeProjection`, `CDx::RestoreProjection`, `CDx::PushRenderTarget`, `CDx::PopRenderTargetDefault`
- `CDx::DrawIndexedPrimitive` calls `CDx_GetStereoSecondEyeTarget`, `CDx::ApplyStereoEyeProjection`, `CDx::RestoreProjection`, `CDx::PushRenderTarget`, `CDx::PopRenderTargetDefault`
- `CDx::DrawPrimitiveUP` calls `CDx_GetStereoSecondEyeTarget`, `CDx::ApplyStereoEyeProjection`, `CDx::RestoreProjection`, `CDx::PushRenderTarget`, `CDx::PopRenderTargetDefault`
- `CDx::ApplyStereoEyeProjection` calls `MathVector_ReturnThis`, `Mat4_SetIdentity`, `Mat4_PreMultiply`, `MathVector_Nop`
- `CDx::RestoreProjection` calls nothing directly
