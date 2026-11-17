# DynVBCtor

Group: `Dyn` (by the file name only). Source: `sdk/tree_src/DynVBCtor.cpp`.

Why the file has this name (data/unit_names.json): DynVB_Constructor; called from the DynVB code

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `DynVBCtor_ToggleByte45` | 0x10043DD0 | 11 | yes | - | Flips the 0/1 flag at +0x45 and returns its new value. | medium |
| `DynVBCtor_ReturnZero` | 0x10043DE0 | 3 | yes | - | Returns 0. | low |
| `DynVB_Constructor` | 0x10043DF0 | 35 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `DynVBCtor_ToggleByte45` calls nothing directly
- `DynVBCtor_ReturnZero` calls nothing directly
- `DynVB_Constructor` calls nothing directly
