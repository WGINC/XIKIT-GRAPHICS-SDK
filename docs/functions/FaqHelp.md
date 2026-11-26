# FaqHelp

Group: `Faq` (by the file name only). Source: `sdk/tree_src/FaqHelp.cpp`.

Why the file has this name (data/unit_names.json): the files kb_faq.pib, kb_faq_idx.pib, kb_faq.pfb, the menus "faqmain", "faqsub", the string SELLANG (an address range between two evidenced source files, holding several of the original files: named for its main contents)

29 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `FaqHelp_CtorVt1033BCF8` | 0x10216570 | 61 | yes | - | Constructs the object with vtable 0x1033BCF8. | low |
| `FaqHelp_CtorVt1033BD58` | 0x102175C0 | 229 | yes | - | Constructs the object with vtable 0x1033BD58 and its 37 entries. | low |
| `FaqHelp_ClearWords0To0A` | 0x1021B330 | 31 | yes | - | Zeroes six words and the byte at +0xC. | low |
| `FaqHelp_Create` | 0x1021BB90 | 58 | no | - | Creates the slot system object once. | low |
| `FaqHelp_SetVtable1033BDA0` | 0x1021BC20 | 9 | yes | - | Sets the record's vtable to 0x1033BDA0. | low |
| `FaqHelp_CopyRecordCtor` | 0x1021BC30 | 69 | yes | - | Constructs an object holding a copy of a 24-byte record. | low |
| `FaqHelp_ReturnTrue` | 0x1021BCB0 | 3 | yes | - | Returns true. | low |
| `FaqHelp_SaveToDat` | 0x1021BDB0 | 147 | yes | - | Saves the slot assignments to a data file. | medium |
| `FaqHelp_LoadFromDat` | 0x1021BF60 | 172 | yes | - | Loads the slot assignments from a data file. | medium |
| `FaqHelp_ResetEntries` | 0x1021C010 | 46 | yes | - | Resets the 0x51 slot entries. | low |
| `FaqHelp_Construct` | 0x1021C070 | 141 | yes | - | Constructs the slot system and loads its saved data. | low |
| `FaqHelp_SaveAndRelease` | 0x1021C100 | 92 | yes | - | Saves the slot data and frees its buffers. | medium |
| `FaqHelp_CanUpdate` | 0x1021C160 | 80 | yes | - | Tests the input state before a slot update. | low |
| `FaqHelp_IsSpecialKey` | 0x1021C1B0 | 84 | yes | - | Tests whether a key is one of the nine reserved slot keys. | low |
| `FaqHelp_AssignItem` | 0x1021C210 | 203 | yes | - | Assigns an item to a slot and updates the item counts. | low |
| `FaqHelp_ClearAndAssign` | 0x1021C2E0 | 110 | yes | - | Clears a slot and assigns a new item to it. | low |
| `FaqHelp_ResetSlot` | 0x1021C350 | 42 | yes | - | Resets one slot entry. | low |
| `FaqHelp_SyncSlots` | 0x1021C380 | 309 | no | - | Brings the 81 slots up to date with the item state when it has changed. | low |
| `FaqHelp_Update` | 0x1021C4C0 | 230 | yes | - | Updates the slot states each frame. | low |
| `FaqHelp_AppendEntry` | 0x1021C5B0 | 207 | yes | - | Appends a record to one of the four slot lists. | low |
| `FaqHelp_RemoveByKey` | 0x1021C680 | 284 | yes | - | Removes the record with the given key from the slot lists. | low |
| `FaqHelp_RebuildWithGlobalFlag` | 0x1021C7C0 | 29 | yes | - | Rebuilds a slot list with the global flag at 0x10666E74. | low |
| `FaqHelp_Rebuild` | 0x1021C7E0 | 613 | yes | - | Rebuilds one slot list from the entries that match a mask. | low |
| `FaqHelp_GetSlotForEntry` | 0x1021CB80 | 57 | yes | - | Returns the slot record that the argument's entry in the current page (+0xC, 0x51 entries a page) refers to. | low |
| `FaqHelp_Is14Not198C8` | 0x1021CCB0 | 27 | yes | - | Returns whether the window's value at +0x14 differs from the one at +0x198C8 of the object at 0x104DFD98. | low |
| `FaqHelp_ResetEntryCtor` | 0x1021D250 | 12 | yes | - | Constructs a slot entry empty. | low |
| `FaqHelp_Reset` | 0x1021D270 | 22 | yes | - | Resets a slot entry to empty. | low |
| `FaqHelp_LoadFromId` | 0x1021D2D0 | 175 | yes | - | Loads a slot entry from an item id. | low |
| `FaqHelp_SetId` | 0x1021D380 | 40 | yes | - | Sets a slot entry's item id when it changes. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `FaqHelp_CtorVt1033BCF8` calls `NetCellFont_ClearWords`
- `FaqHelp_CtorVt1033BD58` calls `NetCellFont_ClearWords`, `FaqHelp_ClearWords0To0A`
- `FaqHelp_ClearWords0To0A` calls nothing directly
- `FaqHelp_Create` calls `Allocator_Generic`, `FaqHelp_CtorVt1033BD58`, `FaqHelp_CtorVt1033BCF8`
- `FaqHelp_SetVtable1033BDA0` calls nothing directly
- `FaqHelp_CopyRecordCtor` calls `FaqHelp_SetVtable1033BDA0`
- `FaqHelp_ReturnTrue` calls nothing directly
- `FaqHelp_SaveToDat` calls `TextInputFiles_DatEntryCtor`, `XI_CRYPT_101B9A10 (left out)`, `TextInputFiles_ClearVtable`
- `FaqHelp_LoadFromDat` calls `TextInputFiles_DatEntryCtor`, `XI_CRYPT_101B9BC0 (left out)`, `TextInputFiles_ClearVtable`
- `FaqHelp_ResetEntries` calls `FaqHelp_ResetEntryCtor`
- `FaqHelp_Construct` calls `game_1021BE50`, `FaqHelp_LoadFromDat`
- `FaqHelp_SaveAndRelease` calls `game_1021BCC0`, `FaqHelp_SaveToDat`, `operator_delete`
- `FaqHelp_CanUpdate` calls `NetCellFont_GetFlags`, `FaqHelp_IsSpecialKey`, `NetCellFont_ApplyStatusText`
- `FaqHelp_IsSpecialKey` calls nothing directly
- `FaqHelp_AssignItem` calls `game_1015BC40`, `FaqHelp_Reset`, `FaqHelp_RemoveByKey`, `FaqHelp_AppendEntry`, `FaqHelp_SetId`
- `FaqHelp_ClearAndAssign` calls `FaqHelp_Reset`, `FaqHelp_RemoveByKey`, `FaqHelp_AppendEntry`, `FaqHelp_SetId`
- `FaqHelp_ResetSlot` calls `FaqHelp_Reset`, `FaqHelp_RemoveByKey`
- `FaqHelp_SyncSlots` calls `NetCellFont_GetSlotPtr`, `NetCellFont_FindOrRemove`, `operator_delete`, `Allocator_Generic`, `FaqHelp_CopyRecordCtor`, `NetCellFont_RemoveRecord`, `FaqHelp_ClearAndAssign`, `FaqHelp_AssignItem`, `FaqHelp_ResetSlot`
- `FaqHelp_Update` calls `FaqHelp_CanUpdate`, `FaqHelp_SyncSlots`, `FaqHelp_IsSpecialKey`, `NetCellFont_ApplyStatusText`, `NetCellFont_GetSlotPtr`, `FaqHelp_ReturnTrue`, `NetCellFont_CountFreeEntries`, `FaqHelp_RebuildWithGlobalFlag`
- `FaqHelp_AppendEntry` calls nothing directly
- `FaqHelp_RemoveByKey` calls nothing directly
- `FaqHelp_RebuildWithGlobalFlag` calls `FaqHelp_Rebuild`
- `FaqHelp_Rebuild` calls `game_103156B3`, `XI_PACKET_100EBF40 (left out)`
- `FaqHelp_GetSlotForEntry` calls `NetCellFont_GetSlotPtr`
- `FaqHelp_Is14Not198C8` calls nothing directly
- `FaqHelp_ResetEntryCtor` calls `FaqHelp_Reset`
- `FaqHelp_Reset` calls nothing directly
- `FaqHelp_LoadFromId` calls `FaqHelp_Reset`, `game_1015BC40`
- `FaqHelp_SetId` calls `FaqHelp_LoadFromId`
