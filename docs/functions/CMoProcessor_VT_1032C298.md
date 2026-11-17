# CMoProcessor_VT_1032C298

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoProcessor_VT_1032C298.cpp`.

5 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoProcessor_VT_1032C298::vf007` | 0x1006D380 | 35 | yes | - | Scales a three-float vector by a scalar in place. (reviewed as sub_1006D380) | medium |
| `CMoProcessor_VT_1032C298::vf014` | 0x1006F5B0 | 31 | yes | - | Returns the dot product of two three-float vectors. (reviewed as sub_1006F5B0) | medium |
| `CMoProcessor_VT_1032C298::vf021` | 0x1006FA30 | 13 | yes | - | - | - |
| `CMoProcessor_VT_1032C298::vf035` | 0x10070020 | 21 | yes | - | Vtable entry that forwards to CMoProcessor_CalcScreenBoundsAndVisible. (reviewed as sub_10070020) | medium |
| `CMoProcessor_VT_1032C298::vf036` | 0x10070040 | 5 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoProcessor_VT_1032C298::vf007` calls nothing directly
- `CMoProcessor_VT_1032C298::vf014` calls nothing directly
- `CMoProcessor_VT_1032C298::vf021` calls `CMoProcessor_VT_1032C368::vf021`
- `CMoProcessor_VT_1032C298::vf035` calls `CMoProcessor::CalcScreenBoundsAndVisible`
- `CMoProcessor_VT_1032C298::vf036` calls `CMoProcessor::CalcScreenBounds`
