# CMoTask_VT_10329C70

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoTask_VT_10329C70.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoTask_VT_10329C70::vf8` | 0x1006B480 | 61 | yes | - | On its second call, caches the camera's view-projection and runs the draw helper; the first call only counts. (reviewed as sub_1006B480) | low |
| `CMoTask_VT_10329C70::vf1` | 0x1006B4C0 | 23 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoTask_VT_10329C70::vf8` calls `sub_10069EE0`, `CameraCache_CacheViewProjection`, `Camera_SetupMatrices`
- `CMoTask_VT_10329C70::vf1` calls `MoDX_Nop`
