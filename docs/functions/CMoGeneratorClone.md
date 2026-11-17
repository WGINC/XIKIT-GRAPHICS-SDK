# CMoGeneratorClone

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoGeneratorClone.cpp`.

16 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoGeneratorClone::InitCloneFromSource` | 0x10047C30 | 165 | yes | - | - | - |
| `CMoGeneratorClone::FixupClonedPointers` | 0x10047CE0 | 658 | yes | 6 | - | - |
| `CMoGeneratorClone::Release` | 0x100480D0 | 38 | yes | - | Releases the generator's held object and then runs the base cleanup. (reviewed as sub_100480D0) | medium |
| `CMoGeneratorClone::UnlinkElemListA` | 0x10048140 | 72 | yes | - | - | - |
| `CMoGeneratorClone::ResolveCmdTargets` | 0x10048220 | 3720 | yes | - | Resolves each command's resource id to its target object. (reviewed as sub_10048220) | medium |
| `CMoGeneratorClone::FindCmdByType` | 0x100492F0 | 52 | yes | - | - | - |
| `CMoGeneratorClone::CopyType1Dwords` | 0x10049520 | 55 | yes | - | Copies three dwords from the type-1 command into the output. (reviewed as sub_10049520) | low |
| `CMoGeneratorClone::ResolveTarget` | 0x10049570 | 305 | yes | - | - | - |
| `CMoGeneratorClone::TestFlag20000000` | 0x1004E470 | 24 | yes | - | Tests bit 0x20000000 of the generator's +0xD8 flags. (reviewed as sub_1004E470) | low |
| `CMoGeneratorClone::ExecuteCmdList` | 0x1004E720 | 402 | yes | 4 | Runs each command in the generator's command list according to its type. (reviewed as sub_1004E720) | medium |
| `CMoGeneratorClone::SetFlagBit0At17B` | 0x10052960 | 27 | yes | - | Sets bit 0 of the generator's +0x17B flags from its argument. (reviewed as sub_10052960) | low |
| `CMoGeneratorClone::SetFlagBit1At17B` | 0x10052980 | 28 | yes | - | Sets bit 1 of the generator's +0x17B flags from its argument. (reviewed as sub_10052980) | low |
| `CMoGeneratorClone::CopyParams` | 0x10053450 | 621 | yes | - | - | - |
| `CMoGeneratorClone::CreateInstance` | 0x100536C0 | 368 | yes | 6 | - | - |
| `CMoGeneratorClone::InitDefaultParams` | 0x10053E00 | 81 | yes | - | - | - |
| `CMoGeneratorClone::Destructor` | 0x100542F0 | 111 | yes | 5 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoGeneratorClone::InitCloneFromSource` calls `CMoAttachments::Reset`
- `CMoGeneratorClone::FixupClonedPointers` calls `CMoAttachments::ClearCaster`, `CMoAttachments::ClearTarget`, `CMoGeneratorClone::ResolveTarget`, `sub_10074290`, `CMoAttachments::SetCaster`, `CMoAttachments::SetTarget`, `SharedConditionalStateReset`, `CMoGeneratorClone::FindCmdByType`
- `CMoGeneratorClone::Release` calls `sub_100720B0`
- `CMoGeneratorClone::UnlinkElemListA` calls `CMoResource::ReleaseChain`
- `CMoGeneratorClone::ResolveCmdTargets` calls `CMoGeneratorClone::ResolveTarget`, `CMoResource::FindByTypeAndId`
- `CMoGeneratorClone::FindCmdByType` calls nothing directly
- `CMoGeneratorClone::CopyType1Dwords` calls `CMoGeneratorClone::FindCmdByType`
- `CMoGeneratorClone::ResolveTarget` calls `CMoResource::FindByTypeAndId`, `ZoneMap_FindSlotByName`
- `CMoGeneratorClone::TestFlag20000000` calls nothing directly
- `CMoGeneratorClone::ExecuteCmdList` calls `CMoSpline::ReleaseRef`, `Generator_IsFlag400OrField22Zero`, `YmGenerater_Stop`, `sub_10311C2C`, `CMoTask::Restart`, `sub_100496F0`, `Generator_ClearSubobjectOrSetFlag`, `CMoAttachments::GetTarget`, `CMoAttachments::GetCaster`, `Scheduler_Execute`
- `CMoGeneratorClone::SetFlagBit0At17B` calls nothing directly
- `CMoGeneratorClone::SetFlagBit1At17B` calls nothing directly
- `CMoGeneratorClone::CopyParams` calls `AttachNotify_CopyFields`
- `CMoGeneratorClone::CreateInstance` calls `Mem_AllocWithFallback`, `CMoGeneratorClone_VT_1032B114_Constructor`, `CMoGeneratorClone::CopyParams`, `CMoAttachments::Reset`, `MeshResourceMng_AllocHandle`, `CMoAttachments::SetCaster`, `CMoAttachments::SetTarget`, `CMoResource::RegisterInTypeList`, `SharedConditionalStateReset`, `CMoResource::FindByTypeAndId`
- `CMoGeneratorClone::InitDefaultParams` calls `Mem_AllocWithHeader12`, `MoProcessor_CallVSlot49`
- `CMoGeneratorClone::Destructor` calls `YmGenerater_Stop`, `CMoAttachments::ResetAll`, `NodePool_ReleaseNode`, `sub_10048000`
