# StAvatarCore

Group: `St` (by the file name only). Source: `sdk/tree_src/StAvatarCore.cpp`.

Why the file has this name (data/unit_names.json): StAvatarRender / Fini, StAvatar_* (the 3D avatar of the lobby)

42 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `StAvatar_Reset` | 0x1024D400 | 97 | yes | - | Resets an avatar's indices and channel entries. | medium |
| `StAvatar_RegisterTriggers` | 0x1024D470 | 37 | yes | - | Registers the avatar's trigger callbacks. | medium |
| `StAvatar_SetTableValues` | 0x1024D4A0 | 149 | yes | - | Sets the avatar's table values for a pose index. | low |
| `StAvatar_SetChannel` | 0x1024D540 | 127 | yes | - | Sets an avatar channel value for a pose index. | low |
| `StAvatar_SetPending` | 0x1024D5C0 | 73 | yes | 6 | Sets the avatar's pending pose, unloading first when it is loaded. | low |
| `StAvatar_Unload` | 0x1024D610 | 150 | yes | - | Releases an avatar's pose data and resets it to the unloaded state. | medium |
| `StAvatar_ApplyChannels` | 0x1024D6B0 | 144 | yes | - | Applies the avatar's channel values for the current time. | low |
| `StAvatar_SetTransition` | 0x1024D740 | 71 | yes | - | Starts a timed change of the avatar's value to a target. | medium |
| `StAvatar_StopAndFreeBuffers` | 0x1024D790 | 190 | yes | 5 | - | - |
| `StAvatar_ResolveItemsAndStart` | 0x1024D850 | 369 | yes | 4 | Resolves the avatar's pending channel and model items and, once its model is resolved, sets its modes and starts it. | medium |
| `StAvatar_FormatNames` | 0x1024D9D0 | 54 | yes | - | Formats the names of the avatar's unused joints. | low |
| `StAvatar_Update` | 0x1024DB60 | 417 | yes | 2 | Per-frame update of the avatar: level, timers, channels, scene, view, input and triggers. | medium |
| `StAvatar_UpdateInput` | 0x1024DD10 | 272 | yes | - | Reads the controller input and updates the avatar's camera and heading. | medium |
| `StAvatar_UpdateCameraYaw` | 0x1024DE20 | 441 | yes | - | Turns the camera's yaw and pitch from the analog input. | low |
| `StAvatar_UpdateCameraFollow` | 0x1024DFE0 | 661 | yes | - | Moves the camera to follow the avatar's target object. | low |
| `StAvatarCore_MoveByAnalogStick` | 0x1024E280 | 1176 | yes | - | Moves and turns the avatar from the analog stick, choosing its movement state by how far the stick is pushed. | medium |
| `StAvatar_SetFlagsBoth` | 0x1024E720 | 50 | yes | - | Applies one update to the two blocks of an avatar. | low |
| `StAvatar_GetCameraMatrix` | 0x1024F050 | 89 | yes | - | Returns the camera matrix the avatar uses for its view. | low |
| `StAvatar_UpdateHeading` | 0x1024F0B0 | 518 | yes | - | Steers the avatar towards its target position and sets its heading. | low |
| `StAvatar_ProjectNodes` | 0x1024F2C0 | 792 | yes | - | Projects the avatar's nodes to screen space and finds the nearest. | low |
| `StAvatar_UpdateSteer` | 0x1024F5E0 | 795 | yes | - | Steers the avatar from the analog input and clamps its position. | low |
| `StAvatar_SetViewFromDancerCamera` | 0x1024F900 | 772 | yes | 1 | - | - |
| `StAvatar_AdvanceTimers` | 0x1024FC10 | 475 | yes | - | Advances the avatar's timers and clamps them to their range. | low |
| `StAvatar_ProcessTriggers` | 0x1024FEC0 | 140 | yes | - | Runs the avatar's trigger opcodes up to the current time. | medium |
| `StAvatar_GetOffset` | 0x1024FF50 | 213 | yes | - | Returns the avatar's offset vector for the current pose. | low |
| `StAvatar_RenderIfEnabled` | 0x10250190 | 44 | yes | 1 | Records the frame time and renders the avatar when enabled. | low |
| `StAvatarRender` | 0x102501C0 | 267 | yes | 0 | - | - |
| `StAvatar_UpdateNodes` | 0x102502D0 | 497 | yes | - | Updates the avatar's five node positions and its transform. | low |
| `StAvatarFini` | 0x102504D0 | 162 | yes | 0 | - | - |
| `StAvatar_ResetChannels` | 0x10250580 | 212 | yes | - | Resets the avatar's channel entries. | low |
| `StAvatar_SetFlagBit` | 0x10250660 | 86 | yes | - | Sets, clears or toggles one of the avatar's flag bits. | low |
| `StAvatar_SetStopped` | 0x102506C0 | 155 | yes | - | Sets or clears the avatar's flag 2, running the matching afterimage tasks. | low |
| `StAvatar_SetField10` | 0x10250760 | 43 | yes | - | Stores a value at +0x10, applying it through 0x10270840 when the avatar is running. | low |
| `StAvatar_SetField14` | 0x10250790 | 43 | yes | - | Stores a value at +0x14, applying it through 0x102709E0 when the avatar is running. | low |
| `StAvatar_StoreMode` | 0x102507C0 | 61 | yes | - | Stores the avatar's mode and restarts its timer from the table. | low |
| `StAvatar_Start` | 0x10250800 | 443 | yes | - | Starts the avatar's pose with its channels reset. | low |
| `StAvatar_SetModelFlags` | 0x102509C0 | 115 | yes | - | Sets or clears the flags of the avatar's two models. | low |
| `StAvatar_SetModelItemFlags` | 0x10250A40 | 156 | yes | - | Sets or clears one flag on each item of a model and records it in the avatar. | low |
| `StAvatar_SetLock` | 0x10250B10 | 240 | yes | - | Locks or unlocks the avatar's channel with a target value. | low |
| `StAvatar_GetField20` | 0x10250C00 | 25 | yes | - | Reads the field at +0x20 when the avatar is active. | low |
| `StAvatar_InitIndices` | 0x10250D80 | 44 | yes | - | Initialises an avatar's index block to its unset state. | low |
| `StChannelItem_Load` | 0x10250DB0 | 91 | yes | - | Starts loading a channel item's file. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `StAvatar_Reset` calls `Mdl_FreeAllSlots`, `Mdl_ReleaseEntries`, `StChannel_ClearFlags`
- `StAvatar_RegisterTriggers` calls `StTrigger_RegisterCallbacks`
- `StAvatar_SetTableValues` calls `StChannelItem_Load`
- `StAvatar_SetChannel` calls `StChannelItem_Load`
- `StAvatar_SetPending` calls `StAvatar_StopAndFreeBuffers`, `StAvatar_Unload`, `StAvatar_SetTransition`
- `StAvatar_Unload` calls `StAvatar_GetValue2B`, `StAvatar_Reset`, `StAvatar_ReleaseResources`, `TextInputFiles_FileMngReleaseAt1F0`, `StAvatar_ApplyChannels`, `TextInputFiles_FileMngGetValueAt1F0`, `StAvatar_SetChannel`, `StModelItem_ReadStart`
- `StAvatar_ApplyChannels` calls `StModelItem_Activate`, `StChannel_RegisterItem`, `Mdl_SetChannelFlag80`
- `StAvatar_SetTransition` calls nothing directly
- `StAvatar_StopAndFreeBuffers` calls `sub_101C4C20`, `sub_101C4AC0`, `StAvatar_ResolveItemsAndStart`, `StAvatar_CheckBuffersReady`, `StModelItem_CheckFileRefs`, `StChannel_MarkIfLoaded`
- `StAvatar_ResolveItemsAndStart` calls `StChannelItemResolve`, `StModelItem_Resolve`, `StAvatar_ApplyChannels`, `LobbyThread_SendCmd6IfRunning`, `sub_1024DA10`, `StAvatar_SetField10`, `StAvatar_SetField14`, `StAvatar_StoreMode`, `StAvatar_Start`, `StAvatar_FormatNames`, `StAvatar_ResetChannels`, `StAvatar_SetStopped`, `CYyMusicLoadTask::StartTrack`, `StAvatar_SetTransition`
- `StAvatar_FormatNames` calls `sub_10311FF1`
- `StAvatar_Update` calls `SqTimer_GetMicroseconds`, `StAvatar_ResolveItemsAndStart`, `NetCellFont_TestCommand36CF60`, `StAvatar_Start`, `StAvatar_AdvanceTimers`, `sub_1024FDF0`, `StChannel_ApplyItem`, `StAvatar_ComputeRatioValue`, `StAvatarScene_UpdateScene`, `sub_10250030`, `StAvatar_SetViewFromDancerCamera`, `StAvatar_UpdateInput`, `StAvatar_ProcessTriggers`
- `StAvatar_UpdateInput` calls `NetCellFont_TestCommand36CF60`, `sub_10311C2C`, `StAvatar_SetOffsets`, `sub_10123970`, `StAvatar_UpdateSteer`, `StAvatar_UpdateCameraFollow`, `StAvatar_UpdateCameraYaw`, `StAvatarCore_MoveByAnalogStick`
- `StAvatar_UpdateCameraYaw` calls `scnGetFlags`, `scnCameraGetInfo`, `sub_10123970`, `Camera_GetFrameScale`, `SqQuat_FromRotationY`, `SqQuatMul_Mul`, `SqQuat_Copy`, `SqQuat_FromRotationX`, `sqxfXformTD_Update`
- `StAvatar_UpdateCameraFollow` calls `scnCameraGetInfo`, `SqQuat_Copy`, `SqmdModel_GetItemKind2`, `SqBoneTransform_TransformOrigin`, `SqQuatMul_RotateVec`, `SqQuat_SetIdentity`, `SqQuat_FromRotationY`, `SqQuatMul_Mul`, `sub_1027AEC0`, `SqQuat_Negate`, `sqxfXformTD_Update`
- `StAvatarCore_MoveByAnalogStick` calls `sub_10123970`, `StAvatar_UpdateHeading`, `Chasm_ApplyAtCurrentIndex`, `sub_1024E760`, `StAvatar_GetCameraMatrix`, `StAvatar_SetFlagsBoth`, `StAvatar_ProjectNodes`, `SqVec_Relink`, `Chn_GetSubIndex`, `sub_1027D110`, `StTrigger_FindIndexAtLeast`
- `StAvatar_SetFlagsBoth` calls `StModelItem_SetPositionAndScale`
- `StAvatar_GetCameraMatrix` calls `scnGetFlags`, `scnCameraGetInfo`, `SqMatrixConnect_SetIdentity`, `SqMatrixConnect_TransformVec3`
- `StAvatar_UpdateHeading` calls `SqMatrixConnect_SetIdentity`, `SqMatrixConnect_TransformVec3`, `SqVec_CopyVec3`, `SqVec_ScaleVec3ByInverseOf102746C0`, `sub_10027530`, `sub_10123970`, `StAvatar_SetFlagsBoth`, `StAvatar_SetLock`
- `StAvatar_ProjectNodes` calls `scnGetFlags`, `scnCameraGetInfo`, `M4fTranspose`, `Mat4x4_TransformVec4`
- `StAvatar_UpdateSteer` calls `sub_10123970`, `NetCellFont_TestCommand36CF60`, `Camera_GetFrameScale`, `StAvatar_SetFlagsBoth`, `StAvatar_ProjectNodes`, `SqVec_Relink`, `Chn_GetSubIndex`, `sub_1027D110`, `StTrigger_FindIndexAtLeast`
- `StAvatar_SetViewFromDancerCamera` calls `MathVector_ReturnThis`, `scnGetFlags`, `scnCameraGetInfo`, `Camera_GetMatrix154Ptr`, `sub_100151F0`, `sub_1027EB10`, `M4fTranspose`, `sqMatrix4_10280140`, `M4fTransform`, `sub_100150D0`, `Camera_GetViewMatrixPtr`, `CDx::SetTransform`, `MathVector_Nop`
- `StAvatar_AdvanceTimers` calls `StModelItem_SetVec78`, `StChannel_SetValue9C`
- `StAvatar_ProcessTriggers` calls `StAvatar_ComputeRatioValue`, `sqopSystemActivate`, `StAvatar_GetOffset`, `StTrigger_ProcessOpcodesUpToTime`
- `StAvatar_GetOffset` calls `SqmdModel_GetItemKind2`, `SqBoneTransform_TransformOrigin`
- `StAvatar_RenderIfEnabled` calls `SqTimer_GetMicroseconds`, `StAvatarRender`
- `StAvatarRender` calls `StAvatar_UpdateNodes`, `sub_10281500`, `___setargv_24`, `___setargv_9`, `SqgxContext_Nop`, `___setargv_16`, `StAvatar_DrawScene`, `StAvatar_IsFlag20`, `sqgxTextureSet`, `sqgxColor`, `sqgxBlendLin`, `sqgxZTest`, `sub_10280DE0`
- `StAvatar_UpdateNodes` calls `StAvatar_SetEntryColor`, `StAvatar_GetField20`, `SqQuat_QuatFromEuler`, `SqQuat_Copy`, `sqxfXformTD_Update`, `ZoneMap_GetAddr0E4`, `StAvatar_SetEntryTransform`
- `StAvatarFini` calls `StAvatar_StopAndFreeBuffers`, `chasm_10273920`, `mdl_1026E900`, `StAvatar_ReleaseResources`, `scnFini`, `MoTask_KillAllGlobalSlots`, `MoTask_KillGlobalSlot1`
- `StAvatar_ResetChannels` calls `StAvatar_UpdateFlag2`
- `StAvatar_SetFlagBit` calls nothing directly
- `StAvatar_SetStopped` calls `MoTask_KillAllGlobalSlots`, `AfterimageTask_Execute`, `StAvatar_AdvanceTimers`, `StModelItem_Refresh`
- `StAvatar_SetField10` calls `sub_10270840`
- `StAvatar_SetField14` calls `sub_102709E0`
- `StAvatar_StoreMode` calls nothing directly
- `StAvatar_Start` calls `SceneCamera_SetVtable1099B138`, `SceneCamera_SelectCamera`, `StAvatar_ResetChannels`, `StAvatar_UpdateFlagBits`, `StAvatar_SetModelFlags`, `StAvatar_SelectEntry`, `StAvatar_ComputeRatioValue`
- `StAvatar_SetModelFlags` calls `StAvatar_SetModelItemFlags`
- `StAvatar_SetModelItemFlags` calls nothing directly
- `StAvatar_SetLock` calls `Mdl_SetSlotLock`
- `StAvatar_GetField20` calls nothing directly
- `StAvatar_InitIndices` calls nothing directly
- `StChannelItem_Load` calls `ErrorReport_NoOpVarargsA`, `TextInputFiles_FileMngQueueFileNumKind2`
