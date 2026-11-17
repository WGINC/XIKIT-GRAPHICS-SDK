# MenuPanels

Group: `Menu` (by the file name only). Source: `sdk/tree_src/MenuPanels.cpp`.

Why the file has this name (data/unit_names.json): Menu_* panels, Movie_CreateFrameTextures / GetCurrentTexture, ActerBuff_DrawNearby, the menus "abisortw", "subwindo", "quest01" (an address range between two evidenced source files, holding several of the original files: named for its main contents)

155 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `MenuPanels_InitAndMarkReady` | 0x1021D930 | 35 | yes | - | Initialises the movie object through sub_1021D9B0 and sets its ready flag at +4 on success. | medium |
| `Movie_Update` | 0x1021D980 | 28 | yes | - | - | - |
| `MenuPanels_ReleaseReturnTrue` | 0x1021D9A0 | 8 | yes | - | Calls the empty fn_1021DDC0 and returns true. | high |
| `MenuPanels_Assign` | 0x1021DD20 | 41 | yes | - | Assigns a reference-counted pointer, releasing the old value and adding a reference to the new one. | medium |
| `MenuPanels_NoOp` | 0x1021DDC0 | 1 | yes | - | Does nothing. | high |
| `Movie_GetCurrentTexture` | 0x1021DDF0 | 24 | yes | - | - | - |
| `MenuPanels_Release` | 0x1021DE10 | 13 | yes | - | Releases the reference-counted pointer held at the start of the object. | medium |
| `MenuPanels_ReleaseComPtr` | 0x1021DE20 | 13 | yes | - | Releases the COM interface held at *self, if any. | medium |
| `MenuPanels_QueryInterface10385E80` | 0x1021DE30 | 20 | yes | - | QueryInterface on *self for the interface id stored at 0x10385E80. | medium |
| `MenuPanels_QueryInterface10385E90` | 0x1021DE50 | 20 | yes | - | QueryInterface on *self for the interface id stored at 0x10385E90. | medium |
| `MenuPanels_QueryInterface10385EA0` | 0x1021DE70 | 20 | yes | - | QueryInterface on *self for the interface id stored at 0x10385EA0. | medium |
| `MenuPanels_ConstructWithBase` | 0x1021DE90 | 117 | yes | - | Initializes the object: base initializer, vtable pointers and zeroed fields. | medium |
| `Movie_CreateFrameTextures` | 0x1021E060 | 177 | yes | 0 | - | - |
| `MenuPanels_FindByName` | 0x1021E3B0 | 135 | yes | - | Finds a mesh resource by its name. | medium |
| `MenuPanels_FindForIds` | 0x1021E480 | 77 | yes | - | Looks up the mesh resource for each id in a list and counts the ones found. | medium |
| `ShapeMng_FindShapes` | 0x1021E4D0 | 44 | yes | - | Looks up the shape for each id in a zero-ended list. | medium |
| `MenuPanels_ClearArrays` | 0x1021E500 | 67 | yes | - | Clears a bit array and a halfword array sized from one count. | low |
| `MenuPanels_UpdateIndexList` | 0x1021E550 | 273 | yes | - | Updates a 16-bit index list from a bitmask and returns the new count. | low |
| `MenuPanels_IsIdInTable10485A30` | 0x1021E670 | 31 | yes | - | Returns whether an id is in the 32-entry short table at 0x10485A30. | high |
| `MenuPanels_ResetFields` | 0x1021E690 | 29 | yes | - | Resets the object's vtable and six fields to zero. | low |
| `MenuPanels_Init` | 0x1021E760 | 186 | yes | - | Allocates and initialises the index tables for a fixed number of entries. | medium |
| `MenuPanels_RotateBytesByBitCount` | 0x1021E870 | 364 | yes | - | Rotates a record's bytes in place (except indices 2, 11, 12) by an amount (0..4 selects the rotation) taken from the bits of bytes 2, 11 and 12. | medium |
| `MenuPanels_CallPanel1021F240And102203B0` | 0x1021ED90 | 41 | yes | - | Calls sub_1021F240 on the object at DAT_10666E84 and then sub_102203B0 unless fn_1015DCE0(&sub_10621838) returns 1. | low |
| `MenuPanels_CallPanel1021EF10` | 0x1021EDC0 | 16 | yes | - | Calls sub_1021EF10 on the panel object at DAT_10666E84, if any. | high |
| `MenuPanels_Call1021EF30If10666E84` | 0x1021EDD0 | 16 | yes | - | Runs 0x1021EF30 when the object pointer at 0x10666E84 is set. | low |
| `Menu_GetPanelByte0D` | 0x1021EDE0 | 23 | yes | - | Returns the byte at offset 0x0D of the menu panel, or 4 when none is set. | low |
| `Menu_SetPanelWord28` | 0x1021EE00 | 19 | yes | - | Stores a word at offset 0x28 of the menu panel. | low |
| `Menu_SetPanelWord2A` | 0x1021EE20 | 19 | yes | - | Stores a word at offset 0x2A of the menu panel. | low |
| `Menu_SetPanelMetrics` | 0x1021EE70 | 56 | yes | - | Sets the menu panel's width, half-width, height and flag. | medium |
| `MenuPanels_InitFieldsDTo38` | 0x1021EEB0 | 92 | yes | - | Sets the object's fields from +0 to +0x38 to their initial values. | low |
| `MenuPanels_SetFlagDAndField1C` | 0x1021EF10 | 21 | yes | - | Sets the flag at +0xD, copies the value at 0x10385ECC to +0x1C and clears the bytes at +0x10/+0x11. | low |
| `MenuPanels_SetPanelMetricsByKind` | 0x1021EF60 | 156 | yes | - | Sets the menu panel metrics (36-unit rows scaled 0.8 or 1.0) and a flag from two kind bytes. | medium |
| `ActerBuff_FindNearest` | 0x1021F030 | 270 | yes | - | Finds the nearest eligible acter to the reference acter and returns its distance. | medium |
| `ActerBuff_CollectNearby` | 0x1021F140 | 239 | yes | - | Collects up to three acters near the reference acter that match a class filter. | medium |
| `MenuPanels_GetWindowRect` | 0x1021F360 | 169 | yes | - | Computes the menu's window rectangle, offset by the draw window. | medium |
| `MenuPanels_DrawPanelForActor` | 0x1021F410 | 103 | yes | 3 | Draws one of two panels depending on the +0x1FF byte of the actor from sub_101CC4F0 and the value at DAT_104DFD98+0x3C350. | low |
| `MenuPanels_DrawActorPanelFigures` | 0x1021F480 | 1226 | yes | 2 | Draws a panel of an actor's figures (counts, ranges, icons) at the menu's window position. | low |
| `MenuPanels_DrawEntryRows` | 0x1021F950 | 315 | yes | 5 | Draws three value rows (two labelled rows and one bar row) of the panel from Unit101D7020 entries 1 and 2. | low |
| `MenuPanels_DrawLabelledRow` | 0x1021FA90 | 121 | yes | 4 | Draws a row: a label, a smoothed value, a second label and a smaller (0.7) smoothed value. | medium |
| `MenuPanels_DrawTwoDigitValue` | 0x1021FB10 | 97 | yes | 4 | Draws a label and a two-digit value. | medium |
| `MenuPanels_DrawBarRow` | 0x1021FB80 | 78 | yes | 4 | Draws an eased percent bar with a label on each side. | high |
| `MenuPanels_DrawNameRows` | 0x1021FBD0 | 267 | yes | 3 | Draws a column of rows, each with a name string from the entry list. | low |
| `ActerBuff_DrawNearby` | 0x1021FCE0 | 298 | yes | 4 | Collects the nearby acters for each of two filters and draws each group. | medium |
| `MenuPanels_DrawStrongholdPanel` | 0x1021FE10 | 905 | yes | 2 | Draws a list of up to six percent bars with labels, using the strings Marchland, Stronghold and Balamor's Adumbration. | low |
| `MenuPanels_DrawLabelBar` | 0x102201A0 | 78 | yes | 2 | Draws a text label with a bar at the given fraction. | medium |
| `MenuPanels_DrawGameTime` | 0x102201F0 | 347 | yes | 2 | Draws the game time as '%d:%02d' followed by a text label. | medium |
| `MenuPanels_RefreshTargetGridText` | 0x10220350 | 94 | yes | - | Returns the cached map-grid text of the target, refreshing it from Unit101D7020_FormatTargetMapGrid on a frame-scaled timer. | medium |
| `Camera_GetWrappedYaw` | 0x10220C20 | 86 | yes | - | Returns a camera-relative angle wrapped to the range minus pi to pi. | low |
| `ShapeMng_FillMenuShapes` | 0x10220C80 | 72 | yes | - | Fills the menu's shape table by looking up each shape id. | medium |
| `Menu_GetTableEntry` | 0x10220CF0 | 21 | yes | - | Returns one entry of the menu's table at the given row and column. | low |
| `Menu_GetGlobalTableEntry` | 0x10220D10 | 20 | yes | - | Returns one entry of the global menu table, or 0 when it is not loaded. | low |
| `MenuPanels_InitPanelState` | 0x10220FD0 | 87 | yes | - | Initialises an embedded panel-state member (zeroes and default sizes 0x88/0x18/0xEC). | low |
| `MenuPanels_SetEntryText` | 0x10221030 | 383 | yes | - | Stores a text in one of the panel's lines, unless it is already there. | medium |
| `Entry_ClearText` | 0x102211B0 | 53 | yes | - | Clears the text of one 0xCB-byte entry. | low |
| `KaHelpMes_ResetLoadMes` | 0x10221300 | 17 | yes | - | - | - |
| `MenuPanels_Draw` | 0x102214D0 | 418 | yes | 1 | Draws a text panel's contents and its sub-panels. | low |
| `MenuPanels_SelectShownLine` | 0x10221680 | 185 | yes | - | Chooses which of the panel's lines is shown and whether it is too wide and must scroll. | low |
| `MenuPanels_IsDone` | 0x10221740 | 38 | yes | - | Tests whether a text panel has finished its work. | low |
| `sub_102217A0` | 0x102217A0 | 15 | no | - | Fills the menu shapes and runs two more menu initialisers at scene start. | medium |
| `MenuPanels_Construct` | 0x102217C0 | 59 | yes | - | Constructs a text panel and sets its default fields. | low |
| `MenuPanels_InitRect` | 0x10221900 | 30 | yes | - | Initialises a text panel's rectangle. | low |
| `MenuPanels_AllocEntriesAndSetCounts` | 0x10221920 | 221 | yes | - | Reallocates the object's 8-byte entry array and sets its counts and state fields. | low |
| `MenuPanels_SetCountAndRebuild` | 0x10221A80 | 254 | yes | - | Sets a new count (and mode at +0x4C), recomputes the derived count at +0x3C and the offset array at +0x50, then calls 0x10221B90. | low |
| `MenuPanels_GetWindowLocate` | 0x10221BE0 | 70 | yes | - | Returns the window location of a text panel's control data. | low |
| `MenuPanels_RunRowCallbacks` | 0x10221F50 | 443 | yes | - | For each visible row, calls the object's row callbacks with the row's button position, then the slot that handles the current button. | low |
| `MenuPanels_SetMode` | 0x10222110 | 63 | yes | - | Applies a mode change to a text panel. | low |
| `MenuPanels_CreateSubsystems` | 0x10222960 | 315 | yes | - | Allocates and constructs the UI subsystem objects. | medium |
| `MenuPanels_ResolveAlias` | 0x10222C10 | 128 | yes | - | Maps an item to a matching alias record when the flag is set. | low |
| `MenuPanels_GetSlotInfo` | 0x10222C90 | 350 | yes | - | Computes the slot count and duration for an item. | low |
| `sub_10222E20` | 0x10222E20 | 539 | no | - | Finds the record whose text matches the given string and returns its id (-1 when none). | medium |
| `MenuPanels_FindByTypeIndex` | 0x10223040 | 130 | yes | - | Finds the n-th item record of a given type. | low |
| `MenuPanels_IsListedIdFlagged` | 0x102231F0 | 80 | yes | - | Returns whether an id in the 16-entry table is flagged for the current acter's group. | low |
| `MenuPanels_FindEntryByCallback` | 0x10223240 | 279 | yes | - | Returns the index of the first table entry that the registered callback accepts for the given text. | low |
| `MenuPanels_HasBitIdPlus200` | 0x10223360 | 36 | yes | - | Returns whether bit id + 0x200 is set in a bit block of the session object. | low |
| `MenuPanels_TestBit` | 0x10223390 | 68 | yes | - | Returns bit n of a byte array. | medium |
| `MenuPanels_SetTargetValuesFor` | 0x102233E0 | 201 | yes | - | Fills the target menu's values from the record for an id. | low |
| `MenuPanels_SetTargetValuesWithCallback` | 0x10223760 | 113 | yes | - | Sets the target menu's values from the record for an id, with the callback at 0x102237E0. | low |
| `MenuPanels_ConstructFromScene` | 0x102238E0 | 45 | yes | - | Constructs the object and initialises its index tables from the scene table value 0x38 with 0x400 entries. | medium |
| `MenuPanels_GetObjectOnce` | 0x10223930 | 51 | yes | - | Returns the static object at DAT_10667050, constructing it on the first call. | medium |
| `MenuPanels_Ctor102239A0` | 0x102239A0 | 20 | yes | - | Constructs the object at 0x10667050: base init and clears the member at +0x10. | medium |
| `MenuPanels_LoadFromFile` | 0x102239C0 | 201 | yes | - | Loads a table's entries from a file. | low |
| `MenuPanels_InitAndRegister` | 0x10223BB0 | 76 | yes | - | Initialises a table and registers it with the data manager. | low |
| `MenuPanels_ClearRecordIfAskedOrFull` | 0x10223C00 | 36 | yes | - | Clears a record when asked or when its count is past 0x6FF. | low |
| `sub_10223C90` | 0x10223C90 | 91 | no | - | Refreshes a table from its source. | low |
| `MenuPanels_ConstructFillMinus1` | 0x10223E60 | 33 | yes | - | Constructs the base object, sets its vtable and fills 24 dwords from offset 0x70 with -1. | low |
| `MenuPanels_GetEntryId` | 0x10224120 | 50 | yes | - | Returns the id of a list entry by index, or -1. | low |
| `MenuPanels_GetRecord` | 0x10224160 | 56 | yes | - | Returns the 48-byte record for an index (or for the current entry). | low |
| `MenuPanels_FindByteIndex` | 0x10225090 | 36 | yes | - | Finds the index of a byte value in the table. | low |
| `MenuPanels_ComputeCount` | 0x10225120 | 245 | yes | - | Computes a count for an entry of the table. | low |
| `MenuPanels_ComputeDelta` | 0x10225220 | 207 | yes | - | Computes a difference between two counts for an entry. | low |
| `MenuPanels_ConstructSetGlobals` | 0x102254D0 | 95 | yes | - | Constructs the base object, clears its fields and writes its nine global words. | low |
| `MenuPanels_InitIndexMap128` | 0x10226080 | 59 | yes | - | Fills a 128-entry index map and registers it. | low |
| `MenuPanels_FillIdentity128` | 0x102260C0 | 27 | yes | - | Fills a 128-entry short array with 0 to 127. | medium |
| `MenuPanels_GetObject106670C8Once` | 0x10226180 | 51 | yes | - | Returns the static object at 0x106670C8, constructing it on first use. | high |
| `MenuPanels_Ctor102261F0` | 0x102261F0 | 20 | yes | - | Constructs the object at 0x106670C8: base init and clears the member at +0x10. | medium |
| `MenuPanels_LoadDMsgTable` | 0x10226210 | 154 | yes | - | Loads the file whose id is scene table entry 0x61 and processes it with the table from Unit10253A20_GetDMsgTable (callee string "d_msg"). | medium |
| `MenuPanels_ConstructZeroFields` | 0x10226550 | 26 | yes | - | Constructs the base object, sets its vtable and zeroes two of its fields. | low |
| `MenuPanels_InitIndexMap64` | 0x10226C80 | 57 | yes | - | Fills a 64-entry index map and registers it. | low |
| `MenuPanels_FindEntryByCallback64` | 0x10227000 | 81 | yes | - | Returns the first of 64 entries the registered callback accepts for a text, or -1. | low |
| `MenuPanels_Alloc1800` | 0x10227080 | 39 | yes | - | Allocates a 0x1800-byte buffer and resets its fields. | low |
| `MenuPanels_ConstructAllocEntries` | 0x102271B0 | 27 | yes | - | Constructs the object and allocates its entry array at offset 0x14. | low |
| `MenuPanels_LoadNamedEntries` | 0x102271D0 | 169 | yes | - | Loads named entries from a file into a table. | low |
| `MenuPanels_CreateAndLoadEntries` | 0x10227750 | 129 | yes | - | Creates three objects into globals and loads the named entries into the first of them. | low |
| `MenuPanels_ConstructBuffersAt68` | 0x102278B0 | 66 | yes | - | Constructs the object and allocates 32 buffers of 0x1800 bytes at offset 0x68. | low |
| `MenuPanels_DrawMovie` | 0x10227F70 | 266 | yes | 1 | Draws a movie at a position offset by one pixel, with a scale and tint that depend on the game timer. | medium |
| `MenuPanels_DrawTimeLeftText` | 0x10228080 | 298 | yes | 3 | Draws, when setting 0xC3 is on, the time left until an entry's stored time as a number, minutes ('%dm') or hours ('%dh'). | medium |
| `MenuPanels_ClearHeaderFields` | 0x102281C0 | 13 | yes | - | Clears the two dwords and the byte at the start of the object. | low |
| `MenuPanels_ConstructBuffersAt8` | 0x10228200 | 72 | yes | - | Constructs the object and allocates 32 buffers of 0x1800 bytes at offset 0x8. | low |
| `MenuPanels_DrawTargetEntryIcons` | 0x10228440 | 1174 | yes | 1 | When setting 0xC2 is on, draws the current target's entry name and up to 32 images, eight to a row, near the menu at sub_10621838. | low |
| `MenuPanels_InitGlobals` | 0x10229430 | 114 | yes | - | Creates the UI's global objects and builds their lookup table. | medium |
| `MenuPanels_ConstructInitAt64` | 0x10229670 | 97 | yes | - | Constructs the object, initialises the sub-object at offset 0x64 and clears its fields. | low |
| `MenuPanels_ClearMenu` | 0x1022A6D0 | 32 | yes | - | Clears the item's flags and destroys its draw menu. | low |
| `MenuPanels_TestBitForId` | 0x1022AF80 | 45 | yes | - | Tests the bit for an id and returns the result. | low |
| `MenuPanels_GetBitIndexForId` | 0x1022AFB0 | 62 | yes | - | Returns the word index and bit mask for an id. | low |
| `MenuPanels_IsBitSetForId` | 0x1022AFF0 | 20 | yes | - | Reports whether the bit for an id is set. | low |
| `MenuPanels_InitSubsystems` | 0x1022B080 | 238 | yes | - | Creates the UI's subsystem objects and clears their tables. | medium |
| `MenuPanels_ClearCounters` | 0x1022B260 | 19 | yes | - | Clears the UI's counter table. | low |
| `MenuPanels_TickCounters` | 0x1022B290 | 91 | yes | - | Counts the UI's timers down each frame and updates the timer length when it changes. | medium |
| `MenuPanels_GetMinutesCeil` | 0x1022B2F0 | 52 | yes | - | Returns a timer counter converted to whole minutes, rounded up. | low |
| `MenuPanels_SetTimerSeconds` | 0x1022B3B0 | 20 | yes | - | Sets the timer length to the given number of minutes in seconds. | low |
| `MenuPanels_FindTableIdByText` | 0x1022B430 | 310 | yes | - | Finds the table row whose text matches the given string and returns its id, -2 when unavailable, -1 when none. | medium |
| `MenuPanels_IsEntryAvailable` | 0x1022B7D0 | 126 | yes | - | Tests an entry's availability against the current values at 0x10485640. | low |
| `MenuPanels_SetTargetValuesFromList7A70` | 0x1022B850 | 135 | yes | - | Sets the target menu's values from a record of the list at 0x10667A70. | low |
| `MenuPanels_GetEntryState` | 0x1022B8E0 | 1129 | yes | - | Fills seven output values describing an entry of the list at 0x10667A70. | low |
| `MenuPanels_CtorVt1033C50C` | 0x1022BD50 | 45 | yes | - | Constructs the subsystem object for table 0x39. | low |
| `MenuPanels_GetSingleton` | 0x1022BDA0 | 51 | yes | - | Returns the UI singleton, initialising it on first use. | medium |
| `MenuPanels_SingletonCtor` | 0x1022BE10 | 20 | yes | - | Constructs the UI singleton's table and file entry. | low |
| `MenuPanels_LoadMessageTable` | 0x1022BE30 | 201 | yes | - | Loads the message table of file 0x5D and its companion 0x5E. | low |
| `MenuPanels_GetRowFirstCell` | 0x1022BF00 | 15 | yes | - | Returns the first cell of a table row. | low |
| `MenuPanels_MixDatCtor` | 0x1022BFB0 | 76 | yes | - | Constructs the object saved as mix.dat and registers it with the DAT manager. | medium |
| `MenuPanels_ClearRecord221IfAskedOrBad` | 0x1022C000 | 41 | yes | - | Clears a record when asked or when its index is out of range, and returns the index. | low |
| `MenuPanels_PanelCtorVt1033C510` | 0x1022C350 | 18 | yes | - | Constructs a text panel with vtable 0x1033C510. | low |
| `MenuPanels_GetEntryId7A7C` | 0x1022C730 | 50 | yes | - | Returns the id of a list entry by index (the list of 0x10667A7C), or -1. | low |
| `MenuPanels_GetRecord100` | 0x1022C770 | 47 | yes | - | Returns the 100-byte record for an index (or for the current entry). | low |
| `MenuPanels_DecodeEntryState` | 0x1022D290 | 204 | yes | - | Unpacks an entry's state record into seven output values. | low |
| `MenuPanels_ComputeEntryFlags` | 0x1022D370 | 355 | yes | - | Works out an entry's flags and display value from its kind and the current target. | low |
| `MenuPanels_ComputeEntryMode` | 0x1022D510 | 210 | yes | - | Sets an entry's mode at +8 from its kind, by a table and, for one case, by testing the acter it names. | low |
| `MenuPanels_PanelCtorVt1033C5C0` | 0x1022DB80 | 25 | yes | - | Constructs a text panel with vtable 0x1033C5C0. | low |
| `MenuPanels_ReadChunkDirectory` | 0x1022EC50 | 159 | yes | - | Reads a UI data file's chunk headers into a directory table. | low |
| `MenuPanels_Clear` | 0x1022ED00 | 13 | yes | - | Clears a UI string list's three counters. | low |
| `MenuPanels_Alloc` | 0x1022ED30 | 54 | yes | - | Allocates the storage for a UI string list. | medium |
| `MenuPanels_Append` | 0x1022ED70 | 113 | yes | - | Appends a string to a UI string list, returning 1 on success. | medium |
| `MenuPanels_LoadStringTable` | 0x1022EEE0 | 519 | yes | - | Loads a file's id/string table into a string list. | low |
| `MenuPanels_ReadChunk` | 0x1022F240 | 56 | yes | - | Reads a block of a UI data file and reports success. | low |
| `MenuPanels_CreateMessagePanels` | 0x1022F3D0 | 305 | yes | - | Creates the message panels and loads their eleven string tables. | low |
| `MenuPanels_PanelCtorVt1033C6B0` | 0x1022F610 | 25 | yes | - | Constructs a text panel with vtable 0x1033C6B0. | low |
| `MenuPanels_CtorVt1033C718` | 0x102303B0 | 44 | yes | - | Constructs the member object with vtable 0x1033C718. | low |
| `MenuPanels_Reset` | 0x10230410 | 52 | yes | - | Resets a UI object's counters and its five table entries. | medium |
| `MenuPanels_PanelCtorVt1033C720` | 0x10233BE0 | 22 | yes | - | Constructs a text panel with vtable 0x1033C720. | low |
| `MenuPanels_PanelCtorVt1033C788` | 0x102340A0 | 25 | yes | - | Constructs a text panel with vtable 0x1033C788. | low |
| `fn_10234610` | 0x10234610 | 66 | yes | - | - | - |
| `MenuPanels_DrawProgressBar` | 0x10234660 | 363 | yes | 2 | Draws a progress bar and its segments from the object's values. | medium |
| `MenuPanels_SendMenuEventByKind` | 0x10234910 | 218 | yes | - | When fn_10123A70(0x3E, 0x8B, n, -1) returns 1, sends menu event 0x16..0x19 chosen by the kind byte +0x28 (kind 3 toggles +0x29 instead); what fn_10123A70 tests is not established. | low |
| `MenuPanels_ComputeClampedIndex` | 0x10234A00 | 97 | yes | - | Computes a clamped index into the UI list from a position. | low |
| `MenuPanels_SetPair` | 0x10234A70 | 20 | yes | - | Stores two values and clears a flag. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `MenuPanels_InitAndMarkReady` calls `sub_1021D9B0`
- `Movie_Update` calls `sub_1021DD50`
- `MenuPanels_ReleaseReturnTrue` calls `MenuPanels_NoOp`
- `MenuPanels_Assign` calls nothing directly
- `MenuPanels_NoOp` calls nothing directly
- `Movie_GetCurrentTexture` calls nothing directly
- `MenuPanels_Release` calls nothing directly
- `MenuPanels_ReleaseComPtr` calls nothing directly
- `MenuPanels_QueryInterface10385E80` calls nothing directly
- `MenuPanels_QueryInterface10385E90` calls nothing directly
- `MenuPanels_QueryInterface10385EA0` calls nothing directly
- `MenuPanels_ConstructWithBase` calls `FitFont_DerivedCtor`
- `Movie_CreateFrameTextures` calls `sub_102D2FB9`
- `MenuPanels_FindByName` calls `ResourceIter_Start`, `ResourceIter_FindNext`
- `MenuPanels_FindForIds` calls `Scene_GetMenuFrameName`, `MenuPanels_FindByName`
- `ShapeMng_FindShapes` calls `ShapeMng_FindShape`
- `MenuPanels_ClearArrays` calls nothing directly
- `MenuPanels_UpdateIndexList` calls nothing directly
- `MenuPanels_IsIdInTable10485A30` calls nothing directly
- `MenuPanels_ResetFields` calls nothing directly
- `MenuPanels_Init` calls `Allocator_Generic`
- `MenuPanels_RotateBytesByBitCount` calls nothing directly
- `MenuPanels_CallPanel1021F240And102203B0` calls `sub_1021F240`, `TargetMenu_MenuTest48OrStateB4`, `sub_102203B0`
- `MenuPanels_CallPanel1021EF10` calls `MenuPanels_SetFlagDAndField1C`
- `MenuPanels_Call1021EF30If10666E84` calls nothing directly
- `Menu_GetPanelByte0D` calls nothing directly
- `Menu_SetPanelWord28` calls nothing directly
- `Menu_SetPanelWord2A` calls nothing directly
- `Menu_SetPanelMetrics` calls nothing directly
- `MenuPanels_InitFieldsDTo38` calls nothing directly
- `MenuPanels_SetFlagDAndField1C` calls nothing directly
- `MenuPanels_SetPanelMetricsByKind` calls `Menu_SetPanelMetrics`
- `ActerBuff_FindNearest` calls nothing directly
- `ActerBuff_CollectNearby` calls nothing directly
- `MenuPanels_GetWindowRect` calls `sub_101602F0`, `sub_1011BA40`, `NetCellFont_GetRect`
- `MenuPanels_DrawPanelForActor` calls `Acter_GetActerAt10485F7A`, `MenuPanels_DrawEntryRows`, `MenuPanels_DrawActorPanelFigures`
- `MenuPanels_DrawActorPanelFigures` calls `MenuPanels_GetWindowRect`, `TargetMenu_GetMessageFwd`, `sub_10311FF1`, `YkCommon_DrawUnscaled`, `YkCommon_GetIndexed`, `sub_1011FB60`
- `MenuPanels_DrawEntryRows` calls `MenuPanels_GetWindowRect`, `YkWindows_GetEntryFieldA`, `YkWindows_GetEntryFieldBPercent`, `MenuPanels_DrawLabelledRow`, `Yk_GetSharePercent`, `MenuPanels_DrawBarRow`, `YkWindows_GetValueIfLoaded`, `MenuPanels_DrawTwoDigitValue`
- `MenuPanels_DrawLabelledRow` calls `YkCommon_DrawUnscaled`, `YkCommon_DrawSmoothedItem1A`, `YkCommon_DrawSmoothedExItem1B`
- `MenuPanels_DrawTwoDigitValue` calls `YkCommon_DrawUnscaled`, `sub_10311FF1`
- `MenuPanels_DrawBarRow` calls `YkCommon_DrawEasedPercentItem1A`, `YkCommon_DrawUnscaled`
- `MenuPanels_DrawNameRows` calls `NetCellFont_GetRect`, `YkCommon_DrawSmoothedItem1A`, `YkCommon_DrawString`, `YkCommon_DrawUnscaled`
- `ActerBuff_DrawNearby` calls `sub_1011BA40`, `Acter_GetActerAt10485F7A`, `ActerBuff_CollectNearby`, `MenuPanels_DrawNameRows`
- `MenuPanels_DrawStrongholdPanel` calls `Acter_GetByte10480824IfFlag`, `Acter_GetDword10480800IfFlag`, `Acter_GetTable10480828IfFlag`, `MenuPanels_GetWindowRect`, `YkCommon_DrawFractionItem1A`, `YkCommon_DrawUnscaled`, `YkCommon_GetIndexed`, `sub_1011FB60`, `sub_10311FF1`, `sub_101C9B50`, `MenuPanels_DrawLabelBar`
- `MenuPanels_DrawLabelBar` calls `sub_1011FB60`, `YkCommon_DrawFractionItem1A`, `YkCommon_DrawUnscaled`
- `MenuPanels_DrawGameTime` calls `MenuPanels_RefreshTargetGridText`, `ntGameTimeGet`, `Time_ModMul3CDiv90`, `Time_ModDivD80Div90`, `sub_10311FF1`, `YkCommon_DrawUnscaled`, `YkCommon_GetIndexed`, `Time_ModDiv6C00Scaled`, `sub_1011FB60`
- `MenuPanels_RefreshTargetGridText` calls `Camera_GetFrameScale`, `sub_10311C2C`, `YkWindows_FormatTargetMapGrid`, `sub_10312050`
- `Camera_GetWrappedYaw` calls `Camera_GetField50`, `CYyCamMng2::GetYaw`
- `ShapeMng_FillMenuShapes` calls `Scene_GetMenuFrameName`, `ShapeMng_FindShape`, `ShapeMng_FindShapes`
- `Menu_GetTableEntry` calls nothing directly
- `Menu_GetGlobalTableEntry` calls nothing directly
- `MenuPanels_InitPanelState` calls `MenuPanels_SelectShownLine`
- `MenuPanels_SetEntryText` calls `Entry_ClearText`, `Font_MeasureTextAll2`, `sub_10312940`, `sub_10312050`, `sub_10313520`, `TargetMenu_CallIfNot3`, `MenuPanels_SelectShownLine`
- `Entry_ClearText` calls `MenuPanels_SelectShownLine`
- `KaHelpMes_ResetLoadMes` calls nothing directly
- `MenuPanels_Draw` calls `sub_10220EF0`, `CDx::GetRenderTargetTop`, `CDx::SetViewport`, `sub_1011D050`, `Font_DrawGlyphQuadGrey`, `sub_10221770`, `sub_10220F40`
- `MenuPanels_SelectShownLine` calls `Font_MeasureTextAll2`
- `MenuPanels_IsDone` calls nothing directly
- `sub_102217A0` calls `ShapeMng_FillMenuShapes`, `sub_102224C0`, `Allocator_Generic`, `MenuPanels_InitFieldsDTo38`
- `MenuPanels_Construct` calls `NetCellFont_ClearWords`, `MenuPanels_InitRect`
- `MenuPanels_InitRect` calls `MenuPanels_AllocEntriesAndSetCounts`
- `MenuPanels_AllocEntriesAndSetCounts` calls `operator_delete`, `Allocator_Generic`, `sub_10221ED0`
- `MenuPanels_SetCountAndRebuild` calls `operator_delete`, `sub_10221E10`, `Allocator_Generic`, `sub_10221B90`
- `MenuPanels_GetWindowLocate` calls `NetCellFont_GetRect`
- `MenuPanels_RunRowCallbacks` calls `MenuPanels_GetWindowLocate`, `sub_102225F0`, `sub_10118900`, `sub_101188E0`
- `MenuPanels_SetMode` calls `NetCellFont_TestCommand36CF60`
- `MenuPanels_CreateSubsystems` calls `Allocator_Generic`, `NetCellFont_ClearWords`, `MenuPanels_ConstructFillMinus1`, `MenuPanels_InitAndRegister`, `MenuPanels_ConstructFromScene`, `MenuPanels_InitIndexMap128`, `MenuPanels_ConstructSetGlobals`, `MenuPanels_InitIndexMap64`, `MenuPanels_ConstructZeroFields`
- `MenuPanels_ResolveAlias` calls nothing directly
- `MenuPanels_GetSlotInfo` calls `MenuPanels_ResolveAlias`, `MenuPanels_ComputeCount`, `MenuPanels_ComputeDelta`
- `sub_10222E20` calls `MenuPanels_GetObjectOnce`, `sub_10223A90`, `sub_10223B10`, `sub_10223C90`, `YkCommon_GetCC4F0ActorByIndexAt1FA`, `XI_PACKET_100FC9C0 (left out)`
- `MenuPanels_FindByTypeIndex` calls `sub_10223C90`
- `MenuPanels_IsListedIdFlagged` calls `Acter_IsByte10483158Set`
- `MenuPanels_FindEntryByCallback` calls `MenuPanels_IsListedIdFlagged`, `MenuPanels_GetObjectOnce`, `sub_10223A90`, `sub_10223B10`
- `MenuPanels_HasBitIdPlus200` calls `NetCellFont_GetBlock2CDE8IfReady`, `MenuPanels_TestBit`
- `MenuPanels_TestBit` calls nothing directly
- `MenuPanels_SetTargetValuesFor` calls `MenuPanels_GetRecord`, `TargetMenu_SetValues3`, `TargetMenu_SetFields78D0`
- `MenuPanels_SetTargetValuesWithCallback` calls `MenuPanels_GetRecord`, `TargetMenu_SetValues3`, `TargetMenu_SetFields78D0`
- `MenuPanels_ConstructFromScene` calls `MenuPanels_ResetFields`, `Scene_GetTableValue`, `MenuPanels_Init`
- `MenuPanels_GetObjectOnce` calls `MenuPanels_Ctor102239A0`, `sub_10313486`
- `MenuPanels_Ctor102239A0` calls `sub_10257860`, `YkCommon_Clear`
- `MenuPanels_LoadFromFile` calls `Scene_GetTableValue`, `FileMng_ResolveOrExit`, `Allocator_Generic`, `TextInputFiles_ForwardOrExit`, `DmsgText_GetDMsgTable`, `DmsgText_Assign`, `DmsgText_Clone`, `operator_delete`, `YkCommon_Load`
- `MenuPanels_InitAndRegister` calls `MenuPanels_ClearArrays`, `TextInputFiles_Register`
- `MenuPanels_ClearRecordIfAskedOrFull` calls nothing directly
- `sub_10223C90` calls `NetCellFont_GetBlock2CDE8IfReady`, `MenuPanels_UpdateIndexList`, `Acter_IsFlag40DB6OrState17`
- `MenuPanels_ConstructFillMinus1` calls `MenuPanels_Construct`
- `MenuPanels_GetEntryId` calls nothing directly
- `MenuPanels_GetRecord` calls `MenuPanels_GetEntryId`
- `MenuPanels_FindByteIndex` calls nothing directly
- `MenuPanels_ComputeCount` calls `MenuPanels_FindByteIndex`, `sub_10311C2C`
- `MenuPanels_ComputeDelta` calls `MenuPanels_FindByteIndex`, `sub_10311C2C`
- `MenuPanels_ConstructSetGlobals` calls `MenuPanels_Construct`
- `MenuPanels_InitIndexMap128` calls `TextInputFiles_Register`
- `MenuPanels_FillIdentity128` calls nothing directly
- `MenuPanels_GetObject106670C8Once` calls `MenuPanels_Ctor102261F0`, `sub_10313486`
- `MenuPanels_Ctor102261F0` calls `sub_10257860`, `YkCommon_Clear`
- `MenuPanels_LoadDMsgTable` calls `Scene_GetTableValue`, `FileMng_ResolveOrExit`, `Allocator_Generic`, `TextInputFiles_ForwardOrExit`, `DmsgText_GetDMsgTable`, `DmsgText_Assign`, `YkCommon_Load`
- `MenuPanels_ConstructZeroFields` calls `MenuPanels_Construct`
- `MenuPanels_InitIndexMap64` calls `TextInputFiles_Register`
- `MenuPanels_FindEntryByCallback64` calls `MenuPanels_GetObject106670C8Once`, `sub_102262B0`, `sub_10226320`
- `MenuPanels_Alloc1800` calls `Allocator_Generic`
- `MenuPanels_ConstructAllocEntries` calls `sub_10257860`, `TextInputFiles_EntriesCtorEmpty`
- `MenuPanels_LoadNamedEntries` calls `TextInputFiles_AllocEntries`, `Scene_GetTableValue`, `TextInputFiles_EntriesSetCount`, `FileMng_ResolveOrExit`, `Allocator_Generic`, `TextInputFiles_ForwardOrExit`, `DmsgText_GetDMsgTable`, `DmsgText_Bind`
- `MenuPanels_CreateAndLoadEntries` calls `Allocator_Generic`, `MenuPanels_ConstructBuffersAt68`, `MenuPanels_ConstructBuffersAt8`, `MenuPanels_ConstructAllocEntries`, `MenuPanels_LoadNamedEntries`
- `MenuPanels_ConstructBuffersAt68` calls `MenuPanels_Construct`, `MenuPanels_Alloc1800`
- `MenuPanels_DrawMovie` calls `ntGameTimeGet`, `sub_10227930`, `Settings_GetValue`, `sub_10227100`, `sub_10311C2C`, `sub_102270F0`, `sub_10227130`, `sub_10227920`, `CXiMovie::Draw`
- `MenuPanels_DrawTimeLeftText` calls `Settings_GetValue`, `ntGameTimeGet`, `sub_10227930`, `sub_10227100`, `sub_10311FF1`, `YkCommon_DrawTextItem0`
- `MenuPanels_ClearHeaderFields` calls nothing directly
- `MenuPanels_ConstructBuffersAt8` calls `MenuPanels_Alloc1800`, `MenuPanels_ClearHeaderFields`
- `MenuPanels_DrawTargetEntryIcons` calls `Settings_GetValue`, `TextInputFiles_GetSetting99`, `TargetMenu_GetField84Ptr`, `sub_101593C0`, `TargetMenu_GetTargetActorPtr74`, `sub_102288E0`, `Yk_FindIndexById`, `Yk_GetActiveEntry`, `sub_10202CC0`, `sub_10098F70`, `sub_10098F90`, `sub_10227110`, `sub_10227920`, `sub_10311C2C`, `sub_10228910`, `Menu_GetDwordAt8C`, `NetCellFont_GetRect`, `YkCommon_DrawUnscaled`, `sub_101C9B50`, `sub_10228280`, `sub_10227130`, `CXiMovie::Draw`
- `MenuPanels_InitGlobals` calls `Allocator_Generic`, `MenuPanels_ConstructInitAt64`, `MenuPanels_Construct`, `MenuPanels_FindForIds`
- `MenuPanels_ConstructInitAt64` calls `MenuPanels_Construct`, `TextInputFiles_Init`
- `MenuPanels_ClearMenu` calls `TargetMenu_MenuInitAndFadeItem`
- `MenuPanels_TestBitForId` calls `MenuPanels_GetBitIndexForId`, `Acter_TestFlagTable`
- `MenuPanels_GetBitIndexForId` calls `TargetMenu_GetInstance`, `TargetMenu_GetWordAt`
- `MenuPanels_IsBitSetForId` calls `MenuPanels_TestBitForId`
- `MenuPanels_InitSubsystems` calls `Allocator_Generic`, `NetCellFont_ClearWords`, `MenuPanels_PanelCtorVt1033C510`, `MenuPanels_MixDatCtor`, `MenuPanels_CtorVt1033C50C`, `MenuPanels_ClearCounters`
- `MenuPanels_ClearCounters` calls nothing directly
- `MenuPanels_TickCounters` calls `Camera_GetField38`, `NetCellFont_FindTimerKind10`, `MenuPanels_SetTimerSeconds`
- `MenuPanels_GetMinutesCeil` calls nothing directly
- `MenuPanels_SetTimerSeconds` calls nothing directly
- `MenuPanels_FindTableIdByText` calls `MenuPanels_GetSingleton`, `sub_1022BF10`, `MenuPanels_GetRowFirstCell`, `NetCellFont_GetBlock2CF54IfFlag`, `MenuPanels_IsEntryAvailable`
- `MenuPanels_IsEntryAvailable` calls `Acter_GetTable10485830IfBit2`
- `MenuPanels_SetTargetValuesFromList7A70` calls `MenuPanels_GetRecord100`, `TargetMenu_SetValues3`, `TargetMenu_SetFields78D0`
- `MenuPanels_GetEntryState` calls `Acter_IsFlag40DB6OrState17`, `MenuPanels_GetRecord100`, `MenuPanels_IsIdInTable10485A30`, `MenuPanels_HasBitIdPlus200`, `TargetMenu_GetActiveEntry16`, `MenuPanels_ComputeEntryFlags`, `MenuPanels_ComputeEntryMode`, `MenuPanels_DecodeEntryState`
- `MenuPanels_CtorVt1033C50C` calls `MenuPanels_ResetFields`, `Scene_GetTableValue`, `MenuPanels_Init`
- `MenuPanels_GetSingleton` calls `MenuPanels_SingletonCtor`, `sub_10313486`
- `MenuPanels_SingletonCtor` calls `sub_10257860`, `YkCommon_Clear`
- `MenuPanels_LoadMessageTable` calls `Scene_GetTableValue`, `FileMng_ResolveOrExit`, `Allocator_Generic`, `TextInputFiles_ForwardOrExit`, `DmsgText_GetDMsgTable`, `DmsgText_Assign`, `DmsgText_Clone`, `operator_delete`, `YkCommon_Load`
- `MenuPanels_GetRowFirstCell` calls `DmsgText_GetCell`
- `MenuPanels_MixDatCtor` calls `MenuPanels_ClearArrays`, `TextInputFiles_Register`
- `MenuPanels_ClearRecord221IfAskedOrBad` calls nothing directly
- `MenuPanels_PanelCtorVt1033C510` calls `MenuPanels_Construct`
- `MenuPanels_GetEntryId7A7C` calls nothing directly
- `MenuPanels_GetRecord100` calls `MenuPanels_GetEntryId7A7C`
- `MenuPanels_DecodeEntryState` calls nothing directly
- `MenuPanels_ComputeEntryFlags` calls `YkCommon_GetCC4F0ActorByIndexAt1FA`, `TargetMenu_GetTargetActorPtr74`, `Acter_GetGlobal10482F38IfIdMatch`
- `MenuPanels_ComputeEntryMode` calls `Acter_FindByField78Fwd`, `YkCommon_ActorPairTest1FF`
- `MenuPanels_PanelCtorVt1033C5C0` calls `MenuPanels_Construct`
- `MenuPanels_ReadChunkDirectory` calls `MenuPanels_ReadChunk`
- `MenuPanels_Clear` calls nothing directly
- `MenuPanels_Alloc` calls `Allocator_Generic`
- `MenuPanels_Append` calls nothing directly
- `MenuPanels_LoadStringTable` calls `sub_10257860`, `FileMng_ResolveOrExit`, `Allocator_Generic`, `TextInputFiles_ForwardOrExit`, `operator_delete`, `DmsgText_GetDMsgTable`, `DmsgText_Assign`, `DmsgText_GetRowCount`, `DmsgText_GetCell`, `MenuPanels_Alloc`, `DmsgText_GetDwordCell`, `MenuPanels_Append`, `TextInputFiles_AllocEntries`, `TextInputFiles_EntriesSetCount`, `DmsgText_BindSource`, `DmsgText_GetRowInfo`, `DmsgText_CallFreeData`
- `MenuPanels_ReadChunk` calls `Scene_GetTableValue`, `TextInputFiles_ForwardOrExit`
- `MenuPanels_CreateMessagePanels` calls `Allocator_Generic`, `MenuPanels_PanelCtorVt1033C6B0`, `MenuPanels_Construct`, `MenuPanels_CtorVt1033C718`, `MenuPanels_PanelCtorVt1033C720`, `MenuPanels_PanelCtorVt1033C788`, `Scene_GetTableValue`, `MenuPanels_LoadStringTable`
- `MenuPanels_PanelCtorVt1033C6B0` calls `MenuPanels_Construct`
- `MenuPanels_CtorVt1033C718` calls `MenuPanels_Reset`
- `MenuPanels_Reset` calls nothing directly
- `MenuPanels_PanelCtorVt1033C720` calls `MenuPanels_Construct`
- `MenuPanels_PanelCtorVt1033C788` calls `MenuPanels_Construct`
- `fn_10234610` calls nothing directly
- `MenuPanels_DrawProgressBar` calls `sub_10311C2C`, `Menu_GetTableEntry`, `Cell_DrawFirstStretched`
- `MenuPanels_SendMenuEventByKind` calls `NetCellFont_TestCommand36CF60`, `Menu_HandleEvent`
- `MenuPanels_ComputeClampedIndex` calls `sub_10311C2C`
- `MenuPanels_SetPair` calls nothing directly
