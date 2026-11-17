# YkFurniture

Group: `Yk` (by the file name only). Source: `sdk/tree_src/YkFurniture.cpp`.

5 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Yk_MapCodeOffset` | 0x101CCE00 | 73 | yes | - | Maps a code in ranges to a fixed offset, or 0 for codes in a gap. | low |
| `YkFurniture_GetEntry1037D7B4` | 0x101CCE50 | 13 | yes | - | Returns the address of the index-th 16-byte entry of the table at 0x1037D7B4. | low |
| `YkFurniture_GetTablePtrBy121` | 0x101CCE90 | 34 | yes | - | Returns one of two pointers of the index-th table pair, chosen by whether a short of g_C_106631D4 is 0x121. | low |
| `YkFurniture_RotateStepAroundOther` | 0x101CD2D0 | 198 | yes | - | Steps the object's turn counter at +0x20 (0 to 3, downward) and recomputes its two coordinates relative to another object's. | low |
| `YkFurniture::Destructor` | 0x101CD900 | 144 | yes | - | Destroys a furniture object and releases the actors and objects it holds. (reviewed as sub_101CD900) | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Yk_MapCodeOffset` calls nothing directly
- `YkFurniture_GetEntry1037D7B4` calls nothing directly
- `YkFurniture_GetTablePtrBy121` calls nothing directly
- `YkFurniture_RotateStepAroundOther` calls `PlantMenu_GetField14`, `PlantMenu_GetField1C`, `PlantMenu_GetTurnedByte4`, `PlantMenu_GetTurnedByte5`, `PlantMenu_SetQuarterTurn`, `sub_101CDD90`
- `YkFurniture::Destructor` calls `PlantMenu_GetValueAt5A`, `FurnitureRelease_ReleaseSlot`, `PlantMenu_GetValueAt54`, `XiFurnitureActor::Release`, `PlantMenu_GetValueAt56`, `Acter_DestroyAndClearSlot`
