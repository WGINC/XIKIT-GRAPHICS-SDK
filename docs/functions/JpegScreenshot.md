# JpegScreenshot

Group: `Jpeg` (by the file name only). Source: `sdk/tree_src/JpegScreenshot.cpp`.

Why the file has this name (data/unit_names.json): YkJpeg::CaptureAndEncode / PutBits, TakeScreenshot, SaveJpegScreenSize, CopyrightText_Draw, the language strings japanese / english / german / french

13 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `JpegScreenshot_PutByte` | 0x101D09C0 | 32 | yes | - | Appends one byte to the writer's buffer when it has room. | medium |
| `JpegScreenshot_PutWordBE` | 0x101D0A20 | 32 | yes | - | Appends a 16-bit value to the buffer, high byte first. | medium |
| `JpegScreenshot_PutFFThenByte` | 0x101D0A40 | 28 | yes | - | Appends a 0xFF byte followed by the argument's low byte. | low |
| `JpegScreenshot_TriggerOnSceneState60` | 0x101D0AB0 | 71 | yes | - | Starts an action and returns true when the scene state is 0x60 and a menu condition holds. | low |
| `CopyrightText_Draw` | 0x101D0B00 | 312 | yes | 3 | - | - |
| `CopyrightText_Format` | 0x101D0C40 | 34 | yes | - | Formats the copyright line into a shared buffer and returns it. | medium |
| `JpegScreenshot_TakeScreenshot` | 0x101D0EA0 | 349 | yes | 4 | Takes a screenshot to a dated JPEG file. | medium |
| `JpegScreenshot_SaveJpeg512x382` | 0x101D1000 | 94 | yes | 3 | Saves a 512x382 JPEG of the screen. | medium |
| `JpegScreenshot_WriteWithFileMngA` | 0x101D10C0 | 64 | yes | - | Hands the encoded data to the file manager through 0x101C0A40. | low |
| `JpegScreenshot_SaveJpegScreenSize` | 0x101D1100 | 118 | yes | 3 | Saves a JPEG of the screen at the camera's size. | medium |
| `JpegScreenshot_WriteWithFileMngB` | 0x101D1180 | 64 | yes | - | Hands the encoded data to the file manager through 0x101C0760. | low |
| `YkInit` | 0x101D11C0 | 2242 | yes | - | - | - |
| `JpegScreenshot_TestMask10663188` | 0x101D29C0 | 33 | yes | - | Tests two arguments against a pair of global masks. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `JpegScreenshot_PutByte` calls nothing directly
- `JpegScreenshot_PutWordBE` calls `JpegScreenshot_PutByte`
- `JpegScreenshot_PutFFThenByte` calls `JpegScreenshot_PutByte`
- `JpegScreenshot_TriggerOnSceneState60` calls `Menu_IsStateB4Eq1`, `MusicTrack_SetVolumeId0016`
- `CopyrightText_Draw` calls `Menu_IsStateB4Eq1`, `CDx::GetRenderTargetTop`, `CopyrightText_Format`, `sub_10311C2C`, `sub_101C9B50`
- `CopyrightText_Format` calls `YkCommon_GetOffset`, `sub_10311FF1`
- `JpegScreenshot_TakeScreenshot` calls `sub_100DBE10`, `YkCommon_TimeToTmWrap28Years`, `sub_10311FF1`, `ntGameTimeGet`, `Time_ModMul3CDiv90`, `JpegScreenshot_SaveJpeg512x382`, `JpegScreenshot_SaveJpegScreenSize`
- `JpegScreenshot_SaveJpeg512x382` calls `Mem_AllocDefault`, `YkJpeg::Destructor`, `YkJpeg::CaptureAndEncode`, `JpegScreenshot_WriteWithFileMngA`, `YkJpeg::Release`, `thunk_sub_10028AA0`
- `JpegScreenshot_WriteWithFileMngA` calls `TextInputFiles_FileMngCall101C0A40`
- `JpegScreenshot_SaveJpegScreenSize` calls `Camera_GetWord10`, `Camera_GetWord12`, `Mem_AllocDefault`, `YkJpeg::Destructor`, `YkJpeg::CaptureAndEncode`, `JpegScreenshot_WriteWithFileMngB`, `YkJpeg::Release`, `thunk_sub_10028AA0`
- `JpegScreenshot_WriteWithFileMngB` calls `TextInputFiles_FileMngSubmitPath4F4Kind3`
- `YkInit` calls `YkCommonInit`, `Allocator_Generic`, `YkWindows_CtorVt1033A8B8`, `Yk_CtorVt10339BC0`, `YkWindows_CtorVt103394C0`, `YkWindows_CtorVt10339698`, `YkWindows_CtorVt10339D78`, `YkWindows_CtorVt10338F68`, `YkWindows_CtorVt1033B948`, `NetCellFont_ClearWords`, `YkWindows_InitFromTablesA`, `YkWindows_InitFromTablesB`, `YkWindows_CtorVt1033ABE0`, `YkWindows_Init`, `Scene_GetMenuFrameName`, `YkWindows_ClearFields14To24`, `YkWindows_CtorVt10339250`, `YkWindows_CtorVt10338D88`, `YkWindows_CtorVt1033A5D8`, `YkWndShop_Constructor`, `Yk_CreateSecondaryObjects`, `YkWindows_CtorVt10339FA0`, `Yk_CreateCommonObjects`, `YkWindows_CtorVt1033B3A0`, `YkWindows_CtorVt10339E48`, `YkWndList_Init`, `YkWindows_CtorVt1033B248`, `YkWindows_CtorVt1033B340`, `YkWindows_CtorVt1033AAB0`, `YkWindows_CtorVt1033A6D0`, `YkWindows_CreateMenuObjects`, `YkCommon_Init`, `YkCommon_ResizeEntries`, `Scene_GetTableValue`, `YkCommon_LoadTable`
- `JpegScreenshot_TestMask10663188` calls nothing directly
