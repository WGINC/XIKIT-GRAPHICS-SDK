> Paths in this document are the development repository's: tree/src/ is sdk/tree_src/ here, kit/xikit/ and kit/d3d8on11/ are src/xikit/ and src/d3d8on11/, sdk/examples/ is sdk/examples/; docs/HISTORY.md and kit/sessions/ are not published.

# The game's camera: view, projection, distances

How FFXiMain.dll builds the view and the projection and decides what is far enough to draw, from its code (analysed
build 6A995428). Sources: the tree's C (tree/src/WinMain.cpp, tree/src/ActorCamera.cpp, tree/src/XiZone.cpp,
tree/src/FrameRender.cpp) and the disassembly where the tree has no source. Most of it was read for two example mods,
whose headers keep the detail: sdk/examples/camera_view.cpp and sdk/examples/photo_mode.cpp. **Not known** marks what
is not read.

## 1. The view

`Camera_ApplyViewProjection` (0x10015510, at the end of `Frame_Render`) asks the camera controller whether it moved
(`Camera_DiffersFromSaved` 0x10021AE0: the eye at controller +0x44 and the look-at point at +0x50 against the copies at
+0x60 and +0x6C). If so, `Camera_SnapshotState` (0x10021B70) builds the view at controller +4 with
`Camera_BuildLookAtView` (eye +0x44, look-at +0x50, roll +0x5C), saves the copies, and the view goes to
`CDx::SetTransform` (VIEW). `MoDX_Update` and `Camera_SetupMatrices` cache it for the billboards and the effects.

The view the game culls with is the one last set on the device (`CDx::GetTransformCached(2)`, the copy at CDx +0x97C:
read in `XiZone_Draw` 0x1017BEFC and `CXiSkeletonActor_OnMove` 0x100C7C3C). It is set at the end of `Frame_Render`
(0x10012E1E), before the next frame's `XiZone::DrawScene` (0x10011C97). A mod's eye set in `Camera_SnapshotState` is
therefore also the eye the zone and the actors are culled with.

## 2. The projection (`Camera_BuildPerspectiveFov`, 0x10015490)

