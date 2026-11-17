# ZoneMapLoad

Group: `Zone` (by the file name only). Source: `sdk/tree_src/ZoneMapLoad.cpp`.

Why the file has this name (data/unit_names.json): ParseZoneMeshData, the ZoneMap_* constructors and lookups, the debug boxes (Dbg_DrawOrientedBoxes) (an address range between two evidenced source files, holding several of the original files: named for its main contents)

49 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ZoneMapLoad_ResetFieldsA` | 0x10163F30 | 55 | yes | - | Resets a block of fields at fixed offsets to zero and sets one flag word to 0x1E. | low |
| `ZoneMapLoad_ResetFieldsB` | 0x10163FA0 | 82 | yes | - | Resets a block of fields at offsets +0xA78 to +0xAA8. | low |
| `ZoneMapLoad_ConstructVt10335CE8` | 0x101641B0 | 38 | yes | - | Constructs the object: sets its vtable to PTR_FUN_10335ce8 and initialises its fields. | medium |
| `ZoneMapLoad_InitA640AndCopyStar` | 0x10164530 | 43 | yes | - | Sets the two dwords at +0xA640/+0xA644 to -1 and copies the string '*-0' to +0xA754, then continues into 0x103108DE. | low |
| `ZoneMapLoad_ResetFieldsC` | 0x10164560 | 31 | yes | - | Resets a small set of fields and sets +0x14 to 1. | low |
| `ZoneMapLoad_ConstructVt10335D30` | 0x10164660 | 55 | yes | - | Constructs the object: sets its vtable to PTR_FUN_10335d30 and initialises its fields. | medium |
| `ZoneMapLoad_ResetFieldsD` | 0x10164800 | 46 | yes | - | Clears a large block from +0x34 and sets two bytes to 0xFF. | low |
| `ZoneMapLoad_ResetFieldsE` | 0x10164980 | 25 | yes | - | Resets five fields and sets +0x2C to 1. | low |
| `ZoneMapLoad_ConstructVt10335D78` | 0x10164A30 | 38 | yes | - | Constructs the object: sets its vtable to PTR_FUN_10335d78 and initialises its fields. | medium |
| `ZoneMapLoad_ConstructVt10335DC0` | 0x10164AF0 | 39 | yes | - | Constructs the object: sets its vtable to PTR_FUN_10335dc0 and initialises its fields. | medium |
| `ZoneMapLoad_CreateUiObjects` | 0x10165070 | 4543 | yes | - | Creates and constructs the game's UI objects (menus, cursor, target manager, help, title, chat lists, ...) at scene start. | medium |
| `ZoneMapLoad_InitGlobalTables` | 0x101671D0 | 326 | yes | - | Looks up the mesh resource tables by tag and clears their memory. | low |
| `ZoneMapLoad_Call10257860ReturnSelf` | 0x10167330 | 12 | yes | - | Calls sub_10257860 on this object and returns the object. | medium |
| `ZoneMapLoad_LoadSceneFileAndBind` | 0x10167340 | 144 | yes | - | Reads the scene's file (table entry 0x14) into a new buffer, checks it against a constant string and binds the table to the buffer if it matches. | medium |
| `ZoneMap_ConstructVt10336614` | 0x10167440 | 71 | yes | - | Constructs the zone map sub-object: sets its vtable, initialises its entry array and clears its fields. | medium |
| `ZoneMap_ConstructVt10336634` | 0x10167800 | 171 | yes | - | Constructs the zone map sub-object: sets its vtable, clears its fields and fills its tables with default values. | medium |
| `ZoneMap_ReleaseBuffers` | 0x10167950 | 67 | yes | - | Frees three buffers and clears the block that holds them. | low |
| `ZoneMap_UnlinkSlotCells` | 0x101679A0 | 303 | yes | - | Removes a slot's entries from the zone map's cell lists. | medium |
| `ZoneMapLoad_GetField34148` | 0x10168FC0 | 7 | yes | - | Returns the zone map's value at +0x34148 (the kind of the last hit, as its callers use it). | low |
| `ZoneMap_GetCount34154` | 0x10168FD0 | 7 | yes | - | Returns the value at +0x34154. | low |
| `ZoneMapLoad_ProbeAxis1` | 0x10169290 | 288 | yes | - | Probes along the second coordinate from a point and moves the output point to the hit; which way is up is not established. | low |
| `ZoneMapLoad_SegmentHit3413A` | 0x101693B0 | 1932 | yes | - | Tests the segment param_1..param_2 against the grid triangles and stores the hit point and triangle data; gated by the flag at +0x3413A. | low |
| `ZoneMapLoad_SegmentHit34139` | 0x10169B40 | 1932 | yes | - | Tests the segment param_1..param_2 against the grid triangles and stores the hit point and triangle data; gated by the flag at +0x34139. | low |
| `ZoneMapLoad_SegmentTest34139` | 0x1016A2D0 | 1719 | yes | - | Tests the segment against the grid triangles and returns whether it hits, recording only the hit triangle's flags. | low |
| `ZoneMapLoad_SegmentHitGridTriangles` | 0x1016A990 | 2103 | yes | - | Tests a segment against the zone map's triangles in the grid cells it passes and returns the nearest hit. | medium |
| `ZoneMapLoad_SegmentHitWithObjects` | 0x1016B1D0 | 3096 | yes | - | Segment test against the grid triangles that also consults objects through g_C_106631D4; what the objects are is not established. | low |
| `fn_1016BDF0` | 0x1016BDF0 | 618 | yes | - | - | - |
| `Mat44_Multiply` | 0x1016C060 | 231 | yes | - | - | - |
| `ZoneMap_GetHitCount` | 0x1016C150 | 7 | yes | - | Returns the value at +0x1807C, which the zone-map queries reset to zero. | low |
| `ZoneMap_IsPointInTriangle` | 0x1016C390 | 559 | yes | - | Returns whether a point lies inside a triangle of the zone map's record. | medium |
| `ZoneMapLoad_SegmentHitObjectTriangles` | 0x1016C5D0 | 1410 | yes | - | Tests a segment against one object's triangles in the zone map (in the object's frame) and gives the hit. | low |
| `ZoneMapLoad_TriangleNormal` | 0x1016CB60 | 237 | yes | - | Computes the unit normal of a triangle and stores it when asked; false for a degenerate triangle. | medium |
| `Dbg_DrawTriangleLines` | 0x1016DDF0 | 465 | yes | 0 | - | - |
| `ZoneMapLoad_SweepSetupAndTest` | 0x1016E930 | 1967 | yes | - | Sets up a swept test between two points and runs it against the grid and objects; the exact shape swept is not established. | low |
| `ZoneMapLoad_SweepStep` | 0x1016F0E0 | 575 | yes | - | Inner loop of the swept test of fn_1016E930: steps through the set-up basis calling sub_1016F320; +0x34130/+0x34134 start at 9999999.0f. | low |
| `ZoneMap_ConstructVt10336668` | 0x1016FC40 | 18 | yes | - | Constructs the zone map sub-object: sets its vtable and runs its base initialisation. | medium |
| `ZoneMapLoad_ClearListFields` | 0x1016FC90 | 12 | yes | - | Clears the list's head, tail and count. | low |
| `ParseZoneMeshData` | 0x1016FCD0 | 3660 | yes | 0 | - | - |
| `ZoneMapLoad_FreeNodeOrAll` | 0x10170CD0 | 425 | yes | - | Frees one node of the list (or all of them), calling slot +8 on every object its entries hold and freeing its arrays. | medium |
| `ZoneMap_FindEntryByName` | 0x10170F30 | 158 | yes | - | Finds a list entry by its 16-byte name, optionally only among entries with a flag set. | medium |
| `ZoneMap_ConstructVt1033668C` | 0x101718E0 | 18 | yes | - | Constructs the zone map sub-object: sets its vtable and resets its debug box list. | medium |
| `ZoneMap_FindDbgBoxMPosById` | 0x10173AE0 | 103 | yes | - | Finds the 'M' entry with the given id in the zone's box list and returns its position. | medium |
| `ZoneMap_ResetDbgBoxList` | 0x10174770 | 30 | yes | - | Clears the debug box list globals and the object's list fields. | medium |
| `ZoneMap_FreeDbgBoxList` | 0x10174A60 | 165 | yes | - | Frees the zone's box list (nodes, entry arrays, entry data) and the two buffers of the zone map, and resets the list. | high |
| `Dbg_DrawOrientedBoxes` | 0x10174EC0 | 2166 | yes | 0 | - | - |
| `Mat4_SetIdentity_2` | 0x10175740 | 59 | yes | - | - | - |
| `ZoneMap_FindDbgBoxHitBySegment` | 0x10176620 | 635 | yes | - | Returns the first '@' box of the zone that the segment between two points touches, or 0. | medium |
| `ZoneMapLoad_SetFlag2000OnUnderscoreEntries` | 0x10176DD0 | 162 | yes | - | Sets or clears flag 0x2000 on the elements of every '_'-named entry in the lists from sub_10621A08. | low |
| `ZoneMapLoad_ConstructResource10336698` | 0x10176E80 | 25 | yes | - | Constructs the resource object whose vtable is at 0x10336698. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ZoneMapLoad_ResetFieldsA` calls nothing directly
- `ZoneMapLoad_ResetFieldsB` calls nothing directly
- `ZoneMapLoad_ConstructVt10335CE8` calls `NetCellFont_ClearWords`
- `ZoneMapLoad_InitA640AndCopyStar` calls `sub_103108DE`
- `ZoneMapLoad_ResetFieldsC` calls nothing directly
- `ZoneMapLoad_ConstructVt10335D30` calls `NetCellFont_ClearWords`
- `ZoneMapLoad_ResetFieldsD` calls nothing directly
- `ZoneMapLoad_ResetFieldsE` calls nothing directly
- `ZoneMapLoad_ConstructVt10335D78` calls `NetCellFont_ClearWords`
- `ZoneMapLoad_ConstructVt10335DC0` calls `NetCellFont_ClearWords`
- `ZoneMapLoad_CreateUiObjects` calls `TargetMenu_GetInstance`, `TargetMenu_LoadMessageSet`, `MenuMng_Init`, `Camera_GetWord16`, `Camera_GetWord14`, `Allocator_Generic`, `TargetMenu_CtorVt10335334`, `TargetMenu_CtorVt10334F18`, `TargetMenu_ConstructVt10333D10`, `TargetMenu_ConstructVt10333D18`, `TargetMenu_CtorVt10334F78`, `NetCellFont_ClearWords`, `TargetMenu_SetCopy`, `Cursor_Init`, `TargetMenu_ConstructVt10333728`, `TargetMenu_ClearThenSetGlobal`, `TargetMenu_ConstructVt103337E0`, `TargetMenu_ConstructVt10333898`, `NetCellFont_Construct`, `TargetMenu_TargetCtor`, `TargetMenu_ConstructVt10333B68`, `TargetMenu_ConstructVt10333BB0`, `TargetMenu_FillSceneTable`, `TargetMenu_CtorVt10333E20`, `TargetMenu_CtorVt10333E70`, `TargetMenu_CtorVt10333DD8`, `TargetMenu_InitFromShape`, `TargetMenu_CtorVt10334928`, `TargetMenu_CtorVt10335060`, `NetCellFont_Clear`, `TargetMenu_IsAlwaysTrue`, `TargetMenu_CreateAll`, `LobbyThread_CtorVt1033CCA8`, `TargetMenu_ConstructVt103335E8`, `TargetMenu_CtorVt10334D00`, `TargetMenu_CtorVt10334E58`, `TargetMenu_CtorVt10333D78`, `TargetMenu_CtorVt10334070`, `TargetMenu_CtorVt10334DC0`, `TargetMenu_CtorVt10333F28`, `TargetMenu_ConstructVt10333CB0`, `TargetMenu_CtorVt10335410`, `TargetMenu_CtorVt10335470`, `TargetMenu_ConstructVt10333A40`, `TargetMenu_ConstructVt10333A90`, `TargetMenu_ConstructVt10333950`, `TargetMenu_ConstructVt103339A0`, `NetCellFont_ChatListCtorA`, `NetCellFont_ChatListCtorB`, `TargetMenu_CtorZeroed`, `TargetMenu_ConstructVt10333500`, `TargetMenu_ConstructVt103333C8`, `TargetMenu_ConstructVt10333410`, `TargetMenu_ConstructVt10333458`, `TargetMenu_ConstructVt103334A0`, `TargetMenu_CtorVt10334EB8`, `TargetMenu_CtorVt10334D60`, `TargetMenu_TableHolderCtor`, `ZoneMapLoad_Call10257860ReturnSelf`, `TargetMenu_LoadTable`, `ZoneMapLoad_LoadSceneFileAndBind`, `FaqHelp_ResetEntries`, `TextInputFiles_AssignCStr`, `TextInputFiles_AssignWhole`, `KeyPrompt_Construct`, `TargetMenu_CtorVt10334260`, `TargetMenu_CtorVt103340D0`, `YkWindows_CtorVt10339E48`, `TargetMenu_CtorVt10334200`, `StDancer_Init`, `TargetMenu_SetMinId6C`
- `ZoneMapLoad_InitGlobalTables` calls `ResourceIter_Start`, `MenuPanels_RotateBytesByBitCount`, `MenuPanels_GetSingleton`, `MenuPanels_LoadMessageTable`, `MenuPanels_GetObjectOnce`, `MenuPanels_LoadFromFile`, `MenuPanels_GetObject106670C8Once`, `MenuPanels_LoadDMsgTable`
- `ZoneMapLoad_Call10257860ReturnSelf` calls `sub_10257860`
- `ZoneMapLoad_LoadSceneFileAndBind` calls `Scene_GetTableValue`, `FileMng_ResolveOrExit`, `Allocator_Generic`, `TextInputFiles_ForwardOrExit`, `DmsgText_GetDMsgTable`, `DmsgText_Assign`
- `ZoneMap_ConstructVt10336614` calls `VectorCtorIterator_CallForEachElement`
- `ZoneMap_ConstructVt10336634` calls nothing directly
- `ZoneMap_ReleaseBuffers` calls `Mem_FreeObject`
- `ZoneMap_UnlinkSlotCells` calls `sub_10311C2C`
- `ZoneMapLoad_GetField34148` calls nothing directly
- `ZoneMap_GetCount34154` calls nothing directly
- `ZoneMapLoad_ProbeAxis1` calls `ZoneMapLoad_SegmentHitGridTriangles`, `ZoneMapLoad_SegmentHit34139`
- `ZoneMapLoad_SegmentHit3413A` calls `sub_10311C2C`, `ZoneMap_IsPointInTriangle`
- `ZoneMapLoad_SegmentHit34139` calls `sub_10311C2C`, `ZoneMap_IsPointInTriangle`
- `ZoneMapLoad_SegmentTest34139` calls `sub_10311C2C`, `ZoneMap_IsPointInTriangle`
- `ZoneMapLoad_SegmentHitGridTriangles` calls `sub_10311C2C`, `ZoneMap_IsPointInTriangle`
- `ZoneMapLoad_SegmentHitWithObjects` calls `sub_10311C2C`, `ZoneMap_IsPointInTriangle`, `TextInputFiles_GetSetting99`, `MyRoom_Is104DFD98Bit40DB1x10Clear`, `sub_10085240`, `CYyObject_IsKindOf`, `ModelActorDraw_GetVec3PairIfModel`, `ZoneMapLoad_SegmentHitObjectTriangles`, `sub_10085270`
- `fn_1016BDF0` calls `Mat44_Multiply`
- `Mat44_Multiply` calls nothing directly
- `ZoneMap_GetHitCount` calls nothing directly
- `ZoneMap_IsPointInTriangle` calls nothing directly
- `ZoneMapLoad_SegmentHitObjectTriangles` calls `fn_1016BDF0`, `ZoneMapLoad_TriangleNormal`, `ZoneMap_IsPointInTriangle`
- `ZoneMapLoad_TriangleNormal` calls nothing directly
- `Dbg_DrawTriangleLines` calls `CDx::DrawPrimitiveUP`
- `ZoneMapLoad_SweepSetupAndTest` calls `sub_1016FA20`, `sub_10311C2C`, `sub_1016C5C0`, `sub_1016DFD0`, `MyRoom_Is104DFD98Bit40DB1x10Clear`, `sub_10085240`, `CYyObject_IsKindOf`, `ModelActorDraw_GetVec3PairIfModel`, `sub_1016D580`, `sub_10085270`, `ZoneMapLoad_SweepStep`
- `ZoneMapLoad_SweepStep` calls `sub_1016F320`
- `ZoneMap_ConstructVt10336668` calls `ZoneMapLoad_ClearListFields`
- `ZoneMapLoad_ClearListFields` calls nothing directly
- `ParseZoneMeshData` calls `sub_10170C80`, `sub_10170E80`, `Mem_AllocObject`, `Util_Copy16Bytes`, `sub_1003ADC0`, `sub_1003AD40`, `sub_1003ACD0`, `sub_10170B30`
- `ZoneMapLoad_FreeNodeOrAll` calls `ZoneMapLoad_ClearListFields`, `Mem_FreeObject`
- `ZoneMap_FindEntryByName` calls `sub_10312940`
- `ZoneMap_ConstructVt1033668C` calls `ZoneMap_ResetDbgBoxList`
- `ZoneMap_FindDbgBoxMPosById` calls nothing directly
- `ZoneMap_ResetDbgBoxList` calls nothing directly
- `ZoneMap_FreeDbgBoxList` calls `Mem_FreeObject`, `ZoneMap_ResetDbgBoxList`
- `Dbg_DrawOrientedBoxes` calls `Mat4_SetIdentity_2`, `Mat44_Multiply`, `sub_10175780`, `CDx::DrawPrimitiveUP`, `Actor_DrawWorldText`
- `Mat4_SetIdentity_2` calls nothing directly
- `ZoneMap_FindDbgBoxHitBySegment` calls `sub_101768A0`
- `ZoneMapLoad_SetFlag2000OnUnderscoreEntries` calls nothing directly
- `ZoneMapLoad_ConstructResource10336698` calls `CMoResource_ConstructBase`
