# sqmdModel

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqmdModel.cpp`.

27 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqmdModel_Validate` | 0x10277A50 | 87 | yes | - | Checks that a model is loaded and linked (flags 1 and 2 at +0xA8); prints the error and returns false otherwise. | high |
| `SqmdModel_Free` | 0x10277AB0 | 184 | yes | - | Releases a sqmdModel and its buffers, checking its DMB header when it has one. | medium |
| `SqmdModel_FreeBuffers` | 0x10277B70 | 1150 | yes | - | Frees a model's buffers and clears their counts, keeping flag 0x200. | medium |
| `SqmdModel_Update` | 0x10278490 | 636 | yes | - | sqmdModelUpdate: runs a shown model's updaters. | high |
| `SqmdModel_Link` | 0x10278710 | 223 | yes | - | Links each of a model's shapes into the scene through fn_102787F0, treating shapes named eyelash* separately. | medium |
| `SqmdModel_LinkShape` | 0x102787F0 | 404 | yes | - | Links one shape of a model into the scene and records the entry in the model's arrays at +0x9C/+0xA0. | medium |
| `SqmdModel_AddIllumLight` | 0x10278990 | 144 | yes | - | sqmdModelAddIllumLight: adds a light to every scene entry of the model. | high |
| `SqmdModel_AddShadowLightInLayer` | 0x10278B50 | 157 | yes | - | sqmdModelAddShadowLightInLayer: adds a shadow light to the model's scene entries in one layer. | high |
| `SqmdModel_Show` | 0x10278BF0 | 139 | yes | - | sqmdModelShow: marks the model's scene entries visible and sets its shown flag. | high |
| `SqmdModel_SetLayerSort` | 0x10278E10 | 123 | yes | - | sqmdModelSetLayerSort: sets, clears or toggles the model's layer-sort flag (0x8000 at +0xA8). | high |
| `SqmdModel_LookAt` | 0x10278E90 | 546 | yes | - | Aims a model item at a target, clamping the angle to the given limit. | medium |
| `SqmdModel_AppendPair44` | 0x10279530 | 104 | yes | - | Appends a pair of values to the model's item arrays at offsets 0x3C and 0x40. | low |
| `SqmdModel_AppendPair68` | 0x102796A0 | 104 | yes | - | Appends a pair of values to the model's item arrays at offsets 0x60 and 0x64. | low |
| `SqmdModel_GetItem` | 0x10279710 | 262 | yes | - | Returns item param_3 of kind param_2 (texture, shader, updater, shape, ...) of a model, or 0 when out of range. | high |
| `SqmdModel_GetItemKind0` | 0x10279830 | 21 | yes | - | Returns the item of kind 0 for the given id. | low |
| `SqmdModel_GetItemKind1` | 0x10279850 | 21 | yes | - | Returns the item of kind 1 for the given id. | low |
| `SqmdModel_GetItemKind2` | 0x10279870 | 21 | yes | - | Returns the item of kind 2 for the given id. | low |
| `SqmdModel_GetItemKind3` | 0x10279890 | 21 | yes | - | Returns the item of kind 3 for the given id. | low |
| `SqmdModel_GetItemKind4` | 0x102798B0 | 21 | yes | - | Returns the item of kind 4 for the given id. | low |
| `sqmdModel_GetItemName` | 0x10279AB0 | 68 | yes | - | - | - |
| `SqmdModel_GetItemNameKind3` | 0x10279B40 | 21 | yes | - | Returns the name of the kind-3 item for the given id. | low |
| `SqmdModel_FindItemName` | 0x10279BA0 | 80 | yes | - | Returns the name of the item with the given id and type, or 'untitled' when none matches. | medium |
| `SqmdModel_FindItemByName` | 0x10279BF0 | 253 | yes | - | Looks up a model item by kind and name, returning the item and storing its index. | medium |
| `SqmdModel_LookupKind2` | 0x10279D50 | 26 | yes | - | Looks up a kind-2 item for the given arguments. | low |
| `SqmdModel_ItemKindName` | 0x1027A1C0 | 58 | yes | - | Returns the name of an item kind for messages. | high |
| `SqmdModel_AppendPair68Flag100` | 0x1027A220 | 38 | yes | - | Appends a pair to the model's 0x60/0x64 arrays and sets flag 0x100 on the new 0x64 entry. | low |
| `SqmdModel_FreeItems` | 0x1027A250 | 154 | yes | - | Releases the model's item entries that it owns. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqmdModel_Validate` calls `sqDebugPrintf`
- `SqmdModel_Free` calls `SqmdModel_FreeBuffers`, `sqFree`, `sqDebugPrintf`, `SqMem_HexDump`
- `SqmdModel_FreeBuffers` calls `SqmdModel_FreeItems`, `SqgxTexture_FreeSlot`, `SqgxTexture_ClearPaletteUsed`, `sqFree`
- `SqmdModel_Update` calls `SqmdModel_Validate`, `sqDebugPrintf`, `SqTimer_GetMicroseconds`, `SqmdModel_GetItemKind2`, `SqDebug_GetFlagByte14`, `SqDebug_InvokeCallback18`, `SqmdModel_GetItemKind3`, `SqIOHooks_CallHook2C`, `SqIOHooks_CallHook3C`
- `SqmdModel_Link` calls `sqDebugPrintf`, `SqmdModel_GetItemNameKind3`, `sub_10312940`, `SqmdModel_LinkShape`
- `SqmdModel_LinkShape` calls `sqDebugPrintf`, `SqMem_Realloc`, `SqmdModel_GetItemKind1`, `SqmdModel_GetItemKind3`, `SqsnScene_LayerAddItem`, `SqsnScene_ShadowAddMember`, `SqmdModel_GetItemNameKind3`, `sub_10311FF1`, `SqmdModel_LookupKind2`
- `SqmdModel_AddIllumLight` calls `SqmdModel_Validate`, `sqDebugPrintf`, `SqsnScene_ItemAddLight`
- `SqmdModel_AddShadowLightInLayer` calls `SqmdModel_Validate`, `sqDebugPrintf`, `SqsnScene_ItemAddShadowLight`
- `SqmdModel_Show` calls `SqmdModel_Validate`, `sqDebugPrintf`, `SqsnScene_GetEntryAddr`
- `SqmdModel_SetLayerSort` calls `SqmdModel_Validate`, `sqDebugPrintf`
- `SqmdModel_LookAt` calls `SqmdModel_GetItemKind2`, `SqBoneTransform_ComputeTransform`, `SqVec_Sub`, `SqQuat_Copy`, `SqQuatMul_NegateInPlace`, `SqQuatMul_RotateVec`, `SqQuat_FromRotationX`, `SqQuatMul_Mul`, `sqDebugPrintf`
- `SqmdModel_AppendPair44` calls `SqMem_Realloc`
- `SqmdModel_AppendPair68` calls `SqMem_Realloc`
- `SqmdModel_GetItem` calls `sqDebugPrintf`, `SqmdModel_ItemKindName`
- `SqmdModel_GetItemKind0` calls `SqmdModel_GetItem`
- `SqmdModel_GetItemKind1` calls `SqmdModel_GetItem`
- `SqmdModel_GetItemKind2` calls `SqmdModel_GetItem`
- `SqmdModel_GetItemKind3` calls `SqmdModel_GetItem`
- `SqmdModel_GetItemKind4` calls `SqmdModel_GetItem`
- `sqmdModel_GetItemName` calls nothing directly
- `SqmdModel_GetItemNameKind3` calls `sqmdModel_GetItemName`
- `SqmdModel_FindItemName` calls nothing directly
- `SqmdModel_FindItemByName` calls `sqScript_TokenEquals`, `sqDebugPrintf`, `SqmdModel_ItemKindName`, `SqmdModel_GetItemKind0`, `SqmdModel_GetItemKind1`, `SqmdModel_GetItemKind2`, `SqmdModel_GetItemKind3`, `SqmdModel_GetItemKind4`
- `SqmdModel_LookupKind2` calls `SqmdModel_FindItemByName`
- `SqmdModel_ItemKindName` calls nothing directly
- `SqmdModel_AppendPair68Flag100` calls `SqmdModel_AppendPair68`
- `SqmdModel_FreeItems` calls `SqObject_Release`, `sqFree`
