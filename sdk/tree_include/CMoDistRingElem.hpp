// CMoDistRingElem -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoDistRingElem {
public:
    void AllocRingGeometry();  // 0x10043720

    void **vftable;  // +0x0
    uint8_t _pad_4[0x9C];
    uint8_t field_A0;  // +0xA0
    uint8_t _pad_A1[0xF7];
    uint8_t field_198;  // +0x198
    uint8_t _pad_199[0xC];
    uint8_t field_1A5;  // +0x1A5
    uint8_t _pad_1A6[0xE];
    uint8_t segmentCount;  // +0x1B4 number of segments around the ring
    uint8_t ringLevelCount;  // +0x1B5 number of levels (rings) along the profile; field_1B5-1 strips are drawn
    uint8_t _pad_1B6[0x4];
};
#pragma pack(pop)
static_assert(sizeof(CMoDistRingElem) == 0x1BA, "CMoDistRingElem: sizeof");
static_assert(XI_OFFSETOF(CMoDistRingElem, field_A0) == 0xA0, "CMoDistRingElem: layout");
static_assert(XI_OFFSETOF(CMoDistRingElem, field_198) == 0x198, "CMoDistRingElem: layout");
static_assert(XI_OFFSETOF(CMoDistRingElem, field_1A5) == 0x1A5, "CMoDistRingElem: layout");
static_assert(XI_OFFSETOF(CMoDistRingElem, segmentCount) == 0x1B4, "CMoDistRingElem: layout");
static_assert(XI_OFFSETOF(CMoDistRingElem, ringLevelCount) == 0x1B5, "CMoDistRingElem: layout");
