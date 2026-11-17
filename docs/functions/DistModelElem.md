# DistModelElem

Group: `Dist` (by the file name only). Source: `sdk/tree_src/DistModelElem.cpp`.

Why the file has this name (data/unit_names.json): CMoDistModelElem::DrawBatches / DrawMesh, the blend weights

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `MoElem_GetVertexData` | 0x1003FD70 | 44 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `MoElem_GetVertexData` calls `CMoDistModelElem::GetDataEnd`
