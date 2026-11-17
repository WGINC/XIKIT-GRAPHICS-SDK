// CMoBm2Res -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoBm2Res {
public:
    static undefined4 __thiscall ReleaseTexture(void * self);  // 0x1001DBD0
    int Slot4StoreInHandle(int a2);  // 0x1001DC20
    unsigned int ** ScalarDeletingDtor(char a2);  // 0x10071A40

    void **vftable;  // +0x0
    uint8_t _pad_4[0x10];
    _DWORD * field_14;  // +0x14
    uint8_t _pad_18[0x18];
};
#pragma pack(pop)
static_assert(sizeof(CMoBm2Res) == 0x30, "CMoBm2Res: sizeof");
static_assert(XI_OFFSETOF(CMoBm2Res, field_14) == 0x14, "CMoBm2Res: layout");
