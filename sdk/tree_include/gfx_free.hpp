// gfx_free.hpp -- graphics functions with no established class.
#pragma once
#include "gfx_common.hpp"
XI_API undefined4 __cdecl App_RenderFrameMaskedFPU(void);  // 0x10001B50
XI_API char __cdecl Gfx_CopySurfaceRectToTexture(struct IDirect3DSurface8 *a1, const struct tagRECT *a2, unsigned int *a3, int a4);  // 0x10002040
XI_API char __cdecl Gfx_ProbeDeviceCaps(int a1, unsigned int *a2, int *a3);  // 0x10002130
XI_API char __cdecl Gfx_CreateD3DHolder(int a1, int a2, int a3, char a4, char a5);  // 0x10002F20
XI_API char __thiscall Gfx_D3DBootstrap(int self_, int a2, int a3, int a4, char a5, char a6, int a7);  // 0x100031F0
XI_API char __thiscall Gfx_TryCreateDeviceForMode(_DWORD **self_, int a2, int a3, int a4, char a5, char a6, int a7, int a8);  // 0x100033C0
XI_API char __thiscall Gfx_CreateDevice(_DWORD *self_, int a2, int a3, int a4, int a5, int a6, char a7, char a8, int a9);  // 0x100034B0
XI_API void __thiscall DebugOverlay_Update(void * self_);  // 0x10003710
XI_API void __thiscall Unit10003890_DrawActorAxes(_DWORD *self_);  // 0x10003890
XI_API int __thiscall Debug_DrawTextTable(_DWORD *self_);  // 0x10003B60
XI_API void __stdcall Debug_DrawWorldText(_DWORD *a1, const char *a2, int arg8);  // 0x10003D70
XI_API char __thiscall App_InitScene(int self_, int a4);  // 0x10010D20
XI_API unsigned __int8 __thiscall Frame_Render(void * self_);  // 0x10011A00
XI_API int __cdecl Post_Afterimage(void);  // 0x10012F40
XI_API int __thiscall Post_FlashAndZoomFeedback(void *self_);  // 0x100132B0
XI_API undefined4 __thiscall App_DispatchSubState(void * self_);  // 0x10014170
XI_API undefined1 __thiscall Unit10014350_RunStepThenLoadAll(void * self_);  // 0x10014350
XI_API undefined1 __thiscall Camera_ReleaseAll(void * self_);  // 0x10014C10
XI_API void __stdcall App_WinMainClearFileMng(undefined4 param_1, undefined4 param_2, undefined4 param_3);  // 0x100157B0
XI_API undefined4 __stdcall App_RunWithCOM(undefined4 xi_s1, undefined4 xi_s2);  // 0x10015AB0
XI_API char __cdecl App_CreateRendererAndApp(void);  // 0x100161B0
XI_API void __cdecl App_RunMainLoopThenSetPtr(void);  // 0x10016300
XI_API _DWORD * __cdecl App_DestroyGlobalObjects(void);  // 0x10016320
XI_API LRESULT __stdcall App_WndProc(HWND param_1, uint32_t param_2, uint32_t param_3, int param_4);  // 0x10016870
XI_API void __thiscall GammaRamp_ApplyIfChanged(int self_);  // 0x10017230
XI_API int __stdcall Unit10014350_Draw(int a1, int a2);  // 0x10017310
XI_API int __thiscall Shader_CreateVertexShader(void *self_, int a1);  // 0x10017810
XI_API void __thiscall Unit10017C10_Step(void * self_, undefined4 param_1, undefined4 param_2, short * param_3);  // 0x10017C20
XI_API int __thiscall Unit10017C10_Begin(int *self_, int a2, int a3, int a4);  // 0x10017C60
XI_API void __thiscall Unit10018840_UpdateRangeEntries(void * self_);  // 0x10018B50
XI_API _DWORD * __cdecl Model_CreateTranslucentTargets(void);  // 0x1001D0A0
XI_API char __thiscall Model_BeginTranslucentPass(int self_);  // 0x1001D240
XI_API char __thiscall Model_TranslucentUnbindTexture(_DWORD *self_);  // 0x1001D350
XI_API int __thiscall Model_CompositeTranslucentPass(void *self_);  // 0x1001D3B0
XI_API void __thiscall TexRes_LoadBm2(void * self_);  // 0x1001D800
XI_API int __thiscall Tex_DrawNamedTexturePreview(void *self_, int a1, int a2);  // 0x1001DC70
XI_API int __stdcall Gfx_DrawScreenQuad256(int a1, int a2);  // 0x1001DD00
XI_API Vt_1032A460_vtbl ** __thiscall Unit10025220_Init(Vt_1032A460_vtbl **self_);  // 0x10025260
XI_API char __thiscall ProjTex_BeginPass(_DWORD *self_, int *a2, int a3, _DWORD *a4);  // 0x10025330
XI_API int __thiscall ProjTex_EndPass(void *self_, int a1);  // 0x100255C0
XI_API int __thiscall ProjTex_CaptureToTarget(void *self_, int a1, int a2, int a3, int a4);  // 0x10025870
XI_API char __stdcall EnvMap_BeginPass(int *a1, int a2, float *a3);  // 0x10025C40
XI_API int __stdcall EnvMap_EndPass(int a1);  // 0x10025F70
XI_API void __cdecl Dbg_DrawViewAxisGizmo(void);  // 0x100263F0
XI_API void __stdcall Dbg_DrawAxesAt(int a1);  // 0x100266C0
XI_API float * __cdecl Gfx_ScreenDeltaToNdc(float *a1, float *a2);  // 0x10027930
XI_API int __stdcall Mem_DrawHeapUsageBar(int a1, int a2, int a3, int a4, int a5);  // 0x100295A0
XI_API int __cdecl CreateSharedVertexBuffers(void);  // 0x10029A50
XI_API void * __thiscall CYyOs2VtxBuffer_ScalarDeletingDtor(void * self_, undefined4 param_1);  // 0x1002D660
XI_API undefined4 __thiscall Unit1002D8E0_FixOffsetsAndCreateVtxBuffer(void * self_);  // 0x1002D8F0
XI_API void __cdecl Gfx_SetStreamSourceCached(int param_1, undefined4 param_2, undefined4 param_3);  // 0x1002F130
XI_API int __cdecl Gfx_ApplyCachedStreamSource(unsigned int a1);  // 0x1002F160
XI_API int __cdecl Gfx_ApplyCachedVertexShader(void);  // 0x1002F1A0
XI_API _DWORD * __thiscall Unit100310A0_Construct(_DWORD *self_);  // 0x10033710
XI_API char __thiscall Model_BeginOffscreenPass(int self_, int *a2, int a3);  // 0x10033800
XI_API char __thiscall Model_EndOffscreenPassBindTextures(_DWORD *self_, int a2);  // 0x10033A70
XI_API undefined4 __thiscall Shadow_DrawByMode(void * self_, float * param_1);  // 0x10033DA0
XI_API int __cdecl Font_DrawPass(void);  // 0x10038520
XI_API unsigned __int8 * __cdecl Font_DrawString(unsigned __int8 *a1, float a2, float arg8, float a4);  // 0x10038720
XI_API _DWORD * __cdecl Post_CreateScreenEffectTargets(void);  // 0x10038930
XI_API int __thiscall Post_CaptureSceneToTarget(void *self_);  // 0x10038A80
XI_API undefined4 __thiscall Post_DrawRotatingGhostLayers(void * self_);  // 0x10038E10
XI_API undefined1 __thiscall TexObj_CreateAndUpload(void * self_);  // 0x10039A30
XI_API undefined1 __thiscall TexObj_Reupload(void * self_);  // 0x10039A60
XI_API int __thiscall TexObj_Upload(void *self_);  // 0x10039E50
XI_API undefined1 __thiscall TexMgr_UploadPumpEntry(void * self_);  // 0x1003AB70
XI_API undefined4 __thiscall TexMgr_UploadPump(void * self_);  // 0x1003ABB0
XI_API int __cdecl Sky_DrawDome(void);  // 0x1003D9A0
XI_API int __cdecl Sky_DrawDomeViewCentered(void);  // 0x1003DB60
XI_API void __thiscall YmElem_DrawD3ASegment(void * self_, undefined4 param_1, undefined4 param_2, int param_3);  // 0x1003E910
XI_API int __thiscall YmElem_SetD3ADrawState(int self_);  // 0x1003E9A0
XI_API _DWORD * __thiscall YmElem_DrawScreenDistortion(float *self_);  // 0x100426F0
XI_API int __thiscall CMoVuElem_Draw(int *self_, int a2, int a3, int a1, unsigned int a5, int a6);  // 0x10043F40
XI_API int __thiscall Gfx_SetViewMatrixFromField10(int self_);  // 0x10044210
XI_API int __thiscall Gfx_SetViewMatrixFromField90(int self_);  // 0x10044230
XI_API _DWORD * __cdecl Mo_InitSharedRenderResources(void);  // 0x10044270
XI_API void __cdecl Unit10043E40_ReleaseResourcesOf(int param_1);  // 0x100446A0
XI_API undefined4 __thiscall YmElem_DrawWithOwnProjection(void * self_);  // 0x10046070
XI_API int __cdecl Fog_SetRenderStates(void);  // 0x100464D0
XI_API int __thiscall YmElem_SetupDevice(void *self_, int a1);  // 0x100467E0
XI_API int __thiscall YmElem_RestoreDevice(_WORD *a1, __int16 a4);  // 0x100472F0
XI_API bool __cdecl GateEffectBoxProjection(int a1, int a2, __int16 a3, __int16 *a4);  // 0x1004A870
XI_API double __cdecl ScaleElemVisibilityByProbe(int a1, int a2, __int16 *a3);  // 0x1004E630
XI_API undefined4 __thiscall SharedConditionalStateReset(void * self_);  // 0x100531D0
XI_API undefined4 __attribute__((stdcall, regparm(3))) YmGenerater_Stop(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, undefined4 * param_2);  // 0x100538E0
XI_API undefined4 __thiscall Unit10053860_StopGenerators(void * self_, int param_1, int param_2, undefined4 param_3, undefined4 * param_4);  // 0x10053A00
XI_API char __cdecl BeginEffectOffscreenPass(void);  // 0x10054D70
XI_API float * __stdcall EndEffectOffscreenPass(float *a1, int a2);  // 0x10054F80
XI_API unsigned int __stdcall Gfx_CreateVertexBuffer(unsigned int a1, int a2, int a3, int a4);  // 0x1006A020
XI_API int __thiscall Batch_DrawPrimitives(_DWORD *self_, int arg0);  // 0x1006AA30
XI_API int __thiscall StateBlockHolder_ApplyRenderStates(_DWORD *self_, int *a2);  // 0x1006AF00
XI_API int __thiscall StateBlock_ApplyTSS(void *self_, int a1);  // 0x1006AF90
XI_API int __thiscall Occlusion_QueryScreenRect(__int16 *self_, float *a2, int a3, int a4, int a5, int a6, int a7, int a8, char a9, int a10);  // 0x1006C280
XI_API int __thiscall Occlusion_QueryScreenRectImpl(__int16 *self_, float *arg0, int a2, int a5, int a6, int a7, int a8, int _60, char a9, int a10);  // 0x1006C300
XI_API int __stdcall Occlusion_DrawQuery(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);  // 0x1006C530
XI_API int __thiscall Occlusion_ReadbackCount(__int16 *self_, char a2);  // 0x1006C8B0
XI_API int __thiscall OcclusionMng_Prepare(_DWORD *self_);  // 0x1006C9B0
XI_API int __cdecl Gfx_InitCubeMapTextures(void);  // 0x10075280
XI_API void __thiscall TexRef_EnsureRenderTarget(int *self_);  // 0x100755A0
XI_API int __thiscall TextureHolder_BindWarped(int *self_, int a2, float a3, float a4, float a5);  // 0x10075700
XI_API int __thiscall TexRef_SetTexture(int *self_, int a2);  // 0x10075960
XI_API int __thiscall TextureHolder_BindTinted(int *self_, int a2, int a3);  // 0x100759C0
XI_API void __cdecl Actor_DrawWorldText(_DWORD *a1, const char *a2, float a3, unsigned int a4, int a5);  // 0x10086210
XI_API void __thiscall Unit10086E90_UpdateFlags120Bit23(void * self_);  // 0x1008E4D0
XI_API undefined4 __thiscall Acter_UpdateOne(void * self_);  // 0x1008E9A0
XI_API void __cdecl Acter_UpdateAllLists(void);  // 0x10095900
XI_API undefined4 __cdecl Acter_UpdateFrame(void);  // 0x10096640
XI_API int __thiscall Actor_SelectNearestLights(void *self_);  // 0x100CB4E0
XI_API long double __thiscall fn_100CD040(void * self_);  // 0x100CD040
XI_API void __attribute__((stdcall, regparm(3))) CXiSkeletonActor_DrawName2IfVisible(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, undefined4 * param_2, char * param_3, float param_4);  // 0x100D08B0
XI_API undefined4 __attribute__((stdcall, regparm(3))) CXiSkeletonActor_AttachPartResource(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, int param_2, int * param_3);  // 0x100D0D70
XI_API undefined4 __thiscall Unit100D13B0_ProcessResidentListEntries(void * self_, int * param_1, int param_2);  // 0x100D1450
XI_API void __thiscall Menu_DrawWindowItems(void * self_);  // 0x101177D0
XI_API undefined8 __thiscall Unit100D7420_DrawUnscaled(void * self_, void * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5);  // 0x10119F80
XI_API int __thiscall Unit100D7420_SetViewport(__int16 *self_);  // 0x1011AA40
XI_API int __cdecl Gfx_ApplyViewport1B70(void);  // 0x1011AAC0
XI_API char __thiscall Font_BindGlyphTexture(int self_);  // 0x1011BAE0
XI_API undefined4 __thiscall Font_DrawGlyphQuadGrey(void * self_, undefined4 param_1, int * param_2, undefined4 param_3, undefined4 param_4);  // 0x1011BBA0
XI_API int __thiscall Font_DrawGlyphQuad(float *self_, __int16 a2, int *a3, unsigned int a4, float a5, float a6);  // 0x1011BBD0
XI_API int __cdecl Gfx_SetAdditiveBlend(void);  // 0x1011BDC0
XI_API undefined4 __cdecl Font_DrawChar(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5);  // 0x1011BF40
XI_API int __cdecl Gfx_SetCellBlendMode(int a1, int a2, int a3, int a4);  // 0x1011C1F0
XI_API void __thiscall Font_LoadHighResTexture(int *self_);  // 0x1011C720
XI_API int __thiscall Cell_DrawAt(void *self_, int a1, int a2);  // 0x1011E800
XI_API int __thiscall Cell_DrawTexturedQuad(void *self_, int a1, int a2, int a3, int a4, int a5, int a6);  // 0x1011E980
XI_API void __thiscall Cell_DrawTransformed(int self_, int a2, int a3, float a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, unsigned int a20, int a21);  // 0x1011EDE0
XI_API int __thiscall Cell_DrawStretchedWrapped(int self_, int a2, int a3, int a4, int a5, int a6, int a7, float a8, float a9, unsigned int a10, unsigned int a11, char a12);  // 0x1011EF60
XI_API void __thiscall Cell_DrawWithDefaultBlend(void * self_);  // 0x1011F2D0
XI_API int __thiscall Cell_DrawQuadBlended(void *self_, int a1, int a2, int a3, int a4, int a5);  // 0x1011F300
XI_API undefined8 __thiscall Cell_DrawFirstStretched(void * self_, uint32_t param_1, uint32_t param_2, undefined4 param_3, undefined4 xi_s4, undefined4 xi_s5, undefined4 xi_s6, undefined4 xi_s7, undefined4 xi_s8, undefined4 xi_s9, undefined4 xi_s10, undefined4 xi_s11);  // 0x10120000
XI_API undefined8 __cdecl Font_DrawStringFlags44(int param_1, undefined4 param_2, char * param_3, int param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7);  // 0x10129F40
XI_API void __thiscall Unit1012AC80_DrawPanel(void * self_);  // 0x1013A350
XI_API void __thiscall Menu_DrawLayers(void * self_);  // 0x1015F6A0
XI_API void __thiscall Menu_DrawAll(void * self_);  // 0x1015FA00
XI_API int __cdecl Gfx_SetDefault2DStates(void);  // 0x101604B0
XI_API int __cdecl Gfx_DisableFogAndAlphaBlend(void);  // 0x10160650
XI_API undefined4 __attribute__((stdcall, regparm(3))) Unit1012AC80_DrawImageAtRightOfRect(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x10161990
XI_API undefined4 __attribute__((stdcall, regparm(3))) Unit1012AC80_DrawImageA4AtRightOfRect(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_);  // 0x10161D60
XI_API int __cdecl Viewport_SetClipped(int a1, int a2);  // 0x10162010
XI_API int __cdecl Gfx_ApplyViewport1904(void);  // 0x101620B0
XI_API void __cdecl Font_SetupAdditiveDraw(void);  // 0x101620D0
XI_API void __thiscall Obj_10621944_DrawBgRect(void * self_);  // 0x10163390
XI_API int __stdcall Gfx_DrawSolidRect2D(int a1, int a2);  // 0x10163400
XI_API int __stdcall Dbg_DrawTriangleLines(int a1, int a2, int a3);  // 0x1016DDF0
XI_API _DWORD * __thiscall ParseZoneMeshData(void *self_, int *a2, int a3, int a4, int a5, int a6, _DWORD *a7, int a8);  // 0x1016FCD0
XI_API int __cdecl Dbg_DrawOrientedBoxes(void);  // 0x10174EC0
XI_API int __stdcall Gfx_CompileVertexShader(int a1, int a2);  // 0x101771B0
XI_API int __thiscall Gfx_AssembleVertexShader(void *self_, int a1, int a2);  // 0x10177240
XI_API int __thiscall Gfx_CompilePixelShader(const char **self_, int a2);  // 0x101772E0
XI_API int __cdecl Gfx_SetZBias(unsigned int a1);  // 0x10177400
XI_API int __cdecl Gfx_SetupLineDrawState(void);  // 0x101779C0
XI_API int __cdecl Gfx_DrawQuadOutline(float *a1, char a2, unsigned __int8 arg8, unsigned __int8 a4, char a5, char a6);  // 0x10177B40
XI_API int __cdecl Gfx_DrawLine3D(int a1, int a2, int a3, int a4, int a5, int a6);  // 0x10177C50
XI_API void __thiscall ZoneMap_UpdateLoadState(void * self_);  // 0x101787C0
XI_API undefined4 __thiscall ZoneMap_SetArea(void * self_, int param_1, int param_2);  // 0x10178A20
XI_API void __thiscall ZoneMap_ReleaseSlot(void * self_, int param_1);  // 0x10178AC0
XI_API int __thiscall ZoneMap_ReleaseStateBlock(CTsZoneMap *self_);  // 0x10178B00
XI_API void __thiscall ZoneMap_Reset(void * self_);  // 0x10178F70
XI_API int __thiscall ZoneMap_DrawBox(void *self_);  // 0x101791F0
XI_API int __thiscall ZoneMap_CreateVertexShaders(char *self_);  // 0x101792A0
XI_API int __thiscall ZoneMap_DrawMeshGroupsWithFog(CTsZoneMap *self_, _DWORD *a2);  // 0x1017ADE0
XI_API undefined4 __thiscall ZoneMap_FreeSlot(void * self_, int param_1);  // 0x1017B110
XI_API undefined4 __thiscall ZoneMap_TeardownStep(void * self_);  // 0x1017B1E0
XI_API int __stdcall Gfx_DrawWireBox(int a1);  // 0x10182F10
XI_API _DWORD * __thiscall ZoneMap_DrawMeshById(int self_, int a2, int a3);  // 0x10183DA0
XI_API undefined4 __attribute__((stdcall, regparm(3))) ModelActor_Draw(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, int param_2, undefined4 xi_s2);  // 0x101844C0
XI_API void __thiscall ZoneMap_ClearSlots(void * self_);  // 0x10186DB0
XI_API void __stdcall ZoneMap_FreeSubAreas(int * param_1);  // 0x10186DD0
XI_API void __thiscall ZoneMap_ReleaseChain(void * self_);  // 0x10187030
XI_API uint32_t __cdecl fn_1018AA50(undefined4 * param_1, undefined4 param_2);  // 0x1018AA50
XI_API uint32_t __cdecl fn_1018AAE0(undefined4 * param_1);  // 0x1018AAE0
XI_API uint32_t __cdecl fn_1018AB60(undefined4 * param_1);  // 0x1018AB60
XI_API void __thiscall Blend_Update(void * self_);  // 0x1018ADE0
XI_API undefined4 __thiscall Unit1018BA60_DrawTextBlockOnce(void * self_);  // 0x1019EBB0
XI_API int __thiscall Unit1018BA60_DrawTextLines(void * self_, uint32_t param_1, int param_2, char * param_3, undefined4 param_4, int param_5);  // 0x1019EDB0
XI_API void __cdecl Gfx_ProjectWorldToScreen(_DWORD *a1, _WORD *a2, _WORD *a3);  // 0x101C8DA0
XI_API undefined8 __cdecl Unit101C72E0_DrawUnscaled(undefined4 param_1, undefined4 param_2, uint8_t * param_3, undefined4 param_4);  // 0x101C9780
XI_API int __cdecl Unit101C72E0_DrawTextItem0(undefined4 param_1, undefined4 param_2, uint8_t * param_3, int param_4, float param_5, float param_6, undefined4 param_7);  // 0x101C97B0
XI_API undefined8 __cdecl Unit101C72E0_DrawString(undefined4 param_1, int param_2, undefined4 param_3, char * param_4, int param_5);  // 0x101C9D50
XI_API int __cdecl Unit101C72E0_DrawTruncated(undefined4 param_1, undefined4 param_2, char * param_3, undefined4 param_4);  // 0x101CA180
XI_API void __cdecl Unit101C72E0_DrawFractionRange(undefined4 param_1, undefined4 param_2, void * param_3, void * param_4, float param_5, float param_6, float param_7, float param_8, float param_9, float param_10);  // 0x101CAD00
XI_API void __cdecl Unit101C72E0_DrawFractionDefault(undefined4 param_1, undefined4 param_2, void * param_3, void * param_4, float param_5, float param_6);  // 0x101CAEC0
XI_API undefined8 __cdecl Unit101C72E0_DrawSmoothed(undefined4 param_1, undefined4 param_2, void * param_3, void * param_4, undefined4 param_5, uint8_t * param_6, float param_7, float param_8, float param_9, float param_10);  // 0x101CAF00
XI_API undefined8 __cdecl Unit101C72E0_DrawSmoothedDefault(undefined4 param_1, undefined4 param_2, void * param_3, void * param_4, undefined4 param_5, uint8_t * param_6);  // 0x101CB000
XI_API void __cdecl Unit101C72E0_DrawFractionItem1A(undefined4 param_1, undefined4 param_2, float param_3, undefined4 param_4);  // 0x101CB040
XI_API undefined8 __cdecl Unit101C72E0_DrawSmoothedItem1A(undefined4 param_1, undefined4 param_2, undefined4 param_3, uint8_t * param_4);  // 0x101CB090
XI_API void __cdecl Unit101C72E0_DrawSmoothedItem1B(undefined4 param_1, undefined4 param_2, undefined4 param_3, uint8_t * param_4);  // 0x101CB1B0
XI_API undefined4 __cdecl Unit101C72E0_DrawSmoothedExItem1B(undefined4 param_1, undefined4 param_2, undefined4 param_3, uint8_t * param_4, float param_5, float param_6, float param_7, float param_8);  // 0x101CB230
XI_API void __cdecl Unit101C72E0_DrawEasedPercent(undefined4 param_1, undefined4 param_2, void * param_3, void * param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7, uint8_t * param_8, float param_9, float param_10, float param_11, float param_12);  // 0x101CB430
XI_API void __cdecl Unit101C72E0_DrawEasedPercentUnitScale(undefined4 param_1, undefined4 param_2, void * param_3, void * param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7, uint8_t * param_8);  // 0x101CB500
XI_API void __cdecl Unit101C72E0_DrawEasedPercentItem1A(undefined4 param_1, undefined4 param_2, undefined4 param_3, uint8_t * param_4);  // 0x101CB550
XI_API undefined4 __cdecl Unit101C72E0_BeginCapture(undefined4 param_1, undefined4 param_2, undefined4 param_3);  // 0x101CB770
XI_API int * __cdecl CopyrightText_Draw(void);  // 0x101D0B00
XI_API undefined4 __cdecl Unit101D0910_TakeScreenshot(int param_1);  // 0x101D0EA0
XI_API undefined4 __cdecl Unit101D0910_SaveJpeg512x382(undefined4 param_1);  // 0x101D1000
XI_API undefined4 __cdecl Unit101D0910_SaveJpegScreenSize(undefined4 param_1);  // 0x101D1100
XI_API void __thiscall Unit101D2FF0_Draw(void * self_, int * param_1);  // 0x101D3FC0
XI_API void __thiscall Unit101D2FF0_Update(void * self_);  // 0x101D5680
XI_API undefined4 __thiscall Unit101D7020_DrawCountersAndGauge(void * self_, int param_1, int param_2);  // 0x10201340
XI_API void __thiscall Yk_UpdateLayout(void * self_);  // 0x102015D0
XI_API void __stdcall Unit101D7020_Call101CA180IfText(undefined4 param_1, undefined4 param_2, char * param_3, undefined4 param_4);  // 0x10202380
XI_API undefined4 __attribute__((stdcall, regparm(3))) Unit101D7020_DrawLabelIfStateGroup06Or38(undefined4 xi_eax, uint32_t xi_edx_unused, void * self_, int param_2, int param_3);  // 0x10202AF0
XI_API undefined4 __thiscall Unit101D7020_Call10156C30InRect(void * self_);  // 0x10211050
XI_API int __thiscall Movie_CreateFrameTextures(Vt_1033BE90 *self_, int a2);  // 0x1021E060
XI_API void __thiscall Unit1021D930_DrawPanelForActor(void * self_);  // 0x1021F410
XI_API void __stdcall Unit1021D930_DrawActorPanelFigures(int param_1);  // 0x1021F480
XI_API void __thiscall Unit1021D930_DrawEntryRows(void * self_, undefined4 xi_s1);  // 0x1021F950
XI_API undefined4 __stdcall Unit1021D930_DrawLabelledRow(int param_1, int param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7, uint8_t * param_8);  // 0x1021FA90
XI_API void __stdcall Unit1021D930_DrawTwoDigitValue(int param_1, undefined4 param_2, undefined4 xi_s3);  // 0x1021FB10
XI_API void __stdcall Unit1021D930_DrawBarRow(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, uint8_t * param_6);  // 0x1021FB80
XI_API void __stdcall Unit1021D930_DrawNameRows(undefined4 param_1, undefined4 param_2, int param_3, int param_4, int param_5, int param_6);  // 0x1021FBD0
XI_API void __thiscall ActerBuff_DrawNearby(void * self_);  // 0x1021FCE0
XI_API void __thiscall Unit1021D930_DrawStrongholdPanel(void * self_);  // 0x1021FE10
XI_API void __stdcall Unit1021D930_DrawLabelBar(int param_1, undefined4 param_2, void * param_3, float param_4, undefined4 param_5);  // 0x102201A0
XI_API void __thiscall Unit1021D930_DrawGameTime(void * self_, int param_1, int param_2);  // 0x102201F0
XI_API int __thiscall Unit1021D930_Draw(int *self_);  // 0x102214D0
XI_API void __cdecl Unit1021D930_DrawMovie(int param_1, undefined4 param_2, int param_3, undefined4 param_4, int param_5);  // 0x10227F70
XI_API undefined4 __cdecl Unit1021D930_DrawTimeLeftText(int param_1, undefined4 param_2, int param_3, int param_4, int param_5);  // 0x10228080
XI_API undefined4 __thiscall Unit1021D930_DrawTargetEntryIcons(void * self_);  // 0x10228440
XI_API void __thiscall Unit1021D930_DrawProgressBar(void * self_);  // 0x10234660
XI_API undefined4 __thiscall fn_10239240(void * self_, undefined4 xi_s1);  // 0x10239240
XI_API char * __thiscall Ui_DrawKeyPrompt(Vt_1033C8F0 *self_);  // 0x102394A0
XI_API void __cdecl fn_102454E0(void);  // 0x102454E0
XI_API void __cdecl LobbyThread_ResetZone(void);  // 0x10245BB0
XI_API int __cdecl StAvatarInit(_DWORD *a1);  // 0x1024CF50
XI_API uint32_t __cdecl StAvatar_Teardown(uint32_t * param_1, uint32_t param_2, uint32_t param_3);  // 0x1024D180
XI_API undefined4 __cdecl StAvatar_SetPending(uint32_t * param_1, uint32_t param_2);  // 0x1024D5C0
XI_API undefined4 __cdecl StAvatar_StopAndFreeBuffers(int param_1);  // 0x1024D790
XI_API undefined4 __cdecl StAvatar_ResolveItemsAndStart(uint32_t * param_1);  // 0x1024D850
XI_API undefined4 __cdecl StAvatar_Update(uint8_t * param_1);  // 0x1024DB60
XI_API void __cdecl StAvatar_SetViewFromDancerCamera(int a1);  // 0x1024F900
XI_API undefined4 __cdecl StAvatar_RenderIfEnabled(int param_1, int param_2);  // 0x10250190
XI_API int __cdecl StAvatarRender(_BYTE *arg0);  // 0x102501C0
XI_API undefined4 __cdecl StAvatarFini(uint32_t * param_1);  // 0x102504D0
XI_API void __thiscall StDancer_Update(void * self_);  // 0x10251500
XI_API void __thiscall Dancer_WorldEnd(void * self_, undefined4 param_1);  // 0x102515F0
XI_API void __thiscall StAvatar_SetActive(void * self_, undefined4 param_1, undefined4 param_2, undefined4 param_3, int param_4);  // 0x10251620
XI_API void __thiscall StAvatar_SetStateTeardown(void * self_, int param_1, uint32_t param_2);  // 0x102516B0
XI_API char __thiscall Dancer_InitDevice(int *self_);  // 0x10251A80
XI_API undefined4 __cdecl StModelItem_Resolve(uint32_t * param_1);  // 0x102528D0
XI_API int __thiscall Gfx_DrawSpriteAlphaTested(void *self_, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);  // 0x10253F60
XI_API int __cdecl FontGlyphCache_CreateTexture(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, D3DFORMAT a5, D3DPOOL a6);  // 0x1025D760
XI_API int __cdecl FontGlyphCache_CreateVertexBuffer(unsigned int a1, unsigned int a2, unsigned int a3, D3DPOOL a4);  // 0x1025D7B0
XI_API void __cdecl StAvatar_DrawScene(void);  // 0x102717F0
XI_API void __cdecl Unit10280C40_CompositeBlendPasses(int param_1, float param_2);  // 0x102813B0
XI_API int __cdecl sqgxTextureCreateFromImage(int a1, _BYTE *a2);  // 0x10281510
XI_API int __cdecl sqgxTextureAddZ(int a1, int a2, int a3);  // 0x102816E0
XI_API int __cdecl sqgxTextureAdd(int a1, int a2, IDirect3DTexture8 *a3, _BYTE *a4);  // 0x10281830
XI_API int __cdecl sqgxTextureClutAdd(int a1, int a2, int a3);  // 0x102819D0
XI_API int __cdecl sqgxTextureClut(int a1);  // 0x10281D60
XI_API int __cdecl sqgxTextureUpdate(void);  // 0x10281DB0
XI_API int __cdecl sqgxTextureStencilClear(int a1);  // 0x10282010
XI_API int __cdecl sqgxTextureClear(float *a1, int a2);  // 0x10282030
XI_API int * __cdecl sqgxTextureDrawZ(IDirect3DSurface8 *a1);  // 0x102820E0
XI_API int * __cdecl sqgxTextureDraw(int a1, char a2);  // 0x10282190
XI_API int * __cdecl sqgxZTest(int a1);  // 0x10282350
XI_API int __cdecl sqgxAlphaTest(unsigned int a1, unsigned int a2);  // 0x102823F0
XI_API int * __cdecl sqgxZMask(int a1);  // 0x10282470
XI_API int * __cdecl sqgxFBMask(int a1, int a2, int a3, int a4);  // 0x102824C0
XI_API int __cdecl Unit102822A0_SetSelectArg1(void);  // 0x10282640
XI_API int __cdecl sqgxBlendAdd(void);  // 0x102826C0
XI_API int __cdecl Unit102822A0_SetMultiplyAdd(void);  // 0x102827D0
XI_API int __cdecl sqgxBlendSub(void);  // 0x10282910
XI_API void __cdecl sqgxBlendLin(float a1);  // 0x10282A30
XI_API int __cdecl sqgxBlendTrsp(void);  // 0x10282B90
XI_API int __cdecl sqgxBlendTrspInv(void);  // 0x10282CB0
XI_API int __cdecl sqgxBlendAddDestAlpha(void);  // 0x10282DC0
XI_API int __cdecl Unit102822A0_SetModulateAlphaAdd(void);  // 0x10282ED0
XI_API int __cdecl sqgxBlendMultAlpha(void);  // 0x10282FF0
XI_API int __cdecl sqgxBlendMul(void);  // 0x10283110
XI_API int __cdecl sqgxBlendOff(void);  // 0x10283220
XI_API int __cdecl sqgxColorUpdate(void);  // 0x10283420
XI_API int * __cdecl sqgxViewport(float a1, float a2, float a3, float a4);  // 0x10283A10
XI_API int __cdecl sqgxPassAdd(int a1);  // 0x10283F70
XI_API int * __cdecl sqgxPass(int a1);  // 0x10283FC0
XI_API int __cdecl sqgxMatrixUpdate(void);  // 0x10284410
XI_API int __cdecl sqgxVertexShaderCreate(_DWORD *a1);  // 0x10284950
XI_API int __cdecl sqgxVertexShaderSelect(void);  // 0x10284A80
XI_API int * __cdecl sqgxShader(int a1, int a2);  // 0x10284B20
XI_API int __cdecl sqgxVertexShaderRelease(void);  // 0x10284EF0
XI_API int __cdecl SqmdDMB_Resolve(char * param_1, undefined4 param_2);  // 0x10287FB0
XI_API uint32_t __cdecl SqmdDMB_ResolveTextures(int param_1, uint32_t param_2);  // 0x102886D0
XI_API uint8_t * __cdecl sqmdDMBBuildShapes(int param_1, uint32_t param_2);  // 0x10288E60
XI_API int * __cdecl sqgxShapeIndexBufferBegin(void);  // 0x1028AA70
XI_API int __cdecl SqgxShape_FillBuffers(void);  // 0x1028AB50
XI_API int * __cdecl sqgxShapeBegin(void);  // 0x1028AFE0
XI_API void __cdecl SqsnScene_DrawMatrixShape(undefined4 param_1, int * param_2);  // 0x1028F4C0
XI_API void __cdecl sqsnSceneDraw(int a1);  // 0x1028F8C0
XI_API void __cdecl sqsnSceneLayerDraw(int * param_1, int param_2);  // 0x1028FDD0
XI_API void __cdecl SqsnScene_DrawFadeSprite(int param_1);  // 0x1028FF80
XI_API void __cdecl sqsnSceneLayerDrawShadowed(int * param_1, int param_2);  // 0x1028FFF0
XI_API void __cdecl sqsnSceneLayerSnapShotComposite(int param_1, int param_2);  // 0x102902C0
XI_API void __cdecl SqsdGeneric_DrawPasses(int param_1, int * param_2);  // 0x10290B60
XI_API int * __cdecl sqsdGeneric_BakeOntoShape(int param_1, int * param_2);  // 0x10290FC0
XI_API int __cdecl sqsnShadowVolumeSetPass(int a1);  // 0x10297CC0
XI_API int __cdecl sqgxShadowStencilEnable(int a1);  // 0x10297EC0
XI_API int __cdecl sqsnShadowVolumeBeginVB(void);  // 0x102981E0
XI_API int __cdecl Texture_CreateEntry(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5);  // 0x10298E10
XI_API void __cdecl SqsdSampling_DrawPasses(int param_1, int * param_2);  // 0x10299090
XI_API int __cdecl sqsdSampling_BakeOntoShape(int param_1, int param_2);  // 0x10299250
XI_API void __cdecl SqsdAniso_DrawPasses(int * param_1, int * param_2);  // 0x102993B0
XI_API int * __cdecl sqsdAniso_BakeOntoShape(int param_1, int * param_2);  // 0x10299610
XI_API void __cdecl SqsdCartoon_Draw(int param_1, int * param_2);  // 0x102997A0
XI_API undefined4 __cdecl SqsdGlow_ApplyShader(int param_1, int param_2);  // 0x102999A0
XI_API int * __cdecl sqsdGlow_BakeOntoShape(int param_1, int * param_2);  // 0x10299AB0
XI_API _DWORD * __cdecl sqgxDlistEnd(void);  // 0x1029B620
XI_API void __cdecl sqgxDlistDraw(IDirect3DVertexBuffer8 **a1);  // 0x1029B9D0
XI_API void __cdecl sqsnShadowVolumeDraw(int a1, int a2, int a3);  // 0x102A21F0
XI_API void __cdecl sqsnPlanarShadowDraw(int a1, int a2);  // 0x102A2530
XI_API void __cdecl Unit102A2530_RenderShadowTexture(int param_1, int param_2);  // 0x102A2720
XI_API void __cdecl Unit102A2530_DrawShadowedShape(int param_1, int * param_2, int param_3, int param_4);  // 0x102A2C00
XI_API void __cdecl Drawable_DrawTwoPass(int param_1, int * param_2);  // 0x102B2CA0
