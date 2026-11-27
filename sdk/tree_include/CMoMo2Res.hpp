// CMoMo2Res -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoMo2Res {
public:
    int Slot4StoreInHandle(int arg1);  // 0x10019A30
    void Slot5Nop(int arg1);  // 0x10019A40
    void Slot9Nop();  // 0x10071A00
    unsigned int ** ScalarDeletingDtor(char arg1);  // 0x10071AC0

    void **vftable;  // +0x0
    uint8_t _pad_4[0x10];
    uint32_t * field_14;  // +0x14
    uint8_t _pad_18[0x18];
};
#pragma pack(pop)
static_assert(sizeof(CMoMo2Res) == 0x30, "CMoMo2Res: sizeof");
static_assert(XI_OFFSETOF(CMoMo2Res, field_14) == 0x14, "CMoMo2Res: layout");
