// CMoTask -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoTask {
public:
    int DrawQuadStates(float *a2, char arg4);  // 0x10076030
    int DrawQuadDynVB(float *a2, float *a3, char a4);  // 0x10076520

    void **vftable;  // +0x0
    uint8_t _pad_4[0x30];
};
#pragma pack(pop)
static_assert(sizeof(CMoTask) == 0x34, "CMoTask: sizeof");
