# SchedularOps

Group: `Schedular` (by the file name only). Source: `sdk/tree_src/SchedularOps.cpp`.

Why the file has this name (data/unit_names.json): read from the code: all 96 functions are called only from 0x10057FB0, CMoSchedularTask's command dispatch; they call the script reader (ScriptMacro), the attachments and the generators; the first is atan2 (fpatan)

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SchedularOps_ClearDword0` | 0x1005E110 | 11 | yes | - | Clears the first dword of the object. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SchedularOps_ClearDword0` calls nothing directly
