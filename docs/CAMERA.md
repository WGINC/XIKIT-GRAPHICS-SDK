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
two opcodes always gets a new zone object and the 43.0 floor.

What that interpreter's scripts are, read 27 Nov (disassembly):
- **The interpreter is the zone's event system.** One interpreter object (0x268 bytes) per actor, at actor + 0xD4,
  made by 0x1008EDC0 and set up by 0x100BD1A0 from one block of an event file: +4 the number of events (word, kept at
  +0xC), then that many 16-bit entry offsets (+0x10), that many 16-bit event numbers (+0x14), a count and a table of
  4-byte values (+0x18, +0x1C), and the byte code after it (+0x20).
- **The event file is one per event key.** 0x100AEB80 loads it with `FileMng` 0x101C4820 and keeps it at [0x10489904].
  Its file number comes from the zone key:
  - key + 0x16BC below 0x100;
  - key + 0x14AFF for 0x100 .. 0x3E7;
  - key + 0xDE31 for 0x3E8 .. 0x7CF;
  - key + 0x1004B from 0x7D0.
  - Whether the key is the zone's number is not read (see below for where it comes from). If it is, zone 118
    (Buburimu Peninsula) would have event file 5938, which is ROM\20\55.DAT by the owner's tables.
- **The zone's dialogue file is loaded beside it.** 0x100AE1E0 loads it as file table 0x6B..0x6E[key] (0x1025B560)
  and keeps it at [0x10489908].
- **One block of the event file per actor.** 0x100AEEA0 walks the file (a count, then a size per block) and gives
  each block to the actor it names (0x100AF180, 0x100BD130), which then gets its interpreter.
- **What starts an event:**
  - **Zone setup:** 0x100AED00 sets up a zone's events and takes the event number it should run first into
    [0x104886dc]. At the first step 0x100BCDD0 runs the entry whose event number is that one, or else the entry
    numbered 0xFFFE.
  - **Another script:** 0x100B3A50, opcode 0x7A of the interpreter itself (jump table entry 0x7A, 0x100BC65F), starts an event of
    another actor through 0x100B3CC0 and 0x100B37D0. 0x100B37D0 sets the pending event at +0x224, and 0x100BD0E0
    moves it into slot 0.
  - **Each step:** 0x100BCD10 runs the slot with the lowest priority word among 16 slots at +0x24.
