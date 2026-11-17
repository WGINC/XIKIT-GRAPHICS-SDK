# SkinCpu

Group: `Skin` (by the file name only). Source: `sdk/tree_src/SkinCpu.cpp`.

Why the file has this name (data/unit_names.json): Model_SkinVerticesCpu, Skin_BlendWeightMatrices, the cached stream source / vertex shader; called from SkinAndDrawV2

5 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Gfx_SetStreamSourceCached` | 0x1002F130 | 36 | yes | 1 | - | - |
| `Gfx_ApplyCachedStreamSource` | 0x1002F160 | 50 | yes | 0 | - | - |
| `Gfx_ApplyCachedVertexShader` | 0x1002F1A0 | 32 | yes | 0 | - | - |
| `Model_SkinVerticesCpu` | 0x1002F1D0 | 3766 | yes | - | - | - |
| `Skin_BlendWeightMatrices` | 0x100303B0 | 1522 | yes | - | Blends the bone matrices of each skinned vertex into the weight-matrix table. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Gfx_SetStreamSourceCached` calls `Gfx_ApplyCachedStreamSource`
- `Gfx_ApplyCachedStreamSource` calls nothing directly
- `Gfx_ApplyCachedVertexShader` calls nothing directly
- `Model_SkinVerticesCpu` calls `sub_1000D680`, `sub_1000D6B0`, `sub_10030FB0`, `Mat4_TransformPoint`, `Mat4_TransformNormal`, `Skin_BlendWeightMatrices`, `sub_100309B0`, `sub_10030A40`
- `Skin_BlendWeightMatrices` calls `sub_100309B0`, `sub_10030A40`
