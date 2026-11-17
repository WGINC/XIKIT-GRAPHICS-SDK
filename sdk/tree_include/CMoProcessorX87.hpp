// CMoProcessorX87 -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoProcessorX87 {
public:
    float * Vec3AddScaled(float *a1, float *a2, float a3);  // 0x1006D3B0
    double Vec3Dot(float *a1, float *a2);  // 0x1006D4D0
    float * Vec3Add(float *a1, float *a2, float *a3);  // 0x1006D680
    float * Vec3MulComponents(float *a1, float *a2, float *a3);  // 0x1006D6B0
    static undefined4 __stdcall TransformPoint(float * param_1, float * param_2, float * param_3);  // 0x1006D720
    float * Vec3Lerp(float *a1, float *a2, float *a3, float a4);  // 0x1006D980
    static undefined4 __thiscall RotationFromAnglesZYX(void * self, undefined4 param_1, float param_2, float param_3, float param_4);  // 0x1006DCF0
    static undefined4 __stdcall RotationY(undefined4 * param_1, float param_2);  // 0x1006E140
    static undefined4 __stdcall RotationZ(undefined4 * param_1, float param_2);  // 0x1006E260
    static undefined4 __thiscall RotationFromAnglesXYZ(void * self, undefined4 param_1, float param_2, float param_3, float param_4);  // 0x1006E380

    void **vftable;  // +0x0
    uint8_t _pad_4[0xC];
};
#pragma pack(pop)
static_assert(sizeof(CMoProcessorX87) == 0x10, "CMoProcessorX87: sizeof");
