// CMoProcessorX87 -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoProcessorX87 {
public:
    float * Vec3AddScaled(float *arg1, float *arg2, float arg3);  // 0x1006D3B0
    double Vec3Dot(float *arg1, float *arg2);  // 0x1006D4D0
    float * Vec3Add(float *arg1, float *arg2, float *arg3);  // 0x1006D680
    float * Vec3MulComponents(float *arg1, float *arg2, float *arg3);  // 0x1006D6B0
    static bits32 __stdcall TransformPoint(float * arg1, float * arg2, float * arg3);  // 0x1006D720
    float * Vec3Lerp(float *arg1, float *arg2, float *arg3, float arg4);  // 0x1006D980
    static bits32 __thiscall RotationFromAnglesZYX(void * self, bits32 arg2, float arg3, float arg4, float arg5);  // 0x1006DCF0
    static bits32 __stdcall RotationY(bits32 * arg1, float arg2);  // 0x1006E140
    static bits32 __stdcall RotationZ(bits32 * arg1, float arg2);  // 0x1006E260
    static bits32 __thiscall RotationFromAnglesXYZ(void * self, bits32 arg2, float arg3, float arg4, float arg5);  // 0x1006E380

    void **vftable;  // +0x0
    uint8_t _pad_4[0xC];
};
#pragma pack(pop)
static_assert(sizeof(CMoProcessorX87) == 0x10, "CMoProcessorX87: sizeof");
