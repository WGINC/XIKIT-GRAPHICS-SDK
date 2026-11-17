# SqItemValue

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqItemValue.cpp`.

Why the file has this name (data/unit_names.json): GetValueByItemKind, SetValueByType; called from Mdl_* and the sqmo channels

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqItemValue_SetValueByType` | 0x10284FD0 | 35 | yes | - | Stores a value in the field selected by the object's type. | low |
| `SqItemValue_GetValueByItemKind` | 0x10285000 | 49 | yes | - | Reads the value field of an item of kind 0x50001..0x50003 (dword 10, or 9 for 0x50002) into the output. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqItemValue_SetValueByType` calls nothing directly
- `SqItemValue_GetValueByItemKind` calls nothing directly
