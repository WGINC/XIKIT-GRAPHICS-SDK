# LobbyScreen

Group: `Lobby` (by the file name only). Source: `sdk/tree_src/LobbyScreen.cpp`.

Why the file has this name (data/unit_names.json): the lobby menus "loby1win", "partywin", "joblevel", the 3D avatar start (StAvatarInit), and the stream thread (the misnamed LobbyThread_*: its thread 0x10245650 reads files and queues music, sounds and streams; it never reaches Winsock) (an address range between two evidenced source files, holding several of the original files: named for its main contents)

29 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `LobbyThread_NoOp` | 0x10244F20 | 1 | yes | - | Does nothing. | low |
| `LobbyThread_Construct` | 0x10244F30 | 45 | yes | - | Constructs the lobby-thread object and sets its vtable and defaults. | medium |
| `LobbyThread_InitState` | 0x10245040 | 8 | yes | - | Sets the lobby thread's field +0x14 to 2. | low |
| `LobbyScreen_LoadResourceRunMain` | 0x10245460 | 88 | yes | - | Loads the screen resource with the given id, holds it, and starts its type-7 child named "main". | medium |
| `LobbyScreen_ReleaseResource` | 0x102454E0 | 61 | yes | 6 | Releases the screen resource held at 0x10669094 and what it started. | medium |
| `LobbyScreen_LoadResourceOnce` | 0x10245520 | 35 | yes | - | Loads the screen resource with the given id unless one is already held. | medium |
| `LobbyThread_Start` | 0x10245600 | 68 | yes | - | - | - |
| `LobbyThread_SetGlobal106690AC` | 0x10245B50 | 12 | yes | - | Stores a value in the global at DAT_106690AC. | low |
| `Lobby_DestroyThreadPool` | 0x10245B60 | 53 | yes | - | - | - |
| `thunk_sub_10245BB0` | 0x10245BA0 | 5 | yes | - | - | - |
| `LobbyThread_ResetZone` | 0x10245BB0 | 42 | yes | 9 | Resets the zone and recreates the camera manager and draw lists. | low |
| `LobbyThread_IsSystemState1` | 0x10245BE0 | 14 | yes | - | Tests whether the system at 0x10669098 is in state 1. | low |
| `LobbyThread_NextSequence` | 0x10245F30 | 25 | yes | - | Advances the thread's sequence number, skipping zero. | medium |
| `LobbyThread_SendCmd0` | 0x10246000 | 36 | yes | - | Sends command 0 to the lobby thread and returns its result. | low |
| `LobbyThread_QueueSoundCmd` | 0x10246030 | 108 | yes | - | Queues a sound command (1, or 2 for an "SeSep" entry) and returns its sequence number. | low |
| `LobbyThread_QueryChannels` | 0x10246160 | 371 | yes | - | Answers queries about the channel records by id (found, values, active count). | low |
| `LobbyThread_SendCmd3` | 0x102462F0 | 42 | yes | - | Sends command 3 to the lobby thread. | low |
| `LobbyThread_SendCmd4` | 0x10246320 | 42 | yes | - | Sends command 4 to the lobby thread and returns its result. | low |
| `LobbyThread_SendCmd6` | 0x102463C0 | 33 | yes | - | Sends command 6 to the lobby thread. | low |
| `LobbyThread_QueueStreamFile` | 0x102463F0 | 163 | yes | - | Reads a stream file's header and queues command 7 to play it. | low |
| `LobbyThread_QueueMusicFile` | 0x102465E0 | 270 | yes | - | Finds the music file musicNNN.bgw under the base paths and queues command 7 for it. | low |
| `LobbyThread_SendCmd8` | 0x10246770 | 42 | yes | - | Sends command 8 to the lobby thread. | low |
| `LobbyThread_SendCmd9` | 0x102467A0 | 36 | yes | - | Sends command 9 to the lobby thread. | low |
| `LobbyThread_SendCmd11` | 0x102467F0 | 33 | yes | - | Sends command 0xB to the lobby thread and returns its result. | low |
| `LobbyThread_PushCmd` | 0x1024C060 | 259 | yes | - | Writes a command and its arguments into the lobby thread's command ring. | medium |
| `LobbyThread_CtorVt1033CCA8` | 0x1024C210 | 125 | yes | - | Constructs an object with vtable 0x1033CCA8 and creates the lobby message queue once. | low |
| `LobbyThread_ConstructQueue` | 0x1024C930 | 38 | yes | - | Constructs the lobby message queue and sets its vtable and defaults. | medium |
| `StAvatarInit` | 0x1024CF50 | 473 | yes | 0 | - | - |
| `StAvatar_InitEntriesFromTables` | 0x1024D130 | 78 | no | - | Sets the five avatar parts' transforms and flags from their default tables. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `LobbyThread_NoOp` calls nothing directly
- `LobbyThread_Construct` calls `NetCellFont_ClearWords`, `LobbyThread_InitState`
- `LobbyThread_InitState` calls nothing directly
- `LobbyScreen_LoadResourceRunMain` calls `sub_100731B0`, `sub_10071E90`, `CMoResource::FindByTypeAndId`, `sub_10056B80`
- `LobbyScreen_ReleaseResource` calls `DynVB_ReleaseResourcesOf`, `CMoResource::ReleaseChain`, `ResHandle_FreeIfUnreferenced`
- `LobbyScreen_LoadResourceOnce` calls `LobbyScreen_LoadResourceRunMain`
- `LobbyThread_Start` calls `Mem_AllocDefault`, `CYyObject::Init`, `ThreadPool_StartThread`
- `LobbyThread_SetGlobal106690AC` calls nothing directly
- `Lobby_DestroyThreadPool` calls `ThreadPool_Shutdown`
- `thunk_sub_10245BB0` calls `LobbyThread_ResetZone`
- `LobbyThread_ResetZone` calls `XiZone::ResetState`, `WinMain_ApplyTables10350210`, `XiZone::GetInstance`, `CYyCamMng2::CreateGlobal`, `Actor_ResetDrawLists`
- `LobbyThread_IsSystemState1` calls `sub_10039590`
- `LobbyThread_NextSequence` calls nothing directly
- `LobbyThread_SendCmd0` calls `LobbyThread_PushCmd`
- `LobbyThread_QueueSoundCmd` calls `LobbyThread_NextSequence`, `LobbyThread_PushCmd`
- `LobbyThread_QueryChannels` calls nothing directly
- `LobbyThread_SendCmd3` calls `LobbyThread_PushCmd`
- `LobbyThread_SendCmd4` calls `LobbyThread_PushCmd`
- `LobbyThread_SendCmd6` calls `LobbyThread_PushCmd`
- `LobbyThread_QueueStreamFile` calls `Allocator_Generic`, `sub_10311FDE`, `sub_1031217F`, `sub_10311F30`, `LobbyThread_PushCmd`, `operator_delete`
- `LobbyThread_QueueMusicFile` calls `Allocator_Generic`, `sub_10311FF1`, `sub_10311FDE`, `sub_10311F30`, `LobbyThread_PushCmd`, `operator_delete`
- `LobbyThread_SendCmd8` calls `LobbyThread_PushCmd`
- `LobbyThread_SendCmd9` calls `LobbyThread_PushCmd`
- `LobbyThread_SendCmd11` calls `LobbyThread_PushCmd`
- `LobbyThread_PushCmd` calls nothing directly
- `LobbyThread_CtorVt1033CCA8` calls `NetCellFont_ClearWords`, `Allocator_Generic`, `LobbyThread_ConstructQueue`
- `LobbyThread_ConstructQueue` calls `NetCellFont_ClearWords`
- `StAvatarInit` calls `SqTimer_GetMicroseconds`, `PackVec4`, `SceneRecord_InitRecord`, `StAvatar_InitSlotRecord`, `StAvatar_InitIndices`, `StModelItem_Init`, `StAvatarScene_InitScene`, `StAvatar_SetSceneValue1`, `StAvatar_SetSceneValue2`, `StAvatar_InitEntriesFromTables`, `StAvatar_InitGlobals1099AEB8`, `scnFini`, `StAvatar_AllocArrays`
- `StAvatar_InitEntriesFromTables` calls `StAvatar_SetEntryTransform`, `StAvatar_SetEntryFlag2`, `StAvatar_SetEntryFlag`, `StAvatar_ToggleFlag168`
