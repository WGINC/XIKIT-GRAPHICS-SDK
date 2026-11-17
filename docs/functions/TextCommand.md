# TextCommand

Group: `Text` (by the file name only). Source: `sdk/tree_src/TextCommand.cpp`.

Why the file has this name (data/unit_names.json): Command_RunLine, SeekIdByString, the commands "/ver", "echo", Actor_FindByName / GetObjectByName, ActorHandle_*

25 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `TextCommand_ParseOnOff` | 0x10079170 | 85 | yes | - | Returns 1 for the argument "on", 2 for "off", and 0 for anything else. | high |
| `TextCommand_ParseNumber` | 0x10079A00 | 247 | yes | - | Parses an integer from a string in decimal, hexadecimal or binary form. | medium |
| `SeekIdByString` | 0x1007A1C0 | 630 | yes | - | - | - |
| `Actor_FindInRange` | 0x1007A440 | 120 | yes | - | Returns the first actor in an index range that passes a test. | medium |
| `Actor_FindByName` | 0x1007A4C0 | 308 | yes | - | Finds an actor by name within an index range. | medium |
| `TextCommand_PacketForIdPairKind04` | 0x1007A9A0 | 42 | yes | - | Text command: hands the current id pair to the packet layer with kind 4. | low |
| `TextCommand_PacketForIdPairKind12` | 0x1007AA80 | 42 | yes | - | Text command: hands the current id pair to the packet layer with kind 0x12. | low |
| `TextCommand_PacketForIdPairKind1A` | 0x1007BB90 | 113 | yes | - | Text command: hands the current id pair and a menu entry index to the packet layer with kind 0x1A. | low |
| `TextCommand_TargetActionToPacket` | 0x1007BF30 | 666 | yes | - | Text command: checks a target action and hands it to the packet layer. | low |
| `UI_QuestCommand` | 0x1007D240 | 40 | yes | - | - | - |
| `TextCommand_CheckThenPostUiRequest0E` | 0x1007E490 | 194 | yes | - | Text command: runs its checks against the game time and state, then posts UI request 0xE. | low |
| `TextCommand_ChangeMyroomMode2` | 0x1007E8D0 | 217 | yes | - | A text command that, when its checks pass, switches the room object to mode 2 (YkMyroom::ChangeMode), or prints a chat message why not. | low |
| `TextCommand_Run100A3040` | 0x10080340 | 10 | yes | - | A text command that runs the function at 0x100A3040. | low |
| `Actor_GetObjectByName` | 0x10080C70 | 46 | yes | - | Returns the object of the actor with the given name. | low |
| `TextCommand_GetWord1047D3FC` | 0x10080D00 | 7 | yes | - | Returns the global word at 0x1047D3FC. | low |
| `TextCommand_IsIdNotInTable10357BB8` | 0x10080D20 | 102 | yes | - | Tells whether a command id is absent from a fixed table. | low |
| `Actor_IsInTable` | 0x10080D90 | 46 | yes | - | Tests whether an actor's key is in the table at DAT_10357BDC. | low |
| `Command_RunLine` | 0x10080DC0 | 1105 | yes | - | Runs a typed chat or slash-command line. | medium |
| `TextCommand_CheckCommandAllowed` | 0x10081230 | 524 | yes | - | Checks whether an input command may run now, showing a message when not. | low |
| `TextCommand_SetFlag1047D498` | 0x10081440 | 10 | yes | - | Sets the global flag byte at 0x1047D498. | low |
| `TextCommand_TestBit1047D499` | 0x10081480 | 21 | yes | - | Tests one bit of the global byte at 0x1047D499. | low |
| `ActorHandle_Constructor` | 0x100814A0 | 32 | yes | - | - | - |
| `ActorHandle_Destructor` | 0x100814E0 | 7 | yes | - | - | - |
| `ActorHandle_SetFields` | 0x10081530 | 17 | yes | - | Sets the two fields of an actor handle. | low |
| `ActorHandle_ResolveObject` | 0x10081600 | 180 | yes | - | Resolves an actor handle to its actor's object, re-finding the actor when needed. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `TextCommand_ParseOnOff` calls nothing directly
- `TextCommand_ParseNumber` calls nothing directly
- `SeekIdByString` calls `Target_GetActorPtr`, `Acter_CopyNameToBuffer`, `NetCellFont_GetIdPair`, `Acter_FindMatchingActor`, `YkCommon_GetCC4F0ActorByIndexAt1FA`, `NetCellFont_GetActiveBlock3AE98`, `ActerBuff_FindNearest`, `YkCommon_GetCC4F0ActorAt2A0`, `sub_10312050`, `TaskAndTextArgs_MapNameLetters`, `Actor_FindByName`, `TextCommand_ParseNumber`, `Entry_ValidateKey`, `Actor_FindInRange`, `Acter_GetCurrentIdRef`, `Acter_ClearCurrentName`
- `Actor_FindInRange` calls `Actor_FindByField78Entry`
- `Actor_FindByName` calls `Actor_FindByField2a4`, `Actor_FindByNameEntry`
- `TextCommand_PacketForIdPairKind04` calls `NetCellFont_GetIdPair`, `XI_PACKET_100780A0 (left out)`
- `TextCommand_PacketForIdPairKind12` calls `NetCellFont_GetIdPair`, `XI_PACKET_100780A0 (left out)`
- `TextCommand_PacketForIdPairKind1A` calls `NetCellFont_GetIdPair`, `sub_101CC0D0`, `MenuPanels_FindEntryByCallback64`, `XI_PACKET_100780A0 (left out)`
- `TextCommand_TargetActionToPacket` calls `YkCommon_IsActorField170Is5`, `YkCommon_IsActorField170Is55`, `sub_100A1AB0`, `XI_PACKET_100780A0 (left out)`, `NetCellFont_SetWord40DAA`, `ChatLog_AddMessage7Code37B`
- `UI_QuestCommand` calls `MenuMng_OpenByName`
- `TextCommand_CheckThenPostUiRequest0E` calls `YkCommon_TestFlags100Or40DAC`, `NetCellFont_IsReadyBy3C350`, `NetCellFont_GetDword40C3C`, `ChatLog_AddMessage7Code37B`, `sub_101CC0D0`, `ntGameTimeGet`, `TargetMenu_GetByteAE`, `Acter_HasEntryForWord40D7C`, `ChatLog_AddTableMessage7`, `XI_PACKET_100F7FA0 (left out)`
- `TextCommand_ChangeMyroomMode2` calls `YkCommon_TestFlags100Or40DAC`, `NetCellFont_IsReadyBy3C350`, `NetCellFont_GetDword40C3C`, `ChatLog_AddMessage7Code37B`, `sub_101CC0D0`, `ntGameTimeGet`, `TargetMenu_GetByteAE`, `Acter_HasEntryForWord40D7C`, `ChatLog_AddTableMessage7`, `YkMyroom::ChangeMode`
- `TextCommand_Run100A3040` calls `AuctionMenu_CreateTaskOnce`
- `Actor_GetObjectByName` calls `SeekIdByString`
- `TextCommand_GetWord1047D3FC` calls nothing directly
- `TextCommand_IsIdNotInTable10357BB8` calls `ActorHandle_Resolve`
- `Actor_IsInTable` calls nothing directly
- `Command_RunLine` calls `TextInputFiles_ProcessInputLine`, `Arg_LookupWord`, `ChatLog_AddMessage7Code37B`, `preprocessArg`, `FsTextInput_GetDataPtr8`, `Arg_CopyCharOrPair`, `Arg_SplitQuoted`, `Arg_FindInSortedTable`, `ChatLog_AddFormattedMessage`, `TextCommand_CheckCommandAllowed`, `sub_10311FF1`, `TargetMenu_GetMessageFwd`
- `TextCommand_CheckCommandAllowed` calls `TextCommand_GetWord1047D3FC`, `Acter_IsState5`, `Acter_IsState55`, `IsEvent`, `ChatLog_AddTableMessage7`, `YkCommon_IsActorField170Is6`, `ChatLog_AddMessage7Code37B`, `TextCommand_TestBit1047D499`, `Menu_FindByFlags34`, `Acter_IsFlag40DB6OrState17`, `TextCommand_IsIdNotInTable10357BB8`, `YkWindows_IsSingleUncheckedEntry`, `Actor_IsInTable`
- `TextCommand_SetFlag1047D498` calls nothing directly
- `TextCommand_TestBit1047D499` calls nothing directly
- `ActorHandle_Constructor` calls nothing directly
- `ActorHandle_Destructor` calls nothing directly
- `ActorHandle_SetFields` calls nothing directly
- `ActorHandle_ResolveObject` calls `ActorHandle_Constructor`, `ActorHandle_Destructor`, `ActorHandle_SetFields`
