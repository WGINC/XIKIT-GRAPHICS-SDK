// CMoSchOp1FAttachments -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoSchOp1FAttachments {
public:
    uint32_t * Slot1DeleteOwner(char arg1);  // 0x10062F60

    void **vftable;  // +0x0
    uint8_t _pad_4[0x3C];
};
#pragma pack(pop)
static_assert(sizeof(CMoSchOp1FAttachments) == 0x40, "CMoSchOp1FAttachments: sizeof");
