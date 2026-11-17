# ElemFog

Group: `Elem` (by the file name only). Source: `sdk/tree_src/ElemFog.cpp`.

Why the file has this name (data/unit_names.json): Fog_SetRenderStates, Zone_UpdateFogAmbient, YmElem_DrawWithOwnProjection, RegisterWithProcessor

9 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ElemFog_ComputeWorldPos` | 0x10044C40 | 174 | yes | - | Computes the element's position scaled by its matrix row values and writes it to the output. | low |
| `ElemFog_IsActive` | 0x10044CF0 | 68 | yes | - | Tests whether the element is active. | low |
| `ElemFog_UpdateTransform` | 0x10044D40 | 450 | yes | - | Updates the element's transform on the processor for this frame. | medium |
| `YmElem_ComputeViewDepthKey` | 0x10044F10 | 628 | yes | - | - | - |
| `ElemFog_GetFlaggedMatrix` | 0x10045C50 | 162 | yes | - | Returns the matrix the element's flags select. | low |
| `RegisterWithProcessor` | 0x10045D40 | 814 | yes | - | - | - |
| `YmElem_DrawWithOwnProjection` | 0x10046070 | 775 | yes | 0 | Draws an element between device setup and restore, with additive blending and, when its flags ask, its own perspective projection. | medium |
| `Zone_UpdateFogAmbient` | 0x10046380 | 335 | yes | - | Sets the zone's fog and ambient colours from the zone's values. | low |
| `Fog_SetRenderStates` | 0x100464D0 | 88 | yes | 0 | Sets the Direct3D fog colour, start and end render states. | high |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ElemFog_ComputeWorldPos` calls `CMoElem::GetActiveField0A4`, `CMoElem::GetAddr78`
- `ElemFog_IsActive` calls nothing directly
- `ElemFog_UpdateTransform` calls `ElemFog_IsActive`, `MoProcessor_CallVSlot49`, `CMoElem::GetAddr84`
- `YmElem_ComputeViewDepthKey` calls `CMoElem::GetActiveField0A4`, `ElemFog_ComputeWorldPos`
- `ElemFog_GetFlaggedMatrix` calls nothing directly
- `RegisterWithProcessor` calls `MoProcessor_CallVSlot49`, `ElemFog_GetFlaggedMatrix`, `CMoElem::GetActiveField0A4`
- `YmElem_DrawWithOwnProjection` calls `SkyDome_ScaleAlpha`, `YmElem_SetupDevice`, `CDx::GetTransformCached`, `RegisterWithProcessor`, `D3DXMatrixPerspectiveFovLH_static`, `YmElem_RestoreDevice`
- `Zone_UpdateFogAmbient` calls `XiZone::GetFog`, `XiZone::GetAmbient`
- `Fog_SetRenderStates` calls nothing directly
