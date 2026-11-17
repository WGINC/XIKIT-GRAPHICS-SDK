# ElemOffset

Group: `Elem` (by the file name only). Source: `sdk/tree_src/ElemOffset.cpp`.

Why the file has this name (data/unit_names.json): GetOffsetVec, called only from the generator code; evaluates the curve (Unit100544A0_Evaluate)

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ElemOffset_GetOffsetVec` | 0x10047B80 | 37 | yes | - | Returns the element's offset vector, or the default vector when it has none. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ElemOffset_GetOffsetVec` calls `CMoSpline::GetData`
