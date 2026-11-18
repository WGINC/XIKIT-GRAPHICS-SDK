// CMoBpRes -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoBpRes {
public:
    int Slot4StoreInHandle(int a2);  // 0x1001E050
    void Slot5Nop(int a1);  // 0x1001E060
    unsigned int ** ScalarDeletingDtor(char a2);  // 0x10071A60

    void **vftable;  // +0x0
    uint8_t _pad_4[0x10];
    _DWORD * field_14;  // +0x14
    uint8_t _pad_18[0x18];
};
#pragma pack(pop)
static_assert(sizeof(CMoBpRes) == 0x30, "CMoBpRes: sizeof");
static_assert(XI_OFFSETOF(CMoBpRes, field_14) == 0x14, "CMoBpRes: layout");
