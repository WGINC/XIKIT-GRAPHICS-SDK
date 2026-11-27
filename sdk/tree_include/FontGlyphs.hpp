// FontGlyphs -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API FontGlyphs {
public:
    int FontGlyphs_DrawString(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8);  // 0x1011C080

    void **vftable;  // +0x0
    uint8_t _pad_4[0xC];
    uint32_t quad0_color;  // +0x10 colour of vertex 0 of a 28-byte-stride quad from +0x0; FontGlyphs_DrawString sets all fo
    uint8_t _pad_14[0x18];
    uint32_t quad1_color;  // +0x2C colour of vertex 1 of a 28-byte-stride quad from +0x0; FontGlyphs_DrawString sets all fo
    uint8_t _pad_30[0x18];
    uint32_t quad2_color;  // +0x48 colour of vertex 2 of a 28-byte-stride quad from +0x0; FontGlyphs_DrawString sets all fo
    uint8_t _pad_4C[0x18];
    uint32_t quad3_color;  // +0x64 colour of vertex 3 of a 28-byte-stride quad from +0x0; FontGlyphs_DrawString sets all fo
};
#pragma pack(pop)
static_assert(XI_OFFSETOF(FontGlyphs, quad0_color) == 0x10, "FontGlyphs: layout");
static_assert(XI_OFFSETOF(FontGlyphs, quad1_color) == 0x2C, "FontGlyphs: layout");
static_assert(XI_OFFSETOF(FontGlyphs, quad2_color) == 0x48, "FontGlyphs: layout");
static_assert(XI_OFFSETOF(FontGlyphs, quad3_color) == 0x64, "FontGlyphs: layout");
