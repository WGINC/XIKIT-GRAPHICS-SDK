# CMoGeneratorTask

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoGeneratorTask.cpp`.

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoGeneratorTask::ScalarDeletingDtor` | 0x10053350 | 30 | yes | - | - | - |
| `CMoGeneratorTask::RunGeneratorAndFinish` | 0x10054220 | 174 | yes | 4 | Runs the task's generator step and, when it is done and no count remains, calls its own slot 0x18 and frees the resource if it is marked for that. (reviewed as sub_10054220) | low |
| `CMoGeneratorTask::Slot11GetCloneRuntimeClass` | 0x10054460 | 8 | yes | - | Returns CMoGeneratorClone's class descriptor. (reviewed as sub_10054460) | high |
| `CMoGeneratorTask::Slot12DeleteClone` | 0x10054470 | 8 | yes | - | Deletes the CMoGeneratorClone this is a member of. (reviewed as sub_10054470) | high |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoGeneratorTask::ScalarDeletingDtor` calls `sub_100541C0`, `SharedDeleteHelper`
- `CMoGeneratorTask::RunGeneratorAndFinish` calls `sub_100496F0`, `MoRes_FreeIfUnreferenced`
- `CMoGeneratorTask::Slot11GetCloneRuntimeClass` calls `CMoGeneratorClone::CMoGeneratorClone_GetRuntimeClass`
- `CMoGeneratorTask::Slot12DeleteClone` calls `CMoGeneratorClone::ScalarDeletingDtor`
