# CMoDamValueProgElem

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoDamValueProgElem.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoDamValueProgElem::Slot18DrawTextAtTarget` | 0x10041AF0 | 296 | yes | 0 | Draws the element's text at its target actor's projected position. (reviewed as sub_10041AF0) | medium |
| `CMoDamValueProgElem_Construct` | 0x10041F40 | 154 | yes | - | Constructor: the damage value's text and colour from its source. | high |
| `CMoDamValueProgElem::ScalarDeletingDtor` | 0x10041FE0 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoDamValueProgElem::Slot18DrawTextAtTarget` calls `CMoAttachments::GetTarget`, `ElemFog_ComputeWorldPos`, `CXiActor::NameCalc`, `CDx::GetRenderTargetTop`, `sub_10041C20`
- `CMoDamValueProgElem_Construct` calls `CMoElem::Constructor`, `CYyObject_IsKindOf`, `sub_10311FF1`
- `CMoDamValueProgElem::ScalarDeletingDtor` calls `CMoElem::CMoElemFamily_SharedCleanup`, `SharedDeleteHelper`
