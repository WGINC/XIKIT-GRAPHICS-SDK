# SqgxContext

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqgxContext.cpp`.

Why the file has this name (data/unit_names.json): SqgxContext_* (the dancer device context), SetPerspective

44 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `sqgxZTest` | 0x10282350 | 81 | yes | 0 | - | - |
| `sqgxAlphaDstTest` | 0x102823B0 | 63 | yes | - | - | - |
| `sqgxAlphaTest` | 0x102823F0 | 116 | yes | 0 | - | - |
| `sqgxZMask` | 0x10282470 | 79 | yes | 0 | - | - |
| `sqgxFBMask` | 0x102824C0 | 162 | yes | 0 | - | - |
| `SqgxContext_ResetHandles` | 0x10282590 | 121 | yes | - | Releases three handles and resets the context's index tables. | low |
| `SqgxContext_Nop` | 0x10282630 | 1 | yes | - | Does nothing. | low |
| `SqgxContext_SetSelectArg1` | 0x10282640 | 128 | yes | 0 | Sets the texture stage to select its argument. | medium |
| `sqgxBlendAdd` | 0x102826C0 | 261 | yes | 0 | - | - |
| `SqgxContext_SetMultiplyAdd` | 0x102827D0 | 292 | yes | 0 | Sets the texture stage to multiply-add, or additive blending without a stage. | medium |
| `sqgxBlendSub` | 0x10282910 | 261 | yes | 0 | - | - |
| `sqgxBlendLin` | 0x10282A30 | 340 | yes | 0 | - | - |
| `sqgxBlendTrsp` | 0x10282B90 | 261 | yes | 0 | - | - |
| `sqgxBlendTrspInv` | 0x10282CB0 | 261 | yes | 0 | - | - |
| `sqgxBlendAddDestAlpha` | 0x10282DC0 | 261 | yes | 0 | - | - |
| `SqgxContext_SetModulateAlphaAdd` | 0x10282ED0 | 279 | yes | 0 | Sets the texture stage to modulate-alpha and add-colour, or alpha blending without a stage. | medium |
| `sqgxBlendMultAlpha` | 0x10282FF0 | 279 | yes | 0 | - | - |
| `sqgxBlendMul` | 0x10283110 | 261 | yes | 0 | - | - |
| `sqgxBlendOff` | 0x10283220 | 19 | yes | 0 | - | - |
| `SqgxContext_NoOpA` | 0x10283240 | 1 | yes | - | Does nothing. | low |
| `___setargv_9` | 0x10283250 | 11 | yes | - | - | - |
| `SqgxContext_SetCurrentIndex` | 0x10283260 | 31 | yes | - | Stores the current two-part index of the context. | low |
| `SqgxContext_StoreEntryVec` | 0x10283280 | 115 | yes | - | Stores a 3-dword vector at the current index. | low |
| `SqgxContext_SetContextSlot854` | 0x10283300 | 42 | yes | - | Stores a value in the rendering context's table at +0x854 at the index the context's +0x78C/+0x790 select, and marks it dirty. | low |
| `sqgxColor` | 0x10283330 | 74 | yes | - | - | - |
| `sqgxAmbient` | 0x10283380 | 26 | yes | - | - | - |
| `SqgxContext_SetFloat76C` | 0x102833A0 | 26 | yes | - | Stores a float at +0x76C and marks the context dirty. | low |
| `SqgxContext_SetDword774AndFactor` | 0x102833C0 | 40 | yes | - | Stores a dword and sets the inverse factor. | low |
| `sqgxColorUpdate` | 0x10283420 | 680 | yes | 0 | - | - |
| `___setargv_16` | 0x10283870 | 11 | yes | - | - | - |
| `sqgxPixelSize` | 0x102838A0 | 66 | yes | - | - | - |
| `SqgxContext_SetViewportVec4` | 0x10283970 | 74 | yes | - | Stores a 4-component viewport value and marks it dirty. | low |
| `sqgxViewport` | 0x10283A10 | 295 | yes | 0 | - | - |
| `SqgxContext_SetPerspective` | 0x10283C10 | 332 | yes | - | Sets the rendering context's field of view (degrees) and near/far planes and derives its perspective terms. | medium |
| `sqgxMatrixCamera` | 0x10283D60 | 60 | yes | - | - | - |
| `SqgxContext_SetTransposedMatrix` | 0x10283DA0 | 55 | yes | - | Stores the transpose of a matrix for the current index. | low |
| `SqgxContext_SetFloat72C` | 0x10283DE0 | 23 | yes | - | Stores a float in the per-index table at +0x72C. | low |
| `sqgxMatrixShape` | 0x10283E00 | 37 | yes | - | - | - |
| `SqgxContext_SetInverseFactor` | 0x10283F20 | 29 | yes | - | Stores the complement of a factor and marks the context dirty. | low |
| `sqgxPassAdd` | 0x10283F70 | 67 | yes | 0 | - | - |
| `sqgxPass` | 0x10283FC0 | 63 | yes | 0 | - | - |
| `SqgxContext_TestClipBounds` | 0x10284000 | 637 | yes | - | Tests a bounding box against the context's clip limits. | low |
| `sqgxMatrixUpdate` | 0x10284410 | 990 | yes | 0 | - | - |
| `___setargv_24` | 0x10284890 | 11 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `sqgxZTest` calls nothing directly
- `sqgxAlphaDstTest` calls nothing directly
- `sqgxAlphaTest` calls nothing directly
- `sqgxZMask` calls nothing directly
- `sqgxFBMask` calls nothing directly
- `SqgxContext_ResetHandles` calls `SqgxTexture_FreeSlot`
- `SqgxContext_Nop` calls nothing directly
- `SqgxContext_SetSelectArg1` calls nothing directly
- `sqgxBlendAdd` calls nothing directly
- `SqgxContext_SetMultiplyAdd` calls nothing directly
- `sqgxBlendSub` calls nothing directly
- `sqgxBlendLin` calls `game_10311C2C`
- `sqgxBlendTrsp` calls nothing directly
- `sqgxBlendTrspInv` calls nothing directly
- `sqgxBlendAddDestAlpha` calls nothing directly
- `SqgxContext_SetModulateAlphaAdd` calls nothing directly
- `sqgxBlendMultAlpha` calls nothing directly
- `sqgxBlendMul` calls nothing directly
- `sqgxBlendOff` calls nothing directly
- `SqgxContext_NoOpA` calls nothing directly
- `___setargv_9` calls nothing directly
- `SqgxContext_SetCurrentIndex` calls nothing directly
- `SqgxContext_StoreEntryVec` calls nothing directly
- `SqgxContext_SetContextSlot854` calls nothing directly
- `sqgxColor` calls nothing directly
- `sqgxAmbient` calls nothing directly
- `SqgxContext_SetFloat76C` calls nothing directly
- `SqgxContext_SetDword774AndFactor` calls `SqgxContext_SetInverseFactor`
- `sqgxColorUpdate` calls nothing directly
- `___setargv_16` calls nothing directly
- `sqgxPixelSize` calls nothing directly
- `SqgxContext_SetViewportVec4` calls nothing directly
- `sqgxViewport` calls `game_10311C2C`
- `SqgxContext_SetPerspective` calls nothing directly
- `sqgxMatrixCamera` calls `M4fTranspose`, `game_1027F0E0`
- `SqgxContext_SetTransposedMatrix` calls `M4fTranspose`
- `SqgxContext_SetFloat72C` calls nothing directly
- `sqgxMatrixShape` calls `M4fTranspose`
- `SqgxContext_SetInverseFactor` calls nothing directly
- `sqgxPassAdd` calls nothing directly
- `sqgxPass` calls nothing directly
- `SqgxContext_TestClipBounds` calls `sqMatrix4_10280140`, `M4fTranspose`, `M4fTransform`, `SqMatrixConnect_TransformVec3`
- `sqgxMatrixUpdate` calls `sqgxShadowPlaneMatrix`, `sqMatrix4_10280140`, `game_1027EB10`, `game_1027F0E0`, `sqMatrix4_1027FCC0`, `M4fTranspose`
- `___setargv_24` calls nothing directly
