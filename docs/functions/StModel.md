# StModel

Group: `St` (by the file name only). Source: `sdk/tree_src/StModel.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `StModelItemClear` | 0x102524E0 | 289 | yes | - | - | - |
| `StModelItem_ReadStart` | 0x10252610 | 214 | yes | - | Starts reading a model item's DMB and DMP files. | high |
| `StModelItem_Resolve` | 0x102528D0 | 297 | yes | 3 | Builds a model item's model from its two read files. | high |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `StModelItemClear` calls `ErrorReport_NoOpVarargsA`, `sqFree`, `SqmdModel_Free`
- `StModelItem_ReadStart` calls `TextInputFiles_FileMngQueueFileNumKind2`, `ErrorReport_NoOpVarargsA`
- `StModelItem_Resolve` calls `ErrorReport_NoOpVarargsA`, `SqTimer_GetMicroseconds`, `TextInputFiles_FileMngReleaseAt1F0`, `SqmdDMB_Resolve`, `TextInputFiles_FileMngGetValueAt1F0`, `sqDebugPrintf`, `sqFree`
