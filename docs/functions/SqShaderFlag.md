# SqShaderFlag

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqShaderFlag.cpp`.

Why the file has this name (data/unit_names.json): Shader_SetFlagBit0; called from sqmdIO and sqmdScript

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Shader_SetFlagBit0` | 0x102778C0 | 26 | yes | - | Sets bit 0 of the flags at +0x68 from the argument. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Shader_SetFlagBit0` calls nothing directly
