// XiModelActor -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API XiModelActor {
public:
    static bits32 __thiscall CopyRectFromSlot(void * self, bits32 arg2, bits32 * arg3);  // 0x100C4B00
    static bits32 __thiscall BuildWorldMatrix(void * self, bits32 arg2, void * arg3);  // 0x100C4B50
    static bits32 __thiscall BuildMatrixAndDraw(void * self);  // 0x100C4C20

    void **vftable;  // +0x0
    uint8_t _pad_4[0x790];
};
#pragma pack(pop)
static_assert(sizeof(XiModelActor) == 0x794, "XiModelActor: sizeof");
