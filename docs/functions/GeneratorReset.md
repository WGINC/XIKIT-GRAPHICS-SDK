# GeneratorReset

Group: `Generator` (by the file name only). Source: `sdk/tree_src/GeneratorReset.cpp`.

Why the file has this name (data/unit_names.json): SharedConditionalStateReset: stops the generators (YmGenerater_Stop) and resets

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SharedConditionalStateReset` | 0x100531D0 | 381 | yes | 5 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SharedConditionalStateReset` calls `Generator_IsFlag400OrField22Zero`, `YmGenerater_Stop`, `CMoAttachments::GetTarget`, `CMoAttachments::GetCaster`, `Generator_StopGenerators`, `Mem_AllocFromArea`, `CMoTask::ResetFields`, `CMoTask::Constructor`, `sub_10053E60`, `sub_100749B0`, `sub_10074A00`
