# YkMyroom

Group: `Yk` (by the file name only). Source: `sdk/tree_src/YkMyroom.cpp`.

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `YkMyroom::Destructor` | 0x101D2F00 | 232 | yes | - | Destroys the Myroom object and releases its menus. (reviewed as sub_101D2F00) | medium |
| `YkMyroom::ReleaseObject38` | 0x101D30B0 | 54 | yes | - | Releases the object at +0x38 and clears its references. (reviewed as sub_101D30B0) | low |
| `YkMyroom::ReleaseResource8` | 0x101D31B0 | 33 | yes | - | Releases the resource chain held at +8. (reviewed as sub_101D31B0) | medium |
| `YkMyroom::ChangeMode` | 0x101D3380 | 1100 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `YkMyroom::Destructor` calls `MyRoom_ReleaseTable`, `YkMyroom::ReleaseObject38`, `Target_SetHandlerCc`, `Menu_RemoveAndFreeItem`, `operator_delete`, `YkMyroom::ReleaseResource8`, `TargetMenu_SetTextFwd`, `TargetMenu_ForwardToPanel`
- `YkMyroom::ReleaseObject38` calls nothing directly
- `YkMyroom::ReleaseResource8` calls `CMoResource::ReleaseChain`, `ResHandle_FreeIfUnreferenced`
- `YkMyroom::ChangeMode` calls `Acter_HasEntryForWord40D7C`, `IsEvent`, `ActorHandle_Resolve`, `YkWindows_HasKind0CFlag40Entry`, `sub_100A1860`, `MyRoom_Is104DFD98Bit40DB1x10Clear`, `MyRoom_CallAllFurniture101CEA80`, `ZoneMap_SetByteOfId999Entries`, `PlantMenu_SetState`, `MyRoom_DoNothing`, `Cell_SetGlobal1036E3A0`, `TargetMenu_SetTextFwd`, `TargetMenu_ForwardToPanel`, `MenuMng_OpenByName`, `XI_PACKET_100F0C80 (left out)`, `MyRoom_BeginMode`, `MyRoom_CopyList6To818`, `Menu_CloseEntry`, `TargetMenu_SetTargetMode`, `TargetMenu_GetMessageFwd`, `PlantMenu_GetWord58`, `MyRoom_GetFirstFurnitureId`, `MyRoom_StartWithCallbackOnce`, `MyRoom_IsWord40D82Zero`, `YkWndItem_Open`, `MyRoom_SelectFurniture`
