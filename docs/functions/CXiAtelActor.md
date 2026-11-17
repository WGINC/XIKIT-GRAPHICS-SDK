# CXiAtelActor

Group: `CXi` (by the file name only). Source: `sdk/tree_src/CXiAtelActor.cpp`.

6 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CXiAtelActor::IsAtelType82` | 0x10082960 | 22 | yes | - | - | - |
| `CXiAtelActor::IsAtelType83` | 0x100829C0 | 22 | yes | - | - | - |
| `CXiAtelActor_UnlinkCasterAttachments` | 0x10085C90 | 91 | yes | - | - | - |
| `CXiAtelActor_UnlinkTargetAttachments` | 0x10085CF0 | 91 | yes | - | - | - |
| `Actor_DrawWorldText` | 0x10086210 | 1774 | yes | 0 | - | - |
| `CXiAtelActor::CopyAndWrapAngles` | 0x10086E90 | 206 | yes | - | Copies a 4-component block into the actor's +0xC4 slot and wraps three angle fields into the [-pi, pi] range. (reviewed as sub_10086E90) | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CXiAtelActor::IsAtelType82` calls nothing directly
- `CXiAtelActor::IsAtelType83` calls nothing directly
- `CXiAtelActor_UnlinkCasterAttachments` calls `CMoAttachments::ClearCaster`
- `CXiAtelActor_UnlinkTargetAttachments` calls `CMoAttachments::ClearTarget`
- `Actor_DrawWorldText` calls `MathVector_ReturnThis`, `Mat4_SetIdentity`, `Mat4_SetTranslation`, `CDx::SetTransform`, `Gfx_ProjectWorldToClip`, `Gfx_NdcToScreen`, `sub_10027050`, `Camera_GetViewportWidth`, `Camera_GetViewportHeight`, `ShapeMng_GetFontGlyph`, `sub_10311C2C`, `Vec2_Add`, `ShapeMng::ShapeMng_BindFontTexture`, `CDx::DrawPrimitiveUP`, `MathVector_Nop`
- `CXiAtelActor::CopyAndWrapAngles` calls `Vec4_Copy`
