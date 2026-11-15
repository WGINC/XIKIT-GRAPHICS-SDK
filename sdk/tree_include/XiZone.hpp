// XiZone -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API XiZone {
public:
    int DrawGroundShadowQuad(int a1, int a2, int a3);  // 0x10184C90
    int DrawDecalOnTriangles(float *a1, float *a2, IDirect3DBaseTexture8 *a3, float a4);  // 0x10185CA0
    static void __thiscall DestroyChildList(void * self);  // 0x10188A10
    static void __thiscall ResetState(void * self);  // 0x1018B620
    static void __thiscall DrawScene(void * self);  // 0x1018B860

    void **vftable;  // +0x0
    uint8_t _pad_4[0x1D8];
};
#pragma pack(pop)
static_assert(sizeof(XiZone) == 0x1DC, "XiZone: sizeof");
