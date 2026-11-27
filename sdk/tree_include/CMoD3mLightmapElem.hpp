// CMoD3mLightmapElem -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoD3mLightmapElem {
public:
    static bits32 __thiscall DrawLightmapPass(void * self);  // 0x10040E70
    static uint64_t __thiscall Ctor(void * self);  // 0x10052E90

    void **vftable;  // +0x0
    uint8_t _pad_4[0x198];
};
#pragma pack(pop)
static_assert(sizeof(CMoD3mLightmapElem) == 0x19C, "CMoD3mLightmapElem: sizeof");
