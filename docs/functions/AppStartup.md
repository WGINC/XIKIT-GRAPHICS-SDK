# AppStartup

Group: `App` (by the file name only). Source: `sdk/tree_src/AppStartup.cpp`.

Why the file has this name (data/unit_names.json): App_Constructor, the game-state step (App_SetSeqStep), loads the resource tables is.dat, bs.dat, cl.dat, ti.dat...; called from the main loop and Frame_Render

7 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `App_RegisterSystemDats` | 0x10010370 | 429 | no | - | - | - |
| `App_SaveAllSlotData` | 0x10010520 | 403 | no | - | Saves every slot object's data to its .dat file and frees them. | medium |
| `App_Constructor` | 0x10010700 | 399 | yes | - | - | - |
| `App_SetSeqStep` | 0x10010CE0 | 18 | yes | - | - | - |
| `App_AdvanceSeqStep` | 0x10010D00 | 11 | yes | - | - | - |
| `AppStartup_IncrementShort6` | 0x10010D10 | 5 | yes | - | Increments the counter at +6. | low |
| `App_InitScene` | 0x10010D20 | 3061 | no | 1 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `App_RegisterSystemDats` calls `FaqHelp_Construct`
- `App_SaveAllSlotData` calls `Game_ClearFlagsBits`, `FaqHelp_SaveAndRelease`, `Acter_Nop`, `Settings_GetValue`
- `App_Constructor` calls `MathVector_ReturnThis`, `Mat4_SetIdentity`
- `App_SetSeqStep` calls nothing directly
- `App_AdvanceSeqStep` calls nothing directly
- `AppStartup_IncrementShort6` calls nothing directly
- `App_InitScene` calls `CDx::BeginScene`, `CDx::NopA`, `TimerResolution_CreateObject`, `TargetMenu_Clear32`, `TargetMenu_LoadAllMessageTables`, `CreateSharedVertexBuffers`, `CreateProcessorInstance`, `Mem_AllocDefault`, `CMoTask::Constructor`, `CMoTaskMng::InitPool`, `Resource_ResetGlobals`, `game_10072DB0`, `CDx::EndScene`, `Mem_AllocFromArea`, `CMoTask::ResetFields`, `game_100749B0`, `CYyTexMng_Init`, `game_1003B080`, `Scene_GetTableValue`, `game_100731B0`, `TargetMenu_Nop`, `game_10071E90`, `Menu_ReloadResource`, `game_10072FD0`, `Allocator_Generic`, `unknown_libname_88`, `Font_LoadWidthTable`, `NetCellFont_MsgWinDataCtor`, `NetCellFont_CtorResetAll`, `CTsZoneMap::Init`, `ZoneMapLoad_InitGlobalTables`, `TextInputFiles_CreateDatManager`, `TextInputFiles_CreateAll`, `game_101B8E70`, `TextInputFiles_CreateEmptyObject`, `TextInputFiles_CreateMenuSystem`, `NetCellFont_InitColors`, `ZoneMapLoad_CreateUiObjects`, `TextInputFiles_CreateConfigObjects`, `YkInit`, `FaqHelp_Create`, `Gfx_InitObject`, `MenuPanels_InitMenuShapes`, `FontGlyphCache_GetCounterBlock`, `FontGlyphCache_ResetCounter`, `XiCapture_Init`, `ErrorReport_CtorVt10329F8C`, `ErrorReport_LoadChecksum`, `StAvatarInfo_Ctor`, `CMoDX::CreateAndInitSystem`, `App_SetSeqStep`, `GammaRamp_ApplyIfChanged`, `App_GetGlobalPair`, `Camera_SetField2E4`, `Camera_PickNearestAspect`, `Camera_SetField2F0`, `Gfx_SetAspectIndex`, `CDx::SetClearParams`, `CDx::AppendStateRecord`, `CDx::CreateTexture`, `game_1000AD70`, `CDx::PushRenderTarget`, `CDx::EndAndClearBegin`, `CDx::SetTexture`, `CDx::CreateStereoResources`, `CEnv::Nop`, `App_AdvanceSeqStep`
