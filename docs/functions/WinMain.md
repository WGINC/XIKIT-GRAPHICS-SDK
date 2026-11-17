# WinMain

Group: `Win` (by the file name only). Source: `sdk/tree_src/WinMain.cpp`.

Why the file has this name (data/unit_names.json): App_WinMain*, App_WndProc, the window class FFXiClass / "FINAL FANTASY XI", CreateWindowExA, CoInitialize, the IME UI DLL, the camera projection (Camera_Build*)

66 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `WinMain_RunStepThenLoadAll` | 0x10014350 | 55 | yes | 6 | Runs the sub-state step 0x10014390 and, when it succeeds, loads the dat entries and settings and releases the object at 0x1045690C. | low |
| `WinMain_EnterState4AfterShutdown` | 0x100149B0 | 100 | yes | - | One Frame_Render step: polls the game mode and, once fn_10014C90 (Acter_ShutdownGlobals plus table reset) succeeds, sets the state at +0x44 to 4. | low |
| `WinMain_TryShutdownActors` | 0x10014A20 | 11 | yes | - | Returns whether fn_10014C90 (Acter_ShutdownGlobals then the table reset) succeeded. | medium |
| `WinMain_StepStagedRelease` | 0x10014A30 | 132 | yes | - | Frame_Render step that runs a four-stage release sequence (actors, then two Unit100D7420 steps with a 900-count timeout) and moves to state 0xE. | low |
| `WinMain_StepMenuOkThenRelease` | 0x10014AD0 | 320 | yes | - | Frame_Render step that shows the 'ok' menu, waits for it to close, then releases the my-room object. | low |
| `Camera_ReleaseAll` | 0x10014C10 | 69 | yes | 2 | Runs the release helpers in turn and returns 1 only when the shutdown and the 32-slot release both succeed. | medium |
| `WinMain_ApplyTables103501F8` | 0x10014C60 | 40 | yes | - | Applies the three table entries at 0x103501F8 when DAT_104570B0 is set. | medium |
| `WinMain_ShutdownActorsAndTables` | 0x10014C90 | 25 | yes | - | Calls Acter_ShutdownGlobals and, when it succeeds, applies the tables at 0x10350210; returns whether it succeeded. | medium |
| `WinMain_ApplyTables10350210` | 0x10014CB0 | 40 | yes | - | Applies the three table entries at 0x10350210 when DAT_104570B0 is set. | medium |
| `Camera_ClearByte0A` | 0x10014CE0 | 10 | yes | - | Clears the byte at offset 0x0A of the camera. | low |
| `Camera_GetFrameScale` | 0x10014CF0 | 33 | yes | - | - | - |
| `Camera_GetClampedField28` | 0x10014D20 | 33 | yes | - | Returns the camera's field at offset 0x28, clamped to at least 1.0. | low |
| `Camera_GetField38` | 0x10014D60 | 9 | yes | - | Returns the value stored at offset 0x38 of the camera. | low |
| `Camera_GetFloat2DC` | 0x10014D70 | 12 | yes | - | - | - |
| `Camera_GetFloat2E0` | 0x10014D80 | 12 | yes | - | - | - |
| `Camera_SetClearColorRGB` | 0x10014D90 | 27 | yes | - | - | - |
| `Camera_SetClearColorPacked` | 0x10014DB0 | 53 | yes | - | Stores the clear colour as one packed value. | medium |
| `Camera_SetField304BytesOnGlobal` | 0x10014E00 | 27 | yes | - | Camera_SetField304Bytes on the global camera. | high |
| `Camera_SetField304Bytes` | 0x10014E20 | 34 | yes | - | Stores three byte values packed into the field at offset 0x304. | low |
| `Camera_SetField2FC` | 0x10014E60 | 16 | yes | - | Stores a float at offset 0x2FC of the camera. | low |
| `Camera_SetField300` | 0x10014E80 | 16 | yes | - | Stores a float at offset 0x300 of the camera. | low |
| `Camera_SetField314` | 0x10014EB0 | 16 | yes | - | Stores a float at offset 0x314 of the camera. | low |
| `Camera_SetField318` | 0x10014ED0 | 16 | yes | - | Stores a float at offset 0x318 of the camera. | low |
| `Camera_Call100151A0OnGlobal` | 0x10015100 | 17 | yes | - | sub_100151A0 on the global camera. | high |
| `Camera_SetViewMatrices` | 0x10015120 | 117 | yes | - | Sets the camera's view matrices from a 4x4 matrix and derives its inverse. | medium |
| `Camera_SetProjectionMatrix` | 0x100151D0 | 28 | yes | - | Sets the camera's projection matrix from a 4x4 matrix. | medium |
| `Camera_GetViewMatrixPtr` | 0x10015220 | 11 | yes | - | - | - |
| `Camera_GetField50` | 0x10015250 | 9 | yes | - | - | - |
| `Camera_GetMatrix154Ptr` | 0x10015270 | 11 | yes | - | - | - |
| `Camera_SetField2F8OnGlobal` | 0x10015290 | 17 | yes | - | Camera_SetField2F8 on the global camera. | high |
| `Camera_SetField2F8` | 0x100152B0 | 13 | yes | - | Stores a dword at offset 0x2F8 of the camera. | low |
| `Camera_GetField2F4` | 0x100152C0 | 12 | yes | - | Returns the float stored at offset 0x2F4 of the camera. | low |
| `Camera_SetField2E4` | 0x10015360 | 59 | yes | - | Stores a scale at offset 0x2E4 of the camera, chosen by a flag. | low |
| `Camera_SetField2F0` | 0x100153A0 | 36 | yes | - | Stores a value derived from two arguments at offset 0x2F0 of the camera. | low |
| `Camera_BuildProjection` | 0x10015480 | 11 | yes | - | - | - |
| `Camera_BuildPerspectiveFov` | 0x10015490 | 89 | yes | - | Builds the camera's perspective projection with D3DX from its field of view, aspect and clip planes. | medium |
| `Camera_GetByte0B` | 0x100155D0 | 9 | yes | - | Returns the byte stored at offset 0x0B of the camera. | low |
| `Camera_GetWord10` | 0x10015600 | 10 | yes | - | Returns the word stored at offset 0x10 of the camera. | low |
| `Camera_GetWord12` | 0x10015610 | 10 | yes | - | Returns the word stored at offset 0x12 of the camera. | low |
| `Camera_GetWord14` | 0x10015640 | 10 | yes | - | Returns the word stored at offset 0x14 of the camera. | low |
| `Camera_GetWord16` | 0x10015650 | 10 | yes | - | Returns the word stored at offset 0x16 of the camera. | low |
| `Camera_GetViewportWidth` | 0x10015680 | 10 | yes | - | - | - |
| `Camera_GetViewportHeight` | 0x10015690 | 10 | yes | - | - | - |
| `Camera_PickNearestAspect` | 0x100156A0 | 160 | yes | - | Picks the table entry whose aspect ratio is closest to the given width and height. | medium |
| `WinMain_ReturnTrue` | 0x10015740 | 3 | yes | - | Returns true (AL=1). | high |
| `App_WinMainClearFileMng` | 0x100157B0 | 31 | yes | 3 | Clears the sub_10662DCC global and then calls App_WinMain. | low |
| `App_RunWithCOM` | 0x10015AB0 | 205 | yes | 1 | - | - |
| `App_CreateRendererAndApp` | 0x100161B0 | 336 | yes | 0 | - | - |
| `App_RunMainLoopThenSetPtr` | 0x10016300 | 31 | yes | 2 | Runs CApp::RunMainLoop once and then stores LAB_10016580 into DAT_104569cc if DAT_104569c8 is nonzero. | low |
| `App_DestroyGlobalObjects` | 0x10016320 | 116 | yes | 0 | - | - |
| `App_SetGlobal_104569C5` | 0x100163C0 | 10 | yes | - | Stores its argument's low byte into DAT_104569c5. | low |
| `App_SetGlobal_104569C6` | 0x100163E0 | 10 | yes | - | Stores its argument's low byte into DAT_104569c6. | low |
| `App_SetGlobal_104569C8` | 0x10016400 | 10 | yes | - | - | - |
| `App_GetGlobal_104569C8` | 0x10016410 | 6 | yes | - | Returns the value of DAT_104569c8. | medium |
| `WinMain_GetSceneStateByte68` | 0x100164B0 | 6 | yes | - | Returns the byte sub_104569EC. | high |
| `App_SetErrorCode` | 0x100164C0 | 10 | yes | - | - | - |
| `App_GetGlobalPair` | 0x10016560 | 24 | yes | - | Writes the globals DAT_10456a60 and DAT_10456c04 through its two pointer arguments. | low |
| `App_WndProc` | 0x10016870 | 1298 | yes | 2 | The window procedure the game registers with RegisterClassA for its window. | high |
| `GammaRamp_SetRGB` | 0x100170A0 | 33 | yes | - | - | - |
| `GammaRamp_GetRGB` | 0x100170D0 | 39 | yes | - | - | - |
| `GammaRamp_GetChannelSamples` | 0x10017100 | 92 | yes | - | - | - |
| `GammaRamp_BuildRamps` | 0x10017160 | 65 | yes | - | - | - |
| `GammaRamp_ApplyIfChanged` | 0x10017230 | 152 | yes | 0 | - | - |
| `WinMain_Draw` | 0x10017310 | 525 | yes | 0 | Draws a 256-entry ramp as a line graph with Direct3D. | medium |
| `setPolUrl` | 0x10017630 | 38 | yes | - | - | - |
| `App_SetGlobalAndClearCamera` | 0x10017670 | 20 | yes | - | Calls FUN_10010520, sets DAT_104569c8 to 1 and returns the result of Camera_ClearByte0A. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `WinMain_RunStepThenLoadAll` calls `sub_10014390`, `TextInputFiles_LoadAllAndTimestamp`
- `WinMain_EnterState4AfterShutdown` calls `LobbyThread_SendCmd6`, `GameMode_PollPendingState`, `WinMain_ShutdownActorsAndTables`
- `WinMain_TryShutdownActors` calls `WinMain_ShutdownActorsAndTables`
- `WinMain_StepStagedRelease` calls `WinMain_ShutdownActorsAndTables`, `NetCellFont_DestroyGlobal`, `NetCellFont_UpdateActive`
- `WinMain_StepMenuOkThenRelease` calls `GameMode_PollPendingState`, `TextInputFiles_LoadAllAndTimestamp`, `YkMyroom::Destructor`, `thunk_sub_10028AA0`, `Menu_CloseEntry`, `AppStartup_IncrementShort6`, `TargetMenu_SetPosition`, `TextInputFiles_AssignWhole`, `LobbyUi_ForwardFlag1`, `MenuMng_OpenByName`
- `Camera_ReleaseAll` calls `TextInputFiles_RunPairB`, `StAvatar_SetActive`, `ModelDtInit_ReleaseAll`, `Acter_ShutdownGlobals`, `WinMain_ApplyTables103501F8`, `TargetMenu_ReleaseAll32`
- `WinMain_ApplyTables103501F8` calls `MemHeapDebug_ApplyFourTables`
- `WinMain_ShutdownActorsAndTables` calls `Acter_ShutdownGlobals`, `WinMain_ApplyTables10350210`
- `WinMain_ApplyTables10350210` calls `MemHeapDebug_ApplyFourTables`
- `Camera_ClearByte0A` calls nothing directly
- `Camera_GetFrameScale` calls nothing directly
- `Camera_GetClampedField28` calls nothing directly
- `Camera_GetField38` calls nothing directly
- `Camera_GetFloat2DC` calls nothing directly
- `Camera_GetFloat2E0` calls nothing directly
- `Camera_SetClearColorRGB` calls `Camera_SetClearColorPacked`
- `Camera_SetClearColorPacked` calls nothing directly
- `Camera_SetField304BytesOnGlobal` calls `Camera_SetField304Bytes`
- `Camera_SetField304Bytes` calls nothing directly
- `Camera_SetField2FC` calls nothing directly
- `Camera_SetField300` calls nothing directly
- `Camera_SetField314` calls nothing directly
- `Camera_SetField318` calls nothing directly
- `Camera_Call100151A0OnGlobal` calls `sub_100151A0`
- `Camera_SetViewMatrices` calls `Mat4_Copy`, `Mat4_SetIdentity`, `Mat4_InvertOrthonormal`, `MathVector_Nop`
- `Camera_SetProjectionMatrix` calls `Mat4_Copy`, `MathVector_Nop`
- `Camera_GetViewMatrixPtr` calls nothing directly
- `Camera_GetField50` calls nothing directly
- `Camera_GetMatrix154Ptr` calls nothing directly
- `Camera_SetField2F8OnGlobal` calls `Camera_SetField2F8`
- `Camera_SetField2F8` calls nothing directly
- `Camera_GetField2F4` calls nothing directly
- `Camera_SetField2E4` calls `Camera_BuildPerspectiveFov`, `Mat4_Copy`
- `Camera_SetField2F0` calls nothing directly
- `Camera_BuildProjection` calls `Camera_BuildPerspectiveFov`
- `Camera_BuildPerspectiveFov` calls `D3DXMatrixPerspectiveFovLH_static`, `Mat4_Copy`
- `Camera_GetByte0B` calls nothing directly
- `Camera_GetWord10` calls nothing directly
- `Camera_GetWord12` calls nothing directly
- `Camera_GetWord14` calls nothing directly
- `Camera_GetWord16` calls nothing directly
- `Camera_GetViewportWidth` calls nothing directly
- `Camera_GetViewportHeight` calls nothing directly
- `Camera_PickNearestAspect` calls nothing directly
- `WinMain_ReturnTrue` calls nothing directly
- `App_WinMainClearFileMng` calls `sub_100157E0`
- `App_RunWithCOM` calls `sub_10311C7A`, `Allocator_Generic`, `sub_10029220`, `sub_10029290`, `App_CreateRendererAndApp`, `App_RunMainLoopThenSetPtr`, `App_DestroyGlobalObjects`
- `App_CreateRendererAndApp` calls `MenuMng_Init`, `sub_101201C0`, `Mem_AllocDefault`, `CDx_Constructor`, `CDx::SetDefaultRenderTargets`, `sub_10001240`, `sub_10019140`, `TimerResolution_CreateObject`
- `App_RunMainLoopThenSetPtr` calls `CApp::RunMainLoop`, `App_GetGlobal_104569C8`
- `App_DestroyGlobalObjects` calls `sub_100191B0`, `sub_10120200`, `sub_1015D9E0`
- `App_SetGlobal_104569C5` calls nothing directly
- `App_SetGlobal_104569C6` calls nothing directly
- `App_SetGlobal_104569C8` calls nothing directly
- `App_GetGlobal_104569C8` calls nothing directly
- `WinMain_GetSceneStateByte68` calls nothing directly
- `App_SetErrorCode` calls nothing directly
- `App_GetGlobalPair` calls nothing directly
- `App_WndProc` calls `sub_10311C2C`, `sub_10002840`, `App_RenderFrameMaskedFPU`
- `GammaRamp_SetRGB` calls nothing directly
- `GammaRamp_GetRGB` calls nothing directly
- `GammaRamp_GetChannelSamples` calls nothing directly
- `GammaRamp_BuildRamps` calls `sub_100171B0`
- `GammaRamp_ApplyIfChanged` calls `GammaRamp_BuildRamps`
- `WinMain_Draw` calls `CDx::DrawPrimitiveUP`
- `setPolUrl` calls `sub_1031111E`
- `App_SetGlobalAndClearCamera` calls `App_SaveAllSlotData`, `App_SetGlobal_104569C8`, `Camera_ClearByte0A`
