# YmCombineWeather

Group: `Ym` (by the file name only). Source: `sdk/tree_src/YmCombineWeather.cpp`.

6 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `YmCombineWeather_ResetFlag1000Generator` | 0x1018AA50 | 100 | yes | 6 | For a generator flagged 0x1000, resets its state and stores the second argument at +0x64, unless the zone setting at +0x1BC rules it out. | low |
| `YmCombineWeather_FindKind5A` | 0x1018AAC0 | 20 | yes | - | Searches the resource chain for kind 5 with the first callback. | low |
| `YmCombineWeather_ResetFlag1000Not800Generator` | 0x1018AAE0 | 85 | yes | 6 | For a generator flagged 0x1000 but not 0x800 whose first command has bit 4 or 0x4000000, resets its state. | low |
| `YmCombineWeather_FindKind5B` | 0x1018AB40 | 20 | yes | - | Searches the resource chain for kind 5 with the second callback. | low |
| `YmCombineWeather_RunFlag800Generator` | 0x1018AB60 | 77 | yes | 6 | For a generator flagged 0x800 whose first command has bit 4 or 0x4000000, runs the function at 0x1018ABB0 on it. | low |
| `YmCombineWeather::Release` | 0x1018ABF0 | 341 | yes | 6 | Detaches a combined weather object from its resource lists. (reviewed as sub_1018ABF0) | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `YmCombineWeather_ResetFlag1000Generator` calls `Generator_IsFlag400OrField22Zero`, `GeneratorClone_GetCmdType1Data`, `SharedConditionalStateReset`
- `YmCombineWeather_FindKind5A` calls `Resource_FindInChainByKind`
- `YmCombineWeather_ResetFlag1000Not800Generator` calls `Generator_IsFlag400OrField22Zero`, `GeneratorClone_GetCmdType1Data`, `SharedConditionalStateReset`
- `YmCombineWeather_FindKind5B` calls `Resource_FindInChainByKind`
- `YmCombineWeather_RunFlag800Generator` calls `Generator_IsFlag400OrField22Zero`, `GeneratorClone_GetCmdType1Data`, `sub_1018ABB0`
- `YmCombineWeather::Release` calls `sub_100742A0`, `EnvBlend_GetField4`, `ResourceIter_FindFirst`, `ResourceIter_FindNext`, `ResourceIter_Start`, `sub_1018ABB0`, `ZoneMap_SetRecord`, `Blend_FreeResult`, `Blend_FindPrevious`, `EnvBlend_SetField10Of4`, `Scheduler_RemoveTasksFor`
