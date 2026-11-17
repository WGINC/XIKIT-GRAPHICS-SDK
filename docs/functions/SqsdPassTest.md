# SqsdPassTest

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqsdPassTest.cpp`.

Why the file has this name (data/unit_names.json): TestSeparationHalf; called from the sqsd shaders and Drawable_DrawTwoPass

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqsdPassTest_TestSeparationHalf` | 0x102A1FA0 | 95 | yes | - | Tests an object's separation against half its difference length. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqsdPassTest_TestSeparationHalf` calls `SqVec_Length`, `SqBounds_GetCenter`, `SqgxContext_TestClipBounds`
