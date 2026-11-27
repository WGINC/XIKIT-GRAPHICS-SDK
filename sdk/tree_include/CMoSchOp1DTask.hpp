// CMoSchOp1DTask -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API CMoSchOp1DTask {
public:
    int Slot11GetPathDriveActorRuntimeClass();  // 0x10063130
    int Slot12DeletePathDriveActorTask(int arg1);  // 0x10063140

    void **vftable;  // +0x0
    uint8_t _pad_4[0x30];
};
#pragma pack(pop)
static_assert(sizeof(CMoSchOp1DTask) == 0x34, "CMoSchOp1DTask: sizeof");
