# The effect interpreters' commands

Written by `pipeline/effect_commands.py` from FFXiMain.dll build 6A995428 (the game's own switches; the script's
first comment says how each column is read). A row is one case address of the switch: the command numbers that
jump there, what the code from there calls (in the order met), the classes whose vtable that code writes
(the class it makes; the base constructor it calls first is only a call), the game strings it uses, and the globals it writes. "instructions" is how many
instructions the walk met. Calls are listed as the code makes them, not followed further.

Not here: what each command's operands are (the offsets each case reads from the command), and the PS2 tag
names (YmGenerateCodeTag and the rest in DancingMad's ps2_types.json): nothing available here pairs a tag with
a number; the PS2 executable's own switch would. Not run: a command's effect in the game.

## Generator (0x1004E8D0): commands 1 to 0x9E

The generator runs the commands of a CMoGeneratorRes for each element it makes (command 1 makes the element:
its own switch on the element kind, 0x10050DA5).

| command | case | the code calls | vtables it writes | strings | writes | instructions |
|---|---|---|---|---|---|---|
| 0x01 | 0x10050D26 | `GeneratorClone_SetDwordAndCopyOut`, `GeneratorClone_AllocWithFallback`, `CMoElem::Constructor`, `GeneratorClone_Set179Byte`, `GeneratorRelease_Get10353710`, `sub_100749B0`, `sub_10044AA0`, `GeneratorClone_IsA4NonZero`, `Mem_AllocWithHeader12`, `GeneratorClone_GetA4`, `CMoElem::GetAddr78`, `GeneratorClone_GetPtr78` and 17 more (a switch of its own at 0x10050D3E, 0x10050DA5) |  |  |  | 300 |
| 0x02 | 0x1005159D | `CMoGeneratorClone::TestFlag20000000`, `GeneratorClone_GetBits13To18Shl2`, `GeneratorRelease_CopyFromPtr` |  |  |  | 23 |
| 0x03 | 0x100515EA | `GeneratorClone_GetBits13To18Shl2`, `Rand_SignedUniformTimes` |  |  |  | 28 |
| 13 commands: 0x04, 0x05, 0x0D, 0x0E, 0x14, 0x15, 0x1B, 0x1C, 0x20, 0x4D, 0x71, 0x73, 0x7B | 0x100523BF | (the default: no command) | | | | |
| 0x06 | 0x10051EA4 | `CMoGeneratorClone::TestFlag20000000`, `Rand_UniformTimes`, `GeneratorClone_Set3Dwords`, `Rand_SignedUniformTimes`, `GeneratorClone_Accumulate` |  |  |  | 50 |
| 0x07 | 0x10051F53 | `Rand_UniformTimes`, `GeneratorClone_Set3Dwords`, `Rand_SignedUniformTimes`, `MoProcessor_PopFreeIndex`, `GeneratorClone_GetFirst`, `GeneratorClone_CallProcessorSlot49`, `GeneratorClone_Accumulate`, `Pool_FreeSlot` |  |  |  | 92 |
| 0x08 | 0x100522BB | `CMoGeneratorClone::TestFlag20000000`, `GeneratorClone_ReturnThis`, `GeneratorClone_SubInto`, `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_GetSelf` |  |  |  | 56 |
| 0x09 | 0x1005163F | `GeneratorClone_GetSelf` |  |  |  | 10 |
| 0x0A | 0x1005164A | `Rand_SignedUniformTimes` |  |  |  | 65 |
| 0x0B | 0x10051771 | `GeneratorClone_GetBits13To18Shl2` |  |  |  | 13 |
| 0x0C | 0x1005179F | `GeneratorClone_GetBits13To18Shl2`, `Rand_SignedUniformTimes` |  |  |  | 28 |
| 0x0F | 0x10051BD1 | `GeneratorClone_GetSelf` |  |  |  | 9 |
| 0x10 | 0x10051BF2 | `GeneratorClone_GetSelf`, `Rand_UniformTimes` |  |  |  | 20 |
| 0x11 | 0x10051C32 | `Rand_UniformTimes`, `GeneratorClone_GetSelf` |  |  |  | 17 |
| 0x12 | 0x10051C6E | `GeneratorClone_GetBits13To18Shl2` |  |  |  | 13 |
| 0x13 | 0x10051C9C | `GeneratorClone_GetBits13To18Shl2`, `Rand_SignedUniformTimes` |  |  |  | 28 |
| 0x16 | 0x10051CF1 | `Color_SetFromU32SwapRB` |  |  |  | 5 |
| 0x17 | 0x10051DAF | `Rand_NextModUnsigned`, `SkyDome_AddToByte2`, `SkyDome_AddToByte1`, `SkyDome_AddToByte0` |  |  |  | 26 |
| 0x18 | 0x10051DFC | `Rand_NextModUnsigned`, `SkyDome_AddToByte2`, `SkyDome_AddToByte1`, `SkyDome_AddToByte0` |  |  |  | 16 |
| 0x19 | 0x10051E36 | `GeneratorClone_GetBits13To18Shl2` |  |  |  | 7 |
| 0x1A | 0x10051E4F | `GeneratorClone_GetBits13To18Shl2`, `Rand_NextMod` |  |  |  | 25 |
| 0x1D | 0x1005237E | `GeneratorClone_IsFirstDwordNotEqual`, `GeneratorClone_GetDwordThroughPtr`, `GeneratorClone_GetPtr30` |  |  |  | 15 |
| 0x1E | 0x10051D05 |  |  |  |  | 3 |
| 0x1F | 0x10052081 | `Rand_SignedUniformTimes`, `GeneratorClone_Get9C`, `MoProcessor_PopFreeIndex`, `GeneratorClone_GetFirst`, `GeneratorClone_CallProcessorSlot49`, `GeneratorClone_TestFn473F0`, `CMoElem::GetActiveField0A4`, `GeneratorClone_SetDwords`, `GeneratorClone_GetPtrB90`, `Rand_UniformTimes`, `GeneratorClone_Set3Dwords`, `GeneratorClone_Accumulate` and 1 more |  |  |  | 173 |
| 0x21, 0x95 | 0x100504C1 | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4`, `GeneratorClone_GetSelf`, `GeneratorClone_Set8` |  |  |  | 25 |
| 0x22, 0x96 | 0x10050707 | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4`, `GeneratorClone_GetSelf`, `GeneratorClone_Set8` |  |  |  | 25 |
| 0x23, 0x97 | 0x10050740 | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4`, `GeneratorClone_GetSelf`, `GeneratorClone_Set8` |  |  |  | 25 |
| 0x24 | 0x100504F9 | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4`, `GeneratorClone_GetSelf`, `GeneratorClone_SetFloat8FromRadians` |  |  |  | 25 |
| 0x25 | 0x10050534 | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4`, `GeneratorClone_GetSelf`, `GeneratorClone_SetFloat8FromRadians` |  |  |  | 25 |
| 0x26 | 0x10050570 | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4`, `GeneratorClone_GetSelf`, `GeneratorClone_SetFloat8FromRadians` |  |  |  | 25 |
| 0x27 | 0x100505AC | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4`, `GeneratorClone_GetSelf`, `GeneratorClone_Set8` |  |  |  | 25 |
| 0x28 | 0x100505E7 | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4`, `GeneratorClone_GetSelf`, `GeneratorClone_Set8` |  |  |  | 25 |
| 0x29 | 0x10050623 | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4`, `GeneratorClone_GetSelf`, `GeneratorClone_Set8` |  |  |  | 25 |
| 0x2A | 0x1005065F | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4`, `GeneratorClone_GetByte2Ptr`, `GeneratorClone_GetByte`, `GeneratorClone_SetFloat8FromByte` |  |  |  | 26 |
| 0x2B | 0x10050697 | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4`, `GeneratorClone_GetByte1Ptr`, `GeneratorClone_GetByte`, `GeneratorClone_SetFloat8FromByte` |  |  |  | 26 |
| 0x2C | 0x100506CF | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4`, `GeneratorClone_ReturnThisB`, `GeneratorClone_GetByte`, `GeneratorClone_SetFloat8FromByte` |  |  |  | 26 |
| 0x2D | 0x10050C82 | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_GetSelfPlus3`, `GeneratorClone_GetByte`, `GeneratorClone_SetFloat8FromByte`, `GeneratorClone_Set4` |  |  |  | 25 |
| 0x2E | 0x10050A85 | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4`, `GeneratorClone_GetFloat120`, `GeneratorClone_Set8`, `CMoGeneratorClone::SetFlagBit0At17B` |  |  |  | 27 |
| 0x2F | 0x10050AD6 | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4`, `GeneratorClone_GetFloat124`, `GeneratorClone_Set8`, `CMoGeneratorClone::SetFlagBit1At17B` |  |  |  | 27 |
| 0x30 | 0x10051D15 |  |  |  |  | 3 |
| 0x31 | 0x100517F4 | `Rand_SignedUniformTimes`, `GeneratorClone_GetBits13To18Shl2` |  |  |  | 18 |
| 0x32 | 0x10051B4B |  |  |  |  | 6 |
| 0x33, 0x36 | 0x10050825 | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4`, `GeneratorClone_Set8` |  |  |  | 21 |
| 0x34, 0x37 | 0x10050864 | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4`, `GeneratorClone_Set8` |  |  |  | 21 |
| 0x35 | 0x100507E6 | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4`, `GeneratorClone_Set8` |  |  |  | 21 |
| 0x38 | 0x100508A3 | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4`, `DistInit_ReturnOne`, `GeneratorClone_SetFloat8Scaled120` |  |  |  | 24 |
| 0x39 | 0x10050BC6 | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4`, `DistInit_ReturnSelf`, `GeneratorClone_SetField8Dword`, `CYyObject_IsKindOf` |  |  |  | 60 |
| 0x3A | 0x10051B5B |  |  |  |  | 26 |
| 0x3B | 0x1005035B | `sub_103138BA` |  |  |  | 29 |
| 0x3C | 0x1004EE0E | `sub_100496F0` |  |  |  | 18 |
| 0x3D | 0x1004F0EB |  |  |  |  | 17 |
| 0x3E | 0x1004F2DB | `Rand_SignedUniformTimes` |  |  |  | 16 |
| 0x3F | 0x1004F2F5 | `Rand_SignedUniformTimes` |  |  |  | 16 |
| 0x40 | 0x1004F311 | `Rand_SignedUniformTimes` |  |  |  | 15 |
| 0x41 | 0x1004F340 | `Rand_SignedUniformTimes` |  |  |  | 54 |
| 0x42 | 0x1004F7D6 | `CMoElem::GetActiveField0A4`, `ZoneMap_Query1693B0` |  |  |  | 76 |
| 0x43 | 0x100501B6 |  |  |  |  | 7 |
| 0x44, 0x53, 0x6A | 0x1004EE4A | `CMoAttachments::GetTarget`, `CMoAttachments::GetCaster`, `CMoGeneratorClone::CreateInstance`, `sub_10071E90`, `CYyObject_IsKindOf`, `CMoElem::GetAddr84`, `CMoElem::GetActiveField0A4`, `ElemFog_ComputeWorldPos`, `sub_100496F0` |  |  |  | 157 |
| 0x45 | 0x1004F8E5 | `AttachNotify_CopyFields`, `CMoAttachments::GetTarget`, `CMoAttachments::GetCaster`, `CMoAttachments::SetCaster`, `CMoAttachments::SetTarget`, `CMoElem::GetActiveField0A4`, `sub_10044C20` |  |  |  | 163 |
| 0x46 | 0x1004FC85 | `GeneratorClone_FindRecordByType` |  |  |  | 67 |
| 0x47 | 0x1004FD62 |  |  |  |  | 13 |
| 0x48 | 0x1004FE57 |  |  |  |  | 7 |
| 0x49 | 0x1004FD94 |  |  |  |  | 12 |
| 0x4A | 0x1004FF28 |  |  |  |  | 8 |
| 0x4B | 0x1004E93A |  |  |  |  | 19 |
| 0x4C | 0x100502D1 | `Generator_ClearSubobjectOrSetFlag` |  |  |  | 35 |
| 0x4E, 0x4F | 0x1004EABA | `Rand_NextModUnsigned`, `CMoSpline::GetWrapped`, `CMoElem::GetActiveField0A4` |  |  |  | 140 |
| 0x50 | 0x1004E986 | `GeneratorClone_SetDwordAndCopyOut`, `GeneratorClone_FindRecordByType` |  |  |  | 25 |
| 0x51 | 0x1004E9C7 | `GeneratorClone_SetDwordAndCopyOut`, `GeneratorClone_FindRecordByType` |  |  |  | 25 |
| 0x52 | 0x1004EA09 | `GeneratorClone_SetDwordAndCopyOut`, `GeneratorClone_FindRecordByType` |  |  |  | 26 |
| 0x54 | 0x1004EC99 | `GeneratorClone_SetDwordAndCopyOut`, `CMoSpline::SetValue` |  |  |  | 109 |
| 0x55 | 0x10051835 | `GeneratorClone_SetPtrAndGetDword`, `GeneratorClone_GetDwordThroughPtrOrZero`, `GeneratorClone_GetFirstDeref`, `GeneratorClone_GetDword`, `GeneratorClone_GetSelfPlus2`, `GeneratorClone_SetByte`, `GeneratorClone_GetSelfPlus1`, `GeneratorClone_ReturnThisA`, `GeneratorClone_GetSelfPlus3`, `GeneratorClone_CopyDwords` |  |  |  | 79 |
| 0x56 | 0x10051941 | `GeneratorClone_GetPtrDE`, `GeneratorClone_Set46Short`, `CMoGeneratorClone::FindCmdByType`, `GeneratorClone_CopyDwords`, `GeneratorClone_SetDwordAndCopyOut`, `GeneratorClone_FindRecordByType`, `Rand_NextMod`, `sub_10064010`, `GeneratorClone_SetDword` |  |  |  | 149 |
| 0x57 | 0x10051B1A |  |  |  |  | 13 |
| 0x58 | 0x10051519 | `ElemFields194_SetField19C`, `ElemFields194_SetField1A0`, `ElemFields194_SetField1A8`, `ElemFields194_SetField1A4` |  |  |  | 27 |
| 0x59 | 0x100508EF | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4`, `GeneratorClone_SetFloat8FromRadians` |  |  |  | 23 |
| 0x5A | 0x1005091F | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4`, `GeneratorClone_SetFloat8FromRadians` |  |  |  | 23 |
| 0x5B | 0x1005094F | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4`, `GeneratorClone_SetFloat8FromRadians` |  |  |  | 22 |
| 0x5C | 0x10050993 | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4`, `GeneratorClone_GetByte2Ptr`, `GeneratorClone_GetByte`, `GeneratorClone_SetFloat8FromByte` |  |  |  | 26 |
| 0x5D | 0x100509CB | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4`, `GeneratorClone_GetByte1Ptr`, `GeneratorClone_GetByte`, `GeneratorClone_SetFloat8FromByte` |  |  |  | 26 |
| 0x5E | 0x10050A00 | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4`, `GeneratorClone_ReturnThisB`, `GeneratorClone_GetByte`, `GeneratorClone_SetFloat8FromByte` |  |  |  | 26 |
| 0x5F | 0x10050A35 | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4`, `GeneratorClone_GetByte3Ptr`, `GeneratorClone_GetByte`, `GeneratorClone_SetFloat8FromByte` |  |  |  | 25 |
| 0x60, 0x70 | 0x10050487 | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4` |  |  |  | 16 |
| 0x61, 0x65, 0x68, 0x6E | 0x10050451 | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4` |  |  |  | 16 |
| 0x62, 0x66, 0x6C, 0x6F | 0x1005046A | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4` |  |  |  | 16 |
| 0x63, 0x6D | 0x100504A4 | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4` |  |  |  | 16 |
| 0x64 | 0x1005043C | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set4` |  |  |  | 13 |
| 0x67 | 0x1004F062 |  |  |  |  | 42 |
| 0x69 | 0x10050B27 | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4`, `GeneratorClone_FindRecordByType` |  |  |  | 26 |
| 0x6B | 0x100501C9 | `Camera_GetField50`, `RabRes_MinOf10055F60OverIndexPairs` |  |  |  | 42 |
| 0x72 | 0x10051D23 | `CMoAttachments::GetTarget`, `CYyObject_IsKindOf` |  |  |  | 37 |
| 0x74, 0x77, 0x80, 0x83, 0x85, 0x8C | 0x100503FA |  |  |  |  | 10 |
| 0x75, 0x76, 0x78, 0x81, 0x84, 0x8B, 0x8D | 0x1005041B |  |  |  |  | 10 |
| 0x79 | 0x1004FDC3 |  |  |  |  | 13 |
| 0x7A | 0x1004FE0D |  |  |  |  | 13 |
| 0x7C | 0x10050779 | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4`, `ElemFields194_GetFloat1A0`, `GeneratorClone_Set8` |  |  |  | 25 |
| 0x7D | 0x100507B1 | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4`, `ElemFields194_GetFloat19C`, `GeneratorClone_Set8` |  |  |  | 25 |
| 0x7E | 0x1004FF54 |  |  |  |  | 13 |
| 0x7F | 0x1004FF8C |  |  |  |  | 13 |
| 0x82 | 0x10050CD2 | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4`, `AttachNotify_GetFactorFromAttachments` |  |  |  | 27 |
| 0x86 | 0x1004FAC3 | `AttachNotify_CopyFields`, `CMoElem::GetActiveField0A4`, `MoProcessor_CallVSlot49`, `CMoElem::GetAddr78`, `CMoElem::GetAddr84`, `sub_10044C20` |  |  |  | 129 |
| 0x87 | 0x1004FE79 |  |  |  |  | 28 |
| 0x88 | 0x1005156D |  |  |  |  | 3 |
| 0x89 | 0x1004EA4D |  |  |  |  | 35 |
| 0x8A | 0x10050274 |  |  |  |  | 8 |
| 0x8E | 0x1004F76B | `CMoAttachments::GetCaster`, `ElemFog_UpdateTransform`, `CXiSkeletonActor::BuildBasisFromVf210` |  |  |  | 29 |
| 0x8F | 0x1004F40E | `CMoAttachments::GetCaster`, `XiZone::FindSubArea`, `ZoneMap_GetAddr064`, `Env_GetColorPtr84`, `XiZone::TestHeadFlag`, `ZoneMap_GetAddr074`, `sub_10311C2C` |  |  |  | 130 |
| 0x90 | 0x1004F5AC | `ZoneMap_GetAddr064`, `Env_GetColorPtr84`, `XiZone::TestHeadFlag`, `ZoneMap_GetAddr074`, `sub_10311C2C` |  |  |  | 118 |
| 0x91 | 0x1004F757 |  |  |  |  | 5 |
| 0x92 | 0x10050291 |  |  |  |  | 8 |
| 0x93 | 0x10050B70 | `GeneratorClone_GetBits13To18Shl2`, `GeneratorClone_Set0`, `GeneratorClone_Set4`, `GeneratorClone_FindRecordByType` |  |  |  | 26 |
| 0x94 | 0x1004FED3 | `CMoGeneratorClone::FindCmdByType` |  |  |  | 23 |
| 0x98 | 0x1004F126 | `CMoGeneratorClone::FindCmdByType` |  |  |  | 45 |
| 0x99 | 0x1004F1AE | `CMoGeneratorClone::FindCmdByType` |  |  |  | 45 |
| 0x9A | 0x1004F238 | `CMoGeneratorClone::FindCmdByType` |  |  |  | 44 |
| 0x9B | 0x1004FFF0 | `CMoAttachments::GetCaster`, `CMoAttachments::SetCaster`, `CMoAttachments::GetTarget`, `CMoAttachments::SetTarget`, `sub_10053E60`, `CMoElem::GetActiveField0A4` |  |  |  | 120 |
| 0x9C | 0x1005157B |  |  |  |  | 7 |
| 0x9D | 0x1004FFC4 |  |  |  |  | 8 |
| 0x9E | 0x100502B1 |  |  |  |  | 8 |

## Scheduler (CMoSchedularTask_Interpret, 0x10057FB0): commands 2 to 0xC3

The scheduler runs a CMoSchedularRes's commands in time order (the CMoSchOp<n>Task classes are named by the
command that makes them).

