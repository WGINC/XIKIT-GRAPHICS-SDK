// CMoSchOp1DAttachments -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoSchOp1DAttachments {
public:
    _DWORD * Slot1DeleteOwner(char a2);  // 0x100630E0

    void **vftable;  // +0x0
    uint8_t _pad_4[0x3C];
};
#pragma pack(pop)
static_assert(sizeof(CMoSchOp1DAttachments) == 0x40, "CMoSchOp1DAttachments: sizeof");
