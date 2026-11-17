# OtLink

Group: `Ot` (by the file name only). Source: `sdk/tree_src/OtLink.cpp`.

Why the file has this name (data/unit_names.json): the OT task links (ClearLink, RelinkEntries); called from CMoOt_InitSystem and CMoOt_Update

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `OtLink_ClearLink` | 0x100552F0 | 8 | yes | - | Clears the table's node pointer at +4. | low |
| `OtLink_Init` | 0x10055300 | 155 | yes | - | Initialises a range table with evenly spaced entries. | low |
| `OtLink_RelinkEntries` | 0x100554B0 | 103 | yes | - | Links the object's 0x20-byte entries into one doubly linked chain in array order and clears their +0x14 fields. | low |
| `OtLink_Free` | 0x10055520 | 48 | yes | - | Releases the nodes of a range table. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `OtLink_ClearLink` calls nothing directly
- `OtLink_Init` calls `Mem_AllocObject`, `OtLink_RelinkEntries`
- `OtLink_RelinkEntries` calls nothing directly
- `OtLink_Free` calls nothing directly
