# ScriptMacro

Group: `Script` (by the file name only). Source: `sdk/tree_src/ScriptMacro.cpp`.

Why the file has this name (data/unit_names.json): the strings "enum", "include", "define", "//##mac", " && ", " || ", "Undefined Label !!": a script and macro reader; called from CMoSchedularTask and the afterimage task

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ScriptMacro_SetDwordValue` | 0x100684F0 | 15 | yes | - | Sets a slot to a dword value with type 0. | low |
| `ScriptMacro_AssignTyped` | 0x10068590 | 46 | yes | - | Stores a value and its type in a slot, freeing the previous value when its type requires it. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ScriptMacro_SetDwordValue` calls `ScriptMacro_AssignTyped`
- `ScriptMacro_AssignTyped` calls `operator_delete`
