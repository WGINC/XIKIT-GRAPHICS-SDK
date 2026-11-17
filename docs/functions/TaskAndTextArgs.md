# TaskAndTextArgs

Group: `Task` (by the file name only). Source: `sdk/tree_src/TaskAndTextArgs.cpp`.

Why the file has this name (data/unit_names.json): CMoTask::Dispatch / DrawQuad*, CMoTaskMng::AllocTask, the text argument parser (Arg_*), the chat tags <st>, <stpc>, <stnpc>, <stpt>

20 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `TaskAndTextArgs_FindTask` | 0x10074F30 | 40 | yes | - | Finds a task in the list by its owner and kind. | low |
| `Gfx_InitCubeMapTextures` | 0x10075280 | 526 | yes | 0 | - | - |
| `TexRef_ResolveByName` | 0x10075520 | 123 | yes | - | - | - |
| `TexRef_EnsureRenderTarget` | 0x100755A0 | 239 | yes | 0 | - | - |
| `TextureHolder_BindWarped` | 0x10075700 | 577 | yes | 0 | - | - |
| `TexRef_SetTexture` | 0x10075960 | 81 | yes | 0 | - | - |
| `TextureHolder_BindTinted` | 0x100759C0 | 622 | yes | 0 | - | - |
| `Arg_SplitQuoted` | 0x10076830 | 440 | yes | - | Splits a command line into arguments, keeping quoted text together. | medium |
| `Arg_CopyCharOrPair` | 0x100769F0 | 115 | yes | - | Copies one character or pair of bytes and returns the byte count. | low |
| `Arg_StripQuotes` | 0x10076A70 | 51 | yes | - | Removes matching surrounding quotes from an argument. | medium |
| `preprocessArg` | 0x10076AB0 | 1340 | yes | - | - | - |
| `Arg_FindInSortedTable` | 0x10077AD0 | 108 | yes | - | Looks up a word in a sorted table of records. | low |
| `Arg_LookupWord` | 0x10077B40 | 87 | yes | - | Copies the next word of a string and looks it up in the table. | low |
| `TaskAndTextArgs_MapNameLetters` | 0x10077C30 | 178 | yes | - | Rewrites a name's leading single-byte letters through two byte-mapping functions. | low |
| `Acter_CopyNameToBuffer` | 0x10077CF0 | 78 | yes | - | Copies an actor's name into the global name buffer. | low |
| `Acter_GetCurrentIdRef` | 0x10077D40 | 39 | yes | - | Returns the current actor's id reference when the actor is valid. | low |
| `Acter_ClearCurrentName` | 0x10077D70 | 13 | yes | - | Clears the current actor id and name globals. | low |
| `Acter_FindMatchingActor` | 0x10077D80 | 161 | yes | - | Finds an actor whose id matches one from a list and whose state is not 2 or 3. | low |
| `ChatLog_AddFormattedMessage` | 0x10077E30 | 90 | yes | - | Formats a message and adds it to the chat log. | medium |
| `TaskAndTextArgs_ToggleOnKey` | 0x10077FB0 | 222 | yes | - | Toggles a setting on a key press and updates the selected entity. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `TaskAndTextArgs_FindTask` calls nothing directly
- `Gfx_InitCubeMapTextures` calls `sub_1000AD70`, `sub_1006A070`, `Gfx_CalcFVFStride`, `CDx::DrawPrimitiveUP`, `sub_1006A0E0`
- `TexRef_ResolveByName` calls `CYyTexMng::FindByNameInResource`, `TexMgr_GetField8`
- `TexRef_EnsureRenderTarget` calls `Mem_AllocDefault`, `CAcc::Constructor`, `CMoDX::CreateTexture`, `sub_1000AD70`
- `TextureHolder_BindWarped` calls `TexRef_EnsureRenderTarget`, `sub_1006A060`, `MoDX_SetInvalid`, `sub_10313486`, `sub_1006AE30`, `DynVB_Reserve`, `DynVB_Lock`, `DynVB_Unlock`, `CMoVuElem_Draw`, `sub_1006A0E0`
- `TexRef_SetTexture` calls nothing directly
- `TextureHolder_BindTinted` calls `TexRef_EnsureRenderTarget`, `sub_1006A060`, `MoDX_SetInvalid`, `sub_10313486`, `sub_1006AE30`, `DynVB_Reserve`, `DynVB_Lock`, `DynVB_Unlock`, `CMoVuElem_Draw`, `sub_1006A0E0`
- `Arg_SplitQuoted` calls `Arg_CopyCharOrPair`, `Arg_StripQuotes`
- `Arg_CopyCharOrPair` calls nothing directly
- `Arg_StripQuotes` calls nothing directly
- `preprocessArg` calls `Arg_LookupWord`, `sub_10312940`, `Menu_FindByFlags34`, `YkCommon_TestFlags100Or40DAC`, `IsEvent`, `sub_10076FF0`, `Arg_CopyCharOrPair`, `ChatLog_AddTableMessage7`, `sub_10312050`, `YkWindows_SetModeFwd`, `TextCommand_SetFlag1047D498`, `sub_10202FE0`, `Target_SetIfUsable`, `Target_ApplyAction`, `Target_SetHandlerC8`, `sub_10077A00`
- `Arg_FindInSortedTable` calls nothing directly
- `Arg_LookupWord` calls `Arg_FindInSortedTable`
- `TaskAndTextArgs_MapNameLetters` calls `sub_103146DE`, `sub_10313B74`, `sub_103145A4`
- `Acter_CopyNameToBuffer` calls `Acter_ClearCurrentName`
- `Acter_GetCurrentIdRef` calls nothing directly
- `Acter_ClearCurrentName` calls nothing directly
- `Acter_FindMatchingActor` calls `NetCellFont_SetByte9800AndGetEntry`, `NetCellFont_SelectNext`
- `ChatLog_AddFormattedMessage` calls `sub_10314942`, `ChatLog_AddMessage`
- `TaskAndTextArgs_ToggleOnKey` calls `sub_10078090`, `NetCellFont_TestCommand36CF60`, `sub_100FC140`, `sub_100FC2E0`, `sub_100FC0F0`, `sub_10077ED0`
