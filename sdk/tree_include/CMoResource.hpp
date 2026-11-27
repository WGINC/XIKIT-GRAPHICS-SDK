// CMoResource -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoResource {
public:
    static char ** __cdecl GetRuntimeClass_variant0();  // 0x10036B70
    int CMoCamera_SetLinkedObject(int arg1);  // 0x10047FC0
    void Slot5DoNothing(int arg1);  // 0x10047FD0
    static char ** __cdecl GetRuntimeClass_variant1();  // 0x10056250
    static char ** __cdecl GetRuntimeClass_variant2();  // 0x10056290
    static char ** __cdecl GetRuntimeClass_variant3();  // 0x10071D70
    void Slot8DoNothing();  // 0x10071DB0
    unsigned int ** ScalarDeletingDtor(char arg1);  // 0x10071DC0
    static void __thiscall Destructor(void * self);  // 0x10071DE0
    static bits32 __thiscall ReleaseChain(void * self);  // 0x10071EC0
    static bits32 __thiscall RegisterInTypeList(void * self);  // 0x10072030
    static void * __thiscall GetParent(void * self);  // 0x10072270
    static uint64_t __thiscall FindByTypeAndId(void * self, bits32 * arg2, bits32 arg3, bits32 arg4);  // 0x10072290
    static uint64_t __thiscall FindWorker(void * self, bits32 * arg2, uint32_t arg3, int arg4, int arg5);  // 0x100722C0
    static bits32 * __stdcall FindOrCreateTask(bits32 * arg1, int arg2);  // 0x100730E0
    static void __stdcall RegisterAndMark(int * arg1, bits32 arg2);  // 0x10073A60
    static bits32 __stdcall InitAndGetFlag(int * arg1);  // 0x10073B80

    void **vftable;  // +0x0
    uint8_t _pad_4[0x10];
    uint32_t * field_14;  // +0x14
    uint8_t _pad_18[0x18];
};
#pragma pack(pop)
static_assert(sizeof(CMoResource) == 0x30, "CMoResource: sizeof");
static_assert(XI_OFFSETOF(CMoResource, field_14) == 0x14, "CMoResource: layout");
