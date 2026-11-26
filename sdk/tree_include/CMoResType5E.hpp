// CMoResType5E -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoResType5E {
public:
    void SetupNop();  // 0x10038920
    void Slot9Nop();  // 0x10071A10
    unsigned int ** ScalarDeletingDtor(char arg1);  // 0x10071B00

    void **vftable;  // +0x0
    uint8_t _pad_4[0x2C];
};
#pragma pack(pop)
static_assert(sizeof(CMoResType5E) == 0x30, "CMoResType5E: sizeof");
