// CMoDX -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoDX {
public:
    static char ** __cdecl GetRuntimeClass();  // 0x10069D60
    uint8_t * ScalarDeletingDtor(char arg1);  // 0x10069DB0
    static bits32 __thiscall CreateTexture(void * self, bits32 arg2, bits32 arg3, bits32 * arg4);  // 0x1006A150
    static void __thiscall SetWorldMatrix(void * self, bits32 * arg2);  // 0x1006A480
    static void __thiscall PushViewMatrix(void * self);  // 0x1006A4C0
    static void __thiscall PopViewMatrix(void * self);  // 0x1006A4F0
    static void __thiscall SetViewMatrix(void * self, bits32 * arg2);  // 0x1006A520
    uint32_t * CreateAndInitSystem();  // 0x1006B2B0

    void **vftable;  // +0x0
    uint8_t _pad_4[0x1EC8];
};
#pragma pack(pop)
static_assert(sizeof(CMoDX) == 0x1ECC, "CMoDX: sizeof");
