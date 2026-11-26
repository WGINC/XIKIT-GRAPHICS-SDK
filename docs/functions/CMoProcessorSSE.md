# CMoProcessorSSE

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoProcessorSSE.cpp`.

5 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoProcessorSSE::Vec3Scale` | 0x1006D380 | 35 | yes | - | Scales a 3-vector in place. (reviewed as game_1006D380) | high |
| `CMoProcessorSSE::Vec3Dot` | 0x1006F5B0 | 31 | yes | - | Dot product of two 3-vectors. (reviewed as game_1006F5B0) | high |
| `CMoProcessorSSE::Vec3Lerp` | 0x1006FA30 | 13 | yes | - | Calls CMoProcessor_Lerp3. (reviewed as game_1006FA30) | medium |
| `CMoProcessorSSE::CalcScreenBoundsAndVisible` | 0x10070020 | 21 | yes | - | Calls CMoProcessor_CalcScreenBoundsAndVisible. (reviewed as game_10070020) | medium |
| `CMoProcessorSSE::CalcScreenBounds` | 0x10070040 | 5 | yes | - | Calls CMoProcessor_CalcScreenBounds. (reviewed as game_10070040) | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoProcessorSSE::Vec3Scale` calls nothing directly
- `CMoProcessorSSE::Vec3Dot` calls nothing directly
- `CMoProcessorSSE::Vec3Lerp` calls `CMoProcessorX87::Vec3Lerp`
- `CMoProcessorSSE::CalcScreenBoundsAndVisible` calls `CMoProcessor::CalcScreenBoundsAndVisible`
- `CMoProcessorSSE::CalcScreenBounds` calls `CMoProcessor::CalcScreenBounds`
