// CMoTaskMng -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoTaskMng {
public:
    uint32_t * ScalarDeletingDtor(char arg1);  // 0x10011950
    static bits32 __stdcall Forward10075120(bits32 xi_s1);  // 0x10074A10
    static char ** __cdecl GetRuntimeClass();  // 0x10074B50
    static void __thiscall InitPool(void * self);  // 0x10074BA0
    static bits32 __thiscall DrawAll(void * self);  // 0x10074C30
    static void __thiscall RemoveByKey(void * self, int arg2, int arg3);  // 0x10074CF0
    static int __thiscall AllocTask(void * self, bits32 arg2);  // 0x10074DF0
    static uint64_t __thiscall InsertIntoBucket(void * self, int arg2, int arg3);  // 0x10074F80
    static uint64_t __thiscall EnqueueTask(void * self, int arg2);  // 0x100750B0
    static int __thiscall InsertAfterCursor(void * self, int arg2);  // 0x10075120
    static void __thiscall UnlinkTask(void * self, int arg2);  // 0x100751B0

    void **vftable;  // +0x0
    uint8_t _pad_4[0xD60];
};
#pragma pack(pop)
static_assert(sizeof(CMoTaskMng) == 0xD64, "CMoTaskMng: sizeof");
