// gfx_free.hpp -- graphics functions with no established class.
#pragma once
#include "gfx_common.hpp"
XI_API undefined4 __stdcall VectorCtorIterator_CallForEachElement(undefined4 param_1, undefined4 param_2, int param_3, undefined * param_4);  // 0x10001070
XI_API void __cdecl App_ForceForegroundWindow(HWND param_1);  // 0x100014A0
XI_API undefined4 __cdecl App_RenderFrameMaskedFPU(void);  // 0x10001B50
XI_API undefined4 __stdcall App_CreateInputSystem(undefined4 param_1);  // 0x10001BB0
XI_API void __cdecl AppMainLoop_ForwardMouseMove(undefined4 param_1);  // 0x10001D90
XI_API undefined4 __cdecl AppMainLoop_AppendWithSpace(char * param_1);  // 0x10001E70
XI_API undefined4 __cdecl AppMainLoop_FindTokenCopyDefault(char * param_1, char * param_2);  // 0x10001F20
XI_API char * __cdecl AppMainLoop_FindTokenCopy(char * param_1, char * param_2, int param_3);  // 0x10001F40
XI_API char __cdecl Gfx_CopySurfaceRectToTexture(struct IDirect3DSurface8 *a1, const struct tagRECT *a2, unsigned int *a3, int a4);  // 0x10002040
XI_API char __cdecl Gfx_ProbeDeviceCaps(int a1, unsigned int *a2, int *a3);  // 0x10002130
XI_API uint32_t __cdecl AppMainLoop_SwapRedBlue(uint32_t param_1);  // 0x10002440
XI_API undefined4 __cdecl Gfx_IsGammaSupported(void);  // 0x10002BE0
XI_API CDx * __cdecl Gfx_SetGammaRGB(int a1, int a2, int a3);  // 0x10002C00
XI_API CDx * __cdecl Gfx_SetGammaR(int a1);  // 0x10002C30
XI_API CDx * __cdecl Gfx_SetGammaG(int a1);  // 0x10002C80
XI_API CDx * __cdecl Gfx_SetGammaB(int a1);  // 0x10002CD0
XI_API int __cdecl Gfx_GetGammaRGB(int a1, int a2, int a3);  // 0x10002D20
XI_API void __cdecl AppMainLoop_SetShadowSetting(undefined4 param_1);  // 0x10002D50
XI_API void __cdecl AppMainLoop_SetFloat10456A68(undefined4 param_1);  // 0x10002D70
XI_API long double __attribute__((cdecl, regparm(1))) AppMainLoop_GetFloat10456A68Or1(undefined4 xi_eax);  // 0x10002D80
XI_API void __cdecl AppMainLoop_SetGlobal10456A5C(undefined4 param_1);  // 0x10002DA0
XI_API void __cdecl AppMainLoop_SetGlobal10456A6C(undefined4 param_1);  // 0x10002DC0
XI_API void __cdecl AppMainLoop_SetFloat10456AB8(undefined4 param_1);  // 0x10002DE0
XI_API void __cdecl AppMainLoop_SetFloat10456AA8(undefined4 param_1);  // 0x10002E00
XI_API void __cdecl AppMainLoop_SetGlobal10456A70(undefined4 param_1);  // 0x10002E20
XI_API void __cdecl AppMainLoop_SetCfg0020(undefined4 param_1);  // 0x10002E40
XI_API void __cdecl Gfx_SetAspectIndex(undefined4 param_1);  // 0x10002E60
XI_API void __cdecl Gfx_ApplyAspectScale(undefined4 param_1);  // 0x10002E80
XI_API long double __cdecl Gfx_GetAspectTableA(int param_1);  // 0x10002EC0
XI_API long double __cdecl Gfx_GetAspectTableB(int param_1);  // 0x10002EE0
XI_API char __cdecl Gfx_CreateD3DHolder(int a1, int a2, int a3, char a4, char a5);  // 0x10002F20
XI_API int __cdecl Gfx_DestroyD3DHolder(void);  // 0x10003040
XI_API char __thiscall Gfx_D3DBootstrap(int self_, int a2, int a3, int a4, char a5, char a6, int a7);  // 0x100031F0
XI_API char __thiscall Gfx_TryCreateDeviceForMode(_DWORD **self_, int a2, int a3, int a4, char a5, char a6, int a7, int a8);  // 0x100033C0
XI_API char __thiscall Gfx_CreateDevice(_DWORD *self_, int a2, int a3, int a4, int a5, int a6, char a7, char a8, int a9);  // 0x100034B0
XI_API void * __thiscall Gfx_InitObject(void * self_);  // 0x100035F0
XI_API void __thiscall Gfx_ResetObject(void * self_);  // 0x10003640
XI_API void __thiscall DebugOverlay_Draw(void * self_);  // 0x10003650
XI_API void __thiscall Debug_Construct(void * self_);  // 0x10003660
XI_API void __thiscall DebugOverlay_Update(void * self_);  // 0x10003710
XI_API undefined4 __attribute__((stdcall, regparm(3))) DebugOverlay_SetEntry(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, uint32_t * param_2, float param_3, float param_4, float param_5, float param_6, char * param_7, undefined4 param_8);  // 0x100037D0
XI_API void __thiscall InputDevices_DrawActorAxes(_DWORD *self_);  // 0x10003890
XI_API int __thiscall Debug_DrawTextTable(_DWORD *self_);  // 0x10003B60
XI_API void __stdcall Debug_DrawWorldText(_DWORD *a1, const char *a2, int arg8);  // 0x10003D70
XI_API void __thiscall Input_SetFlagToggle(void * self_, undefined4 param_1);  // 0x10005600
XI_API void * __thiscall Input_InitState(void * self_);  // 0x10005660
XI_API undefined4 __cdecl Input_MapAxisLow(uint32_t param_1);  // 0x100059C0
XI_API undefined4 __cdecl Input_MapAxisHigh(uint32_t param_1);  // 0x10005A00
XI_API undefined4 __cdecl InputDevices_FindMapValue(char * param_1, undefined4 param_2, undefined4 param_3);  // 0x10007830
XI_API void __stdcall Input_HandleChar(uint32_t param_1, undefined4 xi_s2);  // 0x10007860
XI_API undefined4 __thiscall DirectInput_InstallKeyboard(void * self_);  // 0x10007E20
XI_API char __thiscall DirectInput_InstallMouse(_DWORD **self_);  // 0x10007EF0
XI_API void __thiscall InputDevices_JmpGetKeyboardLayout(void * self_);  // 0x10008020
XI_API undefined4 __thiscall DirectInput_InstallJoystick(void * self_);  // 0x100083D0
XI_API undefined4 __thiscall DirectInput_ReleaseDevice(void * self_, int param_1);  // 0x10008770
XI_API void __stdcall Input_SetActive(int param_1, int param_2, undefined4 xi_s3);  // 0x100087D0
XI_API undefined4 __thiscall Input_IsCursorActive(void * self_, uint32_t param_1);  // 0x10008830
XI_API void __thiscall Input_DispatchButtons(void * self_);  // 0x100088F0
XI_API void __thiscall DirectInput_PollMouse(void * self_);  // 0x100089D0
XI_API undefined4 __thiscall XInput_ProbeDll(void * self_);  // 0x10008D90
XI_API undefined4 __thiscall XInput_LoadFunctions(void * self_);  // 0x10008E10
XI_API undefined4 __stdcall InputDevices_CallPtr10456550IfEnabled(undefined4 param_1, undefined4 param_2);  // 0x10008EA0
XI_API undefined4 __stdcall InputDevices_CallPtr10456558IfEnabled(undefined4 param_1);  // 0x10008F00
XI_API BOOL __stdcall SetCursorPos(int X, int Y);  // 0x10009770
XI_API undefined4 __attribute__((stdcall, regparm(3))) CDx_EndAndApplyStateBlock(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, undefined4 param_2, int * param_3, undefined4 param_4);  // 0x100098E0
XI_API undefined4 __attribute__((stdcall, regparm(3))) CDx_SetVertexShaderCached(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, int param_2);  // 0x1000BE10
XI_API undefined4 __thiscall Light_ApplyTimeOfDayTint(void * self_, int param_1);  // 0x1000BE50
XI_API uint32_t __cdecl ByteSwap_Swap16(uint32_t param_1);  // 0x1000D100
XI_API uint32_t __cdecl ByteSwap_Swap32(uint32_t param_1);  // 0x1000D120
XI_API undefined8 __cdecl ByteSwap_ByteSwap32(uint32_t param_1);  // 0x1000D150
XI_API void __thiscall j_CEnv_UpdateDualTargetMode(void * self_, undefined4 xi_s1);  // 0x1000D3F0
XI_API void __cdecl App_RegisterSystemDats(void);  // 0x10010370
XI_API void __cdecl App_SaveAllSlotData(void);  // 0x10010520
XI_API void * __thiscall App_Constructor(void * self_);  // 0x10010700
XI_API void __thiscall App_SetSeqStep(void * self_, undefined4 param_1);  // 0x10010CE0
XI_API void __thiscall App_AdvanceSeqStep(void * self_);  // 0x10010D00
XI_API void __thiscall AppStartup_IncrementShort6(void * self_);  // 0x10010D10
XI_API char __thiscall App_InitScene(int self_, int a4);  // 0x10010D20
XI_API unsigned __int8 __thiscall Frame_Render(void * self_);  // 0x10011A00
XI_API int __cdecl Post_Afterimage(void);  // 0x10012F40
XI_API int __thiscall Post_FlashAndZoomFeedback(void *self_);  // 0x100132B0
XI_API undefined4 __thiscall App_RunOpening(void * self_);  // 0x100139E0
XI_API undefined4 __cdecl FrameRender_ReturnTrue(void);  // 0x10013AC0
XI_API char __thiscall App_StepGameState6(_WORD *self_);  // 0x10013DF0
XI_API char __thiscall App_StepGameState7(_WORD *self_);  // 0x10013F10
XI_API char __thiscall App_StepGameState8(_WORD *self_);  // 0x10014030
XI_API bool __cdecl App_StepGameState9(void);  // 0x10014120
XI_API undefined4 __thiscall App_DispatchSubState(void * self_);  // 0x10014170
XI_API char __thiscall Game_InGameSubState0(_WORD *self_);  // 0x100141C0
XI_API undefined4 __attribute__((stdcall, regparm(3))) App_SubStateInitCamera(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x10014200
XI_API undefined4 __thiscall App_InitCamera(void * self_, undefined4 param_1);  // 0x10014220
XI_API undefined4 __thiscall App_SubStateAdvance(void * self_);  // 0x100142A0
XI_API void * __thiscall CAtelIdleTask_ScalarDeletingDtor(void * self_, undefined4 param_1);  // 0x10014330
XI_API undefined1 __thiscall WinMain_RunStepThenLoadAll(void * self_);  // 0x10014350
XI_API undefined1 __thiscall WinMain_EnterState4AfterShutdown(void * self_);  // 0x100149B0
XI_API undefined4 __thiscall WinMain_TryShutdownActors(void * self_);  // 0x10014A20
XI_API uint32_t __thiscall WinMain_StepStagedRelease(void * self_);  // 0x10014A30
XI_API undefined4 __thiscall WinMain_StepMenuOkThenRelease(void * self_);  // 0x10014AD0
XI_API undefined1 __thiscall Camera_ReleaseAll(void * self_);  // 0x10014C10
XI_API void __cdecl WinMain_ApplyTables103501F8(void);  // 0x10014C60
XI_API undefined4 __thiscall WinMain_ShutdownActorsAndTables(void * self_);  // 0x10014C90
XI_API undefined4 __cdecl WinMain_ApplyTables10350210(void);  // 0x10014CB0
XI_API undefined4 __cdecl Camera_ClearByte0A(void);  // 0x10014CE0
XI_API long double __cdecl Camera_GetFrameScale(void);  // 0x10014CF0
XI_API long double __cdecl Camera_GetClampedField28(void);  // 0x10014D20
XI_API undefined4 __cdecl Camera_GetField38(void);  // 0x10014D60
XI_API long double __cdecl Camera_GetFloat2DC(void);  // 0x10014D70
XI_API long double __cdecl Camera_GetFloat2E0(void);  // 0x10014D80
XI_API void __cdecl Camera_SetClearColorRGB(undefined4 param_1, undefined4 param_2, undefined4 param_3);  // 0x10014D90
XI_API void __thiscall Camera_SetClearColorPacked(void * self_, uint32_t param_1, uint32_t param_2, uint32_t param_3);  // 0x10014DB0
XI_API void __cdecl Camera_SetField304BytesOnGlobal(undefined4 param_1, undefined4 param_2, undefined4 param_3);  // 0x10014E00
XI_API void __thiscall Camera_SetField304Bytes(void * self_, undefined4 param_1, undefined4 param_2, uint32_t param_3);  // 0x10014E20
XI_API void __cdecl Camera_SetField2FC(float param_1);  // 0x10014E60
XI_API void __cdecl Camera_SetField300(float param_1);  // 0x10014E80
XI_API void __cdecl Camera_SetField314(float param_1);  // 0x10014EB0
XI_API void __cdecl Camera_SetField318(float param_1);  // 0x10014ED0
XI_API undefined4 __cdecl Camera_Call100151A0OnGlobal(undefined4 param_1);  // 0x10015100
XI_API undefined4 __thiscall Camera_SetViewMatrices(void * self_, undefined4 xi_s1, undefined4 xi_s2, undefined4 xi_s3, undefined4 xi_s4, undefined4 xi_s5, undefined4 xi_s6, undefined4 xi_s7, undefined4 xi_s8, undefined4 xi_s9, undefined4 xi_s10, undefined4 xi_s11, undefined4 xi_s12, undefined4 xi_s13, undefined4 xi_s14, undefined4 xi_s15, undefined4 xi_s16);  // 0x10015120
XI_API void __thiscall Camera_SetProjectionMatrix(void * self_, undefined4 xi_s1, undefined4 xi_s2, undefined4 xi_s3, undefined4 xi_s4, undefined4 xi_s5, undefined4 xi_s6, undefined4 xi_s7, undefined4 xi_s8, undefined4 xi_s9, undefined4 xi_s10, undefined4 xi_s11, undefined4 xi_s12, undefined4 xi_s13, undefined4 xi_s14, undefined4 xi_s15, undefined4 xi_s16);  // 0x100151D0
XI_API int __cdecl Camera_GetViewMatrixPtr(void);  // 0x10015220
XI_API undefined4 __cdecl Camera_GetField50(void);  // 0x10015250
XI_API int __cdecl Camera_GetMatrix154Ptr(void);  // 0x10015270
XI_API void __cdecl Camera_SetField2F8OnGlobal(undefined4 param_1);  // 0x10015290
XI_API void __thiscall Camera_SetField2F8(void * self_, undefined4 param_1);  // 0x100152B0
XI_API long double __cdecl Camera_GetField2F4(void);  // 0x100152C0
XI_API void __cdecl Camera_SetField2E4(int param_1);  // 0x10015360
XI_API void __cdecl Camera_SetField2F0(float param_1, float param_2);  // 0x100153A0
XI_API void __cdecl Camera_BuildProjection(void);  // 0x10015480
XI_API void __thiscall Camera_BuildPerspectiveFov(void * self_);  // 0x10015490
XI_API undefined4 __cdecl Camera_GetByte0B(void);  // 0x100155D0
XI_API undefined4 __cdecl Camera_GetWord10(void);  // 0x10015600
XI_API undefined4 __cdecl Camera_GetWord12(void);  // 0x10015610
XI_API undefined4 __cdecl Camera_GetWord14(void);  // 0x10015640
XI_API undefined4 __cdecl Camera_GetWord16(void);  // 0x10015650
XI_API undefined4 __cdecl Camera_GetViewportWidth(void);  // 0x10015680
XI_API undefined4 __cdecl Camera_GetViewportHeight(void);  // 0x10015690
XI_API int __cdecl Camera_PickNearestAspect(int param_1, int param_2, undefined4 * param_3, undefined4 * param_4);  // 0x100156A0
XI_API undefined4 __cdecl WinMain_ReturnTrue(void);  // 0x10015740
XI_API void __stdcall App_WinMainClearFileMng(undefined4 param_1, undefined4 param_2, undefined4 param_3);  // 0x100157B0
XI_API undefined4 __stdcall App_RunWithCOM(undefined4 xi_s1, undefined4 xi_s2);  // 0x10015AB0
XI_API char __cdecl App_CreateRendererAndApp(void);  // 0x100161B0
XI_API void __cdecl App_RunMainLoopThenSetPtr(void);  // 0x10016300
XI_API _DWORD * __cdecl App_DestroyGlobalObjects(void);  // 0x10016320
XI_API void __cdecl App_SetGlobal_104569C5(undefined4 param_1);  // 0x100163C0
XI_API void __cdecl App_SetGlobal_104569C6(undefined4 param_1);  // 0x100163E0
XI_API undefined4 __cdecl App_SetGlobal_104569C8(undefined4 param_1);  // 0x10016400
XI_API undefined4 __cdecl App_GetGlobal_104569C8(void);  // 0x10016410
XI_API undefined4 __attribute__((cdecl, regparm(1))) WinMain_GetSceneStateByte68(undefined4 xi_eax);  // 0x100164B0
XI_API undefined4 __cdecl App_SetErrorCode(undefined4 param_1);  // 0x100164C0
XI_API void __cdecl App_GetGlobalPair(undefined4 * param_1, undefined4 * param_2);  // 0x10016560
XI_API LRESULT __stdcall App_WndProc(HWND param_1, uint32_t param_2, uint32_t param_3, int param_4);  // 0x10016870
XI_API void __thiscall GammaRamp_SetRGB(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3);  // 0x100170A0
XI_API undefined4 __thiscall GammaRamp_GetRGB(void * self_, undefined4 * param_1, undefined4 * param_2, undefined4 * param_3);  // 0x100170D0
XI_API undefined4 __thiscall GammaRamp_GetChannelSamples(void * self_, float * param_1, float * param_2, float * param_3);  // 0x10017100
XI_API void __thiscall GammaRamp_BuildRamps(void * self_);  // 0x10017160
XI_API void __thiscall GammaRamp_ApplyIfChanged(int self_);  // 0x10017230
XI_API int __stdcall WinMain_Draw(int a1, int a2);  // 0x10017310
XI_API void __cdecl setPolUrl(undefined4 param_1, undefined4 param_2);  // 0x10017630
XI_API undefined4 __cdecl App_SetGlobalAndClearCamera(void);  // 0x10017670
XI_API int __thiscall Shader_CreateVertexShader(void *self_, int a1);  // 0x10017810
XI_API undefined4 __thiscall XiCapture_Init(void * self_);  // 0x10017BB0
XI_API void __thiscall ErrorReport_Step(void * self_, undefined4 param_1, undefined4 param_2, short * param_3);  // 0x10017C20
XI_API int __thiscall ErrorReport_Begin(int *self_, int a2, int a3, int a4);  // 0x10017C60
XI_API void __cdecl ErrorReport_NoOpVarargsA(undefined4 xi_s1, ...);  // 0x10017D20
XI_API void __cdecl ErrorReport_NoOpVarargsB(undefined4 xi_s1, ...);  // 0x10017D30
XI_API undefined1 * __cdecl XiErrMsgGetErrCode(int param_1);  // 0x10017D90
XI_API void __cdecl ErrorReport_DispatchErrorCode(int param_1);  // 0x100180D0
XI_API void __cdecl ErrorReport_SendMessage7_1To10668FF8(undefined4 param_1);  // 0x10018140
XI_API undefined8 __cdecl ErrorReport_RegisterCallback(undefined4 param_1);  // 0x10018180
XI_API void __cdecl ErrorReport_SendMessage7_0To10668FF8(uint32_t param_1, char * param_2);  // 0x100181D0
XI_API undefined4 __cdecl ErrorReport_IsRegistered(void);  // 0x10018270
XI_API void __cdecl ErrorReport_Call10114F10NoArgs(undefined4 param_1);  // 0x100182C0
XI_API undefined8 __cdecl _exit_0(undefined4 param_1);  // 0x100182E0
XI_API void __cdecl ErrorReport_Thunk10114F10(uint32_t param_1, undefined4 * param_2, uint32_t param_3);  // 0x10018300
XI_API undefined4 __attribute__((cdecl, regparm(1))) ErrorReport_ReportAndHandleError(undefined4 xi_eax, int param_1, undefined4 * param_2, undefined4 param_3);  // 0x10018310
XI_API void * __thiscall ErrorReport_CtorVt10329F88(void * self_);  // 0x10018350
XI_API void * __thiscall ErrorReport_CtorVt10329F8C(void * self_);  // 0x10018430
XI_API void * __thiscall ErrorReport_CtorVt10329F90(void * self_);  // 0x10018550
XI_API void __thiscall ErrorReport_LoadChecksum(void * self_, undefined4 param_1, uint32_t param_2);  // 0x100185A0
XI_API undefined4 __thiscall OpeningSubtitle_IsStateFour(void * self_);  // 0x10018840
XI_API void * __thiscall OpeningSubtitle_Constructor(void * self_, int param_1);  // 0x10018A50
XI_API void __thiscall OpeningSubtitle_Reset(void * self_);  // 0x10018B30
XI_API void __thiscall OpeningSubtitle_UpdateRangeEntries(void * self_);  // 0x10018B50
XI_API void * __thiscall Vt10329FE0_Constructor(void * self_);  // 0x10018C50
XI_API void __thiscall Vt10329FE0_Reset(void * self_);  // 0x10018CE0
XI_API int * __cdecl TimerResolution_CreateObject(void);  // 0x100191D0
XI_API void __thiscall CXiTimer_Constructor(void * self_);  // 0x10019210
XI_API long double __thiscall CXiTimer_GetFloat08(void * self_);  // 0x10019230
XI_API undefined4 __attribute__((stdcall, regparm(3))) MotionQueue_ApplyPolicy(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, undefined4 param_2, undefined4 param_3, float param_4, undefined4 param_5);  // 0x10019A50
XI_API undefined4 __thiscall SampleAnimationTrack_ToBuffer(void * self_, int param_1, int * param_2, int param_3, float param_4, int param_5);  // 0x10019B30
XI_API undefined4 __thiscall SampleAnimationTrack_Live(void * self_, int param_1, int * param_2, int param_3, float param_4, float param_5, int param_6);  // 0x10019EE0
XI_API void __thiscall MotionQueList_ProcessAll(void * self_, int * param_1);  // 0x1001A3E0
XI_API undefined4 __thiscall MotionQueue_UpdateAllChannels(void * self_, undefined4 xi_s1);  // 0x1001A420
XI_API void __thiscall MotionQueList_QueueMotion(void * self_, int * param_1, int * param_2, undefined4 * param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7, int param_8, undefined4 param_9, undefined4 param_10);  // 0x1001A6E0
XI_API void __thiscall CYyMotionQue_GetResource(void * self_, undefined4 * param_1);  // 0x1001A850
XI_API void __thiscall CYyMotionQueList_Init(void * self_);  // 0x1001ABF0
XI_API void __thiscall KzMotionQueList_AdvanceAll(void * self_, float param_1);  // 0x1001B170
XI_API void __thiscall KzMotionQueList_NotifyAll(void * self_, void * param_1, undefined4 param_2);  // 0x1001B1F0
XI_API undefined4 __thiscall QueTimeStep_StepStateByTime(void * self_, float param_1);  // 0x1001B520
XI_API undefined4 __thiscall QueTimeStep_Update(void * self_);  // 0x1001B5D0
XI_API void * __thiscall ModelTranslucent_ReturnSelf(void * self_);  // 0x1001CF80
XI_API _DWORD * __cdecl Model_CreateTranslucentTargets(void);  // 0x1001D0A0
XI_API void __thiscall ModelTranslucent_Construct(void * self_);  // 0x1001D170
XI_API char __thiscall Model_BeginTranslucentPass(int self_);  // 0x1001D240
XI_API char __thiscall Model_TranslucentUnbindTexture(_DWORD *self_);  // 0x1001D350
XI_API void __stdcall ModelTranslucent_SetColorForce(undefined4 param_1, undefined4 param_2);  // 0x1001D390
XI_API int __thiscall Model_CompositeTranslucentPass(void *self_);  // 0x1001D3B0
XI_API void __thiscall TexRes_LoadBm2(void * self_);  // 0x1001D800
XI_API int __thiscall Tex_DrawNamedTexturePreview(void *self_, int a1, int a2);  // 0x1001DC70
XI_API int __stdcall Gfx_DrawScreenQuad256(int a1, int a2);  // 0x1001DD00
XI_API undefined4 __attribute__((cdecl, regparm(1))) CYyCamMng2_SetGlobalFlags(undefined4 xi_eax, undefined4 param_1, undefined4 param_2, undefined4 param_3);  // 0x1001E2F0
XI_API undefined4 __attribute__((cdecl, regparm(1))) CYyCamMng2_CallGlobalVfunc1(undefined4 xi_eax);  // 0x1001E4B0
XI_API undefined4 __thiscall Camera_SetPosition(void * self_, undefined4 * param_1);  // 0x1001E760
XI_API undefined4 __thiscall Camera_SetTargetIfMoved(void * self_, float * param_1);  // 0x1001E780
XI_API undefined4 __thiscall Camera_PlaceRelativeToActor(void * self_, float * param_1, int * param_2);  // 0x10021680
XI_API undefined4 __thiscall Camera_DiffersFromSaved(void * self_);  // 0x10021AE0
XI_API int __thiscall Camera_SnapshotState(void * self_);  // 0x10021B70
XI_API int __thiscall Camera_BuildLookAtView(void * self_);  // 0x10021C10
XI_API void __thiscall Actor_ClearIndexTable(void * self_);  // 0x100220E0
XI_API long double __thiscall Actor_GetPercentScaleByIndex(void * self_, int param_2);  // 0x10022120
XI_API undefined4 __cdecl Actor_MapPercentScaleIndex(int param_1);  // 0x10022170
XI_API long double __thiscall Actor_LookupPercentScaleA(void * self_, int param_2);  // 0x10022190
XI_API long double __thiscall Actor_LookupPercentScaleB(void * self_, int param_2);  // 0x100221E0
XI_API void * __thiscall Actor_InitIndexTable(void * self_);  // 0x10022230
XI_API int __cdecl ActorCamera_LookupTable1032A41C(int param_1);  // 0x10022320
XI_API void __cdecl ProjTexTarget_Release(void);  // 0x10025220
XI_API Vt_1032A460_vtbl ** __thiscall ProjTexTarget_Init(Vt_1032A460_vtbl **self_);  // 0x10025260
XI_API char __thiscall ProjTex_BeginPass(_DWORD *self_, int *a2, int a3, _DWORD *a4);  // 0x10025330
XI_API int __thiscall ProjTex_EndPass(void *self_, int a1);  // 0x100255C0
XI_API int __thiscall ProjTex_CaptureToTarget(void *self_, int a1, int a2, int a3, int a4);  // 0x10025870
XI_API void __cdecl EnvMapProjTex_Nop_10025BD0(void);  // 0x10025BD0
XI_API void __cdecl EnvMapProjTex_Nop_10025BE0(void);  // 0x10025BE0
XI_API void __thiscall EnvMapProjTex_ClearCounter(void * self_);  // 0x10025BF0
XI_API char __stdcall EnvMap_BeginPass(int *a1, int a2, float *a3);  // 0x10025C40
XI_API int __stdcall EnvMap_EndPass(int a1);  // 0x10025F70
XI_API void __cdecl Dbg_DrawViewAxisGizmo(void);  // 0x100263F0
XI_API void __stdcall Dbg_DrawAxesAt(int a1);  // 0x100266C0
XI_API void __cdecl Vec3_SetZero(undefined4 * param_1);  // 0x10026E00
XI_API void __cdecl Quat_SetIdentity(undefined4 * param_1);  // 0x10026E10
XI_API void __cdecl Vec4_Set(float * param_1, float param_2, float param_3, float param_4, float param_5);  // 0x10026E30
XI_API undefined4 __cdecl Vec3_Set(float * param_1, float param_2, float param_3, float param_4);  // 0x10026E50
XI_API undefined8 __cdecl Vec4_Copy(undefined4 * param_1, undefined4 * param_2);  // 0x10026E90
XI_API undefined4 __cdecl Vec3_Copy(undefined4 * param_1, undefined4 * param_2);  // 0x10026EB0
XI_API undefined4 __cdecl Vec3_AddInPlace(float * param_1, float * param_2);  // 0x10026F20
XI_API void __cdecl Vec3_Add_10026FA0(float * param_1, float * param_2, float * param_3);  // 0x10026FA0
XI_API void __cdecl Vec2_Add(float * param_1, float * param_2, float * param_3);  // 0x10026FD0
XI_API undefined4 __cdecl Vec3_SubInPlace(float * param_1, float * param_2);  // 0x100270A0
XI_API undefined4 __cdecl Vec3_Sub(float * param_1, float * param_2, float * param_3);  // 0x10027120
XI_API void __cdecl Vec3_ScaleInPlace(float * param_1, float param_2);  // 0x100272B0
XI_API undefined4 __cdecl Vec3_Scale(float * param_1, float * param_2, float param_3);  // 0x100272E0
XI_API void __cdecl Vec3_MulInPlace(float * param_1, float * param_2);  // 0x10027310
XI_API undefined4 __cdecl Vec3_MulComponents(float * param_1, float * param_2, float * param_3);  // 0x10027340
XI_API void __cdecl Vec3_CopyThen100274B0(float * param_1, undefined4 * param_2);  // 0x10027510
XI_API undefined4 __cdecl Vec3_Cross(undefined4 * param_1, float * param_2, float * param_3);  // 0x10027550
XI_API long double __cdecl MathVector_Distance3(float * param_1, float * param_2);  // 0x100275D0
XI_API long double __cdecl MathVector_Length3(float * param_1);  // 0x10027600
XI_API long double __cdecl Vec3_Call100275D0(float * param_1, float * param_2);  // 0x10027620
XI_API void __cdecl Gfx_ProjectWorldToClip(float *a1, _DWORD *a2);  // 0x100276F0
XI_API void __cdecl Gfx_TransformWorldToView(float *a1, _DWORD *a2);  // 0x100277E0
XI_API void __cdecl Gfx_ProjectViewToClip(float *a1, _DWORD *a2);  // 0x10027870
XI_API float * __cdecl Gfx_NdcToScreen(float *a1);  // 0x100278E0
XI_API float * __cdecl Gfx_ScreenDeltaToNdc(float *a1, float *a2);  // 0x10027930
XI_API undefined4 __thiscall MathVector_ReturnThis(void * self_);  // 0x10027990
XI_API void __cdecl MathVector_Nop(void);  // 0x100279A0
XI_API undefined4 __thiscall Mat4_SetIdentity(void * self_);  // 0x100279B0
XI_API undefined4 __thiscall Mat4_Copy(void * self_, undefined4 * param_1);  // 0x100279F0
XI_API void __thiscall Mat4_PostScale(void * self_, undefined4 * param_1);  // 0x10027A60
XI_API void __thiscall Mat4_BuildScale(void * self_, undefined4 * param_1);  // 0x10027AE0
XI_API void __thiscall Mat4_SetScale(void * self_, undefined4 * param_1);  // 0x10027B30
XI_API void __thiscall Mat4_PostRotateX(void * self_, float param_1);  // 0x10027B80
XI_API void __thiscall Mat4_PostRotateY(void * self_, float param_1);  // 0x10027BD0
XI_API void __thiscall Mat4_PostRotateZ(void * self_, float param_1);  // 0x10027C20
XI_API void __thiscall Mat4_SetRow3(void * self_, undefined4 * param_1);  // 0x10027CD0
XI_API undefined4 __thiscall Mat4_SetTranslation(void * self_, undefined4 * param_1);  // 0x10027CF0
XI_API void __thiscall Mat4_PostMultiply(void * self_, int param_1);  // 0x10027D10
XI_API void __thiscall Mat4_PreMultiply(void * self_, float * param_1);  // 0x10027E90
XI_API undefined4 __thiscall Mat4_TransformVec4InPlace(void * self_, undefined4 * param_1);  // 0x10028140
XI_API undefined4 __thiscall Mat4_TransformVec4(void * self_, float * param_1, float * param_2);  // 0x10028170
XI_API undefined4 __thiscall Mat4_TransformPointInPlace(void * self_, float * param_1);  // 0x10028200
XI_API undefined8 __thiscall Mat4_TransformPoint(void * self_, float * param_1, float * param_2);  // 0x10028230
XI_API undefined4 __thiscall Mat4_TransformNormalInPlace(void * self_, undefined4 * param_1);  // 0x10028290
XI_API undefined4 __thiscall Mat4_TransformNormal(void * self_, float * param_1, float * param_2);  // 0x100282C0
XI_API undefined4 __thiscall Mat4_TransformCoordInPlace(void * self_, float * param_1);  // 0x10028320
XI_API undefined4 __thiscall Mat4_InvertOrthonormal(void * self_);  // 0x100283C0
XI_API undefined4 * __cdecl Mem_AllocObject(int param_1, undefined4 param_2);  // 0x10028640
XI_API undefined4 * __cdecl Mem_AllocWithFallback(int param_1, int param_2);  // 0x100286B0
XI_API void __cdecl Mem_FreeObject(undefined4 xi_s1);  // 0x10028700
XI_API void __cdecl SharedDeleteHelper(int param_1);  // 0x10028710
XI_API void __cdecl MathVector_Call10029150(undefined4 param_1);  // 0x10028720
XI_API int __cdecl Mem_GetPtrMinus0x20(int param_1);  // 0x10028730
XI_API undefined8 __cdecl MemBlock_AllocFromFront(int param_1, int param_2, int param_3);  // 0x10028850
XI_API undefined8 __cdecl MemBlock_AllocFromBack(int param_1, undefined4 param_2, void * param_3);  // 0x10028930
XI_API int __cdecl MemBlock_FindLargestFreeSize(int param_1, int param_2);  // 0x100289F0
XI_API undefined4 __cdecl Mem_FreeBlockMergeNeighbours(undefined4 param_1);  // 0x10028AA0
XI_API undefined4 __cdecl Mem_FreeHeaderMergeNeighbours(int param_1);  // 0x10028AC0
XI_API int __thiscall MemBlock_GetSize(void * self_);  // 0x10028B90
XI_API undefined4 __attribute__((cdecl, regparm(1))) MemBlock_CallEnabledEntries(undefined4 xi_eax, undefined4 param_1, int param_2, int param_3);  // 0x10028BF0
XI_API undefined4 __cdecl MemBlock_CallEnabledList0(undefined4 param_1);  // 0x10028C30
XI_API void __cdecl MemBlock_CallEnabledList1(undefined4 param_1);  // 0x10028C50
XI_API void __cdecl MemBlock_CallEnabledList2(undefined4 param_1);  // 0x10028C70
XI_API void __cdecl MemBlock_CallEnabledList3(undefined4 param_1);  // 0x10028C90
XI_API undefined4 * __cdecl Mem_AllocFromArea(int param_1, undefined4 param_2);  // 0x10028FD0
XI_API void __cdecl MemArea_CallListByKind(undefined4 param_1);  // 0x10029150
XI_API undefined4 __stdcall MemHeapDebug_ApplyFourTables(undefined4 param_1);  // 0x10029390
XI_API int __stdcall Mem_DrawHeapUsageBar(int a1, int a2, int a3, int a4, int a5);  // 0x100295A0
XI_API int __cdecl CreateSharedVertexBuffers(void);  // 0x10029A50
XI_API void __cdecl ModelDtInit_ReleaseAll(void);  // 0x10029B60
XI_API void __thiscall CYyModelDtBase_Destructor(void * self_);  // 0x10029CD0
XI_API undefined4 __thiscall ModelDtBase_GetField20(void * self_);  // 0x10029D20
XI_API int __thiscall ModelBaseParts_FindTailLink(void * self_);  // 0x10029EB0
XI_API void __thiscall ModelBaseParts_AppendAtTail(void * self_, undefined4 param_1);  // 0x10029F00
XI_API undefined4 __thiscall ModelBaseDraw_ApplyToVec4(void * self_, undefined4 param_1, undefined4 * param_2);  // 0x1002A780
XI_API void __stdcall Part_CopyTranslation(int param_1, undefined4 * param_2);  // 0x1002A890
XI_API void __thiscall Part_AddTranslation(void * self_, int param_1, float * param_2);  // 0x1002A8B0
XI_API undefined4 __stdcall ModelBaseDraw_ClampPointToLocalEllipse(float * param_1, float * param_2, undefined4 * param_3, float * param_4);  // 0x1002B140
XI_API void * __thiscall List_GetTail(void * self_);  // 0x1002C7C0
XI_API void __thiscall ListUtil_PopHead(void * self_, int * param_1);  // 0x1002C800
XI_API undefined4 __cdecl Mem_AllocDefault(undefined4 param_1);  // 0x1002C890
XI_API void __cdecl thunk_sub_10028AA0(int param_1);  // 0x1002C8B0
XI_API void * __thiscall CYyOs2VtxBuffer_ScalarDeletingDtor(void * self_, undefined4 param_1);  // 0x1002D660
XI_API void __attribute__((stdcall, regparm(3))) CMoResource_DropObjectAt5E(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x1002D860
XI_API undefined4 __thiscall Os2VtxBuffer_FixOffsetsAndCreateVtxBuffer(void * self_);  // 0x1002D8F0
XI_API void __cdecl Gfx_SetStreamSourceCached(int param_1, undefined4 param_2, undefined4 param_3);  // 0x1002F130
XI_API int __cdecl Gfx_ApplyCachedStreamSource(unsigned int a1);  // 0x1002F160
XI_API int __cdecl Gfx_ApplyCachedVertexShader(void);  // 0x1002F1A0
XI_API void __thiscall Model_SkinVerticesCpu(void * self_);  // 0x1002F1D0
XI_API void __thiscall Skin_BlendWeightMatrices(void * self_);  // 0x100303B0
XI_API void * __thiscall Quat_SetIdentityChained(void * self_);  // 0x10032A40
XI_API void __thiscall Quat_SetIdentityB(void * self_);  // 0x10032A50
XI_API void __cdecl BoneShadow_Nop(void);  // 0x10032A70
XI_API undefined4 __thiscall Quat_Multiply(void * self_, float * param_1, float * param_2);  // 0x10032B50
XI_API void __thiscall Quat_NormalizeInPlace(void * self_);  // 0x10032DA0
XI_API void __thiscall BoneShadow_FromQuat(void * self_, float * param_1);  // 0x10032FE0
XI_API undefined4 __thiscall Quat_NLerp(void * self_, float * param_1, float * param_2, float param_3);  // 0x10033220
XI_API void __cdecl BoneShadow_InitTargets(void);  // 0x100336B0
XI_API void __cdecl BoneShadow_ReleaseTargets(void);  // 0x100336D0
XI_API _DWORD * __thiscall BoneShadow_Construct(_DWORD *self_);  // 0x10033710
XI_API char __thiscall Model_BeginOffscreenPass(int self_, int *a2, int a3);  // 0x10033800
XI_API char __thiscall Model_EndOffscreenPassBindTextures(_DWORD *self_, int a2);  // 0x10033A70
XI_API undefined4 __thiscall Shadow_DrawByMode(void * self_, float * param_1);  // 0x10033DA0
XI_API void __thiscall Shadow_SmoothLightDirection(void * self_, float * param_1);  // 0x10033EA0
XI_API undefined4 __thiscall Skel_BindShared(void * self_);  // 0x10034330
XI_API void __thiscall Skel_LoadBoneRotTrans(void * self_);  // 0x10034620
XI_API undefined4 __thiscall Skel_ComposeMode(void * self_, int param_1, int param_2, int param_3, int param_4);  // 0x100347D0
XI_API void __stdcall Skel_ComposeFromBone(uint8_t * param_1);  // 0x10034B80
XI_API void __thiscall Skel_OffsetAllTranslations(void * self_, float * param_1, int param_2);  // 0x10035170
XI_API int __thiscall Skel_GetRecordAt(void * self_, int param_1);  // 0x100351F0
XI_API int __thiscall Skel_GetBoneTableBase(void * self_);  // 0x10035210
XI_API uint16_t * __thiscall Skel_GetTableAfterBones(void * self_);  // 0x10035250
XI_API int __thiscall Skel_GetEntryAt(void * self_, int param_1);  // 0x10035270
XI_API undefined4 __thiscall Skel_ClearMarks(void * self_);  // 0x100352A0
XI_API void __thiscall Skel_MarkMarkedChains(void * self_);  // 0x100352F0
XI_API void __thiscall Skel_MarkChain(void * self_, int param_1, undefined4 param_2, uint32_t param_3);  // 0x10035330
XI_API void __cdecl SoundElem_SetFactor103516F8(undefined4 param_1);  // 0x10035E80
XI_API void __cdecl SoundElem_SetFactor103516FC(undefined4 param_1);  // 0x10035EC0
XI_API undefined4 __attribute__((cdecl, regparm(1))) MoTask_KillAllGlobalSlots(undefined4 xi_eax, undefined4 param_1);  // 0x10035F00
XI_API undefined4 __cdecl SoundElem_ClearGlobal10463930(undefined4 xi_s1);  // 0x10035F80
XI_API undefined4 __cdecl SoundElem_SetScaled10351708(float param_1);  // 0x10035FB0
XI_API undefined4 __attribute__((cdecl, regparm(1))) SoundElem_Release10463928AndSetScaled(undefined4 xi_eax, undefined4 xi_s1);  // 0x10036020
XI_API void __cdecl SoundElem_SetScaled10351704(float param_1);  // 0x10036050
XI_API undefined4 __attribute__((cdecl, regparm(1))) MoTask_KillGlobalSlot1(undefined4 xi_eax, undefined4 xi_s1);  // 0x10036070
XI_API void __cdecl SoundElem_SetScaled10351700(float param_1);  // 0x100360A0
XI_API undefined4 __cdecl SoundElem_ClearGlobal10463934(undefined4 xi_s1);  // 0x100360C0
XI_API undefined4 __attribute__((cdecl, regparm(1))) Music_ApplyVolume(undefined4 xi_eax, float param_1);  // 0x100360F0
XI_API void __cdecl SoundElem_SetCurrent10463914(int param_1);  // 0x10036170
XI_API void __cdecl SoundElem_ResetGlobals(void);  // 0x100361D0
XI_API uint32_t __cdecl SoundElem_AddUniqueId(int param_1);  // 0x10036460
XI_API uint32_t __attribute__((cdecl, regparm(1))) CYySoundElem_IsHandleInFrameList(undefined4 xi_eax, int param_1);  // 0x100367F0
XI_API undefined4 __thiscall SoundVolume_SendStopToLobby(void * self_, undefined4 param_1);  // 0x10036B90
XI_API uint32_t __cdecl SoundVolume_ComputeDistanceVolumeAndPan(float * param_1, uint32_t * param_2, float * param_3, float param_4, float param_5, float param_6, undefined4 param_7, int param_8);  // 0x10036C70
XI_API undefined8 __thiscall SoundVolume_SetVolumeScalar(void * self_, undefined4 param_1, undefined4 param_2);  // 0x10036F00
XI_API undefined4 __thiscall SoundVolume_SetVolumeVector(void * self_, undefined4 param_1, undefined4 param_2);  // 0x10036F50
XI_API void __thiscall SoundVolume_CreateSoundElem(void * self_, undefined4 * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7, undefined4 param_8);  // 0x10037020
XI_API void __cdecl StAvatar_SwitchMusicTask(int param_1);  // 0x10037960
XI_API void __cdecl LobbyThread_SendCmd6IfRunning(void);  // 0x10037A10
XI_API void __cdecl SetMusicTrackVolume_C(void);  // 0x10037B30
XI_API void __cdecl SetMusicTrackVolume_A(void);  // 0x10037B90
XI_API undefined4 __cdecl SetMusicTrackVolume_B(void);  // 0x10037BF0
XI_API void __cdecl SetMusicTrackVolume_Tag0004(void);  // 0x10037C50
XI_API void __cdecl MusicTrack_SetVolumeId0009(void);  // 0x10037D70
XI_API void __cdecl MusicTrack_SetVolumeId0010(void);  // 0x10037DD0
XI_API void __cdecl MusicTrack_SetVolumeId0011(void);  // 0x10037E30
XI_API void __cdecl MusicTrack_SetVolumeId0013(void);  // 0x10037E90
XI_API void __cdecl MusicTrack_SetVolumeId0016(void);  // 0x10037FB0
XI_API void __cdecl MusicFont_Create(uint32_t param_1, undefined4 param_2, undefined4 param_3);  // 0x100380F0
XI_API void __attribute__((cdecl, regparm(1))) Music_LoadTrackIfRunning(undefined4 xi_eax, undefined4 param_1, undefined4 param_2);  // 0x100382A0
XI_API undefined4 __cdecl MusicFont_QueueSoundCmdIfChannelsBelowLimit(int param_1, float * param_2, int param_3);  // 0x10038330
XI_API undefined4 __attribute__((cdecl, regparm(1))) LobbyThread_SendCmd3FromFloat(undefined4 xi_eax, undefined4 param_1, float * param_2, undefined4 param_3);  // 0x10038440
XI_API undefined4 __attribute__((cdecl, regparm(1))) Music_SetTrackVolume(undefined4 xi_eax, int param_1, int param_2, undefined4 param_3);  // 0x10038470
XI_API undefined4 __cdecl Font_QueueText(char * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);  // 0x100384B0
XI_API int __cdecl Font_DrawPass(void);  // 0x10038520
XI_API unsigned __int8 * __cdecl Font_DrawString(unsigned __int8 *a1, float a2, float arg8, float a4);  // 0x10038720
XI_API _DWORD * __cdecl Post_CreateScreenEffectTargets(void);  // 0x10038930
XI_API void __cdecl PostCapture_ReleaseTextures(void);  // 0x100389C0
XI_API void __thiscall PostCapture_Init(void * self_);  // 0x10038A20
XI_API int __thiscall Post_CaptureSceneToTarget(void *self_);  // 0x10038A80
XI_API undefined4 __thiscall Post_DrawRotatingGhostLayers(void * self_);  // 0x10038E10
XI_API void __thiscall ThreadPool_StartThread(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3);  // 0x100394D0
XI_API void __thiscall ThreadPool_Shutdown(void * self_);  // 0x10039550
XI_API undefined4 __thiscall CYyObject_VT_1032A9F8_Construct(void * self_);  // 0x100395D0
XI_API void __thiscall ThreadPool_CreateSuspendedThread(void * self_, LPTHREAD_START_ROUTINE param_1, LPVOID param_2, undefined4 xi_s3);  // 0x10039670
XI_API void __thiscall Thread_ResumeAndWait(void * self_);  // 0x100396A0
XI_API undefined4 __thiscall TexBase_CopyName16(void * self_, char * param_1);  // 0x100397A0
XI_API void __thiscall Util_Copy16Bytes(void * self_, int param_1);  // 0x10039810
XI_API undefined4 __thiscall TexObj_Constructor(void * self_);  // 0x10039920
XI_API void __thiscall TexObj_Release(void * self_);  // 0x100399D0
XI_API undefined1 __thiscall TexObj_CreateAndUpload(void * self_);  // 0x10039A30
XI_API undefined1 __thiscall TexObj_Reupload(void * self_);  // 0x10039A60
XI_API int __thiscall TexObj_Upload(void *self_);  // 0x10039E50
XI_API undefined4 __thiscall CYyTexMng_Init(void * self_);  // 0x1003AA50
XI_API int __thiscall TexMgr_GetField8(void * self_);  // 0x1003AAB0
XI_API int * __thiscall TexMgr_GetTailLink(void * self_);  // 0x1003AAF0
XI_API undefined1 __thiscall TexMgr_UploadPumpEntry(void * self_);  // 0x1003AB70
XI_API void __thiscall TexMgr_Enqueue(void * self_, int param_1);  // 0x1003AB80
XI_API undefined4 __thiscall TexMgr_UploadPump(void * self_);  // 0x1003ABB0
XI_API int __thiscall TexMgr_FindByName(void * self_, int param_1, int param_2, undefined4 param_3);  // 0x1003AEA0
XI_API void * __thiscall CYyVb_ScalarDelete(void * self_, undefined4 param_1);  // 0x1003B430
XI_API void __thiscall VertexBufferList_Register(void * self_);  // 0x1003B4D0
XI_API long double __cdecl CMoAttachments_MatrixPointingFromTo(int param_1, float * param_2, float * param_3);  // 0x1003B980
XI_API double __thiscall YmGenerater_BuildAttachMatrix(int self_, _DWORD *a2, int a3, int a4);  // 0x1003BE10
XI_API void __thiscall AttachNotify_CopyFields(void * self_, int param_1);  // 0x1003C740
XI_API long double __attribute__((stdcall, regparm(3))) AttachNotify_GetFactorFromAttachments(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, uint8_t * param_2, float param_3);  // 0x1003C7D0
XI_API int __cdecl Sky_DrawDome(void);  // 0x1003D9A0
XI_API int __cdecl Sky_DrawDomeViewCentered(void);  // 0x1003DB60
XI_API undefined4 __thiscall SkyDome_ScaleColorBytes(void * self_, uint32_t * param_1, float param_2);  // 0x1003DFE0
XI_API undefined4 __thiscall SkyDome_ScaleBytesByVec4(void * self_, undefined4 * param_1, float * param_2);  // 0x1003E0D0
XI_API void __thiscall SkyDome_AddBytes(void * self_, char * param_1);  // 0x1003E1D0
XI_API void __thiscall Color_SetFromU32SwapRB(void * self_, undefined4 param_1);  // 0x1003E280
XI_API uint32_t * __thiscall SkyDome_ScaleAlpha(void * self_, uint32_t * param_1, float param_2);  // 0x1003E330
XI_API __int64 __thiscall SkyDome_AddScaledBytes(unsigned __int8 *self_, unsigned __int8 *a2);  // 0x1003E3A0
XI_API __int64 __thiscall SkyDome_AddScaledWords(unsigned __int8 *self_, __int16 *a2);  // 0x1003E450
XI_API int __thiscall SkyDome_AddScaledWordsSaturated(unsigned __int8 *self_, __int16 *a2);  // 0x1003E500
XI_API void __thiscall SkyDome_AddToByte2(void * self_, undefined4 param_1);  // 0x1003E630
XI_API void __thiscall SkyDome_AddToByte1(void * self_, undefined4 param_1);  // 0x1003E640
XI_API void __thiscall SkyDome_AddToByte0(void * self_, undefined4 param_1);  // 0x1003E650
XI_API void __thiscall SkyDome_AddScaledToByte3(void *self_, int a1);  // 0x1003E660
XI_API void __thiscall YmElem_DrawD3ASegment(void * self_, undefined4 param_1, undefined4 param_2, int param_3);  // 0x1003E910
XI_API int __thiscall YmElem_SetD3ADrawState(int self_);  // 0x1003E9A0
XI_API int __thiscall MoElem_GetVertexData(void * self_);  // 0x1003FD70
XI_API void * __thiscall CXi471011C8_VT_1032AD80_DeletingDtor(void * self_, undefined4 param_1);  // 0x10041130
XI_API undefined8 __thiscall CXiSub_10041E70_Ctor(void * self_, int param_1);  // 0x10041F40
XI_API _DWORD * __thiscall YmElem_DrawScreenDistortion(float *self_);  // 0x100426F0
XI_API undefined4 __attribute__((stdcall, regparm(3))) DynVBCtor_ToggleByte45(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x10043DD0
XI_API undefined4 __cdecl DynVBCtor_ReturnZero(void);  // 0x10043DE0
XI_API undefined8 __thiscall DynVB_Constructor(void * self_);  // 0x10043DF0
XI_API int __thiscall DynVB_Create(_DWORD *self_, int a2, unsigned int a3, int a4);  // 0x10043E50
XI_API void __thiscall DynVB_ReturnBuffersToPool(void * self_);  // 0x10043F00
XI_API int __thiscall CMoVuElem_Draw(int *self_, int a2, int a3, int a1, unsigned int a5, int a6);  // 0x10043F40
XI_API void __thiscall DynVB_Reserve(void * self_, int param_1);  // 0x10044010
XI_API undefined1 * __thiscall DynVB_Lock(void * self_);  // 0x10044130
XI_API void __thiscall DynVB_Unlock(void * self_);  // 0x100441A0
XI_API int __thiscall CameraCache_CacheViewProjection(_DWORD *self_);  // 0x100441C0
XI_API int __thiscall Gfx_SetViewMatrixFromField10(int self_);  // 0x10044210
XI_API int __thiscall Gfx_SetViewMatrixFromField90(int self_);  // 0x10044230
XI_API _DWORD * __cdecl Mo_InitSharedRenderResources(void);  // 0x10044270
XI_API void __stdcall DynVB_ToggleDynVBs(void);  // 0x10044540
XI_API void __cdecl DynVB_ReleaseResourcesOf(int param_1);  // 0x100446A0
XI_API undefined4 __thiscall ElemFog_ComputeWorldPos(void * self_, float * param_1);  // 0x10044C40
XI_API undefined4 __thiscall ElemFog_IsActive(void * self_);  // 0x10044CF0
XI_API void __thiscall ElemFog_UpdateTransform(void * self_);  // 0x10044D40
XI_API undefined4 __thiscall YmElem_ComputeViewDepthKey(void * self_);  // 0x10044F10
XI_API undefined4 __attribute__((stdcall, regparm(3))) YmElem_BuildDrawMatrixAndTest(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x10045920
XI_API CMoProcessor * __thiscall ElemFog_GetFlaggedMatrix(_DWORD *self_);  // 0x10045C50
XI_API void __thiscall RegisterWithProcessor(void * self_);  // 0x10045D40
XI_API undefined4 __thiscall YmElem_DrawWithOwnProjection(void * self_);  // 0x10046070
XI_API void __cdecl Zone_UpdateFogAmbient(void);  // 0x10046380
XI_API int __cdecl Fog_SetRenderStates(void);  // 0x100464D0
XI_API int __thiscall YmElem_SetupDevice(void *self_, int a1);  // 0x100467E0
XI_API int __thiscall YmElem_RestoreDevice(_WORD *a1, __int16 a4);  // 0x100472F0
XI_API unsigned __int8 * __cdecl ElemFields_InitFromRenderTarget(void);  // 0x100474D0
XI_API undefined * __thiscall ElemOffset_GetOffsetVec(void * self_);  // 0x10047B80
XI_API undefined4 * __attribute__((stdcall, regparm(3))) CMoGeneratorClone_VT_1032B114_Constructor(uint32_t xi_eax_unused, undefined4 xi_edx, undefined4 * param_1);  // 0x10047F80
XI_API uint32_t * __thiscall GeneratorClone_FindRecordByType(void * self_, uint32_t param_1);  // 0x10049330
XI_API int __thiscall GeneratorClone_GetShort22ViaPtrE4(void * self_);  // 0x100493B0
XI_API undefined * __thiscall GeneratorClone_GetCmdType1Data(void * self_);  // 0x100493C0
XI_API bool __cdecl GateEffectBoxProjection(int a1, int a2, __int16 a3, __int16 *a4);  // 0x1004A870
XI_API undefined4 __thiscall GeneratorClone_GetSelf(void * self_);  // 0x1004E210
XI_API undefined4 __attribute__((stdcall, regparm(3))) GeneratorClone_SetByte(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, undefined4 param_2);  // 0x1004E250
XI_API int __thiscall GeneratorClone_GetSelfPlus2(void * self_);  // 0x1004E260
XI_API int __thiscall GeneratorClone_GetSelfPlus1(void * self_);  // 0x1004E270
XI_API undefined4 __thiscall GeneratorClone_ReturnThisA(void * self_);  // 0x1004E280
XI_API int __thiscall GeneratorClone_GetSelfPlus3(void * self_);  // 0x1004E290
XI_API int __thiscall GeneratorClone_GetByte2Ptr(void * self_);  // 0x1004E2A0
XI_API int __thiscall GeneratorClone_GetByte1Ptr(void * self_);  // 0x1004E2B0
XI_API undefined4 __thiscall GeneratorClone_ReturnThisB(void * self_);  // 0x1004E2C0
XI_API int __thiscall GeneratorClone_GetByte3Ptr(void * self_);  // 0x1004E2D0
XI_API void __thiscall GeneratorClone_CopyDwords(void * self_, undefined4 * param_1);  // 0x1004E320
XI_API void __thiscall GeneratorClone_Accumulate(void * self_, float * param_1);  // 0x1004E360
XI_API undefined8 __thiscall GeneratorClone_IsFirstDwordNotEqual(void * self_, int param_1);  // 0x1004E3B0
XI_API undefined4 __thiscall Pool_FreeSlot(void * self_);  // 0x1004E3F0
XI_API uint32_t __thiscall GeneratorClone_GetBits13To18Shl2(void * self_);  // 0x1004E490
XI_API long double __thiscall GeneratorClone_EvaluateWithMode4(void * self_, float param_2);  // 0x1004E4E0
XI_API double __cdecl ScaleElemVisibilityByProbe(int a1, int a2, __int16 *a3);  // 0x1004E630
XI_API undefined4 __thiscall GeneratorClone_GetByte(void * self_);  // 0x100527B0
XI_API void __thiscall GeneratorClone_SetDwords(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);  // 0x100527C0
XI_API void __thiscall GeneratorClone_CallProcessorSlot49(void * self_, undefined4 xi_s1);  // 0x100527E0
XI_API void * __thiscall GeneratorClone_ReturnThis(void * self_);  // 0x100527F0
XI_API void __thiscall GeneratorClone_Set3Dwords(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3);  // 0x10052800
XI_API undefined4 __thiscall GeneratorClone_SubInto(void * self_, float * param_1, float * param_2);  // 0x10052820
XI_API undefined4 __thiscall GeneratorClone_SetDwordAndCopyOut(void * self_, undefined4 * param_1, undefined4 param_2);  // 0x10052870
XI_API void __thiscall GeneratorClone_SetDword(void * self_, undefined4 param_1);  // 0x10052880
XI_API undefined4 __thiscall GeneratorClone_GetDwordThroughPtr(void * self_);  // 0x10052890
XI_API undefined4 __thiscall GeneratorClone_GetDword(void * self_);  // 0x100528A0
XI_API int __thiscall GeneratorClone_GetPtr30(void * self_);  // 0x100528B0
XI_API undefined4 __thiscall GeneratorClone_SetPtrAndGetDword(void * self_, undefined4 * param_1);  // 0x100528C0
XI_API undefined4 __thiscall GeneratorClone_GetFirstDeref(void * self_);  // 0x100528E0
XI_API undefined4 __thiscall GeneratorClone_GetDwordThroughPtrOrZero(void * self_);  // 0x100528F0
XI_API int __thiscall GeneratorClone_GetPtrB90(void * self_);  // 0x10052900
XI_API void __thiscall MoProcessor_PopFreeIndex(void * self_);  // 0x10052910
XI_API undefined4 __thiscall GeneratorClone_GetFirst(void * self_);  // 0x10052940
XI_API undefined4 __thiscall GeneratorClone_GetWordAt176(void * self_);  // 0x10052950
XI_API int __thiscall GeneratorClone_GetPtr188(void * self_);  // 0x100529A0
XI_API void __thiscall GeneratorClone_SetLow2Bits17B(void * self_, uint32_t param_1);  // 0x100529B0
XI_API void __thiscall GeneratorClone_Set179Byte(void * self_, undefined4 param_1);  // 0x100529D0
XI_API void __thiscall GeneratorClone_SetFields300And130(void * self_, undefined4 param_1, undefined4 param_2);  // 0x100529E0
XI_API long double __thiscall GeneratorClone_GetFloat300(void * self_);  // 0x10052A00
XI_API void __thiscall GeneratorClone_Set172Short(void * self_, undefined4 param_1);  // 0x10052A10
XI_API void __thiscall GeneratorClone_Set120(void * self_, undefined4 param_1);  // 0x10052A20
XI_API void __thiscall GeneratorClone_Set124(void * self_, undefined4 param_1);  // 0x10052A30
XI_API long double __thiscall GeneratorClone_GetFloat120(void * self_);  // 0x10052A40
XI_API long double __thiscall GeneratorClone_GetFloat124(void * self_);  // 0x10052A50
XI_API undefined8 __cdecl GeneratorClone_AllocWithFallback(int param_1, int param_2);  // 0x10052A60
XI_API undefined4 __thiscall GeneratorClone_TestFn473F0(void * self_);  // 0x10052A80
XI_API int __thiscall GeneratorClone_HasFlags4And8(void * self_);  // 0x10052A90
XI_API undefined4 __thiscall GeneratorClone_Get9C(void * self_);  // 0x10052AB0
XI_API void __thiscall GeneratorClone_Set9C(void * self_, undefined4 param_1);  // 0x10052AC0
XI_API undefined4 __thiscall GeneratorClone_GetC4(void * self_);  // 0x10052AD0
XI_API int __thiscall GeneratorClone_GetPtrDE(void * self_);  // 0x10052AE0
XI_API undefined4 __thiscall GeneratorClone_IsA4NonZero(void * self_);  // 0x10052AF0
XI_API undefined4 __thiscall GeneratorClone_GetA4(void * self_);  // 0x10052B00
XI_API int __thiscall GeneratorClone_GetPtr78(void * self_);  // 0x10052B10
XI_API int __thiscall GeneratorClone_GetPtr84(void * self_);  // 0x10052B20
XI_API undefined4 __thiscall GeneratorClone_CopyF4Out(void * self_, undefined4 * param_1);  // 0x10052B30
XI_API void __thiscall GeneratorClone_Set0(void * self_, undefined4 param_1);  // 0x10052B40
XI_API void __thiscall GeneratorClone_Set4(void * self_, undefined4 param_1);  // 0x10052B50
XI_API void __thiscall GeneratorClone_Set8(void * self_, undefined4 param_1);  // 0x10052B60
XI_API void __thiscall GeneratorClone_SetFloat8FromRadians(void * self_, float param_1);  // 0x10052B70
XI_API void __thiscall GeneratorClone_SetFloat8FromByte(void * self_, int param_1);  // 0x10052B80
XI_API void __thiscall GeneratorClone_SetFloat8Scaled120(void * self_, float param_1);  // 0x10052B90
XI_API void __thiscall GeneratorClone_SetField8Dword(void * self_, undefined4 param_1);  // 0x10052BA0
XI_API void __thiscall GeneratorClone_Set46Short(void * self_, undefined4 param_1);  // 0x10052BB0
XI_API long double __cdecl DistInit_ReturnOne(void);  // 0x10052D20
XI_API undefined4 __thiscall DistInit_ReturnSelf(void * self_);  // 0x10052D30
XI_API void __thiscall ElemCtor471011C8_Set194(void * self_, undefined4 param_1);  // 0x10052E80
XI_API void __thiscall ElemFields194_SetField19C(void * self_, undefined4 param_1);  // 0x10053080
XI_API void __thiscall ElemFields194_SetField1A0(void * self_, undefined4 param_1);  // 0x10053090
XI_API long double __thiscall ElemFields194_GetFloat19C(void * self_);  // 0x100530A0
XI_API long double __thiscall ElemFields194_GetFloat1A0(void * self_);  // 0x100530B0
XI_API undefined4 __thiscall ElemFields194_GetDword194(void * self_);  // 0x100530C0
XI_API void __thiscall ElemFields194_SetField1A4(void * self_, undefined4 param_1);  // 0x100530D0
XI_API void __thiscall ElemFields194_SetField1A8(void * self_, undefined4 param_1);  // 0x100530E0
XI_API undefined4 __thiscall SharedConditionalStateReset(void * self_);  // 0x100531D0
XI_API undefined4 __attribute__((stdcall, regparm(3))) Generator_ClearSubobjectOrSetFlag(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, undefined4 param_2);  // 0x10053890
XI_API undefined4 __attribute__((stdcall, regparm(3))) YmGenerater_Stop(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, undefined4 * param_2);  // 0x100538E0
XI_API undefined4 __thiscall Generator_IsFlag400OrField22Zero(void * self_);  // 0x100539E0
XI_API undefined4 __thiscall Generator_StopGenerators(void * self_, int param_1, int param_2, undefined4 param_3, undefined4 * param_4);  // 0x10053A00
XI_API undefined4 __thiscall YmGenerater_UpdateAttach(void * self_, int param_1, float * param_2);  // 0x10053C80
XI_API undefined4 __attribute__((stdcall, regparm(3))) YmGenerater_UpdateAttachIfPresent(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, int param_2);  // 0x10053DD0
XI_API undefined4 __cdecl GeneratorRelease_Get10353710(void);  // 0x10054410
XI_API void __cdecl GeneratorRelease_CopyFromPtr(undefined4 * param_1, undefined4 * param_2);  // 0x10054430
XI_API long double __thiscall ElemCurve_EvaluateWithFlag34(void * self_, undefined4 param_2, undefined4 param_3);  // 0x100544D0
XI_API long double __thiscall ElemCurve_Evaluate(void * self_, float param_2);  // 0x10054500
XI_API long double __thiscall ElemCurve_EvaluateEaseIn(void * self_, float param_2, undefined4 param_3);  // 0x100546F0
XI_API long double __thiscall ElemCurve_EvaluateEaseInOut(void * self_, float param_2);  // 0x100547A0
XI_API char __cdecl BeginEffectOffscreenPass(void);  // 0x10054D70
XI_API float * __stdcall EndEffectOffscreenPass(float *a1, int a2);  // 0x10054F80
XI_API void __thiscall EffectOffscreen_Init(void * self_);  // 0x10054FC0
XI_API void __attribute__((stdcall, regparm(3))) EffectOffscreen_FreeSplineSet(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x100550F0
XI_API void __thiscall LinkNode_Init(void * self_);  // 0x10055240
XI_API void __thiscall OtLink_ClearLink(void * self_);  // 0x100552F0
XI_API void __thiscall OtLink_Init(void * self_, int param_1, float param_2, float param_3);  // 0x10055300
XI_API undefined4 __thiscall OtLink_RelinkEntries(void * self_);  // 0x100554B0
XI_API void __thiscall OtLink_Free(void * self_);  // 0x10055520
XI_API void __cdecl CMoOt_InitSystem(void);  // 0x100555D0
XI_API void __cdecl CMoOt_Update(void);  // 0x10055620
XI_API long double __thiscall RabRes_MinOf10055F60OverIndexPairs(void * self_, undefined4 * param_2, float * param_3);  // 0x10056160
XI_API char ** __cdecl CMoRabRes_GetRuntimeClass(void);  // 0x10056260
XI_API undefined4 __thiscall CMoResource_CopyHeaderAndBodyThenReset(void * self_, undefined4 * param_1);  // 0x100569D0
XI_API void __thiscall Scheduler_AddTask(void * self_);  // 0x10056AA0
XI_API int __thiscall Scheduler_CreateTask(void * self_, int param_1, int param_2, undefined4 param_3, undefined4 param_4);  // 0x10056CE0
XI_API void __thiscall Scheduler_RemoveTasksFor(void * self_);  // 0x10056EB0
XI_API undefined4 __thiscall Scheduler_Kill(void * self_, int param_1, int param_2);  // 0x10056EF0
XI_API undefined4 __thiscall Scheduler_IsMoving(void * self_, int param_1, int param_2);  // 0x10057010
XI_API void __thiscall CMoSchedularTask_ResetFlags(void * self_);  // 0x100573B0
XI_API undefined4 __thiscall SchedularOps_ClearDword0(void * self_, undefined4 xi_s1);  // 0x1005E110
XI_API undefined8 __thiscall AfterimageTask_FindFirstKind(void * self_);  // 0x10062770
XI_API undefined8 __thiscall Scheduler_ResolveOwner(void * self_);  // 0x100627D0
XI_API void __thiscall AfterimageTask_SetCaster(void * self_, int param_1);  // 0x10062830
XI_API void __thiscall AfterimageTask_SetTarget(void * self_, int param_1);  // 0x10062880
XI_API undefined8 __cdecl AfterimageTask_Execute(undefined4 * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5);  // 0x10062E20
XI_API undefined8 __cdecl AfterimageTask_Kill(undefined4 param_1, undefined4 param_2, int param_3, int param_4);  // 0x10062E80
XI_API undefined4 __cdecl AfterimageTask_IsResourceMoving(undefined4 * param_1, undefined4 param_2, int param_3, int param_4);  // 0x10062ED0
XI_API undefined4 __thiscall CMoSpline_Construct(void * self_);  // 0x10063460
XI_API long double __attribute__((stdcall, regparm(3))) CMoSpline_EvalCubicSegment(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, float param_2, int param_3);  // 0x10063890
XI_API int __thiscall YmElem_ForEachInstance(__int16 *self_, void (__cdecl *a2)(int, float *, int), int a3);  // 0x10063C80
XI_API void __thiscall ScriptMacro_SetDwordValue(void * self_, undefined4 xi_s1);  // 0x100684F0
XI_API void __thiscall ScriptMacro_AssignTyped(void * self_, undefined4 * param_1, undefined4 param_2);  // 0x10068590
XI_API void __cdecl MoDX_Nop(void);  // 0x10069E90
XI_API void __thiscall MoDX_ClearByteTables(void * self_);  // 0x10069EA0
XI_API void __thiscall MoDX_Update(void * self_);  // 0x10069F90
XI_API unsigned int __stdcall Gfx_CreateVertexBuffer(unsigned int a1, int a2, int a3, int a4);  // 0x1006A020
XI_API undefined4 __thiscall Camera_SetupMatrices(void * self_, undefined4 xi_s1, undefined4 xi_s2, undefined4 xi_s3, undefined4 xi_s4);  // 0x1006A180
XI_API void __thiscall Dx_GetCachedTransform2(void * self_, undefined4 * param_1);  // 0x1006A540
XI_API int __cdecl Gfx_CalcFVFStride(uint32_t param_1);  // 0x1006A560
XI_API int __thiscall Batch_DrawPrimitives(_DWORD *self_, int arg0);  // 0x1006AA30
XI_API void __cdecl Attach_SetTranslation(int param_1, undefined4 * param_2);  // 0x1006AD30
XI_API int __cdecl Processor_ApplyPair(int param_1, int param_2);  // 0x1006AD50
XI_API void __thiscall MoDX_SetInvalid(void * self_);  // 0x1006AD90
XI_API void __thiscall MoDX_Insert(void * self_);  // 0x1006ADF0
XI_API int __thiscall StateBlockHolder_ApplyRenderStates(_DWORD *self_, int *a2);  // 0x1006AF00
XI_API int __thiscall StateBlock_ApplyTSS(void *self_, int a1);  // 0x1006AF90
XI_API void * __thiscall VBPool_Constructor(void * self_);  // 0x1006B0C0
XI_API uint32_t __thiscall VBPool_Insert(void * self_, undefined4 * param_1);  // 0x1006B120
XI_API int __thiscall VBPool_FindMatch(void * self_, int param_1);  // 0x1006B1D0
XI_API void __cdecl Rand_SeedMT19937(uint32_t param_1);  // 0x1006BD90
XI_API uint32_t __cdecl RandAndHeader_Next(void);  // 0x1006BE20
XI_API int __cdecl Rand_NextMod(int param_1);  // 0x1006BF40
XI_API uint32_t __cdecl Rand_NextModUnsigned(uint32_t param_1);  // 0x1006BF60
XI_API long double __attribute__((cdecl, regparm(1))) Rand_UniformTimes(undefined4 xi_eax, float param_1);  // 0x1006BF80
XI_API long double __attribute__((cdecl, regparm(1))) Rand_SignedUniformTimes(undefined4 xi_eax, float param_1);  // 0x1006BFD0
XI_API int __cdecl Mem_AllocWithHeader12(int param_1, undefined4 param_2);  // 0x1006C0F0
XI_API void __thiscall j_OcclusionMng_CreateTarget(void * self_);  // 0x1006C210
XI_API void __thiscall OcclusionQuery_Init(void * self_);  // 0x1006C260
XI_API int __thiscall Occlusion_QueryScreenRect(__int16 *self_, float *a2, int a3, int a4, int a5, int a6, int a7, int a8, char a9, int a10);  // 0x1006C280
XI_API int __thiscall Occlusion_QueryScreenRectImpl(__int16 *self_, float *arg0, int a2, int a5, int a6, int a7, int a8, int _60, char a9, int a10);  // 0x1006C300
XI_API int __stdcall Occlusion_DrawQuery(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);  // 0x1006C530
XI_API int __thiscall Occlusion_ReadbackCount(__int16 *self_, char a2);  // 0x1006C8B0
XI_API int __thiscall OcclusionMng_Prepare(_DWORD *self_);  // 0x1006C9B0
XI_API undefined4 __cdecl Occlusion_IsFloatClassAccepted(float param_1);  // 0x1006CA20
XI_API undefined4 __cdecl Occlusion_AreAll16FloatsAccepted(undefined4 * param_1);  // 0x1006CA60
XI_API void __attribute__((stdcall, regparm(3))) CreateProcessorInstance(uint32_t xi_eax_unused, undefined4 xi_edx, undefined4 xi_ecx);  // 0x1006CB50
XI_API undefined4 __attribute__((stdcall, regparm(1))) CMoProcessor_VT_1032C368_SetIdentity(undefined4 xi_eax, undefined4 * param_1);  // 0x1006D0A0
XI_API void __stdcall ProcessorMatrix_InvertMat4InPlace(float * param_1);  // 0x1006D190
XI_API void __stdcall ProcessorMatrix_MultiplyTo(float * param_1, int param_2, float * param_3);  // 0x1006D270
XI_API undefined4 __thiscall ProcessorRotation_MakeFromAngles(void * self_, undefined4 param_1, float * param_2);  // 0x1006D9C0
XI_API void __thiscall Processor_InitIdentityMatrices(void * self_);  // 0x1006EF70
XI_API float * __thiscall Mat4x4_SafeTranspose(void * self_, float * param_1, undefined4 param_2, float * param_3);  // 0x1006F0A0
XI_API void __thiscall ProcessorInit_InitMatrices(void * self_);  // 0x100700E0
XI_API undefined4 __thiscall ResHandle_FreeIfUnreferenced(void * self_);  // 0x10071050
XI_API undefined4 __thiscall ResourceHandle_IsResident(void * self_);  // 0x10071060
XI_API void __thiscall MeshResourceCreate_Create(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);  // 0x100710F0
XI_API void __thiscall MeshResourceCreate_Reset(void * self_);  // 0x100711B0
XI_API void __thiscall MeshResourceCreate_CopyField14At0(void * self_, int param_1);  // 0x100711D0
XI_API void __thiscall MeshResourceCreate_CopyField14At4(void * self_, int param_1);  // 0x100711E0
XI_API void __thiscall MeshResourceCreate_CopyField14At8(void * self_, int param_1);  // 0x10071200
XI_API int * __thiscall MeshResourceMng_CreateResourceByKind(void * self_, undefined4 xi_s1);  // 0x10071270
XI_API undefined4 * __attribute__((stdcall, regparm(3))) CMoResource_ConstructBase(uint32_t xi_eax_unused, undefined4 xi_edx, undefined4 * param_1);  // 0x10071D80
XI_API undefined4 __thiscall CMoResource_CopyBodyTo20(void * self_, undefined4 * param_1);  // 0x10071E00
XI_API undefined4 __thiscall MoRes_FindPrevious(void * self_);  // 0x10071FD0
XI_API undefined4 __thiscall WeatherRes_GetTimeKey(void * self_, undefined4 * param_1);  // 0x10072180
XI_API undefined4 __attribute__((stdcall, regparm(3))) CMoResource_Destroy(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x100721F0
XI_API void * __thiscall Resource_FindSelfLinkedNode(void * self_);  // 0x10072240
XI_API undefined4 __attribute__((stdcall, regparm(1))) CMoResource_FindInScope(undefined4 xi_eax, undefined4 * param_1, int param_2, uint32_t param_3, int param_4);  // 0x10072430
XI_API undefined4 __attribute__((stdcall, regparm(3))) YmResourceFile_FindResourceUnder(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, undefined4 * param_2, uint32_t param_3, int param_4);  // 0x100724C0
XI_API undefined4 __attribute__((stdcall, regparm(3))) Resource_FindInChainByKind(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, uint32_t param_2, int param_3, undefined * param_4, undefined4 param_5);  // 0x10072540
XI_API void __attribute__((stdcall, regparm(3))) Resource_InitFieldsTakeFlag1047D12C(uint32_t xi_eax_unused, undefined4 xi_edx, int param_1);  // 0x10072990
XI_API void __cdecl unknown_libname_61(void);  // 0x100729C0
XI_API void __cdecl Resource_ClearGlobal1047D138(void);  // 0x100729D0
XI_API void __thiscall ResourceLoadTask_Step(void * self_);  // 0x10072A70
XI_API undefined8 __thiscall ResourceLoadTask_Start(void * self_, undefined4 * param_1, undefined4 param_2);  // 0x10072C30
XI_API void __thiscall MeshResourceMng_LoadSystemResources(void * self_, undefined4 * param_1);  // 0x10072ED0
XI_API undefined4 __stdcall ResourceHandle_Deref(undefined4 * param_1);  // 0x10072FB0
XI_API undefined4 __thiscall MeshResourceMng_ResolveTree(void * self_, int * param_1, void * param_2, undefined4 * param_3);  // 0x10073430
XI_API undefined4 __stdcall MoRes_FreeIfUnreferenced(int * param_1);  // 0x10073B20
XI_API undefined4 __stdcall ResourceIter_FindById(undefined4 * param_1, int param_2, int param_3);  // 0x10073BA0
XI_API void __stdcall ResourceIter_FindOrStartTask(undefined4 * param_1, int param_2, undefined4 param_3);  // 0x10073D80
XI_API undefined4 __thiscall MeshResourceMng_Evict(void * self_);  // 0x100740C0
XI_API undefined8 __thiscall ResourceIter_PopFreeNode(void * self_, undefined4 * param_1);  // 0x10074110
XI_API void __thiscall MeshResourceMng_AllocHandle(void * self_, int * param_1, int param_2);  // 0x10074140
XI_API undefined4 __thiscall NodePool_ReleaseNode(void * self_, uint32_t * param_1);  // 0x10074180
XI_API undefined4 __thiscall ResourceIter_InPoolRange(void * self_, undefined4 * param_1);  // 0x100741E0
XI_API void __cdecl ResourceIter_SetCurrentGlobal(undefined4 param_1);  // 0x10074280
XI_API void __thiscall ResourceIter_FindFirst(void * self_, int param_1, int param_2, uint32_t param_3, uint32_t param_4);  // 0x100742B0
XI_API void __thiscall ResourceIter_Start(void * self_, undefined4 param_1, int param_2, uint32_t param_3, uint32_t param_4);  // 0x10074310
XI_API uint32_t __thiscall ResourceIter_MatchCurrent(void * self_);  // 0x10074380
XI_API void __thiscall ResourceIter_Advance(void * self_);  // 0x100743D0
XI_API undefined4 __thiscall ResourceIter_FindNext(void * self_, undefined4 xi_s1);  // 0x100745C0
XI_API void __thiscall MoProcessor_CallVSlot49(void * self_);  // 0x100746A0
XI_API void __thiscall ProcessorSlot_ProcessorSlot41(void * self_);  // 0x10074700
XI_API void __thiscall Task_Remove(void * self_, int param_1);  // 0x100747F0
XI_API void __thiscall Task_RunAsCurrent(void * self_);  // 0x100748C0
XI_API int __thiscall TaskAndTextArgs_FindTask(void * self_, int param_1, int param_2);  // 0x10074F30
XI_API int __cdecl Gfx_InitCubeMapTextures(void);  // 0x10075280
XI_API undefined4 __thiscall TexRef_ResolveByName(void * self_, undefined4 param_1);  // 0x10075520
XI_API void __thiscall TexRef_EnsureRenderTarget(int *self_);  // 0x100755A0
XI_API int __thiscall TextureHolder_BindWarped(int *self_, int a2, float a3, float a4, float a5);  // 0x10075700
XI_API int __thiscall TexRef_SetTexture(int *self_, int a2);  // 0x10075960
XI_API int __thiscall TextureHolder_BindTinted(int *self_, int a2, int a3);  // 0x100759C0
XI_API int __cdecl Arg_SplitQuoted(char * param_1, char * param_2, undefined4 * param_3, undefined4 * param_4, int param_5, undefined4 param_6);  // 0x10076830
XI_API int __cdecl Arg_CopyCharOrPair(char * param_1, char * param_2, int param_3);  // 0x100769F0
XI_API char * __cdecl Arg_StripQuotes(char * param_1);  // 0x10076A70
XI_API int __cdecl preprocessArg(char * param_1, char * param_2, int param_3);  // 0x10076AB0
XI_API uint8_t * __cdecl Arg_FindInSortedTable(uint8_t * param_1, uint8_t * param_2);  // 0x10077AD0
XI_API undefined4 __cdecl Arg_LookupWord(undefined4 param_1, char * param_2);  // 0x10077B40
XI_API undefined4 __cdecl TaskAndTextArgs_MapNameLetters(uint8_t * param_1);  // 0x10077C30
XI_API void __cdecl Acter_CopyNameToBuffer(int * param_1);  // 0x10077CF0
XI_API undefined4 * __cdecl Acter_GetCurrentIdRef(void);  // 0x10077D40
XI_API void __cdecl Acter_ClearCurrentName(void);  // 0x10077D70
XI_API undefined4 __cdecl Acter_FindMatchingActor(void);  // 0x10077D80
XI_API undefined4 __cdecl ChatLog_AddFormattedMessage(undefined4 param_1, undefined4 xi_s2);  // 0x10077E30
XI_API void __cdecl TaskAndTextArgs_ToggleOnKey(void);  // 0x10077FB0
XI_API int __cdecl TextCommand_ParseOnOff(uint8_t * param_1);  // 0x10079170
XI_API int __cdecl TextCommand_ParseNumber(char * param_1);  // 0x10079A00
XI_API int * __cdecl SeekIdByString(char * param_1, undefined4 param_2, int param_3, undefined4 param_4);  // 0x1007A1C0
XI_API int __cdecl Actor_FindInRange(int param_1, int param_2, int param_3);  // 0x1007A440
XI_API int __cdecl Actor_FindByName(char * param_1, uint32_t param_2, int param_3, int param_4, undefined4 param_5);  // 0x1007A4C0
XI_API int __cdecl fn_1007A9A0(undefined4 param_1, undefined4 param_2, int param_3);  // 0x1007A9A0
XI_API int __cdecl fn_1007AA80(undefined4 param_1, undefined4 param_2, int param_3);  // 0x1007AA80
XI_API int __cdecl fn_1007BB90(undefined4 param_1, undefined4 param_2, int param_3);  // 0x1007BB90
XI_API undefined4 __cdecl fn_1007BF30(uint32_t * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5);  // 0x1007BF30
XI_API undefined4 __cdecl UI_QuestCommand(undefined4 param_1, undefined4 param_2, undefined4 param_3);  // 0x1007D240
XI_API int __cdecl fn_1007E490(undefined4 param_1, undefined4 param_2, int param_3);  // 0x1007E490
XI_API int __cdecl TextCommand_ChangeMyroomMode2(undefined4 param_1, undefined4 param_2, int param_3);  // 0x1007E8D0
XI_API undefined4 __cdecl TextCommand_Run100A3040(undefined4 param_1, undefined4 param_2, undefined4 param_3);  // 0x10080340
XI_API undefined4 __cdecl Actor_GetObjectByName(char * param_1);  // 0x10080C70
XI_API undefined4 __attribute__((cdecl, regparm(1))) TextCommand_GetWord1047D3FC(undefined4 xi_eax);  // 0x10080D00
XI_API undefined4 __cdecl TextCommand_IsIdNotInTable10357BB8(int param_1);  // 0x10080D20
XI_API uint32_t __cdecl Actor_IsInTable(int param_1);  // 0x10080D90
XI_API int __cdecl Command_RunLine(char * param_1, undefined4 param_2);  // 0x10080DC0
XI_API undefined4 __attribute__((cdecl, regparm(1))) TextCommand_CheckCommandAllowed(undefined4 xi_eax, int param_1);  // 0x10081230
XI_API void __cdecl TextCommand_SetFlag1047D498(undefined4 param_1);  // 0x10081440
XI_API undefined4 __cdecl TextCommand_TestBit1047D499(undefined4 param_1);  // 0x10081480
XI_API void __thiscall ActorHandle_Constructor(void * self_);  // 0x100814A0
XI_API void __thiscall ActorHandle_Destructor(void * self_);  // 0x100814E0
XI_API undefined4 __thiscall ActorHandle_SetFields(void * self_, undefined4 param_1, undefined4 param_2);  // 0x10081530
XI_API undefined4 __thiscall ActorHandle_ResolveObject(void * self_);  // 0x10081600
XI_API void __cdecl ActorBase_ReleaseQueued(void);  // 0x10081A30
XI_API void __cdecl Actor_ResetDrawLists(void);  // 0x10081A50
XI_API undefined4 __attribute__((stdcall, regparm(3))) CXiActor_LinkIntoDrawList(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x10081AE0
XI_API void __thiscall CXiSkeletonActor_SetMoveSpeed(void * self_, undefined4 param_1);  // 0x10082080
XI_API void __thiscall CXiSkeletonActor_SetMoveSpeedBase(void * self_, undefined4 param_1);  // 0x100820A0
XI_API void __thiscall CXiSkeletonActor_SetWalkSpeed(void * self_, undefined4 param_1);  // 0x100820C0
XI_API int __thiscall GetEmbeddedMember_0x34(void * self_);  // 0x100820E0
XI_API int __thiscall GetEmbeddedMember_0x44(void * self_);  // 0x100820F0
XI_API void __thiscall CXiActor_GetModel(void * self_, undefined4 * param_1);  // 0x10082200
XI_API undefined4 __thiscall CXiActor_GetFieldA8(void * self_);  // 0x10082380
XI_API void __thiscall CXiActor_Slot154ForwardTo5C(void * self_, undefined4 xi_s1);  // 0x10082460
XI_API undefined4 __thiscall CXiActor_GetSubActorStatus(void * self_);  // 0x10082780
XI_API void __thiscall CXiActor_SetSubActorStatus(void * self_, undefined4 param_1);  // 0x10082790
XI_API int __cdecl Actor_CountAll(void);  // 0x10082BF0
XI_API undefined4 __stdcall ActorName_ProjectThroughCamera(undefined4 * param_1, undefined4 * param_2);  // 0x10082FB0
XI_API uint32_t __thiscall ActorModelFlag_GetModelFlag130Bit21(void * self_);  // 0x10083340
XI_API int * __cdecl Target_FindNearestOnLocalPositiveX(undefined4 param_1, undefined4 param_2);  // 0x10083620
XI_API uint32_t __attribute__((stdcall, regparm(3))) CXiActor_ModelTest95790(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, int param_2);  // 0x10084330
XI_API undefined4 __attribute__((stdcall, regparm(3))) CXiActor_ModelTest95680(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, int param_2);  // 0x10084350
XI_API undefined4 __attribute__((stdcall, regparm(3))) CXiActor_ModelTest956A0(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, int param_2);  // 0x10084370
XI_API void __thiscall CXiActor_SetField0B4(void * self_, undefined4 param_1);  // 0x10085010
XI_API uint32_t __thiscall CXiActor_GetField88Bit3(void * self_);  // 0x10085500
XI_API void __thiscall CXiActor_SetField0BC(void * self_, undefined4 param_1);  // 0x10085BF0
XI_API undefined4 __attribute__((stdcall, regparm(3))) CXiAtelActor_UnlinkCasterAttachments(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, int param_2);  // 0x10085C90
XI_API undefined4 __attribute__((stdcall, regparm(3))) CXiAtelActor_UnlinkTargetAttachments(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, int param_2);  // 0x10085CF0
XI_API void __cdecl Actor_DrawWorldText(_DWORD *a1, const char *a2, float a3, unsigned int a4, int a5);  // 0x10086210
XI_API undefined4 __attribute__((cdecl, regparm(1))) Acter_IsParamBelow901(undefined4 xi_eax, uint32_t param_1);  // 0x10086FC0
XI_API uint32_t __cdecl Acter_FindByField78Fwd(int param_1);  // 0x10086FD0
XI_API undefined8 __cdecl ActerBuff_FindByField78(int param_1);  // 0x10086FE0
XI_API uint32_t __cdecl Acter_GetGlobalFlag(void);  // 0x10087010
XI_API undefined4 __attribute__((cdecl, regparm(1))) Acter_IsEvent(undefined4 xi_eax);  // 0x10087060
XI_API uint32_t __attribute__((cdecl, regparm(1))) IsEvent(undefined4 xi_eax, undefined4 param_1);  // 0x10087070
XI_API undefined4 __cdecl Menu_HasAnyFlag(undefined4 param_1, undefined4 param_2);  // 0x100870E0
XI_API undefined4 __attribute__((cdecl, regparm(1))) Acter_GetGlobalByte(undefined4 xi_eax);  // 0x10087110
XI_API undefined4 __cdecl Help_UpdateFromFlags(void);  // 0x100872C0
XI_API void __attribute__((cdecl, regparm(1))) Acter_UpdateObject10578184(undefined4 xi_eax);  // 0x100873B0
XI_API void __cdecl Acter_TargetClearAndSetFlag53(void);  // 0x100875C0
XI_API uint32_t __cdecl Acter_IsIdMatchGlobal(void);  // 0x100875D0
XI_API undefined4 __cdecl Acter_GetByteIfIdMatch(void);  // 0x100875F0
XI_API uint32_t __cdecl Acter_GetDwordIfIdMatch(void);  // 0x10087610
XI_API uint32_t __cdecl Acter_GetGlobal10482F38IfIdMatch(void);  // 0x10087630
XI_API undefined4 __attribute__((cdecl, regparm(1))) Acter_IsWord104802BASet(undefined4 xi_eax);  // 0x10087650
XI_API undefined4 __attribute__((cdecl, regparm(1))) Acter_GetMaskedFlagByte(undefined4 xi_eax);  // 0x10087660
XI_API undefined4 __cdecl Acter_IsGlobalNonzero(void);  // 0x10087670
XI_API uint32_t __attribute__((cdecl, regparm(1))) Acter_GetDword10480800IfFlag(undefined4 xi_eax);  // 0x10087690
XI_API uint32_t __attribute__((cdecl, regparm(1))) Acter_GetByte10480824IfFlag(undefined4 xi_eax);  // 0x100876B0
XI_API uint32_t __attribute__((cdecl, regparm(1))) Acter_GetTable10480828IfFlag(undefined4 xi_eax);  // 0x10087760
XI_API undefined4 __cdecl Acter_GetByte10480825IfSet(void);  // 0x10087830
XI_API undefined4 __attribute__((cdecl, regparm(1))) Acter_GetByte10480826IfFlag(undefined4 xi_eax);  // 0x10087890
XI_API undefined4 __attribute__((cdecl, regparm(1))) Acter_IsByte10483158Set(undefined4 xi_eax);  // 0x10087B20
XI_API void __thiscall Acter_ApplyPair1EC1F4(void * self_);  // 0x10087D40
XI_API undefined4 __thiscall Acter_ResetMotionCounters(void * self_);  // 0x10087E40
XI_API void __thiscall Acter_AdvanceMotionTimer(void * self_);  // 0x10087E80
XI_API void __thiscall Acter_UpdateModelPoint848(void * self_);  // 0x10087F00
XI_API void __thiscall Acter_UpdateByKind170NotGroup38(void * self_);  // 0x100883E0
XI_API void __thiscall Acter_UpdateByKind170NotGroup06(void * self_);  // 0x10089100
XI_API void __cdecl Call1008A0E0With2(void);  // 0x1008A0D0
XI_API undefined4 __cdecl Camera_SetField30(int param_1);  // 0x1008A0E0
XI_API void __thiscall Actor_SetDefaultMotionTags(void * self_);  // 0x1008A160
XI_API int __cdecl ActerBuff_FindByMaskedId(uint32_t param_1);  // 0x1008A8E0
XI_API int __cdecl ActerBuff_FindById(int param_1);  // 0x1008A930
XI_API void __thiscall Acter_StartAutoRunFromZoneMap(void * self_);  // 0x1008B100
XI_API int __thiscall Actor_FindByNameEntry(void * self_, uint8_t * param_1, undefined4 param_2);  // 0x1008B270
XI_API uint32_t __cdecl Actor_CompareNames(uint8_t * param_1, uint8_t * param_2, undefined4 param_3);  // 0x1008B2B0
XI_API int __thiscall Actor_FindByField78Entry(void * self_, int param_1);  // 0x1008B380
XI_API void __thiscall Acter_UpdateOnePart1008CD90(void * self_);  // 0x1008CD90
XI_API void __thiscall Acter_SetModelField78FromTable(void * self_);  // 0x1008DB40
XI_API undefined4 __attribute__((stdcall, regparm(3))) CXiActor_IsIdAbove6ff(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x1008E130
XI_API undefined4 __thiscall Acter_GetActerAt2A4(void * self_);  // 0x1008E220
XI_API undefined4 __thiscall Actor_FindByField2a4(void * self_);  // 0x1008E260
XI_API void __thiscall Acter_UpdateFlags120Bit23(void * self_);  // 0x1008E4D0
XI_API void __thiscall Acter_PlayChorMotion(void * self_);  // 0x1008E740
XI_API uint32_t __thiscall Acter_IsBytes1FFBothIn89NotEqual(void * self_, int param_1);  // 0x1008E8D0
XI_API undefined4 __thiscall Acter_UpdateOne(void * self_);  // 0x1008E9A0
XI_API void __thiscall Acter_ReleaseEventRecord(void * self_);  // 0x1008EE30
XI_API void __thiscall Acter_CallVt180IfState(void * self_);  // 0x1008F2A0
XI_API void __thiscall Acter_ReleaseSlotD0(void * self_);  // 0x100926C0
XI_API void __thiscall Acter_ReleaseSlotCC(void * self_);  // 0x10092710
XI_API void __thiscall Acter_ReleaseTenSlots(void * self_);  // 0x10092760
XI_API void __thiscall Acter_ReleaseSlotByIndex(void * self_, int param_1);  // 0x10092780
XI_API void __thiscall Acter_ReleaseSlotA8(void * self_);  // 0x10092800
XI_API void __thiscall Acter_ReleaseSlotA4(void * self_);  // 0x10092870
XI_API void __thiscall Acter_ReleaseAllSlots(void * self_);  // 0x10092900
XI_API void __thiscall Acter_CopyPosToCached(void * self_);  // 0x100929A0
XI_API void __thiscall Acter_SnapHeightToZoneMap(void * self_);  // 0x100929D0
XI_API undefined4 __thiscall Acter_CopyPosAndAnglesToActorA0(void * self_);  // 0x10092C20
XI_API void __thiscall Acter_CopyPosAndSnap(void * self_);  // 0x100933C0
XI_API undefined4 __thiscall Acter_CopySixDwordsTo7C(void * self_, undefined4 * param_1);  // 0x10093430
XI_API undefined4 __cdecl Acter_ResetGlobals(void);  // 0x10093720
XI_API void __cdecl Acter_ClearGlobalBlocks(void);  // 0x10093A30
XI_API void __cdecl Acter_ResetGlobalSentinels(void);  // 0x10093A90
XI_API void __cdecl Acter_ClearGlobalBlock182(void);  // 0x10093AD0
XI_API void __cdecl Acter_ClearGlobalBlock2C(void);  // 0x10093AF0
XI_API void __cdecl Acter_ClearGlobalBlock23(void);  // 0x10093B10
XI_API void __cdecl Acter_ClearGlobalBlock71(void);  // 0x10093B30
XI_API undefined4 __cdecl Acter_ClearTable10488B08(void);  // 0x10093B50
XI_API undefined4 __cdecl Acter_ShutdownGlobals(void);  // 0x10093B70
XI_API void __cdecl Acter_Nop(void);  // 0x10093DA0
XI_API undefined4 __attribute__((cdecl, regparm(1))) CallMotd(undefined4 xi_eax);  // 0x100955D0
XI_API undefined4 __thiscall Acter_IsState5(void * self_, int param_1);  // 0x10095680
XI_API undefined4 __thiscall Acter_IsState55(void * self_, int param_1);  // 0x100956A0
XI_API undefined4 __thiscall Acter_IsStateGroup06Or38(void * self_, undefined4 xi_s1);  // 0x100956C0
XI_API undefined4 __thiscall Acter_IsStateGroup06(void * self_, int param_1);  // 0x100956F0
XI_API undefined4 __thiscall Acter_IsStateGroup38(void * self_, int param_1);  // 0x10095750
XI_API int __thiscall Acter_IsStateGroup3F(void * self_, int param_1);  // 0x10095790
XI_API uint32_t __thiscall Acter_CanClearPendingState(void * self_);  // 0x10095850
XI_API void __cdecl Acter_UpdateAllLists(void);  // 0x10095900
XI_API void __cdecl Acter_ClearPendingState(void * param_1);  // 0x10095DD0
XI_API void __cdecl Acter_ClearPending272(void * param_1);  // 0x10095E30
XI_API void __cdecl Acter_UpdateActionState(void * param_1);  // 0x10095E90
XI_API int __cdecl Acter_OffsetTableEntry(int param_1, undefined4 param_2);  // 0x10096220
XI_API uint32_t __cdecl Acter_OffsetTableLastIndex(int param_1);  // 0x10096250
XI_API undefined4 __cdecl Acter_NoneOfIdsInTable(void);  // 0x10096270
XI_API void __cdecl Acter_LookupTable10489908(undefined4 param_1);  // 0x100962C0
XI_API void __cdecl Acter_LookupTable10487E58(undefined4 param_1);  // 0x100962F0
XI_API void __cdecl Acter_LookupTable10487E64(undefined4 param_1);  // 0x10096350
XI_API void __cdecl Acter_LookupTable10487E68(undefined4 param_1);  // 0x10096380
XI_API void __cdecl Acter_LookupTable10487E70(undefined4 param_1);  // 0x100963B0
XI_API void __cdecl Acter_LookupTable10487E7C(undefined4 param_1);  // 0x100963E0
XI_API void __cdecl Acter_LookupTable10487E84(undefined4 param_1);  // 0x10096410
XI_API void __cdecl Acter_LookupTable10487E80(undefined4 param_1);  // 0x10096470
XI_API undefined4 __cdecl Acter_UpdateFrame(void);  // 0x10096640
XI_API undefined4 __thiscall Acter_UpdateSkeletonParts(void * self_);  // 0x100973F0
XI_API undefined4 __thiscall Acter_TestFlagsAndUpdateParts(void * self_);  // 0x100977F0
XI_API undefined1 * __thiscall Entity_BuildDisplayName(void * self_);  // 0x10097840
XI_API undefined4 __thiscall Entity_GetIndexedPtr(void * self_);  // 0x10097A40
XI_API undefined4 __cdecl Acter_HasEntryForWord40D7C(void);  // 0x10097B40
XI_API int __cdecl Acter_FindEntryForWord40D7C(void);  // 0x10097B50
XI_API undefined4 __cdecl Acter_GetByte40DB4ByKind(void);  // 0x10097BC0
XI_API undefined4 __cdecl Acter_IsFlag40DB6OrState17(void);  // 0x10097D50
XI_API undefined4 __cdecl Acter_TestFlagTable(int param_1, uint32_t param_2);  // 0x10097E50
XI_API undefined4 __cdecl Acter_TestFlagBit(int param_1);  // 0x10097E80
XI_API undefined4 __thiscall Acter_IsSpecialIdRange(void * self_);  // 0x10098180
XI_API undefined4 __thiscall Acter_ActerTestEE120(void * self_, undefined4 param_1);  // 0x10098210
XI_API uint32_t __thiscall Acter_GetPartnerIfKind(void * self_);  // 0x100983A0
XI_API uint32_t __attribute__((cdecl, regparm(1))) Acter_GetTable10485830IfBit2(undefined4 xi_eax);  // 0x100991F0
XI_API void __cdecl Acter_ResolveEntryNames(void);  // 0x10099730
XI_API void __cdecl Acter_UpdateFrame997B0(void);  // 0x100997B0
XI_API undefined4 __thiscall Acter_IsByte123Mask7In234(void * self_);  // 0x1009AAF0
XI_API undefined4 __thiscall Acter_IsByte123Low3Bits3(void * self_);  // 0x1009AB20
XI_API void __thiscall Acter_SetFieldsAt134And138(void * self_, uint32_t param_1, uint32_t param_2, uint32_t param_3, int param_4, int param_5, int param_6);  // 0x1009ADE0
XI_API long double __thiscall Acter_GetField138Clamped(void * self_);  // 0x1009AEC0
XI_API void __thiscall Acter_SetFlagBits138(void * self_, uint32_t param_1, uint32_t param_2, int param_3);  // 0x1009AF60
XI_API void __cdecl Acter_ClearGlobals10488800(void);  // 0x1009F3F0
XI_API undefined4 __attribute__((cdecl, regparm(1))) Acter_IndexIfMatchesKinds(undefined4 xi_eax, undefined4 param_1);  // 0x100A0010
XI_API undefined4 __cdecl Acter_FindFirstMatchingKinds(void);  // 0x100A0080
XI_API undefined1 * __cdecl Acter_FindStringById(int param_1);  // 0x100A1770
XI_API undefined4 __cdecl Acter_SetFlag8000OfFound(undefined4 param_1);  // 0x100A17F0
XI_API undefined4 __cdecl Acter_CheckIdAgainstBlockBits(undefined4 param_1);  // 0x100A19B0
XI_API undefined4 __cdecl Acter_MatchActorNameOrKind(uint8_t * param_1, undefined4 param_2, undefined4 param_3);  // 0x100A1A00
XI_API undefined1 * __cdecl ActerBuff_GetStringByIdLookup(int param_1);  // 0x100A1D50
XI_API void * __thiscall Acter_ConstructTask1032D6D4(void * self_, undefined4 param_1);  // 0x100A2790
XI_API undefined4 __thiscall AuctionMenu_ResetAndFillHeader(void * self_);  // 0x100A28E0
XI_API uint32_t __thiscall AuctionMenu_WriteHeader(void * self_, undefined1 * param_1, uint32_t param_2);  // 0x100A2B70
XI_API undefined4 __attribute__((cdecl, regparm(1))) AuctionMenu_InitRecord(undefined4 xi_eax, undefined1 * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 * param_5, uint32_t param_6);  // 0x100A2FD0
XI_API undefined4 __cdecl AuctionMenu_CreateTaskOnce(void);  // 0x100A3040
XI_API undefined4 __attribute__((cdecl, regparm(1))) AuctionMenu_GetSceneStateCode(undefined4 xi_eax);  // 0x100A30E0
XI_API void __cdecl AuctionMenu_ResetRecords(void);  // 0x100A3CD0
XI_API undefined4 __thiscall CXiControlActor_GetGroundMaterial(void * self_);  // 0x100A45D0
XI_API undefined1 __attribute__((stdcall, regparm(3))) CXiControlActor_IsFreeRun(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x100A4670
XI_API undefined1 __attribute__((stdcall, regparm(3))) CXiControlActor_IsWalkLock(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x100A4690
XI_API undefined1 __attribute__((stdcall, regparm(3))) CXiControlActor_IsParallelMove(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x100A46B0
XI_API undefined4 __thiscall CXiControlActor_IsControlLock(void * self_);  // 0x100A46C0
XI_API undefined1 __attribute__((stdcall, regparm(3))) CXiCollisionActor_IsTouchDown(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x100A46D0
XI_API undefined1 __attribute__((stdcall, regparm(3))) CXiCollisionActor_IsOnLift(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x100A46F0
XI_API undefined4 __thiscall CXiCollisionActor_GetCurrentAreaId(void * self_);  // 0x100A4710
XI_API undefined4 __attribute__((stdcall, regparm(3))) CXiSkeletonActor_IsReadComplete(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x100A47E0
XI_API undefined4 __thiscall CXiSkeletonActor_GetShadowAlpha(void * self_);  // 0x100A4890
XI_API undefined4 __thiscall CXiControlActor_SetVec4(void * self_, undefined4 * param_1);  // 0x100A57C0
XI_API undefined4 __cdecl XiControlActor_UpdateCamera(int * param_1);  // 0x100A5E10
XI_API void __thiscall ControlActorView_CallUnlessFlag(void * self_, float * param_1);  // 0x100A5EC0
XI_API undefined4 __thiscall XiControlActor_UpdateView(void * self_);  // 0x100A5EF0
XI_API undefined4 __attribute__((stdcall, regparm(1))) XiControlActor_SetAutoRunning(undefined4 xi_eax, undefined4 param_1);  // 0x100A6070
XI_API void __thiscall XiControlActor_NormalizeInput(void * self_, float * param_1, float * param_2, undefined4 xi_s3);  // 0x100A78D0
XI_API void __cdecl CXiControlActor_CallTargetSlot207With0(void);  // 0x100A8C20
XI_API void __cdecl CXiControlActor_CallTargetSlot207With1(void);  // 0x100A8C40
XI_API undefined4 __cdecl Acter_DestroyAndClearSlot(int param_1);  // 0x100AB320
XI_API void __cdecl FurnitureRelease_ReleaseSlot(int param_1);  // 0x100AB550
XI_API undefined4 __attribute__((stdcall, regparm(3))) CXiDancerActor_SetAnglesWrapped(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, undefined4 * param_2);  // 0x100AB880
XI_API void * __thiscall CopyPair_CopyFrom(void * self_, char * param_1, int param_2);  // 0x100ABC20
XI_API undefined4 __cdecl CopyPair_CopyReturnZ(undefined4 * param_1, undefined4 * param_2);  // 0x100ABC70
XI_API int __thiscall CXiDollActor_GetPtr404(void * self_);  // 0x100ABD90
XI_API int __thiscall CXiDollActor_GetPtr414(void * self_);  // 0x100ABDA0
XI_API long double __thiscall CXiDollActor_GetFloat434(void * self_);  // 0x100ABE30
XI_API long double __thiscall CXiDollActor_GetFloat438(void * self_);  // 0x100ABE40
XI_API undefined4 __thiscall CXiDollActor_GetVec4At104(void * self_, int param_1, undefined4 * param_2);  // 0x100ABFB0
XI_API void __cdecl XiDoorActor_NopSlot161(void);  // 0x100AC380
XI_API int __thiscall XiDoorActor_GetPtr5C4(void * self_);  // 0x100AC9C0
XI_API void __cdecl XiEvent_CreateAndAddIfListNotEmpty(undefined4 param_1, undefined4 * param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, char * param_7);  // 0x100AD660
XI_API void __cdecl XiEvent_Spawn(undefined4 param_1, undefined4 * param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, char * param_7, undefined4 param_8, undefined4 param_9);  // 0x100AD6D0
XI_API undefined4 __cdecl XiEvent_IsIdOutsideList(void);  // 0x100AD7C0
XI_API int __cdecl XiEvent_GetGlobalDword(void);  // 0x100AE350
XI_API void __cdecl XiEvent_ResetPending(void);  // 0x100AE3A0
XI_API undefined4 __cdecl XiEvent_ResetActersAndGlobals(void);  // 0x100AE3F0
XI_API undefined4 __cdecl _EventDataReadCallBack(undefined4 param_1, int param_2, undefined1 * param_3);  // 0x100AEC20
XI_API void __thiscall XiEvent_RestoreActer(void * self_);  // 0x100BD5F0
XI_API undefined * __cdecl XiEvent_GetSingleton(void);  // 0x100BD760
XI_API void * __thiscall XiEvent_Init(void * self_, undefined4 * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, char * param_5, undefined4 param_6, undefined4 param_7);  // 0x100C2E20
XI_API undefined4 __attribute__((stdcall, regparm(3))) XiEvent_GetWordBFE(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x100C3020
XI_API undefined4 __attribute__((stdcall, regparm(3))) XiEvent_GetWordC00(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x100C3030
XI_API void __thiscall XiEvent_FreeData(void * self_);  // 0x100C3050
XI_API void * __thiscall XiEvent_Init_100C3060(void * self_, undefined4 * param_1, undefined4 param_2, undefined2 * param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7, undefined4 param_8);  // 0x100C3060
XI_API undefined * __cdecl XiEvent_GetSingleton_100C3190(void);  // 0x100C3190
XI_API void __thiscall XiEvent_SetFlag8(void * self_);  // 0x100C3200
XI_API undefined4 __thiscall XiEvent_HasItems(void * self_);  // 0x100C3210
XI_API undefined4 __thiscall XiEvent_Clear(void * self_);  // 0x100C3220
XI_API void __thiscall XiEvent_Append(void * self_, int param_1);  // 0x100C3260
XI_API void __thiscall XiEvent_AddEvent(void * self_, undefined4 * param_1, void * param_2, undefined2 * param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6);  // 0x100C3300
XI_API undefined4 __thiscall XiEvent_StepTimedMessage(void * self_);  // 0x100C3480
XI_API int __thiscall XiModelActor_GetPtr734(void * self_);  // 0x100C3FB0
XI_API int __thiscall XiModelActor_GetPtr744(void * self_);  // 0x100C3FC0
XI_API void __thiscall ModelActorPosition_SetPosition(void * self_, undefined4 * param_1);  // 0x100C3FF0
XI_API void __thiscall ModelActorPosition_SetAnglesWrapped(void * self_, undefined4 * param_1);  // 0x100C4050
XI_API undefined4 __thiscall ModelActorDraw_GetVec3PairIfModel(void * self_, undefined4 * param_1, undefined4 * param_2);  // 0x100C4BC0
XI_API int __cdecl ModelCodeIndex_MapCodeIndex(undefined4 param_1, int param_2);  // 0x100C51C0
XI_API int __cdecl ModelCodeIndex_AddOffset996B(int param_1);  // 0x100C5260
XI_API int __cdecl ModelCodeIndex_AddOffset19131(int param_1);  // 0x100C5270
XI_API int __cdecl ModelCodeIndex_AddOffset1889B(int param_1);  // 0x100C5280
XI_API int __cdecl ModelCodeIndex_ForwardToCce00(int param_1);  // 0x100C5290
XI_API undefined4 __cdecl TargetActor_SlotHandler1(void);  // 0x100C5410
XI_API undefined4 __cdecl TargetActor_SlotHandler0(void);  // 0x100C5440
XI_API int __thiscall Actor_SelectNearestLights(void *self_);  // 0x100CB4E0
XI_API long double __thiscall CXiSkeletonActor_ComputeCameraFade(void * self_);  // 0x100CD040
XI_API void __attribute__((stdcall, regparm(3))) CXiSkeletonActor_DrawName2IfVisible(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, undefined4 * param_2, char * param_3, float param_4);  // 0x100D08B0
XI_API undefined4 __attribute__((stdcall, regparm(3))) CXiSkeletonActor_AttachPartResource(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, int param_2, int * param_3);  // 0x100D0D70
XI_API undefined4 __attribute__((stdcall, regparm(3))) CXiSkeletonActor_IsReadCompleteBody(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x100D12D0
XI_API undefined4 __thiscall ActorModelParts_ProcessResidentListEntries(void * self_, int * param_1, int param_2);  // 0x100D1450
XI_API undefined4 __attribute__((stdcall, regparm(3))) CXiSkeletonActor_ReleaseListEntriesMatching(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, int param_2);  // 0x100D44B0
XI_API undefined4 __attribute__((stdcall, regparm(3))) SkeletonActorState_SetFlag8ACBit1(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, undefined4 param_2);  // 0x100D6F50
XI_API int __cdecl NetCellFont_AddOne(int param_1);  // 0x100D7E90
XI_API undefined4 __thiscall Game_HasInitCount(void * self_);  // 0x100D9A70
XI_API undefined4 __cdecl NetCellFont_GetEntryMod1066268C(void);  // 0x100D9B00
XI_API uint32_t __thiscall Game_InitSceneState(void * self_);  // 0x100DA6A0
XI_API undefined4 __thiscall GameMode_GetField98(void * self_);  // 0x100DB100
XI_API int __thiscall GameMode_PollPendingState(void * self_);  // 0x100DB140
XI_API undefined4 __thiscall GameMode_RequestState(void * self_, undefined4 param_1, undefined4 param_2);  // 0x100DB170
XI_API undefined4 __stdcall NetCellFont_GetRecordWordFwd(undefined4 param_1);  // 0x100DB780
XI_API undefined4 __stdcall NetCellFont_GetRecordDwordFwd(undefined4 param_1);  // 0x100DB790
XI_API undefined4 __thiscall NetCellFont_LookupNameIfKind3(void * self_, undefined4 param_1);  // 0x100DB7B0
XI_API undefined4 __cdecl NetCellFont_GetWord40D7C(void);  // 0x100DB930
XI_API undefined4 __thiscall NetCellFont_GetField0xA4(void * self_);  // 0x100DBAA0
XI_API undefined4 __thiscall GameMode_OpenTacticsUrl(void * self_, int param_1);  // 0x100DBB50
XI_API undefined4 __cdecl Game_IsFlag10492DB4(void);  // 0x100DBCA0
XI_API undefined1 __cdecl NetCellFont_ReturnTrue100DBDE0(void);  // 0x100DBDE0
XI_API DWORD __stdcall Time_GetMilliseconds(void);  // 0x100DBE00
XI_API undefined4 __cdecl NetCellFont_GetTimeNow(undefined4 * param_1, undefined4 * param_2);  // 0x100DBE30
XI_API undefined4 __cdecl NetCellFont_InitTimer(void);  // 0x100DBE50
XI_API undefined4 __cdecl NetCellFont_Sync(void);  // 0x100DBEB0
XI_API int __cdecl NetCellFont_DiffWrapped(int param_1, uint32_t param_2, uint32_t param_3);  // 0x100DBF00
XI_API void __cdecl NetCellFont_AdvanceClock(void);  // 0x100DBF20
XI_API int __cdecl NetCellFont_GetTotalMilliseconds(void);  // 0x100DC060
XI_API undefined4 __cdecl NetCellFont_GetSeconds(void);  // 0x100DC080
XI_API undefined4 __cdecl NetCellFont_GetMilliseconds(void);  // 0x100DC090
XI_API undefined4 __cdecl NetCellFont_AdvanceAndGetMs(void);  // 0x100DC120
XI_API undefined4 __cdecl NetCellFont_AdvanceAndGetSeconds(void);  // 0x100DC130
XI_API undefined4 __cdecl NetCellFont_Reset(void);  // 0x100DC1F0
XI_API undefined4 __cdecl NetCellFont_Update(void);  // 0x100DC210
XI_API undefined4 __cdecl NetCellFont_IsInitialized(void);  // 0x100DC2C0
XI_API int __cdecl Entry_FindByNormalizedName(char * param_1);  // 0x100E08D0
XI_API void __cdecl Name_Normalize(int param_1, char * param_2);  // 0x100E09A0
XI_API undefined4 __cdecl NetCellFont_FindEntryByName(undefined4 param_1);  // 0x100E0A50
XI_API void __cdecl NetCellFont_NoOp100E0B10(void);  // 0x100E0B10
XI_API undefined4 __cdecl NetCellFont_ApplyNoticeRecord(int param_1);  // 0x100E0D50
XI_API undefined4 __thiscall Entry_ResetFields(void * self_);  // 0x100E13C0
XI_API int __cdecl NetCellFont_AllocEntry4(int param_1);  // 0x100E19C0
XI_API undefined4 __cdecl NetCellFont_AllocEntryFromTable(void);  // 0x100E1AD0
XI_API int __cdecl NetCellFont_CountActive(void);  // 0x100E1B50
XI_API undefined4 __cdecl NetCellFont_ClearMatching(int param_1, undefined2 * param_2);  // 0x100E1C00
XI_API undefined4 __cdecl NetCellFont_RegisterHandler1369C(undefined4 * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6);  // 0x100E2E70
XI_API undefined4 __cdecl NetCellFont_RegisterHandler1369CFlag1(undefined4 * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5);  // 0x100E2EE0
XI_API undefined4 __cdecl NetCellFont_GetEntryMod1066268CFwd(void);  // 0x100E3E30
XI_API undefined4 __cdecl NetCellFont_GetBlock2CFD8(int * param_1);  // 0x100E47A0
XI_API void __cdecl NetCellFont_SetGlobal104B1774(undefined4 param_1);  // 0x100E5E30
XI_API int __cdecl NetCellFont_GetBlock2CDE8IfReady(void);  // 0x100E6020
XI_API void __cdecl NetCellFont_SetWord130(undefined4 param_1);  // 0x100E62C0
XI_API undefined4 __cdecl NetCellFont_ClearBit0Slot(undefined4 param_1);  // 0x100E6370
XI_API undefined4 __cdecl NetCellFont_SetFlagFCBit1(int param_1);  // 0x100E63B0
XI_API undefined4 __cdecl NetCellFont_ClearBit1Fc(int param_1);  // 0x100E63C0
XI_API undefined4 __cdecl NetCellFont_ScanEntriesAndInit(undefined4 param_1);  // 0x100E63E0
XI_API undefined4 __cdecl NetCellFont_InitEncrypt(undefined4 param_1);  // 0x100E6650
XI_API undefined4 __cdecl NetCellFont_IsBeforeDeadline(void);  // 0x100E6790
XI_API undefined4 __cdecl NetCellFont_IsCountOrByte134Set(void);  // 0x100E67E0
XI_API undefined4 __cdecl NetCellFont_ClearTimer140(void);  // 0x100E6810
XI_API undefined4 __cdecl NetCellFont_ScanIfTimer140Set(void);  // 0x100E6830
XI_API undefined4 __cdecl NetCellFont_IsTimer140Clear(void);  // 0x100E6860
XI_API undefined4 __cdecl NetCellFont_GetWord132(void);  // 0x100E6B10
XI_API undefined4 __cdecl NetCellFont_BuildListA90(void);  // 0x100E6B20
XI_API int __cdecl NetCellFont_GetEntryPtrA90(undefined4 param_1);  // 0x100E6C40
XI_API void __cdecl NetCellFont_ClearPending(void);  // 0x100E7260
XI_API int __cdecl NetCellFont_ThunkByIndex200(int param_1, undefined4 param_2);  // 0x100E7B20
XI_API int __cdecl NetCellFont_SetByte9800AndGetEntry(undefined4 param_1);  // 0x100E8B80
XI_API int __cdecl NetCellFont_SelectNext(void);  // 0x100E8C70
XI_API short * __cdecl NetCellFont_GetSlotPtr(int param_1, undefined4 param_2);  // 0x100EB490
XI_API int __cdecl NetCellFont_CountFreeEntries(int param_1);  // 0x100EB8D0
XI_API undefined4 __cdecl NetCellFont_GetEntryCount(int param_1);  // 0x100EB940
XI_API int __cdecl NetCellFont_FindOrRemove(uint32_t param_1, undefined4 param_2, undefined4 param_3);  // 0x100EBF80
XI_API void __cdecl NetCellFont_RemoveRecord(uint32_t param_1, undefined4 param_2);  // 0x100EC060
XI_API void __cdecl NetCellFont_ResetCounter(void);  // 0x100EDEA0
XI_API undefined4 __cdecl NetCellFont_Advance(void);  // 0x100EDEB0
XI_API undefined4 __cdecl NetCellFont_StepRequest1FSequence(int * param_1);  // 0x100EDFB0
XI_API undefined4 __cdecl NetCellFont_StepWait1030FF96(int * param_1);  // 0x100EE0A0
XI_API undefined4 __cdecl NetCellFont_StepRequest21Sequence(int * param_1, undefined4 param_2);  // 0x100EE690
XI_API undefined4 __cdecl NetCellFont_StepRequest22Sequence(int * param_1, undefined4 param_2);  // 0x100EE900
XI_API undefined4 __cdecl NetCellFont_StepRequest28Sequence(int * param_1, undefined4 param_2);  // 0x100EEB70
XI_API undefined4 __cdecl NetCellFont_StepRequest2BSequence(int * param_1, undefined4 param_2);  // 0x100EEDE0
XI_API undefined4 __cdecl NetCellFont_StepState1030FFxx(int * param_1);  // 0x100EEE90
XI_API undefined4 __cdecl NetCellFont_StepWait1030FFD8(int * param_1);  // 0x100EEF80
XI_API undefined4 __cdecl NetCellFont_StepRequest14Sequence(int * param_1, undefined4 param_2);  // 0x100EF020
XI_API int * __cdecl NetCellFont_RunState(int * param_1);  // 0x100EF0E0
XI_API undefined4 __cdecl NetCellFont_StepStateWithEntries(int * param_1);  // 0x100EF4C0
XI_API undefined4 __cdecl NetCellFont_StepStateWithTimer(int * param_1);  // 0x100EF550
XI_API undefined4 __cdecl NetCellFont_UpdateSessionIfReady(void);  // 0x100EF5B0
XI_API undefined4 __cdecl NetCellFont_UpdateSessionReturn1(void);  // 0x100EF5BD
XI_API int * __cdecl NetCellFont_DispatchByKindAndUpdate(int * param_1);  // 0x100EF640
XI_API undefined4 __cdecl NetCellFont_StatusText80IfFlags44(void);  // 0x100EF870
XI_API undefined4 __cdecl NetCellFont_StatusText80IfFlag4Only(void);  // 0x100EF8B0
XI_API undefined4 __cdecl NetCellFont_GetSessionField13C(void);  // 0x100EF8F0
XI_API undefined4 __cdecl NetCellFont_GetRecordWord(int param_1);  // 0x100EFC70
XI_API undefined4 __cdecl NetCellFont_GetRecordDword(int param_1);  // 0x100EFCA0
XI_API char * __cdecl Name_LookupByKey(int param_1);  // 0x100EFCE0
XI_API undefined4 __cdecl NetCellFont_CopyToGlobalBuffer(char * param_1);  // 0x100F0000
XI_API int __cdecl NetCellFont_GetBlock2CF54IfFlag(void);  // 0x100F00A0
XI_API undefined4 __attribute__((cdecl, regparm(1))) NetCellFont_ReturnTrue100F02A0(undefined4 xi_eax);  // 0x100F02A0
XI_API undefined4 __cdecl NetCellFont_SetByte15110(undefined1 * param_1);  // 0x100F04F0
XI_API undefined4 __cdecl NetCellFont_SetByte15114(undefined1 * param_1);  // 0x100F0550
XI_API undefined4 __cdecl NetCellFont_ClearDword136A4(void);  // 0x100F05F0
XI_API uint32_t __cdecl NetCellFont_GetFlagsMasked(void);  // 0x100F0C50
XI_API undefined4 __cdecl NetCellFont_GetWord40D82(void);  // 0x100F1080
XI_API undefined4 __cdecl NetCellFont_ClearRecord(undefined1 * param_1);  // 0x100F10C0
XI_API int __cdecl NetCellFont_UpdateActive(void);  // 0x100F10F0
XI_API int __cdecl NetCellFont_StepBitGuardedTask(int param_1);  // 0x100F1160
XI_API undefined4 __cdecl NetCellFont_AcquireIfFree(undefined4 param_1, undefined4 param_2, undefined4 param_3);  // 0x100F1280
XI_API char * __cdecl NetCellFont_AllocRecord(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);  // 0x100F1300
XI_API undefined4 __cdecl NetCellFont_InitEntry(char * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);  // 0x100F1340
XI_API uint32_t __cdecl NetCellFont_IsBitSet(undefined4 param_1);  // 0x100F13B0
XI_API void __cdecl NetCellFont_SetBit(undefined4 param_1);  // 0x100F13D0
XI_API void __cdecl NetCellFont_ClearBit(undefined4 param_1);  // 0x100F13F0
XI_API uint32_t __cdecl NetCellFont_Query10310030(void);  // 0x100F1670
XI_API void __cdecl NetCellFont_Call10310067(undefined4 param_1);  // 0x100F1870
XI_API void __cdecl NetCellFont_Call10310072(void);  // 0x100F1900
XI_API undefined4 __cdecl NetCellFont_GetLow16(void);  // 0x100F1950
XI_API int __thiscall NetCellFont_AcquireNode(void * self_);  // 0x100F1B20
XI_API undefined4 __thiscall NetCellFont_InitTwoNodes(void * self_);  // 0x100F1BA0
XI_API uint32_t __thiscall NetCellFont_Destroy(void * self_, undefined4 param_1);  // 0x100F1C40
XI_API undefined4 __thiscall NetCellFont_UpdateRequests(void * self_);  // 0x100F1D20
XI_API undefined1 __thiscall NetCellFont_ResetPending(void * self_);  // 0x100F1E70
XI_API undefined4 __thiscall NetCellFont_BeginRequests(void * self_, undefined4 param_1);  // 0x100F1F00
XI_API undefined4 __thiscall NetCellFont_StartRequestSlot20(void * self_, undefined4 * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);  // 0x100F25F0
XI_API undefined4 __thiscall NetCellFont_StartRequestOnNewNodeA(void * self_, undefined4 * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);  // 0x100F2690
XI_API undefined4 __thiscall NetCellFont_StartRequestOnNewNodeB(void * self_, undefined4 * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);  // 0x100F2720
XI_API undefined4 __thiscall NetCellFont_StartRequestSlot24(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3);  // 0x100F2760
XI_API undefined4 __thiscall NetCellFont_ClearNode(void * self_);  // 0x100F29E0
XI_API void __thiscall NetCellFont_DestroyNode(void * self_);  // 0x100F2A40
XI_API undefined4 __thiscall NetCellFont_Complete(void * self_);  // 0x100F2B80
XI_API undefined4 __attribute__((stdcall, regparm(3))) NetCellFont_CallStateCallback3(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x100F2C40
XI_API undefined4 __thiscall NetCellFont_RunCallbacks(void * self_, undefined4 param_1);  // 0x100F2C80
XI_API void __cdecl NetCellFont_CopyBounded(undefined4 * param_1, undefined4 * param_2, uint32_t param_3);  // 0x100F3010
XI_API int __thiscall NetCellFont_StartCallbacks(void * self_, undefined4 * param_1);  // 0x100F32B0
XI_API undefined4 __thiscall NetCellFont_StartIfIdle(void * self_, undefined4 param_1, undefined4 param_2);  // 0x100F3380
XI_API undefined4 __thiscall NetCellFont_InitRequestA(void * self_, undefined4 param_1, undefined4 param_2, undefined4 * param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6);  // 0x100F3BB0
XI_API undefined4 __thiscall NetCellFont_InitRequestB(void * self_, undefined4 param_1, undefined4 param_2, undefined4 * param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6);  // 0x100F3C20
XI_API undefined4 __thiscall NetCellFont_InitRequestC(void * self_, undefined4 param_1, undefined4 param_2, undefined4 * param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6);  // 0x100F3C90
XI_API undefined4 __thiscall NetCellFont_InitRequestD(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5);  // 0x100F3D00
XI_API undefined4 __cdecl NetCellFont_StartGlobalRequestSlot24(undefined4 param_1, undefined4 param_2, undefined4 param_3);  // 0x100F7620
XI_API undefined4 __cdecl NetCellFont_EnsureGlobal(void);  // 0x100F76B0
XI_API undefined4 __attribute__((cdecl, regparm(1))) NetCellFont_DestroyGlobal(undefined4 xi_eax, undefined4 param_1);  // 0x100F76D0
XI_API undefined4 __cdecl NetCellFont_UpdateGlobalRequests(void);  // 0x100F7700
XI_API undefined1 __cdecl NetCellFont_BeginGlobalRequests(void);  // 0x100F7740
XI_API undefined4 __cdecl NetCellFont_StoreQueriesInto104DF90C(void);  // 0x100F78C0
XI_API undefined4 __cdecl NetCellFont_StoreQueries2Into104DF90C(void);  // 0x100F7960
XI_API void __cdecl NetCellFont_InitEntryAt104DF90C(void);  // 0x100F7A00
XI_API undefined4 __cdecl NetCellFont_GetFieldCOf104DF90C(void);  // 0x100F7A80
XI_API int __thiscall NetCellFont_GetActiveBlock3AE98(void * self_);  // 0x100F94D0
XI_API undefined4 __cdecl NetCellFont_GetDword40C3C(int param_1);  // 0x100F9600
XI_API undefined4 __cdecl NetCellFont_IsReadyBy3C350(int param_1);  // 0x100F9680
XI_API undefined4 __cdecl NetCellFont_TickSecondCounters(void);  // 0x100F9CC0
XI_API void __cdecl NetCellFont_UpdateSession(void);  // 0x100F9D50
XI_API undefined4 __cdecl NetCellFont_GetFlags(void);  // 0x100FC160
XI_API undefined4 __cdecl NetCellFont_ApplyStatusText(uint32_t param_1);  // 0x100FC180
XI_API undefined4 __cdecl NetCellFont_GetWord40DAA(void);  // 0x100FC300
XI_API undefined4 __cdecl NetCellFont_SetWord40DAA(undefined4 param_1);  // 0x100FC320
XI_API undefined * __cdecl NetCellFont_GetBlock3C3A4OrDefault(void);  // 0x100FC4E0
XI_API undefined * __cdecl NetCellFont_GetIdPair(void);  // 0x100FC510
XI_API undefined4 __cdecl NetCellFont_FindTimerKind10(void);  // 0x100FCD70
XI_API undefined4 __cdecl NetCellFont_IsId50To99Or88Or89(uint32_t param_1);  // 0x100FD3A0
XI_API undefined4 __cdecl NetCellFont_TestBit198CC(undefined4 param_1);  // 0x100FD6E0
XI_API undefined4 __cdecl NetCellFont_GetTableByteForTens(uint32_t param_1);  // 0x10101BC0
XI_API uint32_t __cdecl NetCellFont_CeilDiv10Max10(uint32_t param_1);  // 0x10101BF0
XI_API undefined4 __cdecl Game_ClearFlagsBits(void);  // 0x10103740
XI_API void __cdecl Game_SetSlot44C(undefined4 param_1, undefined4 param_2);  // 0x101037F0
XI_API undefined4 __cdecl NetCellFont_ReturnZero(void);  // 0x101038C0
XI_API undefined4 __cdecl Game_GetField4(void);  // 0x101038D0
XI_API undefined4 __cdecl NetCellFont_GetWord8Of104E0AF4(void);  // 0x101038E0
XI_API undefined4 __cdecl NetCellFont_UpdateNoticesIfReady(void);  // 0x10103920
XI_API int __cdecl ntGameTimeGet(void);  // 0x101039E0
XI_API undefined4 __cdecl Time_ModDiv12FC00Div19500(uint32_t param_1);  // 0x10103A90
XI_API uint32_t __cdecl Time_ModDiv19500Scaled(uint32_t param_1);  // 0x10103AB0
XI_API uint32_t __cdecl Time_ModDiv6C00Scaled(uint32_t param_1);  // 0x10103AE0
XI_API undefined4 __cdecl Time_ModDivD80Div90(uint32_t param_1);  // 0x10103B10
XI_API uint32_t __cdecl Time_ModMul3CDiv90(uint32_t param_1);  // 0x10103B30
XI_API void __cdecl NetCellFont_SetZero(undefined2 * param_1);  // 0x10103F50
XI_API uint8_t * __cdecl fn_101061D0(uint8_t * param_1, uint32_t * param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5);  // 0x101061D0
XI_API int __cdecl NetCellFont_LookupMaskedTable(uint32_t param_1, uint32_t param_2, int param_3);  // 0x101072D0
XI_API undefined4 __cdecl NetCellFont_LookupTable10364CB0(undefined4 param_1, uint32_t param_2);  // 0x10107320
XI_API undefined4 __cdecl NetCellFont_AppendMax20(uint16_t * param_1, undefined4 param_2);  // 0x10107610
XI_API void __cdecl NetCellFont_DumpHexBytes(void);  // 0x10108150
XI_API int __cdecl NetCellFont_GetPoolBlockPayload(uint32_t param_1);  // 0x101083C0
XI_API undefined4 __cdecl NetCellFont_AllocEntry(uint32_t param_1, uint32_t param_2, uint32_t param_3);  // 0x10108590
XI_API undefined4 __cdecl NetCellFont_AllocFromPool(uint32_t param_1, uint32_t param_2);  // 0x101085C0
XI_API undefined4 __cdecl NetCellFont_AllocFromPool0(uint32_t param_1);  // 0x101085E0
XI_API void __thiscall NetCellFont_InitBlock(void * self_, undefined4 param_1, undefined4 param_2);  // 0x101086C0
XI_API void __thiscall NetCellFont_InsertBlock(void * self_, int param_1);  // 0x10108700
XI_API void __thiscall NetCellFont_InsertAndCoalesce(void * self_, int param_1);  // 0x10108780
XI_API uint32_t __thiscall NetCellFont_GetNextBlock(void * self_, int param_1);  // 0x10108870
XI_API int __stdcall NetCellFont_GetPrevBlock(int param_1);  // 0x101088A0
XI_API void __thiscall NetCellFont_RebalanceList(void * self_);  // 0x101088C0
XI_API undefined4 * __thiscall NetCellFont_TakeFreeBlock(void * self_, int param_1);  // 0x10108990
XI_API void __thiscall NetCellFont_Free(void * self_, int * param_1);  // 0x10108A50
XI_API void __thiscall NetCellFont_UnlinkBlock(void * self_, int param_1);  // 0x10108D80
XI_API void __thiscall NetCellFont_LinkAfter(void * self_, int param_1, int param_2);  // 0x10108E80
XI_API void __thiscall NetCellFont_LinkBefore(void * self_, int param_1, int param_2);  // 0x10108F40
XI_API undefined4 * __thiscall NetCellFont_AllocCopy(void * self_, undefined4 param_1, undefined4 * param_2, uint32_t param_3);  // 0x10109000
XI_API void __thiscall NetCellFont_Release(void * self_);  // 0x101090A0
XI_API void __thiscall NetCellFont_RefStringClear(void * self_);  // 0x10109100
XI_API void * __thiscall NetCellFont_RefStringCtor(void * self_, char * xi_s1);  // 0x10109140
XI_API int __thiscall NetCellFont_RefStringReserve(void * self_, undefined4 param_1);  // 0x101091D0
XI_API void * __attribute__((stdcall, regparm(3))) NetCellFont_RefStringAssign(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, char * param_2);  // 0x101092C0
XI_API void __attribute__((stdcall, regparm(3))) NetCellFont_RefStringRelease(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, undefined4 param_2);  // 0x101094D0
XI_API void __thiscall NetCellFont_Copy12(void * self_, void * param_1);  // 0x1010E040
XI_API void __thiscall NetCellFont_RecorderAddHandler(void * self_, uint32_t * param_1, uint32_t * param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5);  // 0x1010FA30
XI_API void __thiscall NetCellFont_RecorderRecordCode(void * self_, undefined4 param_1, undefined4 param_2);  // 0x1010FBD0
XI_API void __cdecl NetCellFont_ForwardToGlobal1708(undefined4 param_1, undefined4 param_2);  // 0x1010FEB0
XI_API void __thiscall NetCellFont_Copy12B(void * self_, void * param_1);  // 0x1010FEE0
XI_API void __thiscall NetCellFont_ListInsertBefore(void * self_, int param_1);  // 0x10110040
XI_API void __cdecl NetCellFont_ClearTable1710(void);  // 0x101133A0
XI_API undefined4 __cdecl NetCellFont_StartRequestSlot24WithCallback(undefined4 param_1, undefined4 param_2, undefined4 param_3);  // 0x10113CA0
XI_API void __thiscall NetCellFont_ErrorLogDtor(void * self_);  // 0x10114070
XI_API undefined4 * __thiscall NetCellFont_ErrorLogPop(void * self_, undefined4 * param_1);  // 0x10114120
XI_API undefined4 __thiscall NetCellFont_PushRingEntryLocked(void * self_, undefined4 * param_1);  // 0x10114250
XI_API void __thiscall NetCellFont_ErrorLogFlush(void * self_);  // 0x10114320
XI_API int __stdcall NetCellFont_SumWords16(uint16_t * param_1, undefined4 param_2);  // 0x10114620
XI_API void __cdecl NetCellFont_ReportError(uint32_t param_1, undefined4 * param_2, uint32_t param_3);  // 0x10114F10
XI_API void __cdecl FDtGmNoticeProc(void);  // 0x10115020
XI_API undefined4 __cdecl NetCellFont_ReturnOneA(void);  // 0x101152D0
XI_API undefined4 __cdecl NetCellFont_ReturnOneB(void);  // 0x101152E0
XI_API undefined4 __cdecl NetCellFont_ArmCounter10(int param_1);  // 0x10115870
XI_API undefined4 __cdecl NetCellFont_SetSessionData(int param_1, undefined4 * param_2);  // 0x10115930
XI_API undefined4 __cdecl NetCellFont_GetSessionData(int param_1, undefined4 * param_2);  // 0x10115970
XI_API undefined4 __cdecl NetCellFont_IsStateActive(int param_1);  // 0x101163A0
XI_API undefined4 __cdecl NetCellFont_GetField13C(int param_1, undefined4 * param_2);  // 0x101164B0
XI_API int __cdecl NetCellFont_NextSequence(int param_1, int param_2);  // 0x10116D30
XI_API undefined8 __thiscall NetCellFont_SetPair(void * self_, undefined4 param_1, undefined4 param_2);  // 0x101170D0
XI_API undefined8 __thiscall NetCellFont_MenuCtor(void * self_);  // 0x101172C0
XI_API void __thiscall NetCellFont_DeleteAllEntries(void * self_);  // 0x10117460
XI_API void __thiscall Menu_DrawWindowItems(void * self_);  // 0x101177D0
XI_API undefined4 __attribute__((stdcall, regparm(3))) NetCellFont_MenuReleaseItemCount(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x10117EE0
XI_API void __thiscall NetCellFont_InvokeChild34(void * self_);  // 0x10117F30
XI_API void __thiscall NetCellFont_Rebuild(void * self_, void * param_1);  // 0x10117F40
XI_API void __thiscall NetCellFont_ClearEntries(void * self_);  // 0x101180F0
XI_API void __thiscall NetCellFont_AttachSelection(void * self_, int param_1);  // 0x10118170
XI_API short * __thiscall NetCellFont_FindFreeEntry(void * self_);  // 0x10118220
XI_API undefined4 __attribute__((stdcall, regparm(3))) NetCellFont_MenuMoveSelection(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, undefined4 param_2);  // 0x10118260
XI_API void __cdecl NetCellFont_NoOpB(void);  // 0x10118520
XI_API void __thiscall NetCellFont_PlaceCursorObject(void * self_, undefined4 param_1, undefined4 param_2);  // 0x10118530
XI_API int __thiscall NetCellFont_GetFocusedValueA(void * self_);  // 0x101185E0
XI_API int __thiscall NetCellFont_GetFocusedValueB(void * self_);  // 0x10118640
XI_API void __thiscall NetCellFont_MenuUpdateFocusedHelp(void * self_);  // 0x101186A0
XI_API void __thiscall NetCellFont_MenuStartFade(void * self_, undefined4 xi_s1);  // 0x101187F0
XI_API undefined4 __thiscall NetCellFont_SelectFirstVisible(void * self_);  // 0x10118870
XI_API undefined4 __thiscall NetCellFont_SetStateByIndex(void * self_, undefined4 param_1, int param_2);  // 0x10118B60
XI_API undefined4 __thiscall NetCellFont_FindEntryValueById(void * self_, int param_1);  // 0x10118BC0
XI_API uint32_t __thiscall NetCellFont_HitTest(void * self_, uint32_t * param_1);  // 0x10118C10
XI_API undefined4 __thiscall NetCellFont_PickEntry(void * self_, int * param_1, int param_2);  // 0x10118CB0
XI_API undefined4 __attribute__((stdcall, regparm(3))) NetCellFont_SelectEntryMoveCursor(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, int param_2, undefined4 param_3);  // 0x10118DB0
XI_API undefined8 __attribute__((stdcall, regparm(3))) NetCellFont_SelectEntry(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, undefined4 param_2);  // 0x10118E90
XI_API void __thiscall NetCellFont_SetChildOwner(void * self_, undefined4 xi_s1);  // 0x10118F20
XI_API undefined4 __attribute__((stdcall, regparm(3))) NetCellFont_CallMember0CSlot2(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x10118F30
XI_API void __thiscall NetCellFont_FreeChild(void * self_);  // 0x10118F40
XI_API undefined8 __thiscall NetCellFont_GetRect(void * self_, undefined4 * param_1);  // 0x10118F70
XI_API void __thiscall NetCellFont_SetState10ForIndex58(void * self_);  // 0x101190F0
XI_API void __thiscall NetCellFont_SetActive(void * self_, uint32_t param_1);  // 0x10119200
XI_API void __thiscall NetCellFont_ClearEntryFlags(void * self_, undefined4 param_1, undefined4 param_2);  // 0x101192B0
XI_API void __thiscall NetCellFont_MarkDirty(void * self_, undefined4 param_1);  // 0x101192E0
XI_API void * __thiscall NetCellFont_InitScaled(void * self_);  // 0x10119300
XI_API void __thiscall NetCellFont_FreeEntryData(void * self_);  // 0x10119360
XI_API void __thiscall NetCellFont_ClearField34(void * self_);  // 0x10119390
XI_API void __attribute__((stdcall, regparm(3))) NetCellFont_StartFade(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x101193A0
XI_API void __thiscall NetCellFont_StopFade(void * self_);  // 0x101193B0
XI_API undefined4 __thiscall NetCellFont_SetSource(void * self_, int * param_1);  // 0x101193D0
XI_API undefined4 __thiscall NetCellFont_ComputeRect(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3);  // 0x101193F0
XI_API void __thiscall NetCellFont_UpdateLayout(void * self_, float param_1);  // 0x10119550
XI_API undefined4 __cdecl NetCellFont_MapKind119870(undefined4 param_1);  // 0x10119870
XI_API void * __thiscall NetCellFont_LayoutCtor(void * self_, undefined4 param_1);  // 0x101198D0
XI_API void __thiscall NetCellFont_SetState(void * self_, undefined4 param_1);  // 0x10119970
XI_API undefined4 __thiscall NetCellFont_SetNames(void * self_, int * param_1);  // 0x10119A50
XI_API undefined4 __thiscall NetCellFont_ComputeOffsets(void * self_, undefined4 param_1, undefined4 param_2, int param_3);  // 0x10119AD0
XI_API uint32_t __thiscall NetCellFont_ContainsPoint(void * self_, int * param_1);  // 0x10119BC0
XI_API void __thiscall NetCellFont_UpdateState(void * self_, undefined4 param_1);  // 0x10119C00
XI_API void * __thiscall NetCellFont_InitDefaults(void * self_);  // 0x10119DA0
XI_API void __thiscall NetCellFont_SetShape(void * self_, undefined4 param_1);  // 0x10119E20
XI_API undefined4 __thiscall NetCellFont_AttachTo(void * self_, int param_1);  // 0x10119E30
XI_API void __thiscall NetCellFont_ResolveShape(void * self_);  // 0x10119E70
XI_API undefined4 __attribute__((stdcall, regparm(3))) NetCellFont_StepFrameCycle(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x10119F20
XI_API undefined8 __thiscall NetCellFont_DrawUnscaled(void * self_, void * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5);  // 0x10119F80
XI_API undefined4 __thiscall NetCellFont_InvokeCallback7C(void * self_);  // 0x1011A3B0
XI_API void __thiscall NetCellFont_ApplyHelpAndTitle(void * self_);  // 0x1011A490
XI_API undefined4 __thiscall NetCellFont_SetRectAndUpdateNodes(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7);  // 0x1011A5A0
XI_API undefined8 __thiscall NetCellFont_GetPos42(void * self_, undefined4 * param_1);  // 0x1011A710
XI_API int __thiscall NetCellFont_SetViewport(__int16 *self_);  // 0x1011AA40
XI_API int __cdecl Gfx_ApplyViewport1B70(void);  // 0x1011AAC0
XI_API undefined4 __thiscall NetCellFont_GetCenter(void * self_, int * param_1);  // 0x1011ABF0
XI_API undefined4 __thiscall NetCellFont_SetEntryValue4C(void * self_, undefined4 param_1, undefined4 param_2);  // 0x1011ADB0
XI_API void __thiscall NetCellFont_AddEntry(void * self_, undefined4 param_1);  // 0x1011AE10
XI_API uint32_t __thiscall NetCellFont_GetFieldByIndex(void * self_, undefined4 param_1, undefined4 param_2);  // 0x1011B220
XI_API int __thiscall NetCellFont_GetEntryValueById(void * self_, undefined4 param_1);  // 0x1011B2A0
XI_API int __thiscall NetCellFont_GetEntry(void * self_, undefined4 param_1);  // 0x1011B2E0
XI_API undefined4 __thiscall NetCellFont_GetField8(void * self_);  // 0x1011B310
XI_API undefined4 __thiscall NetCellFont_GetFieldC(void * self_);  // 0x1011B320
XI_API void __thiscall NetCellFont_GetOffsets(void * self_, undefined2 * param_1, undefined2 * param_2);  // 0x1011B330
XI_API undefined4 __attribute__((stdcall, regparm(3))) NetCellFont_SetShorts1A1C(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, undefined4 param_2, undefined4 param_3);  // 0x1011B360
XI_API undefined4 __thiscall NetCellFont_InitColors(void * self_);  // 0x1011BA90
XI_API char __thiscall Font_BindGlyphTexture(int self_);  // 0x1011BAE0
XI_API undefined4 __thiscall Font_DrawGlyphQuadGrey(void * self_, undefined4 param_1, int * param_2, undefined4 param_3, undefined4 param_4);  // 0x1011BBA0
XI_API int __thiscall Font_DrawGlyphQuad(float *self_, __int16 a2, int *a3, unsigned int a4, float a5, float a6);  // 0x1011BBD0
XI_API int __cdecl Gfx_SetAdditiveBlend(void);  // 0x1011BDC0
XI_API undefined4 __cdecl Font_DrawChar(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5);  // 0x1011BF40
XI_API int __stdcall Font_MeasureString(char * param_1, undefined4 xi_s2);  // 0x1011BFD0
XI_API int __cdecl Gfx_SetCellBlendMode(int a1, int a2, int a3, int a4);  // 0x1011C1F0
XI_API void __stdcall Font_AllocHighResImage(undefined4 * param_1, int param_2, int param_3);  // 0x1011C5D0
XI_API unsigned char __stdcall Tex_LoadSurfaceFromDatFile(int param_1, undefined4 xi_s2);  // 0x1011C670
XI_API void __thiscall Font_LoadHighResTexture(int *self_);  // 0x1011C720
XI_API void __thiscall Font_ReleaseHighResTexture(void * self_);  // 0x1011C810
XI_API uint32_t __thiscall Font_IsHighResTextureLoaded(void * self_);  // 0x1011C850
XI_API undefined4 __thiscall unknown_libname_88(void * self_);  // 0x1011C870
XI_API undefined4 __cdecl Font_LoadWidthTable(void);  // 0x1011C8B0
XI_API undefined4 __cdecl Font_IsSingleByte(undefined1 * param_1);  // 0x1011C900
XI_API undefined8 __cdecl Sjis_ToJisIndex(uint8_t * param_1);  // 0x1011C940
XI_API int __cdecl Font_DecodeNextChar(int * param_1);  // 0x1011CE80
XI_API int __cdecl Font_GetCharWidth(uint32_t param_1);  // 0x1011CEC0
XI_API int __cdecl Font_MeasureText(char * param_1, uint32_t param_2);  // 0x1011CF70
XI_API void __cdecl Font_MeasureTextAll(char * param_1);  // 0x1011D000
XI_API void __cdecl Font_MeasureTextAll2(char * param_1);  // 0x1011D010
XI_API undefined1 __cdecl NetCellFont_IsNotControlChar(undefined4 param_1);  // 0x1011D290
XI_API uint32_t __cdecl NetCellFont_MeasureTextWidth(char * param_1, uint32_t param_2, undefined4 param_3);  // 0x1011D380
XI_API void __cdecl NetCellFont_MeasureTextWidthAll(char * param_1, undefined4 param_2);  // 0x1011D440
XI_API uint32_t __attribute__((cdecl, regparm(1))) Font_AddGlyphAdvance(undefined4 xi_eax, undefined4 param_1, int * param_2);  // 0x1011D840
XI_API undefined4 __cdecl Font_IsPrintableAscii(int param_1);  // 0x1011D8B0
XI_API void __cdecl NetCellFont_MeasureTextWidthFwd(char * param_1, undefined4 param_2);  // 0x1011D970
XI_API undefined4 __attribute__((cdecl, regparm(2))) Font_GetCharWidthAt(uint32_t xi_eax_unused, undefined4 xi_edx, uint8_t * param_1);  // 0x1011D990
XI_API undefined4 __cdecl Sjis_IsLeadByte(uint32_t param_1);  // 0x1011DA30
XI_API undefined4 __cdecl Sjis_GetCharByteLen(undefined1 * param_1);  // 0x1011DA80
XI_API undefined4 __cdecl Sjis_IsCodeInSet(void * param_1);  // 0x1011DB40
XI_API undefined4 __cdecl NetCellFont_UppercaseCharThen1011DAE0(undefined1 * param_1, void * param_2);  // 0x1011DC00
XI_API void __cdecl NetCellFont_LowercaseCharThen1011DAE0(undefined1 * param_1, void * param_2);  // 0x1011DCC0
XI_API size_t __cdecl Sjis_CopyPrefix(char * param_1, int param_2, char * param_3);  // 0x1011DE80
XI_API int __thiscall Cell_GetField20Ptr(void * self_);  // 0x1011E290
XI_API void __thiscall Cell_ResolveSubCells(void * self_);  // 0x1011E2A0
XI_API undefined4 __thiscall Cell_ResolveTextureUV(void * self_);  // 0x1011E6D0
XI_API int __thiscall Cell_DrawAt(void *self_, int a1, int a2);  // 0x1011E800
XI_API int __thiscall Cell_DrawTexturedQuad(void *self_, int a1, int a2, int a3, int a4, int a5, int a6);  // 0x1011E980
XI_API void __thiscall Cell_DrawTransformed(int self_, int a2, int a3, float a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, unsigned int a20, int a21);  // 0x1011EDE0
XI_API int __thiscall Cell_DrawStretchedWrapped(int self_, int a2, int a3, int a4, int a5, int a6, int a7, float a8, float a9, unsigned int a10, unsigned int a11, char a12);  // 0x1011EF60
XI_API void __thiscall Cell_DrawWithDefaultBlend(void * self_);  // 0x1011F2D0
XI_API int __thiscall Cell_DrawQuadBlended(void *self_, int a1, int a2, int a3, int a4, int a5);  // 0x1011F300
XI_API int __thiscall Cell_GetFrameBounds(void * self_, int param_1, short * param_2);  // 0x1011FA80
XI_API undefined4 __thiscall NetCellFont_GetNthEntryBytePair(void * self_, int param_1, int param_2);  // 0x1011FB00
XI_API undefined8 __thiscall Cell_DrawFirstStretched(void * self_, uint32_t param_1, uint32_t param_2, undefined4 param_3, undefined4 xi_s4, undefined4 xi_s5, undefined4 xi_s6, undefined4 xi_s7, undefined4 xi_s8, undefined4 xi_s9, undefined4 xi_s10, undefined4 xi_s11);  // 0x10120000
XI_API void __thiscall Cell_ResolveTextureList(void * self_);  // 0x10120070
XI_API uint32_t __cdecl Color_ModulateArgb128(uint32_t param_1, uint32_t param_2);  // 0x101200B0
XI_API undefined4 __thiscall ShapeMng_FindShape(void * self_, char * param_1);  // 0x10120450
XI_API undefined4 __thiscall Cell_FindEntryByName(void * self_, char * param_1);  // 0x101204B0
XI_API undefined4 __thiscall ShapeMng_GetFontGlyph(void * self_, uint32_t param_1, undefined4 param_2, short * param_3, undefined2 * param_4, undefined2 * param_5);  // 0x10120510
XI_API void __thiscall ShapeMng_LoadFontTextures(void * self_);  // 0x10120660
XI_API void __thiscall Cell_ResolveAllSubCells(void * self_);  // 0x10120950
XI_API undefined4 __cdecl Cell_TestAny38Or0B8(void);  // 0x10120B80
XI_API undefined4 __cdecl Cell_TestAny1DOr9D(void);  // 0x10120BB0
XI_API undefined4 __cdecl Cell_TestAny2AOr36(void);  // 0x10120BE0
XI_API long double __cdecl Cell_GetByte253Scaled(void);  // 0x10120C40
XI_API uint32_t __attribute__((cdecl, regparm(1))) NetCellFont_QueryState1D44AL(undefined4 xi_eax, uint32_t param_1);  // 0x10120F30
XI_API uint32_t __cdecl NetCellFont_QueryState1D44Mask100(uint32_t param_1);  // 0x101210F0
XI_API uint32_t __cdecl NetCellFont_QueryState1D44Mask1000(uint32_t param_1);  // 0x10121420
XI_API uint32_t __cdecl NetCellFont_QueryState1D44Mask4000(uint32_t param_1);  // 0x10121640
XI_API uint32_t __cdecl NetCellFont_QueryState1D44Clear22C(uint32_t param_1);  // 0x10121DB0
XI_API long double __cdecl NetCellFont_Call10122E30With1(void);  // 0x10122E20
XI_API long double __cdecl NetCellFont_GetCursorValueUnlessBlocked(void);  // 0x101232E0
XI_API undefined4 __cdecl Cell_TestFlagAny2AOr36(undefined4 param_1);  // 0x10123350
XI_API undefined4 __cdecl Cell_TestFlagKind(uint32_t param_1, undefined4 param_2);  // 0x10123380
XI_API undefined4 __cdecl Cell_GetByte1036E0F0(undefined4 param_1);  // 0x10123640
XI_API undefined4 __cdecl Cell_SetByte1036E0F0(undefined4 param_1, undefined4 param_2);  // 0x10123650
XI_API undefined4 __cdecl Cell_GetWord1036D6B0(undefined4 param_1);  // 0x10123670
XI_API undefined4 __cdecl Cell_SetWord1036D6B0(undefined4 param_1, undefined4 param_2);  // 0x10123680
XI_API undefined4 __cdecl NetCellFont_SetTable1036D6B0Word(undefined4 param_1, undefined4 param_2);  // 0x101236B0
XI_API void __cdecl Cell_SetGlobal1036E3A0(undefined4 param_1);  // 0x101236E0
XI_API undefined8 __cdecl NetCellFont_Query123700UnlessBlocked(void);  // 0x10123700
XI_API undefined4 __attribute__((cdecl, regparm(1))) NetCellFont_TestCommand36CF60(undefined4 xi_eax, undefined4 param_1, int param_2, int param_3, int param_4);  // 0x10123A70
XI_API undefined4 __cdecl Cursor_TestAny1DOr9D(void);  // 0x10123DC0
XI_API undefined4 __cdecl Cursor_TestAnyB8Or38(void);  // 0x10123DF0
XI_API undefined4 __cdecl Cell_TestFlagAny2AOr36Kind4(void);  // 0x10123E20
XI_API undefined4 __cdecl Cell_TestGlobal1036E3A0Mask(uint32_t param_1);  // 0x10123E50
XI_API undefined4 __attribute__((cdecl, regparm(1))) Cell_SetByte104E1C3E(undefined4 xi_eax, undefined4 param_1);  // 0x10123E60
XI_API void __cdecl Cell_Nop(void);  // 0x10123E80
XI_API void __cdecl Cell_ClearFlag104E1C3C(void);  // 0x10123E90
XI_API void __cdecl Cell_SetFlag104E1C3C(void);  // 0x10123EA0
XI_API undefined4 __attribute__((cdecl, regparm(1))) Cell_GetByte1036CF5C(undefined4 xi_eax);  // 0x10123EE0
XI_API void __thiscall Cell_SetFlagBit2(void * self_, uint32_t param_1);  // 0x10123F40
XI_API void __thiscall Cell_SetFlagBit8(void * self_, uint32_t param_1);  // 0x10123F60
XI_API undefined4 __thiscall NetCellFont_SetByteFlag1(void * self_, uint32_t param_1);  // 0x10123F80
XI_API void __thiscall Cell_SetFlagBit4Dirty(void * self_, uint32_t param_1);  // 0x10123FC0
XI_API void __thiscall Cell_SetFlagBit10(void * self_, uint32_t param_1);  // 0x10123FE0
XI_API void __thiscall Cell_ClearByte(void * self_, uint32_t param_1);  // 0x10124000
XI_API undefined4 __thiscall Cell_ClearFlag01And08(void * self_, uint32_t param_1);  // 0x10124010
XI_API undefined4 __thiscall Cell_ClearAllFlags(void * self_);  // 0x10124050
XI_API undefined4 __thiscall Cell_TestFlagBit1(void * self_, uint32_t param_1);  // 0x10124070
XI_API undefined4 __thiscall Cell_TakeFlagBit2(void * self_, uint32_t param_1);  // 0x10124090
XI_API undefined4 __thiscall Cell_TestFlagBit3(void * self_, uint32_t param_1);  // 0x101240B0
XI_API undefined4 __thiscall Cell_TestFlagBit0(void * self_, uint32_t param_1);  // 0x101240D0
XI_API undefined4 __thiscall Cursor_TakeEventFlag(void * self_, uint32_t param_1);  // 0x101240F0
XI_API undefined4 __thiscall Cursor_GetFlagBit4(void * self_, uint32_t param_1);  // 0x10124110
XI_API undefined4 __thiscall Cursor_GetFlagBit2(void * self_, uint32_t param_1);  // 0x10124130
XI_API void __attribute__((cdecl, regparm(1))) NetCellFont_HalfKanaToFullWidth(undefined4 xi_eax, undefined1 * param_1, undefined4 param_2);  // 0x10124360
XI_API undefined4 __attribute__((cdecl, regparm(1))) NetCellFont_IsHalfWidthKana(undefined4 xi_eax, undefined4 param_1);  // 0x10124390
XI_API int __thiscall Cursor_Init(int self_);  // 0x10124440
XI_API undefined4 __thiscall Cursor_GetHwCursorSlot(void * self_);  // 0x101245C0
XI_API void __thiscall Cursor_HandleMouseMove(void * self_, int * param_1, undefined4 param_2, undefined4 xi_s3);  // 0x101245D0
XI_API int __thiscall CTkMouse_OnMouseMove(int *self_, int *a2, __int16 a3);  // 0x10124640
XI_API undefined4 __attribute__((stdcall, regparm(3))) Cursor_SetPosition(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, undefined4 * param_2, float param_3);  // 0x10124700
XI_API void __thiscall Cursor_UpdateTimer(void * self_);  // 0x101248A0
XI_API void __thiscall Cursor_EnterMode1(void * self_);  // 0x10124930
XI_API void __thiscall Cursor_ToggleFlag1(void * self_);  // 0x101249E0
XI_API void __thiscall Cursor_EnterMode2(void * self_);  // 0x10124A00
XI_API void __thiscall Cursor_ToggleFlag2(void * self_);  // 0x10124AB0
XI_API void __thiscall Cursor_EnterMode4(void * self_);  // 0x10124AD0
XI_API void __thiscall Cursor_ToggleFlag4(void * self_);  // 0x10124B50
XI_API undefined4 __thiscall Cursor_ResetPositionToMenu(void * self_);  // 0x10124B70
XI_API undefined4 __thiscall NetCellFont_CursorUpdateEdgeAxes(void * self_);  // 0x10124BC0
XI_API undefined4 __thiscall NetCellFont_UpdateHoldState4(void * self_);  // 0x10125040
XI_API undefined4 __attribute__((stdcall, regparm(3))) NetCellFont_UpdateHoldState5(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x10125170
XI_API undefined4 __thiscall Cursor_SetModeFromMenuActive(void * self_);  // 0x101252C0
XI_API unsigned __int8 __thiscall Cursor_SetVisible(unsigned __int8 *self_, unsigned __int8 a2);  // 0x101252F0
XI_API undefined8 __thiscall Cursor_UpdateVisibilityForMode(void * self_, undefined4 param_1);  // 0x10125F70
XI_API long double __thiscall Cursor_GetField98(void * self_);  // 0x101260E0
XI_API long double __thiscall Cursor_GetField94(void * self_);  // 0x101260F0
XI_API long double __thiscall Cursor_GetNormalizedDeltaY(void * self_);  // 0x10126100
XI_API undefined4 __cdecl Cursor_HasTargetHover(void);  // 0x10126270
XI_API undefined4 __cdecl unknown_libname_89(void);  // 0x10126290
XI_API void __thiscall Cursor_StoreScreenCenter(void * self_);  // 0x101262A0
XI_API undefined4 __attribute__((stdcall, regparm(3))) NetCellFont_IsCursorMode2NoEvent(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x101262E0
XI_API undefined4 __thiscall NetCellFont_Init(void * self_);  // 0x10126300
XI_API undefined4 __thiscall NetCellFont_ClearWords(void * self_);  // 0x10126320
XI_API void __cdecl NetCellFont_NoOp(void);  // 0x10126330
XI_API void __thiscall NetCellFont_Clear(void * self_);  // 0x10126350
XI_API undefined4 __thiscall NetCellFont_FreeBothLists(void * self_);  // 0x10126370
XI_API undefined4 * __thiscall NetCellFont_Alloc(void * self_);  // 0x101263B0
XI_API undefined4 __stdcall NetCellFont_GetCount(int param_1);  // 0x10126460
XI_API undefined8 __thiscall NetCellFont_PushBack(void * self_, undefined4 param_1);  // 0x10126480
XI_API undefined8 __thiscall NetCellFont_PushFront(void * self_, undefined4 param_1);  // 0x101264C0
XI_API undefined4 __thiscall NetCellFont_GetHead(void * self_);  // 0x10126500
XI_API undefined4 __thiscall NetCellFont_GetTail(void * self_);  // 0x10126510
XI_API undefined4 __stdcall NetCellFont_NextActiveValue(int * param_1);  // 0x10126550
XI_API void __thiscall NetCellFont_Remove(void * self_, int * param_1);  // 0x10126580
XI_API undefined4 __thiscall NetCellFont_FreeListsAndReset(void * self_);  // 0x101265D0
XI_API void __thiscall NetCellFont_InsertBefore(void * self_, int param_1, int param_2);  // 0x101266B0
XI_API undefined8 __thiscall NetCellFont_InsertAfter(void * self_, int * param_1, int param_2);  // 0x10126700
XI_API void * __thiscall NetCellFont_ChatListCtorA(void * self_, undefined4 param_1);  // 0x10126750
XI_API void * __thiscall NetCellFont_ChatListCtorB(void * self_, undefined4 param_1);  // 0x10126770
XI_API void * __thiscall NetCellFont_ChatListInit(void * self_, undefined4 param_1);  // 0x10126790
XI_API undefined4 __thiscall NetCellFont_AddMessage(void * self_, char * param_1, char * param_2, undefined4 param_3);  // 0x101268F0
XI_API undefined4 __thiscall NetCellFont_ClearAllAndNotifyOwner(void * self_);  // 0x10126A00
XI_API void * __thiscall NetCellFont_MessageCtor(void * self_, undefined4 param_1, undefined4 param_2);  // 0x10126B60
XI_API void __thiscall NetCellFont_MessageSet(void * self_, char * param_1, char * param_2, undefined4 param_3, undefined4 param_4);  // 0x10126BC0
XI_API undefined4 * __attribute__((stdcall, regparm(3))) NetCellFont_ParseMessageControlCode(uint32_t xi_eax_unused, undefined4 param_2, int param_1, int * param_3, undefined1 * param_4);  // 0x10126C60
XI_API void * __thiscall NetCellFont_MsgWinDataCtor(void * self_);  // 0x10127190
XI_API void __thiscall NetCellFont_MsgWinDataReset(void * self_);  // 0x101271C0
XI_API undefined8 __thiscall NetCellFont_ResetEntryRing(void * self_);  // 0x10127250
XI_API int __thiscall NetCellFont_PushSlot(void * self_, undefined4 xi_s1);  // 0x10127280
XI_API int __thiscall NetCellFont_NewRingEntry(void * self_, undefined4 xi_s1);  // 0x10127320
XI_API void __thiscall NetCellFont_BuildRecord(void * self_, uint8_t * param_1, char * param_2, undefined2 * param_3);  // 0x101273C0
XI_API uint32_t __cdecl NetCellFont_FindByKeyByte(uint32_t param_1);  // 0x10127870
XI_API char * __cdecl NetCellFont_FindChar(char * param_1, undefined4 param_2);  // 0x101278B0
XI_API undefined4 __cdecl NetCellFont_FindSubstringIndex(char * param_1, char * param_2, int param_3);  // 0x101278D0
XI_API void __cdecl NetCellFont_CopyLimited(int param_1, char * param_2, int param_3);  // 0x10127930
XI_API void __cdecl NetCellFont_ToLowerInPlace(char * param_1);  // 0x10127970
XI_API uint32_t __cdecl GetCallNum(char * param_1, char * param_2);  // 0x10127990
XI_API undefined4 __cdecl NetCellFont_IsNearNamedActor(uint32_t * param_1);  // 0x10127AB0
XI_API undefined4 __thiscall ChatLog_AddMessage(void * self_, char * param_1, uint8_t * param_2, undefined4 param_3, undefined4 param_4, int param_5);  // 0x10127C00
XI_API undefined4 __cdecl NetCellFont_ClearGlobalLists2150And2154(void);  // 0x10127EA0
XI_API void * __thiscall NetCellFont_CtorResetAll(void * self_);  // 0x10127EE0
XI_API void __thiscall NetCellFont_ResetAll(void * self_);  // 0x10127F00
XI_API uint32_t __thiscall NetCellFont_IsInRow30(void * self_, int param_1, int param_2);  // 0x10127F60
XI_API int __cdecl NetCellFont_FormatHexRecord(char * param_1, undefined4 xi_s2, undefined4 xi_s3, undefined4 xi_s4, undefined4 xi_s5, undefined4 xi_s6, undefined4 xi_s7, undefined4 xi_s8, undefined4 xi_s9, undefined4 xi_s10, undefined4 xi_s11, undefined4 xi_s12, undefined4 xi_s13, undefined4 xi_s14, undefined4 xi_s15, undefined4 xi_s16, undefined4 xi_s17);  // 0x10127FA0
XI_API char * __cdecl NetCellFont_ParseHexRecord(undefined1 * param_1, undefined4 param_2, char * param_3);  // 0x10128060
XI_API void __thiscall NetCellFont_AddByType(void * self_, undefined4 param_1, undefined4 param_2);  // 0x101281F0
XI_API int __cdecl NetCellFont_CountTextChars(char * param_1);  // 0x10128680
XI_API void __cdecl NetCellFont_CountTextCharsAndBytes(int * param_1, int * param_2, char * param_3);  // 0x10128830
XI_API undefined8 __cdecl NetCellFont_BuildTextCharIndex(int * param_1, undefined1 * param_2, char * param_3);  // 0x10128950
XI_API int __cdecl NetCellFont_CopyTextFromIndex(undefined1 * param_1, char * param_2, undefined1 * param_3);  // 0x10128AE0
XI_API void __attribute__((stdcall, regparm(3))) NetCellFont_ClearFlag12FromValue(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, int param_2);  // 0x10129290
XI_API int __attribute__((stdcall, regparm(3))) NetCellFont_RingStepBack(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, short * param_2, int * param_3);  // 0x101292E0
XI_API undefined4 __thiscall NetCellFont_GetOptionByte(void * self_, undefined4 param_1);  // 0x101293F0
XI_API void __thiscall NetCellFont_SetOptionByte(void * self_, undefined4 param_1, uint32_t param_2);  // 0x10129490
XI_API undefined8 __stdcall NetCellFont_IsKindEnabledInSettings(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);  // 0x10129BB0
XI_API short __thiscall NetCellFont_NextRingIndex(void * self_, undefined4 param_1, undefined4 xi_s2);  // 0x10129C20
XI_API undefined4 __attribute__((stdcall, regparm(3))) NetCellFont_GetRingHead14(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x10129C60
XI_API undefined4 * __cdecl NetCellFont_FindKindRecord(undefined4 param_1);  // 0x10129CD0
XI_API undefined4 __cdecl NetCellFont_MapCode(undefined4 param_1);  // 0x10129D00
XI_API uint32_t __thiscall ChatLog_AddTableMessage7(void * self_, uint32_t param_1);  // 0x10129D90
XI_API uint32_t __thiscall ChatLog_AddMessage9Code379(void * self_, uint32_t param_1);  // 0x10129DE0
XI_API uint32_t __thiscall ChatLog_AddMessage7Code37B(void * self_, uint32_t param_1);  // 0x10129E30
XI_API void __thiscall ChatLog_AddTextCode379(void * self_, char * param_1);  // 0x10129E80
XI_API void __thiscall ChatLog_AddTextCode37B(void * self_, char * param_1);  // 0x10129EB0
XI_API undefined4 __cdecl Font_DrawStringDefault(char * param_1);  // 0x10129EE0
XI_API undefined8 __cdecl Font_DrawStringFlags44(int param_1, undefined4 param_2, char * param_3, int param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7);  // 0x10129F40
XI_API undefined4 __cdecl NetCellFont_MapCode1BTo54(int param_1);  // 0x10129F80
XI_API undefined4 __cdecl NetCellFont_MapCode54ToIndex(undefined4 param_1);  // 0x1012A120
XI_API void __thiscall NetCellFont_CallClearBuffers(void * self_);  // 0x1012A350
XI_API undefined4 * __attribute__((stdcall, regparm(3))) NetCellFont_InitTextLayout(uint32_t xi_eax_unused, undefined4 xi_edx, undefined4 * param_1);  // 0x1012A360
XI_API void __thiscall NetCellFont_ClearBuffers(void * self_);  // 0x1012A3B0
XI_API undefined4 __thiscall NetCellFont_GetWord1A(void * self_);  // 0x1012A400
XI_API undefined4 __thiscall NetCellFont_GetByte9(void * self_);  // 0x1012A410
XI_API uint32_t __thiscall NetCellFont_SetString(void * self_, char * param_1, undefined4 param_2, int param_3, int param_4);  // 0x1012A420
XI_API undefined4 __thiscall NetCellFont_GetField20(void * self_);  // 0x1012A4E0
XI_API void * __thiscall NetCellFont_Construct(void * self_);  // 0x1012AB20
XI_API void __cdecl YkZip_DoNothing(void);  // 0x1012AC50
XI_API void __stdcall TargetMenu_DoNothing1Arg(undefined4 xi_s1);  // 0x1012AC80
XI_API void __attribute__((stdcall, regparm(3))) TargetMenu_FillEntriesFromTable1036F390(uint32_t xi_eax_unused, undefined4 param_2, int param_1, int param_3, int param_4);  // 0x1012B2D0
XI_API void __thiscall TargetMenu_UpdateActionMenu(void * self_, undefined4 param_1);  // 0x1012B4B0
XI_API void * __thiscall TargetMenu_ConstructVt103333C8(void * self_);  // 0x1012BEF0
XI_API void __thiscall TargetMenu_ClearEntry1Flags(void * self_);  // 0x1012BF50
XI_API void * __thiscall TargetMenu_ConstructVt10333410(void * self_);  // 0x1012C210
XI_API void * __thiscall TargetMenu_ConstructVt10333458(void * self_);  // 0x1012C540
XI_API void * __thiscall TargetMenu_ConstructVt103334A0(void * self_);  // 0x1012C910
XI_API void * __thiscall TargetMenu_ConstructVt10333500(void * self_);  // 0x1012D450
XI_API void __thiscall TargetMenu_DestroyDraw(void * self_);  // 0x1012E180
XI_API void * __thiscall TargetMenu_ConstructVt103335E8(void * self_);  // 0x1012E360
XI_API void * __thiscall TargetMenu_ClearThenSetGlobal(void * self_);  // 0x10130390
XI_API int __thiscall TargetMenu_GetActiveEntry16(void * self_, int param_1);  // 0x101304A0
XI_API void __thiscall TargetMenu_ResolveEntries(void * self_);  // 0x101304D0
XI_API void __thiscall TargetMenu_ConstructVt10333648(void * self_);  // 0x10130F90
XI_API undefined4 * __thiscall TargetMenu_ConstructVt10333660(void * self_);  // 0x101312E0
XI_API void * __thiscall TargetMenu_ConstructVt10333670(void * self_);  // 0x10131530
XI_API void * __thiscall TargetMenu_ConstructVt10333728(void * self_);  // 0x10131940
XI_API void * __thiscall TargetMenu_ConstructVt103337E0(void * self_);  // 0x10133310
XI_API undefined4 __cdecl TargetMenu_Is1FFDifferentFromActer(int param_1);  // 0x10133A40
XI_API void * __thiscall TargetMenu_ConstructVt10333898(void * self_);  // 0x10135850
XI_API void * __thiscall TargetMenu_ConstructVt10333908(void * self_, undefined4 param_1);  // 0x10136380
XI_API void __thiscall TargetMenu_UpdateLayout(void * self_);  // 0x10136560
XI_API void __attribute__((stdcall, regparm(3))) TargetMenu_LayoutMessage(uint32_t xi_eax_unused, undefined4 param_2, int param_1, char * param_3, undefined4 param_4, undefined4 param_5);  // 0x10136670
XI_API undefined4 __thiscall TargetMenu_SetPosition(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3);  // 0x10136870
XI_API void * __thiscall TargetMenu_ClearBlock(void * self_);  // 0x10136900
XI_API void * __thiscall TargetMenu_ConstructVt10333950(void * self_, undefined4 param_1);  // 0x10136950
XI_API void __cdecl TargetMenu_CloseRem4lineMenu(void);  // 0x101369B0
XI_API void * __thiscall TargetMenu_ConstructVt103339A0(void * self_, undefined4 param_1);  // 0x101369C0
XI_API void __cdecl TargetMenu_CloseRem4li2Menu(void);  // 0x10136A20
XI_API void * __thiscall TargetMenu_ConstructVt103339F0(void * self_, undefined4 param_1);  // 0x10136A30
XI_API void * __thiscall TargetMenu_ConstructVt10333A40(void * self_, undefined4 param_1);  // 0x10136E20
XI_API void * __thiscall TargetMenu_ConstructVt10333A90(void * self_, undefined4 param_1);  // 0x10136EC0
XI_API void * __thiscall TargetMenu_ConstructVt10333AE0(void * self_, undefined4 param_1);  // 0x10136F60
XI_API void __thiscall TargetMenu_CollectEntries(void * self_, int param_1);  // 0x101371E0
XI_API undefined4 __thiscall TargetMenu_HasFreeEntryNotKind12(void * self_);  // 0x10137550
XI_API void * __thiscall TargetMenu_ConstructVt10333B68(void * self_);  // 0x10137630
XI_API void * __thiscall TargetMenu_ConstructVt10333BB0(void * self_);  // 0x10138960
XI_API void __thiscall TargetMenu_ClearRanges(void * self_);  // 0x10138EC0
XI_API undefined1 __cdecl TargetMenu_IsAlwaysTrue(void);  // 0x10138FB0
XI_API void * __thiscall TargetMenu_ConstructVt10333CB0(void * self_);  // 0x10139840
XI_API void * __thiscall TargetMenu_ConstructVt10333D10(void * self_);  // 0x10139EE0
XI_API void __thiscall TargetMenu_CallIfNot3(void * self_, int param_1);  // 0x10139FF0
XI_API void __thiscall TargetMenu_TickHelp(void * self_);  // 0x1013A010
XI_API int __thiscall TkHelp_AdvanceTimer(void * self_);  // 0x1013A030
XI_API undefined4 __attribute__((cdecl, regparm(1))) TargetMenu_IsEvent(undefined4 xi_eax);  // 0x1013A060
XI_API undefined4 __thiscall TargetMenu_AdvanceHelpTimer(void * self_);  // 0x1013A070
XI_API undefined4 __attribute__((stdcall, regparm(3))) TargetMenu_ResetHelpAndTitle(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x1013A100
XI_API void * __thiscall TargetMenu_ConstructVt10333D18(void * self_);  // 0x1013A1E0
XI_API void __thiscall TargetMenu_ForwardToPanel(void * self_, uint8_t * xi_s1, undefined4 xi_s2);  // 0x1013A320
XI_API void __thiscall TargetMenu_TickMember20AndHelp(void * self_, undefined4 xi_s1);  // 0x1013A330
XI_API void __thiscall TargetMenu_DrawPanel(void * self_);  // 0x1013A350
XI_API void * __thiscall TargetMenu_CtorVt10333D78(void * self_);  // 0x1013A480
XI_API void * __thiscall TargetMenu_CtorVt10333DD8(void * self_);  // 0x1013A930
XI_API void * __thiscall TargetMenu_CtorVt10333E20(void * self_);  // 0x1013AA60
XI_API void * __thiscall TargetMenu_CtorVt10333E70(void * self_);  // 0x1013AB20
XI_API void * __thiscall TargetMenu_CtorVt10333EC0(void * self_);  // 0x1013BE50
XI_API undefined4 __thiscall TargetMenu_InitFields1CTo3A7(void * self_);  // 0x1013BF40
XI_API undefined4 __thiscall TargetMenu_Forward1013E590(void * self_);  // 0x1013BFB0
XI_API void __thiscall TargetMenu_InitFromTables(void * self_);  // 0x1013BFC0
XI_API void __thiscall TargetMenu_Call1013E560(void * self_);  // 0x1013C110
XI_API undefined4 __thiscall TargetMenu_SetRowCount(void * self_, int param_1);  // 0x1013C180
XI_API void __thiscall TargetMenu_OpenWithOptions(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);  // 0x1013E3B0
XI_API undefined4 __thiscall TargetMenu_DockWindowLeft(void * self_);  // 0x1013E4F0
XI_API undefined4 __thiscall TargetMenu_GetWindowRect(void * self_, undefined4 * param_1);  // 0x1013E560
XI_API undefined4 __thiscall TargetMenu_PlaceByLayout(void * self_);  // 0x1013E590
XI_API void * __thiscall TargetMenu_CtorVt10333F28(void * self_);  // 0x1013E7F0
XI_API undefined8 __cdecl TargetMenu_Is100EBE60Positive(void);  // 0x1013EFF0
XI_API void * __thiscall TargetMenu_InitFromShape(void * self_);  // 0x1013FBE0
XI_API void __attribute__((stdcall, regparm(3))) TargetMenu_SetupMenuEntriesByState(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x10140090
XI_API undefined4 __attribute__((stdcall, regparm(3))) TargetMenu_UpdateEntryStates(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, undefined4 param_2);  // 0x10140270
XI_API void __thiscall TargetMenu_ReadWindowRect14(void * self_);  // 0x10140890
XI_API undefined4 __attribute__((stdcall, regparm(3))) TargetMenu_ReadWindowRect14IfSet(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x101408A0
XI_API void * __thiscall TargetMenu_CtorVt10334070(void * self_);  // 0x10140950
XI_API void * __thiscall TargetMenu_CtorVt103340D0(void * self_);  // 0x10140E70
XI_API void __thiscall TargetMenu_DestroyDrawMenu(void * self_);  // 0x10141AD0
XI_API void * __thiscall TargetMenu_CtorVt10334200(void * self_);  // 0x101436C0
XI_API void * __thiscall TargetMenu_CtorVt10334260(void * self_);  // 0x10144680
XI_API void * __thiscall TargetMenu_CreateAll(void * self_);  // 0x10144D60
XI_API void * __thiscall TargetMenu_Construct(void * self_);  // 0x10144F40
XI_API void * __thiscall TargetMenu_CtorVt10334928(void * self_);  // 0x10146340
XI_API void __thiscall TargetMenu_Set(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);  // 0x10146930
XI_API void __thiscall TargetMenu_SetCopy(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);  // 0x10146960
XI_API void * __thiscall TargetMenu_CtorVt10334970(void * self_);  // 0x101475B0
XI_API void * __thiscall TargetMenu_CtorVt103349B8(void * self_);  // 0x10148430
XI_API void * __thiscall TargetMenu_CtorVt10334A00(void * self_);  // 0x10148640
XI_API void * __thiscall YkWndList_Construct(void * self_);  // 0x10148ED0
XI_API void * __thiscall TargetMenu_CtorVt10334AB8(void * self_);  // 0x1014A170
XI_API void * __thiscall TargetMenu_CtorVt10334B28(void * self_);  // 0x1014A7D0
XI_API void * __thiscall TargetMenu_CtorVt10334B98(void * self_);  // 0x1014B670
XI_API void * __thiscall TargetMenu_CtorVt10334C08(void * self_);  // 0x1014BA60
XI_API void * __thiscall TargetMenu_CtorVt10334D00(void * self_);  // 0x1014C750
XI_API void * __thiscall TargetMenu_CtorVt10334D60(void * self_);  // 0x1014D970
XI_API void * __thiscall TargetMenu_CtorVt10334DC0(void * self_);  // 0x1014DD30
XI_API undefined4 __thiscall TargetMenu_FillTable13CMinusOne(void * self_);  // 0x1014E020
XI_API undefined4 __stdcall TargetMenu_Fill8DwordsMinusOne(undefined4 * param_1);  // 0x1014E050
XI_API void * __thiscall TargetMenu_CtorVt10334E58(void * self_);  // 0x1014EDC0
XI_API void * __thiscall TargetMenu_CtorVt10334EB8(void * self_);  // 0x1014F840
XI_API void * __thiscall TargetMenu_CtorVt10334F18(void * self_);  // 0x1014FFE0
XI_API void __attribute__((stdcall, regparm(3))) TargetMenu_UpdateTargetMarker(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, undefined4 xi_s1);  // 0x10150090
XI_API void __thiscall TargetMenu_DockAndInit(void * self_);  // 0x10150870
XI_API void __thiscall TargetMenu_ReadWindowRects(void * self_);  // 0x101508F0
XI_API void __thiscall TargetMenu_SetName(void * self_, char * param_1);  // 0x10150A30
XI_API void __thiscall TargetMenu_SetField48(void * self_, undefined4 param_1);  // 0x10150A60
XI_API void __thiscall TargetMenu_CopyList6To78(void * self_);  // 0x10150A70
XI_API void * __thiscall TargetMenu_CtorVt10334F78(void * self_);  // 0x10150AB0
XI_API void __thiscall TargetMenu_SetTextFwd(void * self_, int param_1, int param_2);  // 0x10150CC0
XI_API void __thiscall TargetMenu_SetText(void * self_, int param_1, int param_2);  // 0x10150CE0
XI_API undefined4 __thiscall TargetMenu_IsField8Zero(void * self_);  // 0x10150D90
XI_API void * __thiscall TargetMenu_CtorVt10335060(void * self_);  // 0x10151040
XI_API void __thiscall TargetMenu_ClearFields(void * self_);  // 0x10151140
XI_API void __cdecl TargetMenu_GetMessageFwd(int param_1, undefined4 param_2);  // 0x10152EF0
XI_API void __cdecl TargetMenu_GetMessage(int param_1, undefined4 param_2);  // 0x10152F20
XI_API void __cdecl TargetMenu_Clear32(void);  // 0x10152F80
XI_API undefined4 __cdecl TargetMenu_ReleaseAll32(void);  // 0x10152FA0
XI_API undefined4 __cdecl TargetMenu_ReleaseOne(int param_1);  // 0x10152FC0
XI_API undefined4 __cdecl TargetMenu_LoadMessageBlock(int param_1, int param_2);  // 0x10152FF0
XI_API int __cdecl TargetMenu_GetEntryPtr(int param_1, int param_2);  // 0x10153090
XI_API int __cdecl TargetMenu_GetEntryPtrByLayout(int param_1, int param_2);  // 0x101530C0
XI_API int __cdecl TargetMenu_GetEntryWord3E(int param_1, int param_2);  // 0x10153100
XI_API undefined4 __cdecl TargetMenu_IsMinus6Word(char * param_1);  // 0x10153130
XI_API void __cdecl TargetMenu_FormatMessage4(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 xi_s5);  // 0x10153150
XI_API void __cdecl TargetMenu_FormatMessage5(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 xi_s6);  // 0x10153180
XI_API int __cdecl TargetMenu_Read2Byte7Bit(uint8_t * param_1);  // 0x101531B0
XI_API undefined4 __cdecl TargetMenu_ReadArgCode(uint32_t * param_1, char * param_2, int param_3);  // 0x101531D0
XI_API int __cdecl TargetMenu_FormatDecimal(int param_1, uint32_t param_2, int param_3);  // 0x10153230
XI_API undefined4 __cdecl TargetMenu_Call101532B0OnWordBE(undefined1 * xi_s1);  // 0x101532F0
XI_API int __cdecl TargetMenu_ExpandMessageCodes(int param_1, int param_2, undefined4 param_3, undefined4 param_4, int param_5, undefined4 param_6);  // 0x10153310
XI_API int __cdecl TargetMenu_FormatMessageWithArgs(int param_1, int param_2, int param_3, int param_4, int param_5, undefined4 * param_6);  // 0x10153A40
XI_API undefined4 __cdecl TargetMenu_LoadMessageBlocksSetA(void);  // 0x10153AF0
XI_API undefined4 __cdecl TargetMenu_LoadMessageBlocksSetB(void);  // 0x10153B30
XI_API undefined4 __cdecl TargetMenu_LoadAllMessageTables(void);  // 0x10153C10
XI_API undefined4 __cdecl TargetMenu_LoadStringTable(void * param_1, int param_2);  // 0x10153EF0
XI_API void __thiscall TargetMenu_DtorVt103350EC(void * self_);  // 0x10153F80
XI_API undefined * __cdecl TargetMenu_GetInstance(void);  // 0x10153FF0
XI_API void * __thiscall TargetMenu_MessageSetCtor(void * self_);  // 0x10154070
XI_API uint32_t __stdcall TargetMenu_LoadMessageSetByState(void * param_1, uint16_t * param_2);  // 0x101542B0
XI_API int __thiscall TargetMenu_IndexOf(void * self_, undefined4 param_1);  // 0x101544F0
XI_API undefined4 __thiscall TargetMenu_GetByValue(void * self_, undefined4 param_1);  // 0x10154520
XI_API undefined1 * __thiscall TargetMenu_GetEntryOrEmpty(void * self_, int param_1);  // 0x10154550
XI_API char __thiscall TargetMenu_LoadMessageSet(void * self_);  // 0x10154570
XI_API void __thiscall TargetMenu_ReleaseField7C(void * self_);  // 0x10154840
XI_API void __thiscall TargetMenu_UpdatePendingRead(void * self_);  // 0x10154860
XI_API undefined4 __thiscall TargetMenu_GetCount(void * self_);  // 0x101549E0
XI_API undefined4 __thiscall TargetMenu_GetWordAt(void * self_, int param_1);  // 0x101549F0
XI_API void __thiscall TargetMenu_DtorVt103350F8(void * self_);  // 0x10154A80
XI_API void __thiscall TargetMenu_CtorVt103350F8(void * self_);  // 0x10154AB0
XI_API void __thiscall Entry_Init6(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6);  // 0x10154AD0
XI_API undefined4 __thiscall Entry_ReleaseField4(void * self_);  // 0x10154DB0
XI_API undefined4 * __thiscall TargetMenu_CtorVt1033512C(void * self_);  // 0x10154DC0
XI_API void __thiscall TargetMenu_SetEntryWithStrings(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, char * param_4, char * param_5, undefined4 param_6, char * param_7);  // 0x10154E30
XI_API int __thiscall TargetMenu_GetInnerPtr10(void * self_);  // 0x10154F00
XI_API void __thiscall TargetMenu_DtorVt10335138(void * self_);  // 0x10154F30
XI_API void __thiscall TargetMenu_CtorVt10335138(void * self_);  // 0x10154F60
XI_API void __thiscall Entry_SetFields4(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);  // 0x10154FC0
XI_API undefined4 __thiscall TargetMenu_DtorVt1033515C(void * self_);  // 0x10155100
XI_API undefined4 __thiscall Entry_ReleaseField4Zero(void * self_);  // 0x10155140
XI_API void * __thiscall TargetMenu_CtorVt1033515C(void * self_);  // 0x10155160
XI_API void __thiscall TargetMenu_Assign(void * self_, int param_1, char * param_2, char * param_3, char * param_4, undefined4 param_5);  // 0x101551C0
XI_API int __thiscall TargetMenu_GetMember14(void * self_);  // 0x101552D0
XI_API undefined4 __thiscall TargetMenu_FreeBuffer(void * self_);  // 0x10155360
XI_API void * __thiscall TargetMenu_CtorVt10335168(void * self_);  // 0x10155370
XI_API void __thiscall TargetMenu_SetItemWithStrings(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, char * param_4, char * param_5, undefined4 param_6, undefined4 param_7, undefined4 param_8, char * param_9);  // 0x10155400
XI_API int __thiscall TargetMenu_GetMemberC(void * self_);  // 0x101554E0
XI_API undefined4 __thiscall TargetMenu_FreeStrings(void * self_);  // 0x10155540
XI_API void * __thiscall TargetMenu_CtorVt10335174(void * self_);  // 0x10155550
XI_API void __thiscall TargetMenu_SetString(void * self_, char * param_1);  // 0x101555B0
XI_API int __thiscall TargetMenu_GetField8(void * self_);  // 0x10155600
XI_API undefined4 __cdecl TargetMenu_Pack(undefined4 * param_1, uint32_t param_2, undefined4 param_3, undefined4 param_4, char * param_5, undefined4 param_6, undefined4 param_7, char * param_8);  // 0x10155BD0
XI_API undefined4 __cdecl TargetMenu_PackRecord7(undefined4 * param_1, uint32_t param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, char * param_6, undefined4 param_7, undefined4 param_8, char * param_9);  // 0x10155C70
XI_API undefined4 __cdecl TargetMenu_ReadDword00_10155D10(undefined4 * param_1);  // 0x10155D10
XI_API undefined4 __cdecl TargetMenu_ReadDword04_10155D20(int param_1);  // 0x10155D20
XI_API undefined4 __cdecl TargetMenu_ReadDword08_10155D30(int param_1);  // 0x10155D30
XI_API undefined4 __cdecl TargetMenu_ReadDword0C_10155D40(int param_1);  // 0x10155D40
XI_API undefined4 __cdecl TargetMenu_ReadDword10_10155D50(int param_1);  // 0x10155D50
XI_API undefined4 __cdecl TargetMenu_ReadDword14_10155D60(int param_1);  // 0x10155D60
XI_API undefined4 __cdecl TargetMenu_ReadDword18_10155D70(int param_1);  // 0x10155D70
XI_API void * __thiscall TargetMenu_ConstructText10335180(void * self_, undefined4 param_1, undefined4 param_2, char * param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6);  // 0x10155EA0
XI_API void * __thiscall TargetMenu_ConstructText10335180B(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, char * param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7);  // 0x10155F00
XI_API void __thiscall TargetMenu_InitTextRecord(void * self_, undefined4 param_1, undefined4 param_2, char * param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6);  // 0x10155F60
XI_API void __thiscall TargetMenu_InitTextRecordB(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, char * param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7);  // 0x10156080
XI_API undefined4 __thiscall TargetMenu_GetField0C(void * self_);  // 0x10156440
XI_API undefined4 __thiscall TargetMenu_GetField10(void * self_);  // 0x10156450
XI_API undefined4 __thiscall TargetMenu_GetField24(void * self_);  // 0x10156470
XI_API undefined4 __thiscall TargetMenu_GetField28(void * self_);  // 0x10156480
XI_API undefined4 __cdecl TargetMenu_PackRecord3(undefined4 * param_1, uint32_t param_2, undefined4 param_3, char * param_4, char * param_5);  // 0x10156540
XI_API undefined4 __cdecl TargetMenu_ReadDword00_101565C0(undefined4 * param_1);  // 0x101565C0
XI_API undefined4 __cdecl TargetMenu_ReadDword04_101565D0(int param_1);  // 0x101565D0
XI_API undefined4 __cdecl TargetMenu_ReadDword08_101565E0(int param_1);  // 0x101565E0
XI_API void * __thiscall TargetMenu_ConstructStringPair(void * self_, undefined4 param_1, char * param_2, char * param_3);  // 0x10156630
XI_API void __thiscall TargetMenu_InitStringPair(void * self_, undefined4 param_1, char * param_2, char * param_3);  // 0x10156660
XI_API undefined4 __thiscall TargetMenu_GetField04(void * self_);  // 0x10156840
XI_API undefined4 __thiscall TargetMenu_GetField08(void * self_);  // 0x10156850
XI_API undefined4 __thiscall TargetMenu_GetField10A(void * self_);  // 0x10156860
XI_API undefined4 __cdecl TargetMenu_PackRecordBytes(undefined1 * param_1, uint32_t param_2, undefined4 param_3, undefined4 param_4, char * param_5, char * param_6, undefined4 param_7, undefined4 param_8, undefined4 param_9, char * param_10);  // 0x10156870
XI_API undefined4 __cdecl TargetMenu_GetByte0(undefined1 * param_1);  // 0x10156930
XI_API undefined4 __cdecl TargetMenu_GetByte1(int param_1);  // 0x10156940
XI_API undefined4 __cdecl TargetMenu_GetDword4(int param_1);  // 0x10156950
XI_API undefined4 __cdecl TargetMenu_GetDword8(int param_1);  // 0x10156960
XI_API void __thiscall TargetMenu_DtorVt103351D8(void * self_);  // 0x10156970
XI_API undefined4 __thiscall TargetMenu_SetVt103351D8(void * self_);  // 0x101569A0
XI_API void * __thiscall TargetMenu_ConstructFields(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7, char * param_8);  // 0x101569B0
XI_API void __thiscall TargetMenu_SetFields(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7, char * param_8);  // 0x101569F0
XI_API undefined4 __thiscall TargetMenu_GetField10B(void * self_);  // 0x10156B20
XI_API undefined4 __thiscall TargetMenu_GetField14(void * self_);  // 0x10156B30
XI_API undefined4 __thiscall TargetMenu_GetField20(void * self_);  // 0x10156B40
XI_API undefined4 __cdecl TargetMenu_PackString(int * param_1, uint32_t param_2, char * param_3);  // 0x10156B50
XI_API undefined4 __cdecl TargetMenu_GetDword0(undefined4 * param_1);  // 0x10156BA0
XI_API void __thiscall TargetMenu_DtorVt103351FC(void * self_);  // 0x10156BB0
XI_API undefined4 __thiscall TargetMenu_InitVt103351FC(void * self_);  // 0x10156BE0
XI_API void __thiscall TargetMenu_SetField04(void * self_, undefined4 param_1);  // 0x10156BF0
XI_API undefined4 __thiscall TargetMenu_ConstructWithValue(void * self_, undefined4 param_1);  // 0x10156C00
XI_API void * __thiscall TargetMenu_TableHolderCtor(void * self_);  // 0x10156D90
XI_API void __thiscall TargetMenu_LoadTable(void * self_);  // 0x10156E00
XI_API void * __thiscall TargetMenu_TargetCtor(void * self_);  // 0x101575E0
XI_API void __thiscall TargetMenu_ClearTargetAndRedraw(void * self_);  // 0x10157610
XI_API undefined4 __attribute__((stdcall, regparm(3))) TargetMenu_ClearField68AndDraw(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x10157620
XI_API undefined4 __thiscall TargetMenu_SetTargetMode(void * self_, uint32_t param_1);  // 0x10157660
XI_API undefined4 __cdecl TargetMenu_IsTargetUnusable(void);  // 0x101576F0
XI_API void __thiscall TargetMenu_SetNormalizedPos(void * self_, int param_1, int param_2);  // 0x10157720
XI_API void __thiscall TargetMenu_SetValues3(void * self_, int param_1, int param_2);  // 0x10157780
XI_API void __thiscall TargetMenu_SetValues3Default(void * self_);  // 0x10157850
XI_API undefined4 __thiscall TargetMenu_SetFields78D0(void * self_, undefined4 param_1, undefined4 param_2);  // 0x10157860
XI_API undefined4 __attribute__((stdcall, regparm(3))) TargetMenu_GetByte75(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x10157880
XI_API undefined4 __attribute__((stdcall, regparm(3))) TargetMenu_GetByte76(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x10157890
XI_API undefined4 __attribute__((stdcall, regparm(3))) TargetMenu_GetByte77(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x101578A0
XI_API undefined4 __attribute__((stdcall, regparm(3))) TargetMenu_GetWord80(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x101578B0
XI_API undefined4 __thiscall TargetMenu_GetField7C(void * self_);  // 0x101578C0
XI_API undefined4 __thiscall Target_GetFlag82(void * self_);  // 0x101578D0
XI_API undefined4 __thiscall Target_GetFlag83(void * self_);  // 0x101578E0
XI_API void __thiscall Target_Reset(void * self_);  // 0x101578F0
XI_API void __thiscall TargetMenu_ClearFields84And88(void * self_);  // 0x101579B0
XI_API void __thiscall Target_Update(void * self_);  // 0x101579C0
XI_API undefined4 __thiscall Target_Select(void * self_, int param_1, undefined4 param_2, undefined4 param_3);  // 0x10157B40
XI_API char __thiscall Target_SelectByIndex(void * self_, int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);  // 0x10157C60
XI_API int __thiscall TargetMenu_GetTargetActorPtr74(void * self_);  // 0x10157CB0
XI_API undefined4 __thiscall TargetMenu_GetCachedUnlessFlag21(void * self_);  // 0x10157CF0
XI_API undefined4 __cdecl Menu_IsFocusNotInList(void);  // 0x10157D20
XI_API undefined4 __cdecl Target_FindCandidate(void);  // 0x10157D60
XI_API void __thiscall Target_CycleMenuStep(void * self_);  // 0x10157E20
XI_API undefined4 __attribute__((stdcall, regparm(3))) Target_IssueStateCommand(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x10157FA0
XI_API void __attribute__((stdcall, regparm(3))) Target_UpdateSelectionByState(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x101581E0
XI_API void __thiscall Target_InvokeFieldCallback(void * self_);  // 0x101582F0
XI_API void __thiscall Target_UpdateActorFlags138(void * self_);  // 0x101583F0
XI_API undefined4 __thiscall Target_HasActor(void * self_);  // 0x10158470
XI_API undefined4 __attribute__((stdcall, regparm(3))) Target_UpdateSelection(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x10158480
XI_API void __thiscall Target_SendAttackOff(void * self_);  // 0x10158510
XI_API int * __thiscall Target_GetActor(void * self_);  // 0x10158550
XI_API undefined4 __thiscall Target_Clear(void * self_);  // 0x10158590
XI_API undefined4 __thiscall Target_RunActiveCommand(void * self_);  // 0x101585F0
XI_API undefined4 __cdecl TargetMenu_FindActiveCommand(undefined4 * param_1);  // 0x101587B0
XI_API undefined4 __attribute__((cdecl, regparm(1))) TargetMenu_IsCommand76Or77Active(undefined4 xi_eax);  // 0x10158AA0
XI_API undefined4 __attribute__((stdcall, regparm(3))) TargetMenu_MoveByDirectionIf58(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, undefined4 xi_s1);  // 0x10158AE0
XI_API undefined4 __attribute__((stdcall, regparm(3))) Target_TrySubSelect(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, undefined4 param_2);  // 0x10158B00
XI_API undefined4 __thiscall Target_ActOrTrySubSelect(void * self_, int param_1);  // 0x10158B40
XI_API int __thiscall Target_CycleEntryTarget(void * self_);  // 0x10158B60
XI_API undefined4 __thiscall Target_CycleInView(void * self_, undefined4 param_1);  // 0x10158C40
XI_API int * __thiscall Target_CycleInViewOrFirst(void * self_, undefined4 param_1);  // 0x10158CA0
XI_API undefined4 __thiscall Target_PickNearestToPoint(void * self_);  // 0x10158D90
XI_API undefined4 __thiscall Target_ApplyAction(void * self_, undefined4 param_1);  // 0x10158DB0
XI_API undefined4 __thiscall Target_ClearAll(void * self_);  // 0x10158FF0
XI_API undefined4 __attribute__((stdcall, regparm(3))) Target_CommitSubTarget(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x10159040
XI_API undefined4 __thiscall Target_ClearAndSetFlag53(void * self_);  // 0x101590A0
XI_API void __thiscall Target_SetDisplayName(void * self_, int * param_1);  // 0x101590C0
XI_API void __thiscall Target_SetFlagsFromMask(void * self_, uint32_t param_1);  // 0x10159170
XI_API undefined4 __thiscall Target_IsUsable(void * self_);  // 0x101591D0
XI_API int __thiscall TargetMenu_GetField84Ptr(void * self_);  // 0x10159370
XI_API undefined * __thiscall Yk_GetActiveEntryById(void * self_);  // 0x10159380
XI_API undefined4 __cdecl Actor_SetSlotTableEntry(uint32_t param_1, undefined4 param_2);  // 0x10159400
XI_API undefined4 __cdecl Target_DispatchByIndex(int param_1, undefined4 param_2);  // 0x10159420
XI_API undefined4 __thiscall Target_SetIfUsable(void * self_, undefined4 param_1, undefined4 param_2);  // 0x10159440
XI_API void __thiscall Target_SetHandlerCc(void * self_, undefined4 param_1);  // 0x101594D0
XI_API void __thiscall Target_SetHandlerC8(void * self_, undefined4 param_1);  // 0x101594E0
XI_API undefined4 __thiscall Target_ReleaseSelection(void * self_);  // 0x101594F0
XI_API void * __thiscall Target_ResetRecordReturnSelf(void * self_);  // 0x10159530
XI_API undefined4 __attribute__((stdcall, regparm(3))) Target_IsRecordStillValid(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x10159540
XI_API undefined4 __thiscall Target_CanTarget(void * self_, int param_1);  // 0x101595D0
XI_API undefined4 __thiscall Target_SetActor(void * self_, void * param_1);  // 0x10159660
XI_API undefined4 __thiscall Target_ResetRecord(void * self_);  // 0x10159740
XI_API undefined4 __thiscall Target_RefreshActor(void * self_);  // 0x10159780
XI_API undefined4 __thiscall Entry_InitKey(void * self_, undefined4 param_1, undefined4 param_2);  // 0x101597C0
XI_API uint32_t __thiscall Entry_ValidateKey(void * self_);  // 0x101597F0
XI_API void __thiscall Entry_SetNameAndKey(void * self_, char * param_1, int * param_2);  // 0x10159830
XI_API undefined4 __thiscall Target_GetPosShortsMainOrSub(void * self_, undefined2 * param_1, undefined2 * param_2, undefined4 param_3);  // 0x10159880
XI_API undefined4 __thiscall Target_GetCachedIfValid(void * self_);  // 0x101598A0
XI_API undefined4 __thiscall Target_GetActorPtr(void * self_);  // 0x101598B0
XI_API undefined4 __thiscall TargetMenu_IsWithinRadius(void * self_, float param_1);  // 0x101598C0
XI_API uint32_t __thiscall Entry_MatchesPair(void * self_, int * param_1);  // 0x10159910
XI_API undefined4 __thiscall TargetMenu_MoveByDirection(void * self_, undefined4 param_1);  // 0x10159970
XI_API undefined4 __thiscall TargetMenu_ApplyOffset(void * self_, float * param_1);  // 0x10159A20
XI_API void __stdcall Camera_RotateVecYaw(float * param_1);  // 0x10159B10
XI_API undefined4 __thiscall TargetMenu_GetPositionIfValid(void * self_, undefined4 * param_1);  // 0x10159C80
XI_API undefined4 __thiscall TargetMenu_GetOffsetFromCachedActor(void * self_, float * param_1);  // 0x10159CC0
XI_API undefined4 __thiscall Target_GetPosShorts(void * self_, undefined2 * param_1, undefined2 * param_2);  // 0x10159D40
XI_API int * __thiscall Entry_ResolveValid(void * self_);  // 0x10159DE0
XI_API uint32_t __attribute__((cdecl, regparm(1))) Entry_IsActorFieldMatch(undefined4 xi_eax, int * param_1);  // 0x10159E10
XI_API int __cdecl TargetMenu_FindRange(uint32_t param_1);  // 0x10159EB0
XI_API undefined4 * __cdecl TargetMenu_FindByFirstDword(int param_1);  // 0x10159FB0
XI_API undefined4 __attribute__((stdcall, regparm(3))) TargetMenu_CallMember14CCSlot0(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x1015AF60
XI_API void * __thiscall TargetMenu_Init(void * self_);  // 0x1015AF80
XI_API undefined8 __thiscall TargetMenu_ResetState(void * self_);  // 0x1015AFA0
XI_API uint32_t __thiscall TargetMenu_IsCachedPtrMatch(void * self_);  // 0x1015B190
XI_API undefined4 __thiscall TargetMenu_GetObjectPtr(void * self_);  // 0x1015B270
XI_API void __thiscall TargetMenu_RotateBufferOnce(void * self_);  // 0x1015B3C0
XI_API void __thiscall TargetMenu_WrapTextLines(void * self_);  // 0x1015B410
XI_API void * __thiscall TargetMenu_FillSceneTable(void * self_);  // 0x1015B720
XI_API int __thiscall TargetMenu_FindCachedEntry(void * self_, int param_1, undefined4 param_2);  // 0x1015B970
XI_API uint32_t __thiscall TargetMenu_GetCachedOrLoad(void * self_, uint32_t param_1);  // 0x1015B9E0
XI_API undefined * __cdecl TargetMenu_FindEmptySlot(void);  // 0x1015BAF0
XI_API void __cdecl TargetMenu_OnBufferEvent(undefined4 param_1, int param_2, void * param_3);  // 0x1015BB80
XI_API undefined4 __stdcall TargetMenu_LookupObjectPtr(int param_1);  // 0x1015BD40
XI_API void __cdecl TargetMenu_RotateBits3(int param_1);  // 0x1015D7F0
XI_API undefined1 __cdecl MenuMng_ReinitState(void);  // 0x1015D860
XI_API void __thiscall MenuMng_Init(void * self_);  // 0x1015D900
XI_API undefined4 __thiscall MenuMng_ResetFields(void * self_);  // 0x1015D9A0
XI_API void __thiscall NetCellFont_InsertSortedBy60(void * self_, int param_1);  // 0x1015DB10
XI_API void __stdcall Menu_SetFlag76(int param_1);  // 0x1015DB70
XI_API void __thiscall TargetMenu_MenuForwardItem8(void * self_, int param_1, undefined4 param_2);  // 0x1015DBB0
XI_API void __thiscall NetCellFont_RemoveMatching(void * self_, int param_1);  // 0x1015DBD0
XI_API int __thiscall Menu_FindItemByName(void * self_, char * param_1);  // 0x1015DC10
XI_API undefined4 __stdcall Menu_LookupWindowByName(char * param_1, undefined1 * param_2);  // 0x1015DC70
XI_API undefined4 __thiscall TargetMenu_MenuTest48OrStateB4(void * self_);  // 0x1015DCE0
XI_API undefined8 __thiscall Menu_HandleEvent(void * self_, undefined4 param_1);  // 0x1015DD00
XI_API undefined4 __thiscall Menu_TrackCursor(void * self_);  // 0x1015DD90
XI_API undefined4 __thiscall Menu_HandleCursorSelect(void * self_);  // 0x1015DE50
XI_API int __thiscall TargetMenu_MenuHasFocusedItemFwd(void * self_);  // 0x1015DEE0
XI_API undefined4 __thiscall Menu_DispatchEvent6(void * self_);  // 0x1015DEF0
XI_API void __thiscall Menu_DispatchEvent7(void * self_);  // 0x1015DF20
XI_API void __stdcall TargetMenu_GetCursorPos(undefined4 * param_1);  // 0x1015DF60
XI_API void __stdcall TargetMenu_Nop(undefined4 xi_s1);  // 0x1015DFC0
XI_API int __thiscall Menu_FindItemByNameAt1C(void * self_, char * param_1);  // 0x1015E030
XI_API undefined4 __thiscall MenuMng_TestNameForSceneState(void * self_, char * param_1);  // 0x1015E0F0
XI_API int __thiscall MenuMng_OpenByName(void * self_, char * param_1, undefined4 param_2, undefined4 param_3);  // 0x1015E350
XI_API undefined4 __attribute__((stdcall, regparm(3))) MenuMng_AttachWindowAndPosition(short * xi_eax, uint32_t xi_edx_unused, void * self_, int param_2);  // 0x1015E530
XI_API undefined4 __attribute__((stdcall, regparm(3))) TargetMenu_MenuItemFade(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, void * param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6);  // 0x1015E6E0
XI_API undefined4 __attribute__((stdcall, regparm(3))) TargetMenu_MenuInitAndFadeItem(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, int param_2, undefined4 param_3);  // 0x1015E790
XI_API int __thiscall Menu_FindFirstActiveItem(void * self_);  // 0x1015E7E0
XI_API undefined4 __attribute__((stdcall, regparm(3))) Menu_SetItemAt54(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, int param_2);  // 0x1015E850
XI_API void __attribute__((stdcall, regparm(3))) Menu_RemoveAndFreeItem(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, int param_2);  // 0x1015E8A0
XI_API undefined4 __thiscall Menu_CloseEntry(void * self_, char * param_1);  // 0x1015E910
XI_API void __stdcall Menu_FindWindowDefByName(int param_1, uint8_t * param_2);  // 0x1015E950
XI_API void __thiscall Menu_CloseQuery(void * self_, undefined4 xi_s1);  // 0x1015EB60
XI_API int __thiscall TargetMenu_SetMinId6C(void * self_, undefined4 param_1, undefined4 param_2);  // 0x1015EC20
XI_API undefined4 __stdcall Menu_FindByName(char * param_1);  // 0x1015EC50
XI_API undefined4 __stdcall Menu_FindByFlags34(uint32_t param_1);  // 0x1015ECC0
XI_API undefined4 __stdcall Menu_FindByFlags38(undefined4 param_1, uint32_t param_2, undefined4 param_3);  // 0x1015ED10
XI_API undefined4 __thiscall Menu_IsFocusedItem(void * self_, int param_1);  // 0x1015ED80
XI_API int __thiscall Menu_HasFocusedItem(void * self_);  // 0x1015EDB0
XI_API undefined8 __attribute__((stdcall, regparm(3))) TargetMenu_MenuTestItem34Or6B(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, int param_2);  // 0x1015EDD0
XI_API undefined8 __stdcall Menu_NextVisibleItem(int * param_1);  // 0x1015EE00
XI_API uint32_t __stdcall TargetMenu_GetNodeIfNotClosed(int * param_1);  // 0x1015EE20
XI_API undefined4 __cdecl Menu_OpenMenuWindowWhenIdle(void);  // 0x1015EE40
XI_API void __cdecl Menu_CallSlot30ForEachEntry(void);  // 0x1015EEF0
XI_API void __thiscall Menu_CallChildSlot34ForEachItem(void * self_);  // 0x1015EF20
XI_API void __thiscall MenuMng_UpdateForSceneState(void * self_);  // 0x1015EF60
XI_API undefined4 __thiscall Menu_ApplyFlagsToItems(void * self_, uint32_t param_1);  // 0x1015F3E0
XI_API void __thiscall Menu_DrawLayers(void * self_);  // 0x1015F6A0
XI_API undefined4 __thiscall UI_DockReset(void * self_, int param_1, int param_2);  // 0x1015F760
XI_API undefined4 __stdcall Menu_PositionWindow(int * param_1, int param_2);  // 0x1015F790
XI_API undefined4 __stdcall TargetMenu_MenuGetItemRect(int * param_1, short * param_2);  // 0x1015F8F0
XI_API undefined4 __thiscall Menu_GetDwordAt8C(void * self_, undefined4 param_1);  // 0x1015F960
XI_API int __cdecl TargetMenu_ResolveLayoutIndex(int param_1);  // 0x1015F980
XI_API undefined4 __thiscall TargetMenu_MenuGetLayoutWord(void * self_, int param_1);  // 0x1015F9C0
XI_API int __thiscall Menu_GetWordPtrAtA0(void * self_, int param_1);  // 0x1015F9E0
XI_API void __thiscall Menu_DrawAll(void * self_);  // 0x1015FA00
XI_API undefined8 __thiscall Menu_GetNormalizedPos(void * self_, float * param_1, float * param_2);  // 0x101601D0
XI_API undefined8 __thiscall TargetMenu_GetScaledPos80(void * self_, float * param_1, float * param_2);  // 0x10160210
XI_API long double __thiscall MenuMng_GetOffsetX(void * self_, undefined4 param_2);  // 0x10160290
XI_API long double __thiscall MenuMng_GetOffsetY(void * self_, undefined4 param_2);  // 0x101602C0
XI_API void __thiscall Menu_ReloadResource(void * self_, undefined4 * param_1, int param_2);  // 0x10160440
XI_API int __cdecl Gfx_SetDefault2DStates(void);  // 0x101604B0
XI_API int __cdecl Gfx_DisableFogAndAlphaBlend(void);  // 0x10160650
XI_API undefined4 __attribute__((stdcall, regparm(3))) Menu_GetStateB4(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x101606F0
XI_API undefined4 __attribute__((stdcall, regparm(3))) Menu_IsStateB4Eq1(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x10160700
XI_API undefined4 __attribute__((stdcall, regparm(3))) Menu_SetStateB4(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, undefined4 param_2);  // 0x10160710
XI_API void __thiscall MenuMng_BuildMenuName(void * self_, char * param_1, char * param_2);  // 0x10160760
XI_API void __cdecl TargetMenu_OpenNoticeDialog101608B0(void);  // 0x10160960
XI_API void __cdecl YkWindows_DestroyDrawMenuIfAt14(void);  // 0x101609C0
XI_API undefined4 __cdecl TargetMenu_OpenNoticeDialog101608D0(void);  // 0x101609F0
XI_API void __cdecl YkWindows_CloseIfAt14(void);  // 0x10160A50
XI_API undefined4 __attribute__((stdcall, regparm(3))) TargetMenu_GetByteAE(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x10160C80
XI_API undefined4 __thiscall Menu_GetFocusedItem(void * self_);  // 0x10160C90
XI_API void * __thiscall TargetMenu_CtorVt10335334(void * self_);  // 0x10160DB0
XI_API void * __thiscall TargetMenu_CtorVt10335350(void * self_);  // 0x10161110
XI_API void * __thiscall TargetMenu_CtorVt1033536C(void * self_);  // 0x10161380
XI_API void * __thiscall TargetMenu_CtorVt10335388(void * self_);  // 0x101615E0
XI_API void * __thiscall TargetMenu_CtorVt10335410(void * self_, undefined4 param_1);  // 0x10161850
XI_API void __attribute__((stdcall, regparm(3))) TargetMenu_SetByte5A(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, undefined4 param_2);  // 0x10161870
XI_API undefined1 __attribute__((cdecl, regparm(1))) TargetMenu_ReturnTrue(undefined4 xi_eax);  // 0x10161890
XI_API undefined4 __cdecl TargetMenu_ReturnZero(void);  // 0x101618D0
XI_API void __thiscall TargetMenu_CallSlot17Then1626E0(void * self_, undefined4 param_1);  // 0x10161970
XI_API undefined4 __attribute__((stdcall, regparm(3))) TargetMenu_DrawImageAtRightOfRect(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x10161990
XI_API void * __thiscall TargetMenu_CtorVt10335470(void * self_, undefined4 param_1);  // 0x10161B80
XI_API undefined1 __attribute__((cdecl, regparm(1))) TargetMenu_ReturnFalse(undefined4 xi_eax);  // 0x10161BA0
XI_API undefined4 __cdecl TargetMenu_HasActiveObject10621940(void);  // 0x10161BC0
XI_API undefined4 __cdecl TargetMenu_Return8(void);  // 0x10161BE0
XI_API void __thiscall Menu_PositionWindowBySetting(void * self_, undefined4 xi_s1);  // 0x10161C70
XI_API undefined4 __attribute__((stdcall, regparm(3))) TargetMenu_DrawImageA4AtRightOfRect(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x10161D60
XI_API void * __thiscall TargetMenu_InitFromScreenRect(void * self_, undefined4 param_1);  // 0x10161ED0
XI_API undefined4 __cdecl TargetMenu_SetTopByte(uint32_t * param_1, int param_2);  // 0x10161FF0
XI_API int __cdecl Viewport_SetClipped(int a1, int a2);  // 0x10162010
XI_API int __cdecl Gfx_ApplyViewport1904(void);  // 0x101620B0
XI_API void __cdecl Font_SetupAdditiveDraw(void);  // 0x101620D0
XI_API void __thiscall TargetMenu_ScrollBackStep(void * self_);  // 0x101624B0
XI_API int __cdecl TargetMenu_StepToward(int param_1, int param_2, undefined4 param_3);  // 0x10162CC0
XI_API void __thiscall TargetMenu_SetFlag58AndResetScroll(void * self_, undefined4 param_1);  // 0x10162E00
XI_API void __thiscall TargetMenu_SetLineCount(void * self_, undefined4 param_1);  // 0x10162E20
XI_API void __thiscall TargetMenu_SetShownLines(void * self_, undefined4 param_1);  // 0x10162E60
XI_API void __thiscall TargetMenu_ResetScrollFwd(void * self_);  // 0x10162E90
XI_API void __thiscall TargetMenu_ResetScrollToLines(void * self_);  // 0x10162EF0
XI_API void __stdcall TargetMenu_OpenOrCloseByFlag(int param_1, undefined4 param_2);  // 0x10162F30
XI_API undefined8 __thiscall TargetMenu_UpdatePair1062193C(void * self_);  // 0x10162F60
XI_API undefined8 __thiscall TargetMenu_ApplySlot20Result(void * self_, int * param_1);  // 0x10162FB0
XI_API undefined4 __stdcall TargetMenu_ToggleTo(int * param_1, undefined4 param_2);  // 0x10162FE0
XI_API void __thiscall TargetMenu_SetWord56(void * self_, undefined4 param_1);  // 0x10163070
XI_API int __thiscall TargetMenu_GetShortAt56(void * self_);  // 0x10163080
XI_API void * __thiscall TargetMenu_CtorZeroed(void * self_);  // 0x10163090
XI_API void * __thiscall TargetMenu_ZeroWordsAndDwords(void * self_);  // 0x10163350
XI_API void __cdecl TargetMenu_NoOpE(void);  // 0x10163380
XI_API void __thiscall Obj_10621944_DrawBgRect(void * self_);  // 0x10163390
XI_API void __thiscall TargetMenu_ZeroDwords(void * self_);  // 0x101633D0
XI_API int __stdcall Gfx_DrawSolidRect2D(int a1, int a2);  // 0x10163400
XI_API void __thiscall ZoneMapLoad_ResetFieldsA(void * self_);  // 0x10163F30
XI_API void __thiscall ZoneMapLoad_ResetFieldsB(void * self_);  // 0x10163FA0
XI_API void * __thiscall ZoneMapLoad_ConstructVt10335CE8(void * self_);  // 0x101641B0
XI_API void __thiscall ZoneMapLoad_InitA640AndCopyStar(void * self_);  // 0x10164530
XI_API void __thiscall ZoneMapLoad_ResetFieldsC(void * self_);  // 0x10164560
XI_API void * __thiscall ZoneMapLoad_ConstructVt10335D30(void * self_);  // 0x10164660
XI_API void __thiscall ZoneMapLoad_ResetFieldsD(void * self_);  // 0x10164800
XI_API void __thiscall ZoneMapLoad_ResetFieldsE(void * self_);  // 0x10164980
XI_API void * __thiscall ZoneMapLoad_ConstructVt10335D78(void * self_);  // 0x10164A30
XI_API void * __thiscall ZoneMapLoad_ConstructVt10335DC0(void * self_);  // 0x10164AF0
XI_API void __cdecl ZoneMapLoad_CreateUiObjects(void);  // 0x10165070
XI_API void __cdecl ZoneMapLoad_InitGlobalTables(void);  // 0x101671D0
XI_API void * __thiscall ZoneMapLoad_Call10257860ReturnSelf(void * self_);  // 0x10167330
XI_API undefined4 __thiscall ZoneMapLoad_LoadSceneFileAndBind(void * self_);  // 0x10167340
XI_API void * __thiscall ZoneMap_ConstructVt10336614(void * self_);  // 0x10167440
XI_API void * __thiscall ZoneMap_ConstructVt10336634(void * self_);  // 0x10167800
XI_API void __thiscall ZoneMap_ReleaseBuffers(void * self_);  // 0x10167950
XI_API void __thiscall ZoneMap_UnlinkSlotCells(void * self_, int param_1);  // 0x101679A0
XI_API undefined4 __thiscall ZoneMapLoad_GetField34148(void * self_);  // 0x10168FC0
XI_API undefined4 __thiscall ZoneMap_GetCount34154(void * self_);  // 0x10168FD0
XI_API undefined4 __thiscall ZoneMapLoad_ProbeAxis1(void * self_, float * param_1, float * param_2, undefined4 param_3, float param_4, float param_5, float param_6);  // 0x10169290
XI_API uint32_t __thiscall ZoneMapLoad_SegmentHit3413A(void * self_, float * param_1, float * param_2, float * param_3);  // 0x101693B0
XI_API uint32_t __thiscall ZoneMapLoad_SegmentHit34139(void * self_, float * param_1, float * param_2, float * param_3);  // 0x10169B40
XI_API uint32_t __thiscall ZoneMapLoad_SegmentTest34139(void * self_, float * param_1, float * param_2, undefined4 xi_s3);  // 0x1016A2D0
XI_API uint32_t __thiscall ZoneMapLoad_SegmentHitGridTriangles(void * self_, float * param_1, float * param_2, float * param_3);  // 0x1016A990
XI_API undefined4 __thiscall ZoneMapLoad_SegmentHitWithObjects(void * self_, float * param_1, float * param_2, float * param_3);  // 0x1016B1D0
XI_API void __stdcall fn_1016BDF0(float * param_1, int param_2, float * param_3);  // 0x1016BDF0
XI_API void __cdecl Mat44_Multiply(float * param_1, int param_2, float * param_3);  // 0x1016C060
XI_API undefined4 __thiscall ZoneMap_GetHitCount(void * self_);  // 0x1016C150
XI_API undefined4 __stdcall ZoneMap_IsPointInTriangle(float * param_1, int param_2);  // 0x1016C390
XI_API void __thiscall ZoneMapLoad_SegmentHitObjectTriangles(void * self_, float * param_1, int param_2, float * param_3, float * param_4, float * param_5, float * param_6, float * param_7);  // 0x1016C5D0
XI_API undefined4 __stdcall ZoneMapLoad_TriangleNormal(int param_1, int param_2);  // 0x1016CB60
XI_API int __stdcall Dbg_DrawTriangleLines(int a1, int a2, int a3);  // 0x1016DDF0
XI_API uint64_t __thiscall ZoneMapLoad_SweepSetupAndTest(void * self_, float * param_1, float * param_2, float * param_3);  // 0x1016E930
XI_API undefined4 __thiscall ZoneMapLoad_SweepStep(void * self_, float * param_1, float * param_2);  // 0x1016F0E0
XI_API void * __thiscall ZoneMap_ConstructVt10336668(void * self_);  // 0x1016FC40
XI_API undefined4 __thiscall ZoneMapLoad_ClearListFields(void * self_);  // 0x1016FC90
XI_API _DWORD * __thiscall ParseZoneMeshData(void *self_, int *a2, int a3, int a4, int a5, int a6, _DWORD *a7, int a8);  // 0x1016FCD0
XI_API undefined4 __thiscall ZoneMapLoad_FreeNodeOrAll(void * self_, undefined4 * param_1);  // 0x10170CD0
XI_API int * __thiscall ZoneMap_FindEntryByName(void * self_, char * param_1, int param_2);  // 0x10170F30
XI_API void * __thiscall ZoneMap_ConstructVt1033668C(void * self_);  // 0x101718E0
XI_API undefined4 __stdcall ZoneMap_FindDbgBoxMPosById(undefined4 * param_1, int param_2);  // 0x10173AE0
XI_API void __thiscall ZoneMap_ResetDbgBoxList(void * self_);  // 0x10174770
XI_API void __thiscall ZoneMap_FreeDbgBoxList(void * self_);  // 0x10174A60
XI_API int __cdecl Dbg_DrawOrientedBoxes(void);  // 0x10174EC0
XI_API void __cdecl Mat4_SetIdentity_2(undefined4 * param_1);  // 0x10175740
XI_API float * __thiscall ZoneMap_FindDbgBoxHitBySegment(void * self_, float * param_1, float * param_2);  // 0x10176620
XI_API undefined4 __attribute__((stdcall, regparm(1))) ZoneMapLoad_SetFlag2000OnUnderscoreEntries(undefined4 xi_eax, int param_1);  // 0x10176DD0
XI_API undefined4 * __attribute__((stdcall, regparm(3))) ZoneMapLoad_ConstructResource10336698(uint32_t xi_eax_unused, undefined4 xi_edx, undefined4 * param_1);  // 0x10176E80
XI_API undefined4 * __attribute__((stdcall, regparm(3))) ZoneResWeather_Construct(uint32_t xi_eax_unused, undefined4 xi_edx, undefined4 * param_1);  // 0x10176F60
XI_API undefined4 * __attribute__((stdcall, regparm(3))) ZoneResource_Construct(uint32_t xi_eax_unused, undefined4 xi_edx, undefined4 * param_1);  // 0x10176FE0
XI_API int __stdcall Gfx_CompileVertexShader(int a1, int a2);  // 0x101771B0
XI_API int __thiscall Gfx_AssembleVertexShader(void *self_, int a1, int a2);  // 0x10177240
XI_API int __thiscall Gfx_CompilePixelShader(const char **self_, int a2);  // 0x101772E0
XI_API undefined4 * __cdecl ZoneMap_GetMatrixGlobal(void);  // 0x101773F0
XI_API int __cdecl Gfx_SetZBias(unsigned int a1);  // 0x10177400
XI_API void __thiscall ZoneMap_SetOverlayProjection(void * self_);  // 0x10177420
XI_API uint32_t __attribute__((cdecl, regparm(1))) ZoneMap_QueryBoxHeightGlobal(undefined4 xi_eax, undefined4 param_1, undefined4 param_2, undefined4 param_3, float * param_4);  // 0x10177770
XI_API undefined4 __thiscall ZoneMap_Call10173AE0(void * self_, undefined4 * param_1, int param_2);  // 0x101779B0
XI_API int __cdecl Gfx_SetupLineDrawState(void);  // 0x101779C0
XI_API int __cdecl Gfx_DrawQuadOutline(float *a1, char a2, unsigned __int8 arg8, unsigned __int8 a4, char a5, char a6);  // 0x10177B40
XI_API int __cdecl Gfx_DrawLine3D(int a1, int a2, int a3, int a4, int a5, int a6);  // 0x10177C50
XI_API void __cdecl ZoneMap_ResetGlobalTables(void);  // 0x101784E0
XI_API void __thiscall ZoneMap_UpdateLoadState(void * self_);  // 0x101787C0
XI_API undefined4 __thiscall ZoneMap_SetArea(void * self_, int param_1, int param_2);  // 0x10178A20
XI_API void __thiscall ZoneMap_ReleaseSlot(void * self_, int param_1);  // 0x10178AC0
XI_API int __thiscall ZoneMap_ReleaseStateBlock(CTsZoneMap *self_);  // 0x10178B00
XI_API void __thiscall ZoneMap_Reset(void * self_);  // 0x10178F70
XI_API int __thiscall ZoneMap_DrawBox(void *self_);  // 0x101791F0
XI_API int __thiscall ZoneMap_CreateVertexShaders(char *self_);  // 0x101792A0
XI_API void __thiscall ZoneMap_CopyField342C8ToField39450(void * self_);  // 0x10179410
XI_API undefined4 __thiscall ZoneMap_GetField342C8(void * self_);  // 0x10179420
XI_API void __thiscall ZoneMap_SetByteOfId999Entries(void * self_, undefined4 param_1);  // 0x1017A590
XI_API int __thiscall ZoneMap_DrawMeshGroupsWithFog(CTsZoneMap *self_, _DWORD *a2);  // 0x1017ADE0
XI_API undefined4 __thiscall ZoneMap_FreeSlot(void * self_, int param_1);  // 0x1017B110
XI_API undefined4 __thiscall ZoneMap_TeardownStep(void * self_);  // 0x1017B1E0
XI_API undefined4 __thiscall ZoneMap_QueryBoxHeightBandThenGetCount34154(void * self_, undefined4 param_1, float param_2, float param_3);  // 0x101811D0
XI_API undefined4 __thiscall ZoneMap_QueryBoxHeight(void * self_, undefined4 param_1, float param_2, undefined4 param_3, float param_4, float * param_5);  // 0x10181210
XI_API undefined4 __thiscall ZoneMap_QueryBoxHeightBand(void * self_, undefined4 param_1, float param_2, undefined4 param_3, float param_4, float * param_5);  // 0x10181290
XI_API undefined4 __thiscall ZoneMap_QueryBoxHeightByRadius(void * self_, undefined4 param_1, float param_2, undefined4 param_3, float * param_4);  // 0x10181300
XI_API undefined4 __thiscall ZoneMap_QueryExpandedBox(void * self_, float param_1, float param_2, float param_3, float param_4, float * param_5);  // 0x10181370
XI_API void __thiscall ZoneMap_FindGroundHeight(void * self_, undefined4 param_1, float param_2, undefined4 param_3, float param_4, float * param_5);  // 0x101813F0
XI_API undefined4 __thiscall ZoneMap_Query169290(void * self_, float * param_1, float * param_2, undefined4 param_3);  // 0x101814D0
XI_API undefined4 __thiscall ZoneMap_Query1693B0(void * self_, float * xi_s1, float * xi_s2, float * xi_s3);  // 0x10181590
XI_API undefined8 __thiscall ZoneMap_IsTargetAheadKind9(void * self_);  // 0x101815D0
XI_API undefined8 __thiscall ZoneMap_GetTargetGroundKindByte(void * self_);  // 0x10181930
XI_API undefined4 __thiscall ZoneMap_IsBoxHeightHitByRadius(void * self_, undefined4 param_1, float param_2, undefined4 param_3, float * param_4);  // 0x101819B0
XI_API undefined4 __thiscall ZoneMap_Query16E7E0(void * self_, float * param_1, undefined4 param_2, undefined4 param_3);  // 0x10181A10
XI_API long double __cdecl ZoneMap_MulPointXyz(float * param_1, float * param_2, float * param_3);  // 0x10181F60
XI_API void __stdcall ZoneMap_BuildPerspective(float * param_1, float param_2, float param_3, float param_4, float param_5, float param_6);  // 0x10182490
XI_API int __stdcall Gfx_DrawWireBox(int a1);  // 0x10182F10
XI_API int __thiscall ZoneMap_FindSlotByName(void * self_, int param_1);  // 0x10183420
XI_API _DWORD * __thiscall ZoneMap_DrawMeshById(int self_, int a2, int a3);  // 0x10183DA0
XI_API undefined4 __attribute__((stdcall, regparm(3))) ModelActor_Draw(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, int param_2, undefined4 xi_s2);  // 0x101844C0
XI_API void __thiscall ZoneMap_ClearSlots(void * self_);  // 0x10186DB0
XI_API void __stdcall ZoneMap_FreeSubAreas(int * param_1);  // 0x10186DD0
XI_API int __thiscall ZoneMap_GetAddr0B4(void * self_);  // 0x10186E90
XI_API int __thiscall ZoneMap_GetAddr0C4(void * self_);  // 0x10186EA0
XI_API int __thiscall ZoneMap_GetAddr0D4(void * self_);  // 0x10186EB0
XI_API int __thiscall ZoneMap_GetAddr024(void * self_);  // 0x10186EC0
XI_API int __thiscall ZoneMap_GetAddr044(void * self_);  // 0x10186EE0
XI_API int __thiscall ZoneMap_GetAddr064(void * self_);  // 0x10186F00
XI_API int __thiscall ZoneMap_GetAddr074(void * self_);  // 0x10186F10
XI_API int __thiscall Env_GetColorPtr84(void * self_);  // 0x10186F20
XI_API int __thiscall ZoneMap_GetAddr094(void * self_);  // 0x10186F30
XI_API int __thiscall ZoneMap_GetAddrRef18Plus1C(void * self_);  // 0x10186F40
XI_API int __thiscall ZoneMap_GetAddrRef18Plus20(void * self_);  // 0x10186F50
XI_API int __thiscall ZoneMap_GetAddr0E4(void * self_);  // 0x10186F70
XI_API int __thiscall ZoneMap_GetAddr0F4(void * self_);  // 0x10186F80
XI_API int __thiscall ZoneMap_GetAddr114(void * self_);  // 0x10186F90
XI_API int __thiscall Env_GetAmbientColorPtr(void * self_);  // 0x10186FA0
XI_API int __thiscall ZoneMap_GetAddrRef18Plus3C(void * self_);  // 0x10186FB0
XI_API int __thiscall ZoneMap_GetAddrRef18Plus40(void * self_);  // 0x10186FC0
XI_API long double __thiscall ZoneMap_GetFloatRef18Plus44(void * self_);  // 0x10186FD0
XI_API long double __thiscall ZoneMap_GetFloatRef1CPlus4(void * self_);  // 0x10186FE0
XI_API long double __thiscall ZoneMap_GetFloatRef1CPlus8(void * self_);  // 0x10186FF0
XI_API undefined4 __thiscall ZoneMap_GetByteRef1CPlus10(void * self_);  // 0x10187000
XI_API long double __thiscall ZoneMap_GetFloatRef1CPlus0C(void * self_);  // 0x10187020
XI_API void __thiscall ZoneMap_ReleaseChain(void * self_);  // 0x10187030
XI_API void __thiscall Env_ApplyRecord(void * self_);  // 0x10187050
XI_API void * __thiscall ZoneMap_SetVtableApplyRecord(void * self_);  // 0x10187380
XI_API uint32_t __thiscall ZoneMap_Update(void * self_);  // 0x101874A0
XI_API undefined4 __attribute__((stdcall, regparm(3))) ZoneMap_ForEachFindKind5B(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x101875C0
XI_API undefined4 __attribute__((stdcall, regparm(3))) ZoneMap_ForEachFindKind5A(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x101875E0
XI_API void __thiscall ZoneMap_SaveState(void * self_);  // 0x10187600
XI_API void __thiscall ZoneMap_UpdateOrbit(void * self_, int param_1);  // 0x10187720
XI_API void __thiscall ZoneMap_SetRecord(void * self_, undefined4 * param_1);  // 0x101880C0
XI_API void __thiscall ZoneMap_ApplyColors(void * self_, uint8_t * param_1);  // 0x10188190
XI_API int __cdecl ZoneMap_GetCurrent(void);  // 0x10188900
XI_API void __thiscall ZoneMap_AppendToList(void * self_);  // 0x10188910
XI_API void * __thiscall ZoneMap_FindPrevious(void * self_);  // 0x10188970
XI_API int __cdecl ZoneMap_GetTail(void);  // 0x101889A0
XI_API uint32_t __thiscall Env_RampWindStrength(void * self_);  // 0x10188A50
XI_API void __thiscall ZoneMap_FillDirLight(void * self_, undefined4 * param_1, int param_2);  // 0x10188CA0
XI_API _DWORD * __thiscall Env_ComputeAmbient(char *self_, _DWORD *a2, int a3);  // 0x10188E00
XI_API float * __thiscall Env_ComputeAmbientFloat4(char *self_, float *a2);  // 0x10188FA0
XI_API void __thiscall Env_ComputeFog(void * self_, uint32_t * param_1, float * param_2, float * param_3, int param_4);  // 0x10189120
XI_API undefined4 * __attribute__((stdcall, regparm(3))) WeatherRes_Construct(uint32_t xi_eax_unused, undefined4 xi_edx, undefined4 * param_1);  // 0x101893B0
XI_API void * __thiscall WeatherRes_InitKeyDefaults(void * self_);  // 0x10189400
XI_API void __thiscall Env_BlendKeys(void * self_, uint32_t * param_1, uint32_t * param_2, float param_3);  // 0x10189490
XI_API undefined4 __cdecl Env_LerpFloat(float * param_1, float param_2, float param_3, float param_4);  // 0x10189810
XI_API void __thiscall Env_LerpKeyValues(void * self_, int param_1, int param_2, undefined4 param_3);  // 0x101898E0
XI_API undefined4 __stdcall WeatherRes_IsTimeKeyName(int param_1);  // 0x10189BD0
XI_API void __stdcall Zone_GetClock(int * param_1);  // 0x10189C60
XI_API void __thiscall Env_FindPrevKey(void * self_, undefined4 * param_1, undefined4 xi_s2);  // 0x10189CA0
XI_API void * __thiscall WeatherRes_FindAtOrBefore(void * self_, undefined4 xi_s1);  // 0x10189E30
XI_API void __thiscall Env_FindNextKey(void * self_, undefined4 * param_1, undefined4 xi_s2);  // 0x10189F20
XI_API void * __thiscall WeatherRes_FindNeighbor(void * self_, undefined4 xi_s1);  // 0x1018A0F0
XI_API void __thiscall Env_UpdatePrevKey(void * self_);  // 0x1018A220
XI_API void __thiscall Env_UpdateNextKey(void * self_);  // 0x1018A260
XI_API void __thiscall Env_UpdateKeyAtOrBefore(void * self_);  // 0x1018A2A0
XI_API undefined4 __thiscall Env_UpdateKeyNeighbor(void * self_);  // 0x1018A2C0
XI_API void __thiscall Env_SetKeyField2C(void * self_, undefined4 param_1);  // 0x1018A2E0
XI_API void __thiscall Env_SetKeyField30(void * self_, undefined4 param_1);  // 0x1018A2F0
XI_API void __thiscall Env_SetKeyField24(void * self_, undefined4 param_1);  // 0x1018A300
XI_API undefined4 __thiscall Env_SetKeyField28(void * self_, undefined4 param_1);  // 0x1018A310
XI_API undefined4 __thiscall Env_UpdateTimeKeys(void * self_);  // 0x1018A320
XI_API void __thiscall Env_BlendTimeOfDay(void * self_);  // 0x1018A340
XI_API uint32_t __cdecl YmCombineWeather_ResetFlag1000Generator(undefined4 * param_1, undefined4 param_2);  // 0x1018AA50
XI_API undefined4 __attribute__((stdcall, regparm(3))) YmCombineWeather_FindKind5A(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x1018AAC0
XI_API uint32_t __cdecl YmCombineWeather_ResetFlag1000Not800Generator(undefined4 * param_1);  // 0x1018AAE0
XI_API undefined4 __attribute__((stdcall, regparm(3))) YmCombineWeather_FindKind5B(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x1018AB40
XI_API uint32_t __cdecl YmCombineWeather_RunFlag800Generator(undefined4 * param_1);  // 0x1018AB60
XI_API undefined4 __thiscall EnvBlend_GetField4(void * self_);  // 0x1018AD50
XI_API void __thiscall EnvBlend_SetField10Of4(void * self_, undefined4 param_1);  // 0x1018AD60
XI_API void * __thiscall Blend_FindPrevious(void * self_);  // 0x1018AD80
XI_API void __thiscall Blend_FreeResult(void * self_);  // 0x1018ADA0
XI_API void __thiscall EnvBlend_CallBlendUpdate(void * self_);  // 0x1018ADD0
XI_API void __thiscall Blend_Update(void * self_);  // 0x1018ADE0
XI_API undefined4 __stdcall Blend_AllocResult(undefined4 xi_s1, undefined4 xi_s2);  // 0x1018AEB0
XI_API undefined4 __thiscall unknown_libname_158(void * self_);  // 0x1018BBB0
XI_API void * __thiscall Time_SetNormalized(void * self_, undefined4 param_1);  // 0x1018BBC0
XI_API undefined4 __attribute__((stdcall, regparm(3))) Time_Normalize(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, int param_2);  // 0x1018BC40
XI_API int __thiscall Time_GetModulo60(void * self_);  // 0x1018BC90
XI_API int __thiscall Time_GetModulo3600Div60(void * self_);  // 0x1018BCA0
XI_API int __thiscall Time_GetModulo216000Div3600(void * self_);  // 0x1018BCD0
XI_API int __thiscall Time_GetModulo5184000Div216000(void * self_);  // 0x1018BD00
XI_API int __thiscall Time_GetDiv5184000(void * self_);  // 0x1018BD30
XI_API int __cdecl TextInputFiles_GetGameTimeValue(void);  // 0x1018BDE0
XI_API void __thiscall Time_SetModulo60(void * self_, int param_1);  // 0x1018BE80
XI_API void __thiscall Time_SetModulo3600Div60(void * self_, int param_1);  // 0x1018BEB0
XI_API void __thiscall Time_SetModulo216000Div3600(void * self_, int param_1);  // 0x1018BF00
XI_API void __thiscall Time_FromHours(void * self_, int param_1);  // 0x1018BF50
XI_API void __thiscall Time_SetModulo155520000Div5184000(void * self_, int param_1);  // 0x1018BFA0
XI_API void __thiscall Time_SetDiv155520000(void * self_, int param_1);  // 0x1018C020
XI_API void __cdecl Time_GetDiv5184000Mul5184000(undefined4 * param_1);  // 0x1018C1B0
XI_API void __thiscall Time_AddFrameScale(void * self_);  // 0x1018C270
XI_API undefined4 __thiscall Time_SubtractFrameScale(void * self_);  // 0x1018C290
XI_API uint32_t __cdecl TextInputFiles_GrowCapacity(undefined4 param_1, uint32_t param_2);  // 0x1018D230
XI_API undefined4 __thiscall TextInputFiles_Free(void * self_);  // 0x1018D250
XI_API void __thiscall TextInputFiles_InitEmpty(void * self_);  // 0x1018D280
XI_API void * __thiscall TextInputFiles_Init(void * self_);  // 0x1018D2B0
XI_API void * __thiscall TextInputFiles_AssignCStr(void * self_, char * param_1);  // 0x1018D2D0
XI_API void __thiscall TextInputFiles_AssignWhole(void * self_, char * param_1);  // 0x1018D430
XI_API void __thiscall TextInputFiles_Append(void * self_, char * param_1);  // 0x1018D440
XI_API void __thiscall TextInputFiles_AppendBuf(void * self_, void * param_1);  // 0x1018D450
XI_API undefined1 * __thiscall TextInputFiles_GetCStr(void * self_);  // 0x1018D470
XI_API undefined4 __thiscall TextInputFiles_GetLength(void * self_);  // 0x1018D480
XI_API undefined4 __thiscall TextInputFiles_GetField4_1018D490(void * self_);  // 0x1018D490
XI_API void * __thiscall TextInputFiles_AssignN(void * self_, char * param_1, int param_2);  // 0x1018D4A0
XI_API void * __thiscall TextInputFiles_AppendN(void * self_, char * param_1, size_t param_2);  // 0x1018D580
XI_API void * __thiscall TextInputFiles_InitAcqDat(void * self_);  // 0x1018D640
XI_API int __thiscall TextInputFiles_FillCompletionWords(void * self_, int * param_1, int param_2, uint8_t * param_3, int param_4);  // 0x1018D7F0
XI_API undefined4 __thiscall TextInputFiles_CommitPending8C(void * self_);  // 0x1018D980
XI_API void __thiscall TextInputFiles_ClearByte10E(void * self_);  // 0x1018DA10
XI_API undefined4 __cdecl TextInputFiles_Validate8NamesOrClear(int param_1, void * param_2);  // 0x1018DA20
XI_API undefined4 __stdcall TextInputFiles_AppendCompletionWord(int * param_1, int param_2, int param_3, char * param_4);  // 0x1018DB10
XI_API int __thiscall TextInputFiles_GetEntryMod(void * self_, uint32_t param_1);  // 0x1018DC70
XI_API void __thiscall TextInputFiles_ClearEntries(void * self_);  // 0x1018DCB0
XI_API void * __thiscall TextInputFiles_InitPecDat(void * self_);  // 0x1018DCD0
XI_API undefined4 __cdecl TextInputFiles_Validate64NamesOrClear(int param_1, int param_2);  // 0x1018DFD0
XI_API undefined4 __thiscall FsLogPage_InitPage(void * self_, undefined4 param_1);  // 0x1018E0A0
XI_API void __thiscall FsLogPage_ClearAndVisitFiles(void * self_);  // 0x1018E0E0
XI_API void __cdecl FsLogPage_FormatFileName(undefined1 * param_1, int param_2, undefined4 xi_s3);  // 0x1018E170
XI_API undefined4 __thiscall FsLogPage_AllocBuffer(void * self_);  // 0x1018E1A0
XI_API undefined4 __thiscall FsLogPage_load(void * self_, undefined4 param_1);  // 0x1018E1D0
XI_API undefined4 __thiscall FsLogPage_WriteFile(void * self_, undefined4 param_1);  // 0x1018E310
XI_API undefined4 __thiscall FsLogPage_AddString(void * self_, char * param_1);  // 0x1018E4D0
XI_API int __thiscall TextInputFiles_GetPageLine(void * self_, int param_1);  // 0x1018E620
XI_API void __thiscall FsLogPage_ClearBuffer(void * self_);  // 0x1018E660
XI_API void __thiscall FsLogPage_PruneOffsets(void * self_);  // 0x1018E6A0
XI_API void * __thiscall FsLogPage_Init(void * self_, undefined4 param_1);  // 0x1018E6F0
XI_API undefined4 __thiscall TextInputFiles_FreeAllLogPages(void * self_);  // 0x1018E780
XI_API int __thiscall TextInputFiles_GetLineOfPage(void * self_, int param_1, int param_2);  // 0x1018E7D0
XI_API undefined4 __thiscall FsLogPage_HasPage(void * self_, int param_1);  // 0x1018E7F0
XI_API int __thiscall FsLogPage_EnsurePage(void * self_, int param_1);  // 0x1018E800
XI_API undefined4 __thiscall TextInputFiles_FreeLogPage(void * self_, int param_1);  // 0x1018E890
XI_API undefined4 __thiscall FsLogPage_Rotate(void * self_, void * param_1);  // 0x1018E8D0
XI_API void * __thiscall TextInputFiles_ConstructKind1(void * self_);  // 0x1018E9B0
XI_API void * __thiscall TextInputFiles_ConstructKind2(void * self_);  // 0x1018EA00
XI_API void __thiscall TextInputFiles_InitFields(void * self_, undefined4 param_1);  // 0x1018EA50
XI_API undefined4 __thiscall TextInputFiles_RecreateMembers(void * self_);  // 0x1018EB00
XI_API undefined4 __thiscall TextInputFiles_FreeLogPagesIfLoaded(void * self_);  // 0x1018EBF0
XI_API undefined4 __thiscall TextInputFiles_GetCurrentLogLine(void * self_);  // 0x1018EC10
XI_API undefined4 __thiscall TextInputFiles_LogLineBack(void * self_);  // 0x1018EC50
XI_API undefined4 __thiscall TextInputFiles_LogLineForward(void * self_);  // 0x1018ECE0
XI_API void __thiscall FsLogPage_AddEntry(void * self_, char * param_1);  // 0x1018ED80
XI_API void * __thiscall TextInputFiles_ConstructLarge(void * self_, undefined4 param_1, undefined4 param_2);  // 0x1018EE40
XI_API undefined4 __cdecl Text_ClassifyChar(undefined4 param_1, undefined4 param_2);  // 0x1018FA20
XI_API undefined4 __cdecl Text_GetCharLength(undefined4 param_1, undefined4 param_2);  // 0x1018FA80
XI_API int __cdecl Text_CountChars(int param_1, undefined4 param_2, int param_3);  // 0x1018FB00
XI_API undefined4 __attribute__((cdecl, regparm(1))) Sjis_Remap82To83(undefined4 xi_eax, int param_1, int param_2);  // 0x1018FD90
XI_API int __cdecl Text_EncodeQuotes(char * param_1, int param_2, int param_3);  // 0x10190140
XI_API void __cdecl TextInputFiles_AllocZeroed(undefined4 * param_1, uint32_t param_2);  // 0x101907A0
XI_API undefined8 __cdecl TextInputFiles_FreeBlock(LPVOID param_1);  // 0x101907D0
XI_API void __cdecl TextInputFiles_Nop(void);  // 0x101908D0
XI_API undefined4 __thiscall TextInputFiles_CtorVt10336950(void * self_);  // 0x10190900
XI_API undefined4 __thiscall TextInputFiles_Reset10336950(void * self_, undefined4 param_1);  // 0x10190950
XI_API void __thiscall FsCSKLogic_closeCSK(void * self_);  // 0x10190B50
XI_API void __thiscall TextInputFiles_Update10336950(void * self_);  // 0x10190BB0
XI_API uint32_t __thiscall TextInputFiles_UpdateFromMenu(void * self_);  // 0x101911A0
XI_API void * __thiscall TextInputFiles_CtorVt10336958(void * self_);  // 0x10191AB0
XI_API int __thiscall TextInputFiles_FindTopShape(void * self_, undefined4 param_1);  // 0x10191B20
XI_API int __thiscall TextInputFiles_FindShapeKey2Top(void * self_, undefined4 param_1);  // 0x10192380
XI_API void * __thiscall TextInputFiles_CtorVt103369A0(void * self_, undefined4 param_1);  // 0x10192E50
XI_API undefined4 __cdecl TextInputFiles_AddPairChecked(undefined4 param_1, undefined4 param_2, undefined4 param_3);  // 0x10193800
XI_API undefined4 __cdecl SetConfig(undefined4 param_1, undefined4 param_2);  // 0x10193830
XI_API undefined4 __cdecl Settings_GetValue(undefined4 param_1);  // 0x10193850
XI_API undefined4 __cdecl TextInputFiles_GetSetting99(undefined4 param_1);  // 0x10193890
XI_API undefined4 __cdecl TextInputFiles_GetSettingMapped(undefined4 param_1, undefined4 xi_s2);  // 0x101938B0
XI_API undefined4 __cdecl TextInputFiles_TestBit(uint32_t param_1, undefined4 param_2);  // 0x101938D0
XI_API undefined8 __cdecl TextInputFiles_TestBit64(int param_1, int param_2);  // 0x10193A10
XI_API undefined4 __thiscall TextInputFiles_InitPairNode(void * self_, undefined4 param_1, undefined4 param_2);  // 0x10193B00
XI_API void __thiscall TextInputFiles_FindOrAdd(void * self_, int param_1, int param_2);  // 0x10193B60
XI_API void __thiscall TextInputFiles_ForEach(void * self_, undefined4 param_1, undefined4 param_2);  // 0x10193BC0
XI_API void * __thiscall FsConfig_Constructor(void * self_);  // 0x10193BF0
XI_API undefined4 __thiscall TextInputFiles_ResetConfigReturn1(void * self_);  // 0x10195220
XI_API undefined4 __thiscall TextInputFiles_AddPairAndCall(void * self_, undefined4 param_1, int param_2, undefined4 param_3);  // 0x10195240
XI_API undefined4 __thiscall TextInputFiles_SetEntryValue(void * self_, int param_1, int param_2);  // 0x101952C0
XI_API undefined8 __thiscall TextInputFiles_GetEntryValue(void * self_, undefined4 param_1);  // 0x10195330
XI_API undefined4 __thiscall TextInputFiles_ReloadConfig(void * self_);  // 0x10195350
XI_API void __thiscall TextInputFiles_ReadTigDatSetFlag(void * self_);  // 0x101953A0
XI_API undefined4 __thiscall TextInputFiles_FlushThenTrue(void * self_);  // 0x101953C0
XI_API undefined4 __thiscall TextInputFiles_UpdateIfFlag9(void * self_);  // 0x101953F0
XI_API void __thiscall TextInputFiles_DefineEntry(void * self_, int param_1, undefined4 param_2, int param_3, undefined4 * param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7, undefined4 param_8);  // 0x10195460
XI_API int __thiscall TextInputFiles_GetEntry2C(void * self_, int param_1);  // 0x101954D0
XI_API undefined4 __thiscall TextInputFiles_WriteTigDat(void * self_);  // 0x101954F0
XI_API undefined4 __thiscall TextInputFiles_ReadTigDat(void * self_);  // 0x10195570
XI_API undefined4 __thiscall TextInputFiles_StoreExternalConfig(void * self_);  // 0x10195640
XI_API undefined4 __thiscall TextInputFiles_LoadExternalConfig(void * self_);  // 0x101956F0
XI_API undefined4 __stdcall TextInputFiles_ReadExternalKind1(undefined4 * param_1);  // 0x10195780
XI_API undefined4 __stdcall TextInputFiles_WriteExternalKind1(undefined4 * param_1, undefined4 xi_s2);  // 0x101957B0
XI_API undefined * __stdcall TextInputFiles_ReadExternalKind2(char * param_1);  // 0x10195810
XI_API int __stdcall TextInputFiles_IsExternalKind2Key(char * param_1, undefined4 xi_s2);  // 0x101958C0
XI_API undefined4 __thiscall TextInputFiles_SaveCnfDat(void * self_);  // 0x10195900
XI_API undefined4 __thiscall TextInputFiles_LoadCnfDat(void * self_);  // 0x101959A0
XI_API undefined4 __stdcall TextInputFiles_SetConfigEntryValue(int param_1, int param_2);  // 0x10196040
XI_API void __thiscall TextInputFiles_ResetConfigToDefaults(void * self_, undefined4 param_1);  // 0x10196260
XI_API void __thiscall TextInputFiles_ConstructVt10336A0C(void * self_);  // 0x101962D0
XI_API void * __thiscall TextInputFiles_WindowItemCtor(void * self_);  // 0x10196980
XI_API undefined4 __cdecl TextInputFiles_ReturnZero(void);  // 0x10196BE0
XI_API void * __thiscall TextInputFiles_ClearWords3C(void * self_);  // 0x10196BF0
XI_API void __thiscall TextInputFiles_SetFieldById(void * self_, undefined4 param_1, undefined4 param_2);  // 0x10196F60
XI_API undefined4 __cdecl TextInputFiles_SetFieldCallback(undefined4 param_1, undefined4 param_2, void * param_3);  // 0x10197030
XI_API void * __thiscall TextInputFiles_WindowItemCtorVt10336AC8(void * self_);  // 0x101972B0
XI_API void __thiscall TextInputFiles_SetFieldById2(void * self_, undefined4 param_1, int param_2);  // 0x101978E0
XI_API undefined4 __cdecl TextInputFiles_SetFieldCallback2(undefined4 param_1, int param_2, void * param_3);  // 0x10197A70
XI_API void * __thiscall TextInputFiles_FrameItemCtor(void * self_);  // 0x10197A90
XI_API void * __thiscall TextInputFiles_ConstructVt10336B60(void * self_);  // 0x10197F00
XI_API void * __thiscall TextInputFiles_ConstructVt10336BB0(void * self_);  // 0x10198320
XI_API void * __thiscall TextInputFiles_CtorVt10336C00(void * self_);  // 0x10198CA0
XI_API void * __thiscall TextInputFiles_CtorVt10336C48(void * self_);  // 0x101990C0
XI_API void * __thiscall TextInputFiles_ConstructVt10336C90(void * self_);  // 0x101991B0
XI_API void * __thiscall TextInputFiles_ConstructVt10336CD8(void * self_);  // 0x101992A0
XI_API void * __thiscall TextInputFiles_WindowItemCtorVt10336D20(void * self_);  // 0x10199710
XI_API void * __thiscall TextInputFiles_ConstructVt10336D70(void * self_);  // 0x10199F40
XI_API void * __thiscall TextInputFiles_ConstructVt10336DC0(void * self_);  // 0x1019A010
XI_API void * __thiscall TextInputFiles_WindowItemCtorVt10336E10(void * self_);  // 0x1019A890
XI_API void * __thiscall TextInputFiles_WindowItemCtorVt10336E58(void * self_);  // 0x1019AF00
XI_API void * __thiscall TextInputFiles_WindowItemCtorVt10336EA0(void * self_);  // 0x1019B860
XI_API void * __thiscall TextInputFiles_ConstructVt10336EE8(void * self_);  // 0x1019BC90
XI_API void * __thiscall TextInputFiles_CtorVt10336F30(void * self_);  // 0x1019BFE0
XI_API void * __thiscall TextInputFiles_CtorVt10336F78(void * self_);  // 0x1019C190
XI_API void __cdecl TextInputFiles_RunPairA(void);  // 0x1019C3E0
XI_API void __cdecl TextInputFiles_RunPairB(void);  // 0x1019C4F0
XI_API void __cdecl TextInputFiles_Call10311386(void);  // 0x1019C580
XI_API void __cdecl TextInputFiles_GetSetting41(void);  // 0x1019C590
XI_API void __cdecl TextInputFiles_Call103113C8(void);  // 0x1019C5B0
XI_API void * __thiscall TextInputFiles_ByteTableCtor(void * self_);  // 0x1019CD40
XI_API undefined4 __attribute__((cdecl, regparm(1))) TextInputFiles_HasTable1037A290CellByte(short * xi_eax, undefined4 param_1);  // 0x1019CDC0
XI_API void * __thiscall TextInputFiles_ByteTableDefaultCtor(void * self_);  // 0x1019CE00
XI_API void __thiscall Config_LoadDefaultTable(void * self_);  // 0x1019CE70
XI_API undefined4 __attribute__((stdcall, regparm(3))) TextInputFiles_FillTableBytes(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x1019CF60
XI_API void * __thiscall TextInputFiles_ByteTableAltCtor(void * self_);  // 0x1019D150
XI_API void __thiscall Config_LoadAltTable(void * self_);  // 0x1019D1C0
XI_API void * __thiscall TextInputFiles_CtorVt103370F8(void * self_);  // 0x1019D580
XI_API void * __thiscall TextInputFiles_CtorCachingSettings(void * self_);  // 0x1019D770
XI_API void __thiscall Settings_CacheValues(void * self_);  // 0x1019D8B0
XI_API undefined4 __thiscall TextInputFiles_DrawTextBlockOnce(void * self_);  // 0x1019EBB0
XI_API int64_t __thiscall TextInputFiles_GetScaleTimes310(void * self_);  // 0x1019ED10
XI_API int64_t __thiscall TextInputFiles_GetScaleTimes0(void * self_);  // 0x1019ED20
XI_API int64_t __thiscall TextInputFiles_GetScaleTimes180(void * self_);  // 0x1019ED30
XI_API char * __stdcall TextInputFiles_NextLine(char * param_1);  // 0x1019ED70
XI_API int __thiscall TextInputFiles_DrawTextLines(void * self_, uint32_t param_1, int param_2, char * param_3, undefined4 param_4, int param_5);  // 0x1019EDB0
XI_API void * __thiscall TextInputFiles_CtorWithMenuFepShape(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3);  // 0x1019F160
XI_API int __thiscall TextInputFiles_PushWithRetry(void * self_, undefined4 param_1);  // 0x1019F8B0
XI_API undefined4 __thiscall TextInputFiles_FindMatchAt8(void * self_, undefined4 xi_s1);  // 0x1019F930
XI_API undefined8 __thiscall TextInputFiles_WaitThenHandleFileEvent(void * self_, int param_1);  // 0x1019F960
XI_API int __thiscall TextInputFiles_WaitEvent18At8(void * self_);  // 0x1019FA90
XI_API int __thiscall TextInputFiles_SignalMember8(void * self_);  // 0x1019FAB0
XI_API undefined4 __cdecl TextInputFiles_Call101BE510IfSize4(undefined4 param_1, int param_2, undefined4 xi_s3);  // 0x101A0710
XI_API undefined4 __cdecl TextInputFiles_FillSizeAndDatesFwd(undefined4 xi_s1, undefined4 xi_s2, undefined4 xi_s3, undefined4 xi_s4, undefined4 xi_s5, undefined4 xi_s6, undefined4 xi_s7, undefined4 xi_s8, undefined4 xi_s9, undefined4 xi_s10, undefined4 xi_s11, undefined4 xi_s12, undefined4 xi_s13, undefined4 xi_s14, undefined4 xi_s15, undefined4 xi_s16, undefined4 xi_s17, undefined4 xi_s18, undefined4 xi_s19, undefined4 xi_s20, undefined4 xi_s21, undefined4 xi_s22, undefined4 xi_s23, undefined4 xi_s24, undefined4 xi_s25, undefined4 xi_s26, undefined4 xi_s27, undefined4 xi_s28, undefined4 xi_s29, undefined4 xi_s30, undefined4 xi_s31, undefined4 xi_s32, undefined4 xi_s33, undefined4 xi_s34, undefined4 xi_s35, undefined4 xi_s36, undefined4 xi_s37, undefined4 xi_s38, undefined4 xi_s39, undefined4 xi_s40, undefined4 xi_s41, undefined4 xi_s42, undefined4 xi_s43, undefined4 xi_s44, undefined4 xi_s45, undefined4 xi_s46, undefined4 xi_s47, undefined4 xi_s48, undefined4 xi_s49, undefined4 xi_s50, undefined4 xi_s51, undefined4 xi_s52, undefined4 xi_s53, undefined4 xi_s54, undefined4 xi_s55, undefined4 xi_s56, undefined4 xi_s57, undefined4 xi_s58, undefined4 xi_s59, undefined4 xi_s60, undefined4 xi_s61, undefined4 xi_s62, undefined4 xi_s63, undefined4 xi_s64, undefined4 xi_s65, undefined4 xi_s66, undefined4 xi_s67, undefined4 * xi_s68);  // 0x101A0730
XI_API undefined4 __cdecl TextInputFiles_Call101BE670(undefined4 xi_s1, undefined4 xi_s2, undefined4 xi_s3);  // 0x101A0750
XI_API undefined4 __cdecl TextInputFiles_Call101BE690(undefined4 xi_s1, undefined4 xi_s2, undefined4 xi_s3);  // 0x101A0760
XI_API int __cdecl TextInputFiles_RunKind8WithCallback(undefined4 param_1, int param_2, undefined4 xi_s3, undefined4 xi_s4, undefined4 xi_s5, undefined4 xi_s6, undefined4 xi_s7, undefined4 xi_s8, undefined4 xi_s9, undefined4 xi_s10, undefined4 xi_s11, undefined4 xi_s12, undefined4 xi_s13, undefined4 xi_s14, undefined4 xi_s15, undefined4 xi_s16, undefined4 xi_s17, undefined4 xi_s18, undefined4 xi_s19, undefined4 xi_s20, undefined4 xi_s21, undefined4 xi_s22, undefined4 xi_s23, undefined4 xi_s24, undefined4 xi_s25, undefined4 xi_s26, undefined4 xi_s27, undefined4 xi_s28, undefined4 xi_s29, undefined4 xi_s30, undefined4 xi_s31, undefined4 xi_s32, undefined4 xi_s33, undefined4 xi_s34, undefined4 xi_s35, undefined4 xi_s36, undefined4 xi_s37, undefined4 xi_s38, undefined4 xi_s39, undefined4 xi_s40, undefined4 xi_s41, undefined4 xi_s42, undefined4 xi_s43, undefined4 xi_s44, undefined4 xi_s45, undefined4 xi_s46, undefined4 xi_s47, undefined4 xi_s48, undefined4 xi_s49, undefined4 xi_s50, undefined4 xi_s51, undefined4 xi_s52, undefined4 xi_s53, undefined4 xi_s54, undefined4 xi_s55, undefined4 xi_s56, undefined4 xi_s57, undefined4 xi_s58, undefined4 xi_s59, undefined4 xi_s60, undefined4 xi_s61, undefined4 xi_s62, undefined4 xi_s63, undefined4 xi_s64, undefined4 xi_s65, undefined4 xi_s66, undefined4 xi_s67, undefined4 xi_s68, undefined4 xi_s69, undefined4 xi_s70, undefined4 xi_s71, xi_codefn * xi_s72, undefined4 xi_s73);  // 0x101A0770
XI_API int __thiscall TextInputFiles_SignalEvent10(void * self_);  // 0x101A0910
XI_API int __thiscall TextInputFiles_ResetAndWaitEvent14(void * self_, undefined4 param_1);  // 0x101A0930
XI_API undefined8 __thiscall TextInputFiles_WaitEvent18(void * self_);  // 0x101A0950
XI_API undefined8 __thiscall TextInputFiles_SignalMember18(void * self_);  // 0x101A0970
XI_API undefined4 __thiscall TextInputFiles_Push(void * self_, int param_1);  // 0x101A0BE0
XI_API undefined4 __thiscall TextInputFiles_FindMatch(void * self_, int param_1);  // 0x101A0D30
XI_API undefined4 __thiscall TextInputFiles_HasRecords(void * self_);  // 0x101A0F30
XI_API unsigned char __thiscall TextInputFiles_IsField84PositiveAfterWait(void * self_);  // 0x101A1360
XI_API undefined4 __thiscall TextInputFiles_Pop(void * self_);  // 0x101A1390
XI_API void * __thiscall TextInputFiles_StringListCtor(void * self_);  // 0x101A1400
XI_API void __thiscall TextInputFiles_SetVtable10337210(void * self_);  // 0x101A1460
XI_API undefined4 __thiscall TextInputFiles_PushFrontString(void * self_, undefined4 * param_1, uint32_t param_2);  // 0x101A1470
XI_API int __thiscall TextInputFiles_CopyCurrent(void * self_, undefined4 * param_1, int param_2);  // 0x101A1500
XI_API undefined4 __thiscall TextInputFiles_SetCurrent(void * self_, char * param_1, int param_2);  // 0x101A1580
XI_API undefined4 __thiscall TextInputFiles_Advance(void * self_);  // 0x101A1660
XI_API undefined4 __thiscall TextInputFiles_Retreat(void * self_);  // 0x101A1690
XI_API undefined4 __thiscall TextInputFiles_ClearFirstString(void * self_);  // 0x101A16B0
XI_API void * __thiscall TextInputFiles_McrEntryCtor(void * self_);  // 0x101A16E0
XI_API void __thiscall TextInputFiles_CopyMcrEntry(void * self_, int param_1);  // 0x101A1740
XI_API undefined4 __thiscall TextInputFiles_CopyRecord6x3D(void * self_, undefined4 * param_1);  // 0x101A1790
XI_API undefined4 __thiscall TextInputFiles_ClearRecord6x3D(void * self_);  // 0x101A17E0
XI_API uint32_t __thiscall TextInputFiles_ValidateRecord6x3D(void * self_);  // 0x101A1840
XI_API int __thiscall TextInputFiles_GetMcrEntryLine(void * self_, int param_1);  // 0x101A1910
XI_API int __cdecl TextInputFiles_Create(void);  // 0x101A19B0
XI_API void * __thiscall TextInputFiles_McrManagerCtor(void * self_);  // 0x101A1A20
XI_API undefined4 __thiscall TextInputFiles_QueueEntry(void * self_, int param_1);  // 0x101A1C60
XI_API undefined4 __thiscall TextInputFiles_StepScript(void * self_);  // 0x101A1CC0
XI_API undefined4 __cdecl TextInputFiles_OnMacroFileLoaded(int param_1, undefined4 * param_2, int param_3, int param_4);  // 0x101A1E20
XI_API void __cdecl TextInputFiles_LoadCurrentMacroDat(undefined4 param_1, int param_2);  // 0x101A23D0
XI_API void __cdecl TextInputFiles_ResetNames0To19(int param_1, void * param_2);  // 0x101A2410
XI_API void __cdecl TextInputFiles_ResetNames20To39(int param_1, void * param_2);  // 0x101A2440
XI_API undefined4 __stdcall TextInputFiles_ParseWaitCommand(char * param_1, undefined4 * param_2, int * param_3);  // 0x101A2480
XI_API void __stdcall TextInputFiles_FormatNumberedDatName(undefined1 * param_1, int param_2, undefined4 xi_s3);  // 0x101A2610
XI_API undefined4 __thiscall TextInputFiles_LoadNumberedDatIntoBuffer(void * self_, undefined4 param_1, undefined4 param_2);  // 0x101A2660
XI_API void __thiscall TextInputFiles_LoadMacroDat(void * self_, int param_1, undefined4 xi_s2);  // 0x101A26C0
XI_API void __thiscall TextInputFiles_SplitIndexBy20(void * self_, undefined4 xi_s1);  // 0x101A2870
XI_API undefined4 __thiscall TextInputFiles_SetReadPos(void * self_, int param_1);  // 0x101A2890
XI_API undefined4 __thiscall TextInputFiles_SetName(void * self_, int param_1, char * param_2);  // 0x101A2980
XI_API int __thiscall TextInputFiles_GetEntryPtr(void * self_, int param_1);  // 0x101A29F0
XI_API undefined4 __attribute__((stdcall, regparm(3))) TextInputFiles_FillDefaultNames(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x101A2A10
XI_API undefined4 __thiscall TextInputFiles_CtorVt10337314(void * self_, undefined4 param_1);  // 0x101A2E00
XI_API void __thiscall TextInputFiles_SetFields1C20(void * self_, undefined4 param_1, undefined4 param_2);  // 0x101A2E60
XI_API void __thiscall TextInputFiles_UpdateMenuState(void * self_);  // 0x101A2E80
XI_API undefined4 __thiscall TextInputFiles_SetSlot(void * self_, undefined4 param_1, undefined4 param_2);  // 0x101A3300
XI_API undefined4 __attribute__((cdecl, regparm(1))) TextInputFiles_CanOpenMenuShortcut(undefined4 xi_eax);  // 0x101A33E0
XI_API undefined4 __thiscall TextInputFiles_ApplyKeyAction(void * self_, int param_1, undefined4 param_2, undefined4 xi_s3);  // 0x101A3500
XI_API undefined4 __attribute__((stdcall, regparm(3))) TextInputFiles_HandleReadPosKeys(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x101A3550
XI_API void * __thiscall TextInputFiles_PanelCtorVt10337320(void * self_, undefined4 param_1, undefined4 param_2);  // 0x101A36F0
XI_API void __thiscall TextInputFiles_SetFlag29A(void * self_);  // 0x101A3CF0
XI_API undefined4 __thiscall TextInputFiles_AddMsg10_27IfChangedA(void * self_, undefined4 param_1);  // 0x101A3D00
XI_API void __cdecl TextInputFiles_FormatMessage10_27(undefined1 * param_1, int param_2, undefined4 param_3);  // 0x101A3D60
XI_API void * __thiscall TextInputFiles_PanelCtorVt10337378(void * self_, undefined4 param_1, undefined4 param_2);  // 0x101A3DC0
XI_API void __thiscall TextInputFiles_SetFlag29B(void * self_);  // 0x101A43A0
XI_API undefined4 __thiscall TextInputFiles_AddMsg10_27IfChangedB(void * self_, undefined4 param_1);  // 0x101A43B0
XI_API undefined4 __thiscall TextInputFiles_CtorVt103373BC(void * self_, undefined4 param_1);  // 0x101A4440
XI_API void * __thiscall TextInputFiles_PanelCtorVt103373C8(void * self_, undefined4 param_1, undefined4 param_2);  // 0x101A46C0
XI_API void * __thiscall TextInputFiles_PanelCtorVt10337418(void * self_, undefined4 param_1, undefined4 param_2);  // 0x101A4D70
XI_API void * __thiscall TextInputFiles_CtorVt10337460(void * self_, undefined4 param_1, undefined4 param_2);  // 0x101A54F0
XI_API void * __thiscall TextInputFiles_CtorVt103374A8(void * self_);  // 0x101A6430
XI_API void * __thiscall TextInputFiles_CtorVt103374F0(void * self_, undefined4 param_1);  // 0x101A6C10
XI_API void * __thiscall TextInputFiles_CtorVt10337538(void * self_, undefined4 param_1);  // 0x101A7280
XI_API void * __thiscall TextInputFiles_CtorVt1033757C(void * self_);  // 0x101A83C0
XI_API void __thiscall TextInputFiles_BuildSlotLinks(void * self_, int param_1);  // 0x101A8410
XI_API undefined4 __thiscall TextInputFiles_CtorVt10337580(void * self_, undefined4 param_1);  // 0x101A8750
XI_API void __cdecl TextInputFiles_CreateAll(void);  // 0x101A8B50
XI_API void __cdecl TextInputFiles_CreateDatManager(void);  // 0x101A8D40
XI_API void __cdecl TextInputFiles_CreateConfigObjects(void);  // 0x101A8D60
XI_API void __cdecl TextInputFiles_RegisterMenuHandlers(void);  // 0x101AA300
XI_API undefined4 __cdecl TextInputFiles_ApplyConfigSetting(undefined4 param_1, uint32_t param_2);  // 0x101AA650
XI_API undefined4 __cdecl TextInputFiles_ApplyUiSetting(undefined4 param_1, int param_2);  // 0x101AAA90
XI_API void __cdecl TextInputFiles_CreateEmptyObject(void);  // 0x101AB080
XI_API void __cdecl TextInputFiles_CreateMenuSystem(void);  // 0x101AB0D0
XI_API void __cdecl TextInputFiles_SaveAll(void);  // 0x101AB6D0
XI_API void __cdecl TextInputFiles_Call101953D0(void);  // 0x101AB720
XI_API void __cdecl TextInputFiles_ReloadAll(void);  // 0x101AB730
XI_API void __attribute__((cdecl, regparm(1))) TextInputFiles_HandleJumpMapKeys(undefined4 xi_eax);  // 0x101AB770
XI_API undefined4 __attribute__((cdecl, regparm(1))) TextInputFiles_LoadAllAndTimestamp(undefined4 xi_eax);  // 0x101AB7D0
XI_API void * __thiscall TextInputFiles_ReturnThis(void * self_);  // 0x101AB810
XI_API void __thiscall TextInputFiles_HandleMenuKeys(void * self_);  // 0x101AB820
XI_API void __thiscall FsTextInput_Init(void * self_, undefined4 param_1);  // 0x101ABB40
XI_API void __thiscall TextInputFiles_SetModeAndReset(void * self_, undefined4 param_1);  // 0x101ABBD0
XI_API void __thiscall TextInputFiles_ResetLineState(void * self_);  // 0x101ABBF0
XI_API undefined4 __thiscall FsTextInput_SetText(void * self_, int param_1, int param_2);  // 0x101ABC50
XI_API undefined4 __attribute__((stdcall, regparm(3))) FsTextInput_GetFlag(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x101ABE40
XI_API void __thiscall FsTextInput_ClearState(void * self_);  // 0x101ABE50
XI_API undefined4 __thiscall FsTextInput_GetCode(void * self_, undefined4 * param_1);  // 0x101ABE80
XI_API void __thiscall FsTextInput_CursorLeft(void * self_);  // 0x101ABEF0
XI_API void __thiscall FsTextInput_RebuildAtCursor(void * self_, undefined4 param_1);  // 0x101ABF40
XI_API int __thiscall FsTextInput_GetActiveBuffer(void * self_);  // 0x101AC1B0
XI_API int __thiscall FsTextInput_GetPendingBuffer(void * self_);  // 0x101AC1D0
XI_API undefined4 __thiscall FsTextInput_GetLength(void * self_);  // 0x101AC200
XI_API undefined4 __thiscall FsTextInput_GetCursorOrLength(void * self_);  // 0x101AC210
XI_API int __thiscall FsTextInput_GetMaxLength(void * self_);  // 0x101AC230
XI_API void __thiscall FsTextInput_Reset(void * self_, undefined4 xi_s1);  // 0x101AC250
XI_API undefined4 __thiscall FsTextInput_HistoryNext(void * self_);  // 0x101AC2C0
XI_API undefined4 __thiscall FsTextInput_HistoryPrev(void * self_);  // 0x101AC3D0
XI_API undefined4 __thiscall FsTextInput_HasText(void * self_);  // 0x101AC4D0
XI_API void __thiscall FsTextInput_MoveCursorLeft(void * self_);  // 0x101AC4E0
XI_API void __thiscall FsTextInput_MoveCursorRight(void * self_);  // 0x101AC520
XI_API undefined4 __thiscall FsTextInput_ResetBuffer(void * self_);  // 0x101AC580
XI_API uint32_t __thiscall FsTextInput_ExpandMarkedPhrase(void * self_, int param_1, int param_2, undefined4 * param_3, undefined4 param_4, int * param_5, undefined4 param_6, undefined4 param_7);  // 0x101AC5E0
XI_API int __thiscall FsTextInput_BuildDisplayText(void * self_, int param_1, int param_2, char * param_3, int param_4, undefined4 param_5, undefined4 param_6);  // 0x101AC990
XI_API int __thiscall FsTextInput_BuildDisplayTextTrimmed(void * self_, char * param_1, int param_2, int param_3, int param_4, int * param_5);  // 0x101ACAC0
XI_API undefined4 __thiscall FsTextInput_HasMarkedPhrase(void * self_, char * param_1);  // 0x101ACBE0
XI_API uint32_t __thiscall FsTextInput_CommitEntry(void * self_, int * param_1);  // 0x101ACC30
XI_API void __thiscall FsTextInput_SetCode4(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);  // 0x101ACF40
XI_API undefined4 __thiscall FsTextInput_MapCodeByte(void * self_);  // 0x101ACF60
XI_API void __thiscall FsTextInput_CopyCode4(void * self_, undefined1 * param_1);  // 0x101ACF70
XI_API undefined4 __thiscall FsTextInput_ClearPair(void * self_);  // 0x101ACF90
XI_API undefined4 __thiscall FsTextInput_InsertAtCursor(void * self_);  // 0x101ACFB0
XI_API int __thiscall FsTextInput_DeleteLastWord(void * self_);  // 0x101AD0D0
XI_API undefined4 __stdcall FsTextInput_IsMarkerAt(int param_1, int param_2);  // 0x101AD1B0
XI_API void * __thiscall FsPreParser_Constructor(void * self_, undefined4 param_1);  // 0x101AD290
XI_API void __thiscall TextInputFiles_ProcessInputLine(void * self_, char * param_1, int param_2, size_t param_3);  // 0x101AD4B0
XI_API int __thiscall FsTextInput_GetDataPtr8(void * self_);  // 0x101AD820
XI_API undefined4 __stdcall TextInputFiles_IsSlashChar(char * param_1);  // 0x101ADBC0
XI_API undefined4 __stdcall TextInputFiles_IsKnownCommand(char * param_1);  // 0x101ADBE0
XI_API undefined4 __cdecl Shape_GetValueAt(int param_1, int param_2);  // 0x101ADDC0
XI_API void __thiscall TextInputFiles_ShortcutCtor(void * self_);  // 0x101ADE00
XI_API void __thiscall FsTextInput_SetName(void * self_, undefined4 param_1, undefined4 param_2, char * param_3, undefined4 param_4);  // 0x101ADE80
XI_API void __thiscall TextInputFiles_ShortcutSet(void * self_, undefined4 param_1, undefined4 param_2, char * param_3, char * param_4, undefined4 param_5);  // 0x101ADEC0
XI_API undefined4 __thiscall TextInputFiles_ShortcutCheck(void * self_, undefined * param_1);  // 0x101ADF20
XI_API undefined4 __cdecl FsShortcut_CanUseShortcut(undefined4 param_1);  // 0x101AE010
XI_API void * __thiscall FsShortcutManager_Constructor(void * self_);  // 0x101AE140
XI_API void __thiscall TextInputFiles_UpdateShortcuts(void * self_);  // 0x101AE3E0
XI_API void * __thiscall TextInputFiles_CtorVt10337940(void * self_);  // 0x101AEA40
XI_API undefined4 __thiscall TextInputFiles_InitKeyTopShape(void * self_, undefined4 param_1);  // 0x101AEAC0
XI_API void __cdecl TextInputFiles_CloseKeypadMenu(void);  // 0x101AEB80
XI_API void __cdecl TextInputFiles_NoOpC(void);  // 0x101AFF30
XI_API void __cdecl TextInputFiles_NoOpD(void);  // 0x101AFF40
XI_API HIMC __stdcall TextInputFiles_ImmGetContext(HWND param_1);  // 0x101AFF50
XI_API BOOL __stdcall TextInputFiles_ImmReleaseContext(HWND param_1, HIMC param_2);  // 0x101AFF60
XI_API void __thiscall FsTextInput_InitWithImeOffscreen(void * self_);  // 0x101AFF70
XI_API undefined4 __cdecl TextInputFiles_CanOpenInput(void);  // 0x101B0060
XI_API void __thiscall TextInputFiles_OnMessage(void * self_, int param_1, undefined4 xi_s2);  // 0x101B2710
XI_API void __stdcall TextInputFiles_NoOp2ArgsA(undefined4 xi_s1, undefined4 xi_s2);  // 0x101B27F0
XI_API void __stdcall TextInputFiles_NoOp2ArgsB(undefined4 xi_s1, undefined4 xi_s2);  // 0x101B2800
XI_API undefined4 __thiscall TextInputFiles_HandleKeyDownWithIme(void * self_, UINT param_1, undefined4 xi_s2);  // 0x101B29F0
XI_API void __thiscall TextInputFiles_OnChar(void * self_, uint32_t param_1);  // 0x101B36F0
XI_API void __thiscall TextInputFiles_ResetComposition(void * self_, undefined4 param_1);  // 0x101B3B50
XI_API undefined4 __thiscall TextInputFiles_HasCompositionOrPending(void * self_);  // 0x101B3F00
XI_API undefined4 __cdecl TextInputFiles_HasComposition(void);  // 0x101B3F70
XI_API void __cdecl TextInputFiles_OpenInlineMenus(void);  // 0x101B3FC0
XI_API void __thiscall TextInputFiles_CloseInlineMenusKeepIme(void * self_);  // 0x101B4030
XI_API void __thiscall TextInputFiles_ClearF128AndClose(void * self_);  // 0x101B40C0
XI_API undefined4 __stdcall TextInputFiles_IsOemSlash(int param_1);  // 0x101B4260
XI_API undefined4 __stdcall TextInputFiles_ClassifyVirtualKey(uint32_t param_1);  // 0x101B4270
XI_API void __stdcall TextInputFiles_DoNothing1Arg(undefined4 xi_s1);  // 0x101B4340
XI_API undefined4 __cdecl Scene_IsState70(void);  // 0x101B4350
XI_API void __thiscall TextInputFiles_BeginInputWithIme(void * self_, undefined4 param_1, int param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7, undefined4 param_8);  // 0x101B4360
XI_API uint32_t __cdecl FsSjisToAscii(int param_1, undefined1 * param_2);  // 0x101B4450
XI_API void __thiscall TextInputFiles_CtorVt103379BCWithLang(void * self_);  // 0x101B4570
XI_API void __thiscall TextInputFiles_DtorVt103379BC(void * self_);  // 0x101B45B0
XI_API void __thiscall TextInputFiles_CtorVt103379C0(void * self_);  // 0x101B45E0
XI_API void * __thiscall TextInputFiles_CtorVt103379C4(void * self_);  // 0x101B4710
XI_API void * __thiscall TextInputFiles_Reset(void * self_);  // 0x101B4BB0
XI_API undefined4 __thiscall TextInputFiles_AppendByte(void * self_, undefined4 param_1);  // 0x101B4C20
XI_API undefined4 __thiscall TextInputFiles_DeleteLast(void * self_);  // 0x101B4D30
XI_API undefined4 __thiscall TextInputFiles_DeleteForward(void * self_);  // 0x101B4E70
XI_API void __thiscall TextInputFiles_ClearAll(void * self_);  // 0x101B4F90
XI_API void __thiscall TextInputFiles_MoveBack(void * self_);  // 0x101B4FC0
XI_API undefined4 __thiscall TextInputFiles_MoveForward(void * self_);  // 0x101B5020
XI_API undefined4 __cdecl TextInputFiles_ApplySetting(undefined4 param_1, int param_2, int * param_3);  // 0x101B5080
XI_API undefined4 __thiscall FsTextInput_init(void * self_);  // 0x101B5210
XI_API undefined4 __thiscall TextInputFiles_BeginInput(void * self_, undefined4 param_1, int param_2, undefined4 param_3, undefined4 param_4, int param_5, int param_6, int param_7, uint32_t param_8);  // 0x101B5850
XI_API void __thiscall TextInputFiles_CloseInlineMenu(void * self_);  // 0x101B5A80
XI_API void __thiscall TextInputFiles_CloseInputMenus(void * self_);  // 0x101B5AA0
XI_API uint32_t __thiscall FsTextInput_copyDecidedString(void * self_, undefined4 * param_1, undefined4 xi_s2);  // 0x101B5BC0
XI_API undefined4 __thiscall TextInputFiles_IsModeTwo(void * self_);  // 0x101B5C80
XI_API undefined4 __thiscall TextInputFiles_IsModeFourOrFive(void * self_);  // 0x101B5C90
XI_API undefined4 __thiscall TextInputFiles_IsModeThree(void * self_);  // 0x101B5CC0
XI_API undefined4 __thiscall TextInputFiles_EndMode4Or5(void * self_);  // 0x101B5CD0
XI_API undefined4 __thiscall TextInputFiles_HandleEditKey(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3);  // 0x101B5D10
XI_API int __thiscall FsTextInput_OnChar(void * self_, undefined4 param_1);  // 0x101B6810
XI_API undefined4 __thiscall TextInputFiles_InputSubmit(void * self_, undefined1 * param_1, int param_2);  // 0x101B6C00
XI_API undefined4 __attribute__((stdcall, regparm(3))) TextInputFiles_AcceptsChar(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, undefined4 param_2, int param_3);  // 0x101B6D50
XI_API void __attribute__((stdcall, regparm(3))) TextInputFiles_InputNotify(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, undefined4 param_2, int param_3, undefined4 param_4);  // 0x101B6E40
XI_API undefined4 __attribute__((stdcall, regparm(3))) TextInputFiles_GetFlag8C81(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x101B6E90
XI_API undefined4 __thiscall TextInputFiles_ResetCursor(void * self_);  // 0x101B6EA0
XI_API void * __thiscall TextInputFiles_GetEntry(void * self_);  // 0x101B6EC0
XI_API undefined4 __thiscall TextInputFiles_SetWordForCompletion(void * self_, uint8_t * param_1, int param_2);  // 0x101B6EE0
XI_API void __thiscall List_Advance(void * self_);  // 0x101B70A0
XI_API void __thiscall List_Retreat(void * self_);  // 0x101B70D0
XI_API void __thiscall List_PageDown(void * self_);  // 0x101B7100
XI_API void __thiscall List_PageUp(void * self_);  // 0x101B7130
XI_API undefined4 __thiscall TextInputFiles_HasPendingInput(void * self_);  // 0x101B7160
XI_API void __thiscall TextInputFiles_ResetBuffer(void * self_);  // 0x101B7190
XI_API void __thiscall TextInputFiles_InputCall101AC990(void * self_, undefined4 xi_s1, undefined4 xi_s2, char * xi_s3, undefined4 xi_s4, undefined4 xi_s5, undefined4 xi_s6);  // 0x101B7260
XI_API undefined4 __thiscall TextInputFiles_InputCall101AC990Swapped(void * self_, char * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6);  // 0x101B7280
XI_API undefined4 __thiscall TextInputFiles_InputCall101ACAC0(void * self_, char * param_1, int param_2, int param_3, int param_4);  // 0x101B72B0
XI_API void __thiscall TextInputFiles_Refresh101ABBF0(void * self_);  // 0x101B7890
XI_API int __thiscall TextInputFiles_GetLastWord(void * self_, undefined4 * param_1);  // 0x101B7C20
XI_API undefined4 __cdecl TextInputFiles_DefaultRunLine(int param_1, undefined4 param_2);  // 0x101B7E90
XI_API uint32_t __cdecl TextInputFiles_IsState1Or3(void);  // 0x101B7EE0
XI_API undefined4 __thiscall TextInputFiles_ResetField10(void * self_);  // 0x101B91B0
XI_API void * __thiscall TextInputFiles_CandidatesCtor(void * self_);  // 0x101B9230
XI_API void __attribute__((cdecl, regparm(1))) TextInputFiles_DestroyInputGlobals(undefined4 xi_eax);  // 0x101B92B0
XI_API void __stdcall TextInputFiles_ExitThread1234(void);  // 0x101B94A0
XI_API int __thiscall TextInputFiles_ReleaseSemaphoreAt4(void * self_);  // 0x101B9530
XI_API undefined8 __thiscall Event_Wait(void * self_, DWORD param_1);  // 0x101B9550
XI_API int __thiscall Event_ResetAndWait(void * self_, DWORD param_1);  // 0x101B95D0
XI_API int __thiscall Event_Signal(void * self_);  // 0x101B9610
XI_API undefined4 __thiscall TextInputFiles_CtorVt10337B1C(void * self_);  // 0x101B9650
XI_API int __thiscall FsTinyString_init(void * self_);  // 0x101B9690
XI_API void __thiscall TextInputFiles_DatEntryCtor(void * self_, undefined4 param_1, char * param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7);  // 0x101B9880
XI_API void __thiscall TextInputFiles_InitWithCallback(void * self_, undefined4 param_1, char * param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5);  // 0x101B9910
XI_API void __thiscall TextInputFiles_CopyFrom(void * self_, int param_1);  // 0x101B9980
XI_API void __thiscall TextInputFiles_ClearVtable(void * self_);  // 0x101B9A00
XI_API void * __thiscall TextInputFiles_InitCopy(void * self_, int param_1);  // 0x101B9E00
XI_API int __cdecl TextInputFiles_CreateGlobal10662DB4(void);  // 0x101B9E60
XI_API undefined4 __thiscall TextInputFiles_AppendToList(void * self_, undefined4 param_1);  // 0x101B9EC0
XI_API void __thiscall TextInputFiles_Register(void * self_, undefined4 param_1, undefined4 param_2, char * param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7, undefined4 param_8);  // 0x101B9F20
XI_API undefined4 __thiscall TextInputFiles_RemoveById(void * self_, int param_1);  // 0x101B9F90
XI_API undefined4 __thiscall TextInputFiles_Construct(void * self_);  // 0x101BA180
XI_API void * __thiscall TextInputFiles_CtorVt10337B2C(void * self_);  // 0x101BA280
XI_API void __thiscall TextInputFiles_ClearBufferA(void * self_);  // 0x101BA2D0
XI_API void __thiscall TextInputFiles_ClearBufferB(void * self_);  // 0x101BA300
XI_API void * __thiscall TextInputFiles_CtorVt10337B4C(void * self_);  // 0x101BA570
XI_API void __thiscall TextInputFiles_Destruct(void * self_);  // 0x101BA5B0
XI_API undefined4 __thiscall TextInputFiles_ResetCounters(void * self_);  // 0x101BA5C0
XI_API undefined4 __thiscall TextInputFiles_FreeBlocks18To24(void * self_);  // 0x101BADD0
XI_API undefined4 __thiscall FsWordCompletion_GetCount18(void * self_);  // 0x101BAE20
XI_API undefined4 __thiscall FsWordCompletion_GetCount1C(void * self_);  // 0x101BAE30
XI_API int __thiscall FsWordCompletion_FindNextByKey(void * self_, undefined4 param_1);  // 0x101BAE40
XI_API undefined4 __thiscall FsWordCompletion_GetField20(void * self_);  // 0x101BAEB0
XI_API undefined4 __thiscall FsWordCompletion_GetField28(void * self_);  // 0x101BAEC0
XI_API void * __thiscall FsWordCompletion_Construct(void * self_);  // 0x101BAED0
XI_API void __thiscall FsWordCompletion_ClearEntries(void * self_);  // 0x101BAF90
XI_API void __thiscall FsWordCompletion_Init(void * self_, undefined4 param_1);  // 0x101BAFC0
XI_API uint32_t __cdecl FsWordCompletion_IsEntryValid(uint32_t * param_1);  // 0x101BB100
XI_API void __stdcall FsWordCompletion_CountEntries(int param_1);  // 0x101BB130
XI_API void __thiscall FsWordCompletion_PackEntries(void * self_, int param_1, undefined4 xi_s2);  // 0x101BB1A0
XI_API undefined4 __thiscall FsWordCompletion_BuildKind7Block(void * self_);  // 0x101BB2B0
XI_API void __stdcall FsWordCompletion_CountSupported(int param_1);  // 0x101BB430
XI_API void __thiscall FsWordCompletion_BuildItems(void * self_, int param_1, int param_2, undefined4 param_3);  // 0x101BB4B0
XI_API undefined4 __thiscall FsWordCompletion_AddItem(void * self_, undefined4 * param_1, int * param_2, undefined4 param_3);  // 0x101BB5A0
XI_API undefined4 __thiscall FsWordCompletion_BuildKind13Block(void * self_);  // 0x101BB680
XI_API uint32_t __thiscall FsWordCompletion_Refresh(void * self_);  // 0x101BB740
XI_API undefined4 __thiscall FsWordCompletion_LoadData(void * self_);  // 0x101BB7A0
XI_API undefined1 __thiscall FsWordCompletion_Release(void * self_);  // 0x101BB9E0
XI_API undefined4 __thiscall FsWordCompletion_SetWord(void * self_, char * param_1, uint32_t param_2, undefined4 param_3);  // 0x101BBA90
XI_API void __thiscall FsWordCompletion_Update(void * self_);  // 0x101BBC60
XI_API undefined4 __thiscall TextInputFiles_IsState204Not1(void * self_);  // 0x101BBE50
XI_API undefined4 __thiscall FsWordCompletion_getEntryList(void * self_, undefined4 * param_1, int * param_2);  // 0x101BBE60
XI_API uint32_t __thiscall FsWordCompletion_lookUp(void * self_, uint32_t param_1, char * param_2, int param_3);  // 0x101BC100
XI_API undefined4 __thiscall FsWordCompletion__prepareAllData(void * self_, undefined4 xi_s1);  // 0x101BC520
XI_API undefined4 __thiscall TextInputFiles_Store101BB070At8(void * self_);  // 0x101BC6F0
XI_API undefined4 __thiscall TextInputFiles_FreeBuffer(void * self_);  // 0x101BC720
XI_API undefined4 __thiscall TextInputFiles_InitVt10337BA0(void * self_);  // 0x101BC740
XI_API uint32_t __thiscall TextInputFiles_Set(void * self_, undefined4 param_1, uint32_t param_2, undefined4 param_3);  // 0x101BC7B0
XI_API int __thiscall Entry_CompareKey(void * self_, int * param_1);  // 0x101BC900
XI_API undefined4 __thiscall TextInputFiles_GetUsed(void * self_);  // 0x101BC9B0
XI_API void * __thiscall FsMemory_Constructor(void * self_, uint32_t param_1);  // 0x101BC9E0
XI_API undefined4 * __thiscall TextInputFiles_AppendPadded(void * self_, undefined4 * param_1, uint32_t param_2);  // 0x101BCA40
XI_API int __thiscall TextInputFiles_ReserveZeroed(void * self_, uint32_t param_1);  // 0x101BCAC0
XI_API void __thiscall TextInputFiles_Clear(void * self_);  // 0x101BCB30
XI_API undefined4 __thiscall TextInputFiles_CtorVt10337C3C(void * self_);  // 0x101BCBA0
XI_API void __thiscall TextInputFiles_WatchConfigWindow(void * self_);  // 0x101BCE30
XI_API void * __thiscall TextInputFiles_CtorVt10337C5C(void * self_);  // 0x101BCEF0
XI_API void __thiscall TextInputFiles_ClearTwoBuffers(void * self_);  // 0x101BCF30
XI_API void * __thiscall TextInputFiles_CtorVt10337C60(void * self_);  // 0x101BE260
XI_API void __thiscall TextInputFiles_SetVtable10337C60(void * self_);  // 0x101BE2A0
XI_API void __thiscall TextInputFiles_SetField4(void * self_, undefined4 param_1);  // 0x101BE2B0
XI_API void __thiscall TextInputFiles_SetDateAt9(void * self_, undefined4 xi_s1);  // 0x101BE2C0
XI_API void __thiscall TextInputFiles_SetDateAt11(void * self_, undefined4 xi_s1);  // 0x101BE330
XI_API void __thiscall TextInputFiles_SetDateAt19(void * self_, undefined4 xi_s1);  // 0x101BE3A0
XI_API void __thiscall TextInputFiles_SetVtable10337C64(void * self_);  // 0x101BE410
XI_API undefined4 __thiscall File_FindByKind(void * self_, int * param_1, int param_2, int param_3);  // 0x101BE470
XI_API undefined4 __stdcall TextInputFiles_Call10311F30(undefined4 param_1);  // 0x101BE500
XI_API int __stdcall TextInputFiles_SeekWhence012(undefined4 param_1, undefined4 param_2, int param_3);  // 0x101BE540
XI_API int __stdcall File_WriteChunked(int param_1, int param_2, uint32_t param_3);  // 0x101BE590
XI_API undefined4 __stdcall TextInputFiles_Call10312296(undefined4 param_1, undefined4 param_2, undefined4 param_3);  // 0x101BE650
XI_API int __stdcall TextInputFiles_DeleteFile(LPCSTR param_1);  // 0x101BE670
XI_API undefined4 __stdcall TextInputFiles_FillSizeAndThreeDates(undefined4 param_1, undefined4 * param_2);  // 0x101BE6C0
XI_API undefined4 __stdcall File_CreateParentDirs(int param_1);  // 0x101BE730
XI_API int __thiscall XiFileImpl_QueueLoad(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6);  // 0x101BECC0
XI_API int __thiscall TextInputFiles_SubmitFileNumKind1(void * self_, uint32_t param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);  // 0x101BF280
XI_API int __thiscall TextInputFiles_SubmitPathKind1(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5);  // 0x101BF370
XI_API int __thiscall TextInputFiles_SubmitPath2F4Kind1(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);  // 0x101BF460
XI_API int __thiscall TextInputFiles_SubmitPath3F4Kind1(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);  // 0x101BF550
XI_API undefined4 __thiscall TextInputFiles_ReadFileByName(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6);  // 0x101BF710
XI_API int __thiscall TextInputFiles_ReadTextOrNoData(void * self_, undefined4 param_1, int param_2, undefined4 param_3, undefined4 param_4);  // 0x101BF7F0
XI_API int __thiscall TextInputFiles_QueueFileNumKind2(void * self_, uint32_t param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, int param_5, int param_6);  // 0x101BF970
XI_API int __thiscall TextInputFiles_QueuePathKind3(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, int param_5);  // 0x101C0050
XI_API int __thiscall TextInputFiles_QueuePath2F4Kind3(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, int param_4);  // 0x101C0160
XI_API int __thiscall TextInputFiles_QueuePath3F4Kind3(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, int param_4);  // 0x101C0260
XI_API int __thiscall TextInputFiles_SubmitPathKind3(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, int param_4, int param_5);  // 0x101C0440
XI_API int __thiscall TextInputFiles_SubmitPath2F4Kind3(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, int param_4);  // 0x101C0540
XI_API undefined8 __thiscall TextInputFiles_SubmitPath3F4Kind3(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, int param_4);  // 0x101C0630
XI_API int __thiscall TextInputFiles_SubmitPath4F4Kind3(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, int param_4);  // 0x101C0760
XI_API int __thiscall TextInputFiles_CreateDirAndWait(void * self_);  // 0x101C09B0
XI_API undefined4 __thiscall TextInputFiles_CreateDirAndHandleFile(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);  // 0x101C0A40
XI_API int __thiscall TextInputFiles_SubmitPathKind6(void * self_, undefined4 param_1, int param_2);  // 0x101C0FC0
XI_API int __thiscall TextInputFiles_SubmitPath3F4Kind6(void * self_, undefined4 param_1);  // 0x101C1090
XI_API uint32_t __thiscall TextInputFiles_FindFileNumKind1(void * self_, uint32_t param_1, undefined4 param_2, undefined4 param_3);  // 0x101C11F0
XI_API uint32_t __thiscall TextInputFiles_FindFileNumKind2(void * self_, uint32_t param_1);  // 0x101C13A0
XI_API uint32_t __thiscall TextInputFiles_FindPathKind3(void * self_, undefined4 param_1, int param_2);  // 0x101C1750
XI_API uint32_t __thiscall TextInputFiles_FindPath2F4Kind3(void * self_, undefined4 param_1);  // 0x101C1820
XI_API uint32_t __thiscall TextInputFiles_FindPath3F4Kind3(void * self_, undefined4 param_1);  // 0x101C18E0
XI_API int __thiscall TextInputFiles_SubmitFileNumKind4(void * self_, uint32_t param_1);  // 0x101C1B20
XI_API int __thiscall TextInputFiles_SubmitPath3F4Kind4(void * self_, undefined4 param_1);  // 0x101C1C90
XI_API int __thiscall TextInputFiles_SubmitPathKind4(void * self_, undefined4 param_1, int param_2);  // 0x101C1DF0
XI_API int __thiscall TextInputFiles_SubmitPath2F4Kind4(void * self_, undefined4 param_1);  // 0x101C1EC0
XI_API int __thiscall TextInputFiles_GetFileSizeByName(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3);  // 0x101C1F80
XI_API undefined4 __thiscall TextInputFiles_GetFileSize24(void * self_, undefined4 param_1);  // 0x101C2030
XI_API int __thiscall TextInputFiles_SubmitPath3F4Kind5(void * self_, undefined4 param_1, undefined4 param_2);  // 0x101C2450
XI_API undefined4 __thiscall TextInputFiles_SubmitPath3F4Kind7(void * self_, undefined4 param_1);  // 0x101C2840
XI_API void __thiscall TextInputFiles_WriteTimestampFwd(void * self_, undefined4 xi_s1);  // 0x101C2D80
XI_API int __thiscall TextInputFiles_OpenHexPath(void * self_, undefined4 xi_s1);  // 0x101C2DC0
XI_API void __thiscall TextInputFiles_ReleaseAt1F0(void * self_);  // 0x101C33E0
XI_API undefined4 __thiscall TextInputFiles_GetValueAt1F0(void * self_);  // 0x101C33F0
XI_API undefined4 __thiscall TextInputFiles_FormatUserPath(void * self_, undefined4 param_1, undefined1 * param_2, int param_3);  // 0x101C3D00
XI_API undefined4 __thiscall TextInputFiles_FormatStrAt2F4(void * self_, undefined4 param_1, undefined1 * param_2);  // 0x101C3DB0
XI_API undefined8 __thiscall TextInputFiles_FormatStrAt3F4(void * self_, undefined4 param_1, undefined1 * param_2);  // 0x101C3DE0
XI_API undefined4 __thiscall TextInputFiles_FormatStrAt4F4(void * self_, undefined4 param_1, undefined1 * param_2);  // 0x101C3E10
XI_API undefined4 __stdcall TextInputFiles_FormatWithBase(undefined4 param_1, undefined4 param_2, undefined1 * param_3, undefined4 param_4);  // 0x101C3E40
XI_API undefined4 __thiscall TextInputFiles_FormatPathByKind(void * self_, undefined1 * param_1, uint32_t param_2, char * param_3);  // 0x101C3E90
XI_API undefined4 __thiscall TextInputFiles_CopyPathByMode(void * self_, undefined1 * param_1, int param_2, char * param_3);  // 0x101C3F40
XI_API undefined4 __stdcall TextInputFiles_MapCode012(int param_1);  // 0x101C3FB0
XI_API undefined4 __attribute__((stdcall, regparm(1))) TextInputFiles_CreateDirectories(undefined4 xi_eax, LPCSTR param_1);  // 0x101C3FE0
XI_API void __thiscall TextInputFiles_WriteTimestamp(void * self_, undefined4 xi_s1);  // 0x101C4170
XI_API uint32_t __thiscall TextInputFiles_ReadTimestamp(void * self_, undefined4 xi_s1);  // 0x101C4260
XI_API undefined4 __thiscall TextInputFiles_FileMngQueueLoad(void * self_, undefined4 xi_s1, undefined4 xi_s2, undefined4 xi_s3, undefined4 xi_s4, undefined4 xi_s5, undefined4 xi_s6);  // 0x101C46E0
XI_API int __thiscall TextInputFiles_ForwardOrExit(void * self_, int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);  // 0x101C4740
XI_API undefined4 __thiscall TextInputFiles_FileMngSubmitPathKind1(void * self_, undefined4 xi_s1, undefined4 xi_s2, undefined4 xi_s3, undefined4 xi_s4, undefined4 xi_s5);  // 0x101C4790
XI_API undefined4 __thiscall TextInputFiles_FileMngSubmitPath2F4Kind1(void * self_, undefined4 xi_s1, undefined4 xi_s2, undefined4 xi_s3, undefined4 xi_s4);  // 0x101C47A0
XI_API undefined4 __thiscall TextInputFiles_FileMngSubmitPath3F4Kind1(void * self_, undefined4 xi_s1, undefined4 xi_s2, undefined4 xi_s3, undefined4 xi_s4);  // 0x101C47B0
XI_API void __thiscall TextInputFiles_FileMngReadText(void * self_, undefined4 param_1, int param_2, undefined4 param_3, undefined4 param_4);  // 0x101C4800
XI_API undefined4 __thiscall TextInputFiles_FileMngQueueFileNumKind2(void * self_, uint32_t param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, int param_5, undefined1 * param_6);  // 0x101C4820
XI_API undefined4 __thiscall TextInputFiles_FileMngQueuePathKind3(void * self_, undefined4 xi_s1, undefined4 xi_s2, undefined4 xi_s3, undefined4 xi_s4, undefined4 xi_s5);  // 0x101C48E0
XI_API void __thiscall TextInputFiles_FileMngQueuePath2F4Kind3(void * self_, undefined4 xi_s1, undefined4 xi_s2, undefined4 xi_s3, undefined4 xi_s4);  // 0x101C48F0
XI_API void __thiscall TextInputFiles_FileMngQueuePath3F4Kind3(void * self_, undefined4 xi_s1, undefined4 xi_s2, undefined4 xi_s3, undefined4 xi_s4);  // 0x101C4900
XI_API undefined4 __thiscall TextInputFiles_FileMngSubmitPathKind3(void * self_, undefined4 xi_s1, undefined4 xi_s2, undefined4 xi_s3, undefined4 xi_s4, undefined4 xi_s5);  // 0x101C4920
XI_API void __thiscall TextInputFiles_FileMngSubmitPath2F4Kind3(void * self_, undefined4 xi_s1, undefined4 xi_s2, undefined4 xi_s3, undefined4 xi_s4);  // 0x101C4930
XI_API undefined8 __thiscall TextInputFiles_FileMngSubmitPath3F4Kind3(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, int param_4);  // 0x101C4940
XI_API undefined4 __thiscall TextInputFiles_FileMngSubmitPath4F4Kind3(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, int param_4);  // 0x101C4950
XI_API undefined4 __thiscall TextInputFiles_FileMngCall101C09B0(void * self_);  // 0x101C4990
XI_API undefined4 __thiscall TextInputFiles_FileMngCall101C0A40(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, int param_4);  // 0x101C49A0
XI_API void __thiscall TextInputFiles_FileMngSubmitPathKind6(void * self_, undefined4 param_1, int param_2);  // 0x101C49E0
XI_API void __thiscall TextInputFiles_FileMngSubmitPath3F4Kind6(void * self_, undefined4 param_1);  // 0x101C49F0
XI_API undefined4 __thiscall TextInputFiles_FileMngFindFileNumKind1(void * self_, undefined4 xi_s1, undefined4 xi_s2, undefined4 xi_s3);  // 0x101C4A10
XI_API undefined4 __thiscall TextInputFiles_FileMngFindFileNumKind2(void * self_, uint32_t param_1);  // 0x101C4A30
XI_API undefined4 __thiscall TextInputFiles_FileMngFwd101C1750(void * self_, undefined4 xi_s1, undefined4 xi_s2);  // 0x101C4A80
XI_API undefined4 __thiscall TextInputFiles_FileMngFwd101C1820(void * self_, undefined4 xi_s1);  // 0x101C4A90
XI_API undefined4 __thiscall TextInputFiles_FileMngFwd101C18E0(void * self_, undefined4 xi_s1);  // 0x101C4AA0
XI_API int __thiscall FileMng_ResolveOrExit(void * self_, int param_1);  // 0x101C4AF0
XI_API undefined4 __thiscall TextInputFiles_FileMngFwd101C1C90(void * self_, undefined4 xi_s1);  // 0x101C4B40
XI_API undefined4 __thiscall TextInputFiles_FileMngFwd101C1DF0(void * self_, undefined4 xi_s1, undefined4 xi_s2);  // 0x101C4B60
XI_API undefined4 __thiscall TextInputFiles_FileMngFwd101C1EC0(void * self_, undefined4 xi_s1);  // 0x101C4B70
XI_API undefined4 __thiscall TextInputFiles_FileMngFwd101C2450(void * self_, undefined4 param_1, undefined4 param_2);  // 0x101C4BF0
XI_API undefined4 __thiscall TextInputFiles_FileMngFwd101C2840(void * self_, undefined4 xi_s1);  // 0x101C4C70
XI_API undefined4 __thiscall TextInputFiles_FileMngFwd101C2B60(void * self_, undefined4 xi_s1);  // 0x101C4CC0
XI_API undefined4 __thiscall TextInputFiles_FileMngFwd101C2C80(void * self_);  // 0x101C4CD0
XI_API void __thiscall TextInputFiles_FileMngFwd101C4170(void * self_, undefined4 xi_s1);  // 0x101C4CE0
XI_API void __thiscall TextInputFiles_FileMngFwd101C2E70(void * self_);  // 0x101C4D10
XI_API void __thiscall TextInputFiles_FileMngReleaseAt1F0(void * self_);  // 0x101C4D30
XI_API void __thiscall TextInputFiles_FileMngGetValueAt1F0(void * self_);  // 0x101C4D40
XI_API void * __cdecl TextInputFiles_AllocPlus300OrFree(int param_1, int param_2);  // 0x101C4D50
XI_API void * __thiscall TextInputFiles_EntriesCtorEmpty(void * self_);  // 0x101C5920
XI_API void * __thiscall TextInputFiles_EntriesCtor(void * self_, int param_1);  // 0x101C5930
XI_API void __thiscall TextInputFiles_AllocEntries(void * self_, int param_1);  // 0x101C59B0
XI_API void __thiscall TextInputFiles_EntriesSetCount(void * self_, undefined4 param_1);  // 0x101C5A30
XI_API unsigned char __thiscall TextInputFiles_SubmitFileOrExit(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3);  // 0x101C5A40
XI_API void * __thiscall TextInputFiles_CtorVt10337C90(void * self_, undefined4 param_1, int param_2, undefined4 param_3, undefined4 param_4, char * param_5, undefined4 param_6, undefined4 param_7, int param_8);  // 0x101C5BE0
XI_API undefined4 __thiscall TextInputFiles_CommitTextInput(void * self_);  // 0x101C5EC0
XI_API void __thiscall TextInputFiles_EndTextInput(void * self_);  // 0x101C60C0
XI_API undefined4 __thiscall TextInputFiles_CtorVt10337CA0(void * self_, undefined4 param_1, undefined4 param_2);  // 0x101C6810
XI_API undefined4 __thiscall TextInputFiles_CloseTextInput(void * self_);  // 0x101C68A0
XI_API undefined4 __thiscall YkCommon_InitFourSlots(void * self_);  // 0x101C7C50
XI_API void __thiscall YkCommon_Construct(void * self_);  // 0x101C7F80
XI_API void * __thiscall YkCommon_Clear(void * self_);  // 0x101C8070
XI_API void __thiscall YkCommon_FreeBuffer(void * self_);  // 0x101C80A0
XI_API undefined4 __thiscall YkCommon_Load(void * self_, int param_1);  // 0x101C80C0
XI_API void * __thiscall YkCommon_Init(void * self_);  // 0x101C8260
XI_API void __thiscall YkCommon_ResizeEntries(void * self_, int param_1);  // 0x101C8290
XI_API undefined4 __thiscall YkCommon_LoadTable(void * self_, int param_1);  // 0x101C8380
XI_API undefined4 __cdecl YkCommon_MapChar(int param_1, uint8_t * param_2, uint8_t * param_3);  // 0x101C87A0
XI_API int __cdecl YkCommon_CompareMapped(uint32_t param_1, int param_2, int param_3, undefined4 param_4);  // 0x101C88A0
XI_API void __cdecl YkCommonInit(void);  // 0x101C8950
XI_API undefined4 __cdecl YkCommon_GetIndexed(int param_1);  // 0x101C8C30
XI_API uint32_t __cdecl YkCommon_Checksum(uint8_t * param_1, int param_2);  // 0x101C8C50
XI_API undefined4 __cdecl YkCommon_TimeToTmWrap28Years(uint32_t param_1);  // 0x101C8D10
XI_API int __cdecl YkCommon_GetOffset(void);  // 0x101C8D70
XI_API void __cdecl Gfx_ProjectWorldToScreen(_DWORD *a1, _WORD *a2, _WORD *a3);  // 0x101C8DA0
XI_API undefined * __cdecl YkCommon_FormatDateTime(uint32_t param_1, undefined4 param_2);  // 0x101C8FD0
XI_API short * __cdecl YkCommon_FindShortKeyEntry(short * param_1, undefined4 param_2);  // 0x101C9270
XI_API undefined * __cdecl CTkSubWindow_DrawTime(int param_1);  // 0x101C93C0
XI_API int __cdecl YkCommon_MeasureText(uint8_t * param_1);  // 0x101C9550
XI_API undefined8 __cdecl YkCommon_DrawUnscaled(undefined4 param_1, undefined4 param_2, uint8_t * param_3, undefined4 param_4);  // 0x101C9780
XI_API int __cdecl YkCommon_DrawTextItem0(undefined4 param_1, undefined4 param_2, uint8_t * param_3, int param_4, float param_5, float param_6, undefined4 param_7);  // 0x101C97B0
XI_API undefined8 __cdecl YkCommon_DrawString(undefined4 param_1, int param_2, undefined4 param_3, char * param_4, int param_5);  // 0x101C9D50
XI_API int __cdecl YkCommon_DrawTruncated(undefined4 param_1, undefined4 param_2, char * param_3, undefined4 param_4);  // 0x101CA180
XI_API void __cdecl YkCommon_DrawFractionRange(undefined4 param_1, undefined4 param_2, void * param_3, void * param_4, float param_5, float param_6, float param_7, float param_8, float param_9, float param_10);  // 0x101CAD00
XI_API void __cdecl YkCommon_DrawFractionDefault(undefined4 param_1, undefined4 param_2, void * param_3, void * param_4, float param_5, float param_6);  // 0x101CAEC0
XI_API undefined8 __cdecl YkCommon_DrawSmoothed(undefined4 param_1, undefined4 param_2, void * param_3, void * param_4, undefined4 param_5, uint8_t * param_6, float param_7, float param_8, float param_9, float param_10);  // 0x101CAF00
XI_API undefined8 __cdecl YkCommon_DrawSmoothedDefault(undefined4 param_1, undefined4 param_2, void * param_3, void * param_4, undefined4 param_5, uint8_t * param_6);  // 0x101CB000
XI_API void __cdecl YkCommon_DrawFractionItem1A(undefined4 param_1, undefined4 param_2, float param_3, undefined4 param_4);  // 0x101CB040
XI_API undefined8 __cdecl YkCommon_DrawSmoothedItem1A(undefined4 param_1, undefined4 param_2, undefined4 param_3, uint8_t * param_4);  // 0x101CB090
XI_API void __cdecl YkCommon_DrawSmoothedItem1B(undefined4 param_1, undefined4 param_2, undefined4 param_3, uint8_t * param_4);  // 0x101CB1B0
XI_API undefined4 __cdecl YkCommon_DrawSmoothedExItem1B(undefined4 param_1, undefined4 param_2, undefined4 param_3, uint8_t * param_4, float param_5, float param_6, float param_7, float param_8);  // 0x101CB230
XI_API void __cdecl YkCommon_DrawEasedPercent(undefined4 param_1, undefined4 param_2, void * param_3, void * param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7, uint8_t * param_8, float param_9, float param_10, float param_11, float param_12);  // 0x101CB430
XI_API void __cdecl YkCommon_DrawEasedPercentUnitScale(undefined4 param_1, undefined4 param_2, void * param_3, void * param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7, uint8_t * param_8);  // 0x101CB500
XI_API void __cdecl YkCommon_DrawEasedPercentItem1A(undefined4 param_1, undefined4 param_2, undefined4 param_3, uint8_t * param_4);  // 0x101CB550
XI_API undefined4 __cdecl YkCommon_BeginCapture(undefined4 param_1, undefined4 param_2, undefined4 param_3);  // 0x101CB770
XI_API undefined4 __cdecl YkCommon_Forward10097E80(int param_1);  // 0x101CBC60
XI_API undefined4 __attribute__((cdecl, regparm(1))) YkCommon_IsActorField170(undefined4 xi_eax, int param_1);  // 0x101CBDF0
XI_API undefined4 __attribute__((cdecl, regparm(1))) YkCommon_IsActorField170Is5(undefined4 xi_eax);  // 0x101CBE50
XI_API undefined4 __attribute__((cdecl, regparm(1))) YkCommon_IsActorField170Is55(undefined4 xi_eax);  // 0x101CBE60
XI_API undefined4 __attribute__((cdecl, regparm(1))) YkCommon_IsActorField170Is6(undefined4 xi_eax);  // 0x101CBE70
XI_API undefined4 __cdecl YkCommon_TestFlags100Or40DAC(undefined4 param_1);  // 0x101CC070
XI_API unsigned char __cdecl YkCommon_Test104DFD98Field40C3CZero(void);  // 0x101CC0A0
XI_API undefined4 __attribute__((cdecl, regparm(1))) YkCommon_GetByte1048098D(undefined4 xi_eax);  // 0x101CC1B0
XI_API uint32_t __attribute__((cdecl, regparm(1))) YkCommon_ActorTest1D0(undefined4 xi_eax, int param_1);  // 0x101CC1D0
XI_API undefined4 __attribute__((cdecl, regparm(1))) YkCommon_ActorPairTest1FF(undefined4 xi_eax, int param_1);  // 0x101CC220
XI_API undefined4 __cdecl YkCommon_IsNotD3(int param_1);  // 0x101CC320
XI_API undefined4 __cdecl YkCommon_CC4F0ActorTest400(undefined4 param_1, undefined4 param_2);  // 0x101CC350
XI_API int __cdecl Acter_GetActerAt10485F7A(void);  // 0x101CC4F0
XI_API undefined4 __cdecl YkCommon_GetCC4F0ActorByIndexAt1FA(void);  // 0x101CC510
XI_API undefined4 __cdecl Acter_GetByIndexAt1FA(int param_1);  // 0x101CC520
XI_API undefined4 __cdecl YkCommon_GetCC4F0ActorAt2A0(void);  // 0x101CC550
XI_API undefined4 __cdecl YkCommon_GetActorAt2A0(int param_1);  // 0x101CC560
XI_API int __cdecl Yk_MapCodeOffset(int param_1);  // 0x101CCE00
XI_API undefined * __cdecl YkFurniture_GetEntry1037D7B4(int param_1);  // 0x101CCE50
XI_API undefined * __cdecl YkFurniture_GetTablePtrBy121(int param_1);  // 0x101CCE90
XI_API void __thiscall YkFurniture_RotateStepAroundOther(void * self_, void * param_1, undefined4 param_2);  // 0x101CD2D0
XI_API undefined4 __attribute__((stdcall, regparm(3))) PlantMenu_GetWord58(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x101CD990
XI_API undefined4 __thiscall PlantMenu_GetValueAt58(void * self_);  // 0x101CD9A0
XI_API undefined4 __thiscall PlantMenu_GetValueAt54(void * self_);  // 0x101CD9D0
XI_API undefined4 __thiscall PlantMenu_GetValueAt56(void * self_);  // 0x101CDA00
XI_API undefined4 __thiscall PlantMenu_GetValueAt5A(void * self_);  // 0x101CDA30
XI_API void __thiscall PlantMenu_SetQuarterTurn(void * self_, int param_1);  // 0x101CDF50
XI_API void __thiscall PlantMenu_SetState(void * self_, int param_1, undefined4 xi_s2);  // 0x101CE1E0
XI_API undefined4 __thiscall PlantMenu_SetWord28Recursive(void * self_, undefined4 param_1);  // 0x101CE9E0
XI_API void __thiscall PlantMenu_AddChild(void * self_, int param_1);  // 0x101CEA30
XI_API void __thiscall PlantMenu_CallSlot12OnObjects(void * self_, undefined4 param_1);  // 0x101CEA80
XI_API undefined4 __thiscall PlantMenu_GetField14(void * self_);  // 0x101CEAC0
XI_API undefined4 __thiscall PlantMenu_GetField18(void * self_);  // 0x101CEAD0
XI_API undefined4 __thiscall PlantMenu_GetField1C(void * self_);  // 0x101CEAE0
XI_API void * __thiscall PlantMenu_GetTurnedByte4(void * self_);  // 0x101CEAF0
XI_API void * __thiscall PlantMenu_GetTurnedByte5(void * self_);  // 0x101CEB40
XI_API undefined4 __thiscall PlantMenu_GetDefFlagBit0(void * self_);  // 0x101CEBE0
XI_API undefined4 __thiscall PlantMenu_GetDefFlagBit1(void * self_);  // 0x101CEBF0
XI_API undefined4 __thiscall PlantMenu_GetGridCellByte(void * self_, int param_1, int param_2, int param_3);  // 0x101CECB0
XI_API void __thiscall PlantMenu_ClearItemFromGrid(void * self_, void * param_1);  // 0x101CEEF0
XI_API void __thiscall JpegTables_BuildTables(void * self_, int param_1);  // 0x101CF660
XI_API void __stdcall JpegTables_BuildCodeTable(int param_1, int param_2, int param_3, int param_4);  // 0x101CF820
XI_API void __thiscall JpegTables_Reset(void * self_);  // 0x101D0860
XI_API void __thiscall JpegTables_Free(void * self_);  // 0x101D0880
XI_API void __thiscall JpegScreenshot_PutByte(void * self_, undefined4 param_1);  // 0x101D09C0
XI_API void __thiscall JpegScreenshot_PutWordBE(void * self_, uint32_t param_1);  // 0x101D0A20
XI_API void __thiscall JpegScreenshot_PutFFThenByte(void * self_, undefined4 xi_s1);  // 0x101D0A40
XI_API undefined4 __cdecl JpegScreenshot_TriggerOnSceneState60(void);  // 0x101D0AB0
XI_API int * __cdecl CopyrightText_Draw(void);  // 0x101D0B00
XI_API undefined * __cdecl CopyrightText_Format(void);  // 0x101D0C40
XI_API undefined4 __cdecl JpegScreenshot_TakeScreenshot(int param_1);  // 0x101D0EA0
XI_API undefined4 __cdecl JpegScreenshot_SaveJpeg512x382(undefined4 param_1);  // 0x101D1000
XI_API undefined4 __cdecl JpegScreenshot_WriteWithFileMngA(int param_1, undefined4 param_2);  // 0x101D10C0
XI_API undefined4 __cdecl JpegScreenshot_SaveJpegScreenSize(undefined4 param_1);  // 0x101D1100
XI_API undefined4 __cdecl JpegScreenshot_WriteWithFileMngB(int param_1, undefined4 param_2);  // 0x101D1180
XI_API void __cdecl YkInit(void);  // 0x101D11C0
XI_API undefined4 __cdecl JpegScreenshot_TestMask10663188(uint32_t param_1, uint32_t param_2);  // 0x101D29C0
XI_API undefined4 __thiscall MyRoom_GetObjectAtIndex(void * self_);  // 0x101D30F0
XI_API undefined4 __thiscall MyRoom_SelectFurniture(void * self_, uint32_t param_1, int param_2);  // 0x101D3910
XI_API void __thiscall MyRoom_CallAllFurniture101CEA80(void * self_, undefined4 param_1);  // 0x101D39A0
XI_API void __thiscall MyRoom_ReleaseTable(void * self_);  // 0x101D3DC0
XI_API undefined4 __thiscall MyRoom_GetFirstFurnitureId(void * self_);  // 0x101D3E70
XI_API void __thiscall MyRoom_CopyList6To818(void * self_);  // 0x101D3F60
XI_API void __cdecl MyRoom_DoNothing(void);  // 0x101D3FB0
XI_API void __thiscall MyRoom_Draw(void * self_, int * param_1);  // 0x101D3FC0
XI_API undefined4 __thiscall MyRoom_BeginMode(void * self_, int param_1);  // 0x101D55D0
XI_API void __thiscall MyRoom_Update(void * self_);  // 0x101D5680
XI_API undefined4 __thiscall MyRoom_GetFurnitureAtCell(void * self_, int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);  // 0x101D5E00
XI_API void __thiscall MyRoom_Refresh101CEC50(void * self_);  // 0x101D5E40
XI_API void __thiscall MyRoom_PlaceItemThenRefresh(void * self_, void * param_1);  // 0x101D5EA0
XI_API undefined4 __cdecl MyRoom_Is104DFD98Bit40DB1x10Clear(void);  // 0x101D5FE0
XI_API undefined4 __cdecl MyRoom_IsWord40D82Zero(void);  // 0x101D6020
XI_API undefined4 __thiscall MyRoom_StartWithCallbackOnce(void * self_, undefined4 param_1);  // 0x101D6C90
XI_API void * __thiscall YkWindows_CtorVt10338670(void * self_);  // 0x101D7C10
XI_API void * __thiscall YkWindows_CtorVt10338700(void * self_);  // 0x101D87A0
XI_API void * __thiscall Yk_CreateCommonObjects(void * self_);  // 0x101D9B10
XI_API void * __thiscall YkWindows_CtorVt10338BE8(void * self_);  // 0x101D9E90
XI_API void * __thiscall YkWindows_CtorVt10338D88(void * self_);  // 0x101DC460
XI_API void * __thiscall Yk_CreateSecondaryObjects(void * self_);  // 0x101DCE20
XI_API void * __thiscall YkWindows_CtorVt10338E60(void * self_);  // 0x101DD000
XI_API void __thiscall Yk_InitSlots(void * self_);  // 0x101DDA70
XI_API undefined4 __thiscall YkWindows_ClearSlotBytes3(void * self_, int param_1);  // 0x101DDA90
XI_API undefined4 __thiscall YkWindows_CtorVt10338EA4(void * self_);  // 0x101DDF90
XI_API undefined4 __thiscall YkWindows_CtorVt10338ED4(void * self_);  // 0x101DE6B0
XI_API void * __thiscall YkWindows_CtorVt10338F68(void * self_);  // 0x101DEDC0
XI_API void * __thiscall YkWndList_Init(void * self_);  // 0x101DF210
XI_API undefined4 __thiscall YkWindows_ClearFields14To3F(void * self_);  // 0x101E06C0
XI_API undefined4 __thiscall YkWindows_ClearFields40To48(void * self_);  // 0x101E0700
XI_API void * __thiscall YkWindows_CtorVt10339250(void * self_);  // 0x101E0A90
XI_API undefined4 __attribute__((stdcall, regparm(3))) YkWindows_LoadDatListOrRun101E1A70(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, undefined4 param_2, undefined4 param_3);  // 0x101E11C0
XI_API undefined4 __thiscall YkWindows_IsWithin23Seconds(void * self_);  // 0x101E15C0
XI_API void __thiscall YkWindows_ClearField74(void * self_);  // 0x101E15F0
XI_API undefined4 __thiscall Yk_ClearEntries(void * self_);  // 0x101E1A00
XI_API undefined4 __attribute__((stdcall, regparm(3))) YkWindows_LoadDatListSync(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x101E1AE0
XI_API undefined4 __thiscall YkWindows_LoadDatSync(void * self_, undefined4 param_1);  // 0x101E24F0
XI_API void * __thiscall YkWindows_CtorVt10339298(void * self_);  // 0x101E2B10
XI_API void * __thiscall YkWindows_CtorVt103394C0(void * self_);  // 0x101E3F50
XI_API void * __thiscall YkWindows_CtorVt10339530(void * self_);  // 0x101E48F0
XI_API void * __thiscall YkWindows_CtorVt10339698(void * self_);  // 0x101E4A20
XI_API void * __thiscall YkWindows_CtorVt10339728(void * self_);  // 0x101E51B0
XI_API void * __thiscall YkWindows_CtorVt10339770(void * self_);  // 0x101E5750
XI_API void * __thiscall YkWindows_CtorVt103397B8(void * self_);  // 0x101E5BA0
XI_API void * __thiscall Yk_CtorVt10339BC0(void * self_);  // 0x101E6FB0
XI_API void __cdecl YkWindows_AttachTwoWindows(void);  // 0x101E7E90
XI_API void * __thiscall YkWindows_CtorVt10339D78(void * self_);  // 0x101EB390
XI_API void * __thiscall YkWindows_CtorVt10339DE8(void * self_);  // 0x101EB7E0
XI_API void * __thiscall YkWindows_CtorVt10339E48(void * self_);  // 0x101EBE00
XI_API void * __thiscall YkWindows_CtorVt10339EB8(void * self_);  // 0x101EC0D0
XI_API undefined4 __thiscall YkWindows_InitFields1CTo3C(void * self_);  // 0x101EC3C0
XI_API void * __thiscall YkWindows_CtorVt10339FA0(void * self_);  // 0x101ED450
XI_API undefined4 __thiscall YkWindows_UpdateScreenTransform(void * self_);  // 0x101EE040
XI_API void * __thiscall YkWindows_CtorVt1033A000(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5);  // 0x101EE230
XI_API undefined4 __attribute__((stdcall, regparm(3))) YkWindows_SetFlag20AndValues(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, undefined4 param_2, undefined4 param_3);  // 0x101EFAD0
XI_API void __attribute__((stdcall, regparm(3))) YkWindows_SetFlag20Default(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x101EFB10
XI_API void __thiscall Yk_ResetFields(void * self_);  // 0x101EFCA0
XI_API void __thiscall YkWindows_ClearSixFlags(void * self_);  // 0x101EFEA0
XI_API undefined4 __cdecl YkWindows_Return8(void);  // 0x101EFFD0
XI_API undefined4 __cdecl YkWindows_GetTable103820B0(int param_1);  // 0x101EFFE0
XI_API void * __thiscall YkWindows_CtorVt1033A5D8(void * self_);  // 0x101F17C0
XI_API void __thiscall YkWndItem_Open(void * self_, int * param_1);  // 0x101F23A0
XI_API void __cdecl YkWindows_GetItemEntryState(undefined4 param_1, undefined1 * param_2, undefined1 * param_3, undefined1 * param_4, undefined2 * param_5, undefined4 * param_6, undefined1 * param_7, undefined1 * param_8);  // 0x101F35A0
XI_API void * __thiscall YkWindows_CtorVt1033A6D0(void * self_);  // 0x101F43F0
XI_API undefined4 __thiscall YkWindows_InitEightSlots80808080(void * self_);  // 0x101F4AF0
XI_API undefined4 __thiscall YkWindows_SetSlot(void * self_, int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);  // 0x101F4B20
XI_API void __attribute__((stdcall, regparm(3))) YkWindows_ClampListScroll(undefined4 xi_eax, undefined4 xi_edx, int param_1);  // 0x101F66B0
XI_API undefined4 __attribute__((stdcall, regparm(3))) YkWindows_SetField18AndRemainder(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, undefined4 param_2);  // 0x101F6700
XI_API undefined4 __thiscall YkWindows_ShowSelectedHelp(void * self_, undefined4 param_1);  // 0x101F6720
XI_API void * __thiscall Yk_InitBase(void * self_, undefined4 param_1);  // 0x101F67C0
XI_API void __thiscall YkWindows_ReadRectAndShowHelp(void * self_);  // 0x101F68F0
XI_API undefined4 __attribute__((stdcall, regparm(3))) YkWindows_SetListItems(uint32_t xi_eax_unused, undefined4 param_2, int param_1, undefined4 param_3, undefined4 param_4, undefined4 param_5);  // 0x101F7020
XI_API void __attribute__((stdcall, regparm(3))) YkWindows_SelectListIndex(undefined4 xi_eax, undefined4 param_2, int param_1, int param_3, int param_4);  // 0x101F7080
XI_API int __thiscall YkWindows_GetSelectedIndex(void * self_);  // 0x101F7100
XI_API uint32_t __attribute__((cdecl, regparm(1))) YkWindows_GetValueIfLoaded(undefined4 xi_eax);  // 0x101F71A0
XI_API uint32_t __cdecl Yk_GetSharePercent(int param_1, int param_2);  // 0x101F71C0
XI_API undefined4 __cdecl YkWindows_GetEntryFieldA(int param_1);  // 0x101F7200
XI_API undefined4 __cdecl YkWindows_GetEntryFieldB(int param_1);  // 0x101F7240
XI_API uint32_t __cdecl YkWindows_GetEntryFieldBPercent(int param_1);  // 0x101F7260
XI_API int __cdecl Yk_FindEntryIndex(int param_1, int param_2, undefined4 param_3);  // 0x101F7430
XI_API int __cdecl YkWindows_GetEntryCode(int param_1);  // 0x101F7480
XI_API undefined4 __cdecl YkWindows_TestFlagBitFwd(int param_1);  // 0x101F74E0
XI_API uint32_t __cdecl YkWindows_GetEntryPosition(int param_1, int param_2, short * param_3, short * param_4, undefined4 param_5, undefined4 param_6);  // 0x101F74F0
XI_API long double __cdecl YkWindows_GetEntryRate(int param_1);  // 0x101F75C0
XI_API undefined * __cdecl YkWindows_FormatTargetMapGrid(undefined4 param_1);  // 0x101F7600
XI_API undefined4 __attribute__((cdecl, regparm(1))) fn_101F79E0(undefined4 xi_eax, undefined4 param_1, undefined4 param_2, int param_3, undefined4 param_4);  // 0x101F79E0
XI_API void __attribute__((stdcall, regparm(3))) YkWindows_SetMapWindowState(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x101F7C00
XI_API void __thiscall YkWindows_PlaceListedActerMarkers(void * self_, undefined4 param_1);  // 0x101F7DB0
XI_API void __cdecl YkWindows_PlaceActerMarker(undefined4 param_1, uint32_t param_2, int param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6);  // 0x101F7EC0
XI_API undefined4 __thiscall YkWindows_TerminateMarkerNames(void * self_);  // 0x101F7FE0
XI_API void __thiscall YkWindows_InitMapMarkers(void * self_);  // 0x101F8020
XI_API void __thiscall YkWindows_LoadMapMarkerFile(void * self_, undefined4 xi_s1, undefined4 xi_s2);  // 0x101F80B0
XI_API void __thiscall YkWindows_SubmitMarkerFile(void * self_, undefined4 xi_s1, undefined4 xi_s2);  // 0x101F82B0
XI_API void __thiscall YkWindows_SetMapView(void * self_, int param_1, undefined4 param_2, undefined4 param_3, int * param_4, undefined4 param_5);  // 0x101F8360
XI_API int __cdecl YkWindows_GetMapResourceId(int param_1);  // 0x101F85F0
XI_API void __thiscall YkWindows_ReportMapChange(void * self_, int param_1);  // 0x101F8650
XI_API undefined4 __cdecl YkWindows_AddMessage32(void);  // 0x101F86B0
XI_API void * __thiscall YkWindows_CtorVt1033A8B8(void * self_);  // 0x101F86C0
XI_API void __thiscall YkWindows_UpdateTargetMarker(void * self_, undefined4 param_1);  // 0x101F8EA0
XI_API void __cdecl YkWindows_GetTargetMapCoords(undefined4 param_1, undefined2 * param_2, short * param_3);  // 0x101F8FB0
XI_API void __thiscall YkWindows_ClearMapMarkers(void * self_, undefined4 param_1);  // 0x101F9010
XI_API undefined4 __thiscall fn_101F9110(void * self_, undefined4 param_1, undefined4 param_2, uint8_t * param_3, undefined4 param_4);  // 0x101F9110
XI_API void __thiscall Yk_ResetSlots(void * self_);  // 0x101F92B0
XI_API void __thiscall YkWindows_ResetMapBuffers(void * self_, int param_1);  // 0x101F92E0
XI_API void __thiscall Yk_FreeBuffers(void * self_);  // 0x101F9370
XI_API undefined4 __attribute__((stdcall, regparm(3))) fn_101F9A20(int * xi_eax, uint32_t xi_edx_unused, void * self_, int param_2);  // 0x101F9A20
XI_API undefined4 __thiscall YkWindows_CloseMapMenus(void * self_, undefined4 param_1);  // 0x101FA420
XI_API undefined4 __thiscall YkWindows_CanShowMapTitle(void * self_);  // 0x101FAAB0
XI_API void __thiscall fn_101FAAF0(void * self_);  // 0x101FAAF0
XI_API undefined4 __thiscall YkWindows_MarkGroupMarkers(void * self_, int param_1);  // 0x101FAD00
XI_API void __thiscall YkWindows_ClearMarkerFlags(void * self_, undefined4 param_1);  // 0x101FAD40
XI_API undefined4 __thiscall YkWindows_StepMarkerGroup(void * self_, int param_1);  // 0x101FAD70
XI_API undefined4 __cdecl YkWindows_OnMapClick(undefined4 param_1, char * param_2);  // 0x101FAFF0
XI_API void __thiscall YkWindows_SetupMapImage(void * self_);  // 0x101FB1B0
XI_API void * __thiscall YkWindows_CtorVt1033A918(void * self_);  // 0x101FB710
XI_API void * __thiscall YkWindows_CtorVt1033A988(void * self_);  // 0x101FC2C0
XI_API void * __thiscall YkWindows_CtorVt1033A9D0(void * self_);  // 0x101FCBC0
XI_API void * __thiscall YkWindows_CtorVt1033AAB0(void * self_);  // 0x101FD000
XI_API undefined4 __attribute__((stdcall, regparm(3))) YkWindows_SortEntries(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, uint32_t * param_2);  // 0x101FD600
XI_API undefined4 __thiscall YkWindows_CtorVt1033AAF8(void * self_);  // 0x101FE430
XI_API void * __thiscall YkWindows_CtorVt1033ABE0(void * self_);  // 0x101FF000
XI_API void * __thiscall YkWindows_CtorVt1033AC28(void * self_);  // 0x10200B60
XI_API void * __thiscall YkWindows_InitFromTablesA(void * self_);  // 0x10201020
XI_API void * __thiscall YkWindows_InitFromTablesB(void * self_);  // 0x10201130
XI_API undefined4 __thiscall YkWindows_DrawCountersAndGauge(void * self_, int param_1, int param_2);  // 0x10201340
XI_API void __thiscall Yk_UpdateLayout(void * self_);  // 0x102015D0
XI_API undefined4 __cdecl YkWindows_GetState10664390(void);  // 0x10201690
XI_API void __cdecl YkWindows_CreateMenuObjects(void);  // 0x102017A0
XI_API void * __thiscall YkWindows_CtorVt1033B0C8(void * self_);  // 0x10201C90
XI_API undefined4 __cdecl Yk_CheckFlagAndWord1C(int param_1);  // 0x10201EB0
XI_API undefined4 __attribute__((cdecl, regparm(1))) YkWindows_IsSingleUncheckedEntry(undefined4 xi_eax);  // 0x10201F00
XI_API void __stdcall YkWindows_Call101CA180IfText(undefined4 param_1, undefined4 param_2, char * param_3, undefined4 param_4);  // 0x10202380
XI_API undefined4 __attribute__((stdcall, regparm(3))) YkWindows_DrawLabelIfStateGroup06Or38(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, int param_2, int param_3);  // 0x10202AF0
XI_API undefined * __stdcall Yk_GetActiveEntry(int param_1);  // 0x10202C90
XI_API void __cdecl YkWindows_ResetMode(void);  // 0x10202D10
XI_API void __cdecl YkWindows_SetModeFwd(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6);  // 0x10202D30
XI_API void __cdecl Yk_SetMode(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7);  // 0x10202D80
XI_API void __cdecl YkWindows_RunCallbackAndResetTarget(void);  // 0x10202F00
XI_API undefined4 * __cdecl YkWindows_GetRecord10664390(void);  // 0x10203120
XI_API uint32_t __attribute__((stdcall, regparm(1))) YkWindows_FindActiveEntryById(undefined4 xi_eax, int param_1, undefined4 param_2, undefined4 param_3);  // 0x102031F0
XI_API undefined4 __stdcall Yk_GetActerIfValid(int param_1);  // 0x102033C0
XI_API undefined4 __stdcall YkWindows_GetSelectedActer(undefined4 param_1, undefined4 param_2);  // 0x10203430
XI_API undefined4 __stdcall YkWindows_GetActerIfValidMax5(int param_1, undefined4 param_2);  // 0x10203480
XI_API undefined4 __stdcall Yk_GetActerPtrA0(undefined4 param_1);  // 0x102034A0
XI_API undefined4 __stdcall YkWindows_GetSelectedActerFieldA0(undefined4 param_1, undefined4 param_2);  // 0x102034C0
XI_API undefined4 __stdcall YkWindows_GetCurrentEntry(undefined4 param_1);  // 0x102034E0
XI_API undefined4 __stdcall Yk_GetEntryOrZero(int param_1, undefined4 param_2);  // 0x10203500
XI_API void __stdcall Yk_SetCurrentIndex(int param_1);  // 0x10203520
XI_API int __stdcall Yk_FindIndexById(int param_1);  // 0x10203540
XI_API void __attribute__((stdcall, regparm(3))) YkWindows_UpdateEntryCycle(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x10203920
XI_API void __stdcall Yk_SetStateFromFlag(undefined4 param_1, undefined4 xi_s2);  // 0x10203BC0
XI_API undefined4 __stdcall YkWindows_ReadOrLoadGstEntry(undefined4 param_1);  // 0x10203BE0
XI_API void * __thiscall YkWindows_CtorVt1033B110(void * self_);  // 0x10205500
XI_API undefined4 __thiscall YkWindows_ClearFields14To24(void * self_);  // 0x10206420
XI_API undefined4 __thiscall YkWindows_HasKind0CFlag40Entry(void * self_);  // 0x10207360
XI_API void * __thiscall YkWindows_CtorVt1033B248(void * self_);  // 0x10207730
XI_API undefined4 __thiscall YkWindows_CtorVt1033B28C(void * self_);  // 0x10208500
XI_API void * __thiscall YkWindows_CtorVt1033B340(void * self_);  // 0x10209300
XI_API void * __thiscall YkWindows_CtorVt1033B3A0(void * self_);  // 0x10209B90
XI_API void * __thiscall YkWindows_CtorVt1033B948(void * self_);  // 0x1020B500
XI_API undefined4 __thiscall YkWindows_RecordInit(void * self_, undefined4 param_1);  // 0x1020BA40
XI_API void __thiscall Yk_LoadIndexedTables(void * self_);  // 0x1020BE90
XI_API void * __thiscall YkWindows_CtorVt1033B9D8(void * self_);  // 0x1020C470
XI_API void * __thiscall YkWindows_CtorVt1033BA20(void * self_);  // 0x1020CC30
XI_API void * __thiscall YkWindows_CtorVt1033BA68(void * self_);  // 0x1020ED00
XI_API void * __thiscall YkWndShop_Constructor(void * self_);  // 0x10210310
XI_API void __thiscall YkWindows_ResetState(void * self_);  // 0x10210D60
XI_API void * __thiscall YkWindows_Init(void * self_, undefined4 * param_1, undefined4 param_2);  // 0x10210DA0
XI_API undefined4 __thiscall YkWindows_Open(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, int param_5, undefined4 param_6, int param_7);  // 0x10210E30
XI_API void __thiscall YkWindows_Close(void * self_, undefined4 param_1);  // 0x10210FC0
XI_API undefined4 __thiscall YkWindows_Call10156C30InRect(void * self_);  // 0x10211050
XI_API undefined4 __thiscall YkWindows_HandleChoice(void * self_, undefined4 param_1);  // 0x102112B0
XI_API undefined4 __cdecl YkWindows_ApplyMusicVolume(void);  // 0x10211340
XI_API void __thiscall YkWindows_Refresh(void * self_);  // 0x10211370
XI_API void * __thiscall FaqHelp_CtorVt1033BCF8(void * self_);  // 0x10216570
XI_API void * __thiscall FaqHelp_CtorVt1033BD58(void * self_);  // 0x102175C0
XI_API undefined4 __thiscall FaqHelp_ClearWords0To0A(void * self_);  // 0x1021B330
XI_API void __cdecl FaqHelp_Create(void);  // 0x1021BB90
XI_API void __thiscall FaqHelp_SetVtable1033BDA0(void * self_);  // 0x1021BC20
XI_API undefined4 * __thiscall FaqHelp_CopyRecordCtor(void * self_, char * param_1);  // 0x1021BC30
XI_API undefined4 __cdecl FaqHelp_ReturnTrue(void);  // 0x1021BCB0
XI_API unsigned char __thiscall FaqHelp_SaveToDat(void * self_, char * param_1);  // 0x1021BDB0
XI_API undefined4 __thiscall FaqHelp_LoadFromDat(void * self_, char * param_1, undefined4 xi_s2);  // 0x1021BF60
XI_API void * __thiscall FaqHelp_ResetEntries(void * self_);  // 0x1021C010
XI_API undefined4 __thiscall FaqHelp_Construct(void * self_, undefined4 param_1, int param_2, int param_3);  // 0x1021C070
XI_API undefined4 __attribute__((stdcall, regparm(3))) FaqHelp_SaveAndRelease(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, int param_2, int param_3);  // 0x1021C100
XI_API undefined4 __thiscall FaqHelp_CanUpdate(void * self_);  // 0x1021C160
XI_API undefined4 __cdecl FaqHelp_IsSpecialKey(int param_1);  // 0x1021C1B0
XI_API undefined4 __thiscall FaqHelp_AssignItem(void * self_, short * param_1, uint32_t param_2);  // 0x1021C210
XI_API undefined4 __thiscall FaqHelp_ClearAndAssign(void * self_, short * param_1, uint32_t param_2);  // 0x1021C2E0
XI_API undefined4 __thiscall FaqHelp_ResetSlot(void * self_, undefined4 param_1, uint32_t param_2);  // 0x1021C350
XI_API undefined4 __thiscall FaqHelp_SyncSlots(void * self_);  // 0x1021C380
XI_API uint32_t __thiscall FaqHelp_Update(void * self_);  // 0x1021C4C0
XI_API uint32_t __thiscall FaqHelp_AppendEntry(void * self_, undefined2 * param_1, undefined4 param_2, int param_3);  // 0x1021C5B0
XI_API int __thiscall FaqHelp_RemoveByKey(void * self_, uint32_t param_1);  // 0x1021C680
XI_API undefined4 __attribute__((stdcall, regparm(3))) FaqHelp_RebuildWithGlobalFlag(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, undefined4 param_2, undefined4 param_3, undefined4 param_4);  // 0x1021C7C0
XI_API undefined4 __thiscall FaqHelp_Rebuild(void * self_, undefined4 param_1, int param_2, int param_3, undefined4 param_4);  // 0x1021C7E0
XI_API undefined4 __thiscall FaqHelp_GetSlotForEntry(void * self_, uint32_t param_1);  // 0x1021CB80
XI_API undefined4 __thiscall FaqHelp_Is14Not198C8(void * self_);  // 0x1021CCB0
XI_API void * __thiscall FaqHelp_ResetEntryCtor(void * self_);  // 0x1021D250
XI_API undefined4 __thiscall FaqHelp_Reset(void * self_);  // 0x1021D270
XI_API undefined4 __thiscall FaqHelp_LoadFromId(void * self_, undefined4 param_1, undefined4 param_2);  // 0x1021D2D0
XI_API undefined4 __thiscall FaqHelp_SetId(void * self_, undefined4 param_1, undefined4 param_2);  // 0x1021D380
XI_API undefined4 __attribute__((cdecl, regparm(1))) CXiMovie_DestroyGlobal(undefined4 xi_eax);  // 0x1021D460
XI_API uint32_t __thiscall MenuPanels_InitAndMarkReady(void * self_, undefined4 param_1);  // 0x1021D930
XI_API undefined4 __thiscall Movie_Update(void * self_);  // 0x1021D980
XI_API undefined4 __attribute__((cdecl, regparm(1))) MenuPanels_ReleaseReturnTrue(undefined4 xi_eax);  // 0x1021D9A0
XI_API int * __stdcall MenuPanels_Assign(int * param_1, int * param_2);  // 0x1021DD20
XI_API void __cdecl MenuPanels_NoOp(void);  // 0x1021DDC0
XI_API undefined4 __thiscall Movie_GetCurrentTexture(void * self_);  // 0x1021DDF0
XI_API void __thiscall MenuPanels_Release(void * self_);  // 0x1021DE10
XI_API void __thiscall MenuPanels_ReleaseComPtr(void * self_);  // 0x1021DE20
XI_API void __thiscall MenuPanels_QueryInterface10385E80(void * self_, undefined4 param_1);  // 0x1021DE30
XI_API void __thiscall MenuPanels_QueryInterface10385E90(void * self_, undefined4 param_1);  // 0x1021DE50
XI_API void __thiscall MenuPanels_QueryInterface10385EA0(void * self_, undefined4 param_1);  // 0x1021DE70
XI_API void * __thiscall MenuPanels_ConstructWithBase(void * self_, undefined4 param_1, undefined4 * param_2);  // 0x1021DE90
XI_API int __thiscall Movie_CreateFrameTextures(Vt_1033BE90 *self_, int a2);  // 0x1021E060
XI_API int __cdecl MenuPanels_FindByName(uint8_t * param_1, int param_2);  // 0x1021E3B0
XI_API int __cdecl MenuPanels_FindForIds(short * param_1, int * param_2, int param_3);  // 0x1021E480
XI_API void __cdecl ShapeMng_FindShapes(int * param_1, undefined4 * param_2);  // 0x1021E4D0
XI_API void __cdecl MenuPanels_ClearArrays(undefined4 * param_1, undefined4 * param_2, uint32_t param_3);  // 0x1021E500
XI_API int __cdecl MenuPanels_UpdateIndexList(int param_1, int param_2, int param_3, int param_4, int param_5, undefined1 * param_6);  // 0x1021E550
XI_API uint32_t __cdecl MenuPanels_IsIdInTable10485A30(undefined4 param_1);  // 0x1021E670
XI_API void __thiscall MenuPanels_ResetFields(void * self_);  // 0x1021E690
XI_API void __thiscall MenuPanels_Init(void * self_, undefined4 param_1, int param_2, uint32_t param_3, undefined4 param_4);  // 0x1021E760
XI_API void __cdecl MenuPanels_RotateBytesByBitCount(int param_1, int param_2);  // 0x1021E870
XI_API void __cdecl MenuPanels_CallPanel1021F240And102203B0(void);  // 0x1021ED90
XI_API void __attribute__((cdecl, regparm(1))) MenuPanels_CallPanel1021EF10(undefined4 xi_eax);  // 0x1021EDC0
XI_API undefined4 __attribute__((cdecl, regparm(1))) MenuPanels_Call1021EF30If10666E84(undefined4 xi_eax);  // 0x1021EDD0
XI_API undefined4 __cdecl Menu_GetPanelByte0D(void);  // 0x1021EDE0
XI_API undefined4 __cdecl Menu_SetPanelWord28(undefined4 param_1);  // 0x1021EE00
XI_API void __cdecl Menu_SetPanelWord2A(undefined4 param_1);  // 0x1021EE20
XI_API void __cdecl Menu_SetPanelMetrics(float param_1, float param_2, undefined4 param_3);  // 0x1021EE70
XI_API undefined4 __thiscall MenuPanels_InitFieldsDTo38(void * self_);  // 0x1021EEB0
XI_API undefined4 __thiscall MenuPanels_SetFlagDAndField1C(void * self_);  // 0x1021EF10
XI_API void __stdcall MenuPanels_SetPanelMetricsByKind(undefined4 param_1, undefined4 param_2, undefined4 param_3);  // 0x1021EF60
XI_API long double __stdcall ActerBuff_FindNearest(float * param_1, int * param_2);  // 0x1021F030
XI_API int __stdcall ActerBuff_CollectNearby(int param_1, undefined4 param_2);  // 0x1021F140
XI_API void __stdcall MenuPanels_GetWindowRect(short * param_1);  // 0x1021F360
XI_API void __thiscall MenuPanels_DrawPanelForActor(void * self_);  // 0x1021F410
XI_API void __stdcall MenuPanels_DrawActorPanelFigures(int param_1);  // 0x1021F480
XI_API void __thiscall MenuPanels_DrawEntryRows(void * self_, undefined4 xi_s1);  // 0x1021F950
XI_API undefined4 __stdcall MenuPanels_DrawLabelledRow(int param_1, int param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7, uint8_t * param_8);  // 0x1021FA90
XI_API void __stdcall MenuPanels_DrawTwoDigitValue(int param_1, undefined4 param_2, undefined4 xi_s3);  // 0x1021FB10
XI_API void __stdcall MenuPanels_DrawBarRow(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, uint8_t * param_6);  // 0x1021FB80
XI_API void __stdcall MenuPanels_DrawNameRows(undefined4 param_1, undefined4 param_2, int param_3, int param_4, int param_5, int param_6);  // 0x1021FBD0
XI_API void __thiscall ActerBuff_DrawNearby(void * self_);  // 0x1021FCE0
XI_API void __thiscall MenuPanels_DrawStrongholdPanel(void * self_);  // 0x1021FE10
XI_API void __stdcall MenuPanels_DrawLabelBar(int param_1, undefined4 param_2, void * param_3, float param_4, undefined4 param_5);  // 0x102201A0
XI_API void __thiscall MenuPanels_DrawGameTime(void * self_, int param_1, int param_2);  // 0x102201F0
XI_API int __thiscall MenuPanels_RefreshTargetGridText(void * self_);  // 0x10220350
XI_API long double __cdecl Camera_GetWrappedYaw(void);  // 0x10220C20
XI_API void __cdecl ShapeMng_FillMenuShapes(void);  // 0x10220C80
XI_API undefined4 __cdecl Menu_GetTableEntry(int param_1, int param_2);  // 0x10220CF0
XI_API undefined4 __cdecl Menu_GetGlobalTableEntry(int param_1);  // 0x10220D10
XI_API void * __thiscall MenuPanels_InitPanelState(void * self_);  // 0x10220FD0
XI_API undefined4 __thiscall MenuPanels_SetEntryText(void * self_, uint8_t * param_1, int param_2);  // 0x10221030
XI_API undefined4 __thiscall Entry_ClearText(void * self_, int param_1);  // 0x102211B0
XI_API void __thiscall KaHelpMes_ResetLoadMes(void * self_, uint32_t param_1);  // 0x10221300
XI_API int __thiscall MenuPanels_Draw(int *self_);  // 0x102214D0
XI_API undefined4 __thiscall MenuPanels_SelectShownLine(void * self_);  // 0x10221680
XI_API uint32_t __thiscall MenuPanels_IsDone(void * self_);  // 0x10221740
XI_API void __cdecl MenuPanels_InitMenuShapes(void);  // 0x102217A0
XI_API void * __thiscall MenuPanels_Construct(void * self_);  // 0x102217C0
XI_API void __thiscall MenuPanels_InitRect(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);  // 0x10221900
XI_API undefined4 __thiscall MenuPanels_AllocEntriesAndSetCounts(void * self_, undefined4 param_1, undefined4 param_2, int param_3, int param_4, int param_5);  // 0x10221920
XI_API undefined4 __thiscall MenuPanels_SetCountAndRebuild(void * self_, int param_1, undefined4 param_2);  // 0x10221A80
XI_API void __thiscall MenuPanels_GetWindowLocate(void * self_, int * param_1, int * param_2);  // 0x10221BE0
XI_API undefined4 __thiscall MenuPanels_RunRowCallbacks(void * self_);  // 0x10221F50
XI_API void __thiscall MenuPanels_SetMode(void * self_, undefined4 param_1);  // 0x10222110
XI_API void __cdecl MenuPanels_CreateSubsystems(void);  // 0x10222960
XI_API uint32_t __cdecl MenuPanels_ResolveAlias(uint32_t param_1);  // 0x10222C10
XI_API int __cdecl MenuPanels_GetSlotInfo(undefined4 param_1, undefined4 * param_2);  // 0x10222C90
XI_API uint32_t __cdecl MenuPanels_FindRecordIdByText(char * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5);  // 0x10222E20
XI_API uint32_t __cdecl MenuPanels_FindByTypeIndex(uint32_t param_1, undefined4 param_2);  // 0x10223040
XI_API uint32_t __cdecl MenuPanels_IsListedIdFlagged(uint32_t param_1);  // 0x102231F0
XI_API uint32_t __cdecl MenuPanels_FindEntryByCallback(char * param_1, undefined4 param_2, int param_3, int param_4);  // 0x10223240
XI_API undefined4 __cdecl MenuPanels_HasBitIdPlus200(undefined4 param_1);  // 0x10223360
XI_API undefined4 __cdecl MenuPanels_TestBit(int param_1, uint32_t param_2);  // 0x10223390
XI_API void __cdecl MenuPanels_SetTargetValuesFor(int param_1);  // 0x102233E0
XI_API void __cdecl MenuPanels_SetTargetValuesWithCallback(int param_1);  // 0x10223760
XI_API void * __thiscall MenuPanels_ConstructFromScene(void * self_);  // 0x102238E0
XI_API undefined * __cdecl MenuPanels_GetObjectOnce(void);  // 0x10223930
XI_API void * __thiscall MenuPanels_Ctor102239A0(void * self_);  // 0x102239A0
XI_API void __thiscall MenuPanels_LoadFromFile(void * self_);  // 0x102239C0
XI_API void * __thiscall MenuPanels_InitAndRegister(void * self_);  // 0x10223BB0
XI_API undefined4 __cdecl MenuPanels_ClearRecordIfAskedOrFull(int param_1, undefined4 * param_2);  // 0x10223C00
XI_API char __thiscall MenuPanels_Refresh(void * self_);  // 0x10223C90
XI_API void * __thiscall MenuPanels_ConstructFillMinus1(void * self_);  // 0x10223E60
XI_API uint32_t __thiscall MenuPanels_GetEntryId(void * self_, int param_1);  // 0x10224120
XI_API int __thiscall MenuPanels_GetRecord(void * self_, int param_1);  // 0x10224160
XI_API int __thiscall MenuPanels_FindByteIndex(void * self_, uint32_t param_1);  // 0x10225090
XI_API int __thiscall MenuPanels_ComputeCount(void * self_, int param_1, int param_2, undefined4 xi_s3);  // 0x10225120
XI_API int __thiscall MenuPanels_ComputeDelta(void * self_, int param_1, int param_2, undefined4 xi_s3);  // 0x10225220
XI_API void * __thiscall MenuPanels_ConstructSetGlobals(void * self_);  // 0x102254D0
XI_API void * __thiscall MenuPanels_InitIndexMap128(void * self_);  // 0x10226080
XI_API void __cdecl MenuPanels_FillIdentity128(int param_1, int param_2);  // 0x102260C0
XI_API undefined * __cdecl MenuPanels_GetObject106670C8Once(void);  // 0x10226180
XI_API void * __thiscall MenuPanels_Ctor102261F0(void * self_);  // 0x102261F0
XI_API void __thiscall MenuPanels_LoadDMsgTable(void * self_);  // 0x10226210
XI_API void * __thiscall MenuPanels_ConstructZeroFields(void * self_);  // 0x10226550
XI_API void * __thiscall MenuPanels_InitIndexMap64(void * self_);  // 0x10226C80
XI_API int __cdecl MenuPanels_FindEntryByCallback64(char * param_1);  // 0x10227000
XI_API void * __thiscall MenuPanels_Alloc1800(void * self_);  // 0x10227080
XI_API void * __thiscall MenuPanels_ConstructAllocEntries(void * self_);  // 0x102271B0
XI_API void __thiscall MenuPanels_LoadNamedEntries(void * self_);  // 0x102271D0
XI_API void __cdecl MenuPanels_CreateAndLoadEntries(void);  // 0x10227750
XI_API void * __thiscall MenuPanels_ConstructBuffersAt68(void * self_);  // 0x102278B0
XI_API void __cdecl MenuPanels_DrawMovie(int param_1, undefined4 param_2, int param_3, undefined4 param_4, int param_5);  // 0x10227F70
XI_API undefined4 __cdecl MenuPanels_DrawTimeLeftText(int param_1, undefined4 param_2, int param_3, int param_4, int param_5);  // 0x10228080
XI_API void __thiscall MenuPanels_ClearHeaderFields(void * self_);  // 0x102281C0
XI_API void * __thiscall MenuPanels_ConstructBuffersAt8(void * self_);  // 0x10228200
XI_API undefined4 __thiscall MenuPanels_DrawTargetEntryIcons(void * self_);  // 0x10228440
XI_API void __cdecl MenuPanels_InitGlobals(void);  // 0x10229430
XI_API void * __thiscall MenuPanels_ConstructInitAt64(void * self_);  // 0x10229670
XI_API undefined4 __thiscall MenuPanels_ClearMenu(void * self_);  // 0x1022A6D0
XI_API undefined4 __cdecl MenuPanels_TestBitForId(uint32_t param_1);  // 0x1022AF80
XI_API void __cdecl MenuPanels_GetBitIndexForId(int param_1, uint32_t * param_2, int * param_3);  // 0x1022AFB0
XI_API undefined4 __cdecl MenuPanels_IsBitSetForId(undefined4 param_1);  // 0x1022AFF0
XI_API void __cdecl MenuPanels_InitSubsystems(void);  // 0x1022B080
XI_API void __cdecl MenuPanels_ClearCounters(void);  // 0x1022B260
XI_API void __cdecl MenuPanels_TickCounters(void);  // 0x1022B290
XI_API int __cdecl MenuPanels_GetMinutesCeil(int param_1);  // 0x1022B2F0
XI_API void __cdecl MenuPanels_SetTimerSeconds(undefined4 param_1);  // 0x1022B3B0
XI_API int __cdecl MenuPanels_FindTableIdByText(char * param_1, int param_2, undefined4 param_3);  // 0x1022B430
XI_API undefined4 __cdecl MenuPanels_IsEntryAvailable(int param_1);  // 0x1022B7D0
XI_API void __cdecl MenuPanels_SetTargetValuesFromList7A70(int param_1);  // 0x1022B850
XI_API void __cdecl MenuPanels_GetEntryState(int param_1, undefined1 * param_2, uint8_t * param_3, uint8_t * param_4, short * param_5, int * param_6, undefined1 * param_7, undefined1 * param_8);  // 0x1022B8E0
XI_API void * __thiscall MenuPanels_CtorVt1033C50C(void * self_);  // 0x1022BD50
XI_API undefined * __cdecl MenuPanels_GetSingleton(void);  // 0x1022BDA0
XI_API void * __thiscall MenuPanels_SingletonCtor(void * self_);  // 0x1022BE10
XI_API void __thiscall MenuPanels_LoadMessageTable(void * self_);  // 0x1022BE30
XI_API undefined4 __thiscall MenuPanels_GetRowFirstCell(void * self_, uint32_t param_1);  // 0x1022BF00
XI_API void * __thiscall MenuPanels_MixDatCtor(void * self_);  // 0x1022BFB0
XI_API undefined4 __cdecl MenuPanels_ClearRecord221IfAskedOrBad(int param_1, undefined4 * param_2);  // 0x1022C000
XI_API void * __thiscall MenuPanels_PanelCtorVt1033C510(void * self_);  // 0x1022C350
XI_API uint32_t __thiscall MenuPanels_GetEntryId7A7C(void * self_, int param_1);  // 0x1022C730
XI_API int __thiscall MenuPanels_GetRecord100(void * self_, int param_1);  // 0x1022C770
XI_API undefined4 __cdecl MenuPanels_DecodeEntryState(int * param_1, undefined1 * param_2, uint8_t * param_3, uint8_t * param_4, short * param_5, int * param_6, undefined4 param_7, undefined1 * param_8);  // 0x1022D290
XI_API char __cdecl MenuPanels_ComputeEntryFlags(int param_1);  // 0x1022D370
XI_API void __cdecl MenuPanels_ComputeEntryMode(int param_1);  // 0x1022D510
XI_API void * __thiscall MenuPanels_PanelCtorVt1033C5C0(void * self_);  // 0x1022DB80
XI_API void __cdecl MenuPanels_ReadChunkDirectory(void);  // 0x1022EC50
XI_API void __thiscall MenuPanels_Clear(void * self_);  // 0x1022ED00
XI_API void __thiscall MenuPanels_Alloc(void * self_, int param_1, int param_2);  // 0x1022ED30
XI_API undefined4 __thiscall MenuPanels_Append(void * self_, char * param_1);  // 0x1022ED70
XI_API undefined1 __thiscall MenuPanels_LoadStringTable(void * self_, int param_1);  // 0x1022EEE0
XI_API undefined4 __cdecl MenuPanels_ReadChunk(undefined4 param_1);  // 0x1022F240
XI_API void __cdecl MenuPanels_CreateMessagePanels(void);  // 0x1022F3D0
XI_API void * __thiscall MenuPanels_PanelCtorVt1033C6B0(void * self_);  // 0x1022F610
XI_API void * __thiscall MenuPanels_CtorVt1033C718(void * self_);  // 0x102303B0
XI_API void __thiscall MenuPanels_Reset(void * self_);  // 0x10230410
XI_API void * __thiscall MenuPanels_PanelCtorVt1033C720(void * self_);  // 0x10233BE0
XI_API void * __thiscall MenuPanels_PanelCtorVt1033C788(void * self_);  // 0x102340A0
XI_API undefined4 __thiscall fn_10234610(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5);  // 0x10234610
XI_API void __thiscall MenuPanels_DrawProgressBar(void * self_);  // 0x10234660
XI_API void __thiscall MenuPanels_SendMenuEventByKind(void * self_);  // 0x10234910
XI_API int __thiscall MenuPanels_ComputeClampedIndex(void * self_, undefined4 xi_s1, undefined4 xi_s2);  // 0x10234A00
XI_API undefined8 __thiscall MenuPanels_SetPair(void * self_, undefined4 param_1, undefined4 param_2);  // 0x10234A70
XI_API void * __thiscall LobbyUi_ConstructTable2(void * self_);  // 0x102380A0
XI_API void * __thiscall LobbyUi_ConstructNamed(void * self_);  // 0x102388C0
XI_API void * __thiscall LobbyUi_ConstructTable11(void * self_);  // 0x10238B30
XI_API void * __thiscall KeyPrompt_Construct(void * self_);  // 0x10239170
XI_API void __thiscall LobbyUi_ResetAndPlaceWindow(void * self_);  // 0x102391D0
XI_API undefined4 __thiscall LobbyUi_StepScreenSwitch(void * self_, undefined4 xi_s1);  // 0x10239240
XI_API void __thiscall Ui_KeyPrompt_Init(void * self_, undefined4 param_1);  // 0x10239460
XI_API undefined4 __cdecl LobbyUi_GetGlobalDword(void);  // 0x10239490
XI_API char * __thiscall Ui_DrawKeyPrompt(Vt_1033C8F0 *self_);  // 0x102394A0
XI_API void __cdecl LobbyUi_ForwardFlag1(undefined4 param_1);  // 0x1023BF20
XI_API undefined4 __thiscall LobbyUi_StoreTextIfIdle(void * self_, char * param_1);  // 0x1023C140
XI_API void __attribute__((stdcall, regparm(3))) LobbyUi_UpdateSlotNameAndDate(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, undefined4 xi_s1);  // 0x1023C540
XI_API void * __thiscall LobbyUi_ConstructBase(void * self_);  // 0x1023D610
XI_API undefined4 __cdecl LobbyUi_WaitForState1(int * param_1);  // 0x1023E4B0
XI_API void * __thiscall CIwHnList_Constructor(void * self_);  // 0x1023E830
XI_API void * __thiscall LobbyUi_ConstructTable3(void * self_);  // 0x1023F890
XI_API undefined4 __attribute__((stdcall, regparm(3))) LobbyUi_HandleSelectInput(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, undefined4 param_2);  // 0x10241800
XI_API undefined4 __attribute__((stdcall, regparm(3))) YkZip_SetGlobal2CTo31Or32(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, undefined4 param_2);  // 0x10244E60
XI_API void __cdecl LobbyThread_NoOp(void);  // 0x10244F20
XI_API void * __thiscall LobbyThread_Construct(void * self_);  // 0x10244F30
XI_API void __thiscall LobbyThread_InitState(void * self_);  // 0x10245040
XI_API undefined4 __cdecl LobbyScreen_LoadResourceRunMain(int * param_1, int param_2);  // 0x10245460
XI_API void __cdecl LobbyScreen_ReleaseResource(void);  // 0x102454E0
XI_API void __cdecl LobbyScreen_LoadResourceOnce(undefined4 param_1);  // 0x10245520
XI_API undefined4 __cdecl LobbyThread_Start(undefined4 param_1);  // 0x10245600
XI_API undefined4 __cdecl LobbyThread_SetGlobal106690AC(undefined4 param_1);  // 0x10245B50
XI_API int __cdecl Lobby_DestroyThreadPool(void);  // 0x10245B60
XI_API void __cdecl thunk_sub_10245BB0(void);  // 0x10245BA0
XI_API void __cdecl LobbyThread_ResetZone(void);  // 0x10245BB0
XI_API undefined4 __cdecl LobbyThread_IsSystemState1(void);  // 0x10245BE0
XI_API undefined4 __thiscall LobbyThread_NextSequence(void * self_);  // 0x10245F30
XI_API undefined4 __stdcall LobbyThread_SendCmd0(int * param_1, undefined4 param_2);  // 0x10246000
XI_API undefined8 __thiscall LobbyThread_QueueSoundCmd(void * self_, char * param_1, uint32_t param_2, uint32_t param_3);  // 0x10246030
XI_API undefined8 __stdcall LobbyThread_QueryChannels(undefined4 param_1, int param_2, int param_3);  // 0x10246160
XI_API void __stdcall LobbyThread_SendCmd3(int * param_1, uint32_t param_2, undefined4 param_3);  // 0x102462F0
XI_API undefined4 __stdcall LobbyThread_SendCmd4(int * param_1, uint32_t param_2, undefined4 param_3);  // 0x10246320
XI_API void __stdcall LobbyThread_SendCmd6(int * param_1);  // 0x102463C0
XI_API undefined4 __stdcall LobbyThread_QueueStreamFile(int * param_1, uint32_t param_2, undefined4 param_3);  // 0x102463F0
XI_API uint32_t __stdcall LobbyThread_QueueMusicFile(uint32_t param_1, uint32_t param_2, undefined4 param_3);  // 0x102465E0
XI_API void __stdcall LobbyThread_SendCmd8(int * param_1, uint32_t param_2, undefined4 param_3);  // 0x10246770
XI_API void __stdcall LobbyThread_SendCmd9(int * param_1, undefined4 param_2);  // 0x102467A0
XI_API undefined8 __stdcall LobbyThread_SendCmd11(int * param_1);  // 0x102467F0
XI_API undefined8 __stdcall LobbyThread_PushCmd(int param_1, int * param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8);  // 0x1024C060
XI_API void * __thiscall LobbyThread_CtorVt1033CCA8(void * self_);  // 0x1024C210
XI_API void * __thiscall LobbyThread_ConstructQueue(void * self_);  // 0x1024C930
XI_API int __cdecl StAvatarInit(_DWORD *a1);  // 0x1024CF50
XI_API void __cdecl StAvatar_InitEntriesFromTables(void);  // 0x1024D130
XI_API uint32_t __cdecl StAvatar_Teardown(uint32_t * param_1, uint32_t param_2, uint32_t param_3);  // 0x1024D180
XI_API undefined4 __cdecl StAvatar_ReleaseResources(uint32_t * param_1, int param_2);  // 0x1024D2C0
XI_API void __cdecl StAvatar_Reset(int param_1);  // 0x1024D400
XI_API void __cdecl StAvatar_RegisterTriggers(int param_1, int param_2);  // 0x1024D470
XI_API undefined4 __cdecl StAvatar_SetTableValues(uint8_t * param_1, int param_2);  // 0x1024D4A0
XI_API undefined4 __cdecl StAvatar_SetChannel(uint8_t * param_1, int param_2, int param_3);  // 0x1024D540
XI_API undefined4 __cdecl StAvatar_SetPending(uint32_t * param_1, uint32_t param_2);  // 0x1024D5C0
XI_API undefined4 __cdecl StAvatar_Unload(uint32_t * param_1);  // 0x1024D610
XI_API void __cdecl StAvatar_ApplyChannels(uint8_t * param_1);  // 0x1024D6B0
XI_API undefined4 __cdecl StAvatar_SetTransition(uint32_t * param_1, float param_2, int param_3);  // 0x1024D740
XI_API undefined4 __cdecl StAvatar_StopAndFreeBuffers(int param_1);  // 0x1024D790
XI_API undefined4 __cdecl StAvatar_ResolveItemsAndStart(uint32_t * param_1);  // 0x1024D850
XI_API void __cdecl StAvatar_FormatNames(void);  // 0x1024D9D0
XI_API undefined4 __cdecl StAvatar_Update(uint8_t * param_1);  // 0x1024DB60
XI_API void __cdecl StAvatar_UpdateInput(uint32_t * param_1, undefined4 param_2);  // 0x1024DD10
XI_API void __cdecl StAvatar_UpdateCameraYaw(float param_1);  // 0x1024DE20
XI_API void __cdecl StAvatar_UpdateCameraFollow(int param_1);  // 0x1024DFE0
XI_API void __cdecl StAvatarCore_MoveByAnalogStick(uint32_t * param_1, int param_2);  // 0x1024E280
XI_API void __cdecl StAvatar_SetFlagsBoth(int param_1, undefined4 * param_2, undefined4 * param_3);  // 0x1024E720
XI_API void __cdecl StAvatar_GetCameraMatrix(int param_1, float * param_2);  // 0x1024F050
XI_API void __cdecl StAvatar_UpdateHeading(int param_1, float * param_2, int param_3);  // 0x1024F0B0
XI_API void __cdecl StAvatar_ProjectNodes(int param_1);  // 0x1024F2C0
XI_API void __cdecl StAvatar_UpdateSteer(int param_1, int param_2);  // 0x1024F5E0
XI_API void __cdecl StAvatar_SetViewFromDancerCamera(int a1);  // 0x1024F900
XI_API void __cdecl StAvatar_AdvanceTimers(uint32_t * param_1, int param_2);  // 0x1024FC10
XI_API void __cdecl StAvatar_ProcessTriggers(int param_1);  // 0x1024FEC0
XI_API undefined4 __cdecl StAvatar_GetOffset(uint8_t * param_1, float * param_2);  // 0x1024FF50
XI_API undefined4 __cdecl StAvatar_RenderIfEnabled(int param_1, int param_2);  // 0x10250190
XI_API int __cdecl StAvatarRender(_BYTE *arg0);  // 0x102501C0
XI_API void __cdecl StAvatar_UpdateNodes(uint8_t * param_1);  // 0x102502D0
XI_API undefined4 __cdecl StAvatarFini(uint32_t * param_1);  // 0x102504D0
XI_API undefined4 __cdecl StAvatar_ResetChannels(uint8_t * param_1, uint32_t param_2);  // 0x10250580
XI_API undefined4 __cdecl StAvatar_SetFlagBit(undefined4 param_1, int param_2, int param_3);  // 0x10250660
XI_API undefined4 __attribute__((cdecl, regparm(1))) StAvatar_SetStopped(undefined4 xi_eax, uint32_t * param_1, int param_2);  // 0x102506C0
XI_API undefined4 __cdecl StAvatar_SetField10(uint8_t * param_1, int param_2);  // 0x10250760
XI_API undefined4 __cdecl StAvatar_SetField14(uint8_t * param_1, int param_2);  // 0x10250790
XI_API undefined4 __cdecl StAvatar_StoreMode(uint32_t * param_1, uint32_t param_2);  // 0x102507C0
XI_API undefined4 __cdecl StAvatar_Start(uint8_t * param_1, undefined4 param_2);  // 0x10250800
XI_API void __cdecl StAvatar_SetModelFlags(uint32_t * param_1, uint32_t param_2);  // 0x102509C0
XI_API void __cdecl StAvatar_SetModelItemFlags(uint32_t * param_1, int param_2, int param_3);  // 0x10250A40
XI_API undefined4 __cdecl StAvatar_SetLock(uint32_t * param_1, uint32_t param_2, int param_3);  // 0x10250B10
XI_API undefined4 __cdecl StAvatar_GetField20(uint8_t * param_1, undefined4 * param_2);  // 0x10250C00
XI_API undefined4 __cdecl StAvatar_InitIndices(undefined4 * param_1);  // 0x10250D80
XI_API undefined4 __cdecl StChannelItem_Load(int param_1, undefined4 param_2);  // 0x10250DB0
XI_API undefined4 __cdecl StChannelItemResolve(uint32_t * param_1);  // 0x10250F10
XI_API uint32_t __cdecl StChannel_RegisterItem(uint32_t * param_1, int param_2, float param_3);  // 0x10251070
XI_API undefined4 __cdecl StChannel_ClearFlags(uint32_t * param_1);  // 0x10251160
XI_API undefined4 __cdecl StChannel_MarkIfLoaded(uint32_t * param_1);  // 0x10251180
XI_API undefined4 __cdecl StChannel_SetValue9C(uint8_t * param_1, float param_2);  // 0x102511B0
XI_API undefined4 __cdecl StChannel_ApplyItem(uint8_t * param_1, undefined4 param_2, int param_3);  // 0x10251200
XI_API undefined4 __cdecl StChannelItemClear(uint32_t * param_1);  // 0x102512B0
XI_API undefined4 __cdecl StAvatar_UpdateFlag2(uint32_t * param_1, undefined4 param_2);  // 0x10251320
XI_API undefined4 __cdecl StAvatar_GetValue2B(uint8_t * param_1, undefined4 * param_2);  // 0x10251370
XI_API undefined4 __cdecl StAvatar_GetValue2A(uint8_t * param_1, undefined4 * param_2);  // 0x102513C0
XI_API undefined4 __cdecl StAvatar_ComputeRatioValue(uint8_t * param_1, undefined4 * param_2);  // 0x10251410
XI_API undefined4 __thiscall StDancer_Init(void * self_);  // 0x102514C0
XI_API void __thiscall StDancer_Update(void * self_);  // 0x10251500
XI_API void __thiscall Dancer_WorldEnd(void * self_, undefined4 param_1);  // 0x102515F0
XI_API void __thiscall StAvatar_SetActive(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, int param_4);  // 0x10251620
XI_API void __thiscall StAvatar_SetStateTeardown(void * self_, int param_1, uint32_t param_2);  // 0x102516B0
XI_API void __thiscall StAvatar_SetMode(void * self_, int param_1);  // 0x10251720
XI_API undefined4 __thiscall StAvatar_SetLevel(void * self_, int param_1);  // 0x10251750
XI_API void __attribute__((stdcall, regparm(3))) Dancer_SetStateIfIdle(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, int param_2);  // 0x10251780
XI_API void __thiscall StDancer_SetJobLock(void * self_, int param_1);  // 0x10251890
XI_API void __thiscall StAvatar_ResetOrSetFlag2(void * self_, int param_1);  // 0x10251920
XI_API uint32_t __thiscall StAvatar_IsFlag20(void * self_);  // 0x10251960
XI_API char __thiscall Dancer_InitDevice(int *self_);  // 0x10251A80
XI_API undefined4 __cdecl StAvatar_ReleaseMemory(void);  // 0x10251CE0
XI_API undefined4 __cdecl StAvatar_InitSlotRecord(undefined4 * param_1);  // 0x102524B0
XI_API undefined4 __cdecl StModelItemClear(uint32_t * param_1);  // 0x102524E0
XI_API undefined4 __cdecl StModelItem_ReadStart(int param_1, undefined4 param_2);  // 0x10252610
XI_API undefined4 __cdecl StModelItem_Resolve(uint32_t * param_1);  // 0x102528D0
XI_API undefined4 __cdecl StModelItem_Activate(uint8_t * param_1, uint32_t param_2);  // 0x10252A00
XI_API undefined4 __cdecl StModelItem_CheckFileRefs(uint32_t * param_1);  // 0x10252A40
XI_API undefined4 __cdecl StModelItem_SetPositionAndScale(uint8_t * param_1, undefined4 * param_2, undefined4 * param_3);  // 0x10252AC0
XI_API undefined4 __cdecl StModelItem_SetVec78(uint8_t * param_1, undefined4 param_2);  // 0x10252B50
XI_API undefined4 __cdecl StModelItem_ClearModelItem(uint8_t * param_1);  // 0x10252C10
XI_API undefined4 __cdecl StModelItem_Refresh(uint32_t * param_1, undefined4 param_2);  // 0x10252C30
XI_API undefined4 __cdecl StModelItem_Init(undefined4 * param_1);  // 0x10252C80
XI_API int __cdecl StTrigger_ProcessOpcodesUpToTime(uint32_t * param_1, uint32_t param_2, int param_3, undefined4 * param_4);  // 0x10252CC0
XI_API int __cdecl StTrigger_FindIndexAtLeast(uint32_t * param_1, int param_2, int param_3);  // 0x10252EA0
XI_API undefined4 __cdecl StTrigger_RegisterCallbacks(int param_1, uint32_t param_2, uint32_t param_3);  // 0x10252F00
XI_API undefined4 __cdecl StAvatar_CheckBuffersReady(uint32_t * param_1);  // 0x10253160
XI_API undefined4 __cdecl sqopSystemActivate(uint32_t * param_1);  // 0x102531B0
XI_API undefined4 __cdecl StAvatar_ClearResource(uint32_t * param_1);  // 0x10253210
XI_API undefined4 __attribute__((cdecl, regparm(1))) StAvatarInfo_SubmitInfoBinIfObjSet(undefined4 xi_eax, int param_1, int param_2, int param_3);  // 0x102532C0
XI_API void * __thiscall StAvatarInfo_Ctor(void * self_);  // 0x102532E0
XI_API void __cdecl StAvatarInfo_NoOp(void);  // 0x10253330
XI_API void __stdcall StAvatar_LoadInfoFile(int param_1);  // 0x10253360
XI_API undefined4 __stdcall StAvatarInfo_SubmitInfoBinIfChanged(int param_1, int param_2, int param_3);  // 0x102534F0
XI_API void __cdecl StAvatar_LoadInfo0(void);  // 0x102535B0
XI_API undefined8 __attribute__((cdecl, regparm(1))) StAvatarInfo_SendBytePairKind0(undefined4 xi_eax, undefined4 param_1, undefined4 param_2);  // 0x102535F0
XI_API void __cdecl StAvatar_LoadInfo2(void);  // 0x10253630
XI_API void __cdecl StAvatarInfo_SendBytePairKind2(undefined4 param_1, undefined4 param_2);  // 0x10253670
XI_API int __thiscall Gfx_DrawSpriteAlphaTested(void *self_, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);  // 0x10253F60
XI_API undefined4 __cdecl DmsgText_InvertBytes(int param_1, int param_2, int param_3);  // 0x102572E0
XI_API void __cdecl DmsgText_SwapEndianPair(uint32_t * param_1);  // 0x102573C0
XI_API short * __cdecl DmsgText_GetEntryPtr(uint16_t * param_1, uint32_t param_2);  // 0x102574F0
XI_API short * __cdecl DmsgText_GetCellData(int param_1, int param_2, int param_3);  // 0x10257550
XI_API int __cdecl DmsgText_Align4(int param_1);  // 0x10257590
XI_API undefined4 __cdecl DmsgText_IsNotHashOrDot(char * param_1);  // 0x102575B0
XI_API undefined4 __cdecl DmsgText_GetWord40(int param_1);  // 0x102575D0
XI_API int __cdecl DmsgText_ComputeTotalSize(int param_1);  // 0x102575E0
XI_API undefined4 * __cdecl DmsgText_Clone(undefined4 * param_1, uint32_t * param_2);  // 0x10257670
XI_API undefined * __cdecl DmsgText_GetDataOrDefault(int param_1, int param_2, int param_3, uint32_t param_4);  // 0x102577C0
XI_API undefined4 __cdecl DmsgText_GetDwordEntry(uint16_t * param_1, uint32_t param_2);  // 0x10257800
XI_API undefined1 * __cdecl DmsgText_GetDMsgTable(void);  // 0x10257830
XI_API void __thiscall DmsgText_CallFreeData(void * self_);  // 0x10257840
XI_API void __thiscall DmsgText_FreeData(void * self_);  // 0x10257850
XI_API int __thiscall DmsgText_GetRowBase(void * self_, uint32_t param_1);  // 0x10257870
XI_API short * __thiscall DmsgText_GetCell(void * self_, uint32_t param_1, uint32_t param_2);  // 0x102578B0
XI_API undefined4 __thiscall DmsgText_GetDwordCell(void * self_, uint32_t param_1, uint32_t param_2);  // 0x10257920
XI_API undefined4 __thiscall DmsgText_GetCellCol0(void * self_, undefined4 param_1);  // 0x10257950
XI_API undefined4 __thiscall DmsgText_Assign(void * self_, uint8_t * param_1, undefined4 param_2);  // 0x10257980
XI_API void __thiscall DmsgText_Bind(void * self_, uint8_t * param_1, undefined4 xi_s2);  // 0x102579B0
XI_API undefined4 __thiscall DmsgText_GetRowCount(void * self_);  // 0x10257AF0
XI_API undefined4 __thiscall DmsgText_IsBound(void * self_);  // 0x10257B10
XI_API void __thiscall DmsgText_Clear(void * self_);  // 0x10257B60
XI_API void __thiscall DmsgText_BindSource(void * self_, int param_1, undefined4 xi_s2);  // 0x10257BA0
XI_API int __thiscall DmsgText_GetRowBytes(void * self_);  // 0x10257BC0
XI_API void __thiscall DmsgText_BindDataAndMark(void * self_, undefined4 param_1);  // 0x10257BD0
XI_API void __thiscall DmsgText_BindData(void * self_, int param_1);  // 0x10257BF0
XI_API undefined4 __thiscall DmsgText_GetDataField28(void * self_);  // 0x10257C60
XI_API undefined4 __thiscall DmsgText_GetStride(void * self_);  // 0x10257C70
XI_API undefined4 __thiscall DmsgText_GetRowInfo(void * self_, int * param_1, int param_2);  // 0x10257C80
XI_API undefined4 __cdecl DmsgText_IsTypeOne(char * param_1);  // 0x10257FE0
XI_API undefined4 __cdecl DmsgText_IsTypeRange(char * param_1);  // 0x10257FF0
XI_API undefined2 * __cdecl DmsgText_GetFormString(int param_1, int param_2, int param_3);  // 0x10258040
XI_API undefined * __cdecl DmsgText_PickFormString(int param_1, int param_2, int param_3, int param_4, int param_5);  // 0x10258150
XI_API int __cdecl DmsgText_FindFirstTypeByte(char * param_1);  // 0x102581D0
XI_API undefined4 __cdecl DmsgText_ExpandFormCodes(void * param_1, undefined4 param_2, undefined4 param_3, char * param_4);  // 0x10258430
XI_API undefined4 __thiscall DmsgText_FindFirstTypeByteInText(void * self_);  // 0x102586D0
XI_API undefined4 __thiscall DmsgText_GetDataPtr(void * self_);  // 0x102586F0
XI_API void __thiscall DmsgText_FormatTextAtC(void * self_, void * param_1, int param_2, int param_3);  // 0x10258740
XI_API undefined4 __cdecl DmsgText_IsInSjisSet(char * param_1);  // 0x10258990
XI_API undefined4 __thiscall DmsgText_GetText14(void * self_);  // 0x10258AD0
XI_API undefined * __cdecl DmsgText_PickFormString2(int param_1, undefined * * param_2, int param_3, int param_4);  // 0x10258D00
XI_API char * __cdecl DmsgText_SelectQuantifierForm(int param_1, int param_2, int param_3, int param_4, undefined4 param_5);  // 0x10258D70
XI_API undefined1 * __cdecl DmsgText_GetSolchForm(undefined4 param_1);  // 0x10258E10
XI_API undefined * __cdecl DmsgText_SelectNounForm(int param_1, int param_2, undefined * * param_3, int param_4, int param_5);  // 0x10258E50
XI_API undefined1 * __cdecl DmsgText_GetQuantifierByIndex(int param_1);  // 0x10258ED0
XI_API undefined * __cdecl DmsgText_SelectAdjectiveForm(int param_1, int param_2, int param_3);  // 0x10258F00
XI_API undefined * __cdecl DmsgText_SelectGenderForm(int param_1, int param_2, int param_3);  // 0x10258F60
XI_API void __thiscall DmsgText_ClearListHeader(void * self_);  // 0x102590F0
XI_API void __thiscall DmsgText_Append(void * self_, undefined4 param_1);  // 0x10259100
XI_API undefined4 __thiscall DmsgText_IsEmpty(void * self_);  // 0x10259130
XI_API int __stdcall DmsgText_FindNextTyped(int param_1);  // 0x10259150
XI_API void __thiscall DmsgText_AppendNodeType2(void * self_, undefined4 param_1);  // 0x10259180
XI_API void __thiscall DmsgText_AppendString(void * self_, char * param_1);  // 0x102593F0
XI_API void __thiscall DmsgText_AppendValueNode(void * self_, int param_1, int param_2, int * param_3);  // 0x10259460
XI_API undefined4 __thiscall DmsgText_ComposeTextA(void * self_, int param_1);  // 0x10259990
XI_API void __attribute__((stdcall, regparm(3))) DmsgText_DeleteNodesA(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x10259DE0
XI_API undefined4 __cdecl DmsgText_IsTypeTwoZero(int param_1, int param_2);  // 0x1025A580
XI_API undefined1 * __cdecl DmsgText_GetFormById(int param_1, int param_2, int param_3);  // 0x1025A5A0
XI_API undefined1 * __cdecl DmsgText_GetFormAlt(int param_1, int param_2, int param_3);  // 0x1025A610
XI_API undefined1 * __cdecl DmsgText_GetSuffixByFlag(int param_1, int param_2);  // 0x1025A6C0
XI_API undefined1 * __cdecl DmsgText_GetEntryById(int param_1);  // 0x1025A6F0
XI_API undefined * __cdecl DmsgText_GetPrefixByFlags(int param_1, int param_2, int param_3);  // 0x1025A730
XI_API undefined1 * __cdecl DmsgText_GetPrefixByFlags2(int param_1, int param_2, int param_3, int param_4);  // 0x1025A760
XI_API void __thiscall DmsgText_ClearHead(void * self_);  // 0x1025A810
XI_API void __attribute__((stdcall, regparm(3))) DmsgText_DeleteNodesB(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x1025A820
XI_API void __thiscall DmsgText_AppendNode(void * self_, undefined4 param_1);  // 0x1025A860
XI_API int __stdcall DmsgText_FindNextTyped9(int param_1);  // 0x1025A890
XI_API undefined4 __cdecl DmsgText_ContainsChar(char * param_1);  // 0x1025A8C0
XI_API uint32_t __thiscall DmsgText_BuildNodeString(void * self_, char * param_1);  // 0x1025A930
XI_API undefined4 __thiscall DmsgText_HasNoHead(void * self_);  // 0x1025AA90
XI_API undefined4 __thiscall DmsgText_ComposeTextB(void * self_, int param_1);  // 0x1025AAA0
XI_API void __thiscall DmsgText_AppendStringNode(void * self_, char * param_1);  // 0x1025AEF0
XI_API void __thiscall DmsgText_AppendIdString(void * self_, undefined4 param_1, int param_2, char * param_3, undefined4 param_4);  // 0x1025AFB0
XI_API void __thiscall DmsgText_LinkNode(void * self_, undefined4 param_1);  // 0x1025B100
XI_API void __thiscall DmsgText_AppendTypeTwo(void * self_, undefined4 param_1);  // 0x1025B1E0
XI_API void __cdecl DmsgText_SelectTableByLanguage(undefined4 param_1);  // 0x1025B4F0
XI_API undefined4 __cdecl Scene_GetTableValue(int param_1);  // 0x1025B560
XI_API undefined * __cdecl Scene_GetMenuFrameName(int param_1);  // 0x1025B5A0
XI_API int __cdecl DmsgText_CopyWithoutMarker(undefined1 * param_1, uint32_t param_2, int param_3, uint32_t param_4);  // 0x1025B5E0
XI_API int __cdecl DmsgText_CountChars(int param_1, uint32_t param_2);  // 0x1025B680
XI_API int __cdecl DmsgText_WrapLine(int param_1, uint32_t param_2, char * param_3, uint32_t * param_4, undefined4 param_5, uint32_t param_6, uint32_t param_7, undefined * param_8, undefined * param_9);  // 0x1025B6C0
XI_API undefined4 __cdecl DmsgText_HasKnownPrefix(char * param_1);  // 0x1025BB00
XI_API undefined4 __cdecl DmsgText_IsDashNotDigit(char * param_1);  // 0x1025BB60
XI_API size_t __cdecl DmsgText_FindPrefixEntry(char * param_1, int param_2, size_t * param_3);  // 0x1025BB80
XI_API int __cdecl DmsgText_FindMarker(char * param_1, int param_2);  // 0x1025BDE0
XI_API undefined4 __cdecl DmsgText_IsWrapBreak(char * param_1);  // 0x1025BE20
XI_API uint32_t __cdecl DmsgText_ConvertCharByLanguage(undefined4 * param_1, undefined4 param_2, undefined4 * param_3);  // 0x1025BFB0
XI_API int __cdecl DmsgText_WrapSjisAt(int param_1, int param_2, undefined1 * param_3);  // 0x1025C0F0
XI_API IDirect3DDevice8 * __cdecl FontGlyphCache_GetDevice(void);  // 0x1025D750
XI_API int __cdecl FontGlyphCache_CreateTexture(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, D3DFORMAT a5, D3DPOOL a6);  // 0x1025D760
XI_API int __cdecl FontGlyphCache_CreateVertexBuffer(unsigned int a1, unsigned int a2, unsigned int a3, D3DPOOL a4);  // 0x1025D7B0
XI_API undefined4 __attribute__((cdecl, regparm(1))) FitFont_ReturnFalse(undefined4 xi_eax);  // 0x1025E020
XI_API undefined4 __cdecl FontGlyphCache_IsStateTwo(void);  // 0x1025E050
XI_API undefined * __cdecl FontGlyphCache_GetCounterBlock(void);  // 0x1025E0B0
XI_API void __cdecl FontGlyphCache_ResetCounter(void);  // 0x1025E0C0
XI_API void __cdecl FontGlyphCache_StepCounter(void);  // 0x1025E0E0
XI_API undefined4 __attribute__((cdecl, regparm(1))) FitFont_ReturnFalseFwd(undefined4 xi_eax);  // 0x1025E0F0
XI_API void __cdecl FontGlyphCache_AddToCounter(int param_1);  // 0x1025E210
XI_API void __cdecl FontGlyphCache_ClearCounter(void);  // 0x1025E230
XI_API void __cdecl FontGlyphCache_DecayCounter(void);  // 0x1025E240
XI_API void * __thiscall FitFont_BaseCtor(void * self_, undefined4 * param_1, undefined4 param_2, undefined4 param_3, undefined4 xi_s4);  // 0x1025E260
XI_API void __thiscall FitFont_BaseDtor(void * self_);  // 0x1025E380
XI_API undefined4 __thiscall FitFont_ReleaseField6C(void * self_);  // 0x1025F2F0
XI_API undefined4 __thiscall FitFont_EndTimerPeriodIfActive(void * self_);  // 0x1025F640
XI_API void * __thiscall FitFont_DerivedCtor(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);  // 0x1025FD50
XI_API void __thiscall FitFont_ResetState(void * self_);  // 0x1025FE40
XI_API undefined4 __thiscall FontGlyphCache_StoreElapsed158(void * self_);  // 0x1025FF10
XI_API undefined4 __cdecl FontGlyphCache_NoOpZero(void);  // 0x10260360
XI_API void * __thiscall FitFont_InnerCtor(void * self_, undefined4 param_1, void * param_2, undefined4 param_3, undefined4 * param_4);  // 0x10261210
XI_API void __thiscall FitFont_InnerDtor(void * self_);  // 0x102612D0
XI_API void * __thiscall FitFont_AddLibraryRef(void * self_, undefined4 xi_s1);  // 0x10265940
XI_API void __cdecl FitFont_ReleaseLibraryRef(void);  // 0x10265960
XI_API void * __thiscall FitFont_RefObjCtor(void * self_, undefined4 param_1, void * param_2);  // 0x102659B0
XI_API void * __thiscall FitFont_CreateEvent(void * self_, BOOL param_1);  // 0x10265B70
XI_API unsigned char __cdecl FontGlyphCache_MarkState3(int param_1);  // 0x1026DB24
XI_API void __cdecl sqxfXformTD_Init(undefined4 * param_1);  // 0x1026DF00
XI_API undefined4 __cdecl sqxfXformTD_Update(int param_1);  // 0x1026E1F0
XI_API void __cdecl sqrdLight_Init(undefined4 * param_1);  // 0x1026E2F0
XI_API void __cdecl SqgxContext_StoreVec14(int param_1);  // 0x1026E3D0
XI_API undefined4 __cdecl StAvatar_InitGlobals1099AEB8(void);  // 0x1026E400
XI_API void __cdecl StAvatar_AllocArrays(int param_1, int param_2);  // 0x1026E460
XI_API undefined4 __cdecl StAvatar_InitModel(undefined4 * param_1);  // 0x1026E530
XI_API void __cdecl StAvatar_UpdateModels(undefined4 param_1);  // 0x1026E590
XI_API void __cdecl mdl_1026E900(void);  // 0x1026E900
XI_API int __cdecl Mdl_Register(int param_1, undefined4 param_2);  // 0x1026EBF0
XI_API undefined4 __cdecl Mdl_FreeAllSlots(void);  // 0x1026ECC0
XI_API void __cdecl Mdl_ClearSlotFlags(void);  // 0x1026EE00
XI_API int __cdecl Mdl_ChannelRegister(int param_1, undefined4 param_2);  // 0x1026EF00
XI_API undefined4 __cdecl Mdl_FindNthItemB0001(int param_1, int param_2);  // 0x1026F160
XI_API undefined4 __cdecl Mdl_ReleaseEntries(void);  // 0x1026F1B0
XI_API undefined4 __cdecl Mdl_GetEntryTable(int * param_1, int * param_2);  // 0x1026F4F0
XI_API void __cdecl Mdl_QueryEntryFlag(int param_1, undefined4 * param_2);  // 0x1026F580
XI_API void __cdecl Mdl_GetEntryWord0(int param_1, undefined4 * param_2);  // 0x1026F7B0
XI_API void __cdecl Mdl_SetChannelActive(int param_1, uint32_t param_2, int param_3);  // 0x1026F900
XI_API void __cdecl Mdl_UpdateEntryFlags(int param_1, uint32_t param_2, int param_3);  // 0x1026F9A0
XI_API void __cdecl Mdl_SetChannelFlag80(int param_1, int param_2);  // 0x1026F9E0
XI_API undefined4 __cdecl ModelMinMax_ComputeMinMax(float * param_1);  // 0x1026FBB0
XI_API void __cdecl Mdl_CountSlotsFlag40(int * param_1);  // 0x1026FE60
XI_API void __cdecl Mdl_FindNthFlag40(int param_1, int * param_2);  // 0x1026FEA0
XI_API void __cdecl Mdl_CountSlotsFlag80(int * param_1);  // 0x1026FEF0
XI_API void __cdecl Mdl_FindNthNegative(int param_1, int * param_2);  // 0x1026FF30
XI_API undefined4 __cdecl Mdl_ComputeSlotBounds(int param_1, float * param_2);  // 0x1026FF80
XI_API undefined4 __cdecl Mdl_LinkB0001ItemRefs(int param_1, int param_2, undefined4 param_3);  // 0x102700C0
XI_API void __cdecl Mdl_SetSlotLock(int param_1, uint32_t param_2, undefined4 * param_3, uint32_t param_4, int param_5);  // 0x102701B0
XI_API void __cdecl Mdl_GetSlotPtrs(int param_1, undefined4 * param_2, int * param_3);  // 0x10270240
XI_API void __cdecl Mdl_GetSlotWord0(int param_1, undefined4 * param_2);  // 0x10270290
XI_API void __cdecl Mdl_UpdateSlotFlags(int param_1, uint32_t param_2, int param_3);  // 0x102703C0
XI_API void __cdecl Mdl_SetSlotVisible(int param_1, int param_2);  // 0x10270410
XI_API void __cdecl Mdl_ReleaseSlotPtr(int param_1);  // 0x10270690
XI_API undefined4 __cdecl StAvatarScene_InitScene(void);  // 0x10270B60
XI_API void __cdecl StAvatar_UpdateTransform(void);  // 0x10270EC0
XI_API undefined4 __cdecl StAvatarScene_UpdateScene(undefined4 param_1);  // 0x10270F30
XI_API void __cdecl StAvatar_ApplyModes(undefined4 param_1);  // 0x10271030
XI_API void __cdecl StAvatarScene_RotatePanZoomRoll(int param_1, int param_2, undefined4 param_3, int param_4);  // 0x102710B0
XI_API void __cdecl StAvatar_ApplyEffectFlags(undefined4 param_1);  // 0x102715F0
XI_API void __cdecl StAvatar_UpdateAngles(int param_1, int param_2, undefined4 param_3, float param_4);  // 0x10271630
XI_API void __cdecl StAvatar_DrawScene(void);  // 0x102717F0
XI_API undefined4 __cdecl scnFini(void);  // 0x10271B40
XI_API void __cdecl StAvatar_UpdateFlagBits(uint32_t param_1, int param_2);  // 0x10271B90
XI_API void __cdecl StAvatar_SetOffsets(int param_1, int param_2, int param_3);  // 0x10271C30
XI_API void __cdecl StAvatar_SetSceneValue1(undefined4 param_1, undefined4 param_2);  // 0x10271C60
XI_API void __cdecl StAvatar_SetSceneValue2(undefined4 param_1, undefined4 param_2);  // 0x10271C80
XI_API void __cdecl StAvatar_StoreParams(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7, undefined4 param_8, undefined4 param_9);  // 0x10271CA0
XI_API void __cdecl StAvatar_StoreEntry(void);  // 0x10271D00
XI_API void __cdecl StAvatar_SelectEntry(int param_1);  // 0x10271D70
XI_API void __cdecl scnGetFlags(undefined4 * param_1);  // 0x10271E90
XI_API void __cdecl StAvatar_InitEntry(int param_1);  // 0x10271F20
XI_API void __cdecl StAvatarScene_NoOpA(void);  // 0x102720A0
XI_API void __cdecl StAvatar_SetEntryPosition(int param_1, float * param_2);  // 0x102725A0
XI_API void __cdecl StAvatar_SetEntryFlag(int param_1, int param_2);  // 0x10272630
XI_API void __cdecl StAvatar_SetFlag3(int param_1);  // 0x102726E0
XI_API void __cdecl StAvatar_SetEntryFlag2(int param_1, int param_2);  // 0x10272750
XI_API void __cdecl StAvatar_SetEntryColor(int param_1, undefined4 * param_2);  // 0x102727F0
XI_API void __cdecl StAvatar_SetEntryTransform(int param_1, int param_2, int param_3);  // 0x10272880
XI_API void __cdecl StAvatar_ToggleFlag168(int param_1);  // 0x102729E0
XI_API void __cdecl StAvatar_SelectIndex(int param_1);  // 0x10272A10
XI_API void __cdecl StAvatarScene_NoOpB(void);  // 0x10272BA0
XI_API void __cdecl scnCameraGetInfo(int param_1, undefined4 * param_2, undefined4 * param_3);  // 0x10273370
XI_API void __cdecl SceneCamera_SelectCamera(int param_1);  // 0x102733B0
XI_API void __cdecl SceneCamera_SetCameraEntry(int param_1, int param_2, int param_3);  // 0x10273490
XI_API void __cdecl SceneCamera_UpdateCameraBlend(int param_1);  // 0x10273560
XI_API void __cdecl SceneCamera_SetVtable1099B138(undefined4 * param_1);  // 0x102736D0
XI_API void __cdecl SceneCamera_ApplySceneToModel(undefined4 param_1, int param_2);  // 0x102736E0
XI_API void __cdecl SceneRecord_SetEntryField18(undefined4 param_1, uint32_t param_2, undefined4 param_3);  // 0x10273840
XI_API void __cdecl SceneRecord_ClearGroupField4(int param_1);  // 0x10273870
XI_API void __cdecl SceneRecord_ClearCurrentField4(void);  // 0x102738A0
XI_API void __cdecl SceneRecord_InitRecord(undefined4 * param_1);  // 0x102738D0
XI_API void __cdecl chasm_10273920(uint8_t * param_1);  // 0x10273920
XI_API undefined4 __cdecl Chasm_ApplyAtCurrentIndex(int param_1, undefined4 * param_2, undefined4 * param_3);  // 0x10273D60
XI_API undefined4 __cdecl Chasm_ToggleLayerState(int param_1, int param_2, int param_3);  // 0x10273E80
XI_API int __cdecl SqVec_Relink(int param_1, int param_2);  // 0x102741F0
XI_API undefined4 __cdecl SqVec_GetInterpolated(int param_1, int param_2, undefined4 * param_3, undefined4 * param_4);  // 0x10274370
XI_API void __cdecl SqVec_ZeroDwords(undefined4 * param_1);  // 0x10274640
XI_API undefined4 __cdecl SqVec_CopyVec3(undefined4 * param_1, undefined4 * param_2);  // 0x10274650
XI_API void __cdecl SqVec_SetXyz(float * param_1, float param_2, float param_3, float param_4);  // 0x10274670
XI_API long double __cdecl SqVec_Length(undefined4 param_1);  // 0x102746C0
XI_API void __cdecl SqVec_CrossProduct(float * param_1, float * param_2, float * param_3);  // 0x10274890
XI_API long double __cdecl SqVec_ScaleVec3ByInverseOf102746C0(float * param_1);  // 0x102748F0
XI_API void __cdecl SqVec_Sub(float * param_1, float * param_2, float * param_3);  // 0x102749C0
XI_API void __cdecl SqVec_LerpFactor(float * param_1, float * param_2, float * param_3, float param_4);  // 0x10274A20
XI_API void __cdecl PackVec4(float * param_1, float param_2, float param_3, float param_4, float param_5);  // 0x10274D40
XI_API int __cdecl SqTimer_GetMicroseconds(void);  // 0x10275090
XI_API void __cdecl sqMemInit(void);  // 0x10275150
XI_API void __cdecl SqMem_InitBlock(undefined4 * param_1);  // 0x10275190
XI_API undefined4 __cdecl SqMem_ClassifyBlock(int param_1);  // 0x102752F0
XI_API int __cdecl SqMem_GetPayloadEnd(int param_1);  // 0x10275320
XI_API undefined8 __cdecl SqMem_Check(void);  // 0x10275510
XI_API void __attribute__((cdecl, regparm(2))) SqMem_HexDump(undefined4 xi_eax, undefined4 xi_edx, int param_1, int param_2);  // 0x102755C0
XI_API undefined4 * __cdecl SqMem_FindArena(uint32_t param_1);  // 0x10275670
XI_API void __cdecl sqMemPoolRegister(int param_1, uint32_t param_2, int param_3, undefined4 xi_s4);  // 0x10275B60
XI_API void __cdecl SqMem_PrintPools(void);  // 0x10275CC0
XI_API undefined4 * __cdecl SqMem_AllocZeroed(int param_1, int param_2, undefined4 param_3, undefined4 param_4);  // 0x10275D40
XI_API undefined4 * __cdecl SqMem_Realloc(undefined4 * param_1, uint32_t param_2, undefined4 param_3, undefined4 param_4);  // 0x10275E90
XI_API undefined4 __cdecl sqFree(int param_1, undefined4 param_2, undefined4 param_3);  // 0x102760F0
XI_API undefined4 __cdecl sqgxContext_Create(void);  // 0x10276260
XI_API void __cdecl sqgxContext_Init(undefined4 * param_1);  // 0x10276290
XI_API void __cdecl Shader_SetFlagBit0(int param_1, uint32_t param_2);  // 0x102778C0
XI_API void __cdecl SqsdAniso_SetNumDrawTris(int param_1, int param_2);  // 0x102778F0
XI_API uint32_t __cdecl SqmdModel_Validate(int param_1);  // 0x10277A50
XI_API void __cdecl SqmdModel_Free(int * param_1);  // 0x10277AB0
XI_API void __cdecl SqmdModel_FreeBuffers(int param_1);  // 0x10277B70
XI_API void __cdecl SqmdModel_Update(int param_1);  // 0x10278490
XI_API void __cdecl SqmdModel_Link(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);  // 0x10278710
XI_API void __cdecl SqmdModel_LinkShape(int param_1, int param_2, int param_3, undefined4 param_4, undefined4 param_5);  // 0x102787F0
XI_API void __cdecl SqmdModel_AddIllumLight(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);  // 0x10278990
XI_API void __cdecl SqmdModel_AddShadowLightInLayer(int param_1, undefined4 param_2, int param_3, undefined4 param_4, undefined4 param_5);  // 0x10278B50
XI_API void __cdecl SqmdModel_Show(int param_1, undefined4 param_2);  // 0x10278BF0
XI_API void __cdecl SqmdModel_SetLayerSort(int param_1, int param_2);  // 0x10278E10
XI_API void __cdecl SqmdModel_LookAt(int param_1, int param_2, int param_3, float * param_4, float param_5);  // 0x10278E90
XI_API void __cdecl SqmdModel_AppendPair44(int param_1, undefined4 param_2);  // 0x10279530
XI_API void __cdecl SqmdModel_AppendPair68(int param_1, undefined4 param_2);  // 0x102796A0
XI_API undefined4 __cdecl SqmdModel_GetItem(int param_1, undefined4 param_2, int param_3);  // 0x10279710
XI_API undefined4 __cdecl SqmdModel_GetItemKind0(int param_1, int param_2);  // 0x10279830
XI_API undefined4 __cdecl SqmdModel_GetItemKind1(undefined4 param_1, undefined4 param_2);  // 0x10279850
XI_API undefined4 __cdecl SqmdModel_GetItemKind2(undefined4 param_1, undefined4 param_2);  // 0x10279870
XI_API undefined4 __cdecl SqmdModel_GetItemKind3(undefined4 param_1, undefined4 param_2);  // 0x10279890
XI_API undefined4 __cdecl SqmdModel_GetItemKind4(int param_1, int param_2);  // 0x102798B0
XI_API char * __cdecl sqmdModel_GetItemName(int param_1, int param_2, int param_3);  // 0x10279AB0
XI_API undefined4 __cdecl SqmdModel_GetItemNameKind3(int param_1, int param_2);  // 0x10279B40
XI_API char * __cdecl SqmdModel_FindItemName(int param_1, int param_2, int param_3);  // 0x10279BA0
XI_API undefined4 __cdecl SqmdModel_FindItemByName(int param_1, int param_2, int param_3, undefined4 * param_4);  // 0x10279BF0
XI_API undefined4 __cdecl SqmdModel_LookupKind2(undefined4 param_1, undefined4 param_2, int * param_3);  // 0x10279D50
XI_API char * __cdecl SqmdModel_ItemKindName(undefined4 param_1);  // 0x1027A1C0
XI_API undefined4 __cdecl SqmdModel_AppendPair68Flag100(int param_1, undefined4 param_2);  // 0x1027A220
XI_API void __cdecl SqmdModel_FreeItems(int * param_1);  // 0x1027A250
XI_API void __cdecl SqQuat_SetIdentityFwd(undefined4 * param_1);  // 0x1027A6F0
XI_API undefined4 __cdecl SqQuat_Copy(undefined4 * param_1, undefined4 * param_2);  // 0x1027A700
XI_API void __cdecl SqQuat_Set(float * param_1, float param_2, float param_3, float param_4, float param_5);  // 0x1027A720
XI_API void __cdecl SqQuat_ToMatrix3(float * param_1, float * param_2);  // 0x1027A9D0
XI_API undefined4 __cdecl SqQuat_QuatFromEuler(float * param_1, float param_2, float param_3, float param_4);  // 0x1027AAE0
XI_API void __cdecl SqQuat_FromRotationX(float * param_1, float param_2);  // 0x1027ABA0
XI_API void __cdecl SqQuat_FromRotationY(undefined4 * param_1, float param_2);  // 0x1027ABD0
XI_API void __cdecl SqQuat_FromRotationZ(undefined4 * param_1, float param_2);  // 0x1027AC00
XI_API void __cdecl SqQuat_FromAxisAngle(float * param_1, float * param_2, float param_3);  // 0x1027AC30
XI_API void __cdecl SqQuat_SetIdentity(undefined4 * param_1);  // 0x1027AE50
XI_API void __cdecl SqQuat_Negate(float * param_1);  // 0x1027AEF0
XI_API undefined4 __cdecl SqQuat_NormalizeVec4(float * param_1);  // 0x1027AF20
XI_API undefined4 __cdecl SqQuat_Invert(float * param_1);  // 0x1027AFB0
XI_API void __cdecl SqQuatMul_NegateInPlace(float * param_1);  // 0x1027B060
XI_API void __cdecl SqQuatMul_RotateVec(float * param_1, float * param_2, float * param_3);  // 0x1027B080
XI_API void __cdecl SqQuatMul_Mul(float * param_1, float * param_2, float * param_3);  // 0x1027B170
XI_API void __cdecl Sq_PrintFloat4Indented(float * xi_s1, undefined4 xi_s2, undefined4 xi_s3);  // 0x1027B480
XI_API undefined4 * __cdecl SqskSkeleton_Create(void);  // 0x1027B580
XI_API void __cdecl SqskSkeleton_Init(undefined4 * param_1);  // 0x1027B5A0
XI_API void __cdecl SqskSkeleton_SetNodeCount(int param_1, int param_2);  // 0x1027C4C0
XI_API int __cdecl SqskSkeleton_FindBoneIndex(int param_1, int param_2);  // 0x1027C900
XI_API int __cdecl SqskSkeleton_GetNode(int param_1, int param_2);  // 0x1027C980
XI_API void __cdecl SqskSkeleton_Release(int param_1);  // 0x1027C9D0
XI_API void __cdecl SqBoneTransform_TransformOrigin(undefined4 param_1, undefined4 param_2, undefined4 param_3);  // 0x1027CCF0
XI_API void __cdecl SqBoneTransform_ComputeTransform(int param_1, int param_2, float * param_3, float * param_4);  // 0x1027CD30
XI_API void __cdecl SqBoneTransform_TransformPoint(int param_1, int param_2, float * param_3, float * param_4);  // 0x1027CFD0
XI_API void __cdecl SqmoUtil_MarkSlot(int param_1, int param_2, int param_3, undefined1 * param_4);  // 0x1027D650
XI_API void __cdecl SqChannelDefaults_InitDefaults(undefined4 * param_1);  // 0x1027DAE0
XI_API void __cdecl Chn_ReleaseRefs(uint32_t * param_1);  // 0x1027DB80
XI_API uint32_t * __cdecl Chn_RegisterItem(uint32_t * param_1, uint32_t param_2);  // 0x1027DCC0
XI_API void __cdecl Chn_ForwardIfFlag2(uint8_t * param_1, undefined4 xi_s2);  // 0x1027DD70
XI_API int __cdecl Chn_GetSubIndex(int param_1);  // 0x1027DF70
XI_API void __cdecl Chn_InitDefaults(undefined4 * param_1);  // 0x1027E060
XI_API void __cdecl Chn_ReleaseIfSet(int param_1);  // 0x1027E0D0
XI_API void __cdecl SqMatrixConnect_UpdateMask(uint32_t * param_1, uint32_t param_2, int param_3);  // 0x1027E150
XI_API void __cdecl SqMatrixConnect_SetCallback(int param_1, undefined4 param_2, undefined4 param_3);  // 0x1027E190
XI_API undefined4 __cdecl SqMatrixConnect_ReleaseConnection(uint8_t * param_1);  // 0x1027E3B0
XI_API undefined4 __cdecl SqMatrixConnect_IsConnected(uint8_t * param_1);  // 0x1027E440
XI_API undefined4 __cdecl SqMatrixConnect_UpdateRange(uint8_t * param_1);  // 0x1027E450
XI_API void __cdecl SqMatrixConnect_Advance(uint8_t * param_1, int param_2);  // 0x1027E490
XI_API void __cdecl SqMatrixConnect_Forward1027EBD0(undefined4 * param_1);  // 0x1027EAF0
XI_API void __cdecl SqMatrixConnect_Zero(undefined4 * param_1);  // 0x1027EB00
XI_API void __cdecl SqMatrixConnect_Set(float * param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7, float param_8, float param_9, float param_10, float param_11, float param_12, float param_13, float param_14, float param_15, float param_16, float param_17);  // 0x1027EB50
XI_API undefined4 __cdecl SqMatrixConnect_SetIdentity(undefined4 * param_1);  // 0x1027EBD0
XI_API void __cdecl M4fTransform(float * param_1, float * param_2, float * param_3);  // 0x1027EF20
XI_API void __cdecl SqMatrixConnect_TransformVec3(float * param_1, float * param_2, float * param_3);  // 0x1027EF80
XI_API void __cdecl Mat4x4_TransformVec4(float * param_1, float * param_2, float * param_3);  // 0x1027EFE0
XI_API void __cdecl M4fTranspose(undefined4 * param_1, undefined4 * param_2);  // 0x1027F070
XI_API long double __cdecl sqMatrix4_1027FCC0(float * param_1);  // 0x1027FCC0
XI_API undefined4 __cdecl sqMatrix4_10280140(float * param_1, float * param_2, float * param_3);  // 0x10280140
XI_API void __cdecl SqMatrix4_SetFields(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);  // 0x10280650
XI_API undefined4 __cdecl SqMatrix4_ScaleAxes(int param_1, float param_2, float param_3, float param_4);  // 0x102806B0
XI_API void __cdecl Sq_PrintFloat4x4Indented(float * param_1, undefined4 param_2, int param_3);  // 0x10280D10
XI_API void __cdecl SqgxTextureImage_CompositeBlendPasses(int param_1, float param_2);  // 0x102813B0
XI_API int __cdecl sqgxTextureCreateFromImage(int a1, _BYTE *a2);  // 0x10281510
XI_API int __cdecl sqgxTextureAddZ(int a1, int a2, int a3);  // 0x102816E0
XI_API int __cdecl sqgxCeilLog2(int param_1);  // 0x10281810
XI_API int __cdecl sqgxTextureAdd(int a1, int a2, IDirect3DTexture8 *a3, _BYTE *a4);  // 0x10281830
XI_API void __cdecl SqgxTexture_ClearPaletteUsed(int param_1);  // 0x102819C0
XI_API int __cdecl sqgxTextureClutAdd(int a1, int a2, int a3);  // 0x102819D0
XI_API void __cdecl SqgxTexture_FreeSlot(int param_1);  // 0x10281A70
XI_API void __cdecl sqgxTextureGetSize(int param_1, undefined4 * param_2, undefined4 * param_3);  // 0x10281B60
XI_API undefined4 __cdecl sqgxTextureSet(int param_1);  // 0x10281C20
XI_API undefined4 __cdecl sqgxTextureDecal(undefined4 param_1);  // 0x10281C50
XI_API void __cdecl sqgxTextureClamp(undefined4 param_1);  // 0x10281C80
XI_API int __cdecl sqgxTextureClut(int a1);  // 0x10281D60
XI_API int __cdecl sqgxTextureUpdate(void);  // 0x10281DB0
XI_API int __cdecl sqgxTextureStencilClear(int a1);  // 0x10282010
XI_API int __cdecl sqgxTextureClear(float *a1, int a2);  // 0x10282030
XI_API int * __cdecl sqgxTextureDrawZ(IDirect3DSurface8 *a1);  // 0x102820E0
XI_API int * __cdecl sqgxTextureDraw(int a1, char a2);  // 0x10282190
XI_API int * __cdecl sqgxZTest(int a1);  // 0x10282350
XI_API void __cdecl sqgxAlphaDstTest(int param_1, int param_2);  // 0x102823B0
XI_API int __cdecl sqgxAlphaTest(unsigned int a1, unsigned int a2);  // 0x102823F0
XI_API int * __cdecl sqgxZMask(int a1);  // 0x10282470
XI_API int * __cdecl sqgxFBMask(int a1, int a2, int a3, int a4);  // 0x102824C0
XI_API void __cdecl SqgxContext_ResetHandles(void);  // 0x10282590
XI_API void __cdecl SqgxContext_Nop(void);  // 0x10282630
XI_API int __cdecl SqgxContext_SetSelectArg1(void);  // 0x10282640
XI_API int __cdecl sqgxBlendAdd(void);  // 0x102826C0
XI_API int __cdecl SqgxContext_SetMultiplyAdd(void);  // 0x102827D0
XI_API int __cdecl sqgxBlendSub(void);  // 0x10282910
XI_API void __cdecl sqgxBlendLin(float a1);  // 0x10282A30
XI_API int __cdecl sqgxBlendTrsp(void);  // 0x10282B90
XI_API int __cdecl sqgxBlendTrspInv(void);  // 0x10282CB0
XI_API int __cdecl sqgxBlendAddDestAlpha(void);  // 0x10282DC0
XI_API int __cdecl SqgxContext_SetModulateAlphaAdd(void);  // 0x10282ED0
XI_API int __cdecl sqgxBlendMultAlpha(void);  // 0x10282FF0
XI_API int __cdecl sqgxBlendMul(void);  // 0x10283110
XI_API int __cdecl sqgxBlendOff(void);  // 0x10283220
XI_API void __cdecl SqgxContext_NoOpA(void);  // 0x10283240
XI_API void __cdecl ___setargv_9(void);  // 0x10283250
XI_API void __cdecl SqgxContext_SetCurrentIndex(undefined4 param_1, undefined4 param_2);  // 0x10283260
XI_API void __cdecl SqgxContext_StoreEntryVec(undefined4 * param_1);  // 0x10283280
XI_API undefined4 __cdecl SqgxContext_SetContextSlot854(undefined4 param_1);  // 0x10283300
XI_API void __cdecl sqgxColor(undefined4 * param_1);  // 0x10283330
XI_API void __cdecl sqgxAmbient(float param_1);  // 0x10283380
XI_API void __cdecl SqgxContext_SetFloat76C(float param_1);  // 0x102833A0
XI_API void __cdecl SqgxContext_SetDword774AndFactor(undefined4 param_1, float param_2, undefined4 param_3);  // 0x102833C0
XI_API int __cdecl sqgxColorUpdate(void);  // 0x10283420
XI_API void __cdecl ___setargv_16(void);  // 0x10283870
XI_API void __cdecl sqgxPixelSize(float param_1, float param_2);  // 0x102838A0
XI_API void __cdecl SqgxContext_SetViewportVec4(undefined4 * param_1);  // 0x10283970
XI_API int * __cdecl sqgxViewport(float a1, float a2, float a3, float a4);  // 0x10283A10
XI_API undefined4 __cdecl SqgxContext_SetPerspective(float param_1, float param_2, float param_3);  // 0x10283C10
XI_API void __cdecl sqgxMatrixCamera(undefined4 * param_1);  // 0x10283D60
XI_API void __cdecl SqgxContext_SetTransposedMatrix(undefined4 * param_1);  // 0x10283DA0
XI_API void __cdecl SqgxContext_SetFloat72C(float param_1);  // 0x10283DE0
XI_API void __cdecl sqgxMatrixShape(undefined4 * param_1);  // 0x10283E00
XI_API void __cdecl SqgxContext_SetInverseFactor(float param_1);  // 0x10283F20
XI_API int __cdecl sqgxPassAdd(int a1);  // 0x10283F70
XI_API int * __cdecl sqgxPass(int a1);  // 0x10283FC0
XI_API undefined4 __cdecl SqgxContext_TestClipBounds(float * param_1, float param_2);  // 0x10284000
XI_API int __cdecl sqgxMatrixUpdate(void);  // 0x10284410
XI_API void __cdecl ___setargv_24(void);  // 0x10284890
XI_API int __cdecl sqgxVertexShaderCreate(_DWORD *a1);  // 0x10284950
XI_API int __cdecl sqgxVertexShaderSelect(void);  // 0x10284A80
XI_API int * __cdecl sqgxShader(int a1, int a2);  // 0x10284B20
XI_API void __cdecl SqgxVertexShaderRelease_NoOp(void);  // 0x10284EB0
XI_API int __cdecl sqgxVertexShaderRelease(void);  // 0x10284EF0
XI_API long double __cdecl SqgxVertexShaderRelease_GetFloat20(int param_1);  // 0x10284F20
XI_API undefined4 __cdecl SqmoChannel_Evaluate(int param_1, undefined4 param_2);  // 0x10284F50
XI_API void __cdecl SqItemValue_SetValueByType(int * param_1, int param_2);  // 0x10284FD0
XI_API undefined4 __cdecl SqItemValue_GetValueByItemKind(int * param_1, int * param_2);  // 0x10285000
XI_API int __cdecl SqmoBuild_ReadFrameChannel(undefined4 * param_1, int param_2);  // 0x102851C0
XI_API int __cdecl SqmoBuild_ReadKeyChannel(undefined4 * param_1, int param_2);  // 0x102852E0
XI_API int __cdecl PlaybackChannel_Load(undefined4 * param_1, undefined4 * param_2);  // 0x102853F0
XI_API void __cdecl SqObject_Release(int * param_1);  // 0x10285740
XI_API undefined4 __cdecl SqDebug_GetFlagByte14(int param_1);  // 0x102857D0
XI_API undefined4 __attribute__((cdecl, regparm(1))) SqDebug_SetByte14(undefined4 xi_eax, int param_1, undefined4 param_2);  // 0x102857E0
XI_API undefined4 __cdecl SqDebug_InvokeCallback18(int param_1);  // 0x102857F0
XI_API void __cdecl sqDrawableDraw(int param_1);  // 0x10285850
XI_API int __cdecl SqmdDMB_Resolve(char * param_1, undefined4 param_2);  // 0x10287FB0
XI_API int __cdecl SqmdDMB_TraceDelta(int param_1);  // 0x10288660
XI_API uint32_t __cdecl SqmdDMB_AlignMem(uint32_t param_1);  // 0x10288680
XI_API uint32_t __cdecl SqmdDMB_ResolveTextures(int param_1, uint32_t param_2);  // 0x102886D0
XI_API int * __cdecl SqmdDMB_ResolveShaders(int param_1, uint32_t param_2);  // 0x10288950
XI_API undefined4 __cdecl SqmdDMB_TextureLink(int param_1, uint32_t param_2);  // 0x10288B70
XI_API undefined4 __cdecl SqmdDMB_ResolveMatrices(int param_1, uint32_t param_2);  // 0x10288BB0
XI_API char * __cdecl SqmdDMB_ResolveStrings(int param_1, uint32_t param_2);  // 0x10288C20
XI_API void __cdecl SqmdDMB_ClearTables(int param_1);  // 0x10288DC0
XI_API void __cdecl SqmdDMB_ResetCounts(int param_1);  // 0x10288E00
XI_API uint8_t * __cdecl sqmdDMBBuildShapes(int param_1, uint32_t param_2);  // 0x10288E60
XI_API uint8_t * __cdecl SqmdDMB_BuildUpdaters(int param_1, uint8_t * param_2);  // 0x10288FF0
XI_API void __cdecl SqmdDMBUpdaters_ResolveSkelRefs(int param_1, int param_2, uint32_t param_3);  // 0x102894E0
XI_API void __cdecl SqopSystem_Init(undefined4 * param_1);  // 0x10289620
XI_API void __cdecl SqopSystem_ClearOpcodes(undefined4 * param_1);  // 0x102896A0
XI_API void __cdecl SqopTrack_Reset(undefined4 * param_1);  // 0x10289B40
XI_API void __cdecl SqopTrack_Free(int param_1);  // 0x10289BA0
XI_API int __cdecl sqopOpcodeGet(int * param_1, undefined4 * param_2);  // 0x10289EA0
XI_API int __cdecl sqopTrackSetIndex(int * param_1, int param_2);  // 0x10289EF0
XI_API undefined4 __cdecl sqopTrackAdvance(int * param_1);  // 0x10289F10
XI_API void __cdecl SqxfXformM_Init(undefined4 * param_1);  // 0x10289F50
XI_API void __attribute__((cdecl, regparm(1))) Sq_PrintIndent(undefined4 xi_eax, int param_1);  // 0x1028A0B0
XI_API undefined4 __cdecl SqScriptRead_ReturnZero(void);  // 0x1028A0E0
XI_API undefined4 * __cdecl SqScriptRead_ReadBlock(undefined4 * param_1, int param_2, int param_3, undefined4 * param_4, int param_5);  // 0x1028A0F0
XI_API int __cdecl sqScript_TokenEquals(char * param_1, char * param_2);  // 0x1028A150
XI_API int * __cdecl sqgxShapeIndexBufferBegin(void);  // 0x1028AA70
XI_API int __cdecl SqgxShape_FillBuffers(void);  // 0x1028AB50
XI_API int * __cdecl sqgxShapeBegin(void);  // 0x1028AFE0
XI_API undefined4 * __cdecl SqcoConnector_Create(void);  // 0x1028D6D0
XI_API void __cdecl SqcoConnector_Init(undefined4 * param_1);  // 0x1028D6F0
XI_API undefined4 __cdecl SqConnector_CreateFromFields(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5);  // 0x1028D870
XI_API long double __cdecl SqBounds_SumAxis(int param_1);  // 0x1028D990
XI_API void __cdecl SqBounds_Reset(undefined4 * param_1);  // 0x1028D9A0
XI_API void __cdecl SqBounds_Copy(undefined4 * param_1, undefined4 * param_2);  // 0x1028D9C0
XI_API undefined4 __attribute__((cdecl, regparm(1))) SqBounds_ComputeBounds(float * xi_eax, float * param_1, float * param_2, int param_3);  // 0x1028DA20
XI_API void __cdecl SqBounds_GetCenter(float * param_1, float * param_2);  // 0x1028DBB0
XI_API undefined4 * __cdecl SqmdSnap_Create(void);  // 0x1028DC00
XI_API void __cdecl SqmdSnap_Init(undefined4 * param_1);  // 0x1028DC20
XI_API undefined4 __cdecl SqSnapRef_CreateRef(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);  // 0x1028DE10
XI_API void __cdecl SqsnScene_Free(int param_1);  // 0x1028E1B0
XI_API void __cdecl SqsnScene_Init(undefined4 * param_1);  // 0x1028E350
XI_API void __cdecl SqsnScene_SetItemFloat14(int param_1, int param_2, float param_3);  // 0x1028EBF0
XI_API undefined4 __cdecl SqsnScene_SetEntryField8(int param_1, int param_2, undefined4 param_3);  // 0x1028EC30
XI_API void __cdecl SqsnScene_SetItemByte19(int param_1, int param_2, undefined4 param_3);  // 0x1028EC50
XI_API void __cdecl SqsnScene_SetByteAt28(int param_1, int param_2, undefined4 param_3);  // 0x1028ECC0
XI_API void __cdecl SqsnScene_SetItemByte18(int param_1, int param_2, undefined4 param_3);  // 0x1028ECE0
XI_API int __cdecl SqsnScene_AddCamera(int param_1, undefined4 param_2, undefined4 param_3);  // 0x1028ED00
XI_API int __cdecl SqsnScene_AddLight(int param_1, undefined4 param_2, undefined4 param_3);  // 0x1028ED50
XI_API int __cdecl SqsnScene_LayerAddItem(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, int param_5);  // 0x1028EDE0
XI_API void __cdecl SqsnScene_LayerInit(undefined4 * param_1);  // 0x1028EFB0
XI_API int __cdecl SqsnScene_AddShadow(int param_1, undefined4 param_2);  // 0x1028F130
XI_API void __cdecl SqsnScene_SetItemDword28(int param_1, int param_2, undefined4 param_3);  // 0x1028F220
XI_API void __cdecl SqsnScene_ItemAddLight(int param_1, uint32_t param_2, undefined4 param_3);  // 0x1028F2E0
XI_API void __cdecl SqsnScene_ItemAddShadowLight(int param_1, uint32_t param_2, undefined4 param_3);  // 0x1028F350
XI_API void __cdecl SqsnScene_ShadowAddMember(int param_1, int param_2, undefined4 param_3);  // 0x1028F3C0
XI_API int __cdecl SqsnScene_GetEntryAddr(int param_1, uint32_t param_2);  // 0x1028F430
XI_API void __cdecl SqsnScene_SetCursorIfInRange(int param_1, int param_2);  // 0x1028F4A0
XI_API void __cdecl SqsnScene_DrawMatrixShape(undefined4 param_1, int * param_2);  // 0x1028F4C0
XI_API void __cdecl sqsnScene_1028F5F0(int param_1, int param_2, int param_3);  // 0x1028F5F0
XI_API void __cdecl SqsnScene_SetupLayerLights(int * param_1, int param_2);  // 0x1028F6E0
XI_API void __cdecl sqsnSceneDraw(int a1);  // 0x1028F8C0
XI_API void __cdecl sqsnSceneLayerDraw(int * param_1, int param_2);  // 0x1028FDD0
XI_API void __cdecl SqsnScene_DrawFadeSprite(int param_1);  // 0x1028FF80
XI_API void __cdecl sqsnSceneLayerDrawShadowed(int * param_1, int param_2);  // 0x1028FFF0
XI_API void __cdecl sqsnSceneLayerSnapShotComposite(int param_1, int param_2);  // 0x102902C0
XI_API void __cdecl SqsnScene_NoOp(void);  // 0x10290430
XI_API void __cdecl sqsnSceneLayerSort(int param_1, int param_2);  // 0x10290440
XI_API void __cdecl SqsnScene_Preallocate(int param_1, int param_2, int param_3, int param_4, int param_5);  // 0x10290610
XI_API void __cdecl SqsnScene_LayerPreallocate(int param_1, int param_2, int param_3);  // 0x102907C0
XI_API void __cdecl SqsnScene_ShadowPreallocate(int param_1, int param_2, int param_3);  // 0x10290840
XI_API void __cdecl SqsdGeneric_Init(undefined4 * param_1);  // 0x10290910
XI_API void __cdecl SqsdGeneric_DrawPasses(int param_1, int * param_2);  // 0x10290B60
XI_API int * __cdecl sqsdGeneric_BakeOntoShape(int param_1, int * param_2);  // 0x10290FC0
XI_API void __cdecl SqrdCamera_Init(undefined4 * param_1);  // 0x10291110
XI_API void __cdecl sqrdCamera_Apply(int param_1);  // 0x102911E0
XI_API void __cdecl SqIOHooks_CallHook2C(int param_1);  // 0x10291290
XI_API void __cdecl SqIOHooks_CallHook3C(int param_1);  // 0x102912D0
XI_API void __cdecl SqIOHooks_CallHook40(int param_1);  // 0x102912F0
XI_API undefined4 * __cdecl SqskJoint_Create(void);  // 0x10291360
XI_API void __cdecl SqskJoint_Init(undefined4 * param_1);  // 0x10291390
XI_API void __cdecl SqskJoint_Nop(void);  // 0x10291460
XI_API void __cdecl SqSkelNode_CopyVec3At5C(int param_1, undefined4 * param_2);  // 0x102915B0
XI_API void __cdecl SqSkelNode_CopyQuatAt68(int param_1, undefined4 * param_2);  // 0x102915E0
XI_API void __cdecl SqSkelNode_CopyVec3At78(int param_1, undefined4 * param_2);  // 0x102915F0
XI_API void __cdecl SqSkelNode_SetTripleAt84(int param_1, int * param_2);  // 0x102916D0
XI_API void __cdecl SqSkelNode_SetFloatAt94(int param_1, float param_2);  // 0x10291780
XI_API void __cdecl SqSkelNode_SetFloatAt98(int param_1, float param_2);  // 0x10291790
XI_API undefined4 * __cdecl SqhiNode_Create(void);  // 0x10291B70
XI_API void __cdecl SqhiNode_Init(undefined4 * param_1);  // 0x10291BA0
XI_API void __cdecl SqhiNode_Nop(void);  // 0x10291C50
XI_API void __cdecl SqhiNode_SetField64(int param_1, undefined4 param_2);  // 0x10291F00
XI_API void __cdecl SqhiNode_AppendChild(int param_1, int param_2);  // 0x10291F10
XI_API undefined4 __attribute__((cdecl, regparm(1))) SqIO_SwapBytes(undefined4 xi_eax, undefined1 * param_1, uint32_t param_2, int param_3);  // 0x10292130
XI_API void __cdecl SqNibbleSwap_SwapNibblesXor(int param_1, uint32_t param_2);  // 0x10292490
XI_API undefined4 * __cdecl SqmoPlaybackChannel_Create(void);  // 0x102924F0
XI_API void __cdecl SqmoPlaybackChannel_Init(undefined4 * param_1);  // 0x10292520
XI_API void __cdecl SqmoPlaybackChannel_Update(int param_1, int param_2);  // 0x10293000
XI_API void __cdecl SqChannelHandler_SetHandlerByType(int param_1, undefined4 param_2);  // 0x10293F00
XI_API undefined4 * __cdecl SqmoFrameChannel_Create(void);  // 0x10293F80
XI_API void __cdecl SqmoFrameChannel_Init(undefined4 * param_1);  // 0x10293FA0
XI_API void __cdecl SqmoFrameChannel_Apply(int param_1, int param_2);  // 0x102944E0
XI_API undefined4 * __cdecl SqmoKeyChannel_Create(void);  // 0x102957B0
XI_API void __cdecl SqmoKeyChannel_Init(undefined4 * param_1);  // 0x102957D0
XI_API undefined4 * __cdecl SqmoChannelMotion_Create(void);  // 0x10295E70
XI_API void __cdecl SqmoChannelMotion_Init(undefined4 * param_1);  // 0x10295E90
XI_API undefined4 __cdecl SqChannelMotion_CreateWithOwner(int param_1, undefined4 param_2);  // 0x102960A0
XI_API void __cdecl SqMatrixSet_Set(float * param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7, float param_8, float param_9, float param_10);  // 0x10296410
XI_API long double __cdecl SqMatrix3_Determinant(float * param_1);  // 0x102967E0
XI_API void __cdecl SqgxContext_SetCotHalfAngle(float param_1);  // 0x102972D0
XI_API int __cdecl sqsnShadowVolumeSetPass(int a1);  // 0x10297CC0
XI_API int __cdecl sqgxShadowStencilEnable(int a1);  // 0x10297EC0
XI_API int __cdecl sqsnShadowVolumeBeginVB(void);  // 0x102981E0
XI_API void __cdecl sqgxShadowPlaneMatrix(float * param_1);  // 0x10298350
XI_API undefined4 * __cdecl SqimImage_Create(void);  // 0x102984B0
XI_API void __cdecl SqimImage_Init(undefined4 * param_1);  // 0x10298570
XI_API undefined4 * __cdecl SqrdTexture_Create(void);  // 0x10298B30
XI_API void __cdecl SqrdTexture_Init(undefined4 * param_1);  // 0x10298B90
XI_API void __cdecl Texture_BindFromObject(int param_1);  // 0x10298C50
XI_API int __cdecl Texture_CreateEntry(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5);  // 0x10298E10
XI_API void __cdecl SqsdSampling_DrawPasses(int param_1, int * param_2);  // 0x10299090
XI_API int __cdecl sqsdSampling_BakeOntoShape(int param_1, int param_2);  // 0x10299250
XI_API void __cdecl SqsdAniso_DrawPasses(int * param_1, int * param_2);  // 0x102993B0
XI_API int * __cdecl sqsdAniso_BakeOntoShape(int param_1, int * param_2);  // 0x10299610
XI_API void __cdecl SqsdCartoon_Draw(int param_1, int * param_2);  // 0x102997A0
XI_API undefined4 __cdecl sqsdCartoon_BakeOntoShape_Stub(void);  // 0x10299840
XI_API undefined4 __cdecl SqsdGlow_ApplyShader(int param_1, int param_2);  // 0x102999A0
XI_API int * __cdecl sqsdGlow_BakeOntoShape(int param_1, int * param_2);  // 0x10299AB0
XI_API undefined4 __cdecl SqshBuild_BuildSQO(char * param_1, undefined4 param_2);  // 0x10299B30
XI_API int __cdecl SqshBuild_BuildTriStrip(undefined4 * param_1, int param_2);  // 0x10299C30
XI_API int __cdecl SqshBuild_Read(undefined4 * param_1, undefined4 * param_2, int param_3);  // 0x10299D60
XI_API int __cdecl SqshBuild_BuildPoints(undefined4 * param_1, int param_2);  // 0x10299E40
XI_API int __cdecl SqshBuild_BuildCurves(undefined4 * param_1, int param_2);  // 0x10299EE0
XI_API undefined4 * __cdecl SqinSkin_Create(void);  // 0x10299FE0
XI_API void __cdecl SqinSkin_Init(undefined4 * param_1);  // 0x1029A000
XI_API void __cdecl SqinSkin_InitShapeData(int param_1, int param_2, undefined4 * param_3, undefined4 * param_4, undefined4 param_5, uint32_t param_6);  // 0x1029A160
XI_API void __cdecl SqinSkin_PropagateValue38(int param_1, undefined4 param_2);  // 0x1029A230
XI_API undefined4 __cdecl SqinSkin_ResizeItemArray(int param_1, int param_2);  // 0x1029A330
XI_API int __cdecl SqinSkinAppend_Append(int param_1, int param_2);  // 0x1029A380
XI_API int __cdecl sqskSkeleton_GetNodeByIndex(int param_1, int param_2);  // 0x1029A420
XI_API void __cdecl SqinSkin_BuildPartShapes(int param_1);  // 0x1029A450
XI_API void __cdecl SqinSkin_ReleaseIfHasData(int param_1);  // 0x1029A6F0
XI_API int __cdecl SqinBuild_BuildSQO(undefined4 param_1, char * param_2, undefined4 param_3);  // 0x1029AA80
XI_API void __cdecl sqinSkinBuildBinary(undefined4 param_1, int param_2, int param_3, int param_4);  // 0x1029ABD0
XI_API undefined4 __cdecl SqskSkeleton_BuildSQO(char * param_1, undefined4 param_2);  // 0x1029ADF0
XI_API int __cdecl SqskSkeleton_BuildBinary(int param_1, int param_2, int param_3);  // 0x1029AF20
XI_API undefined4 * __cdecl SqmdSort_Create(void);  // 0x1029B100
XI_API void __cdecl SqmdSort_Init(undefined4 * param_1);  // 0x1029B120
XI_API void __cdecl SqmdSort_AllocLists(int * param_1, int * param_2, int param_3);  // 0x1029B310
XI_API int __cdecl SqmdSort_CreateForStrips(int * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);  // 0x1029B3A0
XI_API void __cdecl SqgxDlist_CreateContextList(void);  // 0x1029B5C0
XI_API _DWORD * __cdecl sqgxDlistEnd(void);  // 0x1029B620
XI_API void __cdecl sqgxDlistDraw(IDirect3DVertexBuffer8 **a1);  // 0x1029B9D0
XI_API void __cdecl SqgxDlist_Nop(void);  // 0x1029BB50
XI_API void __cdecl Sqgx_CopyBlockToContext(int param_1);  // 0x1029BCD0
XI_API void __cdecl Sqgx_SetFloat18(float param_1);  // 0x1029BD40
XI_API void __cdecl Sqgx_ResetPendingList(void);  // 0x1029C180
XI_API void __cdecl Sqgx_AddPendingEntry(undefined4 param_1, undefined4 * param_2, float param_3);  // 0x1029C1B0
XI_API void __cdecl Sqgx_SetContextFieldE24(undefined4 param_1);  // 0x1029C460
XI_API undefined4 __cdecl SqsdPassTest_TestSeparationHalf(int param_1);  // 0x102A1FA0
XI_API undefined4 * __cdecl SqshDispList_Create(void);  // 0x102A2000
XI_API void __cdecl SqshDispList_Init(undefined4 * param_1);  // 0x102A2020
XI_API void __cdecl SqShadowVolumeDraw_CopyBounds(int param_1, int param_2);  // 0x102A2130
XI_API undefined4 __cdecl SqShadowVolumeDraw_ContainsInt(int param_1, int param_2);  // 0x102A2160
XI_API undefined4 __cdecl SqShadowVolumeDraw_ContainsInAnyEntry(int param_1, undefined4 param_2);  // 0x102A2190
XI_API void __cdecl sqsnShadowVolumeDraw(int a1, int a2, int a3);  // 0x102A21F0
XI_API void __cdecl sqsnPlanarShadowDraw(int a1, int a2);  // 0x102A2530
XI_API void __cdecl SqPlanarShadow_RenderShadowTexture(int param_1, int param_2);  // 0x102A2720
XI_API void __cdecl Sqgx_SetTextureAt(int param_1, int param_2);  // 0x102A2A30
XI_API void __cdecl Sqgx_CheckShadowGroupMember(undefined4 param_1, int param_2, int param_3);  // 0x102A2A50
XI_API void __cdecl SqPlanarShadow_DrawShadowedShape(int param_1, int * param_2, int param_3, int param_4);  // 0x102A2C00
XI_API void __cdecl SqrdMaterial_Init(undefined4 * param_1);  // 0x102A3390
XI_API void __cdecl SqgxLighting_ApplyLighting(int param_1);  // 0x102A34D0
XI_API void __cdecl Sqgx_SetParam9cc(float param_1);  // 0x102A3540
XI_API void __cdecl Sqgx_ResetCounter(void);  // 0x102A3760
XI_API void __cdecl Sqgx_IncCounter(void);  // 0x102A3770
XI_API undefined4 * __cdecl SqVtx_Create(void);  // 0x102A9520
XI_API void __cdecl SqVtx_Init(undefined4 * param_1);  // 0x102A9550
XI_API void __cdecl SqVtx_AllocateField(int param_1, int param_2, int param_3);  // 0x102A9980
XI_API void __cdecl SqVtx_ClearEntries(int param_1);  // 0x102A9EF0
XI_API void __cdecl SqVtx_ClearEntriesAlt(int param_1);  // 0x102A9F30
XI_API void __cdecl SqVtx_PackFloatsToBytes(int param_1, int param_2);  // 0x102A9FB0
XI_API undefined4 * __cdecl SqshTriStrip_Create(void);  // 0x102AA2D0
XI_API void __cdecl SqshTriStrip_Init(undefined4 * param_1);  // 0x102AA2F0
XI_API undefined4 __cdecl SqshTriStrip_GetGlobal(void);  // 0x102ABEB0
XI_API undefined4 __cdecl SqshTriStrip_ForEachTriangle(int param_1, undefined * param_2, undefined4 param_3);  // 0x102ABEC0
XI_API undefined4 * __cdecl SqshPoints_Create(void);  // 0x102ACB60
XI_API void __cdecl SqshPoints_Init(undefined4 * param_1);  // 0x102ACB80
XI_API undefined4 * __cdecl SqshCurves_Create(void);  // 0x102ACF20
XI_API void __cdecl SqshCurves_Init(undefined4 * param_1);  // 0x102ACF40
XI_API void __cdecl SqshCurves_ComputeNormals(int param_1, undefined4 xi_s2);  // 0x102AD1D0
XI_API undefined4 __cdecl SqshCurves_ComputeTangents(int param_1, undefined4 xi_s2);  // 0x102AD770
XI_API void __cdecl SqshCurves_RebuildIndex(int param_1);  // 0x102AD990
XI_API void __cdecl SqinShape_Reset(undefined4 * param_1);  // 0x102AEC50
XI_API undefined4 * __cdecl SqdfShape_Create(void);  // 0x102AEE90
XI_API void __cdecl SqdfShape_Init(undefined4 * param_1);  // 0x102AEEB0
XI_API void __cdecl SqdfShape_InitCallbacks(undefined4 * param_1);  // 0x102AF170
XI_API undefined4 * __cdecl sqinCluster_Create(void);  // 0x102AF540
XI_API void __cdecl sqinCluster_Init(undefined4 * param_1);  // 0x102AF570
XI_API void __cdecl Drawable_DrawTwoPass(int param_1, int * param_2);  // 0x102B2CA0
XI_API UINT __stdcall Imm_GetVirtualKeyJmp(HWND param_1);  // 0x102BC820
XI_API UINT __stdcall LinkedLibraries_JmpImmGetDescriptionA(HKL param_1, LPSTR lpszDescription, UINT uBufLen);  // 0x102BC826
XI_API HIMC __stdcall LinkedLibraries_JmpImmGetContext(HWND param_1);  // 0x102BC82C
XI_API BOOL __stdcall LinkedLibraries_JmpImmReleaseContext(HWND param_1, HIMC param_2);  // 0x102BC832
XI_API BOOL __stdcall Imm_NotifyIMEJmp(HIMC param_1, DWORD dwAction, DWORD dwIndex, DWORD dwValue);  // 0x102BC838
XI_API BOOL __stdcall LinkedLibraries_JmpImmSetCandidateWindow(HIMC param_1, LPCANDIDATEFORM lpCandidate);  // 0x102BC83E
XI_API BOOL __stdcall LinkedLibraries_JmpImmSetCompositionWindow(HIMC param_1, LPCOMPOSITIONFORM lpCompForm);  // 0x102BC844
XI_API BOOL __stdcall Imm_SetOpenStatusJmp(HIMC param_1, BOOL param_2);  // 0x102BC856
XI_API BOOL __stdcall Imm_GetOpenStatusJmp(HIMC param_1);  // 0x102BC85C
XI_API BOOL __stdcall Imm_GetConversionStatusJmp(HIMC param_1, LPDWORD lpfdwConversion, LPDWORD lpfdwSentence);  // 0x102BC862
XI_API LONG __stdcall Imm_GetCompositionStringAJmp(HIMC param_1, DWORD param_2, LPVOID lpBuf, DWORD dwBufLen);  // 0x102BC868
XI_API BOOL __stdcall Imm_SetCompositionStringAJmp(HIMC param_1, DWORD dwIndex, LPVOID lpComp, DWORD dwCompLen, LPVOID lpRead, DWORD dwReadLen);  // 0x102BC86E
XI_API BOOL __stdcall LinkedLibraries_JmpImmSetConversionStatus(HIMC param_1, DWORD param_2, DWORD param_3);  // 0x102BC874
