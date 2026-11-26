# ZoneShaderCompile

Group: `Zone` (by the file name only). Source: `sdk/tree_src/ZoneShaderCompile.cpp`.

Why the file has this name (data/unit_names.json): Gfx_AssembleVertexShader, Gfx_CompileVertexShader / PixelShader; called from CTsZoneMap

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Gfx_CompileVertexShader` | 0x101771B0 | 139 | yes | 0 | Assembles a vertex shader and creates it on the Direct3D device. | medium |
| `Gfx_CompilePixelShader` | 0x101772E0 | 93 | yes | 0 | Assembles a pixel shader from source text and creates it on the device. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Gfx_CompileVertexShader` calls `game_102DA79B`, `game_102DAA71`
- `Gfx_CompilePixelShader` calls `game_10177350`, `game_10177340`, `game_102DAA0D`
