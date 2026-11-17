# CMoSchedularTask

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoSchedularTask.cpp`.

8 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoSchedularTask::GetRuntimeClass` | 0x10057090 | 6 | yes | - | - | - |
| `CMoSchedularTask::ScalarDeletingDtor` | 0x10057250 | 30 | yes | - | - | - |
| `CMoSchedularTask::Construct` | 0x10057270 | 108 | yes | - | Constructs a schedular task and initialises its members. (reviewed as sub_10057270) | medium |
| `CMoSchedularTask_ResetFlags` | 0x100573B0 | 39 | yes | - | Clears the schedular task's flag bytes. | low |
| `CMoSchedularTask::InitFromSource` | 0x100573E0 | 180 | yes | - | Initialises a schedular task's members from its source object, a rate argument and a shared reference. (reviewed as sub_100573E0) | low |
| `CMoSchedularTask::Destructor` | 0x100574A0 | 252 | yes | - | - | - |
| `CMoSchedularTask::SetSharedRef` | 0x10057CC0 | 39 | yes | - | Stores a shared reference in the schedular task and takes a count on it. (reviewed as sub_10057CC0) | low |
| `CMoSchedularTask::Update` | 0x10057E10 | 410 | yes | 1 | Advances the scheduler task by one frame step, running its commands whenever their wait has run out. (reviewed as sub_10057E10) | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoSchedularTask::GetRuntimeClass` calls nothing directly
- `CMoSchedularTask::ScalarDeletingDtor` calls `CMoSchedularTask::Destructor`, `SharedDeleteHelper`
- `CMoSchedularTask::Construct` calls `CMoTask::Constructor`, `CMoAttachments::Construct`, `CMoOtTask::Clear`, `CMoSchedularTask_ResetFlags`, `CMoSchedularTask::InitFromSource`, `sub_10074A00`
- `CMoSchedularTask_ResetFlags` calls nothing directly
- `CMoSchedularTask::InitFromSource` calls `CMoSchedularTask::SetSharedRef`
- `CMoSchedularTask::Destructor` calls `CMoAttachments::GetCaster`, `CMoAttachments::GetTarget`, `sub_10074A50`, `sub_1018CEA0`, `CMoResource::ReleaseChain`, `CMoAttachments::ResetAll`, `sub_100683D0`, `sub_10055650`, `ReleaseSubObjectIfPresent`, `CMoTask::Destructor`
- `CMoSchedularTask::SetSharedRef` calls `ScriptMacro_SetDwordValue`
- `CMoSchedularTask::Update` calls `ResourceHandle_IsResident`, `sub_10057C20`, `CMoSchedularTask_Interpret`, `sub_10062DE0`
