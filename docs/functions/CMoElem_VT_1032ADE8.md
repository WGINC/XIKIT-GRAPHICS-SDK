# CMoElem_VT_1032ADE8

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoElem_VT_1032ADE8.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoElem_VT_1032ADE8::vf18` | 0x10041AF0 | 296 | yes | 0 | - | - |
| `CXiSub_10041E70_Ctor` | 0x10041F40 | 154 | yes | - | - | - |
| `CMoElem_VT_1032ADE8::ScalarDeletingDtor` | 0x10041FE0 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoElem_VT_1032ADE8::vf18` calls `CMoAttachments::GetTarget`, `ElemFog_ComputeWorldPos`, `CXiActor::NameCalc`, `CDx::GetRenderTargetTop`, `sub_10041C20`
- `CXiSub_10041E70_Ctor` calls `CMoElem::Constructor`, `CYyObject_IsKindOf`, `sub_10311FF1`
- `CMoElem_VT_1032ADE8::ScalarDeletingDtor` calls `CMoElem::CMoElemFamily_SharedCleanup`, `SharedDeleteHelper`
