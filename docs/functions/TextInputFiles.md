# TextInputFiles

Group: `Text` (by the file name only). Source: `sdk/tree_src/TextInputFiles.cpp`.

Why the file has this name (data/unit_names.json): FsTextInput_* (37), FsWordCompletion_* (24), FsLogPage_*, File_* and FileMng, Config_*, Event_Wait / Signal, the menus "keylayou", "macro", the command "/say " (an address range between two evidenced source files, holding several of the original files: named for its main contents)

544 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `unknown_libname_158` | 0x1018BBB0 | 9 | yes | - | - | - |
| `Time_SetNormalized` | 0x1018BBC0 | 19 | yes | - | Stores the normalized time value in the object and returns the object. | medium |
| `Time_Normalize` | 0x1018BC40 | 66 | yes | - | - | - |
| `Time_GetModulo60` | 0x1018BC90 | 13 | yes | - | Returns the time value at this modulo 60. | low |
| `Time_GetModulo3600Div60` | 0x1018BCA0 | 34 | yes | - | Returns the time value at this modulo 3600, divided by 60. | low |
| `Time_GetModulo216000Div3600` | 0x1018BCD0 | 34 | yes | - | Returns the time value at this modulo 216000, divided by 3600. | low |
| `Time_GetModulo5184000Div216000` | 0x1018BD00 | 34 | yes | - | Returns the time value at this modulo 5184000, divided by 216000. | low |
| `Time_GetDiv5184000` | 0x1018BD30 | 22 | yes | - | Returns the time value at this divided by 5184000. | low |
| `TextInputFiles_GetGameTimeValue` | 0x1018BDE0 | 135 | yes | - | Returns a game-time value from ntGameTimeGet, or one computed locally with the Time_ helpers when that is not available. | low |
| `Time_SetModulo60` | 0x1018BE80 | 45 | yes | - | Sets the time value modulo 60 to the argument, keeping the rest. | low |
| `Time_SetModulo3600Div60` | 0x1018BEB0 | 66 | yes | - | Sets the time value's modulo-3600 component divided by 60 to the argument, keeping the rest. | low |
| `Time_SetModulo216000Div3600` | 0x1018BF00 | 71 | yes | - | Sets the time value's modulo-216000 component divided by 3600 to the argument, keeping the rest. | low |
| `Time_FromHours` | 0x1018BF50 | 72 | yes | - | - | - |
| `Time_SetModulo155520000Div5184000` | 0x1018BFA0 | 75 | yes | - | Sets the count of 5184000-second units within each 155520000-second block to the argument, keeping the rest of the time. | medium |
| `Time_SetDiv155520000` | 0x1018C020 | 51 | yes | - | Sets the number of 155520000-second blocks in the time to the argument, keeping the remainder. | medium |
| `Time_GetDiv5184000Mul5184000` | 0x1018C1B0 | 42 | yes | - | Writes the time at DAT_1065CB1C rounded down to a multiple of 5184000 through the pointer argument. | medium |
| `Time_AddFrameScale` | 0x1018C270 | 27 | yes | - | Advances the time value by the frame scale times 25. | medium |
| `Time_SubtractFrameScale` | 0x1018C290 | 30 | yes | - | Moves the time value back by the frame scale times 25, and reports whether it went below zero. | medium |
| `fn_1018D170` | 0x1018D170 | 81 | yes | - | - | - |
| `TextInputFiles_GrowCapacity` | 0x1018D230 | 21 | yes | - | Returns the capacity to grow a string buffer to for a requested size. | medium |
| `TextInputFiles_Free` | 0x1018D250 | 40 | yes | - | Frees a string buffer's data and empties it. | medium |
| `TextInputFiles_InitEmpty` | 0x1018D280 | 34 | yes | - | Gives a string buffer a 0x40-byte empty allocation. | medium |
| `TextInputFiles_Init` | 0x1018D2B0 | 20 | yes | - | Initialises a string buffer to an empty string. | medium |
| `TextInputFiles_AssignCStr` | 0x1018D2D0 | 87 | yes | - | Replaces the buffer's contents with a NUL-terminated string. | medium |
| `TextInputFiles_AssignWhole` | 0x1018D430 | 15 | yes | - | Replaces the buffer's contents with a whole NUL-terminated string. | medium |
| `TextInputFiles_Append` | 0x1018D440 | 15 | yes | - | Appends a NUL-terminated string to the buffer. | medium |
| `TextInputFiles_AppendBuf` | 0x1018D450 | 28 | yes | - | Appends the contents of another string buffer. | medium |
| `TextInputFiles_GetCStr` | 0x1018D470 | 15 | yes | - | Returns the buffer's contents as a C string. | medium |
| `TextInputFiles_GetLength` | 0x1018D480 | 4 | yes | - | Returns the length of the string in the buffer. | medium |
| `TextInputFiles_GetField4_1018D490` | 0x1018D490 | 4 | yes | - | Returns the dword at +4. | high |
| `TextInputFiles_AssignN` | 0x1018D4A0 | 213 | yes | - | Replaces the buffer's contents with the first n characters of a string, or the whole string when n is -1. | medium |
| `TextInputFiles_AppendN` | 0x1018D580 | 186 | yes | - | Appends the first n characters of a string to the buffer, or the whole string when n is 0xFFFFFFFF. | medium |
| `TextInputFiles_InitAcqDat` | 0x1018D640 | 114 | yes | - | Sets the object's vtable and fields, registers the acq.dat entry with the DAT manager, and clears its entries. | medium |
| `TextInputFiles_FillCompletionWords` | 0x1018D7F0 | 339 | yes | - | Fills candidate words for completion from target and entry names; details not established. | low |
| `TextInputFiles_CommitPending8C` | 0x1018D980 | 60 | yes | - | Copies the pending block at +8 to +0x8C once when the pending flag is set. | high |
| `TextInputFiles_ClearByte10E` | 0x1018DA10 | 8 | yes | - | Clears the object's byte at +0x10E. | low |
| `TextInputFiles_Validate8NamesOrClear` | 0x1018DA20 | 232 | yes | - | Checks the record's eight short names and clears the record when asked or when one has a bad character. | low |
| `TextInputFiles_AppendCompletionWord` | 0x1018DB10 | 144 | yes | - | Adds one word to the completion list when there is room. | low |
| `TextInputFiles_GetEntryMod` | 0x1018DC70 | 55 | yes | - | Returns the entry at the argument modulo the entry count, or null when there is none. | medium |
| `TextInputFiles_ClearEntries` | 0x1018DCB0 | 28 | yes | - | Clears the first byte of each of the object's eight entries and sets the entry count to zero. | medium |
| `TextInputFiles_InitPecDat` | 0x1018DCD0 | 73 | yes | - | Sets the object's vtable, zeroes its 0x500-byte table, and registers the pec.dat entry with the DAT manager. | medium |
| `TextInputFiles_Validate64NamesOrClear` | 0x1018DFD0 | 206 | yes | - | Checks the record's 64 short names and clears it when asked or when one has a bad character. | low |
| `FsLogPage_InitPage` | 0x1018E0A0 | 54 | yes | - | Stores the argument at +0xDC and clears the page's buffer fields. | medium |
| `FsLogPage_ClearAndVisitFiles` | 0x1018E0E0 | 142 | yes | - | Clears the log page and passes each of its log file names (N.log / N_M.log) to Unit1018BA60_FileMngFwd101C1820, sleeping while the file manager is busy; what that call does to the files is not established. | medium |
| `FsLogPage_FormatFileName` | 0x1018E170 | 46 | yes | - | Formats a log file name: N.log or N_M.log. | high |
| `FsLogPage_AllocBuffer` | 0x1018E1A0 | 44 | yes | - | Frees the log page's buffer and allocates a new 0xC80-byte buffer for it. | medium |
| `FsLogPage_load` | 0x1018E1D0 | 306 | yes | - | - | - |
| `FsLogPage_WriteFile` | 0x1018E310 | 443 | yes | - | Writes the log page to the named file through the file manager, waiting while it is busy. | low |
| `FsLogPage_AddString` | 0x1018E4D0 | 324 | yes | - | Appends a string to the log page's buffer and records its offset. | medium |
| `TextInputFiles_GetPageLine` | 0x1018E620 | 57 | yes | - | Returns the text of a line of a log page, or 0. | medium |
| `FsLogPage_ClearBuffer` | 0x1018E660 | 53 | yes | - | Frees the log page's string buffer and resets it. | medium |
| `FsLogPage_PruneOffsets` | 0x1018E6A0 | 73 | yes | - | Invalidates the log page offsets that no longer point at a string. | medium |
| `FsLogPage_Init` | 0x1018E6F0 | 48 | yes | - | Initialises a log page object with the argument at +0x5C and an empty state. | medium |
| `TextInputFiles_FreeAllLogPages` | 0x1018E780 | 73 | yes | - | Frees every loaded page of the log and marks it unloaded. | medium |
| `TextInputFiles_GetLineOfPage` | 0x1018E7D0 | 30 | yes | - | Returns a line of a given log page. | medium |
| `FsLogPage_HasPage` | 0x1018E7F0 | 16 | yes | - | Tests whether a log page slot holds a page. | medium |
| `FsLogPage_EnsurePage` | 0x1018E800 | 142 | yes | - | Creates and loads the log page in a slot when it is empty. | medium |
| `TextInputFiles_FreeLogPage` | 0x1018E890 | 52 | yes | - | Frees one page of the log. | medium |
| `FsLogPage_Rotate` | 0x1018E8D0 | 212 | yes | - | Writes a full log page to the next of 20 rotating log files. | medium |
| `TextInputFiles_ConstructKind1` | 0x1018E9B0 | 20 | yes | - | Runs the base initialiser with argument 1 and sets the object's vtable. | low |
| `TextInputFiles_ConstructKind2` | 0x1018EA00 | 20 | yes | - | Runs the base initialiser with argument 2 and sets the object's vtable. | low |
| `TextInputFiles_InitFields` | 0x1018EA50 | 38 | yes | - | Stores its argument at +0x14 and zeroes the object's fields at +4 to +0x1C. | low |
| `TextInputFiles_RecreateMembers` | 0x1018EB00 | 189 | yes | - | Frees and recreates the two member objects and the data buffer, then resets the related globals. | medium |
| `TextInputFiles_FreeLogPagesIfLoaded` | 0x1018EBF0 | 21 | yes | - | Frees the log's pages if they are loaded. | medium |
| `TextInputFiles_GetCurrentLogLine` | 0x1018EC10 | 62 | yes | - | Returns the text of the log's current line (50 lines a page). | medium |
| `TextInputFiles_LogLineBack` | 0x1018EC50 | 137 | yes | - | Moves the log's current line back one, loading the page it enters and freeing one two pages ahead. | medium |
| `TextInputFiles_LogLineForward` | 0x1018ECE0 | 127 | yes | - | Moves the log's current line forward one, loading the page it enters and freeing one two pages behind. | medium |
| `FsLogPage_AddEntry` | 0x1018ED80 | 157 | yes | - | Adds an entry to the log page, creating a page when needed. | low |
| `TextInputFiles_ConstructLarge` | 0x1018EE40 | 149 | yes | - | Initialises a large object's base subobjects, its vtable and its fields from the two arguments. | low |
| `Text_ClassifyChar` | 0x1018FA20 | 94 | yes | - | Classifies a text character code into a small category. | low |
| `Text_GetCharLength` | 0x1018FA80 | 113 | yes | - | Returns the byte length of the text character at a position, given its lead byte and the next byte. | medium |
| `Text_CountChars` | 0x1018FB00 | 43 | yes | - | Counts the characters in a byte range. | low |
| `Sjis_Remap82To83` | 0x1018FD90 | 94 | yes | - | Rewrites Shift-JIS two-byte characters with lead 0x82 as lead 0x83 with an adjusted trail byte, in place. | medium |
| `Text_EncodeQuotes` | 0x10190140 | 306 | yes | - | Rewrites double quotes in a text buffer as alternating marker codes. | low |
| `TextInputFiles_AllocZeroed` | 0x101907A0 | 48 | yes | - | Allocates a zeroed block and stores its pointer. | medium |
| `TextInputFiles_FreeBlock` | 0x101907D0 | 5 | yes | - | Frees the block it is given by calling operator_delete. | low |
| `TextInputFiles_Nop` | 0x101908D0 | 1 | yes | - | Does nothing. | low |
| `TextInputFiles_CtorVt10336950` | 0x10190900 | 47 | yes | - | Constructor of the object with vtable 0x10336950 (state 0xE). | high |
| `TextInputFiles_Reset10336950` | 0x10190950 | 35 | yes | - | Resets the object to state 0xE with a new owner at +0x18 and updates it. | high |
| `FsCSKLogic_closeCSK` | 0x10190B50 | 88 | yes | - | - | - |
| `TextInputFiles_Update10336950` | 0x10190BB0 | 156 | yes | - | Updates the state at +4 from the owner's value at +0xF10C. | low |
| `TextInputFiles_UpdateFromMenu` | 0x101911A0 | 60 | yes | - | Updates the keypad state from whether the keypad menu is open. | medium |
| `TextInputFiles_CtorVt10336958` | 0x10191AB0 | 52 | yes | - | Constructor of the object with vtable 0x10336958. | high |
| `TextInputFiles_FindTopShape` | 0x10191B20 | 49 | yes | - | Looks up the top-row keypad shape. | low |
| `TextInputFiles_FindShapeKey2Top` | 0x10192380 | 49 | yes | - | Stores its argument and looks up the 'key2top' menu shape, keeping the result at +0x14. | medium |
| `TextInputFiles_CtorVt103369A0` | 0x10192E50 | 66 | yes | - | Constructor of the object with vtable 0x103369A0, which holds the 'key2top' menu shape. | high |
| `TextInputFiles_AddPairChecked` | 0x10193800 | 40 | yes | - | Forwards its three arguments to the pair-adding routine when the object exists, else returns -1. | low |
| `SetConfig` | 0x10193830 | 30 | yes | - | - | - |
| `Settings_GetValue` | 0x10193850 | 25 | yes | - | - | - |
| `TextInputFiles_GetSetting99` | 0x10193890 | 19 | yes | - | Returns the setting with key 0x99, passed through fn_101938B0 with the caller's argument. | medium |
| `TextInputFiles_GetSettingMapped` | 0x101938B0 | 22 | yes | - | Reads a setting and maps it through game_101938D0. | high |
| `TextInputFiles_TestBit` | 0x101938D0 | 19 | yes | - | Returns bit n of a value. | low |
| `TextInputFiles_TestBit64` | 0x10193A10 | 39 | yes | - | Tests one bit of a 64-bit mask. | low |
| `TextInputFiles_InitPairNode` | 0x10193B00 | 32 | yes | - | Initialises a pair node: next pointer null, first and second values stored at +8 and +0xC. | medium |
| `TextInputFiles_FindOrAdd` | 0x10193B60 | 93 | yes | - | Finds a pair of values in a list, adding it when absent. | low |
| `TextInputFiles_ForEach` | 0x10193BC0 | 38 | yes | - | Calls a callback for every pair in the list. | medium |
| `FsConfig_Constructor` | 0x10193BF0 | 5442 | yes | - | - | - |
| `TextInputFiles_ResetConfigReturn1` | 0x10195220 | 25 | yes | - | Resets the configuration to defaults (mode 0) and clears two flags. | high |
| `TextInputFiles_AddPairAndCall` | 0x10195240 | 120 | yes | - | Adds a pair to an entry's list when its second argument is nonzero, then calls the list's callbacks with the entry's two values. | medium |
| `TextInputFiles_SetEntryValue` | 0x101952C0 | 108 | yes | - | Stores a new value in a config entry when it differs from the current one, and marks the table dirty for types 1 and 2. | medium |
| `TextInputFiles_GetEntryValue` | 0x10195330 | 26 | yes | - | Returns the value stored in the entry at the given index, or -1 when the entry is missing. | medium |
| `TextInputFiles_ReloadConfig` | 0x10195350 | 65 | yes | - | Reloads the configuration from cnf.dat and the external config, defaults on failure. | medium |
| `TextInputFiles_ReadTigDatSetFlag` | 0x101953A0 | 18 | yes | - | Runs Unit1018BA60_ReadTigDat and sets the flag at +10. | low |
| `TextInputFiles_FlushThenTrue` | 0x101953C0 | 11 | yes | - | Runs the flush helper and returns 1. | low |
| `TextInputFiles_UpdateIfFlag9` | 0x101953F0 | 28 | yes | - | Runs two update helpers when the flag at +9 is set and returns 1. | low |
| `TextInputFiles_DefineEntry` | 0x10195460 | 97 | yes | - | Fills in the entry at the given index of the entry array with its default, type and value fields. | medium |
| `TextInputFiles_GetEntry2C` | 0x101954D0 | 28 | yes | - | Returns the entry at an index of the 0x2C-byte array at +4. | low |
| `TextInputFiles_WriteTigDat` | 0x101954F0 | 114 | yes | - | Collects the values of the type-6 entries and writes them to tig.dat. | medium |
| `TextInputFiles_ReadTigDat` | 0x10195570 | 207 | yes | - | Reads tig.dat and applies its stored values to the type-6 entries. | medium |
| `TextInputFiles_StoreExternalConfig` | 0x10195640 | 166 | yes | - | Writes the config entries of kinds 1 and 2 to the external store and closes it. | low |
| `TextInputFiles_LoadExternalConfig` | 0x101956F0 | 139 | yes | - | Reads the config entries of kinds 1 and 2 from the external store. | low |
| `TextInputFiles_ReadExternalKind1` | 0x10195780 | 36 | yes | - | Reads one kind-1 config value from the external store. | low |
| `TextInputFiles_WriteExternalKind1` | 0x101957B0 | 82 | yes | - | Writes one kind-1 config value to the external store. | low |
| `TextInputFiles_ReadExternalKind2` | 0x10195810 | 164 | yes | - | Reads one of the two keyed config values from the external store. | low |
| `TextInputFiles_IsExternalKind2Key` | 0x101958C0 | 62 | yes | - | Tests whether a key is one of the two external config keys. | low |
| `TextInputFiles_SaveCnfDat` | 0x10195900 | 148 | yes | - | Saves the kind-4 config values to cnf.dat. | medium |
| `TextInputFiles_LoadCnfDat` | 0x101959A0 | 1661 | yes | - | Loads cnf.dat (version 5) and applies its configuration values. | high |
| `TextInputFiles_SetConfigEntryValue` | 0x10196040 | 80 | yes | - | Sets a config entry's value within its range and notifies its listeners. | medium |
| `TextInputFiles_ResetConfigToDefaults` | 0x10196260 | 97 | yes | - | Resets the config entries to their defaults and notifies their listeners. | low |
| `TextInputFiles_ConstructVt10336A0C` | 0x101962D0 | 13 | yes | - | Sets the object's vtable and clears its flag byte. | low |
| `TextInputFiles_WindowItemCtor` | 0x10196980 | 110 | yes | - | Constructs the window item base with its shape values. | low |
| `TextInputFiles_ReturnZero` | 0x10196BE0 | 3 | yes | - | Returns 0. | medium |
| `TextInputFiles_ClearWords3C` | 0x10196BF0 | 36 | yes | - | Runs the base initialiser and clears four words. | low |
| `TextInputFiles_SetFieldById` | 0x10196F60 | 67 | yes | - | Stores a value in one of four fields by id. | low |
| `TextInputFiles_SetFieldCallback` | 0x10197030 | 25 | yes | - | Applies a setting to the object's fields (a callback form). | low |
| `TextInputFiles_WindowItemCtorVt10336AC8` | 0x101972B0 | 67 | yes | - | Constructs a window item with vtable 0x10336AC8. | low |
| `TextInputFiles_SetFieldById2` | 0x101978E0 | 156 | yes | - | Stores a value in one of the object's fields by id. | low |
| `TextInputFiles_SetFieldCallback2` | 0x10197A70 | 25 | yes | - | Applies a setting to the object's fields (a callback form). | low |
| `TextInputFiles_FrameItemCtor` | 0x10197A90 | 126 | yes | - | Constructs the frame item base with its shape values. | low |
| `TextInputFiles_ConstructVt10336B60` | 0x10197F00 | 26 | yes | - | Constructs the object on its base and sets its vtable. | low |
| `TextInputFiles_ConstructVt10336BB0` | 0x10198320 | 25 | yes | - | Constructs the object on its base and sets its vtable. | low |
| `TextInputFiles_CtorVt10336C00` | 0x10198CA0 | 105 | yes | - | Constructs a menu item with vtable 0x10336C00 and its default colours. | low |
| `TextInputFiles_CtorVt10336C48` | 0x101990C0 | 39 | yes | - | Constructs a menu item object with vtable 0x10336C48. | low |
| `TextInputFiles_ConstructVt10336C90` | 0x101991B0 | 38 | yes | - | Constructs the object and sets its vtable. | low |
| `TextInputFiles_ConstructVt10336CD8` | 0x101992A0 | 32 | yes | - | Constructs the object on its base and sets its vtable. | low |
| `TextInputFiles_WindowItemCtorVt10336D20` | 0x10199710 | 59 | yes | - | Constructs a window item with vtable 0x10336D20. | low |
| `TextInputFiles_ConstructVt10336D70` | 0x10199F40 | 18 | yes | - | Constructs the object on its base and sets its vtable. | low |
| `TextInputFiles_ConstructVt10336DC0` | 0x1019A010 | 18 | yes | - | Constructs the object on its base and sets its vtable. | low |
| `TextInputFiles_WindowItemCtorVt10336E10` | 0x1019A890 | 61 | yes | - | Constructs a window item with vtable 0x10336E10. | low |
| `TextInputFiles_WindowItemCtorVt10336E58` | 0x1019AF00 | 74 | yes | - | Constructs a window item with vtable 0x10336E58. | low |
| `TextInputFiles_WindowItemCtorVt10336EA0` | 0x1019B860 | 46 | yes | - | Constructs a window item with vtable 0x10336EA0. | low |
| `TextInputFiles_ConstructVt10336EE8` | 0x1019BC90 | 29 | yes | - | Constructs the object on its base and sets its vtable. | low |
| `TextInputFiles_CtorVt10336F30` | 0x1019BFE0 | 71 | yes | - | Constructs a menu item object with vtable 0x10336F30. | low |
| `TextInputFiles_CtorVt10336F78` | 0x1019C190 | 77 | yes | - | Constructs a menu item object with vtable 0x10336F78. | low |
| `TextInputFiles_RunPairA` | 0x1019C3E0 | 26 | yes | - | Runs two helpers in order. | low |
| `TextInputFiles_RunPairB` | 0x1019C4F0 | 20 | yes | - | Runs the same two helpers in the reverse order. | low |
| `TextInputFiles_Call10311386` | 0x1019C580 | 9 | yes | - | Returns the result of 0x10311386. | low |
| `TextInputFiles_GetSetting41` | 0x1019C590 | 23 | yes | - | Returns the setting for key 0x41. | low |
| `TextInputFiles_Call103113C8` | 0x1019C5B0 | 9 | yes | - | Calls 0x103113C8. | low |
| `TextInputFiles_ByteTableCtor` | 0x1019CD40 | 63 | yes | - | Constructs the byte-table item base. | low |
| `TextInputFiles_HasTable1037A290CellByte` | 0x1019CDC0 | 60 | yes | - | Tests whether an entry of the table at 0x1037A290 maps (through Cell_GetWord1036D6B0) to the given byte. | low |
| `TextInputFiles_ByteTableDefaultCtor` | 0x1019CE00 | 56 | yes | - | Constructs the byte table from the default table (Config_LoadDefaultTable). | low |
| `Config_LoadDefaultTable` | 0x1019CE70 | 226 | yes | - | Loads the default config table for the scene and writes its entries with SetConfig. | medium |
| `TextInputFiles_FillTableBytes` | 0x1019CF60 | 49 | yes | - | Fills the table bytes from the default table. | low |
| `TextInputFiles_ByteTableAltCtor` | 0x1019D150 | 56 | yes | - | Constructs the byte table from the alternative table (Config_LoadAltTable). | low |
| `Config_LoadAltTable` | 0x1019D1C0 | 240 | yes | - | Loads the alternate config table for the scene and writes its entries with SetConfig. | medium |
| `TextInputFiles_CtorVt103370F8` | 0x1019D580 | 38 | yes | - | Constructs a menu item object with vtable 0x103370F8. | low |
| `TextInputFiles_CtorCachingSettings` | 0x1019D770 | 25 | yes | - | Constructs an object with vtable 0x10337140 and caches settings values into it. | low |
| `Settings_CacheValues` | 0x1019D8B0 | 112 | yes | - | Caches several settings values in the object's fields. | medium |
| `TextInputFiles_DrawTextBlockOnce` | 0x1019EBB0 | 76 | yes | 4 | Draws the object's text block, and stops drawing it once a draw reports failure. | medium |
| `TextInputFiles_GetScaleTimes310` | 0x1019ED10 | 14 | yes | - | Returns the float at this+0x4C times 310, as an integer. | low |
| `TextInputFiles_GetScaleTimes0` | 0x1019ED20 | 14 | yes | - | Returns the float at this+0x4C times 0, as an integer. | low |
| `TextInputFiles_GetScaleTimes180` | 0x1019ED30 | 14 | yes | - | Returns the float at this+0x4C times 180, as an integer. | low |
| `TextInputFiles_NextLine` | 0x1019ED70 | 49 | yes | - | Returns a pointer to the start of the next line in a text buffer. | medium |
| `TextInputFiles_DrawTextLines` | 0x1019EDB0 | 423 | yes | 3 | Draws a text line by line (CR/LF separated, tab-led lines indented), up to a number of lines. | medium |
| `TextInputFiles_CtorWithMenuFepShape` | 0x1019F160 | 94 | yes | - | Constructs an object with vtable 0x103371B8 holding the shape named "menu fep". | medium |
| `TextInputFiles_PushWithRetry` | 0x1019F8B0 | 122 | yes | - | Pushes a record, retrying with an event signal and a 1-second wait until it fits or 100 seconds pass. | medium |
| `TextInputFiles_FindMatchAt8` | 0x1019F930 | 11 | yes | - | Forwards a match search to the queue object reached through +8. | low |
| `TextInputFiles_WaitThenHandleFileEvent` | 0x1019F960 | 207 | yes | - | Waits on an event, hands a copied file request to the file thread manager, then calls 0x101B9530 on that event object. | medium |
| `TextInputFiles_WaitEvent18At8` | 0x1019FA90 | 22 | yes | - | Waits without timeout on the event of the object at +8. | low |
| `TextInputFiles_SignalMember8` | 0x1019FAB0 | 22 | yes | - | Signals the object at +8 (fn_101A0970); 1 on success, -1 on failure. | high |
| `TextInputFiles_Call101BE510IfSize4` | 0x101A0710 | 27 | yes | - | Calls game_101BE510 on a 4-byte argument; -1 for any other size. | high |
| `TextInputFiles_FillSizeAndDatesFwd` | 0x101A0730 | 24 | yes | - | Forwards to Unit1018BA60_FillSizeAndThreeDates with its stacked arguments. | high |
| `TextInputFiles_Call101BE670` | 0x101A0750 | 16 | yes | - | Calls game_101BE670 with the string stored in its arguments. | high |
| `TextInputFiles_Call101BE690` | 0x101A0760 | 16 | yes | - | Calls game_101BE690 with the address of its third argument. | high |
| `TextInputFiles_RunKind8WithCallback` | 0x101A0770 | 94 | yes | - | For kind 8, runs 0x101BE690 on the argument block and reports its result through the given callback. | low |
| `TextInputFiles_SignalEvent10` | 0x101A0910 | 22 | yes | - | Signals the event at +0x10. | medium |
| `TextInputFiles_ResetAndWaitEvent14` | 0x101A0930 | 29 | yes | - | Resets and waits on the event at +0x14 for up to the given milliseconds. | medium |
| `TextInputFiles_WaitEvent18` | 0x101A0950 | 24 | yes | - | Waits without timeout on the event at +0x18. | medium |
| `TextInputFiles_SignalMember18` | 0x101A0970 | 22 | yes | - | Releases the semaphore object at +0x18; 1 on success, -1 on failure. | high |
| `TextInputFiles_Push` | 0x101A0BE0 | 221 | yes | - | Appends a record to the ring buffer, replacing the oldest slot when it is full. | medium |
| `TextInputFiles_FindMatch` | 0x101A0D30 | 250 | yes | - | Searches the ring for a record matching the given name and values. | medium |
| `TextInputFiles_HasRecords` | 0x101A0F30 | 41 | yes | - | Reports whether the record ring has any records. | low |
| `TextInputFiles_IsField84PositiveAfterWait` | 0x101A1360 | 44 | yes | - | Waits on the event at +0x90 and reports whether the count at +0x84 is positive. | low |
| `TextInputFiles_Pop` | 0x101A1390 | 99 | yes | - | Removes and returns the oldest dword from a 32-entry ring, or 0 when it is empty. | medium |
| `TextInputFiles_StringListCtor` | 0x101A1400 | 52 | yes | - | Constructs the list of up to ten strings that 0x101A1470 pushes onto. | low |
| `TextInputFiles_SetVtable10337210` | 0x101A1460 | 7 | yes | - | Sets the vtable to 0x10337210 (destructor body). | high |
| `TextInputFiles_PushFrontString` | 0x101A1470 | 129 | yes | - | Inserts a string at the front of a list of fixed-size entries, shifting the others down. | medium |
| `TextInputFiles_CopyCurrent` | 0x101A1500 | 126 | yes | - | Copies the current string slot into the caller's buffer. | low |
| `TextInputFiles_SetCurrent` | 0x101A1580 | 212 | yes | - | Stores a string into the current string slot. | low |
| `TextInputFiles_Advance` | 0x101A1660 | 33 | yes | - | Moves the string ring's current index forward. | low |
| `TextInputFiles_Retreat` | 0x101A1690 | 27 | yes | - | Moves the string ring's current index back. | low |
| `TextInputFiles_ClearFirstString` | 0x101A16B0 | 45 | yes | - | Clears the first entry of the string list. | low |
| `TextInputFiles_McrEntryCtor` | 0x101A16E0 | 43 | yes | - | Constructs one 0x17C-byte entry of the mcr manager. | low |
| `TextInputFiles_CopyMcrEntry` | 0x101A1740 | 71 | yes | - | Copies an entry's title and its six lines from another entry. | medium |
| `TextInputFiles_CopyRecord6x3D` | 0x101A1790 | 69 | yes | - | Copies a record of six 61-byte strings and nine more bytes into the object. | low |
| `TextInputFiles_ClearRecord6x3D` | 0x101A17E0 | 35 | yes | - | Clears the object's record of six strings. | low |
| `TextInputFiles_ValidateRecord6x3D` | 0x101A1840 | 84 | yes | - | Checks that the record's strings are terminated and clears it if not. | low |
| `TextInputFiles_GetMcrEntryLine` | 0x101A1910 | 33 | yes | - | Returns a pointer to one of an entry's six lines. | medium |
| `TextInputFiles_Create` | 0x101A19B0 | 50 | yes | - | Creates the macro manager object once. | low |
| `TextInputFiles_McrManagerCtor` | 0x101A1A20 | 264 | yes | - | Constructs the manager of the mcr entries and registers its mcr.sys and mcr.ttl files. | medium |
| `TextInputFiles_QueueEntry` | 0x101A1C60 | 76 | yes | - | Queues one of the twenty macro entries and resets the cursor. | low |
| `TextInputFiles_StepScript` | 0x101A1CC0 | 331 | yes | - | Advances the macro script by one line. | low |
| `TextInputFiles_OnMacroFileLoaded` | 0x101A1E20 | 392 | yes | - | Handles a loaded macro data file: copies and checks its records and reports the set and page in the chat log. | medium |
| `TextInputFiles_LoadCurrentMacroDat` | 0x101A23D0 | 61 | yes | - | Loads the macro data file for the object's current index. | medium |
| `TextInputFiles_ResetNames0To19` | 0x101A2410 | 47 | yes | - | Resets the first 20 names to their defaults. | low |
| `TextInputFiles_ResetNames20To39` | 0x101A2440 | 50 | yes | - | Resets names 20 to 39 to their defaults. | low |
| `TextInputFiles_ParseWaitCommand` | 0x101A2480 | 325 | yes | - | Recognises a /wait or <wait N> command in a script line and sets up the wait. | medium |
| `TextInputFiles_FormatNumberedDatName` | 0x101A2610 | 76 | yes | - | Formats a .dat file name with an optional number. | medium |
| `TextInputFiles_LoadNumberedDatIntoBuffer` | 0x101A2660 | 93 | yes | - | Loads the numbered .dat file the arguments name into the object's 0x1DB0-byte buffer at +4. | medium |
| `TextInputFiles_LoadMacroDat` | 0x101A26C0 | 189 | yes | - | Loads a macro .dat file (FsMacroContainer_loadCallback for book 0). | medium |
| `TextInputFiles_SplitIndexBy20` | 0x101A2870 | 31 | yes | - | Splits the object's index into a position (of 20) and a group number. | low |
| `TextInputFiles_SetReadPos` | 0x101A2890 | 135 | yes | - | Sets the macro read position and updates the block index. | low |
| `TextInputFiles_SetName` | 0x101A2980 | 107 | yes | - | Sets one of 40 names, or its numbered default text when none is given. | low |
| `TextInputFiles_GetEntryPtr` | 0x101A29F0 | 32 | yes | - | Returns the address of a macro entry by index. | low |
| `TextInputFiles_FillDefaultNames` | 0x101A2A10 | 49 | yes | - | Gives every empty name its numbered default text. | low |
| `TextInputFiles_CtorVt10337314` | 0x101A2E00 | 44 | yes | - | Constructs an object with vtable 0x10337314 around the given pointer. | low |
| `TextInputFiles_SetFields1C20` | 0x101A2E60 | 17 | yes | - | Sets the two fields at +0x1C and +0x20. | low |
| `TextInputFiles_UpdateMenuState` | 0x101A2E80 | 1060 | yes | - | Updates which macro menu is open from the input state. | low |
| `TextInputFiles_SetSlot` | 0x101A3300 | 67 | yes | - | Sets one of the two macro slots. | low |
| `TextInputFiles_CanOpenMenuShortcut` | 0x101A33E0 | 278 | yes | - | Tests whether a menu shortcut may act now and one of four panels has the focus. | low |
| `TextInputFiles_ApplyKeyAction` | 0x101A3500 | 73 | yes | - | Applies a key press to the macro slots. | low |
| `TextInputFiles_HandleReadPosKeys` | 0x101A3550 | 404 | yes | - | Moves the reader position from ten key inputs. | low |
| `TextInputFiles_PanelCtorVt10337320` | 0x101A36F0 | 131 | yes | - | Constructs a menu panel with vtable 0x10337320 and its string. | low |
| `TextInputFiles_SetFlag29A` | 0x101A3CF0 | 5 | yes | - | Sets the flag at +0x29. | low |
| `TextInputFiles_AddMsg10_27IfChangedA` | 0x101A3D00 | 91 | yes | - | When forced or the read position changed, formats message (10, 0x27) for the current entry and adds it to the object's list. | low |
| `TextInputFiles_FormatMessage10_27` | 0x101A3D60 | 45 | yes | - | Formats game message (10, 0x27) with the argument and (n mod 10) + 1 into a buffer. | low |
| `TextInputFiles_PanelCtorVt10337378` | 0x101A3DC0 | 131 | yes | - | Constructs a menu panel with vtable 0x10337378 and its string. | low |
| `TextInputFiles_SetFlag29B` | 0x101A43A0 | 5 | yes | - | Sets the flag at +0x29. | low |
| `TextInputFiles_AddMsg10_27IfChangedB` | 0x101A43B0 | 91 | yes | - | The second copy of 0x101A3D00: formats message (10, 0x27) for the current entry and adds it to the list when forced or changed. | low |
| `TextInputFiles_CtorVt103373BC` | 0x101A4440 | 30 | yes | - | Constructs a small object with vtable 0x103373BC around a value. | low |
| `TextInputFiles_PanelCtorVt103373C8` | 0x101A46C0 | 131 | yes | - | Constructs a menu panel with vtable 0x103373C8 and its string. | low |
| `TextInputFiles_PanelCtorVt10337418` | 0x101A4D70 | 131 | yes | - | Constructs a menu panel with vtable 0x10337418 and its string. | low |
| `TextInputFiles_CtorVt10337460` | 0x101A54F0 | 279 | yes | - | Constructs a menu object with its text lists. | low |
| `TextInputFiles_CtorVt103374A8` | 0x101A6430 | 38 | yes | - | Constructs a menu item with vtable 0x103374A8. | low |
| `TextInputFiles_CtorVt103374F0` | 0x101A6C10 | 69 | yes | - | Constructs a menu item with vtable 0x103374F0. | low |
| `TextInputFiles_CtorVt10337538` | 0x101A7280 | 47 | yes | - | Constructs a menu item with vtable 0x10337538. | low |
| `TextInputFiles_CtorVt1033757C` | 0x101A83C0 | 27 | yes | - | Constructs the slot object with vtable 0x1033757C. | low |
| `TextInputFiles_BuildSlotLinks` | 0x101A8410 | 82 | yes | - | Builds the slot neighbour links of a macro menu. | low |
| `TextInputFiles_CtorVt10337580` | 0x101A8750 | 18 | yes | - | Constructs an object with vtable 0x10337580 around a value. | low |
| `TextInputFiles_CreateAll` | 0x101A8B50 | 292 | yes | - | Creates the macro system objects and attaches their windows. | low |
| `TextInputFiles_CreateDatManager` | 0x101A8D40 | 11 | yes | - | Creates the DAT manager object 0x10662DB0. | low |
| `TextInputFiles_CreateConfigObjects` | 0x101A8D60 | 4400 | yes | - | Creates the configuration object and its item objects and registers the handler of each configuration id. | medium |
| `TextInputFiles_RegisterMenuHandlers` | 0x101AA300 | 845 | yes | - | Registers one handler for 56 ids. | low |
| `TextInputFiles_ApplyConfigSetting` | 0x101AA650 | 605 | yes | - | Applies one configuration setting (gamma, sound, aspect, shadows and other display options) to the game. | medium |
| `TextInputFiles_ApplyUiSetting` | 0x101AAA90 | 1008 | yes | - | Applies one interface setting: the target window and the chat log windows' lines and sizes. | medium |
| `TextInputFiles_CreateEmptyObject` | 0x101AB080 | 38 | yes | - | Creates the empty global object 0x106627EC. | low |
| `TextInputFiles_CreateMenuSystem` | 0x101AB0D0 | 894 | yes | - | Creates the menu system's global objects. | low |
| `TextInputFiles_SaveAll` | 0x101AB6D0 | 80 | yes | - | Saves the message windows and settings. | low |
| `TextInputFiles_Call101953D0` | 0x101AB720 | 11 | yes | - | Calls 0x101953D0. | low |
| `TextInputFiles_ReloadAll` | 0x101AB730 | 53 | yes | - | Reloads the DAT entries, settings and slots. | low |
| `TextInputFiles_HandleJumpMapKeys` | 0x101AB770 | 92 | yes | - | Runs the /jump and /map commands from their keys. | medium |
| `TextInputFiles_LoadAllAndTimestamp` | 0x101AB7D0 | 50 | yes | - | Loads the DAT entries and settings and writes the timestamp. | low |
| `TextInputFiles_ReturnThis` | 0x101AB810 | 3 | yes | - | Returns this. | medium |
| `TextInputFiles_HandleMenuKeys` | 0x101AB820 | 792 | yes | - | Turns key inputs into menu events each frame. | low |
| `FsTextInput_Init` | 0x101ABB40 | 121 | yes | - | Initialises the text input's buffers and width. | low |
| `TextInputFiles_SetModeAndReset` | 0x101ABBD0 | 18 | yes | - | Sets the input line's mode and resets it. | low |
| `TextInputFiles_ResetLineState` | 0x101ABBF0 | 95 | yes | - | Clears the input line's text, buffers and cursor state. | medium |
| `FsTextInput_SetText` | 0x101ABC50 | 488 | yes | - | Sets the input's text from a string, normalising full-width spaces. | low |
| `FsTextInput_GetFlag` | 0x101ABE40 | 3 | yes | - | Returns the text input's active flag. | low |
| `FsTextInput_ClearState` | 0x101ABE50 | 44 | yes | - | Clears the text input's state. | low |
| `FsTextInput_GetCode` | 0x101ABE80 | 12 | yes | - | Returns the text input's 4-byte code. | low |
| `FsTextInput_CursorLeft` | 0x101ABEF0 | 75 | yes | - | Moves the input cursor one character left. | low |
| `FsTextInput_RebuildAtCursor` | 0x101ABF40 | 609 | yes | - | Rebuilds the input's display text around the cursor. | low |
| `FsTextInput_GetActiveBuffer` | 0x101AC1B0 | 20 | yes | - | Returns the text buffer at +0x6C4 when the input has a length. | low |
| `FsTextInput_GetPendingBuffer` | 0x101AC1D0 | 36 | yes | - | Returns the pending text buffer, choosing between two buffers by a flag. | low |
| `FsTextInput_GetLength` | 0x101AC200 | 7 | yes | - | Returns the input's text length. | low |
| `FsTextInput_GetCursorOrLength` | 0x101AC210 | 24 | yes | - | Returns the cursor value or the length, chosen by the flag at +0xC24. | low |
| `FsTextInput_GetMaxLength` | 0x101AC230 | 19 | yes | - | Returns the larger of the length and the field at +0xA50. | low |
| `FsTextInput_Reset` | 0x101AC250 | 97 | yes | - | Clears the text input's buffers and state. | low |
| `FsTextInput_HistoryNext` | 0x101AC2C0 | 260 | yes | - | Moves to the next history entry and shows it. | low |
| `FsTextInput_HistoryPrev` | 0x101AC3D0 | 256 | yes | - | Moves to the previous history entry and shows it. | low |
| `FsTextInput_HasText` | 0x101AC4D0 | 12 | yes | - | Tests whether the input has any text. | low |
| `FsTextInput_MoveCursorLeft` | 0x101AC4E0 | 60 | yes | - | Moves the cursor position at +0xA58 back, clamped at 0. | low |
| `FsTextInput_MoveCursorRight` | 0x101AC520 | 59 | yes | - | Moves the cursor position at +0xA58 forward, clamped to the length. | low |
| `FsTextInput_ResetBuffer` | 0x101AC580 | 91 | yes | - | Resets the input's buffer and sets its text from the current buffer. | low |
| `FsTextInput_ExpandMarkedPhrase` | 0x101AC5E0 | 699 | yes | - | Expands one 0xFD-marked phrase of the input text. | low |
| `FsTextInput_BuildDisplayText` | 0x101AC990 | 296 | yes | - | Builds the display form of input text with its marked phrases expanded. | low |
| `FsTextInput_BuildDisplayTextTrimmed` | 0x101ACAC0 | 287 | yes | - | Builds the display form of a text, keeping its leading spaces. | low |
| `FsTextInput_HasMarkedPhrase` | 0x101ACBE0 | 75 | yes | - | Tests whether a text holds a 0xFD-marked phrase. | low |
| `FsTextInput_CommitEntry` | 0x101ACC30 | 769 | yes | - | Inserts a chosen candidate entry into the input. | low |
| `FsTextInput_SetCode4` | 0x101ACF40 | 32 | yes | - | Sets a 4-byte code from four values. | low |
| `FsTextInput_MapCodeByte` | 0x101ACF60 | 15 | yes | - | Maps a code's first byte to its group. | low |
| `FsTextInput_CopyCode4` | 0x101ACF70 | 29 | yes | - | Copies a 4-byte code. | low |
| `FsTextInput_ClearPair` | 0x101ACF90 | 20 | yes | - | Clears the two fields at +0xC70 and +0xC74. | low |
| `FsTextInput_InsertAtCursor` | 0x101ACFB0 | 262 | yes | - | Inserts the pending text at the cursor. | low |
| `FsTextInput_DeleteLastWord` | 0x101AD0D0 | 177 | yes | - | Deletes the last word of the input text. | low |
| `FsTextInput_IsMarkerAt` | 0x101AD1B0 | 24 | yes | - | Tests for the 0xFD marker byte at a position. | medium |
| `FsPreParser_Constructor` | 0x101AD290 | 483 | yes | - | - | - |
| `TextInputFiles_ProcessInputLine` | 0x101AD4B0 | 437 | yes | - | Processes a typed line, recognising slash commands. | low |
| `FsTextInput_GetDataPtr8` | 0x101AD820 | 4 | yes | - | Returns the address of the object's data at +8. | low |
| `TextInputFiles_IsSlashChar` | 0x101ADBC0 | 13 | yes | - | Tests whether a character is a forward slash. | medium |
| `TextInputFiles_IsKnownCommand` | 0x101ADBE0 | 80 | yes | - | Tests whether a text starts with one of the 34 known command words. | low |
| `Shape_GetValueAt` | 0x101ADDC0 | 62 | yes | - | Returns a value from the shape table of the entry with id 0x31. | low |
| `TextInputFiles_ShortcutCtor` | 0x101ADE00 | 77 | yes | - | Constructs an empty shortcut entry. | low |
| `FsTextInput_SetName` | 0x101ADE80 | 61 | yes | - | Stores a name string and two values on the input object. | low |
| `TextInputFiles_ShortcutSet` | 0x101ADEC0 | 83 | yes | - | Sets a shortcut's input, handler, two texts and kind. | low |
| `TextInputFiles_ShortcutCheck` | 0x101ADF20 | 141 | yes | - | Runs a shortcut's handler with its text when its input is pressed. | low |
| `FsShortcut_CanUseShortcut` | 0x101AE010 | 288 | yes | - | - | - |
| `FsShortcutManager_Constructor` | 0x101AE140 | 605 | yes | - | - | - |
| `TextInputFiles_UpdateShortcuts` | 0x101AE3E0 | 389 | yes | - | Checks the menu and macro shortcuts each frame. | low |
| `TextInputFiles_CtorVt10337940` | 0x101AEA40 | 78 | yes | - | Constructs a menu item with vtable 0x10337940. | low |
| `TextInputFiles_InitKeyTopShape` | 0x101AEAC0 | 85 | yes | - | Loads the key-top shape for the language. | low |
| `TextInputFiles_CloseKeypadMenu` | 0x101AEB80 | 39 | yes | - | Closes the on-screen keypad menu (one of its two variants by the scene state). | high |
| `TextInputFiles_NoOpC` | 0x101AFF30 | 1 | yes | - | Does nothing. | medium |
| `TextInputFiles_NoOpD` | 0x101AFF40 | 1 | yes | - | Does nothing. | medium |
| `TextInputFiles_ImmGetContext` | 0x101AFF50 | 5 | yes | - | Gets the IME context of a window. | high |
| `TextInputFiles_ImmReleaseContext` | 0x101AFF60 | 5 | yes | - | Releases a window's IME context. | high |
| `FsTextInput_InitWithImeOffscreen` | 0x101AFF70 | 201 | yes | - | Initialises the text input and places the IME's composition and candidate windows off-screen. | high |
| `TextInputFiles_CanOpenInput` | 0x101B0060 | 70 | yes | - | Returns whether text input may open in the current scene state. | low |
| `TextInputFiles_OnMessage` | 0x101B2710 | 222 | yes | - | Handles an IME message by clearing the composition and opening the input menu. | medium |
| `TextInputFiles_NoOp2ArgsA` | 0x101B27F0 | 3 | yes | - | Does nothing. | medium |
| `TextInputFiles_NoOp2ArgsB` | 0x101B2800 | 3 | yes | - | Does nothing. | medium |
| `TextInputFiles_HandleKeyDownWithIme` | 0x101B29F0 | 3023 | yes | - | Handles a key press for the text input while managing the IME context, passing editing keys on to 0x101B5D10. | medium |
| `TextInputFiles_OnChar` | 0x101B36F0 | 384 | yes | - | Handles a typed character in the text input, using the IME state. | medium |
| `TextInputFiles_ResetComposition` | 0x101B3B50 | 183 | yes | - | Resets the IME composition and the input state. | medium |
| `TextInputFiles_HasCompositionOrPending` | 0x101B3F00 | 104 | yes | - | Returns whether the IME has composition text or the input has something pending. | medium |
| `TextInputFiles_HasComposition` | 0x101B3F70 | 75 | yes | - | Reports whether the IME has a composition string. | medium |
| `TextInputFiles_OpenInlineMenus` | 0x101B3FC0 | 105 | yes | - | Clears the IME composition and opens the inline input and palette menus. | high |
| `TextInputFiles_CloseInlineMenusKeepIme` | 0x101B4030 | 144 | yes | - | Closes the inline input and palette menus, remembering whether the IME was on. | high |
| `TextInputFiles_ClearF128AndClose` | 0x101B40C0 | 15 | yes | - | Clears the field at +0xF128 and runs the function at 0x101B7EB0. | low |
| `TextInputFiles_IsOemSlash` | 0x101B4260 | 14 | yes | - | Reports whether a key code is 0xBF. | low |
| `TextInputFiles_ClassifyVirtualKey` | 0x101B4270 | 67 | yes | - | Classifies a Windows virtual-key code (letters, digits, OEM punctuation keys). | medium |
| `TextInputFiles_DoNothing1Arg` | 0x101B4340 | 3 | yes | - | Takes one argument and does nothing. | low |
| `Scene_IsState70` | 0x101B4350 | 15 | yes | - | Reports whether the scene state is 0x70. | low |
| `TextInputFiles_BeginInputWithIme` | 0x101B4360 | 234 | yes | - | Starts text input, putting the IME back into the state it was in. | medium |
| `FsSjisToAscii` | 0x101B4450 | 200 | yes | - | - | - |
| `TextInputFiles_CtorVt103379BCWithLang` | 0x101B4570 | 28 | yes | - | Constructs an object with vtable 0x103379BC that records the scene's language byte. | low |
| `TextInputFiles_DtorVt103379BC` | 0x101B45B0 | 7 | yes | - | Resets an object to vtable 0x103379BC on destruction. | low |
| `TextInputFiles_CtorVt103379C0` | 0x101B45E0 | 41 | yes | - | Constructs a 16-byte object with vtable 0x103379C0. | low |
| `TextInputFiles_CtorVt103379C4` | 0x101B4710 | 69 | yes | - | Constructs an object holding 60 small records and a large buffer. | low |
| `TextInputFiles_Reset` | 0x101B4BB0 | 35 | yes | - | Clears an input buffer and its counts. | low |
| `TextInputFiles_AppendByte` | 0x101B4C20 | 122 | yes | - | Inserts a byte at the cursor of the input buffer. | medium |
| `TextInputFiles_DeleteLast` | 0x101B4D30 | 312 | yes | - | Deletes the character before the cursor in the input buffer. | medium |
| `TextInputFiles_DeleteForward` | 0x101B4E70 | 173 | yes | - | Deletes the character at the cursor in the input buffer. | medium |
| `TextInputFiles_ClearAll` | 0x101B4F90 | 33 | yes | - | Clears an input buffer and its counts. | low |
| `TextInputFiles_MoveBack` | 0x101B4FC0 | 90 | yes | - | Moves the input cursor back one character. | medium |
| `TextInputFiles_MoveForward` | 0x101B5020 | 95 | yes | - | Moves the edit position forward by one character, two bytes for a Shift-JIS double-byte character. | medium |
| `TextInputFiles_ApplySetting` | 0x101B5080 | 165 | yes | - | Applies one setting (by id) to the text input object. | low |
| `FsTextInput_init` | 0x101B5210 | 237 | yes | - | - | - |
| `TextInputFiles_BeginInput` | 0x101B5850 | 524 | yes | - | Starts text input in one of four modes, with its options, callback and target. | low |
| `TextInputFiles_CloseInlineMenu` | 0x101B5A80 | 21 | yes | - | Closes the inline input menu. | high |
| `TextInputFiles_CloseInputMenus` | 0x101B5AA0 | 109 | yes | - | Closes the menus text input opened: the keypad or CSK, and the palette menu. | high |
| `FsTextInput_copyDecidedString` | 0x101B5BC0 | 103 | yes | - | - | - |
| `TextInputFiles_IsModeTwo` | 0x101B5C80 | 15 | yes | - | Reports whether the UI mode is 2. | low |
| `TextInputFiles_IsModeFourOrFive` | 0x101B5C90 | 25 | yes | - | Reports whether the UI mode is 4 or 5. | low |
| `TextInputFiles_IsModeThree` | 0x101B5CC0 | 15 | yes | - | Reports whether the UI mode is 3. | low |
| `TextInputFiles_EndMode4Or5` | 0x101B5CD0 | 61 | yes | - | Ends text input mode 4 (back to mode 3) or mode 5. | low |
| `TextInputFiles_HandleEditKey` | 0x101B5D10 | 2642 | yes | - | Carries out a text-input editing key: delete, completion, submit, cancel, paging, cursor moves and history. | medium |
| `FsTextInput_OnChar` | 0x101B6810 | 742 | yes | - | Adds a typed character to the text input. | medium |
| `TextInputFiles_InputSubmit` | 0x101B6C00 | 331 | yes | - | Submits typed text or the chosen conversion entry to the text input. | low |
| `TextInputFiles_AcceptsChar` | 0x101B6D50 | 231 | yes | - | Tests whether the input's current mode accepts a character. | low |
| `TextInputFiles_InputNotify` | 0x101B6E40 | 75 | yes | - | Notifies the input's callback and refreshes it. | low |
| `TextInputFiles_GetFlag8C81` | 0x101B6E90 | 7 | yes | - | Returns the input's flag at +0x8C81. | low |
| `TextInputFiles_ResetCursor` | 0x101B6EA0 | 26 | yes | - | Resets the text input's cursor and flag. | low |
| `TextInputFiles_GetEntry` | 0x101B6EC0 | 30 | yes | - | Returns the text entry at the current index, or 0 when it is out of range. | low |
| `TextInputFiles_SetWordForCompletion` | 0x101B6EE0 | 433 | yes | - | Sets the word that the completion list looks up. | low |
| `List_Advance` | 0x101B70A0 | 45 | yes | - | Advances the list index by one, wrapping at the end. | low |
| `List_Retreat` | 0x101B70D0 | 37 | yes | - | Moves the list index back by one, wrapping at the start. | low |
| `List_PageDown` | 0x101B7100 | 48 | yes | - | Moves the list index forward by a page of seven entries. | low |
| `List_PageUp` | 0x101B7130 | 41 | yes | - | Moves the list index back by a page of seven entries. | low |
| `TextInputFiles_HasPendingInput` | 0x101B7160 | 35 | yes | - | Returns whether the text input has something pending (its flag at +0x8C81 or a count at +0x8C70). | low |
| `TextInputFiles_ResetBuffer` | 0x101B7190 | 11 | yes | - | Clears the text input buffer. | low |
| `TextInputFiles_InputCall101AC990` | 0x101B7260 | 27 | yes | - | Forwards to the text input's 0x101AC990. | low |
| `TextInputFiles_InputCall101AC990Swapped` | 0x101B7280 | 44 | yes | - | Forwards to the text input's 0x101AC990 with the first two pairs of arguments swapped. | low |
| `TextInputFiles_InputCall101ACAC0` | 0x101B72B0 | 36 | yes | - | Forwards to the text input's 0x101ACAC0. | low |
| `TextInputFiles_Refresh101ABBF0` | 0x101B7890 | 11 | yes | - | Runs the function at 0x101ABBF0 on the text input's line object. | low |
| `TextInputFiles_GetLastWord` | 0x101B7C20 | 219 | yes | - | Copies the last word of the input text. | low |
| `TextInputFiles_DefaultRunLine` | 0x101B7E90 | 24 | yes | - | Runs an entered line as a command, unless the first argument says it was handled. | medium |
| `TextInputFiles_IsState1Or3` | 0x101B7EE0 | 29 | yes | - | Reports whether the session state is 1 or 3. | low |
| `TextInputFiles_ResetField10` | 0x101B91B0 | 13 | yes | - | Sets the object's field at +0x10 to -1. | low |
| `TextInputFiles_CandidatesCtor` | 0x101B9230 | 119 | yes | - | Constructs a candidate record with three entry lists and a string list. | low |
| `TextInputFiles_DestroyInputGlobals` | 0x101B92B0 | 282 | yes | - | Destroys the text-input subsystem's global objects. | low |
| `TextInputFiles_ExitThread1234` | 0x101B94A0 | 11 | yes | - | Ends the calling thread with exit code 0x1234. | high |
| `TextInputFiles_ReleaseSemaphoreAt4` | 0x101B9530 | 23 | yes | - | Releases the semaphore handle at +4 once; 1 on success, -1 on failure. | high |
| `Event_Wait` | 0x101B9550 | 32 | yes | - | Waits on the event handle, returning a success or failure code. | medium |
| `Event_ResetAndWait` | 0x101B95D0 | 57 | yes | - | Resets the event and then waits on it. | medium |
| `Event_Signal` | 0x101B9610 | 19 | yes | - | Signals the event handle, returning a success or failure code. | medium |
| `TextInputFiles_CtorVt10337B1C` | 0x101B9650 | 16 | yes | - | Constructs an object with vtable 0x10337B1C. | low |
| `FsTinyString_init` | 0x101B9690 | 36 | yes | - | - | - |
| `TextInputFiles_DatEntryCtor` | 0x101B9880 | 99 | yes | - | Constructs a DAT entry record with its name and parameters. | low |
| `TextInputFiles_InitWithCallback` | 0x101B9910 | 99 | yes | - | Initialises a DAT entry that uses a callback instead of a buffer. | low |
| `TextInputFiles_CopyFrom` | 0x101B9980 | 115 | yes | - | Copies a DAT entry's fields from another entry. | low |
| `TextInputFiles_ClearVtable` | 0x101B9A00 | 7 | yes | - | Resets a DAT entry's vtable. | low |
| `TextInputFiles_InitCopy` | 0x101B9E00 | 35 | yes | - | Initialises a DAT list node as a copy of another entry. | low |
| `TextInputFiles_CreateGlobal10662DB4` | 0x101B9E60 | 47 | yes | - | Creates the singleton object at 0x10662DB4 once. | medium |
| `TextInputFiles_AppendToList` | 0x101B9EC0 | 92 | yes | - | Appends a DAT entry node to the end of the list. | medium |
| `TextInputFiles_Register` | 0x101B9F20 | 99 | yes | - | Registers a DAT entry with the DAT manager. | medium |
| `TextInputFiles_RemoveById` | 0x101B9F90 | 93 | yes | - | Removes the DAT entry with the given id from the list. | medium |
| `TextInputFiles_Construct` | 0x101BA180 | 20 | yes | - | Constructs the DAT cache object. | low |
| `TextInputFiles_CtorVt10337B2C` | 0x101BA280 | 40 | yes | - | Constructs the object with vtable 0x10337B2C and empty buffers. | low |
| `TextInputFiles_ClearBufferA` | 0x101BA2D0 | 42 | yes | - | Frees the first buffer of the DAT manager. | low |
| `TextInputFiles_ClearBufferB` | 0x101BA300 | 42 | yes | - | Frees the second buffer of the DAT manager. | low |
| `TextInputFiles_CtorVt10337B4C` | 0x101BA570 | 49 | yes | - | Constructs the object with vtable 0x10337B4C. | low |
| `TextInputFiles_Destruct` | 0x101BA5B0 | 11 | yes | - | Releases a DAT block. | low |
| `TextInputFiles_ResetCounters` | 0x101BA5C0 | 11 | yes | - | Resets a DAT block's counters. | low |
| `TextInputFiles_FreeBlocks18To24` | 0x101BADD0 | 74 | yes | - | Frees the three blocks at +0x18, +0x20 and +0x24 and clears their fields. | low |
| `FsWordCompletion_GetCount18` | 0x101BAE20 | 4 | yes | - | Returns the count at +0x18. | low |
| `FsWordCompletion_GetCount1C` | 0x101BAE30 | 4 | yes | - | Returns the count at +0x1C. | low |
| `FsWordCompletion_FindNextByKey` | 0x101BAE40 | 111 | yes | - | Finds the next completion entry with the same key byte. | low |
| `FsWordCompletion_GetField20` | 0x101BAEB0 | 4 | yes | - | Returns the field at +0x20. | low |
| `FsWordCompletion_GetField28` | 0x101BAEC0 | 4 | yes | - | Returns the field at +0x28. | low |
| `FsWordCompletion_Construct` | 0x101BAED0 | 190 | yes | - | Constructs a word completion object and its entries. | low |
| `FsWordCompletion_ClearEntries` | 0x101BAF90 | 44 | yes | - | Clears the completion entries. | low |
| `FsWordCompletion_Init` | 0x101BAFC0 | 139 | yes | - | Initialises a word completion object and its entries. | low |
| `FsWordCompletion_IsEntryValid` | 0x101BB100 | 38 | yes | - | Tests whether a completion entry is usable. | low |
| `FsWordCompletion_CountEntries` | 0x101BB130 | 101 | yes | - | Counts the usable completion entries and their total length. | low |
| `FsWordCompletion_PackEntries` | 0x101BB1A0 | 267 | yes | - | Packs the usable completion entries into a buffer. | low |
| `FsWordCompletion_BuildKind7Block` | 0x101BB2B0 | 374 | yes | - | Builds the kind-7 word completion block (titled by messages 0x91/0x92) from the usable entries and registers it. | low |
| `FsWordCompletion_CountSupported` | 0x101BB430 | 117 | yes | - | Counts the supported completion items and records the total size. | low |
| `FsWordCompletion_BuildItems` | 0x101BB4B0 | 235 | yes | - | Builds the completion item records. | low |
| `FsWordCompletion_AddItem` | 0x101BB5A0 | 224 | yes | - | Adds a completion item to the word completion object. | low |
| `FsWordCompletion_BuildKind13Block` | 0x101BB680 | 186 | yes | - | Builds the kind-0x13 word completion block (titled by messages 0x93/0x94) and adds it. | low |
| `FsWordCompletion_Refresh` | 0x101BB740 | 89 | yes | - | Rebuilds the completion data after a change. | low |
| `FsWordCompletion_LoadData` | 0x101BB7A0 | 567 | yes | - | Loads the word completion data file and builds its entries. | low |
| `FsWordCompletion_Release` | 0x101BB9E0 | 163 | yes | - | Frees the word completion buffers. | low |
| `FsWordCompletion_SetWord` | 0x101BBA90 | 461 | yes | - | Sets the current word for completion and refreshes the candidates. | low |
| `FsWordCompletion_Update` | 0x101BBC60 | 488 | yes | - | Looks up the current word in the sorted completion list each frame. | low |
| `TextInputFiles_IsState204Not1` | 0x101BBE50 | 11 | yes | - | Tells whether the state at +0x204 differs from 1. | low |
| `FsWordCompletion_getEntryList` | 0x101BBE60 | 646 | yes | - | - | - |
| `FsWordCompletion_lookUp` | 0x101BC100 | 888 | yes | - | - | - |
| `FsWordCompletion__prepareAllData` | 0x101BC520 | 452 | yes | - | - | - |
| `TextInputFiles_Store101BB070At8` | 0x101BC6F0 | 42 | yes | - | Stores the result of 0x101BB070 at +8. | low |
| `TextInputFiles_FreeBuffer` | 0x101BC720 | 19 | yes | - | Frees the buffer owned by this object. | medium |
| `TextInputFiles_InitVt10337BA0` | 0x101BC740 | 29 | yes | - | Sets the object's vtable to 0x10337BA0 and clears its fields. | low |
| `TextInputFiles_Set` | 0x101BC7B0 | 55 | yes | - | Sets the range fields and four byte values of a span. | low |
| `Entry_CompareKey` | 0x101BC900 | 155 | yes | - | Compares an entry's stored key with a key string. | low |
| `TextInputFiles_GetUsed` | 0x101BC9B0 | 4 | yes | - | Returns how many bytes of the buffer are in use. | medium |
| `FsMemory_Constructor` | 0x101BC9E0 | 76 | yes | - | - | - |
| `TextInputFiles_AppendPadded` | 0x101BCA40 | 123 | yes | - | Appends bytes to the buffer, padded to 32-byte alignment. | medium |
| `TextInputFiles_ReserveZeroed` | 0x101BCAC0 | 97 | yes | - | Reserves a zeroed, 32-byte aligned block at the end of the buffer. | medium |
| `TextInputFiles_Clear` | 0x101BCB30 | 35 | yes | - | Empties the buffer and zeroes its contents. | medium |
| `TextInputFiles_CtorVt10337C3C` | 0x101BCBA0 | 24 | yes | - | Constructs an object with vtable 0x10337C3C. | low |
| `TextInputFiles_WatchConfigWindow` | 0x101BCE30 | 120 | yes | - | Watches the gamepad configuration window and clears the input state when it closes. | medium |
| `TextInputFiles_CtorVt10337C5C` | 0x101BCEF0 | 18 | yes | - | Constructs an object with vtable 0x10337C5C and clears its buffers. | low |
| `TextInputFiles_ClearTwoBuffers` | 0x101BCF30 | 58 | yes | - | Clears the object's two 10000-byte buffers and their counts. | low |
| `TextInputFiles_CtorVt10337C60` | 0x101BE260 | 24 | yes | - | Constructs the 32-byte record that 0x101BE6C0 fills with a size and three dates. | low |
| `TextInputFiles_SetVtable10337C60` | 0x101BE2A0 | 7 | yes | - | Sets the vtable to 0x10337C60. | high |
| `TextInputFiles_SetField4` | 0x101BE2B0 | 10 | yes | - | Sets the field at +4. | low |
| `TextInputFiles_SetDateAt9` | 0x101BE2C0 | 97 | yes | - | Stores a time value as a calendar date in the fields at +9. | medium |
| `TextInputFiles_SetDateAt11` | 0x101BE330 | 97 | yes | - | Stores a time value as a calendar date in the fields at +0x11. | medium |
| `TextInputFiles_SetDateAt19` | 0x101BE3A0 | 97 | yes | - | Stores a time value as a calendar date in the fields at +0x19. | medium |
| `TextInputFiles_SetVtable10337C64` | 0x101BE410 | 9 | yes | - | Sets the vtable to 0x10337C64. | high |
| `File_FindByKind` | 0x101BE470 | 142 | yes | - | Looks up a file entry in one of three tables by kind. | low |
| `TextInputFiles_Call10311F30` | 0x101BE500 | 16 | yes | - | Calls game_10311F30. | high |
| `TextInputFiles_SeekWhence012` | 0x101BE540 | 66 | yes | - | Seeks with origin 0, 1 or 2 through game_10313CF0; -1 for any other origin. | medium |
| `File_WriteChunked` | 0x101BE590 | 177 | yes | - | Writes a large block in 256 KB chunks, yielding between them. | medium |
| `TextInputFiles_Call10312296` | 0x101BE650 | 28 | yes | - | Calls game_10312296(buffer, 1, count, handle). | high |
| `TextInputFiles_DeleteFile` | 0x101BE670 | 22 | yes | - | Deletes the named file, returning 1 on success and -1 on failure. | high |
| `TextInputFiles_FillSizeAndThreeDates` | 0x101BE6C0 | 112 | no | - | Queries an item through 0x10312487 and fills a record with one value and three dates. | low |
| `File_CreateParentDirs` | 0x101BE730 | 85 | yes | - | Creates each parent directory of a file path. | medium |
| `XiFileImpl_QueueLoad` | 0x101BECC0 | 270 | yes | - | Builds a file load request and queues it. | low |
| `TextInputFiles_SubmitFileNumKind1` | 0x101BF280 | 229 | yes | - | Builds a kind-1 file request from a file number and has it handled at once. | medium |
| `TextInputFiles_SubmitPathKind1` | 0x101BF370 | 237 | yes | - | Builds a kind-1 file request from a formatted path and has it handled at once. | medium |
| `TextInputFiles_SubmitPath2F4Kind1` | 0x101BF460 | 229 | yes | - | Builds a kind-1 file request under the +0x2F4 base path and has it handled at once. | medium |
| `TextInputFiles_SubmitPath3F4Kind1` | 0x101BF550 | 229 | yes | - | Builds a kind-1 file request under the +0x3F4 base path and has it handled at once. | medium |
| `TextInputFiles_ReadFileByName` | 0x101BF710 | 217 | yes | - | Reads the named file into a buffer through the file thread and returns the result. | medium |
| `TextInputFiles_ReadTextOrNoData` | 0x101BF7F0 | 185 | yes | - | Reads a text file for the caller, or gives the text "NO DATA!-0" when it cannot. | medium |
| `TextInputFiles_QueueFileNumKind2` | 0x101BF970 | 295 | yes | - | Builds a kind-2 file request from a file number and queues it. | medium |
| `TextInputFiles_QueuePathKind3` | 0x101C0050 | 258 | yes | - | Builds a kind-3 file request from a formatted path and queues it. | medium |
| `TextInputFiles_QueuePath2F4Kind3` | 0x101C0160 | 250 | yes | - | Builds a kind-3 file request under the +0x2F4 base path and queues it. | medium |
| `TextInputFiles_QueuePath3F4Kind3` | 0x101C0260 | 250 | yes | - | Builds a kind-3 file request under the +0x3F4 base path and queues it. | medium |
| `TextInputFiles_SubmitPathKind3` | 0x101C0440 | 245 | yes | - | Builds a kind-3 file request from a formatted path and has it handled at once. | medium |
| `TextInputFiles_SubmitPath2F4Kind3` | 0x101C0540 | 237 | yes | - | Builds a kind-3 file request under the +0x2F4 base path and has it handled at once. | medium |
| `TextInputFiles_SubmitPath3F4Kind3` | 0x101C0630 | 293 | yes | - | Builds a kind-3 file request under the +0x3F4 base path and has it handled at once. | medium |
| `TextInputFiles_SubmitPath4F4Kind3` | 0x101C0760 | 347 | yes | - | Builds a kind-3 file request under the +0x4F4 base path and has it handled at once. | medium |
| `TextInputFiles_CreateDirAndWait` | 0x101C09B0 | 139 | yes | - | Creates a directory and runs a file-manager job loop; details not established. | low |
| `TextInputFiles_CreateDirAndHandleFile` | 0x101C0A40 | 375 | yes | - | File-manager job that creates a directory and handles a file event; details not established. | low |
| `TextInputFiles_SubmitPathKind6` | 0x101C0FC0 | 195 | yes | - | Builds a kind-6 file request from a formatted path and has it handled at once. | medium |
| `TextInputFiles_SubmitPath3F4Kind6` | 0x101C1090 | 187 | yes | - | Builds a kind-6 file request under the +0x3F4 base path and has it handled at once. | medium |
| `TextInputFiles_FindFileNumKind1` | 0x101C11F0 | 214 | yes | - | Looks for a pending kind-1 request for a file number. | medium |
| `TextInputFiles_FindFileNumKind2` | 0x101C13A0 | 186 | yes | - | Looks for a pending kind-2 request for a file number. | medium |
| `TextInputFiles_FindPathKind3` | 0x101C1750 | 194 | yes | - | Looks for a pending kind-3 request for a formatted path. | medium |
| `TextInputFiles_FindPath2F4Kind3` | 0x101C1820 | 186 | yes | - | Looks for a pending kind-3 request for a file under the +0x2F4 base path. | low |
| `TextInputFiles_FindPath3F4Kind3` | 0x101C18E0 | 186 | yes | - | Looks for a pending kind-3 request for a file under the +0x3F4 base path. | low |
| `TextInputFiles_SubmitFileNumKind4` | 0x101C1B20 | 187 | yes | - | Handles a kind-4 request for a file number at once (the file's size). | low |
| `TextInputFiles_SubmitPath3F4Kind4` | 0x101C1C90 | 187 | yes | - | Handles a kind-4 request for a file under the +0x3F4 base path at once. | low |
| `TextInputFiles_SubmitPathKind4` | 0x101C1DF0 | 195 | yes | - | Handles a kind-4 request for a formatted path at once. | low |
| `TextInputFiles_SubmitPath2F4Kind4` | 0x101C1EC0 | 187 | yes | - | Handles a kind-4 request for a file under the +0x2F4 base path at once. | low |
| `TextInputFiles_GetFileSizeByName` | 0x101C1F80 | 175 | yes | - | Asks the file thread for the size of the named file. | medium |
| `TextInputFiles_GetFileSize24` | 0x101C2030 | 17 | yes | - | Asks for a file's size with the fixed arguments 0x24 and 1. | low |
| `TextInputFiles_SubmitPath3F4Kind5` | 0x101C2450 | 201 | yes | - | Handles a kind-5 request for a file under the +0x3F4 base path at once. | low |
| `TextInputFiles_SubmitPath3F4Kind7` | 0x101C2840 | 192 | yes | - | Handles a kind-7 request for a file under the +0x3F4 base path and reports whether it gave 1. | low |
| `TextInputFiles_WriteTimestampFwd` | 0x101C2D80 | 5 | yes | - | Writes the timestamp file (through Unit1018BA60_WriteTimestamp). | low |
| `TextInputFiles_OpenHexPath` | 0x101C2DC0 | 163 | yes | - | Builds the path for a hex-numbered entry and opens it, creating directories as needed. | low |
| `TextInputFiles_ReleaseAt1F0` | 0x101C33E0 | 11 | yes | - | Calls the release helper on the object at +0x1F0. | low |
| `TextInputFiles_GetValueAt1F0` | 0x101C33F0 | 11 | yes | - | Returns the value that FUN_1019FAB0 gives for the object at +0x1F0. | low |
| `TextInputFiles_FormatUserPath` | 0x101C3D00 | 172 | yes | - | Formats a file path under the base directory, with a hex id directory from the game mode when there is one. | medium |
| `TextInputFiles_FormatStrAt2F4` | 0x101C3DB0 | 38 | yes | - | Formats the string at +0x2F4 into the output buffer. | low |
| `TextInputFiles_FormatStrAt3F4` | 0x101C3DE0 | 38 | yes | - | Formats the string at +0x3F4 into the output buffer. | low |
| `TextInputFiles_FormatStrAt4F4` | 0x101C3E10 | 38 | yes | - | Formats the string at +0x4F4 into the output buffer. | low |
| `TextInputFiles_FormatWithBase` | 0x101C3E40 | 76 | yes | - | Formats a path from a base string and the given parts. | low |
| `TextInputFiles_FormatPathByKind` | 0x101C3E90 | 165 | yes | - | Formats a path into a caller buffer by the object's kind at +8: kind 3 joins the directory at +0xD0 and the name with '/', kind 4 copies the name. | medium |
| `TextInputFiles_CopyPathByMode` | 0x101C3F40 | 93 | yes | - | Copies a path into a buffer by the object's mode. | low |
| `TextInputFiles_MapCode012` | 0x101C3FB0 | 33 | yes | - | Maps the codes 0 and 1 to 1 and 2, and any other code to 0. | low |
| `TextInputFiles_CreateDirectories` | 0x101C3FE0 | 158 | yes | - | Creates a directory and its missing parents. | medium |
| `TextInputFiles_WriteTimestamp` | 0x101C4170 | 235 | yes | - | Writes the current game time to timestamp.dat. | medium |
| `TextInputFiles_ReadTimestamp` | 0x101C4260 | 223 | yes | - | Reads the game time stored in timestamp.dat. | medium |
| `TextInputFiles_FileMngQueueLoad` | 0x101C46E0 | 8 | yes | - | Has the file manager queue a load. | medium |
| `TextInputFiles_ForwardOrExit` | 0x101C4740 | 65 | yes | - | Forwards the call to the inner object and exits the process when it fails. | low |
| `TextInputFiles_FileMngSubmitPathKind1` | 0x101C4790 | 8 | yes | - | Has the file manager handle a kind-1 request for a formatted path at once. | low |
| `TextInputFiles_FileMngSubmitPath2F4Kind1` | 0x101C47A0 | 8 | yes | - | Has the file manager handle a kind-1 request under the +0x2F4 base path at once. | low |
| `TextInputFiles_FileMngSubmitPath3F4Kind1` | 0x101C47B0 | 8 | yes | - | Has the file manager handle a kind-1 request under the +0x3F4 base path at once. | low |
| `TextInputFiles_FileMngReadText` | 0x101C4800 | 8 | yes | - | Reads a text file through the file manager, or gives "NO DATA!-0". | medium |
| `TextInputFiles_FileMngQueueFileNumKind2` | 0x101C4820 | 25 | yes | - | Has the file manager queue a kind-2 request for a file number. | low |
| `TextInputFiles_FileMngQueuePathKind3` | 0x101C48E0 | 8 | yes | - | Has the file manager queue a kind-3 request for a formatted path. | low |
| `TextInputFiles_FileMngQueuePath2F4Kind3` | 0x101C48F0 | 8 | yes | - | Has the file manager queue a kind-3 request under the +0x2F4 base path. | low |
| `TextInputFiles_FileMngQueuePath3F4Kind3` | 0x101C4900 | 8 | yes | - | Has the file manager queue a kind-3 request under the +0x3F4 base path. | low |
| `TextInputFiles_FileMngSubmitPathKind3` | 0x101C4920 | 8 | yes | - | Has the file manager handle a kind-3 request for a formatted path at once. | low |
| `TextInputFiles_FileMngSubmitPath2F4Kind3` | 0x101C4930 | 8 | yes | - | Has the file manager handle a kind-3 request under the +0x2F4 base path at once. | low |
| `TextInputFiles_FileMngSubmitPath3F4Kind3` | 0x101C4940 | 8 | yes | - | Has the file manager handle a kind-3 request under the +0x3F4 base path at once. | low |
| `TextInputFiles_FileMngSubmitPath4F4Kind3` | 0x101C4950 | 8 | yes | - | Has the file manager handle a kind-3 request under the +0x4F4 base path at once. | low |
| `TextInputFiles_FileMngCall101C09B0` | 0x101C4990 | 8 | yes | - | Calls the file manager's 0x101C09B0. | low |
| `TextInputFiles_FileMngCall101C0A40` | 0x101C49A0 | 8 | yes | - | Calls the file manager's 0x101C0A40. | low |
| `TextInputFiles_FileMngSubmitPathKind6` | 0x101C49E0 | 8 | yes | - | Has the file manager handle a kind-6 request for a formatted path at once. | low |
| `TextInputFiles_FileMngSubmitPath3F4Kind6` | 0x101C49F0 | 8 | yes | - | Has the file manager handle a kind-6 request under the +0x3F4 base path at once. | low |
| `TextInputFiles_FileMngFindFileNumKind1` | 0x101C4A10 | 8 | yes | - | Has the file manager look for a pending kind-1 request for a file number. | low |
| `TextInputFiles_FileMngFindFileNumKind2` | 0x101C4A30 | 8 | yes | - | Has the file manager look for a pending kind-2 request for a file number. | low |
| `TextInputFiles_FileMngFwd101C1750` | 0x101C4A80 | 8 | yes | - | Asks the file manager whether a kind-3 request for a path is pending. | low |
| `TextInputFiles_FileMngFwd101C1820` | 0x101C4A90 | 8 | yes | - | Forwards a file-name query to the file manager's inner object. | low |
| `TextInputFiles_FileMngFwd101C18E0` | 0x101C4AA0 | 8 | yes | - | Forwards a path query to the file manager's inner object. | low |
| `FileMng_ResolveOrExit` | 0x101C4AF0 | 50 | yes | - | - | - |
| `TextInputFiles_FileMngFwd101C1C90` | 0x101C4B40 | 8 | yes | - | Forwards to the file manager's 0x101C1C90. | low |
| `TextInputFiles_FileMngFwd101C1DF0` | 0x101C4B60 | 8 | yes | - | Forwards a read to the file manager's 0x101C1DF0. | low |
| `TextInputFiles_FileMngFwd101C1EC0` | 0x101C4B70 | 8 | yes | - | Forwards a file-name call to the file manager's 0x101C1EC0. | low |
| `TextInputFiles_FileMngFwd101C2450` | 0x101C4BF0 | 8 | yes | - | Forwards to the file manager's 0x101C2450. | low |
| `TextInputFiles_FileMngFwd101C2840` | 0x101C4C70 | 8 | yes | - | Forwards to the file manager's 0x101C2840. | low |
| `TextInputFiles_FileMngFwd101C2B60` | 0x101C4CC0 | 8 | yes | - | Forwards to the file manager's 0x101C2B60. | low |
| `TextInputFiles_FileMngFwd101C2C80` | 0x101C4CD0 | 8 | yes | - | Forwards to the file manager's 0x101C2C80. | low |
| `TextInputFiles_FileMngFwd101C4170` | 0x101C4CE0 | 8 | yes | - | Forwards to the file manager's 0x101C4170. | low |
| `TextInputFiles_FileMngFwd101C2E70` | 0x101C4D10 | 8 | yes | - | Forwards to the file manager's 0x101C2E70. | low |
| `TextInputFiles_FileMngReleaseAt1F0` | 0x101C4D30 | 8 | yes | - | Releases the file manager's inner +0x1F0 object. | low |
| `TextInputFiles_FileMngGetValueAt1F0` | 0x101C4D40 | 8 | yes | - | Calls the file manager's inner +0x1F0 getter. | low |
| `TextInputFiles_AllocPlus300OrFree` | 0x101C4D50 | 44 | yes | - | Allocates size + 0x300 bytes, or frees the pointer when the size is 0. | low |
| `TextInputFiles_EntriesCtorEmpty` | 0x101C5920 | 14 | yes | - | Constructs an empty array of 16-byte entries. | low |
| `TextInputFiles_EntriesCtor` | 0x101C5930 | 19 | yes | - | Constructs an array of n 16-byte entries. | low |
| `TextInputFiles_AllocEntries` | 0x101C59B0 | 85 | yes | - | Allocates a zeroed array of 16-byte entries. | medium |
| `TextInputFiles_EntriesSetCount` | 0x101C5A30 | 10 | yes | - | Sets the +4 field (count) of an entry array. | low |
| `TextInputFiles_SubmitFileOrExit` | 0x101C5A40 | 42 | yes | - | Submits the object's file number to the file manager, exiting the game when it fails. | low |
| `TextInputFiles_CtorVt10337C90` | 0x101C5BE0 | 407 | yes | - | Constructor of the object with vtable 0x10337C90: stores the kind, the label string and the callback/position arguments, and sets its flag bytes per kind. | medium |
| `TextInputFiles_CommitTextInput` | 0x101C5EC0 | 98 | yes | - | Takes the text input's decided string and hands it on, keeping the result. | low |
| `TextInputFiles_EndTextInput` | 0x101C60C0 | 30 | yes | - | Commits the text input and ends it. | low |
| `TextInputFiles_CtorVt10337CA0` | 0x101C6810 | 33 | yes | - | Constructs an object with vtable 0x10337CA0 around two values. | low |
| `TextInputFiles_CloseTextInput` | 0x101C68A0 | 57 | yes | - | Closes an open text input and notifies its owner. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `unknown_libname_158` calls nothing directly
- `Time_SetNormalized` calls `Time_Normalize`
- `Time_Normalize` calls nothing directly
- `Time_GetModulo60` calls nothing directly
- `Time_GetModulo3600Div60` calls nothing directly
- `Time_GetModulo216000Div3600` calls nothing directly
- `Time_GetModulo5184000Div216000` calls nothing directly
- `Time_GetDiv5184000` calls nothing directly
- `TextInputFiles_GetGameTimeValue` calls `ntGameTimeGet`, `game_10103B60`, `game_1018C180`, `Time_SetNormalized`, `Time_Normalize`, `Time_GetDiv5184000`
- `Time_SetModulo60` calls `Time_Normalize`
- `Time_SetModulo3600Div60` calls `Time_Normalize`
- `Time_SetModulo216000Div3600` calls `Time_Normalize`
- `Time_FromHours` calls `Time_Normalize`
- `Time_SetModulo155520000Div5184000` calls `Time_Normalize`
- `Time_SetDiv155520000` calls `Time_Normalize`
- `Time_GetDiv5184000Mul5184000` calls `unknown_libname_158`, `Time_GetDiv5184000`, `Time_SetModulo155520000Div5184000`
- `Time_AddFrameScale` calls `Camera_GetFrameScale`, `game_10311C2C`
- `Time_SubtractFrameScale` calls `Camera_GetFrameScale`, `game_10311C2C`
- `fn_1018D170` calls `game_1018D130`
- `TextInputFiles_GrowCapacity` calls nothing directly
- `TextInputFiles_Free` calls `operator_delete`
- `TextInputFiles_InitEmpty` calls `Allocator_Generic`
- `TextInputFiles_Init` calls `TextInputFiles_InitEmpty`
- `TextInputFiles_AssignCStr` calls `TextInputFiles_InitEmpty`, `TextInputFiles_GrowCapacity`, `Allocator_Generic`
- `TextInputFiles_AssignWhole` calls `TextInputFiles_AssignN`
- `TextInputFiles_Append` calls `TextInputFiles_AppendN`
- `TextInputFiles_AppendBuf` calls `TextInputFiles_GetCStr`, `TextInputFiles_AppendN`
- `TextInputFiles_GetCStr` calls nothing directly
- `TextInputFiles_GetLength` calls nothing directly
- `TextInputFiles_GetField4_1018D490` calls nothing directly
- `TextInputFiles_AssignN` calls `game_1018D3D0`, `operator_delete`, `TextInputFiles_GrowCapacity`, `Allocator_Generic`, `game_10312050`
- `TextInputFiles_AppendN` calls `game_10312050`, `TextInputFiles_GrowCapacity`, `Allocator_Generic`, `operator_delete`, `game_10313520`
- `TextInputFiles_InitAcqDat` calls `TextInputFiles_Register`, `TextInputFiles_ClearEntries`
- `TextInputFiles_FillCompletionWords` calls `game_10325D00`, `TextInputFiles_AppendCompletionWord`, `Target_GetActorPtr`, `Yk_GetActiveEntry`
- `TextInputFiles_CommitPending8C` calls nothing directly
- `TextInputFiles_ClearByte10E` calls nothing directly
- `TextInputFiles_Validate8NamesOrClear` calls `game_103146DE`, `TextInputFiles_ClearByte10E`
- `TextInputFiles_AppendCompletionWord` calls `TextInputFiles_Set`
- `TextInputFiles_GetEntryMod` calls nothing directly
- `TextInputFiles_ClearEntries` calls nothing directly
- `TextInputFiles_InitPecDat` calls `TextInputFiles_Register`
- `TextInputFiles_Validate64NamesOrClear` calls `game_103146DE`
- `FsLogPage_InitPage` calls nothing directly
- `FsLogPage_ClearAndVisitFiles` calls `FsLogPage_ClearBuffer`, `FsLogPage_FormatFileName`, `TextInputFiles_FileMngFwd101C1820`, `operator_delete`
- `FsLogPage_FormatFileName` calls `game_10311FF1`
- `FsLogPage_AllocBuffer` calls `FsLogPage_ClearBuffer`, `Allocator_Generic`
- `FsLogPage_load` calls `TextInputFiles_FileMngFwd101C1820`, `TextInputFiles_FileMngFwd101C1EC0`, `TextInputFiles_AllocZeroed`, `TextInputFiles_FileMngSubmitPath2F4Kind1`, `FsLogPage_ClearBuffer`, `Allocator_Generic`, `TextInputFiles_FreeBlock`, `FsLogPage_PruneOffsets`
- `FsLogPage_WriteFile` calls `FsLogPage_PruneOffsets`, `TextInputFiles_FileMngFwd101C1820`, `FsLogPage_FormatFileName`, `operator_delete`, `Allocator_Generic`, `TextInputFiles_FileMngQueuePath2F4Kind3`, `TextInputFiles_FileMngSubmitPath2F4Kind3`
- `FsLogPage_AddString` calls `Allocator_Generic`, `operator_delete`
- `TextInputFiles_GetPageLine` calls nothing directly
- `FsLogPage_ClearBuffer` calls `operator_delete`
- `FsLogPage_PruneOffsets` calls nothing directly
- `FsLogPage_Init` calls nothing directly
- `TextInputFiles_FreeAllLogPages` calls `FsLogPage_ClearAndVisitFiles`, `operator_delete`
- `TextInputFiles_GetLineOfPage` calls `TextInputFiles_GetPageLine`
- `FsLogPage_HasPage` calls nothing directly
- `FsLogPage_EnsurePage` calls `FsLogPage_FormatFileName`, `Allocator_Generic`, `FsLogPage_InitPage`, `FsLogPage_load`
- `TextInputFiles_FreeLogPage` calls `FsLogPage_ClearAndVisitFiles`, `operator_delete`
- `FsLogPage_Rotate` calls `FsLogPage_FormatFileName`, `FsLogPage_WriteFile`, `FsLogPage_ClearAndVisitFiles`, `operator_delete`, `game_103149D0`
- `TextInputFiles_ConstructKind1` calls `TextInputFiles_InitFields`
- `TextInputFiles_ConstructKind2` calls `TextInputFiles_InitFields`
- `TextInputFiles_InitFields` calls nothing directly
- `TextInputFiles_RecreateMembers` calls `FsLogPage_ClearAndVisitFiles`, `operator_delete`, `Allocator_Generic`, `FsLogPage_InitPage`, `FsLogPage_AllocBuffer`, `FsLogPage_Init`, `NetCellFont_MsgWinDataReset`, `NetCellFont_ResetAll`
- `TextInputFiles_FreeLogPagesIfLoaded` calls `TextInputFiles_FreeAllLogPages`
- `TextInputFiles_GetCurrentLogLine` calls `TextInputFiles_GetLineOfPage`, `TextInputFiles_GetPageLine`
- `TextInputFiles_LogLineBack` calls `FsLogPage_HasPage`, `TextInputFiles_FreeLogPage`, `FsLogPage_EnsurePage`, `TextInputFiles_GetLineOfPage`, `TextInputFiles_GetPageLine`
- `TextInputFiles_LogLineForward` calls `FsLogPage_HasPage`, `TextInputFiles_FreeLogPage`, `FsLogPage_EnsurePage`, `TextInputFiles_GetLineOfPage`, `TextInputFiles_GetPageLine`
- `FsLogPage_AddEntry` calls `FsLogPage_AddString`, `FsLogPage_Rotate`, `FsLogPage_HasPage`, `FsLogPage_EnsurePage`, `FsLogPage_AllocBuffer`
- `TextInputFiles_ConstructLarge` calls `NetCellFont_ClearWords`, `TextInputFiles_CtorVt103379C4`
- `Text_ClassifyChar` calls `Sjis_IsLeadByte`
- `Text_GetCharLength` calls `Sjis_IsLeadByte`
- `Text_CountChars` calls `Text_GetCharLength`
- `Sjis_Remap82To83` calls `Text_GetCharLength`
- `Text_EncodeQuotes` calls `Allocator_Generic`, `Text_GetCharLength`, `Text_ClassifyChar`, `game_10312050`, `operator_delete`
- `TextInputFiles_AllocZeroed` calls `Allocator_Generic`
- `TextInputFiles_FreeBlock` calls `operator_delete`
- `TextInputFiles_Nop` calls nothing directly
- `TextInputFiles_CtorVt10336950` calls nothing directly
- `TextInputFiles_Reset10336950` calls `TextInputFiles_Update10336950`
- `FsCSKLogic_closeCSK` calls `Menu_CloseEntry`, `Menu_FindByName`
- `TextInputFiles_Update10336950` calls nothing directly
- `TextInputFiles_UpdateFromMenu` calls `Menu_FindByName`
- `TextInputFiles_CtorVt10336958` calls `NetCellFont_ClearWords`
- `TextInputFiles_FindTopShape` calls `ShapeMng_FindShape`
- `TextInputFiles_FindShapeKey2Top` calls `ShapeMng_FindShape`
- `TextInputFiles_CtorVt103369A0` calls `NetCellFont_ClearWords`, `ShapeMng_FindShape`
- `TextInputFiles_AddPairChecked` calls `TextInputFiles_AddPairAndCall`
- `SetConfig` calls `TextInputFiles_SetEntryValue`
- `Settings_GetValue` calls `TextInputFiles_GetEntryValue`
- `TextInputFiles_GetSetting99` calls `TextInputFiles_GetSettingMapped`
- `TextInputFiles_GetSettingMapped` calls `Settings_GetValue`, `TextInputFiles_TestBit`
- `TextInputFiles_TestBit` calls nothing directly
- `TextInputFiles_TestBit64` calls nothing directly
- `TextInputFiles_InitPairNode` calls nothing directly
- `TextInputFiles_FindOrAdd` calls `Allocator_Generic`, `TextInputFiles_InitPairNode`
- `TextInputFiles_ForEach` calls nothing directly
- `FsConfig_Constructor` calls `TextInputFiles_ConstructVt10336A0C`, `Allocator_Generic`, `TextInputFiles_DefineEntry`, `Camera_GetWord12`, `Camera_GetWord10`, `Camera_PickNearestAspect`
- `TextInputFiles_ResetConfigReturn1` calls `TextInputFiles_ResetConfigToDefaults`
- `TextInputFiles_AddPairAndCall` calls `TextInputFiles_GetEntry2C`, `Allocator_Generic`, `TextInputFiles_InitPairNode`, `TextInputFiles_FindOrAdd`, `TextInputFiles_ForEach`
- `TextInputFiles_SetEntryValue` calls `TextInputFiles_GetEntry2C`, `TextInputFiles_SetConfigEntryValue`
- `TextInputFiles_GetEntryValue` calls `TextInputFiles_GetEntry2C`
- `TextInputFiles_ReloadConfig` calls `StAvatarInfo_SendBytePairKind0`, `TextInputFiles_LoadCnfDat`, `TextInputFiles_ResetConfigToDefaults`, `TextInputFiles_LoadExternalConfig`
- `TextInputFiles_ReadTigDatSetFlag` calls `TextInputFiles_ReadTigDat`
- `TextInputFiles_FlushThenTrue` calls `TextInputFiles_LoadExternalConfig`
- `TextInputFiles_UpdateIfFlag9` calls `TextInputFiles_StoreExternalConfig`, `TextInputFiles_SaveCnfDat`
- `TextInputFiles_DefineEntry` calls nothing directly
- `TextInputFiles_GetEntry2C` calls nothing directly
- `TextInputFiles_WriteTigDat` calls `TextInputFiles_FileMngSubmitPathKind3`
- `TextInputFiles_ReadTigDat` calls `TextInputFiles_FileMngSubmitPathKind1`, `Settings_GetValue`, `TextInputFiles_ForEach`, `TextInputFiles_SetConfigEntryValue`
- `TextInputFiles_StoreExternalConfig` calls `game_10310DF0`, `game_10310DFB`, `TextInputFiles_WriteExternalKind1`, `TextInputFiles_IsExternalKind2Key`, `game_10310E06`, `game_10310E11`, `game_10310E1C`
- `TextInputFiles_LoadExternalConfig` calls `game_10310DF0`, `game_10310DFB`, `TextInputFiles_ReadExternalKind1`, `TextInputFiles_ReadExternalKind2`, `TextInputFiles_SetConfigEntryValue`, `game_10310E1C`
- `TextInputFiles_ReadExternalKind1` calls `game_10310E27`
- `TextInputFiles_WriteExternalKind1` calls `game_10310E27`, `game_10310E32`
- `TextInputFiles_ReadExternalKind2` calls `game_10310B30`, `game_10310B3B`
- `TextInputFiles_IsExternalKind2Key` calls nothing directly
- `TextInputFiles_SaveCnfDat` calls `SetConfig`, `TextInputFiles_FileMngSubmitPathKind3`
- `TextInputFiles_LoadCnfDat` calls `TextInputFiles_FileMngSubmitPathKind1`, `TextInputFiles_SetConfigEntryValue`, `Settings_GetValue`, `TextInputFiles_ForEach`
- `TextInputFiles_SetConfigEntryValue` calls `TextInputFiles_ForEach`
- `TextInputFiles_ResetConfigToDefaults` calls `Settings_GetValue`, `TextInputFiles_ForEach`
- `TextInputFiles_ConstructVt10336A0C` calls nothing directly
- `TextInputFiles_WindowItemCtor` calls `NetCellFont_ClearWords`, `Shape_GetValueAt`, `TextInputFiles_ReturnZero`
- `TextInputFiles_ReturnZero` calls nothing directly
- `TextInputFiles_ClearWords3C` calls `TextInputFiles_WindowItemCtor`
- `TextInputFiles_SetFieldById` calls nothing directly
- `TextInputFiles_SetFieldCallback` calls `TextInputFiles_SetFieldById`
- `TextInputFiles_WindowItemCtorVt10336AC8` calls `TextInputFiles_WindowItemCtor`
- `TextInputFiles_SetFieldById2` calls nothing directly
- `TextInputFiles_SetFieldCallback2` calls `TextInputFiles_SetFieldById2`
- `TextInputFiles_FrameItemCtor` calls `NetCellFont_ClearWords`, `Shape_GetValueAt`
- `TextInputFiles_ConstructVt10336B60` calls `TextInputFiles_FrameItemCtor`
- `TextInputFiles_ConstructVt10336BB0` calls `TextInputFiles_FrameItemCtor`
- `TextInputFiles_CtorVt10336C00` calls `NetCellFont_ClearWords`, `Shape_GetValueAt`
- `TextInputFiles_CtorVt10336C48` calls `NetCellFont_ClearWords`
- `TextInputFiles_ConstructVt10336C90` calls `NetCellFont_ClearWords`
- `TextInputFiles_ConstructVt10336CD8` calls `TextInputFiles_WindowItemCtor`
- `TextInputFiles_WindowItemCtorVt10336D20` calls `TextInputFiles_WindowItemCtor`
- `TextInputFiles_ConstructVt10336D70` calls `TextInputFiles_WindowItemCtorVt10336D20`
- `TextInputFiles_ConstructVt10336DC0` calls `TextInputFiles_WindowItemCtorVt10336D20`
- `TextInputFiles_WindowItemCtorVt10336E10` calls `TextInputFiles_WindowItemCtor`
- `TextInputFiles_WindowItemCtorVt10336E58` calls `TextInputFiles_WindowItemCtor`
- `TextInputFiles_WindowItemCtorVt10336EA0` calls `TextInputFiles_WindowItemCtor`
- `TextInputFiles_ConstructVt10336EE8` calls `TextInputFiles_WindowItemCtor`
- `TextInputFiles_CtorVt10336F30` calls `NetCellFont_ClearWords`, `Shape_GetValueAt`, `TextInputFiles_ReturnZero`
- `TextInputFiles_CtorVt10336F78` calls `NetCellFont_ClearWords`, `Shape_GetValueAt`
- `TextInputFiles_RunPairA` calls `game_103113D3`, `game_10311386`
- `TextInputFiles_RunPairB` calls `game_10311386`, `game_103113D3`
- `TextInputFiles_Call10311386` calls `game_10311386`
- `TextInputFiles_GetSetting41` calls `Settings_GetValue`, `game_10311386`
- `TextInputFiles_Call103113C8` calls `game_103113C8`
- `TextInputFiles_ByteTableCtor` calls `NetCellFont_ClearWords`
- `TextInputFiles_HasTable1037A290CellByte` calls `Cell_GetWord1036D6B0`
- `TextInputFiles_ByteTableDefaultCtor` calls `TextInputFiles_ByteTableCtor`, `TextInputFiles_FillTableBytes`, `game_1019CFA0`, `Config_LoadDefaultTable`
- `Config_LoadDefaultTable` calls `SetConfig`, `game_1019CFA0`
- `TextInputFiles_FillTableBytes` calls `Cell_GetWord1036D6B0`, `game_1019D2B0`
- `TextInputFiles_ByteTableAltCtor` calls `TextInputFiles_ByteTableCtor`, `game_1019D2B0`, `game_1019D350`, `Config_LoadAltTable`
- `Config_LoadAltTable` calls `SetConfig`, `game_1019D350`, `game_1019D320`
- `TextInputFiles_CtorVt103370F8` calls `NetCellFont_ClearWords`
- `TextInputFiles_CtorCachingSettings` calls `TextInputFiles_WindowItemCtor`, `Settings_CacheValues`
- `Settings_CacheValues` calls `Shape_GetValueAt`, `Settings_GetValue`
- `TextInputFiles_DrawTextBlockOnce` calls `game_1019ED50`, `TextInputFiles_GetScaleTimes0`, `TextInputFiles_GetScaleTimes310`, `TextInputFiles_DrawTextLines`
- `TextInputFiles_GetScaleTimes310` calls `game_10311C2C`
- `TextInputFiles_GetScaleTimes0` calls `game_10311C2C`
- `TextInputFiles_GetScaleTimes180` calls `game_10311C2C`
- `TextInputFiles_NextLine` calls nothing directly
- `TextInputFiles_DrawTextLines` calls `game_1019ED50`, `TextInputFiles_GetScaleTimes180`, `game_1019E550`, `game_1019E290`
- `TextInputFiles_CtorWithMenuFepShape` calls `NetCellFont_ClearWords`, `ShapeMng_FindShape`
- `TextInputFiles_PushWithRetry` calls `TextInputFiles_Push`, `TextInputFiles_SignalEvent10`, `TextInputFiles_ResetAndWaitEvent14`
- `TextInputFiles_FindMatchAt8` calls `TextInputFiles_FindMatch`
- `TextInputFiles_WaitThenHandleFileEvent` calls `TextInputFiles_WaitEvent18`, `game_1019FD50`, `TextInputFiles_SignalMember18`
- `TextInputFiles_WaitEvent18At8` calls `TextInputFiles_WaitEvent18`
- `TextInputFiles_SignalMember8` calls `TextInputFiles_SignalMember18`
- `TextInputFiles_Call101BE510IfSize4` calls `game_101BE510`
- `TextInputFiles_FillSizeAndDatesFwd` calls `TextInputFiles_FillSizeAndThreeDates`
- `TextInputFiles_Call101BE670` calls `TextInputFiles_DeleteFile`
- `TextInputFiles_Call101BE690` calls `game_101BE690`
- `TextInputFiles_RunKind8WithCallback` calls `game_101BE690`
- `TextInputFiles_SignalEvent10` calls `Event_Signal`
- `TextInputFiles_ResetAndWaitEvent14` calls `Event_ResetAndWait`
- `TextInputFiles_WaitEvent18` calls `Event_Wait`
- `TextInputFiles_SignalMember18` calls `TextInputFiles_ReleaseSemaphoreAt4`
- `TextInputFiles_Push` calls `Event_Wait`, `TextInputFiles_ReleaseSemaphoreAt4`
- `TextInputFiles_FindMatch` calls `Event_Wait`, `TextInputFiles_ReleaseSemaphoreAt4`
- `TextInputFiles_HasRecords` calls `Event_Wait`, `TextInputFiles_ReleaseSemaphoreAt4`
- `TextInputFiles_IsField84PositiveAfterWait` calls `Event_Wait`, `TextInputFiles_ReleaseSemaphoreAt4`
- `TextInputFiles_Pop` calls `Event_Wait`, `TextInputFiles_ReleaseSemaphoreAt4`
- `TextInputFiles_StringListCtor` calls nothing directly
- `TextInputFiles_SetVtable10337210` calls nothing directly
- `TextInputFiles_PushFrontString` calls `game_103149D0`
- `TextInputFiles_CopyCurrent` calls `game_1018FDF0`
- `TextInputFiles_SetCurrent` calls `game_1018FDF0`
- `TextInputFiles_Advance` calls nothing directly
- `TextInputFiles_Retreat` calls nothing directly
- `TextInputFiles_ClearFirstString` calls nothing directly
- `TextInputFiles_McrEntryCtor` calls nothing directly
- `TextInputFiles_CopyMcrEntry` calls nothing directly
- `TextInputFiles_CopyRecord6x3D` calls nothing directly
- `TextInputFiles_ClearRecord6x3D` calls nothing directly
- `TextInputFiles_ValidateRecord6x3D` calls `TextInputFiles_ClearRecord6x3D`
- `TextInputFiles_GetMcrEntryLine` calls nothing directly
- `TextInputFiles_Create` calls `Allocator_Generic`, `TextInputFiles_McrManagerCtor`
- `TextInputFiles_McrManagerCtor` calls `TextInputFiles_McrEntryCtor`, `TextInputFiles_Register`
- `TextInputFiles_QueueEntry` calls `TextInputFiles_CopyMcrEntry`
- `TextInputFiles_StepScript` calls `game_101A1CB0`, `TextInputFiles_GetMcrEntryLine`, `NetCellFont_AdvanceAndGetMs`, `TextInputFiles_ParseWaitCommand`, `Command_RunLine`
- `TextInputFiles_OnMacroFileLoaded` calls `TargetMenu_GetMessageFwd`, `game_10311FF1`, `ChatLog_AddTextCode37B`, `TextInputFiles_ClearRecord6x3D`, `TextInputFiles_LoadNumberedDatIntoBuffer`, `TextInputFiles_CopyRecord6x3D`, `TextInputFiles_ValidateRecord6x3D`
- `TextInputFiles_LoadCurrentMacroDat` calls `TextInputFiles_SplitIndexBy20`, `TextInputFiles_LoadMacroDat`
- `TextInputFiles_ResetNames0To19` calls `TextInputFiles_FillDefaultNames`, `TextInputFiles_SetName`
- `TextInputFiles_ResetNames20To39` calls `TextInputFiles_FillDefaultNames`, `TextInputFiles_SetName`
- `TextInputFiles_ParseWaitCommand` calls `game_10311EB0`, `game_10313643`, `NetCellFont_AdvanceAndGetMs`, `TextInputFiles_InputCall101AC990Swapped`
- `TextInputFiles_FormatNumberedDatName` calls `game_10311FF1`
- `TextInputFiles_LoadNumberedDatIntoBuffer` calls `TextInputFiles_FormatNumberedDatName`, `TextInputFiles_DatEntryCtor`, `XI_CRYPT_101B9A10 (left out)`, `TextInputFiles_ClearVtable`
- `TextInputFiles_LoadMacroDat` calls `TextInputFiles_FormatNumberedDatName`, `TextInputFiles_InitWithCallback`, `XI_CRYPT_101B9BC0 (left out)`, `TextInputFiles_DatEntryCtor`, `TextInputFiles_RemoveById`, `TextInputFiles_AppendToList`, `TextInputFiles_ClearVtable`
- `TextInputFiles_SplitIndexBy20` calls nothing directly
- `TextInputFiles_SetReadPos` calls `TextInputFiles_LoadNumberedDatIntoBuffer`, `TextInputFiles_LoadMacroDat`
- `TextInputFiles_SetName` calls `TargetMenu_GetMessageFwd`, `game_10311FF1`, `game_10312050`
- `TextInputFiles_GetEntryPtr` calls nothing directly
- `TextInputFiles_FillDefaultNames` calls `TextInputFiles_SetName`
- `TextInputFiles_CtorVt10337314` calls nothing directly
- `TextInputFiles_SetFields1C20` calls nothing directly
- `TextInputFiles_UpdateMenuState` calls `TextInputFiles_StepScript`, `NetCellFont_TestCommand36CF60`, `TextInputFiles_CanOpenMenuShortcut`, `Menu_CloseEntry`, `MenuMng_OpenByName`, `ntGameTimeGet`, `TextInputFiles_HandleReadPosKeys`, `TextInputFiles_ApplyKeyAction`
- `TextInputFiles_SetSlot` calls `TextInputFiles_QueueEntry`
- `TextInputFiles_CanOpenMenuShortcut` calls `TargetMenu_MenuTest48OrStateB4`, `IsEvent`, `Menu_HasFocusedItem`, `Menu_IsFocusedItem`
- `TextInputFiles_ApplyKeyAction` calls `NetCellFont_TestCommand36CF60`, `TextInputFiles_SetSlot`
- `TextInputFiles_HandleReadPosKeys` calls `NetCellFont_TestCommand36CF60`, `TextInputFiles_SetReadPos`, `TextInputFiles_AddMsg10_27IfChangedA`, `TextInputFiles_SetFlag29A`, `TextInputFiles_AddMsg10_27IfChangedB`, `TextInputFiles_SetFlag29B`
- `TextInputFiles_PanelCtorVt10337320` calls `NetCellFont_ClearWords`, `Allocator_Generic`, `TextInputFiles_CtorVt10337B1C`, `FsTinyString_init`
- `TextInputFiles_SetFlag29A` calls nothing directly
- `TextInputFiles_AddMsg10_27IfChangedA` calls `TextInputFiles_GetEntryPtr`, `TextInputFiles_FormatMessage10_27`, `NetCellFont_AddEntry`
- `TextInputFiles_FormatMessage10_27` calls `TargetMenu_GetMessageFwd`, `game_10311FF1`
- `TextInputFiles_PanelCtorVt10337378` calls `NetCellFont_ClearWords`, `Allocator_Generic`, `TextInputFiles_CtorVt10337B1C`, `FsTinyString_init`
- `TextInputFiles_SetFlag29B` calls nothing directly
- `TextInputFiles_AddMsg10_27IfChangedB` calls `TextInputFiles_GetEntryPtr`, `TextInputFiles_FormatMessage10_27`, `NetCellFont_AddEntry`
- `TextInputFiles_CtorVt103373BC` calls nothing directly
- `TextInputFiles_PanelCtorVt103373C8` calls `NetCellFont_ClearWords`, `Allocator_Generic`, `TextInputFiles_CtorVt10337B1C`, `FsTinyString_init`
- `TextInputFiles_PanelCtorVt10337418` calls `NetCellFont_ClearWords`, `Allocator_Generic`, `TextInputFiles_CtorVt10337B1C`, `FsTinyString_init`
- `TextInputFiles_CtorVt10337460` calls `NetCellFont_ClearWords`, `Allocator_Generic`, `TextInputFiles_CtorVt10337C90`
- `TextInputFiles_CtorVt103374A8` calls `NetCellFont_ClearWords`
- `TextInputFiles_CtorVt103374F0` calls `NetCellFont_ClearWords`
- `TextInputFiles_CtorVt10337538` calls `NetCellFont_ClearWords`
- `TextInputFiles_CtorVt1033757C` calls `TextInputFiles_BuildSlotLinks`
- `TextInputFiles_BuildSlotLinks` calls nothing directly
- `TextInputFiles_CtorVt10337580` calls nothing directly
- `TextInputFiles_CreateAll` calls `Allocator_Generic`, `TextInputFiles_CtorVt10337B2C`, `TextInputFiles_InitAcqDat`, `TextInputFiles_InitPecDat`, `TextInputFiles_ConstructKind1`, `TextInputFiles_RecreateMembers`, `TextInputFiles_ConstructKind2`, `TextInputFiles_CtorVt10337C5C`, `TextInputFiles_CtorVt10337C3C`
- `TextInputFiles_CreateDatManager` calls `TextInputFiles_CreateGlobal10662DB4`
- `TextInputFiles_CreateConfigObjects` calls `Allocator_Generic`, `FsConfig_Constructor`, `NetCellFont_ClearWords`, `TextInputFiles_ClearWords3C`, `TextInputFiles_WindowItemCtorVt10336AC8`, `TextInputFiles_ConstructVt10336B60`, `TextInputFiles_CtorVt10336C00`, `TextInputFiles_CtorVt10336C48`, `TextInputFiles_ConstructVt10336C90`, `TextInputFiles_ConstructVt10336CD8`, `TextInputFiles_ConstructVt10336D70`, `TextInputFiles_ConstructVt10336DC0`, `TextInputFiles_WindowItemCtorVt10336E10`, `TextInputFiles_CtorVt10336F30`, `TextInputFiles_ConstructVt10336BB0`, `TextInputFiles_CtorVt10336F78`, `TextInputFiles_ByteTableAltCtor`, `TextInputFiles_ByteTableDefaultCtor`, `TextInputFiles_CtorVt103370F8`, `TextInputFiles_WindowItemCtorVt10336E58`, `TextInputFiles_WindowItemCtorVt10336EA0`, `TextInputFiles_ConstructVt10336EE8`, `TextInputFiles_CtorCachingSettings`, `TextInputFiles_AddPairChecked`, `TextInputFiles_RegisterMenuHandlers`, `game_1019D320`
- `TextInputFiles_RegisterMenuHandlers` calls `TextInputFiles_AddPairChecked`
- `TextInputFiles_ApplyConfigSetting` calls `SoundElem_SetFactor103516F8`, `SoundElem_SetFactor103516FC`, `game_100372A0`, `game_100372E0`, `AppMainLoop_SetShadowSetting`, `AppMainLoop_SetFloat10456A68`, `Gfx_IsGammaSupported`, `Gfx_SetGammaR`, `Gfx_SetGammaG`, `Gfx_SetGammaB`, `AppMainLoop_SetGlobal10456A70`, `AppMainLoop_SetGlobal10456A5C`, `AppMainLoop_SetGlobal10456A6C`, `AppMainLoop_SetFloat10456AB8`, `AppMainLoop_SetFloat10456AA8`, `AppMainLoop_SetCfg0020`, `Gfx_SetAspectIndex`
- `TextInputFiles_ApplyUiSetting` calls `TargetMenu_ResetScrollFwd`, `TargetMenu_SetWord56`, `Settings_GetValue`, `TargetMenu_SetLineCount`, `TargetMenu_SetShownLines`, `game_10162D90`, `SetConfig`, `game_10162EA0`, `TargetMenu_SetFlag58AndResetScroll`, `Menu_ReloadResource`
- `TextInputFiles_CreateEmptyObject` calls `Allocator_Generic`, `TextInputFiles_ReturnThis`
- `TextInputFiles_CreateMenuSystem` calls `TextInputFiles_Create`, `Allocator_Generic`, `TextInputFiles_CtorVt10337314`, `TextInputFiles_PanelCtorVt10337320`, `TextInputFiles_PanelCtorVt10337378`, `TextInputFiles_SetFields1C20`, `TextInputFiles_CtorVt103373BC`, `TextInputFiles_PanelCtorVt103373C8`, `TextInputFiles_PanelCtorVt10337418`, `TextInputFiles_CtorVt10337460`, `NetCellFont_ClearWords`, `TextInputFiles_CtorVt103374A8`, `TextInputFiles_CtorVt1033757C`, `TextInputFiles_CtorVt10337580`, `TextInputFiles_CtorVt103374F0`, `TextInputFiles_CtorVt10337538`
- `TextInputFiles_SaveAll` calls `TextInputFiles_RecreateMembers`, `TextInputFiles_ResetConfigReturn1`, `TextInputFiles_FlushThenTrue`, `TextInputFiles_ReadTigDatSetFlag`
- `TextInputFiles_Call101953D0` calls `TextInputFiles_WriteTigDat`
- `TextInputFiles_ReloadAll` calls `TextInputFiles_NoOpC`, `XI_CRYPT_101BA030 (left out)`, `TextInputFiles_ReloadConfig`, `TextInputFiles_BuildSlotLinks`
- `TextInputFiles_HandleJumpMapKeys` calls `TextInputFiles_CommitPending8C`, `NetCellFont_TestCommand36CF60`, `Command_RunLine`
- `TextInputFiles_LoadAllAndTimestamp` calls `XI_CRYPT_101B9FF0 (left out)`, `TextInputFiles_UpdateIfFlag9`, `game_101C4CF0`, `TextInputFiles_NoOpD`
- `TextInputFiles_ReturnThis` calls nothing directly
- `TextInputFiles_HandleMenuKeys` calls `TextInputFiles_IsModeFourOrFive`, `NetCellFont_TestCommand36CF60`, `Menu_HandleEvent`, `FitFont_ReturnFalse`
- `FsTextInput_Init` calls nothing directly
- `TextInputFiles_SetModeAndReset` calls `TextInputFiles_ResetLineState`
- `TextInputFiles_ResetLineState` calls `TextInputFiles_ClearFirstString`
- `FsTextInput_SetText` calls `Text_GetCharLength`, `game_103149D0`, `FsTextInput_BuildDisplayText`
- `FsTextInput_GetFlag` calls nothing directly
- `FsTextInput_ClearState` calls `TextInputFiles_ClearFirstString`
- `FsTextInput_GetCode` calls nothing directly
- `FsTextInput_CursorLeft` calls `Text_CountChars`, `FsTextInput_RebuildAtCursor`
- `FsTextInput_RebuildAtCursor` calls `Text_ClassifyChar`, `FsTextInput_BuildDisplayTextTrimmed`, `Text_CountChars`, `Text_GetCharLength`, `FsTextInput_BuildDisplayText`
- `FsTextInput_GetActiveBuffer` calls nothing directly
- `FsTextInput_GetPendingBuffer` calls nothing directly
- `FsTextInput_GetLength` calls nothing directly
- `FsTextInput_GetCursorOrLength` calls nothing directly
- `FsTextInput_GetMaxLength` calls nothing directly
- `FsTextInput_Reset` calls `TextInputFiles_ClearFirstString`
- `FsTextInput_HistoryNext` calls `TextInputFiles_SetCurrent`, `TextInputFiles_Advance`, `TextInputFiles_CopyCurrent`, `FsTextInput_BuildDisplayText`, `game_1018FDF0`
- `FsTextInput_HistoryPrev` calls `TextInputFiles_SetCurrent`, `TextInputFiles_Retreat`, `TextInputFiles_CopyCurrent`, `FsTextInput_BuildDisplayText`, `game_1018FDF0`
- `FsTextInput_HasText` calls nothing directly
- `FsTextInput_MoveCursorLeft` calls `Text_CountChars`
- `FsTextInput_MoveCursorRight` calls `Text_GetCharLength`
- `FsTextInput_ResetBuffer` calls `TextInputFiles_ClearFirstString`, `TextInputFiles_SetCurrent`, `TextInputFiles_PushFrontString`
- `FsTextInput_ExpandMarkedPhrase` calls `FsTextInput_IsMarkerAt`, `FsWordCompletion_lookUp`
- `FsTextInput_BuildDisplayText` calls `FsTextInput_IsMarkerAt`, `Sjis_GetCharByteLen`, `game_10312050`, `FsTextInput_ExpandMarkedPhrase`
- `FsTextInput_BuildDisplayTextTrimmed` calls `FsTextInput_IsMarkerAt`, `FsTextInput_ExpandMarkedPhrase`
- `FsTextInput_HasMarkedPhrase` calls `FsTextInput_IsMarkerAt`
- `FsTextInput_CommitEntry` calls `FsTextInput_SetCode4`, `TextInputFiles_GetUsed`, `FsTextInput_MapCodeByte`, `FsTextInput_SetText`, `FsTextInput_CopyCode4`, `FsTextInput_IsMarkerAt`, `FsTextInput_InsertAtCursor`
- `FsTextInput_SetCode4` calls nothing directly
- `FsTextInput_MapCodeByte` calls nothing directly
- `FsTextInput_CopyCode4` calls nothing directly
- `FsTextInput_ClearPair` calls nothing directly
- `FsTextInput_InsertAtCursor` calls `game_103149D0`, `FsTextInput_BuildDisplayText`
- `FsTextInput_DeleteLastWord` calls `Text_CountChars`, `FsTextInput_BuildDisplayText`
- `FsTextInput_IsMarkerAt` calls nothing directly
- `FsPreParser_Constructor` calls nothing directly
- `TextInputFiles_ProcessInputLine` calls `TextInputFiles_InputCall101ACAC0`, `TextInputFiles_IsSlashChar`, `FsTextInput_GetDataPtr8`, `game_10312050`, `game_10313520`, `game_101ADBD0`, `TextInputFiles_InputCall101AC990Swapped`, `TextInputFiles_IsKnownCommand`
- `FsTextInput_GetDataPtr8` calls nothing directly
- `TextInputFiles_IsSlashChar` calls nothing directly
- `TextInputFiles_IsKnownCommand` calls `game_10312940`
- `Shape_GetValueAt` calls `ResourceIter_FindById`, `ShapeMng_FindShape`
- `TextInputFiles_ShortcutCtor` calls nothing directly
- `FsTextInput_SetName` calls nothing directly
- `TextInputFiles_ShortcutSet` calls nothing directly
- `TextInputFiles_ShortcutCheck` calls `NetCellFont_TestCommand36CF60`, `FsShortcut_CanUseShortcut`
- `FsShortcut_CanUseShortcut` calls `ActorHandle_Resolve`, `IsEvent`, `TargetMenu_MenuTest48OrStateB4`, `Menu_HasFocusedItem`, `Menu_FindByName`, `Menu_FindByFlags34`
- `FsShortcutManager_Constructor` calls `TextInputFiles_ShortcutCtor`, `FsTextInput_SetName`, `TextInputFiles_ShortcutSet`
- `TextInputFiles_UpdateShortcuts` calls `TextInputFiles_IsModeFourOrFive`, `TextInputFiles_ShortcutCheck`
- `TextInputFiles_CtorVt10337940` calls `NetCellFont_ClearWords`
- `TextInputFiles_InitKeyTopShape` calls `ShapeMng_FindShape`
- `TextInputFiles_CloseKeypadMenu` calls `Menu_CloseEntry`
- `TextInputFiles_NoOpC` calls nothing directly
- `TextInputFiles_NoOpD` calls nothing directly
- `TextInputFiles_ImmGetContext` calls `LinkedLibraries_JmpImmGetContext`
- `TextInputFiles_ImmReleaseContext` calls `LinkedLibraries_JmpImmReleaseContext`
- `FsTextInput_InitWithImeOffscreen` calls `FsTextInput_init`, `TextInputFiles_ImmGetContext`, `LinkedLibraries_JmpImmSetCompositionWindow`, `LinkedLibraries_JmpImmSetCandidateWindow`, `Imm_NotifyIMEJmp`, `TextInputFiles_ImmReleaseContext`
- `TextInputFiles_CanOpenInput` calls `TargetMenu_MenuTest48OrStateB4`, `TargetMenu_GetByteAE`, `Acter_GetGlobalFlag`
- `TextInputFiles_OnMessage` calls `TextInputFiles_ImmGetContext`, `Imm_NotifyIMEJmp`, `WinMain_GetSceneStateByte68`, `TextInputFiles_ImmReleaseContext`, `MenuMng_OpenByName`
- `TextInputFiles_NoOp2ArgsA` calls nothing directly
- `TextInputFiles_NoOp2ArgsB` calls nothing directly
- `TextInputFiles_HandleKeyDownWithIme` calls `TextInputFiles_ImmGetContext`, `Imm_GetVirtualKeyJmp`, `TextInputFiles_ImmReleaseContext`, `TextInputFiles_IsModeFourOrFive`, `Cursor_GetFlagBit2`, `TextInputFiles_IsOemSlash`, `TextInputFiles_IsModeThree`, `Imm_GetOpenStatusJmp`, `Imm_SetOpenStatusJmp`, `FsTextInput_OnChar`, `TextInputFiles_IsState1Or3`, `TextInputFiles_ClassifyVirtualKey`, `Scene_IsState70`, `Imm_GetCompositionStringAJmp`, `TextInputFiles_InputSubmit`, `TextInputFiles_GetFlag8C81`, `TextInputFiles_IsModeTwo`, `Imm_NotifyIMEJmp`, `TextInputFiles_HandleEditKey`, `MenuMng_OpenByName`, `SetMusicTrackVolume_A`, `SetMusicTrackVolume_C`, `TextInputFiles_ResetCursor`, `Cursor_SetVisible`, `TextInputFiles_HasComposition`, `TextInputFiles_ResetComposition`, `TextInputFiles_UpdateFromMenu`, `SetMusicTrackVolume_B`
- `TextInputFiles_OnChar` calls `NetCellFont_IsNotControlChar`, `TextInputFiles_IsModeFourOrFive`, `TextInputFiles_ImmGetContext`, `Imm_GetOpenStatusJmp`, `Imm_GetConversionStatusJmp`, `FsTextInput_OnChar`, `SetMusicTrackVolume_Tag0004`, `TextInputFiles_ImmReleaseContext`, `TextInputFiles_IsModeThree`, `Imm_SetCompositionStringAJmp`
- `TextInputFiles_ResetComposition` calls `TextInputFiles_ImmGetContext`, `WinMain_GetSceneStateByte68`, `Imm_NotifyIMEJmp`, `Imm_SetCompositionStringAJmp`, `TextInputFiles_ImmReleaseContext`, `TextInputFiles_ResetBuffer`
- `TextInputFiles_HasCompositionOrPending` calls `TextInputFiles_ImmGetContext`, `Imm_GetCompositionStringAJmp`, `TextInputFiles_ImmReleaseContext`, `TextInputFiles_HasPendingInput`
- `TextInputFiles_HasComposition` calls `TextInputFiles_ImmGetContext`, `Imm_GetCompositionStringAJmp`, `TextInputFiles_ImmReleaseContext`
- `TextInputFiles_OpenInlineMenus` calls `TextInputFiles_ImmGetContext`, `Imm_GetOpenStatusJmp`, `Imm_SetCompositionStringAJmp`, `TextInputFiles_ImmReleaseContext`, `MenuMng_OpenByName`
- `TextInputFiles_CloseInlineMenusKeepIme` calls `TextInputFiles_ImmGetContext`, `Imm_GetOpenStatusJmp`, `Imm_GetConversionStatusJmp`, `TextInputFiles_ImmReleaseContext`, `Menu_CloseEntry`, `TextInputFiles_CloseInlineMenu`
- `TextInputFiles_ClearF128AndClose` calls `Menu_CloseEntry`
- `TextInputFiles_IsOemSlash` calls nothing directly
- `TextInputFiles_ClassifyVirtualKey` calls `FontGlyphCache_IsStateTwo`
- `TextInputFiles_DoNothing1Arg` calls nothing directly
- `Scene_IsState70` calls nothing directly
- `TextInputFiles_BeginInputWithIme` calls `TextInputFiles_ImmGetContext`, `Imm_GetOpenStatusJmp`, `Imm_SetOpenStatusJmp`, `TextInputFiles_ImmReleaseContext`, `TextInputFiles_BeginInput`
- `FsSjisToAscii` calls nothing directly
- `TextInputFiles_CtorVt103379BCWithLang` calls nothing directly
- `TextInputFiles_DtorVt103379BC` calls nothing directly
- `TextInputFiles_CtorVt103379C0` calls nothing directly
- `TextInputFiles_CtorVt103379C4` calls `TextInputFiles_CtorVt103379C0`
- `TextInputFiles_Reset` calls nothing directly
- `TextInputFiles_AppendByte` calls `game_103149D0`
- `TextInputFiles_DeleteLast` calls `Font_IsSingleByte`, `game_103149D0`
- `TextInputFiles_DeleteForward` calls `Font_IsSingleByte`, `game_103149D0`
- `TextInputFiles_ClearAll` calls nothing directly
- `TextInputFiles_MoveBack` calls `Font_IsSingleByte`
- `TextInputFiles_MoveForward` calls `Font_IsSingleByte`
- `TextInputFiles_ApplySetting` calls nothing directly
- `FsTextInput_init` calls `FsWordCompletion_Init`, `FsWordCompletion_LoadData`, `TextInputFiles_Nop`, `FsTextInput_Init`
- `TextInputFiles_BeginInput` calls `FsTextInput_ClearState`, `FsTextInput_ClearPair`, `TextInputFiles_ResetCursor`, `TargetMenu_GetByteAE`, `TextInputFiles_SetModeAndReset`
- `TextInputFiles_CloseInlineMenu` calls `Menu_CloseEntry`
- `TextInputFiles_CloseInputMenus` calls `Settings_GetValue`, `FsCSKLogic_closeCSK`, `TextInputFiles_CloseKeypadMenu`, `Menu_FindByName`, `Menu_CloseEntry`
- `FsTextInput_copyDecidedString` calls `FsTextInput_GetActiveBuffer`, `FsTextInput_GetLength`, `TextInputFiles_Nop`
- `TextInputFiles_IsModeTwo` calls nothing directly
- `TextInputFiles_IsModeFourOrFive` calls nothing directly
- `TextInputFiles_IsModeThree` calls nothing directly
- `TextInputFiles_EndMode4Or5` calls nothing directly
- `TextInputFiles_HandleEditKey` calls `TextInputFiles_GetFlag8C81`, `TextInputFiles_SetWordForCompletion`, `MenuMng_OpenByName`, `List_Retreat`, `List_Advance`, `TextInputFiles_GetLastWord`, `FsTextInput_HasText`, `FsTextInput_GetCursorOrLength`, `FsTextInput_GetPendingBuffer`, `TextInputFiles_InputNotify`, `FsTextInput_DeleteLastWord`, `TextInputFiles_InputSubmit`, `TextInputFiles_DeleteLast`, `FsTextInput_CursorLeft`, `TextInputFiles_DeleteForward`, `FsTextInput_RebuildAtCursor`, `TextInputFiles_IsModeFourOrFive`, `TextInputFiles_ClearAll`, `FsTextInput_ClearState`, `FsTextInput_ClearPair`, `FsTextInput_Reset`, `FsTextInput_HistoryNext`, `FsTextInput_HistoryPrev`, `FsTextInput_GetFlag`, `TextInputFiles_MoveBack`, `FsTextInput_MoveCursorLeft`, `TextInputFiles_MoveForward`, `FsTextInput_MoveCursorRight`, `List_PageDown`, `List_PageUp`
- `FsTextInput_OnChar` calls `TextInputFiles_GetFlag8C81`, `game_10311344`, `TextInputFiles_InputSubmit`, `FsTextInput_GetMaxLength`, `TextInputFiles_AppendByte`, `TextInputFiles_SetWordForCompletion`, `MenuMng_OpenByName`, `TextInputFiles_AcceptsChar`, `FsTextInput_SetText`, `SetMusicTrackVolume_Tag0004`
- `TextInputFiles_InputSubmit` calls `Cell_ClearAllFlags`, `TextInputFiles_GetFlag8C81`, `TextInputFiles_GetEntry`, `FsTextInput_CommitEntry`, `FsTextInput_ClearState`, `FsTextInput_ClearPair`, `FsTextInput_GetFlag`, `FsTextInput_GetCode`, `TextInputFiles_SetWordForCompletion`, `MenuMng_OpenByName`, `TextInputFiles_AcceptsChar`, `FsTextInput_SetText`
- `TextInputFiles_AcceptsChar` calls `Font_IsPrintableAscii`, `game_10314801`, `game_103146DE`, `game_1031475C`
- `TextInputFiles_InputNotify` calls `FsTextInput_ResetBuffer`
- `TextInputFiles_GetFlag8C81` calls nothing directly
- `TextInputFiles_ResetCursor` calls nothing directly
- `TextInputFiles_GetEntry` calls nothing directly
- `TextInputFiles_SetWordForCompletion` calls `FsTextInput_ClearState`, `FsWordCompletion_SetWord`, `TextInputFiles_IsState204Not1`, `FsWordCompletion_Update`, `FsWordCompletion_getEntryList`, `TextInputFiles_FillCompletionWords`, `game_10312050`
- `List_Advance` calls nothing directly
- `List_Retreat` calls nothing directly
- `List_PageDown` calls nothing directly
- `List_PageUp` calls nothing directly
- `TextInputFiles_HasPendingInput` calls `TextInputFiles_GetFlag8C81`
- `TextInputFiles_ResetBuffer` calls `TextInputFiles_ClearAll`
- `TextInputFiles_InputCall101AC990` calls `FsTextInput_BuildDisplayText`
- `TextInputFiles_InputCall101AC990Swapped` calls `FsTextInput_BuildDisplayText`
- `TextInputFiles_InputCall101ACAC0` calls `FsTextInput_BuildDisplayTextTrimmed`
- `TextInputFiles_Refresh101ABBF0` calls `TextInputFiles_ResetLineState`
- `TextInputFiles_GetLastWord` calls `FsTextInput_GetActiveBuffer`, `FsTextInput_GetLength`, `Text_CountChars`
- `TextInputFiles_DefaultRunLine` calls `Command_RunLine`
- `TextInputFiles_IsState1Or3` calls nothing directly
- `TextInputFiles_ResetField10` calls nothing directly
- `TextInputFiles_CandidatesCtor` calls `TextInputFiles_StringListCtor`
- `TextInputFiles_DestroyInputGlobals` calls `TextInputFiles_DtorVt103379BC`, `TextInputFiles_SetVtable10337210`, `FsWordCompletion_ClearEntries`, `operator_delete`
- `TextInputFiles_ExitThread1234` calls nothing directly
- `TextInputFiles_ReleaseSemaphoreAt4` calls nothing directly
- `Event_Wait` calls nothing directly
- `Event_ResetAndWait` calls nothing directly
- `Event_Signal` calls nothing directly
- `TextInputFiles_CtorVt10337B1C` calls nothing directly
- `FsTinyString_init` calls `ShapeMng_FindShape`
- `TextInputFiles_DatEntryCtor` calls nothing directly
- `TextInputFiles_InitWithCallback` calls nothing directly
- `TextInputFiles_CopyFrom` calls nothing directly
- `TextInputFiles_ClearVtable` calls nothing directly
- `TextInputFiles_InitCopy` calls `TextInputFiles_CopyFrom`
- `TextInputFiles_CreateGlobal10662DB4` calls `Allocator_Generic`, `TextInputFiles_Construct`
- `TextInputFiles_AppendToList` calls `Allocator_Generic`, `TextInputFiles_InitCopy`
- `TextInputFiles_Register` calls `TextInputFiles_DatEntryCtor`, `TextInputFiles_AppendToList`, `TextInputFiles_ClearVtable`
- `TextInputFiles_RemoveById` calls nothing directly
- `TextInputFiles_Construct` calls nothing directly
- `TextInputFiles_CtorVt10337B2C` calls `TextInputFiles_ClearBufferA`, `TextInputFiles_ClearBufferB`
- `TextInputFiles_ClearBufferA` calls `TextInputFiles_FreeBlock`
- `TextInputFiles_ClearBufferB` calls `TextInputFiles_FreeBlock`
- `TextInputFiles_CtorVt10337B4C` calls `TextInputFiles_InitVt10337BA0`
- `TextInputFiles_Destruct` calls `TextInputFiles_FreeBlocks18To24`
- `TextInputFiles_ResetCounters` calls nothing directly
- `TextInputFiles_FreeBlocks18To24` calls `TextInputFiles_FreeBlock`, `operator_delete`
- `FsWordCompletion_GetCount18` calls nothing directly
- `FsWordCompletion_GetCount1C` calls nothing directly
- `FsWordCompletion_FindNextByKey` calls nothing directly
- `FsWordCompletion_GetField20` calls nothing directly
- `FsWordCompletion_GetField28` calls nothing directly
- `FsWordCompletion_Construct` calls `TextInputFiles_InitVt10337BA0`, `TextInputFiles_CtorVt10337B4C`
- `FsWordCompletion_ClearEntries` calls `FsWordCompletion_Release`, `TextInputFiles_Destruct`
- `FsWordCompletion_Init` calls `FsWordCompletion_Release`, `TextInputFiles_ResetCounters`
- `FsWordCompletion_IsEntryValid` calls nothing directly
- `FsWordCompletion_CountEntries` calls `FsWordCompletion_IsEntryValid`
- `FsWordCompletion_PackEntries` calls `FsWordCompletion_IsEntryValid`
- `FsWordCompletion_BuildKind7Block` calls `TargetMenu_GetMessageFwd`, `FsWordCompletion_CountEntries`, `TextInputFiles_Clear`, `Allocator_Generic`, `FsMemory_Constructor`, `TextInputFiles_AppendPadded`, `TextInputFiles_ReserveZeroed`, `FsWordCompletion_PackEntries`, `TextInputFiles_ResetCounters`
- `FsWordCompletion_CountSupported` calls `TargetMenu_GetInstance`, `TargetMenu_GetCount`, `MenuPanels_IsBitSetForId`, `TargetMenu_GetWordAt`
- `FsWordCompletion_BuildItems` calls `TargetMenu_GetInstance`, `TargetMenu_GetCount`, `MenuPanels_IsBitSetForId`, `TargetMenu_GetWordAt`, `TargetMenu_GetEntryOrEmpty`
- `FsWordCompletion_AddItem` calls `TextInputFiles_AppendPadded`, `TextInputFiles_ReserveZeroed`, `FsWordCompletion_BuildItems`, `TextInputFiles_ResetCounters`
- `FsWordCompletion_BuildKind13Block` calls `TargetMenu_GetMessageFwd`, `FsWordCompletion_CountSupported`, `TextInputFiles_Clear`, `Allocator_Generic`, `FsMemory_Constructor`, `FsWordCompletion_AddItem`
- `FsWordCompletion_Refresh` calls `FsWordCompletion_BuildKind13Block`, `FsWordCompletion_BuildKind7Block`, `FsWordCompletion__prepareAllData`, `TextInputFiles_Store101BB070At8`
- `FsWordCompletion_LoadData` calls `TextInputFiles_Clear`, `Allocator_Generic`, `FsMemory_Constructor`, `Scene_GetTableValue`, `FileMng_ResolveOrExit`, `TextInputFiles_ForwardOrExit`, `TextInputFiles_AppendPadded`, `TextInputFiles_ReserveZeroed`, `TextInputFiles_ResetCounters`, `FsWordCompletion__prepareAllData`, `TextInputFiles_Store101BB070At8`, `operator_delete`, `game_101BCA30`
- `FsWordCompletion_Release` calls `game_101BCA30`, `operator_delete`, `TextInputFiles_FreeBuffer`
- `FsWordCompletion_SetWord` calls `FsWordCompletion_Refresh`, `game_101BB070`, `FsWordCompletion_GetField20`, `FsWordCompletion_GetField28`, `Sjis_Remap82To83`
- `FsWordCompletion_Update` calls `game_101BB070`, `FsWordCompletion_GetField20`, `FsWordCompletion_GetField28`
- `TextInputFiles_IsState204Not1` calls nothing directly
- `FsWordCompletion_getEntryList` calls `TextInputFiles_Set`, `Entry_CompareKey`, `FsWordCompletion_GetCount18`
- `FsWordCompletion_lookUp` calls `TextInputFiles_GetUsed`, `game_1015BC40`, `TargetMenu_GetInstance`, `TargetMenu_GetByValue`, `DmsgText_WrapSjisAt`, `game_101BB070`, `FsWordCompletion_FindNextByKey`
- `FsWordCompletion__prepareAllData` calls `FsWordCompletion_GetCount18`, `FsWordCompletion_GetCount1C`, `TextInputFiles_AllocZeroed`, `operator_delete`, `TextInputFiles_GetUsed`
- `TextInputFiles_Store101BB070At8` calls `game_101BB070`
- `TextInputFiles_FreeBuffer` calls `TextInputFiles_FreeBlock`
- `TextInputFiles_InitVt10337BA0` calls nothing directly
- `TextInputFiles_Set` calls nothing directly
- `Entry_CompareKey` calls `TextInputFiles_GetUsed`, `YkCommon_CompareMapped`, `game_10312940`, `game_10325D00`
- `TextInputFiles_GetUsed` calls nothing directly
- `FsMemory_Constructor` calls `TextInputFiles_AllocZeroed`
- `TextInputFiles_AppendPadded` calls nothing directly
- `TextInputFiles_ReserveZeroed` calls nothing directly
- `TextInputFiles_Clear` calls nothing directly
- `TextInputFiles_CtorVt10337C3C` calls nothing directly
- `TextInputFiles_WatchConfigWindow` calls `Input_SetFlagToggle`
- `TextInputFiles_CtorVt10337C5C` calls `TextInputFiles_ClearTwoBuffers`
- `TextInputFiles_ClearTwoBuffers` calls nothing directly
- `TextInputFiles_CtorVt10337C60` calls nothing directly
- `TextInputFiles_SetVtable10337C60` calls nothing directly
- `TextInputFiles_SetField4` calls nothing directly
- `TextInputFiles_SetDateAt9` calls `game_10314D91`
- `TextInputFiles_SetDateAt11` calls `game_10314D91`
- `TextInputFiles_SetDateAt19` calls `game_10314D91`
- `TextInputFiles_SetVtable10337C64` calls nothing directly
- `File_FindByKind` calls `game_10311FDE`, `File_CreateParentDirs`
- `TextInputFiles_Call10311F30` calls `game_10311F30`
- `TextInputFiles_SeekWhence012` calls `game_10313CF0`
- `File_WriteChunked` calls `game_1031217F`
- `TextInputFiles_Call10312296` calls `game_10312296`
- `TextInputFiles_DeleteFile` calls nothing directly
- `TextInputFiles_FillSizeAndThreeDates` calls `game_10312487`, `TextInputFiles_SetField4`, `TextInputFiles_SetDateAt9`, `TextInputFiles_SetDateAt11`, `TextInputFiles_SetDateAt19`
- `File_CreateParentDirs` calls nothing directly
- `XiFileImpl_QueueLoad` calls `game_101C3A90`, `TextInputFiles_FormatPathByKind`, `TextInputFiles_PushWithRetry`
- `TextInputFiles_SubmitFileNumKind1` calls `game_101C3A90`, `TextInputFiles_FormatPathByKind`, `TextInputFiles_WaitThenHandleFileEvent`
- `TextInputFiles_SubmitPathKind1` calls `TextInputFiles_FormatUserPath`, `TextInputFiles_FormatPathByKind`, `TextInputFiles_WaitThenHandleFileEvent`
- `TextInputFiles_SubmitPath2F4Kind1` calls `TextInputFiles_FormatStrAt2F4`, `TextInputFiles_FormatPathByKind`, `TextInputFiles_WaitThenHandleFileEvent`
- `TextInputFiles_SubmitPath3F4Kind1` calls `TextInputFiles_FormatStrAt3F4`, `TextInputFiles_FormatPathByKind`, `TextInputFiles_WaitThenHandleFileEvent`
- `TextInputFiles_ReadFileByName` calls `TextInputFiles_FormatWithBase`, `TextInputFiles_WaitThenHandleFileEvent`
- `TextInputFiles_ReadTextOrNoData` calls `TextInputFiles_GetFileSize24`, `Allocator_Generic`, `TextInputFiles_ReadFileByName`, `game_10311856`, `operator_delete`
- `TextInputFiles_QueueFileNumKind2` calls `game_101C3A90`, `TextInputFiles_FormatPathByKind`, `TextInputFiles_PushWithRetry`
- `TextInputFiles_QueuePathKind3` calls `TextInputFiles_FormatUserPath`, `TextInputFiles_FormatPathByKind`, `TextInputFiles_MapCode012`, `TextInputFiles_PushWithRetry`
- `TextInputFiles_QueuePath2F4Kind3` calls `TextInputFiles_FormatStrAt2F4`, `TextInputFiles_FormatPathByKind`, `TextInputFiles_MapCode012`, `TextInputFiles_PushWithRetry`
- `TextInputFiles_QueuePath3F4Kind3` calls `TextInputFiles_FormatStrAt3F4`, `TextInputFiles_FormatPathByKind`, `TextInputFiles_MapCode012`, `TextInputFiles_PushWithRetry`
- `TextInputFiles_SubmitPathKind3` calls `TextInputFiles_FormatUserPath`, `TextInputFiles_FormatPathByKind`, `TextInputFiles_MapCode012`, `TextInputFiles_WaitThenHandleFileEvent`
- `TextInputFiles_SubmitPath2F4Kind3` calls `TextInputFiles_FormatStrAt2F4`, `TextInputFiles_FormatPathByKind`, `TextInputFiles_MapCode012`, `TextInputFiles_WaitThenHandleFileEvent`
- `TextInputFiles_SubmitPath3F4Kind3` calls `TextInputFiles_FormatPathByKind`, `TextInputFiles_CreateDirectories`, `TextInputFiles_FormatStrAt3F4`, `TextInputFiles_MapCode012`, `TextInputFiles_WaitThenHandleFileEvent`
- `TextInputFiles_SubmitPath4F4Kind3` calls `game_10311FF1`, `TextInputFiles_CopyPathByMode`, `TextInputFiles_CreateDirectories`, `TextInputFiles_FormatStrAt4F4`, `TextInputFiles_MapCode012`, `TextInputFiles_WaitThenHandleFileEvent`
- `TextInputFiles_CreateDirAndWait` calls `game_1030FED0`, `TextInputFiles_WaitEvent18At8`, `game_10311365`, `TextInputFiles_SignalMember8`, `game_1031135A`
- `TextInputFiles_CreateDirAndHandleFile` calls `game_10311370`, `game_1030FED0`, `TextInputFiles_WaitEvent18At8`, `game_10311365`, `TextInputFiles_SignalMember8`, `game_1031135A`, `TextInputFiles_FormatWithBase`, `TextInputFiles_MapCode012`, `game_101C0BC0`, `TextInputFiles_WaitThenHandleFileEvent`
- `TextInputFiles_SubmitPathKind6` calls `TextInputFiles_FormatUserPath`, `TextInputFiles_FormatPathByKind`, `TextInputFiles_WaitThenHandleFileEvent`
- `TextInputFiles_SubmitPath3F4Kind6` calls `TextInputFiles_FormatStrAt3F4`, `TextInputFiles_FormatPathByKind`, `TextInputFiles_WaitThenHandleFileEvent`
- `TextInputFiles_FindFileNumKind1` calls `game_101C3A90`, `TextInputFiles_FormatPathByKind`, `TextInputFiles_FindMatchAt8`
- `TextInputFiles_FindFileNumKind2` calls `game_101C3A90`, `TextInputFiles_FormatPathByKind`, `TextInputFiles_FindMatchAt8`
- `TextInputFiles_FindPathKind3` calls `TextInputFiles_FormatUserPath`, `TextInputFiles_FormatPathByKind`, `TextInputFiles_FindMatchAt8`
- `TextInputFiles_FindPath2F4Kind3` calls `TextInputFiles_FormatStrAt2F4`, `TextInputFiles_FormatPathByKind`, `TextInputFiles_FindMatchAt8`
- `TextInputFiles_FindPath3F4Kind3` calls `TextInputFiles_FormatStrAt3F4`, `TextInputFiles_FormatPathByKind`, `TextInputFiles_FindMatchAt8`
- `TextInputFiles_SubmitFileNumKind4` calls `game_101C3A90`, `TextInputFiles_FormatPathByKind`, `TextInputFiles_WaitThenHandleFileEvent`
- `TextInputFiles_SubmitPath3F4Kind4` calls `TextInputFiles_FormatStrAt3F4`, `TextInputFiles_FormatPathByKind`, `TextInputFiles_WaitThenHandleFileEvent`
- `TextInputFiles_SubmitPathKind4` calls `TextInputFiles_FormatUserPath`, `TextInputFiles_FormatPathByKind`, `TextInputFiles_WaitThenHandleFileEvent`
- `TextInputFiles_SubmitPath2F4Kind4` calls `TextInputFiles_FormatStrAt2F4`, `TextInputFiles_FormatPathByKind`, `TextInputFiles_WaitThenHandleFileEvent`
- `TextInputFiles_GetFileSizeByName` calls `TextInputFiles_FormatWithBase`, `TextInputFiles_WaitThenHandleFileEvent`
- `TextInputFiles_GetFileSize24` calls `TextInputFiles_GetFileSizeByName`
- `TextInputFiles_SubmitPath3F4Kind5` calls `TextInputFiles_FormatStrAt3F4`, `TextInputFiles_FormatPathByKind`, `TextInputFiles_WaitThenHandleFileEvent`
- `TextInputFiles_SubmitPath3F4Kind7` calls `TextInputFiles_FormatStrAt3F4`, `TextInputFiles_FormatPathByKind`, `TextInputFiles_WaitThenHandleFileEvent`
- `TextInputFiles_WriteTimestampFwd` calls `TextInputFiles_WriteTimestamp`
- `TextInputFiles_OpenHexPath` calls `game_10311FF1`, `TextInputFiles_ReleaseAt1F0`, `game_101C4080`, `TextInputFiles_GetValueAt1F0`, `TextInputFiles_CreateDirectories`
- `TextInputFiles_ReleaseAt1F0` calls `TextInputFiles_WaitEvent18At8`
- `TextInputFiles_GetValueAt1F0` calls `TextInputFiles_SignalMember8`
- `TextInputFiles_FormatUserPath` calls `NetCellFont_GetRecordDwordFwd`, `game_10311FF1`
- `TextInputFiles_FormatStrAt2F4` calls `game_10311FF1`
- `TextInputFiles_FormatStrAt3F4` calls `game_10311FF1`
- `TextInputFiles_FormatStrAt4F4` calls `game_10311FF1`
- `TextInputFiles_FormatWithBase` calls `game_1030FED0`, `game_10311FF1`
- `TextInputFiles_FormatPathByKind` calls `game_10311FF1`
- `TextInputFiles_CopyPathByMode` calls `game_10311FF1`
- `TextInputFiles_MapCode012` calls nothing directly
- `TextInputFiles_CreateDirectories` calls `game_10312050`
- `TextInputFiles_WriteTimestamp` calls `game_10311FF1`, `ntGameTimeGet`, `TextInputFiles_FormatPathByKind`, `TextInputFiles_MapCode012`, `TextInputFiles_WaitThenHandleFileEvent`
- `TextInputFiles_ReadTimestamp` calls `game_10311FF1`, `TextInputFiles_FormatPathByKind`, `TextInputFiles_WaitThenHandleFileEvent`
- `TextInputFiles_FileMngQueueLoad` calls `XiFileImpl_QueueLoad`
- `TextInputFiles_ForwardOrExit` calls `TextInputFiles_SubmitFileNumKind1`, `StAvatarInfo_SendBytePairKind2`, `_exit_0`
- `TextInputFiles_FileMngSubmitPathKind1` calls `TextInputFiles_SubmitPathKind1`
- `TextInputFiles_FileMngSubmitPath2F4Kind1` calls `TextInputFiles_SubmitPath2F4Kind1`
- `TextInputFiles_FileMngSubmitPath3F4Kind1` calls `TextInputFiles_SubmitPath3F4Kind1`
- `TextInputFiles_FileMngReadText` calls `TextInputFiles_ReadTextOrNoData`
- `TextInputFiles_FileMngQueueFileNumKind2` calls `TextInputFiles_QueueFileNumKind2`
- `TextInputFiles_FileMngQueuePathKind3` calls `TextInputFiles_QueuePathKind3`
- `TextInputFiles_FileMngQueuePath2F4Kind3` calls `TextInputFiles_QueuePath2F4Kind3`
- `TextInputFiles_FileMngQueuePath3F4Kind3` calls `TextInputFiles_QueuePath3F4Kind3`
- `TextInputFiles_FileMngSubmitPathKind3` calls `TextInputFiles_SubmitPathKind3`
- `TextInputFiles_FileMngSubmitPath2F4Kind3` calls `TextInputFiles_SubmitPath2F4Kind3`
- `TextInputFiles_FileMngSubmitPath3F4Kind3` calls `TextInputFiles_SubmitPath3F4Kind3`
- `TextInputFiles_FileMngSubmitPath4F4Kind3` calls `TextInputFiles_SubmitPath4F4Kind3`
- `TextInputFiles_FileMngCall101C09B0` calls `TextInputFiles_CreateDirAndWait`
- `TextInputFiles_FileMngCall101C0A40` calls `TextInputFiles_CreateDirAndHandleFile`
- `TextInputFiles_FileMngSubmitPathKind6` calls `TextInputFiles_SubmitPathKind6`
- `TextInputFiles_FileMngSubmitPath3F4Kind6` calls `TextInputFiles_SubmitPath3F4Kind6`
- `TextInputFiles_FileMngFindFileNumKind1` calls `TextInputFiles_FindFileNumKind1`
- `TextInputFiles_FileMngFindFileNumKind2` calls `TextInputFiles_FindFileNumKind2`
- `TextInputFiles_FileMngFwd101C1750` calls `TextInputFiles_FindPathKind3`
- `TextInputFiles_FileMngFwd101C1820` calls `TextInputFiles_FindPath2F4Kind3`
- `TextInputFiles_FileMngFwd101C18E0` calls `TextInputFiles_FindPath3F4Kind3`
- `FileMng_ResolveOrExit` calls `TextInputFiles_SubmitFileNumKind4`, `StAvatarInfo_SendBytePairKind2`, `_exit_0`
- `TextInputFiles_FileMngFwd101C1C90` calls `TextInputFiles_SubmitPath3F4Kind4`
- `TextInputFiles_FileMngFwd101C1DF0` calls `TextInputFiles_SubmitPathKind4`
- `TextInputFiles_FileMngFwd101C1EC0` calls `TextInputFiles_SubmitPath2F4Kind4`
- `TextInputFiles_FileMngFwd101C2450` calls `TextInputFiles_SubmitPath3F4Kind5`
- `TextInputFiles_FileMngFwd101C2840` calls `TextInputFiles_SubmitPath3F4Kind7`
- `TextInputFiles_FileMngFwd101C2B60` calls `game_101C2B60`
- `TextInputFiles_FileMngFwd101C2C80` calls `game_101C2C80`
- `TextInputFiles_FileMngFwd101C4170` calls `TextInputFiles_WriteTimestampFwd`
- `TextInputFiles_FileMngFwd101C2E70` calls `game_101C2E70`
- `TextInputFiles_FileMngReleaseAt1F0` calls `TextInputFiles_ReleaseAt1F0`
- `TextInputFiles_FileMngGetValueAt1F0` calls `TextInputFiles_GetValueAt1F0`
- `TextInputFiles_AllocPlus300OrFree` calls `operator_delete`, `Allocator_Generic`
- `TextInputFiles_EntriesCtorEmpty` calls `TextInputFiles_AllocEntries`
- `TextInputFiles_EntriesCtor` calls `TextInputFiles_AllocEntries`
- `TextInputFiles_AllocEntries` calls `Allocator_Generic`
- `TextInputFiles_EntriesSetCount` calls nothing directly
- `TextInputFiles_SubmitFileOrExit` calls `TextInputFiles_ForwardOrExit`
- `TextInputFiles_CtorVt10337C90` calls `TextInputFiles_InputCall101AC990Swapped`
- `TextInputFiles_CommitTextInput` calls `game_101C6960`, `TextInputFiles_InputCall101AC990Swapped`
- `TextInputFiles_EndTextInput` calls `TextInputFiles_CommitTextInput`
- `TextInputFiles_CtorVt10337CA0` calls nothing directly
- `TextInputFiles_CloseTextInput` calls `TextInputFiles_EndTextInput`
