# CMoDistModelElem

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoDistModelElem.cpp`.

11 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoDistModelElem::IsDistortedMode` | 0x1003FCB0 | 28 | yes | - | Tests whether the element's mode nibble is in the distorted range. (reviewed as sub_1003FCB0) | low |
| `CMoDistModelElem::GetVertexBase` | 0x1003FCE0 | 4 | yes | - | Returns the address of the element's vertex data block at +0x38. (reviewed as sub_1003FCE0) | low |
| `CMoDistModelElem::GetDataEnd` | 0x1003FCF0 | 117 | yes | - | Returns the end of the element's data block, from its counts and mode. (reviewed as sub_1003FCF0) | low |
| `CMoDistModelElem::DrawBatches` | 0x10040220 | 1006 | yes | 0 | Draws a distance-model element's vertex batches with its texture factor colour, texture-stage states and per-batch textures. (reviewed as sub_10040220) | medium |
| `CMoDistModelElem::DrawMesh` | 0x10040670 | 1235 | yes | 1 | - | - |
| `CMoDistModelElem::GetRuntimeClass` | 0x100431A0 | 6 | yes | - | - | - |
| `CMoDistModelElem::Draw` | 0x100431B0 | 338 | yes | 0 | Draws the distant model element through the processor, applying its transform and render state. (reviewed as sub_100431B0) | medium |
| `CMoDistModelElem::Init` | 0x10052F20 | 27 | yes | - | Constructs the base element and sets the CMoDistModelElem vtable and its field at 0x176. (reviewed as sub_10052F20) | medium |
| `CMoDistModelElem::IsKind4` | 0x10052F40 | 15 | yes | - | Returns whether the argument is 4, the kind this element class answers to. (reviewed as sub_10052F40) | medium |
| `CMoDistModelElem::set_field_194` | 0x10052F50 | 13 | yes | - | - | - |
| `CMoDistModelElem::ScalarDeletingDtor` | 0x10052F60 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoDistModelElem::IsDistortedMode` calls nothing directly
- `CMoDistModelElem::GetVertexBase` calls nothing directly
- `CMoDistModelElem::GetDataEnd` calls `CMoDistModelElem::GetVertexBase`
- `CMoDistModelElem::DrawBatches` calls `CMoDistModelElem::GetDataEnd`, `MoDX_SetInvalid`, `sub_10313486`, `StateBlock_ApplyTSS`, `CMoVuElem_Draw`, `MoProcessor_CallVSlot49`, `CDx::SetTransform`, `CMoDistModelElem::GetVertexBase`, `TexRef_SetTexture`
- `CMoDistModelElem::DrawMesh` calls `CMoDistModelElem::GetDataEnd`, `MoDX_SetInvalid`, `sub_10313486`, `StateBlock_ApplyTSS`, `CMoVuElem_Draw`, `MoProcessor_CallVSlot49`, `CDx::SetTransform`, `CMoDistModelElem::GetVertexBase`, `TextureHolder_BindWarped`, `CMoDistModelElem::IsDistortedMode`
- `CMoDistModelElem::GetRuntimeClass` calls nothing directly
- `CMoDistModelElem::Draw` calls `MoProcessor_CallVSlot49`, `CDx::SetTransform`, `MoDX_SetInvalid`, `sub_10313486`, `StateBlock_ApplyTSS`, `RegisterWithProcessor`, `XiZone_DrawModelAtMatrix`
- `CMoDistModelElem::Init` calls `CMoElem::Constructor`
- `CMoDistModelElem::IsKind4` calls nothing directly
- `CMoDistModelElem::set_field_194` calls nothing directly
- `CMoDistModelElem::ScalarDeletingDtor` calls `CMoElem::CMoElemFamily_SharedCleanup`, `SharedDeleteHelper`
