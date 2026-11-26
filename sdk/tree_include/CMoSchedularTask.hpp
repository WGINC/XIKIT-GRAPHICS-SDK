// CMoSchedularTask -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoSchedularTask {
public:
    static char ** __cdecl GetRuntimeClass();  // 0x10057090
    void * ScalarDeletingDtor(char arg1);  // 0x10057250
    static void * __thiscall Construct(void * self, bits32 arg2, bits32 arg3, bits32 arg4);  // 0x10057270
    static bits32 __thiscall InitFromSource(void * self, int arg2, uint32_t arg3, short * arg4);  // 0x100573E0
    static void __thiscall Destructor(void * self);  // 0x100574A0
    static void __thiscall SetSharedRef(void * self, short * arg2);  // 0x10057CC0
    static bits32 __thiscall Update(void * self);  // 0x10057E10

    void **vftable;  // +0x0
    uint8_t _pad_4[0x146];
};
#pragma pack(pop)
static_assert(sizeof(CMoSchedularTask) == 0x14A, "CMoSchedularTask: sizeof");
