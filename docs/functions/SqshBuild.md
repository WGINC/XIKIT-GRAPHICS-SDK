# SqshBuild

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqshBuild.cpp`.

Why the file has this name (data/unit_names.json): SqshBuild_BuildSQO

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqshBuild_BuildSQO` | 0x10299B30 | 256 | yes | - | Builds a shape from an SQLE-tagged block by its shape type. | high |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqshBuild_BuildSQO` calls `SqScriptRead_ReadBlock`, `sqDebugPrintf`, `SqshBuild_BuildTriStrip`, `SqshBuild_BuildPoints`, `SqshBuild_BuildCurves`
