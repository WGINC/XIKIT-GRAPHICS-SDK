// CMoDamValueProgElem -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoDamValueProgElem {
public:
    void Slot18DrawTextAtTarget();  // 0x10041AF0
    int * ScalarDeletingDtor(char arg1);  // 0x10041FE0

    void **vftable;  // +0x0
    uint8_t _pad_4[0xF8];
    int * listAResourceHandle;  // +0xFC pointer to a handle of the linked resource (same member as CMoElem+0xFC)
    uint8_t _pad_100[0x94];
};
#pragma pack(pop)
static_assert(sizeof(CMoDamValueProgElem) == 0x194, "CMoDamValueProgElem: sizeof");
static_assert(XI_OFFSETOF(CMoDamValueProgElem, listAResourceHandle) == 0xFC, "CMoDamValueProgElem: layout");
