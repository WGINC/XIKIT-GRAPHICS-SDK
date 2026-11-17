# ProjTexTarget

Group: `Proj` (by the file name only). Source: `sdk/tree_src/ProjTexTarget.cpp`.

Why the file has this name (data/unit_names.json): creates and releases the projected-texture target (g_projTexTarget, CDx::CreateTexture at the viewport size); called from CYyModel::Constructor

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ProjTexTarget_Release` | 0x10025220 | 51 | yes | - | Releases the projection texture and its target. | medium |
| `ProjTexTarget_Init` | 0x10025260 | 109 | yes | 1 | Initialises the projection texture object, creating its texture at the viewport size if needed. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ProjTexTarget_Release` calls nothing directly
- `ProjTexTarget_Init` calls `Camera_GetViewportHeight`, `Camera_GetViewportWidth`, `CDx::CreateTexture`
