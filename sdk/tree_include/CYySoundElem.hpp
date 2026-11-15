// CYySoundElem -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CYySoundElem {
public:
    static void __cdecl UpdateQueue();  // 0x10036230
    static void __thiscall UpdateOne(void * self);  // 0x100364A0
    static undefined4 __thiscall UpdateTimerAndPosition(void * self);  // 0x100364E0
    static undefined4 __thiscall UpdateFromCamera(void * self);  // 0x100368B0

    void **vftable;  // +0x0
    uint8_t _pad_4[0x1E9];
};
#pragma pack(pop)
static_assert(sizeof(CYySoundElem) == 0x1ED, "CYySoundElem: sizeof");
