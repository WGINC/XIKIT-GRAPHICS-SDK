# ZoneMap

Group: `Zone` (by the file name only). Source: `sdk/tree_src/ZoneMap.cpp`.

Why the file has this name (data/unit_names.json): CTsZoneMap::Render / DrawProjectedShadow / DrawProjectedTexture, XiZone_Draw / DrawElement, ModelActor_Draw, Env_*

68 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ZoneMap_UpdateLoadState` | 0x101787C0 | 313 | yes | 8 | Steps a zone-map area load through its states, binding the mesh resource once it is resident. | medium |
| `ZoneMap_SetArea` | 0x10178A20 | 157 | yes | 8 | Requests a zone-map area by id, or clears the current one when the id is zero. | medium |
| `ZoneMap_ReleaseSlot` | 0x10178AC0 | 58 | yes | 7 | Releases one zone-map slot and clears the loaded-area marker. | medium |
| `ZoneMap_Reset` | 0x10178F70 | 27 | yes | 8 | Tears down the zone map's current step and returns its state to 1. | medium |
| `ZoneMap_DrawBox` | 0x101791F0 | 176 | yes | 0 | - | - |
| `ZoneMap_CreateVertexShaders` | 0x101792A0 | 71 | yes | 0 | - | - |
| `ZoneMap_CopyField342C8ToField39450` | 0x10179410 | 13 | yes | - | - | - |
| `ZoneMap_GetField342C8` | 0x10179420 | 7 | yes | - | Returns the value stored at offset 0x342C8 of the zone map. | low |
| `ZoneMap_SetByteOfId999Entries` | 0x1017A590 | 80 | yes | - | Sets the first byte of every zone-map record with id 999 to the argument. | low |
| `ZoneMap_DrawMeshGroupsWithFog` | 0x1017ADE0 | 335 | yes | 0 | - | - |
| `ZoneMap_FreeSlot` | 0x1017B110 | 200 | yes | 6 | Frees the resources held by one zone-map slot and clears the slot. | medium |
| `ZoneMap_TeardownStep` | 0x1017B1E0 | 292 | yes | 7 | - | - |
| `ZoneMap_QueryBoxHeightBandThenGetCount34154` | 0x101811D0 | 60 | yes | - | Returns the dword at +0x34154 of the sub-object at +0x178 when the box-height band query hits, else 0. | low |
| `ZoneMap_QueryBoxHeight` | 0x10181210 | 117 | yes | - | Tests a box against the zone map and returns the height of the hit. | low |
| `ZoneMap_QueryBoxHeightBand` | 0x10181290 | 95 | yes | - | Queries the box height at two offsets 0.51 either side of the given position. | low |
| `ZoneMap_QueryBoxHeightByRadius` | 0x10181300 | 104 | yes | - | Queries the box height at two offsets given by the stored radius at this+0x170. | low |
| `ZoneMap_QueryExpandedBox` | 0x10181370 | 115 | yes | - | Tests a box around the given point, expanded by a constant, against the sub-object at +0x178 and writes the hit height to *arg6. | low |
| `ZoneMap_FindGroundHeight` | 0x101813F0 | 183 | yes | - | - | - |
| `ZoneMap_Query169290` | 0x101814D0 | 49 | yes | - | Queries the zone map's +0x178 member through 0x10169290. | low |
| `ZoneMap_Query1693B0` | 0x10181590 | 11 | yes | - | Queries the zone map's +0x178 member for a position through 0x101693B0. | low |
| `ZoneMap_IsTargetAheadKind9` | 0x101815D0 | 861 | yes | - | Returns whether the ground a short way ahead of the target actor is of kind 9 (by the zone map), with nothing in between. | low |
| `ZoneMap_GetTargetGroundKindByte` | 0x10181930 | 119 | yes | - | Returns the table byte for the kind of ground under the target actor, or false when there is none. | low |
| `ZoneMap_IsBoxHeightHitByRadius` | 0x101819B0 | 47 | yes | - | Tests whether the zone map box at x minus the radius at +0x170, height 19.0, hits. | low |
| `ZoneMap_Query16E7E0` | 0x10181A10 | 34 | yes | - | Queries the zone map's +0x178 member through 0x1016E7E0. | low |
| `ZoneMap_MulPointXyz` | 0x10181F60 | 116 | yes | - | Transforms a point by a 4x4 matrix, writing the xyz result and returning w. | medium |
| `ZoneMap_BuildPerspective` | 0x10182490 | 611 | yes | - | Builds a 4x4 perspective projection from the width, height, near and far values. | medium |
| `Gfx_DrawWireBox` | 0x10182F10 | 1115 | yes | 0 | - | - |
| `ZoneMap_FindSlotByName` | 0x10183420 | 52 | yes | - | Finds the zone-map slot whose name matches the given string. | medium |
| `ZoneMap_DrawMeshById` | 0x10183DA0 | 1811 | yes | 1 | - | - |
| `ModelActor_Draw` | 0x101844C0 | 1969 | yes | 0 | - | - |
| `ZoneMap_ClearSlots` | 0x10186DB0 | 31 | yes | 10 | Clears both zone-map slots. | medium |
| `ZoneMap_FreeSubAreas` | 0x10186DD0 | 118 | yes | 9 | Frees the sub-area objects held by one zone-map slot, other than the zone itself. | medium |
| `ZoneMap_GetAddr0B4` | 0x10186E90 | 7 | yes | - | Returns the address of the zone map's field at offset 0xB4. | low |
| `ZoneMap_GetAddr0C4` | 0x10186EA0 | 7 | yes | - | Returns the address of the zone map's field at offset 0xC4. | low |
| `ZoneMap_GetAddr0D4` | 0x10186EB0 | 7 | yes | - | Returns the address of the zone map's field at offset 0xD4. | low |
| `ZoneMap_GetAddr024` | 0x10186EC0 | 4 | yes | - | Returns the address of the zone map's field at offset 0x24. | low |
| `ZoneMap_GetAddr044` | 0x10186EE0 | 4 | yes | - | Returns the address of the zone map's field at offset 0x44. | low |
| `ZoneMap_GetAddr064` | 0x10186F00 | 4 | yes | - | Returns the address of the zone map's field at offset 0x64. | low |
| `ZoneMap_GetAddr074` | 0x10186F10 | 4 | yes | - | Returns the address of the zone map's field at offset 0x74. | low |
| `Env_GetColorPtr84` | 0x10186F20 | 7 | yes | - | - | - |
| `ZoneMap_GetAddr094` | 0x10186F30 | 7 | yes | - | Returns the address of the zone map's field at offset 0x94. | low |
| `ZoneMap_GetAddrRef18Plus1C` | 0x10186F40 | 7 | yes | - | Returns the address at offset 0x1C of the object referenced at this+0x18. | low |
| `ZoneMap_GetAddrRef18Plus20` | 0x10186F50 | 7 | yes | - | Returns the address at offset 0x20 of the object referenced at this+0x18. | low |
| `ZoneMap_GetAddr0E4` | 0x10186F70 | 7 | yes | - | Returns the address of the zone map's field at offset 0xE4. | low |
| `ZoneMap_GetAddr0F4` | 0x10186F80 | 7 | yes | - | Returns the address of the zone map's field at offset 0xF4. | low |
| `ZoneMap_GetAddr114` | 0x10186F90 | 7 | yes | - | Returns the address of the zone map's field at offset 0x114. | low |
| `Env_GetAmbientColorPtr` | 0x10186FA0 | 7 | yes | - | - | - |
| `ZoneMap_GetAddrRef18Plus3C` | 0x10186FB0 | 7 | yes | - | Returns the address at offset 0x3C of the object referenced at this+0x18. | low |
| `ZoneMap_GetAddrRef18Plus40` | 0x10186FC0 | 7 | yes | - | Returns the address at offset 0x40 of the object referenced at this+0x18. | low |
| `ZoneMap_GetFloatRef18Plus44` | 0x10186FD0 | 7 | yes | - | Returns the float at offset 0x44 of the object referenced at this+0x18. | low |
| `ZoneMap_GetFloatRef1CPlus4` | 0x10186FE0 | 7 | yes | - | Returns the float at offset 4 of the object referenced at this+0x1C. | low |
| `ZoneMap_GetFloatRef1CPlus8` | 0x10186FF0 | 7 | yes | - | Returns the float at offset 8 of the object referenced at this+0x1C. | low |
| `ZoneMap_GetByteRef1CPlus10` | 0x10187000 | 11 | yes | - | Returns the byte at offset 0x10 of the object referenced at this+0x1C. | low |
| `ZoneMap_GetFloatRef1CPlus0C` | 0x10187020 | 7 | yes | - | Returns the float at +0x0C of the record pointed to by this+0x1C. | low |
| `ZoneMap_ReleaseChain` | 0x10187030 | 31 | yes | 8 | Releases a zone map and the chain of zone maps linked at +4. | medium |
| `Env_ApplyRecord` | 0x10187050 | 803 | yes | - | - | - |
| `ZoneMap_SetVtableApplyRecord` | 0x10187380 | 18 | yes | - | Sets the object's vtable, applies its record through Env_ApplyRecord, and returns the object. | low |
| `ZoneMap_Update` | 0x101874A0 | 72 | yes | - | Updates a zone map and its chained maps, and applies the current record. | medium |
| `ZoneMap_ForEachFindKind5B` | 0x101875C0 | 24 | yes | - | Runs YmCombineWeather_FindKind5B over the zone's object list. | low |
| `ZoneMap_ForEachFindKind5A` | 0x101875E0 | 24 | yes | - | Runs YmCombineWeather_FindKind5A over the zone's object list. | low |
| `ZoneMap_SaveState` | 0x10187600 | 288 | yes | - | Saves the zone map's current state into its previous-state block. | medium |
| `ZoneMap_UpdateOrbit` | 0x10187720 | 2446 | yes | - | Places the zone's light positions on a circle around the camera from an angle. | low |
| `ZoneMap_SetRecord` | 0x101880C0 | 193 | yes | - | Sets the zone map's current record and applies its colours. | medium |
| `ZoneMap_ApplyColors` | 0x10188190 | 1894 | yes | - | Converts a zone record's colour bytes into the zone map and the environment colours. | medium |
| `ZoneMap_GetCurrent` | 0x10188900 | 15 | yes | - | Returns the active zone map, if one exists. | medium |
| `ZoneMap_AppendToList` | 0x10188910 | 40 | yes | - | Appends a zone map to the end of the active zone's list. | medium |
| `ZoneMap_FindPrevious` | 0x10188970 | 35 | yes | - | Returns the zone map before this one in the active list. | medium |
| `ZoneMap_GetTail` | 0x101889A0 | 26 | yes | - | Returns the last zone map in the active list. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ZoneMap_UpdateLoadState` calls `ZoneMap_ReleaseSlot`, `game_10178D90`, `ResourceHandle_IsResident`, `game_10178DD0`, `game_10072FD0`, `game_10071E90`, `XI_PACKET_100FC680 (left out)`, `ZoneMapLoad_SetFlag2000OnUnderscoreEntries`, `game_1017A630`, `game_10186D30`, `XiZone::FindSubArea`, `game_100852D0`, `XI_PACKET_10178790 (left out)`
- `ZoneMap_SetArea` calls `ZoneMap_ReleaseSlot`, `XI_PACKET_100FC680 (left out)`, `ZoneMap_Call10173AE0`, `ZoneMapLoad_SetFlag2000OnUnderscoreEntries`
- `ZoneMap_ReleaseSlot` calls `ZoneMap_UnlinkSlotCells`, `ZoneMap_FreeSlot`
- `ZoneMap_Reset` calls `ZoneMap_TeardownStep`, `EffectOffscreen_FreeSplineSet`
- `ZoneMap_DrawBox` calls `CDx::DrawIndexedPrimitive`
- `ZoneMap_CreateVertexShaders` calls nothing directly
- `ZoneMap_CopyField342C8ToField39450` calls nothing directly
- `ZoneMap_GetField342C8` calls nothing directly
- `ZoneMap_SetByteOfId999Entries` calls nothing directly
- `ZoneMap_DrawMeshGroupsWithFog` calls `ZoneMap_DrawMeshById`
- `ZoneMap_FreeSlot` calls `Mem_FreeObject`, `ZoneMapLoad_FreeNodeOrAll`, `ZoneMap_FreeSubAreas`, `game_1017A690`, `DynVB_ReleaseResourcesOf`, `CMoResource::ReleaseChain`, `MoRes_FreeIfUnreferenced`
- `ZoneMap_TeardownStep` calls `ZoneMap_FreeDbgBoxList`, `ZoneMap_FreeSlot`, `ZoneMap_ResetGlobalTables`, `ZoneMap_ReleaseBuffers`, `CMoResource::ReleaseChain`, `MoRes_FreeIfUnreferenced`
- `ZoneMap_QueryBoxHeightBandThenGetCount34154` calls `ZoneMap_QueryBoxHeightBand`, `ZoneMap_GetCount34154`
- `ZoneMap_QueryBoxHeight` calls `ZoneMapLoad_SegmentHit3413A`
- `ZoneMap_QueryBoxHeightBand` calls `ZoneMap_QueryBoxHeight`
- `ZoneMap_QueryBoxHeightByRadius` calls `ZoneMap_QueryBoxHeight`
- `ZoneMap_QueryExpandedBox` calls `ZoneMapLoad_SegmentHitWithObjects`
- `ZoneMap_FindGroundHeight` calls `ZoneMapLoad_SegmentTest34139`
- `ZoneMap_Query169290` calls `ZoneMapLoad_ProbeAxis1`
- `ZoneMap_Query1693B0` calls `ZoneMapLoad_SegmentHit3413A`
- `ZoneMap_IsTargetAheadKind9` calls `ActorHandle_Resolve`, `Mat44_Multiply`, `ZoneMapLoad_SegmentHitWithObjects`, `ZoneMap_QueryBoxHeight`, `ZoneMapLoad_GetField34148`
- `ZoneMap_GetTargetGroundKindByte` calls `ActorHandle_Resolve`, `ZoneMap_QueryBoxHeight`, `ZoneMapLoad_GetField34148`
- `ZoneMap_IsBoxHeightHitByRadius` calls `ZoneMap_QueryBoxHeight`
- `ZoneMap_Query16E7E0` calls `game_1016E7E0`
- `ZoneMap_MulPointXyz` calls nothing directly
- `ZoneMap_BuildPerspective` calls nothing directly
- `Gfx_DrawWireBox` calls `CDx::DrawPrimitiveUP`
- `ZoneMap_FindSlotByName` calls `ZoneMap_FindEntryByName`
- `ZoneMap_DrawMeshById` calls `game_10181BB0`, `CDx::SetLight`, `CDx::SetTransform`, `XiZone::GetDirLights`, `ZoneMap_FillDirLight`, `Env_ComputeAmbient`, `Env_ComputeFog`, `CDx::DrawPrimitive`
- `ModelActor_Draw` calls `game_10178760`, `CDx::SetLight`, `XiZone::GetDirLights`, `XiZone::GetDirLight`, `XiZone::GetAmbient`, `XiZone::GetFog`, `Gfx_SetZBias`, `CDx::SetTransform`, `CDx::DrawPrimitive`
- `ZoneMap_ClearSlots` calls `ZoneMap_FreeSubAreas`
- `ZoneMap_FreeSubAreas` calls `XiZone::FindSubArea`, `game_10187470`, `thunk_Mem_FreeBlockMergeNeighbours_as_v0`, `operator_delete`
- `ZoneMap_GetAddr0B4` calls nothing directly
- `ZoneMap_GetAddr0C4` calls nothing directly
- `ZoneMap_GetAddr0D4` calls nothing directly
- `ZoneMap_GetAddr024` calls nothing directly
- `ZoneMap_GetAddr044` calls nothing directly
- `ZoneMap_GetAddr064` calls nothing directly
- `ZoneMap_GetAddr074` calls nothing directly
- `Env_GetColorPtr84` calls nothing directly
- `ZoneMap_GetAddr094` calls nothing directly
- `ZoneMap_GetAddrRef18Plus1C` calls nothing directly
- `ZoneMap_GetAddrRef18Plus20` calls nothing directly
- `ZoneMap_GetAddr0E4` calls nothing directly
- `ZoneMap_GetAddr0F4` calls nothing directly
- `ZoneMap_GetAddr114` calls nothing directly
- `Env_GetAmbientColorPtr` calls nothing directly
- `ZoneMap_GetAddrRef18Plus3C` calls nothing directly
- `ZoneMap_GetAddrRef18Plus40` calls nothing directly
- `ZoneMap_GetFloatRef18Plus44` calls nothing directly
- `ZoneMap_GetFloatRef1CPlus4` calls nothing directly
- `ZoneMap_GetFloatRef1CPlus8` calls nothing directly
- `ZoneMap_GetByteRef1CPlus10` calls nothing directly
- `ZoneMap_GetFloatRef1CPlus0C` calls nothing directly
- `ZoneMap_ReleaseChain` calls `XiZone::DestroyChildList`
- `Env_ApplyRecord` calls `ZoneMap_AppendToList`
- `ZoneMap_SetVtableApplyRecord` calls `Env_ApplyRecord`
- `ZoneMap_Update` calls `ZoneMap_SaveState`, `EnvBlend_CallBlendUpdate`, `ZoneMap_SetRecord`, `Env_RampWindStrength`
- `ZoneMap_ForEachFindKind5B` calls `YmCombineWeather_FindKind5B`
- `ZoneMap_ForEachFindKind5A` calls `YmCombineWeather_FindKind5A`
- `ZoneMap_SaveState` calls `ZoneMap_UpdateOrbit`
- `ZoneMap_UpdateOrbit` calls `MathVector_ReturnThis`, `Mat4_SetIdentity`, `Mat4_PostRotateX`, `Mat4_TransformPointInPlace`, `Camera_GetField50`, `Vec3_Copy`, `Vec3_SubInPlace`, `Vec3_ScaleInPlace`, `Vec3_AddInPlace`, `game_100274B0`, `game_10027530`, `MathVector_Nop`
- `ZoneMap_SetRecord` calls `game_10311C2C`, `Camera_SetField304BytesOnGlobal`, `Camera_SetField300`, `Camera_SetField2FC`, `ZoneMap_GetFloatRef1CPlus8`, `Camera_SetField314`, `ZoneMap_GetFloatRef1CPlus4`, `Camera_SetField318`, `ZoneMap_ApplyColors`
- `ZoneMap_ApplyColors` calls `game_100274B0`, `Env_GetAmbientColorPtr`, `Env_GetColorPtr84`, `ZoneMap_GetAddr114`, `ZoneMap_GetAddr094`, `ZoneMap_GetAddrRef18Plus3C`, `ZoneMap_GetAddrRef18Plus40`, `ZoneMap_GetAddrRef18Plus1C`, `ZoneMap_GetAddrRef18Plus20`, `ZoneMap_GetAddr0F4`, `ZoneMap_GetAddr074`, `ZoneMap_GetAddr0C4`, `ZoneMap_GetAddr044`, `ZoneMap_GetAddr064`, `ZoneMap_GetAddr024`
- `ZoneMap_GetCurrent` calls nothing directly
- `ZoneMap_AppendToList` calls `ZoneMap_GetCurrent`, `ZoneMap_GetTail`
- `ZoneMap_FindPrevious` calls `ZoneMap_GetCurrent`
- `ZoneMap_GetTail` calls `ZoneMap_GetCurrent`
