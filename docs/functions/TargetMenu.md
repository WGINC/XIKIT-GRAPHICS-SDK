# TargetMenu

Group: `Target` (by the file name only). Source: `sdk/tree_src/TargetMenu.cpp`.

Why the file has this name (data/unit_names.json): Target_* (46 named), Menu_* and MenuMng_*, the menus "money", "level", "jobchang", "iteminfo", the command "/attack %d" (an address range between two evidenced source files, holding several of the original files: named for its main contents)

422 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `TargetMenu_DoNothing1Arg` | 0x1012AC80 | 3 | yes | - | Takes one argument and does nothing. | low |
| `TargetMenu_FillEntriesFromTable1036F390` | 0x1012B2D0 | 175 | yes | - | Saves the menu's previous fields and fills its entries from a table row for the given index. | low |
| `TargetMenu_UpdateActionMenu` | 0x1012B4B0 | 964 | yes | - | Updates the action menu for the current target: its window, entries, input and help text. | medium |
| `TargetMenu_ConstructVt103333C8` | 0x1012BEF0 | 42 | yes | - | Initialises the object's fields and sets its vtable to PTR_FUN_103333c8. | medium |
| `TargetMenu_ClearEntry1Flags` | 0x1012BF50 | 13 | yes | - | Clears both flags of the window's first entry. | low |
| `TargetMenu_ConstructVt10333410` | 0x1012C210 | 42 | yes | - | Initialises the object's fields and sets its vtable to PTR_FUN_10333410. | medium |
| `TargetMenu_ConstructVt10333458` | 0x1012C540 | 71 | yes | - | Initialises the object's fields and sets its vtable to PTR_FUN_10333458. | medium |
| `TargetMenu_ConstructVt103334A0` | 0x1012C910 | 42 | yes | - | Initialises the object's fields and sets its vtable to PTR_FUN_103334a0. | medium |
| `TargetMenu_ConstructVt10333500` | 0x1012D450 | 82 | yes | - | Initialises the object's fields and sets its vtable to PTR_FUN_10333500. | medium |
| `TargetMenu_DestroyDraw` | 0x1012E180 | 17 | yes | - | Destroys the menu's draw entry through the menu manager. | medium |
| `TargetMenu_ConstructVt103335E8` | 0x1012E360 | 177 | yes | - | Initialises the object, sets its vtable to PTR_FUN_103335e8, and creates the global DAT_1057819c once. | medium |
| `TargetMenu_ClearThenSetGlobal` | 0x10130390 | 39 | yes | - | Clears 0x30 dwords of the object and stores &LAB_101303e0 in the global DAT_104b1774. | low |
| `TargetMenu_GetActiveEntry16` | 0x101304A0 | 42 | yes | - | Returns one of 16 entries when it is in use and not flagged, else 0. | low |
| `TargetMenu_ResolveEntries` | 0x101304D0 | 100 | yes | - | Resolves each pending 12-byte entry through two lookups and clears its pending flag. | low |
| `TargetMenu_ConstructVt10333648` | 0x10130F90 | 9 | yes | - | Sets the object's vtable to PTR_FUN_10333648. | medium |
| `TargetMenu_ConstructVt10333660` | 0x101312E0 | 14 | yes | - | Runs the base constructor fn_10130F90, then sets the vtable to PTR_FUN_10333660. | medium |
| `TargetMenu_ConstructVt10333670` | 0x10131530 | 58 | yes | - | Initialises the object's fields and sets its vtable to PTR_FUN_10333670. | medium |
| `TargetMenu_ConstructVt10333728` | 0x10131940 | 262 | yes | - | Runs the base constructor, builds the subobjects and arrays, sets the vtable to PTR_FUN_10333728, and initialises the global DAT_105781b0. | medium |
| `TargetMenu_ConstructVt103337E0` | 0x10133310 | 95 | yes | - | Runs the base constructor, sets the vtable to PTR_FUN_103337e0, and initialises the globals DAT_105781b4 and DAT_105781c4. | medium |
| `TargetMenu_Is1FFDifferentFromActer` | 0x10133A40 | 62 | yes | - | Returns whether the object's byte at +0x1FF differs from the current acter's, when either is 8 or 9. | low |
| `TargetMenu_ConstructVt10333898` | 0x10135850 | 35 | yes | - | Runs the base constructor, sets the vtable to PTR_FUN_10333898, and clears three fields. | medium |
| `TargetMenu_ConstructVt10333908` | 0x10136380 | 139 | yes | - | Initialises the object, stores its argument at +0x64, and sets the vtable to PTR_FUN_10333908. | medium |
| `TargetMenu_UpdateLayout` | 0x10136560 | 271 | yes | - | Refreshes the window rectangle of the object at +8, marks it dirty, then records the list head and a count capped at four. | low |
| `TargetMenu_LayoutMessage` | 0x10136670 | 374 | no | - | Lays out a message into lines for the message window and adds it to its list and the chat log. | low |
| `TargetMenu_SetPosition` | 0x10136870 | 132 | yes | - | Sets a menu's position, with negative coordinates measured from the screen's bottom-right edge. | medium |
| `TargetMenu_ClearBlock` | 0x10136900 | 49 | yes | - | Zeroes the object's data block and its trailing fields. | low |
| `TargetMenu_ConstructVt10333950` | 0x10136950 | 25 | yes | - | Runs the FEMultiLineText base constructor, then sets the vtable to PTR_FUN_10333950. | medium |
| `TargetMenu_CloseRem4lineMenu` | 0x101369B0 | 16 | yes | - | Closes the menu named rem4line. | high |
| `TargetMenu_ConstructVt103339A0` | 0x101369C0 | 25 | yes | - | Runs the FEMultiLineText base constructor, then sets the vtable to PTR_FUN_103339a0. | medium |
| `TargetMenu_CloseRem4li2Menu` | 0x10136A20 | 16 | yes | - | Closes the menu named rem4li2. | high |
| `TargetMenu_ConstructVt103339F0` | 0x10136A30 | 32 | yes | - | Runs the base constructor fn_10136380, sets the vtable to PTR_FUN_103339f0, and clears +0x68. | medium |
| `TargetMenu_ConstructVt10333A40` | 0x10136E20 | 25 | yes | - | Runs the base constructor fn_10136F60, then sets the vtable to PTR_FUN_10333a40. | medium |
| `TargetMenu_ConstructVt10333A90` | 0x10136EC0 | 25 | yes | - | Runs the base constructor fn_10136F60, then sets the vtable to PTR_FUN_10333a90. | medium |
| `TargetMenu_ConstructVt10333AE0` | 0x10136F60 | 44 | yes | - | Runs the base constructor fn_10136380, sets the vtable to PTR_FUN_10333ae0, and clears its list fields. | medium |
| `TargetMenu_CollectEntries` | 0x101371E0 | 143 | yes | - | Walks the list from its head, flagging entries until one whose +0x110 value exceeds the argument, up to four, and records the count and head. | low |
| `TargetMenu_HasFreeEntryNotKind12` | 0x10137550 | 33 | yes | - | Returns whether the window has a free entry that is not of kind 1 or 2. | low |
| `TargetMenu_ConstructVt10333B68` | 0x10137630 | 59 | yes | - | Initialises the object's fields and sets its vtable to PTR_FUN_10333b68. | medium |
| `TargetMenu_ConstructVt10333BB0` | 0x10138960 | 45 | yes | - | Initialises the object, sets its vtable to PTR_FUN_10333bb0, and clears its data ranges through fn_10138EC0. | medium |
| `TargetMenu_ClearRanges` | 0x10138EC0 | 40 | yes | - | Zeroes four ranges of the object's fields. | low |
| `TargetMenu_IsAlwaysTrue` | 0x10138FB0 | 3 | yes | - | Returns 1. | low |
| `TargetMenu_ConstructVt10333CB0` | 0x10139840 | 86 | yes | - | Initialises the object, sets its vtable to PTR_FUN_10333cb0, and creates the global DAT_105781f4 once. | medium |
| `TargetMenu_ConstructVt10333D10` | 0x10139EE0 | 48 | yes | - | Initialises the object's fields and sets its vtable to PTR_FUN_10333d10. | medium |
| `TargetMenu_CallIfNot3` | 0x10139FF0 | 15 | yes | - | Calls thunk_FUN_1013a100 unless its argument is 3. | low |
| `TargetMenu_TickHelp` | 0x1013A010 | 25 | yes | - | Runs the help-timer check and calls one of two follow-up functions on its result. | low |
| `TkHelp_AdvanceTimer` | 0x1013A030 | 46 | yes | - | Advances the help counter by the frame scale and reports when it passes its limit. | medium |
| `TargetMenu_IsEvent` | 0x1013A060 | 16 | yes | - | Returns whether IsEvent(0, its argument) is nonzero. | low |
| `TargetMenu_AdvanceHelpTimer` | 0x1013A070 | 93 | yes | - | Returns whether the help timer should advance, testing the help and title globals, and otherwise advances it through TkHelp_AdvanceTimer. | low |
| `TargetMenu_ResetHelpAndTitle` | 0x1013A100 | 90 | yes | - | When its flag is set, sets the title and help panels' text with (0, 3) and refreshes both, then restarts its counter at 90. | low |
| `TargetMenu_ConstructVt10333D18` | 0x1013A1E0 | 52 | yes | - | Initialises the object, constructs the subobject at +0x20, and sets the vtable to PTR_FUN_10333d18. | medium |
| `TargetMenu_ForwardToPanel` | 0x1013A320 | 8 | yes | - | Forwards its two arguments to the object at +0x20. | low |
| `TargetMenu_TickMember20AndHelp` | 0x1013A330 | 22 | yes | - | Updates the member at +0x20 and ticks the help object at DAT_105781FC. | high |
| `TargetMenu_DrawPanel` | 0x1013A350 | 140 | yes | 1 | Draws the panel at +0x20 with additive blending and the glyph texture. | low |
| `TargetMenu_CtorVt10333D78` | 0x1013A480 | 58 | yes | - | Constructs a UI object with vtable 0x10333D78. | low |
| `TargetMenu_CtorVt10333DD8` | 0x1013A930 | 38 | yes | - | Constructs a UI object with vtable 0x10333DD8. | low |
| `TargetMenu_CtorVt10333E20` | 0x1013AA60 | 18 | yes | - | Constructs a UI object with vtable 0x10333E20. | low |
| `TargetMenu_CtorVt10333E70` | 0x1013AB20 | 39 | yes | - | Constructs a UI object with vtable 0x10333E70. | low |
| `TargetMenu_CtorVt10333EC0` | 0x1013BE50 | 190 | yes | - | Constructs a UI object with vtable 0x10333EC0. | low |
| `TargetMenu_InitFields1CTo3A7` | 0x1013BF40 | 111 | yes | - | Resets the object's fields from +0x1C to +0x3A7 to their initial values. | low |
| `TargetMenu_Forward1013E590` | 0x1013BFB0 | 5 | yes | - | Calls the function at 0x1013E590 on the menu. | low |
| `TargetMenu_InitFromTables` | 0x1013BFC0 | 324 | yes | - | Sets the menu up from the global tables and the scene state. | low |
| `TargetMenu_Call1013E560` | 0x1013C110 | 17 | yes | - | Calls the function at 0x1013E560 on the menu. | low |
| `TargetMenu_SetRowCount` | 0x1013C180 | 149 | yes | - | Sets the menu's number of rows (3 to 12), resizing and re-docking its window. | low |
| `TargetMenu_OpenWithOptions` | 0x1013E3B0 | 83 | yes | - | Opens the menu (by the name it gives) with its options. | low |
| `TargetMenu_DockWindowLeft` | 0x1013E4F0 | 40 | yes | - | Docks the menu's window in position 0 (the flag 0x1000). | low |
| `TargetMenu_GetWindowRect` | 0x1013E560 | 34 | yes | - | Reads the window's rectangle and returns its first pair. | low |
| `TargetMenu_PlaceByLayout` | 0x1013E590 | 250 | yes | - | Places the menu's window by its layout setting. | low |
| `TargetMenu_CtorVt10333F28` | 0x1013E7F0 | 84 | yes | - | Constructs a UI object with vtable 0x10333F28. | low |
| `TargetMenu_Is100EBE60Positive` | 0x1013EFF0 | 11 | yes | - | Returns whether the function at 0x100EBE60 returns a positive value. | low |
| `TargetMenu_InitFromShape` | 0x1013FBE0 | 94 | yes | - | Initialises a window object from its named shape. | low |
| `TargetMenu_SetupMenuEntriesByState` | 0x10140090 | 464 | yes | - | Fills in the texts and enabled states of a menu's entries according to the event and session flags. | low |
| `TargetMenu_UpdateEntryStates` | 0x10140270 | 242 | yes | - | Sets the states and texts of entries 0xC, 6 and 10 of its layout from the session and Yk state. | low |
| `TargetMenu_ReadWindowRect14` | 0x10140890 | 13 | yes | - | Reads the window's rectangle into the object at +0x14. | low |
| `TargetMenu_ReadWindowRect14IfSet` | 0x101408A0 | 20 | yes | - | Reads the window's rectangle into +0x14 when the flag at +0x10 is set. | low |
| `TargetMenu_CtorVt10334070` | 0x10140950 | 58 | yes | - | Constructs a UI object with vtable 0x10334070. | low |
| `TargetMenu_CtorVt103340D0` | 0x10140E70 | 61 | yes | - | Constructs a UI object with vtable 0x103340D0. | low |
| `TargetMenu_DestroyDrawMenu` | 0x10141AD0 | 17 | yes | - | Destroys the draw menu for this object. | medium |
| `TargetMenu_CtorVt10334200` | 0x101436C0 | 227 | yes | - | Constructs a UI object with vtable 0x10334200. | low |
| `TargetMenu_CtorVt10334260` | 0x10144680 | 61 | yes | - | Constructs a UI object with vtable 0x10334260. | low |
| `TargetMenu_CreateAll` | 0x10144D60 | 480 | yes | - | Creates the shared UI resource objects. | low |
| `TargetMenu_Construct` | 0x10144F40 | 38 | yes | - | Constructs a base UI object and sets its common fields. | low |
| `TargetMenu_CtorVt10334928` | 0x10146340 | 1511 | yes | - | Constructs the UI object with vtable 0x10334928 and its many shared helpers. | low |
| `TargetMenu_Set` | 0x10146930 | 40 | yes | - | Stores four 16-bit values in a 4-short block. | low |
| `TargetMenu_SetCopy` | 0x10146960 | 38 | yes | - | Stores four 16-bit values in a 4-short block. | low |
| `TargetMenu_CtorVt10334970` | 0x101475B0 | 62 | yes | - | Constructs a UI object with vtable 0x10334970. | low |
| `TargetMenu_CtorVt103349B8` | 0x10148430 | 66 | yes | - | Constructs a UI object with vtable 0x103349B8. | low |
| `TargetMenu_CtorVt10334A00` | 0x10148640 | 64 | yes | - | Constructs a UI object with vtable 0x10334A00. | low |
| `YkWndList_Construct` | 0x10148ED0 | 98 | yes | - | Constructs a window list object and sets its line and default values. | low |
| `TargetMenu_CtorVt10334AB8` | 0x1014A170 | 82 | yes | - | Constructs a UI object with vtable 0x10334AB8. | low |
| `TargetMenu_CtorVt10334B28` | 0x1014A7D0 | 92 | yes | - | Constructs a UI object with vtable 0x10334B28. | low |
| `TargetMenu_CtorVt10334B98` | 0x1014B670 | 78 | yes | - | Constructs a UI object with vtable 0x10334B98. | low |
| `TargetMenu_CtorVt10334C08` | 0x1014BA60 | 83 | yes | - | Constructs a UI object with vtable 0x10334C08. | low |
| `TargetMenu_CtorVt10334D00` | 0x1014C750 | 99 | yes | - | Constructs a UI object with vtable 0x10334D00. | low |
| `TargetMenu_CtorVt10334D60` | 0x1014D970 | 142 | yes | - | Constructs a UI object with vtable 0x10334D60. | low |
| `TargetMenu_CtorVt10334DC0` | 0x1014DD30 | 138 | yes | - | Constructs a UI object with vtable 0x10334DC0. | low |
| `TargetMenu_FillTable13CMinusOne` | 0x1014E020 | 44 | yes | - | Fills the 32 eight-dword blocks at +0x13C with -1 and clears +0x53C. | low |
| `TargetMenu_Fill8DwordsMinusOne` | 0x1014E050 | 19 | yes | - | Fills the eight dwords at the argument with -1. | low |
| `TargetMenu_CtorVt10334E58` | 0x1014EDC0 | 290 | yes | - | Constructs a UI object with vtable 0x10334E58. | low |
| `TargetMenu_CtorVt10334EB8` | 0x1014F840 | 178 | yes | - | Constructs a UI object with vtable 0x10334EB8. | low |
| `TargetMenu_CtorVt10334F18` | 0x1014FFE0 | 120 | yes | - | Constructs a UI object with vtable 0x10334F18. | low |
| `TargetMenu_UpdateTargetMarker` | 0x10150090 | 272 | yes | - | Per-frame update of the target marker's blink and screen position. | low |
| `TargetMenu_DockAndInit` | 0x10150870 | 122 | yes | - | Docks the menu's window in position 2 and sets up its rectangles and list. | low |
| `TargetMenu_ReadWindowRects` | 0x101508F0 | 29 | yes | - | Reads the window's rectangle into the menu's two copies. | low |
| `TargetMenu_SetName` | 0x10150A30 | 47 | yes | - | Stores a name string of up to 0x31 bytes in a UI item. | low |
| `TargetMenu_SetField48` | 0x10150A60 | 14 | yes | - | Stores a value at +0x48 and clears the flag +0x14. | low |
| `TargetMenu_CopyList6To78` | 0x10150A70 | 59 | yes | - | Copies the global list number 6 into the menu. | low |
| `TargetMenu_CtorVt10334F78` | 0x10150AB0 | 74 | yes | - | Constructs a UI object with vtable 0x10334F78. | low |
| `TargetMenu_SetTextFwd` | 0x10150CC0 | 5 | yes | - | Sets the object's text (through Unit1012AC80_SetText). | low |
| `TargetMenu_SetText` | 0x10150CE0 | 82 | yes | - | Sets the text of the object's +0xA4 member from a converted copy. | low |
| `TargetMenu_IsField8Zero` | 0x10150D90 | 9 | yes | - | Reports whether the field at +8 is empty. | low |
| `TargetMenu_CtorVt10335060` | 0x10151040 | 120 | yes | - | Constructs a UI object with vtable 0x10335060. | low |
| `TargetMenu_ClearFields` | 0x10151140 | 21 | yes | - | Clears five fields. | low |
| `TargetMenu_GetMessageFwd` | 0x10152EF0 | 5 | yes | - | Looks up a message by table and index (through Unit1012AC80_GetMessage). | low |
| `TargetMenu_GetMessage` | 0x10152F20 | 88 | yes | - | Returns the text of row arg2 of message table arg1. | low |
| `TargetMenu_Clear32` | 0x10152F80 | 17 | yes | - | Clears the 32-entry slot table at DAT_10578548. | low |
| `TargetMenu_ReleaseAll32` | 0x10152FA0 | 32 | yes | - | Releases all 32 slots and reports whether every release succeeded. | medium |
| `TargetMenu_ReleaseOne` | 0x10152FC0 | 40 | yes | - | Releases the object in one slot and clears the slot. | medium |
| `TargetMenu_LoadMessageBlock` | 0x10152FF0 | 88 | yes | - | Loads a file into message block slot arg1. | low |
| `TargetMenu_GetEntryPtr` | 0x10153090 | 34 | yes | - | Returns the address of the table entry at an index. | low |
| `TargetMenu_GetEntryPtrByLayout` | 0x101530C0 | 56 | yes | - | Returns a table entry's address using the layout selected by the word at +0xA. | low |
| `TargetMenu_GetEntryWord3E` | 0x10153100 | 30 | yes | - | Returns a word from the table entry at an index, or -1. | low |
| `TargetMenu_IsMinus6Word` | 0x10153130 | 25 | yes | - | Tests whether two bytes form the word 0xFFFA. | low |
| `TargetMenu_FormatMessage4` | 0x10153150 | 36 | yes | - | Formats a message with arguments (four fixed). | low |
| `TargetMenu_FormatMessage5` | 0x10153180 | 39 | yes | - | Formats a message with arguments (five fixed). | low |
| `TargetMenu_Read2Byte7Bit` | 0x101531B0 | 21 | yes | - | Decodes a two-byte value stored in 7-bit groups. | medium |
| `TargetMenu_ReadArgCode` | 0x101531D0 | 84 | yes | - | Decodes one argument code of a message string. | low |
| `TargetMenu_FormatDecimal` | 0x10153230 | 121 | yes | - | Writes a number's decimal digits into a buffer. | low |
| `TargetMenu_Call101532B0OnWordBE` | 0x101532F0 | 20 | no | - | Passes the two bytes at p, read as a big-endian word, to 0x101532B0. | low |
| `TargetMenu_ExpandMessageCodes` | 0x10153310 | 1762 | no | - | Expands a game message's control codes (nested messages, choices, numbers, string and name arguments) into a buffer; returns the length or -1. | medium |
| `TargetMenu_FormatMessageWithArgs` | 0x10153A40 | 175 | yes | - | Formats message (param_3, param_4) with an argument array of param_5 values. | medium |
| `TargetMenu_LoadMessageBlocksSetA` | 0x10153AF0 | 57 | yes | - | Loads message blocks 0, 8 and 10 from the first file set. | low |
| `TargetMenu_LoadMessageBlocksSetB` | 0x10153B30 | 57 | yes | - | Loads message blocks 0, 8 and 10 from the second file set. | low |
| `TargetMenu_LoadAllMessageTables` | 0x10153C10 | 690 | yes | - | Loads the message blocks and string tables for the current language. | low |
| `TargetMenu_LoadStringTable` | 0x10153EF0 | 138 | yes | - | Loads a file into a string table object. | low |
| `TargetMenu_DtorVt103350EC` | 0x10153F80 | 7 | yes | - | Resets an object to vtable 0x103350EC on destruction. | low |
| `TargetMenu_GetInstance` | 0x10153FF0 | 51 | yes | - | Returns the singleton object, initialising it on first use. | low |
| `TargetMenu_MessageSetCtor` | 0x10154070 | 42 | yes | - | Constructs the message set object. | low |
| `TargetMenu_LoadMessageSetByState` | 0x101542B0 | 407 | yes | - | Per-scene-state step of Unit1012AC80_LoadMessageSet; the meaning of each state is not established. | low |
| `TargetMenu_IndexOf` | 0x101544F0 | 37 | yes | - | Returns the index of a short value in the array, or -1. | medium |
| `TargetMenu_GetByValue` | 0x10154520 | 35 | yes | - | Returns the table entry for a value, or 0 when it is absent. | low |
| `TargetMenu_GetEntryOrEmpty` | 0x10154550 | 28 | yes | - | Returns the table entry at an index, or an empty string when the index is negative. | low |
| `TargetMenu_LoadMessageSet` | 0x10154570 | 607 | yes | - | Loads table 0x3F's rows and builds their texts into a string list. | low |
| `TargetMenu_ReleaseField7C` | 0x10154840 | 31 | yes | - | Frees the buffer at +0x7C and clears the field at +0x78. | low |
| `TargetMenu_UpdatePendingRead` | 0x10154860 | 106 | yes | - | Finishes a pending read and frees its buffer. | low |
| `TargetMenu_GetCount` | 0x101549E0 | 3 | yes | - | Returns the count at +0. | low |
| `TargetMenu_GetWordAt` | 0x101549F0 | 14 | yes | - | Returns the word at an index of the array at +4. | low |
| `TargetMenu_DtorVt103350F8` | 0x10154A80 | 11 | yes | - | Destroys an object with vtable 0x103350F8. | low |
| `TargetMenu_CtorVt103350F8` | 0x10154AB0 | 20 | yes | - | Constructs an object with vtable 0x103350F8. | low |
| `Entry_Init6` | 0x10154AD0 | 45 | yes | - | Stores six values in the entry's fields. | low |
| `Entry_ReleaseField4` | 0x10154DB0 | 11 | yes | - | Frees the buffer at +4. | low |
| `TargetMenu_CtorVt1033512C` | 0x10154DC0 | 26 | yes | - | Constructs an object with vtable 0x1033512C. | low |
| `TargetMenu_SetEntryWithStrings` | 0x10154E30 | 208 | yes | - | Copies an entry's three strings into one block it owns and sets its fields. | low |
| `TargetMenu_GetInnerPtr10` | 0x10154F00 | 4 | yes | - | Returns the address of the object's inner block at +0x10. | low |
| `TargetMenu_DtorVt10335138` | 0x10154F30 | 11 | yes | - | Destroys an object with vtable 0x10335138. | low |
| `TargetMenu_CtorVt10335138` | 0x10154F60 | 28 | yes | - | Constructs an object with vtable 0x10335138 and two empty strings. | low |
| `Entry_SetFields4` | 0x10154FC0 | 31 | yes | - | Stores four values in the entry's fields. | low |
| `TargetMenu_DtorVt1033515C` | 0x10155100 | 30 | yes | - | Destructor body of the object with vtable 0x1033515C. | medium |
| `Entry_ReleaseField4Zero` | 0x10155140 | 24 | yes | - | Frees the buffer at +4 and clears the field. | low |
| `TargetMenu_CtorVt1033515C` | 0x10155160 | 28 | yes | - | Constructs an object with vtable 0x1033515C and its +0x14 member. | low |
| `TargetMenu_Assign` | 0x101551C0 | 262 | yes | - | Stores three strings in one buffer and records their positions. | medium |
| `TargetMenu_GetMember14` | 0x101552D0 | 4 | yes | - | Returns the address of the +0x14 member. | low |
| `TargetMenu_FreeBuffer` | 0x10155360 | 11 | yes | - | Frees the string buffer held by the object. | medium |
| `TargetMenu_CtorVt10335168` | 0x10155370 | 34 | yes | - | Constructs an object with vtable 0x10335168. | low |
| `TargetMenu_SetItemWithStrings` | 0x10155400 | 218 | yes | - | Copies an item's three strings into one block it owns and sets the item's fields. | medium |
| `TargetMenu_GetMemberC` | 0x101554E0 | 4 | yes | - | Returns the address of the +0xC member. | low |
| `TargetMenu_FreeStrings` | 0x10155540 | 11 | yes | - | Frees the object's string block. | low |
| `TargetMenu_CtorVt10335174` | 0x10155550 | 34 | yes | - | Constructs an object with vtable 0x10335174. | low |
| `TargetMenu_SetString` | 0x101555B0 | 79 | yes | - | Copies a string into a block it owns and hands it to its member. | medium |
| `TargetMenu_GetField8` | 0x10155600 | 4 | yes | - | Returns the address of the string holder's field at offset 8. | low |
| `TargetMenu_Pack` | 0x10155BD0 | 146 | yes | - | Packs two strings and four values into a record of the given size, reporting whether it fits. | medium |
| `TargetMenu_PackRecord7` | 0x10155C70 | 146 | yes | - | Packs a record with two strings into a buffer when it fits. | low |
| `TargetMenu_ReadDword00_10155D10` | 0x10155D10 | 7 | yes | - | Returns the dword at +0x0 of a record. | low |
| `TargetMenu_ReadDword04_10155D20` | 0x10155D20 | 8 | yes | - | Returns the dword at +0x4 of a record. | low |
| `TargetMenu_ReadDword08_10155D30` | 0x10155D30 | 8 | yes | - | Returns the dword at +0x8 of a record. | low |
| `TargetMenu_ReadDword0C_10155D40` | 0x10155D40 | 8 | yes | - | Returns the dword at +0xC of a record. | low |
| `TargetMenu_ReadDword10_10155D50` | 0x10155D50 | 8 | yes | - | Returns the dword at +0x10 of a record. | low |
| `TargetMenu_ReadDword14_10155D60` | 0x10155D60 | 8 | yes | - | Returns the dword at +0x14 of a record. | low |
| `TargetMenu_ReadDword18_10155D70` | 0x10155D70 | 8 | yes | - | Returns the dword at +0x18 of a record. | low |
| `TargetMenu_ConstructText10335180` | 0x10155EA0 | 83 | yes | - | Constructs a text record (vtable 0x10335180) from its arguments. | low |
| `TargetMenu_ConstructText10335180B` | 0x10155F00 | 88 | yes | - | Constructs a text record (vtable 0x10335180) from seven arguments. | low |
| `TargetMenu_InitTextRecord` | 0x10155F60 | 283 | yes | - | Fills a text record from its arguments and counts its text's characters. | low |
| `TargetMenu_InitTextRecordB` | 0x10156080 | 270 | yes | - | Fills a text record from seven arguments and counts its text's characters. | low |
| `TargetMenu_GetField0C` | 0x10156440 | 4 | yes | - | Returns the value stored at offset 0xC of the menu item. | low |
| `TargetMenu_GetField10` | 0x10156450 | 4 | yes | - | Returns the value stored at offset 0x10 of the menu item. | low |
| `TargetMenu_GetField24` | 0x10156470 | 4 | yes | - | Returns the value stored at offset 0x24 of the menu item. | low |
| `TargetMenu_GetField28` | 0x10156480 | 4 | yes | - | Returns the value stored at offset 0x28 of the menu item. | low |
| `TargetMenu_PackRecord3` | 0x10156540 | 118 | yes | - | Packs a value and two strings into a buffer when they fit. | low |
| `TargetMenu_ReadDword00_101565C0` | 0x101565C0 | 7 | yes | - | Returns the dword at +0x0 of a record. | low |
| `TargetMenu_ReadDword04_101565D0` | 0x101565D0 | 8 | yes | - | Returns the dword at +0x4 of a record. | low |
| `TargetMenu_ReadDword08_101565E0` | 0x101565E0 | 8 | yes | - | Returns the dword at +0x8 of a record. | low |
| `TargetMenu_ConstructStringPair` | 0x10156630 | 37 | yes | - | Constructs the object (vtable 0x103351B4) holding a mode and two strings. | low |
| `TargetMenu_InitStringPair` | 0x10156660 | 108 | yes | - | Stores a mode and two strings with their lengths, and a flag from the mode (or from the first string's characters). | low |
| `TargetMenu_GetField04` | 0x10156840 | 4 | yes | - | Returns the value stored at offset 4 of the menu item. | low |
| `TargetMenu_GetField08` | 0x10156850 | 4 | yes | - | Returns the value stored at offset 8 of the menu item. | low |
| `TargetMenu_GetField10A` | 0x10156860 | 4 | yes | - | Returns the field at +0x10. | low |
| `TargetMenu_PackRecordBytes` | 0x10156870 | 181 | yes | - | Packs four bytes and three strings into a buffer when they fit. | low |
| `TargetMenu_GetByte0` | 0x10156930 | 9 | yes | - | Returns byte 0 of a record. | low |
| `TargetMenu_GetByte1` | 0x10156940 | 10 | yes | - | Returns byte 1 of a record. | low |
| `TargetMenu_GetDword4` | 0x10156950 | 8 | yes | - | Returns the dword at +4 of a record. | low |
| `TargetMenu_GetDword8` | 0x10156960 | 8 | yes | - | Returns the dword at +8 of a record. | low |
| `TargetMenu_DtorVt103351D8` | 0x10156970 | 11 | yes | - | Destroys an object with vtable 0x103351D8. | low |
| `TargetMenu_SetVt103351D8` | 0x101569A0 | 9 | yes | - | Sets the object's vtable pointer to 0x103351D8. | low |
| `TargetMenu_ConstructFields` | 0x101569B0 | 62 | yes | - | Constructs the object (vtable 0x103351D8) and sets its fields. | low |
| `TargetMenu_SetFields` | 0x101569F0 | 77 | yes | - | Sets a menu item's type and its position and text fields. | medium |
| `TargetMenu_GetField10B` | 0x10156B20 | 4 | yes | - | Returns the field at +0x10. | low |
| `TargetMenu_GetField14` | 0x10156B30 | 4 | yes | - | Returns the value stored at offset 0x14 of the menu item. | low |
| `TargetMenu_GetField20` | 0x10156B40 | 4 | yes | - | Returns the value stored at offset 0x20 of the menu item. | low |
| `TargetMenu_PackString` | 0x10156B50 | 68 | yes | - | Packs one string into a buffer when it fits. | low |
| `TargetMenu_GetDword0` | 0x10156BA0 | 7 | yes | - | Returns the dword at +0 of a record. | low |
| `TargetMenu_DtorVt103351FC` | 0x10156BB0 | 11 | yes | - | Destroys an object with vtable 0x103351FC. | low |
| `TargetMenu_InitVt103351FC` | 0x10156BE0 | 16 | yes | - | Clears +4 and sets the object's vtable pointer to 0x103351FC. | low |
| `TargetMenu_SetField04` | 0x10156BF0 | 10 | yes | - | Stores a value at offset 4 of the string holder. | low |
| `TargetMenu_ConstructWithValue` | 0x10156C00 | 18 | yes | - | Constructs the object (vtable 0x103351FC) holding one value. | low |
| `TargetMenu_TableHolderCtor` | 0x10156D90 | 108 | yes | - | Constructs the object that holds table 0x3E for the scene. | low |
| `TargetMenu_LoadTable` | 0x10156E00 | 114 | yes | - | Reads table 0x3E's header from its file and allocates a row buffer. | low |
| `TargetMenu_TargetCtor` | 0x101575E0 | 34 | yes | - | Constructs the target object and resets its records. | low |
| `TargetMenu_ClearTargetAndRedraw` | 0x10157610 | 5 | yes | - | Clears the target field and redraws the menu (0x10157620). | low |
| `TargetMenu_ClearField68AndDraw` | 0x10157620 | 19 | yes | - | Clears the field at +0x68 and calls the menu manager's 0x1015E850. | low |
| `TargetMenu_SetTargetMode` | 0x10157660 | 131 | yes | - | Changes the target mode and runs the handler for it. | low |
| `TargetMenu_IsTargetUnusable` | 0x101576F0 | 43 | yes | - | Reports whether the current target actor is missing or in state 2/3. | low |
| `TargetMenu_SetNormalizedPos` | 0x10157720 | 83 | yes | - | Stores a screen position as values normalised to -1 to 1 about the screen centre. | medium |
| `TargetMenu_SetValues3` | 0x10157780 | 53 | yes | - | Copies up to three values into the widget's value array. | low |
| `TargetMenu_SetValues3Default` | 0x10157850 | 13 | yes | - | Sets the menu's three values from the table at 0x10335240. | low |
| `TargetMenu_SetFields78D0` | 0x10157860 | 20 | yes | - | Stores two values at offsets 0x78 and 0xD0 of the widget. | low |
| `TargetMenu_GetByte75` | 0x10157880 | 4 | yes | - | Returns the byte at this+0x75. | low |
| `TargetMenu_GetByte76` | 0x10157890 | 4 | yes | - | Returns the byte at this+0x76. | low |
| `TargetMenu_GetByte77` | 0x101578A0 | 4 | yes | - | Returns the byte at this+0x77. | low |
| `TargetMenu_GetWord80` | 0x101578B0 | 8 | yes | - | Returns the 16-bit value at this+0x80. | low |
| `TargetMenu_GetField7C` | 0x101578C0 | 4 | yes | - | Returns the value stored at offset 0x7C of the widget. | low |
| `Target_GetFlag82` | 0x101578D0 | 7 | yes | - | Returns the byte at offset 0x82 of the target record. | low |
| `Target_GetFlag83` | 0x101578E0 | 7 | yes | - | Returns the byte at offset 0x83 of the target record. | low |
| `Target_Reset` | 0x101578F0 | 184 | yes | - | Resets the target record and its two sub-records to their initial state. | medium |
| `TargetMenu_ClearFields84And88` | 0x101579B0 | 15 | yes | - | Sets the two fields at +0x84 and +0x88 to zero. | low |
| `Target_Update` | 0x101579C0 | 323 | yes | - | Per-frame update of the target selection, by scene state. | medium |
| `Target_Select` | 0x10157B40 | 278 | yes | - | Makes an actor the current target, moving the selection flag from the previous target. | medium |
| `Target_SelectByIndex` | 0x10157C60 | 73 | yes | - | Selects the actor at an index in the actor table as the target. | medium |
| `TargetMenu_GetTargetActorPtr74` | 0x10157CB0 | 51 | yes | - | Returns the address of the +0x74 member of the current target's actor (or of the window's selected one). | low |
| `TargetMenu_GetCachedUnlessFlag21` | 0x10157CF0 | 34 | yes | - | Returns the cached target, unless the target manager's flag at +0x21 is 1. | low |
| `Menu_IsFocusNotInList` | 0x10157D20 | 58 | yes | - | Returns 1 when the focused menu item is nonzero and is not found in the list at 0x10371ECC, otherwise 0. | low |
| `Target_FindCandidate` | 0x10157D60 | 185 | yes | - | Returns the first actor in the table that passes the candidate test for the target. | low |
| `Target_CycleMenuStep` | 0x10157E20 | 371 | yes | - | When a key check passes, advances the three-step counter at +0x68 (wrapping) and dispatches the menu for the new step. | low |
| `Target_IssueStateCommand` | 0x10157FA0 | 480 | yes | - | Runs a heal or sit command for the target actor, chosen by the actor's state. | medium |
| `Target_UpdateSelectionByState` | 0x101581E0 | 260 | yes | - | Each frame, when the target actor is in state 1 and no selection is held, selects the first candidate found. | low |
| `Target_InvokeFieldCallback` | 0x101582F0 | 243 | yes | - | Calls the callback stored at +0xd0 with the target's fields and passes the results on to another call. | low |
| `Target_UpdateActorFlags138` | 0x101583F0 | 119 | yes | - | Sets bits at +0x138 of the actor from the target's flags 0x82/0x83 and setting 0xC0. | medium |
| `Target_HasActor` | 0x10158470 | 12 | yes | - | Tests whether there is a current target actor. | medium |
| `Target_UpdateSelection` | 0x10158480 | 129 | yes | - | Validates the current and sub target records and clears them (sending /attackoff where needed) when they are no longer valid. | low |
| `Target_SendAttackOff` | 0x10158510 | 49 | yes | - | Sends the attackoff command for the current target when its owner flags require it. | medium |
| `Target_GetActor` | 0x10158550 | 53 | yes | - | Returns the current target actor, if it is valid. | medium |
| `Target_Clear` | 0x10158590 | 82 | yes | - | Clears the current target and its selection flag. | medium |
| `Target_RunActiveCommand` | 0x101585F0 | 441 | yes | - | Finds the active command in the table at 0x10371EE0 (fn_101587B0) and runs the matching target action. | low |
| `TargetMenu_FindActiveCommand` | 0x101587B0 | 52 | yes | - | Returns the result code of the first entry of a command table whose test (Unit100D7420_TestCommand36CF60) is active. | high |
| `TargetMenu_IsCommand76Or77Active` | 0x10158AA0 | 49 | yes | - | Returns whether command 0x76 or 0x77 (mode 4) is active. | high |
| `TargetMenu_MoveByDirectionIf58` | 0x10158AE0 | 32 | yes | - | Calls Unit1012AC80_MoveByDirection with the second argument when the flag at +0x58 is set and a condition on +0x59 or +0xc4 holds. | low |
| `Target_TrySubSelect` | 0x10158B00 | 54 | yes | - | Runs sub_10159BA0 when the target flags at +0x58/+0x59 allow it and command 0x76/0x77 is active. | low |
| `Target_ActOrTrySubSelect` | 0x10158B40 | 31 | yes | - | Runs the target action param_1, or the sub-select check when there is none. | high |
| `Target_CycleEntryTarget` | 0x10158B60 | 221 | yes | - | Picks the next target from the Unit101D7020 entry list; details not established. | low |
| `Target_CycleInView` | 0x10158C40 | 92 | yes | - | Steps the target to the next lower or higher candidate in view. | medium |
| `Target_CycleInViewOrFirst` | 0x10158CA0 | 234 | yes | - | Steps the target to the next lower or higher candidate in view, or picks the first one when there is no current target. | medium |
| `Target_PickNearestToPoint` | 0x10158D90 | 32 | yes | - | Picks the actor nearest to the stored point at +0x8C. | high |
| `Target_ApplyAction` | 0x10158DB0 | 565 | yes | - | Carries out a target action (with menu and sound side effects); details not established. | low |
| `Target_ClearAll` | 0x10158FF0 | 71 | yes | - | Clears the target, its display and its callback. | medium |
| `Target_CommitSubTarget` | 0x10159040 | 92 | yes | - | Makes the pending sub target the main target and leaves sub-target mode. | high |
| `Target_ClearAndSetFlag53` | 0x101590A0 | 14 | yes | - | Clears the target, then sets the flag at +0x53. | low |
| `Target_SetDisplayName` | 0x101590C0 | 171 | yes | - | Sets or clears the target name shown on the target window. | medium |
| `Target_SetFlagsFromMask` | 0x10159170 | 89 | yes | - | Sets the flags at +0x60 and +0x64 from the table entries whose key matches the input mask. | low |
| `Target_IsUsable` | 0x101591D0 | 142 | yes | - | Tests whether the current target is usable under its flags. | low |
| `TargetMenu_GetField84Ptr` | 0x10159370 | 7 | yes | - | Returns the address of the field at this+0x84. | low |
| `Yk_GetActiveEntryById` | 0x10159380 | 59 | yes | - | Returns the active Yk table entry whose id is the value at this+0x88, or 0 when there is none. | medium |
| `Actor_SetSlotTableEntry` | 0x10159400 | 26 | yes | - | - | - |
| `Target_DispatchByIndex` | 0x10159420 | 32 | yes | - | Calls a handler from a table by index. | low |
| `Target_SetIfUsable` | 0x10159440 | 134 | yes | - | Stores the given value at +0xc4 when the target is usable, otherwise resets the target's flags and record. | low |
| `Target_SetHandlerCc` | 0x101594D0 | 13 | yes | - | Stores a callback pointer at offset 0xCC of the target record. | low |
| `Target_SetHandlerC8` | 0x101594E0 | 13 | yes | - | Stores a callback pointer at offset 0xC8 of the target record. | low |
| `Target_ReleaseSelection` | 0x101594F0 | 60 | yes | - | Releases the current selection through its callback and clears its state. | medium |
| `Target_ResetRecordReturnSelf` | 0x10159530 | 12 | yes | - | Resets the target record and returns the same object pointer. | low |
| `Target_IsRecordStillValid` | 0x10159540 | 134 | yes | - | Tests whether a target record needs to be dropped (the sense of 1 versus 0 is not established). | low |
| `Target_CanTarget` | 0x101595D0 | 48 | yes | - | Tests whether the target's actor can be targeted. | low |
| `Target_SetActor` | 0x10159660 | 139 | yes | - | Sets the target record from an actor and returns whether it took it. | medium |
| `Target_ResetRecord` | 0x10159740 | 56 | yes | - | Resets a target sub-record to its initial values. | medium |
| `Target_RefreshActor` | 0x10159780 | 54 | yes | - | Resolves the entry, refreshes the cached actor and its field from it, or resets the target record. | medium |
| `Entry_InitKey` | 0x101597C0 | 40 | yes | - | Stores two values in an entry and computes its key at +0x24. | low |
| `Entry_ValidateKey` | 0x101597F0 | 50 | yes | - | Returns the entry when its stored key matches its fields. | low |
| `Entry_SetNameAndKey` | 0x10159830 | 80 | yes | - | Stores an entry's name and derived key. | low |
| `Target_GetPosShortsMainOrSub` | 0x10159880 | 29 | yes | - | Target_GetPosShorts of the main or (when param_3) the sub target record. | high |
| `Target_GetCachedIfValid` | 0x101598A0 | 14 | yes | - | Returns the cached pointer at +0xC when the valid flag at +0x20 is set, otherwise 0. | low |
| `Target_GetActorPtr` | 0x101598B0 | 4 | yes | - | Returns the actor pointer stored at this+8. | medium |
| `TargetMenu_IsWithinRadius` | 0x101598C0 | 68 | yes | - | Tests whether the target actor is within a radius of the entry. | medium |
| `Entry_MatchesPair` | 0x10159910 | 43 | yes | - | Tests whether an entry's two fields match the given pair. | low |
| `TargetMenu_MoveByDirection` | 0x10159970 | 147 | yes | - | Moves the target by one unit along a chosen axis. | low |
| `TargetMenu_ApplyOffset` | 0x10159A20 | 231 | yes | - | Applies a scaled offset to the tracked position. | low |
| `Camera_RotateVecYaw` | 0x10159B10 | 129 | yes | - | Rotates a point by the camera's yaw. | medium |
| `TargetMenu_GetPositionIfValid` | 0x10159C80 | 62 | yes | - | Copies the target's position to the output when it has one. | medium |
| `TargetMenu_GetOffsetFromCachedActor` | 0x10159CC0 | 117 | yes | - | Returns the target position relative to the cached target actor's position. | medium |
| `Target_GetPosShorts` | 0x10159D40 | 157 | yes | - | Asks the cached object for a point through its vtable and returns it as two shorts, or zeros with failure. | low |
| `Entry_ResolveValid` | 0x10159DE0 | 41 | yes | - | Returns the entry if it is valid and resolved. | low |
| `Entry_IsActorFieldMatch` | 0x10159E10 | 56 | yes | - | Tests whether the actor indexed by the pair's first value has its +0x78 field equal to the pair's second value. | low |
| `TargetMenu_FindRange` | 0x10159EB0 | 70 | yes | - | Finds the range entry of the table at DAT_1062180C that contains an id. | high |
| `TargetMenu_FindByFirstDword` | 0x10159FB0 | 53 | yes | - | Finds the table entry whose first dword equals the argument. | low |
| `TargetMenu_CallMember14CCSlot0` | 0x1015AF60 | 27 | yes | - | Calls vtable slot 0 with 1 on the object at +0x14CC, if any. | low |
| `TargetMenu_Init` | 0x1015AF80 | 29 | yes | - | Initialises the target object and resets its state. | low |
| `TargetMenu_ResetState` | 0x1015AFA0 | 482 | yes | - | Clears the target object's state fields. | low |
| `TargetMenu_IsCachedPtrMatch` | 0x1015B190 | 65 | yes | - | Tests whether the cached pointer at +0x14B0 matches the value read through +0x14B8 while the state flags are set. | low |
| `TargetMenu_GetObjectPtr` | 0x1015B270 | 7 | yes | - | Returns the object pointer stored at this+0x14CC. | low |
| `TargetMenu_RotateBufferOnce` | 0x1015B3C0 | 67 | yes | - | Once per state, rotates the 0x1400-byte buffer at +0xB0 and runs the object's and the helper's follow-up calls. | low |
| `TargetMenu_WrapTextLines` | 0x1015B410 | 353 | yes | - | Wraps the menu's one or two texts into at most 20 lines each, recording each line's length. | medium |
| `TargetMenu_FillSceneTable` | 0x1015B720 | 355 | yes | - | Clears the object and fills the global table at DAT_1062180C with scene table values. | medium |
| `TargetMenu_FindCachedEntry` | 0x1015B970 | 100 | yes | - | Looks up an id in the cache list, optionally moving the hit to the front. | medium |
| `TargetMenu_GetCachedOrLoad` | 0x1015B9E0 | 262 | yes | - | Returns the cached record for an id, loading it into the 100-entry cache when missing. | medium |
| `TargetMenu_FindEmptySlot` | 0x1015BAF0 | 132 | yes | - | Returns the address of the first slot whose first dword is zero, searching from the current index and wrapping, or 0. | medium |
| `TargetMenu_OnBufferEvent` | 0x1015BB80 | 76 | yes | - | Handles a callback on the menu: on event 0x1400 advances its text buffer, otherwise releases its object and resets it. | low |
| `TargetMenu_LookupObjectPtr` | 0x1015BD40 | 33 | yes | - | Looks up a record by the parameter and returns its object pointer, or 0. | low |
| `TargetMenu_RotateBits3` | 0x1015D7F0 | 34 | yes | - | Rotates each byte of a 0x1400-byte buffer left by three bits. | medium |
| `MenuMng_ReinitState` | 0x1015D860 | 25 | yes | - | Resets the menu manager's state and reinitialises it. | low |
| `MenuMng_Init` | 0x1015D900 | 156 | yes | - | - | - |
| `MenuMng_ResetFields` | 0x1015D9A0 | 35 | yes | - | Resets the menu manager's fields to their defaults. | low |
| `NetCellFont_InsertSortedBy60` | 0x1015DB10 | 88 | yes | - | Inserts a node into the list after the last node whose byte at +0x60 is 4 or less. | low |
| `Menu_SetFlag76` | 0x1015DB70 | 15 | yes | - | Sets the menu object's +0x76 flag. | low |
| `TargetMenu_MenuForwardItem8` | 0x1015DBB0 | 31 | yes | - | Forwards the item at +8 of param_1 to sub_1015DB80. | high |
| `NetCellFont_RemoveMatching` | 0x1015DBD0 | 64 | yes | - | Removes every list node whose value equals the given value. | medium |
| `Menu_FindItemByName` | 0x1015DC10 | 89 | yes | - | Finds a menu item by its 16-byte name. | medium |
| `Menu_LookupWindowByName` | 0x1015DC70 | 109 | yes | - | Looks up a menu window by name in a fixed table. | low |
| `TargetMenu_MenuTest48OrStateB4` | 0x1015DCE0 | 26 | yes | - | Returns whether the object at DAT_105781CC has its flag at +0x48 set or is in state B4==1. | medium |
| `Menu_HandleEvent` | 0x1015DD00 | 76 | yes | - | Dispatches a menu event to the cursor and child handlers. | low |
| `Menu_TrackCursor` | 0x1015DD90 | 192 | yes | - | Tracks the cursor over the menu and adjusts its hold value. | low |
| `Menu_HandleCursorSelect` | 0x1015DE50 | 132 | yes | - | Handles a cursor selection on a menu item. | low |
| `TargetMenu_MenuHasFocusedItemFwd` | 0x1015DEE0 | 5 | yes | - | Menu_HasFocusedItem. | high |
| `Menu_DispatchEvent6` | 0x1015DEF0 | 26 | yes | - | Sends menu event 6 when the cursor is in the active state. | low |
| `Menu_DispatchEvent7` | 0x1015DF20 | 37 | yes | - | Sends menu event 7 under a condition. | low |
| `TargetMenu_GetCursorPos` | 0x1015DF60 | 27 | yes | - | Copies the cursor's position to the output. | medium |
| `TargetMenu_Nop` | 0x1015DFC0 | 3 | yes | - | Does nothing. | low |
| `Menu_FindItemByNameAt1C` | 0x1015E030 | 89 | yes | - | Finds a menu item by name in the list at +0x1C. | low |
| `MenuMng_TestNameForSceneState` | 0x1015E0F0 | 344 | yes | - | Tests, from the menu name table's flags, whether the named menu passes for the current scene state. | medium |
| `MenuMng_OpenByName` | 0x1015E350 | 466 | yes | - | - | - |
| `MenuMng_AttachWindowAndPosition` | 0x1015E530 | 427 | yes | - | Finds the window for a menu item, makes the item its owner, shows its help/title, resets the cursor and positions the window by the item's flags. | medium |
| `TargetMenu_MenuItemFade` | 0x1015E6E0 | 174 | yes | - | Passes a menu item through sub_10118830 and Unit100D7420_MenuStartFade/InvokeCallback7C (kind 0xE items only set the flag +0x75). | low |
| `TargetMenu_MenuInitAndFadeItem` | 0x1015E790 | 73 | yes | - | Initialises a menu item on first use (vtable slot 2 of its +0xC member) and passes it to fn_1015E6E0. | low |
| `Menu_FindFirstActiveItem` | 0x1015E7E0 | 78 | yes | - | Returns the first menu item in the list that is not hidden or disabled. | medium |
| `Menu_SetItemAt54` | 0x1015E850 | 74 | yes | - | Replaces the item stored at this+0x54 with the argument, releases the old and new items, and resets the cursor to the menu when the new item is non-null. | low |
| `Menu_RemoveAndFreeItem` | 0x1015E8A0 | 109 | yes | - | Finds the item in the menu list, removes it, clears its entries and child, and deletes it. | medium |
| `Menu_CloseEntry` | 0x1015E910 | 56 | yes | - | Looks up a menu entry and destroys its drawn menu if one is open. | medium |
| `Menu_FindWindowDefByName` | 0x1015E950 | 209 | yes | - | Finds a menu window definition by name and fills the caller's record from it. | medium |
| `Menu_CloseQuery` | 0x1015EB60 | 13 | yes | - | Closes the menu named menu_query. | medium |
| `TargetMenu_SetMinId6C` | 0x1015EC20 | 43 | yes | - | Raises (or with param_2 forces) the 16-bit value at +0x6C. | high |
| `Menu_FindByName` | 0x1015EC50 | 102 | yes | - | Returns whether a menu item with the given name exists. | medium |
| `Menu_FindByFlags34` | 0x1015ECC0 | 76 | yes | - | Returns whether a menu item has any of the given +0x34 flags. | medium |
| `Menu_FindByFlags38` | 0x1015ED10 | 108 | yes | - | Finds a menu item by a +0x38 mask. | low |
| `Menu_IsFocusedItem` | 0x1015ED80 | 36 | yes | - | Tests whether an item is the current focused item. | medium |
| `Menu_HasFocusedItem` | 0x1015EDB0 | 26 | yes | - | Tests whether there is a usable focused item. | medium |
| `TargetMenu_MenuTestItem34Or6B` | 0x1015EDD0 | 45 | yes | - | Tests a menu item by bit 2 of +0x34 (0), byte +0x6B (1) and then the items at +0x54/+0x5C; what the result means is not established. | low |
| `Menu_NextVisibleItem` | 0x1015EE00 | 31 | yes | - | Advances a menu list iterator and skips items flagged at +0x70. | low |
| `TargetMenu_GetNodeIfNotClosed` | 0x1015EE20 | 31 | yes | - | Returns the item from sub_10126550 unless its flag at +0x70 is set. | high |
| `Menu_OpenMenuWindowWhenIdle` | 0x1015EE40 | 85 | yes | - | Opens the menu window when no target is active. | medium |
| `Menu_CallSlot30ForEachEntry` | 0x1015EEF0 | 46 | yes | - | For each non-null object in the menu entry table, calls its virtual method at offset 0x30. | low |
| `Menu_CallChildSlot34ForEachItem` | 0x1015EF20 | 51 | yes | - | For each item in the list, calls the virtual method at offset 0x34 on the item's child object if present. | low |
| `MenuMng_UpdateForSceneState` | 0x1015EF60 | 866 | yes | - | Each frame, applies menu update flags to the menu windows when the scene state, session, target kind or event state changes, and handles a few menu commands. | medium |
| `Menu_ApplyFlagsToItems` | 0x1015F3E0 | 692 | yes | - | Applies a bitmask of menu update requests to each menu window entry. | low |
| `Menu_DrawLayers` | 0x1015F6A0 | 180 | yes | 1 | Draws the menu items layer by layer, with the cursor, between the 2D state setup and teardown. | medium |
| `UI_DockReset` | 0x1015F760 | 46 | yes | - | - | - |
| `Menu_PositionWindow` | 0x1015F790 | 350 | yes | - | Places a menu window beside its anchor window. | medium |
| `TargetMenu_MenuGetItemRect` | 0x1015F8F0 | 105 | yes | - | Gets the screen rect of a menu item. | medium |
| `Menu_GetDwordAt8C` | 0x1015F960 | 27 | yes | - | Returns the dword in the table at this+0x8C, indexed by the value fn_1015F980 yields. | low |
| `TargetMenu_ResolveLayoutIndex` | 0x1015F980 | 61 | yes | - | Chooses the layout index: 0 becomes 0 or 4 from setting 0xB4 and DAT_10621940. | high |
| `TargetMenu_MenuGetLayoutWord` | 0x1015F9C0 | 31 | yes | - | Returns the layout word for an index after Unit1012AC80_ResolveLayoutIndex. | high |
| `Menu_GetWordPtrAtA0` | 0x1015F9E0 | 27 | yes | - | Returns a pointer into the word table at this+0xA0, indexed by the value fn_1015F980 yields. | low |
| `Menu_DrawAll` | 0x1015FA00 | 1995 | yes | 1 | - | - |
| `Menu_GetNormalizedPos` | 0x101601D0 | 59 | yes | - | Returns the menu position scaled to a 640 by 480 space. | medium |
| `TargetMenu_GetScaledPos80` | 0x10160210 | 59 | yes | - | Returns the position at +0x80/+0x82 as fractions of 640x480. | high |
| `MenuMng_GetOffsetX` | 0x10160290 | 36 | yes | - | - | - |
| `MenuMng_GetOffsetY` | 0x101602C0 | 36 | yes | - | - | - |
| `Menu_ReloadResource` | 0x10160440 | 112 | yes | - | Replaces the menu's loaded resource with a new one. | medium |
| `Gfx_SetDefault2DStates` | 0x101604B0 | 402 | yes | 0 | - | - |
| `Gfx_DisableFogAndAlphaBlend` | 0x10160650 | 69 | yes | 0 | - | - |
| `Menu_GetStateB4` | 0x101606F0 | 7 | yes | - | Returns the byte stored at this+0xB4. | low |
| `Menu_IsStateB4Eq1` | 0x10160700 | 11 | yes | - | Tests whether the byte at this+0xB4 equals 1. | medium |
| `Menu_SetStateB4` | 0x10160710 | 47 | yes | - | Sets the byte at this+0xB4 to the argument when the value is below 2 and the bytes at +0xB2 and +0xB3 are zero. | low |
| `MenuMng_BuildMenuName` | 0x10160760 | 300 | yes | - | Builds the 16-character menu resource name ('menu    ' + name) for a menu, with the long variants of the macro menus when the flag is clear. | medium |
| `TargetMenu_OpenNoticeDialog101608B0` | 0x10160960 | 89 | yes | - | Opens a dialog with one of three messages chosen by the session flags and the callback 0x101608B0. | low |
| `YkWindows_DestroyDrawMenuIfAt14` | 0x101609C0 | 39 | yes | - | If the callback slot at +0x14 is LAB_101608B0, clears it and destroys the drawn menu at +0x8. | medium |
| `TargetMenu_OpenNoticeDialog101608D0` | 0x101609F0 | 86 | yes | - | Opens a dialog with one of three messages chosen by the session flags and the callback 0x101608D0. | low |
| `YkWindows_CloseIfAt14` | 0x10160A50 | 23 | yes | - | Closes the dialog on DAT_10664520 when its +0x14 slot equals LAB_101608D0. | medium |
| `TargetMenu_GetByteAE` | 0x10160C80 | 7 | yes | - | Returns the menu manager's byte at +0xAE. | low |
| `Menu_GetFocusedItem` | 0x10160C90 | 4 | yes | - | Returns the current focused menu item. | medium |
| `TargetMenu_CtorVt10335334` | 0x10160DB0 | 29 | yes | - | Constructor of the object with vtable 0x10335334. | high |
| `TargetMenu_CtorVt10335350` | 0x10161110 | 29 | yes | - | Constructor of the object with vtable 0x10335350. | high |
| `TargetMenu_CtorVt1033536C` | 0x10161380 | 32 | yes | - | Constructor of the object with vtable 0x1033536C. | high |
| `TargetMenu_CtorVt10335388` | 0x101615E0 | 29 | yes | - | Constructor of the object with vtable 0x10335388. | high |
| `TargetMenu_CtorVt10335410` | 0x10161850 | 25 | yes | - | Constructor of the object with vtable 0x10335410. | high |
| `TargetMenu_SetByte5A` | 0x10161870 | 10 | yes | - | Sets the object's byte at +0x5A. | low |
| `TargetMenu_ReturnTrue` | 0x10161890 | 3 | yes | - | Returns true. | low |
| `TargetMenu_ReturnZero` | 0x101618D0 | 3 | yes | - | Returns 0. | low |
| `TargetMenu_CallSlot17Then1626E0` | 0x10161970 | 27 | yes | - | Runs slot 17 and then 0x101626E0 with one argument. | low |
| `TargetMenu_DrawImageAtRightOfRect` | 0x10161990 | 261 | yes | 2 | Draws an image chosen from the table at 0x10578474 (by 0x1014FF70 and setting 0xB4) at a position computed from the layout's rectangle and the menu offset. | low |
| `TargetMenu_CtorVt10335470` | 0x10161B80 | 29 | yes | - | Constructs a screen-sized UI object with vtable 0x10335470. | low |
| `TargetMenu_ReturnFalse` | 0x10161BA0 | 3 | yes | - | Returns false. | low |
| `TargetMenu_HasActiveObject10621940` | 0x10161BC0 | 21 | yes | - | Reports whether the object 0x10621940 holds something at +8. | low |
| `TargetMenu_Return8` | 0x10161BE0 | 6 | yes | - | Returns 8. | low |
| `Menu_PositionWindowBySetting` | 0x10161C70 | 230 | yes | - | Places this object's window relative to another window, choosing the offset by the setting value 0xB4. | low |
| `TargetMenu_DrawImageA4AtRightOfRect` | 0x10161D60 | 217 | yes | 2 | Draws the image at 0x10578474+0xA4 at the position 0x10161990 uses. | low |
| `TargetMenu_InitFromScreenRect` | 0x10161ED0 | 183 | yes | - | Initialises the object's fields and vtable, sizing two fields from the screen rectangle less 0xA0. | low |
| `TargetMenu_SetTopByte` | 0x10161FF0 | 30 | yes | - | Sets the top byte of a dword. | low |
| `Viewport_SetClipped` | 0x10162010 | 157 | yes | 1 | Sets the viewport to the requested range clipped to the render target. | medium |
| `Gfx_ApplyViewport1904` | 0x101620B0 | 17 | yes | 1 | - | - |
| `Font_SetupAdditiveDraw` | 0x101620D0 | 22 | yes | 1 | Sets additive blending and binds the font glyph texture for drawing. | medium |
| `TargetMenu_ScrollBackStep` | 0x101624B0 | 70 | yes | - | Moves the list's scroll position back one line and its second counter back by 20. | low |
| `TargetMenu_StepToward` | 0x10162CC0 | 146 | yes | - | Returns the first value moved one step towards the second. | medium |
| `TargetMenu_SetFlag58AndResetScroll` | 0x10162E00 | 23 | yes | - | Sets the flag at +0x58 and puts the scroll back to its first-line position. | low |
| `TargetMenu_SetLineCount` | 0x10162E20 | 58 | yes | - | Sets the window's line count (4 to 24, else 24) and resets its scroll. | low |
| `TargetMenu_SetShownLines` | 0x10162E60 | 40 | yes | - | Sets how many lines are shown (only when the flag at +0x58 allows it) and resets the scroll. | low |
| `TargetMenu_ResetScrollFwd` | 0x10162E90 | 5 | yes | - | Resets the window's scroll position. | low |
| `TargetMenu_ResetScrollToLines` | 0x10162EF0 | 15 | yes | - | Sets the scroll position to the line height times the line count. | low |
| `TargetMenu_OpenOrCloseByFlag` | 0x10162F30 | 39 | yes | - | Calls one of the window's two functions (0x10163050 or 0x10163020) by the argument. | low |
| `TargetMenu_UpdatePair1062193C` | 0x10162F60 | 67 | yes | - | Updates the two objects 0x10621940 and 0x1062193C. | low |
| `TargetMenu_ApplySlot20Result` | 0x10162FB0 | 37 | yes | - | Passes an object's slot-20 result to 0x10162FE0. | low |
| `TargetMenu_ToggleTo` | 0x10162FE0 | 51 | yes | - | Switches the window to the state given, returning -1 or 1 for the direction, or 0 when it is already there. | low |
| `TargetMenu_SetWord56` | 0x10163070 | 12 | yes | - | Sets the window's word at +0x56. | low |
| `TargetMenu_GetShortAt56` | 0x10163080 | 5 | yes | - | Returns the short stored at this+0x56. | low |
| `TargetMenu_CtorZeroed` | 0x10163090 | 20 | yes | - | Constructs a zeroed object. | low |
| `TargetMenu_ZeroWordsAndDwords` | 0x10163350 | 29 | yes | - | Zeroes four word fields at the start of the object and then the three dwords through Unit1012AC80_ZeroDwords. | low |
| `TargetMenu_NoOpE` | 0x10163380 | 1 | yes | - | Does nothing. | low |
| `MenuTextBlock_DrawBgRect` | 0x10163390 | 15 | yes | 1 | - | - |
| `TargetMenu_ZeroDwords` | 0x101633D0 | 13 | yes | - | Zeroes a 3-component dword vector. | medium |
| `Gfx_DrawSolidRect2D` | 0x10163400 | 534 | yes | 0 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `TargetMenu_DoNothing1Arg` calls nothing directly
- `TargetMenu_FillEntriesFromTable1036F390` calls `sub_1012AF30`, `NetCellFont_SelectEntryMoveCursor`
- `TargetMenu_UpdateActionMenu` calls `TargetMenu_MenuItemFade`, `MenuMng_AttachWindowAndPosition`, `ActorHandle_Resolve`, `TargetMenu_MenuInitAndFadeItem`, `Target_HasActor`, `Target_GetActorPtr`, `YkCommon_ActorPairTest1FF`, `CXiActor::IsFlag1d0Clear`, `Acter_IsState5`, `Acter_IsState55`, `TargetMenu_FillEntriesFromTable1036F390`, `TargetMenu_GetMessageFwd`, `TargetMenu_SetTextFwd`, `sub_1011A8F0`, `NetCellFont_SelectEntryMoveCursor`, `UI_DockReset`, `YkWindows_GetState10664390`, `TargetMenu_Is1FFDifferentFromActer`, `TargetMenu_ForwardToPanel`, `Menu_HasFocusedItem`, `TargetMenu_GetCursorPos`, `Menu_IsFocusedItem`, `NetCellFont_HitTest`, `NetCellFont_PickEntry`, `NetCellFont_TestCommand36CF60`, `Camera_GetFrameScale`, `sub_10311C2C`
- `TargetMenu_ConstructVt103333C8` calls `NetCellFont_ClearWords`
- `TargetMenu_ClearEntry1Flags` calls `NetCellFont_ClearEntryFlags`
- `TargetMenu_ConstructVt10333410` calls `NetCellFont_ClearWords`
- `TargetMenu_ConstructVt10333458` calls `NetCellFont_ClearWords`
- `TargetMenu_ConstructVt103334A0` calls `NetCellFont_ClearWords`
- `TargetMenu_ConstructVt10333500` calls `NetCellFont_ClearWords`
- `TargetMenu_DestroyDraw` calls `TargetMenu_MenuInitAndFadeItem`
- `TargetMenu_ConstructVt103335E8` calls `NetCellFont_ClearWords`, `Allocator_Generic`
- `TargetMenu_ClearThenSetGlobal` calls `NetCellFont_ClearWords`, `NetCellFont_SetGlobal104B1774`
- `TargetMenu_GetActiveEntry16` calls nothing directly
- `TargetMenu_ResolveEntries` calls `NetCellFont_GetSlotPtr`, `sub_1015BC40`
- `TargetMenu_ConstructVt10333648` calls nothing directly
- `TargetMenu_ConstructVt10333660` calls `TargetMenu_ConstructVt10333648`
- `TargetMenu_ConstructVt10333670` calls `NetCellFont_ClearWords`
- `TargetMenu_ConstructVt10333728` calls `TargetMenu_ConstructVt10333670`, `TargetMenu_ConstructVt10333660`, `Allocator_Generic`
- `TargetMenu_ConstructVt103337E0` calls `TargetMenu_ConstructVt10333670`, `Allocator_Generic`
- `TargetMenu_Is1FFDifferentFromActer` calls nothing directly
- `TargetMenu_ConstructVt10333898` calls `TargetMenu_ConstructVt10333670`
- `TargetMenu_ConstructVt10333908` calls `NetCellFont_ClearWords`, `NetCellFont_Clear`, `NetCellFont_FreeListsAndReset`
- `TargetMenu_UpdateLayout` calls `sub_10119110`, `NetCellFont_ClearFlag12FromValue`, `NetCellFont_MarkDirty`, `NetCellFont_GetRect`, `NetCellFont_SetRectAndUpdateNodes`, `sub_1015DB80`, `NetCellFont_GetHead`
- `TargetMenu_LayoutMessage` calls `NetCellFont_InitTextLayout`, `NetCellFont_FindByKeyByte`, `NetCellFont_SetString`, `NetCellFont_GetField20`, `Allocator_Generic`, `TargetMenu_ClearBlock`, `sub_1012A4F0`, `sub_101284F0`, `NetCellFont_PushBack`, `ChatLog_AddMessage`, `NetCellFont_CallClearBuffers`
- `TargetMenu_SetPosition` calls nothing directly
- `TargetMenu_ClearBlock` calls `NetCellFont_ClearWords`
- `TargetMenu_ConstructVt10333950` calls `TargetMenu_ConstructVt103339F0`
- `TargetMenu_CloseRem4lineMenu` calls `Menu_CloseEntry`
- `TargetMenu_ConstructVt103339A0` calls `TargetMenu_ConstructVt103339F0`
- `TargetMenu_CloseRem4li2Menu` calls `Menu_CloseEntry`
- `TargetMenu_ConstructVt103339F0` calls `TargetMenu_ConstructVt10333908`
- `TargetMenu_ConstructVt10333A40` calls `TargetMenu_ConstructVt10333AE0`
- `TargetMenu_ConstructVt10333A90` calls `TargetMenu_ConstructVt10333AE0`
- `TargetMenu_ConstructVt10333AE0` calls `TargetMenu_ConstructVt10333908`
- `TargetMenu_CollectEntries` calls `NetCellFont_GetHead`, `sub_10126520`
- `TargetMenu_HasFreeEntryNotKind12` calls `NetCellFont_FindFreeEntry`
- `TargetMenu_ConstructVt10333B68` calls `NetCellFont_ClearWords`
- `TargetMenu_ConstructVt10333BB0` calls `NetCellFont_ClearWords`, `TargetMenu_ClearRanges`
- `TargetMenu_ClearRanges` calls nothing directly
- `TargetMenu_IsAlwaysTrue` calls nothing directly
- `TargetMenu_ConstructVt10333CB0` calls `NetCellFont_ClearWords`, `Allocator_Generic`
- `TargetMenu_ConstructVt10333D10` calls `NetCellFont_ClearWords`
- `TargetMenu_CallIfNot3` calls `sub_10139FE0`
- `TargetMenu_TickHelp` calls `TargetMenu_AdvanceHelpTimer`, `TargetMenu_ResetHelpAndTitle`, `sub_1013A160`, `sub_1013A1A0`
- `TkHelp_AdvanceTimer` calls `Camera_GetFrameScale`, `sub_10311C2C`
- `TargetMenu_IsEvent` calls `IsEvent`
- `TargetMenu_AdvanceHelpTimer` calls `TargetMenu_IsEvent`, `sub_1013A470`, `sub_10150D60`, `TkHelp_AdvanceTimer`
- `TargetMenu_ResetHelpAndTitle` calls `TargetMenu_SetTextFwd`, `TargetMenu_ForwardToPanel`, `MenuPanels_SelectShownLine`
- `TargetMenu_ConstructVt10333D18` calls `NetCellFont_ClearWords`, `MenuPanels_InitPanelState`
- `TargetMenu_ForwardToPanel` calls `MenuPanels_SetEntryText`
- `TargetMenu_TickMember20AndHelp` calls `sub_102213E0`, `TargetMenu_TickHelp`
- `TargetMenu_DrawPanel` calls `Gfx_SetAdditiveBlend`, `Font_BindGlyphTexture`, `MenuPanels_Draw`, `sub_1011AE80`, `NetCellFont_GetRect`, `sub_1011FB60`
- `TargetMenu_CtorVt10333D78` calls `NetCellFont_ClearWords`
- `TargetMenu_CtorVt10333DD8` calls `NetCellFont_ClearWords`
- `TargetMenu_CtorVt10333E20` calls `TargetMenu_CtorVt10333EC0`
- `TargetMenu_CtorVt10333E70` calls `TargetMenu_CtorVt10333EC0`
- `TargetMenu_CtorVt10333EC0` calls `NetCellFont_ClearWords`, `TargetMenu_InitFields1CTo3A7`
- `TargetMenu_InitFields1CTo3A7` calls nothing directly
- `TargetMenu_Forward1013E590` calls `TargetMenu_PlaceByLayout`
- `TargetMenu_InitFromTables` calls `TargetMenu_GetWindowRect`, `YkCommon_GetIndexed`, `TargetMenu_Forward1013E590`, `TargetMenu_SetRowCount`, `Allocator_Generic`, `YkCommon_Init`, `YkCommon_ResizeEntries`, `Scene_GetTableValue`, `YkCommon_LoadTable`
- `TargetMenu_Call1013E560` calls `TargetMenu_GetWindowRect`
- `TargetMenu_SetRowCount` calls `sub_1011A8F0`, `UI_DockReset`, `TargetMenu_Forward1013E590`
- `TargetMenu_OpenWithOptions` calls `TargetMenu_InitFields1CTo3A7`, `MenuMng_OpenByName`
- `TargetMenu_DockWindowLeft` calls `UI_DockReset`
- `TargetMenu_GetWindowRect` calls `NetCellFont_GetRect`
- `TargetMenu_PlaceByLayout` calls `sub_101602F0`, `sub_10119110`
- `TargetMenu_CtorVt10333F28` calls `NetCellFont_ClearWords`
- `TargetMenu_Is100EBE60Positive` calls `sub_100EBE60`
- `TargetMenu_InitFromShape` calls `NetCellFont_ClearWords`, `ShapeMng_FindShape`
- `TargetMenu_SetupMenuEntriesByState` calls `IsEvent`, `NetCellFont_ClearEntryFlags`, `NetCellFont_GetFlagsMasked`, `Acter_IsFlag40DB6OrState17`, `TargetMenu_GetMessageFwd`, `sub_1011ADE0`, `NetCellFont_SetStateByIndex`, `NetCellFont_SetEntryValue4C`, `sub_10140070`, `sub_1011AE50`, `YkWindows_IsWithin23Seconds`, `YkWindows_IsSingleUncheckedEntry`, `sub_10037EF0`, `TargetMenu_MenuInitAndFadeItem`
- `TargetMenu_UpdateEntryStates` calls `NetCellFont_GetFlagsMasked`, `Acter_IsFlag40DB6OrState17`, `Acter_HasEntryForWord40D7C`, `YkCommon_Test104DFD98Field40C3CZero`, `NetCellFont_FindEntryValueById`, `NetCellFont_SetStateByIndex`, `TargetMenu_GetMessageFwd`, `NetCellFont_SetEntryValue4C`, `YkWindows_IsSingleUncheckedEntry`, `YkWindows_IsWithin23Seconds`
- `TargetMenu_ReadWindowRect14` calls `NetCellFont_GetRect`
- `TargetMenu_ReadWindowRect14IfSet` calls `NetCellFont_GetRect`
- `TargetMenu_CtorVt10334070` calls `NetCellFont_ClearWords`
- `TargetMenu_CtorVt103340D0` calls `NetCellFont_ClearWords`
- `TargetMenu_DestroyDrawMenu` calls `TargetMenu_MenuInitAndFadeItem`
- `TargetMenu_CtorVt10334200` calls `NetCellFont_ClearWords`, `TargetMenu_ConstructVt10333660`
- `TargetMenu_CtorVt10334260` calls `NetCellFont_ClearWords`
- `TargetMenu_CreateAll` calls `NetCellFont_ClearWords`, `Allocator_Generic`, `TargetMenu_Construct`
- `TargetMenu_Construct` calls `NetCellFont_ClearWords`
- `TargetMenu_CtorVt10334928` calls `NetCellFont_ClearWords`, `Allocator_Generic`, `TargetMenu_CtorVt10334970`, `TargetMenu_Set`, `TargetMenu_CtorVt103349B8`, `TargetMenu_CtorVt10334A00`, `TargetMenu_Construct`, `YkWndList_Construct`, `TargetMenu_SetCopy`, `TargetMenu_CtorVt10334AB8`, `TargetMenu_CtorVt10335350`, `TargetMenu_CtorVt10334B28`, `TargetMenu_CtorVt1033536C`, `YkWindows_Init`, `TargetMenu_CtorVt10334B98`, `TargetMenu_CtorVt10334C08`, `TargetMenu_CtorVt10335388`
- `TargetMenu_Set` calls nothing directly
- `TargetMenu_SetCopy` calls nothing directly
- `TargetMenu_CtorVt10334970` calls `NetCellFont_ClearWords`
- `TargetMenu_CtorVt103349B8` calls `NetCellFont_ClearWords`
- `TargetMenu_CtorVt10334A00` calls `NetCellFont_ClearWords`
- `YkWndList_Construct` calls `Yk_InitBase`, `YkWindows_SetField18AndRemainder`
- `TargetMenu_CtorVt10334AB8` calls `Yk_InitBase`, `YkWindows_SetField18AndRemainder`
- `TargetMenu_CtorVt10334B28` calls `Yk_InitBase`, `YkWindows_SetField18AndRemainder`
- `TargetMenu_CtorVt10334B98` calls `Yk_InitBase`, `YkWindows_SetField18AndRemainder`
- `TargetMenu_CtorVt10334C08` calls `Yk_InitBase`, `YkWindows_SetField18AndRemainder`
- `TargetMenu_CtorVt10334D00` calls `NetCellFont_ClearWords`, `Allocator_Generic`
- `TargetMenu_CtorVt10334D60` calls `NetCellFont_ClearWords`
- `TargetMenu_CtorVt10334DC0` calls `NetCellFont_ClearWords`, `NetCellFont_Clear`, `NetCellFont_FreeListsAndReset`, `TargetMenu_FillTable13CMinusOne`
- `TargetMenu_FillTable13CMinusOne` calls `TargetMenu_Fill8DwordsMinusOne`
- `TargetMenu_Fill8DwordsMinusOne` calls nothing directly
- `TargetMenu_CtorVt10334E58` calls `NetCellFont_ClearWords`, `ShapeMng_FindShape`
- `TargetMenu_CtorVt10334EB8` calls `NetCellFont_ClearWords`, `ShapeMng_FindShape`
- `TargetMenu_CtorVt10334F18` calls `NetCellFont_ClearWords`
- `TargetMenu_UpdateTargetMarker` calls `Target_GetCachedIfValid`, `TargetMenu_MenuInitAndFadeItem`, `Camera_GetFrameScale`, `sub_10311C2C`, `Target_GetPosShortsMainOrSub`
- `TargetMenu_DockAndInit` calls `YkCommon_GetIndexed`, `UI_DockReset`, `NetCellFont_GetRect`, `TargetMenu_CopyList6To78`
- `TargetMenu_ReadWindowRects` calls `NetCellFont_GetRect`
- `TargetMenu_SetName` calls `sub_10312050`
- `TargetMenu_SetField48` calls nothing directly
- `TargetMenu_CopyList6To78` calls `YkCommon_GetIndexed`
- `TargetMenu_CtorVt10334F78` calls `NetCellFont_ClearWords`, `MenuPanels_InitPanelState`
- `TargetMenu_SetTextFwd` calls `TargetMenu_SetText`
- `TargetMenu_SetText` calls `DmsgText_WrapSjisAt`, `MenuPanels_SetEntryText`
- `TargetMenu_IsField8Zero` calls nothing directly
- `TargetMenu_CtorVt10335060` calls `NetCellFont_ClearWords`, `TargetMenu_ClearFields`, `Allocator_Generic`
- `TargetMenu_ClearFields` calls nothing directly
- `TargetMenu_GetMessageFwd` calls `TargetMenu_GetMessage`
- `TargetMenu_GetMessage` calls `DmsgText_IsBound`, `DmsgText_GetCellCol0`, `TargetMenu_GetEntryPtrByLayout`
- `TargetMenu_Clear32` calls nothing directly
- `TargetMenu_ReleaseAll32` calls `TargetMenu_ReleaseOne`
- `TargetMenu_ReleaseOne` calls `sub_10312EAD`
- `TargetMenu_LoadMessageBlock` calls `FileMng_ResolveOrExit`, `sub_10312F96`, `TextInputFiles_ForwardOrExit`
- `TargetMenu_GetEntryPtr` calls nothing directly
- `TargetMenu_GetEntryPtrByLayout` calls `TargetMenu_GetEntryPtr`
- `TargetMenu_GetEntryWord3E` calls nothing directly
- `TargetMenu_IsMinus6Word` calls nothing directly
- `TargetMenu_FormatMessage4` calls `TargetMenu_FormatMessageWithArgs`
- `TargetMenu_FormatMessage5` calls `TargetMenu_FormatMessageWithArgs`
- `TargetMenu_Read2Byte7Bit` calls nothing directly
- `TargetMenu_ReadArgCode` calls `TargetMenu_Read2Byte7Bit`
- `TargetMenu_FormatDecimal` calls nothing directly
- `TargetMenu_Call101532B0OnWordBE` calls nothing directly
- `TargetMenu_ExpandMessageCodes` calls `TargetMenu_GetMessageFwd`, `TargetMenu_Call101532B0OnWordBE`, `TargetMenu_IsMinus6Word`, `TargetMenu_GetEntryWord3E`, `TargetMenu_ReadArgCode`, `TargetMenu_Read2Byte7Bit`, `TargetMenu_FormatDecimal`, `sub_10312050`, `TargetMenu_LookupObjectPtr`, `DmsgText_IsInSjisSet`, `DmsgText_ClearListHeader`, `DmsgText_AppendNodeType2`, `DmsgText_AppendString`, `DmsgText_AppendValueNode`, `TextInputFiles_Init`, `DmsgText_ComposeTextA`, `TextInputFiles_GetCStr`, `TextInputFiles_Free`, `sub_102590E0`, `DmsgText_ClearHead`, `DmsgText_AppendTypeTwo`, `DmsgText_AppendStringNode`, `DmsgText_AppendIdString`, `DmsgText_ComposeTextB`, `sub_1025A800`
- `TargetMenu_FormatMessageWithArgs` calls `TargetMenu_GetMessageFwd`, `TargetMenu_GetEntryWord3E`, `TargetMenu_ExpandMessageCodes`
- `TargetMenu_LoadMessageBlocksSetA` calls `TargetMenu_LoadMessageBlock`
- `TargetMenu_LoadMessageBlocksSetB` calls `TargetMenu_LoadMessageBlock`
- `TargetMenu_LoadAllMessageTables` calls `sub_10153B70`, `TargetMenu_LoadMessageBlocksSetA`, `TargetMenu_LoadMessageBlocksSetB`, `Scene_GetTableValue`, `TargetMenu_LoadMessageBlock`, `TargetMenu_LoadStringTable`
- `TargetMenu_LoadStringTable` calls `FileMng_ResolveOrExit`, `Allocator_Generic`, `TextInputFiles_ForwardOrExit`, `DmsgText_GetDMsgTable`, `DmsgText_Assign`
- `TargetMenu_DtorVt103350EC` calls nothing directly
- `TargetMenu_GetInstance` calls `TargetMenu_MessageSetCtor`, `sub_10313486`
- `TargetMenu_MessageSetCtor` calls `MenuPanels_Clear`, `DmsgText_Clear`
- `TargetMenu_LoadMessageSetByState` calls `DmsgText_GetDwordEntry`, `TargetMenu_CtorVt10335174`, `sub_101540A0`, `TargetMenu_GetField8`, `TextInputFiles_AssignWhole`, `sub_10155500`, `TargetMenu_CtorVt1033515C`, `TargetMenu_GetMember14`, `TargetMenu_DtorVt1033515C`, `TargetMenu_CtorVt1033512C`, `TargetMenu_GetInnerPtr10`, `sub_10154D70`, `TargetMenu_CtorVt10335168`, `TargetMenu_GetMemberC`, `sub_10155320`
- `TargetMenu_IndexOf` calls nothing directly
- `TargetMenu_GetByValue` calls `TargetMenu_IndexOf`, `TargetMenu_GetEntryOrEmpty`
- `TargetMenu_GetEntryOrEmpty` calls nothing directly
- `TargetMenu_LoadMessageSet` calls `Scene_GetTableValue`, `sub_10257860`, `FileMng_ResolveOrExit`, `Allocator_Generic`, `TextInputFiles_ForwardOrExit`, `operator_delete`, `DmsgText_GetDMsgTable`, `DmsgText_Assign`, `DmsgText_GetRowCount`, `TextInputFiles_Init`, `DmsgText_GetRowBase`, `TargetMenu_LoadMessageSetByState`, `TextInputFiles_GetField4_1018D490`, `MenuPanels_Alloc`, `TextInputFiles_GetCStr`, `MenuPanels_Append`, `TextInputFiles_Free`, `DmsgText_BindSource`, `DmsgText_CallFreeData`
- `TargetMenu_ReleaseField7C` calls `operator_delete`
- `TargetMenu_UpdatePendingRead` calls `Scene_GetTableValue`, `TextInputFiles_FileMngFindFileNumKind1`, `TargetMenu_ReleaseField7C`
- `TargetMenu_GetCount` calls nothing directly
- `TargetMenu_GetWordAt` calls nothing directly
- `TargetMenu_DtorVt103350F8` calls nothing directly
- `TargetMenu_CtorVt103350F8` calls nothing directly
- `Entry_Init6` calls nothing directly
- `Entry_ReleaseField4` calls `operator_delete`
- `TargetMenu_CtorVt1033512C` calls `TargetMenu_CtorVt103350F8`
- `TargetMenu_SetEntryWithStrings` calls `Allocator_Generic`, `Entry_Init6`
- `TargetMenu_GetInnerPtr10` calls nothing directly
- `TargetMenu_DtorVt10335138` calls nothing directly
- `TargetMenu_CtorVt10335138` calls nothing directly
- `Entry_SetFields4` calls nothing directly
- `TargetMenu_DtorVt1033515C` calls `Entry_ReleaseField4Zero`, `TargetMenu_DtorVt10335138`, `TargetMenu_DtorVt103350EC`
- `Entry_ReleaseField4Zero` calls `operator_delete`
- `TargetMenu_CtorVt1033515C` calls `TargetMenu_CtorVt10335138`
- `TargetMenu_Assign` calls `Allocator_Generic`, `Entry_SetFields4`
- `TargetMenu_GetMember14` calls nothing directly
- `TargetMenu_FreeBuffer` calls `operator_delete`
- `TargetMenu_CtorVt10335168` calls `TargetMenu_SetVt103351D8`
- `TargetMenu_SetItemWithStrings` calls `Allocator_Generic`, `TargetMenu_SetFields`
- `TargetMenu_GetMemberC` calls nothing directly
- `TargetMenu_FreeStrings` calls `operator_delete`
- `TargetMenu_CtorVt10335174` calls `TargetMenu_InitVt103351FC`
- `TargetMenu_SetString` calls `Allocator_Generic`, `TargetMenu_SetField04`
- `TargetMenu_GetField8` calls nothing directly
- `TargetMenu_Pack` calls nothing directly
- `TargetMenu_PackRecord7` calls nothing directly
- `TargetMenu_ReadDword00_10155D10` calls nothing directly
- `TargetMenu_ReadDword04_10155D20` calls nothing directly
- `TargetMenu_ReadDword08_10155D30` calls nothing directly
- `TargetMenu_ReadDword0C_10155D40` calls nothing directly
- `TargetMenu_ReadDword10_10155D50` calls nothing directly
- `TargetMenu_ReadDword14_10155D60` calls nothing directly
- `TargetMenu_ReadDword18_10155D70` calls nothing directly
- `TargetMenu_ConstructText10335180` calls `TargetMenu_InitTextRecord`
- `TargetMenu_ConstructText10335180B` calls `TargetMenu_InitTextRecordB`
- `TargetMenu_InitTextRecord` calls `Sjis_GetCharByteLen`
- `TargetMenu_InitTextRecordB` calls `Sjis_GetCharByteLen`
- `TargetMenu_GetField0C` calls nothing directly
- `TargetMenu_GetField10` calls nothing directly
- `TargetMenu_GetField24` calls nothing directly
- `TargetMenu_GetField28` calls nothing directly
- `TargetMenu_PackRecord3` calls nothing directly
- `TargetMenu_ReadDword00_101565C0` calls nothing directly
- `TargetMenu_ReadDword04_101565D0` calls nothing directly
- `TargetMenu_ReadDword08_101565E0` calls nothing directly
- `TargetMenu_ConstructStringPair` calls `TargetMenu_InitStringPair`
- `TargetMenu_InitStringPair` calls `DmsgText_IsInSjisSet`
- `TargetMenu_GetField04` calls nothing directly
- `TargetMenu_GetField08` calls nothing directly
- `TargetMenu_GetField10A` calls nothing directly
- `TargetMenu_PackRecordBytes` calls nothing directly
- `TargetMenu_GetByte0` calls nothing directly
- `TargetMenu_GetByte1` calls nothing directly
- `TargetMenu_GetDword4` calls nothing directly
- `TargetMenu_GetDword8` calls nothing directly
- `TargetMenu_DtorVt103351D8` calls nothing directly
- `TargetMenu_SetVt103351D8` calls nothing directly
- `TargetMenu_ConstructFields` calls `TargetMenu_SetFields`
- `TargetMenu_SetFields` calls nothing directly
- `TargetMenu_GetField10B` calls nothing directly
- `TargetMenu_GetField14` calls nothing directly
- `TargetMenu_GetField20` calls nothing directly
- `TargetMenu_PackString` calls nothing directly
- `TargetMenu_GetDword0` calls nothing directly
- `TargetMenu_DtorVt103351FC` calls nothing directly
- `TargetMenu_InitVt103351FC` calls nothing directly
- `TargetMenu_SetField04` calls nothing directly
- `TargetMenu_ConstructWithValue` calls nothing directly
- `TargetMenu_TableHolderCtor` calls `DmsgText_Clear`, `TextInputFiles_EntriesCtorEmpty`, `Scene_GetTableValue`
- `TargetMenu_LoadTable` calls `TextInputFiles_AllocEntries`, `Scene_GetTableValue`, `TextInputFiles_EntriesSetCount`, `TextInputFiles_SubmitFileOrExit`, `DmsgText_BindSource`, `DmsgText_GetStride`, `Allocator_Generic`
- `TargetMenu_TargetCtor` calls `Target_ResetRecordReturnSelf`, `Target_Reset`, `TargetMenu_ClearFields84And88`
- `TargetMenu_ClearTargetAndRedraw` calls `TargetMenu_ClearField68AndDraw`
- `TargetMenu_ClearField68AndDraw` calls `Menu_SetItemAt54`
- `TargetMenu_SetTargetMode` calls `TargetMenu_IsTargetUnusable`, `ActorHandle_Resolve`, `Target_GetCachedIfValid`, `Target_DispatchByIndex`
- `TargetMenu_IsTargetUnusable` calls `ActorHandle_Resolve`
- `TargetMenu_SetNormalizedPos` calls nothing directly
- `TargetMenu_SetValues3` calls nothing directly
- `TargetMenu_SetValues3Default` calls `TargetMenu_SetValues3`
- `TargetMenu_SetFields78D0` calls nothing directly
- `TargetMenu_GetByte75` calls nothing directly
- `TargetMenu_GetByte76` calls nothing directly
- `TargetMenu_GetByte77` calls nothing directly
- `TargetMenu_GetWord80` calls nothing directly
- `TargetMenu_GetField7C` calls nothing directly
- `Target_GetFlag82` calls nothing directly
- `Target_GetFlag83` calls nothing directly
- `Target_Reset` calls `Target_ResetRecord`
- `TargetMenu_ClearFields84And88` calls nothing directly
- `Target_Update` calls `TargetMenu_MenuTest48OrStateB4`, `NetCellFont_TestCommand36CF60`, `TargetMenu_ClearFields84And88`, `Acter_GetGlobalFlag`, `TargetMenu_IsTargetUnusable`, `TargetMenu_SetTargetMode`, `Target_UpdateSelection`, `IsEvent`, `Target_IssueStateCommand`, `Target_InvokeFieldCallback`, `Target_UpdateActorFlags138`, `Target_CycleMenuStep`, `Target_RefreshActor`, `Target_RunActiveCommand`, `Target_UpdateSelectionByState`
- `Target_Select` calls `Target_ClearAndSetFlag53`, `IsEvent`, `Entry_ValidateKey`, `Target_GetCachedIfValid`, `Target_SetActor`, `MusicTrack_SetVolumeId0010`, `MusicTrack_SetVolumeId0009`, `Target_SetDisplayName`, `Target_GetActorPtr`, `Yk_SetCurrentIndex`, `Entry_MatchesPair`, `TargetMenu_SetTargetMode`
- `Target_SelectByIndex` calls `Entry_IsActorFieldMatch`, `Target_Select`
- `TargetMenu_GetTargetActorPtr74` calls `YkWindows_GetSelectedActerFieldA0`, `Target_GetActorPtr`
- `TargetMenu_GetCachedUnlessFlag21` calls `Target_GetCachedIfValid`
- `Menu_IsFocusNotInList` calls `Menu_GetFocusedItem`
- `Target_FindCandidate` calls `ActorHandle_Resolve`, `Acter_IsBytes1FFBothIn89NotEqual`
- `Target_CycleMenuStep` calls `Menu_FindByFlags34`, `Menu_IsFocusNotInList`, `Menu_HasFocusedItem`, `NetCellFont_TestCommand36CF60`, `IsEvent`, `MusicTrack_SetVolumeId0013`, `Menu_SetItemAt54`, `TargetMenu_MenuForwardItem8`, `sub_1015E830`, `Cell_SetFlag104E1C3C`
- `Target_IssueStateCommand` calls `NetCellFont_TestCommand36CF60`, `ActorHandle_Resolve`, `Settings_GetValue`, `sub_10123970`, `sub_10311FF1`, `Command_RunLine`, `SetMusicTrackVolume_A`
- `Target_UpdateSelectionByState` calls `NetCellFont_TestCommand36CF60`, `TargetMenu_SetTargetMode`, `Target_DispatchByIndex`, `Target_GetCachedIfValid`, `ActorHandle_Resolve`, `Target_GetActorPtr`, `Target_FindCandidate`, `Target_SelectByIndex`
- `Target_InvokeFieldCallback` calls `Acter_GetActerAt10485F7A`, `TargetMenu_GetByte75`, `TargetMenu_GetByte77`, `TargetMenu_GetByte76`, `TargetMenu_GetWord80`, `TargetMenu_GetField7C`, `Settings_GetValue`, `Acter_SetFieldsAt134And138`
- `Target_UpdateActorFlags138` calls `Acter_GetActerAt10485F7A`, `Target_GetFlag82`, `Target_GetFlag83`, `Settings_GetValue`, `Acter_SetFlagBits138`
- `Target_HasActor` calls `Target_GetActor`
- `Target_UpdateSelection` calls `Target_IsRecordStillValid`, `Target_ResetRecord`, `Menu_ApplyFlagsToItems`, `Menu_CallChildSlot34ForEachItem`, `TargetMenu_SetTargetMode`, `Target_SendAttackOff`, `Target_Clear`, `Target_ClearAll`
- `Target_SendAttackOff` calls `Target_GetCachedIfValid`, `Command_RunLine`
- `Target_GetActor` calls `Entry_ValidateKey`, `Entry_IsActorFieldMatch`
- `Target_Clear` calls `Target_GetCachedIfValid`, `Target_ResetRecord`, `TargetMenu_SetValues3`, `TargetMenu_SetFields78D0`
- `Target_RunActiveCommand` calls `TargetMenu_FindActiveCommand`, `TextInputFiles_IsModeFourOrFive`, `FontGlyphCache_IsStateTwo`, `Target_ActOrTrySubSelect`, `Target_HasActor`, `sub_101587F0`, `Acter_IsFlag40DB6OrState17`, `MenuMng_OpenByName`, `MusicTrack_SetVolumeId0011`, `Target_GetCachedIfValid`, `Target_ApplyAction`, `Cell_SetFlag104E1C3C`
- `TargetMenu_FindActiveCommand` calls `NetCellFont_TestCommand36CF60`
- `TargetMenu_IsCommand76Or77Active` calls `NetCellFont_TestCommand36CF60`
- `TargetMenu_MoveByDirectionIf58` calls `TargetMenu_MoveByDirection`
- `Target_TrySubSelect` calls `TargetMenu_IsCommand76Or77Active`, `sub_10159BA0`
- `Target_ActOrTrySubSelect` calls `sub_101587F0`, `Target_TrySubSelect`
- `Target_CycleEntryTarget` calls `Entry_ValidateKey`, `YkWindows_UpdateEntryCycle`, `YkWindows_FindActiveEntryById`, `YkWindows_GetCurrentEntry`, `ActorHandle_Resolve`
- `Target_CycleInView` calls `Entry_ValidateKey`, `Target_GetCachedIfValid`, `CXiActor::FindNearestHigherInView`, `CXiActor::FindNearestLowerInView`, `ActorHandle_Resolve`
- `Target_CycleInViewOrFirst` calls `Entry_ValidateKey`, `Target_GetCachedIfValid`, `CXiActor::FindNearestHigherInView`, `CXiActor::FindNearestLowerInView`, `Target_FindNearestOnLocalPositiveX`
- `Target_PickNearestToPoint` calls `CXiActor::FindNearestToPoint`
- `Target_ApplyAction` calls `Target_GetActorPtr`, `Target_GetCachedIfValid`, `Entry_ValidateKey`, `Entry_SetNameAndKey`, `MusicTrack_SetVolumeId0009`, `Target_CommitSubTarget`, `NetCellFont_GetFlagsMasked`, `TextCommand_TargetActionToPacket`, `Acter_GetActerAt10485F7A`, `Target_CanTarget`, `CXiActor::IsFlag1d0Clear`, `Acter_IsFlag40DB6OrState17`, `MenuMng_OpenByName`, `MusicTrack_SetVolumeId0011`
- `Target_ClearAll` calls `Target_SetDisplayName`, `Target_Clear`, `Target_CommitSubTarget`
- `Target_CommitSubTarget` calls `Target_GetCachedIfValid`, `Target_Select`, `Target_ResetRecord`, `TargetMenu_SetTargetMode`
- `Target_ClearAndSetFlag53` calls `Target_Clear`
- `Target_SetDisplayName` calls `Target_GetActorPtr`, `ActorHandle_Resolve`, `TargetMenu_SetField48`, `TargetMenu_SetName`, `sub_1011BA40`, `MenuMng_OpenByName`, `Menu_CloseEntry`, `sub_100814F0`
- `Target_SetFlagsFromMask` calls `YkCommon_CC4F0ActorTest400`
- `Target_IsUsable` calls `Target_HasActor`, `Target_GetActorPtr`, `YkCommon_ActorPairTest1FF`, `sub_101587F0`, `YkCommon_ActorTest1D0`
- `TargetMenu_GetField84Ptr` calls nothing directly
- `Yk_GetActiveEntryById` calls `TargetMenu_GetField84Ptr`, `Yk_FindIndexById`, `Yk_GetActiveEntry`
- `Actor_SetSlotTableEntry` calls nothing directly
- `Target_DispatchByIndex` calls nothing directly
- `Target_SetIfUsable` calls `Target_SetFlagsFromMask`, `Target_HasActor`, `Target_GetCachedIfValid`, `Target_SetActor`, `Target_IsUsable`, `Target_ResetRecord`
- `Target_SetHandlerCc` calls nothing directly
- `Target_SetHandlerC8` calls nothing directly
- `Target_ReleaseSelection` calls `Target_CommitSubTarget`
- `Target_ResetRecordReturnSelf` calls `Target_ResetRecord`
- `Target_IsRecordStillValid` calls `Entry_ResolveValid`, `Acter_GetActerAt10485F7A`, `Target_CanTarget`, `TargetMenu_IsWithinRadius`
- `Target_CanTarget` calls `Acter_IsBytes1FFBothIn89NotEqual`
- `Target_SetActor` calls `Target_ResetRecord`, `Entry_InitKey`, `CXiActor::GetField78Of70`, `Target_RefreshActor`
- `Target_ResetRecord` calls nothing directly
- `Target_RefreshActor` calls `Entry_ResolveValid`, `Target_ResetRecord`
- `Entry_InitKey` calls nothing directly
- `Entry_ValidateKey` calls nothing directly
- `Entry_SetNameAndKey` calls `sub_10312050`
- `Target_GetPosShortsMainOrSub` calls `Target_GetPosShorts`
- `Target_GetCachedIfValid` calls nothing directly
- `Target_GetActorPtr` calls nothing directly
- `TargetMenu_IsWithinRadius` calls `ActorHandle_Resolve`, `Target_GetCachedIfValid`, `CXiActor::IsWithinRadius`
- `Entry_MatchesPair` calls `Entry_ValidateKey`
- `TargetMenu_MoveByDirection` calls `TargetMenu_ApplyOffset`
- `TargetMenu_ApplyOffset` calls `Target_GetCachedIfValid`, `Camera_GetFrameScale`, `sub_10311C2C`, `Settings_GetValue`, `Camera_RotateVecYaw`, `ZoneMap_QueryBoxHeightGlobal`
- `Camera_RotateVecYaw` calls `Camera_GetField50`, `MathVector_ReturnThis`, `Mat4_SetIdentity`, `Mat4_PostRotateY`, `Mat4_TransformPointInPlace`, `MathVector_Nop`
- `TargetMenu_GetPositionIfValid` calls nothing directly
- `TargetMenu_GetOffsetFromCachedActor` calls `Target_GetCachedIfValid`, `TargetMenu_GetPositionIfValid`
- `Target_GetPosShorts` calls `Target_GetCachedIfValid`, `TargetMenu_GetPositionIfValid`, `sub_10311C2C`
- `Entry_ResolveValid` calls `Entry_ValidateKey`, `Entry_IsActorFieldMatch`
- `Entry_IsActorFieldMatch` calls nothing directly
- `TargetMenu_FindRange` calls nothing directly
- `TargetMenu_FindByFirstDword` calls nothing directly
- `TargetMenu_CallMember14CCSlot0` calls `NetCellFont_NoOp`
- `TargetMenu_Init` calls `NetCellFont_ClearWords`, `TargetMenu_ResetState`
- `TargetMenu_ResetState` calls nothing directly
- `TargetMenu_IsCachedPtrMatch` calls nothing directly
- `TargetMenu_GetObjectPtr` calls nothing directly
- `TargetMenu_RotateBufferOnce` calls `TargetMenu_RotateBits3`, `TargetMenu_FindRange`, `TargetMenu_WrapTextLines`
- `TargetMenu_WrapTextLines` calls `DmsgText_WrapLine`, `sub_103151D0`
- `TargetMenu_FillSceneTable` calls `NetCellFont_Clear`, `NetCellFont_FreeListsAndReset`, `Scene_GetTableValue`
- `TargetMenu_FindCachedEntry` calls `NetCellFont_GetHead`, `sub_10126520`, `NetCellFont_Remove`, `NetCellFont_PushFront`
- `TargetMenu_GetCachedOrLoad` calls `TargetMenu_FindCachedEntry`, `TargetMenu_IsCachedPtrMatch`, `TargetMenu_FindRange`, `NetCellFont_GetTail`, `NetCellFont_GetCount`, `NetCellFont_Remove`, `TargetMenu_ResetState`, `TargetMenu_FindEmptySlot`, `TextInputFiles_FileMngQueueLoad`, `NetCellFont_PushFront`
- `TargetMenu_FindEmptySlot` calls nothing directly
- `TargetMenu_OnBufferEvent` calls `TargetMenu_RotateBufferOnce`, `sub_10159FF0`, `TargetMenu_ResetState`
- `TargetMenu_LookupObjectPtr` calls `TargetMenu_GetCachedOrLoad`, `TargetMenu_GetObjectPtr`
- `TargetMenu_RotateBits3` calls nothing directly
- `MenuMng_ReinitState` calls `MenuMng_ResetFields`, `sub_1015EEA0`
- `MenuMng_Init` calls `MenuMng_ResetFields`
- `MenuMng_ResetFields` calls nothing directly
- `NetCellFont_InsertSortedBy60` calls `NetCellFont_GetTail`, `NetCellFont_NextActiveValue`, `NetCellFont_InsertAfter`, `NetCellFont_PushBack`
- `Menu_SetFlag76` calls nothing directly
- `TargetMenu_MenuForwardItem8` calls `sub_1015DB80`
- `NetCellFont_RemoveMatching` calls `NetCellFont_GetHead`, `sub_10126520`, `NetCellFont_Remove`
- `Menu_FindItemByName` calls `NetCellFont_GetHead`, `sub_10126520`, `sub_10312940`
- `Menu_LookupWindowByName` calls `sub_10312940`
- `TargetMenu_MenuTest48OrStateB4` calls `Menu_IsStateB4Eq1`
- `Menu_HandleEvent` calls `TargetMenu_MenuTest48OrStateB4`, `Menu_HasFocusedItem`, `Menu_IsStateB4Eq1`, `NetCellFont_MenuMoveSelection`, `Menu_OpenMenuWindowWhenIdle`
- `Menu_TrackCursor` calls `Menu_HasFocusedItem`, `NetCellFont_HitTest`, `NetCellFont_PickEntry`, `NetCellFont_SelectEntryMoveCursor`, `Menu_HandleEvent`, `Camera_GetFrameScale`, `sub_10311C2C`
- `Menu_HandleCursorSelect` calls `NetCellFont_PickEntry`, `Menu_HandleEvent`, `SetMusicTrackVolume_Tag0004`
- `TargetMenu_MenuHasFocusedItemFwd` calls `Menu_HasFocusedItem`
- `Menu_DispatchEvent6` calls `Menu_HandleEvent`
- `Menu_DispatchEvent7` calls `FontGlyphCache_IsStateTwo`, `Cell_TestGlobal1036E3A0Mask`, `Menu_HandleEvent`
- `TargetMenu_GetCursorPos` calls nothing directly
- `TargetMenu_Nop` calls nothing directly
- `Menu_FindItemByNameAt1C` calls `NetCellFont_GetHead`, `sub_10126520`, `sub_10312940`
- `MenuMng_TestNameForSceneState` calls `sub_10312940`, `IsEvent`, `NetCellFont_GetTail`, `NetCellFont_NextActiveValue`
- `MenuMng_OpenByName` calls `MenuMng_BuildMenuName`, `Menu_LookupWindowByName`, `MenuMng_TestNameForSceneState`, `Menu_FindItemByNameAt1C`, `Menu_FindItemByName`, `Menu_FindWindowDefByName`, `NetCellFont_SelectFirstVisible`, `NetCellFont_MenuReleaseItemCount`, `Menu_FindByFlags38`, `Menu_SetFlag76`, `Allocator_Generic`, `NetCellFont_MenuCtor`, `NetCellFont_Rebuild`, `NetCellFont_SetState10ForIndex58`, `NetCellFont_InsertSortedBy60`, `MenuMng_AttachWindowAndPosition`, `sub_1015DB80`
- `MenuMng_AttachWindowAndPosition` calls `Cell_SetFlag104E1C3C`, `NetCellFont_MenuReleaseItemCount`, `Menu_LookupWindowByName`, `NetCellFont_SetChildOwner`, `NetCellFont_ApplyHelpAndTitle`, `Cursor_ResetPositionToMenu`, `Menu_GetDwordAt8C`, `Menu_PositionWindow`, `NetCellFont_FindFreeEntry`, `NetCellFont_StopFade`, `NetCellFont_StartFade`, `NetCellFont_GetTail`, `NetCellFont_NextActiveValue`, `TargetMenu_MenuInitAndFadeItem`
- `TargetMenu_MenuItemFade` calls `sub_10118830`, `Cell_SetFlag104E1C3C`, `NetCellFont_MenuStartFade`, `NetCellFont_InvokeCallback7C`
- `TargetMenu_MenuInitAndFadeItem` calls `NetCellFont_CallMember0CSlot2`, `TargetMenu_MenuItemFade`
- `Menu_FindFirstActiveItem` calls `NetCellFont_GetTail`, `NetCellFont_NextActiveValue`
- `Menu_SetItemAt54` calls `NetCellFont_SetActive`, `Cursor_ResetPositionToMenu`
- `Menu_RemoveAndFreeItem` calls `NetCellFont_GetTail`, `NetCellFont_NextActiveValue`, `NetCellFont_ClearEntries`, `NetCellFont_RemoveMatching`, `NetCellFont_FreeChild`, `NetCellFont_DeleteAllEntries`, `operator_delete`
- `Menu_CloseEntry` calls `MenuMng_BuildMenuName`, `Menu_FindItemByName`, `TargetMenu_MenuInitAndFadeItem`
- `Menu_FindWindowDefByName` calls nothing directly
- `Menu_CloseQuery` calls `Menu_CloseEntry`
- `TargetMenu_SetMinId6C` calls `NetCellFont_GetTail`
- `Menu_FindByName` calls `NetCellFont_GetHead`, `Menu_NextVisibleItem`, `sub_10312940`
- `Menu_FindByFlags34` calls `NetCellFont_GetHead`, `Menu_NextVisibleItem`
- `Menu_FindByFlags38` calls `NetCellFont_GetHead`, `Menu_NextVisibleItem`
- `Menu_IsFocusedItem` calls nothing directly
- `Menu_HasFocusedItem` calls nothing directly
- `TargetMenu_MenuTestItem34Or6B` calls nothing directly
- `Menu_NextVisibleItem` calls `sub_10126520`
- `TargetMenu_GetNodeIfNotClosed` calls `NetCellFont_NextActiveValue`
- `Menu_OpenMenuWindowWhenIdle` calls `TextInputFiles_IsModeFourOrFive`, `MenuMng_OpenByName`
- `Menu_CallSlot30ForEachEntry` calls nothing directly
- `Menu_CallChildSlot34ForEachItem` calls `NetCellFont_GetHead`, `sub_10126520`, `NetCellFont_InvokeChild34`
- `MenuMng_UpdateForSceneState` calls `Menu_ApplyFlagsToItems`, `Cell_SetGlobal1036E3A0`, `NetCellFont_ClearGlobalLists2150And2154`, `TextInputFiles_RunPairB`, `TextInputFiles_RunPairA`, `Menu_CallSlot30ForEachEntry`, `ActorHandle_Resolve`, `Acter_IsEvent`, `IsEvent`, `NetCellFont_TestCommand36CF60`, `Menu_GetStateB4`, `Menu_SetStateB4`, `Menu_IsStateB4Eq1`, `Cell_SetFlag104E1C3C`, `TextInputFiles_IsModeFourOrFive`, `YkCommon_IsActorField170`, `Menu_FindByFlags34`, `ChatLog_AddTableMessage7`, `TargetMenu_OpenNoticeDialog101608D0`, `TargetMenu_OpenNoticeDialog101608B0`, `YkWindows_DestroyDrawMenuIfAt14`, `YkWindows_CloseIfAt14`
- `Menu_ApplyFlagsToItems` calls `Menu_HasAnyFlag`, `Menu_CloseEntry`, `TargetMenu_ClearTargetAndRedraw`, `Acter_IsFlag40DB6OrState17`, `MenuMng_OpenByName`, `Target_ReleaseSelection`, `YkWindows_RunCallbackAndResetTarget`, `TargetMenu_ClearField68AndDraw`, `TextInputFiles_GetSetting41`, `TextInputFiles_Call10311386`
- `Menu_DrawLayers` calls `Gfx_SetDefault2DStates`, `MenuTextBlock::MenuTextBlock_Draw`, `NetCellFont_CursorUpdateEdgeAxes`, `TargetMenu_MenuTest48OrStateB4`, `MenuPanels_SendMenuEventByKind`, `NetCellFont_GetHead`, `Menu_NextVisibleItem`, `Menu_IsStateB4Eq1`, `Menu_DrawWindowItems`, `sub_10124EB0`, `Gfx_DisableFogAndAlphaBlend`
- `UI_DockReset` calls `Menu_GetDwordAt8C`, `Menu_PositionWindow`
- `Menu_PositionWindow` calls `IsEvent`, `NetCellFont_GetRect`, `NetCellFont_FindFreeEntry`, `sub_10119110`
- `TargetMenu_MenuGetItemRect` calls `NetCellFont_GetRect`
- `Menu_GetDwordAt8C` calls `TargetMenu_ResolveLayoutIndex`
- `TargetMenu_ResolveLayoutIndex` calls `Settings_GetValue`
- `TargetMenu_MenuGetLayoutWord` calls `TargetMenu_ResolveLayoutIndex`, `Menu_GetWordPtrAtA0`
- `Menu_GetWordPtrAtA0` calls `TargetMenu_ResolveLayoutIndex`
- `Menu_DrawAll` calls `NetCellFont_TestCommand36CF60`, `Menu_TrackCursor`, `Menu_HandleCursorSelect`, `TargetMenu_MenuHasFocusedItemFwd`, `Menu_DispatchEvent6`, `Menu_DispatchEvent7`, `TargetMenu_ResolveEntries`, `sub_101630C0`, `Gfx_SetDefault2DStates`, `MenuMng_UpdateForSceneState`, `NetCellFont_GetHead`, `sub_10126520`, `Menu_RemoveAndFreeItem`, `NetCellFont_RemoveMatching`, `NetCellFont_PushBack`, `NetCellFont_InsertBefore`, `NetCellFont_InsertSortedBy60`, `Menu_SetItemAt54`, `NetCellFont_GetCenter`, `Cursor_SetPosition`, `Menu_FindFirstActiveItem`, `Menu_GetWordPtrAtA0`, `Menu_GetDwordAt8C`, `TargetMenu_MenuGetItemRect`, `TargetMenu_MenuGetLayoutWord`, `Menu_SetPanelWord2A`, `Menu_NextVisibleItem`, `Menu_PositionWindow`, `sub_10125360`, `NetCellFont_GetTail`, `TargetMenu_GetNodeIfNotClosed`, `TargetMenu_MenuItemFade`, `MenuMng_AttachWindowAndPosition`, `MenuPanels_IsDone`, `TargetMenu_IsField8Zero`, `Camera_GetFrameScale`, `sub_10311C2C`, `NetCellFont_FindFreeEntry`, `MenuPanels_CallPanel1021F240And102203B0`, `FaqHelp_Update`, `MenuPanels_TickCounters`, `sub_10222DF0`, `sub_10226540`, `Menu_GetPanelByte0D`, `IsEvent`, `Menu_FindByFlags38`, `sub_101602F0`, `Menu_SetPanelWord28`, `MenuPanels_CallPanel1021EF10`, `Gfx_DisableFogAndAlphaBlend`, `MenuPanels_Call1021EF30If10666E84`
- `Menu_GetNormalizedPos` calls nothing directly
- `TargetMenu_GetScaledPos80` calls nothing directly
- `MenuMng_GetOffsetX` calls nothing directly
- `MenuMng_GetOffsetY` calls nothing directly
- `Menu_ReloadResource` calls `CMoResource::ReleaseChain`, `ResHandle_FreeIfUnreferenced`, `sub_101CC620`, `Cell_ResolveAllSubCells`
- `Gfx_SetDefault2DStates` calls nothing directly
- `Gfx_DisableFogAndAlphaBlend` calls nothing directly
- `Menu_GetStateB4` calls nothing directly
- `Menu_IsStateB4Eq1` calls nothing directly
- `Menu_SetStateB4` calls nothing directly
- `MenuMng_BuildMenuName` calls `sub_10312050`
- `TargetMenu_OpenNoticeDialog101608B0` calls `Acter_NoneOfIdsInTable`, `NetCellFont_GetFlags`, `TargetMenu_GetMessageFwd`, `YkWindows_Open`
- `YkWindows_DestroyDrawMenuIfAt14` calls `TargetMenu_MenuInitAndFadeItem`
- `TargetMenu_OpenNoticeDialog101608D0` calls `Acter_NoneOfIdsInTable`, `NetCellFont_GetFlags`, `TargetMenu_GetMessageFwd`, `YkWindows_Open`
- `YkWindows_CloseIfAt14` calls `YkWindows_Close`
- `TargetMenu_GetByteAE` calls nothing directly
- `Menu_GetFocusedItem` calls nothing directly
- `TargetMenu_CtorVt10335334` calls `YkCommon_Construct`
- `TargetMenu_CtorVt10335350` calls `YkCommon_Construct`
- `TargetMenu_CtorVt1033536C` calls `YkCommon_Construct`
- `TargetMenu_CtorVt10335388` calls `YkCommon_Construct`
- `TargetMenu_CtorVt10335410` calls `TargetMenu_InitFromScreenRect`
- `TargetMenu_SetByte5A` calls nothing directly
- `TargetMenu_ReturnTrue` calls nothing directly
- `TargetMenu_ReturnZero` calls nothing directly
- `TargetMenu_CallSlot17Then1626E0` calls `sub_101626E0`
- `TargetMenu_DrawImageAtRightOfRect` calls `sub_10162510`, `Settings_GetValue`, `sub_1014FF70`, `NetCellFont_GetRect`, `MenuMng_GetOffsetX`, `sub_10311C2C`, `sub_1011FB60`
- `TargetMenu_CtorVt10335470` calls `TargetMenu_InitFromScreenRect`
- `TargetMenu_ReturnFalse` calls nothing directly
- `TargetMenu_HasActiveObject10621940` calls nothing directly
- `TargetMenu_Return8` calls nothing directly
- `Menu_PositionWindowBySetting` calls `sub_101295D0`, `NetCellFont_GetRect`, `Settings_GetValue`, `sub_10119110`, `sub_101626E0`
- `TargetMenu_DrawImageA4AtRightOfRect` calls `sub_10162510`, `NetCellFont_GetRect`, `MenuMng_GetOffsetX`, `sub_10311C2C`, `sub_1011FB60`
- `TargetMenu_InitFromScreenRect` calls `NetCellFont_ClearWords`
- `TargetMenu_SetTopByte` calls nothing directly
- `Viewport_SetClipped` calls `CDx::GetRenderTargetTop`, `CDx::SetViewport`
- `Gfx_ApplyViewport1904` calls `CDx::SetViewport`
- `Font_SetupAdditiveDraw` calls `Gfx_SetAdditiveBlend`, `Font_BindGlyphTexture`
- `TargetMenu_ScrollBackStep` calls nothing directly
- `TargetMenu_StepToward` calls nothing directly
- `TargetMenu_SetFlag58AndResetScroll` calls `TargetMenu_ResetScrollToLines`
- `TargetMenu_SetLineCount` calls `TargetMenu_ResetScrollToLines`
- `TargetMenu_SetShownLines` calls `TargetMenu_ResetScrollToLines`
- `TargetMenu_ResetScrollFwd` calls `TargetMenu_ResetScrollToLines`
- `TargetMenu_ResetScrollToLines` calls nothing directly
- `TargetMenu_OpenOrCloseByFlag` calls `sub_10163050`, `sub_10163020`
- `TargetMenu_UpdatePair1062193C` calls `TargetMenu_ApplySlot20Result`, `TargetMenu_OpenOrCloseByFlag`
- `TargetMenu_ApplySlot20Result` calls `TargetMenu_ToggleTo`
- `TargetMenu_ToggleTo` calls `sub_10163050`, `sub_10163020`
- `TargetMenu_SetWord56` calls nothing directly
- `TargetMenu_GetShortAt56` calls nothing directly
- `TargetMenu_CtorZeroed` calls `TargetMenu_ZeroWordsAndDwords`
- `TargetMenu_ZeroWordsAndDwords` calls `TargetMenu_ZeroDwords`
- `TargetMenu_NoOpE` calls nothing directly
- `MenuTextBlock_DrawBgRect` calls `Gfx_DrawSolidRect2D`
- `TargetMenu_ZeroDwords` calls nothing directly
- `Gfx_DrawSolidRect2D` calls `CDx_SetDefaultRenderState`, `CDx::DrawPrimitiveUP`, `Gfx_SetDefault2DStates`
