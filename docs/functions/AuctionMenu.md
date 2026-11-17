# AuctionMenu

Group: `Auction` (by the file name only). Source: `sdk/tree_src/AuctionMenu.cpp`.

Why the file has this name (data/unit_names.json): the string "menu    auc1    " and calls into the menu code (Unit1012AC80_GetMessageFwd): read from the code

6 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `AuctionMenu_ResetAndFillHeader` | 0x100A28E0 | 201 | yes | - | Resets the object's state and writes the header for the record at +0x48 into its buffer at +0x70. | low |
| `AuctionMenu_WriteHeader` | 0x100A2B70 | 100 | yes | - | Writes the object's 32-byte header into the given block, with the length capped at 0xEC. | low |
| `AuctionMenu_InitRecord` | 0x100A2FD0 | 107 | yes | - | Initialises a record from three byte values and attaches a zeroed buffer to it. | low |
| `AuctionMenu_CreateTaskOnce` | 0x100A3040 | 150 | yes | - | Creates the menu's task and its record once, and returns whether it was made now. | low |
| `AuctionMenu_GetSceneStateCode` | 0x100A30E0 | 61 | yes | - | Returns a code from 1 to 4 for the scene state. | low |
| `AuctionMenu_ResetRecords` | 0x100A3CD0 | 38 | yes | - | Clears the fields of each record in the table and two globals. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `AuctionMenu_ResetAndFillHeader` calls `AuctionMenu_WriteHeader`
- `AuctionMenu_WriteHeader` calls nothing directly
- `AuctionMenu_InitRecord` calls nothing directly
- `AuctionMenu_CreateTaskOnce` calls `AuctionMenu_GetSceneStateCode`, `AuctionMenu_InitRecord`, `Mem_AllocFromArea`, `CMoTask::ResetFields`, `Acter_ConstructTask1032D6D4`, `AuctionMenu_ResetAndFillHeader`
- `AuctionMenu_GetSceneStateCode` calls nothing directly
- `AuctionMenu_ResetRecords` calls nothing directly
