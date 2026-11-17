# ModelDtInit

Group: `Model` (by the file name only). Source: `sdk/tree_src/ModelDtInit.cpp`.

Why the file has this name (data/unit_names.json): CYyModelDt::Init / InitBase, CreateSharedVertexBuffers

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CreateSharedVertexBuffers` | 0x10029A50 | 264 | yes | 0 | - | - |
| `sub_10029B60` | 0x10029B60 | 71 | no | - | Releases every vertex buffer and resets the related graphics state. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CreateSharedVertexBuffers` calls `Mat4_SetIdentity`, `Model_CreateTranslucentTargets`, `BoneShadow_InitTargets`, `Post_CreateScreenEffectTargets`, `EnvMapProjTex_Nop_10025BD0`
- `sub_10029B60` calls `ProjTexTarget_Release`, `EnvMapProjTex_Nop_10025BE0`, `PostCapture_ReleaseTextures`, `BoneShadow_ReleaseTargets`
