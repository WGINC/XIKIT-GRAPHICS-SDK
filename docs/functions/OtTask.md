# OtTask

Group: `Ot` (by the file name only). Source: `sdk/tree_src/OtTask.cpp`.

Why the file has this name (data/unit_names.json): CMoOtTask::*, CMoOt_InitSystem, CMoOt_Update

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoOt_InitSystem` | 0x100555D0 | 68 | yes | - | Creates the CMoOt object and registers its update callback. | medium |
| `CMoOt_Update` | 0x10055620 | 27 | yes | - | Per-frame update of the CMoOt object and the zone fog and ambient. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoOt_InitSystem` calls `Mem_AllocDefault`, `CMoOT::Constructor`, `OtLink_Init`, `sub_10074CC0`
- `CMoOt_Update` calls `Zone_UpdateFogAmbient`, `OtLink_Free`, `OtLink_RelinkEntries`
