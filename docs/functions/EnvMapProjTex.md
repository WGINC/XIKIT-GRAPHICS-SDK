# EnvMapProjTex

Group: `Env` (by the file name only). Source: `sdk/tree_src/EnvMapProjTex.cpp`.

Why the file has this name (data/unit_names.json): EnvMap_BeginPass / EndPass, ProjTex_BeginPass / CaptureToTarget / EndPass, Dbg_DrawAxesAt; called from SkinAndDrawV2 and DrawModel

10 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ProjTex_BeginPass` | 0x10025330 | 643 | yes | 0 | - | - |
| `ProjTex_EndPass` | 0x100255C0 | 657 | yes | 0 | - | - |
| `ProjTex_CaptureToTarget` | 0x10025870 | 801 | yes | 0 | - | - |
| `EnvMapProjTex_Nop_10025BD0` | 0x10025BD0 | 1 | yes | - | Does nothing. | low |
| `EnvMapProjTex_Nop_10025BE0` | 0x10025BE0 | 1 | yes | - | Does nothing. | low |
| `EnvMapProjTex_ClearCounter` | 0x10025BF0 | 19 | yes | - | Sets the model base vtable and clears a global counter. | low |
| `EnvMap_BeginPass` | 0x10025C40 | 810 | yes | 0 | - | - |
| `EnvMap_EndPass` | 0x10025F70 | 663 | yes | 0 | - | - |
| `Dbg_DrawViewAxisGizmo` | 0x100263F0 | 708 | yes | 0 | - | - |
| `Dbg_DrawAxesAt` | 0x100266C0 | 422 | yes | 0 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ProjTex_BeginPass` calls `MathVector_ReturnThis`, `MathVector_Nop`, `Mat4_Copy`
- `ProjTex_EndPass` calls `sub_10025860`
- `ProjTex_CaptureToTarget` calls `CDx::GetRenderTargetTop`, `CDx::PushRenderTarget`, `CDx::DrawPrimitiveUP`, `CDx::SetTexture`
- `EnvMapProjTex_Nop_10025BD0` calls nothing directly
- `EnvMapProjTex_Nop_10025BE0` calls nothing directly
- `EnvMapProjTex_ClearCounter` calls nothing directly
- `EnvMap_BeginPass` calls `MathVector_ReturnThis`, `MathVector_Nop`, `TexRef_SetTexture`, `Mat4_SetIdentity`, `Mat4_PreMultiply`
- `EnvMap_EndPass` calls `sub_10025860`
- `Dbg_DrawViewAxisGizmo` calls `MathVector_ReturnThis`, `CDx::GetTransformCached`, `Mat4_InvertOrthonormal`, `Mat4_TransformPointInPlace`, `Mat4_SetScale`, `Mat4_SetTranslation`, `CDx::SetTransform`, `CDx::DrawPrimitiveUP`, `MathVector_Nop`
- `Dbg_DrawAxesAt` calls `MathVector_ReturnThis`, `CDx::GetTransformCached`, `Mat4_SetIdentity`, `Mat4_SetTranslation`, `CDx::SetTransform`, `CDx::DrawPrimitiveUP`, `MathVector_Nop`
