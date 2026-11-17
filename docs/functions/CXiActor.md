# CXiActor

Group: `CXi` (by the file name only). Source: `sdk/tree_src/CXiActor.cpp`.

73 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CXiActor::Init` | 0x10081BA0 | 326 | yes | - | - | - |
| `CXiActor::ConstructBase` | 0x10081CF0 | 33 | yes | - | Constructs the CXiActor part of an actor. (reviewed as sub_10081CF0) | medium |
| `CXiActor::CXiSkeletonActor_GetMoveSpeed` | 0x10082070 | 7 | yes | - | - | - |
| `CXiSkeletonActor_SetMoveSpeed` | 0x10082080 | 13 | yes | - | - | - |
| `CXiActor::CXiSkeletonActor_GetMoveSpeedBase` | 0x10082090 | 7 | yes | - | - | - |
| `CXiSkeletonActor_SetMoveSpeedBase` | 0x100820A0 | 13 | yes | - | - | - |
| `CXiActor::CXiSkeletonActor_GetWalkSpeed` | 0x100820B0 | 13 | yes | - | - | - |
| `CXiSkeletonActor_SetWalkSpeed` | 0x100820C0 | 13 | yes | - | - | - |
| `CXiActor::CXiSkeletonActor_GetEquip` | 0x100820D0 | 8 | yes | - | - | - |
| `GetEmbeddedMember_0x34` | 0x100820E0 | 4 | yes | - | - | - |
| `GetEmbeddedMember_0x44` | 0x100820F0 | 4 | yes | - | - | - |
| `CXiActor_GetModel` | 0x10082200 | 15 | yes | - | - | - |
| `CXiActor_GetFieldA8` | 0x10082380 | 7 | yes | - | - | - |
| `CXiActor_Slot154ForwardTo5C` | 0x10082460 | 8 | yes | - | Passes its argument to FUN_100814F0 on the actor's member at +0x5C. | low |
| `CXiActor_GetSubActorStatus` | 0x10082780 | 7 | yes | - | - | - |
| `CXiActor_SetSubActorStatus` | 0x10082790 | 13 | yes | - | - | - |
| `CXiActor::IsChocobo` | 0x100827A0 | 25 | yes | - | - | - |
| `CXiActor::IsStateA4Eq54` | 0x100827F0 | 22 | yes | - | Tests whether the actor's field at +0xA4 equals 0x54. (reviewed as sub_100827F0) | medium |
| `CXiActor::IsA4InRange3DTo51` | 0x10082860 | 25 | yes | - | Tests whether the actor's field at +0xA4 lies in the range 0x3D to 0x51. (reviewed as sub_10082860) | low |
| `CXiActor::IsA4InRange25To34` | 0x100828B0 | 25 | yes | - | Tests whether the actor's field at +0xA4 lies in the range 0x25 to 0x34. (reviewed as sub_100828B0) | low |
| `CXiActor::IsA4InRange35To3C` | 0x10082900 | 25 | yes | - | Tests whether the actor's field at +0xA4 lies in the range 0x35 to 0x3C. (reviewed as sub_10082900) | low |
| `CXiActor::GetName` | 0x10082F60 | 64 | yes | - | Returns the actor's name, copied from its model when it has one. (reviewed as sub_10082F60) | medium |
| `CXiActor::GetField78Of70` | 0x10082FA0 | 14 | yes | - | Returns the +0x78 field of the actor's model object. (reviewed as sub_10082FA0) | low |
| `CXiActor::NameCalc` | 0x100830C0 | 337 | yes | - | - | - |
| `CXiActor::CXiSkeletonActor_AddRef` | 0x100832D0 | 7 | yes | - | - | - |
| `CXiActor::CXiSkeletonActor_AddSchRef` | 0x10083390 | 7 | yes | - | - | - |
| `CXiActor::CXiSkeletonActor_SubSchRef` | 0x100833A0 | 7 | yes | - | - | - |
| `CXiActor::ComputeDrawState` | 0x10083430 | 494 | yes | - | Computes a draw-state byte for the actor from its model flags and settings. (reviewed as sub_10083430) | low |
| `CXiActor::FindNearestToPoint` | 0x10083750 | 405 | yes | - | Returns the nearest actor whose bounds contain the given point, or null. (reviewed as sub_10083750) | medium |
| `CXiActor::FindNearestLowerInView` | 0x10083B40 | 444 | yes | - | Returns the actor nearest below this actor in the camera view, within 50 units. (reviewed as sub_10083B40) | low |
| `CXiActor::FindNearestHigherInView` | 0x10083D00 | 446 | yes | - | Returns the actor nearest above this actor in the camera view, within 50 units. (reviewed as sub_10083D00) | low |
| `CXiActor::FindNearestToTarget_Mode0` | 0x10083EC0 | 21 | yes | - | Wrapper that calls the nearest-actor search with mode 0. (reviewed as sub_10083EC0) | low |
| `CXiActor::FindNearestToTarget_Mode1` | 0x10083EE0 | 21 | yes | - | Wrapper that calls the nearest-actor search with mode 1. (reviewed as sub_10083EE0) | low |
| `CXiActor::FindNearestToTarget_Mode2` | 0x10083F00 | 21 | yes | - | Wrapper that calls the nearest-actor search with mode 2. (reviewed as sub_10083F00) | low |
| `CXiActor::FindNearestToTarget` | 0x10083F20 | 477 | yes | - | Finds the actor nearest to the target actor, filtered by the mode argument. (reviewed as sub_10083F20) | medium |
| `CXiActor::IsWithinRadius` | 0x10084100 | 61 | yes | - | Tests whether the squared distance between two actors' positions is under the given squared radius. (reviewed as sub_10084100) | medium |
| `CXiActor::IsModelMissingOrFlag2000` | 0x10084140 | 23 | yes | - | - | - |
| `CXiActor_ModelTest95790` | 0x10084330 | 17 | yes | - | - | - |
| `CXiActor_ModelTest95680` | 0x10084350 | 17 | yes | - | - | - |
| `CXiActor_ModelTest956A0` | 0x10084370 | 17 | yes | - | - | - |
| `CXiActor::GetModelField170` | 0x10084390 | 20 | yes | - | - | - |
| `CXiActor::HasNonzeroField150or158` | 0x100843B0 | 70 | yes | - | - | - |
| `CXiActor::GetModelByteEE` | 0x10084400 | 21 | yes | - | - | - |
| `CXiActor::GetModelByteEF` | 0x10084420 | 57 | yes | - | - | - |
| `CXiActor::GetModelPartWord` | 0x10084480 | 90 | yes | - | - | - |
| `CXiActor::GetModelFlags120Top2` | 0x10084500 | 26 | yes | - | - | - |
| `CXiActor::GetModelFlags130Top2` | 0x10084520 | 23 | yes | - | - | - |
| `CXiActor::GetModelFloat9AEC0` | 0x10084540 | 19 | yes | - | - | - |
| `CXiActor::IsModelMissingOrSuppressed` | 0x10084580 | 35 | yes | - | - | - |
| `CXiActor::TestModelFlags100000_200000_4000` | 0x10084640 | 41 | yes | - | - | - |
| `CXiActor::GetModelFlag120Bit5` | 0x10084670 | 23 | yes | - | Returns bit 5 of the model's flags word at offset 0x120. (reviewed as sub_10084670) | low |
| `CXiActor::GetModelWord166` | 0x10084690 | 19 | yes | - | Returns the word stored at offset 0x166 of the actor's model. (reviewed as sub_10084690) | low |
| `CXiActor::GetModelByte1DB` | 0x10084720 | 21 | yes | - | - | - |
| `CXiActor::GetModelField204` | 0x100849A0 | 21 | yes | - | Returns the float at +0x204 of the actor's model, or -1 when the actor has no model. (reviewed as sub_100849A0) | low |
| `CXiActor::GetModelField12CBit17` | 0x10084BA0 | 28 | yes | - | Returns bit 17 of the dword at offset 0x12C of the actor's model, or the global byte when there is no model. (reviewed as sub_10084BA0) | low |
| `CXiActor::IsModelField210Set` | 0x10084BC0 | 25 | yes | - | Tests whether the 16-bit field at offset 0x210 of the actor's model is nonzero; the result also carries the upper bits of the model pointer. (reviewed as sub_10084BC0) | low |
| `CXiActor_SetField0B4` | 0x10085010 | 13 | yes | - | Stores a value in the actor's +0xB4 field. | low |
| `CXiActor::SpawnResourceGenerators` | 0x10085060 | 378 | yes | 6 | - | - |
| `CXiActor::IsInModelSlotTable` | 0x10085490 | 109 | yes | - | - | - |
| `CXiActor_GetField88Bit3` | 0x10085500 | 13 | yes | - | Returns bit 3 of the actor's +0x88 flags. | low |
| `CXiActor_SetField0BC` | 0x10085BF0 | 13 | yes | - | Stores a value in the actor's +0xBC field. | low |
| `CXiActor::GetTwoBitField` | 0x10087DC0 | 33 | yes | - | Returns a 2-bit field from the actor's flag words, chosen by one flag bit. (reviewed as sub_10087DC0) | low |
| `CXiActor::Construct` | 0x1008A120 | 20 | yes | - | Sets the actor's vtable and runs its default initialisation. (reviewed as sub_1008A120) | medium |
| `CXiActor::SelectMotionTags` | 0x1008A1A0 | 328 | yes | - | Chooses the actor's motion tag set from its model slot and state and stores it. (reviewed as sub_1008A1A0) | medium |
| `CXiActor::PushTagsToObject` | 0x1008A2F0 | 90 | yes | - | Copies the actor's tags into its model object when the object is of the expected kind. (reviewed as sub_1008A2F0) | medium |
| `CXiActor::InitDefaults` | 0x1008A350 | 1021 | yes | - | Resets the actor's fields to their default values. (reviewed as sub_1008A350) | medium |
| `CXiActor::Destroy` | 0x1008A7B0 | 22 | yes | - | Tears down an actor object: its base cleanup, then release of its slots. (reviewed as sub_1008A7B0) | medium |
| `CXiActor::ResetRandomTimer` | 0x1008D980 | 118 | yes | - | Resets the actor's random timer to 600 to 1199 and copies one candidate value to the current value. (reviewed as sub_1008D980) | low |
| `CXiActor::TickRandomTimer` | 0x1008DA00 | 306 | yes | - | Ticks the actor's random timer by the camera frame scale and re-picks its value when it expires. (reviewed as sub_1008DA00) | low |
| `CXiActor::IsField78HighZero` | 0x1008E140 | 14 | yes | - | Returns 1 when the high byte of the actor's field at +0x78 is zero. (reviewed as sub_1008E140) | low |
| `CXiActor::IsFlag1d0Clear` | 0x1008E150 | 33 | yes | - | Returns 1 when two flags in the actor's field at +0x1d0 are clear and its byte at +0x1ff is 1. (reviewed as sub_1008E150) | low |
| `CXiActor::CorrectOnZoneMap` | 0x100C8280 | 315 | yes | - | Moves the actor's position by the offset from a zone-map query at its two probe points. (reviewed as sub_100C8280) | medium |
| `CXiActor::RequestModelParts` | 0x100D14C0 | 508 | yes | 8 | Requests an actor's model parts from the resource manager, loading any that are not resident. (reviewed as sub_100D14C0) | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CXiActor::Init` calls `Vec4_Copy`, `CXiActor_LinkIntoDrawList`, `Actor_CountAll`
- `CXiActor::ConstructBase` calls `CMoTask::Constructor`, `ActorHandle_Constructor`, `CXiActor::Init`
- `CXiActor::CXiSkeletonActor_GetMoveSpeed` calls nothing directly
- `CXiSkeletonActor_SetMoveSpeed` calls nothing directly
- `CXiActor::CXiSkeletonActor_GetMoveSpeedBase` calls nothing directly
- `CXiSkeletonActor_SetMoveSpeedBase` calls nothing directly
- `CXiActor::CXiSkeletonActor_GetWalkSpeed` calls nothing directly
- `CXiSkeletonActor_SetWalkSpeed` calls nothing directly
- `CXiActor::CXiSkeletonActor_GetEquip` calls nothing directly
- `GetEmbeddedMember_0x34` calls nothing directly
- `GetEmbeddedMember_0x44` calls nothing directly
- `CXiActor_GetModel` calls nothing directly
- `CXiActor_GetFieldA8` calls nothing directly
- `CXiActor_Slot154ForwardTo5C` calls `sub_100814F0`
- `CXiActor_GetSubActorStatus` calls nothing directly
- `CXiActor_SetSubActorStatus` calls nothing directly
- `CXiActor::IsChocobo` calls nothing directly
- `CXiActor::IsStateA4Eq54` calls nothing directly
- `CXiActor::IsA4InRange3DTo51` calls nothing directly
- `CXiActor::IsA4InRange25To34` calls nothing directly
- `CXiActor::IsA4InRange35To3C` calls nothing directly
- `CXiActor::GetName` calls `CXiActor::IsInModelSlotTable`, `sub_100979B0`
- `CXiActor::GetField78Of70` calls nothing directly
- `CXiActor::NameCalc` calls `ActorName_ProjectThroughCamera`, `GetFrameCounter`, `sub_10311C2C`
- `CXiActor::CXiSkeletonActor_AddRef` calls nothing directly
- `CXiActor::CXiSkeletonActor_AddSchRef` calls nothing directly
- `CXiActor::CXiSkeletonActor_SubSchRef` calls nothing directly
- `CXiActor::ComputeDrawState` calls `ActorHandle_Resolve`, `CXiActor::IsModelMissingOrFlag2000`, `YkCommon_ActorTest1D0`, `YkCommon_ActorPairTest1FF`, `Settings_GetValue`, `CXiActor::IsField78HighZero`, `Acter_IsBytes1FFBothIn89NotEqual`, `CXiActor::GetModelField170`, `CXiActor::IsModelMissingOrSuppressed`
- `CXiActor::FindNearestToPoint` calls `Camera_GetField50`, `Vec3_Copy`, `MathVector_ReturnThis`, `Camera_GetViewMatrixPtr`, `Mat4_Copy`, `Camera_GetMatrix154Ptr`, `Mat4_PostMultiply`, `YkCommon_GetCC4F0ActorByIndexAt1FA`, `sub_10085240`, `CXiActor::ComputeDrawState`, `sub_10085270`, `MathVector_Nop`
- `CXiActor::FindNearestLowerInView` calls `MathVector_ReturnThis`, `Camera_GetViewMatrixPtr`, `Mat4_Copy`, `Mat4_TransformPoint`, `Camera_GetField2F4`, `YkCommon_GetCC4F0ActorByIndexAt1FA`, `sub_10085240`, `CXiActor::ComputeDrawState`, `MathVector_Length3`, `sub_10085270`, `MathVector_Nop`
- `CXiActor::FindNearestHigherInView` calls `MathVector_ReturnThis`, `Camera_GetViewMatrixPtr`, `Mat4_Copy`, `Mat4_TransformPoint`, `Camera_GetField2F4`, `YkCommon_GetCC4F0ActorByIndexAt1FA`, `sub_10085240`, `CXiActor::ComputeDrawState`, `MathVector_Length3`, `sub_10085270`, `MathVector_Nop`
- `CXiActor::FindNearestToTarget_Mode0` calls `CXiActor::FindNearestToTarget`
- `CXiActor::FindNearestToTarget_Mode1` calls `CXiActor::FindNearestToTarget`
- `CXiActor::FindNearestToTarget_Mode2` calls `CXiActor::FindNearestToTarget`
- `CXiActor::FindNearestToTarget` calls `ActorHandle_Resolve`, `MathVector_ReturnThis`, `Mat4_SetIdentity`, `Mat4_PostRotateY`, `Mat4_SetRow3`, `Mat4_InvertOrthonormal`, `YkCommon_GetCC4F0ActorByIndexAt1FA`, `sub_10085240`, `CXiActor::GetField78Of70`, `Acter_IsBytes1FFBothIn89NotEqual`, `YkCommon_ActorPairTest1FF`, `CXiActor::ComputeDrawState`, `Mat4_TransformPoint`, `sub_10027530`, `sub_10085270`, `MathVector_Nop`
- `CXiActor::IsWithinRadius` calls `MathVector_Distance3`
- `CXiActor::IsModelMissingOrFlag2000` calls nothing directly
- `CXiActor_ModelTest95790` calls `Acter_IsStateGroup3F`
- `CXiActor_ModelTest95680` calls `Acter_IsState5`
- `CXiActor_ModelTest956A0` calls `Acter_IsState55`
- `CXiActor::GetModelField170` calls nothing directly
- `CXiActor::HasNonzeroField150or158` calls nothing directly
- `CXiActor::GetModelByteEE` calls nothing directly
- `CXiActor::GetModelByteEF` calls nothing directly
- `CXiActor::GetModelPartWord` calls nothing directly
- `CXiActor::GetModelFlags120Top2` calls nothing directly
- `CXiActor::GetModelFlags130Top2` calls nothing directly
- `CXiActor::GetModelFloat9AEC0` calls `Acter_GetField138Clamped`
- `CXiActor::IsModelMissingOrSuppressed` calls nothing directly
- `CXiActor::TestModelFlags100000_200000_4000` calls nothing directly
- `CXiActor::GetModelFlag120Bit5` calls nothing directly
- `CXiActor::GetModelWord166` calls nothing directly
- `CXiActor::GetModelByte1DB` calls nothing directly
- `CXiActor::GetModelField204` calls nothing directly
- `CXiActor::GetModelField12CBit17` calls nothing directly
- `CXiActor::IsModelField210Set` calls nothing directly
- `CXiActor_SetField0B4` calls nothing directly
- `CXiActor::SpawnResourceGenerators` calls `ResourceIter_FindFirst`, `ResourceIter_FindNext`, `Generator_StopGenerators`, `ErrorReport_NoOpVarargsA`, `CMoGeneratorClone::CreateInstance`
- `CXiActor::IsInModelSlotTable` calls nothing directly
- `CXiActor_GetField88Bit3` calls nothing directly
- `CXiActor_SetField0BC` calls nothing directly
- `CXiActor::GetTwoBitField` calls nothing directly
- `CXiActor::Construct` calls `CXiActor::InitDefaults`
- `CXiActor::SelectMotionTags` calls `CXiActor::IsInModelSlotTable`, `Acter_IsByte123Mask7In234`, `CXiActor::GetTwoBitField`, `Acter_IsStateGroup3F`, `CXiActor_IsIdAbove6ff`, `CXiActor::PushTagsToObject`
- `CXiActor::PushTagsToObject` calls `CYyObject_IsKindOf`
- `CXiActor::InitDefaults` calls `Actor_SetDefaultMotionTags`, `CXiActor::SelectMotionTags`, `CXiActor::ResetRandomTimer`
- `CXiActor::Destroy` calls `Acter_ReleaseEventRecord`, `Acter_ReleaseAllSlots`
- `CXiActor::ResetRandomTimer` calls `sub_103149A0`, `CYyObject_IsKindOf`
- `CXiActor::TickRandomTimer` calls `Camera_GetFrameScale`, `sub_10311C2C`, `sub_103149A0`, `CYyObject_IsKindOf`
- `CXiActor::IsField78HighZero` calls nothing directly
- `CXiActor::IsFlag1d0Clear` calls nothing directly
- `CXiActor::CorrectOnZoneMap` calls `CXiActor::GetModelField170`, `CXiActor_ModelTest95680`, `CXiActor_ModelTest956A0`, `MathVector_ReturnThis`, `Mat4_SetIdentity`, `Mat4_PostRotateX`, `Mat4_PostRotateY`, `Mat4_PostRotateZ`, `Mat4_SetTranslation`, `Mat4_TransformPointInPlace`, `ZoneMap_Query1693B0`, `MathVector_Nop`
- `CXiActor::RequestModelParts` calls `CXiActor::GetModelByteEE`, `CXiActor::GetModelByteEF`, `sub_100D2D70`, `sub_100D4520`, `CMoResource::FindOrCreateTask`, `CXiSkeletonActor::AddListEntry`, `ResourceHandle_IsResident`, `ActorModelParts_ProcessResidentListEntries`, `Allocator_Generic`, `ActorHandle_Constructor`, `sub_100814F0`, `MeshResourceCreate_Create`, `sub_100D2E30`, `CXiActor::GetModelField170`, `CXiActor_ModelTest95680`, `CXiActor_ModelTest956A0`, `sub_100D2800`
