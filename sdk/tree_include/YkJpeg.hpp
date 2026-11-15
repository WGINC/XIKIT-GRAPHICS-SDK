// YkJpeg -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API YkJpeg {
public:
    static undefined4 __cdecl CaptureAndEncode(void * param_1, uint32_t param_2, uint32_t param_3);  // 0x101D1060

    void **vftable;  // +0x0
    uint8_t _pad_4[0xCF8];
};
#pragma pack(pop)
static_assert(sizeof(YkJpeg) == 0xCFC, "YkJpeg: sizeof");
