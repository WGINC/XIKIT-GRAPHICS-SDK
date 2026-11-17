# PlantMenu

Group: `Plant` (by the file name only). Source: `sdk/tree_src/PlantMenu.cpp`.

Why the file has this name (data/unit_names.json): the menus "plnt1" to "plnt6"; called from YkFurniture and YkMyroom::ChangeMode: read from the code

19 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `PlantMenu_GetWord58` | 0x101CD990 | 5 | yes | - | Returns the acter index stored at +0x58. | low |
| `PlantMenu_GetValueAt58` | 0x101CD9A0 | 35 | yes | - | Returns the +0xA0 object of the acter whose index is at +0x58, or 0. | medium |
| `PlantMenu_GetValueAt54` | 0x101CD9D0 | 35 | yes | - | Returns the value at offset 0xA0 of the acter selected by the index at offset 0x54. | low |
| `PlantMenu_GetValueAt56` | 0x101CDA00 | 35 | yes | - | Returns the value at offset 0xA0 of the acter selected by the index at offset 0x56. | low |
| `PlantMenu_GetValueAt5A` | 0x101CDA30 | 35 | yes | - | Returns the value at offset 0xA0 of the acter selected by the index at offset 0x5A. | low |
| `PlantMenu_SetQuarterTurn` | 0x101CDF50 | 400 | yes | - | Turns the item to one of four quarter turns, with its acters, attached object and child items. | medium |
| `PlantMenu_SetState` | 0x101CE1E0 | 366 | yes | - | Puts a room item into one of five states, placing its acters and updating the room grid. | low |
| `PlantMenu_SetWord28Recursive` | 0x101CE9E0 | 77 | yes | - | Sets the item's words at +0x24..+0x28 (the last from the argument), and those of its child items. | low |
| `PlantMenu_AddChild` | 0x101CEA30 | 51 | yes | - | Adds an item to this item's list of children, at most 32 and without repeats. | medium |
| `PlantMenu_CallSlot12OnObjects` | 0x101CEA80 | 48 | yes | - | Calls virtual slot 12 with the argument on the item's acter object and its attached object. | low |
| `PlantMenu_GetField14` | 0x101CEAC0 | 4 | yes | - | Returns the item's field at +0x14. | low |
| `PlantMenu_GetField18` | 0x101CEAD0 | 4 | yes | - | Returns the item's field at +0x18. | low |
| `PlantMenu_GetField1C` | 0x101CEAE0 | 4 | yes | - | Returns the item's field at +0x1C. | low |
| `PlantMenu_GetTurnedByte4` | 0x101CEAF0 | 50 | yes | - | Returns byte 4 or 5 of the item's record, swapped by an odd quarter turn. | low |
| `PlantMenu_GetTurnedByte5` | 0x101CEB40 | 50 | yes | - | Returns byte 5 or 4 of the item's record, swapped by an odd quarter turn. | low |
| `PlantMenu_GetDefFlagBit0` | 0x101CEBE0 | 12 | yes | - | Returns bit 0 of the item record's flag byte. | low |
| `PlantMenu_GetDefFlagBit1` | 0x101CEBF0 | 14 | yes | - | Returns bit 1 of the item record's flag byte. | low |
| `PlantMenu_GetGridCellByte` | 0x101CECB0 | 34 | yes | - | Returns the byte of the room grid at a cell (0x1A rows of 8). | low |
| `PlantMenu_ClearItemFromGrid` | 0x101CEEF0 | 218 | yes | - | Removes an item from the room grid: every cell it occupied is cleared and marked free. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `PlantMenu_GetWord58` calls nothing directly
- `PlantMenu_GetValueAt58` calls nothing directly
- `PlantMenu_GetValueAt54` calls nothing directly
- `PlantMenu_GetValueAt56` calls nothing directly
- `PlantMenu_GetValueAt5A` calls nothing directly
- `PlantMenu_SetQuarterTurn` calls `PlantMenu_GetDefFlagBit1`, `YkFurniture_RotateStepAroundOther`, `PlantMenu_GetValueAt5A`, `PlantMenu_GetValueAt54`, `ModelActorPosition_SetAnglesWrapped`, `PlantMenu_GetValueAt56`, `CXiDancerActor_SetAnglesWrapped`, `Vec4_Copy`
- `PlantMenu_SetState` calls `PlantMenu_GetValueAt5A`, `PlantMenu_GetValueAt58`, `CXiDancerActor::SetPosition`, `PlantMenu_SetQuarterTurn`, `PlantMenu_GetDefFlagBit1`, `MyRoom_PlaceItemThenRefresh`
- `PlantMenu_SetWord28Recursive` calls `PlantMenu_GetDefFlagBit1`
- `PlantMenu_AddChild` calls nothing directly
- `PlantMenu_CallSlot12OnObjects` calls `PlantMenu_GetValueAt58`
- `PlantMenu_GetField14` calls nothing directly
- `PlantMenu_GetField18` calls nothing directly
- `PlantMenu_GetField1C` calls nothing directly
- `PlantMenu_GetTurnedByte4` calls nothing directly
- `PlantMenu_GetTurnedByte5` calls nothing directly
- `PlantMenu_GetDefFlagBit0` calls nothing directly
- `PlantMenu_GetDefFlagBit1` calls nothing directly
- `PlantMenu_GetGridCellByte` calls nothing directly
- `PlantMenu_ClearItemFromGrid` calls `PlantMenu_GetDefFlagBit0`, `PlantMenu_GetField18`
