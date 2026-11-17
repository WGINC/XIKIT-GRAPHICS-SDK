# StAvatarModel

Group: `St` (by the file name only). Source: `sdk/tree_src/StAvatarModel.cpp`.

Why the file has this name (data/unit_names.json): StAvatar_InitModel / UpdateModels / AllocArrays

5 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqgxContext_StoreVec14` | 0x1026E3D0 | 42 | yes | - | Stores an object's vector at +0x14 in the context. | low |
| `StAvatar_InitGlobals1099AEB8` | 0x1026E400 | 85 | yes | - | Initialises a block of avatar globals. | low |
| `StAvatar_AllocArrays` | 0x1026E460 | 200 | yes | - | Allocates the avatar's model and channel arrays. | medium |
| `StAvatar_InitModel` | 0x1026E530 | 90 | yes | - | Initialises one entry of the avatar's model array. | low |
| `StAvatar_UpdateModels` | 0x1026E590 | 396 | yes | - | Updates the avatar's models and accumulates their values. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqgxContext_StoreVec14` calls `SqgxContext_StoreEntryVec`
- `StAvatar_InitGlobals1099AEB8` calls `Chn_InitDefaults`
- `StAvatar_AllocArrays` calls `sub_10275D80`, `SqChannelDefaults_InitDefaults`, `StAvatar_InitModel`
- `StAvatar_InitModel` calls `SqVec_ZeroDwords`
- `StAvatar_UpdateModels` calls `SqMatrixConnect_IsConnected`, `SqMatrixConnect_Advance`, `SqDebug_GetFlagByte14`, `SqDebug_InvokeCallback18`, `Chn_ForwardIfFlag2`, `scnCameraGetInfo`, `SqmdModel_LookAt`, `SqmdModel_Update`
