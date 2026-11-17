# SqIOHooks

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqIOHooks.cpp`.

Why the file has this name (data/unit_names.json): CallHook2C / 3C / 40; called from sqinIO, sqmdIO, the image readers

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqIOHooks_CallHook2C` | 0x10291290 | 18 | yes | - | Runs the object's hook at +0x2C. | low |
| `SqIOHooks_CallHook3C` | 0x102912D0 | 18 | yes | - | Runs the object's hook at +0x3C. | low |
| `SqIOHooks_CallHook40` | 0x102912F0 | 18 | yes | - | Runs the object's hook at +0x40. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqIOHooks_CallHook2C` calls nothing directly
- `SqIOHooks_CallHook3C` calls nothing directly
- `SqIOHooks_CallHook40` calls nothing directly
