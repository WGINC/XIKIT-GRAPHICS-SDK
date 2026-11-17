# YkWindows

Group: `Yk` (by the file name only). Source: `sdk/tree_src/YkWindows.cpp`.

Why the file has this name (data/unit_names.json): Yk_* (the window lists), YkWndItem_Open, YkWndList_Init, YkWndShop_Constructor, the menus "link*", "mapframe", "msgline", "money" (an address range between two evidenced source files, holding several of the original files: named for its main contents)

159 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `YkWindows_CtorVt10338670` | 0x101D7C10 | 87 | yes | - | Constructs the Yk object with vtable 0x10338670 (0x10663428). | low |
| `YkWindows_CtorVt10338700` | 0x101D87A0 | 30 | yes | - | Constructs the Yk object with vtable 0x10338700 (0x1066342C). | low |
| `Yk_CreateCommonObjects` | 0x101D9B10 | 842 | yes | - | Creates the common global objects the Yk subsystem uses. | low |
| `YkWindows_CtorVt10338BE8` | 0x101D9E90 | 38 | yes | - | Constructs an object with vtable 0x10338BE8. | low |
| `YkWindows_CtorVt10338D88` | 0x101DC460 | 176 | yes | - | Constructs the Yk object 0x10663468 and its three shared helpers. | low |
| `Yk_CreateSecondaryObjects` | 0x101DCE20 | 186 | yes | - | Creates a second set of global Yk objects. | low |
| `YkWindows_CtorVt10338E60` | 0x101DD000 | 63 | yes | - | Constructs the object 0x10663484 with its seven slots. | low |
| `Yk_InitSlots` | 0x101DDA70 | 23 | yes | - | Initialises seven slots of a Yk object. | low |
| `YkWindows_ClearSlotBytes3` | 0x101DDA90 | 34 | yes | - | Clears three bytes 0x29 apart in the 0x7B-byte slot the argument selects. | low |
| `YkWindows_CtorVt10338EA4` | 0x101DDF90 | 20 | yes | - | Constructs the small object 0x10663488. | low |
| `YkWindows_CtorVt10338ED4` | 0x101DE6B0 | 20 | yes | - | Constructs the small object 0x1066348C. | low |
| `YkWindows_CtorVt10338F68` | 0x101DEDC0 | 113 | yes | - | Constructs the Yk object 0x10663494 and its helper. | low |
| `YkWndList_Init` | 0x101DF210 | 459 | yes | - | Initialises the window list with its line objects and layout. | medium |
| `YkWindows_ClearFields14To3F` | 0x101E06C0 | 52 | yes | - | Zeroes the object's fields from +0x14 through the ten-entry arrays at +0x15, +0x22 and +0x36. | low |
| `YkWindows_ClearFields40To48` | 0x101E0700 | 15 | yes | - | Zeroes the two dwords at +0x40 and +0x44 and the word at +0x48. | low |
| `YkWindows_CtorVt10339250` | 0x101E0A90 | 342 | yes | - | Constructs the object 0x106634AC and its helpers. | low |
| `YkWindows_LoadDatListOrRun101E1A70` | 0x101E11C0 | 63 | yes | - | Depending on its two flags, loads the dat list of the object at 0x106634B8 or runs 0x101E1A70 on it, then clears this+0x74. | low |
| `YkWindows_IsWithin23Seconds` | 0x101E15C0 | 21 | yes | - | Returns whether fewer than 23 seconds have passed since the time stored at +0x74. | medium |
| `YkWindows_ClearField74` | 0x101E15F0 | 8 | yes | - | Clears the field at +0x74. | low |
| `Yk_ClearEntries` | 0x101E1A00 | 74 | yes | - | Clears a table of ten entries. | low |
| `YkWindows_LoadDatListSync` | 0x101E1AE0 | 44 | yes | - | Walks the list of dat entries from this and loads each pending one synchronously, marking a loaded one 2. | medium |
| `YkWindows_LoadDatSync` | 0x101E24F0 | 91 | yes | - | Loads the .dat file chosen by param_1 into this object synchronously through a temporary dat entry. | medium |
| `YkWindows_CtorVt10339298` | 0x101E2B10 | 18 | yes | - | Constructs an object with vtable 0x10339298 on the 0x101EBE00 base. | low |
| `YkWindows_CtorVt103394C0` | 0x101E3F50 | 491 | yes | - | Constructs the Yk object 0x10663520 and its eight helpers. | low |
| `YkWindows_CtorVt10339530` | 0x101E48F0 | 38 | yes | - | Constructs the helper 0x10663554. | low |
| `YkWindows_CtorVt10339698` | 0x101E4A20 | 292 | yes | - | Constructs the Yk object 0x10663524 and its four helpers. | low |
| `YkWindows_CtorVt10339728` | 0x101E51B0 | 60 | yes | - | Constructs the helper 0x10663528 with its three colours. | low |
| `YkWindows_CtorVt10339770` | 0x101E5750 | 42 | yes | - | Constructs the helper 0x1066352C. | low |
| `YkWindows_CtorVt103397B8` | 0x101E5BA0 | 51 | yes | - | Constructs a helper with vtable 0x103397B8. | low |
| `Yk_CtorVt10339BC0` | 0x101E6FB0 | 1429 | yes | - | Constructs the Yk object: base window, its vtable, its message tables and 13 helper objects. | medium |
| `YkWindows_AttachTwoWindows` | 0x101E7E90 | 55 | yes | - | Attaches and positions two of the interface windows. | low |
| `YkWindows_CtorVt10339D78` | 0x101EB390 | 293 | yes | - | Constructs the Yk object 0x10663684 and its helpers. | low |
| `YkWindows_CtorVt10339DE8` | 0x101EB7E0 | 90 | yes | - | Constructs the helper 0x10663688 with two values from 0x101C8C30's entries. | low |
| `YkWindows_CtorVt10339E48` | 0x101EBE00 | 69 | yes | - | Constructs the Yk object 0x1066369C and its helper. | low |
| `YkWindows_CtorVt10339EB8` | 0x101EC0D0 | 56 | yes | - | Constructs the helper 0x106636A0. | low |
| `YkWindows_InitFields1CTo3C` | 0x101EC3C0 | 37 | yes | - | Sets the two words at +0x1C/+0x1E to -1 and zeroes the fields from +0x20 to +0x3C. | low |
| `YkWindows_CtorVt10339FA0` | 0x101ED450 | 195 | yes | - | Constructs the object 0x106636AC and its three helpers. | low |
| `YkWindows_UpdateScreenTransform` | 0x101EE040 | 491 | yes | - | Recomputes the window's offset and scale for drawing from its position and the screen rectangle. | low |
| `YkWindows_CtorVt1033A000` | 0x101EE230 | 405 | yes | - | Constructs a window object of a given size scaled to the screen. | low |
| `YkWindows_SetFlag20AndValues` | 0x101EFAD0 | 43 | yes | - | Marks the object (flag 0x20) and stores two values. | low |
| `YkWindows_SetFlag20Default` | 0x101EFB10 | 16 | yes | - | Marks the object with the default values 0xFF. | low |
| `Yk_ResetFields` | 0x101EFCA0 | 90 | yes | - | Resets a group of fields to their defaults. | low |
| `YkWindows_ClearSixFlags` | 0x101EFEA0 | 18 | yes | - | Clears the flag byte of six entries. | low |
| `YkWindows_Return8` | 0x101EFFD0 | 6 | yes | - | Returns 8. | low |
| `YkWindows_GetTable103820B0` | 0x101EFFE0 | 12 | yes | - | Returns an entry of the table at 0x103820B0. | low |
| `YkWindows_CtorVt1033A5D8` | 0x101F17C0 | 859 | yes | - | Constructs the Yk object 0x10663740 and its helpers. | low |
| `YkWndItem_Open` | 0x101F23A0 | 531 | yes | - | - | - |
| `YkWindows_GetItemEntryState` | 0x101F35A0 | 263 | yes | - | Fills seven output values describing an entry of the list at 0x10621808. | low |
| `YkWindows_CtorVt1033A6D0` | 0x101F43F0 | 93 | yes | - | Constructs the object 0x10663784 and its helper. | low |
| `YkWindows_InitEightSlots80808080` | 0x101F4AF0 | 42 | yes | - | Initialises eight slots (a flag byte, a dword 0 and a dword 0x80808080 each) and clears +0x48..+0x50. | low |
| `YkWindows_SetSlot` | 0x101F4B20 | 52 | yes | - | Sets one of the object's eight slots (a kind and two values). | low |
| `YkWindows_ClampListScroll` | 0x101F66B0 | 69 | yes | - | Keeps the list's visible range inside its item count. | medium |
| `YkWindows_SetField18AndRemainder` | 0x101F6700 | 31 | yes | - | Stores the argument at +0x18 and the non-negative difference of +0x20 and it at +0x22. | low |
| `YkWindows_ShowSelectedHelp` | 0x101F6720 | 148 | yes | - | Shows the help text of the list's selected item. | medium |
| `Yk_InitBase` | 0x101F67C0 | 124 | yes | - | Initialises the base fields shared by the Yk objects. | medium |
| `YkWindows_ReadRectAndShowHelp` | 0x101F68F0 | 74 | yes | - | Stores the window's position and shows the selected item's help. | low |
| `YkWindows_SetListItems` | 0x101F7020 | 94 | yes | - | Gives the list its items and count and keeps its view and help text right. | medium |
| `YkWindows_SelectListIndex` | 0x101F7080 | 123 | yes | - | Scrolls the list to an index and moves the cursor there. | medium |
| `YkWindows_GetSelectedIndex` | 0x101F7100 | 24 | yes | - | Returns the index of the list item under the cursor, or -1. | medium |
| `YkWindows_GetValueIfLoaded` | 0x101F71A0 | 18 | yes | - | Returns the value at 0x106637E0 once the table is loaded. | low |
| `Yk_GetSharePercent` | 0x101F71C0 | 54 | yes | - | Returns a percentage share of two table entries. | low |
| `YkWindows_GetEntryFieldA` | 0x101F7200 | 26 | yes | - | Returns the first value of a 16-byte table entry once loaded. | low |
| `YkWindows_GetEntryFieldB` | 0x101F7240 | 26 | yes | - | Returns the third value of a 16-byte table entry once loaded. | low |
| `YkWindows_GetEntryFieldBPercent` | 0x101F7260 | 35 | yes | - | Returns a table value as a percentage of 15000. | low |
| `Yk_FindEntryIndex` | 0x101F7430 | 80 | yes | - | Finds the index of an entry matching a key in the Yk table. | low |
| `YkWindows_GetEntryCode` | 0x101F7480 | 96 | yes | - | Returns a code for an entry from its kind nibble and number. | low |
| `YkWindows_TestFlagBitFwd` | 0x101F74E0 | 5 | yes | - | Returns bit n of the acter flag table (through two forwarders). | medium |
| `YkWindows_GetEntryPosition` | 0x101F74F0 | 119 | yes | - | Returns an entry's position relative to its offsets. | low |
| `YkWindows_GetEntryRate` | 0x101F75C0 | 57 | yes | - | Returns 2560 divided by an entry's rate byte. | low |
| `YkWindows_FormatTargetMapGrid` | 0x101F7600 | 299 | yes | - | Returns a static string with the map grid square of the current target, such as (H-8), or (?-?) when it cannot be placed. | medium |
| `fn_101F79E0` | 0x101F79E0 | 207 | yes | - | - | - |
| `YkWindows_SetMapWindowState` | 0x101F7C00 | 67 | yes | - | Sets the map window's state (5 or 11) by two flags. | low |
| `YkWindows_PlaceListedActerMarkers` | 0x101F7DB0 | 268 | yes | - | Clears the map's markers and places one for each acter of a list that is in the same map area. | low |
| `YkWindows_PlaceActerMarker` | 0x101F7EC0 | 275 | yes | - | Places one listed acter's marker on the map when it is in the shown area. | low |
| `YkWindows_TerminateMarkerNames` | 0x101F7FE0 | 56 | yes | - | Makes sure each map marker's name is terminated. | low |
| `YkWindows_InitMapMarkers` | 0x101F8020 | 135 | yes | - | Initialises the map window's 20 marker records and their header "KMIX". | medium |
| `YkWindows_LoadMapMarkerFile` | 0x101F80B0 | 505 | yes | - | Loads the map marker file for a map number, or starts empty markers when there is none. | high |
| `YkWindows_SubmitMarkerFile` | 0x101F82B0 | 164 | yes | - | Checksums the 0x1C0-byte marker block and submits it to the file manager under the name M%03d%02d.MRK made from its two arguments. | medium |
| `YkWindows_SetMapView` | 0x101F8360 | 644 | yes | - | Sets the map window up for a map: which image, where and how large. | low |
| `YkWindows_GetMapResourceId` | 0x101F85F0 | 81 | yes | - | Returns the resource id of a map entry's image. | low |
| `YkWindows_ReportMapChange` | 0x101F8650 | 91 | yes | - | Prints the new map's name to the chat log when the map changes. | low |
| `YkWindows_AddMessage32` | 0x101F86B0 | 14 | yes | - | Adds message 0x20 of the message table to the chat log. | low |
| `YkWindows_CtorVt1033A8B8` | 0x101F86C0 | 426 | yes | - | Constructs the Yk object with vtable 0x1033A8B8. | low |
| `YkWindows_UpdateTargetMarker` | 0x101F8EA0 | 269 | yes | - | Puts the target actor's position and heading into the map's marker. | low |
| `YkWindows_GetTargetMapCoords` | 0x101F8FB0 | 93 | yes | - | Converts the target actor's position into map coordinates. | low |
| `YkWindows_ClearMapMarkers` | 0x101F9010 | 89 | yes | - | Clears the map window's markers. | low |
| `fn_101F9110` | 0x101F9110 | 383 | yes | - | - | - |
| `Yk_ResetSlots` | 0x101F92B0 | 34 | yes | - | Clears two slot pointers and sets their index words to -1. | low |
| `YkWindows_ResetMapBuffers` | 0x101F92E0 | 142 | yes | - | Reallocates the map window's two work buffers. | low |
| `Yk_FreeBuffers` | 0x101F9370 | 92 | yes | - | Frees the two buffers held by the object and resets its indices. | medium |
| `fn_101F9A20` | 0x101F9A20 | 41 | yes | - | - | - |
| `YkWindows_CloseMapMenus` | 0x101FA420 | 260 | yes | - | Frees its buffers, saves its marker file if changed, stores a setting 0x8A and closes the map0/mapv2/mapv3/scanlist/mapscan menus. | medium |
| `YkWindows_CanShowMapTitle` | 0x101FAAB0 | 56 | yes | - | Returns whether the map window's title can be shown. | low |
| `fn_101FAAF0` | 0x101FAAF0 | 40 | yes | - | - | - |
| `YkWindows_MarkGroupMarkers` | 0x101FAD00 | 54 | yes | - | Clears the marker flags and marks the active markers of one group. | low |
| `YkWindows_ClearMarkerFlags` | 0x101FAD40 | 48 | yes | - | Clears the flag of every map marker descriptor (and a second byte when asked). | low |
| `YkWindows_StepMarkerGroup` | 0x101FAD70 | 171 | yes | - | Moves to the next (or previous) map marker group that has markers and marks it. | low |
| `YkWindows_OnMapClick` | 0x101FAFF0 | 125 | yes | - | Handles a pending click on the map window. | low |
| `YkWindows_SetupMapImage` | 0x101FB1B0 | 260 | yes | - | Sets the map window's image and its size on the screen. | low |
| `YkWindows_CtorVt1033A918` | 0x101FB710 | 51 | yes | - | Constructs the Yk object with vtable 0x1033A918. | low |
| `YkWindows_CtorVt1033A988` | 0x101FC2C0 | 39 | yes | - | Constructs the Yk object with vtable 0x1033A988. | low |
| `YkWindows_CtorVt1033A9D0` | 0x101FCBC0 | 50 | yes | - | Constructs the Yk object with vtable 0x1033A9D0. | low |
| `YkWindows_CtorVt1033AAB0` | 0x101FD000 | 168 | yes | - | Constructs the Yk object with vtable 0x1033AAB0. | low |
| `YkWindows_SortEntries` | 0x101FD600 | 848 | yes | - | Gathers the used slots of an object and orders them. | low |
| `YkWindows_CtorVt1033AAF8` | 0x101FE430 | 33 | yes | - | Constructs the Yk object with vtable 0x1033AAF8. | low |
| `YkWindows_CtorVt1033ABE0` | 0x101FF000 | 246 | yes | - | Constructs the Yk object with vtable 0x1033ABE0. | low |
| `YkWindows_CtorVt1033AC28` | 0x10200B60 | 45 | yes | - | Constructs the Yk object with vtable 0x1033AC28. | low |
| `YkWindows_InitFromTablesA` | 0x10201020 | 115 | yes | - | Initialises a record from values of 0x101C8C30's entries 1 and 0. | low |
| `YkWindows_InitFromTablesB` | 0x10201130 | 65 | yes | - | Initialises a record from 13 values of 0x101C8C30's entry 0x10. | low |
| `YkWindows_DrawCountersAndGauge` | 0x10201340 | 382 | yes | 2 | Draws two labelled values and a third value with an image chosen by its range, read from the object at 0x104DFD98+0x4638. | low |
| `Yk_UpdateLayout` | 0x102015D0 | 100 | yes | 3 | Lays out the object's window according to its current mode. | medium |
| `YkWindows_GetState10664390` | 0x10201690 | 68 | yes | - | Returns a state from 0 to 4 for the window record at 0x10664390. | low |
| `YkWindows_CreateMenuObjects` | 0x102017A0 | 726 | yes | - | Creates a set of global UI objects once. | low |
| `YkWindows_CtorVt1033B0C8` | 0x10201C90 | 38 | yes | - | Constructs the Yk object with vtable 0x1033B0C8. | low |
| `Yk_CheckFlagAndWord1C` | 0x10201EB0 | 25 | yes | - | Reports whether the object's flag is set and its word at offset 0x1C exceeds 0x6FF. | low |
| `YkWindows_IsSingleUncheckedEntry` | 0x10201F00 | 67 | yes | - | Reports whether exactly one active entry fails the check while others pass. | low |
| `YkWindows_Call101CA180IfText` | 0x10202380 | 35 | yes | 3 | Calls 0x101CA180 when a text is given. | low |
| `YkWindows_DrawLabelIfStateGroup06Or38` | 0x10202AF0 | 144 | yes | 3 | Draws a label at (x-0x3A, y) when the actor is in state group 6 or 0x38; what the label shows is not established. | low |
| `Yk_GetActiveEntry` | 0x10202C90 | 38 | yes | - | Returns the table entry at the given index when it is active. | low |
| `YkWindows_ResetMode` | 0x10202D10 | 21 | yes | - | Resets the Yk mode with zero arguments. | low |
| `YkWindows_SetModeFwd` | 0x10202D30 | 41 | yes | - | Sets the Yk mode with a zero second argument. | low |
| `Yk_SetMode` | 0x10202D80 | 383 | yes | - | Switches between the menu and target modes, showing or hiding the menu window and updating the target manager. | medium |
| `YkWindows_RunCallbackAndResetTarget` | 0x10202F00 | 222 | yes | - | Runs the callback at 0x106643E4, updates its menu entry, then resets the Yk mode and clears the target manager's values. | low |
| `YkWindows_GetRecord10664390` | 0x10203120 | 6 | yes | - | Returns the address of the window record at 0x10664390. | low |
| `YkWindows_FindActiveEntryById` | 0x102031F0 | 97 | yes | - | Tests whether an active entry with an id exists. | low |
| `Yk_GetActerIfValid` | 0x102033C0 | 98 | yes | - | Returns the acter for a table index when that entry is valid for the current scene. | medium |
| `YkWindows_GetSelectedActer` | 0x10203430 | 43 | yes | - | Returns the acter the window's index at 0x106643E0 selects (or a default one when none is selected). | low |
| `YkWindows_GetActerIfValidMax5` | 0x10203480 | 31 | yes | - | Returns the acter for an index when it is valid, limited to indexes up to 5 when asked. | low |
| `Yk_GetActerPtrA0` | 0x102034A0 | 28 | yes | - | Returns the value at offset 0xA0 of the valid acter for a table index. | low |
| `YkWindows_GetSelectedActerFieldA0` | 0x102034C0 | 31 | yes | - | Returns the field at +0xA0 of the selected acter, or 0. | low |
| `YkWindows_GetCurrentEntry` | 0x102034E0 | 20 | yes | - | Returns the entry at the current index 0x106643DC. | low |
| `Yk_GetEntryOrZero` | 0x10203500 | 31 | yes | - | Returns the entry for an index, or 0 for an out-of-range index in a restricted mode. | low |
| `Yk_SetCurrentIndex` | 0x10203520 | 29 | yes | - | Sets the current entry index from an object's id. | medium |
| `Yk_FindIndexById` | 0x10203540 | 42 | yes | - | Returns the index of the active entry with the given id, or -1. | medium |
| `YkWindows_UpdateEntryCycle` | 0x10203920 | 268 | yes | - | Cycles the current entry index with two inputs. | low |
| `Yk_SetStateFromFlag` | 0x10203BC0 | 28 | yes | - | Sets the object's state from a boolean argument. | low |
| `YkWindows_ReadOrLoadGstEntry` | 0x10203BE0 | 113 | yes | - | Reads (arg set) or loads from file the 700-byte "gst" dat entry held at 0x104DFD98+0x9534. | medium |
| `YkWindows_CtorVt1033B110` | 0x10205500 | 52 | yes | - | Constructs the Yk object with vtable 0x1033B110. | low |
| `YkWindows_ClearFields14To24` | 0x10206420 | 18 | yes | - | Zeroes the fields from +0x14 to +0x24. | low |
| `YkWindows_HasKind0CFlag40Entry` | 0x10207360 | 130 | yes | - | Returns whether any entry of the window's group refers to a kind-0xC record with flag 0x40 set. | low |
| `YkWindows_CtorVt1033B248` | 0x10207730 | 239 | yes | - | Constructs the Yk object with vtable 0x1033B248. | low |
| `YkWindows_CtorVt1033B28C` | 0x10208500 | 53 | yes | - | Constructs the Yk object with vtable 0x1033B28C. | low |
| `YkWindows_CtorVt1033B340` | 0x10209300 | 156 | yes | - | Constructs the Yk object with vtable 0x1033B340. | low |
| `YkWindows_CtorVt1033B3A0` | 0x10209B90 | 38 | yes | - | Constructs the Yk object with vtable 0x1033B3A0. | low |
| `YkWindows_CtorVt1033B948` | 0x1020B500 | 1071 | yes | - | Constructs the Yk object with vtable 0x1033B948. | low |
| `YkWindows_RecordInit` | 0x1020BA40 | 53 | yes | - | Initialises a record with its id. | low |
| `sub_1020BE90` | 0x1020BE90 | 252 | no | - | Fills the object's tables from the indexed records of the loaded data. | medium |
| `YkWindows_CtorVt1033B9D8` | 0x1020C470 | 152 | yes | - | Constructs the Yk object with vtable 0x1033B9D8. | low |
| `YkWindows_CtorVt1033BA20` | 0x1020CC30 | 38 | yes | - | Constructs the Yk object with vtable 0x1033BA20. | low |
| `YkWindows_CtorVt1033BA68` | 0x1020ED00 | 50 | yes | - | Constructs the Yk object with vtable 0x1033BA68. | low |
| `YkWndShop_Constructor` | 0x10210310 | 299 | yes | - | - | - |
| `YkWindows_ResetState` | 0x10210D60 | 52 | yes | - | Clears the dialog's callback, title and state fields. | low |
| `YkWindows_Init` | 0x10210DA0 | 95 | yes | - | Initialises a menu dialog with its four-value layout and flag. | medium |
| `YkWindows_Open` | 0x10210E30 | 217 | yes | - | Opens the menu dialog with its callback and flags. | medium |
| `YkWindows_Close` | 0x10210FC0 | 70 | yes | - | Closes the menu dialog, running its callback and destroying its menu. | medium |
| `YkWindows_Call10156C30InRect` | 0x10211050 | 108 | yes | 3 | Passes the value at +0x1C to 0x10156C30 inside the rectangle of the layout entry at +8, inset by 4. | low |
| `YkWindows_HandleChoice` | 0x102112B0 | 127 | yes | - | Handles the chosen menu option for the dialog's mode. | low |
| `YkWindows_ApplyMusicVolume` | 0x10211340 | 43 | yes | - | Applies the music volume for the dialog when its flag is set. | low |
| `YkWindows_Refresh` | 0x10211370 | 168 | yes | - | Refreshes the menu dialog, re-running its callback and redrawing the menu. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `YkWindows_CtorVt10338670` calls `Yk_InitBase`
- `YkWindows_CtorVt10338700` calls `Yk_InitBase`
- `Yk_CreateCommonObjects` calls `NetCellFont_ClearWords`, `Allocator_Generic`, `TargetMenu_Construct`, `YkWindows_CtorVt10338BE8`, `YkWindows_CtorVt10338670`, `YkWindows_CtorVt10338700`
- `YkWindows_CtorVt10338BE8` calls `NetCellFont_ClearWords`
- `YkWindows_CtorVt10338D88` calls `Yk_InitBase`, `Allocator_Generic`
- `Yk_CreateSecondaryObjects` calls `NetCellFont_ClearWords`, `Allocator_Generic`, `YkWindows_CtorVt10338E60`, `YkWindows_CtorVt10338EA4`, `YkWindows_CtorVt10338ED4`
- `YkWindows_CtorVt10338E60` calls `NetCellFont_ClearWords`, `Yk_InitSlots`
- `Yk_InitSlots` calls `YkWindows_ClearSlotBytes3`
- `YkWindows_ClearSlotBytes3` calls nothing directly
- `YkWindows_CtorVt10338EA4` calls nothing directly
- `YkWindows_CtorVt10338ED4` calls nothing directly
- `YkWindows_CtorVt10338F68` calls `Yk_InitBase`, `Allocator_Generic`, `NetCellFont_ClearWords`
- `YkWndList_Init` calls `Yk_InitBase`, `Allocator_Generic`, `YkCommon_Construct`, `NetCellFont_ClearWords`, `YkWindows_SetField18AndRemainder`, `NetCellFont_GetTableByteForTens`, `YkWindows_InitEightSlots80808080`
- `YkWindows_ClearFields14To3F` calls nothing directly
- `YkWindows_ClearFields40To48` calls nothing directly
- `YkWindows_CtorVt10339250` calls `NetCellFont_ClearWords`, `Allocator_Generic`, `YkWindows_ClearFields14To3F`, `YkWindows_ClearFields40To48`, `Yk_ClearEntries`, `YkWindows_ClearField74`
- `YkWindows_LoadDatListOrRun101E1A70` calls `YkWindows_LoadDatListSync`, `YkWindows_ClearField74`, `sub_101E1A70`
- `YkWindows_IsWithin23Seconds` calls `NetCellFont_AdvanceAndGetSeconds`
- `YkWindows_ClearField74` calls nothing directly
- `Yk_ClearEntries` calls nothing directly
- `YkWindows_LoadDatListSync` calls `YkWindows_LoadDatSync`
- `YkWindows_LoadDatSync` calls `sub_101E2880`, `TextInputFiles_DatEntryCtor`, `XI_CRYPT_101B9A10 (left out)`, `TextInputFiles_ClearVtable`
- `YkWindows_CtorVt10339298` calls `YkWindows_CtorVt10339E48`
- `YkWindows_CtorVt103394C0` calls `Yk_InitBase`, `Allocator_Generic`, `YkWindows_CtorVt10339770`, `YkWindows_CtorVt10339728`, `NetCellFont_ClearWords`, `YkWindows_CtorVt103397B8`, `YkWindows_CtorVt10339530`
- `YkWindows_CtorVt10339530` calls `NetCellFont_ClearWords`
- `YkWindows_CtorVt10339698` calls `Yk_InitBase`, `Allocator_Generic`, `NetCellFont_ClearWords`
- `YkWindows_CtorVt10339728` calls `NetCellFont_ClearWords`
- `YkWindows_CtorVt10339770` calls `NetCellFont_ClearWords`
- `YkWindows_CtorVt103397B8` calls `NetCellFont_ClearWords`
- `Yk_CtorVt10339BC0` calls `YkWindows_CtorVt1033A000`, `TargetMenu_GetMessageFwd`, `Allocator_Generic`, `NetCellFont_ClearWords`
- `YkWindows_AttachTwoWindows` calls `MenuMng_AttachWindowAndPosition`
- `YkWindows_CtorVt10339D78` calls `Yk_InitBase`, `Allocator_Generic`, `YkWindows_CtorVt10339DE8`, `NetCellFont_ClearWords`
- `YkWindows_CtorVt10339DE8` calls `NetCellFont_ClearWords`, `YkCommon_GetIndexed`
- `YkWindows_CtorVt10339E48` calls `Yk_InitBase`, `Allocator_Generic`, `YkWindows_CtorVt10339EB8`
- `YkWindows_CtorVt10339EB8` calls `NetCellFont_ClearWords`, `YkWindows_InitFields1CTo3C`
- `YkWindows_InitFields1CTo3C` calls nothing directly
- `YkWindows_CtorVt10339FA0` calls `NetCellFont_ClearWords`, `Allocator_Generic`
- `YkWindows_UpdateScreenTransform` calls nothing directly
- `YkWindows_CtorVt1033A000` calls `NetCellFont_ClearWords`, `sub_10311C2C`, `Yk_ResetFields`
- `YkWindows_SetFlag20AndValues` calls nothing directly
- `YkWindows_SetFlag20Default` calls `YkWindows_SetFlag20AndValues`
- `Yk_ResetFields` calls nothing directly
- `YkWindows_ClearSixFlags` calls nothing directly
- `YkWindows_Return8` calls nothing directly
- `YkWindows_GetTable103820B0` calls nothing directly
- `YkWindows_CtorVt1033A5D8` calls `Yk_InitBase`, `Allocator_Generic`, `NetCellFont_ClearWords`, `TargetMenu_Construct`, `YkWindows_CtorVt10339298`, `YkWindows_ClearSixFlags`
- `YkWndItem_Open` calls `IsEvent`, `TargetMenu_OpenWithOptions`, `TargetMenu_DockWindowLeft`, `YkWindows_SetField18AndRemainder`, `MenuMng_OpenByName`, `TargetMenu_MenuItemFade`, `sub_101F1230`, `sub_101F11E0`, `YkWindows_SelectListIndex`
- `YkWindows_GetItemEntryState` calls `Acter_IsFlag40DB6OrState17`, `sub_1015BC40`, `MenuPanels_ComputeEntryFlags`, `MenuPanels_ComputeEntryMode`, `MenuPanels_DecodeEntryState`
- `YkWindows_CtorVt1033A6D0` calls `NetCellFont_ClearWords`, `Allocator_Generic`
- `YkWindows_InitEightSlots80808080` calls nothing directly
- `YkWindows_SetSlot` calls nothing directly
- `YkWindows_ClampListScroll` calls nothing directly
- `YkWindows_SetField18AndRemainder` calls nothing directly
- `YkWindows_ShowSelectedHelp` calls `TargetMenu_MenuTestItem34Or6B`, `YkWindows_GetSelectedIndex`, `TargetMenu_ForwardToPanel`
- `Yk_InitBase` calls `NetCellFont_ClearWords`
- `YkWindows_ReadRectAndShowHelp` calls `NetCellFont_GetRect`, `YkWindows_ShowSelectedHelp`
- `YkWindows_SetListItems` calls `YkWindows_ClampListScroll`, `YkWindows_ShowSelectedHelp`
- `YkWindows_SelectListIndex` calls `YkWindows_ClampListScroll`, `NetCellFont_SelectEntryMoveCursor`, `YkWindows_ShowSelectedHelp`
- `YkWindows_GetSelectedIndex` calls nothing directly
- `YkWindows_GetValueIfLoaded` calls nothing directly
- `Yk_GetSharePercent` calls nothing directly
- `YkWindows_GetEntryFieldA` calls nothing directly
- `YkWindows_GetEntryFieldB` calls nothing directly
- `YkWindows_GetEntryFieldBPercent` calls `YkWindows_GetEntryFieldB`
- `Yk_FindEntryIndex` calls nothing directly
- `YkWindows_GetEntryCode` calls nothing directly
- `YkWindows_TestFlagBitFwd` calls `YkCommon_Forward10097E80`
- `YkWindows_GetEntryPosition` calls `Yk_FindEntryIndex`, `YkWindows_GetEntryCode`, `sub_101F7570`
- `YkWindows_GetEntryRate` calls nothing directly
- `YkWindows_FormatTargetMapGrid` calls `ActorHandle_Resolve`, `YkCommon_TestFlags100Or40DAC`, `ZoneMap_QueryBoxHeightBandThenGetCount34154`, `YkWindows_GetEntryPosition`, `sub_10311FF1`
- `fn_101F79E0` calls `ActorHandle_Resolve`, `ZoneMap_QueryBoxHeightBandThenGetCount34154`, `Yk_FindEntryIndex`, `sub_101F9A50`
- `YkWindows_SetMapWindowState` calls `NetCellFont_SetStateByIndex`, `YkCommon_CC4F0ActorTest400`
- `YkWindows_PlaceListedActerMarkers` calls `YkWindows_ClearMapMarkers`, `ActorHandle_Resolve`, `ZoneMap_QueryBoxHeightBandThenGetCount34154`, `NetCellFont_SetByte9800AndGetEntry`, `NetCellFont_SelectNext`, `YkWindows_PlaceActerMarker`
- `YkWindows_PlaceActerMarker` calls `KaHelpMes_ResetLoadMes`, `ZoneMap_QueryBoxHeightBandThenGetCount34154`, `NetCellFont_SetByte9800AndGetEntry`, `NetCellFont_SelectNext`, `Yk_FindEntryIndex`, `sub_101F7570`, `fn_101F9110`
- `YkWindows_TerminateMarkerNames` calls nothing directly
- `YkWindows_InitMapMarkers` calls nothing directly
- `YkWindows_LoadMapMarkerFile` calls `sub_10311FF1`, `TextInputFiles_FileMngFwd101C1DF0`, `TextInputFiles_FileMngSubmitPathKind1`, `Allocator_Generic`, `operator_delete`, `YkCommon_Checksum`, `YkWindows_TerminateMarkerNames`, `YkWindows_ClearMapMarkers`, `YkWindows_InitMapMarkers`
- `YkWindows_SubmitMarkerFile` calls `YkCommon_Checksum`, `sub_10311FF1`, `TextInputFiles_FileMngSubmitPathKind6`, `TextInputFiles_FileMngSubmitPathKind3`
- `YkWindows_SetMapView` calls `YkWindows_ReportMapChange`, `YkWindows_GetMapResourceId`, `sub_101CC620`, `Settings_GetValue`, `YkWindows_UpdateScreenTransform`, `YkCommon_GetIndexed`, `sub_101CBC10`
- `YkWindows_GetMapResourceId` calls nothing directly
- `YkWindows_ReportMapChange` calls `sub_101CBC10`, `TargetMenu_GetMessageFwd`, `sub_10311FF1`, `ChatLog_AddTextCode379`
- `YkWindows_AddMessage32` calls `ChatLog_AddTableMessage7`
- `YkWindows_CtorVt1033A8B8` calls `YkWindows_CtorVt1033A000`, `Yk_ResetSlots`, `Allocator_Generic`, `NetCellFont_ClearWords`, `YkWindows_CtorVt1033A988`, `YkWindows_CtorVt1033A918`, `YkWindows_CtorVt1033A9D0`
- `YkWindows_UpdateTargetMarker` calls `ActorHandle_Resolve`, `YkWindows_GetTargetMapCoords`, `NetCellFont_GetActiveBlock3AE98`, `sub_101F7570`
- `YkWindows_GetTargetMapCoords` calls `ActorHandle_Resolve`, `sub_101F7570`
- `YkWindows_ClearMapMarkers` calls nothing directly
- `fn_101F9110` calls `YkWindows_GetRecord10664390`, `YkWindows_StepMarkerGroup`
- `Yk_ResetSlots` calls nothing directly
- `YkWindows_ResetMapBuffers` calls `operator_delete`, `Allocator_Generic`
- `Yk_FreeBuffers` calls `operator_delete`
- `fn_101F9A20` calls `Acter_IsWord104802BASet`
- `YkWindows_CloseMapMenus` calls `Yk_FreeBuffers`, `YkWindows_SubmitMarkerFile`, `sub_10311C2C`, `SetConfig`, `Menu_CloseEntry`
- `YkWindows_CanShowMapTitle` calls nothing directly
- `fn_101FAAF0` calls `YkWindows_CanShowMapTitle`, `XI_PACKET_101FA680 (left out)`
- `YkWindows_MarkGroupMarkers` calls `YkWindows_ClearMarkerFlags`
- `YkWindows_ClearMarkerFlags` calls nothing directly
- `YkWindows_StepMarkerGroup` calls `YkWindows_ClearMarkerFlags`, `YkWindows_MarkGroupMarkers`
- `YkWindows_OnMapClick` calls `fn_101F79E0`, `MenuMng_AttachWindowAndPosition`
- `YkWindows_SetupMapImage` calls `sub_101CC620`, `Settings_GetValue`, `YkWindows_UpdateScreenTransform`
- `YkWindows_CtorVt1033A918` calls `Yk_InitBase`
- `YkWindows_CtorVt1033A988` calls `NetCellFont_ClearWords`
- `YkWindows_CtorVt1033A9D0` calls `Yk_InitBase`
- `YkWindows_CtorVt1033AAB0` calls `NetCellFont_ClearWords`, `Allocator_Generic`, `YkWindows_CtorVt1033AAF8`
- `YkWindows_SortEntries` calls nothing directly
- `YkWindows_CtorVt1033AAF8` calls nothing directly
- `YkWindows_CtorVt1033ABE0` calls `NetCellFont_ClearWords`, `Allocator_Generic`, `YkWindows_CtorVt1033AC28`
- `YkWindows_CtorVt1033AC28` calls `Yk_InitBase`
- `YkWindows_InitFromTablesA` calls `YkCommon_GetIndexed`
- `YkWindows_InitFromTablesB` calls `YkCommon_GetIndexed`
- `YkWindows_DrawCountersAndGauge` calls `sub_100FCB40`, `sub_10311FF1`, `TargetMenu_GetMessageFwd`, `YkCommon_DrawUnscaled`, `sub_100FCB50`, `sub_100FCB60`, `sub_102012D0`, `sub_1011FB60`, `YkCommon_GetIndexed`
- `Yk_UpdateLayout` calls `NetCellFont_GetRect`, `YkWindows_DrawCountersAndGauge`, `sub_10201180`
- `YkWindows_GetState10664390` calls `YkWindows_GetRecord10664390`, `YkWindows_IsSingleUncheckedEntry`
- `YkWindows_CreateMenuObjects` calls `Allocator_Generic`, `TargetMenu_Construct`, `Yk_InitBase`, `YkWindows_CtorVt1033B110`, `YkWindows_CtorVt1033B0C8`
- `YkWindows_CtorVt1033B0C8` calls `NetCellFont_ClearWords`
- `Yk_CheckFlagAndWord1C` calls nothing directly
- `YkWindows_IsSingleUncheckedEntry` calls `Yk_CheckFlagAndWord1C`
- `YkWindows_Call101CA180IfText` calls `YkCommon_DrawTruncated`
- `YkWindows_DrawLabelIfStateGroup06Or38` calls `IsEvent`, `Acter_GetActerAt10485F7A`, `Acter_IsStateGroup06Or38`, `sub_101CB0D0`, `YkCommon_DrawString`
- `Yk_GetActiveEntry` calls nothing directly
- `YkWindows_ResetMode` calls `YkWindows_SetModeFwd`
- `YkWindows_SetModeFwd` calls `Yk_SetMode`
- `Yk_SetMode` calls `Entry_ValidateKey`, `Yk_FindIndexById`, `YkCommon_GetCC4F0ActorAt2A0`, `sub_1015DB80`, `sub_1015E830`, `TargetMenu_SetValues3`, `TargetMenu_SetFields78D0`
- `YkWindows_RunCallbackAndResetTarget` calls `sub_1015DB80`, `MenuMng_AttachWindowAndPosition`, `TargetMenu_MenuInitAndFadeItem`, `YkWindows_ResetMode`, `TargetMenu_SetValues3`, `TargetMenu_SetFields78D0`
- `YkWindows_GetRecord10664390` calls nothing directly
- `YkWindows_FindActiveEntryById` calls `Yk_CheckFlagAndWord1C`
- `Yk_GetActerIfValid` calls nothing directly
- `YkWindows_GetSelectedActer` calls `YkCommon_GetCC4F0ActorAt2A0`, `YkWindows_GetActerIfValidMax5`
- `YkWindows_GetActerIfValidMax5` calls `Yk_GetActerIfValid`
- `Yk_GetActerPtrA0` calls `Yk_GetActerIfValid`
- `YkWindows_GetSelectedActerFieldA0` calls `YkWindows_GetSelectedActer`
- `YkWindows_GetCurrentEntry` calls `Yk_GetEntryOrZero`
- `Yk_GetEntryOrZero` calls `Yk_GetActerPtrA0`
- `Yk_SetCurrentIndex` calls `Yk_FindIndexById`
- `Yk_FindIndexById` calls nothing directly
- `YkWindows_UpdateEntryCycle` calls `Target_GetActorPtr`, `YkWindows_FindActiveEntryById`, `NetCellFont_TestCommand36CF60`, `YkWindows_GetCurrentEntry`
- `Yk_SetStateFromFlag` calls `YkWindows_ReadOrLoadGstEntry`
- `YkWindows_ReadOrLoadGstEntry` calls `TextInputFiles_DatEntryCtor`, `XI_CRYPT_101B9BC0 (left out)`, `TextInputFiles_ClearVtable`, `XI_CRYPT_101B9A10 (left out)`
- `YkWindows_CtorVt1033B110` calls `NetCellFont_ClearWords`
- `YkWindows_ClearFields14To24` calls nothing directly
- `YkWindows_HasKind0CFlag40Entry` calls `NetCellFont_GetEntryCount`, `NetCellFont_GetSlotPtr`, `sub_1015BC40`
- `YkWindows_CtorVt1033B248` calls `NetCellFont_ClearWords`, `Allocator_Generic`, `YkWindows_CtorVt1033B28C`
- `YkWindows_CtorVt1033B28C` calls nothing directly
- `YkWindows_CtorVt1033B340` calls `NetCellFont_ClearWords`, `Allocator_Generic`
- `YkWindows_CtorVt1033B3A0` calls `Yk_InitBase`
- `YkWindows_CtorVt1033B948` calls `Yk_InitBase`, `Allocator_Generic`, `YkWindows_CtorVt1033B9D8`, `YkWindows_CtorVt1033BA20`, `NetCellFont_ClearWords`, `TargetMenu_Construct`, `YkWindows_CtorVt1033BA68`, `YkWindows_RecordInit`, `sub_1020BE90`
- `YkWindows_RecordInit` calls nothing directly
- `sub_1020BE90` calls `YkCommon_GetIndexed`
- `YkWindows_CtorVt1033B9D8` calls `NetCellFont_ClearWords`, `YkCommon_GetIndexed`
- `YkWindows_CtorVt1033BA20` calls `NetCellFont_ClearWords`
- `YkWindows_CtorVt1033BA68` calls `Yk_InitBase`
- `YkWndShop_Constructor` calls `Yk_InitBase`, `Allocator_Generic`, `NetCellFont_ClearWords`, `YkWindows_Init`
- `YkWindows_ResetState` calls `TargetMenu_SetTextFwd`
- `YkWindows_Init` calls `NetCellFont_ClearWords`, `YkWindows_ResetState`
- `YkWindows_Open` calls `TargetMenu_SetTextFwd`, `MenuMng_OpenByName`, `NetCellFont_SelectEntry`, `YkWindows_HandleChoice`
- `YkWindows_Close` calls `TargetMenu_MenuInitAndFadeItem`, `Menu_CloseEntry`
- `YkWindows_Call10156C30InRect` calls `NetCellFont_GetRect`, `sub_10156C30`
- `YkWindows_HandleChoice` calls `sub_1011BA40`, `Menu_CloseEntry`, `YkWindows_ApplyMusicVolume`, `MenuMng_OpenByName`
- `YkWindows_ApplyMusicVolume` calls `sub_1011BA40`, `SetMusicTrackVolume_B`
- `YkWindows_Refresh` calls `SetMusicTrackVolume_A`, `TargetMenu_MenuInitAndFadeItem`, `Menu_CloseEntry`, `MenuMng_OpenByName`, `NetCellFont_SelectEntry`
