// CMoSpline -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoSpline {
public:
    static char ** __cdecl GetRuntimeClass();  // 0x10063450
    int * ScalarDeletingDtor(char arg1);  // 0x10063480
    static void __thiscall Destructor(void * self);  // 0x100634A0
    static void __thiscall Init(void * self, int arg2, uint32_t arg3, bits32 arg4, bits32 arg5);  // 0x100634B0
    static void __thiscall FreeBuffers(void * self);  // 0x10063550
    static void __thiscall BuildSegmentTables(void * self);  // 0x100635B0
    static void __thiscall ReleaseRef(void * self);  // 0x10063B20
    static int * __thiscall GetWrapped(void * self, int arg2);  // 0x10063B50
    static int __thiscall GetData(void * self);  // 0x10063B70
    static bits32 __thiscall EnsureSamples(void * self);  // 0x10063B80
    static void __thiscall SetValue(void * self, float * arg2, bits32 arg3);  // 0x10063C30

    void **vftable;  // +0x0
    uint8_t _pad_4[0x24];
};
#pragma pack(pop)
static_assert(sizeof(CMoSpline) == 0x28, "CMoSpline: sizeof");
