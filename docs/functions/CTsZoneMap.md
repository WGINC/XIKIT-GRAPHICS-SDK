# CTsZoneMap

Group: `CTs` (by the file name only). Source: `sdk/tree_src/CTsZoneMap.cpp`.

19 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Gfx_AssembleVertexShader` | 0x10177240 | 150 | yes | 0 | - | - |
| `ZoneMap_GetMatrixGlobal` | 0x101773F0 | 6 | yes | - | Returns the address of the zone map's global matrix. | low |
| `Gfx_SetZBias` | 0x10177400 | 25 | yes | 0 | - | - |
| `ZoneMap_SetOverlayProjection` | 0x10177420 | 186 | yes | - | - | - |
| `ZoneMap_QueryBoxHeightGlobal` | 0x10177770 | 39 | yes | - | Queries the current zone map's box height, or returns false without a zone map. | medium |
| `ZoneMap_Call10173AE0` | 0x101779B0 | 11 | yes | - | Forwards to 0x10173AE0. | low |
| `Gfx_SetupLineDrawState` | 0x101779C0 | 369 | yes | 0 | - | - |
| `Gfx_DrawQuadOutline` | 0x10177B40 | 259 | yes | 0 | - | - |
| `Gfx_DrawLine3D` | 0x10177C50 | 125 | yes | 1 | - | - |
| `CTsZoneMap::Init` | 0x10177D00 | 638 | yes | - | Constructs the zone map task and initialises its sub-objects, state and global tables. (reviewed as sub_10177D00) | medium |
| `CTsZoneMap::SetLayerOrder` | 0x10177FA0 | 120 | yes | - | Sets the zone map's six layer-order entries, depending on a flag. (reviewed as sub_10177FA0) | low |
| `CTsZoneMap::CTsZoneMap_Destructor` | 0x10178070 | 344 | yes | 0 | - | - |
| `CTsZoneMap::InitZBiasPresets` | 0x101781D0 | 115 | yes | - | - | - |
| `ZoneMap_ResetGlobalTables` | 0x101784E0 | 68 | yes | - | Clears the zone map's global tables and sets their default entries. | medium |
| `ZoneMap_ReleaseStateBlock` | 0x10178B00 | 48 | yes | 0 | - | - |
| `CTsZoneMap::Render` | 0x10178B30 | 516 | yes | 1 | Per-frame zone-map update: sets up the zone matrices and draws the zone when it is loaded. (reviewed as sub_10178B30) | medium |
| `CTsZoneMap::UpdateViewerPosition` | 0x10179390 | 118 | yes | - | - | - |
| `CTsZoneMap::DrawProjectedTexture` | 0x10182700 | 2050 | yes | 0 | - | - |
| `CTsZoneMap::DrawProjectedShadow` | 0x10184FE0 | 3262 | yes | 0 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Gfx_AssembleVertexShader` calls `sub_10177350`, `sub_10177340`, `sub_102DAA0D`, `sub_102DAA71`
- `ZoneMap_GetMatrixGlobal` calls nothing directly
- `Gfx_SetZBias` calls nothing directly
- `ZoneMap_SetOverlayProjection` calls `D3DXMatrixPerspectiveFovLH_static`
- `ZoneMap_QueryBoxHeightGlobal` calls `ZoneMap_IsBoxHeightHitByRadius`
- `ZoneMap_Call10173AE0` calls `ZoneMap_FindDbgBoxMPosById`
- `Gfx_SetupLineDrawState` calls `CDx::SetTransform`
- `Gfx_DrawQuadOutline` calls `CDx::DrawPrimitiveUP`
- `Gfx_DrawLine3D` calls `CDx::DrawPrimitiveUP`
- `CTsZoneMap::Init` calls `CMoTask::Constructor`, `ZoneMap_ConstructVt10336668`, `ZoneMap_ConstructVt10336634`, `ZoneMap_ConstructVt1033668C`, `MathVector_ReturnThis`, `ZoneMap_ConstructVt10336614`, `EffectOffscreen_Init`, `ZoneMap_ResetGlobalTables`, `CTsZoneMap::SetLayerOrder`
- `CTsZoneMap::SetLayerOrder` calls nothing directly
- `CTsZoneMap::CTsZoneMap_Destructor` calls `ZoneMap_TeardownStep`, `ZoneMap_ReleaseStateBlock`, `sub_10055000`, `sub_101674B0`, `MathVector_Nop`, `sub_10171920`, `sub_101678D0`, `sub_1016FC80`, `CMoTask::Destructor`
- `CTsZoneMap::InitZBiasPresets` calls nothing directly
- `ZoneMap_ResetGlobalTables` calls nothing directly
- `ZoneMap_ReleaseStateBlock` calls nothing directly
- `CTsZoneMap::Render` calls `sub_10055130`, `sub_10055160`, `sub_10183370`, `Camera_GetFrameScale`, `ZoneMap_UpdateLoadState`, `XiZone_Draw`, `sub_10178250`, `CTsZoneMap::InitZBiasPresets`, `ZoneMap_CreateVertexShaders`, `CTsZoneMap_LogZoneMetrics`, `JpegScreenshot_TestMask10663188`, `sub_10186E70`, `sub_101D2260`
- `CTsZoneMap::UpdateViewerPosition` calls `ZoneMap_GetHitCount`, `Camera_GetField50`, `Vec3_Copy`
- `CTsZoneMap::DrawProjectedTexture` calls `Mat44_Multiply`, `sub_10167940`, `sub_10311C2C`, `CDx::SetTransform`, `CDx::DrawPrimitiveUP`
- `CTsZoneMap::DrawProjectedShadow` calls `ZoneMap_SetOverlayProjection`, `Gfx_SetZBias`, `sub_10167940`, `sub_10311C2C`, `CDx::SetTransform`, `CDx::DrawPrimitiveUP`
