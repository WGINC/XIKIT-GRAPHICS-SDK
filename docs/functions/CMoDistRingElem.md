# CMoDistRingElem

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoDistRingElem.cpp`.

6 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoDistRingElem::GetRuntimeClass` | 0x10043710 | 6 | yes | - | - | - |
| `CMoDistRingElem::AllocRingGeometry` | 0x10043720 | 642 | yes | 0 | - | - |
| `CMoDistRingElem::Construct` | 0x10052FD0 | 27 | yes | - | Constructs the distortion ring element and sets its vtable and type word. (reviewed as game_10052FD0) | medium |
| `CMoDistRingElem::IsKind5` | 0x10052FF0 | 15 | yes | - | Returns whether the argument is 5, the kind this element class answers to. (reviewed as game_10052FF0) | medium |
| `CMoDistRingElem::set_field_1B6` | 0x10053000 | 13 | yes | - | - | - |
| `CMoDistRingElem::ScalarDeletingDtor` | 0x10053010 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoDistRingElem::GetRuntimeClass` calls nothing directly
- `CMoDistRingElem::AllocRingGeometry` calls `Allocator_Generic`, `RegisterWithProcessor`, `CMoDistMorphElem_ValidateMorphData`, `MoDX_SetInvalid`, `game_10313486`, `StateBlock_ApplyTSS`, `Gfx_CalcFVFStride`, `CDx::DrawPrimitiveUP`, `operator_delete`
- `CMoDistRingElem::Construct` calls `CMoElem::Constructor`
- `CMoDistRingElem::IsKind5` calls nothing directly
- `CMoDistRingElem::set_field_1B6` calls nothing directly
- `CMoDistRingElem::ScalarDeletingDtor` calls `CMoElem::CMoElemFamily_SharedCleanup`, `SharedDeleteHelper`
