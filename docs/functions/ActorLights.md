# ActorLights

Group: `Actor` (by the file name only). Source: `sdk/tree_src/ActorLights.cpp`.

Why the file has this name (data/unit_names.json): Actor_SelectNearestLights, CXiActor::CorrectOnZoneMap, the light table globals

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Actor_SelectNearestLights` | 0x100CB4E0 | 2161 | yes | 0 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Actor_SelectNearestLights` calls `Camera_GetFrameScale`, `Vec3_Sub`, `Vec3_MulComponents`, `sub_100274B0`, `Vec3_ScaleInPlace`, `sub_10039410`, `XiZone::GetAmbient`, `XiZone::GetFog`, `TargetMenu_GetCachedUnlessFlag21`, `ActorHandle_ResolveObject`, `sub_10027020`, `sub_10311C2C`
