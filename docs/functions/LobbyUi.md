# LobbyUi

Group: `Lobby` (by the file name only). Source: `sdk/tree_src/LobbyUi.cpp`.

Why the file has this name (data/unit_names.json): Ui_KeyPrompt_Init, KeyPrompt_Construct, the menus "lobbywin", "netwait", "netbar", "chmkname", "lobyhelp" (an address range between two evidenced source files, holding several of the original files: named for its main contents)

17 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `LobbyUi_ConstructTable2` | 0x102380A0 | 129 | yes | - | Constructs a game system object with its table 2. | low |
| `LobbyUi_ConstructNamed` | 0x102388C0 | 73 | yes | - | Constructs a named game system object. | low |
| `LobbyUi_ConstructTable11` | 0x10238B30 | 135 | yes | - | Constructs a game system object with its table 11. | low |
| `KeyPrompt_Construct` | 0x10239170 | 47 | yes | - | Constructs a key prompt object. | low |
| `LobbyUi_ResetAndPlaceWindow` | 0x102391D0 | 99 | yes | - | Resets the lobby window's state and places it at the position from 0x103879D8. | low |
| `LobbyUi_StepScreenSwitch` | 0x10239240 | 482 | yes | 7 | Steps the lobby's change of screen: runs one schedule, waits, swaps the screen resource and sounds, then runs another schedule. | low |
| `Ui_KeyPrompt_Init` | 0x10239460 | 37 | yes | - | - | - |
| `LobbyUi_GetGlobalDword` | 0x10239490 | 6 | yes | - | Returns the game system global at DAT_10668FE4. | low |
| `Ui_DrawKeyPrompt` | 0x102394A0 | 548 | yes | 0 | - | - |
| `LobbyUi_ForwardFlag1` | 0x1023BF20 | 16 | yes | - | Forwards its argument to FUN_1023be10 with flag 1. | low |
| `LobbyUi_StoreTextIfIdle` | 0x1023C140 | 51 | yes | - | Copies a text into the object's 0x230-byte buffer and points 0x10668FF4 at it, unless the object's +0x14 is already set. | low |
| `LobbyUi_UpdateSlotNameAndDate` | 0x1023C540 | 483 | yes | - | Reads the selected slot's FFXI<n>.DAT text and fills in its name and formatted date, or the NO DATA text. | medium |
| `LobbyUi_ConstructBase` | 0x1023D610 | 41 | yes | - | Constructs a game system base object. | low |
| `LobbyUi_WaitForState1` | 0x1023E4B0 | 50 | yes | - | Waits until a game system reaches state 1. | low |
| `CIwHnList_Constructor` | 0x1023E830 | 149 | yes | - | - | - |
| `LobbyUi_ConstructTable3` | 0x1023F890 | 129 | yes | - | Constructs a game system object with its table 3. | low |
| `LobbyUi_HandleSelectInput` | 0x10241800 | 225 | yes | - | Handles the lobby list's select key, and selects the entry under the cursor when the cursor is in its mode 2. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `LobbyUi_ConstructTable2` calls `NetCellFont_ClearWords`, `Allocator_Generic`, `TextInputFiles_CtorVt10337C90`
- `LobbyUi_ConstructNamed` calls `NetCellFont_ClearWords`
- `LobbyUi_ConstructTable11` calls `NetCellFont_ClearWords`, `Allocator_Generic`, `TextInputFiles_CtorVt10337C90`
- `KeyPrompt_Construct` calls `NetCellFont_ClearWords`, `Ui_KeyPrompt_Init`
- `LobbyUi_ResetAndPlaceWindow` calls `sub_101602F0`, `sub_10119110`
- `LobbyUi_StepScreenSwitch` calls `CMoResource::ReleaseChain`, `ResHandle_FreeIfUnreferenced`, `sub_100731B0`, `sub_10071E90`, `ResourceHandle_IsResident`, `AfterimageTask_Execute`, `LobbyScreen_ReleaseResource`, `LobbyScreen_LoadResourceOnce`, `SoundElem_ClearGlobal10463930`, `SoundElem_Release10463928AndSetScaled`
- `Ui_KeyPrompt_Init` calls nothing directly
- `LobbyUi_GetGlobalDword` calls nothing directly
- `Ui_DrawKeyPrompt` calls `CMoResource::FindByTypeAndId`, `ShapeMng_FindShape`, `sub_10160250`, `sub_1011FC80`, `MenuMng_GetOffsetX`, `MenuMng_GetOffsetY`, `sub_10311C2C`
- `LobbyUi_ForwardFlag1` calls `sub_1023BE10`
- `LobbyUi_StoreTextIfIdle` calls `sub_10312050`
- `LobbyUi_UpdateSlotNameAndDate` calls `sub_103108E9`, `sub_103108F4`, `sub_10311FF1`, `TextInputFiles_FileMngReadText`, `sub_10312872`, `YkCommon_FormatDateTime`, `sub_10312050`
- `LobbyUi_ConstructBase` calls `Yk_InitBase`
- `LobbyUi_WaitForState1` calls `LobbyThread_IsSystemState1`
- `CIwHnList_Constructor` calls `NetCellFont_ClearWords`, `YkCommon_InitFourSlots`
- `LobbyUi_ConstructTable3` calls `NetCellFont_ClearWords`, `Allocator_Generic`, `TextInputFiles_CtorVt10337C90`
- `LobbyUi_HandleSelectInput` calls `NetCellFont_TestCommand36CF60`, `NetCellFont_IsCursorMode2NoEvent`, `NetCellFont_HitTest`
