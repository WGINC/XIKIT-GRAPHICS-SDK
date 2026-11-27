# sqinBuild

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqinBuild.cpp`.

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `sqinSkinBuildBinary` | 0x1029ABD0 | 540 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `sqinSkinBuildBinary` calls `sqDebugPrintf`, `SqScriptRead_ReadBlock`, `SqinSkin_ResizeItemArray`, `game_10275D80`, `sqskSkeleton_GetNodeByIndex`, `sqinCluster_Create`, `SqinSkinAppend_Append`
