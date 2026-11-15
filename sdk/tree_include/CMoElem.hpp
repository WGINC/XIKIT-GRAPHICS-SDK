// CMoElem -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoElem {
public:
    static undefined4 __thiscall AdvanceTimer(void * self);  // 0x10044AE0
    static undefined4 __thiscall PrepareDraw(void * self);  // 0x10045A40

    void **vftable;  // +0x0
    uint8_t _pad_4[0xF8];
    int32_t listAResourceHandle;  // +0xFC pointer to a handle of the resource this element is linked to through list A
    int32_t listBResourceHandle;  // +0x100 pointer to a handle of the resource this element is linked to through list B
    uint8_t _pad_104[0x4];
    int32_t headeredAllocation;  // +0x108 block freed with sub_1006C110 by the cleanup
    uint8_t _pad_10C[0x58];
    int32_t backrefResourceHandle;  // +0x164 pointer to a handle of a resource whose +248 back-reference the cleanup clears and releases
    uint8_t _pad_168[0x2C];
};
#pragma pack(pop)
static_assert(sizeof(CMoElem) == 0x194, "CMoElem: sizeof");
static_assert(XI_OFFSETOF(CMoElem, listAResourceHandle) == 0xFC, "CMoElem: layout");
static_assert(XI_OFFSETOF(CMoElem, listBResourceHandle) == 0x100, "CMoElem: layout");
static_assert(XI_OFFSETOF(CMoElem, headeredAllocation) == 0x108, "CMoElem: layout");
static_assert(XI_OFFSETOF(CMoElem, backrefResourceHandle) == 0x164, "CMoElem: layout");
