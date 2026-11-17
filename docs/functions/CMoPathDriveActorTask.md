# CMoPathDriveActorTask

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoPathDriveActorTask.cpp`.

5 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoPathDriveActorTask::GetRuntimeClass` | 0x10056940 | 6 | yes | - | - | - |
| `CMoPathDriveActorTask::Update` | 0x1005E9C0 | 867 | yes | - | Advances the path drive one frame and moves its actor along the path. (reviewed as sub_1005E9C0) | medium |
| `CMoPathDriveActorTask::ApplyFraction` | 0x1005EEF0 | 963 | yes | - | Applies a path fraction to the drive's actor, setting its position and heading. (reviewed as sub_1005EEF0) | low |
| `CMoPathDriveActorTask::Slot11CallGetRuntimeClass` | 0x100630A0 | 8 | yes | - | Returns what CMoLockColorDriveTask_GetRuntimeClass returns. (reviewed as sub_100630A0) | low |
| `CMoPathDriveActorTask::Slot12ThunkDeletingDtor` | 0x100630B0 | 8 | yes | - | Moves this back 0x34 bytes and calls the scalar deleting destructor with the flags argument. (reviewed as sub_100630B0) | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoPathDriveActorTask::GetRuntimeClass` calls nothing directly
- `CMoPathDriveActorTask::Update` calls `CMoSpline::SetValue`, `sub_1005ED30`, `CMoAttachments::GetCaster`, `CYyObject_IsKindOf`, `sub_1005ED90`, `CXiControlActor_SetVec4`, `sub_1005EE90`, `sub_1005EEC0`, `sub_1005EDC0`, `CMoSpline::ReleaseRef`, `sub_10055AD0`, `ElemCurve_EvaluateEaseInOut`, `ElemCurve_Evaluate`, `CMoPathDriveActorTask::ApplyFraction`
- `CMoPathDriveActorTask::ApplyFraction` calls `CMoSpline::SetValue`, `CMoAttachments::GetCaster`, `CYyObject_IsKindOf`, `CXiControlActor_SetVec4`, `Vec4_Copy`
- `CMoPathDriveActorTask::Slot11CallGetRuntimeClass` calls `CMoLockColorDriveTask::GetRuntimeClass`
- `CMoPathDriveActorTask::Slot12ThunkDeletingDtor` calls `sub_1005F3F0`
