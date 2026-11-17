// CMoResType3E -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoResType3E {
public:
    void SetupClearField34();  // 0x10063C50

    void **vftable;  // +0x0
    uint8_t _pad_4[0x30];
    uint32_t field_34;  // +0x34
};
#pragma pack(pop)
static_assert(sizeof(CMoResType3E) == 0x38, "CMoResType3E: sizeof");
static_assert(XI_OFFSETOF(CMoResType3E, field_34) == 0x34, "CMoResType3E: layout");
