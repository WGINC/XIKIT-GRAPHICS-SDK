// CMoSchedulerResAttachments -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoSchedulerResAttachments {
public:
    unsigned int ** Slot1DeleteOwner(char arg1);  // 0x10074600

    void **vftable;  // +0x0
    uint8_t _pad_4[0x3C];
};
#pragma pack(pop)
static_assert(sizeof(CMoSchedulerResAttachments) == 0x40, "CMoSchedulerResAttachments: sizeof");
