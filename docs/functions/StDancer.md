# StDancer

Group: `St` (by the file name only). Source: `sdk/tree_src/StDancer.cpp`.

Why the file has this name (data/unit_names.json): Dancer_InitDevice / WorldEnd, StAvatar_SetLevel / SetMode, the dancer memory globals

18 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `StAvatar_UpdateFlag2` | 0x10251320 | 78 | yes | - | Updates the avatar's flag from its sub-object's state. | low |
| `StAvatar_GetValue2B` | 0x10251370 | 73 | yes | - | Returns a value from the avatar's table entry at offset 0x2B. | low |
| `StAvatar_GetValue2A` | 0x102513C0 | 73 | yes | - | Returns a value from the avatar's table entry at offset 0x2A. | low |
| `StAvatar_ComputeRatioValue` | 0x10251410 | 132 | yes | - | Computes a ratio from the avatar's field and its sub-object's range. | low |
| `StDancer_Init` | 0x102514C0 | 35 | yes | - | Initialises the avatar state block. | low |
| `StDancer_Update` | 0x10251500 | 226 | yes | 1 | - | - |
| `Dancer_WorldEnd` | 0x102515F0 | 34 | yes | 2 | - | - |
| `StAvatar_SetActive` | 0x10251620 | 137 | yes | 1 | Activates or deactivates the avatar, clearing its state when it is turned off. | low |
| `StAvatar_SetStateTeardown` | 0x102516B0 | 51 | yes | 7 | Sets the avatar's state and tears it down when it is active. | low |
| `StAvatar_SetMode` | 0x10251720 | 41 | yes | - | Sets the avatar's mode, passing it to the avatar when it is active. | medium |
| `StAvatar_SetLevel` | 0x10251750 | 41 | yes | - | Sets the avatar's level, applying it to the avatar when it is active. | low |
| `Dancer_SetStateIfIdle` | 0x10251780 | 38 | yes | - | Sets the state at +0x1C when it is 0 or 1 and forwards it. | low |
| `StDancer_SetJobLock` | 0x10251890 | 54 | yes | - | - | - |
| `StAvatar_ResetOrSetFlag2` | 0x10251920 | 34 | yes | - | Resets the avatar's state or sets its second flag bit. | low |
| `StAvatar_IsFlag20` | 0x10251960 | 7 | yes | - | Returns bit 0x20 of the avatar's flag word. | low |
| `Dancer_InitDevice` | 0x10251A80 | 597 | yes | 0 | - | - |
| `StAvatar_ReleaseMemory` | 0x10251CE0 | 87 | yes | - | Releases the avatar's memory blocks and clears their globals. | medium |
| `StAvatar_InitSlotRecord` | 0x102524B0 | 43 | yes | - | Initialises a 9-dword slot record. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `StAvatar_UpdateFlag2` calls `Mdl_SetChannelActive`, `Mdl_GetEntryWord0`
- `StAvatar_GetValue2B` calls `Mdl_GetEntryTable`
- `StAvatar_GetValue2A` calls `Mdl_GetEntryTable`
- `StAvatar_ComputeRatioValue` calls `Mdl_GetEntryTable`, `Chn_GetSubIndex`, `game_1027D110`
- `StDancer_Init` calls nothing directly
- `StDancer_Update` calls `StAvatar_Update`, `Dancer_InitDevice`, `ErrorReport_NoOpVarargsA`, `StAvatarInit`, `StAvatar_SetStateTeardown`, `StAvatar_SetMode`, `StAvatar_SetLevel`, `Dancer_SetStateIfIdle`, `StDancer_SetJobLock`, `StAvatar_SetFlagBit`
- `Dancer_WorldEnd` calls `StAvatar_RenderIfEnabled`
- `StAvatar_SetActive` calls `StAvatar_ResetOrSetFlag2`, `StAvatarFini`, `StAvatar_ReleaseMemory`
- `StAvatar_SetStateTeardown` calls `StAvatar_Teardown`
- `StAvatar_SetMode` calls `StAvatar_StoreMode`
- `StAvatar_SetLevel` calls `StAvatar_Start`
- `Dancer_SetStateIfIdle` calls `StAvatar_SetField10`
- `StDancer_SetJobLock` calls `StAvatar_SetLock`
- `StAvatar_ResetOrSetFlag2` calls nothing directly
- `StAvatar_IsFlag20` calls nothing directly
- `Dancer_InitDevice` calls `Mem_AllocObject`, `ErrorReport_NoOpVarargsA`, `ErrorReport_NoOpVarargsB`, `sqMemInit`, `sqMemPoolRegister`, `sqgxContext_Create`, `sqgxTextureAdd`, `sqgxTextureAddZ`, `sqgxTextureClear`, `sqgxTextureDraw`
- `StAvatar_ReleaseMemory` calls `SqgxContext_ResetHandles`, `SqObject_Release`, `Mem_FreeObject`
- `StAvatar_InitSlotRecord` calls nothing directly
