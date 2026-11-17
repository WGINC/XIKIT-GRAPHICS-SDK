# sqsdAnisoCommon

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqsdAnisoCommon.cpp`.

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqsdAniso_SetNumDrawTris` | 0x102778F0 | 106 | yes | - | Sets the number of triangles the sqsdAniso shader draws (1 to 4). | high |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqsdAniso_SetNumDrawTris` calls `sqDebugPrintf`
