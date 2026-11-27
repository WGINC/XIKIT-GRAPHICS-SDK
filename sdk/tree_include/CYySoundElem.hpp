// CYySoundElem -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CYySoundElem {
public:
    static void __cdecl UpdateQueue();  // 0x10036230
    static bits32 __cdecl QueueIfAbsent(int * arg1);  // 0x10036360
    static bits32 __thiscall ClearHandle(void * self);  // 0x10036420
    static void __thiscall UpdateOne(void * self);  // 0x100364A0
    static bits32 __thiscall UpdateTimerAndPosition(void * self);  // 0x100364E0
    static bits32 __thiscall IsFinished(void * self);  // 0x10036770
    static bits32 __thiscall IsTimerPositive(void * self);  // 0x100367C0
    static uint32_t __cdecl FindInQueue(bits32 * arg1);  // 0x10036830
    static bits32 __cdecl AppendToQueue(int * arg1);  // 0x10036870
    static bits32 __thiscall UpdateFromCamera(void * self);  // 0x100368B0
    static void __thiscall PushActive(void * self);  // 0x10036980
    static bits32 __thiscall Constructor(void * self);  // 0x100369F0

    void **vftable;  // +0x0
    uint8_t _pad_4[0x1E9];
};
#pragma pack(pop)
static_assert(sizeof(CYySoundElem) == 0x1ED, "CYySoundElem: sizeof");
