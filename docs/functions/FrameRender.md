# FrameRender

Group: `Frame` (by the file name only). Source: `sdk/tree_src/FrameRender.cpp`.

Why the file has this name (data/unit_names.json): Frame_Render and the per-state frame functions (App_StepGameState6-9, App_RunOpening), the afterimage and flash post effects; called from App_RenderFrameMaskedFPU

14 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Frame_Render` | 0x10011A00 | 5355 | yes | 0 | - | - |
| `Post_Afterimage` | 0x10012F40 | 868 | yes | 1 | - | - |
| `Post_FlashAndZoomFeedback` | 0x100132B0 | 1814 | yes | 0 | - | - |
| `App_RunOpening` | 0x100139E0 | 215 | yes | - | Runs the opening movie step and frees the opening object when it finishes. | medium |
| `FrameRender_ReturnTrue` | 0x10013AC0 | 3 | yes | - | Returns true. | low |
| `App_StepGameState6` | 0x10013DF0 | 259 | yes | - | - | - |
| `App_StepGameState7` | 0x10013F10 | 254 | yes | - | - | - |
| `App_StepGameState8` | 0x10014030 | 206 | yes | - | - | - |
| `App_StepGameState9` | 0x10014120 | 73 | yes | - | - | - |
| `App_DispatchSubState` | 0x10014170 | 60 | yes | 7 | Runs the handler for the current application sub-state. | medium |
| `Game_InGameSubState0` | 0x100141C0 | 55 | yes | - | - | - |
| `App_SubStateInitCamera` | 0x10014200 | 32 | yes | - | Sub-state step that initialises the camera and moves to the next step. | medium |
| `App_InitCamera` | 0x10014220 | 123 | yes | - | Selects the camera id and creates the camera manager. | medium |
| `App_SubStateAdvance` | 0x100142A0 | 8 | yes | - | Sub-state step that only moves to the next step. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Frame_Render` calls `sub_10311C2C`, `j_CEnv_UpdateDualTargetMode`, `CDx::TestCooperativeLevel`, `App_SetErrorCode`, `CDx::BeginScene`, `CDx_SetDefaultRenderState`, `CDx::NopA`, `TexMgr_UploadPumpEntry`, `Input_IsCursorActive`, `TextInputFiles_Call103113C8`, `CEnv::IsStereoMode`, `CDx::PushRenderTarget`, `CDx::EndAndClearBegin`, `CDx::SetTexture`, `CDx::PushRenderTargetRet1`, `GameMode_PollPendingState`, `_exit_0`, `XiZone::GetInstance`, `sub_1018C2B0`, `StDancer_Update`, `XiZone::DrawScene`, `CMoTaskMng::DrawAll`, `Dancer_WorldEnd`, `CYySoundElem::UpdateQueue`, `App_SetSeqStep`, `CDx::StepFadeCounter`, `CDx::SetClearColor`, `WinMain_StepMenuOkThenRelease`, `Scene_GetTableValue`, `sub_100731B0`, `sub_10071E90`, `NetCellFont_InitTimer`, `App_GetGlobal_104569C8`, `LobbyThread_SetGlobal106690AC`, `App_SetGlobal_104569C8`, `TextInputFiles_RunPairA`, `App_RunOpening`, `sub_103134C7`, `AppMainLoop_AppendWithSpace`, `Game_InitSceneState`, `WinMain_ReturnTrue`, `FrameRender_ReturnTrue`, `ErrorReport_LoadChecksum`, `sub_10013AD0`, `StAvatarInfo_SendBytePairKind2`, `NetCellFont_GetRecordDwordFwd`, `TextInputFiles_FileMngFwd101C2B60`, `TextInputFiles_FileMngFwd101C2C80`, `TextInputFiles_FileMngFwd101C2E70`, `TextInputFiles_FileMngFwd101C4170`, `App_StepGameState6`, `App_StepGameState7`, `App_StepGameState8`, `App_StepGameState9`, `App_DispatchSubState`, `App_SetGlobal_104569C5`, `App_SaveAllSlotData`, `WinMain_EnterState4AfterShutdown`, `WinMain_TryShutdownActors`, `SoundElem_ResetGlobals`, `Ui_KeyPrompt_Init`, `MenuMng_OpenByName`, `WinMain_StepStagedRelease`, `DebugOverlay_Draw`, `ZoneMap_GetByteRef1CPlus10`, `CDx::DrawTextureToViewport`, `ZoneMap_GetFloatRef1CPlus4`, `Mat4_TransformPointInPlace`, `CDx::SetTransform`, `Gfx_ProjectWorldToClip`, `CDx::Post_DepthBlurComposite`, `Post_Afterimage`, `Post_FlashAndZoomFeedback`, `CopyrightText_Draw`, `CDx::SetViewport`, `CDx::CompositeSceneToBackBuffer`, `CDx::NopB`, `App_SetGlobal_104569C6`, `TextInputFiles_WatchConfigWindow`, `sub_10005A40`, `Cell_ClearFlag104E1C3C`, `Input_DispatchButtons`, `Target_Update`, `TextInputFiles_HandleMenuKeys`, `TextInputFiles_UpdateShortcuts`, `TextInputFiles_UpdateMenuState`, `sub_101C46A0`, `TextInputFiles_HandleJumpMapKeys`, `TargetMenu_GetInstance`, `TargetMenu_UpdatePendingRead`, `Gfx_SetDefault2DStates`, `Menu_DrawAll`, `Menu_DrawLayers`, `Gfx_DisableFogAndAlphaBlend`, `FontGlyphCache_GetCounterBlock`, `FontGlyphCache_StepCounter`, `FitFont_ReturnFalseFwd`, `MyRoom_Update`, `sub_10018850`, `Cursor_UpdateTimer`, `CDx_CompositeUITarget`, `CDx::DrawFadeQuad`, `CXiMovie::DrawFrame`, `sub_101D0C70`, `Font_QueueText`, `Font_DrawPass`, `CDx::DrawStereoOddFrameOverlay`, `CDx::EndScene`, `CDx::Present`, `Game_SetSlot44C`, `Camera_ApplyViewProjection`, `GammaRamp_ApplyIfChanged`
- `Post_Afterimage` calls `CEnv::IsStereoMode`, `CDx_SetDefaultRenderState`, `CDx::PushRenderTarget`, `CDx::DrawTextureToViewport`, `CDx::SetTexture`, `sub_10311C2C`
- `Post_FlashAndZoomFeedback` calls `CDx::GetRenderTargetTop`, `CDx::DrawPrimitiveUP`, `CEnv::IsStereoMode`, `CDx::PushRenderTarget`, `CDx::SetTexture`, `CDx::DrawTextureToViewport`, `CDx::DrawTexturedScreenQuad`
- `App_RunOpening` calls `OpeningSubtitle_IsStateFour`, `sub_10313520`, `sub_10312050`, `Mem_AllocDefault`, `CXiOpening::Constructor`, `App_AdvanceSeqStep`
- `FrameRender_ReturnTrue` calls nothing directly
- `App_StepGameState6` calls `App_RegisterSystemDats`, `Ui_KeyPrompt_Init`, `MenuMng_OpenByName`, `CDx::SetClearParams`, `Acter_ResetGlobals`, `GameMode_RequestState`, `App_AdvanceSeqStep`, `GameMode_PollPendingState`
- `App_StepGameState7` calls `Ui_KeyPrompt_Init`, `MenuMng_OpenByName`, `CDx::SetClearParams`, `Acter_ResetGlobals`, `GameMode_RequestState`, `App_AdvanceSeqStep`, `GameMode_PollPendingState`
- `App_StepGameState8` calls `App_RegisterSystemDats`, `Ui_KeyPrompt_Init`, `MenuMng_OpenByName`, `CDx::SetClearParams`, `Acter_ResetGlobals`, `GameMode_RequestState`, `App_AdvanceSeqStep`, `GameMode_PollPendingState`
- `App_StepGameState9` calls `App_RegisterSystemDats`, `Ui_KeyPrompt_Init`, `MenuMng_OpenByName`, `CDx::SetClearParams`, `Acter_ResetGlobals`
- `App_DispatchSubState` calls `Game_InGameSubState0`, `App_SubStateInitCamera`, `App_SubStateAdvance`, `CAtelIdleTask::Create`, `WinMain_RunStepThenLoadAll`
- `Game_InGameSubState0` calls `CDx::StepFadeCounter`, `App_AdvanceSeqStep`
- `App_SubStateInitCamera` calls `App_InitCamera`, `App_AdvanceSeqStep`
- `App_InitCamera` calls `NetCellFont_GetFlags`, `CYyCamMng2::CreateGlobal`, `NetCellFont_GetWord40D7C`
- `App_SubStateAdvance` calls `App_AdvanceSeqStep`
