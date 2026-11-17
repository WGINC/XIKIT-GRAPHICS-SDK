# SqgxLighting

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqgxLighting.cpp`.

Why the file has this name (data/unit_names.json): ApplyLighting, Sqgx_IncCounter / ResetCounter

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqgxLighting_ApplyLighting` | 0x102A34D0 | 97 | yes | - | Applies a lighting description to the rendering context. | medium |
| `Sqgx_SetParam9cc` | 0x102A3540 | 16 | yes | - | Stores a float setting in the rendering context. | low |
| `Sqgx_ResetCounter` | 0x102A3760 | 16 | yes | - | Resets a counter in the rendering context. | low |
| `Sqgx_IncCounter` | 0x102A3770 | 12 | yes | - | Increments the counter in the rendering context. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqgxLighting_ApplyLighting` calls `sqgxColor`, `sqgxAmbient`, `SqgxContext_SetFloat76C`, `SqgxContext_SetDword774AndFactor`
- `Sqgx_SetParam9cc` calls nothing directly
- `Sqgx_ResetCounter` calls nothing directly
- `Sqgx_IncCounter` calls nothing directly
