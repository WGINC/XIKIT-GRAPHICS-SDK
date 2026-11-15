// CYyModelBase -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CYyModelBase {
public:
    int DrawLit(int a2, int a3, int a4);  // 0x1002A3B0

    void **vftable;  // +0x0
    uint8_t _pad_4[0xC0];
    uint32_t cubemapSpecTexture;  // +0xC4 texture found by the cubemap-specular name, -1 until looked up
};
#pragma pack(pop)
static_assert(sizeof(CYyModelBase) == 0xC8, "CYyModelBase: sizeof");
static_assert(XI_OFFSETOF(CYyModelBase, cubemapSpecTexture) == 0xC4, "CYyModelBase: layout");
