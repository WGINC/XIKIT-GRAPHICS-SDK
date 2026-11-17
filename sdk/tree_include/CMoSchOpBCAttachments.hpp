// CMoSchOpBCAttachments -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoSchOpBCAttachments {
public:
    _DWORD * Slot1DeleteOwner(char a2);  // 0x100630D0

    void **vftable;  // +0x0
    uint8_t _pad_4[0x3C];
};
#pragma pack(pop)
static_assert(sizeof(CMoSchOpBCAttachments) == 0x40, "CMoSchOpBCAttachments: sizeof");
