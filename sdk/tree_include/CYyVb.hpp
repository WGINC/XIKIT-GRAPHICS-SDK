// CYyVb -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CYyVb {
public:
    static bits32 __thiscall Init(void * self);  // 0x1003B420
    static void * __thiscall Constructor(void * self, bits32 arg2, bits32 arg3, bits32 arg4, bits32 arg5, bits32 arg6);  // 0x1003B450
    static void __thiscall Destroy(void * self);  // 0x1003B4A0

    void **vftable;  // +0x0
    uint8_t _pad_4[0x1C];
};
#pragma pack(pop)
static_assert(sizeof(CYyVb) == 0x20, "CYyVb: sizeof");
