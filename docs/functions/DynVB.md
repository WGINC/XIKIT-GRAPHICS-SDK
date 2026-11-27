# DynVB

Group: `Dyn` (by the file name only). Source: `sdk/tree_src/DynVB.cpp`.

Why the file has this name (data/unit_names.json): DynVB_Create / Lock / Reserve / Unlock, CMoVuElem_Draw, Mo_InitSharedRenderResources, the strings spec, cubemap, map

12 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `DynVB_Create` | 0x10043E50 | 162 | yes | - | - | - |
| `DynVB_ReturnBuffersToPool` | 0x10043F00 | 54 | yes | - | Returns the object's two vertex buffers to the vertex-buffer pool, releasing any the pool refuses. | low |
| `CMoVuElem_Draw` | 0x10043F40 | 201 | yes | 0 | - | - |
| `DynVB_Reserve` | 0x10044010 | 88 | yes | - | - | - |
| `DynVB_Lock` | 0x10044130 | 109 | yes | - | - | - |
| `DynVB_Unlock` | 0x100441A0 | 23 | yes | - | - | - |
| `CameraCache_CacheViewProjection` | 0x100441C0 | 78 | yes | - | - | - |
| `Gfx_SetViewMatrixFromField10` | 0x10044210 | 23 | yes | 1 | - | - |
| `Gfx_SetViewMatrixFromField90` | 0x10044230 | 26 | yes | 1 | - | - |
| `Mo_InitSharedRenderResources` | 0x10044270 | 529 | yes | 2 | - | - |
| `DynVB_ToggleDynVBs` | 0x10044540 | 60 | yes | - | Toggles the +0x45 byte of each dynamic vertex buffer. | medium |
| `DynVB_ReleaseResourcesOf` | 0x100446A0 | 340 | yes | 5 | Stops and releases the resources and tasks that belong to a resource. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `DynVB_Create` calls `DynVB_ReturnBuffersToPool`, `Gfx_CalcFVFStride`, `VBPool_FindMatch`
- `DynVB_ReturnBuffersToPool` calls `VBPool_Insert`
- `CMoVuElem_Draw` calls `DynVBCtor_ReturnZero`, `Gfx_CalcFVFStride`, `CDx::DrawPrimitive`
- `DynVB_Reserve` calls `DynVBCtor_ReturnZero`
- `DynVB_Lock` calls `DynVBCtor_ReturnZero`
- `DynVB_Unlock` calls `DynVBCtor_ReturnZero`
- `CameraCache_CacheViewProjection` calls `CDx::GetTransformCached`
- `Gfx_SetViewMatrixFromField10` calls `CDx::SetTransform`
- `Gfx_SetViewMatrixFromField90` calls `CDx::SetTransform`
- `Mo_InitSharedRenderResources` calls `Rand_SeedMT19937`, `TexRef_ResolveByName`, `Mem_AllocDefault`, `CAcc::Constructor`, `CMoDX::CreateTexture`, `game_1000AD70`, `Allocator_Generic`, `DynVB_Constructor`, `DynVB_Create`
- `DynVB_ToggleDynVBs` calls `DynVBCtor_ToggleByte45`
- `DynVB_ReleaseResourcesOf` calls `game_100742A0`, `ResourceIter_FindFirst`, `ResourceIter_FindNext`, `ResourceIter_Start`, `game_10071E90`, `YmGenerater_Stop`, `CMoResource::ReleaseChain`, `MoRes_FreeIfUnreferenced`, `Generator_ClearSubobjectOrSetFlag`, `CMoTask::Release`
