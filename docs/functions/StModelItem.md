# StModelItem

Group: `St` (by the file name only). Source: `sdk/tree_src/StModelItem.cpp`.

Why the file has this name (data/unit_names.json): Activate, CheckFileRefs, SetPositionAndScale; called from StAvatar_ApplyChannels

7 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `StModelItem_Activate` | 0x10252A00 | 63 | yes | - | Activates a game state object and records its index. | low |
| `StModelItem_CheckFileRefs` | 0x10252A40 | 70 | yes | - | Checks the file references of a game state object. | low |
| `StModelItem_SetPositionAndScale` | 0x10252AC0 | 133 | yes | - | Sets the position and scale on the matching sub-objects. | low |
| `StModelItem_SetVec78` | 0x10252B50 | 98 | yes | - | Sets a uniform vector on the matching sub-objects. | low |
| `StModelItem_ClearModelItem` | 0x10252C10 | 21 | yes | - | Clears the model item of a game state object. | low |
| `StModelItem_Refresh` | 0x10252C30 | 76 | yes | - | Refreshes a game state object's sub-object and updates its flag. | low |
| `StModelItem_Init` | 0x10252C80 | 53 | yes | - | Initialises a game state object and its opcode system. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `StModelItem_Activate` calls `Mdl_Register`, `Mdl_UpdateSlotFlags`
- `StModelItem_CheckFileRefs` calls `TextInputFiles_FileMngFindFileNumKind2`
- `StModelItem_SetPositionAndScale` calls `SqmdModel_GetItemKind2`, `SqVec_SetXyz`, `SqQuat_QuatFromEuler`
- `StModelItem_SetVec78` calls `SqmdModel_GetItemKind2`, `SqVec_SetXyz`
- `StModelItem_ClearModelItem` calls `StModelItemClear`
- `StModelItem_Refresh` calls `Mdl_SetSlotVisible`, `Mdl_GetSlotWord0`
- `StModelItem_Init` calls `SqopSystem_Init`
