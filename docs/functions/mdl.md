# mdl

Group: `mdl` (by the file name only). Source: `sdk/tree_src/mdl.cpp`.

25 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `mdl_1026E900` | 0x1026E900 | 248 | yes | - | - | - |
| `Mdl_Register` | 0x1026EBF0 | 189 | yes | - | Registers a model in the next model slot and returns its index. | medium |
| `Mdl_FreeAllSlots` | 0x1026ECC0 | 307 | yes | - | Frees the models of all model slots. | low |
| `Mdl_ClearSlotFlags` | 0x1026EE00 | 66 | yes | - | Clears the flag fields of every slot in the table. | low |
| `Mdl_ChannelRegister` | 0x1026EF00 | 166 | yes | - | Registers a channel for a model and returns its index. | medium |
| `Mdl_FindNthItemB0001` | 0x1026F160 | 73 | yes | - | Returns the n-th item of type 0xB0001 of a model. | low |
| `Mdl_ReleaseEntries` | 0x1026F1B0 | 72 | yes | - | Releases every entry of the 0xC0-byte table and empties it. | medium |
| `Mdl_GetEntryTable` | 0x1026F4F0 | 54 | yes | - | Returns the entry table and its count when the table is populated. | medium |
| `Mdl_QueryEntryFlag` | 0x1026F580 | 62 | yes | - | Stores whether the entry is valid, after a query on its pointer at +0xB4. | low |
| `Mdl_GetEntryWord0` | 0x1026F7B0 | 26 | yes | - | Returns the first dword of a table entry. | low |
| `Mdl_SetChannelActive` | 0x1026F900 | 158 | yes | - | Turns a channel on, off or over, and times how long it was on. | low |
| `Mdl_UpdateEntryFlags` | 0x1026F9A0 | 58 | yes | - | Sets, clears or toggles the flag mask 0x32C in a table entry by mode. | low |
| `Mdl_SetChannelFlag80` | 0x1026F9E0 | 154 | yes | - | Sets or clears a channel's flag 0x80 and its object's value. | low |
| `Mdl_CountSlotsFlag40` | 0x1026FE60 | 49 | yes | - | Counts the model slots with flag 0x40. | medium |
| `Mdl_FindNthFlag40` | 0x1026FEA0 | 73 | yes | - | Finds the nth slot with flag 0x40 set and returns its index. | low |
| `Mdl_CountSlotsFlag80` | 0x1026FEF0 | 50 | yes | - | Counts model slots with flag 0x80 (testing only the first slot). | low |
| `Mdl_FindNthNegative` | 0x1026FF30 | 73 | yes | - | Finds the nth slot whose top flag bit is set and returns its index. | low |
| `Mdl_ComputeSlotBounds` | 0x1026FF80 | 222 | yes | - | Computes the bounding box of a model slot's items. | medium |
| `Mdl_LinkB0001ItemRefs` | 0x102700C0 | 236 | yes | - | Creates references from the 0xB0001 items of one model entry to the 0xB0001 item of another and appends them to the first model. | low |
| `Mdl_SetSlotLock` | 0x102701B0 | 131 | yes | - | Locks or unlocks a model slot with a target and vector. | low |
| `Mdl_GetSlotPtrs` | 0x10270240 | 79 | yes | - | Returns the value and address pointer of a slot. | low |
| `Mdl_GetSlotWord0` | 0x10270290 | 38 | yes | - | Returns the first dword of a slot. | low |
| `Mdl_UpdateSlotFlags` | 0x102703C0 | 76 | yes | - | Sets, clears or toggles mask flags in a slot by mode. | low |
| `Mdl_SetSlotVisible` | 0x10270410 | 161 | yes | - | Shows or hides a model slot's model. | low |
| `Mdl_ReleaseSlotPtr` | 0x10270690 | 81 | yes | - | Frees the slot's pointer at +0xA4 and clears its field at +0x8C. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `mdl_1026E900` calls `Chn_ReleaseIfSet`, `Chn_ReleaseRefs`, `sqFree`, `SqmdModel_Free`, `Mdl_ReleaseSlotPtr`
- `Mdl_Register` calls `SceneCamera_ApplySceneToModel`, `sub_10273810`, `sqDebugPrintf`, `Mdl_UpdateSlotFlags`
- `Mdl_FreeAllSlots` calls `SceneRecord_ClearGroupField4`, `SceneRecord_ClearCurrentField4`, `Mdl_ClearSlotFlags`, `sqDebugPrintf`, `SqmdModel_Free`, `SceneCamera_ApplySceneToModel`, `sub_10273810`
- `Mdl_ClearSlotFlags` calls nothing directly
- `Mdl_ChannelRegister` calls `SqChannelDefaults_InitDefaults`, `Chn_RegisterItem`, `sqDebugPrintf`
- `Mdl_FindNthItemB0001` calls `SqmdModel_GetItemKind2`
- `Mdl_ReleaseEntries` calls `Chn_ReleaseRefs`
- `Mdl_GetEntryTable` calls nothing directly
- `Mdl_QueryEntryFlag` calls `SqItemValue_GetValueByItemKind`
- `Mdl_GetEntryWord0` calls nothing directly
- `Mdl_SetChannelActive` calls `SqDebug_SetByte14`, `SqTimer_GetMicroseconds`
- `Mdl_UpdateEntryFlags` calls nothing directly
- `Mdl_SetChannelFlag80` calls `Mdl_QueryEntryFlag`, `SqItemValue_SetValueByType`, `Mdl_UpdateEntryFlags`
- `Mdl_CountSlotsFlag40` calls nothing directly
- `Mdl_FindNthFlag40` calls nothing directly
- `Mdl_CountSlotsFlag80` calls nothing directly
- `Mdl_FindNthNegative` calls nothing directly
- `Mdl_ComputeSlotBounds` calls `SqBounds_Reset`, `M4fTransform`
- `Mdl_LinkB0001ItemRefs` calls `SqmdModel_GetItemKind2`, `SqSnapRef_CreateRef`, `SqmdModel_AppendPair44`, `SqmdModel_AppendPair68Flag100`
- `Mdl_SetSlotLock` calls `SqVec_CopyVec3`, `SqVec_ZeroDwords`
- `Mdl_GetSlotPtrs` calls nothing directly
- `Mdl_GetSlotWord0` calls nothing directly
- `Mdl_UpdateSlotFlags` calls nothing directly
- `Mdl_SetSlotVisible` calls `sub_10273810`, `Mdl_UpdateSlotFlags`
- `Mdl_ReleaseSlotPtr` calls `sqFree`
