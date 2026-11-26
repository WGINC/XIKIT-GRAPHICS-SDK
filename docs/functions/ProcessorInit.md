# ProcessorInit

Group: `Processor` (by the file name only). Source: `sdk/tree_src/ProcessorInit.cpp`.

Why the file has this name (data/unit_names.json): InitMatrices; called only from CreateProcessorInstance

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ProcessorInit_InitMatrices` | 0x100700E0 | 286 | yes | - | Initialises a processor's four matrix slots from the identity default. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ProcessorInit_InitMatrices` calls `game_10313486`
