# CYyModelDt

Group: `CYy` (by the file name only). Source: `sdk/tree_src/CYyModelDt.cpp`.

13 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CYyModelDt::SetVertexShader` | 0x10022FA0 | 48 | yes | 0 | - | - |
| `CYyModelDt::Construct` | 0x10025010 | 29 | yes | - | Constructs the model-dt object on top of its base and sets its defaults. (reviewed as sub_10025010) | medium |
| `CYyModelDt::PrepareRenderStateEntry` | 0x10025030 | 46 | yes | 1 | - | - |
| `CYyModelDt::PrepareRenderStateSimpleEntry` | 0x10025060 | 41 | yes | - | - | - |
| `CYyModelDt::MarkReferencedBones` | 0x100251A0 | 85 | yes | - | - | - |
| `CYyModelDt::GetRuntimeClass` | 0x10029880 | 6 | yes | - | - | - |
| `CYyModelDt::InitBase` | 0x10029BB0 | 41 | yes | - | Initialises the base part of a CYyModelDt object. (reviewed as sub_10029BB0) | medium |
| `CYyModelDt::Init` | 0x10029C90 | 30 | yes | - | Initialises a CYyModelDt object and its base part. (reviewed as sub_10029C90) | medium |
| `CYyModelDt::ScalarDeletingDtor` | 0x10029CB0 | 30 | yes | - | - | - |
| `CYyModelDt::PrepareRenderStateV2Entry` | 0x1002A000 | 55 | yes | 2 | - | - |
| `CYyModelDt::PrepareRenderStateV2SimpleEntry` | 0x1002A040 | 50 | yes | - | - | - |
| `CYyModelDt::GetResourceWord5E` | 0x1002A080 | 19 | yes | - | Returns the dword at +0x5E of the model's resource. (reviewed as sub_1002A080) | medium |
| `CYyModelDt::SkinAndDrawV2` | 0x1002DC10 | 5315 | yes | 1 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CYyModelDt::SetVertexShader` calls nothing directly
- `CYyModelDt::Construct` calls `CYyModelDt::Init`
- `CYyModelDt::PrepareRenderStateEntry` calls `ResourceHandle_Deref`, `CYyModelDt_PrepareRenderState`
- `CYyModelDt::PrepareRenderStateSimpleEntry` calls `ResourceHandle_Deref`, `CYyModelDt_PrepareRenderStateSimple`
- `CYyModelDt::MarkReferencedBones` calls `ResourceHandle_Deref`
- `CYyModelDt::GetRuntimeClass` calls nothing directly
- `CYyModelDt::InitBase` calls nothing directly
- `CYyModelDt::Init` calls `CYyModelDt::InitBase`
- `CYyModelDt::ScalarDeletingDtor` calls `CYyModelDtBase_Destructor`, `thunk_sub_10028AA0`
- `CYyModelDt::PrepareRenderStateV2Entry` calls `ResourceHandle_Deref`, `CYyModelDt::SkinAndDrawV2`
- `CYyModelDt::PrepareRenderStateV2SimpleEntry` calls `ResourceHandle_Deref`, `sub_10030BD0`
- `CYyModelDt::GetResourceWord5E` calls `ResourceHandle_Deref`
- `CYyModelDt::SkinAndDrawV2` calls `sub_1002F1C0`, `Model_SkinVerticesCpu`, `CDx::SetLight`, `sub_10311C2C`, `CYyTexMng::FindByNameInResource`, `Gfx_SetStreamSourceCached`, `CDx::DrawIndexedPrimitive`, `EnvMap_BeginPass`, `Gfx_ApplyCachedVertexShader`, `EnvMap_EndPass`, `ProjTex_BeginPass`, `ProjTex_EndPass`, `Model_BeginOffscreenPass`, `Model_EndOffscreenPassBindTextures`
