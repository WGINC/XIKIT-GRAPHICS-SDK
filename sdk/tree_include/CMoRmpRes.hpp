// CMoRmpRes -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoRmpRes {
public:
    unsigned int ** ScalarDeletingDtor(char a2);  // 0x10071C90
    int Slot11GetCameraRuntimeClass();  // 0x100745E0
    int Slot12DeleteOwner(int a1);  // 0x100745F0
    void SetupNop();  // 0x10074610

    void **vftable;  // +0x0
    uint8_t _pad_4[0x2C];
};
#pragma pack(pop)
static_assert(sizeof(CMoRmpRes) == 0x30, "CMoRmpRes: sizeof");
