// CMoTask -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoTask {
public:
    static char ** __cdecl GetRuntimeClass_variant0();  // 0x10010310
    void Slot7DoNothing();  // 0x10011920
    void Slot9DoNothing();  // 0x10011930
    void Slot10DoNothing(int arg1);  // 0x10011940
    static char ** __cdecl GetRuntimeClass_variant1();  // 0x1001B800
    static char ** __cdecl GetRuntimeClass_variant2();  // 0x1002C950
    static void * __thiscall CtorByMode(void * self, bits32 arg2, int arg3, bits32 arg4);  // 0x10035A00
    static void __cdecl CreateMode2(bits32 arg1, bits32 arg2);  // 0x10035D40
    static void __cdecl CreateMode1(bits32 arg1, int arg2);  // 0x10035D90
    static void __cdecl CreateMode4(bits32 arg1, int arg2);  // 0x10035DE0
    static char ** __cdecl GetRuntimeClass_variant3();  // 0x10037280
    static char ** __cdecl GetRuntimeClass_variant4();  // 0x1003CC60
    char Slot8ReturnFalse();  // 0x10042640
    static void __thiscall Restart(void * self);  // 0x10053370
    static char ** __cdecl GetRuntimeClass_variant5();  // 0x10055550
    static char ** __cdecl GetRuntimeClass_variant6();  // 0x10056930
    static char ** __cdecl GetRuntimeClass_variant7();  // 0x10056950
    static char ** __cdecl GetRuntimeClass_variant8();  // 0x10056970
    static char ** __cdecl GetRuntimeClass_variant9();  // 0x10056990
    static char ** __cdecl GetRuntimeClass_variant10();  // 0x100569B0
    static char ** __cdecl GetRuntimeClass_variant11();  // 0x10057080
    static void * __thiscall InitVariant12(void * self);  // 0x10070F40
    static void __thiscall InitAndRegister(void * self, bits32 arg2, bits32 arg3, bits32 arg4, bits32 arg5);  // 0x10070F90
    static char ** __cdecl GetRuntimeClass_variant12();  // 0x10074730
    static void * __thiscall Constructor(void * self);  // 0x10074740
    uint32_t * ScalarDeletingDtor(char arg1);  // 0x10074770
    static void __thiscall Destructor(void * self);  // 0x100747C0
    static void __thiscall DestroyChain(void * self);  // 0x10074890
    static bits32 __thiscall ResetFields(void * self);  // 0x100748F0
    static bits32 * __thiscall Clone(void * self, uint32_t arg2);  // 0x10074920
    static void __thiscall Release(void * self);  // 0x10074AB0
    static bits32 __thiscall DetachAndRecycle(void * self, int arg2);  // 0x10074AD0
    static void __cdecl Dispatch(int * arg1);  // 0x10075000
    int DrawQuadStates(float *arg1, char arg4);  // 0x10076030
    int DrawQuadDynVB(float *arg1, float *arg2, char arg3);  // 0x10076520
    static void __thiscall SetRect30(void * self, bits32 * arg2);  // 0x10076750
    static char ** __cdecl GetRuntimeClass_variant13();  // 0x10081710
    static char ** __cdecl GetRuntimeClass_variant14();  // 0x10081730
    static char ** __cdecl GetRuntimeClass_variant15();  // 0x10081750
    static char ** __cdecl GetRuntimeClass_variant16();  // 0x10084E50
    static char ** __cdecl GetRuntimeClass_variant17();  // 0x100A8E10
    static char ** __cdecl GetRuntimeClass_variant18();  // 0x100C51A0
    static char ** __cdecl GetRuntimeClass_variant19();  // 0x101773B0

    void **vftable;  // +0x0
    uint8_t _pad_4[0x30];
};
#pragma pack(pop)
static_assert(sizeof(CMoTask) == 0x34, "CMoTask: sizeof");
