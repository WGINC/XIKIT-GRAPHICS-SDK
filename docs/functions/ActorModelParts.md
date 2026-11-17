# ActorModelParts

Group: `Actor` (by the file name only). Source: `sdk/tree_src/ActorModelParts.cpp`.

Why the file has this name (data/unit_names.json): CXiActor::RequestModelParts, ProcessResidentListEntries

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ActorModelParts_ProcessResidentListEntries` | 0x100D1450 | 103 | yes | 7 | For the actor's current resource, spawns its generators if it asks for them and runs 0x1001B7B0 on each list entry whose resource is resident and not yet handled. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ActorModelParts_ProcessResidentListEntries` calls `CXiActor::SpawnResourceGenerators`, `ResourceHandle_IsResident`, `sub_1001B7B0`
