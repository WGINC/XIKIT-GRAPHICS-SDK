# ElemFields

Group: `Elem` (by the file name only). Source: `sdk/tree_src/ElemFields.cpp`.

Why the file has this name (data/unit_names.json): CMoElem::GetActiveField0A4 / GetAddr78 / GetAddr84

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ElemFields_InitFromRenderTarget` | 0x100474D0 | 71 | yes | - | Resets the lightmap's frame values and sets them from the render target's size. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ElemFields_InitFromRenderTarget` calls `CDx::GetRenderTargetTop`
