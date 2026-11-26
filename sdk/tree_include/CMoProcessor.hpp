// CMoProcessor -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
// NOTE: class descriptor says 0x10; the IDB struct and the code use 0xBB0.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoProcessor {
public:
    uint32_t * InitRotationMatrices();  // 0x1006CE70
    static void __stdcall TransposeInPlace(int arg1);  // 0x1006D3E0
    static long double __stdcall LengthSafe(float * arg1);  // 0x1006D580
    int ScratchMatrixOp(int arg1, int arg2, int arg3);  // 0x1006E6B0
    static CMoProcessor * __stdcall CalcScreenBounds(float *arg1, float *arg2, int arg3, int arg4, const void *arg5);  // 0x1006E970
    static void __thiscall CalcScreenBoundsAndVisible(void * self, float * arg2, float * arg3, float arg4, float arg5, float arg6, bits32 xi_s6, bits32 xi_s7);  // 0x1006ED10
    static float * __stdcall MulPointVec3(float * arg1, float * arg2, float * arg3);  // 0x1006F800
    static bits32 __thiscall BuildRotationXYZ(void * self, bits32 arg2, float arg3, float arg4, float arg5);  // 0x1006FAE0
    static bits32 __thiscall SetRotationFromAngles(void * self, bits32 arg2, float arg3, float arg4, float arg5);  // 0x1006FC40

    void **vftable;  // +0x0
    float ScratchMatrices[512];  // +0x4
    uint8_t _pad_804[0xC];
    float RotationMatrix[64];  // +0x810
    uint8_t _pad_910[0x100];
    float * ScratchMatrixFreeList[32];  // +0xA10
    int ScratchMatrixStackTop;  // +0xA90
    uint8_t _pad_A94[0xC];
    float TransposeScratch[16];  // +0xAA0
    float TransposeScratchTemp[16];  // +0xAE0
    uint8_t _pad_B20[0x90];
};
#pragma pack(pop)
static_assert(sizeof(CMoProcessor) == 0xBB0, "CMoProcessor: sizeof");
static_assert(XI_OFFSETOF(CMoProcessor, ScratchMatrices) == 0x4, "CMoProcessor: layout");
static_assert(XI_OFFSETOF(CMoProcessor, RotationMatrix) == 0x810, "CMoProcessor: layout");
static_assert(XI_OFFSETOF(CMoProcessor, ScratchMatrixFreeList) == 0xA10, "CMoProcessor: layout");
static_assert(XI_OFFSETOF(CMoProcessor, ScratchMatrixStackTop) == 0xA90, "CMoProcessor: layout");
static_assert(XI_OFFSETOF(CMoProcessor, TransposeScratch) == 0xAA0, "CMoProcessor: layout");
static_assert(XI_OFFSETOF(CMoProcessor, TransposeScratchTemp) == 0xAE0, "CMoProcessor: layout");
