// YkJpeg -- graphics members reconstructed from Hex-Rays output, gate-verified.
// Unnamed fields are field_XXX (the offset); sizes come from the class descriptor.
#pragma once
#include "gfx_common.hpp"
#pragma pack(push, 1)
class XI_API YkJpeg {
public:
    static void __thiscall InitTables(void * self);  // 0x101CF870
    static void __stdcall CopyBlock(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6);  // 0x101CFDB0
    static int __stdcall Unpack565(uint32_t arg1, int * arg2, int * arg3, int arg4);  // 0x101CFE20
    static void __thiscall UnpackBlock565(void * self, int arg2, int arg3, int arg4, int arg5, int arg6, int * arg7);  // 0x101CFEB0
    static void __stdcall ForwardDct(int arg1);  // 0x101CFF60
    static void __thiscall EncodeBlock(void * self, int * arg2, char * arg3);  // 0x101D0210
    static bits32 __thiscall Encode(void * self, uint32_t arg2, uint32_t arg3, int arg4, int arg5);  // 0x101D0370
    static uint8_t * __cdecl GetCopyrightString();  // 0x101D05E0
    static int __thiscall EncodeChecked(void * self, uint32_t arg2, uint32_t arg3, int arg4, int arg5);  // 0x101D0600
    static bits32 __thiscall Destructor(void * self);  // 0x101D08C0
    static void __thiscall Release(void * self);  // 0x101D08D0
    static void __thiscall PutBit(void * self, int arg2);  // 0x101D0910
    static void __thiscall PutBits(void * self, uint32_t arg2, uint32_t arg3);  // 0x101D0970
    static void __thiscall PutBytes(void * self, int arg2, int arg3);  // 0x101D09E0
    static void __thiscall FlushBits(void * self);  // 0x101D0A60
    static bits32 __cdecl CaptureAndEncode(void * arg1, uint32_t arg2, uint32_t arg3);  // 0x101D1060

    void **vftable;  // +0x0
    uint8_t _pad_4[0xCF8];
};
#pragma pack(pop)
static_assert(sizeof(YkJpeg) == 0xCFC, "YkJpeg: sizeof");
