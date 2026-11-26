# sqsnScene

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqsnScene.cpp`.

31 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqsnScene_Free` | 0x1028E1B0 | 408 | yes | - | Frees a scene's cameras, lights, layers and shadow entries. | medium |
| `SqsnScene_Init` | 0x1028E350 | 96 | yes | - | Initialises a sqsnScene object's header, callbacks and empty arrays. | medium |
| `SqsnScene_SetItemFloat14` | 0x1028EBF0 | 26 | yes | - | Stores a float at +0x14 of a scene item. | low |
| `SqsnScene_SetEntryField8` | 0x1028EC30 | 26 | yes | - | Stores a value at +8 of the given 0x2C-byte entry of the scene's array at +0x48. | low |
| `SqsnScene_SetItemByte19` | 0x1028EC50 | 26 | yes | - | Stores a byte at +0x19 of a scene item. | low |
| `SqsnScene_SetByteAt28` | 0x1028ECC0 | 19 | yes | - | Stores a byte at an offset in the table at +0x28. | low |
| `SqsnScene_SetItemByte18` | 0x1028ECE0 | 26 | yes | - | Stores a byte at +0x18 of a scene item. | low |
| `SqsnScene_AddCamera` | 0x1028ED00 | 76 | yes | - | Adds a camera and its transform to a scene and returns its index. | low |
| `SqsnScene_AddLight` | 0x1028ED50 | 112 | yes | - | Adds an enabled light and its transform to a scene and returns its index. | low |
| `SqsnScene_LayerAddItem` | 0x1028EDE0 | 452 | yes | - | Adds an item to a scene layer, creating the layer if needed, and returns its id. | low |
| `SqsnScene_LayerInit` | 0x1028EFB0 | 55 | yes | - | Initialises one scene layer to its defaults. | low |
| `SqsnScene_AddShadow` | 0x1028F130 | 164 | yes | - | Adds a shadow entry to a scene and returns its index. | low |
| `SqsnScene_SetItemDword28` | 0x1028F220 | 26 | yes | - | Stores a dword at +0x28 of a scene item. | low |
| `SqsnScene_ItemAddLight` | 0x1028F2E0 | 100 | yes | - | Adds a light to a scene layer item (at most eight). | high |
| `SqsnScene_ItemAddShadowLight` | 0x1028F350 | 100 | yes | - | Adds a shadow light to a scene layer item (at most eight). | high |
| `SqsnScene_ShadowAddMember` | 0x1028F3C0 | 73 | yes | - | Adds a member to a shadow entry's list. | low |
| `SqsnScene_GetEntryAddr` | 0x1028F430 | 43 | yes | - | Returns the address of a scene entry from a packed index. | low |
| `SqsnScene_SetCursorIfInRange` | 0x1028F4A0 | 17 | yes | - | Sets the cursor at +0x1C when the argument is within the count at +0x14. | low |
| `SqsnScene_DrawMatrixShape` | 0x1028F4C0 | 46 | yes | 2 | Draws a matrix shape for the scene item. | low |
| `sqsnScene_1028F5F0` | 0x1028F5F0 | 236 | yes | - | - | - |
| `SqsnScene_SetupLayerLights` | 0x1028F6E0 | 473 | yes | - | Loads up to four lights of each kind for a layer into the rendering context. | low |
| `sqsnSceneDraw` | 0x1028F8C0 | 1288 | yes | 0 | - | - |
| `sqsnSceneLayerDraw` | 0x1028FDD0 | 420 | yes | 2 | - | - |
| `SqsnScene_DrawFadeSprite` | 0x1028FF80 | 101 | yes | 1 | Copies the current target into the scene's +0x60 texture through a full sprite. | low |
| `sqsnSceneLayerDrawShadowed` | 0x1028FFF0 | 706 | yes | 1 | - | - |
| `sqsnSceneLayerSnapShotComposite` | 0x102902C0 | 367 | yes | 2 | - | - |
| `SqsnScene_NoOp` | 0x10290430 | 1 | yes | - | Does nothing. | low |
| `sqsnSceneLayerSort` | 0x10290440 | 450 | yes | - | - | - |
| `SqsnScene_Preallocate` | 0x10290610 | 432 | yes | - | Preallocates a scene's camera, light, layer and shadow arrays. | high |
| `SqsnScene_LayerPreallocate` | 0x102907C0 | 114 | yes | - | Preallocates the items of one scene layer. | high |
| `SqsnScene_ShadowPreallocate` | 0x10290840 | 83 | yes | - | Preallocates the member list of one shadow entry. | high |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqsnScene_Free` calls `SqgxTexture_FreeSlot`, `sqFree`, `SqObject_Release`
- `SqsnScene_Init` calls `SqrdTexture_Init`
- `SqsnScene_SetItemFloat14` calls nothing directly
- `SqsnScene_SetEntryField8` calls nothing directly
- `SqsnScene_SetItemByte19` calls nothing directly
- `SqsnScene_SetByteAt28` calls nothing directly
- `SqsnScene_SetItemByte18` calls nothing directly
- `SqsnScene_AddCamera` calls `SqMem_Realloc`
- `SqsnScene_AddLight` calls `SqMem_Realloc`
- `SqsnScene_LayerAddItem` calls `SqMem_Realloc`, `SqsnScene_LayerInit`
- `SqsnScene_LayerInit` calls nothing directly
- `SqsnScene_AddShadow` calls `SqMem_Realloc`
- `SqsnScene_SetItemDword28` calls nothing directly
- `SqsnScene_ItemAddLight` calls `sqDebugPrintf`
- `SqsnScene_ItemAddShadowLight` calls `sqDebugPrintf`
- `SqsnScene_ShadowAddMember` calls `SqMem_Realloc`
- `SqsnScene_GetEntryAddr` calls nothing directly
- `SqsnScene_SetCursorIfInRange` calls nothing directly
- `SqsnScene_DrawMatrixShape` calls `sqgxMatrixShape`, `game_102A1F20`
- `sqsnScene_1028F5F0` calls `SqgxContext_SetCurrentIndex`, `SqgxContext_StoreVec14`, `SqgxContext_SetTransposedMatrix`, `SqgxContext_SetFloat72C`, `SqgxContext_SetContextSlot854`
- `SqsnScene_SetupLayerLights` calls `SqgxContext_SetCurrentIndex`, `SqgxContext_StoreVec14`, `SqgxContext_SetTransposedMatrix`, `SqgxContext_SetFloat72C`, `SqgxContext_SetContextSlot854`
- `sqsnSceneDraw` calls `sqsnSceneLayerSort`, `sqgxTextureAdd`, `sqgxTextureDraw`, `sqgxTextureClear`, `sqrdCamera_Apply`, `sqgxMatrixCamera`, `sqsnSceneLayerDrawShadowed`, `sqsnSceneLayerDraw`, `sqgxTextureSet`, `sqsnSceneLayerSnapShotComposite`, `sqgxTextureGetSize`, `sqgxTextureStencilClear`, `sqgxTextureDecal`, `sqgxTextureClamp`, `sqgxBlendOff`, `sqgxZTest`, `SqsnScene_NoOp`, `sqgxColor`, `sqgxBlendTrsp`, `game_10280DE0`
- `sqsnSceneLayerDraw` calls `sqrdCamera_Apply`, `sqgxMatrixCamera`, `SqShadowVolumeDraw_CopyBounds`, `SqsnScene_SetupLayerLights`, `SqsnScene_DrawMatrixShape`, `SqsnScene_DrawFadeSprite`
- `SqsnScene_DrawFadeSprite` calls `sqgxZTest`, `sqgxTextureDraw`, `sqgxTextureSet`, `sqgxTextureDecal`, `game_10280DE0`
- `sqsnSceneLayerDrawShadowed` calls `sqrdCamera_Apply`, `sqgxMatrixCamera`, `sqsnPlanarShadowDraw`, `SqShadowVolumeDraw_CopyBounds`, `SqsnScene_SetupLayerLights`, `SqsnScene_DrawMatrixShape`, `SqShadowVolumeDraw_ContainsInAnyEntry`, `SqPlanarShadow_RenderShadowTexture`, `SqShadowVolumeDraw_ContainsInt`, `SqPlanarShadow_DrawShadowedShape`, `SqsnScene_DrawFadeSprite`
- `sqsnSceneLayerSnapShotComposite` calls `SqgxTextureImage_CompositeBlendPasses`
- `SqsnScene_NoOp` calls nothing directly
- `sqsnSceneLayerSort` calls `sqgxMatrixCamera`, `SqBounds_GetCenter`, `sqgxMatrixShape`, `sqMatrix4_10280140`, `M4fTranspose`, `M4fTransform`
- `SqsnScene_Preallocate` calls `game_10275D80`, `sqDebugPrintf`, `SqsnScene_LayerInit`
- `SqsnScene_LayerPreallocate` calls `game_10275D80`, `sqDebugPrintf`
- `SqsnScene_ShadowPreallocate` calls `game_10275D80`, `sqDebugPrintf`
