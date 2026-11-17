# CMoOtDrawUPTask

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoOtDrawUPTask.cpp`.

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoOtDrawUPTask::Slot8Update` | 0x10042020 | 377 | yes | - | Per-frame update: advances the timer, places and projects the element; ends after 150. (reviewed as sub_10042020) | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoOtDrawUPTask::Slot8Update` calls `CDx::GetTransformCached`, `sub_100555B0`
