# ErrorReport

Group: `Error` (by the file name only). Source: `sdk/tree_src/ErrorReport.cpp`.

Why the file has this name (data/unit_names.json): XiErrMsgGetErrCode, ReportAndHandleError, error callbacks (RegisterCallback, IsRegistered); called from event, menu and actor code

18 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ErrorReport_Step` | 0x10017C20 | 54 | yes | 1 | Advances a texture copy by copying the surface rectangle when it is ready. | low |
| `ErrorReport_Begin` | 0x10017C60 | 191 | yes | 0 | Starts a copy of the viewport rectangle into a texture. | medium |
| `ErrorReport_NoOpVarargsA` | 0x10017D20 | 1 | yes | - | Takes any arguments and does nothing. | medium |
| `ErrorReport_NoOpVarargsB` | 0x10017D30 | 1 | yes | - | Takes any arguments and does nothing. | medium |
| `XiErrMsgGetErrCode` | 0x10017D90 | 148 | yes | - | - | - |
| `ErrorReport_DispatchErrorCode` | 0x100180D0 | 97 | no | - | Finds an error code in the error table and calls its handler with the code's message, or sends the default game message when the code is not listed. | medium |
| `ErrorReport_SendMessage7_1To10668FF8` | 0x10018140 | 64 | yes | - | Formats game message (7, 1, arg) and passes the text to the object at 0x10668FF8. | low |
| `ErrorReport_RegisterCallback` | 0x10018180 | 73 | yes | - | Registers the callback 0x10018280 and records whether it succeeded. | low |
| `ErrorReport_SendMessage7_0To10668FF8` | 0x100181D0 | 149 | yes | - | Formats game message (7, 0, \|arg1\|), optionally followed by arg2, and passes the text to the object at 0x10668FF8. | low |
| `ErrorReport_IsRegistered` | 0x10018270 | 6 | yes | - | Reports whether the callback registration succeeded. | low |
| `ErrorReport_Call10114F10NoArgs` | 0x100182C0 | 18 | yes | - | Calls 0x10114F10 with one argument and two zeros. | low |
| `_exit_0` | 0x100182E0 | 18 | yes | - | - | - |
| `ErrorReport_Thunk10114F10` | 0x10018300 | 5 | yes | - | Forwards to 0x10114F10. | medium |
| `ErrorReport_ReportAndHandleError` | 0x10018310 | 58 | yes | - | Reports an error code and then handles it, through a registered callback for negative codes or the error table otherwise. | medium |
| `ErrorReport_CtorVt10329F88` | 0x10018350 | 32 | yes | - | Constructs an object with vtable 0x10329F88. | low |
| `ErrorReport_CtorVt10329F8C` | 0x10018430 | 49 | yes | - | Constructs the object App_InitScene creates with vtable 0x10329F8C and its three members. | low |
| `ErrorReport_CtorVt10329F90` | 0x10018550 | 28 | yes | - | Constructs an object with vtable 0x10329F90. | low |
| `ErrorReport_LoadChecksum` | 0x100185A0 | 194 | yes | - | Loads a file and stores a checksum of its bytes. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ErrorReport_Step` calls `Gfx_CopySurfaceRectToTexture`
- `ErrorReport_Begin` calls `Camera_GetViewportWidth`, `Camera_GetViewportHeight`, `ErrorReport_Step`
- `ErrorReport_NoOpVarargsA` calls nothing directly
- `ErrorReport_NoOpVarargsB` calls nothing directly
- `XiErrMsgGetErrCode` calls `sub_10311877`, `TargetMenu_GetMessageFwd`
- `ErrorReport_DispatchErrorCode` calls `ErrorReport_SendMessage7_1To10668FF8`, `XiErrMsgGetErrCode`
- `ErrorReport_SendMessage7_1To10668FF8` calls `TargetMenu_GetMessageFwd`, `sub_10311FF1`, `LobbyUi_StoreTextIfIdle`
- `ErrorReport_RegisterCallback` calls `NetCellFont_StartRequestSlot24WithCallback`, `ErrorReport_SendMessage7_0To10668FF8`
- `ErrorReport_SendMessage7_0To10668FF8` calls `TargetMenu_GetMessageFwd`, `sub_10311FF1`, `LobbyUi_StoreTextIfIdle`
- `ErrorReport_IsRegistered` calls nothing directly
- `ErrorReport_Call10114F10NoArgs` calls `ErrorReport_Thunk10114F10`
- `_exit_0` calls `ErrorReport_ReportAndHandleError`
- `ErrorReport_Thunk10114F10` calls `NetCellFont_ReportError`
- `ErrorReport_ReportAndHandleError` calls `NetCellFont_ReportError`, `ErrorReport_RegisterCallback`, `ErrorReport_DispatchErrorCode`
- `ErrorReport_CtorVt10329F88` calls `TextInputFiles_SetVtable10337C64`
- `ErrorReport_CtorVt10329F8C` calls `ErrorReport_CtorVt10329F88`, `ErrorReport_CtorVt10329F90`
- `ErrorReport_CtorVt10329F90` calls `TextInputFiles_SetVtable10337C64`
- `ErrorReport_LoadChecksum` calls `sub_101BE510`, `Allocator_Generic`, `File_FindByKind`, `File_WriteChunked`, `operator_delete`, `TextInputFiles_Call10311F30`
