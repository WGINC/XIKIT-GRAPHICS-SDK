# BoneShadow

Group: `Bone` (by the file name only). Source: `sdk/tree_src/BoneShadow.cpp`.

Why the file has this name (data/unit_names.json): Quat_* and BoneXform_*, Shadow_DrawByMode, Shadow_SmoothLightDirection, the model offscreen pass

14 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Quat_SetIdentityChained` | 0x10032A40 | 12 | yes | - | Sets a quaternion to identity and returns it. | low |
| `Quat_SetIdentityB` | 0x10032A50 | 18 | yes | - | Sets a quaternion to the identity. | medium |
| `BoneShadow_Nop` | 0x10032A70 | 1 | yes | - | Does nothing. | low |
| `Quat_Multiply` | 0x10032B50 | 197 | yes | - | Multiplies two quaternions into an output quaternion. | medium |
| `Quat_NormalizeInPlace` | 0x10032DA0 | 103 | yes | - | Normalises a quaternion in place. | medium |
| `BoneShadow_FromQuat` | 0x10032FE0 | 223 | yes | - | Builds a 4x4 rotation matrix from a quaternion. | medium |
| `Quat_NLerp` | 0x10033220 | 313 | yes | - | - | - |
| `BoneShadow_InitTargets` | 0x100336B0 | 31 | yes | - | Sets up the translucent target pointers and takes a reference to the target. | low |
| `BoneShadow_ReleaseTargets` | 0x100336D0 | 51 | yes | - | Releases the translucent target pointers. | low |
| `BoneShadow_Construct` | 0x10033710 | 134 | yes | 1 | Constructs the translucent helper and creates its render target texture. | low |
| `Model_BeginOffscreenPass` | 0x10033800 | 616 | yes | 1 | - | - |
| `Model_EndOffscreenPassBindTextures` | 0x10033A70 | 813 | yes | 1 | - | - |
| `Shadow_DrawByMode` | 0x10033DA0 | 255 | yes | 1 | Draws the actor's shadow according to the current shadow mode. | medium |
| `Shadow_SmoothLightDirection` | 0x10033EA0 | 437 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Quat_SetIdentityChained` calls `Quat_SetIdentityB`
- `Quat_SetIdentityB` calls nothing directly
- `BoneShadow_Nop` calls nothing directly
- `Quat_Multiply` calls `Quat_SetIdentityChained`
- `Quat_NormalizeInPlace` calls nothing directly
- `BoneShadow_FromQuat` calls nothing directly
- `Quat_NLerp` calls `Quat_SetIdentityChained`
- `BoneShadow_InitTargets` calls nothing directly
- `BoneShadow_ReleaseTargets` calls nothing directly
- `BoneShadow_Construct` calls `Camera_GetViewportHeight`, `Camera_GetViewportWidth`, `CDx::CreateTexture`, `Vec3_SetZero`
- `Model_BeginOffscreenPass` calls `MathVector_ReturnThis`, `CDx::PushRenderTarget`, `CDx::EndClearBegin`, `D3DXMatrixPerspectiveFovLH_static`, `CDx::SetTransform`, `MathVector_Nop`
- `Model_EndOffscreenPassBindTextures` calls `CDx::SetTexture`, `CDx::SetTransform`
- `Shadow_DrawByMode` calls `XiZone::DrawGroundShadowQuad`, `XiZone::DrawDecalOnTriangles`, `CTsZoneMap::DrawProjectedShadow`
- `Shadow_SmoothLightDirection` calls `Camera_GetFrameScale`, `Vec3_SubInPlace`, `Vec3_ScaleInPlace`, `Vec3_AddInPlace`, `Vec3_CopyThen100274B0`, `sub_100274B0`, `Vec3_Set`