Built at camera +0x154 (a copy at +0x1D4) with D3DXMatrixPerspectiveFovLH: vertical field of view
2 x atan(192 / [+0x2F4]), aspect 1 / ([+0x2F0] x [+0x2E8]), near [+0x2DC], far [+0x2E0]. Its callers:
`Camera_BuildProjection`, `Camera_SetField2E4`, 0x10015430. As run, the matrix has _33 = -far / (far - near) and
_34 = -1 (the right-handed form, whatever the routine's name; kit/xikit/test mode cammod). Other readers of
+0x2F4 and +0x2E0: `ZoneMap_SetOverlayProjection` (the zone map's own projection), the effects' fog
(tree/src/ElemFog.cpp), `Camera_GetField2F4`, `Camera_GetFloat2E0`. So changing the fields (not the matrix) changes
every reader alike.

## 3. Draw distance (`XiZone::ComputeFogDistance`, 0x1018B8F0)

The zone's value (100 without a zone record); when the zone's +0x1D0 is above 0, that value times the time-of-day
factor (`Env_FogDistanceFactor` 0x101892B0) but not less than +0x1D0. Used by:
- `XiZone_Draw` (0x1017BF35): kept at zone +0x39420 and its square at +0x39424; a mesh is drawn only when its squared
  distance from the eye is below that (or a smaller per-mesh value); it is also the far distance of the zone's
  culling frustum (`ZoneMap_BuildPerspective` 0x1017BFB4, zone +0x38FDC);
- `CXiSkeletonActor_OnMove` (0x100C7D47) and 0x100AC5A0: beyond it an actor gets bit 1 of its flags word +0xB2, and
  `CXiActorDraw::UpdateDrawList` (0x10082DC7) draws it only while that word is 0.
The fog's own distances are another computation (`Env_ComputeFog`, sdk/examples/world_light.cpp).

### 3a. The floor +0x1D0 (25 Nov, disassembly)

`XiZone::Constructor` (0x1018B170) sets +0x1D0 to 43.0 (0x422C0000). The zone change 0x1018B3A0 (argument: the zone
number, kept at +0x1B4; called from three functions of the game) writes `[g_pXiZone]` +0x1D0 = 0 only for
zone 0xC1, and +0x1D4 = 0.7 only for zone 0x32; nothing in the game sets +0x1D0 back to 43.0 (the scan of every
store to +0x1D0 in XiZone's range: the constructor and this one). So while +0x1D0 is 43.0 the draw distance is the
zone's value times the time-of-day factor, but at least 43.0; in zone 0xC1 the product with no floor. The object: `XiZone::GetInstance`
makes it when `g_pXiZone` is empty (0x1018B14C, the constructor, then the 43.0); slot 1 of its vtable 0x10336838
(0x1018B360, an event handler) releases it and clears `g_pXiZone` for events of type 2 and 5. So after one of those
the next zone gets a new object and the floor 43.0 again. Which events those two types are (whether every zone
change sends one), read 26 Nov (disassembly): the zone object
lives in a block of the game's memory areas (`Mem_AllocFromArea`; its base slots 2 and 3, 0x1002C930/0x1002C920, read
and set a flag in the block header at object - 8). `MemBlock_CallEnabledEntries` (0x10028BF0) calls slot 1 of every
enabled block of an area with an event record; `MemHeapDebug_ApplyFourTables` (0x10029390) does it for the four
areas. The records are two series of {type, 0}: 0x103501F8 = {1}, {2}, {3}, sent in turn by 0x10014C60 (from
`Camera_ReleaseAll`, called by `CApp::RunMainLoop` 0x100016A9 and 0x100013C0), and 0x10350210 = {4}, {5}, {6}, sent by
0x10014CB0 (from `WinMain_ShutdownActorsAndTables`, which `WinMain_EnterState4AfterShutdown`,
`WinMain_TryShutdownActors` and `WinMain_StepStagedRelease` call; from 0x100B5C30, called by 0x100B5A90 and
0x100B5B70; and from `LobbyThread_ResetZone`). So the zone object is released by the second event of either series.
0x100B5A90 and 0x100B5B70 are opcodes 0x34 and 0x35 of the byte-code interpreter 0x100BC280 (jump table
0x100BC960, 219 entries; 0x100BCCD0 feeds it bytes from [object + 0x20] at +0x256): after a 300-step wait
([0x10489910]) each sends events 4..6 (0x100B5C30) and changes the zone with 0x1018B3A0 (section 3a), unless
[0x10489918] is set, when it resets the zone object instead (`XiZone::ResetState`). So a zone change made by those
two opcodes always gets a new zone object and the 43.0 floor. Whether every zone change in play goes through them
(what that interpreter's scripts are): not read.

## 4. Not known

- The zone's value is the float at +0xC of the record `[zone + 0x1C]` (`ZoneMap_GetFloatRef1CPlus0C`). Read 26 Nov
  (disassembly): `ZoneMap_SetRecord` (0x101880C0) sets +0x18 to its record and +0x1C to the record + 0x4C, so the value
  is the record's float at **+0x58**. The record at a zone's start: 0x1018B6A0 (from 0x1018B500, the zone load) takes
  the zone's resource, finds its chunk of type 0x2F (`CMoResource::FindByTypeAndId`, 0x1018B6CE; the factory's class
  `WeatherRes`, ctor 0x101893B0) and hands its data to 0x1018B010, which copies 0xAC bytes unchanged to 0x1065CA58
  (0x1018A760, `rep movsd` of 0x2B dwords) and sets that record on every zone map. The zone's resource is the file
  numbered zone + 100, or zone + 0x144F7 for zones 600 and above (0x10178DF0, 0x10178EB1..0x10178EF1; file numbers to
  paths: docs/DATA_FILES.md). So the draw distance is the float at +0x58 of the type-0x2F chunk's data in the zone's
  file. Later records: `ZoneMap_Update` sets `[map + 0x10] + 0x20` (the environment blend's record),
  `YmCombineWeather::Release` and 0x101873A0 set others (their records' source: not read).
  Checked 26 Nov on a real file: the owner's file 218 (`ROM/0/71.DAT`, zone 118 taken from row 118 of the English
  zone-name table, ROM/165/84.DAT, "Buburimu Peninsula"; that the table's row is the zone number is not shown by the
  code read). It walks as 1,794 resource chunks to its exact end, with the zone-map types 0x1C, 0x2E, 0x36 and 57
  chunks of type 0x2F (176 bytes of data each; ids of four digits: 0000, 0500, 0600, 1200, 1700, 1800, 2100). The float
  at +0x58 is 396.0 in the first 43 of them and 120.0 in the last 14. Which one the zone load takes:
  `FindByTypeAndId` is called with id 0 (0x1018B6C5), and with a type given, id 0 matches any id
  (`CMoResource::FindWorker`, tree/src/CMoResource.cpp:258): the first type-0x2F chunk its walk meets. In file order
  that is the "0600" chunk, 396.0; whether the walk's order is the file's order: not read (all of the first 43 hold
  396.0 either way). So in that zone the draw distance is 396 times the time-of-day factor, at least 43, until a
  later record replaces it. (+0x1D0, the floor, is read: 3a.) Whether models stay loaded beyond the
  game's distance (read 26 Nov, every instruction of the game that touches an actor's +0xB2): the distance bit gates
  work only: the draw list (`CXiActorDraw::UpdateDrawList`), names, lights (`Actor_SelectNearestLights`), the parts
  (`CXiSkeletonActor::ForParts0To9`), head look, effect generators whose caster or target is beyond (0x100575A0,
  0x10057840/0x1005785F) and spawning the actor's resource generators (`CXiActor::SpawnResourceGenerators`,
  0x1008507C). None of them frees or unloads anything, so a model beyond the distance stays loaded; what does release
  an actor is not this flag.
- Other copies of the view (read 25 Nov; 26 Nov, the whole game scanned): every function in the tree that reads the
  view does it through `CDx::GetTransformCached` (0x1000BDB0), the copy `Camera_ApplyViewProjection` sets each frame;
  nine calls in five functions without source read the same copy (0x1006A4A0, 0x100AC390, 0x100C4CE0, 0x100C63D0,
  0x1017B510). Calls of the device's own `GetTransform` (slot +0x98 with the device `[[0x1045666C] + 0xC]` pushed):
  four, all for D3DTS_PROJECTION (3, d3d8types.h), none for the view: `XiZone::DrawGroundShadowQuad`,
  `CTsZoneMap::DrawProjectedShadow`, `XiZone::DrawDecalOnTriangles`, `YmElem_SetupDevice`. The other 11 calls through
  a slot +0x98 in functions without source pass a game object in ecx (the game's own methods), not the device. So
  no code reads the view another way.
- Whether other tools running in the game (Windower, Ashita) write the same camera fields: their code is closed; the
  owner's run with and without Windower (kit/sessions/ltp_25nov R6) is the test.