| command | case | the code calls | vtables it writes | strings | writes | instructions |
|---|---|---|---|---|---|---|
| 0x02 | 0x100598E1 | `sub_1005E240`, `sub_1004E3C0`, `sub_1005E500`, `CMoResource::FindByTypeAndId`, `GeneratorClone_SetDwordAndCopyOut`, `sub_1005E130`, `CMoGeneratorClone::ResolveTarget`, `sub_1005E1C0`, `CYyObject_IsKindOf`, `sub_1005E650`, `sub_1005E0B0`, `sub_10057BF0` and 22 more |  |  |  | 219 |
| 0x03, 0x73 | 0x1005946D | `Scheduler_ResolveOwner`, `AfterimageTask_FindFirstKind`, `Scheduler_Execute`, `sub_10056BB0`, `CMoResource::FindByTypeAndId` |  |  |  | 120 |
| 0x04, 0x81 | 0x1005A03C | `sub_1005E100`, `sub_1005E260`, `GeneratorClone_SetDwordAndCopyOut`, `GeneratorClone_IsFirstDwordNotEqual`, `sub_10057BF0`, `sub_10057BE0`, `sub_1005E590`, `sub_10311C2C`, `sub_1004E3C0`, `sub_1003C8A0`, `sub_100747D0`, `sub_1005E500` and 2 more |  |  |  | 71 |
| 0x05 | 0x1005CB23 | `AfterimageTask_FindFirstKind`, `SchedularOps_ClearDword0`, `GeneratorClone_SetDword`, `sub_10083220`, `sub_1005E4F0`, `sub_100725C0`, `GeneratorClone_SetDwordAndCopyOut`, `sub_1005E130`, `GeneratorClone_IsFirstDwordNotEqual`, `ResourceHandle_Deref`, `sub_1005E590`, `sub_1005E660` and 5 more |  |  |  | 271 |
| 0x06 | 0x1005CEB9 | `Scheduler_ResolveOwner`, `SchedularOps_ClearDword0`, `GeneratorClone_IsFirstDwordNotEqual`, `GeneratorClone_GetDwordThroughPtr`, `CMoResource::FindByTypeAndId`, `GeneratorClone_SetDwordAndCopyOut`, `sub_1005E280`, `sub_1005E130`, `ResourceHandle_Deref`, `sub_1005E660`, `sub_1005E590`, `CXiSkeletonActor::SetSlotMotion` |  |  |  | 104 |
| 0x07 | 0x1005A280 | `AfterimageTask_FindFirstKind`, `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `sub_100607E0` |  |  |  | 27 |
| 0x08 | 0x1005A2CD | `Scheduler_ResolveOwner`, `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `sub_100607E0` |  |  |  | 27 |
| 0x09 | 0x100597EF | `CMoAttachments::FindKindFromRoot`, `sub_1004E3C0`, `CYyObject_IsKindOf`, `CXiSkeletonActor::ReverseFindRes`, `sub_1005E150`, `GeneratorClone_GetDwordThroughPtr`, `CMoResource::FindByTypeAndId`, `sub_10057BE0`, `sub_10057BF0`, `sub_10056BB0` |  |  |  | 77 |
| 0x0A | 0x1005B613 | `sub_10057BE0`, `sub_1005E230`, `sub_1004E3C0`, `sub_1005E4F0`, `CMoResource::FindByTypeAndId`, `GeneratorClone_SetDwordAndCopyOut`, `GeneratorClone_IsFirstDwordNotEqual`, `GeneratorClone_SetDword`, `sub_1005E2E0`, `sub_1005E700`, `sub_1005E2F0`, `sub_100370D0` and 1 more |  |  |  | 142 |
| 0x0B | 0x1005B5F8 | `sub_10057BF0`, `sub_1005E230`, `sub_1004E3C0`, `sub_1005E4F0`, `CMoResource::FindByTypeAndId`, `GeneratorClone_SetDwordAndCopyOut`, `GeneratorClone_IsFirstDwordNotEqual`, `GeneratorClone_SetDword`, `sub_1005E2E0`, `sub_1005E700`, `sub_1005E2F0`, `sub_100370D0` and 1 more |  |  |  | 143 |
| 0x0C | 0x1005A21F | `sub_1003B950`, `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `sub_10043BB0` |  |  |  | 33 |
| 0x0D | 0x1005A1BE | `sub_1003B950`, `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `sub_100439C0` |  |  |  | 33 |
| 0x0E | 0x10058D94 | `Mem_AllocFromArea`, `CMoTask::ResetFields`, `sub_10311C2C`, `sub_10074790` | CMoSchOp0ETask |  | `g_feedbackBufferIndex`, `dword_1047BF20`, `g_resourcesDirty` | 71 |
| 0x0F | 0x10058E96 | `Mem_AllocFromArea`, `CMoTask::ResetFields`, `sub_10311C2C`, `CMoTask::Constructor` | CMoSchOp0FTask |  | `dword_1047BF28`, `g_resourcesDirty` | 69 |
| 0x10 | 0x10058C72 | `Mem_AllocFromArea`, `CMoTask::ResetFields`, `sub_10311C2C`, `sub_10074790`, `Camera_GetViewportHeight`, `Camera_GetViewportWidth`, `CDx::CreateTexture` | CMoSchOp10Task |  | `dword_1045689C`, `dword_10456910`, `g_afterimageHalfTex`, `g_afterimageDepth`, `dword_1045691C`, `g_afterimageState` | 82 |
| 0x11 | 0x1005883B | `Scheduler_ResolveOwner`, `AfterimageTask_FindFirstKind`, `sub_100AA380` |  |  |  | 23 |
| 0x12 | 0x100588BB | `AfterimageTask_FindFirstKind`, `sub_100AA3B0` |  |  |  | 20 |
| 0x13 | 0x1005887B | `AfterimageTask_FindFirstKind`, `Scheduler_ResolveOwner`, `sub_100AA380` |  |  |  | 23 |
| 0x14 | 0x100588F3 | `Scheduler_ResolveOwner`, `sub_100AA3B0` |  |  |  | 20 |
| 0x15, 0x16 | 0x10058ACD | `AfterimageTask_FindFirstKind`, `CMoAttachments::GetCaster`, `Mem_AllocFromArea`, `CMoTask::ResetFields`, `sub_100ABEA0`, `sub_10062D50`, `AfterimageTask_SetCaster`, `Scheduler_ResolveOwner`, `CMoAttachments::GetTarget`, `AfterimageTask_SetTarget` |  |  | `g_resourcesDirty` | 87 |
| 0x17 | 0x10058B9E | `CMoAttachments::GetCaster`, `CYyObject_IsKindOf`, `sub_10062D50`, `AfterimageTask_SetCaster` |  |  |  | 35 |
| 0x18 | 0x10058C08 | `CMoAttachments::GetTarget`, `CYyObject_IsKindOf`, `CMoAttachments::GetCaster`, `sub_10062D50`, `AfterimageTask_SetTarget` |  |  |  | 35 |
| 0x19 | 0x1005841C | `AfterimageTask_FindFirstKind`, `Scheduler_ResolveOwner` |  |  |  | 26 |
| 0x1A | 0x10058103 | `sub_100841A0`, `ModelCodeIndex_MapCodeIndex`, `sub_10072FD0`, `sub_10085E40`, `sub_10084160`, `Vec4_Copy`, `CXiControlActor_SetVec4` |  |  |  | 210 |
| 0x1B | 0x100580AB | `sub_100841A0`, `AfterimageTask_SetCaster` |  |  |  | 17 |
| 0x1C | 0x100580DA | `sub_100841A0`, `AfterimageTask_SetTarget` |  |  |  | 16 |
| 0x1D | 0x100586DB | `Scheduler_ResolveOwner`, `Mem_AllocFromArea`, `CMoTask::ResetFields`, `sub_1005E590`, `sub_10311C2C`, `Time_SetNormalized`, `sub_1005E4F0`, `GeneratorClone_GetDword`, `CMoTask::Constructor`, `CMoAttachments::Construct`, `unknown_libname_158`, `ntGameTimeGet` and 9 more | CMoSchOp1DAttachments, CMoSchOp1DTask |  | `g_resourcesDirty` | 103 |
| 0x1E, 0x2D | 0x10059C27 | `sub_1005E240`, `sub_1004E3C0`, `sub_1005E4F0`, `CMoResource::FindByTypeAndId`, `GeneratorClone_SetDwordAndCopyOut`, `GeneratorClone_IsFirstDwordNotEqual`, `sub_1005E1C0`, `CMoGeneratorClone::ResolveTarget`, `CYyObject_IsKindOf`, `sub_1005E650`, `sub_1005E0B0`, `sub_1005E1F0` and 8 more |  |  |  | 135 |
| 0x1F | 0x1005A31A | `AfterimageTask_FindFirstKind`, `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `sub_100601F0` |  |  |  | 27 |
| 0x20 | 0x1005A367 | `Scheduler_ResolveOwner`, `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `sub_100601F0` |  |  |  | 27 |
| 0x21 | 0x1005A6B6 | `AfterimageTask_FindFirstKind`, `Scheduler_ResolveOwner`, `sub_1005E510`, `sub_1005E5F0`, `sub_1005E350`, `sub_100CE180`, `sub_100CDD60` |  |  |  | 53 |
| 0x22, 0x23 | 0x1005892B | `AfterimageTask_FindFirstKind`, `CMoAttachments::GetCaster`, `Mem_AllocFromArea`, `CMoTask::ResetFields`, `sub_100ABEA0`, `sub_10062D50`, `AfterimageTask_SetCaster`, `Scheduler_ResolveOwner`, `CMoAttachments::GetTarget`, `AfterimageTask_SetTarget` |  |  | `g_resourcesDirty` | 85 |
| 0x24 | 0x1005A95E | `AfterimageTask_FindFirstKind`, `Scheduler_ResolveOwner`, `sub_1005E510`, `sub_100D6850`, `GeneratorClone_IsFirstDwordNotEqual`, `GeneratorClone_GetDwordThroughPtr`, `GeneratorClone_GetDword`, `sub_1005E7A0`, `sub_1004E3C0`, `sub_10056BB0`, `sub_1005E530`, `sub_1005E540` and 3 more |  |  |  | 74 |
| 0x25 | 0x1005A706 | `AfterimageTask_FindFirstKind`, `Scheduler_ResolveOwner`, `sub_1005E510`, `sub_1005E5F0`, `sub_1005E350`, `sub_100CE180`, `sub_100CDD60` |  |  |  | 54 |
| 0x26, 0x27 | 0x1005C954 | `sub_1005E120`, `sub_1005E4F0`, `CMoResource::FindByTypeAndId`, `GeneratorClone_SetDwordAndCopyOut`, `sub_1005E1F0`, `AfterimageTask_FindFirstKind`, `sub_1005E310`, `CYyObject_IsKindOf`, `sub_1005E0E0`, `GeneratorClone_IsFirstDwordNotEqual`, `sub_1005E040`, `sub_1005E5B0` and 3 more |  |  |  | 133 |
| 0x28 | 0x1005B0C8 | `AfterimageTask_FindFirstKind`, `sub_1005E790`, `sub_100C8BB0`, `SchedularOps_ClearDword0`, `CXiSkeletonActor::SetMotionFromSources`, `sub_1005E780` |  |  |  | 47 |
| 0x29 | 0x1005BD1C | `AfterimageTask_FindFirstKind`, `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `sub_1005F6C0` |  |  |  | 32 |
| 0x2A | 0x1005BD7A | `Scheduler_ResolveOwner`, `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `sub_1005F6C0` |  |  |  | 32 |
| 0x2B | 0x100593B4 | `sub_1018C810` |  |  |  | 11 |
| 0x2C | 0x1005A432 | `AfterimageTask_FindFirstKind`, `SchedularOps_ClearDword0`, `CXiSkeletonActor::ReverseFindRes`, `GeneratorClone_SetDwordAndCopyOut`, `sub_1005E120`, `sub_1004E3C0`, `sub_1005E200`, `sub_1005E880`, `sub_1005E040`, `sub_1005E800`, `sub_1005E590`, `sub_10311C2C` and 2 more |  |  |  | 196 |
| 0x2E | 0x1005C86D | `AfterimageTask_FindFirstKind`, `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `sub_10062310` |  |  |  | 27 |
| 0x2F | 0x1005C8BA | `AfterimageTask_FindFirstKind`, `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `sub_100624B0` |  |  |  | 27 |
| 0x30 | 0x100595A3 | `CMoResource::FindByTypeAndId`, `GeneratorClone_SetDwordAndCopyOut`, `GeneratorClone_IsFirstDwordNotEqual`, `sub_1018C980`, `AfterimageTask_FindFirstKind`, `sub_10056BB0`, `Scheduler_ResolveOwner` |  |  |  | 85 |
| 25 commands: 0x31, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3E, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x61, 0x63, 0x66, 0x68, 0x69, 0x6C, 0x6D, 0x74, 0xA2 | 0x1005AC96 | (the default: no command) | | | | |
| 0x32 | 0x1005D8DD | `sub_1005E510`, `sub_1018CE10`, `Sch_GetStatusEntry`, `AfterimageTask_SetTarget`, `sub_1005E500`, `sub_1005E4E0`, `sub_1005E1F0`, `sub_1005E1D0`, `sub_1005E520`, `sub_1005E550`, `sub_1005E570` |  |  |  | 78 |
| 0x3B | 0x1005DB0B | `sub_1005E250`, `GeneratorClone_SetDwordAndCopyOut`, `GeneratorClone_IsFirstDwordNotEqual`, `sub_1005E4F0`, `CMoResource::FindByTypeAndId`, `sub_1005E510`, `sub_10057BF0`, `sub_10057BE0`, `sub_1004E3C0`, `Scheduler_Execute`, `sub_1005E530`, `sub_10074A30` and 3 more |  |  |  | 95 |
| 0x3C | 0x1005D9C5 | `AfterimageTask_FindFirstKind`, `GeneratorClone_SetDword`, `CMoAttachments::FindKindInChain`, `CXiSkeletonActor::ReverseFindRes`, `GeneratorClone_SetDwordAndCopyOut`, `sub_1005E250`, `sub_1005E120`, `GeneratorClone_IsFirstDwordNotEqual`, `sub_10057BF0`, `sub_10057BE0`, `sub_1004E3C0`, `sub_10056BB0` and 4 more |  |  |  | 112 |
| 0x3D, 0xAF | 0x1005D7D9 | `sub_1005E1D0`, `sub_1005E1F0`, `sub_1005E020`, `sub_1005E000`, `sub_1005E520`, `sub_1005E550`, `Rand_NextModUnsigned`, `CMoSchedularTask_Interpret` |  |  |  | 82 |
| 0x3F | 0x10059E8E | `sub_1005E120`, `sub_1005E4F0`, `CMoResource::FindByTypeAndId`, `GeneratorClone_SetDwordAndCopyOut`, `sub_1004E3C0`, `sub_1005E0B0`, `Generator_IsFlag400OrField22Zero`, `sub_1005E140`, `YmGenerater_Stop`, `CMoGeneratorClone::CreateInstance`, `sub_1005E0F0`, `sub_10057BF0` and 6 more |  |  |  | 137 |
| 0x40 | 0x1005BC51 | `AfterimageTask_FindFirstKind`, `sub_1005E120`, `sub_1005E4F0`, `CMoResource::FindByTypeAndId`, `GeneratorClone_SetDwordAndCopyOut`, `sub_1005E130`, `CYyObject_IsKindOf`, `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `sub_100617B0` |  |  |  | 64 |
| 0x41 | 0x1005BC43 | `Scheduler_ResolveOwner`, `sub_1005E120`, `sub_1005E4F0`, `CMoResource::FindByTypeAndId`, `GeneratorClone_SetDwordAndCopyOut`, `sub_1005E130`, `CYyObject_IsKindOf`, `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `sub_100617B0` |  |  |  | 65 |
| 0x42, 0x43 | 0x1005BB38 | `AfterimageTask_FindFirstKind`, `CYyObject_IsKindOf`, `sub_1005E040`, `sub_1005E1F0`, `sub_1005E590`, `sub_10311C2C`, `sub_100615B0` |  |  |  | 40 |
| 0x44, 0x45 | 0x1005BB84 | `Scheduler_ResolveOwner`, `CYyObject_IsKindOf`, `sub_1005E040`, `sub_1005E1F0`, `sub_1005E590`, `sub_10311C2C`, `sub_100615B0` |  |  |  | 39 |
| 0x46 | 0x1005B22B | `AfterimageTask_FindFirstKind`, `CYyObject_IsKindOf`, `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `sub_1005F6C0` |  |  |  | 39 |
| 0x47 | 0x1005B2A4 | `Scheduler_ResolveOwner`, `CYyObject_IsKindOf`, `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `sub_1005F6C0` |  |  |  | 40 |
| 0x48, 0x49 | 0x1005B447 | `sub_1005E1F0`, `AfterimageTask_FindFirstKind`, `CYyObject_IsKindOf`, `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `sub_10061240`, `Scheduler_ResolveOwner` |  |  |  | 37 |
| 0x4A | 0x1005B5DA | `sub_10057BF0`, `sub_1005E230`, `sub_1004E3C0`, `sub_1005E4F0`, `CMoResource::FindByTypeAndId`, `GeneratorClone_SetDwordAndCopyOut`, `GeneratorClone_IsFirstDwordNotEqual`, `GeneratorClone_SetDword`, `sub_1005E2E0`, `sub_1005E700`, `sub_1005E2F0`, `sub_100370D0` and 1 more |  |  |  | 148 |
| 0x51 | 0x10058F8F | `Mem_AllocFromArea`, `CMoTask::ResetFields`, `sub_10311C2C`, `CMoTask::Constructor` | CMoSchOp0FTask |  | `dword_1047BF2C`, `g_resourcesDirty` | 69 |
| 0x52 | 0x100584B0 | `unknown_libname_158`, `Time_Normalize`, `Time_SetNormalized`, `CMoTask::Clone` |  |  |  | 159 |
| 0x53 | 0x1005B4B9 | `sub_1005E510`, `sub_1005E300`, `sub_10057BE0`, `sub_1005E320`, `sub_1018C980`, `GeneratorClone_ReturnThis`, `sub_1005E230`, `sub_1004E3C0`, `sub_1005E4F0`, `CMoResource::FindByTypeAndId`, `GeneratorClone_SetDwordAndCopyOut`, `GeneratorClone_IsFirstDwordNotEqual` and 7 more |  |  |  | 231 |
| 0x54 | 0x1005BC28 | `sub_1005E210`, `AfterimageTask_FindFirstKind`, `sub_1005E120`, `sub_1005E4F0`, `CMoResource::FindByTypeAndId`, `GeneratorClone_SetDwordAndCopyOut`, `sub_1005E130`, `CYyObject_IsKindOf`, `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `sub_100617B0` |  |  |  | 73 |
| 0x55 | 0x1005BBFF | `sub_1005E210`, `Scheduler_ResolveOwner`, `sub_1005E120`, `sub_1005E4F0`, `CMoResource::FindByTypeAndId`, `GeneratorClone_SetDwordAndCopyOut`, `sub_1005E130`, `CYyObject_IsKindOf`, `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `sub_100617B0` |  |  |  | 75 |
| 0x56 | 0x1005A3B4 | `sub_1005E510`, `sub_1005E320`, `sub_1018C980`, `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `sub_100601F0`, `Scheduler_ResolveOwner` |  |  |  | 73 |
| 0x57, 0x85 | 0x100596CA | `CMoAttachments::FindKindInChain`, `sub_1004E3C0`, `CYyObject_IsKindOf`, `CXiSkeletonActor::ReverseFindRes`, `sub_1005E150`, `GeneratorClone_GetDwordThroughPtr`, `CMoResource::FindByTypeAndId`, `sub_1005E1F0`, `CMoAttachments::FindKindFromRoot`, `Scheduler_Kill`, `sub_10057BF0`, `sub_10057BE0` and 1 more |  |  |  | 96 |
| 0x58 | 0x100593FA | `sub_10021280`, `Camera_GetField50`, `Camera_SetPosition`, `Camera_SetTargetIfMoved`, `Camera_SetField2F8OnGlobal` |  |  |  | 34 |
| 0x59 | 0x1005C907 | `AfterimageTask_FindFirstKind`, `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `sub_10062650` |  |  |  | 27 |
| 0x5A | 0x1005A778 | `AfterimageTask_FindFirstKind`, `Scheduler_ResolveOwner`, `sub_100CDE70`, `sub_100CDF00` |  |  |  | 49 |
| 0x5B | 0x1005A7FB | `AfterimageTask_FindFirstKind`, `Scheduler_ResolveOwner`, `sub_100CDE70`, `sub_100CDF00` |  |  |  | 39 |
| 0x5C | 0x1005A854 | `AfterimageTask_FindFirstKind`, `Scheduler_ResolveOwner`, `sub_1005E5D0`, `CXiActor::GetModelByteEE`, `sub_1005E5E0`, `CXiSkeletonActor::ReverseFindRes`, `GeneratorClone_IsFirstDwordNotEqual`, `ResourceHandle_Deref`, `sub_10056BB0`, `ErrorReport_NoOpVarargsB` |  |  |  | 93 |
| 0x5D | 0x1005AA0F | `AfterimageTask_FindFirstKind`, `Scheduler_ResolveOwner`, `sub_1005E510`, `sub_100D6850`, `GeneratorClone_IsFirstDwordNotEqual`, `sub_1005E5D0`, `sub_1005E7A0`, `sub_1004E3C0`, `sub_10056BB0`, `sub_1005E530`, `sub_1005E540`, `sub_10074A30` and 4 more |  |  |  | 80 |
| 0x5E | 0x1005AB63 | `AfterimageTask_FindFirstKind`, `Scheduler_ResolveOwner`, `sub_1005E510`, `sub_100CE180`, `sub_100AA940`, `CXiActor::GetModelField170`, `sub_1005E360`, `sub_100AA8E0` (a switch of its own at 0x1005AC4B) |  |  |  | 75 |
| 0x5F | 0x10059B95 | `sub_1005E250`, `sub_1004E3C0`, `sub_1005E4F0`, `CMoResource::FindByTypeAndId`, `GeneratorClone_SetDwordAndCopyOut`, `GeneratorClone_IsFirstDwordNotEqual`, `Scheduler_RemoveTasksFor` |  |  |  | 47 |
| 0x60 | 0x1005B7F0 | `sub_1005E230`, `sub_1004E3C0`, `sub_1005E4F0`, `CMoResource::FindByTypeAndId`, `GeneratorClone_SetDwordAndCopyOut`, `GeneratorClone_IsFirstDwordNotEqual`, `sub_1005E610`, `sub_1005E600`, `sub_1005E620`, `sub_10311C2C`, `SoundVolume_SetVolumeScalar`, `sub_1005E640` |  |  |  | 67 |
| 0x62 | 0x1005AF2C | `sub_1005E040`, `sub_1005E590`, `AfterimageTask_FindFirstKind`, `sub_10060F80`, `Scheduler_ResolveOwner`, `sub_100D5490`, `sub_1005DFF0`, `sub_1005E7C0`, `sub_1005E7D0` |  |  |  | 125 |
| 0x64, 0x65 | 0x1005D0D0 | `sub_10069D30`, `sub_1005E4A0`, `CMoTask::Clone`, `sub_1005E1D0`, `sub_10062DE0`, `sub_1003DE40`, `sub_1005E1F0`, `CMoSchedularTask_Interpret` |  |  |  | 73 |
| 0x67 | 0x1005D0B7 |  |  |  |  | 11 |
| 0x6A | 0x1005D1E7 |  |  |  |  | 11 |
| 0x6B | 0x1005D200 | `sub_10060910`, `sub_10069D30`, `sub_100683F0`, `sub_1005E4C0` (a switch of its own at 0x1005D25E) |  |  |  | 33 |
| 0x6E | 0x1005AEE0 | `AfterimageTask_FindFirstKind`, `sub_1005E200`, `sub_100AAD40` |  |  |  | 25 |
| 0x6F, 0x70 | 0x10059DA7 | `sub_1005E120`, `sub_1005E4F0`, `CMoResource::FindByTypeAndId`, `GeneratorClone_SetDwordAndCopyOut`, `sub_1004E3C0`, `Generator_IsFlag400OrField22Zero`, `sub_1005E180`, `sub_1005E040`, `sub_1005E1F0`, `sub_1005E590`, `sub_10060990` |  |  |  | 72 |
| 0x71 | 0x100593D4 | `sub_1018C870` |  |  |  | 14 |
| 0x72 | 0x10059088 | `Mem_AllocFromArea`, `CMoTask::ResetFields`, `sub_10311C2C`, `CMoTask::Constructor` | CMoSchOp0FTask |  | `dword_1047BF30`, `g_resourcesDirty` | 69 |
| 0x75 | 0x1005BE14 | `AfterimageTask_FindFirstKind`, `sub_1005E590`, `CXiActor::GetModelField170`, `sub_100D5F10`, `sub_100D60E0`, `sub_1005E040`, `sub_10311C2C`, `sub_10061960` |  |  |  | 75 |
| 0x76, 0x77 | 0x1005ADB5 | `AfterimageTask_FindFirstKind`, `Scheduler_ResolveOwner`, `SchedularOps_ClearDword0`, `sub_1005E1F0`, `sub_1005E5D0`, `sub_1005E2D0`, `sub_1005E7A0`, `CXiSkeletonActor::ReverseFindRes`, `GeneratorClone_SetDwordAndCopyOut`, `GeneratorClone_IsFirstDwordNotEqual`, `ResourceHandle_Deref`, `sub_10056BB0` |  |  |  | 97 |
| 0x78 | 0x1005BF72 | `sub_10057BE0`, `sub_1005E2A0`, `sub_1005E290`, `sub_1005E7B0`, `sub_1004E3C0`, `YmResourceFile_FindResourceUnder`, `SoundVolume_CreateSoundElem` |  |  |  | 68 |
| 0x79 | 0x1005C046 | `AfterimageTask_FindFirstKind`, `sub_1005E770` |  |  |  | 17 |
| 0x7A | 0x1005C7C9 | `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `Scheduler_ResolveOwner`, `AfterimageTask_FindFirstKind`, `sub_10061FD0` |  |  |  | 31 |
| 0x7B | 0x10057FDF | `sub_1018B3A0` |  |  |  | 14 |
| 0x7C | 0x1005801E | `unknown_libname_158`, `Time_Normalize`, `Time_SetNormalized`, `sub_101874F0` |  |  |  | 28 |
| 0x7D | 0x10058005 | `sub_1018C210` |  |  |  | 11 |
| 0x7E | 0x10058469 | `CMoResource::FindByTypeAndId`, `sub_1018B010` |  |  |  | 25 |
| 0x7F | 0x1005BA4B | `AfterimageTask_FindFirstKind`, `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `sub_100613D0` |  |  |  | 29 |
| 0x80 | 0x1005BAA0 | `sub_1005E510`, `sub_1005E330`, `sub_1018CEF0`, `sub_1005E380`, `AfterimageTask_FindFirstKind`, `sub_100A8E30` |  |  |  | 30 |
| 0x82 | 0x10059273 | `ZoneMap_GetByteRef1CPlus10`, `ZoneMap_GetFloatRef1CPlus4`, `sub_10187010`, `ZoneMap_GetFloatRef1CPlus8`, `Mem_AllocFromArea`, `CMoTask::ResetFields`, `sub_10311C2C`, `sub_10074790` | CMoSchOp82Task |  | `CMoSchedularTask_Interpret_static_BCEC`, `CMoSchedularTask_Interpret_static_BCF0`, `dword_1047BF18`, `dword_1047BF24`, `g_resourcesDirty` | 82 |
| 0x83 | 0x10059181 | `Mem_AllocFromArea`, `CMoTask::ResetFields`, `sub_10311C2C`, `sub_10074790`, `ZoneMap_GetFloatRef1CPlus4`, `ZoneMap_GetByteRef1CPlus10`, `ZoneMap_GetFloatRef1CPlus8`, `sub_10187010` | CMoSchOp82Task |  | `dword_1047BF24`, `g_resourcesDirty` | 64 |
| 0x84 | 0x1005AA93 | `CMoAttachments::FindKindInChain`, `CMoAttachments::FindKindFromRoot`, `SchedularOps_ClearDword0`, `sub_1005E2B0`, `CXiSkeletonActor::ReverseFindRes`, `GeneratorClone_SetDwordAndCopyOut`, `GeneratorClone_IsFirstDwordNotEqual`, `ResourceHandle_Deref`, `sub_10056BB0`, `sub_1005E2C0` |  |  |  | 71 |
| 0x86 | 0x1005968F | `CMoAttachments::FindKindInChain`, `sub_1005E2E0`, `sub_1005E710` |  |  |  | 20 |
| 0x87 | 0x1005BAFD | `AfterimageTask_FindFirstKind` |  |  |  | 22 |
| 0x88 | 0x1005B1DE | `AfterimageTask_FindFirstKind`, `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `sub_1005F320` |  |  |  | 27 |
| 0x89 | 0x1005B14C | `AfterimageTask_FindFirstKind`, `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `sub_1005F450` |  |  |  | 27 |
| 0x8A | 0x1005B8A0 | `sub_1005E230`, `sub_1004E3C0`, `sub_1005E4F0`, `CMoResource::FindByTypeAndId`, `GeneratorClone_SetDwordAndCopyOut`, `GeneratorClone_IsFirstDwordNotEqual`, `sub_1005E610`, `sub_1005E600`, `sub_1005E620`, `sub_10311C2C`, `SoundVolume_SetVolumeScalar`, `sub_1005E640` |  |  |  | 75 |
| 0x8B | 0x1005B97E | `sub_1005E230`, `sub_1004E3C0`, `sub_1005E4F0`, `CMoResource::FindByTypeAndId`, `GeneratorClone_SetDwordAndCopyOut`, `GeneratorClone_IsFirstDwordNotEqual`, `SoundVolume_SendStopToLobby` |  |  |  | 53 |
| 0x8C | 0x1005C07A | `AfterimageTask_FindFirstKind`, `sub_1005E740`, `sub_1005E2E0`, `sub_1005E6B0`, `sub_1005E6C0`, `sub_1005E6D0`, `sub_1005E680` |  |  |  | 35 |
| 0x8D | 0x1005C22B | `AfterimageTask_FindFirstKind` |  |  |  | 17 |
| 0x8E | 0x1005C25B | `AfterimageTask_FindFirstKind` |  |  |  | 17 |
| 0x8F | 0x1005C28B | `AfterimageTask_FindFirstKind` |  |  |  | 17 |
| 0x90 | 0x1005C2BB | `AfterimageTask_FindFirstKind` |  |  |  | 17 |
| 0x91 | 0x1005C2EB | `AfterimageTask_FindFirstKind` |  |  |  | 17 |
| 0x92 | 0x1005C31B | `AfterimageTask_FindFirstKind` |  |  |  | 17 |
| 0x93 | 0x1005C34B | `AfterimageTask_FindFirstKind` |  |  |  | 17 |
| 0x94 | 0x1005C37B | `AfterimageTask_FindFirstKind` |  |  |  | 17 |
| 0x95 | 0x1005C3AB | `AfterimageTask_FindFirstKind` |  |  |  | 17 |
| 0x96 | 0x1005C3DB | `AfterimageTask_FindFirstKind` |  |  |  | 17 |
| 0x97 | 0x1005C40B | `AfterimageTask_FindFirstKind` |  |  |  | 17 |
| 0x98 | 0x1005C43B | `AfterimageTask_FindFirstKind` |  |  |  | 17 |
| 0x99 | 0x1005C46B | `AfterimageTask_FindFirstKind` |  |  |  | 17 |
| 0x9A | 0x1005C58B | `AfterimageTask_FindFirstKind` |  |  |  | 17 |
| 0x9B | 0x1005C647 | `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `Scheduler_ResolveOwner`, `AfterimageTask_FindFirstKind`, `sub_10061E00` |  |  |  | 29 |
| 0x9C, 0x9D | 0x100589E2 | `AfterimageTask_FindFirstKind`, `CMoAttachments::GetCaster`, `Mem_AllocFromArea`, `CMoTask::ResetFields`, `sub_100ABEA0`, `sub_100AC290`, `sub_10062D50`, `AfterimageTask_SetCaster`, `Scheduler_ResolveOwner`, `CMoAttachments::GetTarget`, `AfterimageTask_SetTarget` |  |  | `g_resourcesDirty` | 97 |
| 0x9E | 0x1005C709 | `AfterimageTask_FindFirstKind` |  |  |  | 17 |
| 0x9F | 0x1005C739 | `AfterimageTask_FindFirstKind` |  |  |  | 17 |
| 0xA0 | 0x1005B2EE | `AfterimageTask_FindFirstKind`, `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `sub_1005F6C0` |  |  |  | 32 |
| 0xA1 | 0x1005B34C | `Scheduler_ResolveOwner`, `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `sub_1005F6C0` |  |  |  | 33 |
| 0xA3 | 0x1005BEF4 | `AfterimageTask_FindFirstKind`, `sub_100D5F10`, `sub_100D60E0` |  |  |  | 30 |
| 0xA4 | 0x1005C0E1 | `AfterimageTask_FindFirstKind`, `sub_1005E760`, `sub_1005E2E0`, `sub_1005E6F0`, `sub_1005E6A0` |  |  |  | 29 |
| 0xA5 | 0x1005C138 | `AfterimageTask_FindFirstKind`, `sub_1005E750`, `sub_1005E2E0`, `sub_1005E6E0`, `sub_1005E690` |  |  |  | 29 |
| 0xA6 | 0x1005BA2B | `sub_10035E30` |  |  |  | 14 |
| 0xA7 | 0x1005C697 | `AfterimageTask_FindFirstKind` |  |  |  | 21 |
| 0xA8 | 0x1005C6D0 | `AfterimageTask_FindFirstKind` |  |  |  | 21 |
| 0xA9 | 0x1005B392 | `AfterimageTask_FindFirstKind`, `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `sub_1005FA20` |  |  |  | 38 |
| 0xAA | 0x1005B3DF | `Scheduler_ResolveOwner`, `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `AfterimageTask_FindFirstKind`, `sub_1005FA20` |  |  |  | 37 |
| 0xAB | 0x1005C18F | `AfterimageTask_FindFirstKind`, `sub_1005E2E0`, `sub_1005E720` |  |  |  | 20 |
| 0xAC | 0x1005C1CB | `AfterimageTask_FindFirstKind` |  |  |  | 17 |
| 0xAD | 0x1005C769 | `AfterimageTask_FindFirstKind` |  |  |  | 17 |
| 0xAE | 0x1005D01F | `sub_101880B0`, `sub_1018BB20`, `XiZone::SetPtr1D8FromTable`, `unknown_libname_158`, `sub_1018BBE0`, `sub_10311C2C`, `Time_Normalize`, `sub_1018BB10`, `sub_101874F0` |  |  |  | 42 |
| 0xB0 | 0x1005A12C | `sub_1005E270`, `sub_1004E3C0`, `sub_1005E4F0`, `CMoResource::FindByTypeAndId`, `GeneratorClone_SetDwordAndCopyOut`, `GeneratorClone_IsFirstDwordNotEqual`, `sub_1003CBB0` |  |  |  | 47 |
| 0xB1 | 0x1005BDD8 | `AfterimageTask_FindFirstKind`, `sub_100618A0` |  |  |  | 12 |
| 0xB2 | 0x1005BDF6 | `Scheduler_ResolveOwner`, `sub_100618A0` |  |  |  | 12 |
| 0xB3 | 0x1005B601 | `TextInputFiles_GetSetting99`, `sub_10057BE0`, `sub_1005E230`, `sub_1004E3C0`, `sub_1005E4F0`, `CMoResource::FindByTypeAndId`, `GeneratorClone_SetDwordAndCopyOut`, `GeneratorClone_IsFirstDwordNotEqual`, `GeneratorClone_SetDword`, `sub_1005E2E0`, `sub_1005E700`, `sub_1005E2F0` and 2 more |  |  |  | 147 |
| 0xB4 | 0x1005C81D | `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `Scheduler_ResolveOwner`, `AfterimageTask_FindFirstKind`, `sub_10062180` |  |  |  | 29 |
| 0xB5 | 0x1005C5BB | `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `Scheduler_ResolveOwner`, `AfterimageTask_FindFirstKind`, `sub_10061AF0` |  |  |  | 26 |
| 0xB6 | 0x1005BF36 | `AfterimageTask_FindFirstKind`, `CMoAttachments::FindKindInChain`, `sub_1005E7E0` |  |  |  | 20 |
| 0xB7 | 0x1005C1FB | `AfterimageTask_FindFirstKind` |  |  |  | 17 |
| 0xB8 | 0x1005C49B | `AfterimageTask_FindFirstKind` |  |  |  | 17 |
| 0xB9 | 0x1005C4CB | `AfterimageTask_FindFirstKind` |  |  |  | 17 |
| 0xBA | 0x1005B19C | `AfterimageTask_FindFirstKind`, `CYyObject_IsKindOf`, `CXiSkeletonActor::SetFlag840Bit23` |  |  |  | 23 |
| 0xBB | 0x1005C4FB | `AfterimageTask_FindFirstKind` |  |  |  | 17 |
| 0xBC | 0x1005C601 | `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `Scheduler_ResolveOwner`, `AfterimageTask_FindFirstKind`, `sub_10061C70` |  |  |  | 26 |
| 0xBD | 0x1005C799 | `AfterimageTask_FindFirstKind` |  |  |  | 17 |
| 0xBE | 0x1005CAEF | `AfterimageTask_FindFirstKind`, `sub_10083230` |  |  |  | 18 |
| 0xBF | 0x1005ACA3 | `AfterimageTask_FindFirstKind`, `Scheduler_ResolveOwner`, `sub_1005E510`, `sub_1005E360`, `sub_100CE180`, `sub_1005E040`, `sub_1005E590`, `sub_10311C2C`, `sub_10060DA0` |  |  |  | 86 |
| 0xC0 | 0x10058079 | `Time_Normalize` |  |  |  | 12 |
| 0xC1 | 0x1005C52B | `AfterimageTask_FindFirstKind` |  |  |  | 17 |
| 0xC2 | 0x1005C55B | `AfterimageTask_FindFirstKind` |  |  |  | 17 |
| 0xC3 | 0x1005809B | `sub_100841A0`, `AfterimageTask_SetCaster` |  |  |  | 20 |
