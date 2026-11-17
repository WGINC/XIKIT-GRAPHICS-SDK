# CMoAttachments

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoAttachments.cpp`.

23 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoAttachments::GetRuntimeClass` | 0x1003B530 | 6 | yes | - | - | - |
| `CMoAttachments::Construct` | 0x1003B540 | 36 | yes | - | Constructs the attachments object's handles and resets it. (reviewed as sub_1003B540) | medium |
| `CMoAttachments::Slot4ReturnFalse` | 0x1003B570 | 3 | yes | - | The default of virtual slot 4: returns false. (reviewed as sub_1003B570) | low |
| `CMoAttachments::Slot5ReturnFalse` | 0x1003B580 | 3 | yes | - | The default of virtual slot 5: returns false. (reviewed as sub_1003B580) | low |
| `CMoAttachments::Slot6ReturnZero` | 0x1003B590 | 3 | yes | - | The default of virtual slot 6: returns 0. (reviewed as sub_1003B590) | low |
| `CMoAttachments::ScalarDeletingDtor` | 0x1003B5A0 | 30 | yes | - | - | - |
| `CMoAttachments::Reset` | 0x1003B640 | 66 | yes | - | - | - |
| `CMoAttachments::ResetAll` | 0x1003B690 | 49 | yes | - | Clears the caster and target of an attachment object and resets it. (reviewed as sub_1003B690) | medium |
| `CMoAttachments::GetCaster` | 0x1003B6D0 | 47 | yes | - | Returns the attachment's caster while its handle is still valid. (reviewed as sub_1003B6D0) | medium |
| `CMoAttachments::GetTarget` | 0x1003B700 | 47 | yes | - | Returns the attachment's target while its handle is still valid. (reviewed as sub_1003B700) | medium |
| `CMoAttachments::ClearCaster` | 0x1003B750 | 48 | yes | - | - | - |
| `CMoAttachments::ClearTarget` | 0x1003B780 | 48 | yes | - | - | - |
| `CMoAttachments::SetCaster` | 0x1003B7B0 | 120 | yes | - | - | - |
| `CMoAttachments::SetTarget` | 0x1003B830 | 120 | yes | - | - | - |
| `CMoAttachments::FindKindInChain` | 0x1003B8B0 | 67 | yes | - | Walks the link chain from self and returns the first object of the given class. (reviewed as sub_1003B8B0) | low |
| `CMoAttachments::FindKindFromRoot` | 0x1003B900 | 67 | yes | - | Walks the link chain from the root object and returns the first object of the given class. (reviewed as sub_1003B900) | low |
| `CMoAttachments_MatrixPointingFromTo` | 0x1003B980 | 157 | yes | - | Builds a matrix at 'from' rotated to point at 'to' and returns the distance between them. | medium |
| `CMoAttachments::SetMappedSlot` | 0x1003BD90 | 87 | yes | - | Maps an attachment id to its slot number and forwards it to the target. (reviewed as sub_1003BD90) | low |
| `YmGenerater_BuildAttachMatrix` | 0x1003BE10 | 2109 | yes | - | - | - |
| `CMoAttachments::NotifyCaster` | 0x1003C6E0 | 32 | yes | - | Passes this to the caster object's notification slot. (reviewed as sub_1003C6E0) | low |
| `CMoAttachments::NotifyTarget` | 0x1003C700 | 32 | yes | - | Passes this to the target object's notification slot. (reviewed as sub_1003C700) | low |
| `CMoAttachments::PushCasterLink` | 0x10085D50 | 16 | yes | - | Links an object onto the caster list of an attachments object. (reviewed as sub_10085D50) | medium |
| `CMoAttachments::PushTargetLink` | 0x10085D60 | 16 | yes | - | Links an object onto the target list of an attachments object. (reviewed as sub_10085D60) | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoAttachments::GetRuntimeClass` calls nothing directly
- `CMoAttachments::Construct` calls `ActorHandle_Constructor`, `CMoAttachments::Reset`
- `CMoAttachments::Slot4ReturnFalse` calls nothing directly
- `CMoAttachments::Slot5ReturnFalse` calls nothing directly
- `CMoAttachments::Slot6ReturnZero` calls nothing directly
- `CMoAttachments::ScalarDeletingDtor` calls `ReleaseSubObjectIfPresent`, `operator_delete`
- `CMoAttachments::Reset` calls `ActorHandle_SetFields`
- `CMoAttachments::ResetAll` calls `CMoAttachments::GetCaster`, `CMoAttachments::ClearCaster`, `CMoAttachments::GetTarget`, `CMoAttachments::ClearTarget`, `CMoAttachments::Reset`
- `CMoAttachments::GetCaster` calls `ActorHandle_Resolve`
- `CMoAttachments::GetTarget` calls `ActorHandle_Resolve`
- `CMoAttachments::ClearCaster` calls `CMoAttachments::NotifyCaster`, `ActorHandle_SetFields`
- `CMoAttachments::ClearTarget` calls `CMoAttachments::NotifyTarget`, `ActorHandle_SetFields`
- `CMoAttachments::SetCaster` calls `CMoAttachments::GetCaster`, `ActorHandle_SetFields`, `CXiActor_GetField88Bit3`, `sub_100814F0`, `CMoAttachments::PushCasterLink`
- `CMoAttachments::SetTarget` calls `CMoAttachments::GetTarget`, `ActorHandle_SetFields`, `CXiActor_GetField88Bit3`, `sub_100814F0`, `CMoAttachments::PushTargetLink`
- `CMoAttachments::FindKindInChain` calls `CMoAttachments::GetCaster`, `CYyObject_IsKindOf`
- `CMoAttachments::FindKindFromRoot` calls `CMoAttachments::GetTarget`, `CYyObject_IsKindOf`, `CMoAttachments::GetCaster`
- `CMoAttachments_MatrixPointingFromTo` calls nothing directly
- `CMoAttachments::SetMappedSlot` calls nothing directly
- `YmGenerater_BuildAttachMatrix` calls `CMoAttachments::GetCaster`, `CMoAttachments::GetTarget`, `sub_100845E0`, `sub_1003BA20`, `CMoAttachments_MatrixPointingFromTo`, `MoProcessor_CallVSlot49`, `CMoAttachments::SetMappedSlot`, `ZoneMap_GetMatrixGlobal`, `ZoneMap_GetAddr0D4`, `ZoneMap_GetAddr0B4`, `Attach_SetTranslation`
- `CMoAttachments::NotifyCaster` calls `CMoAttachments::GetCaster`
- `CMoAttachments::NotifyTarget` calls `CMoAttachments::GetTarget`
- `CMoAttachments::PushCasterLink` calls nothing directly
- `CMoAttachments::PushTargetLink` calls nothing directly
