// CMoElemKind5C -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoElemKind5C {
public:
    void Slot18DrawTextAtTarget();  // 0x10041AF0
    int * ScalarDeletingDtor(char a2);  // 0x10041FE0

    void **vftable;  // +0x0
    uint8_t _pad_4[0xF8];
    int * listAResourceHandle;  // +0xFC pointer to a handle of the linked resource (same member as CMoElem+0xFC)
    uint8_t _pad_100[0x94];
};
#pragma pack(pop)
static_assert(sizeof(CMoElemKind5C) == 0x194, "CMoElemKind5C: sizeof");
static_assert(XI_OFFSETOF(CMoElemKind5C, listAResourceHandle) == 0xFC, "CMoElemKind5C: layout");
