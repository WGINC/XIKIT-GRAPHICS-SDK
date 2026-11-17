# GeneratorClone

Group: `Generator` (by the file name only). Source: `sdk/tree_src/GeneratorClone.cpp`.

Why the file has this name (data/unit_names.json): CMoGeneratorClone::* (the effect generator command list), GateEffectBoxProjection

69 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `GeneratorClone_FindRecordByType` | 0x10049330 | 52 | yes | - | Finds a record of a given type in a packed record list. | low |
| `GeneratorClone_GetShort22ViaPtrE4` | 0x100493B0 | 11 | yes | - | Returns the 16-bit value at offset 0x22 of the object pointed to by the field at +0xE4. | low |
| `GeneratorClone_GetCmdType1Data` | 0x100493C0 | 45 | yes | - | Returns the data of the type-1 command, or a pointer to a zeroed static dword when there is none. | medium |
| `GateEffectBoxProjection` | 0x1004A870 | 263 | yes | 2 | - | - |
| `GeneratorClone_GetSelf` | 0x1004E210 | 3 | yes | - | Returns the object pointer it is given. | low |
| `GeneratorClone_SetByte` | 0x1004E250 | 9 | yes | - | Stores the low byte of its argument into the object's first byte. | medium |
| `GeneratorClone_GetSelfPlus2` | 0x1004E260 | 4 | yes | - | Returns the object pointer plus 2. | low |
| `GeneratorClone_GetSelfPlus1` | 0x1004E270 | 4 | yes | - | Returns the object pointer plus 1. | low |
| `GeneratorClone_ReturnThisA` | 0x1004E280 | 3 | yes | - | Returns this. | low |
| `GeneratorClone_GetSelfPlus3` | 0x1004E290 | 4 | yes | - | Returns the object pointer plus 3. | low |
| `GeneratorClone_GetByte2Ptr` | 0x1004E2A0 | 4 | yes | - | Returns the address of the byte at +2. | low |
| `GeneratorClone_GetByte1Ptr` | 0x1004E2B0 | 4 | yes | - | Returns the address of the byte at +1. | low |
| `GeneratorClone_ReturnThisB` | 0x1004E2C0 | 3 | yes | - | Returns this. | low |
| `GeneratorClone_GetByte3Ptr` | 0x1004E2D0 | 4 | yes | - | Returns the address of the byte at +3. | low |
| `GeneratorClone_CopyDwords` | 0x1004E320 | 23 | yes | - | Copies a 3-component vector into this one. | medium |
| `GeneratorClone_Accumulate` | 0x1004E360 | 31 | yes | - | Adds a 3-component vector to this one in place. | medium |
| `GeneratorClone_IsFirstDwordNotEqual` | 0x1004E3B0 | 16 | yes | - | Tests whether the object's first dword differs from the argument. | medium |
| `Pool_FreeSlot` | 0x1004E3F0 | 28 | yes | - | - | - |
| `GeneratorClone_GetBits13To18Shl2` | 0x1004E490 | 11 | yes | - | Returns bits 13 to 18 of the object's first dword, shifted left by 2. | low |
| `GeneratorClone_EvaluateWithMode4` | 0x1004E4E0 | 79 | yes | - | Evaluates the curve held by the object's first pointer, choosing the evaluator from the mode byte at +4. | medium |
| `ScaleElemVisibilityByProbe` | 0x1004E630 | 231 | yes | 2 | - | - |
| `GeneratorClone_GetByte` | 0x100527B0 | 5 | yes | - | Returns the byte at the object's offset 0. | medium |
| `GeneratorClone_SetDwords` | 0x100527C0 | 31 | yes | - | Stores four dword values in a 16-byte block at +0x30. | low |
| `GeneratorClone_CallProcessorSlot49` | 0x100527E0 | 8 | yes | - | Passes its object pointer to the processor's vtable slot 49. | low |
| `GeneratorClone_ReturnThis` | 0x100527F0 | 3 | yes | - | Returns its this pointer. | low |
| `GeneratorClone_Set3Dwords` | 0x10052800 | 23 | yes | - | Stores three dwords at the start of the object. | medium |
| `GeneratorClone_SubInto` | 0x10052820 | 67 | yes | - | Writes the difference of this vector and another into the output vector. | medium |
| `GeneratorClone_SetDwordAndCopyOut` | 0x10052870 | 15 | yes | - | Stores one dword at the object and at the pointer argument, and returns that pointer. | low |
| `GeneratorClone_SetDword` | 0x10052880 | 9 | yes | - | Stores a dword in the object's first field. | medium |
| `GeneratorClone_GetDwordThroughPtr` | 0x10052890 | 5 | yes | - | Returns the dword that the object's first pointer points to. | medium |
| `GeneratorClone_GetDword` | 0x100528A0 | 3 | yes | - | Returns the object's first dword. | medium |
| `GeneratorClone_GetPtr30` | 0x100528B0 | 4 | yes | - | Returns the address of the object's field at offset 0x30. | low |
| `GeneratorClone_SetPtrAndGetDword` | 0x100528C0 | 20 | yes | - | Stores a pointer in the object and returns the dword it points to, or 0 when it is null. | medium |
| `GeneratorClone_GetFirstDeref` | 0x100528E0 | 5 | yes | - | Returns the value the first field points to. | low |
| `GeneratorClone_GetDwordThroughPtrOrZero` | 0x100528F0 | 12 | yes | - | Returns the dword that the object's first pointer points to, or 0 when that pointer is null. | medium |
| `GeneratorClone_GetPtrB90` | 0x10052900 | 7 | yes | - | Returns the address of the object's field at offset 0xB90. | low |
| `MoProcessor_PopFreeIndex` | 0x10052910 | 33 | yes | - | Takes the next index from the processor's free-index table. | low |
| `GeneratorClone_GetFirst` | 0x10052940 | 3 | yes | - | Returns the first field. | low |
| `GeneratorClone_GetWordAt176` | 0x10052950 | 8 | yes | - | Returns the 16-bit value at offset 0x176. | medium |
| `GeneratorClone_GetPtr188` | 0x100529A0 | 7 | yes | - | Returns the address of the +0x188 sub-object. | low |
| `GeneratorClone_SetLow2Bits17B` | 0x100529B0 | 30 | yes | - | Sets the low two bits of the dword at +0x17B to the low two bits of its argument. | medium |
| `GeneratorClone_Set179Byte` | 0x100529D0 | 13 | yes | - | Stores a byte at +0x179. | low |
| `GeneratorClone_SetFields300And130` | 0x100529E0 | 23 | yes | - | Stores two dwords at +0x12C and +0x130. | low |
| `GeneratorClone_GetFloat300` | 0x10052A00 | 7 | yes | - | Returns the float at +0x12C. | low |
| `GeneratorClone_Set172Short` | 0x10052A10 | 15 | yes | - | Stores a short at +0x172. | low |
| `GeneratorClone_Set120` | 0x10052A20 | 13 | yes | - | Stores a dword at +0x120. | low |
| `GeneratorClone_Set124` | 0x10052A30 | 13 | yes | - | Stores a dword at +0x124. | low |
| `GeneratorClone_GetFloat120` | 0x10052A40 | 7 | yes | - | Returns the float at +0x120. | low |
| `GeneratorClone_GetFloat124` | 0x10052A50 | 7 | yes | - | Returns the float at +0x124. | low |
| `GeneratorClone_AllocWithFallback` | 0x10052A60 | 23 | yes | - | Allocates a block at an offset computed from its arguments. | low |
| `GeneratorClone_TestFn473F0` | 0x10052A80 | 12 | yes | - | Returns whether FUN_100473f0 reports non-zero for this object. | low |
| `GeneratorClone_HasFlags4And8` | 0x10052A90 | 20 | yes | - | Tests bits 0x4 and 0x8 of the flags at +0x10C. | low |
| `GeneratorClone_Get9C` | 0x10052AB0 | 7 | yes | - | Returns the dword at +0x9C. | low |
| `GeneratorClone_Set9C` | 0x10052AC0 | 13 | yes | - | Stores a dword at +0x9C. | low |
| `GeneratorClone_GetC4` | 0x10052AD0 | 7 | yes | - | Returns the dword at +0xC4. | low |
| `GeneratorClone_GetPtrDE` | 0x10052AE0 | 7 | yes | - | Returns the address of the +0xDE sub-object. | low |
| `GeneratorClone_IsA4NonZero` | 0x10052AF0 | 14 | yes | - | Tests whether the +0xA4 field is non-zero. | low |
| `GeneratorClone_GetA4` | 0x10052B00 | 7 | yes | - | Returns the dword at +0xA4. | low |
| `GeneratorClone_GetPtr78` | 0x10052B10 | 4 | yes | - | Returns the address of the +0x78 sub-object. | low |
| `GeneratorClone_GetPtr84` | 0x10052B20 | 7 | yes | - | Returns the address of the +0x84 sub-object. | low |
| `GeneratorClone_CopyF4Out` | 0x10052B30 | 15 | yes | - | Copies the +0xF4 dword to the output. | low |
| `GeneratorClone_Set0` | 0x10052B40 | 9 | yes | - | Stores a dword at +0. | low |
| `GeneratorClone_Set4` | 0x10052B50 | 10 | yes | - | Stores a dword at +4. | low |
| `GeneratorClone_Set8` | 0x10052B60 | 10 | yes | - | Stores a dword at +8. | low |
| `GeneratorClone_SetFloat8FromRadians` | 0x10052B70 | 16 | yes | - | Stores a radian value at +8 as a fraction of a turn (divided by pi). | medium |
| `GeneratorClone_SetFloat8FromByte` | 0x10052B80 | 16 | yes | - | Stores a byte-range integer at +8 as a float in 0..1. | medium |
| `GeneratorClone_SetFloat8Scaled120` | 0x10052B90 | 16 | yes | - | Stores its argument divided by 120 at +8. | low |
| `GeneratorClone_SetField8Dword` | 0x10052BA0 | 10 | yes | - | Stores a dword at +8. | low |
| `GeneratorClone_Set46Short` | 0x10052BB0 | 12 | yes | - | Stores a short at +0x46. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `GeneratorClone_FindRecordByType` calls nothing directly
- `GeneratorClone_GetShort22ViaPtrE4` calls nothing directly
- `GeneratorClone_GetCmdType1Data` calls `CMoGeneratorClone::FindCmdByType`
- `GateEffectBoxProjection` calls `Camera_GetViewportHeight`, `Camera_GetViewportWidth`, `Occlusion_QueryScreenRect`
- `GeneratorClone_GetSelf` calls nothing directly
- `GeneratorClone_SetByte` calls nothing directly
- `GeneratorClone_GetSelfPlus2` calls nothing directly
- `GeneratorClone_GetSelfPlus1` calls nothing directly
- `GeneratorClone_ReturnThisA` calls nothing directly
- `GeneratorClone_GetSelfPlus3` calls nothing directly
- `GeneratorClone_GetByte2Ptr` calls nothing directly
- `GeneratorClone_GetByte1Ptr` calls nothing directly
- `GeneratorClone_ReturnThisB` calls nothing directly
- `GeneratorClone_GetByte3Ptr` calls nothing directly
- `GeneratorClone_CopyDwords` calls nothing directly
- `GeneratorClone_Accumulate` calls nothing directly
- `GeneratorClone_IsFirstDwordNotEqual` calls nothing directly
- `Pool_FreeSlot` calls nothing directly
- `GeneratorClone_GetBits13To18Shl2` calls nothing directly
- `GeneratorClone_EvaluateWithMode4` calls `ElemCurve_EvaluateEaseIn`, `ElemCurve_EvaluateWithFlag34`
- `ScaleElemVisibilityByProbe` calls `Camera_GetViewportHeight`, `Camera_GetViewportWidth`, `Occlusion_QueryScreenRect`
- `GeneratorClone_GetByte` calls nothing directly
- `GeneratorClone_SetDwords` calls nothing directly
- `GeneratorClone_CallProcessorSlot49` calls `MoProcessor_CallVSlot49`
- `GeneratorClone_ReturnThis` calls nothing directly
- `GeneratorClone_Set3Dwords` calls nothing directly
- `GeneratorClone_SubInto` calls nothing directly
- `GeneratorClone_SetDwordAndCopyOut` calls nothing directly
- `GeneratorClone_SetDword` calls nothing directly
- `GeneratorClone_GetDwordThroughPtr` calls nothing directly
- `GeneratorClone_GetDword` calls nothing directly
- `GeneratorClone_GetPtr30` calls nothing directly
- `GeneratorClone_SetPtrAndGetDword` calls nothing directly
- `GeneratorClone_GetFirstDeref` calls nothing directly
- `GeneratorClone_GetDwordThroughPtrOrZero` calls nothing directly
- `GeneratorClone_GetPtrB90` calls nothing directly
- `MoProcessor_PopFreeIndex` calls nothing directly
- `GeneratorClone_GetFirst` calls nothing directly
- `GeneratorClone_GetWordAt176` calls nothing directly
- `GeneratorClone_GetPtr188` calls nothing directly
- `GeneratorClone_SetLow2Bits17B` calls nothing directly
- `GeneratorClone_Set179Byte` calls nothing directly
- `GeneratorClone_SetFields300And130` calls nothing directly
- `GeneratorClone_GetFloat300` calls nothing directly
- `GeneratorClone_Set172Short` calls nothing directly
- `GeneratorClone_Set120` calls nothing directly
- `GeneratorClone_Set124` calls nothing directly
- `GeneratorClone_GetFloat120` calls nothing directly
- `GeneratorClone_GetFloat124` calls nothing directly
- `GeneratorClone_AllocWithFallback` calls `Mem_AllocWithFallback`
- `GeneratorClone_TestFn473F0` calls `CMoElem::GetActiveField0A4`
- `GeneratorClone_HasFlags4And8` calls nothing directly
- `GeneratorClone_Get9C` calls nothing directly
- `GeneratorClone_Set9C` calls nothing directly
- `GeneratorClone_GetC4` calls nothing directly
- `GeneratorClone_GetPtrDE` calls nothing directly
- `GeneratorClone_IsA4NonZero` calls nothing directly
- `GeneratorClone_GetA4` calls nothing directly
- `GeneratorClone_GetPtr78` calls nothing directly
- `GeneratorClone_GetPtr84` calls nothing directly
- `GeneratorClone_CopyF4Out` calls nothing directly
- `GeneratorClone_Set0` calls nothing directly
- `GeneratorClone_Set4` calls nothing directly
- `GeneratorClone_Set8` calls nothing directly
- `GeneratorClone_SetFloat8FromRadians` calls nothing directly
- `GeneratorClone_SetFloat8FromByte` calls nothing directly
- `GeneratorClone_SetFloat8Scaled120` calls nothing directly
- `GeneratorClone_SetField8Dword` calls nothing directly
- `GeneratorClone_Set46Short` calls nothing directly
