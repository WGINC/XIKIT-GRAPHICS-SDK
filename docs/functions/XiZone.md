# XiZone

Group: `Xi` (by the file name only). Source: `sdk/tree_src/XiZone.cpp`.

22 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `XiZone::RestoreSavedFields` | 0x100BA080 | 54 | yes | - | Restores two saved zone fields and clears the saved flag. (reviewed as game_100BA080) | low |
| `XiZone::DrawMarkerForward` | 0x10177CD0 | 39 | yes | - | - | - |
| `XiZone::DrawGroundShadowQuad` | 0x10184C90 | 843 | yes | 1 | - | - |
| `XiZone::DrawDecalOnTriangles` | 0x10185CA0 | 3800 | yes | 0 | - | - |
| `XiZone::FindSubArea` | 0x101889C0 | 31 | yes | - | - | - |
| `XiZone::UpdateTree` | 0x101889E0 | 38 | yes | - | Updates the zone's child and each entry of its list. (reviewed as game_101889E0) | medium |
| `XiZone::DestroyChildList` | 0x10188A10 | 60 | yes | 7 | Destroys the zone's child and every node in its list. (reviewed as game_10188A10) | medium |
| `Env_RampWindStrength` | 0x10188A50 | 181 | yes | - | - | - |
| `XiZone::TestHeadFlag` | 0x10188B10 | 83 | yes | - | Tests a flag on the zone's head node, depending on the zone's state value. (reviewed as game_10188B10) | low |
| `XiZone::GetDirLights` | 0x10188B70 | 296 | yes | - | - | - |
| `XiZone::GetInstance` | 0x1018B130 | 50 | yes | - | - | - |
| `XiZone::Constructor` | 0x1018B170 | 461 | yes | - | - | - |
| `XiZone::SetTreeState1BC` | 0x1018B5E0 | 61 | yes | - | Sets the zone tree's state word at +0x1BC and applies it along the chain. (reviewed as game_1018B5E0) | low |
| `XiZone::ResetState` | 0x1018B620 | 124 | yes | 8 | Resets the zone's state and the camera and zone-map values it uses. (reviewed as game_1018B620) | medium |
| `XiZone::DrawScene` | 0x1018B860 | 70 | yes | 1 | - | - |
| `XiZone::Call10036170` | 0x1018B8B0 | 14 | yes | - | Forwards its argument to 0x10036170. (reviewed as game_1018B8B0) | low |
| `XiZone::ComputeFogDistance` | 0x1018B8F0 | 110 | yes | - | Computes the zone's fog distance and clamps it to its limit. (reviewed as game_1018B8F0) | medium |
| `XiZone::GetDirLightsForArea` | 0x1018B960 | 49 | yes | - | Gets the directional lights of the zone or of the sub-area for the given argument. (reviewed as game_1018B960) | medium |
| `XiZone::GetDirLight` | 0x1018B9A0 | 49 | yes | - | - | - |
| `XiZone::GetAmbient` | 0x1018B9E0 | 49 | yes | - | - | - |
| `XiZone::GetFog` | 0x1018BA20 | 59 | yes | - | - | - |
| `XiZone::SetPtr1D8FromTable` | 0x1018BAE0 | 43 | yes | - | Stores a table pointer chosen by its argument into the object's field at +0x1D8. (reviewed as game_1018BAE0) | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `XiZone::RestoreSavedFields` calls nothing directly
- `XiZone::DrawMarkerForward` calls `game_10168D20`
- `XiZone::DrawGroundShadowQuad` calls `ZoneMap_SetOverlayProjection`, `Gfx_SetZBias`, `Mat4_SetIdentity_2`, `Mat44_Multiply`, `CDx::SetTransform`, `CDx::DrawPrimitiveUP`
- `XiZone::DrawDecalOnTriangles` calls `ZoneMap_SetOverlayProjection`, `Gfx_SetZBias`, `Mat44_Multiply`, `game_10167940`, `game_10311C2C`, `CDx::SetTransform`, `CDx::DrawPrimitiveUP`
- `XiZone::FindSubArea` calls `ZoneMap_GetCurrent`
- `XiZone::UpdateTree` calls `Env_UpdateTimeKeys`
- `XiZone::DestroyChildList` calls `YmCombineWeather::Release`, `thunk_Mem_FreeBlockMergeNeighbours_as_v0`
- `Env_RampWindStrength` calls `Camera_GetFrameScale`, `game_103149A0`
- `XiZone::TestHeadFlag` calls nothing directly
- `XiZone::GetDirLights` calls `ZoneMap_GetFloatRef18Plus44`, `Vec3_Scale`
- `XiZone::GetInstance` calls `Mem_AllocDefault`, `XiZone::Constructor`
- `XiZone::Constructor` calls `ZoneMap_SetVtableApplyRecord`, `unknown_libname_158`, `Time_Normalize`, `ZoneMap_SetRecord`, `XiZone::SetPtr1D8FromTable`
- `XiZone::SetTreeState1BC` calls `XiZone::UpdateTree`, `ZoneMap_ForEachFindKind5B`, `ZoneMap_ForEachFindKind5A`
- `XiZone::ResetState` calls `ActorBase_ReleaseQueued`, `ZoneMap_ReleaseChain`, `ZoneMap_ClearSlots`, `XiZone::DestroyChildList`, `Time_Normalize`, `ZoneMap_Reset`
- `XiZone::DrawScene` calls `ZoneMap_Update`, `Sky_DrawDomeViewCentered`, `XiZone::Call10036170`
- `XiZone::Call10036170` calls `SoundElem_SetCurrent10463914`
- `XiZone::ComputeFogDistance` calls `Env_FogDistanceFactor`, `ZoneMap_GetFloatRef1CPlus0C`
- `XiZone::GetDirLightsForArea` calls `XiZone::FindSubArea`, `XiZone::GetDirLights`
- `XiZone::GetDirLight` calls `XiZone::FindSubArea`, `ZoneMap_FillDirLight`
- `XiZone::GetAmbient` calls `XiZone::FindSubArea`, `Env_ComputeAmbient`
- `XiZone::GetFog` calls `XiZone::FindSubArea`, `Env_ComputeFog`
- `XiZone::SetPtr1D8FromTable` calls nothing directly
