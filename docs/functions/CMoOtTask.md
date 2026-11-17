# CMoOtTask

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoOtTask.cpp`.

5 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoOtTask::Slot11DoNothing` | 0x10042650 | 1 | yes | - | The default of virtual slot 11: does nothing. (reviewed as sub_10042650) | low |
| `CMoOtTask::GetRuntimeClass_variant0` | 0x10044870 | 6 | yes | - | - | - |
| `CMoOtTask::GetRuntimeClass_variant1` | 0x10055560 | 6 | yes | - | - | - |
| `CMoOtTask::Constructor` | 0x10055570 | 36 | yes | - | Constructs the CMoOt task and links it into its list. (reviewed as sub_10055570) | medium |
| `CMoOtTask::Clear` | 0x10055640 | 13 | yes | - | Clears the three link fields of a CMoOt task. (reviewed as sub_10055640) | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoOtTask::Slot11DoNothing` calls nothing directly
- `CMoOtTask::GetRuntimeClass_variant0` calls nothing directly
- `CMoOtTask::GetRuntimeClass_variant1` calls nothing directly
- `CMoOtTask::Constructor` calls `CMoTask::Constructor`, `LinkNode_Init`
- `CMoOtTask::Clear` calls nothing directly
