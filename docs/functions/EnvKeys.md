# EnvKeys

Group: `Env` (by the file name only). Source: `sdk/tree_src/EnvKeys.cpp`.

Why the file has this name (data/unit_names.json): Env_BlendKeys / BlendTimeOfDay / FindNextKey / LerpKeyValues: the time-of-day keys

20 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `WeatherRes_InitKeyDefaults` | 0x10189400 | 131 | yes | - | Fills a weather key with its default values. | low |
| `Env_BlendKeys` | 0x10189490 | 609 | yes | - | Interpolates one environment key towards another. | medium |
| `Env_LerpFloat` | 0x10189810 | 23 | yes | - | Linearly interpolates between two floats by a factor and stores the result. | medium |
| `Env_LerpKeyValues` | 0x101898E0 | 148 | yes | - | Interpolates one key's values toward another by a factor. | low |
| `WeatherRes_IsTimeKeyName` | 0x10189BD0 | 144 | yes | - | Tells whether a weather resource's name is a four-digit time. | low |
| `Zone_GetClock` | 0x10189C60 | 52 | yes | - | - | - |
| `Env_FindPrevKey` | 0x10189CA0 | 394 | yes | - | Finds the weather key at or before the current zone time. | medium |
| `WeatherRes_FindAtOrBefore` | 0x10189E30 | 236 | yes | - | - | - |
| `Env_FindNextKey` | 0x10189F20 | 460 | yes | - | Finds the next weather key after the current zone time. | medium |
| `WeatherRes_FindNeighbor` | 0x1018A0F0 | 300 | yes | - | - | - |
| `Env_UpdatePrevKey` | 0x1018A220 | 51 | yes | - | Finds the key at or before the current time and stores it as the previous key. | medium |
| `Env_UpdateNextKey` | 0x1018A260 | 51 | yes | - | Finds the next key for the current time and stores it. | medium |
| `Env_UpdateKeyAtOrBefore` | 0x1018A2A0 | 26 | yes | - | Looks up the weather key at or before the current time and stores it at +0x24. | medium |
| `Env_UpdateKeyNeighbor` | 0x1018A2C0 | 26 | yes | - | Looks up the neighbouring weather key for the current time and stores it at +0x28. | medium |
| `Env_SetKeyField2C` | 0x1018A2E0 | 10 | yes | - | Stores a key pointer at +0x2C. | low |
| `Env_SetKeyField30` | 0x1018A2F0 | 10 | yes | - | Stores a key pointer at +0x30. | low |
| `Env_SetKeyField24` | 0x1018A300 | 10 | yes | - | Stores a key pointer at +0x24. | low |
| `Env_SetKeyField28` | 0x1018A310 | 10 | yes | - | Stores a key pointer at +0x28 and returns it. | low |
| `Env_UpdateTimeKeys` | 0x1018A320 | 30 | yes | - | Refreshes the previous, next and neighbouring weather keys for the current time. | medium |
| `Env_BlendTimeOfDay` | 0x1018A340 | 1055 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `WeatherRes_InitKeyDefaults` calls nothing directly
- `Env_BlendKeys` calls `Env_LerpKeyValues`, `sub_100274B0`, `Quat_SetIdentityChained`, `sub_10033360`, `MathVector_ReturnThis`, `BoneShadow_FromQuat`, `Mat4_TransformPointInPlace`, `sub_10311C2C`, `MathVector_Nop`, `BoneShadow_Nop`, `sub_10189980`
- `Env_LerpFloat` calls nothing directly
- `Env_LerpKeyValues` calls `sub_10189750`, `Env_LerpFloat`
- `WeatherRes_IsTimeKeyName` calls nothing directly
- `Zone_GetClock` calls nothing directly
- `Env_FindPrevKey` calls `Zone_GetClock`, `Time_SetNormalized`, `YmResourceFile_FindResourceUnder`, `sub_100742A0`, `ResourceIter_FindFirst`, `ResourceIter_FindNext`, `WeatherRes_IsTimeKeyName`, `WeatherRes_GetTimeKey`, `Time_Normalize`
- `WeatherRes_FindAtOrBefore` calls `Zone_GetClock`, `Time_SetNormalized`, `sub_100742A0`, `ResourceIter_FindFirst`, `ResourceIter_FindNext`, `WeatherRes_GetTimeKey`, `Time_Normalize`
- `Env_FindNextKey` calls `Zone_GetClock`, `Time_SetNormalized`, `YmResourceFile_FindResourceUnder`, `sub_100742A0`, `ResourceIter_FindFirst`, `ResourceIter_FindNext`, `WeatherRes_IsTimeKeyName`, `WeatherRes_GetTimeKey`, `Time_Normalize`
- `WeatherRes_FindNeighbor` calls `Zone_GetClock`, `Time_SetNormalized`, `sub_100742A0`, `ResourceIter_FindFirst`, `ResourceIter_FindNext`, `WeatherRes_GetTimeKey`, `Time_Normalize`
- `Env_UpdatePrevKey` calls `Env_FindPrevKey`, `Env_SetKeyField2C`
- `Env_UpdateNextKey` calls `Env_FindNextKey`, `Env_SetKeyField30`
- `Env_UpdateKeyAtOrBefore` calls `WeatherRes_FindAtOrBefore`, `Env_SetKeyField24`
- `Env_UpdateKeyNeighbor` calls `WeatherRes_FindNeighbor`, `Env_SetKeyField28`
- `Env_SetKeyField2C` calls nothing directly
- `Env_SetKeyField30` calls nothing directly
- `Env_SetKeyField24` calls nothing directly
- `Env_SetKeyField28` calls nothing directly
- `Env_UpdateTimeKeys` calls `Env_UpdatePrevKey`, `Env_UpdateNextKey`, `Env_UpdateKeyAtOrBefore`, `Env_UpdateKeyNeighbor`
- `Env_BlendTimeOfDay` calls `Zone_GetClock`, `Env_UpdatePrevKey`, `Env_UpdateNextKey`, `unknown_libname_158`, `WeatherRes_GetTimeKey`, `Time_Normalize`, `Time_SetNormalized`, `Env_UpdateKeyAtOrBefore`, `Env_UpdateKeyNeighbor`, `Blend_FreeResult`, `Blend_AllocResult`, `Env_BlendKeys`
