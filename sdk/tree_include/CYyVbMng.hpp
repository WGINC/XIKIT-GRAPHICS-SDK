// CYyVbMng -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CYyVbMng {
public:
    int AcquireVertexBuffer(int arg1, int arg2, int arg3, int arg4, int *arg5, char arg6);  // 0x1003B210
    static bits32 __stdcall ReleaseVertexBuffer(int * arg1);  // 0x1003B3C0

    void **vftable;  // +0x0
    uint32_t pooledBufferCount;  // +0x4 number of pooled vertex buffers
    uint8_t _pad_8[0x4];
};
#pragma pack(pop)
static_assert(sizeof(CYyVbMng) == 0xC, "CYyVbMng: sizeof");
static_assert(XI_OFFSETOF(CYyVbMng, pooledBufferCount) == 0x4, "CYyVbMng: layout");
