// CYyMotionQue -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CYyMotionQue {
public:
    static void __thiscall SetSlotMotion(void * self, int * arg2, bits32 arg3, bits32 arg4, bits32 arg5, bits32 arg6, bits32 arg7, bits32 arg8, int arg9, bits32 arg10, bits32 arg11);  // 0x1001A660
    static void __thiscall StartMotion(void * self, int arg2, bits32 arg3, bits32 arg4, int arg5);  // 0x1001AB60
    static void __thiscall AppendSync(void * self, int * arg2, bits32 * arg3, bits32 arg4, bits32 arg5, bits32 arg6, bits32 arg7, bits32 arg8, bits32 arg9);  // 0x1001ACB0
    static bits32 __thiscall SampleInto(void * self, int arg2, bits32 arg3);  // 0x1001B230
    static void __thiscall Update(void * self, int * arg2, int arg3);  // 0x1001B2E0

    void **vftable;  // +0x0
    uint8_t _pad_4[0x3C];
};
#pragma pack(pop)
static_assert(sizeof(CYyMotionQue) == 0x40, "CYyMotionQue: sizeof");
