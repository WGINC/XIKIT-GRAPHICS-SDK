// CXiActor -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CXiActor {
public:
    static void __thiscall SpawnResourceGenerators(void * self, undefined4 * param_1);  // 0x10085060
    static void __thiscall RequestModelParts(void * self);  // 0x100D14C0

    void **vftable;  // +0x0
    uint8_t _pad_4[0x7C];
    uint32_t refCount;  // +0x80 unknown type, 4 bytes
    uint32_t schRefCount;  // +0x84 unknown type, 4 bytes
    uint8_t _pad_88[0xC];
    float moveSpeedBase;  // +0x94
    float moveSpeed;  // +0x98
    uint8_t _pad_9C[0x8];
    int32_t subActorStatus;  // +0xA4
    uint8_t _pad_A8[0x14];
    float distanceToCamera;  // +0xBC
    uint8_t _pad_C0[0x4];
};
#pragma pack(pop)
static_assert(sizeof(CXiActor) == 0xC4, "CXiActor: sizeof");
static_assert(XI_OFFSETOF(CXiActor, refCount) == 0x80, "CXiActor: layout");
static_assert(XI_OFFSETOF(CXiActor, schRefCount) == 0x84, "CXiActor: layout");
static_assert(XI_OFFSETOF(CXiActor, moveSpeedBase) == 0x94, "CXiActor: layout");
static_assert(XI_OFFSETOF(CXiActor, moveSpeed) == 0x98, "CXiActor: layout");
static_assert(XI_OFFSETOF(CXiActor, subActorStatus) == 0xA4, "CXiActor: layout");
static_assert(XI_OFFSETOF(CXiActor, distanceToCamera) == 0xBC, "CXiActor: layout");
