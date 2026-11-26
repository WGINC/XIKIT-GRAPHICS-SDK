# CMoD3mLightmapElem

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoD3mLightmapElem.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoD3mLightmapElem::DrawLightmapPass` | 0x10040E70 | 316 | yes | 1 | Draws the element's model into the effects' offscreen target and projects it onto the ground. (reviewed as game_10040E70) | high |
| `CMoD3mLightmapElem::Ctor` | 0x10052E90 | 27 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoD3mLightmapElem::DrawLightmapPass` calls `CMoDX::SetWorldMatrix`, `BeginEffectOffscreenPass`, `CMoElemFamily_SharedEarlyExit`, `CMoDistModelElem::DrawBatches`, `ElemFog_ComputeWorldPos`, `YmElem_RestoreDevice`, `game_1006A450`, `CMoDX::PopViewMatrix`, `game_1006A0E0`, `YmElem_SetupDevice`, `EndEffectOffscreenPass`
- `CMoD3mLightmapElem::Ctor` calls `CMoElem::Constructor`
