# ShaderSetup

Group: `Shader` (by the file name only). Source: `sdk/tree_src/ShaderSetup.cpp`.

Why the file has this name (data/unit_names.json): Shader_CreateVertexShader, with the menu resolution settings (g_cfgMenuResX/Y); called from the device code

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Shader_CreateVertexShader` | 0x10017810 | 50 | yes | 0 | Creates a Direct3D vertex shader from the object's declaration and function. | high |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Shader_CreateVertexShader` calls nothing directly
