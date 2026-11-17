# ModelDtBase

Group: `Model` (by the file name only). Source: `sdk/tree_src/ModelDtBase.cpp`.

Why the file has this name (data/unit_names.json): CYyModelDtBase_Destructor and a field getter; called from CYyModelDt destructors

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CYyModelDtBase_Destructor` | 0x10029CD0 | 72 | yes | - | - | - |
| `ModelDtBase_GetField20` | 0x10029D20 | 16 | yes | - | Returns the +0x20 field of the object held in this handle. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CYyModelDtBase_Destructor` calls `CMoResource::ReleaseChain`, `ResHandle_FreeIfUnreferenced`, `sub_10029C00`
- `ModelDtBase_GetField20` calls nothing directly
