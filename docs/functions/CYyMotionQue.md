# CYyMotionQue

Group: `CYy` (by the file name only). Source: `sdk/tree_src/CYyMotionQue.cpp`.

6 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CYyMotionQue::SetSlotMotion` | 0x1001A660 | 123 | yes | - | - | - |
| `CYyMotionQue_GetResource` | 0x1001A850 | 12 | yes | - | - | - |
| `CYyMotionQue::StartMotion` | 0x1001AB60 | 102 | yes | - | - | - |
| `CYyMotionQue::AppendSync` | 0x1001ACB0 | 72 | yes | - | Appends a synchronised motion entry and sets its field at +0x24. (reviewed as sub_1001ACB0) | low |
| `CYyMotionQue::SampleInto` | 0x1001B230 | 122 | yes | - | - | - |
| `CYyMotionQue::Update` | 0x1001B2E0 | 95 | yes | - | Advances the motion queue, finishing or removing entries whose motion has completed. (reviewed as sub_1001B2E0) | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CYyMotionQue::SetSlotMotion` calls `sub_10084620`, `CYyMotionQue::AppendSync`
- `CYyMotionQue_GetResource` calls nothing directly
- `CYyMotionQue::StartMotion` calls `ResourceHandle_IsResident`, `ResourceHandle_Deref`, `MotionQueue_ApplyPolicy`
- `CYyMotionQue::AppendSync` calls `sub_1001AD00`, `sub_1001B1A0`
- `CYyMotionQue::SampleInto` calls nothing directly
- `CYyMotionQue::Update` calls `QueTimeStep_Update`, `sub_1001B0F0`