- **Where the zone setup's inputs come from:**
  - 0x100AED00 is called from the event system's step 0x10096640, with values from the game state block
    [0x104dfd98] + 0x40D90, 0x40D92, 0x40D8E and 0x3C35A.
  - (28 Nov, disassembly; RESEARCH F4; corrected the same day) the key: at 0x100967DD the four arguments are, in order,
    the game state words +0x40D90, +0x40D92, +0x40D8E and +0x3C35A. In 0x100AED00 (0x100AEDEE..0x100AEE1D): when the
    fourth is 0x3E8..0x513, the key is the fourth + 0x3E8; otherwise, when the first equals the third, the key is the
    first; otherwise the third + 0x3E8.
  - **Where those words come from (not published):** +0x40D90 = message +0x62, +0x40D92 = +0x64, +0x40D8E = +0x66, +0x3C35A = +0x9E, and the zone change's
    number +0x40D80 = message +0xAA (also +0x3C350 = the dword at +0x30, +0x40D7C = +0x42). Windower's field list
    (addons/libs/packets/fields.lua, a lead) calls +0x30 "Zone", +0x42 "_dupeZone", +0x62 "Menu Zone" ("only set if
    the menu ID is sent"), +0x64 "Menu ID", +0x66 unknown and +0xAA "Zone model". So **the event key is not the zone
    number field**: it is made from +0x62, +0x66 and +0x9E as above; the zone's resource file comes from +0xAA. Whether
    those hold the zone's number in a given zone is the server's choice; the probe logging the message's +0x30, +0x62,
    +0x66, +0x9E and +0xAA would show it.
  - The code that writes those values, and three more callers of 0x100AED00, are left out of the public kit
    (security set).
  - The zone key is the first value when it equals the third, else the third + 1000. When the fourth is in
    1000 .. 1299, the key is the fourth + 1000.
- **So opcodes 0x34 and 0x35 run when an event in the zone's event file reaches them.** That includes the zone's
  first event at setup, and events started by other events.
- **Which events hold them is not read.** It needs the zone event files, which the owner has not sent (none of the
  416 game files received is an event file of a known zone), and the length of every opcode, so the code can be walked
  from each entry.
- **The opcodes' lengths (28 Nov, `pipeline/event_opcode_lengths.py`, its output `data/event_opcodes.txt`).** For each of
  the 219 handlers, what it does to the program counter (+0x256): 169 add one constant (0x34 and 0x35 add 3); 10 add
  one of several constants by a branch (0x1F: 2 or 8; `EventOp_LoadWeather` 4, 6 or 10 by the byte after the opcode);
  25 store a computed value (jumps, and lengths read from the code: 0x01, 0x02, 0x1A, 0x1B among them); 18 change
  nothing in themselves or their direct callees (0x00, 0x21, 0x26, 0x7A among them: waits, the end, or a counter
  moved deeper than the scan follows). A walk of an event file can take the 169 as they are; the other 53 need their
  handlers read one by one (their addresses are in the file). The event files themselves: `pipeline/collect_event_files.py`
  copies the player's own into one zip.
- **The walk (28 Nov, `pipeline/event_walk.py` on the owner's files; its output `data/event_walk_28nov.txt`).** Of
  the 1,190 files the script took (every key 0..0xFFF), 334 are event files: all 256 keys below 0x100, and 78 above
  (the other 856 numbers hold other files; their block sizes do not add up). Their 217,392 events were walked through
  the 169 fixed-length opcodes and the control opcodes read from their handlers (0x01 jump, 0x02 branch, 0x1A call,
  0x1B return, 0x21 wait, 0x1F's two sub-codes), every reachable point once:
  - **679 events reach 0x34 or 0x35**, in 84 files (keys and files listed in the output), so those are the zone
    events that release the zone object and change the zone (533 before 0x3E, 0x43, 0x5B and 0x66 were read: 0x43
    is 2 bytes, 0x5B and 0x66 15, 0x3E a branch to pc+7 or the word at pc+5);
  - 185,900 have every path end (0x00, 0x1B, 0x21) without reaching them: they do not;
  - 30,813 reach an opcode the walk cannot step over before reaching either (0x9D, 0xB6, 0x47, 0xCC, 0xB4, 0x59 most):
    open. Those handlers switch on a sub-code with cases that fall into one another (0xCC, 0x71: eight or more
    cases each) or compute a length (0x9D); each needs its cases read exactly, as a wrong length would mislead the
    walk both ways.
  Which events are which in the game (a cutscene, a door, a mog house exit) is not read: the event numbers are given.

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
  `YmCombineWeather::Release` and 0x101873A0 set others. **Their source, read 28 Nov (RESEARCH F3):** the weather
  message **0x057** (not published) stores its +4 dword at 0x104807F8, its +8 word (the
  weather) at 0x104807F0 and its +0xA word at 0x1047FAAC, and sets 0x104807F6. Each frame `game_1009F2F0` (from
  `Acter_UpdateFrame` 0x10096BBE), when 0x104807F6 is set and 0x10487E48 is not, copies the weather to 0x10485FE0,
  sets the clock (0x1018D1B0 with [0x104819A8] x 60, `Time_Normalize` with the hour [0x10480C5C] x 3600; running-build
  addresses), takes the zone's weather record **[XiZone + 0x1D8] + 4 x weather** and hands it to 0x10188AC0, which,
  when it differs from the current one, releases the current blends (`YmCombineWeather::Release`) and makes a new one
  (0x1018BD70), then clears 0x104807F6. `XiZone::SetPtr1D8FromTable` sets +0x1D8 to one of two constant tables
  (pointers at 0x10377C58, analysed): **20 four-character names by weather number**, `fine suny clod mist dryw heat
  rain squl dust sand wind stom snow bliz thdr bolt aura ligt fogd dark`, and the same with a final `1` (`fin1 sun1
  ...`). So the zone's weather is the resource of that name in the zone's data, picked by the server's weather number.
  A mod could ask the client's own path for another weather by writing 0x104807F0 and setting 0x104807F6 (untested:
  the server's next 0x057 sets it back).
  **The time of day the light is blended for (read 28 Nov, Ghidra on 6AE818B4's `Zone_GetClock` and
  `Env_BlendTimeOfDay`; RESEARCH F2):** `Zone_GetClock` gives **XiZone + 0x1C8 when it is 0 or more and the byte
  g_pCamera + 9 is set, otherwise the game's clock at 0x1065CB18** (analysed). The clock counts 1/60 s of game time:
  `Time_GetModulo3600Div60` minutes, `Time_GetModulo216000Div3600` hours, `Time_GetModulo5184000Div216000` days of a
  30-day month, `Time_SetModulo155520000Div5184000` months; a day is 0x4F1A00 (5,184,000). `Env_BlendTimeOfDay` keeps
  the zone's two weather records whose time keys (`WeatherRes_GetTimeKey`: the four-digit ids, 0000..2100) are at or
  before and after that time, and blends them by where the time falls between the keys, wrapping at a day. So a mod
  can hold the light's time of day by setting XiZone + 0x1C8 (in 1/60 s since midnight) while g_pCamera + 9 is set;
  what else reads +0x1C8 is not read. **g_pCamera + 9** (read 28 Nov, `Frame_Render`'s state switch, kit/speedfix's fork
of it, lines ~288-350): set to 1 when the game's scene starts (after `Game_InitSceneState`, or when the lobby hands
over, `App_GetGlobal_104569C8`), and to 0 when the application setting +40 is 0; so it is 1 while you play.
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
