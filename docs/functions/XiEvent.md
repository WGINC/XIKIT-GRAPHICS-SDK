# XiEvent

Group: `Xi` (by the file name only). Source: `sdk/tree_src/XiEvent.cpp`.

Why the file has this name (data/unit_names.json): XiEvent_* (Init, Spawn, ResetPending), _EventDataReadCallBack, the strings "ERROR!:set Work_Zone Over[%d]", "menu    eventtim"

21 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `XiEvent_CreateAndAddIfListNotEmpty` | 0x100AD660 | 112 | yes | - | When the event list is not empty, makes a new 0x1304-byte event record from its arguments and adds it to the list. | medium |
| `XiEvent_Spawn` | 0x100AD6D0 | 118 | yes | - | Creates an event record and queues it. | low |
| `XiEvent_IsIdOutsideList` | 0x100AD7C0 | 63 | yes | - | Reports whether the current id at 0x104DFD98+0x40D7C is outside a fixed list. | low |
| `XiEvent_GetGlobalDword` | 0x100AE350 | 8 | yes | - | Returns the event global at DAT_104896E4. | low |
| `XiEvent_ResetPending` | 0x100AE3A0 | 73 | yes | - | Clears the pending event state and its menu. | low |
| `XiEvent_ResetActersAndGlobals` | 0x100AE3F0 | 1377 | yes | - | Ends the event state: restores every acter's position and flags, re-aims the camera, frees the event buffers, clears the event globals and resets the related menus. | medium |
| `_EventDataReadCallBack` | 0x100AEC20 | 56 | yes | - | - | - |
| `XiEvent_RestoreActer` | 0x100BD5F0 | 297 | yes | - | Restores the acter referenced by an event record. | low |
| `XiEvent_GetSingleton` | 0x100BD760 | 51 | yes | - | Returns the XiEvent singleton, creating it on first use. | low |
| `XiEvent_Init` | 0x100C2E20 | 387 | yes | - | Initialises an event record from its arguments. | low |
| `XiEvent_GetWordBFE` | 0x100C3020 | 8 | yes | - | Returns the word at +0xBFE. | low |
| `XiEvent_GetWordC00` | 0x100C3030 | 8 | yes | - | Returns the word at +0xC00. | low |
| `XiEvent_FreeData` | 0x100C3050 | 15 | yes | - | Frees an event record's data buffer. | low |
| `XiEvent_Init_100C3060` | 0x100C3060 | 113 | yes | - | Initialises an event list record. | low |
| `XiEvent_GetSingleton_100C3190` | 0x100C3190 | 51 | yes | - | Returns the event list singleton, creating it on first use. | low |
| `XiEvent_SetFlag8` | 0x100C3200 | 8 | yes | - | Sets the list's flag at +8. | low |
| `XiEvent_HasItems` | 0x100C3210 | 11 | yes | - | Tests whether the event list has an entry. | low |
| `XiEvent_Clear` | 0x100C3220 | 53 | yes | - | Frees all event records in the list. | low |
| `XiEvent_Append` | 0x100C3260 | 46 | yes | - | Appends an event record to the end of the list. | medium |
| `XiEvent_AddEvent` | 0x100C3300 | 194 | yes | - | Creates an event record from actor ids and appends it to the list. | low |
| `XiEvent_StepTimedMessage` | 0x100C3480 | 1012 | yes | - | Counts down a timed event by the frame step, then shows its message. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `XiEvent_CreateAndAddIfListNotEmpty` calls `XiEvent_GetSingleton_100C3190`, `XiEvent_HasItems`, `Allocator_Generic`, `XiEvent_Init`, `XiEvent_AddEvent`
- `XiEvent_Spawn` calls `XiEvent_GetSingleton_100C3190`, `XiEvent_HasItems`, `Allocator_Generic`, `XiEvent_Init`, `XiEvent_AddEvent`
- `XiEvent_IsIdOutsideList` calls nothing directly
- `XiEvent_GetGlobalDword` calls nothing directly
- `XiEvent_ResetPending` calls `Menu_CloseQuery`, `NetCellFont_ClearGlobalLists2150And2154`
- `XiEvent_ResetActersAndGlobals` calls `sub_101C4AE0`, `Acter_TargetClearAndSetFlag53`, `XiEvent_ResetPending`, `ZoneMap_QueryBoxHeightBand`, `ZoneMap_QueryBoxHeightByRadius`, `Acter_CopyPosAndSnap`, `Acter_ReleaseEventRecord`, `CXiSkeletonActor::SetFlag840Bit23`, `Acter_CallVt180IfState`, `Acter_CopyPosToCached`, `Camera_GetField50`, `Camera_SetTargetIfMoved`, `Camera_PlaceRelativeToActor`, `operator_delete`, `XiEvent_GetGlobalDword`, `Cell_SetByte104E1C3E`, `XiZone::RestoreSavedFields`, `Acter_ClearGlobals10488800`, `YkWindows_CloseMapMenus`, `CMoTask::CreateMode4`, `CMoTask::CreateMode2`, `TargetMenu_SetPosition`, `TargetMenu_MenuInitAndFadeItem`, `TargetMenu_InitFields1CTo3A7`, `MenuPanels_ClearMenu`, `sub_101FCFB0`, `CallMotd`, `NetCellFont_SetWord40DAA`
- `_EventDataReadCallBack` calls `ErrorReport_NoOpVarargsA`, `operator_delete`
- `XiEvent_RestoreActer` calls `operator_delete`, `Acter_ApplyPair1EC1F4`, `CYyObject_IsKindOf`, `Acter_ResetMotionCounters`, `CXiSkeletonActor_ReleaseListEntriesMatching`, `CXiSkeletonActor::SetFlag840Bit23`
- `XiEvent_GetSingleton` calls `sub_100BD820`, `sub_10313486`
- `XiEvent_Init` calls `Acter_IsParamBelow901`, `sub_10312050`
- `XiEvent_GetWordBFE` calls nothing directly
- `XiEvent_GetWordC00` calls nothing directly
- `XiEvent_FreeData` calls `operator_delete`
- `XiEvent_Init_100C3060` calls nothing directly
- `XiEvent_GetSingleton_100C3190` calls `sub_100C31F0`, `sub_10313486`
- `XiEvent_SetFlag8` calls nothing directly
- `XiEvent_HasItems` calls nothing directly
- `XiEvent_Clear` calls `XiEvent_FreeData`, `operator_delete`
- `XiEvent_Append` calls nothing directly
- `XiEvent_AddEvent` calls `XiEvent_GetWordBFE`, `Acter_IsParamBelow901`, `XiEvent_GetWordC00`, `Allocator_Generic`, `XiEvent_Init_100C3060`, `XiEvent_Append`
- `XiEvent_StepTimedMessage` calls `sub_100C3130`, `sub_100C3140`, `Camera_GetFrameScale`, `sub_10311C2C`, `sub_100C2FB0`, `sub_100C30F0`, `sub_100C2D00`, `sub_100C2FE0`, `sub_100C3150`, `sub_100C3100`, `sub_100C3120`, `sub_100C3160`, `sub_10087DF0`, `ChatLog_AddMessage`, `sub_100C3170`
