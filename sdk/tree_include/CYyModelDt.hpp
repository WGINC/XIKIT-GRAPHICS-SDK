// CYyModelDt -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CYyModelDt {
public:
    static int __cdecl SetVertexShader(int arg1);  // 0x10022FA0
    static void * __thiscall Construct(void * self);  // 0x10025010
    char PrepareRenderStateEntry(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6);  // 0x10025030
    unsigned short PrepareRenderStateSimpleEntry(int arg1, int arg2, int arg3, int arg4, int arg5);  // 0x10025060
    int MarkReferencedBones(int arg1);  // 0x100251A0
    static char ** __cdecl GetRuntimeClass();  // 0x10029880
    static void __thiscall InitBase(void * self);  // 0x10029BB0
    static bits32 * __thiscall Init(void * self);  // 0x10029C90
    uint32_t * ScalarDeletingDtor(char arg1);  // 0x10029CB0
    static void __thiscall PrepareRenderStateV2Entry(void * self, bits32 arg2, bits32 arg3, bits32 arg4, bits32 arg5, bits32 * arg6, bits32 * arg7);  // 0x1002A000
    static bits32 __thiscall PrepareRenderStateV2SimpleEntry(void * self, bits32 arg2, bits32 arg3, bits32 arg4, bits32 arg5, bits32 arg6);  // 0x1002A040
    static bits32 __thiscall GetResourceWord5E(void * self);  // 0x1002A080
    short SkinAndDrawV2(int arg1, int arg2, int _180, int arg4, uint32_t *arg5, uint32_t *arg6);  // 0x1002DC10

    void **vftable;  // +0x0
    uint8_t _pad_4[0x4];
    int32_t modelResourceHandle;  // +0x8 handle of the model resource, dereferenced with ResourceHandle_Deref
    uint8_t _pad_C[0x27];
    uint8_t renderVariant;  // +0x33 selector of which flag bytes SkinAndDrawV2 sets
    uint8_t extraStreamFlags;  // +0x34 bit 0: also bind the two extra vertex streams and draw them
    uint8_t _pad_35[0x7];
};
#pragma pack(pop)
static_assert(sizeof(CYyModelDt) == 0x3C, "CYyModelDt: sizeof");
static_assert(XI_OFFSETOF(CYyModelDt, modelResourceHandle) == 0x8, "CYyModelDt: layout");
static_assert(XI_OFFSETOF(CYyModelDt, renderVariant) == 0x33, "CYyModelDt: layout");
static_assert(XI_OFFSETOF(CYyModelDt, extraStreamFlags) == 0x34, "CYyModelDt: layout");
