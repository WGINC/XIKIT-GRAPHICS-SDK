// gfx_orig.hpp -- calls into the game's own code (not reconstructed here), by address.
#pragma once
#include "gfx_common.hpp"
#define XI_ORIG static inline __attribute__((always_inline))
namespace orig {
XI_ORIG int sub_10001240(int a0, int a1, HINSTANCE a2, int a3, void * a4, void * a5) { return reinterpret_cast<int (__thiscall *)(int, int, HINSTANCE, int, void *, void *)>(XI_GAME(0x10001240u))(a0, a1, a2, a3, a4, a5); }
XI_ORIG int sub_100014A0(HWND a0) { return reinterpret_cast<int (__cdecl *)(HWND)>(XI_GAME(0x100014A0u))(a0); }
XI_ORIG void CApp_RunMainLoop(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10001520u))(a0); }
XI_ORIG char sub_100016C0(int a0, unsigned int a1, unsigned int a2, unsigned int a3) { return reinterpret_cast<char (__cdecl *)(int, unsigned int, unsigned int, unsigned int)>(XI_GAME(0x100016C0u))(a0, a1, a2, a3); }
XI_ORIG int App_RenderFrameMaskedFPU(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10001B50u))(a0); }
XI_ORIG undefined4 App_RenderFrameMaskedFPU_v1() { return reinterpret_cast<undefined4 (__cdecl *)()>(XI_GAME(0x10001B50u))(); }
XI_ORIG char sub_10001BB0(HINSTANCE a0) { return reinterpret_cast<char (__stdcall *)(HINSTANCE)>(XI_GAME(0x10001BB0u))(a0); }
XI_ORIG BOOL sub_10001CC0(void * a0, void * a1) { return reinterpret_cast<BOOL (__thiscall *)(void *, void *)>(XI_GAME(0x10001CC0u))(a0, a1); }
XI_ORIG char sub_10001E70(void * a0) { return reinterpret_cast<char (__cdecl *)(void *)>(XI_GAME(0x10001E70u))(a0); }
XI_ORIG unsigned long long Gfx_CopySurfaceRectToTexture(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4) {
    uint32_t xs[4] = {a0.bits, a1.bits, a2.bits, a3.bits}; uint32_t ra = a4.bits, rc = 0, rd = 0;
    __asm__ volatile("pushl 12(%%esi)\n\t""pushl 8(%%esi)\n\t""pushl 4(%%esi)\n\t""pushl 0(%%esi)\n\t""call *%%edi\n\t""addl $16, %%esp\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10002040u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG char Gfx_ProbeDeviceCaps(int a0, void * a1, void * a2) { return reinterpret_cast<char (__cdecl *)(int, void *, void *)>(XI_GAME(0x10002130u))(a0, a1, a2); }
XI_ORIG unsigned int sub_10002440(int a0) { return reinterpret_cast<unsigned int (__cdecl *)(int)>(XI_GAME(0x10002440u))(a0); }
XI_ORIG void sub_10002840(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x10002840u))(a0, a1); }
XI_ORIG std::codecvt_base * sub_10002E60(int a0) { return reinterpret_cast<std::codecvt_base * (__cdecl *)(int)>(XI_GAME(0x10002E60u))(a0); }
XI_ORIG _DWORD * sub_10003070(void * a0) { return reinterpret_cast<_DWORD * (__thiscall *)(void *)>(XI_GAME(0x10003070u))(a0); }
XI_ORIG char sub_10003110(void * a0, int a1, int a2, int a3, char a4, char a5) { return reinterpret_cast<char (__thiscall *)(void *, int, int, int, char, char)>(XI_GAME(0x10003110u))(a0, a1, a2, a3, a4, a5); }
XI_ORIG char Gfx_TryCreateDeviceForMode(void * a0, int a1, int a2, int a3, char a4, char a5, int a6, int a7) { return reinterpret_cast<char (__thiscall *)(void *, int, int, int, char, char, int, int)>(XI_GAME(0x100033C0u))(a0, a1, a2, a3, a4, a5, a6, a7); }
XI_ORIG uint8_t sub_10003460(void * a0, int a1, int a2, int a3) { return reinterpret_cast<uint8_t (__thiscall *)(void *, int, int, int)>(XI_GAME(0x10003460u))(a0, a1, a2, a3); }
XI_ORIG char Gfx_CreateDevice(void * a0, int a1, int a2, int a3, int a4, int a5, char a6, char a7, int a8) { return reinterpret_cast<char (__thiscall *)(void *, int, int, int, int, int, char, char, int)>(XI_GAME(0x100034B0u))(a0, a1, a2, a3, a4, a5, a6, a7, a8); }
XI_ORIG int sub_100035F0(int a0) { return reinterpret_cast<int (__thiscall *)(int)>(XI_GAME(0x100035F0u))(a0); }
XI_ORIG char sub_10003650(void * a0) { return reinterpret_cast<char (__thiscall *)(void *)>(XI_GAME(0x10003650u))(a0); }
XI_ORIG void DebugOverlay_Update(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10003710u))(a0); }
XI_ORIG unsigned long long sub_100037D0(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5, XI_ANY a6, XI_ANY a7, XI_ANY a8) {
    uint32_t xs[7] = {a1.bits, a2.bits, a3.bits, a4.bits, a5.bits, a6.bits, a7.bits}; uint32_t ra = a8.bits, rc = a0.bits, rd = 0;
    __asm__ volatile("pushl 24(%%esi)\n\t""pushl 20(%%esi)\n\t""pushl 16(%%esi)\n\t""pushl 12(%%esi)\n\t""pushl 8(%%esi)\n\t""pushl 4(%%esi)\n\t""pushl 0(%%esi)\n\t""call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x100037D0u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG void Unit10003890_DrawActorAxes(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10003890u))(a0); }
XI_ORIG void Debug_DrawTextTable(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10003B60u))(a0); }
XI_ORIG void Debug_DrawWorldText(void * a0, void * a1, int a2) { reinterpret_cast<void (__stdcall *)(void *, void *, int)>(XI_GAME(0x10003D70u))(a0, a1, a2); }
XI_ORIG int sub_10005A40(int a0) { return reinterpret_cast<int (__thiscall *)(int)>(XI_GAME(0x10005A40u))(a0); }
XI_ORIG char sub_10008830(void * a0, unsigned __int8 a1) { return reinterpret_cast<char (__thiscall *)(void *, unsigned __int8)>(XI_GAME(0x10008830u))(a0, a1); }
XI_ORIG unsigned int sub_100088F0(void * a0) { return reinterpret_cast<unsigned int (__thiscall *)(void *)>(XI_GAME(0x100088F0u))(a0); }
XI_ORIG CDx * sub_10008F90(void * a0, void * a1, void * a2) { return reinterpret_cast<CDx * (__thiscall *)(void *, void *, void *)>(XI_GAME(0x10008F90u))(a0, a1, a2); }
XI_ORIG char CDx_Initialize(void * a0) { return reinterpret_cast<char (__thiscall *)(void *)>(XI_GAME(0x100091B0u))(a0); }
XI_ORIG char sub_10009620(void * a0, int a1, int a2, int a3) { return reinterpret_cast<char (__thiscall *)(void *, int, int, int)>(XI_GAME(0x10009620u))(a0, a1, a2, a3); }
XI_ORIG int sub_10009640(void * a0, int a1, int a2, int a3, int a4) { return reinterpret_cast<int (__thiscall *)(void *, int, int, int, int)>(XI_GAME(0x10009640u))(a0, a1, a2, a3, a4); }
XI_ORIG int sub_10009670(void * a0, int a1) { return reinterpret_cast<int (__thiscall *)(void *, int)>(XI_GAME(0x10009670u))(a0, a1); }
XI_ORIG int CDx_EndClearBegin(void * a0, int a1, int a2, int a3, int a4, int a5, int a6) { return reinterpret_cast<int (__thiscall *)(void *, int, int, int, int, int, int)>(XI_GAME(0x100096B0u))(a0, a1, a2, a3, a4, a5, a6); }
XI_ORIG undefined4 CDx_EndClearBegin_v1(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5, XI_ANY a6) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x100096B0u))(a0, a1, a2, a3, a4, a5, a6); }
XI_ORIG uint8_t CDx_TestCooperativeLevel(void * a0) { return reinterpret_cast<uint8_t (__thiscall *)(void *)>(XI_GAME(0x10009710u))(a0); }
XI_ORIG int CDx_Present() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10009720u))(); }
XI_ORIG int CDx_BeginScene(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10009730u))(a0); }
XI_ORIG int CDx_EndScene(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10009740u))(a0); }
XI_ORIG int CDx_SetDefaultRenderState(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10009920u))(a0); }
XI_ORIG int sub_10009D20(int a0) { return reinterpret_cast<int (__thiscall *)(int)>(XI_GAME(0x10009D20u))(a0); }
XI_ORIG int CDx_SetViewport(void * a0, void * a1) { return reinterpret_cast<int (__thiscall *)(void *, void *)>(XI_GAME(0x10009DC0u))(a0, a1); }
XI_ORIG unsigned __int8 * sub_10009E00(void * a0) { return reinterpret_cast<unsigned __int8 * (__thiscall *)(void *)>(XI_GAME(0x10009E00u))(a0); }
XI_ORIG int sub_10009E00_2(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10009E00u))(a0); }
XI_ORIG int CDx_PushRenderTarget(void * a0, int a1, int a2, int a3) { return reinterpret_cast<int (__thiscall *)(void *, int, int, int)>(XI_GAME(0x10009E20u))(a0, a1, a2, a3); }
XI_ORIG undefined4 CDx_PushRenderTarget_v1(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10009E20u))(a0, a1, a2, a3); }
XI_ORIG int CDx_PushRenderTargetTexture_Flag1(void * a0, int a1, int a2, int a3) { return reinterpret_cast<int (__thiscall *)(void *, int, int, int)>(XI_GAME(0x10009EA0u))(a0, a1, a2, a3); }
XI_ORIG int CDx_PushRenderTargetTexture_Flag0(void * a0, int a1, int a2, int a3) { return reinterpret_cast<int (__thiscall *)(void *, int, int, int)>(XI_GAME(0x10009EE0u))(a0, a1, a2, a3); }
XI_ORIG int CDx_PushRenderTargetTexture(void * a0, int a1, int a2, int a3, void * a4, void * a5, int a6, int a7) { return reinterpret_cast<int (__thiscall *)(void *, int, int, int, void *, void *, int, int)>(XI_GAME(0x10009F20u))(a0, a1, a2, a3, a4, a5, a6, a7); }
XI_ORIG undefined4 CDx_PushRenderTargetTexture_v1(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5, XI_ANY a6, XI_ANY a7) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10009F20u))(a0, a1, a2, a3, a4, a5, a6, a7); }
XI_ORIG int CDx_SetTexture(void * a0, int a1, int a2) { return reinterpret_cast<int (__thiscall *)(void *, int, int)>(XI_GAME(0x1000A1D0u))(a0, a1, a2); }
XI_ORIG undefined4 CDx_SetTexture_v1(void * a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x1000A1D0u))(a0, a1, a2); }
XI_ORIG int sub_1000A200(void * a0, int a1, int a2) { return reinterpret_cast<int (__thiscall *)(void *, int, int)>(XI_GAME(0x1000A200u))(a0, a1, a2); }
XI_ORIG int sub_1000A230(void * a0, int a1, int a2) { return reinterpret_cast<int (__thiscall *)(void *, int, int)>(XI_GAME(0x1000A230u))(a0, a1, a2); }
XI_ORIG int sub_1000A290(void * a0, int a1, int a2) { return reinterpret_cast<int (__thiscall *)(void *, int, int)>(XI_GAME(0x1000A290u))(a0, a1, a2); }
XI_ORIG int sub_1000A2B0(int a0, int a1, int a2, int a3, int a4) { return reinterpret_cast<int (__thiscall *)(int, int, int, int, int)>(XI_GAME(0x1000A2B0u))(a0, a1, a2, a3, a4); }
XI_ORIG int CDx_EndAndClearBegin(void * a0, int a1, int a2, int a3, int a4) { return reinterpret_cast<int (__thiscall *)(void *, int, int, int, int)>(XI_GAME(0x1000A390u))(a0, a1, a2, a3, a4); }
XI_ORIG int CDx_DrawScreenQuadAtDepth(void * a0, int a1, int a2) { return reinterpret_cast<int (__thiscall *)(void *, int, int)>(XI_GAME(0x1000A3B0u))(a0, a1, a2); }
XI_ORIG int CDx_DrawTextureToViewport(void * a0, int a1, int a2, int a3) { return reinterpret_cast<int (__thiscall *)(void *, int, int, int)>(XI_GAME(0x1000A4F0u))(a0, a1, a2, a3); }
XI_ORIG void CDx_DrawTexturedScreenQuadUnit(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1000A550u))(a0, a1, a2, a3, a4); }
XI_ORIG int CDx_DrawTexturedScreenQuad(void * a0, int a1, int a2, int a3, int a4, int a5) { return reinterpret_cast<int (__thiscall *)(void *, int, int, int, int, int)>(XI_GAME(0x1000A5A0u))(a0, a1, a2, a3, a4, a5); }
XI_ORIG void CDx_DrawTexturedScreenQuad_v1(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1000A5A0u))(a0, a1, a2, a3, a4, a5); }
XI_ORIG _DWORD * CDx_CreateTexture(void * a0, unsigned __int16 a1, unsigned __int16 a2, void * a3, int a4, int a5) { return reinterpret_cast<_DWORD * (__thiscall *)(void *, unsigned __int16, unsigned __int16, void *, int, int)>(XI_GAME(0x1000A6E0u))(a0, a1, a2, a3, a4, a5); }
XI_ORIG undefined8 CDx_CreateTexture_v1(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5) { return reinterpret_cast<undefined8 (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1000A6E0u))(a0, a1, a2, a3, a4, a5); }
XI_ORIG char CDx_PushRenderTargetRet1(void * a0, int a1, int a2, int a3) { return reinterpret_cast<char (__thiscall *)(void *, int, int, int)>(XI_GAME(0x1000A800u))(a0, a1, a2, a3); }
XI_ORIG int CDx_DrawFadeQuad(void * a0, int a1, int a2) { return reinterpret_cast<int (__thiscall *)(void *, int, int)>(XI_GAME(0x1000A820u))(a0, a1, a2); }
XI_ORIG int Post_DepthBlurComposite(void * a0, int a1, int a2) { return reinterpret_cast<int (__thiscall *)(void *, int, int)>(XI_GAME(0x1000AAB0u))(a0, a1, a2); }
XI_ORIG int sub_1000ABE0(void * a0, int a1, int a2) { return reinterpret_cast<int (__thiscall *)(void *, int, int)>(XI_GAME(0x1000ABE0u))(a0, a1, a2); }
XI_ORIG int sub_1000AD70(void * a0, unsigned __int16 a1, unsigned __int16 a2) { return reinterpret_cast<int (__thiscall *)(void *, unsigned __int16, unsigned __int16)>(XI_GAME(0x1000AD70u))(a0, a1, a2); }
XI_ORIG char sub_1000AE40(void * a0, float a1, float a2, int a3) { return reinterpret_cast<char (__thiscall *)(void *, float, float, int)>(XI_GAME(0x1000AE40u))(a0, a1, a2, a3); }
XI_ORIG void sub_1000BB10() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x1000BB10u))(); }
XI_ORIG void sub_1000BB20() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x1000BB20u))(); }
XI_ORIG char CDx_DrawStereoOddFrameOverlay(void * a0, int a1) { return reinterpret_cast<char (__thiscall *)(void *, int)>(XI_GAME(0x1000BB90u))(a0, a1); }
XI_ORIG int CDx_SetTransform(void * a0, int a1, void * a2) { return reinterpret_cast<int (__thiscall *)(void *, int, void *)>(XI_GAME(0x1000BD50u))(a0, a1, a2); }
XI_ORIG undefined4 CDx_SetTransform_v1(void * a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x1000BD50u))(a0, a1, a2); }
XI_ORIG int sub_1000BDB0(void * a0, int a1, void * a2) { return reinterpret_cast<int (__thiscall *)(void *, int, void *)>(XI_GAME(0x1000BDB0u))(a0, a1, a2); }
XI_ORIG undefined4 sub_1000BDB0_2(void * a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x1000BDB0u))(a0, a1, a2); }
XI_ORIG void sub_1000BDB0_3(void * a0, XI_ANY a1, XI_ANY a2) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x1000BDB0u))(a0, a1, a2); }
XI_ORIG int sub_1000BE10(int a0, int a1) { return reinterpret_cast<int (__thiscall *)(int, int)>(XI_GAME(0x1000BE10u))(a0, a1); }
XI_ORIG char sub_1000BE50(void * a0, void * a1) { return reinterpret_cast<char (__thiscall *)(void *, void *)>(XI_GAME(0x1000BE50u))(a0, a1); }
XI_ORIG int CDx_SetLight(void * a0, int a1, void * a2) { return reinterpret_cast<int (__thiscall *)(void *, int, void *)>(XI_GAME(0x1000BF30u))(a0, a1, a2); }
XI_ORIG undefined4 CDx_SetLight_v1(void * a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x1000BF30u))(a0, a1, a2); }
XI_ORIG int CDx_CompositeSceneToBackBuffer(void * a0, int a1, int a2, int a3, int a4) { return reinterpret_cast<int (__thiscall *)(void *, int, int, int, int)>(XI_GAME(0x1000C0B0u))(a0, a1, a2, a3, a4); }
XI_ORIG int CDx_CreateStereoResources(void * a0, unsigned __int16 a1, unsigned __int16 a2) { return reinterpret_cast<int (__thiscall *)(void *, unsigned __int16, unsigned __int16)>(XI_GAME(0x1000C6E0u))(a0, a1, a2); }
XI_ORIG int sub_1000C7C0(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x1000C7C0u))(a0); }
XI_ORIG int CDx_CreateRampTexture1x16(void * a0, int a1) { return reinterpret_cast<int (__thiscall *)(void *, int)>(XI_GAME(0x1000C850u))(a0, a1); }
XI_ORIG char CDx_CreateRampTextures1024x2(void * a0, void * a1, int a2) { return reinterpret_cast<char (__thiscall *)(void *, void *, int)>(XI_GAME(0x1000C900u))(a0, a1, a2); }
XI_ORIG char CDx_GetStereoSecondEyeTarget(void * a0, int a1, int a2) { return reinterpret_cast<char (__thiscall *)(void *, int, int)>(XI_GAME(0x1000CA00u))(a0, a1, a2); }
XI_ORIG int CDx_DrawPrimitive(void * a0, int a1, int a2, int a3) { return reinterpret_cast<int (__thiscall *)(void *, int, int, int)>(XI_GAME(0x1000CB20u))(a0, a1, a2, a3); }
XI_ORIG undefined4 CDx_DrawPrimitive_v1(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1000CB20u))(a0, a1, a2, a3); }
XI_ORIG int CDx_DrawIndexedPrimitive(void * a0, int a1, int a2, int a3, int a4, int a5) { return reinterpret_cast<int (__thiscall *)(void *, int, int, int, int, int)>(XI_GAME(0x1000CC00u))(a0, a1, a2, a3, a4, a5); }
XI_ORIG int CDx_DrawPrimitiveUP(void * a0, int a1, int a2, int a3, int a4) { return reinterpret_cast<int (__thiscall *)(void *, int, int, int, int)>(XI_GAME(0x1000CD00u))(a0, a1, a2, a3, a4); }
XI_ORIG undefined4 CDx_DrawPrimitiveUP_v1(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1000CD00u))(a0, a1, a2, a3, a4); }
XI_ORIG void CDx_ApplyStereoEyeProjection(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1000CF20u))(a0); }
XI_ORIG int CDx_RestoreProjection(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x1000CF90u))(a0); }
XI_ORIG _DWORD * sub_1000CFB0(void * a0) { return reinterpret_cast<_DWORD * (__thiscall *)(void *)>(XI_GAME(0x1000CFB0u))(a0); }
XI_ORIG char sub_1000D3F0(int a0, int a1) { return reinterpret_cast<char (__thiscall *)(int, int)>(XI_GAME(0x1000D3F0u))(a0, a1); }
XI_ORIG void sub_1000D620() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x1000D620u))(); }
XI_ORIG char sub_1000D660(void * a0) { return reinterpret_cast<char (__thiscall *)(void *)>(XI_GAME(0x1000D660u))(a0); }
XI_ORIG undefined4 sub_1000D660_2(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x1000D660u))(a0); }
XI_ORIG int sub_10010520() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10010520u))(); }
XI_ORIG char * sub_10010700(void * a0) { return reinterpret_cast<char * (__thiscall *)(void *)>(XI_GAME(0x10010700u))(a0); }
XI_ORIG __int16 sub_10010CE0(void * a0, __int16 a1) { return reinterpret_cast<__int16 (__thiscall *)(void *, __int16)>(XI_GAME(0x10010CE0u))(a0, a1); }
XI_ORIG void sub_10010D00(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10010D00u))(a0); }
XI_ORIG char App_InitScene(int a0, int a1) { return reinterpret_cast<char (__thiscall *)(int, int)>(XI_GAME(0x10010D20u))(a0, a1); }
XI_ORIG undefined4 Frame_Render(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x10011A00u))(a0); }
XI_ORIG int Post_Afterimage() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10012F40u))(); }
XI_ORIG int Post_FlashAndZoomFeedback(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x100132B0u))(a0); }
XI_ORIG char sub_100139E0(void * a0) { return reinterpret_cast<char (__thiscall *)(void *)>(XI_GAME(0x100139E0u))(a0); }
XI_ORIG char App_StepGameState5Connect(int a0, int a1) { return reinterpret_cast<char (__thiscall *)(int, int)>(XI_GAME(0x10013AD0u))(a0, a1); }
XI_ORIG char sub_10013DF0(void * a0) { return reinterpret_cast<char (__thiscall *)(void *)>(XI_GAME(0x10013DF0u))(a0); }
XI_ORIG char sub_10013F10(void * a0) { return reinterpret_cast<char (__thiscall *)(void *)>(XI_GAME(0x10013F10u))(a0); }
XI_ORIG char sub_10014030(void * a0) { return reinterpret_cast<char (__thiscall *)(void *)>(XI_GAME(0x10014030u))(a0); }
XI_ORIG uint8_t sub_10014120() { return reinterpret_cast<uint8_t (__cdecl *)()>(XI_GAME(0x10014120u))(); }
XI_ORIG char App_DispatchSubState(void * a0) { return reinterpret_cast<char (__thiscall *)(void *)>(XI_GAME(0x10014170u))(a0); }
XI_ORIG undefined4 sub_100141C0(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x100141C0u))(a0); }
XI_ORIG unsigned long long sub_10014200(XI_ANY a0, XI_ANY a1) {
    uint32_t xs[1] = {0}; uint32_t ra = a1.bits, rc = a0.bits, rd = 0;
    __asm__ volatile("call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10014200u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG undefined4 sub_100142A0(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x100142A0u))(a0); }
XI_ORIG undefined4 sub_100142B0() { return reinterpret_cast<undefined4 (__cdecl *)()>(XI_GAME(0x100142B0u))(); }
XI_ORIG undefined4 Unit10014350_RunStepThenLoadAll(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x10014350u))(a0); }
XI_ORIG undefined4 sub_10014390(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x10014390u))(a0); }
XI_ORIG char sub_100149B0(void * a0) { return reinterpret_cast<char (__thiscall *)(void *)>(XI_GAME(0x100149B0u))(a0); }
XI_ORIG uint8_t sub_10014A20(void * a0) { return reinterpret_cast<uint8_t (__thiscall *)(void *)>(XI_GAME(0x10014A20u))(a0); }
XI_ORIG char sub_10014A30(int a0) { return reinterpret_cast<char (__thiscall *)(int)>(XI_GAME(0x10014A30u))(a0); }
XI_ORIG char sub_10014AD0(void * a0) { return reinterpret_cast<char (__thiscall *)(void *)>(XI_GAME(0x10014AD0u))(a0); }
XI_ORIG uint8_t Camera_ReleaseAll(void * a0) { return reinterpret_cast<uint8_t (__thiscall *)(void *)>(XI_GAME(0x10014C10u))(a0); }
XI_ORIG void sub_10014C60() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x10014C60u))(); }
XI_ORIG undefined4 sub_10014CB0_2() { return reinterpret_cast<undefined4 (__cdecl *)()>(XI_GAME(0x10014CB0u))(); }
XI_ORIG double sub_10014CF0() { return reinterpret_cast<double (__cdecl *)()>(XI_GAME(0x10014CF0u))(); }
XI_ORIG long double sub_10014CF0_2(XI_ANY a0) {
    uint32_t xs[1] = {0}; uint32_t ra = a0.bits, rc = 0, rd = 0; long double st0;
    __asm__ volatile("call *%%edi\n\t"
        : "=t"(st0), "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10014CF0u)) : "memory", "cc", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return st0;
}
XI_ORIG long double sub_10014CF0_3() { return reinterpret_cast<long double (__cdecl *)()>(XI_GAME(0x10014CF0u))(); }
XI_ORIG int sub_10014D50() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10014D50u))(); }
XI_ORIG double sub_10014D70() { return reinterpret_cast<double (__cdecl *)()>(XI_GAME(0x10014D70u))(); }
XI_ORIG double sub_10014D80() { return reinterpret_cast<double (__cdecl *)()>(XI_GAME(0x10014D80u))(); }
XI_ORIG unsigned int sub_10014D90(unsigned __int8 a0, unsigned __int8 a1, unsigned __int8 a2) { return reinterpret_cast<unsigned int (__cdecl *)(unsigned __int8, unsigned __int8, unsigned __int8)>(XI_GAME(0x10014D90u))(a0, a1, a2); }
XI_ORIG void sub_100150D0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15) { reinterpret_cast<void (__cdecl *)(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int)>(XI_GAME(0x100150D0u))(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); }
XI_ORIG void sub_100151F0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15) { reinterpret_cast<void (__cdecl *)(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int)>(XI_GAME(0x100151F0u))(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); }
XI_ORIG char * sub_10015220() { return reinterpret_cast<char * (__cdecl *)()>(XI_GAME(0x10015220u))(); }
XI_ORIG int sub_10015220_2() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10015220u))(); }
XI_ORIG char * sub_10015240() { return reinterpret_cast<char * (__cdecl *)()>(XI_GAME(0x10015240u))(); }
XI_ORIG int sub_10015250() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10015250u))(); }
XI_ORIG undefined4 sub_10015250_2() { return reinterpret_cast<undefined4 (__cdecl *)()>(XI_GAME(0x10015250u))(); }
XI_ORIG char * sub_10015270() { return reinterpret_cast<char * (__cdecl *)()>(XI_GAME(0x10015270u))(); }
XI_ORIG std::codecvt_base * sub_10015360(int a0) { return reinterpret_cast<std::codecvt_base * (__cdecl *)(int)>(XI_GAME(0x10015360u))(a0); }
XI_ORIG std::codecvt_base * sub_100153A0(float a0, float a1) { return reinterpret_cast<std::codecvt_base * (__cdecl *)(float, float)>(XI_GAME(0x100153A0u))(a0, a1); }
XI_ORIG void Camera_ApplyViewProjection() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x10015510u))(); }
XI_ORIG undefined4 sub_10015600() { return reinterpret_cast<undefined4 (__cdecl *)()>(XI_GAME(0x10015600u))(); }
XI_ORIG undefined4 sub_10015610() { return reinterpret_cast<undefined4 (__cdecl *)()>(XI_GAME(0x10015610u))(); }
XI_ORIG __int16 sub_10015680() { return reinterpret_cast<__int16 (__cdecl *)()>(XI_GAME(0x10015680u))(); }
XI_ORIG __int16 sub_10015690() { return reinterpret_cast<__int16 (__cdecl *)()>(XI_GAME(0x10015690u))(); }
XI_ORIG int sub_100156A0(int a0, int a1, void * a2, void * a3) { return reinterpret_cast<int (__cdecl *)(int, int, void *, void *)>(XI_GAME(0x100156A0u))(a0, a1, a2, a3); }
XI_ORIG uint8_t sub_10015740() { return reinterpret_cast<uint8_t (__cdecl *)()>(XI_GAME(0x10015740u))(); }
XI_ORIG undefined4 sub_100157E0(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x100157E0u))(a0, a1); }
XI_ORIG undefined4 App_CreateRendererAndApp() { return reinterpret_cast<undefined4 (__cdecl *)()>(XI_GAME(0x100161B0u))(); }
XI_ORIG void App_RunMainLoopThenSetPtr() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x10016300u))(); }
XI_ORIG void App_DestroyGlobalObjects() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x10016320u))(); }
XI_ORIG char sub_100163C0(char a0) { return reinterpret_cast<char (__cdecl *)(char)>(XI_GAME(0x100163C0u))(a0); }
XI_ORIG char sub_100163E0(char a0) { return reinterpret_cast<char (__cdecl *)(char)>(XI_GAME(0x100163E0u))(a0); }
XI_ORIG int sub_10016400(int a0) { return reinterpret_cast<int (__cdecl *)(int)>(XI_GAME(0x10016400u))(a0); }
XI_ORIG int sub_10016410() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10016410u))(); }
XI_ORIG undefined4 sub_10016410_2() { return reinterpret_cast<undefined4 (__cdecl *)()>(XI_GAME(0x10016410u))(); }
XI_ORIG int sub_100164C0(int a0) { return reinterpret_cast<int (__cdecl *)(int)>(XI_GAME(0x100164C0u))(a0); }
XI_ORIG int sub_10016560(void * a0, void * a1) { return reinterpret_cast<int (__cdecl *)(void *, void *)>(XI_GAME(0x10016560u))(a0, a1); }
XI_ORIG __int64 sub_10017160(void * a0) { return reinterpret_cast<__int64 (__thiscall *)(void *)>(XI_GAME(0x10017160u))(a0); }
XI_ORIG void GammaRamp_ApplyIfChanged(int a0) { reinterpret_cast<void (__thiscall *)(int)>(XI_GAME(0x10017230u))(a0); }
XI_ORIG int CShader_Destructor(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x100177A0u))(a0); }
XI_ORIG exception * sub_10017BB0(void * a0) { return reinterpret_cast<exception * (__thiscall *)(void *)>(XI_GAME(0x10017BB0u))(a0); }
XI_ORIG int Unit10017C10_Step(int a0, void * a1, void * a2, int a3) { return reinterpret_cast<int (__thiscall *)(int, void *, void *, int)>(XI_GAME(0x10017C20u))(a0, a1, a2, a3); }
XI_ORIG undefined4 Unit10017C10_Begin(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10017C60u))(a0, a1, a2, a3); }
template <class... R> XI_ORIG int sub_10017D20(void * a0, R... rest) { return reinterpret_cast<int (__cdecl *)(void *, ...)>(XI_GAME(0x10017D20u))(a0, rest...); }
template <class... R> XI_ORIG void sub_10017D20_2(XI_ANY a0, R... rest) { reinterpret_cast<void (__cdecl *)(XI_ANY, decltype(XI_ANY(rest))...)>(XI_GAME(0x10017D20u))(a0, XI_ANY(rest)...); }
template <class... R> XI_ORIG int sub_10017D30(void * a0, R... rest) { return reinterpret_cast<int (__cdecl *)(void *, ...)>(XI_GAME(0x10017D30u))(a0, rest...); }
template <class... R> XI_ORIG void sub_10017D30_2(XI_ANY a0, R... rest) { reinterpret_cast<void (__cdecl *)(XI_ANY, decltype(XI_ANY(rest))...)>(XI_GAME(0x10017D30u))(a0, XI_ANY(rest)...); }
XI_ORIG void sub_10017D50_2() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x10017D50u))(); }
XI_ORIG void sub_100182E0(int a0) { reinterpret_cast<void (__cdecl *)(int)>(XI_GAME(0x100182E0u))(a0); }
XI_ORIG _DWORD * sub_10018430(void * a0) { return reinterpret_cast<_DWORD * (__thiscall *)(void *)>(XI_GAME(0x10018430u))(a0); }
XI_ORIG void sub_100185A0(void * a0, void * a1, unsigned int a2) { reinterpret_cast<void (__thiscall *)(void *, void *, unsigned int)>(XI_GAME(0x100185A0u))(a0, a1, a2); }
XI_ORIG char sub_10018850(int a0) { return reinterpret_cast<char (__thiscall *)(int)>(XI_GAME(0x10018850u))(a0); }
XI_ORIG MMRESULT sub_10019140() { return reinterpret_cast<MMRESULT (__cdecl *)()>(XI_GAME(0x10019140u))(); }
XI_ORIG MMRESULT sub_100191B0() { return reinterpret_cast<MMRESULT (__cdecl *)()>(XI_GAME(0x100191B0u))(); }
XI_ORIG _DWORD * sub_100191D0() { return reinterpret_cast<_DWORD * (__cdecl *)()>(XI_GAME(0x100191D0u))(); }
XI_ORIG unsigned long long sub_1001B7B0(XI_ANY a0, XI_ANY a1) {
    uint32_t xs[1] = {0}; uint32_t ra = a1.bits, rc = a0.bits, rd = 0;
    __asm__ volatile("call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x1001B7B0u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG _DWORD * Model_CreateTranslucentTargets() { return reinterpret_cast<_DWORD * (__cdecl *)()>(XI_GAME(0x1001D0A0u))(); }
XI_ORIG void sub_1001D170(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1001D170u))(a0); }
XI_ORIG char Model_BeginTranslucentPass(int a0) { return reinterpret_cast<char (__thiscall *)(int)>(XI_GAME(0x1001D240u))(a0); }
XI_ORIG char Model_TranslucentUnbindTexture(void * a0) { return reinterpret_cast<char (__thiscall *)(void *)>(XI_GAME(0x1001D350u))(a0); }
XI_ORIG int sub_1001D390(int a0, char a1) { return reinterpret_cast<int (__stdcall *)(int, char)>(XI_GAME(0x1001D390u))(a0, a1); }
XI_ORIG int Model_CompositeTranslucentPass(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x1001D3B0u))(a0); }
XI_ORIG void sub_1001D8E0(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x1001D8E0u))(a0, a1); }
XI_ORIG int Gfx_DrawScreenQuad256(int a0, int a1) { return reinterpret_cast<int (__stdcall *)(int, int)>(XI_GAME(0x1001DD00u))(a0, a1); }
XI_ORIG unsigned int sub_1001E0A0(void * a0, int a1, int a2) { return reinterpret_cast<unsigned int (__thiscall *)(void *, int, int)>(XI_GAME(0x1001E0A0u))(a0, a1, a2); }
XI_ORIG undefined4 sub_1001E470() { return reinterpret_cast<undefined4 (__cdecl *)()>(XI_GAME(0x1001E470u))(); }
XI_ORIG undefined4 sub_1001E780(void * a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x1001E780u))(a0, a1); }
XI_ORIG void sub_10021680(void * a0, XI_ANY a1, XI_ANY a2) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x10021680u))(a0, a1, a2); }
XI_ORIG _BYTE * sub_10022230(void * a0) { return reinterpret_cast<_BYTE * (__thiscall *)(void *)>(XI_GAME(0x10022230u))(a0); }
XI_ORIG undefined4 sub_10022470(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x10022470u))(a0); }
XI_ORIG char CYyModelDt_PrepareRenderState(void * a0, int a1, int a2, int a3, int a4, int a5) { return reinterpret_cast<char (__thiscall *)(void *, int, int, int, int, int)>(XI_GAME(0x100224D0u))(a0, a1, a2, a3, a4, a5); }
XI_ORIG void Unit10025220_Init(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10025260u))(a0); }
XI_ORIG char ProjTex_BeginPass(void * a0, void * a1, int a2, void * a3) { return reinterpret_cast<char (__thiscall *)(void *, void *, int, void *)>(XI_GAME(0x10025330u))(a0, a1, a2, a3); }
XI_ORIG int ProjTex_EndPass(void * a0, int a1) { return reinterpret_cast<int (__thiscall *)(void *, int)>(XI_GAME(0x100255C0u))(a0, a1); }
XI_ORIG int sub_10025860(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10025860u))(a0); }
XI_ORIG int ProjTex_CaptureToTarget(void * a0, int a1, int a2, int a3, int a4) { return reinterpret_cast<int (__thiscall *)(void *, int, int, int, int)>(XI_GAME(0x10025870u))(a0, a1, a2, a3, a4); }
XI_ORIG int sub_10025BD0() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10025BD0u))(); }
XI_ORIG void sub_10025BF0(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10025BF0u))(a0); }
XI_ORIG char EnvMap_BeginPass(void * a0, int a1, void * a2) { return reinterpret_cast<char (__stdcall *)(void *, int, void *)>(XI_GAME(0x10025C40u))(a0, a1, a2); }
XI_ORIG int EnvMap_EndPass(int a0) { return reinterpret_cast<int (__stdcall *)(int)>(XI_GAME(0x10025F70u))(a0); }
XI_ORIG int sub_10026210(int a0, int a1, int a2, int a3) { return reinterpret_cast<int (__stdcall *)(int, int, int, int)>(XI_GAME(0x10026210u))(a0, a1, a2, a3); }
XI_ORIG int * sub_10026890(void * a0, int a1, void * a2, int a3) { return reinterpret_cast<int * (__thiscall *)(void *, int, void *, int)>(XI_GAME(0x10026890u))(a0, a1, a2, a3); }
XI_ORIG void CXiMovie_Draw(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10026AD0u))(a0, a1, a2, a3, a4, a5); }
XI_ORIG int CYyIcon_DrawSubRect(void * a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9) { return reinterpret_cast<int (__thiscall *)(void *, int, int, int, int, int, int, int, int, int)>(XI_GAME(0x10026C70u))(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9); }
XI_ORIG _DWORD * sub_10026E00(void * a0) { return reinterpret_cast<_DWORD * (__cdecl *)(void *)>(XI_GAME(0x10026E00u))(a0); }
XI_ORIG int sub_10026E30(int a0, float a1, int a2, int a3, int a4) { return reinterpret_cast<int (__cdecl *)(int, float, int, int, int)>(XI_GAME(0x10026E30u))(a0, a1, a2, a3, a4); }
XI_ORIG void sub_10026E30_2(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10026E30u))(a0, a1, a2, a3, a4); }
XI_ORIG int sub_10026E90(void * a0, void * a1) { return reinterpret_cast<int (__cdecl *)(void *, void *)>(XI_GAME(0x10026E90u))(a0, a1); }
XI_ORIG int sub_10026EB0(void * a0, void * a1) { return reinterpret_cast<int (__cdecl *)(void *, void *)>(XI_GAME(0x10026EB0u))(a0, a1); }
XI_ORIG undefined4 sub_10026EB0_2(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x10026EB0u))(a0, a1); }
XI_ORIG float * sub_10026F20(void * a0, void * a1) { return reinterpret_cast<float * (__cdecl *)(void *, void *)>(XI_GAME(0x10026F20u))(a0, a1); }
XI_ORIG float * sub_10026F50(void * a0, void * a1) { return reinterpret_cast<float * (__cdecl *)(void *, void *)>(XI_GAME(0x10026F50u))(a0, a1); }
XI_ORIG float * sub_10026FA0(void * a0, void * a1, void * a2) { return reinterpret_cast<float * (__cdecl *)(void *, void *, void *)>(XI_GAME(0x10026FA0u))(a0, a1, a2); }
XI_ORIG float * sub_10026FD0(void * a0, void * a1, void * a2) { return reinterpret_cast<float * (__cdecl *)(void *, void *, void *)>(XI_GAME(0x10026FD0u))(a0, a1, a2); }
XI_ORIG float * sub_10027020(void * a0, float a1) { return reinterpret_cast<float * (__cdecl *)(void *, float)>(XI_GAME(0x10027020u))(a0, a1); }
XI_ORIG float * sub_10027050(void * a0, float a1) { return reinterpret_cast<float * (__cdecl *)(void *, float)>(XI_GAME(0x10027050u))(a0, a1); }
XI_ORIG float * sub_10027120(void * a0, void * a1, void * a2) { return reinterpret_cast<float * (__cdecl *)(void *, void *, void *)>(XI_GAME(0x10027120u))(a0, a1, a2); }
XI_ORIG undefined4 sub_10027120_2(XI_ANY a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10027120u))(a0, a1, a2); }
XI_ORIG int sub_100272B0_2(int a0, float a1) { return reinterpret_cast<int (__cdecl *)(int, float)>(XI_GAME(0x100272B0u))(a0, a1); }
XI_ORIG float * sub_100272E0(void * a0, void * a1, float a2) { return reinterpret_cast<float * (__cdecl *)(void *, void *, float)>(XI_GAME(0x100272E0u))(a0, a1, a2); }
XI_ORIG float * sub_10027340(void * a0, void * a1, void * a2) { return reinterpret_cast<float * (__cdecl *)(void *, void *, void *)>(XI_GAME(0x10027340u))(a0, a1, a2); }
XI_ORIG void sub_10027340_3(XI_ANY a0, XI_ANY a1, XI_ANY a2) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10027340u))(a0, a1, a2); }
XI_ORIG void sub_100274B0(void * a0) { reinterpret_cast<void (__cdecl *)(void *)>(XI_GAME(0x100274B0u))(a0); }
XI_ORIG void sub_100276F0(void * a0, void * a1) { reinterpret_cast<void (__cdecl *)(void *, void *)>(XI_GAME(0x100276F0u))(a0, a1); }
XI_ORIG void sub_100276F0_2(XI_ANY a0, XI_ANY a1) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x100276F0u))(a0, a1); }
XI_ORIG float * sub_100278E0(void * a0) { return reinterpret_cast<float * (__cdecl *)(void *)>(XI_GAME(0x100278E0u))(a0); }
XI_ORIG void sub_100278E0_2(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x100278E0u))(a0); }
XI_ORIG undefined4 sub_10027990_2(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x10027990u))(a0); }
XI_ORIG Iostream_init * sub_10027990_3(void * a0) { return reinterpret_cast<Iostream_init * (__thiscall *)(void *)>(XI_GAME(0x10027990u))(a0); }
XI_ORIG void sub_100279A0() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x100279A0u))(); }
XI_ORIG int sub_100279B0(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x100279B0u))(a0); }
XI_ORIG void sub_100279B0_2(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x100279B0u))(a0); }
XI_ORIG undefined4 sub_100279B0_3(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x100279B0u))(a0); }
XI_ORIG int sub_100279F0(void * a0, void * a1) { return reinterpret_cast<int (__thiscall *)(void *, void *)>(XI_GAME(0x100279F0u))(a0, a1); }
XI_ORIG int sub_10027AE0(void * a0, void * a1) { return reinterpret_cast<int (__thiscall *)(void *, void *)>(XI_GAME(0x10027AE0u))(a0, a1); }
XI_ORIG int sub_10027B30(void * a0, void * a1) { return reinterpret_cast<int (__thiscall *)(void *, void *)>(XI_GAME(0x10027B30u))(a0, a1); }
XI_ORIG int sub_10027B80(void * a0, float a1) { return reinterpret_cast<int (__thiscall *)(void *, float)>(XI_GAME(0x10027B80u))(a0, a1); }
XI_ORIG void sub_10027B80_2(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x10027B80u))(a0, a1); }
XI_ORIG int sub_10027BD0(void * a0, float a1) { return reinterpret_cast<int (__thiscall *)(void *, float)>(XI_GAME(0x10027BD0u))(a0, a1); }
XI_ORIG void sub_10027BD0_2(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x10027BD0u))(a0, a1); }
XI_ORIG int sub_10027C20(void * a0, float a1) { return reinterpret_cast<int (__thiscall *)(void *, float)>(XI_GAME(0x10027C20u))(a0, a1); }
XI_ORIG void sub_10027C20_2(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x10027C20u))(a0, a1); }
XI_ORIG int sub_10027CD0(void * a0, void * a1) { return reinterpret_cast<int (__thiscall *)(void *, void *)>(XI_GAME(0x10027CD0u))(a0, a1); }
XI_ORIG int sub_10027CF0(void * a0, void * a1) { return reinterpret_cast<int (__thiscall *)(void *, void *)>(XI_GAME(0x10027CF0u))(a0, a1); }
XI_ORIG undefined4 sub_10027CF0_2(void * a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x10027CF0u))(a0, a1); }
XI_ORIG void sub_10027CF0_3(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x10027CF0u))(a0, a1); }
XI_ORIG int sub_10027D10(int a0, int a1) { return reinterpret_cast<int (__thiscall *)(int, int)>(XI_GAME(0x10027D10u))(a0, a1); }
XI_ORIG int sub_10027E90(void * a0, void * a1) { return reinterpret_cast<int (__thiscall *)(void *, void *)>(XI_GAME(0x10027E90u))(a0, a1); }
XI_ORIG _BYTE * sub_10027F60(void * a0, int a1) { return reinterpret_cast<_BYTE * (__thiscall *)(void *, int)>(XI_GAME(0x10027F60u))(a0, a1); }
XI_ORIG float * sub_10028200(void * a0, void * a1) { return reinterpret_cast<float * (__thiscall *)(void *, void *)>(XI_GAME(0x10028200u))(a0, a1); }
XI_ORIG float * sub_10028290(void * a0, void * a1) { return reinterpret_cast<float * (__thiscall *)(void *, void *)>(XI_GAME(0x10028290u))(a0, a1); }
XI_ORIG float * sub_100282C0(void * a0, void * a1, void * a2) { return reinterpret_cast<float * (__thiscall *)(void *, void *, void *)>(XI_GAME(0x100282C0u))(a0, a1, a2); }
XI_ORIG int sub_100283C0(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x100283C0u))(a0); }
XI_ORIG _DWORD * sub_10028640(int a0, int a1) { return reinterpret_cast<_DWORD * (__cdecl *)(int, int)>(XI_GAME(0x10028640u))(a0, a1); }
XI_ORIG undefined4 * sub_10028640_2(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 * (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x10028640u))(a0, a1); }
XI_ORIG _DWORD * sub_100286B0(int a0, int a1) { return reinterpret_cast<_DWORD * (__cdecl *)(int, int)>(XI_GAME(0x100286B0u))(a0, a1); }
XI_ORIG _DWORD * sub_10028700(int a0) { return reinterpret_cast<_DWORD * (__cdecl *)(int)>(XI_GAME(0x10028700u))(a0); }
XI_ORIG void sub_10028700_2(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x10028700u))(a0); }
XI_ORIG int sub_10028710(int a0) { return reinterpret_cast<int (__cdecl *)(int)>(XI_GAME(0x10028710u))(a0); }
XI_ORIG void sub_10028710_2(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x10028710u))(a0); }
XI_ORIG int sub_10028B90(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10028B90u))(a0); }
XI_ORIG _DWORD * sub_10028FD0(int a0, int a1) { return reinterpret_cast<_DWORD * (__cdecl *)(int, int)>(XI_GAME(0x10028FD0u))(a0, a1); }
XI_ORIG undefined4 * sub_10028FD0_3(XI_ANY a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<undefined4 * (__cdecl *)(XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10028FD0u))(a0, a1, a2); }
XI_ORIG undefined4 sub_10029220(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x10029220u))(a0); }
XI_ORIG undefined4 sub_10029290(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x10029290u))(a0); }
XI_ORIG int CreateSharedVertexBuffers() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10029A50u))(); }
XI_ORIG void sub_10029B60() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x10029B60u))(); }
XI_ORIG char * sub_10029E70(void * a0) { return reinterpret_cast<char * (__thiscall *)(void *)>(XI_GAME(0x10029E70u))(a0); }
XI_ORIG int CYyModelBase_DrawLit(int a0, int a1, int a2, int a3) { return reinterpret_cast<int (__thiscall *)(int, int, int, int)>(XI_GAME(0x1002A3B0u))(a0, a1, a2, a3); }
XI_ORIG char * CYyModel_Constructor(void * a0) { return reinterpret_cast<char * (__thiscall *)(void *)>(XI_GAME(0x1002B4B0u))(a0); }
XI_ORIG int sub_1002B550(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x1002B550u))(a0); }
XI_ORIG char * sub_1002B5A0(void * a0) { return reinterpret_cast<char * (__thiscall *)(void *)>(XI_GAME(0x1002B5A0u))(a0); }
XI_ORIG int sub_1002B5A0_2(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x1002B5A0u))(a0); }
XI_ORIG undefined4 sub_1002B6A0(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x1002B6A0u))(a0); }
XI_ORIG char CXiSkeletonActor_DrawModel(int a0, void * a1, void * a2, int a3, void * a4, int a5, int a6, unsigned int a7) { return reinterpret_cast<char (__thiscall *)(int, void *, void *, int, void *, int, int, unsigned int)>(XI_GAME(0x1002B6E0u))(a0, a1, a2, a3, a4, a5, a6, a7); }
XI_ORIG char sub_1002C2D0(int a0, void * a1, void * a2, int a3, void * a4) { return reinterpret_cast<char (__thiscall *)(int, void *, void *, int, void *)>(XI_GAME(0x1002C2D0u))(a0, a1, a2, a3, a4); }
XI_ORIG void CXiSkeletonActor_PrepareModelsOnce(int a0, int a1, int a2) { reinterpret_cast<void (__thiscall *)(int, int, int)>(XI_GAME(0x1002C360u))(a0, a1, a2); }
XI_ORIG _DWORD * sub_1002C890(int a0) { return reinterpret_cast<_DWORD * (__cdecl *)(int)>(XI_GAME(0x1002C890u))(a0); }
XI_ORIG undefined4 sub_1002C890_2(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x1002C890u))(a0); }
XI_ORIG int sub_1002C8B0(int a0) { return reinterpret_cast<int (__cdecl *)(int)>(XI_GAME(0x1002C8B0u))(a0); }
XI_ORIG void sub_1002C8B0_2(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x1002C8B0u))(a0); }
XI_ORIG undefined4 sub_1002C8B0_4(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x1002C8B0u))(a0); }
XI_ORIG undefined8 sub_1002C8F0(void * a0, XI_ANY a1) { return reinterpret_cast<undefined8 (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x1002C8F0u))(a0, a1); }
XI_ORIG void * CYyOs2VtxBuffer_Constructor(void * a0, XI_ANY a1) { return reinterpret_cast<void * (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x1002D680u))(a0, a1); }
XI_ORIG void CYyOs2VtxBuffer_CYyOs2VtxBuffer_Destructor(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1002D700u))(a0); }
XI_ORIG undefined4 Unit1002D8E0_FixOffsetsAndCreateVtxBuffer(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x1002D8F0u))(a0); }
XI_ORIG void CYyModelDt_SkinAndDrawV2(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5, XI_ANY a6) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1002DC10u))(a0, a1, a2, a3, a4, a5, a6); }
XI_ORIG int Gfx_SetStreamSourceCached(unsigned int a0, int a1, int a2) { return reinterpret_cast<int (__cdecl *)(unsigned int, int, int)>(XI_GAME(0x1002F130u))(a0, a1, a2); }
XI_ORIG undefined4 Gfx_ApplyCachedStreamSource(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x1002F160u))(a0); }
XI_ORIG int Gfx_ApplyCachedVertexShader() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x1002F1A0u))(); }
XI_ORIG int sub_1002F1C0(int a0) { return reinterpret_cast<int (__cdecl *)(int)>(XI_GAME(0x1002F1C0u))(a0); }
XI_ORIG _DWORD * sub_1002F1D0(void * a0) { return reinterpret_cast<_DWORD * (__thiscall *)(void *)>(XI_GAME(0x1002F1D0u))(a0); }
XI_ORIG int sub_100336B0() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x100336B0u))(); }
XI_ORIG void Unit100310A0_Construct(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10033710u))(a0); }
XI_ORIG char Model_BeginOffscreenPass(int a0, void * a1, int a2) { return reinterpret_cast<char (__thiscall *)(int, void *, int)>(XI_GAME(0x10033800u))(a0, a1, a2); }
XI_ORIG char Model_EndOffscreenPassBindTextures(void * a0, int a1) { return reinterpret_cast<char (__thiscall *)(void *, int)>(XI_GAME(0x10033A70u))(a0, a1); }
XI_ORIG char Shadow_DrawByMode(int a0, void * a1) { return reinterpret_cast<char (__thiscall *)(int, void *)>(XI_GAME(0x10033DA0u))(a0, a1); }
XI_ORIG void sub_10033EA0(void * a0, void * a1) { reinterpret_cast<void (__thiscall *)(void *, void *)>(XI_GAME(0x10033EA0u))(a0, a1); }
XI_ORIG unsigned long long sub_10035F00(XI_ANY a0, XI_ANY a1) {
    uint32_t xs[1] = {a0.bits}; uint32_t ra = a1.bits, rc = 0, rd = 0;
    __asm__ volatile("pushl 0(%%esi)\n\t""call *%%edi\n\t""addl $4, %%esp\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10035F00u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG undefined4 sub_10035F80(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x10035F80u))(a0); }
XI_ORIG unsigned long long sub_10036020(XI_ANY a0, XI_ANY a1) {
    uint32_t xs[1] = {a0.bits}; uint32_t ra = a1.bits, rc = 0, rd = 0;
    __asm__ volatile("pushl 0(%%esi)\n\t""call *%%edi\n\t""addl $4, %%esp\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10036020u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG unsigned long long sub_10036070(XI_ANY a0, XI_ANY a1) {
    uint32_t xs[1] = {a0.bits}; uint32_t ra = a1.bits, rc = 0, rd = 0;
    __asm__ volatile("pushl 0(%%esi)\n\t""call *%%edi\n\t""addl $4, %%esp\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10036070u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG int sub_100361D0() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x100361D0u))(); }
XI_ORIG char CYySoundElem_UpdateQueue() { return reinterpret_cast<char (__cdecl *)()>(XI_GAME(0x10036230u))(); }
XI_ORIG undefined4 sub_10036360(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x10036360u))(a0); }
XI_ORIG void sub_100363B0(void * a0, XI_ANY a1, XI_ANY a2) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x100363B0u))(a0, a1, a2); }
XI_ORIG undefined4 sub_10036420(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x10036420u))(a0); }
XI_ORIG void CYySoundElem_UpdateOne(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x100364A0u))(a0); }
XI_ORIG undefined4 CYySoundElem_UpdateTimerAndPosition(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x100364E0u))(a0); }
XI_ORIG undefined4 sub_100367C0(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x100367C0u))(a0); }
XI_ORIG uint32_t sub_10036C70(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5, XI_ANY a6, XI_ANY a7) { return reinterpret_cast<uint32_t (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10036C70u))(a0, a1, a2, a3, a4, a5, a6, a7); }
XI_ORIG undefined4 sub_100378B0(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x100378B0u))(a0); }
XI_ORIG void sub_10037960(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x10037960u))(a0); }
XI_ORIG void sub_10037A10() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x10037A10u))(); }
XI_ORIG undefined8 sub_10037BF0() { return reinterpret_cast<undefined8 (__cdecl *)()>(XI_GAME(0x10037BF0u))(); }
XI_ORIG unsigned long long sub_10038440(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3) {
    uint32_t xs[3] = {a0.bits, a1.bits, a2.bits}; uint32_t ra = a3.bits, rc = 0, rd = 0;
    __asm__ volatile("pushl 8(%%esi)\n\t""pushl 4(%%esi)\n\t""pushl 0(%%esi)\n\t""call *%%edi\n\t""addl $12, %%esp\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10038440u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG unsigned long long sub_10038470(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3) {
    uint32_t xs[3] = {a0.bits, a1.bits, a2.bits}; uint32_t ra = a3.bits, rc = 0, rd = 0;
    __asm__ volatile("pushl 8(%%esi)\n\t""pushl 4(%%esi)\n\t""pushl 0(%%esi)\n\t""call *%%edi\n\t""addl $12, %%esp\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10038470u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG unsigned int sub_100384B0(void * a0, int a1, int a2, char a3) { return reinterpret_cast<unsigned int (__cdecl *)(void *, int, int, char)>(XI_GAME(0x100384B0u))(a0, a1, a2, a3); }
XI_ORIG int Font_DrawPass() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10038520u))(); }
XI_ORIG unsigned __int8 * Font_DrawString(void * a0, float a1, float a2, float a3) { return reinterpret_cast<unsigned __int8 * (__cdecl *)(void *, float, float, float)>(XI_GAME(0x10038720u))(a0, a1, a2, a3); }
XI_ORIG _DWORD * Post_CreateScreenEffectTargets() { return reinterpret_cast<_DWORD * (__cdecl *)()>(XI_GAME(0x10038930u))(); }
XI_ORIG void sub_10038A20(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10038A20u))(a0); }
XI_ORIG void sub_10038A70(int a0) { reinterpret_cast<void (__stdcall *)(int)>(XI_GAME(0x10038A70u))(a0); }
XI_ORIG int Post_CaptureSceneToTarget(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10038A80u))(a0); }
XI_ORIG int Post_DrawRotatingGhostLayers(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10038E10u))(a0); }
XI_ORIG _DWORD * sub_10039410(void * a0, void * a1) { return reinterpret_cast<_DWORD * (__thiscall *)(void *, void *)>(XI_GAME(0x10039410u))(a0, a1); }
XI_ORIG int sub_10039810(void * a0, int a1) { return reinterpret_cast<int (__thiscall *)(void *, int)>(XI_GAME(0x10039810u))(a0, a1); }
XI_ORIG void sub_10039810_2(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x10039810u))(a0, a1); }
XI_ORIG void * sub_10039920(void * a0) { return reinterpret_cast<void * (__thiscall *)(void *)>(XI_GAME(0x10039920u))(a0); }
XI_ORIG char TexObj_CreateAndUpload(void * a0) { return reinterpret_cast<char (__thiscall *)(void *)>(XI_GAME(0x10039A30u))(a0); }
XI_ORIG undefined1 TexObj_CreateAndUpload_v1(void * a0) { return reinterpret_cast<undefined1 (__thiscall *)(void *)>(XI_GAME(0x10039A30u))(a0); }
XI_ORIG undefined1 TexObj_Reupload(void * a0) { return reinterpret_cast<undefined1 (__thiscall *)(void *)>(XI_GAME(0x10039A60u))(a0); }
XI_ORIG undefined4 TexObj_Create(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x10039A80u))(a0); }
XI_ORIG undefined4 TexObj_Upload(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x10039E50u))(a0); }
XI_ORIG _WORD * sub_1003AA50(void * a0) { return reinterpret_cast<_WORD * (__thiscall *)(void *)>(XI_GAME(0x1003AA50u))(a0); }
XI_ORIG int sub_1003AAB0(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x1003AAB0u))(a0); }
XI_ORIG char TexMgr_UploadPumpEntry(void * a0) { return reinterpret_cast<char (__thiscall *)(void *)>(XI_GAME(0x1003AB70u))(a0); }
XI_ORIG void sub_1003AB80(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x1003AB80u))(a0, a1); }
XI_ORIG undefined4 TexMgr_UploadPump(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x1003ABB0u))(a0); }
XI_ORIG int sub_1003AC80(void * a0, int a1) { return reinterpret_cast<int (__thiscall *)(void *, int)>(XI_GAME(0x1003AC80u))(a0, a1); }
XI_ORIG int sub_1003ACD0(void * a0, int a1) { return reinterpret_cast<int (__thiscall *)(void *, int)>(XI_GAME(0x1003ACD0u))(a0, a1); }
XI_ORIG int sub_1003AD40(void * a0, void * a1, int a2) { return reinterpret_cast<int (__thiscall *)(void *, void *, int)>(XI_GAME(0x1003AD40u))(a0, a1, a2); }
XI_ORIG int sub_1003ADC0(void * a0, int a1, int a2) { return reinterpret_cast<int (__thiscall *)(void *, int, int)>(XI_GAME(0x1003ADC0u))(a0, a1, a2); }
XI_ORIG _DWORD * sub_1003AEA0(void * a0, int a1, int a2, char a3) { return reinterpret_cast<_DWORD * (__thiscall *)(void *, int, int, char)>(XI_GAME(0x1003AEA0u))(a0, a1, a2, a3); }
XI_ORIG int sub_1003AEA0_2(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3) { return reinterpret_cast<int (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1003AEA0u))(a0, a1, a2, a3); }
XI_ORIG int sub_1003AF10(void * a0, void * a1, int a2) { return reinterpret_cast<int (__thiscall *)(void *, void *, int)>(XI_GAME(0x1003AF10u))(a0, a1, a2); }
XI_ORIG _DWORD * sub_1003B080(void * a0) { return reinterpret_cast<_DWORD * (__thiscall *)(void *)>(XI_GAME(0x1003B080u))(a0); }
XI_ORIG int CYyVbMng_AcquireVertexBuffer(void * a0, int a1, unsigned int a2, unsigned int a3, D3DPOOL a4, void * a5, char a6) { return reinterpret_cast<int (__thiscall *)(void *, int, unsigned int, unsigned int, D3DPOOL, void *, char)>(XI_GAME(0x1003B210u))(a0, a1, a2, a3, a4, a5, a6); }
XI_ORIG int CYyVbMng_AcquireVertexBuffer_v1(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5, XI_ANY a6) { return reinterpret_cast<int (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1003B210u))(a0, a1, a2, a3, a4, a5, a6); }
XI_ORIG _DWORD * sub_1003B3C0(void * a0) { return reinterpret_cast<_DWORD * (__stdcall *)(void *)>(XI_GAME(0x1003B3C0u))(a0); }
XI_ORIG undefined4 sub_1003B3C0_2(XI_ANY a0) { return reinterpret_cast<undefined4 (__stdcall *)(XI_ANY)>(XI_GAME(0x1003B3C0u))(a0); }
XI_ORIG _DWORD * sub_1003B450(void * a0, int a1, int a2, int a3, int a4, int a5) { return reinterpret_cast<_DWORD * (__thiscall *)(void *, int, int, int, int, int)>(XI_GAME(0x1003B450u))(a0, a1, a2, a3, a4, a5); }
XI_ORIG int sub_1003B640(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x1003B640u))(a0); }
XI_ORIG void sub_1003B690_2(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1003B690u))(a0); }
XI_ORIG int sub_1003B6D0(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x1003B6D0u))(a0); }
XI_ORIG undefined4 sub_1003B6D0_3(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x1003B6D0u))(a0); }
XI_ORIG int sub_1003B700(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x1003B700u))(a0); }
XI_ORIG undefined8 sub_1003B700_2(void * a0) { return reinterpret_cast<undefined8 (__thiscall *)(void *)>(XI_GAME(0x1003B700u))(a0); }
XI_ORIG undefined4 sub_1003B700_3(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x1003B700u))(a0); }
XI_ORIG int sub_1003B750(void * a0, char a1) { return reinterpret_cast<int (__thiscall *)(void *, char)>(XI_GAME(0x1003B750u))(a0, a1); }
XI_ORIG int sub_1003B780(void * a0, char a1) { return reinterpret_cast<int (__thiscall *)(void *, char)>(XI_GAME(0x1003B780u))(a0, a1); }
XI_ORIG _DWORD * sub_1003B7B0(void * a0, void * a1) { return reinterpret_cast<_DWORD * (__thiscall *)(void *, void *)>(XI_GAME(0x1003B7B0u))(a0, a1); }
XI_ORIG _DWORD * sub_1003B830(void * a0, void * a1) { return reinterpret_cast<_DWORD * (__thiscall *)(void *, void *)>(XI_GAME(0x1003B830u))(a0, a1); }
XI_ORIG int Sky_DrawGradientDome(float a0, float a1, int a2, void * a3, float a4) { return reinterpret_cast<int (__cdecl *)(float, float, int, void *, float)>(XI_GAME(0x1003D640u))(a0, a1, a2, a3, a4); }
XI_ORIG void Sky_DrawDomeViewCentered() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x1003DB60u))(); }
XI_ORIG unsigned int sub_1003E280(void * a0, unsigned int a1) { return reinterpret_cast<unsigned int (__thiscall *)(void *, unsigned int)>(XI_GAME(0x1003E280u))(a0, a1); }
XI_ORIG char sub_1003E2A0(void * a0, void * a1) { return reinterpret_cast<char (__thiscall *)(void *, void *)>(XI_GAME(0x1003E2A0u))(a0, a1); }
XI_ORIG uint32_t * sub_1003E330(void * a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<uint32_t * (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x1003E330u))(a0, a1, a2); }
XI_ORIG int YmElem_DrawD3ASegment(int a0, int a1, int a2, int a3) { return reinterpret_cast<int (__thiscall *)(int, int, int, int)>(XI_GAME(0x1003E910u))(a0, a1, a2, a3); }
XI_ORIG int YmElem_SetD3ADrawState(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x1003E9A0u))(a0); }
XI_ORIG _DWORD * sub_1003F8A0(int a0, int a1, int a2) { return reinterpret_cast<_DWORD * (__thiscall *)(int, int, int)>(XI_GAME(0x1003F8A0u))(a0, a1, a2); }
XI_ORIG uint8_t sub_1003FCB0(void * a0) { return reinterpret_cast<uint8_t (__thiscall *)(void *)>(XI_GAME(0x1003FCB0u))(a0); }
XI_ORIG char * sub_1003FCE0(void * a0) { return reinterpret_cast<char * (__thiscall *)(void *)>(XI_GAME(0x1003FCE0u))(a0); }
XI_ORIG int sub_1003FCE0_2(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x1003FCE0u))(a0); }
XI_ORIG char * sub_1003FCF0(void * a0) { return reinterpret_cast<char * (__thiscall *)(void *)>(XI_GAME(0x1003FCF0u))(a0); }
XI_ORIG int sub_1003FCF0_2(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x1003FCF0u))(a0); }
XI_ORIG undefined4 CMoDistModelElem_DrawBatches(void * a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x10040220u))(a0, a1, a2); }
XI_ORIG undefined4 CMoElemFamily_SharedEarlyExit(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x10040C20u))(a0); }
XI_ORIG void Font_DrawProjectedText3D(int a0, int a1, int a2, int a3, int a4) { reinterpret_cast<void (__cdecl *)(int, int, int, int, int)>(XI_GAME(0x10041C20u))(a0, a1, a2, a3, a4); }
XI_ORIG char CMoDistMorphElem_ValidateMorphData(int a0, int a1, int a2, int a3) { return reinterpret_cast<char (__stdcall *)(int, int, int, int)>(XI_GAME(0x10042D00u))(a0, a1, a2, a3); }
XI_ORIG int sub_10043DE0() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10043DE0u))(); }
XI_ORIG char * sub_10043DF0(void * a0) { return reinterpret_cast<char * (__thiscall *)(void *)>(XI_GAME(0x10043DF0u))(a0); }
XI_ORIG int sub_10043E50(void * a0, int a1, unsigned int a2, int a3) { return reinterpret_cast<int (__thiscall *)(void *, int, unsigned int, int)>(XI_GAME(0x10043E50u))(a0, a1, a2, a3); }
XI_ORIG int VertexBatch_BindAndDraw(void * a0, int a1, int a2, int a3, unsigned int a4, int a5) { return reinterpret_cast<int (__thiscall *)(void *, int, int, int, unsigned int, int)>(XI_GAME(0x10043F40u))(a0, a1, a2, a3, a4, a5); }
XI_ORIG void VertexBatch_BindAndDraw_v1(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10043F40u))(a0, a1, a2, a3, a4, a5); }
XI_ORIG undefined4 VertexBatch_BindAndDraw_v2(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10043F40u))(a0, a1, a2, a3, a4, a5); }
XI_ORIG int sub_10044010(void * a0, int a1) { return reinterpret_cast<int (__thiscall *)(void *, int)>(XI_GAME(0x10044010u))(a0, a1); }
XI_ORIG void * sub_10044130(void * a0) { return reinterpret_cast<void * (__thiscall *)(void *)>(XI_GAME(0x10044130u))(a0); }
XI_ORIG int sub_100441A0(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x100441A0u))(a0); }
XI_ORIG int Gfx_SetViewMatrixFromField10(int a0) { return reinterpret_cast<int (__thiscall *)(int)>(XI_GAME(0x10044210u))(a0); }
XI_ORIG int Gfx_SetViewMatrixFromField90(int a0) { return reinterpret_cast<int (__thiscall *)(int)>(XI_GAME(0x10044230u))(a0); }
XI_ORIG undefined4 FUN_10044250(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x10044250u))(a0, a1); }
XI_ORIG _DWORD * Mo_InitSharedRenderResources() { return reinterpret_cast<_DWORD * (__cdecl *)()>(XI_GAME(0x10044270u))(); }
XI_ORIG void Unit10043E40_ReleaseResourcesOf(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x100446A0u))(a0); }
XI_ORIG undefined4 CMoElem_AdvanceTimer(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x10044AE0u))(a0); }
XI_ORIG float * sub_10044C40(int a0, void * a1) { return reinterpret_cast<float * (__thiscall *)(int, void *)>(XI_GAME(0x10044C40u))(a0, a1); }
XI_ORIG undefined4 sub_10044C40_2(void * a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x10044C40u))(a0, a1); }
XI_ORIG void sub_10044D40(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10044D40u))(a0); }
XI_ORIG undefined4 sub_10044F10(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x10044F10u))(a0); }
XI_ORIG undefined4 sub_10045190(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10045190u))(a0, a1, a2, a3); }
XI_ORIG int sub_10045800(void * a0) { return reinterpret_cast<int (__cdecl *)(void *)>(XI_GAME(0x10045800u))(a0); }
XI_ORIG undefined4 sub_100458F0(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x100458F0u))(a0); }
XI_ORIG unsigned long long sub_10045920(XI_ANY a0, XI_ANY a1) {
    uint32_t xs[1] = {0}; uint32_t ra = a1.bits, rc = a0.bits, rd = 0;
    __asm__ volatile("call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10045920u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG int sub_10045C50(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10045C50u))(a0); }
XI_ORIG int sub_10045D40(int a0) { return reinterpret_cast<int (__thiscall *)(int)>(XI_GAME(0x10045D40u))(a0); }
XI_ORIG void sub_10045D40_2(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10045D40u))(a0); }
XI_ORIG int Fog_SetRenderStates() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x100464D0u))(); }
XI_ORIG int sub_10046550(void * a0, int a1) { return reinterpret_cast<int (__thiscall *)(void *, int)>(XI_GAME(0x10046550u))(a0, a1); }
XI_ORIG uint32_t YmElem_SetupDevice(void * a0, XI_ANY a1) { return reinterpret_cast<uint32_t (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x100467E0u))(a0, a1); }
XI_ORIG void YmElem_RestoreDevice(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x100472F0u))(a0, a1); }
XI_ORIG int sub_100473F0(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x100473F0u))(a0); }
XI_ORIG int sub_100473F0_2(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x100473F0u))(a0); }
XI_ORIG int sub_10047F80(int a0) { return reinterpret_cast<int (__thiscall *)(int)>(XI_GAME(0x10047F80u))(a0); }
XI_ORIG void * CMoGeneratorClone_VT_1032B114_ScalarDeletingDtor(void * a0, char a1) { return reinterpret_cast<void * (__thiscall *)(void *, char)>(XI_GAME(0x10047FE0u))(a0, a1); }
XI_ORIG int sub_10048000(int a0) { return reinterpret_cast<int (__thiscall *)(int)>(XI_GAME(0x10048000u))(a0); }
XI_ORIG void sub_10048000_2(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10048000u))(a0); }
XI_ORIG _DWORD * sub_100492F0(void * a0, int a1) { return reinterpret_cast<_DWORD * (__thiscall *)(void *, int)>(XI_GAME(0x100492F0u))(a0, a1); }
XI_ORIG undefined * sub_100493C0(void * a0) { return reinterpret_cast<undefined * (__thiscall *)(void *)>(XI_GAME(0x100493C0u))(a0); }
XI_ORIG int sub_10049570(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10049570u))(a0); }
XI_ORIG unsigned long long sub_100496F0_2(XI_ANY a0, XI_ANY a1, XI_ANY a2) {
    uint32_t xs[1] = {a1.bits}; uint32_t ra = a2.bits, rc = a0.bits, rd = 0;
    __asm__ volatile("pushl 0(%%esi)\n\t""call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x100496F0u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG uint8_t sub_100496F0(int a0, int a1) { return reinterpret_cast<uint8_t (__thiscall *)(int, int)>(XI_GAME(0x100496F0u))(a0, a1); }
XI_ORIG undefined4 sub_1004A980(void * a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x1004A980u))(a0, a1); }
XI_ORIG void CMoGeneratorClone_ExecuteCmdList(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x1004E720u))(a0, a1); }
XI_ORIG undefined4 sub_10052870(void * a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x10052870u))(a0, a1, a2); }
XI_ORIG __int16 SharedConditionalStateReset(int a0) { return reinterpret_cast<__int16 (__thiscall *)(int)>(XI_GAME(0x100531D0u))(a0); }
XI_ORIG undefined4 SharedConditionalStateReset_v1(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x100531D0u))(a0); }
XI_ORIG __int16 sub_10053370(int a0) { return reinterpret_cast<__int16 (__thiscall *)(int)>(XI_GAME(0x10053370u))(a0); }
XI_ORIG undefined4 sub_10053370_2(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x10053370u))(a0); }
XI_ORIG int sub_10053450(int a0, int a1) { return reinterpret_cast<int (__thiscall *)(int, int)>(XI_GAME(0x10053450u))(a0, a1); }
XI_ORIG undefined4 * CMoGeneratorClone_CreateInstance(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3) { return reinterpret_cast<undefined4 * (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x100536C0u))(a0, a1, a2, a3); }
XI_ORIG char * CMoGeneratorClone_VT_1032B69C_ScalarDeletingDtor(void * a0, char a1) { return reinterpret_cast<char * (__thiscall *)(void *, char)>(XI_GAME(0x10053840u))(a0, a1); }
XI_ORIG int sub_10053890(int a0, char a1) { return reinterpret_cast<int (__thiscall *)(int, char)>(XI_GAME(0x10053890u))(a0, a1); }
XI_ORIG unsigned long long sub_10053890_2(XI_ANY a0, XI_ANY a1, XI_ANY a2) {
    uint32_t xs[1] = {a1.bits}; uint32_t ra = a2.bits, rc = a0.bits, rd = 0;
    __asm__ volatile("pushl 0(%%esi)\n\t""call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10053890u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG undefined4 sub_10053890_3(void * a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x10053890u))(a0, a1); }
XI_ORIG char YmGenerater_Stop(int a0, void * a1) { return reinterpret_cast<char (__thiscall *)(int, void *)>(XI_GAME(0x100538E0u))(a0, a1); }
XI_ORIG unsigned long long YmGenerater_Stop_v1(XI_ANY a0, XI_ANY a1, XI_ANY a2) {
    uint32_t xs[1] = {a1.bits}; uint32_t ra = a2.bits, rc = a0.bits, rd = 0;
    __asm__ volatile("pushl 0(%%esi)\n\t""call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x100538E0u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG undefined4 YmGenerater_Stop_v2(void * a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x100538E0u))(a0, a1); }
XI_ORIG unsigned long long YmGenerater_Stop_v3(XI_ANY a0, XI_ANY a1, XI_ANY a2) {
    uint32_t xs[1] = {a1.bits}; uint32_t ra = a2.bits, rc = a0.bits, rd = 0;
    __asm__ volatile("pushl 0(%%esi)\n\t""call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x100538E0u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG uint8_t sub_100539E0(void * a0) { return reinterpret_cast<uint8_t (__thiscall *)(void *)>(XI_GAME(0x100539E0u))(a0); }
XI_ORIG undefined4 sub_100539E0_2(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x100539E0u))(a0); }
XI_ORIG undefined4 Unit10053860_StopGenerators(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10053A00u))(a0, a1, a2, a3, a4); }
XI_ORIG unsigned long long sub_10053DD0(XI_ANY a0, XI_ANY a1, XI_ANY a2) {
    uint32_t xs[1] = {a1.bits}; uint32_t ra = a2.bits, rc = a0.bits, rd = 0;
    __asm__ volatile("pushl 0(%%esi)\n\t""call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10053DD0u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG undefined4 sub_10053E60(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x10053E60u))(a0); }
XI_ORIG int CMoGeneratorClone_Destructor(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x100542F0u))(a0); }
XI_ORIG __int16 sub_100543A0(int a0) { return reinterpret_cast<__int16 (__cdecl *)(int)>(XI_GAME(0x100543A0u))(a0); }
XI_ORIG uint32_t BeginEffectOffscreenPass() { return reinterpret_cast<uint32_t (__cdecl *)()>(XI_GAME(0x10054D70u))(); }
XI_ORIG void EndEffectOffscreenPass(XI_ANY a0, XI_ANY a1) { reinterpret_cast<void (__stdcall *)(XI_ANY, XI_ANY)>(XI_GAME(0x10054F80u))(a0, a1); }
XI_ORIG int sub_10055000(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10055000u))(a0); }
XI_ORIG unsigned long long sub_100550F0(XI_ANY a0, XI_ANY a1) {
    uint32_t xs[1] = {0}; uint32_t ra = a1.bits, rc = a0.bits, rd = 0;
    __asm__ volatile("call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x100550F0u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG undefined4 sub_10055130(void * a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x10055130u))(a0, a1, a2); }
XI_ORIG int sub_10055160(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10055160u))(a0); }
XI_ORIG _DWORD * sub_10055240(void * a0) { return reinterpret_cast<_DWORD * (__thiscall *)(void *)>(XI_GAME(0x10055240u))(a0); }
XI_ORIG int sub_10055250(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10055250u))(a0); }
XI_ORIG _DWORD * sub_100555D0() { return reinterpret_cast<_DWORD * (__cdecl *)()>(XI_GAME(0x100555D0u))(); }
XI_ORIG long double sub_10056160(void * a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<long double (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x10056160u))(a0, a1, a2); }
XI_ORIG int * sub_10056C70(void * a0, void * a1, void * a2, int a3, int a4) { return reinterpret_cast<int * (__thiscall *)(void *, void *, void *, int, int)>(XI_GAME(0x10056C70u))(a0, a1, a2, a3, a4); }
XI_ORIG void sub_10056EB0(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10056EB0u))(a0); }
XI_ORIG uint32_t sub_10057C20(void * a0) { return reinterpret_cast<uint32_t (__thiscall *)(void *)>(XI_GAME(0x10057C20u))(a0); }
XI_ORIG undefined4 CMoSchedularTask_Interpret(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x10057FB0u))(a0); }
XI_ORIG undefined4 sub_10062DE0(void * a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x10062DE0u))(a0, a1); }
XI_ORIG undefined4 sub_10062E20_2(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10062E20u))(a0, a1, a2, a3, a4); }
XI_ORIG int sub_10063B20(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10063B20u))(a0); }
XI_ORIG _BYTE * sub_10069DD0(int a0, int a1) { return reinterpret_cast<_BYTE * (__thiscall *)(int, int)>(XI_GAME(0x10069DD0u))(a0, a1); }
XI_ORIG int sub_1006A060(void * a0, int a1, int a2, int a3) { return reinterpret_cast<int (__thiscall *)(void *, int, int, int)>(XI_GAME(0x1006A060u))(a0, a1, a2, a3); }
XI_ORIG int sub_1006A070(int a0, int a1, int a2, int a3) { return reinterpret_cast<int (__thiscall *)(int, int, int, int)>(XI_GAME(0x1006A070u))(a0, a1, a2, a3); }
XI_ORIG void sub_1006A0E0_2(void * a0, XI_ANY a1, XI_ANY a2) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x1006A0E0u))(a0, a1, a2); }
XI_ORIG int sub_1006A0E0(int a0, int a1, int a2) { return reinterpret_cast<int (__thiscall *)(int, int, int)>(XI_GAME(0x1006A0E0u))(a0, a1, a2); }
XI_ORIG _DWORD * CMoDX_CreateTexture(void * a0, unsigned __int16 a1, unsigned __int16 a2, void * a3) { return reinterpret_cast<_DWORD * (__thiscall *)(void *, unsigned __int16, unsigned __int16, void *)>(XI_GAME(0x1006A150u))(a0, a1, a2, a3); }
XI_ORIG int sub_1006A420(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x1006A420u))(a0); }
XI_ORIG void sub_1006A450(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1006A450u))(a0); }
XI_ORIG int CMoDX_SetWorldMatrix(void * a0, void * a1) { return reinterpret_cast<int (__thiscall *)(void *, void *)>(XI_GAME(0x1006A480u))(a0, a1); }
XI_ORIG void CMoDX_SetWorldMatrix_v1(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x1006A480u))(a0, a1); }
XI_ORIG int sub_1006A4A0(void * a0, void * a1) { return reinterpret_cast<int (__thiscall *)(void *, void *)>(XI_GAME(0x1006A4A0u))(a0, a1); }
XI_ORIG int sub_1006A4C0(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x1006A4C0u))(a0); }
XI_ORIG int CMoDX_PopViewMatrix(int a0) { return reinterpret_cast<int (__thiscall *)(int)>(XI_GAME(0x1006A4F0u))(a0); }
XI_ORIG void CMoDX_PopViewMatrix_v1(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1006A4F0u))(a0); }
XI_ORIG int CMoDX_SetViewMatrix(void * a0, void * a1) { return reinterpret_cast<int (__thiscall *)(void *, void *)>(XI_GAME(0x1006A520u))(a0, a1); }
XI_ORIG void CMoDX_SetViewMatrix_v1(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x1006A520u))(a0, a1); }
XI_ORIG int sub_1006A560(unsigned int a0) { return reinterpret_cast<int (__cdecl *)(unsigned int)>(XI_GAME(0x1006A560u))(a0); }
XI_ORIG void sub_1006AD90(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1006AD90u))(a0); }
XI_ORIG exception * sub_1006AD90_2(void * a0) { return reinterpret_cast<exception * (__thiscall *)(void *)>(XI_GAME(0x1006AD90u))(a0); }
XI_ORIG int sub_1006ADF0(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x1006ADF0u))(a0); }
XI_ORIG int sub_1006AE30(void * a0, int a1, int a2) { return reinterpret_cast<int (__thiscall *)(void *, int, int)>(XI_GAME(0x1006AE30u))(a0, a1, a2); }
XI_ORIG int StateBlockHolder_ApplyRenderStates(void * a0, void * a1) { return reinterpret_cast<int (__thiscall *)(void *, void *)>(XI_GAME(0x1006AF00u))(a0, a1); }
XI_ORIG int StateBlock_ApplyTSS(void * a0, int a1) { return reinterpret_cast<int (__thiscall *)(void *, int)>(XI_GAME(0x1006AF90u))(a0, a1); }
XI_ORIG void StateBlock_ApplyTSS_v1(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x1006AF90u))(a0, a1); }
XI_ORIG _DWORD * sub_1006B050(int a0) { return reinterpret_cast<_DWORD * (__thiscall *)(int)>(XI_GAME(0x1006B050u))(a0); }
XI_ORIG void CMoDxStatusMng_Destructor(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1006B090u))(a0); }
XI_ORIG _DWORD * sub_1006B0C0(void * a0) { return reinterpret_cast<_DWORD * (__thiscall *)(void *)>(XI_GAME(0x1006B0C0u))(a0); }
XI_ORIG _DWORD * CMoDX_CreateAndInitSystem(void * a0) { return reinterpret_cast<_DWORD * (__thiscall *)(void *)>(XI_GAME(0x1006B2B0u))(a0); }
XI_ORIG int sub_1006BD90(int a0) { return reinterpret_cast<int (__cdecl *)(int)>(XI_GAME(0x1006BD90u))(a0); }
XI_ORIG CMoOcclusionMng_vtbl ** CMoOcclusionMng_Constructor(void * a0) { return reinterpret_cast<CMoOcclusionMng_vtbl ** (__thiscall *)(void *)>(XI_GAME(0x1006C140u))(a0); }
XI_ORIG _DWORD * sub_1006C210(void * a0) { return reinterpret_cast<_DWORD * (__thiscall *)(void *)>(XI_GAME(0x1006C210u))(a0); }
XI_ORIG _DWORD * OcclusionMng_CreateTarget(void * a0) { return reinterpret_cast<_DWORD * (__thiscall *)(void *)>(XI_GAME(0x1006C220u))(a0); }
XI_ORIG void OcclusionMng_CreateTarget_v1(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1006C220u))(a0); }
XI_ORIG int sub_1006C260(int a0) { return reinterpret_cast<int (__thiscall *)(int)>(XI_GAME(0x1006C260u))(a0); }
XI_ORIG int sub_1006C270(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x1006C270u))(a0); }
XI_ORIG int Occlusion_QueryScreenRect(void * a0, void * a1, int a2, int a3, int a4, int a5, int a6, int a7, char a8, int a9) { return reinterpret_cast<int (__thiscall *)(void *, void *, int, int, int, int, int, int, char, int)>(XI_GAME(0x1006C280u))(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9); }
XI_ORIG int Occlusion_QueryScreenRectImpl(void * a0, void * a1, int a2, int a3, int a4, int a5, int a6, int a7, char a8, int a9) { return reinterpret_cast<int (__thiscall *)(void *, void *, int, int, int, int, int, int, char, int)>(XI_GAME(0x1006C300u))(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9); }
XI_ORIG int DrawScreenProbe(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8) { return reinterpret_cast<int (__stdcall *)(int, int, int, int, int, int, int, int, int)>(XI_GAME(0x1006C530u))(a0, a1, a2, a3, a4, a5, a6, a7, a8); }
XI_ORIG int sub_1006C8B0(void * a0, char a1) { return reinterpret_cast<int (__thiscall *)(void *, char)>(XI_GAME(0x1006C8B0u))(a0, a1); }
XI_ORIG int OcclusionMng_Prepare(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x1006C9B0u))(a0); }
XI_ORIG _DWORD * sub_1006CB50() { return reinterpret_cast<_DWORD * (__cdecl *)()>(XI_GAME(0x1006CB50u))(); }
XI_ORIG __int16 sub_10071050(void * a0) { return reinterpret_cast<__int16 (__thiscall *)(void *)>(XI_GAME(0x10071050u))(a0); }
XI_ORIG void sub_10071050_3(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10071050u))(a0); }
XI_ORIG uint8_t sub_10071060(void * a0) { return reinterpret_cast<uint8_t (__fastcall *)(void *)>(XI_GAME(0x10071060u))(a0); }
XI_ORIG undefined4 sub_10071060_2(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x10071060u))(a0); }
XI_ORIG undefined4 sub_100710F0(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x100710F0u))(a0, a1, a2, a3, a4); }
XI_ORIG int * sub_10071E90(int a0) { return reinterpret_cast<int * (__fastcall *)(int)>(XI_GAME(0x10071E90u))(a0); }
XI_ORIG unsigned long long sub_10071E90_2(XI_ANY a0, XI_ANY a1) {
    uint32_t xs[1] = {0}; uint32_t ra = a1.bits, rc = a0.bits, rd = 0;
    __asm__ volatile("call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10071E90u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG undefined8 sub_10071E90_3(void * a0) { return reinterpret_cast<undefined8 (__thiscall *)(void *)>(XI_GAME(0x10071E90u))(a0); }
XI_ORIG void sub_10071E90_4(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10071E90u))(a0); }
XI_ORIG char sub_10071EC0(int a0, int a1) { return reinterpret_cast<char (__fastcall *)(int, int)>(XI_GAME(0x10071EC0u))(a0, a1); }
XI_ORIG undefined4 sub_10071EC0_2(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x10071EC0u))(a0); }
XI_ORIG void sub_10071EC0_3(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10071EC0u))(a0); }
XI_ORIG void sub_10071F50_2(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10071F50u))(a0); }
XI_ORIG _DWORD * sub_10071F50(void * a0) { return reinterpret_cast<_DWORD * (__thiscall *)(void *)>(XI_GAME(0x10071F50u))(a0); }
XI_ORIG void sub_10071F60(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10071F60u))(a0); }
XI_ORIG int sub_10072030(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10072030u))(a0); }
XI_ORIG _DWORD * sub_10072290(void * a0, void * a1, int a2, int a3) { return reinterpret_cast<_DWORD * (__thiscall *)(void *, void *, int, int)>(XI_GAME(0x10072290u))(a0, a1, a2, a3); }
XI_ORIG undefined4 sub_10072430_2(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3) { return reinterpret_cast<undefined4 (__stdcall *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10072430u))(a0, a1, a2, a3); }
XI_ORIG int sub_100729C0() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x100729C0u))(); }
XI_ORIG int sub_10072DB0(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10072DB0u))(a0); }
XI_ORIG int * sub_10072ED0(int a0, int a1) { return reinterpret_cast<int * (__thiscall *)(int, int)>(XI_GAME(0x10072ED0u))(a0, a1); }
XI_ORIG int sub_10072FB0(int a0) { return reinterpret_cast<int (__stdcall *)(int)>(XI_GAME(0x10072FB0u))(a0); }
XI_ORIG undefined4 sub_10072FB0_2(XI_ANY a0) { return reinterpret_cast<undefined4 (__stdcall *)(XI_ANY)>(XI_GAME(0x10072FB0u))(a0); }
XI_ORIG undefined4 sub_10072FD0_2(void * a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x10072FD0u))(a0, a1, a2); }
XI_ORIG int * sub_10072FD0(void * a0, void * a1, int a2) { return reinterpret_cast<int * (__thiscall *)(void *, void *, int)>(XI_GAME(0x10072FD0u))(a0, a1, a2); }
XI_ORIG undefined4 * sub_100730E0(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 * (__stdcall *)(XI_ANY, XI_ANY)>(XI_GAME(0x100730E0u))(a0, a1); }
XI_ORIG undefined4 sub_100731B0_2(void * a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x100731B0u))(a0, a1, a2); }
XI_ORIG int * sub_100731B0(void * a0, void * a1, int a2) { return reinterpret_cast<int * (__thiscall *)(void *, void *, int)>(XI_GAME(0x100731B0u))(a0, a1, a2); }
XI_ORIG undefined4 sub_10073B20_2(XI_ANY a0) { return reinterpret_cast<undefined4 (__stdcall *)(XI_ANY)>(XI_GAME(0x10073B20u))(a0); }
XI_ORIG _DWORD * sub_10074140(void * a0, void * a1, int a2) { return reinterpret_cast<_DWORD * (__thiscall *)(void *, void *, int)>(XI_GAME(0x10074140u))(a0, a1, a2); }
XI_ORIG void sub_10074180_2(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x10074180u))(a0, a1); }
XI_ORIG int sub_10074290() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10074290u))(); }
XI_ORIG void sub_100742A0(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x100742A0u))(a0); }
XI_ORIG void sub_100742B0_2(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x100742B0u))(a0, a1, a2, a3, a4); }
XI_ORIG void sub_10074310(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10074310u))(a0, a1, a2, a3, a4); }
XI_ORIG undefined4 sub_100745C0_2(void * a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x100745C0u))(a0, a1); }
XI_ORIG int sub_100746A0(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x100746A0u))(a0); }
XI_ORIG void sub_100746A0_2(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x100746A0u))(a0); }
XI_ORIG _DWORD * sub_10074740(void * a0) { return reinterpret_cast<_DWORD * (__thiscall *)(void *)>(XI_GAME(0x10074740u))(a0); }
XI_ORIG void * sub_10074740_3(void * a0) { return reinterpret_cast<void * (__thiscall *)(void *)>(XI_GAME(0x10074740u))(a0); }
XI_ORIG char sub_100747C0(void * a0) { return reinterpret_cast<char (__thiscall *)(void *)>(XI_GAME(0x100747C0u))(a0); }
XI_ORIG int sub_100748F0(int a0) { return reinterpret_cast<int (__thiscall *)(int)>(XI_GAME(0x100748F0u))(a0); }
XI_ORIG undefined4 sub_100748F0_2(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x100748F0u))(a0); }
XI_ORIG int sub_100749B0(void * a0, int a1) { return reinterpret_cast<int (__thiscall *)(void *, int)>(XI_GAME(0x100749B0u))(a0, a1); }
XI_ORIG undefined4 sub_100749B0_2(XI_ANY a0) { return reinterpret_cast<undefined4 (__stdcall *)(XI_ANY)>(XI_GAME(0x100749B0u))(a0); }
XI_ORIG undefined4 sub_10074A00() { return reinterpret_cast<undefined4 (__cdecl *)()>(XI_GAME(0x10074A00u))(); }
XI_ORIG int sub_10074A10(int a0) { return reinterpret_cast<int (__stdcall *)(int)>(XI_GAME(0x10074A10u))(a0); }
XI_ORIG void sub_10074AB0(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10074AB0u))(a0); }
XI_ORIG int sub_10074BA0(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10074BA0u))(a0); }
XI_ORIG int sub_10074C30(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10074C30u))(a0); }
XI_ORIG int Gfx_InitCubeMapTextures() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10075280u))(); }
XI_ORIG int sub_10075520(void * a0, int a1) { return reinterpret_cast<int (__thiscall *)(void *, int)>(XI_GAME(0x10075520u))(a0, a1); }
XI_ORIG void TexRef_EnsureRenderTarget(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x100755A0u))(a0); }
XI_ORIG int TextureHolder_BindWarped(void * a0, int a1, float a2, float a3, float a4) { return reinterpret_cast<int (__thiscall *)(void *, int, float, float, float)>(XI_GAME(0x10075700u))(a0, a1, a2, a3, a4); }
XI_ORIG int TexRef_SetTexture(void * a0, int a1) { return reinterpret_cast<int (__thiscall *)(void *, int)>(XI_GAME(0x10075960u))(a0, a1); }
XI_ORIG void TexRef_SetTexture_v1(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x10075960u))(a0, a1); }
XI_ORIG undefined4 TextureHolder_BindTinted(void * a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x100759C0u))(a0, a1, a2); }
XI_ORIG void sub_10077FB0() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x10077FB0u))(); }
XI_ORIG undefined4 sub_100780A0(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x100780A0u))(a0, a1, a2, a3, a4); }
XI_ORIG _DWORD * sub_100814A0(int a0) { return reinterpret_cast<_DWORD * (__thiscall *)(int)>(XI_GAME(0x100814A0u))(a0); }
XI_ORIG void sub_100814A0_2(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x100814A0u))(a0); }
XI_ORIG void sub_100814E0(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x100814E0u))(a0); }
XI_ORIG undefined8 sub_100814F0_2(void * a0, XI_ANY a1) { return reinterpret_cast<undefined8 (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x100814F0u))(a0, a1); }
XI_ORIG int sub_10081550(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10081550u))(a0); }
XI_ORIG undefined8 sub_10081550_2(void * a0) { return reinterpret_cast<undefined8 (__thiscall *)(void *)>(XI_GAME(0x10081550u))(a0); }
XI_ORIG int sub_10081600(int a0) { return reinterpret_cast<int (__thiscall *)(int)>(XI_GAME(0x10081600u))(a0); }
XI_ORIG void sub_10081A30() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x10081A30u))(); }
XI_ORIG void sub_10081A50() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x10081A50u))(); }
XI_ORIG int sub_10082B10(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10082B10u))(a0); }
XI_ORIG char sub_100830C0(void * a0, void * a1, int a2, void * a3, int a4) { return reinterpret_cast<char (__thiscall *)(void *, void *, int, void *, int)>(XI_GAME(0x100830C0u))(a0, a1, a2, a3, a4); }
XI_ORIG uint32_t sub_10083340(void * a0) { return reinterpret_cast<uint32_t (__thiscall *)(void *)>(XI_GAME(0x10083340u))(a0); }
XI_ORIG char sub_10084140(void * a0) { return reinterpret_cast<char (__thiscall *)(void *)>(XI_GAME(0x10084140u))(a0); }
XI_ORIG unsigned long long sub_10084350(XI_ANY a0, XI_ANY a1, XI_ANY a2) {
    uint32_t xs[1] = {a1.bits}; uint32_t ra = a2.bits, rc = a0.bits, rd = 0;
    __asm__ volatile("pushl 0(%%esi)\n\t""call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10084350u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG uint8_t sub_10084370(void * a0, int a1) { return reinterpret_cast<uint8_t (__thiscall *)(void *, int)>(XI_GAME(0x10084370u))(a0, a1); }
XI_ORIG unsigned long long sub_10084370_2(XI_ANY a0, XI_ANY a1, XI_ANY a2) {
    uint32_t xs[1] = {a1.bits}; uint32_t ra = a2.bits, rc = a0.bits, rd = 0;
    __asm__ volatile("pushl 0(%%esi)\n\t""call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10084370u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG int sub_10084390(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10084390u))(a0); }
XI_ORIG undefined4 sub_10084390_2(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x10084390u))(a0); }
XI_ORIG uint8_t sub_100843B0(void * a0) { return reinterpret_cast<uint8_t (__thiscall *)(void *)>(XI_GAME(0x100843B0u))(a0); }
XI_ORIG int sub_10084400(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10084400u))(a0); }
XI_ORIG int sub_10084400_2(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10084400u))(a0); }
XI_ORIG int sub_10084420(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10084420u))(a0); }
XI_ORIG uint32_t sub_10084480(void * a0, XI_ANY a1) { return reinterpret_cast<uint32_t (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x10084480u))(a0, a1); }
XI_ORIG BOOL sub_10084580(int a0) { return reinterpret_cast<BOOL (__thiscall *)(int)>(XI_GAME(0x10084580u))(a0); }
XI_ORIG BOOL sub_100845B0(void * a0) { return reinterpret_cast<BOOL (__thiscall *)(void *)>(XI_GAME(0x100845B0u))(a0); }
XI_ORIG BOOL sub_10084640(void * a0) { return reinterpret_cast<BOOL (__thiscall *)(void *)>(XI_GAME(0x10084640u))(a0); }
XI_ORIG uint32_t sub_10084670(void * a0) { return reinterpret_cast<uint32_t (__thiscall *)(void *)>(XI_GAME(0x10084670u))(a0); }
XI_ORIG undefined4 sub_10084690(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x10084690u))(a0); }
XI_ORIG undefined4 sub_10084720(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x10084720u))(a0); }
XI_ORIG void sub_10085010(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x10085010u))(a0, a1); }
XI_ORIG int CXiActor_SpawnResourceGenerators(int a0, void * a1) { return reinterpret_cast<int (__thiscall *)(int, void *)>(XI_GAME(0x10085060u))(a0, a1); }
XI_ORIG void CXiActor_SpawnResourceGenerators_v1(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x10085060u))(a0, a1); }
XI_ORIG undefined4 CXiActor_SpawnResourceGenerators_v2(void * a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x10085060u))(a0, a1); }
XI_ORIG void sub_100852D0() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x100852D0u))(); }
XI_ORIG uint8_t sub_10085490(void * a0) { return reinterpret_cast<uint8_t (__thiscall *)(void *)>(XI_GAME(0x10085490u))(a0); }
XI_ORIG unsigned long long sub_10085A10(XI_ANY a0, XI_ANY a1) {
    uint32_t xs[1] = {0}; uint32_t ra = a1.bits, rc = a0.bits, rd = 0;
    __asm__ volatile("call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10085A10u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG void sub_10085A50(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10085A50u))(a0); }
XI_ORIG void sub_10085AB0(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10085AB0u))(a0); }
XI_ORIG void sub_10085AC0(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x10085AC0u))(a0, a1); }
XI_ORIG unsigned long long sub_10085AD0(XI_ANY a0, XI_ANY a1) {
    uint32_t xs[1] = {0}; uint32_t ra = a1.bits, rc = a0.bits, rd = 0;
    __asm__ volatile("call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10085AD0u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG void sub_10085B10(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x10085B10u))(a0, a1); }
XI_ORIG void Actor_DrawWorldText(void * a0, void * a1, float a2, unsigned int a3, int a4) { reinterpret_cast<void (__cdecl *)(void *, void *, float, unsigned int, int)>(XI_GAME(0x10086210u))(a0, a1, a2, a3, a4); }
XI_ORIG void Actor_DrawWorldText_v1(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10086210u))(a0, a1, a2, a3, a4); }
XI_ORIG void DrawNameplateSecondString(XI_ANY a0, XI_ANY a1, XI_ANY a2) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10086900u))(a0, a1, a2); }
XI_ORIG unsigned long long sub_10087060(XI_ANY a0) {
    uint32_t xs[1] = {0}; uint32_t ra = a0.bits, rc = 0, rd = 0;
    __asm__ volatile("call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10087060u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG unsigned long long sub_10087070(XI_ANY a0, XI_ANY a1) {
    uint32_t xs[1] = {a0.bits}; uint32_t ra = a1.bits, rc = 0, rd = 0;
    __asm__ volatile("pushl 0(%%esi)\n\t""call *%%edi\n\t""addl $4, %%esp\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10087070u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG unsigned long long sub_10087070_2(XI_ANY a0, XI_ANY a1) {
    uint32_t xs[1] = {a0.bits}; uint32_t ra = a1.bits, rc = 0, rd = 0;
    __asm__ volatile("pushl 0(%%esi)\n\t""call *%%edi\n\t""addl $4, %%esp\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10087070u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG undefined sub_10087220() { return reinterpret_cast<undefined (__cdecl *)()>(XI_GAME(0x10087220u))(); }
XI_ORIG undefined4 sub_100872C0() { return reinterpret_cast<undefined4 (__cdecl *)()>(XI_GAME(0x100872C0u))(); }
XI_ORIG unsigned long long sub_100873B0(XI_ANY a0) {
    uint32_t xs[1] = {0}; uint32_t ra = a0.bits, rc = 0, rd = 0;
    __asm__ volatile("call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x100873B0u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG unsigned long long sub_10087690(XI_ANY a0) {
    uint32_t xs[1] = {0}; uint32_t ra = a0.bits, rc = 0, rd = 0;
    __asm__ volatile("call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10087690u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG unsigned long long sub_100876B0(XI_ANY a0) {
    uint32_t xs[1] = {0}; uint32_t ra = a0.bits, rc = 0, rd = 0;
    __asm__ volatile("call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x100876B0u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG unsigned long long sub_10087760(XI_ANY a0) {
    uint32_t xs[1] = {0}; uint32_t ra = a0.bits, rc = 0, rd = 0;
    __asm__ volatile("call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10087760u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG undefined4 sub_10087890() { return reinterpret_cast<undefined4 (__cdecl *)()>(XI_GAME(0x10087890u))(); }
XI_ORIG uint32_t sub_10087AD0() { return reinterpret_cast<uint32_t (__cdecl *)()>(XI_GAME(0x10087AD0u))(); }
XI_ORIG void sub_10087E80(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10087E80u))(a0); }
XI_ORIG void sub_10087F00(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10087F00u))(a0); }
XI_ORIG void sub_100882D0() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x100882D0u))(); }
XI_ORIG void sub_100883E0(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x100883E0u))(a0); }
XI_ORIG void sub_10089100(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10089100u))(a0); }
XI_ORIG undefined4 sub_1008A120(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x1008A120u))(a0); }
XI_ORIG undefined8 sub_1008ABE0() { return reinterpret_cast<undefined8 (__cdecl *)()>(XI_GAME(0x1008ABE0u))(); }
XI_ORIG void sub_1008B100(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1008B100u))(a0); }
XI_ORIG void sub_1008B170(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1008B170u))(a0); }
XI_ORIG undefined4 sub_1008B410(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x1008B410u))(a0); }
XI_ORIG undefined4 sub_1008B460(void * a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x1008B460u))(a0, a1); }
XI_ORIG void sub_1008C480(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1008C480u))(a0); }
XI_ORIG undefined4 sub_1008C6C0(void * a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x1008C6C0u))(a0, a1); }
XI_ORIG void sub_1008CD90(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1008CD90u))(a0); }
XI_ORIG void sub_1008DA00(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1008DA00u))(a0); }
XI_ORIG void sub_1008DB40(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1008DB40u))(a0); }
XI_ORIG void sub_1008E290(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1008E290u))(a0); }
XI_ORIG void sub_1008E3F0(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1008E3F0u))(a0); }
XI_ORIG void Unit10086E90_UpdateFlags120Bit23(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1008E4D0u))(a0); }
XI_ORIG void sub_1008E740(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1008E740u))(a0); }
XI_ORIG void sub_1008E870(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1008E870u))(a0); }
XI_ORIG undefined4 Acter_UpdateOne(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x1008E9A0u))(a0); }
XI_ORIG void sub_1008EE30(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1008EE30u))(a0); }
XI_ORIG void sub_1008F740(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1008F740u))(a0); }
XI_ORIG void sub_10092900(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10092900u))(a0); }
XI_ORIG undefined4 sub_10093B70() { return reinterpret_cast<undefined4 (__cdecl *)()>(XI_GAME(0x10093B70u))(); }
XI_ORIG uint8_t sub_10093DB0() { return reinterpret_cast<uint8_t (__cdecl *)()>(XI_GAME(0x10093DB0u))(); }
XI_ORIG undefined4 sub_10093DB0_2() { return reinterpret_cast<undefined4 (__cdecl *)()>(XI_GAME(0x10093DB0u))(); }
XI_ORIG void sub_10093E30() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x10093E30u))(); }
XI_ORIG void sub_10093E50() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x10093E50u))(); }
XI_ORIG undefined4 sub_10094190() { return reinterpret_cast<undefined4 (__cdecl *)()>(XI_GAME(0x10094190u))(); }
XI_ORIG void sub_10095660() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x10095660u))(); }
XI_ORIG undefined4 sub_100956C0(void * a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x100956C0u))(a0, a1); }
XI_ORIG void Acter_UpdateAllLists() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x10095900u))(); }
XI_ORIG int sub_10095D80() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10095D80u))(); }
XI_ORIG void sub_10095DA0(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x10095DA0u))(a0); }
XI_ORIG void sub_10095DD0(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x10095DD0u))(a0); }
XI_ORIG void sub_10095E30(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x10095E30u))(a0); }
XI_ORIG void sub_10095E90(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x10095E90u))(a0); }
XI_ORIG uint32_t sub_10096040(XI_ANY a0) { return reinterpret_cast<uint32_t (__cdecl *)(XI_ANY)>(XI_GAME(0x10096040u))(a0); }
XI_ORIG undefined4 sub_100960F0(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x100960F0u))(a0, a1); }
XI_ORIG uint32_t sub_100961D0(XI_ANY a0) { return reinterpret_cast<uint32_t (__cdecl *)(XI_ANY)>(XI_GAME(0x100961D0u))(a0); }
XI_ORIG undefined4 sub_10096200(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x10096200u))(a0); }
XI_ORIG undefined4 Acter_UpdateFrame() { return reinterpret_cast<undefined4 (__cdecl *)()>(XI_GAME(0x10096640u))(); }
XI_ORIG void sub_10096C90(XI_ANY a0, XI_ANY a1) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x10096C90u))(a0, a1); }
XI_ORIG void sub_100973B0(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x100973B0u))(a0); }
XI_ORIG undefined4 sub_10097A40(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x10097A40u))(a0); }
XI_ORIG void sub_10097AF0() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x10097AF0u))(); }
XI_ORIG void sub_100983F0(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x100983F0u))(a0); }
XI_ORIG int * sub_10098F70(XI_ANY a0) { return reinterpret_cast<int * (__cdecl *)(XI_ANY)>(XI_GAME(0x10098F70u))(a0); }
XI_ORIG undefined4 sub_10098F90(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x10098F90u))(a0, a1); }
XI_ORIG void sub_100997B0() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x100997B0u))(); }
XI_ORIG void sub_1009F2F0() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x1009F2F0u))(); }
XI_ORIG void sub_1009F4C0(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1009F4C0u))(a0); }
XI_ORIG void sub_100A3D00() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x100A3D00u))(); }
XI_ORIG _DWORD * sub_100A4C20(void * a0) { return reinterpret_cast<_DWORD * (__thiscall *)(void *)>(XI_GAME(0x100A4C20u))(a0); }
XI_ORIG char sub_100A8CA0(void * a0) { return reinterpret_cast<char (__thiscall *)(void *)>(XI_GAME(0x100A8CA0u))(a0); }
XI_ORIG long double sub_100AAEF0(XI_ANY a0) { return reinterpret_cast<long double (__stdcall *)(XI_ANY)>(XI_GAME(0x100AAEF0u))(a0); }
XI_ORIG void sub_100AB750(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x100AB750u))(a0, a1, a2, a3, a4); }
XI_ORIG void sub_100AE960() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x100AE960u))(); }
XI_ORIG undefined4 sub_100AEA40() { return reinterpret_cast<undefined4 (__cdecl *)()>(XI_GAME(0x100AEA40u))(); }
XI_ORIG undefined4 sub_100AEC70(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x100AEC70u))(a0); }
XI_ORIG void sub_100AED00(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x100AED00u))(a0, a1, a2, a3); }
XI_ORIG int sub_100B37A0(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x100B37A0u))(a0); }
XI_ORIG void sub_100BCD10(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x100BCD10u))(a0); }
XI_ORIG undefined4 sub_100BD0E0(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x100BD0E0u))(a0); }
XI_ORIG undefined4 sub_100C4400(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x100C4400u))(a0); }
XI_ORIG int sub_100C51C0(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<int (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x100C51C0u))(a0, a1); }
XI_ORIG undefined4 CXiSkeletonActor_Constructor_1Arg(void * a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x100C52A0u))(a0, a1); }
XI_ORIG char CXiSkeletonActor_DestructorBody(int a0) { return reinterpret_cast<char (__thiscall *)(int)>(XI_GAME(0x100C5C00u))(a0); }
XI_ORIG int sub_100C5D60(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x100C5D60u))(a0); }
XI_ORIG int Actor_SelectNearestLights(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x100CB4E0u))(a0); }
XI_ORIG void PerActor_FourBucketStaggeredUpdate(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x100CBDE0u))(a0); }
XI_ORIG void sub_100CCE60(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x100CCE60u))(a0); }
XI_ORIG void sub_100CFA50(void * a0, XI_ANY a1, XI_ANY a2) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x100CFA50u))(a0, a1, a2); }
XI_ORIG void CXiSkeletonActor_DrawNameIfVisible(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x100D0880u))(a0, a1, a2, a3, a4, a5); }
XI_ORIG unsigned long long CXiSkeletonActor_DrawName2IfVisible(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4) {
    uint32_t xs[3] = {a1.bits, a2.bits, a3.bits}; uint32_t ra = a4.bits, rc = a0.bits, rd = 0;
    __asm__ volatile("pushl 8(%%esi)\n\t""pushl 4(%%esi)\n\t""pushl 0(%%esi)\n\t""call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x100D08B0u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG undefined4 CXiSkeletonActor_AddPartAndMarkSlot(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x100D0B50u))(a0, a1, a2, a3, a4); }
XI_ORIG undefined4 sub_100D0D40(void * a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x100D0D40u))(a0, a1, a2); }
XI_ORIG unsigned long long CXiSkeletonActor_AttachPartResource(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3) {
    uint32_t xs[2] = {a1.bits, a2.bits}; uint32_t ra = a3.bits, rc = a0.bits, rd = 0;
    __asm__ volatile("pushl 4(%%esi)\n\t""pushl 0(%%esi)\n\t""call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x100D0D70u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG void sub_100D0FC0(void * a0, XI_ANY a1, XI_ANY a2) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x100D0FC0u))(a0, a1, a2); }
XI_ORIG undefined4 sub_100D1190(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x100D1190u))(a0); }
XI_ORIG unsigned long long sub_100D12D0(XI_ANY a0, XI_ANY a1) {
    uint32_t xs[1] = {0}; uint32_t ra = a1.bits, rc = a0.bits, rd = 0;
    __asm__ volatile("call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x100D12D0u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG void Unit100D13B0_ProcessResidentListEntries(void * a0, XI_ANY a1, XI_ANY a2) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x100D1450u))(a0, a1, a2); }
XI_ORIG void CXiActor_RequestModelParts(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x100D14C0u))(a0); }
XI_ORIG void sub_100D16C0(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x100D16C0u))(a0); }
XI_ORIG void sub_100D1970(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x100D1970u))(a0); }
XI_ORIG undefined4 sub_100D1C80(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x100D1C80u))(a0); }
XI_ORIG void sub_100D1F70(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x100D1F70u))(a0); }
XI_ORIG void sub_100D2460(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x100D2460u))(a0); }
XI_ORIG void sub_100D2800(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x100D2800u))(a0); }
XI_ORIG int sub_100D2D70(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3) { return reinterpret_cast<int (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x100D2D70u))(a0, a1, a2, a3); }
XI_ORIG int sub_100D2E30(void * a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<int (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x100D2E30u))(a0, a1, a2); }
XI_ORIG char CXiSkeletonActor_LoadSkeletonSync(int a0, int a1) { return reinterpret_cast<char (__thiscall *)(int, int)>(XI_GAME(0x100D2F60u))(a0, a1); }
XI_ORIG undefined4 CXiSkeletonActor_LoadSkeletonSync_v1(void * a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x100D2F60u))(a0, a1); }
XI_ORIG char CXiSkeletonActor_LoadSkeletonResource(void * a0, int a1) { return reinterpret_cast<char (__thiscall *)(void *, int)>(XI_GAME(0x100D4330u))(a0, a1); }
XI_ORIG undefined4 CXiSkeletonActor_LoadSkeletonResource_v1(void * a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x100D4330u))(a0, a1); }
XI_ORIG int sub_100D43E0() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x100D43E0u))(); }
XI_ORIG int sub_100D4410(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4) { return reinterpret_cast<int (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x100D4410u))(a0, a1, a2, a3, a4); }
XI_ORIG int sub_100D44F0(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x100D44F0u))(a0); }
XI_ORIG int sub_100D4520(void * a0, XI_ANY a1) { return reinterpret_cast<int (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x100D4520u))(a0, a1); }
XI_ORIG void sub_100D54C0(void * a0, void * a1, float a2) { reinterpret_cast<void (__thiscall *)(void *, void *, float)>(XI_GAME(0x100D54C0u))(a0, a1, a2); }
XI_ORIG void sub_100D5B10(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x100D5B10u))(a0); }
XI_ORIG int sub_100D6D30(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x100D6D30u))(a0); }
XI_ORIG void * sub_100D7020(void * a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<void * (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x100D7020u))(a0, a1, a2); }
XI_ORIG char sub_100DA6A0(int a0) { return reinterpret_cast<char (__thiscall *)(int)>(XI_GAME(0x100DA6A0u))(a0); }
XI_ORIG undefined4 sub_100DAF30(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x100DAF30u))(a0); }
XI_ORIG int sub_100DB140(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x100DB140u))(a0); }
XI_ORIG int sub_100DB790(int a0) { return reinterpret_cast<int (__stdcall *)(int)>(XI_GAME(0x100DB790u))(a0); }
XI_ORIG undefined4 sub_100DBE10() { return reinterpret_cast<undefined4 (__cdecl *)()>(XI_GAME(0x100DBE10u))(); }
XI_ORIG char sub_100DBE50() { return reinterpret_cast<char (__cdecl *)()>(XI_GAME(0x100DBE50u))(); }
XI_ORIG int sub_100E8B80(XI_ANY a0) { return reinterpret_cast<int (__cdecl *)(XI_ANY)>(XI_GAME(0x100E8B80u))(a0); }
XI_ORIG int sub_100E8C70() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x100E8C70u))(); }
XI_ORIG undefined4 sub_100FC160() { return reinterpret_cast<undefined4 (__cdecl *)()>(XI_GAME(0x100FC160u))(); }
XI_ORIG undefined4 sub_100FC2B0(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x100FC2B0u))(a0); }
XI_ORIG undefined4 sub_100FC300() { return reinterpret_cast<undefined4 (__cdecl *)()>(XI_GAME(0x100FC300u))(); }
XI_ORIG undefined4 sub_100FC320(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x100FC320u))(a0); }
XI_ORIG undefined * sub_100FC510() { return reinterpret_cast<undefined * (__cdecl *)()>(XI_GAME(0x100FC510u))(); }
XI_ORIG undefined4 sub_100FC680(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x100FC680u))(a0, a1); }
XI_ORIG undefined4 sub_100FCB40(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x100FCB40u))(a0); }
XI_ORIG undefined4 sub_100FCB50(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x100FCB50u))(a0); }
XI_ORIG undefined4 sub_100FCB60(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x100FCB60u))(a0); }
XI_ORIG undefined4 sub_100FD3A0(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x100FD3A0u))(a0); }
XI_ORIG int sub_101037F0(int a0, int a1) { return reinterpret_cast<int (__cdecl *)(int, int)>(XI_GAME(0x101037F0u))(a0, a1); }
XI_ORIG int sub_101039E0() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x101039E0u))(); }
XI_ORIG uint32_t sub_10103AE0(XI_ANY a0) { return reinterpret_cast<uint32_t (__cdecl *)(XI_ANY)>(XI_GAME(0x10103AE0u))(a0); }
XI_ORIG undefined4 sub_10103B10(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x10103B10u))(a0); }
XI_ORIG uint32_t sub_10103B30(XI_ANY a0) { return reinterpret_cast<uint32_t (__cdecl *)(XI_ANY)>(XI_GAME(0x10103B30u))(a0); }
XI_ORIG void sub_10117520(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10117520u))(a0); }
XI_ORIG undefined8 Menu_DrawWindowItems(void * a0) { return reinterpret_cast<undefined8 (__thiscall *)(void *)>(XI_GAME(0x101177D0u))(a0); }
XI_ORIG short * sub_10118220(void * a0) { return reinterpret_cast<short * (__thiscall *)(void *)>(XI_GAME(0x10118220u))(a0); }
XI_ORIG undefined8 sub_10118F70(void * a0, XI_ANY a1) { return reinterpret_cast<undefined8 (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x10118F70u))(a0, a1); }
XI_ORIG void sub_10118F70_2(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x10118F70u))(a0, a1); }
XI_ORIG void Unit100D7420_DrawUnscaled(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10119F80u))(a0, a1, a2, a3, a4, a5); }
XI_ORIG undefined8 sub_10119FB0(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5, XI_ANY a6, XI_ANY a7) { return reinterpret_cast<undefined8 (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10119FB0u))(a0, a1, a2, a3, a4, a5, a6, a7); }
XI_ORIG void sub_1011A150(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4) { reinterpret_cast<void (__stdcall *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1011A150u))(a0, a1, a2, a3, a4); }
XI_ORIG void sub_1011A250(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1011A250u))(a0, a1, a2, a3, a4, a5); }
XI_ORIG void Unit100D7420_SetViewport(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1011AA40u))(a0); }
XI_ORIG void Gfx_ApplyViewport1B70() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x1011AAC0u))(); }
XI_ORIG undefined4 sub_1011ABF0(void * a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x1011ABF0u))(a0, a1); }
XI_ORIG undefined4 sub_1011AE80(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x1011AE80u))(a0); }
XI_ORIG undefined8 sub_1011BA40(void * a0) { return reinterpret_cast<undefined8 (__thiscall *)(void *)>(XI_GAME(0x1011BA40u))(a0); }
XI_ORIG int sub_1011BA90(int a0) { return reinterpret_cast<int (__thiscall *)(int)>(XI_GAME(0x1011BA90u))(a0); }
XI_ORIG char Font_BindGlyphTexture(int a0) { return reinterpret_cast<char (__thiscall *)(int)>(XI_GAME(0x1011BAE0u))(a0); }
XI_ORIG undefined4 Font_BindGlyphTexture_v1(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x1011BAE0u))(a0); }
XI_ORIG int Font_DrawGlyphQuadGrey(void * a0, __int16 a1, void * a2, float a3, float a4) { return reinterpret_cast<int (__thiscall *)(void *, __int16, void *, float, float)>(XI_GAME(0x1011BBA0u))(a0, a1, a2, a3, a4); }
XI_ORIG undefined4 Font_DrawGlyphQuadGrey_v1(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1011BBA0u))(a0, a1, a2, a3, a4); }
XI_ORIG undefined4 Font_DrawGlyphQuad(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1011BBD0u))(a0, a1, a2, a3, a4, a5); }
XI_ORIG int Gfx_SetAdditiveBlend() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x1011BDC0u))(); }
XI_ORIG void Gfx_SetAdditiveBlend_v1() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x1011BDC0u))(); }
XI_ORIG void Font_DrawChar(__int16 a0, int a1, int a2, float a3, float a4) { reinterpret_cast<void (__cdecl *)(__int16, int, int, float, float)>(XI_GAME(0x1011BF40u))(a0, a1, a2, a3, a4); }
XI_ORIG undefined8 Obj_104E1B90_DrawString(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5, XI_ANY a6, XI_ANY a7, XI_ANY a8) { return reinterpret_cast<undefined8 (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1011C080u))(a0, a1, a2, a3, a4, a5, a6, a7, a8); }
XI_ORIG int Gfx_SetCellBlendMode(int a0, int a1, int a2, int a3) { return reinterpret_cast<int (__cdecl *)(int, int, int, int)>(XI_GAME(0x1011C1F0u))(a0, a1, a2, a3); }
XI_ORIG int sub_1011C5D0(void * a0, int a1, int a2) { return reinterpret_cast<int (__stdcall *)(void *, int, int)>(XI_GAME(0x1011C5D0u))(a0, a1, a2); }
XI_ORIG char sub_1011C670(void * a0, int a1) { return reinterpret_cast<char (__stdcall *)(void *, int)>(XI_GAME(0x1011C670u))(a0, a1); }
XI_ORIG void Font_LoadHighResTexture(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1011C720u))(a0); }
XI_ORIG int sub_1011C810(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x1011C810u))(a0); }
XI_ORIG uint8_t sub_1011C850(int a0) { return reinterpret_cast<uint8_t (__thiscall *)(int)>(XI_GAME(0x1011C850u))(a0); }
XI_ORIG int sub_1011C870(_DWORD a0) { return reinterpret_cast<int (__thiscall *)(_DWORD)>(XI_GAME(0x1011C870u))(a0); }
XI_ORIG char sub_1011C8B0() { return reinterpret_cast<char (__cdecl *)()>(XI_GAME(0x1011C8B0u))(); }
XI_ORIG __int16 sub_1011CE80(void * a0) { return reinterpret_cast<__int16 (__cdecl *)(void *)>(XI_GAME(0x1011CE80u))(a0); }
XI_ORIG __int16 sub_1011D050(void * a0) { return reinterpret_cast<__int16 (__cdecl *)(void *)>(XI_GAME(0x1011D050u))(a0); }
XI_ORIG char sub_1011D840(unsigned __int16 a0, void * a1) { return reinterpret_cast<char (__cdecl *)(unsigned __int16, void *)>(XI_GAME(0x1011D840u))(a0, a1); }
XI_ORIG int sub_1011DA80(void * a0) { return reinterpret_cast<int (__cdecl *)(void *)>(XI_GAME(0x1011DA80u))(a0); }
XI_ORIG undefined8 Cell_DrawStretchedWrapped(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5, XI_ANY a6, XI_ANY a7, XI_ANY a8, XI_ANY a9, XI_ANY a10, XI_ANY a11) { return reinterpret_cast<undefined8 (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1011EF60u))(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11); }
XI_ORIG int Cell_DrawWithDefaultBlend(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x1011F2D0u))(a0); }
XI_ORIG int Cell_DrawQuadBlended(void * a0, int a1, int a2, int a3, int a4, int a5) { return reinterpret_cast<int (__thiscall *)(void *, int, int, int, int, int)>(XI_GAME(0x1011F300u))(a0, a1, a2, a3, a4, a5); }
XI_ORIG void Cell_DrawQuadBlended_v1(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1011F300u))(a0, a1, a2, a3, a4, a5); }
XI_ORIG undefined8 FUN_1011fb60(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5) { return reinterpret_cast<undefined8 (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1011FB60u))(a0, a1, a2, a3, a4, a5); }
XI_ORIG undefined4 FUN_1011fb60_v1(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1011FB60u))(a0, a1, a2, a3, a4, a5); }
XI_ORIG int Shape_DrawScaled(int a0, int a1, int a2, int a3, int a4, int a5, char a6, int a7, int a8) { return reinterpret_cast<int (__thiscall *)(int, int, int, int, int, int, char, int, int)>(XI_GAME(0x1011FC80u))(a0, a1, a2, a3, a4, a5, a6, a7, a8); }
XI_ORIG undefined8 Shape_DrawScaled_v1(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5, XI_ANY a6, XI_ANY a7, XI_ANY a8) { return reinterpret_cast<undefined8 (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1011FC80u))(a0, a1, a2, a3, a4, a5, a6, a7, a8); }
XI_ORIG void Cell_DrawFirstStretched(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5, XI_ANY a6, XI_ANY a7, XI_ANY a8, XI_ANY a9, XI_ANY a10, XI_ANY a11) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10120000u))(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11); }
XI_ORIG int sub_101200B0(unsigned int a0, unsigned int a1) { return reinterpret_cast<int (__cdecl *)(unsigned int, unsigned int)>(XI_GAME(0x101200B0u))(a0, a1); }
XI_ORIG _DWORD * sub_101201C0(void * a0) { return reinterpret_cast<_DWORD * (__thiscall *)(void *)>(XI_GAME(0x101201C0u))(a0); }
XI_ORIG _DWORD * sub_10120200(void * a0) { return reinterpret_cast<_DWORD * (__thiscall *)(void *)>(XI_GAME(0x10120200u))(a0); }
XI_ORIG char * sub_10120450(void * a0, void * a1) { return reinterpret_cast<char * (__thiscall *)(void *, void *)>(XI_GAME(0x10120450u))(a0, a1); }
XI_ORIG uint8_t sub_10120510(void * a0, unsigned __int8 a1, int a2, void * a3, void * a4, void * a5) { return reinterpret_cast<uint8_t (__thiscall *)(void *, unsigned __int8, int, void *, void *, void *)>(XI_GAME(0x10120510u))(a0, a1, a2, a3, a4, a5); }
XI_ORIG char ShapeMng_BindFontTexture(void * a0, unsigned int a1, void * a2, void * a3) { return reinterpret_cast<char (__thiscall *)(void *, unsigned int, void *, void *)>(XI_GAME(0x10120590u))(a0, a1, a2, a3); }
XI_ORIG char * sub_10120660(void * a0) { return reinterpret_cast<char * (__thiscall *)(void *)>(XI_GAME(0x10120660u))(a0); }
XI_ORIG char * sub_10120880(void * a0) { return reinterpret_cast<char * (__thiscall *)(void *)>(XI_GAME(0x10120880u))(a0); }
XI_ORIG unsigned long long sub_10123A70(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4) {
    uint32_t xs[4] = {a0.bits, a1.bits, a2.bits, a3.bits}; uint32_t ra = a4.bits, rc = 0, rd = 0;
    __asm__ volatile("pushl 12(%%esi)\n\t""pushl 8(%%esi)\n\t""pushl 4(%%esi)\n\t""pushl 0(%%esi)\n\t""call *%%edi\n\t""addl $16, %%esp\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10123A70u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG unsigned long long sub_10123A70_2(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4) {
    uint32_t xs[4] = {a0.bits, a1.bits, a2.bits, a3.bits}; uint32_t ra = a4.bits, rc = 0, rd = 0;
    __asm__ volatile("pushl 12(%%esi)\n\t""pushl 8(%%esi)\n\t""pushl 4(%%esi)\n\t""pushl 0(%%esi)\n\t""call *%%edi\n\t""addl $16, %%esp\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10123A70u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG unsigned long long sub_10123E60(XI_ANY a0, XI_ANY a1) {
    uint32_t xs[1] = {a0.bits}; uint32_t ra = a1.bits, rc = 0, rd = 0;
    __asm__ volatile("pushl 0(%%esi)\n\t""call *%%edi\n\t""addl $4, %%esp\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10123E60u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG void sub_10123E90() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x10123E90u))(); }
XI_ORIG unsigned long long sub_10124700_3(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3) {
    uint32_t xs[2] = {a1.bits, a2.bits}; uint32_t ra = a3.bits, rc = a0.bits, rd = 0;
    __asm__ volatile("pushl 4(%%esi)\n\t""pushl 0(%%esi)\n\t""call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10124700u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG void sub_101248A0(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x101248A0u))(a0); }
XI_ORIG undefined8 sub_10124BC0(void * a0) { return reinterpret_cast<undefined8 (__thiscall *)(void *)>(XI_GAME(0x10124BC0u))(a0); }
XI_ORIG unsigned long long sub_10124EB0(XI_ANY a0, XI_ANY a1, XI_ANY a2) {
    uint32_t xs[1] = {0}; uint32_t ra = a2.bits, rc = a0.bits, rd = a1.bits;
    __asm__ volatile("call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10124EB0u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG void sub_10125360(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10125360u))(a0); }
XI_ORIG void sub_10126480_2(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x10126480u))(a0, a1); }
XI_ORIG undefined4 sub_10126500(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x10126500u))(a0); }
XI_ORIG undefined4 sub_10126510(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x10126510u))(a0); }
XI_ORIG undefined8 sub_10126520(XI_ANY a0) { return reinterpret_cast<undefined8 (__stdcall *)(XI_ANY)>(XI_GAME(0x10126520u))(a0); }
XI_ORIG void sub_101266B0(void * a0, XI_ANY a1, XI_ANY a2) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x101266B0u))(a0, a1, a2); }
XI_ORIG _DWORD * sub_10127190(void * a0) { return reinterpret_cast<_DWORD * (__thiscall *)(void *)>(XI_GAME(0x10127190u))(a0); }
XI_ORIG _DWORD * sub_10127EE0(void * a0) { return reinterpret_cast<_DWORD * (__thiscall *)(void *)>(XI_GAME(0x10127EE0u))(a0); }
XI_ORIG void sub_101304D0(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x101304D0u))(a0); }
XI_ORIG undefined4 sub_1014FF70() { return reinterpret_cast<undefined4 (__cdecl *)()>(XI_GAME(0x1014FF70u))(); }
XI_ORIG undefined4 sub_10150D90(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x10150D90u))(a0); }
XI_ORIG undefined4 sub_10152EF0(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x10152EF0u))(a0, a1); }
XI_ORIG undefined4 sub_10152EF0_2(XI_ANY a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10152EF0u))(a0, a1, a2); }
XI_ORIG int sub_10152F80() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10152F80u))(); }
XI_ORIG undefined4 sub_10152FA0() { return reinterpret_cast<undefined4 (__cdecl *)()>(XI_GAME(0x10152FA0u))(); }
XI_ORIG char sub_10153C10(void * a0) { return reinterpret_cast<char (__thiscall *)(void *)>(XI_GAME(0x10153C10u))(a0); }
XI_ORIG _DWORD * sub_10153FF0() { return reinterpret_cast<_DWORD * (__cdecl *)()>(XI_GAME(0x10153FF0u))(); }
XI_ORIG void sub_10154860(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10154860u))(a0); }
XI_ORIG int sub_10156C30(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5) { return reinterpret_cast<int (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10156C30u))(a0, a1, a2, a3, a4, a5); }
XI_ORIG char sub_10157660(int a0, int a1) { return reinterpret_cast<char (__thiscall *)(int, int)>(XI_GAME(0x10157660u))(a0, a1); }
XI_ORIG int sub_101579C0(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x101579C0u))(a0); }
XI_ORIG int sub_10157CB0(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10157CB0u))(a0); }
XI_ORIG int sub_10157CF0(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10157CF0u))(a0); }
XI_ORIG int sub_10159370(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10159370u))(a0); }
XI_ORIG undefined4 sub_101593C0(XI_ANY a0) { return reinterpret_cast<undefined4 (__stdcall *)(XI_ANY)>(XI_GAME(0x101593C0u))(a0); }
XI_ORIG char sub_10159400(unsigned int a0, int a1) { return reinterpret_cast<char (__cdecl *)(unsigned int, int)>(XI_GAME(0x10159400u))(a0, a1); }
XI_ORIG int sub_1015D900(int a0) { return reinterpret_cast<int (__thiscall *)(int)>(XI_GAME(0x1015D900u))(a0); }
XI_ORIG _DWORD * sub_1015D9E0(void * a0) { return reinterpret_cast<_DWORD * (__thiscall *)(void *)>(XI_GAME(0x1015D9E0u))(a0); }
XI_ORIG undefined4 sub_1015DB10(void * a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x1015DB10u))(a0, a1); }
XI_ORIG void sub_1015DBD0(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x1015DBD0u))(a0, a1); }
XI_ORIG undefined8 sub_1015DCE0(void * a0) { return reinterpret_cast<undefined8 (__thiscall *)(void *)>(XI_GAME(0x1015DCE0u))(a0); }
XI_ORIG undefined4 sub_1015DD90(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x1015DD90u))(a0); }
XI_ORIG undefined4 sub_1015DE50(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x1015DE50u))(a0); }
XI_ORIG int sub_1015DEE0(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x1015DEE0u))(a0); }
XI_ORIG undefined4 sub_1015DEF0(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x1015DEF0u))(a0); }
XI_ORIG void sub_1015DF20(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1015DF20u))(a0); }
XI_ORIG void sub_1015DFC0(int a0) { reinterpret_cast<void (__stdcall *)(int)>(XI_GAME(0x1015DFC0u))(a0); }
XI_ORIG _DWORD * sub_1015E350(void * a0, void * a1, char a2, char a3) { return reinterpret_cast<_DWORD * (__thiscall *)(void *, void *, char, char)>(XI_GAME(0x1015E350u))(a0, a1, a2, a3); }
XI_ORIG unsigned long long sub_1015E530(XI_ANY a0, XI_ANY a1, XI_ANY a2) {
    uint32_t xs[1] = {a1.bits}; uint32_t ra = a2.bits, rc = a0.bits, rd = 0;
    __asm__ volatile("pushl 0(%%esi)\n\t""call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x1015E530u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG unsigned long long sub_1015E6E0_2(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5, XI_ANY a6) {
    uint32_t xs[5] = {a1.bits, a2.bits, a3.bits, a4.bits, a5.bits}; uint32_t ra = a6.bits, rc = a0.bits, rd = 0;
    __asm__ volatile("pushl 16(%%esi)\n\t""pushl 12(%%esi)\n\t""pushl 8(%%esi)\n\t""pushl 4(%%esi)\n\t""pushl 0(%%esi)\n\t""call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x1015E6E0u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG int sub_1015E7E0(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x1015E7E0u))(a0); }
XI_ORIG unsigned long long sub_1015E850_3(XI_ANY a0, XI_ANY a1, XI_ANY a2) {
    uint32_t xs[1] = {a1.bits}; uint32_t ra = a2.bits, rc = a0.bits, rd = 0;
    __asm__ volatile("pushl 0(%%esi)\n\t""call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x1015E850u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG unsigned long long sub_1015E8A0(XI_ANY a0, XI_ANY a1, XI_ANY a2) {
    uint32_t xs[1] = {a1.bits}; uint32_t ra = a2.bits, rc = a0.bits, rd = 0;
    __asm__ volatile("pushl 0(%%esi)\n\t""call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x1015E8A0u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG undefined4 sub_1015ED10(XI_ANY a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<undefined4 (__stdcall *)(XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1015ED10u))(a0, a1, a2); }
XI_ORIG undefined4 sub_1015ED80(void * a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x1015ED80u))(a0, a1); }
XI_ORIG unsigned long long sub_1015EDD0(XI_ANY a0, XI_ANY a1, XI_ANY a2) {
    uint32_t xs[1] = {a1.bits}; uint32_t ra = a2.bits, rc = a0.bits, rd = 0;
    __asm__ volatile("pushl 0(%%esi)\n\t""call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x1015EDD0u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG undefined8 sub_1015EE00(XI_ANY a0) { return reinterpret_cast<undefined8 (__stdcall *)(XI_ANY)>(XI_GAME(0x1015EE00u))(a0); }
XI_ORIG uint32_t sub_1015EE20(XI_ANY a0) { return reinterpret_cast<uint32_t (__stdcall *)(XI_ANY)>(XI_GAME(0x1015EE20u))(a0); }
XI_ORIG void sub_1015EF60(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1015EF60u))(a0); }
XI_ORIG int Menu_DrawLayers(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x1015F6A0u))(a0); }
XI_ORIG undefined4 sub_1015F790(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__stdcall *)(XI_ANY, XI_ANY)>(XI_GAME(0x1015F790u))(a0, a1); }
XI_ORIG undefined4 sub_1015F8F0(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__stdcall *)(XI_ANY, XI_ANY)>(XI_GAME(0x1015F8F0u))(a0, a1); }
XI_ORIG undefined4 sub_1015F960(void * a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x1015F960u))(a0, a1); }
XI_ORIG undefined4 sub_1015F9C0(void * a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x1015F9C0u))(a0, a1); }
XI_ORIG int sub_1015F9E0(void * a0, XI_ANY a1) { return reinterpret_cast<int (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x1015F9E0u))(a0, a1); }
XI_ORIG int sub_1015FA00(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x1015FA00u))(a0); }
XI_ORIG void sub_10160210(void * a0, XI_ANY a1, XI_ANY a2) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x10160210u))(a0, a1, a2); }
XI_ORIG int sub_10160250(void * a0, void * a1, void * a2) { return reinterpret_cast<int (__thiscall *)(void *, void *, void *)>(XI_GAME(0x10160250u))(a0, a1, a2); }
XI_ORIG double sub_10160290(void * a0, char a1) { return reinterpret_cast<double (__thiscall *)(void *, char)>(XI_GAME(0x10160290u))(a0, a1); }
XI_ORIG long double sub_10160290_2(void * a0, XI_ANY a1) { return reinterpret_cast<long double (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x10160290u))(a0, a1); }
XI_ORIG double sub_101602C0(void * a0, char a1) { return reinterpret_cast<double (__thiscall *)(void *, char)>(XI_GAME(0x101602C0u))(a0, a1); }
XI_ORIG void sub_101602F0(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x101602F0u))(a0, a1, a2, a3); }
XI_ORIG int ** sub_10160440(int a0, int a1, void * a2, int a3) { return reinterpret_cast<int ** (__fastcall *)(int, int, void *, int)>(XI_GAME(0x10160440u))(a0, a1, a2, a3); }
XI_ORIG int Gfx_SetDefault2DStates() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x101604B0u))(); }
XI_ORIG void Gfx_SetDefault2DStates_v1() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x101604B0u))(); }
XI_ORIG int Gfx_DisableFogAndAlphaBlend() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10160650u))(); }
XI_ORIG void Gfx_DisableFogAndAlphaBlend_v1() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x10160650u))(); }
XI_ORIG unsigned long long sub_10160700(XI_ANY a0, XI_ANY a1) {
    uint32_t xs[1] = {0}; uint32_t ra = a1.bits, rc = a0.bits, rd = 0;
    __asm__ volatile("call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10160700u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG void sub_10160930() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x10160930u))(); }
XI_ORIG void sub_101609C0() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x101609C0u))(); }
XI_ORIG void sub_10160A50() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x10160A50u))(); }
XI_ORIG unsigned long long sub_10162510(XI_ANY a0, XI_ANY a1) {
    uint32_t xs[1] = {0}; uint32_t ra = a1.bits, rc = a0.bits, rd = 0;
    __asm__ volatile("call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10162510u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG void sub_101630C0(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x101630C0u))(a0); }
XI_ORIG void Obj_10621944_Draw(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x101630E0u))(a0); }
XI_ORIG int Obj_10621944_DrawBgRect(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10163390u))(a0); }
XI_ORIG void Gfx_DrawSolidRect2D(XI_ANY a0, XI_ANY a1) { reinterpret_cast<void (__stdcall *)(XI_ANY, XI_ANY)>(XI_GAME(0x10163400u))(a0, a1); }
XI_ORIG char sub_10165070() { return reinterpret_cast<char (__cdecl *)()>(XI_GAME(0x10165070u))(); }
XI_ORIG signed int sub_101671D0() { return reinterpret_cast<signed int (__cdecl *)()>(XI_GAME(0x101671D0u))(); }
XI_ORIG void sub_101674B0(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x101674B0u))(a0); }
XI_ORIG int sub_101678D0(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x101678D0u))(a0); }
XI_ORIG _DWORD * sub_10167940(void * a0) { return reinterpret_cast<_DWORD * (__thiscall *)(void *)>(XI_GAME(0x10167940u))(a0); }
XI_ORIG void sub_10167950(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10167950u))(a0); }
XI_ORIG void sub_101679A0(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x101679A0u))(a0, a1); }
XI_ORIG float * sub_1016C060(void * a0, int a1, void * a2) { return reinterpret_cast<float * (__cdecl *)(void *, int, void *)>(XI_GAME(0x1016C060u))(a0, a1, a2); }
XI_ORIG int sub_1016FC80(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x1016FC80u))(a0); }
XI_ORIG float * sub_10170B30(void * a0, void * a1, void * a2, void * a3) { return reinterpret_cast<float * (__stdcall *)(void *, void *, void *, void *)>(XI_GAME(0x10170B30u))(a0, a1, a2, a3); }
XI_ORIG _DWORD * sub_10170C80(int a0) { return reinterpret_cast<_DWORD * (__thiscall *)(int)>(XI_GAME(0x10170C80u))(a0); }
XI_ORIG void sub_10170CD0(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x10170CD0u))(a0, a1); }
XI_ORIG int sub_10170E80(int a0, int a1, int a2, int a3) { return reinterpret_cast<int (__stdcall *)(int, int, int, int)>(XI_GAME(0x10170E80u))(a0, a1, a2, a3); }
XI_ORIG int sub_10171920(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10171920u))(a0); }
XI_ORIG void sub_10174A60(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10174A60u))(a0); }
XI_ORIG _DWORD * sub_10175740(void * a0) { return reinterpret_cast<_DWORD * (__cdecl *)(void *)>(XI_GAME(0x10175740u))(a0); }
XI_ORIG float * sub_10175780(void * a0, int a1, void * a2) { return reinterpret_cast<float * (__cdecl *)(void *, int, void *)>(XI_GAME(0x10175780u))(a0, a1, a2); }
XI_ORIG unsigned long long sub_10176DD0(XI_ANY a0, XI_ANY a1) {
    uint32_t xs[1] = {a0.bits}; uint32_t ra = a1.bits, rc = 0, rd = 0;
    __asm__ volatile("pushl 0(%%esi)\n\t""call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10176DD0u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG int sub_10177340(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10177340u))(a0); }
XI_ORIG unsigned int sub_10177350(void * a0) { return reinterpret_cast<unsigned int (__thiscall *)(void *)>(XI_GAME(0x10177350u))(a0); }
XI_ORIG int Gfx_SetZBias(unsigned int a0) { return reinterpret_cast<int (__cdecl *)(unsigned int)>(XI_GAME(0x10177400u))(a0); }
XI_ORIG void Gfx_SetZBias_v1(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x10177400u))(a0); }
XI_ORIG int sub_10177420(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10177420u))(a0); }
XI_ORIG unsigned long long sub_10177800(XI_ANY a0) {
    uint32_t xs[1] = {0}; uint32_t ra = a0.bits, rc = 0, rd = 0;
    __asm__ volatile("call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10177800u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG undefined4 sub_101779B0(void * a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x101779B0u))(a0, a1, a2); }
XI_ORIG int sub_10177D00(int a0) { return reinterpret_cast<int (__thiscall *)(int)>(XI_GAME(0x10177D00u))(a0); }
XI_ORIG void sub_101781D0(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x101781D0u))(a0); }
XI_ORIG void FUN_10178250(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10178250u))(a0); }
XI_ORIG void sub_101784E0() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x101784E0u))(); }
XI_ORIG int * sub_10178760(XI_ANY a0) { return reinterpret_cast<int * (__stdcall *)(XI_ANY)>(XI_GAME(0x10178760u))(a0); }
XI_ORIG void sub_10178790(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10178790u))(a0); }
XI_ORIG void ZoneMap_UpdateLoadState(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x101787C0u))(a0); }
XI_ORIG void ZoneMap_ReleaseSlot(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x10178AC0u))(a0, a1); }
XI_ORIG int ZoneMap_ReleaseStateBlock(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10178B00u))(a0); }
XI_ORIG undefined4 * sub_10178D90(void * a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<undefined4 * (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x10178D90u))(a0, a1, a2); }
XI_ORIG undefined4 sub_10178DD0(XI_ANY a0) { return reinterpret_cast<undefined4 (__stdcall *)(XI_ANY)>(XI_GAME(0x10178DD0u))(a0); }
XI_ORIG void ZoneMap_Reset(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10178F70u))(a0); }
XI_ORIG void ZoneMap_CreateVertexShaders(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x101792A0u))(a0); }
XI_ORIG void sub_1017A630(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1017A630u))(a0); }
XI_ORIG void sub_1017A690(XI_ANY a0) { reinterpret_cast<void (__stdcall *)(XI_ANY)>(XI_GAME(0x1017A690u))(a0); }
XI_ORIG undefined4 ZoneMap_FreeSlot(void * a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x1017B110u))(a0, a1); }
XI_ORIG int ZoneMap_TeardownStep(int a0) { return reinterpret_cast<int (__thiscall *)(int)>(XI_GAME(0x1017B1E0u))(a0); }
XI_ORIG undefined4 ZoneMap_TeardownStep_v1(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x1017B1E0u))(a0); }
XI_ORIG void XiZone_Draw(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1017B510u))(a0); }
XI_ORIG BOOL sub_10181BB0(void * a0, void * a1) { return reinterpret_cast<BOOL (__stdcall *)(void *, void *)>(XI_GAME(0x10181BB0u))(a0, a1); }
XI_ORIG float * CTsZoneMap_DrawProjectedTexture(int a0, void * a1, int a2, void * a3, float a4) { return reinterpret_cast<float * (__thiscall *)(int, void *, int, void *, float)>(XI_GAME(0x10182700u))(a0, a1, a2, a3, a4); }
XI_ORIG undefined4 sub_10183370(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__stdcall *)(XI_ANY, XI_ANY)>(XI_GAME(0x10183370u))(a0, a1); }
XI_ORIG float * XiZone_DrawModelAtMatrix(void * a0, void * a1, int a2) { return reinterpret_cast<float * (__thiscall *)(void *, void *, int)>(XI_GAME(0x10183490u))(a0, a1, a2); }
XI_ORIG _DWORD * ZoneMap_DrawMeshById(int a0, int a1, int a2) { return reinterpret_cast<_DWORD * (__thiscall *)(int, int, int)>(XI_GAME(0x10183DA0u))(a0, a1, a2); }
XI_ORIG unsigned long long FUN_101844c0(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3) {
    uint32_t xs[2] = {a1.bits, a2.bits}; uint32_t ra = a3.bits, rc = a0.bits, rd = 0;
    __asm__ volatile("pushl 4(%%esi)\n\t""pushl 0(%%esi)\n\t""call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x101844C0u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG undefined4 XiZone_DrawGroundShadowQuad(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10184C90u))(a0, a1, a2, a3); }
XI_ORIG undefined4 CTsZoneMap_DrawProjectedShadow(void * a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x10184FE0u))(a0, a1, a2); }
XI_ORIG undefined4 XiZone_DrawDecalOnTriangles(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10185CA0u))(a0, a1, a2, a3, a4); }
XI_ORIG void sub_10186D30(void * a0, XI_ANY a1, XI_ANY a2) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x10186D30u))(a0, a1, a2); }
XI_ORIG void ZoneMap_ClearSlots(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10186DB0u))(a0); }
XI_ORIG void ZoneMap_FreeSubAreas(XI_ANY a0) { reinterpret_cast<void (__stdcall *)(XI_ANY)>(XI_GAME(0x10186DD0u))(a0); }
XI_ORIG void sub_10186E70() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x10186E70u))(); }
XI_ORIG double sub_10186FE0(void * a0) { return reinterpret_cast<double (__thiscall *)(void *)>(XI_GAME(0x10186FE0u))(a0); }
XI_ORIG int sub_10187000(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10187000u))(a0); }
XI_ORIG void FUN_10187030(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10187030u))(a0); }
XI_ORIG void ZoneMap_ReleaseChain(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10187030u))(a0); }
XI_ORIG void sub_10187470(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10187470u))(a0); }
XI_ORIG uint32_t sub_101874A0_2(void * a0) { return reinterpret_cast<uint32_t (__thiscall *)(void *)>(XI_GAME(0x101874A0u))(a0); }
XI_ORIG void sub_101880C0(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x101880C0u))(a0, a1); }
XI_ORIG int sub_101889C0(XI_ANY a0) { return reinterpret_cast<int (__cdecl *)(XI_ANY)>(XI_GAME(0x101889C0u))(a0); }
XI_ORIG void FUN_10188a10(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10188A10u))(a0); }
XI_ORIG undefined4 XiZone_DestroyChildList(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x10188A10u))(a0); }
XI_ORIG _DWORD * sub_10188B70(int a0, void * a1, void * a2) { return reinterpret_cast<_DWORD * (__thiscall *)(int, void *, void *)>(XI_GAME(0x10188B70u))(a0, a1, a2); }
XI_ORIG void sub_10188B70_2(void * a0, XI_ANY a1, XI_ANY a2) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x10188B70u))(a0, a1, a2); }
XI_ORIG int sub_10188CA0(int a0, void * a1, int a2) { return reinterpret_cast<int (__thiscall *)(int, void *, int)>(XI_GAME(0x10188CA0u))(a0, a1, a2); }
XI_ORIG _DWORD * sub_10188E00(void * a0, void * a1, int a2) { return reinterpret_cast<_DWORD * (__thiscall *)(void *, void *, int)>(XI_GAME(0x10188E00u))(a0, a1, a2); }
XI_ORIG void sub_10189120(int a0, void * a1, void * a2, void * a3, int a4) { reinterpret_cast<void (__thiscall *)(int, void *, void *, void *, int)>(XI_GAME(0x10189120u))(a0, a1, a2, a3, a4); }
XI_ORIG void sub_10189490(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10189490u))(a0, a1, a2, a3); }
XI_ORIG void sub_1018A340(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1018A340u))(a0); }
XI_ORIG unsigned long long sub_1018ABB0(XI_ANY a0, XI_ANY a1) {
    uint32_t xs[1] = {a0.bits}; uint32_t ra = a1.bits, rc = 0, rd = 0;
    __asm__ volatile("pushl 0(%%esi)\n\t""call *%%edi\n\t""addl $4, %%esp\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x1018ABB0u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG undefined4 sub_1018ABB0_2(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x1018ABB0u))(a0); }
XI_ORIG void FUN_1018abf0(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1018ABF0u))(a0); }
XI_ORIG void YmCombineWeather_Release(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1018ABF0u))(a0); }
XI_ORIG undefined4 sub_1018AD50(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x1018AD50u))(a0); }
XI_ORIG void sub_1018AD60(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x1018AD60u))(a0, a1); }
XI_ORIG void * sub_1018AD80(void * a0) { return reinterpret_cast<void * (__thiscall *)(void *)>(XI_GAME(0x1018AD80u))(a0); }
XI_ORIG void sub_1018ADA0(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1018ADA0u))(a0); }
XI_ORIG void Blend_Update(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1018ADE0u))(a0); }
XI_ORIG void FUN_1018ade0(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1018ADE0u))(a0); }
XI_ORIG undefined4 sub_1018AEB0(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__stdcall *)(XI_ANY, XI_ANY)>(XI_GAME(0x1018AEB0u))(a0, a1); }
XI_ORIG void sub_1018B130_2() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x1018B130u))(); }
XI_ORIG _DWORD * sub_1018B130() { return reinterpret_cast<_DWORD * (__cdecl *)()>(XI_GAME(0x1018B130u))(); }
XI_ORIG void FUN_1018b620(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1018B620u))(a0); }
XI_ORIG void XiZone_ResetState(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x1018B620u))(a0); }
XI_ORIG int sub_1018B860(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x1018B860u))(a0); }
XI_ORIG void sub_1018B8B0(XI_ANY a0) { reinterpret_cast<void (__stdcall *)(XI_ANY)>(XI_GAME(0x1018B8B0u))(a0); }
XI_ORIG _DWORD * sub_1018B960(void * a0, void * a1, void * a2, int a3) { return reinterpret_cast<_DWORD * (__thiscall *)(void *, void *, void *, int)>(XI_GAME(0x1018B960u))(a0, a1, a2, a3); }
XI_ORIG int sub_1018B9A0(void * a0, void * a1, int a2, int a3) { return reinterpret_cast<int (__thiscall *)(void *, void *, int, int)>(XI_GAME(0x1018B9A0u))(a0, a1, a2, a3); }
XI_ORIG void sub_1018B9A0_2(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1018B9A0u))(a0, a1, a2, a3); }
XI_ORIG int sub_1018B9E0(void * a0, void * a1, int a2, int a3) { return reinterpret_cast<int (__thiscall *)(void *, void *, int, int)>(XI_GAME(0x1018B9E0u))(a0, a1, a2, a3); }
XI_ORIG void sub_1018B9E0_2(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1018B9E0u))(a0, a1, a2, a3); }
XI_ORIG void sub_1018BA20(void * a0, void * a1, void * a2, void * a3, int a4, int a5) { reinterpret_cast<void (__thiscall *)(void *, void *, void *, void *, int, int)>(XI_GAME(0x1018BA20u))(a0, a1, a2, a3, a4, a5); }
XI_ORIG void sub_1018BA20_2(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1018BA20u))(a0, a1, a2, a3, a4, a5); }
XI_ORIG unsigned long long sub_1018BC40(XI_ANY a0, XI_ANY a1, XI_ANY a2) {
    uint32_t xs[1] = {a1.bits}; uint32_t ra = a2.bits, rc = a0.bits, rd = 0;
    __asm__ volatile("pushl 0(%%esi)\n\t""call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x1018BC40u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG undefined4 sub_1018C290_2(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x1018C290u))(a0); }
XI_ORIG unsigned int sub_1018C2B0() { return reinterpret_cast<unsigned int (__cdecl *)()>(XI_GAME(0x1018C2B0u))(); }
XI_ORIG int sub_10193850(int a0) { return reinterpret_cast<int (__cdecl *)(int)>(XI_GAME(0x10193850u))(a0); }
XI_ORIG undefined8 sub_10193850_2(XI_ANY a0) { return reinterpret_cast<undefined8 (__cdecl *)(XI_ANY)>(XI_GAME(0x10193850u))(a0); }
XI_ORIG undefined4 sub_10193850_3(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x10193850u))(a0); }
XI_ORIG undefined4 sub_10193890(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x10193890u))(a0); }
XI_ORIG int sub_1019C3E0() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x1019C3E0u))(); }
XI_ORIG void sub_1019C4F0() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x1019C4F0u))(); }
XI_ORIG int sub_1019C5B0() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x1019C5B0u))(); }
XI_ORIG int sub_1019E290(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5, XI_ANY a6) { return reinterpret_cast<int (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1019E290u))(a0, a1, a2, a3, a4, a5, a6); }
XI_ORIG void sub_1019E550(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5, XI_ANY a6) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1019E550u))(a0, a1, a2, a3, a4, a5, a6); }
XI_ORIG int Unit1018BA60_DrawTextBlockOnce(int a0) { return reinterpret_cast<int (__thiscall *)(int)>(XI_GAME(0x1019EBB0u))(a0); }
XI_ORIG int64_t sub_1019ED10(void * a0) { return reinterpret_cast<int64_t (__thiscall *)(void *)>(XI_GAME(0x1019ED10u))(a0); }
XI_ORIG int64_t sub_1019ED20(void * a0) { return reinterpret_cast<int64_t (__thiscall *)(void *)>(XI_GAME(0x1019ED20u))(a0); }
XI_ORIG int64_t sub_1019ED30(void * a0) { return reinterpret_cast<int64_t (__thiscall *)(void *)>(XI_GAME(0x1019ED30u))(a0); }
XI_ORIG int64_t sub_1019ED50(void * a0, XI_ANY a1) { return reinterpret_cast<int64_t (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x1019ED50u))(a0, a1); }
XI_ORIG int Unit1018BA60_DrawTextLines(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5) { return reinterpret_cast<int (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1019EDB0u))(a0, a1, a2, a3, a4, a5); }
XI_ORIG char sub_101A2E80(int a0) { return reinterpret_cast<char (__thiscall *)(int)>(XI_GAME(0x101A2E80u))(a0); }
XI_ORIG _BYTE * sub_101A8B50() { return reinterpret_cast<_BYTE * (__cdecl *)()>(XI_GAME(0x101A8B50u))(); }
XI_ORIG _DWORD * sub_101A8D40() { return reinterpret_cast<_DWORD * (__cdecl *)()>(XI_GAME(0x101A8D40u))(); }
XI_ORIG int sub_101A8D60() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x101A8D60u))(); }
XI_ORIG Iostream_init * sub_101AB080() { return reinterpret_cast<Iostream_init * (__cdecl *)()>(XI_GAME(0x101AB080u))(); }
XI_ORIG char * sub_101AB0D0() { return reinterpret_cast<char * (__cdecl *)()>(XI_GAME(0x101AB0D0u))(); }
XI_ORIG char sub_101AB770() { return reinterpret_cast<char (__cdecl *)()>(XI_GAME(0x101AB770u))(); }
XI_ORIG unsigned long long sub_101AB7D0_2(XI_ANY a0) {
    uint32_t xs[1] = {0}; uint32_t ra = a0.bits, rc = 0, rd = 0;
    __asm__ volatile("call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x101AB7D0u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG void sub_101AB820(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x101AB820u))(a0); }
XI_ORIG int sub_101AE3E0(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x101AE3E0u))(a0); }
XI_ORIG int sub_101B8E70() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x101B8E70u))(); }
XI_ORIG char sub_101BCE30(int a0) { return reinterpret_cast<char (__thiscall *)(int)>(XI_GAME(0x101BCE30u))(a0); }
XI_ORIG void sub_101C46A0(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x101C46A0u))(a0); }
XI_ORIG undefined4 sub_101C4AC0(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x101C4AC0u))(a0); }
XI_ORIG int sub_101C4AF0(void * a0, int a1) { return reinterpret_cast<int (__thiscall *)(void *, int)>(XI_GAME(0x101C4AF0u))(a0, a1); }
XI_ORIG void sub_101C4C20(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x101C4C20u))(a0); }
XI_ORIG char sub_101C4CC0(void * a0, int a1) { return reinterpret_cast<char (__thiscall *)(void *, int)>(XI_GAME(0x101C4CC0u))(a0, a1); }
XI_ORIG uint8_t sub_101C4CD0(void * a0) { return reinterpret_cast<uint8_t (__thiscall *)(void *)>(XI_GAME(0x101C4CD0u))(a0); }
XI_ORIG int sub_101C4CE0(void * a0, int a1) { return reinterpret_cast<int (__thiscall *)(void *, int)>(XI_GAME(0x101C4CE0u))(a0, a1); }
XI_ORIG int sub_101C4D10(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x101C4D10u))(a0); }
XI_ORIG void sub_101C4D30(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x101C4D30u))(a0); }
XI_ORIG void sub_101C4D40(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x101C4D40u))(a0); }
XI_ORIG undefined4 sub_101C8C30(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x101C8C30u))(a0); }
XI_ORIG undefined4 sub_101C8D10(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x101C8D10u))(a0); }
XI_ORIG void Gfx_ProjectWorldToScreen(XI_ANY a0, XI_ANY a1, XI_ANY a2) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x101C8DA0u))(a0, a1, a2); }
XI_ORIG int sub_101C9550(XI_ANY a0) { return reinterpret_cast<int (__cdecl *)(XI_ANY)>(XI_GAME(0x101C9550u))(a0); }
XI_ORIG undefined8 Unit101C72E0_DrawUnscaled(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3) { return reinterpret_cast<undefined8 (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x101C9780u))(a0, a1, a2, a3); }
XI_ORIG undefined4 Unit101C72E0_DrawUnscaled_v1(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x101C9780u))(a0, a1, a2, a3); }
XI_ORIG undefined8 Unit101C72E0_DrawTextItem0(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5, XI_ANY a6) { return reinterpret_cast<undefined8 (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x101C97B0u))(a0, a1, a2, a3, a4, a5, a6); }
XI_ORIG int Unit101C72E0_DrawTextItem0_v1(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5, XI_ANY a6) { return reinterpret_cast<int (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x101C97B0u))(a0, a1, a2, a3, a4, a5, a6); }
XI_ORIG undefined8 sub_101C9B50(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5, XI_ANY a6) { return reinterpret_cast<undefined8 (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x101C9B50u))(a0, a1, a2, a3, a4, a5, a6); }
XI_ORIG undefined8 Unit101C72E0_DrawString(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4) { return reinterpret_cast<undefined8 (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x101C9D50u))(a0, a1, a2, a3, a4); }
XI_ORIG int Unit101C72E0_DrawTruncated(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3) { return reinterpret_cast<int (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x101CA180u))(a0, a1, a2, a3); }
XI_ORIG void Unit101C72E0_DrawFractionRange(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5, XI_ANY a6, XI_ANY a7, XI_ANY a8, XI_ANY a9) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x101CAD00u))(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9); }
XI_ORIG void Unit101C72E0_DrawFractionDefault(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x101CAEC0u))(a0, a1, a2, a3, a4, a5); }
XI_ORIG undefined8 Unit101C72E0_DrawSmoothed(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5, XI_ANY a6, XI_ANY a7, XI_ANY a8, XI_ANY a9) { return reinterpret_cast<undefined8 (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x101CAF00u))(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9); }
XI_ORIG undefined8 Unit101C72E0_DrawSmoothedDefault(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5) { return reinterpret_cast<undefined8 (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x101CB000u))(a0, a1, a2, a3, a4, a5); }
XI_ORIG void Unit101C72E0_DrawFractionItem1A(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x101CB040u))(a0, a1, a2, a3); }
XI_ORIG undefined8 Unit101C72E0_DrawSmoothedItem1A(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3) { return reinterpret_cast<undefined8 (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x101CB090u))(a0, a1, a2, a3); }
XI_ORIG void sub_101CB0D0(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x101CB0D0u))(a0, a1, a2, a3); }
XI_ORIG undefined4 Unit101C72E0_DrawSmoothedExItem1B(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5, XI_ANY a6, XI_ANY a7) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x101CB230u))(a0, a1, a2, a3, a4, a5, a6, a7); }
XI_ORIG void sub_101CB280(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5, XI_ANY a6, XI_ANY a7, XI_ANY a8, XI_ANY a9, XI_ANY a10) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x101CB280u))(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10); }
XI_ORIG void Unit101C72E0_DrawEasedPercent(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5, XI_ANY a6, XI_ANY a7, XI_ANY a8, XI_ANY a9, XI_ANY a10, XI_ANY a11) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x101CB430u))(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11); }
XI_ORIG void Unit101C72E0_DrawEasedPercentUnitScale(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5, XI_ANY a6, XI_ANY a7) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x101CB500u))(a0, a1, a2, a3, a4, a5, a6, a7); }
XI_ORIG void Unit101C72E0_DrawEasedPercentItem1A(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x101CB550u))(a0, a1, a2, a3); }
XI_ORIG undefined4 Unit101C72E0_BeginCapture(XI_ANY a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x101CB770u))(a0, a1, a2); }
XI_ORIG undefined8 sub_101CC4F0() { return reinterpret_cast<undefined8 (__cdecl *)()>(XI_GAME(0x101CC4F0u))(); }
XI_ORIG int sub_101CC4F0_2() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x101CC4F0u))(); }
XI_ORIG undefined4 sub_101CC510() { return reinterpret_cast<undefined4 (__cdecl *)()>(XI_GAME(0x101CC510u))(); }
XI_ORIG int sub_101D0600(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4) { return reinterpret_cast<int (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x101D0600u))(a0, a1, a2, a3, a4); }
XI_ORIG undefined4 sub_101D08C0(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x101D08C0u))(a0); }
XI_ORIG void sub_101D08D0(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x101D08D0u))(a0); }
XI_ORIG char sub_101D0B00() { return reinterpret_cast<char (__cdecl *)()>(XI_GAME(0x101D0B00u))(); }
XI_ORIG undefined * sub_101D0C40() { return reinterpret_cast<undefined * (__cdecl *)()>(XI_GAME(0x101D0C40u))(); }
XI_ORIG char sub_101D0C70() { return reinterpret_cast<char (__cdecl *)()>(XI_GAME(0x101D0C70u))(); }
XI_ORIG undefined4 Unit101D0910_SaveJpeg512x382(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x101D1000u))(a0); }
XI_ORIG undefined4 YkJpeg_CaptureAndEncode(XI_ANY a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x101D1060u))(a0, a1, a2); }
XI_ORIG undefined4 sub_101D10C0(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x101D10C0u))(a0, a1); }
XI_ORIG undefined4 Unit101D0910_SaveJpegScreenSize(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x101D1100u))(a0); }
XI_ORIG undefined4 sub_101D1180(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x101D1180u))(a0, a1); }
XI_ORIG _WORD * sub_101D11C0() { return reinterpret_cast<_WORD * (__cdecl *)()>(XI_GAME(0x101D11C0u))(); }
XI_ORIG undefined4 sub_101D2260(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x101D2260u))(a0, a1); }
XI_ORIG undefined4 sub_101D29C0(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x101D29C0u))(a0, a1); }
XI_ORIG undefined4 sub_101D30F0(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x101D30F0u))(a0); }
XI_ORIG void Unit101D2FF0_Draw(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x101D3FC0u))(a0, a1); }
XI_ORIG undefined4 sub_101D4A20(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x101D4A20u))(a0); }
XI_ORIG unsigned long long sub_101D5370(XI_ANY a0, XI_ANY a1) {
    uint32_t xs[1] = {0}; uint32_t ra = a1.bits, rc = a0.bits, rd = 0;
    __asm__ volatile("call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x101D5370u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG void Unit101D2FF0_Update(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x101D5680u))(a0); }
XI_ORIG unsigned long long sub_101F71A0(XI_ANY a0) {
    uint32_t xs[1] = {0}; uint32_t ra = a0.bits, rc = 0, rd = 0;
    __asm__ volatile("call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x101F71A0u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG uint32_t sub_101F71C0(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<uint32_t (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x101F71C0u))(a0, a1); }
XI_ORIG undefined4 sub_101F7200(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x101F7200u))(a0); }
XI_ORIG uint32_t sub_101F7260(XI_ANY a0) { return reinterpret_cast<uint32_t (__cdecl *)(XI_ANY)>(XI_GAME(0x101F7260u))(a0); }
XI_ORIG undefined8 sub_10201180(void * a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<undefined8 (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x10201180u))(a0, a1, a2); }
XI_ORIG int sub_102012D0(void * a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<int (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x102012D0u))(a0, a1, a2); }
XI_ORIG void Unit101D7020_DrawCountersAndGauge(void * a0, XI_ANY a1, XI_ANY a2) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x10201340u))(a0, a1, a2); }
XI_ORIG undefined * sub_10202C90(XI_ANY a0) { return reinterpret_cast<undefined * (__stdcall *)(XI_ANY)>(XI_GAME(0x10202C90u))(a0); }
XI_ORIG uint32_t sub_10202CC0(XI_ANY a0) { return reinterpret_cast<uint32_t (__stdcall *)(XI_ANY)>(XI_GAME(0x10202CC0u))(a0); }
XI_ORIG int sub_10203540(XI_ANY a0) { return reinterpret_cast<int (__stdcall *)(XI_ANY)>(XI_GAME(0x10203540u))(a0); }
XI_ORIG _WORD * sub_1021BB90() { return reinterpret_cast<_WORD * (__cdecl *)()>(XI_GAME(0x1021BB90u))(); }
XI_ORIG undefined4 sub_1021C4C0(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x1021C4C0u))(a0); }
XI_ORIG int CXiMovie_DrawFrame(int a0, int a1, int a2, int a3, void * a4) { return reinterpret_cast<int (__cdecl *)(int, int, int, int, void *)>(XI_GAME(0x1021D4C0u))(a0, a1, a2, a3, a4); }
XI_ORIG char sub_1021D980(int a0) { return reinterpret_cast<char (__thiscall *)(int)>(XI_GAME(0x1021D980u))(a0); }
XI_ORIG int sub_1021DDF0(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x1021DDF0u))(a0); }
XI_ORIG void sub_1021ED90() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x1021ED90u))(); }
XI_ORIG unsigned long long sub_1021EDC0(XI_ANY a0) {
    uint32_t xs[1] = {0}; uint32_t ra = a0.bits, rc = 0, rd = 0;
    __asm__ volatile("call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x1021EDC0u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG unsigned long long sub_1021EDD0(XI_ANY a0) {
    uint32_t xs[1] = {0}; uint32_t ra = a0.bits, rc = 0, rd = 0;
    __asm__ volatile("call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x1021EDD0u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG undefined4 sub_1021EDE0() { return reinterpret_cast<undefined4 (__cdecl *)()>(XI_GAME(0x1021EDE0u))(); }
XI_ORIG undefined4 sub_1021EE00(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x1021EE00u))(a0); }
XI_ORIG void sub_1021EE20(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x1021EE20u))(a0); }
XI_ORIG int sub_1021F140(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<int (__stdcall *)(XI_ANY, XI_ANY)>(XI_GAME(0x1021F140u))(a0, a1); }
XI_ORIG void sub_1021F360(XI_ANY a0) { reinterpret_cast<void (__stdcall *)(XI_ANY)>(XI_GAME(0x1021F360u))(a0); }
XI_ORIG void Unit1021D930_DrawActorPanelFigures(XI_ANY a0) { reinterpret_cast<void (__stdcall *)(XI_ANY)>(XI_GAME(0x1021F480u))(a0); }
XI_ORIG void Unit1021D930_DrawEntryRows(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x1021F950u))(a0, a1); }
XI_ORIG undefined4 Unit1021D930_DrawLabelledRow(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5, XI_ANY a6, XI_ANY a7) { return reinterpret_cast<undefined4 (__stdcall *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1021FA90u))(a0, a1, a2, a3, a4, a5, a6, a7); }
XI_ORIG void Unit1021D930_DrawTwoDigitValue(XI_ANY a0, XI_ANY a1, XI_ANY a2) { reinterpret_cast<void (__stdcall *)(XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1021FB10u))(a0, a1, a2); }
XI_ORIG void Unit1021D930_DrawBarRow(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5) { reinterpret_cast<void (__stdcall *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1021FB80u))(a0, a1, a2, a3, a4, a5); }
XI_ORIG void Unit1021D930_DrawNameRows(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5) { reinterpret_cast<void (__stdcall *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1021FBD0u))(a0, a1, a2, a3, a4, a5); }
XI_ORIG void Unit1021D930_DrawLabelBar(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4) { reinterpret_cast<void (__stdcall *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x102201A0u))(a0, a1, a2, a3, a4); }
XI_ORIG int sub_10220350(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10220350u))(a0); }
XI_ORIG undefined4 sub_10220CF0(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x10220CF0u))(a0, a1); }
XI_ORIG int sub_10220EF0(int a0, int a1, int a2, char a3) { return reinterpret_cast<int (__thiscall *)(int, int, int, char)>(XI_GAME(0x10220EF0u))(a0, a1, a2, a3); }
XI_ORIG int sub_10220F40(int a0, int a1, int a2) { return reinterpret_cast<int (__thiscall *)(int, int, int)>(XI_GAME(0x10220F40u))(a0, a1, a2); }
XI_ORIG void Unit1021D930_Draw(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x102214D0u))(a0); }
XI_ORIG uint32_t sub_10221740(void * a0) { return reinterpret_cast<uint32_t (__thiscall *)(void *)>(XI_GAME(0x10221740u))(a0); }
XI_ORIG int sub_10221770(unsigned __int16 a0) { return reinterpret_cast<int (__cdecl *)(unsigned __int16)>(XI_GAME(0x10221770u))(a0); }
XI_ORIG void * sub_102217A0() { return reinterpret_cast<void * (__cdecl *)()>(XI_GAME(0x102217A0u))(); }
XI_ORIG void sub_10222DF0() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x10222DF0u))(); }
XI_ORIG void sub_10226540() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x10226540u))(); }
XI_ORIG undefined4 sub_102270F0(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x102270F0u))(a0); }
XI_ORIG undefined4 sub_10227100(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x10227100u))(a0); }
XI_ORIG undefined4 sub_10227110(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x10227110u))(a0); }
XI_ORIG undefined4 sub_10227130(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x10227130u))(a0); }
XI_ORIG undefined4 sub_10227920(void * a0) { return reinterpret_cast<undefined4 (__thiscall *)(void *)>(XI_GAME(0x10227920u))(a0); }
XI_ORIG int sub_10227930(void * a0, XI_ANY a1) { return reinterpret_cast<int (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x10227930u))(a0, a1); }
XI_ORIG int sub_10228280(void * a0, XI_ANY a1) { return reinterpret_cast<int (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x10228280u))(a0, a1); }
XI_ORIG void sub_102288E0(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x102288E0u))(a0); }
XI_ORIG void sub_10228910(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10228910u))(a0); }
XI_ORIG void sub_1022B290() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x1022B290u))(); }
XI_ORIG void Unit1021D930_DrawProgressBar(void * a0) { reinterpret_cast<void (__thiscall *)(void *)>(XI_GAME(0x10234660u))(a0); }
XI_ORIG undefined8 sub_10234910(void * a0) { return reinterpret_cast<undefined8 (__thiscall *)(void *)>(XI_GAME(0x10234910u))(a0); }
XI_ORIG void sub_10234A90(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5, XI_ANY a6, XI_ANY a7) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10234A90u))(a0, a1, a2, a3, a4, a5, a6, a7); }
XI_ORIG int sub_10239460(void * a0, int a1) { return reinterpret_cast<int (__thiscall *)(void *, int)>(XI_GAME(0x10239460u))(a0, a1); }
XI_ORIG void FUN_102454e0() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x102454E0u))(); }
XI_ORIG void sub_10245520(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x10245520u))(a0); }
XI_ORIG int sub_10245B50(int a0) { return reinterpret_cast<int (__cdecl *)(int)>(XI_GAME(0x10245B50u))(a0); }
XI_ORIG void LobbyThread_ResetZone() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x10245BB0u))(); }
XI_ORIG undefined8 sub_10246160(XI_ANY a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<undefined8 (__stdcall *)(XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10246160u))(a0, a1, a2); }
XI_ORIG undefined4 StAvatarInit(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x1024CF50u))(a0); }
XI_ORIG char sub_1024D130() { return reinterpret_cast<char (__cdecl *)()>(XI_GAME(0x1024D130u))(); }
XI_ORIG uint32_t StAvatar_Teardown(XI_ANY a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<uint32_t (__cdecl *)(XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1024D180u))(a0, a1, a2); }
XI_ORIG undefined4 sub_1024D2C0(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x1024D2C0u))(a0, a1); }
XI_ORIG void sub_1024D400(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x1024D400u))(a0); }
XI_ORIG void sub_1024D470(XI_ANY a0, XI_ANY a1) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x1024D470u))(a0, a1); }
XI_ORIG undefined4 sub_1024D4A0(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x1024D4A0u))(a0, a1); }
XI_ORIG undefined4 sub_1024D540(XI_ANY a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1024D540u))(a0, a1, a2); }
XI_ORIG undefined4 StAvatar_SetPending(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x1024D5C0u))(a0, a1); }
XI_ORIG undefined4 sub_1024D610(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x1024D610u))(a0); }
XI_ORIG void sub_1024D6B0(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x1024D6B0u))(a0); }
XI_ORIG undefined4 sub_1024D740(XI_ANY a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1024D740u))(a0, a1, a2); }
XI_ORIG undefined4 StAvatar_StopAndFreeBuffers(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x1024D790u))(a0); }
XI_ORIG void StAvatar_ResolveItemsAndStart(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x1024D850u))(a0); }
XI_ORIG void sub_1024D9D0() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x1024D9D0u))(); }
XI_ORIG void sub_1024DA10(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x1024DA10u))(a0); }
XI_ORIG undefined4 StAvatar_Update(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x1024DB60u))(a0); }
XI_ORIG void sub_1024DD10(XI_ANY a0, XI_ANY a1) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x1024DD10u))(a0, a1); }
XI_ORIG void StAvatar_SetViewFromDancerCamera(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x1024F900u))(a0); }
XI_ORIG void sub_1024FC10(XI_ANY a0, XI_ANY a1) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x1024FC10u))(a0, a1); }
XI_ORIG void sub_1024FDF0(XI_ANY a0, XI_ANY a1) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x1024FDF0u))(a0, a1); }
XI_ORIG void sub_1024FEC0(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x1024FEC0u))(a0); }
XI_ORIG unsigned long long sub_10250030(XI_ANY a0, XI_ANY a1) {
    uint32_t xs[1] = {a0.bits}; uint32_t ra = a1.bits, rc = 0, rd = 0;
    __asm__ volatile("pushl 0(%%esi)\n\t""call *%%edi\n\t""addl $4, %%esp\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10250030u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG undefined4 StAvatar_RenderIfEnabled(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x10250190u))(a0, a1); }
XI_ORIG void StAvatarRender(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x102501C0u))(a0); }
XI_ORIG int sub_102502D0(void * a0) { return reinterpret_cast<int (__cdecl *)(void *)>(XI_GAME(0x102502D0u))(a0); }
XI_ORIG undefined4 StAvatarFini(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x102504D0u))(a0); }
XI_ORIG undefined4 sub_10250580(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x10250580u))(a0, a1); }
XI_ORIG undefined4 sub_10250660(XI_ANY a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10250660u))(a0, a1, a2); }
XI_ORIG unsigned long long sub_102506C0(XI_ANY a0, XI_ANY a1, XI_ANY a2) {
    uint32_t xs[2] = {a0.bits, a1.bits}; uint32_t ra = a2.bits, rc = 0, rd = 0;
    __asm__ volatile("pushl 4(%%esi)\n\t""pushl 0(%%esi)\n\t""call *%%edi\n\t""addl $8, %%esp\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x102506C0u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG undefined4 sub_10250760(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x10250760u))(a0, a1); }
XI_ORIG undefined4 sub_10250790(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x10250790u))(a0, a1); }
XI_ORIG undefined4 sub_102507C0(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x102507C0u))(a0, a1); }
XI_ORIG undefined4 sub_10250800(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x10250800u))(a0, a1); }
XI_ORIG int sub_10250D80(void * a0) { return reinterpret_cast<int (__cdecl *)(void *)>(XI_GAME(0x10250D80u))(a0); }
XI_ORIG undefined4 sub_10250F10(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x10250F10u))(a0); }
XI_ORIG undefined4 sub_10251180(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x10251180u))(a0); }
XI_ORIG undefined4 sub_10251200(XI_ANY a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10251200u))(a0, a1, a2); }
XI_ORIG undefined4 sub_10251410(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x10251410u))(a0, a1); }
XI_ORIG int StDancer_Update(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10251500u))(a0); }
XI_ORIG int sub_102515F0(void * a0, int a1) { return reinterpret_cast<int (__thiscall *)(void *, int)>(XI_GAME(0x102515F0u))(a0, a1); }
XI_ORIG void StAvatar_SetActive(void * a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10251620u))(a0, a1, a2, a3, a4); }
XI_ORIG void StAvatar_SetStateTeardown(void * a0, XI_ANY a1, XI_ANY a2) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY, XI_ANY)>(XI_GAME(0x102516B0u))(a0, a1, a2); }
XI_ORIG void sub_10251720(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x10251720u))(a0, a1); }
XI_ORIG undefined4 sub_10251750(void * a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x10251750u))(a0, a1); }
XI_ORIG unsigned long long sub_10251780(XI_ANY a0, XI_ANY a1, XI_ANY a2) {
    uint32_t xs[1] = {a1.bits}; uint32_t ra = a2.bits, rc = a0.bits, rd = 0;
    __asm__ volatile("pushl 0(%%esi)\n\t""call *%%edi\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x10251780u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG void sub_10251890(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x10251890u))(a0, a1); }
XI_ORIG void sub_10251920(void * a0, XI_ANY a1) { reinterpret_cast<void (__thiscall *)(void *, XI_ANY)>(XI_GAME(0x10251920u))(a0, a1); }
XI_ORIG int sub_10251960(void * a0) { return reinterpret_cast<int (__thiscall *)(void *)>(XI_GAME(0x10251960u))(a0); }
XI_ORIG uint32_t Dancer_InitDevice(void * a0) { return reinterpret_cast<uint32_t (__thiscall *)(void *)>(XI_GAME(0x10251A80u))(a0); }
XI_ORIG undefined4 sub_10251CE0() { return reinterpret_cast<undefined4 (__cdecl *)()>(XI_GAME(0x10251CE0u))(); }
XI_ORIG int sub_102524B0(void * a0) { return reinterpret_cast<int (__cdecl *)(void *)>(XI_GAME(0x102524B0u))(a0); }
XI_ORIG undefined4 sub_10252610(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x10252610u))(a0, a1); }
XI_ORIG undefined4 StModelItem_Resolve(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x102528D0u))(a0); }
XI_ORIG undefined4 sub_10252A40(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x10252A40u))(a0); }
XI_ORIG int sub_10252C80(void * a0) { return reinterpret_cast<int (__cdecl *)(void *)>(XI_GAME(0x10252C80u))(a0); }
XI_ORIG undefined4 sub_10253160(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x10253160u))(a0); }
XI_ORIG _DWORD * sub_102532E0(void * a0) { return reinterpret_cast<_DWORD * (__thiscall *)(void *)>(XI_GAME(0x102532E0u))(a0); }
XI_ORIG char sub_10253670(__int16 a0, char a1) { return reinterpret_cast<char (__cdecl *)(__int16, char)>(XI_GAME(0x10253670u))(a0, a1); }
XI_ORIG int sub_1025B560(int a0) { return reinterpret_cast<int (__cdecl *)(int)>(XI_GAME(0x1025B560u))(a0); }
XI_ORIG void * sub_1025E0B0() { return reinterpret_cast<void * (__cdecl *)()>(XI_GAME(0x1025E0B0u))(); }
XI_ORIG void sub_1025E0C0() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x1025E0C0u))(); }
XI_ORIG int sub_1025E0E0() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x1025E0E0u))(); }
XI_ORIG char sub_1025E0F0() { return reinterpret_cast<char (__cdecl *)()>(XI_GAME(0x1025E0F0u))(); }
XI_ORIG int sub_1026E400() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x1026E400u))(); }
XI_ORIG _DWORD * sub_1026E460(int a0, int a1) { return reinterpret_cast<_DWORD * (__cdecl *)(int, int)>(XI_GAME(0x1026E460u))(a0, a1); }
XI_ORIG void sub_1026E900() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x1026E900u))(); }
XI_ORIG int sub_10270B60() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10270B60u))(); }
XI_ORIG undefined4 sub_10270F30(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x10270F30u))(a0); }
XI_ORIG void StAvatar_DrawScene() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x102717F0u))(); }
XI_ORIG char sub_10271B40() { return reinterpret_cast<char (__cdecl *)()>(XI_GAME(0x10271B40u))(); }
XI_ORIG undefined4 sub_10271B40_2() { return reinterpret_cast<undefined4 (__cdecl *)()>(XI_GAME(0x10271B40u))(); }
XI_ORIG void sub_10271C60(int a0, int a1) { reinterpret_cast<void (__cdecl *)(int, int)>(XI_GAME(0x10271C60u))(a0, a1); }
XI_ORIG void sub_10271C80(int a0, int a1) { reinterpret_cast<void (__cdecl *)(int, int)>(XI_GAME(0x10271C80u))(a0, a1); }
XI_ORIG _DWORD * sub_10271E90(void * a0) { return reinterpret_cast<_DWORD * (__cdecl *)(void *)>(XI_GAME(0x10271E90u))(a0); }
XI_ORIG int sub_10273370(int a0, void * a1, void * a2) { return reinterpret_cast<int (__cdecl *)(int, void *, void *)>(XI_GAME(0x10273370u))(a0, a1, a2); }
XI_ORIG _DWORD * sub_102738D0(void * a0) { return reinterpret_cast<_DWORD * (__cdecl *)(void *)>(XI_GAME(0x102738D0u))(a0); }
XI_ORIG void sub_10273920(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x10273920u))(a0); }
XI_ORIG int sub_10274D40(int a0, float a1, int a2, int a3, int a4) { return reinterpret_cast<int (__cdecl *)(int, float, int, int, int)>(XI_GAME(0x10274D40u))(a0, a1, a2, a3, a4); }
XI_ORIG int sub_10275090() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10275090u))(); }
XI_ORIG int sub_10275090_2() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10275090u))(); }
XI_ORIG int sub_10275150() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10275150u))(); }
XI_ORIG unsigned long long sub_102755C0(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3) {
    uint32_t xs[2] = {a0.bits, a1.bits}; uint32_t ra = a2.bits, rc = 0, rd = a3.bits;
    __asm__ volatile("pushl 4(%%esi)\n\t""pushl 0(%%esi)\n\t""call *%%edi\n\t""addl $8, %%esp\n\t"
        : "+a"(ra), "+c"(rc), "+d"(rd) : "S"(xs), "D"(XI_GAME(0x102755C0u)) : "memory", "cc", "st", "st(1)", "st(2)", "st(3)", "st(4)", "st(5)", "st(6)", "st(7)");
    return ((unsigned long long)rd << 32) | ra;
}
XI_ORIG void sub_10275B60(int a0, int a1, int a2, void * a3) { reinterpret_cast<void (__cdecl *)(int, int, int, void *)>(XI_GAME(0x10275B60u))(a0, a1, a2, a3); }
XI_ORIG int sub_102760F0(int a0, void * a1, int a2) { return reinterpret_cast<int (__cdecl *)(int, void *, int)>(XI_GAME(0x102760F0u))(a0, a1, a2); }
XI_ORIG undefined4 sub_102760F0_2(XI_ANY a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x102760F0u))(a0, a1, a2); }
XI_ORIG _DWORD * sub_10276260() { return reinterpret_cast<_DWORD * (__cdecl *)()>(XI_GAME(0x10276260u))(); }
XI_ORIG void sub_1027A220(XI_ANY a0, XI_ANY a1) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x1027A220u))(a0, a1); }
XI_ORIG void sub_1027EB10(void * a0, void * a1) { reinterpret_cast<void (__cdecl *)(void *, void *)>(XI_GAME(0x1027EB10u))(a0, a1); }
XI_ORIG float * sub_1027EF20(void * a0, void * a1, void * a2) { return reinterpret_cast<float * (__cdecl *)(void *, void *, void *)>(XI_GAME(0x1027EF20u))(a0, a1, a2); }
XI_ORIG int sub_1027F070(void * a0, void * a1) { return reinterpret_cast<int (__cdecl *)(void *, void *)>(XI_GAME(0x1027F070u))(a0, a1); }
XI_ORIG int sub_1027F0E0(void * a0, int a1) { return reinterpret_cast<int (__cdecl *)(void *, int)>(XI_GAME(0x1027F0E0u))(a0, a1); }
XI_ORIG double sub_1027FCC0(int a0) { return reinterpret_cast<double (__cdecl *)(int)>(XI_GAME(0x1027FCC0u))(a0); }
XI_ORIG float * sub_10280140(void * a0, void * a1, void * a2) { return reinterpret_cast<float * (__cdecl *)(void *, void *, void *)>(XI_GAME(0x10280140u))(a0, a1, a2); }
XI_ORIG int * sqgxSprite(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8) { return reinterpret_cast<int * (__cdecl *)(int, int, int, int, int, int, int, int, int)>(XI_GAME(0x10280DE0u))(a0, a1, a2, a3, a4, a5, a6, a7, a8); }
XI_ORIG void sqgxSprite_v1(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4, XI_ANY a5, XI_ANY a6, XI_ANY a7) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10280DE0u))(a0, a1, a2, a3, a4, a5, a6, a7); }
XI_ORIG void Unit10280C40_CompositeBlendPasses(XI_ANY a0, XI_ANY a1) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x102813B0u))(a0, a1); }
XI_ORIG int sub_10281500() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10281500u))(); }
XI_ORIG int sqgxTextureCreateFromImage(int a0, void * a1) { return reinterpret_cast<int (__cdecl *)(int, void *)>(XI_GAME(0x10281510u))(a0, a1); }
XI_ORIG int sqgxTextureAddZ(int a0, int a1, int a2) { return reinterpret_cast<int (__cdecl *)(int, int, int)>(XI_GAME(0x102816E0u))(a0, a1, a2); }
XI_ORIG int sub_10281810(int a0) { return reinterpret_cast<int (__cdecl *)(int)>(XI_GAME(0x10281810u))(a0); }
XI_ORIG int sqgxTextureAdd(int a0, int a1, void * a2, void * a3) { return reinterpret_cast<int (__cdecl *)(int, int, void *, void *)>(XI_GAME(0x10281830u))(a0, a1, a2, a3); }
XI_ORIG int sqgxTextureAdd_v1(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3) { return reinterpret_cast<int (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10281830u))(a0, a1, a2, a3); }
XI_ORIG int sqgxTextureClutAdd(XI_ANY a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<int (__cdecl *)(XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x102819D0u))(a0, a1, a2); }
XI_ORIG int sub_10281B60(int a0, void * a1, void * a2) { return reinterpret_cast<int (__cdecl *)(int, void *, void *)>(XI_GAME(0x10281B60u))(a0, a1, a2); }
XI_ORIG void sub_10281B60_2(XI_ANY a0, XI_ANY a1, XI_ANY a2) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10281B60u))(a0, a1, a2); }
XI_ORIG _DWORD * sub_10281C20(int a0) { return reinterpret_cast<_DWORD * (__cdecl *)(int)>(XI_GAME(0x10281C20u))(a0); }
XI_ORIG void sub_10281C20_2(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x10281C20u))(a0); }
XI_ORIG int sub_10281C50(int a0) { return reinterpret_cast<int (__cdecl *)(int)>(XI_GAME(0x10281C50u))(a0); }
XI_ORIG void sub_10281C50_2(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x10281C50u))(a0); }
XI_ORIG int sub_10281C80(int a0) { return reinterpret_cast<int (__cdecl *)(int)>(XI_GAME(0x10281C80u))(a0); }
XI_ORIG void sub_10281C80_2(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x10281C80u))(a0); }
XI_ORIG void sqgxTextureClut(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x10281D60u))(a0); }
XI_ORIG int sqgxTextureUpdate() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10281DB0u))(); }
XI_ORIG void sqgxTextureUpdate_v1() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x10281DB0u))(); }
XI_ORIG int sqgxTextureStencilClear(int a0) { return reinterpret_cast<int (__cdecl *)(int)>(XI_GAME(0x10282010u))(a0); }
XI_ORIG int sqgxTextureClear(void * a0, int a1) { return reinterpret_cast<int (__cdecl *)(void *, int)>(XI_GAME(0x10282030u))(a0, a1); }
XI_ORIG void sqgxTextureClear_v1(XI_ANY a0, XI_ANY a1) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x10282030u))(a0, a1); }
XI_ORIG int * sqgxTextureDraw(int a0, char a1) { return reinterpret_cast<int * (__cdecl *)(int, char)>(XI_GAME(0x10282190u))(a0, a1); }
XI_ORIG undefined4 sqgxTextureDraw_v1(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x10282190u))(a0, a1); }
XI_ORIG int * sqgxZTest(int a0) { return reinterpret_cast<int * (__cdecl *)(int)>(XI_GAME(0x10282350u))(a0); }
XI_ORIG void sqgxZTest_v1(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x10282350u))(a0); }
XI_ORIG int sub_102823B0(int a0, int a1) { return reinterpret_cast<int (__cdecl *)(int, int)>(XI_GAME(0x102823B0u))(a0, a1); }
XI_ORIG void sqgxAlphaTest(XI_ANY a0, XI_ANY a1) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x102823F0u))(a0, a1); }
XI_ORIG int * sqgxZMask(int a0) { return reinterpret_cast<int * (__cdecl *)(int)>(XI_GAME(0x10282470u))(a0); }
XI_ORIG void sqgxZMask_v1(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x10282470u))(a0); }
XI_ORIG int * sqgxFBMask(int a0, int a1, int a2, int a3) { return reinterpret_cast<int * (__cdecl *)(int, int, int, int)>(XI_GAME(0x102824C0u))(a0, a1, a2, a3); }
XI_ORIG void sqgxFBMask_v1(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x102824C0u))(a0, a1, a2, a3); }
XI_ORIG int sub_10282630() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10282630u))(); }
XI_ORIG void sqgxBlendAdd(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x102826C0u))(a0); }
XI_ORIG void Unit102822A0_SetMultiplyAdd(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x102827D0u))(a0); }
XI_ORIG void sqgxBlendSub() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x10282910u))(); }
XI_ORIG void sqgxBlendLin(float a0) { reinterpret_cast<void (__cdecl *)(float)>(XI_GAME(0x10282A30u))(a0); }
XI_ORIG void sqgxBlendLin_v1(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x10282A30u))(a0); }
XI_ORIG int sqgxBlendTrsp() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10282B90u))(); }
XI_ORIG void sqgxBlendTrsp_v1() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x10282B90u))(); }
XI_ORIG void sqgxBlendAddDestAlpha() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x10282DC0u))(); }
XI_ORIG void sqgxBlendZeroSrcAlpha() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x10282FF0u))(); }
XI_ORIG int sqgxBlendMul() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10283110u))(); }
XI_ORIG int sqgxBlendOff() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10283220u))(); }
XI_ORIG void sqgxBlendOff_v1() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x10283220u))(); }
XI_ORIG int sub_10283240() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10283240u))(); }
XI_ORIG void sub_10283240_2() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x10283240u))(); }
XI_ORIG int sub_10283250() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10283250u))(); }
XI_ORIG int sub_10283330(void * a0) { return reinterpret_cast<int (__cdecl *)(void *)>(XI_GAME(0x10283330u))(a0); }
XI_ORIG void sub_10283330_2(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x10283330u))(a0); }
XI_ORIG int sub_10283380(float a0) { return reinterpret_cast<int (__cdecl *)(float)>(XI_GAME(0x10283380u))(a0); }
XI_ORIG void sub_10283380_2(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x10283380u))(a0); }
XI_ORIG void sub_102833A0(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x102833A0u))(a0); }
XI_ORIG void sub_102833C0(XI_ANY a0, XI_ANY a1, XI_ANY a2) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x102833C0u))(a0, a1, a2); }
XI_ORIG int sqgxColorUpdate() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10283420u))(); }
XI_ORIG void sqgxColorUpdate_v1() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x10283420u))(); }
XI_ORIG int sub_10283870() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10283870u))(); }
XI_ORIG int sub_102838A0(float a0, float a1) { return reinterpret_cast<int (__cdecl *)(float, float)>(XI_GAME(0x102838A0u))(a0, a1); }
XI_ORIG void sub_10283970(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x10283970u))(a0); }
XI_ORIG int * sqgxViewport(float a0, float a1, float a2, float a3) { return reinterpret_cast<int * (__cdecl *)(float, float, float, float)>(XI_GAME(0x10283A10u))(a0, a1, a2, a3); }
XI_ORIG void sub_10283C10(XI_ANY a0, XI_ANY a1, XI_ANY a2) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10283C10u))(a0, a1, a2); }
XI_ORIG int sub_10283D60(void * a0) { return reinterpret_cast<int (__cdecl *)(void *)>(XI_GAME(0x10283D60u))(a0); }
XI_ORIG void sub_10283D60_2(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x10283D60u))(a0); }
XI_ORIG int sub_10283E00(void * a0) { return reinterpret_cast<int (__cdecl *)(void *)>(XI_GAME(0x10283E00u))(a0); }
XI_ORIG void sub_10283E00_2(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x10283E00u))(a0); }
XI_ORIG void sub_10283F20(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x10283F20u))(a0); }
XI_ORIG int sqgxPassAdd(int a0) { return reinterpret_cast<int (__cdecl *)(int)>(XI_GAME(0x10283F70u))(a0); }
XI_ORIG void sqgxPassAdd_v1(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x10283F70u))(a0); }
XI_ORIG void sqgxPass(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x10283FC0u))(a0); }
XI_ORIG int sqgxMatrixUpdate() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10284410u))(); }
XI_ORIG int sub_10284890() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10284890u))(); }
XI_ORIG int sqgxVertexShaderCreate(void * a0) { return reinterpret_cast<int (__cdecl *)(void *)>(XI_GAME(0x10284950u))(a0); }
XI_ORIG int * sqgxShader(int a0, int a1) { return reinterpret_cast<int * (__cdecl *)(int, int)>(XI_GAME(0x10284B20u))(a0, a1); }
XI_ORIG undefined4 sqgxShader_v1(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x10284B20u))(a0, a1); }
XI_ORIG void sqgxShader_v2(XI_ANY a0, XI_ANY a1) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x10284B20u))(a0, a1); }
XI_ORIG int sub_10284EB0() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10284EB0u))(); }
XI_ORIG int sub_10284EC0() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x10284EC0u))(); }
XI_ORIG void sub_10285740(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x10285740u))(a0); }
XI_ORIG void * sub_10285850(int a0) { return reinterpret_cast<void * (__cdecl *)(int)>(XI_GAME(0x10285850u))(a0); }
XI_ORIG void sub_10285850_2(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x10285850u))(a0); }
template <class... R> XI_ORIG void sub_10285890(void * a0, R... rest) { reinterpret_cast<void (__cdecl *)(void *, ...)>(XI_GAME(0x10285890u))(a0, rest...); }
template <class... R> XI_ORIG undefined8 sub_10285890_2(XI_ANY a0, R... rest) { return reinterpret_cast<undefined8 (__cdecl *)(XI_ANY, decltype(XI_ANY(rest))...)>(XI_GAME(0x10285890u))(a0, XI_ANY(rest)...); }
XI_ORIG int SqmdDMB_Resolve(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<int (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x10287FB0u))(a0, a1); }
XI_ORIG int sub_10288660(XI_ANY a0) { return reinterpret_cast<int (__cdecl *)(XI_ANY)>(XI_GAME(0x10288660u))(a0); }
XI_ORIG uint32_t sub_10288680(XI_ANY a0) { return reinterpret_cast<uint32_t (__cdecl *)(XI_ANY)>(XI_GAME(0x10288680u))(a0); }
XI_ORIG uint32_t SqmdDMB_ResolveTextures(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<uint32_t (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x102886D0u))(a0, a1); }
XI_ORIG int * sub_10288950(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<int * (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x10288950u))(a0, a1); }
XI_ORIG undefined4 sub_10288BB0(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x10288BB0u))(a0, a1); }
XI_ORIG char * sub_10288C20(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<char * (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x10288C20u))(a0, a1); }
XI_ORIG void sub_10288DC0(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x10288DC0u))(a0); }
XI_ORIG void sub_10288E00(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x10288E00u))(a0); }
XI_ORIG uint8_t * FUN_10288e60(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<uint8_t * (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x10288E60u))(a0, a1); }
XI_ORIG uint8_t * sub_10288FF0(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<uint8_t * (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x10288FF0u))(a0, a1); }
XI_ORIG int sub_1028A730(int a0, int a1) { return reinterpret_cast<int (__cdecl *)(int, int)>(XI_GAME(0x1028A730u))(a0, a1); }
XI_ORIG int sub_1028A770(int a0, int a1) { return reinterpret_cast<int (__cdecl *)(int, int)>(XI_GAME(0x1028A770u))(a0, a1); }
XI_ORIG int sub_1028A790(int a0) { return reinterpret_cast<int (__cdecl *)(int)>(XI_GAME(0x1028A790u))(a0); }
XI_ORIG int * sqgxShapeBegin() { return reinterpret_cast<int * (__cdecl *)()>(XI_GAME(0x1028AFE0u))(); }
XI_ORIG int sub_1028BB10(int a0) { return reinterpret_cast<int (__cdecl *)(int)>(XI_GAME(0x1028BB10u))(a0); }
XI_ORIG int sub_1028BB70() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x1028BB70u))(); }
XI_ORIG int sub_1028BBD0() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x1028BBD0u))(); }
XI_ORIG void sub_1028D9C0(XI_ANY a0, XI_ANY a1) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x1028D9C0u))(a0, a1); }
XI_ORIG void SqsnScene_DrawMatrixShape(XI_ANY a0, XI_ANY a1) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x1028F4C0u))(a0, a1); }
XI_ORIG int sub_1028F5F0(int a0, int a1, int a2) { return reinterpret_cast<int (__cdecl *)(int, int, int)>(XI_GAME(0x1028F5F0u))(a0, a1, a2); }
XI_ORIG void sub_1028F5F0_2(XI_ANY a0, XI_ANY a1, XI_ANY a2) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1028F5F0u))(a0, a1, a2); }
XI_ORIG void sub_1028F6E0(XI_ANY a0, XI_ANY a1) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x1028F6E0u))(a0, a1); }
XI_ORIG void sqsnSceneDraw(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x1028F8C0u))(a0); }
XI_ORIG int sqsnSceneLayerDraw(void * a0, int a1) { return reinterpret_cast<int (__cdecl *)(void *, int)>(XI_GAME(0x1028FDD0u))(a0, a1); }
XI_ORIG void SqsnScene_DrawFadeSprite(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x1028FF80u))(a0); }
XI_ORIG int sqsnSceneLayerDrawShadowed(void * a0, int a1) { return reinterpret_cast<int (__cdecl *)(void *, int)>(XI_GAME(0x1028FFF0u))(a0, a1); }
XI_ORIG int sqsnSceneLayerSnapShotComposite(int a0, int a1) { return reinterpret_cast<int (__cdecl *)(int, int)>(XI_GAME(0x102902C0u))(a0, a1); }
XI_ORIG int sub_10290430(_DWORD a0, _DWORD a1) { return reinterpret_cast<int (__cdecl *)(_DWORD, _DWORD)>(XI_GAME(0x10290430u))(a0, a1); }
XI_ORIG int sub_10290440(int a0, int a1) { return reinterpret_cast<int (__cdecl *)(int, int)>(XI_GAME(0x10290440u))(a0, a1); }
XI_ORIG int * sqsdGeneric_BakeOntoShape(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<int * (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x10290FC0u))(a0, a1); }
XI_ORIG int sub_102911E0(void * a0) { return reinterpret_cast<int (__cdecl *)(void *)>(XI_GAME(0x102911E0u))(a0); }
XI_ORIG void sub_102911E0_2(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x102911E0u))(a0); }
XI_ORIG void sub_102912F0(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x102912F0u))(a0); }
XI_ORIG void sub_102972D0(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x102972D0u))(a0); }
XI_ORIG int sub_10297320(int a0, int a1, int a2) { return reinterpret_cast<int (__cdecl *)(int, int, int)>(XI_GAME(0x10297320u))(a0, a1, a2); }
XI_ORIG unsigned int sub_102979E0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, void * a8, float a9, int a10) { return reinterpret_cast<unsigned int (__cdecl *)(int, int, int, int, int, int, int, int, void *, float, int)>(XI_GAME(0x102979E0u))(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10); }
XI_ORIG int sub_10297B10(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, void * a8, float a9, int a10) { return reinterpret_cast<int (__cdecl *)(int, int, int, int, int, int, int, int, void *, float, int)>(XI_GAME(0x10297B10u))(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10); }
XI_ORIG int sqsnShadowVolumeSetPass(int a0) { return reinterpret_cast<int (__cdecl *)(int)>(XI_GAME(0x10297CC0u))(a0); }
XI_ORIG int sub_10297F90(int a0, void * a1, int a2, int a3, void * a4, int a5, void * a6) { return reinterpret_cast<int (__cdecl *)(int, void *, int, int, void *, int, void *)>(XI_GAME(0x10297F90u))(a0, a1, a2, a3, a4, a5, a6); }
XI_ORIG int sqsnShadowVolumeBeginVB() { return reinterpret_cast<int (__cdecl *)()>(XI_GAME(0x102981E0u))(); }
XI_ORIG int sub_10298350(int a0) { return reinterpret_cast<int (__cdecl *)(int)>(XI_GAME(0x10298350u))(a0); }
XI_ORIG undefined4 * sub_102984B0() { return reinterpret_cast<undefined4 * (__cdecl *)()>(XI_GAME(0x102984B0u))(); }
XI_ORIG undefined4 * sub_10298B30() { return reinterpret_cast<undefined4 * (__cdecl *)()>(XI_GAME(0x10298B30u))(); }
XI_ORIG void sub_10298C50(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x10298C50u))(a0); }
XI_ORIG int Texture_CreateEntry(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4) { return reinterpret_cast<int (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10298E10u))(a0, a1, a2, a3, a4); }
XI_ORIG int sqsdSampling_BakeOntoShape(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<int (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x10299250u))(a0, a1); }
XI_ORIG int * sqsdAniso_BakeOntoShape(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<int * (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x10299610u))(a0, a1); }
XI_ORIG undefined4 sub_10299840() { return reinterpret_cast<undefined4 (__cdecl *)()>(XI_GAME(0x10299840u))(); }
XI_ORIG undefined4 SqsdGlow_ApplyShader(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x102999A0u))(a0, a1); }
XI_ORIG int * sqsdGlow_BakeOntoShape(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<int * (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x10299AB0u))(a0, a1); }
XI_ORIG undefined4 sub_10299B30(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x10299B30u))(a0, a1); }
XI_ORIG void sub_1029B5C0() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x1029B5C0u))(); }
XI_ORIG undefined4 * FUN_1029b620() { return reinterpret_cast<undefined4 * (__cdecl *)()>(XI_GAME(0x1029B620u))(); }
XI_ORIG void sub_1029BCD0(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x1029BCD0u))(a0); }
XI_ORIG void sub_1029BD40(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x1029BD40u))(a0); }
XI_ORIG int sub_1029BD50(int a0, int a1, void * a2, void * a3) { return reinterpret_cast<int (__cdecl *)(int, int, void *, void *)>(XI_GAME(0x1029BD50u))(a0, a1, a2, a3); }
XI_ORIG int sub_1029BF50(int a0, void * a1, void * a2) { return reinterpret_cast<int (__cdecl *)(int, void *, void *)>(XI_GAME(0x1029BF50u))(a0, a1, a2); }
XI_ORIG undefined4 * sub_1029C260(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4) { return reinterpret_cast<undefined4 * (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x1029C260u))(a0, a1, a2, a3, a4); }
XI_ORIG void sub_1029C460(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x1029C460u))(a0); }
XI_ORIG float * sub_1029C480(int a0, void * a1, void * a2, int a3, int a4, void * a5, void * a6) { return reinterpret_cast<float * (__cdecl *)(int, void *, void *, int, int, void *, void *)>(XI_GAME(0x1029C480u))(a0, a1, a2, a3, a4, a5, a6); }
XI_ORIG void sub_1029C610(int a0, void * a1, int a2, int a3) { reinterpret_cast<void (__cdecl *)(int, void *, int, int)>(XI_GAME(0x1029C610u))(a0, a1, a2, a3); }
XI_ORIG int sub_1029C950(int a0, int a1, void * a2, void * a3, void * a4, void * a5) { return reinterpret_cast<int (__cdecl *)(int, int, void *, void *, void *, void *)>(XI_GAME(0x1029C950u))(a0, a1, a2, a3, a4, a5); }
XI_ORIG void FUN_102a1f20(XI_ANY a0, XI_ANY a1) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x102A1F20u))(a0, a1); }
XI_ORIG undefined4 sub_102A1FA0(XI_ANY a0) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY)>(XI_GAME(0x102A1FA0u))(a0); }
XI_ORIG undefined4 * sub_102A2000() { return reinterpret_cast<undefined4 * (__cdecl *)()>(XI_GAME(0x102A2000u))(); }
XI_ORIG void sub_102A2130(XI_ANY a0, XI_ANY a1) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x102A2130u))(a0, a1); }
XI_ORIG undefined4 sub_102A2160(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x102A2160u))(a0, a1); }
XI_ORIG undefined4 sub_102A2190(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x102A2190u))(a0, a1); }
XI_ORIG void sqsnPlanarShadowDraw(XI_ANY a0, XI_ANY a1) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x102A2530u))(a0, a1); }
XI_ORIG void Unit102A2530_RenderShadowTexture(XI_ANY a0, XI_ANY a1) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x102A2720u))(a0, a1); }
XI_ORIG void sub_102A2A30(XI_ANY a0, XI_ANY a1) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x102A2A30u))(a0, a1); }
XI_ORIG void sub_102A2A50(XI_ANY a0, XI_ANY a1, XI_ANY a2) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x102A2A50u))(a0, a1, a2); }
XI_ORIG void Unit102A2530_DrawShadowedShape(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3) { reinterpret_cast<void (__cdecl *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x102A2C00u))(a0, a1, a2, a3); }
XI_ORIG void sub_102A34D0(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x102A34D0u))(a0); }
XI_ORIG void sub_102A3540(XI_ANY a0) { reinterpret_cast<void (__cdecl *)(XI_ANY)>(XI_GAME(0x102A3540u))(a0); }
XI_ORIG void sub_102A3760() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x102A3760u))(); }
XI_ORIG void sub_102A3770() { reinterpret_cast<void (__cdecl *)()>(XI_GAME(0x102A3770u))(); }
XI_ORIG int sub_102D2600(_DWORD a0) { return reinterpret_cast<int (__stdcall *)(_DWORD)>(XI_GAME(0x102D2600u))(a0); }
XI_ORIG int sub_102D2868(void * a0, void * a1, void * a2, int a3, int a4, int a5, int a6, void * a7, int a8, int a9) { return reinterpret_cast<int (__stdcall *)(void *, void *, void *, int, int, int, int, void *, int, int)>(XI_GAME(0x102D2868u))(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9); }
XI_ORIG int sub_102D2FB9(void * a0, unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, _D3DFORMAT a5, __int32 a6, void * a7) { return reinterpret_cast<int (__stdcall *)(void *, unsigned int, unsigned int, unsigned int, unsigned int, _D3DFORMAT, __int32, void *)>(XI_GAME(0x102D2FB9u))(a0, a1, a2, a3, a4, a5, a6, a7); }
XI_ORIG int sub_102D4515(void * a0, void * a1, void * a2, void * a3, void * a4, void * a5, int a6, int a7) { return reinterpret_cast<int (__stdcall *)(void *, void *, void *, void *, void *, void *, int, int)>(XI_GAME(0x102D4515u))(a0, a1, a2, a3, a4, a5, a6, a7); }
XI_ORIG float * sub_102D7FF9_2(void * a0, void * a1, void * a2, void * a3) { return reinterpret_cast<float * (__stdcall *)(void *, void *, void *, void *)>(XI_GAME(0x102D7FF9u))(a0, a1, a2, a3); }
XI_ORIG int sub_102D83C6(int a0, float a1, float a2, float a3, float a4) { return reinterpret_cast<int (__stdcall *)(int, float, float, float, float)>(XI_GAME(0x102D83C6u))(a0, a1, a2, a3, a4); }
XI_ORIG undefined4 sub_102D83C6_2(XI_ANY a0, XI_ANY a1, XI_ANY a2, XI_ANY a3, XI_ANY a4) { return reinterpret_cast<undefined4 (__stdcall *)(XI_ANY, XI_ANY, XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x102D83C6u))(a0, a1, a2, a3, a4); }
XI_ORIG int sub_102DA79B(void * a0, unsigned int a1, void * a2, void * a3, void * a4) { return reinterpret_cast<int (__stdcall *)(void *, unsigned int, void *, void *, void *)>(XI_GAME(0x102DA79Bu))(a0, a1, a2, a3, a4); }
XI_ORIG int sub_102DAA0D(void * a0, char a1, unsigned int a2, void * a3, void * a4, void * a5) { return reinterpret_cast<int (__stdcall *)(void *, char, unsigned int, void *, void *, void *)>(XI_GAME(0x102DAA0Du))(a0, a1, a2, a3, a4, a5); }
XI_ORIG int sub_102DAA71(int a0, void * a1, unsigned int a2) { return reinterpret_cast<int (__stdcall *)(int, void *, unsigned int)>(XI_GAME(0x102DAA71u))(a0, a1, a2); }
XI_ORIG void sub_10311BB0(void * a0) { reinterpret_cast<void (__cdecl *)(void *)>(XI_GAME(0x10311BB0u))(a0); }
XI_ORIG undefined8 sub_10311BB0_2(XI_ANY a0) { return reinterpret_cast<undefined8 (__cdecl *)(XI_ANY)>(XI_GAME(0x10311BB0u))(a0); }
XI_ORIG void * sub_10311BBB(unsigned int a0) { return reinterpret_cast<void * (__cdecl *)(unsigned int)>(XI_GAME(0x10311BBBu))(a0); }
XI_ORIG undefined8 sub_10311BBB_2(XI_ANY a0) { return reinterpret_cast<undefined8 (__cdecl *)(XI_ANY)>(XI_GAME(0x10311BBBu))(a0); }
XI_ORIG void * sub_10311BBB_4(XI_ANY a0) { return reinterpret_cast<void * (__cdecl *)(XI_ANY)>(XI_GAME(0x10311BBBu))(a0); }
XI_ORIG uint32_t sub_10311C7A(XI_ANY a0, XI_ANY a1) { return reinterpret_cast<uint32_t (__cdecl *)(XI_ANY, XI_ANY)>(XI_GAME(0x10311C7Au))(a0, a1); }
template <class... R> XI_ORIG undefined8 sub_10311FF1(XI_ANY a0, XI_ANY a1, R... rest) { return reinterpret_cast<undefined8 (__cdecl *)(XI_ANY, XI_ANY, decltype(XI_ANY(rest))...)>(XI_GAME(0x10311FF1u))(a0, a1, XI_ANY(rest)...); }
template <class... R> XI_ORIG undefined4 sub_10311FF1_2(XI_ANY a0, XI_ANY a1, R... rest) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY, decltype(XI_ANY(rest))...)>(XI_GAME(0x10311FF1u))(a0, a1, XI_ANY(rest)...); }
XI_ORIG char * sub_103127C0(void * a0, int a1) { return reinterpret_cast<char * (__cdecl *)(void *, int)>(XI_GAME(0x103127C0u))(a0, a1); }
XI_ORIG void * sub_10312F96(size_t a0) { return reinterpret_cast<void * (__cdecl *)(size_t)>(XI_GAME(0x10312F96u))(a0); }
XI_ORIG int sub_10313486(void * a0) { return reinterpret_cast<int (__cdecl *)(void *)>(XI_GAME(0x10313486u))(a0); }
XI_ORIG int sub_10313486_2(XI_ANY a0) { return reinterpret_cast<int (__cdecl *)(XI_ANY)>(XI_GAME(0x10313486u))(a0); }
template <class... R> XI_ORIG int sub_103134C7(void * a0, const size_t a1, void * a2, R... rest) { return reinterpret_cast<int (__cdecl *)(void *, const size_t, void *, ...)>(XI_GAME(0x103134C7u))(a0, a1, a2, rest...); }
XI_ORIG undefined4 sub_10314D55(XI_ANY a0, XI_ANY a1, XI_ANY a2) { return reinterpret_cast<undefined4 (__cdecl *)(XI_ANY, XI_ANY, XI_ANY)>(XI_GAME(0x10314D55u))(a0, a1, a2); }
XI_ORIG char * sub_10315AA8(void * a0) { return reinterpret_cast<char * (__cdecl *)(void *)>(XI_GAME(0x10315AA8u))(a0); }
}  // namespace orig
// a game function used as a value (callback, table entry): its address in the game image
namespace orig_addr {
constexpr uint32_t CApp_RunMainLoop = 0x10001520u;
constexpr uint32_t App_RenderFrameMaskedFPU = 0x10001B50u;
constexpr uint32_t App_RenderFrameMaskedFPU_v1 = 0x10001B50u;
constexpr uint32_t Gfx_CopySurfaceRectToTexture = 0x10002040u;
constexpr uint32_t Gfx_ProbeDeviceCaps = 0x10002130u;
constexpr uint32_t Gfx_TryCreateDeviceForMode = 0x100033C0u;
constexpr uint32_t Gfx_CreateDevice = 0x100034B0u;
constexpr uint32_t DebugOverlay_Update = 0x10003710u;
constexpr uint32_t Unit10003890_DrawActorAxes = 0x10003890u;
constexpr uint32_t Debug_DrawTextTable = 0x10003B60u;
constexpr uint32_t Debug_DrawWorldText = 0x10003D70u;
constexpr uint32_t CDx_Initialize = 0x100091B0u;
constexpr uint32_t CDx_EndClearBegin = 0x100096B0u;
constexpr uint32_t CDx_EndClearBegin_v1 = 0x100096B0u;
constexpr uint32_t CDx_TestCooperativeLevel = 0x10009710u;
constexpr uint32_t CDx_Present = 0x10009720u;
constexpr uint32_t CDx_BeginScene = 0x10009730u;
constexpr uint32_t CDx_EndScene = 0x10009740u;
constexpr uint32_t CDx_SetDefaultRenderState = 0x10009920u;
constexpr uint32_t CDx_SetViewport = 0x10009DC0u;
constexpr uint32_t CDx_PushRenderTarget = 0x10009E20u;
constexpr uint32_t CDx_PushRenderTarget_v1 = 0x10009E20u;
constexpr uint32_t CDx_PushRenderTargetTexture_Flag1 = 0x10009EA0u;
constexpr uint32_t CDx_PushRenderTargetTexture_Flag0 = 0x10009EE0u;
constexpr uint32_t CDx_PushRenderTargetTexture = 0x10009F20u;
constexpr uint32_t CDx_PushRenderTargetTexture_v1 = 0x10009F20u;
constexpr uint32_t CDx_SetTexture = 0x1000A1D0u;
constexpr uint32_t CDx_SetTexture_v1 = 0x1000A1D0u;
constexpr uint32_t CDx_EndAndClearBegin = 0x1000A390u;
constexpr uint32_t CDx_DrawScreenQuadAtDepth = 0x1000A3B0u;
constexpr uint32_t CDx_DrawTextureToViewport = 0x1000A4F0u;
constexpr uint32_t CDx_DrawTexturedScreenQuadUnit = 0x1000A550u;
constexpr uint32_t CDx_DrawTexturedScreenQuad = 0x1000A5A0u;
constexpr uint32_t CDx_DrawTexturedScreenQuad_v1 = 0x1000A5A0u;
constexpr uint32_t CDx_CreateTexture = 0x1000A6E0u;
constexpr uint32_t CDx_CreateTexture_v1 = 0x1000A6E0u;
constexpr uint32_t CDx_PushRenderTargetRet1 = 0x1000A800u;
constexpr uint32_t CDx_DrawFadeQuad = 0x1000A820u;
constexpr uint32_t Post_DepthBlurComposite = 0x1000AAB0u;
constexpr uint32_t sub_1000ABE0 = 0x1000ABE0u;
constexpr uint32_t CDx_DrawStereoOddFrameOverlay = 0x1000BB90u;
constexpr uint32_t CDx_SetTransform = 0x1000BD50u;
constexpr uint32_t CDx_SetTransform_v1 = 0x1000BD50u;
constexpr uint32_t CDx_SetLight = 0x1000BF30u;
constexpr uint32_t CDx_SetLight_v1 = 0x1000BF30u;
constexpr uint32_t CDx_CompositeSceneToBackBuffer = 0x1000C0B0u;
constexpr uint32_t CDx_CreateStereoResources = 0x1000C6E0u;
constexpr uint32_t CDx_CreateRampTexture1x16 = 0x1000C850u;
constexpr uint32_t CDx_CreateRampTextures1024x2 = 0x1000C900u;
constexpr uint32_t CDx_GetStereoSecondEyeTarget = 0x1000CA00u;
constexpr uint32_t CDx_DrawPrimitive = 0x1000CB20u;
constexpr uint32_t CDx_DrawPrimitive_v1 = 0x1000CB20u;
constexpr uint32_t CDx_DrawIndexedPrimitive = 0x1000CC00u;
constexpr uint32_t CDx_DrawPrimitiveUP = 0x1000CD00u;
constexpr uint32_t CDx_DrawPrimitiveUP_v1 = 0x1000CD00u;
constexpr uint32_t CDx_ApplyStereoEyeProjection = 0x1000CF20u;
constexpr uint32_t CDx_RestoreProjection = 0x1000CF90u;
constexpr uint32_t App_InitScene = 0x10010D20u;
constexpr uint32_t Frame_Render = 0x10011A00u;
constexpr uint32_t Post_Afterimage = 0x10012F40u;
constexpr uint32_t Post_FlashAndZoomFeedback = 0x100132B0u;
constexpr uint32_t App_StepGameState5Connect = 0x10013AD0u;
constexpr uint32_t App_DispatchSubState = 0x10014170u;
constexpr uint32_t Unit10014350_RunStepThenLoadAll = 0x10014350u;
constexpr uint32_t Camera_ReleaseAll = 0x10014C10u;
constexpr uint32_t Camera_ApplyViewProjection = 0x10015510u;
constexpr uint32_t App_CreateRendererAndApp = 0x100161B0u;
constexpr uint32_t App_RunMainLoopThenSetPtr = 0x10016300u;
constexpr uint32_t App_DestroyGlobalObjects = 0x10016320u;
constexpr uint32_t GammaRamp_ApplyIfChanged = 0x10017230u;
constexpr uint32_t CShader_Destructor = 0x100177A0u;
constexpr uint32_t Unit10017C10_Step = 0x10017C20u;
constexpr uint32_t Unit10017C10_Begin = 0x10017C60u;
constexpr uint32_t Model_CreateTranslucentTargets = 0x1001D0A0u;
constexpr uint32_t Model_BeginTranslucentPass = 0x1001D240u;
constexpr uint32_t Model_TranslucentUnbindTexture = 0x1001D350u;
constexpr uint32_t Model_CompositeTranslucentPass = 0x1001D3B0u;
constexpr uint32_t Gfx_DrawScreenQuad256 = 0x1001DD00u;
constexpr uint32_t CYyModelDt_PrepareRenderState = 0x100224D0u;
constexpr uint32_t Unit10025220_Init = 0x10025260u;
constexpr uint32_t ProjTex_BeginPass = 0x10025330u;
constexpr uint32_t ProjTex_EndPass = 0x100255C0u;
constexpr uint32_t ProjTex_CaptureToTarget = 0x10025870u;
constexpr uint32_t EnvMap_BeginPass = 0x10025C40u;
constexpr uint32_t EnvMap_EndPass = 0x10025F70u;
constexpr uint32_t CXiMovie_Draw = 0x10026AD0u;
constexpr uint32_t CYyIcon_DrawSubRect = 0x10026C70u;
constexpr uint32_t CreateSharedVertexBuffers = 0x10029A50u;
constexpr uint32_t CYyModelBase_DrawLit = 0x1002A3B0u;
constexpr uint32_t CYyModel_Constructor = 0x1002B4B0u;
constexpr uint32_t CXiSkeletonActor_DrawModel = 0x1002B6E0u;
constexpr uint32_t CXiSkeletonActor_PrepareModelsOnce = 0x1002C360u;
constexpr uint32_t CYyOs2VtxBuffer_Constructor = 0x1002D680u;
constexpr uint32_t CYyOs2VtxBuffer_CYyOs2VtxBuffer_Destructor = 0x1002D700u;
constexpr uint32_t Unit1002D8E0_FixOffsetsAndCreateVtxBuffer = 0x1002D8F0u;
constexpr uint32_t CYyModelDt_SkinAndDrawV2 = 0x1002DC10u;
constexpr uint32_t Gfx_SetStreamSourceCached = 0x1002F130u;
constexpr uint32_t Gfx_ApplyCachedStreamSource = 0x1002F160u;
constexpr uint32_t Gfx_ApplyCachedVertexShader = 0x1002F1A0u;
constexpr uint32_t Unit100310A0_Construct = 0x10033710u;
constexpr uint32_t Model_BeginOffscreenPass = 0x10033800u;
constexpr uint32_t Model_EndOffscreenPassBindTextures = 0x10033A70u;
constexpr uint32_t Shadow_DrawByMode = 0x10033DA0u;
constexpr uint32_t CYySoundElem_UpdateQueue = 0x10036230u;
constexpr uint32_t CYySoundElem_UpdateOne = 0x100364A0u;
constexpr uint32_t CYySoundElem_UpdateTimerAndPosition = 0x100364E0u;
constexpr uint32_t Font_DrawPass = 0x10038520u;
constexpr uint32_t Font_DrawString = 0x10038720u;
constexpr uint32_t Post_CreateScreenEffectTargets = 0x10038930u;
constexpr uint32_t Post_CaptureSceneToTarget = 0x10038A80u;
constexpr uint32_t Post_DrawRotatingGhostLayers = 0x10038E10u;
constexpr uint32_t TexObj_CreateAndUpload = 0x10039A30u;
constexpr uint32_t TexObj_CreateAndUpload_v1 = 0x10039A30u;
constexpr uint32_t TexObj_Reupload = 0x10039A60u;
constexpr uint32_t TexObj_Create = 0x10039A80u;
constexpr uint32_t TexObj_Upload = 0x10039E50u;
constexpr uint32_t TexMgr_UploadPumpEntry = 0x1003AB70u;
constexpr uint32_t TexMgr_UploadPump = 0x1003ABB0u;
constexpr uint32_t sub_1003B080 = 0x1003B080u;
constexpr uint32_t CYyVbMng_AcquireVertexBuffer = 0x1003B210u;
constexpr uint32_t CYyVbMng_AcquireVertexBuffer_v1 = 0x1003B210u;
constexpr uint32_t Sky_DrawGradientDome = 0x1003D640u;
constexpr uint32_t sub_1003DB50 = 0x1003DB50u;
constexpr uint32_t Sky_DrawDomeViewCentered = 0x1003DB60u;
constexpr uint32_t sub_1003DDF0 = 0x1003DDF0u;
constexpr uint32_t YmElem_DrawD3ASegment = 0x1003E910u;
constexpr uint32_t YmElem_SetD3ADrawState = 0x1003E9A0u;
constexpr uint32_t sub_1003EB00 = 0x1003EB00u;
constexpr uint32_t sub_1003EB10 = 0x1003EB10u;
constexpr uint32_t sub_1003EB20 = 0x1003EB20u;
constexpr uint32_t sub_1003F890 = 0x1003F890u;
constexpr uint32_t CMoDistModelElem_DrawBatches = 0x10040220u;
constexpr uint32_t sub_10040B50 = 0x10040B50u;
constexpr uint32_t sub_10040B60 = 0x10040B60u;
constexpr uint32_t sub_10040B70 = 0x10040B70u;
constexpr uint32_t sub_10040B80 = 0x10040B80u;
constexpr uint32_t sub_10040B90 = 0x10040B90u;
constexpr uint32_t CMoElemFamily_SharedEarlyExit = 0x10040C20u;
constexpr uint32_t Font_DrawProjectedText3D = 0x10041C20u;
constexpr uint32_t sub_10042CD0 = 0x10042CD0u;
constexpr uint32_t sub_10042CE0 = 0x10042CE0u;
constexpr uint32_t sub_10042CF0 = 0x10042CF0u;
constexpr uint32_t CMoDistMorphElem_ValidateMorphData = 0x10042D00u;
constexpr uint32_t sub_10043310 = 0x10043310u;
constexpr uint32_t sub_100439B0 = 0x100439B0u;
constexpr uint32_t VertexBatch_BindAndDraw = 0x10043F40u;
constexpr uint32_t VertexBatch_BindAndDraw_v1 = 0x10043F40u;
constexpr uint32_t VertexBatch_BindAndDraw_v2 = 0x10043F40u;
constexpr uint32_t Gfx_SetViewMatrixFromField10 = 0x10044210u;
constexpr uint32_t Gfx_SetViewMatrixFromField90 = 0x10044230u;
constexpr uint32_t FUN_10044250 = 0x10044250u;
constexpr uint32_t Mo_InitSharedRenderResources = 0x10044270u;
constexpr uint32_t Unit10043E40_ReleaseResourcesOf = 0x100446A0u;
constexpr uint32_t CMoElem_AdvanceTimer = 0x10044AE0u;
constexpr uint32_t Fog_SetRenderStates = 0x100464D0u;
constexpr uint32_t sub_10046550 = 0x10046550u;
constexpr uint32_t YmElem_SetupDevice = 0x100467E0u;
constexpr uint32_t sub_100472D0 = 0x100472D0u;
constexpr uint32_t YmElem_RestoreDevice = 0x100472F0u;
constexpr uint32_t sub_100473E0 = 0x100473E0u;
constexpr uint32_t CMoGeneratorClone_VT_1032B114_ScalarDeletingDtor = 0x10047FE0u;
constexpr uint32_t CMoGeneratorClone_ExecuteCmdList = 0x1004E720u;
constexpr uint32_t SharedConditionalStateReset = 0x100531D0u;
constexpr uint32_t SharedConditionalStateReset_v1 = 0x100531D0u;
constexpr uint32_t CMoGeneratorClone_CreateInstance = 0x100536C0u;
constexpr uint32_t CMoGeneratorClone_VT_1032B69C_ScalarDeletingDtor = 0x10053840u;
constexpr uint32_t YmGenerater_Stop = 0x100538E0u;
constexpr uint32_t YmGenerater_Stop_v1 = 0x100538E0u;
constexpr uint32_t YmGenerater_Stop_v2 = 0x100538E0u;
constexpr uint32_t YmGenerater_Stop_v3 = 0x100538E0u;
constexpr uint32_t Unit10053860_StopGenerators = 0x10053A00u;
constexpr uint32_t CMoGeneratorClone_Destructor = 0x100542F0u;
constexpr uint32_t BeginEffectOffscreenPass = 0x10054D70u;
constexpr uint32_t sub_10054F70 = 0x10054F70u;
constexpr uint32_t EndEffectOffscreenPass = 0x10054F80u;
constexpr uint32_t CMoSchedularTask_Interpret = 0x10057FB0u;
constexpr uint32_t CMoDX_CreateTexture = 0x1006A150u;
constexpr uint32_t CMoDX_SetWorldMatrix = 0x1006A480u;
constexpr uint32_t CMoDX_SetWorldMatrix_v1 = 0x1006A480u;
constexpr uint32_t CMoDX_PopViewMatrix = 0x1006A4F0u;
constexpr uint32_t CMoDX_PopViewMatrix_v1 = 0x1006A4F0u;
constexpr uint32_t CMoDX_SetViewMatrix = 0x1006A520u;
constexpr uint32_t CMoDX_SetViewMatrix_v1 = 0x1006A520u;
constexpr uint32_t StateBlockHolder_ApplyRenderStates = 0x1006AF00u;
constexpr uint32_t StateBlock_ApplyTSS = 0x1006AF90u;
constexpr uint32_t StateBlock_ApplyTSS_v1 = 0x1006AF90u;
constexpr uint32_t CMoDxStatusMng_Destructor = 0x1006B090u;
constexpr uint32_t CMoDX_CreateAndInitSystem = 0x1006B2B0u;
constexpr uint32_t CMoOcclusionMng_Constructor = 0x1006C140u;
constexpr uint32_t OcclusionMng_CreateTarget = 0x1006C220u;
constexpr uint32_t OcclusionMng_CreateTarget_v1 = 0x1006C220u;
constexpr uint32_t Occlusion_QueryScreenRect = 0x1006C280u;
constexpr uint32_t Occlusion_QueryScreenRectImpl = 0x1006C300u;
constexpr uint32_t DrawScreenProbe = 0x1006C530u;
constexpr uint32_t sub_1006C890 = 0x1006C890u;
constexpr uint32_t sub_1006C8A0 = 0x1006C8A0u;
constexpr uint32_t sub_1006C8B0 = 0x1006C8B0u;
constexpr uint32_t OcclusionMng_Prepare = 0x1006C9B0u;
constexpr uint32_t Gfx_InitCubeMapTextures = 0x10075280u;
constexpr uint32_t TexRef_EnsureRenderTarget = 0x100755A0u;
constexpr uint32_t TextureHolder_BindWarped = 0x10075700u;
constexpr uint32_t sub_10075950 = 0x10075950u;
constexpr uint32_t TexRef_SetTexture = 0x10075960u;
constexpr uint32_t TexRef_SetTexture_v1 = 0x10075960u;
constexpr uint32_t TextureHolder_BindTinted = 0x100759C0u;
constexpr uint32_t sub_10075C30 = 0x10075C30u;
constexpr uint32_t CXiActor_SpawnResourceGenerators = 0x10085060u;
constexpr uint32_t CXiActor_SpawnResourceGenerators_v1 = 0x10085060u;
constexpr uint32_t CXiActor_SpawnResourceGenerators_v2 = 0x10085060u;
constexpr uint32_t Actor_DrawWorldText = 0x10086210u;
constexpr uint32_t Actor_DrawWorldText_v1 = 0x10086210u;
constexpr uint32_t DrawNameplateSecondString = 0x10086900u;
constexpr uint32_t Unit10086E90_UpdateFlags120Bit23 = 0x1008E4D0u;
constexpr uint32_t Acter_UpdateOne = 0x1008E9A0u;
constexpr uint32_t Acter_UpdateAllLists = 0x10095900u;
constexpr uint32_t Acter_UpdateFrame = 0x10096640u;
constexpr uint32_t CXiSkeletonActor_Constructor_1Arg = 0x100C52A0u;
constexpr uint32_t sub_100C5410 = 0x100C5410u;
constexpr uint32_t sub_100C5440 = 0x100C5440u;
constexpr uint32_t sub_100C54C0 = 0x100C54C0u;
constexpr uint32_t CXiSkeletonActor_DestructorBody = 0x100C5C00u;
constexpr uint32_t Actor_SelectNearestLights = 0x100CB4E0u;
constexpr uint32_t PerActor_FourBucketStaggeredUpdate = 0x100CBDE0u;
constexpr uint32_t sub_100CCE20 = 0x100CCE20u;
constexpr uint32_t sub_100CCE30 = 0x100CCE30u;
constexpr uint32_t sub_100CCE40 = 0x100CCE40u;
constexpr uint32_t sub_100CCE50 = 0x100CCE50u;
constexpr uint32_t CXiSkeletonActor_DrawNameIfVisible = 0x100D0880u;
constexpr uint32_t CXiSkeletonActor_DrawName2IfVisible = 0x100D08B0u;
constexpr uint32_t CXiSkeletonActor_AddPartAndMarkSlot = 0x100D0B50u;
constexpr uint32_t CXiSkeletonActor_AttachPartResource = 0x100D0D70u;
constexpr uint32_t sub_100D0E80 = 0x100D0E80u;
constexpr uint32_t Unit100D13B0_ProcessResidentListEntries = 0x100D1450u;
constexpr uint32_t CXiActor_RequestModelParts = 0x100D14C0u;
constexpr uint32_t CXiSkeletonActor_LoadSkeletonSync = 0x100D2F60u;
constexpr uint32_t CXiSkeletonActor_LoadSkeletonSync_v1 = 0x100D2F60u;
constexpr uint32_t sub_100D4220 = 0x100D4220u;
constexpr uint32_t CXiSkeletonActor_LoadSkeletonResource = 0x100D4330u;
constexpr uint32_t CXiSkeletonActor_LoadSkeletonResource_v1 = 0x100D4330u;
constexpr uint32_t Menu_DrawWindowItems = 0x101177D0u;
constexpr uint32_t Unit100D7420_DrawUnscaled = 0x10119F80u;
constexpr uint32_t Unit100D7420_SetViewport = 0x1011AA40u;
constexpr uint32_t Gfx_ApplyViewport1B70 = 0x1011AAC0u;
constexpr uint32_t Font_BindGlyphTexture = 0x1011BAE0u;
constexpr uint32_t Font_BindGlyphTexture_v1 = 0x1011BAE0u;
constexpr uint32_t Font_DrawGlyphQuadGrey = 0x1011BBA0u;
constexpr uint32_t Font_DrawGlyphQuadGrey_v1 = 0x1011BBA0u;
constexpr uint32_t Font_DrawGlyphQuad = 0x1011BBD0u;
constexpr uint32_t Gfx_SetAdditiveBlend = 0x1011BDC0u;
constexpr uint32_t Gfx_SetAdditiveBlend_v1 = 0x1011BDC0u;
constexpr uint32_t Font_DrawChar = 0x1011BF40u;
constexpr uint32_t Obj_104E1B90_DrawString = 0x1011C080u;
constexpr uint32_t Gfx_SetCellBlendMode = 0x1011C1F0u;
constexpr uint32_t Font_LoadHighResTexture = 0x1011C720u;
constexpr uint32_t Cell_DrawStretchedWrapped = 0x1011EF60u;
constexpr uint32_t Cell_DrawWithDefaultBlend = 0x1011F2D0u;
constexpr uint32_t Cell_DrawQuadBlended = 0x1011F300u;
constexpr uint32_t Cell_DrawQuadBlended_v1 = 0x1011F300u;
constexpr uint32_t FUN_1011fb60 = 0x1011FB60u;
constexpr uint32_t FUN_1011fb60_v1 = 0x1011FB60u;
constexpr uint32_t Shape_DrawScaled = 0x1011FC80u;
constexpr uint32_t Shape_DrawScaled_v1 = 0x1011FC80u;
constexpr uint32_t Cell_DrawFirstStretched = 0x10120000u;
constexpr uint32_t ShapeMng_BindFontTexture = 0x10120590u;
constexpr uint32_t Menu_DrawLayers = 0x1015F6A0u;
constexpr uint32_t sub_1015FA00 = 0x1015FA00u;
constexpr uint32_t Gfx_SetDefault2DStates = 0x101604B0u;
constexpr uint32_t Gfx_SetDefault2DStates_v1 = 0x101604B0u;
constexpr uint32_t Gfx_DisableFogAndAlphaBlend = 0x10160650u;
constexpr uint32_t Gfx_DisableFogAndAlphaBlend_v1 = 0x10160650u;
constexpr uint32_t Obj_10621944_Draw = 0x101630E0u;
constexpr uint32_t Obj_10621944_DrawBgRect = 0x10163390u;
constexpr uint32_t Gfx_DrawSolidRect2D = 0x10163400u;
constexpr uint32_t Gfx_SetZBias = 0x10177400u;
constexpr uint32_t Gfx_SetZBias_v1 = 0x10177400u;
constexpr uint32_t FUN_10178250 = 0x10178250u;
constexpr uint32_t ZoneMap_UpdateLoadState = 0x101787C0u;
constexpr uint32_t ZoneMap_ReleaseSlot = 0x10178AC0u;
constexpr uint32_t ZoneMap_ReleaseStateBlock = 0x10178B00u;
constexpr uint32_t ZoneMap_Reset = 0x10178F70u;
constexpr uint32_t ZoneMap_CreateVertexShaders = 0x101792A0u;
constexpr uint32_t ZoneMap_FreeSlot = 0x1017B110u;
constexpr uint32_t ZoneMap_TeardownStep = 0x1017B1E0u;
constexpr uint32_t ZoneMap_TeardownStep_v1 = 0x1017B1E0u;
constexpr uint32_t XiZone_Draw = 0x1017B510u;
constexpr uint32_t CTsZoneMap_DrawProjectedTexture = 0x10182700u;
constexpr uint32_t XiZone_DrawModelAtMatrix = 0x10183490u;
constexpr uint32_t ZoneMap_DrawMeshById = 0x10183DA0u;
constexpr uint32_t FUN_101844c0 = 0x101844C0u;
constexpr uint32_t XiZone_DrawGroundShadowQuad = 0x10184C90u;
constexpr uint32_t CTsZoneMap_DrawProjectedShadow = 0x10184FE0u;
constexpr uint32_t XiZone_DrawDecalOnTriangles = 0x10185CA0u;
constexpr uint32_t ZoneMap_ClearSlots = 0x10186DB0u;
constexpr uint32_t ZoneMap_FreeSubAreas = 0x10186DD0u;
constexpr uint32_t FUN_10187030 = 0x10187030u;
constexpr uint32_t ZoneMap_ReleaseChain = 0x10187030u;
constexpr uint32_t FUN_10188a10 = 0x10188A10u;
constexpr uint32_t XiZone_DestroyChildList = 0x10188A10u;
constexpr uint32_t FUN_1018abf0 = 0x1018ABF0u;
constexpr uint32_t YmCombineWeather_Release = 0x1018ABF0u;
constexpr uint32_t Blend_Update = 0x1018ADE0u;
constexpr uint32_t FUN_1018ade0 = 0x1018ADE0u;
constexpr uint32_t FUN_1018b620 = 0x1018B620u;
constexpr uint32_t XiZone_ResetState = 0x1018B620u;
constexpr uint32_t sub_1018B860 = 0x1018B860u;
constexpr uint32_t Unit1018BA60_DrawTextBlockOnce = 0x1019EBB0u;
constexpr uint32_t Unit1018BA60_DrawTextLines = 0x1019EDB0u;
constexpr uint32_t Gfx_ProjectWorldToScreen = 0x101C8DA0u;
constexpr uint32_t Unit101C72E0_DrawUnscaled = 0x101C9780u;
constexpr uint32_t Unit101C72E0_DrawUnscaled_v1 = 0x101C9780u;
constexpr uint32_t Unit101C72E0_DrawTextItem0 = 0x101C97B0u;
constexpr uint32_t Unit101C72E0_DrawTextItem0_v1 = 0x101C97B0u;
constexpr uint32_t Unit101C72E0_DrawString = 0x101C9D50u;
constexpr uint32_t Unit101C72E0_DrawTruncated = 0x101CA180u;
constexpr uint32_t Unit101C72E0_DrawFractionRange = 0x101CAD00u;
constexpr uint32_t Unit101C72E0_DrawFractionDefault = 0x101CAEC0u;
constexpr uint32_t Unit101C72E0_DrawSmoothed = 0x101CAF00u;
constexpr uint32_t Unit101C72E0_DrawSmoothedDefault = 0x101CB000u;
constexpr uint32_t Unit101C72E0_DrawFractionItem1A = 0x101CB040u;
constexpr uint32_t Unit101C72E0_DrawSmoothedItem1A = 0x101CB090u;
constexpr uint32_t Unit101C72E0_DrawSmoothedExItem1B = 0x101CB230u;
constexpr uint32_t Unit101C72E0_DrawEasedPercent = 0x101CB430u;
constexpr uint32_t Unit101C72E0_DrawEasedPercentUnitScale = 0x101CB500u;
constexpr uint32_t Unit101C72E0_DrawEasedPercentItem1A = 0x101CB550u;
constexpr uint32_t Unit101C72E0_BeginCapture = 0x101CB770u;
constexpr uint32_t sub_101D0B00 = 0x101D0B00u;
constexpr uint32_t Unit101D0910_SaveJpeg512x382 = 0x101D1000u;
constexpr uint32_t YkJpeg_CaptureAndEncode = 0x101D1060u;
constexpr uint32_t Unit101D0910_SaveJpegScreenSize = 0x101D1100u;
constexpr uint32_t Unit101D2FF0_Draw = 0x101D3FC0u;
constexpr uint32_t Unit101D2FF0_Update = 0x101D5680u;
constexpr uint32_t Unit101D7020_DrawCountersAndGauge = 0x10201340u;
constexpr uint32_t CXiMovie_DrawFrame = 0x1021D4C0u;
constexpr uint32_t Unit1021D930_DrawActorPanelFigures = 0x1021F480u;
constexpr uint32_t Unit1021D930_DrawEntryRows = 0x1021F950u;
constexpr uint32_t Unit1021D930_DrawLabelledRow = 0x1021FA90u;
constexpr uint32_t Unit1021D930_DrawTwoDigitValue = 0x1021FB10u;
constexpr uint32_t Unit1021D930_DrawBarRow = 0x1021FB80u;
constexpr uint32_t Unit1021D930_DrawNameRows = 0x1021FBD0u;
constexpr uint32_t Unit1021D930_DrawLabelBar = 0x102201A0u;
constexpr uint32_t Unit1021D930_Draw = 0x102214D0u;
constexpr uint32_t Unit1021D930_DrawProgressBar = 0x10234660u;
constexpr uint32_t FUN_102454e0 = 0x102454E0u;
constexpr uint32_t LobbyThread_ResetZone = 0x10245BB0u;
constexpr uint32_t StAvatarInit = 0x1024CF50u;
constexpr uint32_t StAvatar_Teardown = 0x1024D180u;
constexpr uint32_t StAvatar_SetPending = 0x1024D5C0u;
constexpr uint32_t StAvatar_StopAndFreeBuffers = 0x1024D790u;
constexpr uint32_t StAvatar_ResolveItemsAndStart = 0x1024D850u;
constexpr uint32_t StAvatar_Update = 0x1024DB60u;
constexpr uint32_t StAvatar_SetViewFromDancerCamera = 0x1024F900u;
constexpr uint32_t StAvatar_RenderIfEnabled = 0x10250190u;
constexpr uint32_t StAvatarRender = 0x102501C0u;
constexpr uint32_t StAvatarFini = 0x102504D0u;
constexpr uint32_t StDancer_Update = 0x10251500u;
constexpr uint32_t sub_102515F0 = 0x102515F0u;
constexpr uint32_t StAvatar_SetActive = 0x10251620u;
constexpr uint32_t StAvatar_SetStateTeardown = 0x102516B0u;
constexpr uint32_t Dancer_InitDevice = 0x10251A80u;
constexpr uint32_t StModelItem_Resolve = 0x102528D0u;
constexpr uint32_t StAvatar_DrawScene = 0x102717F0u;
constexpr uint32_t sub_10277A50_2 = 0x10277A50u;
constexpr uint32_t sub_10277AB0_2 = 0x10277AB0u;
constexpr uint32_t sub_10277FF0 = 0x10277FF0u;
constexpr uint32_t sub_10278490_2 = 0x10278490u;
constexpr uint32_t sqgxSprite = 0x10280DE0u;
constexpr uint32_t sqgxSprite_v1 = 0x10280DE0u;
constexpr uint32_t Unit10280C40_CompositeBlendPasses = 0x102813B0u;
constexpr uint32_t sqgxTextureCreateFromImage = 0x10281510u;
constexpr uint32_t sqgxTextureAddZ = 0x102816E0u;
constexpr uint32_t sqgxTextureAdd = 0x10281830u;
constexpr uint32_t sqgxTextureAdd_v1 = 0x10281830u;
constexpr uint32_t sqgxTextureClutAdd = 0x102819D0u;
constexpr uint32_t sqgxTextureClut = 0x10281D60u;
constexpr uint32_t sqgxTextureUpdate = 0x10281DB0u;
constexpr uint32_t sqgxTextureUpdate_v1 = 0x10281DB0u;
constexpr uint32_t sqgxTextureStencilClear = 0x10282010u;
constexpr uint32_t sqgxTextureClear = 0x10282030u;
constexpr uint32_t sqgxTextureClear_v1 = 0x10282030u;
constexpr uint32_t sqgxTextureDraw = 0x10282190u;
constexpr uint32_t sqgxTextureDraw_v1 = 0x10282190u;
constexpr uint32_t sqgxZTest = 0x10282350u;
constexpr uint32_t sqgxZTest_v1 = 0x10282350u;
constexpr uint32_t sqgxAlphaTest = 0x102823F0u;
constexpr uint32_t sqgxZMask = 0x10282470u;
constexpr uint32_t sqgxZMask_v1 = 0x10282470u;
constexpr uint32_t sqgxFBMask = 0x102824C0u;
constexpr uint32_t sqgxFBMask_v1 = 0x102824C0u;
constexpr uint32_t sqgxBlendAdd = 0x102826C0u;
constexpr uint32_t Unit102822A0_SetMultiplyAdd = 0x102827D0u;
constexpr uint32_t sqgxBlendSub = 0x10282910u;
constexpr uint32_t sqgxBlendLin = 0x10282A30u;
constexpr uint32_t sqgxBlendLin_v1 = 0x10282A30u;
constexpr uint32_t sqgxBlendTrsp = 0x10282B90u;
constexpr uint32_t sqgxBlendTrsp_v1 = 0x10282B90u;
constexpr uint32_t sqgxBlendAddDestAlpha = 0x10282DC0u;
constexpr uint32_t sqgxBlendZeroSrcAlpha = 0x10282FF0u;
constexpr uint32_t sqgxBlendMul = 0x10283110u;
constexpr uint32_t sqgxBlendOff = 0x10283220u;
constexpr uint32_t sqgxBlendOff_v1 = 0x10283220u;
constexpr uint32_t sqgxColorUpdate = 0x10283420u;
constexpr uint32_t sqgxColorUpdate_v1 = 0x10283420u;
constexpr uint32_t sqgxViewport = 0x10283A10u;
constexpr uint32_t sqgxPassAdd = 0x10283F70u;
constexpr uint32_t sqgxPassAdd_v1 = 0x10283F70u;
constexpr uint32_t sqgxPass = 0x10283FC0u;
constexpr uint32_t sqgxMatrixUpdate = 0x10284410u;
constexpr uint32_t sqgxVertexShaderCreate = 0x10284950u;
constexpr uint32_t sqgxShader = 0x10284B20u;
constexpr uint32_t sqgxShader_v1 = 0x10284B20u;
constexpr uint32_t sqgxShader_v2 = 0x10284B20u;
constexpr uint32_t SqmdDMB_Resolve = 0x10287FB0u;
constexpr uint32_t SqmdDMB_ResolveTextures = 0x102886D0u;
constexpr uint32_t FUN_10288e60 = 0x10288E60u;
constexpr uint32_t sqgxShapeBegin = 0x1028AFE0u;
constexpr uint32_t SqsnScene_DrawMatrixShape = 0x1028F4C0u;
constexpr uint32_t sqsnSceneDraw = 0x1028F8C0u;
constexpr uint32_t sqsnSceneLayerDraw = 0x1028FDD0u;
constexpr uint32_t SqsnScene_DrawFadeSprite = 0x1028FF80u;
constexpr uint32_t sqsnSceneLayerDrawShadowed = 0x1028FFF0u;
constexpr uint32_t sqsnSceneLayerSnapShotComposite = 0x102902C0u;
constexpr uint32_t sqsdGeneric_BakeOntoShape = 0x10290FC0u;
constexpr uint32_t sqsnShadowVolumeSetPass = 0x10297CC0u;
constexpr uint32_t sqsnShadowVolumeBeginVB = 0x102981E0u;
constexpr uint32_t sub_10298540 = 0x10298540u;
constexpr uint32_t sub_10298B60 = 0x10298B60u;
constexpr uint32_t sub_10298C10 = 0x10298C10u;
constexpr uint32_t Texture_CreateEntry = 0x10298E10u;
constexpr uint32_t sqsdSampling_BakeOntoShape = 0x10299250u;
constexpr uint32_t sqsdAniso_BakeOntoShape = 0x10299610u;
constexpr uint32_t SqsdGlow_ApplyShader = 0x102999A0u;
constexpr uint32_t sqsdGlow_BakeOntoShape = 0x10299AB0u;
constexpr uint32_t FUN_1029b620 = 0x1029B620u;
constexpr uint32_t FUN_102a1f20 = 0x102A1F20u;
constexpr uint32_t sqsnPlanarShadowDraw = 0x102A2530u;
constexpr uint32_t Unit102A2530_RenderShadowTexture = 0x102A2720u;
constexpr uint32_t Unit102A2530_DrawShadowedShape = 0x102A2C00u;
}  // namespace orig_addr
#define XI_CODE(name) reinterpret_cast<void *>(XI_GAME(orig_addr::name))
