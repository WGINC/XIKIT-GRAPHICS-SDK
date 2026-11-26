// CMoProcessor3DNow -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoProcessor3DNow {
public:
    int Slot8CallSlot9(void * arg1, void * arg2, void * arg3);  // 0x1006CC40
    int Slot10CallSlot11(void * arg1, void * arg2, void * arg3);  // 0x1006CC50
    int Slot40CallSlot41(float * arg1);  // 0x1006CC60
    int Slot38CallSlot39(float * arg1, float * arg2);  // 0x1006CC70
    int Slot46CallSlot48(void * arg1);  // 0x1006CC80
    int Slot45CallSlot47(void * arg1, void * arg2);  // 0x1006CC90
    static char ** __cdecl CMoProcessor_GetRuntimeClass();  // 0x1006CCD0
    float * Vec3AddScaled(float *arg1, float *arg2, float arg3);  // 0x10070780
    double Vec3Dot(float *arg1, float *arg2);  // 0x10070790
    float * Vec4TransformB(float *arg1, float *arg2, float *arg3);  // 0x10070AA0
    float * Vec4Transform(float *arg1, float *arg2, float *arg3);  // 0x10070AB0
    float * Vec3Transform(float *arg1, float *arg2, float *arg3);  // 0x10070AC0
    float * Vec3Lerp(float *arg1, float *arg2, float *arg3, float arg4);  // 0x10070AD0
    float * ProjectVertsAndBounds(float *arg1, float *arg2, int arg3, float *arg4, float *arg5, float arg6, float arg7);  // 0x10070E20
    CMoProcessor * CalcScreenBoundsAndVisible(float *arg1, float *arg2, int arg3, int arg4, int arg5, float arg6, float arg7);  // 0x10070E40
    CMoProcessor * CalcScreenBounds(float *arg1, float *arg2, int arg3, int arg4, const void *arg5);  // 0x10070E60

    void **vftable;  // +0x0
    uint8_t _pad_4[0xC];
};
#pragma pack(pop)
static_assert(sizeof(CMoProcessor3DNow) == 0x10, "CMoProcessor3DNow: sizeof");
