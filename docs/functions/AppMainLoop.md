# AppMainLoop

Group: `App` (by the file name only). Source: `sdk/tree_src/AppMainLoop.cpp`.

Why the file has this name (data/unit_names.json): CApp::RunMainLoop, App_RenderFrameMaskedFPU, the Direct3D device bootstrap (Gfx_D3DBootstrap, Gfx_CreateDevice, Gfx_CreateD3DHolder), the pad settings (padmode000...), the clipboard; called from WndProc and the window code

36 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `App_ForceForegroundWindow` | 0x100014A0 | 128 | yes | - | - | - |
| `App_RenderFrameMaskedFPU` | 0x10001B50 | 90 | yes | 1 | - | - |
| `App_CreateInputSystem` | 0x10001BB0 | 69 | yes | - | - | - |
| `AppMainLoop_ForwardMouseMove` | 0x10001D90 | 104 | yes | - | Forwards a vertical mouse movement to the menu cursor or to the input handler. | low |
| `AppMainLoop_AppendWithSpace` | 0x10001E70 | 173 | yes | - | Appends a space and a string to the global string. | medium |
| `AppMainLoop_FindTokenCopyDefault` | 0x10001F20 | 21 | yes | - | Finds a token with the third argument 0. | low |
| `AppMainLoop_FindTokenCopy` | 0x10001F40 | 233 | yes | - | Finds a word in the global string and copies the token after it. | low |
| `Gfx_CopySurfaceRectToTexture` | 0x10002040 | 231 | yes | 0 | - | - |
| `Gfx_ProbeDeviceCaps` | 0x10002130 | 637 | yes | 0 | - | - |
| `AppMainLoop_SwapRedBlue` | 0x10002440 | 31 | yes | - | Swaps the red and blue channels of a packed 32-bit colour. | medium |
| `Gfx_IsGammaSupported` | 0x10002BE0 | 19 | yes | - | - | - |
| `Gfx_SetGammaRGB` | 0x10002C00 | 36 | yes | - | - | - |
| `Gfx_SetGammaR` | 0x10002C30 | 69 | yes | - | - | - |
| `Gfx_SetGammaG` | 0x10002C80 | 71 | yes | - | - | - |
| `Gfx_SetGammaB` | 0x10002CD0 | 71 | yes | - | - | - |
| `Gfx_GetGammaRGB` | 0x10002D20 | 36 | yes | - | - | - |
| `AppMainLoop_SetShadowSetting` | 0x10002D50 | 10 | yes | - | Stores its argument in sub_10456ACC. | medium |
| `AppMainLoop_SetFloat10456A68` | 0x10002D70 | 10 | yes | - | Stores its argument in the global at 0x10456A68. | medium |
| `AppMainLoop_GetFloat10456A68Or1` | 0x10002D80 | 23 | yes | - | Returns 1.0 or the float at 0x10456A68, by a global flag. | low |
| `AppMainLoop_SetGlobal10456A5C` | 0x10002DA0 | 10 | yes | - | Stores its argument in the global at 0x10456A5C;. | low |
| `AppMainLoop_SetGlobal10456A6C` | 0x10002DC0 | 10 | yes | - | Stores its argument in the global at 0x10456A6C. | low |
| `AppMainLoop_SetFloat10456AB8` | 0x10002DE0 | 10 | yes | - | Stores its argument in the global at 0x10456AB8. | low |
| `AppMainLoop_SetFloat10456AA8` | 0x10002E00 | 10 | yes | - | Stores its argument in the global at 0x10456AA8. | low |
| `AppMainLoop_SetGlobal10456A70` | 0x10002E20 | 10 | yes | - | Stores its argument in the global at 0x10456A70;. | low |
| `AppMainLoop_SetCfg0020` | 0x10002E40 | 10 | yes | - | Stores its argument in sub_10456C00. | medium |
| `Gfx_SetAspectIndex` | 0x10002E60 | 18 | yes | - | Stores an aspect-ratio index and applies its scale. | low |
| `Gfx_ApplyAspectScale` | 0x10002E80 | 33 | yes | - | Sets the camera scale from the aspect-ratio table entry for an index. | medium |
| `Gfx_GetAspectTableA` | 0x10002EC0 | 22 | yes | - | Returns the first value of the aspect-ratio table entry for an index, clamped to five. | low |
| `Gfx_GetAspectTableB` | 0x10002EE0 | 22 | yes | - | Returns the second value of the aspect-ratio table entry for an index, clamped to five. | low |
| `Gfx_CreateD3DHolder` | 0x10002F20 | 288 | yes | 3 | - | - |
| `Gfx_DestroyD3DHolder` | 0x10003040 | 42 | yes | - | - | - |
| `Gfx_D3DBootstrap` | 0x100031F0 | 450 | yes | 1 | - | - |
| `Gfx_TryCreateDeviceForMode` | 0x100033C0 | 150 | yes | 0 | - | - |
| `Gfx_CreateDevice` | 0x100034B0 | 234 | yes | 0 | - | - |
| `Gfx_InitObject` | 0x100035F0 | 28 | yes | - | Initialises the graphics helper object and its sub-object. | medium |
| `Gfx_ResetObject` | 0x10003640 | 8 | yes | - | Resets the graphics helper object. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `App_ForceForegroundWindow` calls nothing directly
- `App_RenderFrameMaskedFPU` calls `sub_10311C7A`, `Frame_Render`, `sub_100DAF30`
- `App_CreateInputSystem` calls `Allocator_Generic`, `Input_InitState`, `sub_100058F0`
- `AppMainLoop_ForwardMouseMove` calls `Menu_HasFocusedItem`, `CTkMouse_OnMouseMove`, `FontGlyphCache_AddToCounter`
- `AppMainLoop_AppendWithSpace` calls `Allocator_Generic`, `operator_delete`
- `AppMainLoop_FindTokenCopyDefault` calls `AppMainLoop_FindTokenCopy`
- `AppMainLoop_FindTokenCopy` calls `sub_10311EB0`
- `Gfx_CopySurfaceRectToTexture` calls `CDx::CreateTexture`, `sub_102D4515`, `Gfx_ProbeDeviceCaps`
- `Gfx_ProbeDeviceCaps` calls `AppMainLoop_SwapRedBlue`
- `AppMainLoop_SwapRedBlue` calls nothing directly
- `Gfx_IsGammaSupported` calls nothing directly
- `Gfx_SetGammaRGB` calls `GammaRamp_SetRGB`
- `Gfx_SetGammaR` calls `GammaRamp_GetRGB`, `Gfx_SetGammaRGB`
- `Gfx_SetGammaG` calls `GammaRamp_GetRGB`, `Gfx_SetGammaRGB`
- `Gfx_SetGammaB` calls `GammaRamp_GetRGB`, `Gfx_SetGammaRGB`
- `Gfx_GetGammaRGB` calls `GammaRamp_GetRGB`
- `AppMainLoop_SetShadowSetting` calls nothing directly
- `AppMainLoop_SetFloat10456A68` calls nothing directly
- `AppMainLoop_GetFloat10456A68Or1` calls `Acter_GetGlobalByte`
- `AppMainLoop_SetGlobal10456A5C` calls nothing directly
- `AppMainLoop_SetGlobal10456A6C` calls nothing directly
- `AppMainLoop_SetFloat10456AB8` calls nothing directly
- `AppMainLoop_SetFloat10456AA8` calls nothing directly
- `AppMainLoop_SetGlobal10456A70` calls nothing directly
- `AppMainLoop_SetCfg0020` calls nothing directly
- `Gfx_SetAspectIndex` calls `Gfx_ApplyAspectScale`
- `Gfx_ApplyAspectScale` calls `Gfx_GetAspectTableB`, `Gfx_GetAspectTableA`, `Camera_SetField2F0`
- `Gfx_GetAspectTableA` calls nothing directly
- `Gfx_GetAspectTableB` calls nothing directly
- `Gfx_CreateD3DHolder` calls `Allocator_Generic`, `sub_10003070`, `sub_10003110`
- `Gfx_DestroyD3DHolder` calls `sub_100035A0`
- `Gfx_D3DBootstrap` calls `sub_102D2600`, `Allocator_Generic`, `Gfx_TryCreateDeviceForMode`
- `Gfx_TryCreateDeviceForMode` calls `sub_10003460`, `Gfx_CreateDevice`
- `Gfx_CreateDevice` calls nothing directly
- `Gfx_InitObject` calls `Debug_Construct`, `Gfx_ResetObject`
- `Gfx_ResetObject` calls nothing directly
