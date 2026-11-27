# EnvLight

Group: `Env` (by the file name only). Source: `sdk/tree_src/EnvLight.cpp`.

Why the file has this name (data/unit_names.json): Env_ComputeAmbient / ComputeFog, ZoneMap_FillDirLight, WeatherRes_Construct

5 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ZoneMap_FillDirLight` | 0x10188CA0 | 338 | yes | - | Fills a directional light record from one of the zone's two light sets. | medium |
| `Env_ComputeAmbient` | 0x10188E00 | 405 | yes | - | - | - |
| `Env_ComputeAmbientFloat4` | 0x10188FA0 | 371 | yes | - | - | - |
| `Env_ComputeFog` | 0x10189120 | 388 | yes | - | - | - |
| `WeatherRes_Construct` | 0x101893B0 | 26 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ZoneMap_FillDirLight` calls `Vec4_Copy`, `game_10186F60`, `ZoneMap_GetFloatRef18Plus44`, `Vec3_Scale`
- `Env_ComputeAmbient` calls `Env_GetColorPtr84`, `Env_GetAmbientColorPtr`, `GammaRamp_GetChannelSamples`, `game_10311C2C`
- `Env_ComputeAmbientFloat4` calls `Env_GetAmbientColorPtr`, `GammaRamp_GetChannelSamples`
- `Env_ComputeFog` calls `ZoneMap_GetAddr114`, `game_10311C2C`, `ZoneMap_GetAddrRef18Plus1C`, `Env_FogDistanceFactor`, `ZoneMap_GetAddrRef18Plus20`, `ZoneMap_GetAddrRef18Plus3C`, `ZoneMap_GetAddrRef18Plus40`
- `WeatherRes_Construct` calls `CMoResource_ConstructBase`, `WeatherRes_InitKeyDefaults`
