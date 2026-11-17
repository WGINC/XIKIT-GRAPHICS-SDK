// CMoOs2Res -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoOs2Res {
public:
    static undefined4 __thiscall CheckVersionAndInit(void * self);  // 0x1002D7F0
    int Slot4PointersToWordOffsets(int a2);  // 0x1002D880
    unsigned int ** ScalarDeletingDtor(char a2);  // 0x10071A80

    void **vftable;  // +0x0
    uint8_t _pad_4[0x32];
    uint32_t field_36;  // +0x36
    uint8_t _pad_3A[0x2];
    uint32_t field_3C;  // +0x3C
    uint8_t _pad_40[0x2];
    uint32_t field_42;  // +0x42
    uint8_t _pad_46[0x2];
    uint32_t field_48;  // +0x48
    uint8_t _pad_4C[0x2];
    uint32_t field_4E;  // +0x4E
    uint8_t _pad_52[0x2];
    uint32_t field_54;  // +0x54
};
#pragma pack(pop)
static_assert(sizeof(CMoOs2Res) == 0x58, "CMoOs2Res: sizeof");
static_assert(XI_OFFSETOF(CMoOs2Res, field_36) == 0x36, "CMoOs2Res: layout");
static_assert(XI_OFFSETOF(CMoOs2Res, field_3C) == 0x3C, "CMoOs2Res: layout");
static_assert(XI_OFFSETOF(CMoOs2Res, field_42) == 0x42, "CMoOs2Res: layout");
static_assert(XI_OFFSETOF(CMoOs2Res, field_48) == 0x48, "CMoOs2Res: layout");
static_assert(XI_OFFSETOF(CMoOs2Res, field_4E) == 0x4E, "CMoOs2Res: layout");
static_assert(XI_OFFSETOF(CMoOs2Res, field_54) == 0x54, "CMoOs2Res: layout");
