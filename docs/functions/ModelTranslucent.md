# ModelTranslucent

Group: `Model` (by the file name only). Source: `sdk/tree_src/ModelTranslucent.cpp`.

Why the file has this name (data/unit_names.json): Model_BeginTranslucentPass / CompositeTranslucentPass / CreateTranslucentTargets, TexRes_LoadBm2, the g_translucent* globals; called from CXiSkeletonActor::DrawModel

8 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ModelTranslucent_ReturnSelf` | 0x1001CF80 | 3 | yes | - | Returns its object. | low |
| `Model_CreateTranslucentTargets` | 0x1001D0A0 | 108 | yes | 1 | - | - |
| `ModelTranslucent_Construct` | 0x1001D170 | 82 | yes | - | Constructs a translucent set and takes references to its textures. | low |
| `Model_BeginTranslucentPass` | 0x1001D240 | 270 | yes | 1 | - | - |
| `Model_TranslucentUnbindTexture` | 0x1001D350 | 54 | yes | 1 | - | - |
| `ModelTranslucent_SetColorForce` | 0x1001D390 | 22 | yes | - | Sets the translucent colour and force flag. | low |
| `Model_CompositeTranslucentPass` | 0x1001D3B0 | 1104 | yes | 0 | - | - |
| `TexRes_LoadBm2` | 0x1001D800 | 194 | yes | 2 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ModelTranslucent_ReturnSelf` calls nothing directly
- `Model_CreateTranslucentTargets` calls `Camera_GetViewportHeight`, `Camera_GetViewportWidth`, `CDx::CreateTexture`
- `ModelTranslucent_Construct` calls nothing directly
- `Model_BeginTranslucentPass` calls `CEnv::IsStereoMode`, `CDx::PushRenderTarget`, `CDx::EndClearBegin`, `CDx::SetTexture`
- `Model_TranslucentUnbindTexture` calls `CDx::SetTexture`
- `ModelTranslucent_SetColorForce` calls nothing directly
- `Model_CompositeTranslucentPass` calls `CDx::GetRenderTargetTop`, `CEnv::IsStereoMode`, `CDx::DrawPrimitiveUP`, `CDx::PushRenderTarget`, `CDx::SetTexture`
- `TexRes_LoadBm2` calls `sub_10017D50`, `ErrorReport_NoOpVarargsA`, `Util_Copy16Bytes`, `TexMgr_FindByName`, `Mem_AllocDefault`, `TexObj_Constructor`, `sub_1001D8E0`, `TexMgr_Enqueue`, `sub_10071F50`, `TexObj_CreateAndUpload`
