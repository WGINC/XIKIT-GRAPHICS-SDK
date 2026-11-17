# TexObj

Group: `Tex` (by the file name only). Source: `sdk/tree_src/TexObj.cpp`.

Why the file has this name (data/unit_names.json): TexObj_CreateAndUpload / Upload / Reupload / Release

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `TexObj_Release` | 0x100399D0 | 84 | yes | - | Removes a texture object from the texture manager and releases its references. | medium |
| `TexObj_CreateAndUpload` | 0x10039A30 | 37 | yes | 1 | - | - |
| `TexObj_Reupload` | 0x10039A60 | 25 | yes | 1 | - | - |
| `TexObj_Upload` | 0x10039E50 | 2853 | yes | 0 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `TexObj_Release` calls `sub_1003AB10`
- `TexObj_CreateAndUpload` calls `TexObj_Create`, `sub_10071F60`
- `TexObj_Reupload` calls `TexObj_Upload`
- `TexObj_Upload` calls `sub_102D2FB9`, `sub_1001E0A0`, `sub_102D4515`, `sub_102D2868`
