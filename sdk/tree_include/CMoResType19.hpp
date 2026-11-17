// CMoResType19 -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoResType19 {
public:
    void SetupNop();  // 0x10054480
    void Slot9Nop();  // 0x10054490
    unsigned int ** ScalarDeletingDtor(char a2);  // 0x10071C40

    void **vftable;  // +0x0
    uint8_t _pad_4[0x2C];
};
#pragma pack(pop)
static_assert(sizeof(CMoResType19) == 0x30, "CMoResType19: sizeof");
