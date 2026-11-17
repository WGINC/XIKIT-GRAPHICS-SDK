# Generator

Group: `Generator` (by the file name only). Source: `sdk/tree_src/Generator.cpp`.

Why the file has this name (data/unit_names.json): YmGenerater_Stop / UpdateAttach, Generator_ClearSubobjectOrSetFlag

6 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Generator_ClearSubobjectOrSetFlag` | 0x10053890 | 76 | yes | - | Clears a state flag on the generator and either releases its attached sub-object or marks it as stopped, depending on the argument. | low |
| `YmGenerater_Stop` | 0x100538E0 | 256 | yes | 4 | - | - |
| `Generator_IsFlag400OrField22Zero` | 0x100539E0 | 25 | yes | - | Reports whether the generator is flagged 0x400 or the short field at +0x22 of its sub-object is zero. | low |
| `Generator_StopGenerators` | 0x10053A00 | 627 | yes | 5 | Stops the generators of the mesh resources owned by an object and releases them. | medium |
| `YmGenerater_UpdateAttach` | 0x10053C80 | 325 | yes | - | Rebuilds the generator's attach matrix and blends the attached transform toward it by the weight. | medium |
| `YmGenerater_UpdateAttachIfPresent` | 0x10053DD0 | 37 | yes | - | When given a nonzero weight, updates the generator's attach transform if its 0x11 element exists, and returns 0 otherwise. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Generator_ClearSubobjectOrSetFlag` calls nothing directly
- `YmGenerater_Stop` calls `sub_10071E90`, `CMoResource::ReleaseChain`, `sub_10311C2C`, `CMoTask::Restart`, `sub_100496F0`, `Generator_ClearSubobjectOrSetFlag`
- `Generator_IsFlag400OrField22Zero` calls `GeneratorClone_GetShort22ViaPtrE4`
- `Generator_StopGenerators` calls `CYyObject_IsKindOf`, `Generator_ClearSubobjectOrSetFlag`, `YmGenerater_Stop`, `CMoAttachments::GetTarget`, `sub_10071E90`, `CMoResource::ReleaseChain`, `MoRes_FreeIfUnreferenced`, `ResourceIter_Start`, `ResourceIter_FindNext`
- `YmGenerater_UpdateAttach` calls `YmGenerater_BuildAttachMatrix`
- `YmGenerater_UpdateAttachIfPresent` calls `sub_100492B0`, `YmGenerater_UpdateAttach`
