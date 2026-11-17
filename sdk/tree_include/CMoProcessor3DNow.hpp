// CMoProcessor3DNow -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoProcessor3DNow {
public:
    int Slot8CallSlot9(void * a1, void * a2, void * a3);  // 0x1006CC40
    int Slot10CallSlot11(void * a1, void * a2, void * a3);  // 0x1006CC50
    int Slot40CallSlot41(float * a1);  // 0x1006CC60
    int Slot38CallSlot39(float * a1, float * a2);  // 0x1006CC70
    int Slot46CallSlot48(void * a1);  // 0x1006CC80
    int Slot45CallSlot47(void * a1, void * a2);  // 0x1006CC90
    static char ** __cdecl CMoProcessor_GetRuntimeClass();  // 0x1006CCD0
    float * Vec3AddScaled(float *a1, float *a2, float a3);  // 0x10070780
    double Vec3Dot(float *a1, float *a2);  // 0x10070790
    float * Vec4TransformB(float *a1, float *a2, float *a3);  // 0x10070AA0
    float * Vec4Transform(float *a1, float *a2, float *a3);  // 0x10070AB0
    float * Vec3Transform(float *a1, float *a2, float *a3);  // 0x10070AC0
    float * Vec3Lerp(float *a1, float *a2, float *a3, float a4);  // 0x10070AD0
    float * ProjectVertsAndBounds(float *a1, float *a2, int a3, float *a4, float *a5, float a6, float a7);  // 0x10070E20
    CMoProcessor * CalcScreenBoundsAndVisible(float *a2, float *a3, int a4, int a5, int a6, float a7, float a8);  // 0x10070E40
    CMoProcessor * CalcScreenBounds(float *a1, float *a2, int a3, int a4, const void *a5);  // 0x10070E60

    void **vftable;  // +0x0
    uint8_t _pad_4[0xC];
};
#pragma pack(pop)
static_assert(sizeof(CMoProcessor3DNow) == 0x10, "CMoProcessor3DNow: sizeof");
