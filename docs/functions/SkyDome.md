# SkyDome

Group: `Sky` (by the file name only). Source: `sdk/tree_src/SkyDome.cpp`.

Why the file has this name (data/unit_names.json): Sky_DrawDome, Sky_DrawDomeViewCentered, and the colour byte arithmetic it uses

14 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Sky_DrawDome` | 0x1003D9A0 | 422 | yes | 0 | - | - |
| `Sky_DrawDomeViewCentered` | 0x1003DB60 | 653 | yes | 0 | - | - |
| `SkyDome_ScaleColorBytes` | 0x1003DFE0 | 240 | yes | - | Scales three colour bytes by a factor. | low |
| `SkyDome_ScaleBytesByVec4` | 0x1003E0D0 | 241 | yes | - | Scales four colour bytes by a float vector and returns the packed dword. | medium |
| `SkyDome_AddBytes` | 0x1003E1D0 | 50 | yes | - | Adds a four-byte colour to the object's bytes. | medium |
| `Color_SetFromU32SwapRB` | 0x1003E280 | 31 | yes | - | - | - |
| `SkyDome_ScaleAlpha` | 0x1003E330 | 111 | yes | - | Scales the top byte of a colour by a float and returns the dword. | medium |
| `SkyDome_AddScaledBytes` | 0x1003E3A0 | 167 | yes | - | Adds the argument's bytes scaled by a global factor to self. | low |
| `SkyDome_AddScaledWords` | 0x1003E450 | 163 | yes | - | Adds 16-bit values scaled by a global factor to self's bytes. | low |
| `SkyDome_AddScaledWordsSaturated` | 0x1003E500 | 291 | yes | - | Adds scaled 16-bit values to self with saturation, storing the high bytes. | low |
| `SkyDome_AddToByte2` | 0x1003E630 | 15 | yes | - | Adds a value to the byte at +2. | low |
| `SkyDome_AddToByte1` | 0x1003E640 | 15 | yes | - | Adds a value to the byte at +1. | low |
| `SkyDome_AddToByte0` | 0x1003E650 | 13 | yes | - | Adds a value to the byte at +0. | low |
| `SkyDome_AddScaledToByte3` | 0x1003E660 | 43 | yes | - | Adds a scaled value to the byte at +3. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Sky_DrawDome` calls `Camera_SetClearColorRGB`, `MoDX_SetInvalid`, `sub_10313486`, `sub_1006AE30`, `CMoDX::SetWorldMatrix`, `Gfx_SetViewMatrixFromField90`, `sub_1003E2A0`, `Camera_GetFloat2E0`, `Camera_GetFloat2DC`, `sub_1003D640`, `Gfx_SetViewMatrixFromField10`
- `Sky_DrawDomeViewCentered` calls `Camera_SetClearColorRGB`, `MoDX_SetInvalid`, `sub_10313486`, `sub_1006AE30`, `CMoDX::SetWorldMatrix`, `CMoDX::PushViewMatrix`, `CMoDX::SetViewMatrix`, `Color_SetFromU32SwapRB`, `Camera_GetFloat2E0`, `Camera_GetFloat2DC`, `sub_1003D640`, `CMoDX::PopViewMatrix`
- `SkyDome_ScaleColorBytes` calls `sub_10311C2C`
- `SkyDome_ScaleBytesByVec4` calls `sub_10311C2C`
- `SkyDome_AddBytes` calls nothing directly
- `Color_SetFromU32SwapRB` calls nothing directly
- `SkyDome_ScaleAlpha` calls `sub_10311C2C`
- `SkyDome_AddScaledBytes` calls `sub_10311C2C`
- `SkyDome_AddScaledWords` calls `sub_10311C2C`
- `SkyDome_AddScaledWordsSaturated` calls `sub_10311C2C`
- `SkyDome_AddToByte2` calls nothing directly
- `SkyDome_AddToByte1` calls nothing directly
- `SkyDome_AddToByte0` calls nothing directly
- `SkyDome_AddScaledToByte3` calls `sub_10311C2C`
