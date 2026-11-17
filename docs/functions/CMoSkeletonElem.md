# CMoSkeletonElem

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoSkeletonElem.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoSkeletonElem::GetRuntimeClass` | 0x10047580 | 6 | yes | - | - | - |
| `CMoSkeletonElem::ScalarDeletingDtor` | 0x10047940 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoSkeletonElem::GetRuntimeClass` calls nothing directly
- `CMoSkeletonElem::ScalarDeletingDtor` calls `sub_10047900`, `SharedDeleteHelper`
