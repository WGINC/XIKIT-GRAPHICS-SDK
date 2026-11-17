# ZoneResource

Group: `Zone` (by the file name only). Source: `sdk/tree_src/ZoneResource.cpp`.

Why the file has this name (data/unit_names.json): called only from MeshResourceMng_CreateResourceByKind; calls the ZoneMap code: read from the code

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ZoneResource_Construct` | 0x10176FE0 | 18 | yes | - | Constructs the resource object whose vtable is at 0x103366F0 on its CMoResource base. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ZoneResource_Construct` calls `CMoResource_ConstructBase`
