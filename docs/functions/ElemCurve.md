# ElemCurve

Group: `Elem` (by the file name only). Source: `sdk/tree_src/ElemCurve.cpp`.

Why the file has this name (data/unit_names.json): Evaluate, EvaluateEaseIn, EvaluateEaseInOut: the element curves

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ElemCurve_EvaluateWithFlag34` | 0x100544D0 | 42 | yes | - | Evaluates the curve with a temporarily replaced value at +0x34. | low |
| `ElemCurve_Evaluate` | 0x10054500 | 155 | yes | - | Evaluates the key curve at a time between 0 and 1 by linear interpolation. | medium |
| `ElemCurve_EvaluateEaseIn` | 0x100546F0 | 168 | yes | - | Evaluates the key curve with an ease-in weighting on the first half of the segment. | low |
| `ElemCurve_EvaluateEaseInOut` | 0x100547A0 | 146 | yes | - | Evaluates the key curve with an ease-in-out weighting across the segment. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ElemCurve_EvaluateWithFlag34` calls `ElemCurve_Evaluate`
- `ElemCurve_Evaluate` calls nothing directly
- `ElemCurve_EvaluateEaseIn` calls nothing directly
- `ElemCurve_EvaluateEaseInOut` calls nothing directly
