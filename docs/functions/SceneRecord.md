# SceneRecord

Group: `Scene` (by the file name only). Source: `sdk/tree_src/SceneRecord.cpp`.

Why the file has this name (data/unit_names.json): InitRecord, ClearGroupField4, SetEntryField18; called from StAvatarInit and Mdl_FreeAllSlots

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SceneRecord_SetEntryField18` | 0x10273840 | 46 | yes | - | Sets a field of the entry a group:index handle names. | low |
| `SceneRecord_ClearGroupField4` | 0x10273870 | 36 | yes | - | Clears a field of one group. | low |
| `SceneRecord_ClearCurrentField4` | 0x102738A0 | 34 | yes | - | Clears a field of the current record. | low |
| `SceneRecord_InitRecord` | 0x102738D0 | 40 | yes | - | Initialises a record to its unset state. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SceneRecord_SetEntryField18` calls nothing directly
- `SceneRecord_ClearGroupField4` calls nothing directly
- `SceneRecord_ClearCurrentField4` calls nothing directly
- `SceneRecord_InitRecord` calls nothing directly
