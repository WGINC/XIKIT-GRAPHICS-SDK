# CMoD3mElemFlag200000

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoD3mElemFlag200000.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoD3mElemFlag200000::RebuildBlendWeights` | 0x10040E70 | 316 | yes | 1 | - | - |
| `CMoD3mElemFlag200000::Ctor` | 0x10052E90 | 27 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoD3mElemFlag200000::RebuildBlendWeights` calls `CMoDX::SetWorldMatrix`, `BeginEffectOffscreenPass`, `CMoElemFamily_SharedEarlyExit`, `CMoDistModelElem::DrawBatches`, `ElemFog_ComputeWorldPos`, `YmElem_RestoreDevice`, `sub_1006A450`, `CMoDX::PopViewMatrix`, `sub_1006A0E0`, `YmElem_SetupDevice`, `EndEffectOffscreenPass`
- `CMoD3mElemFlag200000::Ctor` calls `CMoElem::Constructor`
