// CMoCameraSetupTask -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoCameraSetupTask {
public:
    static uint32_t __thiscall Slot8SetupCameraAfterOneTick(void * self);  // 0x1006B480
    static _DWORD * __stdcall Slot1NopOnMessage6(_DWORD *a1);  // 0x1006B4C0

    void **vftable;  // +0x0
    uint8_t _pad_4[0x30];
};
#pragma pack(pop)
static_assert(sizeof(CMoCameraSetupTask) == 0x34, "CMoCameraSetupTask: sizeof");
