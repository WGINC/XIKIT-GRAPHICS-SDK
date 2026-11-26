// CXiDancerActor -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CXiDancerActor {
public:
    static bits32 __thiscall Construct(void * self, bits32 arg2, bits32 arg3, bits32 arg4, uint32_t arg5);  // 0x100AB700
    static void __thiscall InitBind(void * self, bits32 arg2, bits32 arg3, bits32 * arg4, uint32_t arg5);  // 0x100AB750
    static void __thiscall SetPosition(void * self, bits32 * arg2);  // 0x100AB830
    static void __thiscall ApplyStateBlock(void * self, void * arg2, bits32 * arg3, bits32 * arg4, bits32 * arg5);  // 0x100AB9A0

    void **vftable;  // +0x0
    uint8_t _pad_4[0xCB4];
};
#pragma pack(pop)
static_assert(sizeof(CXiDancerActor) == 0xCB8, "CXiDancerActor: sizeof");
