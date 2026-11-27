// XiZone -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API XiZone {
public:
    static void __cdecl RestoreSavedFields();  // 0x100BA080
    int DrawMarkerForward(float *arg1, int arg2, float arg3);  // 0x10177CD0
    int DrawGroundShadowQuad(int arg1, int arg2, int arg3);  // 0x10184C90
    int DrawDecalOnTriangles(float *arg1, float *arg2, IDirect3DBaseTexture8 *arg3, float arg4);  // 0x10185CA0
    static int __cdecl FindSubArea(int arg1);  // 0x101889C0
    static void __thiscall UpdateTree(void * self);  // 0x101889E0
    static void __thiscall DestroyChildList(void * self);  // 0x10188A10
    static uint32_t __thiscall TestHeadFlag(void * self);  // 0x10188B10
    static void __thiscall GetDirLights(void * self, bits32 * arg2, bits32 * arg3);  // 0x10188B70
    static void __cdecl GetInstance();  // 0x1018B130
    static void * __thiscall Constructor(void * self);  // 0x1018B170
    static void __thiscall SetTreeState1BC(void * self, int arg2);  // 0x1018B5E0
    static void __thiscall ResetState(void * self);  // 0x1018B620
    static void __thiscall DrawScene(void * self);  // 0x1018B860
    static void __stdcall Call10036170(int arg1);  // 0x1018B8B0
    static long double __thiscall ComputeFogDistance(void * self, bits32 arg2);  // 0x1018B8F0
    static void __thiscall GetDirLightsForArea(void * self, bits32 * arg2, bits32 * arg3, int arg4);  // 0x1018B960
    static void __thiscall GetDirLight(void * self, bits32 * arg2, bits32 arg3, int arg4);  // 0x1018B9A0
    static void __thiscall GetAmbient(void * self, uint32_t * arg2, int arg3, int arg4);  // 0x1018B9E0
    static void __thiscall GetFog(void * self, uint32_t * arg2, float * arg3, float * arg4, bits32 arg5, int arg6);  // 0x1018BA20
    static void __thiscall SetPtr1D8FromTable(void * self, uint32_t arg2);  // 0x1018BAE0

    void **vftable;  // +0x0
    uint8_t _pad_4[0x1D8];
};
#pragma pack(pop)
static_assert(sizeof(XiZone) == 0x1DC, "XiZone: sizeof");
