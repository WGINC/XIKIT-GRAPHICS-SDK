// CXiDancerActor -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CXiDancerActor {
public:
    static undefined4 __thiscall Construct(void * self, undefined4 param_1, undefined4 param_2, undefined4 param_3, uint32_t param_4);  // 0x100AB700

    void **vftable;  // +0x0
    uint8_t _pad_4[0xCB4];
};
#pragma pack(pop)
static_assert(sizeof(CXiDancerActor) == 0xCB8, "CXiDancerActor: sizeof");
