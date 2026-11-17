# CMoTask_VT_1032B654

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoTask_VT_1032B654.cpp`.

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoTask_VT_1032B654::ScalarDeletingDtor` | 0x10053350 | 30 | yes | - | - | - |
| `CMoTask_VT_1032B654::RunGeneratorAndFinish` | 0x10054220 | 174 | yes | 4 | Runs the task's generator step and, when it is done and no count remains, calls its own slot 0x18 and frees the resource if it is marked for that. (reviewed as sub_10054220) | low |
| `CMoTask_VT_1032B654::vf011` | 0x10054460 | 8 | yes | - | - | - |
| `CMoTask_VT_1032B654::vf012` | 0x10054470 | 8 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoTask_VT_1032B654::ScalarDeletingDtor` calls `sub_100541C0`, `SharedDeleteHelper`
- `CMoTask_VT_1032B654::RunGeneratorAndFinish` calls `sub_100496F0`, `MoRes_FreeIfUnreferenced`
- `CMoTask_VT_1032B654::vf011` calls `CMoGeneratorClone_VT_1032B69C::CMoGeneratorClone_GetRuntimeClass`
- `CMoTask_VT_1032B654::vf012` calls `CMoGeneratorClone_VT_1032B69C::ScalarDeletingDtor`
