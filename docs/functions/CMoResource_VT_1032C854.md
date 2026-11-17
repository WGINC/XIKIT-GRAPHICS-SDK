# CMoResource_VT_1032C854

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoResource_VT_1032C854.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoResource_VT_1032C854::CheckVersionAndInit` | 0x1002D7F0 | 97 | yes | 2 | Checks the resource's Os2 version byte and, the first time, runs the set-up its kind byte selects. (reviewed as sub_1002D7F0) | medium |
| `CMoResource_VT_1032C854::vf004` | 0x1002D880 | 90 | yes | - | Converts the object's stored pointers to offsets from its base and stores a value through its reference. (reviewed as sub_1002D880) | medium |
| `CMoResource_VT_1032C854::ScalarDeletingDtor` | 0x10071A80 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoResource_VT_1032C854::CheckVersionAndInit` calls `sub_10017D50`, `ErrorReport_NoOpVarargsA`, `sub_10022470`, `Os2VtxBuffer_FixOffsetsAndCreateVtxBuffer`
- `CMoResource_VT_1032C854::vf004` calls nothing directly
- `CMoResource_VT_1032C854::ScalarDeletingDtor` calls `CMoResource::Destructor`, `SharedDeleteHelper`
