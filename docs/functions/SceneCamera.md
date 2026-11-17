# SceneCamera

Group: `Scene` (by the file name only). Source: `sdk/tree_src/SceneCamera.cpp`.

Why the file has this name (data/unit_names.json): scnCameraGetInfo, SelectCamera, UpdateCameraBlend, the file "./cam_restrict.crf"

6 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `scnCameraGetInfo` | 0x10273370 | 62 | yes | - | - | - |
| `SceneCamera_SelectCamera` | 0x102733B0 | 216 | yes | - | Switches the avatar scene to another camera entry, blending over time when a blend time is set. | low |
| `SceneCamera_SetCameraEntry` | 0x10273490 | 193 | yes | - | Copies a camera's values and transform into one entry of the avatar scene's camera tables. | low |
| `SceneCamera_UpdateCameraBlend` | 0x10273560 | 360 | yes | - | Advances the blend between the previous and the new camera entry, and finishes the switch at the end. | low |
| `SceneCamera_SetVtable1099B138` | 0x102736D0 | 15 | yes | - | Sets the first word of the given object to a fixed table address. | low |
| `SceneCamera_ApplySceneToModel` | 0x102736E0 | 151 | yes | - | Applies the avatar scene's layer and lights to a model. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `scnCameraGetInfo` calls nothing directly
- `SceneCamera_SelectCamera` calls `SqsnScene_SetCursorIfInRange`, `SqsnScene_SetEntryField8`, `SceneCamera_SetCameraEntry`
- `SceneCamera_SetCameraEntry` calls `sub_1027EB10`, `SqVec_CopyVec3`, `SqQuat_Copy`, `sqxfXformTD_Update`
- `SceneCamera_UpdateCameraBlend` calls `SqVec_LerpFactor`, `sub_1027B2C0`, `sqxfXformTD_Update`, `SqsnScene_SetCursorIfInRange`, `SqsnScene_SetEntryField8`
- `SceneCamera_SetVtable1099B138` calls nothing directly
- `SceneCamera_ApplySceneToModel` calls `SqmdModel_Link`, `SqmdModel_SetLayerSort`, `SqmdModel_AddShadowLightInLayer`, `StAvatar_SelectIndex`, `SqmdModel_AddIllumLight`
