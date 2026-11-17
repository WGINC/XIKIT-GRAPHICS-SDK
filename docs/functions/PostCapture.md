# PostCapture

Group: `Post` (by the file name only). Source: `sdk/tree_src/PostCapture.cpp`.

Why the file has this name (data/unit_names.json): Post_CaptureSceneToTarget, Post_CreateScreenEffectTargets, Post_DrawRotatingGhostLayers (the aura)

5 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Post_CreateScreenEffectTargets` | 0x10038930 | 134 | yes | 1 | - | - |
| `PostCapture_ReleaseTextures` | 0x100389C0 | 89 | yes | - | Releases the scene capture textures and depth buffers. | medium |
| `PostCapture_Init` | 0x10038A20 | 17 | yes | - | Sets the base vtable and clears two fields. | low |
| `Post_CaptureSceneToTarget` | 0x10038A80 | 899 | yes | 0 | - | - |
| `Post_DrawRotatingGhostLayers` | 0x10038E10 | 1507 | yes | 0 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Post_CreateScreenEffectTargets` calls `CDx::CreateTexture`
- `PostCapture_ReleaseTextures` calls nothing directly
- `PostCapture_Init` calls nothing directly
- `Post_CaptureSceneToTarget` calls `Settings_GetValue`, `CEnv::IsStereoMode`, `CDx::PushRenderTarget`, `CDx::DrawPrimitiveUP`, `CDx::SetTexture`
- `Post_DrawRotatingGhostLayers` calls `Settings_GetValue`, `CDx::GetRenderTargetTop`, `CEnv::IsStereoMode`, `CDx::PushRenderTarget`, `CDx::DrawPrimitiveUP`, `CDx::SetTexture`, `Camera_GetFrameScale`, `sub_10311C2C`
