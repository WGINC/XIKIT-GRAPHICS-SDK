# ActorModelState

Group: `Actor` (by the file name only). Source: `sdk/tree_src/ActorModelState.cpp`.

Why the file has this name (data/unit_names.json): CXiActor::ComputeDrawState and the CXiActor::GetModel* field readers

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Target_FindNearestOnLocalPositiveX` | 0x10083620 | 292 | yes | - | Among the drawable candidates, returns the one closest to the current target on the positive-x side of the target's yaw frame. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Target_FindNearestOnLocalPositiveX` calls `ActorHandle_Resolve`, `MathVector_ReturnThis`, `Mat4_SetIdentity`, `Mat4_PostRotateY`, `Mat4_SetRow3`, `Mat4_InvertOrthonormal`, `YkCommon_GetCC4F0ActorByIndexAt1FA`, `sub_10085240`, `CXiActor::ComputeDrawState`, `Mat4_TransformPoint`, `sub_10027530`, `sub_10085270`, `MathVector_Nop`
