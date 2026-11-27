# CMoElem

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoElem.cpp`.

34 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoElem::GetRuntimeClass_variant0` | 0x100353C0 | 6 | yes | - | - | - |
| `CMoElem::Slot13DoNothing` | 0x10036A80 | 3 | yes | - | The default of virtual slot 13: does nothing (takes 4 bytes of arguments, unused). (reviewed as game_10036A80) | low |
| `CMoElem::Slot14DoNothing` | 0x10036A90 | 3 | yes | - | The default of virtual slot 14: does nothing (takes 4 bytes of arguments, unused). (reviewed as game_10036A90) | low |
| `CMoElem::Slot15ReturnZero` | 0x10036AA0 | 3 | yes | - | The default of virtual slot 15: returns 0. (reviewed as game_10036AA0) | low |
| `CMoElem::Slot19DoNothing` | 0x10036AB0 | 1 | yes | - | The default of virtual slot 19: does nothing. (reviewed as game_10036AB0) | low |
| `CMoElem::GetRuntimeClass_variant1` | 0x1003E690 | 6 | yes | - | - | - |
| `CMoElem::GetRuntimeClass_variant2` | 0x10041000 | 6 | yes | - | - | - |
| `CMoElem::CMoElemFamily_IsKind0` | 0x10041120 | 14 | yes | - | - | - |
| `CMoElem::GetRuntimeClass_variant3` | 0x100426A0 | 6 | yes | - | - | - |
| `CMoElem::GetRuntimeClass_variant4` | 0x100426D0 | 6 | yes | - | - | - |
| `CMoElem::GetRuntimeClass_variant5` | 0x10043190 | 6 | yes | - | - | - |
| `CMoElem::GetRuntimeClass_variant6` | 0x10043570 | 6 | yes | - | - | - |
| `CMoElem::GetRuntimeClass_variant7` | 0x10043700 | 6 | yes | - | - | - |
| `CMoElem::GetRuntimeClass_variant8` | 0x10044880 | 6 | yes | - | - | - |
| `CMoElem::Constructor` | 0x10044890 | 188 | yes | - | - | - |
| `CMoElem::ScalarDeletingDtor` | 0x10044950 | 30 | yes | - | - | - |
| `CMoElem::CMoElemFamily_SharedCleanup` | 0x10044970 | 294 | yes | - | - | - |
| `CMoElem::IsSourceAt0FCTest` | 0x10044AC0 | 30 | yes | - | Returns the boolean result of game_100539E0 on the first word of the object at this+0xFC, or false when there is none. (reviewed as game_10044AC0) | low |
| `CMoElem::AdvanceTimer` | 0x10044AE0 | 318 | yes | 4 | Advances the element's timer by the frame delta and acts when it expires. (reviewed as game_10044AE0) | medium |
| `CMoElem::InvertInPlace` | 0x10045800 | 237 | yes | - | Inverts the 4x4 matrix in place. (reviewed as game_10045800) | medium |
| `CMoElem::CheckAt138ThenCall` | 0x100458F0 | 48 | yes | - | Resets the float at +0x138 to 1.0 when it is below 0.01, otherwise calls game_100555B0 with the float at +0x12C. (reviewed as game_100458F0) | low |
| `YmElem_BuildDrawMatrixAndTest` | 0x10045920 | 271 | yes | - | - | - |
| `CMoElem::PrepareDraw` | 0x10045A40 | 147 | yes | 5 | Computes the element's draw key and draw matrix for this frame, and tests it. (reviewed as game_10045A40) | medium |
| `YmElem_SetupDevice` | 0x100467E0 | 2643 | yes | 0 | - | - |
| `CMoElem::Slot18DoNothing` | 0x100472E0 | 1 | yes | - | The default of virtual slot 18: does nothing. (reviewed as game_100472E0) | low |
| `YmElem_RestoreDevice` | 0x100472F0 | 234 | yes | 0 | - | - |
| `CMoElem::GetActiveField0A4` | 0x100473F0 | 95 | yes | - | Returns the value at offset 0xA4 of the element's active object. (reviewed as game_100473F0) | low |
| `CMoElem::GetAddr78` | 0x10047450 | 52 | yes | - | Returns the address at offset 0x78 of the element's active object. (reviewed as game_10047450) | low |
| `CMoElem::GetAddr84` | 0x10047490 | 54 | yes | - | Returns the address at offset 0x84 of the element's active object. (reviewed as game_10047490) | low |
| `CMoElem::GetRuntimeClass_variant9` | 0x10047550 | 6 | yes | - | - | - |
| `CMoElem::GetRuntimeClass_variant10` | 0x10047570 | 6 | yes | - | - | - |
| `CMoElem::GetRuntimeClass_variant11` | 0x100548A0 | 6 | yes | - | - | - |
| `CMoElem::GetRuntimeClass_variant12` | 0x100562D0 | 6 | yes | - | - | - |
| `CMoElem::GetRuntimeClass_variant13` | 0x10064160 | 6 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoElem::GetRuntimeClass_variant0` calls nothing directly
- `CMoElem::Slot13DoNothing` calls nothing directly
- `CMoElem::Slot14DoNothing` calls nothing directly
- `CMoElem::Slot15ReturnZero` calls nothing directly
- `CMoElem::Slot19DoNothing` calls nothing directly
- `CMoElem::GetRuntimeClass_variant1` calls nothing directly
- `CMoElem::GetRuntimeClass_variant2` calls nothing directly
- `CMoElem::CMoElemFamily_IsKind0` calls nothing directly
- `CMoElem::GetRuntimeClass_variant3` calls nothing directly
- `CMoElem::GetRuntimeClass_variant4` calls nothing directly
- `CMoElem::GetRuntimeClass_variant5` calls nothing directly
- `CMoElem::GetRuntimeClass_variant6` calls nothing directly
- `CMoElem::GetRuntimeClass_variant7` calls nothing directly
- `CMoElem::GetRuntimeClass_variant8` calls nothing directly
- `CMoElem::Constructor` calls `CMoOtTask::Constructor`, `OcclusionQuery_Init`
- `CMoElem::ScalarDeletingDtor` calls `CMoElem::CMoElemFamily_SharedCleanup`, `SharedDeleteHelper`
- `CMoElem::CMoElemFamily_SharedCleanup` calls `game_100481D0`, `CMoGeneratorClone::UnlinkElemListA`, `CMoResource::ReleaseChain`, `MoRes_FreeIfUnreferenced`, `NodePool_ReleaseNode`, `game_1006C110`, `game_1006C270`, `game_10055250`, `CMoTask::Destructor`
- `CMoElem::IsSourceAt0FCTest` calls `Generator_IsFlag400OrField22Zero`
- `CMoElem::AdvanceTimer` calls `CMoGeneratorClone::ExecuteCmdList`, `CMoElem::GetActiveField0A4`, `YmGenerater_UpdateAttachIfPresent`, `game_1004A980`
- `CMoElem::InvertInPlace` calls nothing directly
- `CMoElem::CheckAt138ThenCall` calls `game_100555B0`
- `YmElem_BuildDrawMatrixAndTest` calls `RegisterWithProcessor`, `game_10313486`
- `CMoElem::PrepareDraw` calls `CMoElem::AdvanceTimer`, `YmElem_ComputeViewDepthKey`, `ElemFog_UpdateTransform`, `game_10045190`, `YmElem_BuildDrawMatrixAndTest`, `CMoElem::CheckAt138ThenCall`
- `YmElem_SetupDevice` calls `CMoDX::SetViewMatrix`, `game_10046550`, `RegisterWithProcessor`, `CMoDX::SetWorldMatrix`, `ElemFog_GetFlaggedMatrix`, `CMoElem::GetActiveField0A4`, `CMoElem::InvertInPlace`, `XiZone::GetDirLight`, `CDx::SetLight`, `XiZone::GetDirLightsForArea`, `XiZone::GetDirLights`, `D3DXMatrixPerspectiveFovLH_static`, `XiZone::GetFog`, `Fog_SetRenderStates`, `XiZone::GetAmbient`, `MoDX_SetInvalid`, `game_10313486`, `StateBlock_ApplyTSS`
- `CMoElem::Slot18DoNothing` calls nothing directly
- `YmElem_RestoreDevice` calls `game_10046550`, `CMoDX::SetViewMatrix`, `MoDX_SetInvalid`, `game_10313486`, `StateBlockHolder_ApplyRenderStates`
- `CMoElem::GetActiveField0A4` calls nothing directly
- `CMoElem::GetAddr78` calls nothing directly
- `CMoElem::GetAddr84` calls nothing directly
- `CMoElem::GetRuntimeClass_variant9` calls nothing directly
- `CMoElem::GetRuntimeClass_variant10` calls nothing directly
- `CMoElem::GetRuntimeClass_variant11` calls nothing directly
- `CMoElem::GetRuntimeClass_variant12` calls nothing directly
- `CMoElem::GetRuntimeClass_variant13` calls nothing directly
