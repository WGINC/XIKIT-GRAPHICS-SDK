# TexMgr

Group: `Tex` (by the file name only). Source: `sdk/tree_src/TexMgr.cpp`.

Why the file has this name (data/unit_names.json): TexMgr_*, CYyTexMng::FindByName

6 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `TexMgr_GetField8` | 0x1003AAB0 | 4 | yes | - | Returns the address of the texture manager's field at offset 8. | low |
| `TexMgr_GetTailLink` | 0x1003AAF0 | 22 | yes | - | Returns the address of the last link in the texture list, for appending a texture. | medium |
| `TexMgr_UploadPumpEntry` | 0x1003AB70 | 8 | yes | 3 | - | - |
| `TexMgr_Enqueue` | 0x1003AB80 | 20 | yes | - | - | - |
| `TexMgr_UploadPump` | 0x1003ABB0 | 144 | yes | 2 | - | - |
| `TexMgr_FindByName` | 0x1003AEA0 | 105 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `TexMgr_GetField8` calls nothing directly
- `TexMgr_GetTailLink` calls `TexMgr_GetField8`
- `TexMgr_UploadPumpEntry` calls `TexMgr_UploadPump`
- `TexMgr_Enqueue` calls `TexMgr_GetTailLink`
- `TexMgr_UploadPump` calls `TexMgr_GetField8`, `TexObj_CreateAndUpload`, `TexObj_Reupload`
- `TexMgr_FindByName` calls `TexMgr_GetField8`
