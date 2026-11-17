# Spline

Group: `Spline` (by the file name only). Source: `sdk/tree_src/Spline.cpp`.

Why the file has this name (data/unit_names.json): CMoSpline::* (segment tables, samples, cubic segments)

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoSpline_EvalCubicSegment` | 0x10063890 | 294 | yes | - | Evaluates a cubic spline segment at a parameter. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoSpline_EvalCubicSegment` calls nothing directly
