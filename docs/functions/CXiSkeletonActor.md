# CXiSkeletonActor

Group: `CXi` (by the file name only). Source: `sdk/tree_src/CXiSkeletonActor.cpp`.

135 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CXiSkeletonActor::DrawModel` | 0x1002B6E0 | 2959 | yes | 0 | - | - |
| `CXiSkeletonActor::AnimateModels` | 0x1002C2D0 | 86 | yes | - | - | - |
| `CXiSkeletonActor::PrepareModelsOnce` | 0x1002C360 | 114 | yes | 0 | - | - |
| `CXiSkeletonActor::GetElemThunk` | 0x1002C3E0 | 23 | yes | - | - | - |
| `CXiSkeletonActor::GetModelElem` | 0x1002C5C0 | 58 | yes | - | - | - |
| `CXiSkeletonActor::PoseCompose` | 0x100343C0 | 603 | yes | - | - | - |
| `CXiSkeletonActor::GetEnglishName` | 0x10082F20 | 64 | yes | - | - | - |
| `CXiSkeletonActor::SubRef` | 0x100832E0 | 18 | yes | - | - | - |
| `CXiSkeletonActor::GetPos` | 0x100A4740 | 7 | yes | - | - | - |
| `CXiSkeletonActor::GetDir` | 0x100A4750 | 7 | yes | - | - | - |
| `CXiSkeletonActor::IsMotionLock` | 0x100A4760 | 13 | yes | - | - | - |
| `CXiSkeletonActor::IsMotionLock_Set` | 0x100A4770 | 29 | yes | - | - | - |
| `CXiSkeletonActor::EnableFlag8AC` | 0x100A4790 | 8 | yes | - | - | - |
| `CXiSkeletonActor::DisableFlag8AC` | 0x100A47A0 | 8 | yes | - | - | - |
| `CXiSkeletonActor::IsFlag8ACSet` | 0x100A47B0 | 10 | yes | - | - | - |
| `CXiSkeletonActor::GetField79C` | 0x100A47C0 | 7 | yes | - | - | - |
| `CXiSkeletonActor::SetField79C` | 0x100A47D0 | 13 | yes | - | - | - |
| `CXiSkeletonActor_IsReadComplete` | 0x100A47E0 | 5 | yes | - | - | - |
| `CXiSkeletonActor::GetPartSlot9Resource` | 0x100A47F0 | 15 | yes | - | Writes the actor's part slot 9 resource to the output. (reviewed as sub_100A47F0) | medium |
| `CXiSkeletonActor::SetField670` | 0x100A4800 | 15 | yes | - | - | - |
| `CXiSkeletonActor::GetField670` | 0x100A4810 | 8 | yes | - | - | - |
| `CXiSkeletonActor::Slot257ReturnFalse` | 0x100A4820 | 3 | yes | - | The default of virtual slot 257: returns false. (reviewed as sub_100A4820) | low |
| `CXiSkeletonActor::SetColor` | 0x100A4830 | 13 | yes | - | - | - |
| `CXiSkeletonActor::GetColor` | 0x100A4840 | 7 | yes | - | - | - |
| `CXiSkeletonActor::GetByte663` | 0x100A4850 | 9 | yes | - | Returns the actor's byte at +0x663. (reviewed as sub_100A4850) | low |
| `CXiSkeletonActor::SetMultiTexAlpha` | 0x100A4860 | 13 | yes | - | - | - |
| `CXiSkeletonActor::SetSahdowAlpha` | 0x100A4880 | 13 | yes | - | - | - |
| `CXiSkeletonActor_GetShadowAlpha` | 0x100A4890 | 7 | yes | - | - | - |
| `CXiSkeletonActor::EnableEffect` | 0x100A48A0 | 21 | yes | - | - | - |
| `CXiSkeletonActor::DisableEffect` | 0x100A48C0 | 23 | yes | - | - | - |
| `CXiSkeletonActor::SetUVOffset` | 0x100A48F0 | 23 | yes | - | - | - |
| `CXiSkeletonActor::SetEmapColor` | 0x100A4920 | 13 | yes | - | - | - |
| `CXiSkeletonActor::SetEmapTexture` | 0x100A4930 | 13 | yes | - | - | - |
| `CXiSkeletonActor::SetEmapAlphaMode` | 0x100A4950 | 13 | yes | - | - | - |
| `CXiSkeletonActor::GetEmapAlphaMode` | 0x100A4960 | 7 | yes | - | - | - |
| `CXiSkeletonActor::GetDword750` | 0x100A4970 | 15 | yes | - | Writes the actor's dword at +0x750 to the output. (reviewed as sub_100A4970) | low |
| `CXiSkeletonActor::get_field_74C` | 0x100A4980 | 7 | yes | - | - | - |
| `CXiSkeletonActor::set_field_73C` | 0x100A4990 | 13 | yes | - | - | - |
| `CXiSkeletonActor::get_field_73C` | 0x100A49A0 | 7 | yes | - | - | - |
| `CXiSkeletonActor::set_field_740` | 0x100A49B0 | 13 | yes | - | - | - |
| `CXiSkeletonActor::get_field_740` | 0x100A49C0 | 7 | yes | - | - | - |
| `CXiSkeletonActor::IsEnvmap` | 0x100A49D0 | 10 | yes | - | - | - |
| `CXiSkeletonActor::IsDistortion` | 0x100A49E0 | 12 | yes | - | - | - |
| `CXiSkeletonActor::IsMasking` | 0x100A49F0 | 13 | yes | - | - | - |
| `CXiSkeletonActor::IsEffectFlag8` | 0x100A4A00 | 13 | yes | - | Returns whether bit 3 of the actor's effect flags is set. (reviewed as sub_100A4A00) | medium |
| `CXiSkeletonActor::IsDirectionLock` | 0x100A4A10 | 7 | yes | - | - | - |
| `CXiSkeletonActor::IsConstrain` | 0x100A4A20 | 8 | yes | - | - | - |
| `CXiSkeletonActor::IsConstrain_Set` | 0x100A4A30 | 23 | yes | - | - | - |
| `CXiSkeletonActor::IsConstrain2` | 0x100A4A50 | 8 | yes | - | - | - |
| `CXiSkeletonActor::IsConstrain2_Set` | 0x100A4A70 | 23 | yes | - | - | - |
| `CXiSkeletonActor::GetByte8A5` | 0x100A4A90 | 7 | yes | - | Returns the actor's byte at +0x8A5. (reviewed as sub_100A4A90) | low |
| `CXiSkeletonActor::SetByte8A5` | 0x100A4AA0 | 13 | yes | - | Sets the actor's byte at +0x8A5. (reviewed as sub_100A4AA0) | low |
| `CXiSkeletonActor::GetByte8A6` | 0x100A4AB0 | 7 | yes | - | Returns the actor's byte at +0x8A6. (reviewed as sub_100A4AB0) | low |
| `CXiSkeletonActor::SetByte8A6` | 0x100A4AC0 | 13 | yes | - | Sets the actor's byte at +0x8A6. (reviewed as sub_100A4AC0) | low |
| `CXiSkeletonActor::GetByte8A7` | 0x100A4AD0 | 7 | yes | - | Returns the actor's byte at +0x8A7. (reviewed as sub_100A4AD0) | low |
| `CXiSkeletonActor::SetByte8A7` | 0x100A4AE0 | 13 | yes | - | Sets the actor's byte at +0x8A7. (reviewed as sub_100A4AE0) | low |
| `CXiSkeletonActor::GetByte8A8` | 0x100A4AF0 | 7 | yes | - | Returns the actor's byte at +0x8A8. (reviewed as sub_100A4AF0) | low |
| `CXiSkeletonActor::ActivateFlag9F8` | 0x100A4B00 | 13 | yes | - | - | - |
| `CXiSkeletonActor::ActivateFlagA04` | 0x100A4B10 | 7 | yes | - | - | - |
| `CXiSkeletonActor::SetByte8A9` | 0x100A4B20 | 13 | yes | - | Sets the actor's byte at +0x8A9. (reviewed as sub_100A4B20) | low |
| `CXiSkeletonActor::SetForceUpdateFlag` | 0x100A4B30 | 8 | yes | - | Sets the actor's force-update flag. (reviewed as sub_100A4B30) | medium |
| `CXiSkeletonActor::SetByteA04` | 0x100A4B40 | 8 | yes | - | Sets the actor's byte at +0xA04 to 1. (reviewed as sub_100A4B40) | low |
| `CXiSkeletonActor::GetRuntimeClass_variant0` | 0x100AB070 | 6 | yes | - | - | - |
| `CXiSkeletonActor::GetRuntimeClass_variant1` | 0x100C5190 | 6 | yes | - | - | - |
| `CXiSkeletonActor::Constructor_1Arg` | 0x100C52A0 | 365 | yes | 3 | - | - |
| `TargetActor_SlotHandler1` | 0x100C5410 | 37 | yes | - | - | - |
| `TargetActor_SlotHandler0` | 0x100C5440 | 122 | yes | - | - | - |
| `CXiSkeletonActor::ScalarDeletingDtor` | 0x100C5540 | 30 | yes | 7 | - | - |
| `CXiSkeletonActor::Constructor_2Arg` | 0x100C5560 | 372 | yes | 3 | - | - |
| `CXiSkeletonActor::Constructor_3Arg` | 0x100C56E0 | 412 | yes | 3 | - | - |
| `CXiSkeletonActor::Constructor_4Arg` | 0x100C5880 | 304 | yes | 3 | - | - |
| `CXiSkeletonActor::Constructor_Factory` | 0x100C59B0 | 577 | yes | 3 | - | - |
| `CXiSkeletonActor::DestructorBody` | 0x100C5C00 | 338 | yes | 6 | - | - |
| `CXiSkeletonActor::Init` | 0x100C5D60 | 1648 | yes | - | - | - |
| `CXiSkeletonActor::PlaceAttachedInRing` | 0x100C9C10 | 1791 | yes | - | Places the actor's attached actors on a circle around a centre, 15 degrees apart, and keeps their state and on/off events in step. (reviewed as sub_100C9C10) | medium |
| `CXiSkeletonActor::CopyModelValuesTo` | 0x100CB390 | 112 | yes | - | Copies one float per model entry from this actor's models to another actor's. (reviewed as sub_100CB390) | low |
| `CXiSkeletonActor::RunStaggeredUpdates` | 0x100CBD60 | 44 | yes | 2 | - | - |
| `CXiSkeletonActor::PerActor_FourBucketStaggeredUpdate` | 0x100CBDE0 | 4153 | yes | 1 | - | - |
| `CXiSkeletonActor_ComputeCameraFade` | 0x100CD040 | 912 | yes | 8 | Returns the actor's opacity value, lowered as the camera comes close to it. | low |
| `CXiSkeletonActor::SetMotion` | 0x100CD490 | 78 | yes | - | - | - |
| `CXiSkeletonActor::SetSlotMotion` | 0x100CD4E0 | 84 | yes | - | Sets a motion on the model's motion queue slot. (reviewed as sub_100CD4E0) | medium |
| `sub_100CD540` | 0x100CD540 | 978 | no | - | - | - |
| `CXiSkeletonActor::SetMotionFromSources` | 0x100CD920 | 1060 | yes | - | Applies a motion request to the actor through CXiSkeletonActor_SetMotion, trying its motion resources in turn; what the result means is not established. (reviewed as sub_100CD920) | low |
| `CXiSkeletonActor::UpdateRandomTimer` | 0x100CDF90 | 219 | yes | - | Counts down a random interval by the frame scale and, when it expires, starts a motion found in the actor's resources. (reviewed as sub_100CDF90) | medium |
| `CXiSkeletonActor::AdvanceMotionQueue` | 0x100CE160 | 31 | yes | - | Advances the actor model's motion queue list by a fixed step of 8.0 when the model has a list. (reviewed as sub_100CE160) | medium |
| `CXiSkeletonActor::ReverseFindRes` | 0x100CE480 | 768 | yes | - | - | - |
| `CXiSkeletonActor::ActorFindResource` | 0x100CE9B0 | 324 | yes | - | - | - |
| `CXiSkeletonActor::ActorFindResourceNth` | 0x100CEB00 | 392 | yes | - | - | - |
| `CXiSkeletonActor::ActorGetResourceCount` | 0x100CEC90 | 349 | yes | - | - | - |
| `CXiSkeletonActor::ReplaceAttack` | 0x100CEDF0 | 3 | yes | - | - | - |
| `CXiSkeletonActor::SetAttack` | 0x100CEE00 | 64 | yes | - | - | - |
| `CXiSkeletonActor::SetAction` | 0x100CEE40 | 186 | yes | - | - | - |
| `CXiSkeletonActor::SetAttack_SchStatus` | 0x100CF030 | 39 | yes | - | - | - |
| `CXiSkeletonActor::ForParts0To9` | 0x100CF100 | 86 | yes | - | For each of the 10 parts calls one of two per-part routines (sub_100D5FE0 or sub_100D6180), chosen by the actor's state; what they do is not established. (reviewed as sub_100CF100) | low |
| `CXiSkeletonActor::ForwardToModelField24` | 0x100CF200 | 11 | yes | - | Passes its argument on to the actor model's object at +0x44 (CYyModelBase_ForwardToField24). (reviewed as sub_100CF200) | low |
| `sub_100CFA50` | 0x100CFA50 | 119 | no | - | Adds a part to the model for each resource of the given type, and spawns generators when the resource asks for them. | medium |
| `CXiSkeletonActor::GetTableOrDefault` | 0x100CFAD0 | 34 | yes | - | Returns the table that sub_100CFB40 gives for this actor, or a fallback address when that is null. (reviewed as sub_100CFAD0) | low |
| `CXiSkeletonActor::GetTableEntryByModelKind` | 0x100CFB40 | 128 | yes | - | Returns entry 0, 1 or 2 of the skeleton's after-bones table, chosen by the actor's model kind (field 170). (reviewed as sub_100CFB40) | medium |
| `CXiSkeletonActor::Slot244_Unknown` | 0x100CFC10 | 814 | yes | - | - | - |
| `CXiSkeletonActor::GetField878Ptr_Candidate` | 0x100D04B0 | 7 | yes | - | - | - |
| `CXiSkeletonActor::GetNamePos` | 0x100D04C0 | 79 | yes | - | - | - |
| `CXiSkeletonActor_OnDrawName` | 0x100D0510 | 445 | no | - | - | - |
| `CXiSkeletonActor::GetArrowPos` | 0x100D06F0 | 71 | yes | - | - | - |
| `CXiSkeletonActor::ProjectToScreen` | 0x100D0740 | 315 | yes | 1 | - | - |
| `CXiSkeletonActor::DrawNameIfVisible` | 0x100D0880 | 46 | yes | 1 | - | - |
| `CXiSkeletonActor_DrawName2IfVisible` | 0x100D08B0 | 36 | yes | 1 | - | - |
| `CXiSkeletonActor::GetWidthScale` | 0x100D08E0 | 201 | yes | - | - | - |
| `CXiSkeletonActor::GetHeightScale` | 0x100D09B0 | 200 | yes | - | - | - |
| `CXiSkeletonActor::GetDepthScale` | 0x100D0A80 | 201 | yes | - | - | - |
| `CXiSkeletonActor::AddPartAndMarkSlot` | 0x100D0B50 | 466 | yes | 8 | Adds a loaded part resource's parts to the actor's model, copies its per-slot settings and marks the slot as loaded. (reviewed as sub_100D0B50) | medium |
| `CXiSkeletonActor::SetField0B4IfField9EC` | 0x100D0D40 | 45 | yes | - | Sets the actor's +0xB4 field and runs sub_100CF750 only when the argument matches the actor's +0x9EC field. (reviewed as sub_100D0D40) | low |
| `CXiSkeletonActor_AttachPartResource` | 0x100D0D70 | 267 | yes | 9 | Given a resource handle for this actor, links a part resource to it, either directly when the resource is resident or through a new attachments task. | low |
| `CXiSkeletonActor::SelectStateMessage` | 0x100D0FC0 | 176 | yes | - | Chooses one of the state messages to send to the skeleton actor from its current flags. (reviewed as sub_100D0FC0) | low |
| `CXiSkeletonActor::RunPendingPartStep` | 0x100D1070 | 256 | yes | 9 | When all part slots are loaded, runs the pending model step recorded at +0x8A4, then hands the object at +0x8C4 to vtable slot +0x298 once the body is read. (reviewed as sub_100D1070) | low |
| `CXiSkeletonActor::ChoosePendingPartStep` | 0x100D1190 | 202 | yes | - | Records at +0x8A4 which model step to run later, chosen from the model's kind fields. (reviewed as sub_100D1190) | low |
| `CXiSkeletonActor_IsReadCompleteBody` | 0x100D12D0 | 212 | yes | - | - | - |
| `CXiSkeletonActor::OnSkeletonLoaded` | 0x100D2F40 | 18 | yes | 10 | - | - |
| `CXiSkeletonActor::LoadSkeletonSync` | 0x100D2F60 | 4476 | yes | 9 | - | - |
| `CXiSkeletonActor::LoadSkeletonResource` | 0x100D4330 | 172 | yes | 10 | - | - |
| `CXiSkeletonActor::GetSkeletonFileNo` | 0x100D43E0 | 35 | yes | - | Returns a file number (0xCA53 plus a table offset chosen by a 0/1 setting) used by CXiSkeletonActor_LoadSkeletonSync. (reviewed as sub_100D43E0) | medium |
| `CXiSkeletonActor::AddListEntry` | 0x100D4410 | 87 | yes | - | Allocates a list entry, fills it from the arguments and adds it to the actor's list. (reviewed as sub_100D4410) | medium |
| `CXiSkeletonActor_ReleaseListEntriesMatching` | 0x100D44B0 | 60 | yes | - | Removes every entry from the actor's +0x7E4 list whose field at +0xC equals the argument, and releases each removed entry. | medium |
| `CXiSkeletonActor::FindListEntry` | 0x100D4540 | 31 | yes | - | Finds the entry in the actor's list whose key matches the argument. (reviewed as sub_100D4540) | medium |
| `CXiSkeletonActor::SetFlag840Bit23` | 0x100D5430 | 41 | yes | - | Sets or clears bit 23 of the flags at +0x840. (reviewed as sub_100D5430) | low |
| `CXiSkeletonActor::IsDirectionLock_Set` | 0x100D5460 | 48 | yes | - | - | - |
| `CXiSkeletonActor::BuildBasisFromVf210` | 0x100D59A0 | 357 | yes | - | Builds a 4x4 basis matrix from the negated vector of vtable slot 0x210 and an up vector turned by the angles of slot 0x1C0. (reviewed as sub_100D59A0) | low |
| `CXiSkeletonActor::UpdateHeadLook` | 0x100D5B10 | 988 | yes | - | - | - |
| `CXiSkeletonActor::FindPartValue` | 0x100D6240 | 120 | yes | - | Finds the part whose tag matches the argument and returns its value. (reviewed as sub_100D6240) | low |
| `CXiSkeletonActor::DrawResourceShadows` | 0x100D62C0 | 167 | yes | 7 | - | - |
| `CXiSkeletonActor::Slot33DoNothing` | 0x100D6F90 | 1 | yes | - | The default of virtual slot 33: does nothing. (reviewed as sub_100D6F90) | low |
| `CXiSkeletonActor::Slot34DoNothing` | 0x100D6FA0 | 1 | yes | - | The default of virtual slot 34: does nothing. (reviewed as sub_100D6FA0) | low |
| `CXiSkeletonActor::Slot35DoNothing` | 0x100D6FB0 | 3 | yes | - | The default of virtual slot 35: does nothing (takes 8 bytes of arguments, unused). (reviewed as sub_100D6FB0) | low |
| `CXiSkeletonActor::Slot36DoNothing` | 0x100D6FC0 | 3 | yes | - | The default of virtual slot 36: does nothing (takes 4 bytes of arguments, unused). (reviewed as sub_100D6FC0) | low |
| `CXiSkeletonActor::Slot37DoNothing` | 0x100D6FD0 | 1 | yes | - | The default of virtual slot 37: does nothing. (reviewed as sub_100D6FD0) | low |
| `CXiSkeletonActor::GetRuntimeClass_variant2` | 0x100D7140 | 6 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CXiSkeletonActor::DrawModel` calls `Vec4_Copy`, `CDx_SetVertexShaderCached`, `CDx::GetTransformCached`, `CXiSkeletonActor::AnimateModels`, `Mat4_SetIdentity`, `sub_10015240`, `sub_10027F60`, `sub_10039410`, `ModelTranslucent_SetColorForce`, `Model_BeginTranslucentPass`, `MathVector_ReturnThis`, `Mat4_SetScale`, `Mat4_SetTranslation`, `Mat4_PostMultiply`, `sub_10026210`, `MathVector_Nop`, `Mat4_Copy`, `Mat4_TransformPointInPlace`, `sub_10026F50`, `ProjTex_CaptureToTarget`, `CDx::SetTransform`, `CDx_SetDefaultRenderState`, `CXiSkeletonActor::PrepareModelsOnce`, `Model_TranslucentUnbindTexture`, `sub_10038A70`, `Post_CaptureSceneToTarget`, `Post_DrawRotatingGhostLayers`, `Model_CompositeTranslucentPass`, `Shadow_DrawByMode`
- `CXiSkeletonActor::AnimateModels` calls `CYyModel::GetField44Addr`, `Model_AnimateAndPose`
- `CXiSkeletonActor::PrepareModelsOnce` calls `CYyModel::GetField44Addr`, `CYyModelBase::DrawLit`
- `CXiSkeletonActor::GetElemThunk` calls `CYyModel::GetPartOffset`
- `CXiSkeletonActor::GetModelElem` calls `CYyModel::GetField44Addr`, `CYyModelBase::FindPartIndex`
- `CXiSkeletonActor::PoseCompose` calls `Mat4_Copy`, `Mat4_SetScale`, `BoneXform_PostMultiplyInto`, `Mat4_SetTranslation`, `Mat4_PostMultiply`, `Vec3_MulInPlace`
- `CXiSkeletonActor::GetEnglishName` calls `CXiActor::IsInModelSlotTable`, `Entity_BuildDisplayName`
- `CXiSkeletonActor::SubRef` calls nothing directly
- `CXiSkeletonActor::GetPos` calls nothing directly
- `CXiSkeletonActor::GetDir` calls nothing directly
- `CXiSkeletonActor::IsMotionLock` calls nothing directly
- `CXiSkeletonActor::IsMotionLock_Set` calls nothing directly
- `CXiSkeletonActor::EnableFlag8AC` calls nothing directly
- `CXiSkeletonActor::DisableFlag8AC` calls nothing directly
- `CXiSkeletonActor::IsFlag8ACSet` calls nothing directly
- `CXiSkeletonActor::GetField79C` calls nothing directly
- `CXiSkeletonActor::SetField79C` calls nothing directly
- `CXiSkeletonActor_IsReadComplete` calls `CXiSkeletonActor_IsReadCompleteBody`
- `CXiSkeletonActor::GetPartSlot9Resource` calls nothing directly
- `CXiSkeletonActor::SetField670` calls nothing directly
- `CXiSkeletonActor::GetField670` calls nothing directly
- `CXiSkeletonActor::Slot257ReturnFalse` calls nothing directly
- `CXiSkeletonActor::SetColor` calls nothing directly
- `CXiSkeletonActor::GetColor` calls nothing directly
- `CXiSkeletonActor::GetByte663` calls nothing directly
- `CXiSkeletonActor::SetMultiTexAlpha` calls nothing directly
- `CXiSkeletonActor::SetSahdowAlpha` calls nothing directly
- `CXiSkeletonActor_GetShadowAlpha` calls nothing directly
- `CXiSkeletonActor::EnableEffect` calls nothing directly
- `CXiSkeletonActor::DisableEffect` calls nothing directly
- `CXiSkeletonActor::SetUVOffset` calls nothing directly
- `CXiSkeletonActor::SetEmapColor` calls nothing directly
- `CXiSkeletonActor::SetEmapTexture` calls nothing directly
- `CXiSkeletonActor::SetEmapAlphaMode` calls nothing directly
- `CXiSkeletonActor::GetEmapAlphaMode` calls nothing directly
- `CXiSkeletonActor::GetDword750` calls nothing directly
- `CXiSkeletonActor::get_field_74C` calls nothing directly
- `CXiSkeletonActor::set_field_73C` calls nothing directly
- `CXiSkeletonActor::get_field_73C` calls nothing directly
- `CXiSkeletonActor::set_field_740` calls nothing directly
- `CXiSkeletonActor::get_field_740` calls nothing directly
- `CXiSkeletonActor::IsEnvmap` calls nothing directly
- `CXiSkeletonActor::IsDistortion` calls nothing directly
- `CXiSkeletonActor::IsMasking` calls nothing directly
- `CXiSkeletonActor::IsEffectFlag8` calls nothing directly
- `CXiSkeletonActor::IsDirectionLock` calls nothing directly
- `CXiSkeletonActor::IsConstrain` calls nothing directly
- `CXiSkeletonActor::IsConstrain_Set` calls nothing directly
- `CXiSkeletonActor::IsConstrain2` calls nothing directly
- `CXiSkeletonActor::IsConstrain2_Set` calls nothing directly
- `CXiSkeletonActor::GetByte8A5` calls nothing directly
- `CXiSkeletonActor::SetByte8A5` calls nothing directly
- `CXiSkeletonActor::GetByte8A6` calls nothing directly
- `CXiSkeletonActor::SetByte8A6` calls nothing directly
- `CXiSkeletonActor::GetByte8A7` calls nothing directly
- `CXiSkeletonActor::SetByte8A7` calls nothing directly
- `CXiSkeletonActor::GetByte8A8` calls nothing directly
- `CXiSkeletonActor::ActivateFlag9F8` calls nothing directly
- `CXiSkeletonActor::ActivateFlagA04` calls nothing directly
- `CXiSkeletonActor::SetByte8A9` calls nothing directly
- `CXiSkeletonActor::SetForceUpdateFlag` calls nothing directly
- `CXiSkeletonActor::SetByteA04` calls nothing directly
- `CXiSkeletonActor::GetRuntimeClass_variant0` calls nothing directly
- `CXiSkeletonActor::GetRuntimeClass_variant1` calls nothing directly
- `CXiSkeletonActor::Constructor_1Arg` calls `CXiCollisionActor::Constructor`, `CYyModel::Constructor`, `ActorHandle_Constructor`, `Actor_InitIndexTable`, `LinkNode_Init`, `OcclusionQuery_Init`, `MathVector_ReturnThis`, `CXiSkeletonActor::Init`, `Camera_GetField50`, `Vec4_Copy`, `Actor_SetSlotTableEntry`, `CXiActor::GetModelField170`, `CXiActor::GetModelByteEE`, `CXiActor::IsModelMissingOrFlag2000`, `sub_100749B0`, `XI_PACKET_10093DB0 (left out)`
- `TargetActor_SlotHandler1` calls `ActorHandle_Resolve`
- `TargetActor_SlotHandler0` calls `ActorHandle_Resolve`, `TargetMenu_GetCachedUnlessFlag21`, `ActorHandle_ResolveObject`, `CXiActor::GetModelByteEF`
- `CXiSkeletonActor::ScalarDeletingDtor` calls `CXiSkeletonActor::DestructorBody`, `SharedDeleteHelper`
- `CXiSkeletonActor::Constructor_2Arg` calls `CXiCollisionActor::Constructor`, `CYyModel::Constructor`, `ActorHandle_Constructor`, `Actor_InitIndexTable`, `LinkNode_Init`, `OcclusionQuery_Init`, `MathVector_ReturnThis`, `CXiSkeletonActor::Init`, `Vec4_Copy`, `Actor_SetSlotTableEntry`, `CXiActor::GetModelField170`, `CXiActor::GetModelByteEE`, `CXiActor::IsModelMissingOrFlag2000`, `sub_100749B0`, `XI_PACKET_10093DB0 (left out)`, `CXiSkeletonActor::LoadSkeletonResource`
- `CXiSkeletonActor::Constructor_3Arg` calls `CXiCollisionActor::Constructor`, `CYyModel::Constructor`, `ActorHandle_Constructor`, `Actor_InitIndexTable`, `LinkNode_Init`, `OcclusionQuery_Init`, `MathVector_ReturnThis`, `CXiSkeletonActor::Init`, `Vec4_Copy`, `CXiSkeletonActor::LoadSkeletonResource`, `Actor_SetSlotTableEntry`, `CXiActor::GetModelField170`, `CXiActor::GetModelByteEE`, `CXiActor::IsModelMissingOrFlag2000`, `sub_100749B0`, `XI_PACKET_10093DB0 (left out)`
- `CXiSkeletonActor::Constructor_4Arg` calls `CXiCollisionActor::Constructor`, `CYyModel::Constructor`, `ActorHandle_Constructor`, `Actor_InitIndexTable`, `LinkNode_Init`, `OcclusionQuery_Init`, `MathVector_ReturnThis`, `CXiSkeletonActor::Init`, `Vec4_Copy`, `CXiSkeletonActor::LoadSkeletonResource`, `Actor_SetSlotTableEntry`, `sub_100749B0`, `XI_PACKET_10093DB0 (left out)`
- `CXiSkeletonActor::Constructor_Factory` calls `CXiCollisionActor::Constructor`, `CYyModel::Constructor`, `ActorHandle_Constructor`, `Actor_InitIndexTable`, `LinkNode_Init`, `OcclusionQuery_Init`, `MathVector_ReturnThis`, `CXiSkeletonActor::Init`, `ErrorReport_NoOpVarargsB`, `Vec4_Copy`, `CMoTaskMng::Forward10075120`, `XI_PACKET_10093DB0 (left out)`, `CXiSkeletonActor::LoadSkeletonResource`
- `CXiSkeletonActor::DestructorBody` calls `CMoResource::ReleaseChain`, `sub_100543A0`, `sub_10082B10`, `sub_100D44F0`, `ResHandle_FreeIfUnreferenced`, `ActorHandle_Resolve`, `TargetMenu_SetTargetMode`, `MathVector_Nop`, `sub_1006C270`, `sub_10055250`, `ActorHandle_Destructor`, `CYyModel::Destructor`, `sub_100A8CA0`
- `CXiSkeletonActor::Init` calls `Vec3_Copy`, `Vec4_Copy`, `CXiSkeletonActor::SetFlag840Bit23`, `CXiSkeletonActor::FindPartValue`, `sub_100814F0`
- `CXiSkeletonActor::PlaceAttachedInRing` calls `sub_100877B0`, `sub_100877F0`, `sub_10087770`, `sub_10087790`, `Camera_GetField50`, `Vec3_Sub`, `Vec3_Call100275D0`, `sub_100274B0`, `Vec3_ScaleInPlace`, `Vec3_AddInPlace`, `sub_10311C2C`, `MathVector_Length3`, `Vec4_Copy`, `CXiControlActor_SetVec4`, `sub_100AAEE0`
- `CXiSkeletonActor::CopyModelValuesTo` calls `CYyModel::GetField44Addr`, `sub_1001B1A0`
- `CXiSkeletonActor::RunStaggeredUpdates` calls `CXiSkeletonActor::PerActor_FourBucketStaggeredUpdate`
- `CXiSkeletonActor::PerActor_FourBucketStaggeredUpdate` calls `CYyModel::GetField44Addr`, `Actor_SetCameraFromModelPoints`, `sub_100845B0`, `CXiActor::IsModelMissingOrSuppressed`, `CDx::SetTransform`, `Mat4_Copy`, `Actor_SelectNearestLights`, `sub_10311C2C`, `Camera_GetField50`, `Vec3_Sub`, `CXiActor::IsInModelSlotTable`, `sub_10313486`, `Vec3_Copy`, `Shadow_SmoothLightDirection`, `sub_102D7FF9`, `MathVector_ReturnThis`, `Mat4_TransformNormal`, `Vec4_Copy`, `Vec3_Scale`, `Vec3_AddInPlace`, `MathVector_Nop`, `GetFrameCounter`, `Camera_GetViewportHeight`, `Camera_GetViewportWidth`, `Occlusion_QueryScreenRect`, `Vec4_Set`, `Mat4_BuildScale`, `CXiActor::TestModelFlags100000_200000_4000`, `CXiActor::GetModelField170`, `sub_100D54C0`, `Vec3_Add_10026FA0`, `Mat4_PostRotateX`, `Mat4_PostRotateY`, `Mat4_PostRotateZ`, `Mat4_SetRow3`, `CXiSkeletonActor::AnimateModels`, `CXiActor_ModelTest956A0`, `CXiSkeletonActor::UpdateHeadLook`, `sub_100D6D30`, `CXiActor::HasNonzeroField150or158`, `CXiSkeletonActor::DrawModel`
- `CXiSkeletonActor_ComputeCameraFade` calls `CXiControlActor::GetSpeed`, `Camera_GetField50`, `Vec3_Sub`, `Vec3_MulComponents`, `ActorHandle_Resolve`, `Entity_GetIndexedPtr`, `Acter_GetActerAt10485F7A`, `Acter_IsStateGroup06Or38`, `Acter_GetByte10480826IfFlag`, `sub_10087AD0`, `sub_10085AC0`, `sub_10085B10`, `sub_10085AB0`, `sub_10085AD0`
- `CXiSkeletonActor::SetMotion` calls `CYyModel::GetField44Addr`, `CYyMotionQue::SetSlotMotion`
- `CXiSkeletonActor::SetSlotMotion` calls `CYyModel::GetField44Addr`, `CYyMotionQue::SetSlotMotion`
- `sub_100CD540` calls `ResourceIter_FindFirst`, `sub_10312872`, `ErrorReport_NoOpVarargsA`, `CXiActor::GetModelByteEE`, `CYyModel::GetField44Addr`, `MotionQueList_QueueMotion`, `CYyMotionQue::SetSlotMotion`, `ResourceIter_FindNext`, `CMoResource::GetParent`
- `CXiSkeletonActor::SetMotionFromSources` calls `CYyModel::GetField44Addr`, `sub_1001B360`, `CXiActor::GetModelByteEE`, `ResourceHandle_IsResident`, `sub_100CD540`, `List_GetTail`, `CXiActor::GetModelByteEF`, `sub_1001B140`
- `CXiSkeletonActor::UpdateRandomTimer` calls `Camera_GetFrameScale`, `sub_103149A0`, `CXiSkeletonActor_IsReadCompleteBody`, `ResourceHandle_IsResident`, `CMoResource_FindInScope`, `CXiSkeletonActor::SetSlotMotion`
- `CXiSkeletonActor::AdvanceMotionQueue` calls `CYyModel::GetField44Addr`, `KzMotionQueList_AdvanceAll`
- `CXiSkeletonActor::ReverseFindRes` calls `List_GetTail`, `ResourceHandle_IsResident`, `ResourceIter_FindFirst`, `ResourceIter_FindNext`, `CMoResource::GetParent`
- `CXiSkeletonActor::ActorFindResource` calls `CYyModel::GetField44Addr`, `CYyModelBase::GetPartList`, `ResourceIter_FindFirst`, `CMoResource::GetParent`, `ResourceHandle_IsResident`, `YmResourceFile_FindResourceUnder`
- `CXiSkeletonActor::ActorFindResourceNth` calls `CYyModel::GetField44Addr`, `CYyModelBase::GetPartList`, `ResourceIter_FindFirst`, `ResourceIter_FindNext`, `CMoResource::GetParent`, `ResourceHandle_IsResident`
- `CXiSkeletonActor::ActorGetResourceCount` calls `CYyModel::GetField44Addr`, `CYyModelBase::GetPartList`, `ResourceIter_FindFirst`, `ResourceIter_FindNext`, `CMoResource::GetParent`, `ResourceHandle_IsResident`
- `CXiSkeletonActor::ReplaceAttack` calls nothing directly
- `CXiSkeletonActor::SetAttack` calls `ChatLog_AddMessage`
- `CXiSkeletonActor::SetAction` calls `CXiSkeletonActor::ReverseFindRes`, `ResourceHandle_Deref`, `Scheduler_Execute`, `YmResourceFile_FindResourceUnder`, `CXiSchStatus_Destructor`, `operator_delete`
- `CXiSkeletonActor::SetAttack_SchStatus` calls `Sch_GetStatusEntry`
- `CXiSkeletonActor::ForParts0To9` calls `CXiActor::GetModelField170`, `CXiSkeletonActor::FindPartValue`, `sub_100D5FE0`, `sub_100D6180`
- `CXiSkeletonActor::ForwardToModelField24` calls `CYyModel::GetField44Addr`, `sub_1002AC50`
- `sub_100CFA50` calls `ResourceIter_FindFirst`, `CYyModelBase::AddPartFromResource`, `sub_10071E90`, `ResourceIter_FindNext`, `CXiActor::SpawnResourceGenerators`
- `CXiSkeletonActor::GetTableOrDefault` calls `CXiSkeletonActor::GetTableEntryByModelKind`
- `CXiSkeletonActor::GetTableEntryByModelKind` calls `CXiActor::GetModelField170`, `CXiActor_ModelTest95680`, `CXiActor_ModelTest956A0`, `CYyModel::GetField44Addr`, `Skel_GetTableAfterBones`
- `CXiSkeletonActor::Slot244_Unknown` calls `MathVector_ReturnThis`, `Mat4_SetIdentity`, `Mat4_PostRotateY`, `Mat4_SetTranslation`, `Mat4_PostMultiply`, `MathVector_Nop`, `Mat4_TransformCoordInPlace`, `Vec4_Copy`
- `CXiSkeletonActor::GetField878Ptr_Candidate` calls nothing directly
- `CXiSkeletonActor::GetNamePos` calls `CXiActor::NameCalc`
- `CXiSkeletonActor_OnDrawName` calls `ActorHandle_Resolve`, `Entity_GetIndexedPtr`, `sub_100845B0`, `sub_10098320`, `Acter_GetActerAt10485F7A`, `Quat_SetIdentity`, `sub_10311FF1`, `CXiSkeletonActor::DrawNameIfVisible`, `CXiSkeletonActor_DrawName2IfVisible`
- `CXiSkeletonActor::GetArrowPos` calls nothing directly
- `CXiSkeletonActor::ProjectToScreen` calls `MathVector_ReturnThis`, `CDx::GetTransformCached`, `Mat4_SetIdentity`, `Mat4_SetTranslation`, `Camera_GetViewMatrixPtr`, `CDx::SetTransform`, `Vec4_Set`, `Gfx_ProjectWorldToClip`, `Gfx_NdcToScreen`, `MathVector_Nop`
- `CXiSkeletonActor::DrawNameIfVisible` calls `Actor_DrawWorldText`
- `CXiSkeletonActor_DrawName2IfVisible` calls `DrawNameplateSecondString`
- `CXiSkeletonActor::GetWidthScale` calls `CYyModel::GetField44Addr`, `Skel_GetTableAfterBones`
- `CXiSkeletonActor::GetHeightScale` calls `CYyModel::GetField44Addr`, `Skel_GetTableAfterBones`
- `CXiSkeletonActor::GetDepthScale` calls `CYyModel::GetField44Addr`, `Skel_GetTableAfterBones`
- `CXiSkeletonActor::AddPartAndMarkSlot` calls `CXiActor::GetModelByteEE`, `CXiActor::GetModelPartWord`, `CXiActor_SetField0B4`, `CXiActor::GetModelByteEF`, `GeneratorClone_SetDwordAndCopyOut`, `sub_10071E90`, `CYyModel::GetField44Addr`, `CYyModel::CreateModelBase`, `sub_100CFA50`, `CMoResource_FindInScope`
- `CXiSkeletonActor::SetField0B4IfField9EC` calls `CXiActor_SetField0B4`, `sub_100CF750`
- `CXiSkeletonActor_AttachPartResource` calls `CXiActor_SetField0B4`, `CXiSkeletonActor::SelectStateMessage`, `CXiActor::GetModelByteEE`, `CXiActor::GetModelPartWord`, `ModelCodeIndex_MapCodeIndex`, `CMoResource::FindOrCreateTask`, `ResourceHandle_IsResident`, `CXiSkeletonActor::AddPartAndMarkSlot`, `Allocator_Generic`, `ActorHandle_Constructor`, `sub_100814F0`, `MeshResourceCreate_Create`
- `CXiSkeletonActor::SelectStateMessage` calls nothing directly
- `CXiSkeletonActor::RunPendingPartStep` calls `CXiActor::GetModelByteEE`, `CXiActor::RequestModelParts`, `sub_100D1970`, `sub_100D16C0`, `sub_100D1C80`, `sub_100D2460`, `sub_100D1F70`, `CXiSkeletonActor_IsReadCompleteBody`, `ErrorReport_NoOpVarargsB`
- `CXiSkeletonActor::ChoosePendingPartStep` calls `CXiActor::GetModelField170`, `CXiActor::GetModelByteEE`, `CXiSkeletonActor::FindListEntry`
- `CXiSkeletonActor_IsReadCompleteBody` calls `List_GetTail`, `ResourceHandle_IsResident`, `CXiActor::GetModelByteEE`, `CXiActor::GetModelPartWord`
- `CXiSkeletonActor::OnSkeletonLoaded` calls `CXiSkeletonActor::LoadSkeletonSync`
- `CXiSkeletonActor::LoadSkeletonSync` calls `CXiActor::GetModelByteEF`, `ErrorReport_NoOpVarargsB`, `CMoResource::FindOrCreateTask`, `ResourceHandle_IsResident`, `CXiSkeletonActor::SetField0B4IfField9EC`, `Allocator_Generic`, `ActorHandle_Constructor`, `sub_100814F0`, `MeshResourceCreate_Create`, `CXiActor::GetModelPartWord`, `CXiSkeletonActor::AddPartAndMarkSlot`, `NetCellFont_IsId50To99Or88Or89`, `ModelCodeIndex_MapCodeIndex`, `CXiSkeletonActor_AttachPartResource`, `CXiActor::GetModelByte1DB`, `CXiSkeletonActor::GetSkeletonFileNo`, `CXiActor::GetModelByteEE`, `sub_100731B0`, `CXiSkeletonActor::ChoosePendingPartStep`, `ActorModelFlag_GetModelFlag130Bit21`, `CXiActor::GetModelFlag120Bit5`, `CXiActor::GetModelWord166`, `sub_10072FD0`
- `CXiSkeletonActor::LoadSkeletonResource` calls `Mem_AllocFromArea`, `CMoTask::ResetFields`, `CXiSkeletonActorRes::Constructor`, `CXiSkeletonActor::LoadSkeletonSync`
- `CXiSkeletonActor::GetSkeletonFileNo` calls `Acter_GetByte10480825IfSet`
- `CXiSkeletonActor::AddListEntry` calls `Mem_AllocDefault`, `sub_1001B710`, `sub_1002C7E0`
- `CXiSkeletonActor_ReleaseListEntriesMatching` calls `ListUtil_PopHead`
- `CXiSkeletonActor::FindListEntry` calls nothing directly
- `CXiSkeletonActor::SetFlag840Bit23` calls nothing directly
- `CXiSkeletonActor::IsDirectionLock_Set` calls nothing directly
- `CXiSkeletonActor::BuildBasisFromVf210` calls `MathVector_ReturnThis`, `Vec3_Copy`, `Vec3_Scale`, `Mat4_SetIdentity`, `Vec4_Copy`, `Mat4_PostRotateX`, `Mat4_PostRotateY`, `Mat4_PostRotateZ`, `Mat4_TransformPointInPlace`, `sub_100274B0`, `Vec3_Cross`, `MathVector_Nop`
- `CXiSkeletonActor::UpdateHeadLook` calls `CYyModel::GetField44Addr`, `CXiActor::GetModelFlag120Bit5`, `TargetMenu_GetCachedUnlessFlag21`, `sub_100845E0`, `CXiActor::GetModelByteEE`, `CXiActor::GetModelField170`, `CXiActor_ModelTest95790`, `CXiActor_ModelTest95680`, `CXiActor_ModelTest956A0`, `Vec3_SubInPlace`, `MathVector_ReturnThis`, `Mat4_SetIdentity`, `Mat4_PostRotateY`, `Mat4_TransformPointInPlace`, `MathVector_Nop`, `Acter_IsEvent`, `sub_10027530`, `Mat4_SetTranslation`
- `CXiSkeletonActor::FindPartValue` calls `CYyModel::GetField44Addr`, `CYyModelBase::GetPartList`, `sub_1002C710`, `sub_1002C750`
- `CXiSkeletonActor::DrawResourceShadows` calls `ResourceHandle_IsResident`, `CXiActor::SpawnResourceGenerators`, `CYyModel::GetField44Addr`, `CYyModelBase::GetPartList`
- `CXiSkeletonActor::Slot33DoNothing` calls nothing directly
- `CXiSkeletonActor::Slot34DoNothing` calls nothing directly
- `CXiSkeletonActor::Slot35DoNothing` calls nothing directly
- `CXiSkeletonActor::Slot36DoNothing` calls nothing directly
- `CXiSkeletonActor::Slot37DoNothing` calls nothing directly
- `CXiSkeletonActor::GetRuntimeClass_variant2` calls nothing directly
