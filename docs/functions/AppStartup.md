# AppStartup

Group: `App` (by the file name only). Source: `sdk/tree_src/AppStartup.cpp`.

Why the file has this name (data/unit_names.json): App_Constructor, the game-state step (App_SetSeqStep), loads the resource tables is.dat, bs.dat, cl.dat, ti.dat...; called from the main loop and Frame_Render

7 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `sub_10010370` | 0x10010370 | 429 | no | - | - | - |
| `sub_10010520` | 0x10010520 | 403 | no | - | Saves every slot object's data to its .dat file and frees them. | medium |
| `App_Constructor` | 0x10010700 | 399 | yes | - | - | - |
| `App_SetSeqStep` | 0x10010CE0 | 18 | yes | - | - | - |
| `App_AdvanceSeqStep` | 0x10010D00 | 11 | yes | - | - | - |
| `AppStartup_IncrementShort6` | 0x10010D10 | 5 | yes | - | Increments the counter at +6. | low |
| `App_InitScene` | 0x10010D20 | 3061 | no | 1 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `sub_10010370` calls `FaqHelp_Construct`
- `sub_10010520` calls `Game_ClearFlagsBits`, `FaqHelp_SaveAndRelease`, `Acter_Nop`, `Settings_GetValue`
- `App_Constructor` calls `MathVector_ReturnThis`, `Mat4_SetIdentity`
- `App_SetSeqStep` calls nothing directly
- `App_AdvanceSeqStep` calls nothing directly
- `AppStartup_IncrementShort6` calls nothing directly
- `App_InitScene` calls `CDx::BeginScene`, `CDx::NopA`, `TimerResolution_CreateObject`, `TargetMenu_Clear32`, `TargetMenu_LoadAllMessageTables`, `CreateSharedVertexBuffers`, `CreateProcessorInstance`, `Mem_AllocDefault`, `CMoTask::Constructor`, `CMoTaskMng::InitPool`, `sub_100729C0`, `sub_10072DB0`, `CDx::EndScene`, `Mem_AllocFromArea`, `CMoTask::ResetFields`, `sub_100749B0`, `CYyTexMng_Init`, `sub_1003B080`, `Scene_GetTableValue`, `sub_100731B0`, `TargetMenu_Nop`, `sub_10071E90`, `Menu_ReloadResource`, `sub_10072FD0`, `Allocator_Generic`, `unknown_libname_88`, `Font_LoadWidthTable`, `NetCellFont_MsgWinDataCtor`, `NetCellFont_CtorResetAll`, `CTsZoneMap::Init`, `ZoneMapLoad_InitGlobalTables`, `TextInputFiles_CreateDatManager`, `TextInputFiles_CreateAll`, `sub_101B8E70`, `TextInputFiles_CreateEmptyObject`, `TextInputFiles_CreateMenuSystem`, `NetCellFont_InitColors`, `ZoneMapLoad_CreateUiObjects`, `TextInputFiles_CreateConfigObjects`, `YkInit`, `sub_1021BB90`, `Gfx_InitObject`, `sub_102217A0`, `FontGlyphCache_GetCounterBlock`, `FontGlyphCache_ResetCounter`, `XiCapture_Init`, `ErrorReport_CtorVt10329F8C`, `ErrorReport_LoadChecksum`, `StAvatarInfo_Ctor`, `CMoDX::CreateAndInitSystem`, `App_SetSeqStep`, `GammaRamp_ApplyIfChanged`, `App_GetGlobalPair`, `Camera_SetField2E4`, `Camera_PickNearestAspect`, `Camera_SetField2F0`, `Gfx_SetAspectIndex`, `CDx::SetClearParams`, `CDx::AppendStateRecord`, `CDx::CreateTexture`, `sub_1000AD70`, `CDx::PushRenderTarget`, `CDx::EndAndClearBegin`, `CDx::SetTexture`, `CDx::CreateStereoResources`, `CEnv::Nop`, `App_AdvanceSeqStep`
