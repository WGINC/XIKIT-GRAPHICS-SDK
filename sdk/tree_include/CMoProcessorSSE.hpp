// CMoProcessorSSE -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoProcessorSSE {
public:
    float * Vec3Scale(float *a1, float a2);  // 0x1006D380
    double Vec3Dot(float *a1, float *a2);  // 0x1006F5B0
    float * Vec3Lerp(float *a1, float *a2, float *a3, float a4);  // 0x1006FA30
    CMoProcessor * CalcScreenBoundsAndVisible(float *a2, float *a3, int a4, int a5, int a6, float a7, float a8);  // 0x10070020
    CMoProcessor * CalcScreenBounds(float *a1, float *a2, int a3, int a4, const void *a5);  // 0x10070040

    void **vftable;  // +0x0
    uint8_t _pad_4[0xC];
};
#pragma pack(pop)
static_assert(sizeof(CMoProcessorSSE) == 0x10, "CMoProcessorSSE: sizeof");
