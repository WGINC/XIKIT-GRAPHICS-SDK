# MyRoom

Group: `My` (by the file name only). Source: `sdk/tree_src/MyRoom.cpp`.

Why the file has this name (data/unit_names.json): YkMyroom::ChangeMode / ReleaseObject38, the menus "roomlist", "bankmenu", "mogdoor"

16 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `MyRoom_GetObjectAtIndex` | 0x101D30F0 | 38 | yes | - | Returns the object of the actor stored at this object's index. | low |
| `MyRoom_SelectFurniture` | 0x101D3910 | 138 | yes | - | Puts every item of the room's two lists in one state and the chosen item in another, and remembers the chosen item's id. | low |
| `MyRoom_CallAllFurniture101CEA80` | 0x101D39A0 | 49 | yes | - | Calls the function at 0x101CEA80 with the argument on every item of the room's two lists. | low |
| `MyRoom_ReleaseTable` | 0x101D3DC0 | 68 | yes | - | Releases every actor held in a table. | low |
| `MyRoom_GetFirstFurnitureId` | 0x101D3E70 | 62 | yes | - | Returns the id of the first item in the room's lists, or 0. | low |
| `MyRoom_CopyList6To818` | 0x101D3F60 | 72 | yes | - | Copies the global list number 6 into the room object and resets its position in it. | low |
| `MyRoom_DoNothing` | 0x101D3FB0 | 1 | yes | - | Does nothing. | low |
| `MyRoom_Draw` | 0x101D3FC0 | 186 | yes | 2 | Draws a marker at an object's projected screen position. | low |
| `MyRoom_BeginMode` | 0x101D55D0 | 176 | yes | - | Starts the room's mode 0 or 1: sets its timer to 0xB4 and its phase, and for mode 0 starts the acter's "main" schedule. | low |
| `MyRoom_Update` | 0x101D5680 | 19 | yes | 3 | Draws the marker while the state is active. | low |
| `MyRoom_GetFurnitureAtCell` | 0x101D5E00 | 56 | yes | - | Returns the room item placed at a grid cell. | low |
| `MyRoom_Refresh101CEC50` | 0x101D5E40 | 8 | yes | - | Runs the function at 0x101CEC50 on the room's grid. | low |
| `MyRoom_PlaceItemThenRefresh` | 0x101D5EA0 | 27 | yes | - | Passes an item to the room's grid (0x101CEEF0) and refreshes the grid. | low |
| `MyRoom_Is104DFD98Bit40DB1x10Clear` | 0x101D5FE0 | 27 | yes | - | Returns whether the object at 0x104DFD98 exists and has bit 0x10 of its byte at +0x40DB1 clear. | low |
| `MyRoom_IsWord40D82Zero` | 0x101D6020 | 11 | yes | - | Returns whether the word at +0x40D82 of the object at 0x104DFD98 is zero. | low |
| `MyRoom_StartWithCallbackOnce` | 0x101D6C90 | 43 | yes | - | Starts the object with the given callback unless it already has one. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `MyRoom_GetObjectAtIndex` calls nothing directly
- `MyRoom_SelectFurniture` calls `PlantMenu_SetState`, `PlantMenu_SetWord28Recursive`, `PlantMenu_GetWord58`
- `MyRoom_CallAllFurniture101CEA80` calls `PlantMenu_CallSlot12OnObjects`
- `MyRoom_ReleaseTable` calls `YkFurniture::Destructor`, `thunk_Mem_FreeBlockMergeNeighbours_as_v0`
- `MyRoom_GetFirstFurnitureId` calls `PlantMenu_GetWord58`
- `MyRoom_CopyList6To818` calls `YkCommon_GetIndexed`
- `MyRoom_DoNothing` calls nothing directly
- `MyRoom_Draw` calls `Gfx_ProjectWorldToScreen`, `Camera_GetFrameScale`, `game_10311C2C`, `game_1011FB60`
- `MyRoom_BeginMode` calls `MyRoom_IsWord40D82Zero`, `Acter_SetFlag8000OfFound`, `game_100A1860`, `Acter_FindFirstMatchingKinds`, `AfterimageTask_IsResourceMoving`, `AfterimageTask_Execute`
- `MyRoom_Update` calls `MyRoom_GetObjectAtIndex`, `MyRoom_Draw`
- `MyRoom_GetFurnitureAtCell` calls `PlantMenu_GetGridCellByte`
- `MyRoom_Refresh101CEC50` calls `game_101CEC50`
- `MyRoom_PlaceItemThenRefresh` calls `PlantMenu_ClearItemFromGrid`, `MyRoom_Refresh101CEC50`
- `MyRoom_Is104DFD98Bit40DB1x10Clear` calls nothing directly
- `MyRoom_IsWord40D82Zero` calls `NetCellFont_GetWord40D82`
- `MyRoom_StartWithCallbackOnce` calls `game_101D6CC0`
