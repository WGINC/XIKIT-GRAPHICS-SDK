# CMoDX

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoDX.cpp`.

8 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoDX::GetRuntimeClass` | 0x10069D60 | 6 | yes | - | - | - |
| `CMoDX::ScalarDeletingDtor` | 0x10069DB0 | 30 | yes | - | - | - |
| `CMoDX::CreateTexture` | 0x1006A150 | 33 | yes | 1 | - | - |
| `CMoDX::SetWorldMatrix` | 0x1006A480 | 24 | yes | 1 | - | - |
| `CMoDX::PushViewMatrix` | 0x1006A4C0 | 38 | yes | - | - | - |
| `CMoDX::PopViewMatrix` | 0x1006A4F0 | 34 | yes | 2 | - | - |
| `CMoDX::SetViewMatrix` | 0x1006A520 | 21 | yes | 1 | - | - |
| `CMoDX::CreateAndInitSystem` | 0x1006B2B0 | 256 | yes | 1 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoDX::GetRuntimeClass` calls nothing directly
- `CMoDX::ScalarDeletingDtor` calls `sub_10069D70`, `thunk_sub_10028AA0`
- `CMoDX::CreateTexture` calls `CDx::CreateTexture`
- `CMoDX::SetWorldMatrix` calls `CDx::SetTransform`
- `CMoDX::PushViewMatrix` calls `Dx_GetCachedTransform2`
- `CMoDX::PopViewMatrix` calls `CMoDX::SetViewMatrix`
- `CMoDX::SetViewMatrix` calls `CDx::SetTransform`
- `CMoDX::CreateAndInitSystem` calls `Mem_AllocDefault`, `sub_10069DD0`, `VBPool_Constructor`, `MeshResourceMng_LoadSystemResources`, `CMoResource::FindByTypeAndId`, `Mo_InitSharedRenderResources`, `CMoDxStatusMng::Constructor`, `Gfx_InitCubeMapTextures`, `CMoOt_InitSystem`, `sub_1006C140`, `j_OcclusionMng_CreateTarget`
