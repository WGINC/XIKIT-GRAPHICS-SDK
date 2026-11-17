// CMoResType2F -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoResType2F {
public:
    unsigned int ** ScalarDeletingDtor(char a2);  // 0x101893D0
    void SetupNop();  // 0x101893F0

    void **vftable;  // +0x0
    uint8_t _pad_4[0x2C];
};
#pragma pack(pop)
static_assert(sizeof(CMoResType2F) == 0x30, "CMoResType2F: sizeof");
