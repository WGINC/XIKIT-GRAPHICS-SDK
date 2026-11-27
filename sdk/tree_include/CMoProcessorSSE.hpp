// CMoProcessorSSE -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoProcessorSSE {
public:
    float * Vec3Scale(float *arg1, float arg2);  // 0x1006D380
    double Vec3Dot(float *arg1, float *arg2);  // 0x1006F5B0
    float * Vec3Lerp(float *arg1, float *arg2, float *arg3, float arg4);  // 0x1006FA30
    CMoProcessor * CalcScreenBoundsAndVisible(float *arg1, float *arg2, int arg3, int arg4, int arg5, float arg6, float arg7);  // 0x10070020
    CMoProcessor * CalcScreenBounds(float *arg1, float *arg2, int arg3, int arg4, const void *arg5);  // 0x10070040

    void **vftable;  // +0x0
    uint8_t _pad_4[0xC];
};
#pragma pack(pop)
static_assert(sizeof(CMoProcessorSSE) == 0x10, "CMoProcessorSSE: sizeof");
