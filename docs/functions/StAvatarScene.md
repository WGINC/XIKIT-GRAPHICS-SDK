# StAvatarScene

Group: `St` (by the file name only). Source: `sdk/tree_src/StAvatarScene.cpp`.

Why the file has this name (data/unit_names.json): StAvatar_DrawScene / InitEntry / SetEntryTransform, the strings "static int s_%s_lightLocked[%d"

28 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `StAvatarScene_InitScene` | 0x10270B60 | 863 | yes | - | Initialises the avatar scene's state, cameras, lights and parts. | low |
| `StAvatar_UpdateTransform` | 0x10270EC0 | 106 | yes | - | Copies the selected part's values and updates its transform. | low |
| `StAvatarScene_UpdateScene` | 0x10270F30 | 242 | yes | - | Per-frame update of the avatar scene: modes, camera blend, models and part transforms. | low |
| `StAvatar_ApplyModes` | 0x10271030 | 118 | yes | - | Applies the avatar's current display modes. | low |
| `StAvatarScene_RotatePanZoomRoll` | 0x102710B0 | 542 | yes | - | Moves the current view by the mode given: turns it, slides it, zooms it or rolls it by the two amounts, scaled to the frame rate. | medium |
| `StAvatar_ApplyEffectFlags` | 0x102715F0 | 57 | yes | - | Applies the avatar's effect flags. | low |
| `StAvatar_UpdateAngles` | 0x10271630 | 442 | yes | - | Converts the view angles into part rotations and updates the transforms. | low |
| `StAvatar_DrawScene` | 0x102717F0 | 12 | yes | 1 | Draws the avatar scene. | medium |
| `scnFini` | 0x10271B40 | 48 | yes | - | - | - |
| `StAvatar_UpdateFlagBits` | 0x10271B90 | 63 | yes | - | Sets, clears or toggles flag bits of the avatar state. | medium |
| `StAvatar_SetOffsets` | 0x10271C30 | 47 | yes | - | Stores a pair of offsets for an index and flags the change. | low |
| `StAvatar_SetSceneValue1` | 0x10271C60 | 24 | yes | - | Forwards a value pair to the scene. | low |
| `StAvatar_SetSceneValue2` | 0x10271C80 | 24 | yes | - | Forwards a value pair to the scene's second setting. | low |
| `StAvatar_StoreParams` | 0x10271CA0 | 88 | yes | - | Stores nine parameter values in the avatar globals. | low |
| `StAvatar_StoreEntry` | 0x10271D00 | 108 | yes | - | Saves the current parameters into the entry for the current index. | low |
| `StAvatar_SelectEntry` | 0x10271D70 | 147 | yes | - | Switches the avatar to another stored parameter entry. | low |
| `scnGetFlags` | 0x10271E90 | 17 | yes | - | - | - |
| `StAvatar_InitEntry` | 0x10271F20 | 374 | yes | - | Initialises one avatar part's transforms from its table entry. | low |
| `StAvatarScene_NoOpA` | 0x102720A0 | 1 | yes | - | Does nothing. | medium |
| `StAvatar_SetEntryPosition` | 0x102725A0 | 107 | yes | - | Sets the position of one avatar part entry. | low |
| `StAvatar_SetEntryFlag` | 0x10272630 | 87 | yes | - | Sets or clears the scene flag for one avatar part. | low |
| `StAvatar_SetFlag3` | 0x102726E0 | 82 | yes | - | Sets or clears scene flag 3. | low |
| `StAvatar_SetEntryFlag2` | 0x10272750 | 149 | yes | - | Sets or clears the second flag of an avatar part. | low |
| `StAvatar_SetEntryColor` | 0x102727F0 | 136 | yes | - | Stores a colour for one avatar part and applies it to its scene object. | low |
| `StAvatar_SetEntryTransform` | 0x10272880 | 190 | yes | - | Sets an avatar part's values and transform from its source records. | low |
| `StAvatar_ToggleFlag168` | 0x102729E0 | 33 | yes | - | Sets or toggles the avatar's +0x168 flag. | low |
| `StAvatar_SelectIndex` | 0x10272A10 | 94 | yes | - | Selects the scene slot for an avatar part. | low |
| `StAvatarScene_NoOpB` | 0x10272BA0 | 1 | yes | - | Does nothing. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `StAvatarScene_InitScene` calls `SqsnScene_Init`, `SqsnScene_Preallocate`, `SqrdCamera_Init`, `sqxfXformTD_Init`, `sqxfXformTD_Update`, `SqsnScene_AddCamera`, `StAvatarScene_NoOpB`, `sqrdLight_Init`, `SqsnScene_AddLight`, `StAvatar_UpdateTransform`, `SqsnScene_SetByteAt28`, `SqsdGeneric_Init`, `SqsnScene_LayerAddItem`, `SqsnScene_ItemAddLight`, `StAvatar_InitEntry`, `SqQuat_SetIdentity`, `StAvatarScene_NoOpA`, `StAvatar_SetFlag3`, `StAvatar_SelectIndex`, `SqsnScene_SetItemByte19`
- `StAvatar_UpdateTransform` calls `sqxfXformTD_Update`
- `StAvatarScene_UpdateScene` calls `StAvatar_ApplyModes`, `StAvatar_ApplyEffectFlags`, `SceneCamera_UpdateCameraBlend`, `StAvatar_UpdateModels`, `SqQuatMul_Mul`, `sqxfXformTD_Update`, `SqMatrix4_ScaleAxes`
- `StAvatar_ApplyModes` calls `sub_102712E0`, `StAvatarScene_RotatePanZoomRoll`, `StAvatar_UpdateTransform`
- `StAvatarScene_RotatePanZoomRoll` calls `SqQuat_FromRotationY`, `SqQuat_FromRotationX`, `SqQuatMul_Mul`, `sqxfXformTD_Update`, `SqVec_SetXyz`, `SqQuatMul_RotateVec`, `SqQuat_FromRotationZ`, `SqQuat_Copy`
- `StAvatar_ApplyEffectFlags` calls `StAvatar_UpdateAngles`
- `StAvatar_UpdateAngles` calls `SqQuat_FromAxisAngle`, `SqQuatMul_Mul`, `SqQuat_Copy`, `sqxfXformTD_Update`, `SqMatrix4_ScaleAxes`
- `StAvatar_DrawScene` calls `sqsnSceneDraw`
- `scnFini` calls `SqObject_Release`, `SqsnScene_Free`
- `StAvatar_UpdateFlagBits` calls nothing directly
- `StAvatar_SetOffsets` calls nothing directly
- `StAvatar_SetSceneValue1` calls `SqsnScene_LayerPreallocate`
- `StAvatar_SetSceneValue2` calls `SqsnScene_ShadowPreallocate`
- `StAvatar_StoreParams` calls nothing directly
- `StAvatar_StoreEntry` calls nothing directly
- `StAvatar_SelectEntry` calls `StAvatar_StoreEntry`, `StAvatar_StoreParams`, `sub_102712E0`
- `scnGetFlags` calls nothing directly
- `StAvatar_InitEntry` calls `StAvatar_SetEntryColor`, `sqxfXformTD_Init`, `sqxfXformTD_Update`, `SqMatrix4_ScaleAxes`, `ModelMinMax_ComputeMinMax`, `StAvatar_SetEntryPosition`
- `StAvatarScene_NoOpA` calls nothing directly
- `StAvatar_SetEntryPosition` calls `SqBounds_GetCenter`, `sqxfXformTD_Update`, `SqMatrix4_ScaleAxes`
- `StAvatar_SetEntryFlag` calls `SqsnScene_SetByteAt28`
- `StAvatar_SetFlag3` calls `SqsnScene_SetItemByte18`
- `StAvatar_SetEntryFlag2` calls `SqQuat_Copy`, `SqQuat_Invert`, `SqQuatMul_Mul`
- `StAvatar_SetEntryColor` calls nothing directly
- `StAvatar_SetEntryTransform` calls `sub_1027EB10`, `SqVec_CopyVec3`, `SqQuat_Copy`
- `StAvatar_ToggleFlag168` calls nothing directly
- `StAvatar_SelectIndex` calls `SqsnScene_AddShadow`, `SqsnScene_SetItemDword28`
- `StAvatarScene_NoOpB` calls nothing directly
