# CMoDistMorphElem

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoDistMorphElem.cpp`.

7 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoDistMorphElem::ApplyMorph` | 0x1003F440 | 1094 | yes | 0 | - | - |
| `CMoDistMorphElem::ComputeMorphHandle` | 0x1003F8A0 | 624 | yes | - | - | - |
| `CMoDistMorphElem::GetRuntimeClass` | 0x10043580 | 6 | yes | - | - | - |
| `CMoDistMorphElem::Construct` | 0x10052E20 | 27 | yes | - | Constructs a distance-morph element with its type id. (reviewed as game_10052E20) | medium |
| `CMoDistMorphElem::IsKind6` | 0x10052E40 | 15 | yes | - | Returns whether the argument is 6, the kind this element class answers to. (reviewed as game_10052E40) | medium |
| `CMoDistMorphElem::set_field_1C0` | 0x10052E50 | 13 | yes | - | - | - |
| `CMoDistMorphElem::ScalarDeletingDtor` | 0x10052E60 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoDistMorphElem::ApplyMorph` calls `TextureHolder_BindWarped`, `CMoDistMorphElem::ComputeMorphHandle`, `DynVB_Reserve`, `DynVB_Lock`, `DynVB_Unlock`, `Mem_FreeObject`, `MoDX_SetInvalid`, `game_10313486`, `StateBlock_ApplyTSS`, `MoProcessor_CallVSlot49`, `CDx::SetTransform`, `CMoVuElem_Draw`
- `CMoDistMorphElem::ComputeMorphHandle` calls `Mem_AllocObject`
- `CMoDistMorphElem::GetRuntimeClass` calls nothing directly
- `CMoDistMorphElem::Construct` calls `CMoD3bElem::Ctor`
- `CMoDistMorphElem::IsKind6` calls nothing directly
- `CMoDistMorphElem::set_field_1C0` calls nothing directly
- `CMoDistMorphElem::ScalarDeletingDtor` calls `CMoD3bElem_Dtor`, `SharedDeleteHelper`
