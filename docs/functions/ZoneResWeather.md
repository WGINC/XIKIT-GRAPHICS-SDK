# ZoneResWeather

Group: `Zone` (by the file name only). Source: `sdk/tree_src/ZoneResWeather.cpp`.

Why the file has this name (data/unit_names.json): called only from MeshResourceMng_CreateResourceByKind, the zone map resource; the string "awanbraccol1sh-usuim": read from the code

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ZoneResWeather_Construct` | 0x10176F60 | 18 | yes | - | Constructs the resource object whose vtable is at 0x103366C4 on its CMoResource base. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ZoneResWeather_Construct` calls `CMoResource_ConstructBase`
