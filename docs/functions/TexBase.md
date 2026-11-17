# TexBase

Group: `Tex` (by the file name only). Source: `sdk/tree_src/TexBase.cpp`.

Why the file has this name (data/unit_names.json): CYyTexBase::Constructor, CopyName16, the format "%10d" and "-uniq"

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `TexBase_CopyName16` | 0x100397A0 | 106 | yes | - | Copies a string into a 16-byte name field, truncating at 16 and padding with zeros. | medium |
| `Util_Copy16Bytes` | 0x10039810 | 25 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `TexBase_CopyName16` calls nothing directly
- `Util_Copy16Bytes` calls nothing directly
