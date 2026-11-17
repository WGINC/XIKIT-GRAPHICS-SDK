# NetCellFont

Group: `Net` (by the file name only). Source: `sdk/tree_src/NetCellFont.cpp`.

Why the file has this name (data/unit_names.json): the network (604 of its 2,763 functions are in data/security_set.json: the game connection, its packet queue and handlers, the encryption), the UI cells (Cell_*), the cursor, the fonts, the chat log (an address range between two evidenced source files, holding several of the original files: named for its main contents)

493 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `NetCellFont_AddOne` | 0x100D7E90 | 6 | yes | - | Returns the argument plus one. | low |
| `Game_HasInitCount` | 0x100D9A70 | 9 | yes | - | Tests whether the init counter at +2 is nonzero. | low |
| `NetCellFont_GetEntryMod1066268C` | 0x100D9B00 | 21 | yes | - | Unit1018BA60_GetEntryMod(.., 0) of the object at DAT_1066268C, or 0. | high |
| `Game_InitSceneState` | 0x100DA6A0 | 169 | yes | - | Initialises the scene state fields after game init. | low |
| `GameMode_GetField98` | 0x100DB100 | 7 | yes | - | - | - |
| `GameMode_PollPendingState` | 0x100DB140 | 35 | yes | - | - | - |
| `GameMode_RequestState` | 0x100DB170 | 1043 | yes | - | - | - |
| `NetCellFont_GetRecordWordFwd` | 0x100DB780 | 16 | yes | - | Forwards to Unit100D7420_GetRecordWord. | high |
| `NetCellFont_GetRecordDwordFwd` | 0x100DB790 | 16 | yes | - | Forwards to Unit100D7420_GetRecordDword. | high |
| `NetCellFont_LookupNameIfKind3` | 0x100DB7B0 | 30 | yes | - | Looks up the name for a key when the object's kind at +0x98 is 3. | high |
| `NetCellFont_GetWord40D7C` | 0x100DB930 | 21 | yes | - | Returns a word from the zone block at +0x40D7C. | low |
| `NetCellFont_GetField0xA4` | 0x100DBAA0 | 7 | yes | - | Returns the field at offset 0xA4 of its object. | low |
| `GameMode_OpenTacticsUrl` | 0x100DBB50 | 187 | yes | - | - | - |
| `Game_IsFlag10492DB4` | 0x100DBCA0 | 11 | yes | - | Tests the global flag at DAT_10492DB4. | low |
| `NetCellFont_ReturnTrue100DBDE0` | 0x100DBDE0 | 3 | yes | - | Returns true. | high |
| `Time_GetMilliseconds` | 0x100DBE00 | 6 | yes | - | Returns the system time from timeGetTime. | high |
| `NetCellFont_GetTimeNow` | 0x100DBE30 | 29 | yes | - | Stores sub_10314EF1(NULL) (time(NULL) shape) and 0 into the two outputs. | medium |
| `NetCellFont_InitTimer` | 0x100DBE50 | 81 | yes | - | Initialises the timer block at 0x10492DB8 from the system clock and resets its wrap counter. | medium |
| `NetCellFont_Sync` | 0x100DBEB0 | 71 | yes | - | Advances the timer and syncs its last-sample fields. | low |
| `NetCellFont_DiffWrapped` | 0x100DBF00 | 26 | yes | - | Returns the difference between two times, wrapping at param_1. | medium |
| `NetCellFont_AdvanceClock` | 0x100DBF20 | 175 | yes | - | Advances the timer's seconds and milliseconds from the system clock. | medium |
| `NetCellFont_GetTotalMilliseconds` | 0x100DC060 | 25 | yes | - | Returns the timer's total time in milliseconds. | medium |
| `NetCellFont_GetSeconds` | 0x100DC080 | 9 | yes | - | Returns the timer's seconds field. | low |
| `NetCellFont_GetMilliseconds` | 0x100DC090 | 9 | yes | - | Returns the timer's milliseconds field. | low |
| `NetCellFont_AdvanceAndGetMs` | 0x100DC120 | 10 | yes | - | Advances the timer and returns its total milliseconds. | low |
| `NetCellFont_AdvanceAndGetSeconds` | 0x100DC130 | 10 | yes | - | Advances the timer and returns its seconds. | low |
| `NetCellFont_Reset` | 0x100DC1F0 | 27 | yes | - | Resets the wrap counter and records the current tick count. | medium |
| `NetCellFont_Update` | 0x100DC210 | 49 | yes | - | Updates the last tick count and counts timer wraparounds. | medium |
| `NetCellFont_IsInitialized` | 0x100DC2C0 | 11 | yes | - | Tests whether the crypt context has been set up. | low |
| `Entry_FindByNormalizedName` | 0x100E08D0 | 197 | yes | - | Finds an entry by its normalised name. | low |
| `Name_Normalize` | 0x100E09A0 | 94 | yes | - | Copies a name with its non-matching characters removed. | low |
| `NetCellFont_FindEntryByName` | 0x100E0A50 | 71 | yes | - | Looks a name up with Entry_FindByNormalizedName: 1 found, 0 not found, 2 when DAT_104DFD98 is missing or its byte +0x1A698 is not 1 (then it calls fn_100E0AA0). | medium |
| `NetCellFont_NoOp100E0B10` | 0x100E0B10 | 1 | yes | - | Does nothing. | high |
| `NetCellFont_ApplyNoticeRecord` | 0x100E0D50 | 1621 | yes | - | Applies a notice record by its kind at +0xC; details not established. | low |
| `Entry_ResetFields` | 0x100E13C0 | 70 | yes | - | Clears an entry's fields and runs its callback. | low |
| `NetCellFont_AllocEntry4` | 0x100E19C0 | 236 | yes | - | Allocates one of four fixed-size table entries. | low |
| `NetCellFont_AllocEntryFromTable` | 0x100E1AD0 | 26 | yes | - | Allocates an entry from the table the global points to, or returns 0 when there is none. | medium |
| `NetCellFont_CountActive` | 0x100E1B50 | 49 | yes | - | Counts the active entries in a two-entry table. | low |
| `NetCellFont_ClearMatching` | 0x100E1C00 | 48 | yes | - | Clears the table entry that matches the given pointer. | low |
| `NetCellFont_RegisterHandler1369C` | 0x100E2E70 | 99 | yes | - | Registers a handler on the record at DAT_104DF770+0x1369C and clears matching old entries. | low |
| `NetCellFont_RegisterHandler1369CFlag1` | 0x100E2EE0 | 36 | yes | - | Unit100D7420_RegisterHandler1369C with the last argument 1. | high |
| `NetCellFont_GetEntryMod1066268CFwd` | 0x100E3E30 | 5 | yes | - | Forwards to Unit100D7420_GetEntryMod1066268C. | high |
| `NetCellFont_GetBlock2CFD8` | 0x100E47A0 | 26 | yes | - | Returns the address of the block at +0x2CFD8 of the zone state. | low |
| `NetCellFont_SetGlobal104B1774` | 0x100E5E30 | 10 | yes | - | Stores a value in the global at DAT_104B1774. | low |
| `NetCellFont_GetBlock2CDE8IfReady` | 0x100E6020 | 38 | yes | - | Returns the block at +0x2CDE8 when its two ready bytes are set. | low |
| `NetCellFont_SetWord130` | 0x100E62C0 | 36 | yes | - | Stores a word at +0x130 of the state object and clears its pending byte. | low |
| `NetCellFont_ClearBit0Slot` | 0x100E6370 | 25 | yes | - | Clears bit 0 of a dword in an indexed slot of the state object. | low |
| `NetCellFont_SetFlagFCBit1` | 0x100E63B0 | 12 | yes | - | Sets bit 1 of the object's flags at +0xFC. | low |
| `NetCellFont_ClearBit1Fc` | 0x100E63C0 | 12 | yes | - | Clears bit 0x02 of the word at +0xFC of the given object. | low |
| `NetCellFont_ScanEntriesAndInit` | 0x100E63E0 | 621 | yes | - | Walks the 300 entries, collects those whose key matches the word at +0x130 into a list, and initialises encryption when any were collected. | low |
| `NetCellFont_InitEncrypt` | 0x100E6650 | 60 | yes | - | Initialises the state's encryption context and sets its pending flag. | medium |
| `NetCellFont_IsBeforeDeadline` | 0x100E6790 | 43 | yes | - | Tests whether the current time is before the state's deadline. | low |
| `NetCellFont_IsCountOrByte134Set` | 0x100E67E0 | 36 | yes | - | Returns 1 when the active count is non-zero or the byte at +0x134 is set. | low |
| `NetCellFont_ClearTimer140` | 0x100E6810 | 27 | yes | - | Clears the timer word at +0x140 and runs the state flush. | low |
| `NetCellFont_ScanIfTimer140Set` | 0x100E6830 | 33 | yes | - | Runs the entry scan when the timer word at +0x140 is non-zero and returns 0; returns 1 when it is zero. | low |
| `NetCellFont_IsTimer140Clear` | 0x100E6860 | 19 | yes | - | Tests whether the timer word at +0x140 is zero. | low |
| `NetCellFont_GetWord132` | 0x100E6B10 | 13 | yes | - | Returns the word at +0x132 of the state object. | low |
| `NetCellFont_BuildListA90` | 0x100E6B20 | 210 | yes | - | Rebuilds the list of entry indexes at +0x832 from the 300 entries at +0xA90 and returns the count. | low |
| `NetCellFont_GetEntryPtrA90` | 0x100E6C40 | 44 | yes | - | Returns the entry in the state's table at +0xA90 for an index. | low |
| `NetCellFont_ClearPending` | 0x100E7260 | 28 | yes | - | Clears the pending byte and word of the state object. | low |
| `sub_100E7B20` | 0x100E7B20 | 63 | no | - | Calls one of two thunked routines according to whether the index is below 200, and returns its result. | low |
| `NetCellFont_SetByte9800AndGetEntry` | 0x100E8B80 | 227 | yes | - | Stores its argument at byte +0x9800, sets the index at +0x97FC to 1, fills the entry selected by the argument from globals, and returns that entry. | low |
| `NetCellFont_SelectNext` | 0x100E8C70 | 307 | yes | - | Returns the next entry of a 20-entry table that passes the state test. | low |
| `NetCellFont_GetSlotPtr` | 0x100EB490 | 86 | yes | - | Returns the slot record for an index, claiming it when the second argument is 0 and the record is free. | medium |
| `NetCellFont_CountFreeEntries` | 0x100EB8D0 | 104 | yes | - | Counts the zero-valued entries of the given table group, or returns -1 when there is no state object. | medium |
| `NetCellFont_GetEntryCount` | 0x100EB940 | 24 | yes | - | Returns the number of entries in the given group. | medium |
| `NetCellFont_FindOrRemove` | 0x100EBF80 | 222 | yes | - | Finds a keyed record, or removes it by moving the last record into its place. | medium |
| `NetCellFont_RemoveRecord` | 0x100EC060 | 21 | yes | - | Removes the keyed record from the pool. | medium |
| `NetCellFont_ResetCounter` | 0x100EDEA0 | 11 | yes | - | Sets the global counter at DAT_104ca648 to zero. | low |
| `NetCellFont_Advance` | 0x100EDEB0 | 24 | yes | - | Advances the global counter and tests whether it passed 0xE0F. | low |
| `NetCellFont_StepRequest1FSequence` | 0x100EDFB0 | 210 | yes | - | Runs one step of the request 0x1F exchange with the session; 1 when finished, -1 on failure. | low |
| `NetCellFont_StepWait1030FF96` | 0x100EE0A0 | 166 | yes | - | Steps through starting 0x1030FF8B and waiting on 0x1030FF96, with a status message; 1 when finished, -1 on failure. | low |
| `NetCellFont_StepRequest21Sequence` | 0x100EE690 | 574 | yes | - | Runs one step of the request 0x21 exchange with the session; 1 when finished, -1 on failure. | low |
| `NetCellFont_StepRequest22Sequence` | 0x100EE900 | 574 | yes | - | Runs one step of the request 0x22 exchange with the session; 1 when finished, -1 on failure. | low |
| `NetCellFont_StepRequest28Sequence` | 0x100EEB70 | 574 | yes | - | Runs one step of the request 0x28 exchange with the session; 1 when finished, -1 on failure. | low |
| `NetCellFont_StepRequest2BSequence` | 0x100EEDE0 | 170 | yes | - | Runs one step of the request 0x2B exchange with the session; 1 when finished, -1 on failure. | low |
| `NetCellFont_StepState1030FFxx` | 0x100EEE90 | 215 | yes | - | One step of a state machine in *param_1 driving the sub_1030FFxx imports and recording errors at DAT_104DF770+0x136AC. | low |
| `NetCellFont_StepWait1030FFD8` | 0x100EEF80 | 155 | yes | - | Steps through starting 0x1030FFCD and waiting on 0x1030FFD8, with a status message; 1 when finished, -1 on failure. | low |
| `NetCellFont_StepRequest14Sequence` | 0x100EF020 | 185 | yes | - | Runs one step of the request 0x14 exchange with the session; 1 when finished, -1 on failure. | low |
| `NetCellFont_RunState` | 0x100EF0E0 | 181 | yes | - | Runs the handler for the current state value and calls the frame tail on success. | low |
| `NetCellFont_StepStateWithEntries` | 0x100EF4C0 | 142 | yes | - | Runs one step of a three-state sequence that initialises the state, waits on the timer, and counts the entries. | low |
| `NetCellFont_StepStateWithTimer` | 0x100EF550 | 85 | yes | - | Runs one step of a three-state sequence that resets, clears the timer, and checks the timer. | low |
| `NetCellFont_UpdateSessionIfReady` | 0x100EF5B0 | 13 | yes | - | Calls Unit100D7420_UpdateSession when DAT_104DF770 exists (returns 1), else -1. | high |
| `NetCellFont_UpdateSessionReturn1` | 0x100EF5BD | 11 | yes | - | Calls Unit100D7420_UpdateSession and returns 1 (the tail of fn_100EF5B0). | high |
| `NetCellFont_DispatchByKindAndUpdate` | 0x100EF640 | 61 | yes | - | Runs the handler the table at 0x1036202C holds for the record's first dword, then the session update. | low |
| `NetCellFont_StatusText80IfFlags44` | 0x100EF870 | 52 | yes | - | Applies status text 0x80 when flags 0x04 and 0x40 are both set. | high |
| `NetCellFont_StatusText80IfFlag4Only` | 0x100EF8B0 | 52 | yes | - | Applies status text 0x80 when flag 0x04 is set without 0x40. | high |
| `NetCellFont_GetSessionField13C` | 0x100EF8F0 | 43 | yes | - | Returns field 0x13C of the object at DAT_104DF770+0x13690, or 0. | high |
| `NetCellFont_GetRecordWord` | 0x100EFC70 | 35 | yes | - | Returns the key word of the record at the given index. | low |
| `NetCellFont_GetRecordDword` | 0x100EFCA0 | 30 | yes | - | Returns the key dword of the record at the given index. | low |
| `Name_LookupByKey` | 0x100EFCE0 | 63 | yes | - | Returns the name stored for a key, or the unknown-name string. | medium |
| `NetCellFont_CopyToGlobalBuffer` | 0x100F0000 | 24 | yes | - | Copies a string into the global buffer at 0x104CA438. | medium |
| `NetCellFont_GetBlock2CF54IfFlag` | 0x100F00A0 | 29 | yes | - | Returns the block at DAT_104DFD98+0x2CF54 when its flag byte +0x2CFD4 is set, else null. | high |
| `NetCellFont_ReturnTrue100F02A0` | 0x100F02A0 | 3 | yes | - | Returns true. | high |
| `NetCellFont_SetByte15110` | 0x100F04F0 | 27 | yes | - | Stores one byte at offset 0x15110 of the state object. | low |
| `NetCellFont_SetByte15114` | 0x100F0550 | 27 | yes | - | Stores one byte at offset 0x15114 of the state object. | low |
| `NetCellFont_ClearDword136A4` | 0x100F05F0 | 25 | yes | - | Clears the dword at offset 0x136A4 of the state object. | low |
| `NetCellFont_GetFlagsMasked` | 0x100F0C50 | 23 | yes | - | Returns the session flags word shifted right by 8 and masked to bits 0, 8-15 and 24-31, or 0 when the global is null. | low |
| `NetCellFont_GetWord40D82` | 0x100F1080 | 22 | yes | - | Returns the word at +0x40D82 of the object at 0x104DFD98. | low |
| `NetCellFont_ClearRecord` | 0x100F10C0 | 42 | yes | - | Clears one 0x2C-byte pool record. | medium |
| `NetCellFont_UpdateActive` | 0x100F10F0 | 98 | yes | - | Runs the callbacks of the active pool records and clears the finished ones. | medium |
| `NetCellFont_StepBitGuardedTask` | 0x100F1160 | 257 | yes | - | Steps a task state machine at +0x24 that holds a bit (Unit100D7420_SetBit/ClearBit) while it runs. | low |
| `NetCellFont_AcquireIfFree` | 0x100F1280 | 49 | yes | - | Allocates a pool entry when the check on param_1 passes. | low |
| `NetCellFont_AllocRecord` | 0x100F1300 | 61 | yes | - | Takes the first free 0x2C-byte record from the record table, marks it in use, stores the four arguments in it and returns it, or returns 0 when none is free. | medium |
| `NetCellFont_InitEntry` | 0x100F1340 | 49 | yes | - | Sets the fields of an in-use pool record. | low |
| `NetCellFont_IsBitSet` | 0x100F13B0 | 20 | yes | - | Tests one bit of the pool's bitmask. | low |
| `NetCellFont_SetBit` | 0x100F13D0 | 19 | yes | - | Sets one bit of the pool's bitmask. | low |
| `NetCellFont_ClearBit` | 0x100F13F0 | 25 | yes | - | Clears one bit of the pool's bitmask. | low |
| `NetCellFont_Query10310030` | 0x100F1670 | 61 | yes | - | Queries status through sub_10310030/sub_1030FF75 and returns a 2-bit state or -1. | low |
| `NetCellFont_Call10310067` | 0x100F1870 | 24 | yes | - | Calls sub_10310067. | high |
| `NetCellFont_Call10310072` | 0x100F1900 | 14 | yes | - | Calls sub_10310072. | high |
| `NetCellFont_GetLow16` | 0x100F1950 | 11 | yes | - | Returns the low 16 bits of the result of sub_103100EB. | low |
| `NetCellFont_AcquireNode` | 0x100F1B20 | 119 | yes | - | Returns a free node from the list, allocating one when the list is not full. | medium |
| `NetCellFont_InitTwoNodes` | 0x100F1BA0 | 150 | yes | - | Initialises a pool object and creates its two working nodes. | medium |
| `NetCellFont_Destroy` | 0x100F1C40 | 183 | yes | - | Tears down a pool object: finishes its pending requests and frees its nodes, clearing the global pointer if the object is the global. | medium |
| `NetCellFont_UpdateRequests` | 0x100F1D20 | 325 | yes | - | Per-frame update of the two pending request slots at +0x24/+0x28, running their callbacks. | low |
| `NetCellFont_ResetPending` | 0x100F1E70 | 140 | yes | - | Clears the pool object's pending state and completes its current request, as the first step of initialising or destroying it. | medium |
| `NetCellFont_BeginRequests` | 0x100F1F00 | 281 | yes | - | Starts the request sequence on the global request object (called by fn_100F7740). | low |
| `NetCellFont_StartRequestSlot20` | 0x100F25F0 | 68 | yes | - | Starts a request on the slot at +0x20 with the next sequence number. | high |
| `NetCellFont_StartRequestOnNewNodeA` | 0x100F2690 | 58 | yes | - | Starts a request on a newly acquired node through fn_100F3C20. | high |
| `NetCellFont_StartRequestOnNewNodeB` | 0x100F2720 | 58 | yes | - | Starts a request on a newly acquired node through fn_100F3C90. | high |
| `NetCellFont_StartRequestSlot24` | 0x100F2760 | 63 | yes | - | Starts a request on the slot at +0x24 with the next sequence number. | high |
| `NetCellFont_ClearNode` | 0x100F29E0 | 94 | yes | - | Clears a pool node to its initial state. | medium |
| `NetCellFont_DestroyNode` | 0x100F2A40 | 33 | yes | - | Destroys a pool node and the block it owns. | medium |
| `NetCellFont_Complete` | 0x100F2B80 | 186 | yes | - | Finishes a pool request and runs its completion callbacks. | low |
| `NetCellFont_CallStateCallback3` | 0x100F2C40 | 53 | yes | - | Calls the request's current state callback with code 3; returns true when there is none or it returns 0. | high |
| `NetCellFont_RunCallbacks` | 0x100F2C80 | 910 | yes | - | Steps through the object's callback table, calling each callback until one does not ask to advance, then runs its completion callbacks. | medium |
| `NetCellFont_CopyBounded` | 0x100F3010 | 55 | yes | - | Copies at most a fixed number of bytes and ends the string with NUL. | medium |
| `NetCellFont_StartCallbacks` | 0x100F32B0 | 91 | yes | - | Installs a callback table on a pool object and runs its first callback to start the request. | medium |
| `NetCellFont_StartIfIdle` | 0x100F3380 | 74 | yes | - | Starts the object with the callback table at 0x103622FC unless it is already running. | low |
| `NetCellFont_InitRequestA` | 0x100F3BB0 | 112 | yes | - | Fills a request record (variant A) and starts its callbacks; 3 when the record is busy. | medium |
| `NetCellFont_InitRequestB` | 0x100F3C20 | 104 | yes | - | Fills a request record (variant B) and starts its callbacks; 3 when the record is busy. | medium |
| `NetCellFont_InitRequestC` | 0x100F3C90 | 112 | yes | - | Fills a request record (variant C) and starts its callbacks; 3 when the record is busy. | medium |
| `NetCellFont_InitRequestD` | 0x100F3D00 | 98 | yes | - | Fills a request record (variant D) and starts its callbacks; 3 when the record is busy. | medium |
| `NetCellFont_StartGlobalRequestSlot24` | 0x100F7620 | 37 | yes | - | Starts a request on slot +0x24 of the global request object DAT_104DF908. | high |
| `NetCellFont_EnsureGlobal` | 0x100F76B0 | 28 | yes | - | Creates the global pool object on first use. | medium |
| `NetCellFont_DestroyGlobal` | 0x100F76D0 | 44 | yes | - | Destroys the global pool object and clears the global pointer when the destroy finishes. | medium |
| `NetCellFont_UpdateGlobalRequests` | 0x100F7700 | 21 | yes | - | Runs Unit100D7420_UpdateRequests on the global request object, if any. | high |
| `NetCellFont_BeginGlobalRequests` | 0x100F7740 | 25 | yes | - | Ensures the global request object exists and starts its request sequence. | high |
| `NetCellFont_StoreQueriesInto104DF90C` | 0x100F78C0 | 152 | yes | - | Fills the record at 0x104DF90C with the values of several queries. | low |
| `NetCellFont_StoreQueries2Into104DF90C` | 0x100F7960 | 93 | yes | - | Refreshes part of the record at 0x104DF90C from two queries. | low |
| `NetCellFont_InitEntryAt104DF90C` | 0x100F7A00 | 26 | yes | - | Initialises the pool record of the object at 0x104DF90C. | low |
| `NetCellFont_GetFieldCOf104DF90C` | 0x100F7A80 | 9 | yes | - | Returns a field of the object at 0x104DF90C. | low |
| `NetCellFont_GetActiveBlock3AE98` | 0x100F94D0 | 54 | yes | - | Returns a session block when it is active. | low |
| `NetCellFont_GetDword40C3C` | 0x100F9600 | 27 | yes | - | Returns the dword at +0x40C3C of the given object (or of the one at 0x104DFD98). | low |
| `NetCellFont_IsReadyBy3C350` | 0x100F9680 | 71 | yes | - | Returns a readiness flag of the object (at 0x104DFD98 by default), which depends on its state value at +0x3C350. | low |
| `NetCellFont_TickSecondCounters` | 0x100F9CC0 | 134 | yes | - | Rolls the per-second counters over when a new second starts. | medium |
| `NetCellFont_UpdateSession` | 0x100F9D50 | 27 | yes | - | Runs the per-frame session update. | low |
| `NetCellFont_GetFlags` | 0x100FC160 | 17 | yes | - | Returns the session's flags word. | low |
| `NetCellFont_ApplyStatusText` | 0x100FC180 | 290 | yes | - | Adds flags to the session and shows the status text for the combined flags. | medium |
| `NetCellFont_GetWord40DAA` | 0x100FC300 | 21 | yes | - | Returns the word at +0x40DAA of the object at 0x104DFD98. | low |
| `NetCellFont_SetWord40DAA` | 0x100FC320 | 22 | yes | - | Stores a word at offset 0x40DAA of the session state. | low |
| `NetCellFont_GetBlock3C3A4OrDefault` | 0x100FC4E0 | 36 | yes | - | Returns a session block, or a static default without a session. | low |
| `NetCellFont_GetIdPair` | 0x100FC510 | 43 | yes | - | Returns the session's id word and value as a static pair. | low |
| `NetCellFont_FindTimerKind10` | 0x100FCD70 | 79 | yes | - | Returns the value of the first record of kind 0x10. | low |
| `NetCellFont_IsId50To99Or88Or89` | 0x100FD3A0 | 36 | yes | - | Tells whether an id is in the range 80-99 or is 136 or 137. | low |
| `NetCellFont_TestBit198CC` | 0x100FD6E0 | 33 | yes | - | Returns bit n of the dword at +0x198CC of the object at 0x104DFD98. | low |
| `NetCellFont_GetTableByteForTens` | 0x10101BC0 | 34 | yes | - | Looks up a table byte by the argument's tens, rounded up and capped. | low |
| `NetCellFont_CeilDiv10Max10` | 0x10101BF0 | 39 | yes | - | Returns the byte argument divided by ten, rounded up and capped at ten. | medium |
| `Game_ClearFlagsBits` | 0x10103740 | 57 | yes | - | Clears three flag bits in the game state. | low |
| `Game_SetSlot44C` | 0x101037F0 | 37 | yes | - | Stores a value in one of eight slots of the game state. | low |
| `NetCellFont_ReturnZero` | 0x101038C0 | 3 | yes | - | Returns 0. | low |
| `Game_GetField4` | 0x101038D0 | 14 | yes | - | Returns the value stored at offset 4 of the game state. | low |
| `NetCellFont_GetWord8Of104E0AF4` | 0x101038E0 | 18 | yes | - | Returns a word of the object at 0x104E0AF4. | low |
| `NetCellFont_UpdateNoticesIfReady` | 0x10103920 | 75 | yes | - | Runs the notice processing when the session is ready. | low |
| `ntGameTimeGet` | 0x101039E0 | 12 | yes | - | - | - |
| `Time_ModDiv12FC00Div19500` | 0x10103A90 | 26 | yes | - | Returns a time value modulo 0x12FC00, divided by 0x19500. | low |
| `Time_ModDiv19500Scaled` | 0x10103AB0 | 34 | yes | - | Returns a time value modulo 0x19500 scaled to a smaller unit. | low |
| `Time_ModDiv6C00Scaled` | 0x10103AE0 | 34 | yes | - | Returns a time value modulo 0x6C00 scaled to a smaller unit. | low |
| `Time_ModDivD80Div90` | 0x10103B10 | 26 | yes | - | Returns a time value modulo 0xD80, divided by 0x90. | low |
| `Time_ModMul3CDiv90` | 0x10103B30 | 35 | yes | - | Returns a time value modulo 0x90 scaled to 0 to 0x3C. | low |
| `NetCellFont_SetZero` | 0x10103F50 | 10 | yes | - | Clears the word at the given address. | low |
| `fn_101061D0` | 0x101061D0 | 2585 | yes | - | - | - |
| `NetCellFont_LookupMaskedTable` | 0x101072D0 | 35 | yes | - | Returns the text of a masked index's entry in a 12-byte-entry table. | low |
| `NetCellFont_LookupTable10364CB0` | 0x10107320 | 21 | yes | - | Returns the entry of the table at 0x10364CB0 for an index (masked to 4 bits). | low |
| `NetCellFont_AppendMax20` | 0x10107610 | 38 | yes | - | Appends a dword to a list of at most twenty entries. | low |
| `NetCellFont_DumpHexBytes` | 0x10108150 | 422 | yes | - | Formats the stored byte blocks as hex and text, then releases the table. | low |
| `NetCellFont_GetPoolBlockPayload` | 0x101083C0 | 31 | yes | - | Returns a pool's block size less its 20-byte header. | low |
| `NetCellFont_AllocEntry` | 0x10108590 | 46 | yes | - | Allocates an entry from the table at the given index. | low |
| `NetCellFont_AllocFromPool` | 0x101085C0 | 30 | yes | - | Allocates from one of the pools at 0x104E0B00. | low |
| `NetCellFont_AllocFromPool0` | 0x101085E0 | 20 | yes | - | Allocates from the first pool. | low |
| `NetCellFont_InitBlock` | 0x101086C0 | 62 | yes | - | Initialises a heap block node as an empty free-list head. | medium |
| `NetCellFont_InsertBlock` | 0x10108700 | 114 | yes | - | Inserts a free block into the heap's size-ordered free list. | medium |
| `NetCellFont_InsertAndCoalesce` | 0x10108780 | 230 | yes | - | Inserts a freed block into the heap, merging it with adjacent free blocks. | medium |
| `NetCellFont_GetNextBlock` | 0x10108870 | 34 | yes | - | Returns the block that follows a heap block, or 0 at the end of the heap. | medium |
| `NetCellFont_GetPrevBlock` | 0x101088A0 | 29 | yes | - | Returns the block that precedes a heap block, or 0 at the start of the heap. | medium |
| `NetCellFont_RebalanceList` | 0x101088C0 | 202 | yes | - | Re-sorts the heap's free list after a block changes size. | medium |
| `NetCellFont_TakeFreeBlock` | 0x10108990 | 191 | yes | - | Takes a free block of a size from the heap, splitting off the remainder. | medium |
| `NetCellFont_Free` | 0x10108A50 | 167 | yes | - | Returns a block to the heap, merging it with adjacent free blocks. | medium |
| `NetCellFont_UnlinkBlock` | 0x10108D80 | 250 | yes | - | Removes a block from the heap's linked list. | medium |
| `NetCellFont_LinkAfter` | 0x10108E80 | 187 | yes | - | Links a heap block after another block in the list. | medium |
| `NetCellFont_LinkBefore` | 0x10108F40 | 181 | yes | - | Links a heap block before another block in the list. | medium |
| `NetCellFont_AllocCopy` | 0x10109000 | 150 | yes | - | Allocates a buffer from the pool and copies the given bytes into it. | medium |
| `NetCellFont_Release` | 0x101090A0 | 52 | yes | - | Releases a reference-counted buffer and frees it when its count reaches zero. | medium |
| `NetCellFont_RefStringClear` | 0x10109100 | 8 | yes | - | Empties a shared-string handle. | low |
| `NetCellFont_RefStringCtor` | 0x10109140 | 30 | yes | - | Constructs a shared-string object from a C string. | low |
| `NetCellFont_RefStringReserve` | 0x101091D0 | 135 | yes | - | Makes room for appending to a shared string and returns where to write. | low |
| `NetCellFont_RefStringAssign` | 0x101092C0 | 122 | yes | - | Assigns a C string to a shared-string object. | low |
| `NetCellFont_RefStringRelease` | 0x101094D0 | 101 | yes | - | Releases a shared string's reference, freeing it on the last one. | low |
| `NetCellFont_Copy12` | 0x1010E040 | 37 | yes | - | Copies a 12-byte value. | low |
| `NetCellFont_RecorderAddHandler` | 0x1010FA30 | 404 | yes | - | Adds a handler entry under a 12-byte key to the recorder's list. | low |
| `NetCellFont_RecorderRecordCode` | 0x1010FBD0 | 124 | yes | - | Records a code and value in an 8-entry ring, merging repeats. | low |
| `NetCellFont_ForwardToGlobal1708` | 0x1010FEB0 | 26 | yes | - | Forwards its two arguments to the object at DAT_104E1708 when it exists. | low |
| `NetCellFont_Copy12B` | 0x1010FEE0 | 37 | yes | - | Copies a 12-byte value. | low |
| `NetCellFont_ListInsertBefore` | 0x10110040 | 35 | yes | - | Inserts a list node before another. | low |
| `NetCellFont_ClearTable1710` | 0x101133A0 | 17 | yes | - | Clears the table at DAT_104E1710. | low |
| `NetCellFont_StartRequestSlot24WithCallback` | 0x10113CA0 | 132 | yes | - | Starts the global request on slot 0x24 with a completion routine that will call the given callback with its context; once at a time. | medium |
| `NetCellFont_ErrorLogDtor` | 0x10114070 | 106 | yes | - | Destroys the error log and releases its queued entries. | low |
| `NetCellFont_ErrorLogPop` | 0x10114120 | 290 | yes | - | Takes the oldest entry from the error log's ring under its mutex. | low |
| `NetCellFont_PushRingEntryLocked` | 0x10114250 | 200 | yes | - | Under the object's mutex, stores a record in its 16-slot ring buffer, overwriting the oldest when full. | medium |
| `NetCellFont_ErrorLogFlush` | 0x10114320 | 472 | yes | - | Writes up to four queued error records to the err file. | low |
| `NetCellFont_SumWords16` | 0x10114620 | 62 | yes | - | Computes a 16-bit folded sum of a buffer's words. | medium |
| `NetCellFont_ReportError` | 0x10114F10 | 264 | yes | - | Reports an error code with its data to the recorder and the error log. | low |
| `FDtGmNoticeProc` | 0x10115020 | 433 | yes | - | - | - |
| `NetCellFont_ReturnOneA` | 0x101152D0 | 6 | yes | - | Returns 1. | medium |
| `NetCellFont_ReturnOneB` | 0x101152E0 | 6 | yes | - | Returns 1. | medium |
| `NetCellFont_ArmCounter10` | 0x10115870 | 37 | yes | - | Arms the counter at +0x4F1A8 to 10 and marks the object at +0x3F12C. | low |
| `NetCellFont_SetSessionData` | 0x10115930 | 54 | yes | - | Replaces the session data and waits in state 0xD. | low |
| `NetCellFont_GetSessionData` | 0x10115970 | 54 | yes | - | Copies out the session data and waits in state 0xE. | low |
| `NetCellFont_IsStateActive` | 0x101163A0 | 26 | yes | - | Reports whether the connection state at +0x2F0F8 is active (not 0 or 6). | low |
| `NetCellFont_GetField13C` | 0x101164B0 | 28 | yes | - | Reads the session data field +0x13C. | low |
| `NetCellFont_NextSequence` | 0x10116D30 | 79 | yes | - | Returns the next sequence number. | low |
| `NetCellFont_SetPair` | 0x101170D0 | 18 | yes | - | Stores two values. | low |
| `NetCellFont_MenuCtor` | 0x101172C0 | 409 | yes | - | Constructs a menu object with its default fields. | low |
| `NetCellFont_DeleteAllEntries` | 0x10117460 | 166 | yes | - | Removes and deletes all entries of a menu. | low |
| `Menu_DrawWindowItems` | 0x101177D0 | 1807 | yes | 2 | Draws one menu window: its items (the focused one highlighted), its cursor and its progress bar, inside its viewport when it has one. | medium |
| `NetCellFont_MenuReleaseItemCount` | 0x10117EE0 | 34 | yes | - | Gives back the item's count at +0x6F to the target manager's counter +0x6A and clears its open flags. | high |
| `NetCellFont_InvokeChild34` | 0x10117F30 | 13 | yes | - | Calls slot 13 of the menu's child object. | low |
| `NetCellFont_Rebuild` | 0x10117F40 | 426 | yes | - | Rebuilds a menu's layouts from its source entries. | medium |
| `NetCellFont_ClearEntries` | 0x101180F0 | 120 | yes | - | Frees the entries of a layout list. | low |
| `NetCellFont_AttachSelection` | 0x10118170 | 82 | yes | - | Attaches the menu's kind-2 entries to the selected entry. | low |
| `NetCellFont_FindFreeEntry` | 0x10118220 | 50 | yes | - | Returns the first unused entry of a layout list. | low |
| `NetCellFont_MenuMoveSelection` | 0x10118260 | 639 | yes | - | Moves a menu's selection (sub_101181D0, Unit100D7420_SelectEntry) and calls the SetMusicTrackVolume_A/B/C functions; details not established. | low |
| `NetCellFont_NoOpB` | 0x10118520 | 1 | yes | - | Does nothing. | medium |
| `NetCellFont_PlaceCursorObject` | 0x10118530 | 133 | yes | - | Creates the window's 0x2C-byte helper object once and places it by the window's position and an entry. | low |
| `NetCellFont_GetFocusedValueA` | 0x101185E0 | 81 | yes | - | Returns a value of the focused menu's first entry. | low |
| `NetCellFont_GetFocusedValueB` | 0x10118640 | 81 | yes | - | Returns another value of the focused menu's first entry. | low |
| `sub_101186A0` | 0x101186A0 | 244 | no | - | Updates the help and title windows for the focused menu's current entry. | medium |
| `NetCellFont_MenuStartFade` | 0x101187F0 | 54 | yes | - | Starts the menu's fade (state 0xE). | low |
| `NetCellFont_SelectFirstVisible` | 0x10118870 | 75 | yes | - | Selects the menu's starting entry. | low |
| `NetCellFont_SetStateByIndex` | 0x10118B60 | 83 | yes | - | Sets the state of the layout entry with a given index. | medium |
| `NetCellFont_FindEntryValueById` | 0x10118BC0 | 76 | yes | - | Returns the value of the window's entry with a given id, or 0. | low |
| `NetCellFont_HitTest` | 0x10118C10 | 54 | yes | - | Tests whether a point lies inside the layout's rectangle. | medium |
| `NetCellFont_PickEntry` | 0x10118CB0 | 246 | yes | - | Returns the layout entry under a point. | medium |
| `NetCellFont_SelectEntryMoveCursor` | 0x10118DB0 | 223 | yes | - | Selects a menu entry and moves the cursor onto it. | low |
| `NetCellFont_SelectEntry` | 0x10118E90 | 128 | yes | - | Selects a menu entry. | low |
| `NetCellFont_SetChildOwner` | 0x10118F20 | 9 | yes | - | Makes the menu the owner of its child object. | low |
| `NetCellFont_CallMember0CSlot2` | 0x10118F30 | 13 | yes | - | Calls vtable slot 2 of the member object at +0xC, if any. | high |
| `NetCellFont_FreeChild` | 0x10118F40 | 34 | yes | - | Releases the child layout of an object. | low |
| `NetCellFont_GetRect` | 0x10118F70 | 174 | yes | - | Returns a layout entry's on-screen rectangle. | medium |
| `NetCellFont_SetState10ForIndex58` | 0x101190F0 | 17 | yes | - | Sets state 0x10 on the layout entry whose index is at +0x58. | low |
| `NetCellFont_SetActive` | 0x10119200 | 157 | yes | - | Activates or deactivates a menu, updating the target manager flag and the help text. | low |
| `NetCellFont_ClearEntryFlags` | 0x101192B0 | 33 | yes | - | Clears an entry's flag, and a second flag unless told to keep it. | low |
| `NetCellFont_MarkDirty` | 0x101192E0 | 25 | yes | - | Marks a layout entry as needing an update. | low |
| `NetCellFont_InitScaled` | 0x10119300 | 91 | yes | - | Initialises a layout object with unit scales. | low |
| `NetCellFont_FreeEntryData` | 0x10119360 | 34 | yes | - | Frees an entry's data block. | low |
| `NetCellFont_ClearField34` | 0x10119390 | 8 | yes | - | Clears the field at +0x34. | low |
| `NetCellFont_StartFade` | 0x101193A0 | 11 | yes | - | Starts a layout's fade countdown from its full length. | low |
| `NetCellFont_StopFade` | 0x101193B0 | 7 | yes | - | Clears a layout's fade countdown. | low |
| `NetCellFont_SetSource` | 0x101193D0 | 30 | yes | - | Sets the source record of a layout and copies its size fields. | low |
| `NetCellFont_ComputeRect` | 0x101193F0 | 350 | yes | - | Computes a layout's on-screen rectangle from its source record. | medium |
| `NetCellFont_UpdateLayout` | 0x10119550 | 791 | yes | - | Per-frame update of a menu layout's size, fade/alpha and shape. | low |
| `NetCellFont_MapKind119870` | 0x10119870 | 55 | yes | - | Maps a kind value (0,1,3,5,7,9) to an index 0..5, 6 for anything else. | high |
| `NetCellFont_LayoutCtor` | 0x101198D0 | 150 | yes | - | Constructs a menu layout entry with its defaults. | low |
| `NetCellFont_SetState` | 0x10119970 | 158 | yes | - | Sets a layout's state and its timer by a state code. | medium |
| `NetCellFont_SetNames` | 0x10119A50 | 128 | yes | - | Sets a layout's source and its two text strings. | medium |
| `NetCellFont_ComputeOffsets` | 0x10119AD0 | 235 | yes | - | Computes a layout's offsets and extents from its source. | low |
| `sub_10119BC0` | 0x10119BC0 | 63 | no | - | Tests whether the point the argument points to lies inside the rectangle (x, y, width, height words at +0x2A..+0x30). | medium |
| `NetCellFont_UpdateState` | 0x10119C00 | 370 | yes | - | Advances a layout's timer and refreshes its shape from its source. | low |
| `NetCellFont_InitDefaults` | 0x10119DA0 | 83 | yes | - | Initialises a layout object's fields to their defaults. | medium |
| `NetCellFont_SetShape` | 0x10119E20 | 15 | yes | - | Sets a layout's shape reference and resolves it. | low |
| `NetCellFont_AttachTo` | 0x10119E30 | 62 | yes | - | Positions a layout relative to a parent layout. | low |
| `NetCellFont_ResolveShape` | 0x10119E70 | 138 | yes | - | Resolves a layout's shape by its key. | low |
| `NetCellFont_StepFrameCycle` | 0x10119F20 | 88 | yes | - | Counts the object's countdown down by the frame scale and, when it runs out, moves to the next entry of its list, wrapping at the end. | low |
| `NetCellFont_DrawUnscaled` | 0x10119F80 | 43 | yes | 3 | Calls 0x10119FB0 with both scales at 1.0. | low |
| `NetCellFont_InvokeCallback7C` | 0x1011A3B0 | 25 | yes | - | Calls the callback at +0x7C with its id and context. | low |
| `NetCellFont_ApplyHelpAndTitle` | 0x1011A490 | 202 | yes | - | Shows the help text and title of the current menu item. | medium |
| `NetCellFont_SetRectAndUpdateNodes` | 0x1011A5A0 | 355 | yes | - | Moves a layout to a new rectangle and updates its child nodes by kind. | low |
| `NetCellFont_GetPos42` | 0x1011A710 | 20 | yes | - | Copies the window's position pair at +0x42 to the output. | low |
| `NetCellFont_SetViewport` | 0x1011AA40 | 120 | yes | 1 | Sets the render viewport to a layout's rectangle. | medium |
| `Gfx_ApplyViewport1B70` | 0x1011AAC0 | 17 | yes | 1 | - | - |
| `NetCellFont_GetCenter` | 0x1011ABF0 | 114 | yes | - | Returns the centre of the matching layout item. | medium |
| `NetCellFont_SetEntryValue4C` | 0x1011ADB0 | 47 | yes | - | Sets a value of one of the window's entries and updates the focused help text. | low |
| `NetCellFont_AddEntry` | 0x1011AE10 | 30 | yes | - | Fills the first free entry with a value and refreshes the list. | low |
| `NetCellFont_GetFieldByIndex` | 0x1011B220 | 102 | yes | - | Returns one of four byte fields of a layout entry by index. | low |
| `NetCellFont_GetEntryValueById` | 0x1011B2A0 | 52 | yes | - | Returns the value of the entry with a given id. | low |
| `NetCellFont_GetEntry` | 0x1011B2E0 | 36 | yes | - | Returns a layout table entry by one-based index. | low |
| `NetCellFont_GetField8` | 0x1011B310 | 4 | yes | - | Returns the field at +8. | low |
| `NetCellFont_GetFieldC` | 0x1011B320 | 4 | yes | - | Returns the field at +0xC. | low |
| `NetCellFont_GetOffsets` | 0x1011B330 | 43 | yes | - | Returns a layout's offsets. | low |
| `NetCellFont_SetShorts1A1C` | 0x1011B360 | 21 | yes | - | Stores two 16-bit values at +0x1A and +0x1C. | high |
| `NetCellFont_InitColors` | 0x1011BA90 | 67 | yes | - | Sets a layout's default colours and scales. | low |
| `Font_BindGlyphTexture` | 0x1011BAE0 | 180 | yes | 0 | - | - |
| `Font_DrawGlyphQuadGrey` | 0x1011BBA0 | 33 | yes | 1 | Draws a glyph quad in the grey colour 0x80808080. | low |
| `Font_DrawGlyphQuad` | 0x1011BBD0 | 316 | yes | 0 | - | - |
| `Gfx_SetAdditiveBlend` | 0x1011BDC0 | 66 | yes | 0 | - | - |
| `Font_DrawChar` | 0x1011BF40 | 140 | yes | 1 | - | - |
| `Font_MeasureString` | 0x1011BFD0 | 162 | yes | - | Measures the width of a Shift-JIS string at a scale. | medium |
| `Gfx_SetCellBlendMode` | 0x1011C1F0 | 992 | yes | 0 | - | - |
| `Font_AllocHighResImage` | 0x1011C5D0 | 153 | yes | - | - | - |
| `Tex_LoadSurfaceFromDatFile` | 0x1011C670 | 165 | yes | - | - | - |
| `Font_LoadHighResTexture` | 0x1011C720 | 227 | yes | 2 | - | - |
| `Font_ReleaseHighResTexture` | 0x1011C810 | 51 | yes | - | - | - |
| `Font_IsHighResTextureLoaded` | 0x1011C850 | 29 | yes | - | - | - |
| `unknown_libname_88` | 0x1011C870 | 9 | yes | - | - | - |
| `Font_LoadWidthTable` | 0x1011C8B0 | 77 | yes | - | Loads the font width table from the shape manager. | low |
| `Font_IsSingleByte` | 0x1011C900 | 23 | yes | - | Tests whether the byte at a position starts a single-byte character. | low |
| `Sjis_ToJisIndex` | 0x1011C940 | 520 | yes | - | Converts a Shift-JIS code to a row and cell index. | low |
| `Font_DecodeNextChar` | 0x1011CE80 | 55 | yes | - | - | - |
| `Font_GetCharWidth` | 0x1011CEC0 | 171 | yes | - | Returns the advance width of one character. | medium |
| `Font_MeasureText` | 0x1011CF70 | 134 | yes | - | Returns the total width of a text string, up to a length limit. | medium |
| `Font_MeasureTextAll` | 0x1011D000 | 16 | yes | - | Measures the width of a whole text string. | medium |
| `Font_MeasureTextAll2` | 0x1011D010 | 5 | yes | - | Forwards to Font_MeasureTextAll. | low |
| `NetCellFont_IsNotControlChar` | 0x1011D290 | 187 | yes | - | Tests whether a typed character is not one of the listed control codes (backspace, tab and escape are not listed). | medium |
| `NetCellFont_MeasureTextWidth` | 0x1011D380 | 181 | yes | - | Returns the pixel width of a text (or of its first n bytes). | medium |
| `NetCellFont_MeasureTextWidthAll` | 0x1011D440 | 21 | yes | - | Returns the pixel width of a whole text. | medium |
| `Font_AddGlyphAdvance` | 0x1011D840 | 102 | yes | - | - | - |
| `Font_IsPrintableAscii` | 0x1011D8B0 | 20 | yes | - | Tests whether a character code is printable ASCII. | medium |
| `NetCellFont_MeasureTextWidthFwd` | 0x1011D970 | 13 | yes | - | Returns the pixel width of a whole text (a callback form). | low |
| `Font_GetCharWidthAt` | 0x1011D990 | 53 | yes | - | Returns the width of the (one- or two-byte) character at a position. | medium |
| `Sjis_IsLeadByte` | 0x1011DA30 | 67 | yes | - | Tests whether a byte is a Shift-JIS lead byte. | medium |
| `Sjis_GetCharByteLen` | 0x1011DA80 | 25 | yes | - | - | - |
| `Sjis_IsCodeInSet` | 0x1011DB40 | 92 | yes | - | Tests whether a 16-bit code is one of a fixed set of ranges and values. | low |
| `sub_1011DC00` | 0x1011DC00 | 180 | no | - | Maps an ASCII or Shift-JIS character to its upper-case form and passes it with arg1 to 0x1011DAE0. | low |
| `sub_1011DCC0` | 0x1011DCC0 | 174 | no | - | Maps an ASCII or Shift-JIS character to its lower-case form and passes it with arg1 to 0x1011DAE0. | low |
| `Sjis_CopyPrefix` | 0x1011DE80 | 86 | yes | - | Copies the longest prefix of a Shift-JIS string that fits in a byte count. | medium |
| `Cell_GetField20Ptr` | 0x1011E290 | 4 | yes | - | Returns the address of the object's field at offset +0x20. | low |
| `Cell_ResolveSubCells` | 0x1011E2A0 | 41 | yes | - | Runs the texture resolve on each entry of the sub-cell array. | low |
| `Cell_ResolveTextureUV` | 0x1011E6D0 | 304 | yes | - | Looks up the cell's texture by name and computes its UV scale and offsets. | medium |
| `Cell_DrawAt` | 0x1011E800 | 370 | yes | 0 | - | - |
| `Cell_DrawTexturedQuad` | 0x1011E980 | 993 | yes | 0 | Binds the cell's texture and draws a four-vertex quad with modulated colour. | medium |
| `Cell_DrawTransformed` | 0x1011EDE0 | 370 | yes | 0 | - | - |
| `Cell_DrawStretchedWrapped` | 0x1011EF60 | 873 | yes | 0 | - | - |
| `Cell_DrawWithDefaultBlend` | 0x1011F2D0 | 34 | yes | 1 | - | - |
| `Cell_DrawQuadBlended` | 0x1011F300 | 1914 | yes | 0 | - | - |
| `Cell_GetFrameBounds` | 0x1011FA80 | 119 | yes | - | Returns the frame's four vertex pairs and its width and height. | low |
| `NetCellFont_GetNthEntryBytePair` | 0x1011FB00 | 96 | yes | - | Returns a pair of bytes (+0x1D+i, +0x29+i) of the n-th entry of the list at +4. | medium |
| `Cell_DrawFirstStretched` | 0x10120000 | 99 | yes | 1 | Draws the first sub-object with the stretched-wrap draw when it exists. | low |
| `Cell_ResolveTextureList` | 0x10120070 | 54 | yes | - | Resolves the texture of each item in the cell's list. | medium |
| `Color_ModulateArgb128` | 0x101200B0 | 170 | yes | - | - | - |
| `ShapeMng_FindShape` | 0x10120450 | 92 | yes | - | - | - |
| `Cell_FindEntryByName` | 0x101204B0 | 92 | yes | - | Finds the entry whose 16-byte name matches the argument and returns its result. | low |
| `ShapeMng_GetFontGlyph` | 0x10120510 | 120 | yes | - | - | - |
| `ShapeMng_LoadFontTextures` | 0x10120660 | 208 | yes | - | - | - |
| `Cell_ResolveAllSubCells` | 0x10120950 | 47 | yes | - | Runs the sub-cell resolve over each item of the cell's list. | low |
| `Cell_TestAny38Or0B8` | 0x10120B80 | 44 | yes | - | Tests a flag table at DAT_104E1C40 for ids 0x38 or 0xB8. | low |
| `Cell_TestAny1DOr9D` | 0x10120BB0 | 44 | yes | - | Tests a flag table at DAT_104E1C40 for ids 0x1D or 0x9D. | low |
| `Cell_TestAny2AOr36` | 0x10120BE0 | 41 | yes | - | Tests a flag table at DAT_104E1C40 for ids 0x2A or 0x36. | low |
| `Cell_GetByte253Scaled` | 0x10120C40 | 36 | yes | - | Returns a byte at +0x253 of a global object, offset and scaled to a float. | low |
| `NetCellFont_QueryState1D44AL` | 0x10120F30 | 169 | yes | - | Queries the state words at +0x238/+0x228 of dword_104E1D44 by selector, returning a byte. | medium |
| `NetCellFont_QueryState1D44Mask100` | 0x101210F0 | 234 | yes | - | Queries the state words at +0x238/+0x228 of the object dword_104E1D44 by selector; selector 2 tests bit 0x100. | medium |
| `NetCellFont_QueryState1D44Mask1000` | 0x10121420 | 234 | yes | - | Queries the state words at +0x238/+0x228 of the object dword_104E1D44 by selector; selector 2 tests bit 0x1000. | medium |
| `NetCellFont_QueryState1D44Mask4000` | 0x10121640 | 234 | yes | - | Queries the state words at +0x238/+0x228 of the object dword_104E1D44 by selector; selector 2 tests bit 0x4000. | medium |
| `NetCellFont_QueryState1D44Clear22C` | 0x10121DB0 | 209 | yes | - | Queries the state words of dword_104E1D44 by selector; selector 2 also clears the word at +0x22C. | medium |
| `NetCellFont_Call10122E30With1` | 0x10122E20 | 9 | yes | - | sub_10122E30(1). | high |
| `NetCellFont_GetCursorValueUnlessBlocked` | 0x101232E0 | 105 | yes | - | Returns a value from the cursor object (sub_101260D0) unless menu, scene or cell state block it; the value's meaning is not established. | low |
| `Cell_TestFlagAny2AOr36` | 0x10123350 | 41 | yes | - | Tests the flag kind for ids 0x2A or 0x36 with the given kind. | low |
| `Cell_TestFlagKind` | 0x10123380 | 157 | yes | - | Dispatches to one of six bit tests on the flag table by the kind argument. | low |
| `Cell_GetByte1036E0F0` | 0x10123640 | 15 | yes | - | Returns a byte from the table at DAT_1036E0F0. | low |
| `Cell_SetByte1036E0F0` | 0x10123650 | 19 | yes | - | Stores a byte in the table at DAT_1036E0F0. | low |
| `Cell_GetWord1036D6B0` | 0x10123670 | 16 | yes | - | Returns the byte entry of the table at DAT_1036D6B0 at index param. | low |
| `Cell_SetWord1036D6B0` | 0x10123680 | 42 | yes | - | Sets a word entry in the table at DAT_1036D6B0. | low |
| `NetCellFont_SetTable1036D6B0Word` | 0x101236B0 | 42 | yes | - | Sets the word of entry arg1 in the 6-byte table at 0x1036D6B0 to 0x80xx with the given byte, or to 0. | low |
| `Cell_SetGlobal1036E3A0` | 0x101236E0 | 10 | yes | - | Stores a value in the global at DAT_1036E3A0. | low |
| `NetCellFont_Query123700UnlessBlocked` | 0x10123700 | 613 | yes | - | Builds a 64-bit state value from menu, cell and cursor tests unless the mode or scene state blocks it; its meaning is not established. | low |
| `NetCellFont_TestCommand36CF60` | 0x10123A70 | 799 | yes | - | Tests whether command code param_2 (mask from the table at 0x1036CF60) is active in mode param_3 through the cell and cursor state. | low |
| `Cursor_TestAny1DOr9D` | 0x10123DC0 | 39 | yes | - | Tests the flag table at DAT_104E1C40 for ids 0x1D or 0x9D, bit 2. | medium |
| `Cursor_TestAnyB8Or38` | 0x10123DF0 | 39 | yes | - | Tests the flag table at DAT_104E1C40 for ids 0xB8 or 0x38, bit 2. | medium |
| `Cell_TestFlagAny2AOr36Kind4` | 0x10123E20 | 36 | yes | - | Tests the flag kind for ids 0x2A or 0x36 with kind 4. | medium |
| `Cell_TestGlobal1036E3A0Mask` | 0x10123E50 | 15 | yes | - | Tests a mask against the global at DAT_1036E3A0. | low |
| `Cell_SetByte104E1C3E` | 0x10123E60 | 10 | yes | - | Stores the low byte of its second argument in DAT_104E1C3E and returns that byte in AL. | medium |
| `Cell_Nop` | 0x10123E80 | 1 | yes | - | Does nothing. | low |
| `Cell_ClearFlag104E1C3C` | 0x10123E90 | 8 | yes | - | Clears the flag at DAT_104E1C3C. | low |
| `Cell_SetFlag104E1C3C` | 0x10123EA0 | 8 | yes | - | Sets the flag at DAT_104E1C3C. | low |
| `Cell_GetByte1036CF5C` | 0x10123EE0 | 6 | yes | - | Returns the byte at DAT_1036CF5C. | medium |
| `Cell_SetFlagBit2` | 0x10123F40 | 17 | yes | - | Sets bit 2 of the byte selected by the argument. | low |
| `Cell_SetFlagBit8` | 0x10123F60 | 17 | yes | - | Sets bit 8 of the byte selected by the argument. | low |
| `NetCellFont_SetByteFlag1` | 0x10123F80 | 17 | yes | - | Sets bit 0 of the byte the argument indexes. | low |
| `Cell_SetFlagBit4Dirty` | 0x10123FC0 | 28 | yes | - | Sets bit 4 of a byte and marks the object dirty. | low |
| `Cell_SetFlagBit10` | 0x10123FE0 | 17 | yes | - | Sets bit 0x10 of the byte selected by the argument. | low |
| `Cell_ClearByte` | 0x10124000 | 16 | yes | - | Clears the byte selected by the argument. | low |
| `Cell_ClearFlag01And08` | 0x10124010 | 17 | yes | - | Clears bits 0x01 and 0x08 of the byte selected by the argument. | low |
| `sub_10124050` | 0x10124050 | 25 | no | - | Clears the flag bytes for all 256 indices. | low |
| `Cell_TestFlagBit1` | 0x10124070 | 19 | yes | - | Returns bit 0x02 of the byte selected by the argument. | low |
| `Cell_TakeFlagBit2` | 0x10124090 | 31 | yes | - | Tests and clears bit 0x02 of the byte selected by the argument. | low |
| `Cell_TestFlagBit3` | 0x101240B0 | 20 | yes | - | Returns bit 0x08 of the byte selected by the argument. | low |
| `Cell_TestFlagBit0` | 0x101240D0 | 17 | yes | - | Returns bit 0x01 of the byte selected by the argument. | low |
| `Cursor_TakeEventFlag` | 0x101240F0 | 31 | yes | - | Returns whether the cursor's flag byte had its bit set, and clears that bit. | medium |
| `Cursor_GetFlagBit4` | 0x10124110 | 20 | yes | - | Returns bit 4 of the cursor flag byte selected by the argument. | low |
| `Cursor_GetFlagBit2` | 0x10124130 | 20 | yes | - | Returns bit 2 of the cursor flag byte selected by the argument. | low |
| `NetCellFont_HalfKanaToFullWidth` | 0x10124360 | 48 | yes | - | Converts a Shift-JIS half-width katakana byte to its two-byte full-width form. | medium |
| `NetCellFont_IsHalfWidthKana` | 0x10124390 | 18 | yes | - | Tests whether a byte is a Shift-JIS half-width katakana. | medium |
| `Cursor_Init` | 0x10124440 | 327 | yes | - | - | - |
| `Cursor_GetHwCursorSlot` | 0x101245C0 | 8 | yes | - | - | - |
| `Cursor_HandleMouseMove` | 0x101245D0 | 103 | yes | - | Passes a mouse move to the cursor's mouse handler, first updating the menu when the cursor is active. | medium |
| `CTkMouse_OnMouseMove` | 0x10124640 | 183 | yes | - | - | - |
| `Cursor_SetPosition` | 0x10124700 | 406 | yes | - | - | - |
| `Cursor_UpdateTimer` | 0x101248A0 | 136 | yes | - | Counts the cursor timer down by the frame scale and, when it expires, sets the pending flags. | medium |
| `Cursor_EnterMode1` | 0x10124930 | 164 | yes | - | Enters cursor mode 1 once, recording the current position. | low |
| `Cursor_ToggleFlag1` | 0x101249E0 | 22 | yes | - | Toggles the cursor's first mode flag, once per frame. | low |
| `Cursor_EnterMode2` | 0x10124A00 | 162 | yes | - | Enters cursor mode 2 once, recording the current position. | low |
| `Cursor_ToggleFlag2` | 0x10124AB0 | 22 | yes | - | Toggles the cursor's second mode flag, once per frame. | low |
| `Cursor_EnterMode4` | 0x10124AD0 | 126 | yes | - | Enters cursor mode 4 once, recording the current position. | low |
| `Cursor_ToggleFlag4` | 0x10124B50 | 22 | yes | - | Toggles the cursor's third mode flag, once per frame. | low |
| `Cursor_ResetPositionToMenu` | 0x10124B70 | 72 | yes | - | Moves the cursor to the menu's position when the menu is active. | low |
| `NetCellFont_CursorUpdateEdgeAxes` | 0x10124BC0 | 743 | yes | - | Works out from the cursor's position whether it is at a screen edge on each axis (-1, 0, 1) and stores that, with settings-controlled inversion. | medium |
| `NetCellFont_UpdateHoldState4` | 0x10125040 | 296 | yes | - | Enters state 4 after an input is held long enough near the same point. | low |
| `NetCellFont_UpdateHoldState5` | 0x10125170 | 324 | yes | - | Enters state 5 after another input is held long enough near the same point. | low |
| `Cursor_SetModeFromMenuActive` | 0x101252C0 | 29 | yes | - | Sets the cursor mode from whether the menu is active. | low |
| `Cursor_SetVisible` | 0x101252F0 | 110 | yes | - | - | - |
| `Cursor_UpdateVisibilityForMode` | 0x10125F70 | 81 | yes | - | Shows or hides the cursor according to its current mode. | medium |
| `Cursor_GetField98` | 0x101260E0 | 7 | yes | - | Returns the float stored at offset 0x98 of the cursor. | low |
| `Cursor_GetField94` | 0x101260F0 | 7 | yes | - | Returns the float stored at offset 0x94 of the cursor. | low |
| `Cursor_GetNormalizedDeltaY` | 0x10126100 | 135 | yes | - | Returns the cursor's vertical offset from its anchor, normalised to the screen height and clamped. | low |
| `Cursor_HasTargetHover` | 0x10126270 | 17 | yes | - | Reports whether the target manager has a hovered target. | low |
| `unknown_libname_89` | 0x10126290 | 10 | yes | - | - | - |
| `Cursor_StoreScreenCenter` | 0x101262A0 | 50 | yes | - | - | - |
| `NetCellFont_IsCursorMode2NoEvent` | 0x101262E0 | 26 | yes | - | Returns whether the cursor is in its mode 2 while no event is running. | low |
| `NetCellFont_Init` | 0x10126300 | 23 | yes | - | Initialises an empty linked list head. | medium |
| `NetCellFont_ClearWords` | 0x10126320 | 14 | yes | - | Clears the first two words of an object. | medium |
| `NetCellFont_NoOp` | 0x10126330 | 1 | yes | - | Does nothing. | medium |
| `NetCellFont_Clear` | 0x10126350 | 25 | yes | - | Clears a seven-dword node. | low |
| `NetCellFont_FreeBothLists` | 0x10126370 | 55 | yes | - | Frees all nodes of the object's two linked lists. | medium |
| `NetCellFont_Alloc` | 0x101263B0 | 90 | yes | - | Takes a list node from the free pool, or allocates a new one. | medium |
| `NetCellFont_GetCount` | 0x10126460 | 17 | yes | - | Returns the number of entries in a list, or 0 for a null list. | medium |
| `NetCellFont_PushBack` | 0x10126480 | 51 | yes | - | Appends a value to the end of the list. | medium |
| `NetCellFont_PushFront` | 0x101264C0 | 55 | yes | - | Adds a value to the front of the list. | medium |
| `NetCellFont_GetHead` | 0x10126500 | 3 | yes | - | Returns the head node of the list. | medium |
| `NetCellFont_GetTail` | 0x10126510 | 4 | yes | - | Returns the tail node of the list. | medium |
| `NetCellFont_NextActiveValue` | 0x10126550 | 47 | yes | - | List iterator: returns the value of the next node not flagged at +0x14 and advances the cursor past it. | medium |
| `NetCellFont_Remove` | 0x10126580 | 68 | yes | - | Removes a node from the list and returns it to the pool. | medium |
| `NetCellFont_FreeListsAndReset` | 0x101265D0 | 79 | yes | - | Frees all nodes of the object's two linked lists and resets its list fields. | medium |
| `NetCellFont_InsertBefore` | 0x101266B0 | 76 | yes | - | Inserts a new value before the given node. | medium |
| `NetCellFont_InsertAfter` | 0x10126700 | 77 | yes | - | Inserts a new value after the given node. | medium |
| `NetCellFont_ChatListCtorA` | 0x10126750 | 19 | yes | - | Constructs a message list for an owner. | low |
| `NetCellFont_ChatListCtorB` | 0x10126770 | 19 | yes | - | Constructs a message list for an owner. | low |
| `NetCellFont_ChatListInit` | 0x10126790 | 46 | yes | - | Initialises a message list with its owner. | low |
| `NetCellFont_AddMessage` | 0x101268F0 | 128 | yes | - | Creates a message entry and appends it to the message list. | low |
| `NetCellFont_ClearAllAndNotifyOwner` | 0x10126A00 | 144 | yes | - | Removes and deletes all entries of the list, resets it and notifies its owner object. | low |
| `NetCellFont_MessageCtor` | 0x10126B60 | 84 | yes | - | Constructs a 0x844-byte message entry. | low |
| `NetCellFont_MessageSet` | 0x10126BC0 | 157 | yes | - | Fills a message entry with its header and text and hands the formatted text to the owner. | low |
| `sub_10126C60` | 0x10126C60 | 1289 | no | - | Splits a message at its 0x7F control code and sets the message window's mode (and wait) from the code. | medium |
| `NetCellFont_MsgWinDataCtor` | 0x10127190 | 22 | yes | - | Constructs a message-window data object. | low |
| `NetCellFont_MsgWinDataReset` | 0x101271C0 | 129 | yes | - | Resets a message-window data object and measures its marker character. | low |
| `NetCellFont_ResetEntryRing` | 0x10127250 | 35 | yes | - | Clears the ring of 100 entries and its indices. | medium |
| `NetCellFont_PushSlot` | 0x10127280 | 154 | yes | - | Advances the ring buffer and clears the new slot. | low |
| `NetCellFont_NewRingEntry` | 0x10127320 | 155 | yes | - | Takes the next 2 KB entry of a 100-entry ring, dropping the oldest when it is full, and returns it cleared. | medium |
| `NetCellFont_BuildRecord` | 0x101273C0 | 902 | yes | - | Builds an event record from a source entry. | low |
| `NetCellFont_FindByKeyByte` | 0x10127870 | 62 | yes | - | Finds a table entry by its key byte. | low |
| `NetCellFont_FindChar` | 0x101278B0 | 29 | yes | - | Returns a pointer to the first matching character in a string. | medium |
| `NetCellFont_FindSubstringIndex` | 0x101278D0 | 89 | yes | - | Searches a string for a pattern and returns the match result. | medium |
| `NetCellFont_CopyLimited` | 0x10127930 | 53 | yes | - | Copies at most a given number of characters and terminates the result. | medium |
| `NetCellFont_ToLowerInPlace` | 0x10127970 | 32 | yes | - | Converts an ASCII string to lower case in place. | high |
| `GetCallNum` | 0x10127990 | 277 | yes | - | - | - |
| `NetCellFont_IsNearNamedActor` | 0x10127AB0 | 332 | yes | - | Tests whether the target is within a short distance of a named actor. | low |
| `ChatLog_AddMessage` | 0x10127C00 | 657 | yes | - | - | - |
| `NetCellFont_ClearGlobalLists2150And2154` | 0x10127EA0 | 58 | yes | - | Clears the two lists at 0x104E2150 and 0x104E2154 and notifies their owners. | low |
| `NetCellFont_CtorResetAll` | 0x10127EE0 | 12 | yes | - | Constructs the object by resetting all its fields. | low |
| `NetCellFont_ResetAll` | 0x10127F00 | 21 | yes | - | Resets the object's fields to zero. | low |
| `NetCellFont_IsInRow30` | 0x10127F60 | 51 | yes | - | Returns whether a value is one of the 30 entries of a table row. | low |
| `NetCellFont_FormatHexRecord` | 0x10127FA0 | 180 | yes | - | Writes a record's fields as a comma-separated hex line. | medium |
| `NetCellFont_ParseHexRecord` | 0x10128060 | 393 | yes | - | Reads a record written as comma-separated hex numbers into its fields. | medium |
| `NetCellFont_AddByType` | 0x101281F0 | 503 | yes | - | Adds a value to the stat counters for an event type. | low |
| `NetCellFont_CountTextChars` | 0x10128680 | 104 | yes | - | Counts the characters of a message string, counting each 0x7F/0x1E/0x1F control sequence and each Shift-JIS character as one. | medium |
| `NetCellFont_CountTextCharsAndBytes` | 0x10128830 | 195 | yes | - | Counts the characters and bytes of a message string, treating control sequences and Shift-JIS characters as one character. | medium |
| `NetCellFont_BuildTextCharIndex` | 0x10128950 | 318 | yes | - | Builds a per-character index (offsets and escape bytes) and a per-byte class map of a message string. | medium |
| `NetCellFont_CopyTextFromIndex` | 0x10128AE0 | 349 | yes | - | Rebuilds a message string from a class map and the escape entries saved by fn_10128950. | medium |
| `NetCellFont_ClearFlag12FromValue` | 0x10129290 | 72 | yes | - | Clears a flag in the ring entries at or past a value. | low |
| `NetCellFont_RingStepBack` | 0x101292E0 | 80 | yes | - | Returns the current ring entry and steps the index backward. | medium |
| `NetCellFont_GetOptionByte` | 0x101293F0 | 107 | yes | - | Returns one of the object's option bytes by id. | low |
| `NetCellFont_SetOptionByte` | 0x10129490 | 272 | yes | - | Sets one of the object's option bytes by id. | low |
| `NetCellFont_IsKindEnabledInSettings` | 0x10129BB0 | 111 | yes | - | Checks a record kind against a bit mask taken from two settings. | low |
| `NetCellFont_NextRingIndex` | 0x10129C20 | 39 | yes | - | Returns the ring index after the given one (wrapping after 99). | medium |
| `NetCellFont_GetRingHead14` | 0x10129C60 | 5 | yes | - | Returns the ring's head index. | low |
| `NetCellFont_FindKindRecord` | 0x10129CD0 | 47 | yes | - | Finds the record for an id in the table at 0x1036E888. | high |
| `NetCellFont_MapCode` | 0x10129D00 | 51 | yes | - | Maps a code to its value in a fixed table. | low |
| `ChatLog_AddTableMessage7` | 0x10129D90 | 74 | yes | - | Adds message (7, table[index]) to the chat log with the table entry's code. | medium |
| `ChatLog_AddMessage9Code379` | 0x10129DE0 | 73 | yes | - | Adds game message (9, index) to the chat log with code 0x379. | medium |
| `ChatLog_AddMessage7Code37B` | 0x10129E30 | 73 | yes | - | Adds game message (7, index) to the chat log with code 0x37B. | medium |
| `ChatLog_AddTextCode379` | 0x10129E80 | 41 | yes | - | Adds a text to the chat log with code 0x379. | medium |
| `ChatLog_AddTextCode37B` | 0x10129EB0 | 41 | yes | - | Adds a text to the chat log with code 0x37B. | medium |
| `Font_DrawStringDefault` | 0x10129EE0 | 22 | yes | - | Draws a string with the default scale. | low |
| `Font_DrawStringFlags44` | 0x10129F40 | 49 | yes | 1 | Draws a string with a fixed flag value of 0x44. | low |
| `NetCellFont_MapCode1BTo54` | 0x10129F80 | 116 | yes | - | Maps codes 0x1B.. to codes 0x54.. | high |
| `NetCellFont_MapCode54ToIndex` | 0x1012A120 | 192 | yes | - | Maps codes 0x54.. to setting indices. | high |
| `NetCellFont_CallClearBuffers` | 0x1012A350 | 5 | yes | - | Clears the object's buffers. | low |
| `NetCellFont_InitTextLayout` | 0x1012A360 | 73 | yes | - | Initialises a text layout record with the width and character count of a fixed string in the given font. | medium |
| `NetCellFont_ClearBuffers` | 0x1012A3B0 | 72 | yes | - | Frees a text object's buffers and resets its fields. | medium |
| `NetCellFont_GetWord1A` | 0x1012A400 | 7 | yes | - | Returns the word at +0x1A. | low |
| `NetCellFont_GetByte9` | 0x1012A410 | 4 | yes | - | Returns the byte at +9. | low |
| `NetCellFont_SetString` | 0x1012A420 | 186 | yes | - | Stores a string in a text object and builds its index buffer. | low |
| `NetCellFont_GetField20` | 0x1012A4E0 | 4 | yes | - | Returns the field at +0x20. | low |
| `NetCellFont_Construct` | 0x1012AB20 | 69 | yes | - | Constructs a text object and sets its default fields. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `NetCellFont_AddOne` calls nothing directly
- `Game_HasInitCount` calls nothing directly
- `NetCellFont_GetEntryMod1066268C` calls `TextInputFiles_GetEntryMod`
- `Game_InitSceneState` calls `XI_NETWORK_100D9950 (left out)`, `Game_GetField4`, `NetCellFont_ReturnZero`, `NetCellFont_GetWord8Of104E0AF4`
- `GameMode_GetField98` calls nothing directly
- `GameMode_PollPendingState` calls nothing directly
- `GameMode_RequestState` calls `NetCellFont_StoreQueriesInto104DF90C`
- `NetCellFont_GetRecordWordFwd` calls `NetCellFont_GetRecordWord`
- `NetCellFont_GetRecordDwordFwd` calls `NetCellFont_GetRecordDword`
- `NetCellFont_LookupNameIfKind3` calls `Name_LookupByKey`
- `NetCellFont_GetWord40D7C` calls nothing directly
- `NetCellFont_GetField0xA4` calls nothing directly
- `GameMode_OpenTacticsUrl` calls `GameMode_PollPendingState`, `NetCellFont_LookupNameIfKind3`, `sub_10311FF1`, `setPolUrl`
- `Game_IsFlag10492DB4` calls nothing directly
- `NetCellFont_ReturnTrue100DBDE0` calls nothing directly
- `Time_GetMilliseconds` calls nothing directly
- `NetCellFont_GetTimeNow` calls `sub_10314EF1`
- `NetCellFont_InitTimer` calls `NetCellFont_ReturnTrue100DBDE0`, `NetCellFont_GetTimeNow`, `Time_GetMilliseconds`, `NetCellFont_Reset`
- `NetCellFont_Sync` calls `NetCellFont_AdvanceClock`, `NetCellFont_DiffWrapped`, `NetCellFont_Update`
- `NetCellFont_DiffWrapped` calls nothing directly
- `NetCellFont_AdvanceClock` calls `Time_GetMilliseconds`, `NetCellFont_DiffWrapped`
- `NetCellFont_GetTotalMilliseconds` calls nothing directly
- `NetCellFont_GetSeconds` calls nothing directly
- `NetCellFont_GetMilliseconds` calls nothing directly
- `NetCellFont_AdvanceAndGetMs` calls `NetCellFont_AdvanceClock`, `NetCellFont_GetTotalMilliseconds`
- `NetCellFont_AdvanceAndGetSeconds` calls `NetCellFont_AdvanceClock`, `NetCellFont_GetSeconds`
- `NetCellFont_Reset` calls `Time_GetMilliseconds`
- `NetCellFont_Update` calls `Time_GetMilliseconds`
- `NetCellFont_IsInitialized` calls nothing directly
- `Entry_FindByNormalizedName` calls `Name_Normalize`
- `Name_Normalize` calls `sub_10315140`
- `NetCellFont_FindEntryByName` calls `XI_PACKET_100E0AA0 (left out)`, `Entry_FindByNormalizedName`, `NetCellFont_NoOp100E0B10`
- `NetCellFont_NoOp100E0B10` calls nothing directly
- `NetCellFont_ApplyNoticeRecord` calls `sub_100DBE10`, `Entry_ResetFields`
- `Entry_ResetFields` calls nothing directly
- `NetCellFont_AllocEntry4` calls nothing directly
- `NetCellFont_AllocEntryFromTable` calls `NetCellFont_AllocEntry4`
- `NetCellFont_CountActive` calls nothing directly
- `NetCellFont_ClearMatching` calls nothing directly
- `NetCellFont_RegisterHandler1369C` calls `XI_LOBBY_100E1C30 (left out)`, `NetCellFont_ClearMatching`
- `NetCellFont_RegisterHandler1369CFlag1` calls `NetCellFont_RegisterHandler1369C`
- `NetCellFont_GetEntryMod1066268CFwd` calls `NetCellFont_GetEntryMod1066268C`
- `NetCellFont_GetBlock2CFD8` calls nothing directly
- `NetCellFont_SetGlobal104B1774` calls nothing directly
- `NetCellFont_GetBlock2CDE8IfReady` calls nothing directly
- `NetCellFont_SetWord130` calls `NetCellFont_BuildListA90`
- `NetCellFont_ClearBit0Slot` calls nothing directly
- `NetCellFont_SetFlagFCBit1` calls nothing directly
- `NetCellFont_ClearBit1Fc` calls nothing directly
- `NetCellFont_ScanEntriesAndInit` calls `NetCellFont_IsBeforeDeadline`, `NetCellFont_IsCountOrByte134Set`, `sub_100E7B20`, `NetCellFont_ClearBit0Slot`, `NetCellFont_AllocEntryFromTable`, `NetCellFont_SetZero`, `NetCellFont_AppendMax20`, `NetCellFont_InitEncrypt`
- `NetCellFont_InitEncrypt` calls `NetCellFont_RegisterHandler1369CFlag1`
- `NetCellFont_IsBeforeDeadline` calls `NetCellFont_GetSeconds`
- `NetCellFont_IsCountOrByte134Set` calls `NetCellFont_CountActive`
- `NetCellFont_ClearTimer140` calls `NetCellFont_ScanEntriesAndInit`
- `NetCellFont_ScanIfTimer140Set` calls `NetCellFont_IsTimer140Clear`, `NetCellFont_ScanEntriesAndInit`
- `NetCellFont_IsTimer140Clear` calls nothing directly
- `NetCellFont_GetWord132` calls nothing directly
- `NetCellFont_BuildListA90` calls `sub_100E7B20`
- `NetCellFont_GetEntryPtrA90` calls nothing directly
- `NetCellFont_ClearPending` calls nothing directly
- `sub_100E7B20` calls `sub_100F1770`, `sub_100F1780`, `_exit_0`
- `NetCellFont_SetByte9800AndGetEntry` calls `sub_10312050`
- `NetCellFont_SelectNext` calls `NetCellFont_GetTotalMilliseconds`, `XI_PACKET_100E9550 (left out)`
- `NetCellFont_GetSlotPtr` calls nothing directly
- `NetCellFont_CountFreeEntries` calls `NetCellFont_GetEntryCount`
- `NetCellFont_GetEntryCount` calls nothing directly
- `NetCellFont_FindOrRemove` calls nothing directly
- `NetCellFont_RemoveRecord` calls `NetCellFont_FindOrRemove`
- `NetCellFont_ResetCounter` calls nothing directly
- `NetCellFont_Advance` calls nothing directly
- `NetCellFont_StepRequest1FSequence` calls `NetCellFont_ResetCounter`, `NetCellFont_Advance`, `TargetMenu_GetMessageFwd`, `NetCellFont_CopyToGlobalBuffer`, `XI_NETWORK_10115610 (left out)`, `NetCellFont_GetSessionData`, `XI_DEBUGLINK_10115D50 (left out)`
- `NetCellFont_StepWait1030FF96` calls `TargetMenu_GetMessageFwd`, `NetCellFont_CopyToGlobalBuffer`, `sub_1030FF8B`, `sub_1030FF96`
- `NetCellFont_StepRequest21Sequence` calls `NetCellFont_ResetCounter`, `NetCellFont_Advance`, `TargetMenu_GetMessageFwd`, `NetCellFont_CopyToGlobalBuffer`, `NetCellFont_SetSessionData`, `XI_DEBUGLINK_10115D50 (left out)`, `XI_NETWORK_10115A00 (left out)`, `NetCellFont_GetSessionData`, `NetCellFont_GetSessionField13C`, `XI_DEBUGLINK_10115820 (left out)`
- `NetCellFont_StepRequest22Sequence` calls `NetCellFont_ResetCounter`, `NetCellFont_Advance`, `TargetMenu_GetMessageFwd`, `NetCellFont_CopyToGlobalBuffer`, `NetCellFont_SetSessionData`, `XI_DEBUGLINK_10115D50 (left out)`, `XI_NETWORK_10115B20 (left out)`, `NetCellFont_GetSessionData`, `NetCellFont_GetSessionField13C`, `XI_DEBUGLINK_10115820 (left out)`
- `NetCellFont_StepRequest28Sequence` calls `NetCellFont_ResetCounter`, `NetCellFont_Advance`, `TargetMenu_GetMessageFwd`, `NetCellFont_CopyToGlobalBuffer`, `NetCellFont_SetSessionData`, `XI_DEBUGLINK_10115D50 (left out)`, `XI_NETWORK_10115C30 (left out)`, `NetCellFont_GetSessionData`, `NetCellFont_GetSessionField13C`, `XI_DEBUGLINK_10115820 (left out)`
- `NetCellFont_StepRequest2BSequence` calls `NetCellFont_ResetCounter`, `NetCellFont_Advance`, `XI_DEBUGLINK_10115D50 (left out)`, `TargetMenu_GetMessageFwd`, `NetCellFont_CopyToGlobalBuffer`, `XI_NETWORK_10115CC0 (left out)`
- `NetCellFont_StepState1030FFxx` calls `sub_1030FFCD`, `sub_1030FFD8`, `sub_1030FFB7`, `sub_1030FFC2`
- `NetCellFont_StepWait1030FFD8` calls `sub_1030FFD8`, `TargetMenu_GetMessageFwd`, `NetCellFont_CopyToGlobalBuffer`, `sub_1030FFCD`
- `NetCellFont_StepRequest14Sequence` calls `NetCellFont_ResetCounter`, `NetCellFont_Advance`, `XI_DEBUGLINK_10115D50 (left out)`, `TargetMenu_GetMessageFwd`, `NetCellFont_CopyToGlobalBuffer`, `XI_NETWORK_10115A90 (left out)`
- `NetCellFont_RunState` calls `NetCellFont_ResetCounter`, `NetCellFont_Advance`, `_exit_0`, `NetCellFont_UpdateSession`
- `NetCellFont_StepStateWithEntries` calls `NetCellFont_GetEntryPtrA90`, `NetCellFont_ScanIfTimer140Set`, `NetCellFont_GetRecordWordFwd`, `NetCellFont_SetWord130`, `NetCellFont_ClearTimer140`, `NetCellFont_UpdateSession`
- `NetCellFont_StepStateWithTimer` calls `NetCellFont_ScanIfTimer140Set`, `NetCellFont_ClearTimer140`, `NetCellFont_UpdateSession`
- `NetCellFont_UpdateSessionIfReady` calls nothing directly
- `NetCellFont_UpdateSessionReturn1` calls `NetCellFont_UpdateSession`
- `NetCellFont_DispatchByKindAndUpdate` calls `NetCellFont_UpdateSession`
- `NetCellFont_StatusText80IfFlags44` calls `NetCellFont_GetFlags`, `NetCellFont_ApplyStatusText`
- `NetCellFont_StatusText80IfFlag4Only` calls `NetCellFont_GetFlags`, `NetCellFont_ApplyStatusText`
- `NetCellFont_GetSessionField13C` calls `NetCellFont_GetField13C`
- `NetCellFont_GetRecordWord` calls nothing directly
- `NetCellFont_GetRecordDword` calls nothing directly
- `Name_LookupByKey` calls nothing directly
- `NetCellFont_CopyToGlobalBuffer` calls nothing directly
- `NetCellFont_GetBlock2CF54IfFlag` calls nothing directly
- `NetCellFont_ReturnTrue100F02A0` calls nothing directly
- `NetCellFont_SetByte15110` calls nothing directly
- `NetCellFont_SetByte15114` calls nothing directly
- `NetCellFont_ClearDword136A4` calls nothing directly
- `NetCellFont_GetFlagsMasked` calls `NetCellFont_GetFlags`
- `NetCellFont_GetWord40D82` calls nothing directly
- `NetCellFont_ClearRecord` calls nothing directly
- `NetCellFont_UpdateActive` calls `NetCellFont_StepBitGuardedTask`, `NetCellFont_ClearRecord`
- `NetCellFont_StepBitGuardedTask` calls `NetCellFont_IsBitSet`, `NetCellFont_SetBit`, `ErrorReport_Call10114F10NoArgs`, `_exit_0`, `NetCellFont_ClearBit`
- `NetCellFont_AcquireIfFree` calls `sub_100F1410`, `NetCellFont_AllocRecord`
- `NetCellFont_AllocRecord` calls nothing directly
- `NetCellFont_InitEntry` calls nothing directly
- `NetCellFont_IsBitSet` calls nothing directly
- `NetCellFont_SetBit` calls nothing directly
- `NetCellFont_ClearBit` calls nothing directly
- `NetCellFont_Query10310030` calls `sub_10310030`, `sub_1030FF75`
- `NetCellFont_Call10310067` calls `sub_10310067`
- `NetCellFont_Call10310072` calls `sub_10310072`
- `NetCellFont_GetLow16` calls `sub_103100EB`
- `NetCellFont_AcquireNode` calls `Allocator_Generic`, `NetCellFont_ClearNode`
- `NetCellFont_InitTwoNodes` calls `NetCellFont_ResetPending`, `Allocator_Generic`, `NetCellFont_ClearNode`
- `NetCellFont_Destroy` calls `NetCellFont_ResetPending`, `NetCellFont_RunCallbacks`, `NetCellFont_DestroyNode`, `operator_delete`
- `NetCellFont_UpdateRequests` calls `NetCellFont_RunCallbacks`, `NetCellFont_CallStateCallback3`, `NetCellFont_Complete`
- `NetCellFont_ResetPending` calls `sub_1031040E`, `sub_100F2A70`, `NetCellFont_CallStateCallback3`, `NetCellFont_Complete`
- `NetCellFont_BeginRequests` calls `sub_10310D82`, `Allocator_Generic`, `NetCellFont_ClearNode`, `NetCellFont_GetWord132`, `NetCellFont_GetEntryPtrA90`, `NetCellFont_ClearBit1Fc`, `NetCellFont_StartRequestSlot20`, `NetCellFont_StartRequestOnNewNodeA`, `NetCellFont_StartRequestOnNewNodeB`
- `NetCellFont_StartRequestSlot20` calls `NetCellFont_InitRequestA`
- `NetCellFont_StartRequestOnNewNodeA` calls `NetCellFont_AcquireNode`, `NetCellFont_InitRequestB`
- `NetCellFont_StartRequestOnNewNodeB` calls `NetCellFont_AcquireNode`, `NetCellFont_InitRequestC`
- `NetCellFont_StartRequestSlot24` calls `NetCellFont_InitRequestD`
- `NetCellFont_ClearNode` calls nothing directly
- `NetCellFont_DestroyNode` calls `sub_100F2A70`, `operator_delete`
- `NetCellFont_Complete` calls `ErrorReport_Call10114F10NoArgs`, `sub_100F2A70`
- `NetCellFont_CallStateCallback3` calls nothing directly
- `NetCellFont_RunCallbacks` calls `sub_100F2A70`, `sub_1030FF75`, `NetCellFont_CopyBounded`, `sub_1030FF49`, `sub_1030FF33`, `sub_10310353`, `_exit_0`
- `NetCellFont_CopyBounded` calls nothing directly
- `NetCellFont_StartCallbacks` calls nothing directly
- `NetCellFont_StartIfIdle` calls `NetCellFont_StartCallbacks`
- `NetCellFont_InitRequestA` calls `NetCellFont_StartCallbacks`
- `NetCellFont_InitRequestB` calls `NetCellFont_StartCallbacks`
- `NetCellFont_InitRequestC` calls `NetCellFont_StartCallbacks`
- `NetCellFont_InitRequestD` calls `NetCellFont_StartCallbacks`
- `NetCellFont_StartGlobalRequestSlot24` calls `NetCellFont_StartRequestSlot24`
- `NetCellFont_EnsureGlobal` calls `NetCellFont_InitTwoNodes`
- `NetCellFont_DestroyGlobal` calls `NetCellFont_Destroy`
- `NetCellFont_UpdateGlobalRequests` calls `NetCellFont_UpdateRequests`
- `NetCellFont_BeginGlobalRequests` calls `NetCellFont_EnsureGlobal`, `NetCellFont_BeginRequests`
- `NetCellFont_StoreQueriesInto104DF90C` calls `sub_100F1920`, `sub_100F1910`, `sub_100F1940`, `sub_100F1930`, `NetCellFont_GetLow16`, `NetCellFont_Query10310030`
- `NetCellFont_StoreQueries2Into104DF90C` calls `sub_100F1940`, `sub_100F1930`, `NetCellFont_InitEntryAt104DF90C`, `NetCellFont_Query10310030`
- `NetCellFont_InitEntryAt104DF90C` calls `NetCellFont_InitEntry`
- `NetCellFont_GetFieldCOf104DF90C` calls nothing directly
- `NetCellFont_GetActiveBlock3AE98` calls nothing directly
- `NetCellFont_GetDword40C3C` calls nothing directly
- `NetCellFont_IsReadyBy3C350` calls nothing directly
- `NetCellFont_TickSecondCounters` calls `NetCellFont_SetByte15110`, `NetCellFont_GetTotalMilliseconds`
- `NetCellFont_UpdateSession` calls `NetCellFont_TickSecondCounters`, `XI_NETWORK_100FA180 (left out)`
- `NetCellFont_GetFlags` calls nothing directly
- `NetCellFont_ApplyStatusText` calls `sub_10311FF1`, `NetCellFont_SetByte15114`
- `NetCellFont_GetWord40DAA` calls nothing directly
- `NetCellFont_SetWord40DAA` calls nothing directly
- `NetCellFont_GetBlock3C3A4OrDefault` calls nothing directly
- `NetCellFont_GetIdPair` calls nothing directly
- `NetCellFont_FindTimerKind10` calls nothing directly
- `NetCellFont_IsId50To99Or88Or89` calls nothing directly
- `NetCellFont_TestBit198CC` calls nothing directly
- `NetCellFont_GetTableByteForTens` calls `NetCellFont_CeilDiv10Max10`
- `NetCellFont_CeilDiv10Max10` calls nothing directly
- `Game_ClearFlagsBits` calls nothing directly
- `Game_SetSlot44C` calls nothing directly
- `NetCellFont_ReturnZero` calls nothing directly
- `Game_GetField4` calls nothing directly
- `NetCellFont_GetWord8Of104E0AF4` calls nothing directly
- `NetCellFont_UpdateNoticesIfReady` calls `NetCellFont_Sync`, `Game_IsFlag10492DB4`, `NetCellFont_IsInitialized`, `NetCellFont_ApplyNoticeRecord`, `FDtGmNoticeProc`, `NetCellFont_UpdateGlobalRequests`
- `ntGameTimeGet` calls `NetCellFont_AdvanceAndGetSeconds`
- `Time_ModDiv12FC00Div19500` calls nothing directly
- `Time_ModDiv19500Scaled` calls nothing directly
- `Time_ModDiv6C00Scaled` calls nothing directly
- `Time_ModDivD80Div90` calls nothing directly
- `Time_ModMul3CDiv90` calls nothing directly
- `NetCellFont_SetZero` calls nothing directly
- `fn_101061D0` calls nothing directly
- `NetCellFont_LookupMaskedTable` calls nothing directly
- `NetCellFont_LookupTable10364CB0` calls `NetCellFont_LookupMaskedTable`
- `NetCellFont_AppendMax20` calls nothing directly
- `NetCellFont_DumpHexBytes` calls `sub_10311FF1`, `sub_1031482F`, `NetCellFont_GetNextBlock`, `sub_10312EAD`, `operator_delete`
- `NetCellFont_GetPoolBlockPayload` calls nothing directly
- `NetCellFont_AllocEntry` calls `sub_10108460`
- `NetCellFont_AllocFromPool` calls `sub_10108460`
- `NetCellFont_AllocFromPool0` calls `sub_10108460`
- `NetCellFont_InitBlock` calls nothing directly
- `NetCellFont_InsertBlock` calls `NetCellFont_LinkBefore`, `NetCellFont_LinkAfter`, `NetCellFont_RebalanceList`
- `NetCellFont_InsertAndCoalesce` calls `NetCellFont_UnlinkBlock`, `NetCellFont_LinkAfter`, `NetCellFont_LinkBefore`
- `NetCellFont_GetNextBlock` calls nothing directly
- `NetCellFont_GetPrevBlock` calls nothing directly
- `NetCellFont_RebalanceList` calls nothing directly
- `NetCellFont_TakeFreeBlock` calls `NetCellFont_GetNextBlock`, `NetCellFont_InsertBlock`, `NetCellFont_UnlinkBlock`
- `NetCellFont_Free` calls `NetCellFont_GetPrevBlock`, `NetCellFont_GetNextBlock`, `NetCellFont_InsertAndCoalesce`, `NetCellFont_InsertBlock`, `NetCellFont_UnlinkBlock`, `NetCellFont_RebalanceList`
- `NetCellFont_UnlinkBlock` calls `NetCellFont_RebalanceList`
- `NetCellFont_LinkAfter` calls `NetCellFont_RebalanceList`
- `NetCellFont_LinkBefore` calls `NetCellFont_RebalanceList`
- `NetCellFont_AllocCopy` calls `NetCellFont_GetPoolBlockPayload`, `NetCellFont_AllocEntry`, `sub_101086B0`
- `NetCellFont_Release` calls `sub_101086B0`
- `NetCellFont_RefStringClear` calls nothing directly
- `NetCellFont_RefStringCtor` calls `NetCellFont_RefStringClear`, `NetCellFont_RefStringAssign`
- `NetCellFont_RefStringReserve` calls `NetCellFont_AllocFromPool`, `NetCellFont_RefStringClear`, `NetCellFont_AllocCopy`
- `NetCellFont_RefStringAssign` calls `NetCellFont_RefStringRelease`, `NetCellFont_RefStringReserve`, `sub_101086B0`, `NetCellFont_RefStringClear`
- `NetCellFont_RefStringRelease` calls `NetCellFont_RefStringClear`, `sub_101086B0`
- `NetCellFont_Copy12` calls nothing directly
- `NetCellFont_RecorderAddHandler` calls `Allocator_Generic`, `NetCellFont_Copy12B`, `NetCellFont_Copy12`, `NetCellFont_AllocFromPool0`, `NetCellFont_ListInsertBefore`
- `NetCellFont_RecorderRecordCode` calls nothing directly
- `NetCellFont_ForwardToGlobal1708` calls `NetCellFont_RecorderRecordCode`
- `NetCellFont_Copy12B` calls nothing directly
- `NetCellFont_ListInsertBefore` calls nothing directly
- `NetCellFont_ClearTable1710` calls nothing directly
- `NetCellFont_StartRequestSlot24WithCallback` calls `Allocator_Generic`, `NetCellFont_StartGlobalRequestSlot24`, `operator_delete`
- `NetCellFont_ErrorLogDtor` calls `sub_10312EAD`, `operator_delete`
- `NetCellFont_ErrorLogPop` calls `sub_10312EAD`, `operator_delete`
- `NetCellFont_PushRingEntryLocked` calls `sub_10312EAD`, `operator_delete`
- `NetCellFont_ErrorLogFlush` calls `TextInputFiles_FileMngFwd101C18E0`, `NetCellFont_ErrorLogPop`, `sub_10312EAD`, `operator_delete`, `sub_10311FF1`, `TextInputFiles_FileMngQueuePath3F4Kind3`
- `NetCellFont_SumWords16` calls nothing directly
- `NetCellFont_ReportError` calls `sub_100DBE10`, `NetCellFont_ForwardToGlobal1708`, `Allocator_Generic`, `sub_10312F96`, `operator_delete`, `NetCellFont_PushRingEntryLocked`, `sub_10312EAD`
- `FDtGmNoticeProc` calls `NetCellFont_ErrorLogFlush`, `TextInputFiles_FileMngFwd101C1750`, `TextInputFiles_FileMngSubmitPathKind3`, `sub_10311FF1`, `TextInputFiles_FileMngQueuePathKind3`, `NetCellFont_ClearTable1710`
- `NetCellFont_ReturnOneA` calls nothing directly
- `NetCellFont_ReturnOneB` calls nothing directly
- `NetCellFont_ArmCounter10` calls `FontGlyphCache_MarkState3`
- `NetCellFont_SetSessionData` calls nothing directly
- `NetCellFont_GetSessionData` calls nothing directly
- `NetCellFont_IsStateActive` calls nothing directly
- `NetCellFont_GetField13C` calls nothing directly
- `NetCellFont_NextSequence` calls `NetCellFont_AddOne`, `sub_10311FF1`
- `NetCellFont_SetPair` calls nothing directly
- `NetCellFont_MenuCtor` calls `NetCellFont_ClearWords`, `NetCellFont_Clear`, `NetCellFont_SetPair`
- `NetCellFont_DeleteAllEntries` calls `NetCellFont_GetHead`, `sub_10126520`, `NetCellFont_Remove`, `NetCellFont_NoOp`, `NetCellFont_FreeEntryData`, `operator_delete`, `NetCellFont_FreeListsAndReset`, `NetCellFont_FreeBothLists`
- `Menu_DrawWindowItems` calls `sub_10117520`, `NetCellFont_GetHead`, `NetCellFont_SetViewport`, `sub_10126520`, `Menu_IsFocusedItem`, `NetCellFont_DrawUnscaled`, `sub_1011FC80`, `TargetMenu_MenuTestItem34Or6B`, `sub_10311C2C`, `sub_10234A90`, `sub_1011A250`, `sub_1011A150`, `Gfx_ApplyViewport1B70`, `TargetMenu_GetScaledPos80`, `MenuPanels_DrawProgressBar`
- `NetCellFont_MenuReleaseItemCount` calls nothing directly
- `NetCellFont_InvokeChild34` calls nothing directly
- `NetCellFont_Rebuild` calls `NetCellFont_GetField8`, `Allocator_Generic`, `NetCellFont_InitScaled`, `NetCellFont_SetSource`, `NetCellFont_ComputeRect`, `NetCellFont_UpdateLayout`, `NetCellFont_PushBack`, `NetCellFont_GetEntry`, `NetCellFont_LayoutCtor`, `NetCellFont_SetNames`, `NetCellFont_ComputeOffsets`, `NetCellFont_UpdateState`, `NetCellFont_GetFieldC`, `NetCellFont_InitDefaults`, `NetCellFont_SetShape`, `NetCellFont_AttachTo`, `NetCellFont_StepFrameCycle`, `NetCellFont_SelectEntry`
- `NetCellFont_ClearEntries` calls `NetCellFont_GetHead`, `sub_10126520`, `NetCellFont_Remove`, `NetCellFont_NoOp`, `NetCellFont_FreeEntryData`, `operator_delete`, `NetCellFont_FreeListsAndReset`
- `NetCellFont_AttachSelection` calls `sub_101181D0`, `NetCellFont_GetHead`, `sub_10126520`, `NetCellFont_AttachTo`
- `NetCellFont_FindFreeEntry` calls `NetCellFont_GetHead`, `sub_10126520`
- `NetCellFont_MenuMoveSelection` calls `sub_101181D0`, `NetCellFont_GetFieldByIndex`, `NetCellFont_SelectEntry`, `SetMusicTrackVolume_C`, `SetMusicTrackVolume_Tag0004`, `SetMusicTrackVolume_A`, `NetCellFont_GetEntryValueById`, `NetCellFont_SetState`, `SetMusicTrackVolume_B`, `TargetMenu_MenuInitAndFadeItem`, `MenuMng_TestNameForSceneState`
- `NetCellFont_NoOpB` calls nothing directly
- `NetCellFont_PlaceCursorObject` calls `Allocator_Generic`, `fn_10234610`
- `NetCellFont_GetFocusedValueA` calls `Menu_GetFocusedItem`, `NetCellFont_GetHead`, `sub_10126520`
- `NetCellFont_GetFocusedValueB` calls `Menu_GetFocusedItem`, `NetCellFont_GetHead`, `sub_10126520`
- `sub_101186A0` calls `Menu_GetFocusedItem`, `sub_101181D0`, `NetCellFont_GetFocusedValueA`, `TargetMenu_ForwardToPanel`, `TargetMenu_SetTextFwd`, `NetCellFont_GetFocusedValueB`
- `NetCellFont_MenuStartFade` calls nothing directly
- `NetCellFont_SelectFirstVisible` calls `NetCellFont_GetOffsets`, `NetCellFont_SelectEntry`
- `NetCellFont_SetStateByIndex` calls `NetCellFont_GetHead`, `sub_10126520`, `NetCellFont_SetState`
- `NetCellFont_FindEntryValueById` calls `NetCellFont_GetHead`, `sub_10126520`
- `NetCellFont_HitTest` calls nothing directly
- `NetCellFont_PickEntry` calls `NetCellFont_GetHead`, `sub_10126520`
- `NetCellFont_SelectEntryMoveCursor` calls `sub_101181D0`, `NetCellFont_SetState`, `NetCellFont_AttachSelection`, `NetCellFont_MenuMoveSelection`, `NetCellFont_GetCenter`, `Cursor_SetPosition`, `sub_101186A0`
- `NetCellFont_SelectEntry` calls `sub_101181D0`, `NetCellFont_SetState`, `NetCellFont_AttachSelection`, `sub_101186A0`
- `NetCellFont_SetChildOwner` calls nothing directly
- `NetCellFont_CallMember0CSlot2` calls nothing directly
- `NetCellFont_FreeChild` calls nothing directly
- `NetCellFont_GetRect` calls `Menu_GetNormalizedPos`, `sub_10311C2C`
- `NetCellFont_SetState10ForIndex58` calls `NetCellFont_SetStateByIndex`
- `NetCellFont_SetActive` calls `NetCellFont_GetHead`, `sub_10126520`, `NetCellFont_ClearField34`, `NetCellFont_ApplyHelpAndTitle`, `sub_101186A0`, `sub_1011A560`
- `NetCellFont_ClearEntryFlags` calls `sub_101181D0`
- `NetCellFont_MarkDirty` calls `sub_101181D0`
- `NetCellFont_InitScaled` calls `NetCellFont_ClearWords`
- `NetCellFont_FreeEntryData` calls `operator_delete`, `NetCellFont_NoOp`
- `NetCellFont_ClearField34` calls nothing directly
- `NetCellFont_StartFade` calls nothing directly
- `NetCellFont_StopFade` calls nothing directly
- `NetCellFont_SetSource` calls nothing directly
- `NetCellFont_ComputeRect` calls `Menu_GetNormalizedPos`, `sub_10311C2C`
- `NetCellFont_UpdateLayout` calls `Menu_GetNormalizedPos`, `sub_10311C2C`, `Allocator_Generic`, `MenuPanels_SetPair`, `Camera_GetFrameScale`, `NetCellFont_MapKind119870`, `ShapeMng_FindShape`
- `NetCellFont_MapKind119870` calls nothing directly
- `NetCellFont_LayoutCtor` calls `NetCellFont_ClearWords`, `NetCellFont_SetPair`, `NetCellFont_SetState`
- `NetCellFont_SetState` calls nothing directly
- `NetCellFont_SetNames` calls nothing directly
- `NetCellFont_ComputeOffsets` calls `Menu_GetNormalizedPos`, `sub_10311C2C`
- `sub_10119BC0` calls nothing directly
- `NetCellFont_UpdateState` calls `NetCellFont_SetState`, `sub_10119BC0`, `NetCellFont_MapKind119870`, `ShapeMng_FindShape`, `Menu_GetNormalizedPos`
- `NetCellFont_InitDefaults` calls `NetCellFont_ClearWords`
- `NetCellFont_SetShape` calls `NetCellFont_ResolveShape`
- `NetCellFont_AttachTo` calls nothing directly
- `NetCellFont_ResolveShape` calls `ShapeMng_FindShape`
- `NetCellFont_StepFrameCycle` calls `Camera_GetFrameScale`, `sub_10311C2C`
- `NetCellFont_DrawUnscaled` calls `sub_10119FB0`
- `NetCellFont_InvokeCallback7C` calls nothing directly
- `NetCellFont_ApplyHelpAndTitle` calls `Menu_GetFocusedItem`, `NetCellFont_GetHead`, `sub_10126520`, `TargetMenu_ForwardToPanel`, `TargetMenu_SetTextFwd`
- `NetCellFont_SetRectAndUpdateNodes` calls `NetCellFont_GetHead`, `sub_10126520`, `NetCellFont_AttachTo`, `NetCellFont_ComputeOffsets`
- `NetCellFont_GetPos42` calls nothing directly
- `NetCellFont_SetViewport` calls `CDx::GetRenderTargetTop`, `CDx::SetViewport`
- `Gfx_ApplyViewport1B70` calls `CDx::SetViewport`
- `NetCellFont_GetCenter` calls `NetCellFont_GetHead`, `sub_10126520`
- `NetCellFont_SetEntryValue4C` calls `sub_101181D0`, `sub_101186A0`
- `NetCellFont_AddEntry` calls `NetCellFont_FindFreeEntry`, `sub_101186A0`
- `NetCellFont_GetFieldByIndex` calls nothing directly
- `NetCellFont_GetEntryValueById` calls nothing directly
- `NetCellFont_GetEntry` calls nothing directly
- `NetCellFont_GetField8` calls nothing directly
- `NetCellFont_GetFieldC` calls nothing directly
- `NetCellFont_GetOffsets` calls nothing directly
- `NetCellFont_SetShorts1A1C` calls nothing directly
- `NetCellFont_InitColors` calls nothing directly
- `Font_BindGlyphTexture` calls `Util_Copy16Bytes`, `CYyTexMng::FindByName`, `Font_LoadHighResTexture`, `Font_IsHighResTextureLoaded`
- `Font_DrawGlyphQuadGrey` calls `Font_DrawGlyphQuad`
- `Font_DrawGlyphQuad` calls `Color_ModulateArgb128`, `CDx::DrawPrimitiveUP`
- `Gfx_SetAdditiveBlend` calls nothing directly
- `Font_DrawChar` calls `Font_DrawGlyphQuadGrey`, `sub_1011FB60`, `Gfx_SetAdditiveBlend`, `Font_BindGlyphTexture`
- `Font_MeasureString` calls `Sjis_GetCharByteLen`, `Font_DecodeNextChar`, `Font_AddGlyphAdvance`, `sub_10311C2C`
- `Gfx_SetCellBlendMode` calls `ErrorReport_NoOpVarargsA`
- `Font_AllocHighResImage` calls `Allocator_Generic`, `TexBase_CopyName16`
- `Tex_LoadSurfaceFromDatFile` calls `FileMng_ResolveOrExit`, `Allocator_Generic`, `TextInputFiles_ForwardOrExit`, `sub_102D445D`, `operator_delete`
- `Font_LoadHighResTexture` calls `FileMng_ResolveOrExit`, `Font_AllocHighResImage`, `Mem_AllocDefault`, `sub_10026890`, `TexObj_CreateAndUpload`, `Tex_LoadSurfaceFromDatFile`, `Font_ReleaseHighResTexture`
- `Font_ReleaseHighResTexture` calls `operator_delete`
- `Font_IsHighResTextureLoaded` calls nothing directly
- `unknown_libname_88` calls nothing directly
- `Font_LoadWidthTable` calls `Cell_FindEntryByName`, `NetCellFont_GetNthEntryBytePair`
- `Font_IsSingleByte` calls `Sjis_IsLeadByte`
- `Sjis_ToJisIndex` calls nothing directly
- `Font_DecodeNextChar` calls `Font_IsSingleByte`, `Sjis_ToJisIndex`
- `Font_GetCharWidth` calls `Sjis_ToJisIndex`, `ShapeMng_FindShape`
- `Font_MeasureText` calls `Font_IsSingleByte`, `Font_GetCharWidth`
- `Font_MeasureTextAll` calls `Font_MeasureText`
- `Font_MeasureTextAll2` calls `Font_MeasureTextAll`
- `NetCellFont_IsNotControlChar` calls nothing directly
- `NetCellFont_MeasureTextWidth` calls `Font_IsSingleByte`, `Font_GetCharWidth`
- `NetCellFont_MeasureTextWidthAll` calls `NetCellFont_MeasureTextWidth`
- `Font_AddGlyphAdvance` calls nothing directly
- `Font_IsPrintableAscii` calls nothing directly
- `NetCellFont_MeasureTextWidthFwd` calls `NetCellFont_MeasureTextWidthAll`
- `Font_GetCharWidthAt` calls `Font_IsSingleByte`, `Font_GetCharWidth`
- `Sjis_IsLeadByte` calls nothing directly
- `Sjis_GetCharByteLen` calls `Sjis_IsLeadByte`
- `Sjis_IsCodeInSet` calls `sub_1011DAA0`
- `sub_1011DC00` calls `sub_1011DAA0`
- `sub_1011DCC0` calls `sub_1011DAA0`
- `Sjis_CopyPrefix` calls `Sjis_GetCharByteLen`, `sub_10312050`
- `Cell_GetField20Ptr` calls nothing directly
- `Cell_ResolveSubCells` calls `Cell_ResolveTextureList`
- `Cell_ResolveTextureUV` calls `sub_10315AA8`, `Util_Copy16Bytes`, `CYyTexMng::FindByName`
- `Cell_DrawAt` calls `sub_10315AA8`, `Util_Copy16Bytes`, `CYyTexMng::FindByName`, `Cell_DrawQuadBlended`
- `Cell_DrawTexturedQuad` calls `sub_10315AA8`, `Util_Copy16Bytes`, `CYyTexMng::FindByName`, `Color_ModulateArgb128`, `Cell_DrawWithDefaultBlend`, `Cell_DrawQuadBlended`
- `Cell_DrawTransformed` calls `sub_10315AA8`, `Util_Copy16Bytes`, `CYyTexMng::FindByName`, `MathVector_Nop`, `Color_ModulateArgb128`, `Mat4_TransformNormalInPlace`, `Cell_DrawWithDefaultBlend`, `Cell_DrawQuadBlended`
- `Cell_DrawStretchedWrapped` calls `sub_10315AA8`, `Util_Copy16Bytes`, `CYyTexMng::FindByName`, `Color_ModulateArgb128`, `Cell_DrawWithDefaultBlend`, `Cell_DrawQuadBlended`
- `Cell_DrawWithDefaultBlend` calls `Cell_DrawQuadBlended`
- `Cell_DrawQuadBlended` calls `ErrorReport_NoOpVarargsA`, `CDx::DrawPrimitiveUP`
- `Cell_GetFrameBounds` calls `NetCellFont_GetHead`, `sub_10126520`
- `NetCellFont_GetNthEntryBytePair` calls `NetCellFont_GetHead`, `sub_10126520`
- `Cell_DrawFirstStretched` calls `NetCellFont_GetHead`, `sub_10126520`, `Cell_DrawStretchedWrapped`
- `Cell_ResolveTextureList` calls `NetCellFont_GetHead`, `sub_10126520`, `Cell_ResolveTextureUV`
- `Color_ModulateArgb128` calls nothing directly
- `ShapeMng_FindShape` calls `NetCellFont_GetHead`, `sub_10126520`, `sub_10325D00`, `Cell_GetField20Ptr`
- `Cell_FindEntryByName` calls `NetCellFont_GetTail`, `NetCellFont_NextActiveValue`, `sub_10325D00`, `Cell_GetField20Ptr`
- `ShapeMng_GetFontGlyph` calls `ShapeMng_FindShape`, `Cell_GetFrameBounds`
- `ShapeMng_LoadFontTextures` calls `Util_Copy16Bytes`, `ShapeMng_FindShape`, `NetCellFont_GetHead`, `sub_10126520`, `sub_10315AA8`, `sub_10312940`, `CYyTexMng::FindByName`
- `Cell_ResolveAllSubCells` calls `NetCellFont_GetHead`, `sub_10126520`, `Cell_ResolveSubCells`
- `Cell_TestAny38Or0B8` calls `Cursor_GetFlagBit2`
- `Cell_TestAny1DOr9D` calls `Cursor_GetFlagBit2`
- `Cell_TestAny2AOr36` calls `Cursor_GetFlagBit2`
- `Cell_GetByte253Scaled` calls nothing directly
- `NetCellFont_QueryState1D44AL` calls nothing directly
- `NetCellFont_QueryState1D44Mask100` calls nothing directly
- `NetCellFont_QueryState1D44Mask1000` calls nothing directly
- `NetCellFont_QueryState1D44Mask4000` calls nothing directly
- `NetCellFont_QueryState1D44Clear22C` calls nothing directly
- `NetCellFont_Call10122E30With1` calls `sub_10122E30`
- `NetCellFont_GetCursorValueUnlessBlocked` calls `Menu_HasFocusedItem`, `Cell_TestFlagAny2AOr36`, `TextInputFiles_IsModeFourOrFive`, `sub_101260D0`, `sub_10122E30`
- `Cell_TestFlagAny2AOr36` calls `Cell_TestFlagKind`
- `Cell_TestFlagKind` calls `TextInputFiles_IsModeFourOrFive`, `Cursor_GetFlagBit4`, `Cell_TestFlagBit0`, `Cell_TestFlagBit1`, `Cursor_TakeEventFlag`, `Cell_TakeFlagBit2`, `Cell_TestFlagBit3`, `Cursor_GetFlagBit2`
- `Cell_GetByte1036E0F0` calls nothing directly
- `Cell_SetByte1036E0F0` calls nothing directly
- `Cell_GetWord1036D6B0` calls nothing directly
- `Cell_SetWord1036D6B0` calls nothing directly
- `NetCellFont_SetTable1036D6B0Word` calls nothing directly
- `Cell_SetGlobal1036E3A0` calls nothing directly
- `NetCellFont_Query123700UnlessBlocked` calls `TextInputFiles_IsModeFourOrFive`, `sub_1011BA40`, `Menu_HasFocusedItem`, `Cell_TestAny1DOr9D`, `Cell_TestAny38Or0B8`, `Cell_TestAny2AOr36`, `TextInputFiles_IsState1Or3`, `TextInputFiles_HasTable1037A290CellByte`, `Cursor_GetFlagBit2`
- `NetCellFont_TestCommand36CF60` calls `TextInputFiles_IsModeFourOrFive`, `Cursor_TestAny1DOr9D`, `Cursor_TestAnyB8Or38`, `Cell_TestFlagAny2AOr36Kind4`, `Cell_GetByte1036CF5C`, `Cell_TestFlagKind`, `Cell_TestAny38Or0B8`, `Cell_TestAny2AOr36`, `Cell_TestAny1DOr9D`, `Cursor_UpdateVisibilityForMode`
- `Cursor_TestAny1DOr9D` calls `Cursor_GetFlagBit2`
- `Cursor_TestAnyB8Or38` calls `Cursor_GetFlagBit2`
- `Cell_TestFlagAny2AOr36Kind4` calls `Cell_TestFlagKind`
- `Cell_TestGlobal1036E3A0Mask` calls nothing directly
- `Cell_SetByte104E1C3E` calls nothing directly
- `Cell_Nop` calls nothing directly
- `Cell_ClearFlag104E1C3C` calls nothing directly
- `Cell_SetFlag104E1C3C` calls nothing directly
- `Cell_GetByte1036CF5C` calls nothing directly
- `Cell_SetFlagBit2` calls nothing directly
- `Cell_SetFlagBit8` calls nothing directly
- `NetCellFont_SetByteFlag1` calls nothing directly
- `Cell_SetFlagBit4Dirty` calls nothing directly
- `Cell_SetFlagBit10` calls nothing directly
- `Cell_ClearByte` calls nothing directly
- `Cell_ClearFlag01And08` calls nothing directly
- `sub_10124050` calls `Cell_ClearFlag01And08`
- `Cell_TestFlagBit1` calls nothing directly
- `Cell_TakeFlagBit2` calls nothing directly
- `Cell_TestFlagBit3` calls nothing directly
- `Cell_TestFlagBit0` calls nothing directly
- `Cursor_TakeEventFlag` calls nothing directly
- `Cursor_GetFlagBit4` calls nothing directly
- `Cursor_GetFlagBit2` calls nothing directly
- `NetCellFont_HalfKanaToFullWidth` calls nothing directly
- `NetCellFont_IsHalfWidthKana` calls nothing directly
- `Cursor_Init` calls `ShapeMng_FindShape`, `Cursor_StoreScreenCenter`, `CDx::ShowCursor`, `Cursor_SetPosition`
- `Cursor_GetHwCursorSlot` calls nothing directly
- `Cursor_HandleMouseMove` calls `FontGlyphCache_IsStateTwo`, `Menu_HasFocusedItem`, `CTkMouse_OnMouseMove`, `FontGlyphCache_AddToCounter`
- `CTkMouse_OnMouseMove` calls `Menu_GetStateB4`, `CDx::ShowCursor`, `Cursor_SetVisible`, `sub_10311C2C`
- `Cursor_SetPosition` calls `sub_10311C2C`, `SetCursorPos`
- `Cursor_UpdateTimer` calls `Menu_GetStateB4`, `Camera_GetFrameScale`, `sub_10311C2C`
- `Cursor_EnterMode1` calls `FontGlyphCache_IsStateTwo`, `Settings_GetValue`, `Cursor_StoreScreenCenter`
- `Cursor_ToggleFlag1` calls nothing directly
- `Cursor_EnterMode2` calls `FontGlyphCache_IsStateTwo`, `Settings_GetValue`, `Cursor_StoreScreenCenter`
- `Cursor_ToggleFlag2` calls nothing directly
- `Cursor_EnterMode4` calls `FontGlyphCache_IsStateTwo`, `Settings_GetValue`, `Cursor_StoreScreenCenter`
- `Cursor_ToggleFlag4` calls nothing directly
- `Cursor_ResetPositionToMenu` calls `Menu_HasFocusedItem`, `Menu_GetFocusedItem`, `NetCellFont_GetCenter`, `Cursor_SetPosition`
- `NetCellFont_CursorUpdateEdgeAxes` calls `sub_10311C2C`, `Settings_GetValue`, `FontGlyphCache_IsStateTwo`, `Camera_GetFrameScale`, `ActorHandle_Resolve`
- `NetCellFont_UpdateHoldState4` calls `FontGlyphCache_IsStateTwo`, `NetCellFont_TestCommand36CF60`, `Camera_GetFrameScale`, `sub_10311C2C`
- `NetCellFont_UpdateHoldState5` calls `NetCellFont_TestCommand36CF60`, `FontGlyphCache_IsStateTwo`, `Camera_GetFrameScale`, `sub_10311C2C`, `LobbyUi_GetGlobalDword`
- `Cursor_SetModeFromMenuActive` calls `Menu_HasFocusedItem`
- `Cursor_SetVisible` calls `CDx::ShowCursor`, `CDx::SetCursorShape`
- `Cursor_UpdateVisibilityForMode` calls `Cursor_SetVisible`, `Cursor_SetModeFromMenuActive`
- `Cursor_GetField98` calls nothing directly
- `Cursor_GetField94` calls nothing directly
- `Cursor_GetNormalizedDeltaY` calls nothing directly
- `Cursor_HasTargetHover` calls `Target_PickNearestToPoint`
- `unknown_libname_89` calls `Menu_HasFocusedItem`
- `Cursor_StoreScreenCenter` calls nothing directly
- `NetCellFont_IsCursorMode2NoEvent` calls `IsEvent`
- `NetCellFont_Init` calls nothing directly
- `NetCellFont_ClearWords` calls nothing directly
- `NetCellFont_NoOp` calls nothing directly
- `NetCellFont_Clear` calls nothing directly
- `NetCellFont_FreeBothLists` calls `operator_delete`
- `NetCellFont_Alloc` calls `Allocator_Generic`, `NetCellFont_Init`
- `NetCellFont_GetCount` calls nothing directly
- `NetCellFont_PushBack` calls `NetCellFont_Alloc`
- `NetCellFont_PushFront` calls `NetCellFont_Alloc`
- `NetCellFont_GetHead` calls nothing directly
- `NetCellFont_GetTail` calls nothing directly
- `NetCellFont_NextActiveValue` calls nothing directly
- `NetCellFont_Remove` calls nothing directly
- `NetCellFont_FreeListsAndReset` calls `operator_delete`
- `NetCellFont_InsertBefore` calls `NetCellFont_PushBack`, `NetCellFont_Alloc`
- `NetCellFont_InsertAfter` calls `NetCellFont_PushBack`, `NetCellFont_Alloc`
- `NetCellFont_ChatListCtorA` calls `NetCellFont_ChatListInit`
- `NetCellFont_ChatListCtorB` calls `NetCellFont_ChatListInit`
- `NetCellFont_ChatListInit` calls `NetCellFont_Clear`, `NetCellFont_FreeListsAndReset`
- `NetCellFont_AddMessage` calls `Allocator_Generic`, `NetCellFont_MessageCtor`, `NetCellFont_MessageSet`, `NetCellFont_PushBack`
- `NetCellFont_ClearAllAndNotifyOwner` calls `NetCellFont_ClearFlag12FromValue`, `NetCellFont_GetHead`, `sub_10126520`, `NetCellFont_Remove`, `NetCellFont_NoOp`, `operator_delete`, `NetCellFont_FreeListsAndReset`
- `NetCellFont_MessageCtor` calls `NetCellFont_ClearWords`
- `NetCellFont_MessageSet` calls `sub_10312050`, `sub_10126C60`, `sub_10136670`
- `sub_10126C60` calls `NetCellFont_InitTextLayout`, `sub_10312050`, `NetCellFont_CallClearBuffers`, `NetCellFont_SetString`, `NetCellFont_GetWord1A`, `NetCellFont_GetField20`, `sub_1012A4F0`, `NetCellFont_GetByte9`, `sub_1012A340`, `sub_10315BE0`
- `NetCellFont_MsgWinDataCtor` calls `NetCellFont_MsgWinDataReset`
- `NetCellFont_MsgWinDataReset` calls `NetCellFont_ResetEntryRing`, `Font_GetCharWidthAt`, `NetCellFont_CountTextChars`
- `NetCellFont_ResetEntryRing` calls nothing directly
- `NetCellFont_PushSlot` calls nothing directly
- `NetCellFont_NewRingEntry` calls nothing directly
- `NetCellFont_BuildRecord` calls `NetCellFont_FindKindRecord`, `NetCellFont_MapCode`, `sub_100DBE10`, `sub_101284F0`
- `NetCellFont_FindByKeyByte` calls nothing directly
- `NetCellFont_FindChar` calls nothing directly
- `NetCellFont_FindSubstringIndex` calls nothing directly
- `NetCellFont_CopyLimited` calls nothing directly
- `NetCellFont_ToLowerInPlace` calls nothing directly
- `GetCallNum` calls `Settings_GetValue`, `NetCellFont_CopyLimited`, `NetCellFont_ToLowerInPlace`, `NetCellFont_FindChar`, `NetCellFont_FindSubstringIndex`, `sub_103151D0`
- `NetCellFont_IsNearNamedActor` calls `sub_103151D0`, `sub_10312050`, `ActorHandle_Resolve`, `Actor_GetObjectByName`, `sub_10311C2C`
- `ChatLog_AddMessage` calls `JpegScreenshot_TestMask10663188`, `sub_1012A340`, `NetCellFont_BuildRecord`, `GetCallNum`, `NetCellFont_IsNearNamedActor`, `MusicFont_Create`, `TextInputFiles_InputCall101AC990`, `sub_10312050`, `NetCellFont_AddMessage`, `Text_EncodeQuotes`, `NetCellFont_FindByKeyByte`, `sub_10128CE0`
- `NetCellFont_ClearGlobalLists2150And2154` calls `NetCellFont_ClearAllAndNotifyOwner`
- `NetCellFont_CtorResetAll` calls `NetCellFont_ResetAll`
- `NetCellFont_ResetAll` calls nothing directly
- `NetCellFont_IsInRow30` calls nothing directly
- `NetCellFont_FormatHexRecord` calls `sub_10311FF1`
- `NetCellFont_ParseHexRecord` calls `sub_10313643`, `NetCellFont_IsInRow30`
- `NetCellFont_AddByType` calls nothing directly
- `NetCellFont_CountTextChars` calls `Sjis_GetCharByteLen`
- `NetCellFont_CountTextCharsAndBytes` calls `Sjis_GetCharByteLen`
- `NetCellFont_BuildTextCharIndex` calls `Sjis_GetCharByteLen`, `sub_10312050`
- `NetCellFont_CopyTextFromIndex` calls `sub_10312050`, `Sjis_GetCharByteLen`
- `NetCellFont_ClearFlag12FromValue` calls `NetCellFont_GetRingHead14`, `NetCellFont_RingStepBack`
- `NetCellFont_RingStepBack` calls nothing directly
- `NetCellFont_GetOptionByte` calls nothing directly
- `NetCellFont_SetOptionByte` calls nothing directly
- `NetCellFont_IsKindEnabledInSettings` calls `NetCellFont_FindKindRecord`, `NetCellFont_MapCode54ToIndex`, `Settings_GetValue`, `TextInputFiles_TestBit64`
- `NetCellFont_NextRingIndex` calls nothing directly
- `NetCellFont_GetRingHead14` calls nothing directly
- `NetCellFont_FindKindRecord` calls nothing directly
- `NetCellFont_MapCode` calls nothing directly
- `ChatLog_AddTableMessage7` calls `TargetMenu_GetMessageFwd`, `ChatLog_AddMessage`
- `ChatLog_AddMessage9Code379` calls `TargetMenu_GetMessageFwd`, `ChatLog_AddMessage`
- `ChatLog_AddMessage7Code37B` calls `TargetMenu_GetMessageFwd`, `ChatLog_AddMessage`
- `ChatLog_AddTextCode379` calls `ChatLog_AddMessage`
- `ChatLog_AddTextCode37B` calls `ChatLog_AddMessage`
- `Font_DrawStringDefault` calls `Font_MeasureString`
- `Font_DrawStringFlags44` calls `Obj_104E1B90::Obj_104E1B90_DrawString`
- `NetCellFont_MapCode1BTo54` calls nothing directly
- `NetCellFont_MapCode54ToIndex` calls nothing directly
- `NetCellFont_CallClearBuffers` calls `NetCellFont_ClearBuffers`
- `NetCellFont_InitTextLayout` calls `Font_GetCharWidthAt`, `NetCellFont_CountTextChars`
- `NetCellFont_ClearBuffers` calls `operator_delete`
- `NetCellFont_GetWord1A` calls nothing directly
- `NetCellFont_GetByte9` calls nothing directly
- `NetCellFont_SetString` calls `NetCellFont_ClearBuffers`, `NetCellFont_CountTextCharsAndBytes`, `Allocator_Generic`, `NetCellFont_BuildTextCharIndex`
- `NetCellFont_GetField20` calls nothing directly
- `NetCellFont_Construct` calls `NetCellFont_ClearWords`
