# SqDebug

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqDebug.cpp`.

Why the file has this name (data/unit_names.json): sqDebugPrintf, sqDrawableDraw

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqDebug_GetFlagByte14` | 0x102857D0 | 8 | yes | - | Returns the object's byte field at +0x14. | low |
| `SqDebug_SetByte14` | 0x102857E0 | 12 | yes | - | Stores a byte at +0x14 of the object. | low |
| `SqDebug_InvokeCallback18` | 0x102857F0 | 18 | yes | - | Calls the object's callback at +0x18 when one is set. | low |
| `sqDrawableDraw` | 0x10285850 | 18 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqDebug_GetFlagByte14` calls nothing directly
- `SqDebug_SetByte14` calls nothing directly
- `SqDebug_InvokeCallback18` calls nothing directly
- `sqDrawableDraw` calls nothing directly
