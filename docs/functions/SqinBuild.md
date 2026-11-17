# SqinBuild

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqinBuild.cpp`.

Why the file has this name (data/unit_names.json): SqinBuild_BuildSQO

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqinBuild_BuildSQO` | 0x1029AA80 | 329 | yes | - | Builds a skin from an SQLE-tagged binary block. | high |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqinBuild_BuildSQO` calls `SqScriptRead_ReadBlock`, `SqinSkin_Create`, `sqinSkinBuildBinary`, `sqDebugPrintf`
