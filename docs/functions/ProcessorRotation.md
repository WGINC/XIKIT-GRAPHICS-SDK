# ProcessorRotation

Group: `Processor` (by the file name only). Source: `sdk/tree_src/ProcessorRotation.cpp`.

Why the file has this name (data/unit_names.json): CMoProcessorX87::RotationFromAnglesXYZ / ZYX, RotationY, RotationZ

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ProcessorRotation_MakeFromAngles` | 0x1006D9C0 | 754 | yes | - | Builds the rotation matrix for three angles (one about each axis) into the output, multiplying the three axis rotations through its own matrix-product slot. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ProcessorRotation_MakeFromAngles` calls `game_10313486`
