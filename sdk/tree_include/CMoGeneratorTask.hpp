// CMoGeneratorTask -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoGeneratorTask {
public:
    uint32_t * ScalarDeletingDtor(char arg1);  // 0x10053350
    static bits32 __thiscall RunGeneratorAndFinish(void * self);  // 0x10054220
    int Slot11GetCloneRuntimeClass();  // 0x10054460
    int Slot12DeleteClone(int arg1);  // 0x10054470

    void **vftable;  // +0x0
    uint8_t _pad_4[0x30];
};
#pragma pack(pop)
static_assert(sizeof(CMoGeneratorTask) == 0x34, "CMoGeneratorTask: sizeof");
