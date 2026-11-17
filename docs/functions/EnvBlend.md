# EnvBlend

Group: `Env` (by the file name only). Source: `sdk/tree_src/EnvBlend.cpp`.

Why the file has this name (data/unit_names.json): Blend_AllocResult / FindPrevious / FreeResult / Update; called from YmCombineWeather

7 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `EnvBlend_GetField4` | 0x1018AD50 | 4 | yes | - | Returns the field at +4. | low |
| `EnvBlend_SetField10Of4` | 0x1018AD60 | 13 | yes | - | Sets the field at +0x10 of the object at +4. | low |
| `Blend_FindPrevious` | 0x1018AD80 | 28 | yes | - | Returns the blend before this one in the owner's list. | medium |
| `Blend_FreeResult` | 0x1018ADA0 | 38 | yes | - | Frees the blend's result object when it owns it. | low |
| `EnvBlend_CallBlendUpdate` | 0x1018ADD0 | 5 | yes | - | Runs Blend_Update on the object. | low |
| `Blend_Update` | 0x1018ADE0 | 208 | yes | 7 | Advances a blend and blends its two sources into a new result. | medium |
| `Blend_AllocResult` | 0x1018AEB0 | 25 | yes | - | Allocates a blend result object that the blend owns. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `EnvBlend_GetField4` calls nothing directly
- `EnvBlend_SetField10Of4` calls nothing directly
- `Blend_FindPrevious` calls nothing directly
- `Blend_FreeResult` calls `Mem_FreeObject`
- `EnvBlend_CallBlendUpdate` calls `Blend_Update`
- `Blend_Update` calls `Time_SubtractFrameScale`, `Time_Normalize`, `YmCombineWeather::Release`, `thunk_sub_10028AA0`, `Env_BlendTimeOfDay`, `Blend_AllocResult`, `Env_BlendKeys`, `Blend_FreeResult`
- `Blend_AllocResult` calls `Mem_AllocObject`
