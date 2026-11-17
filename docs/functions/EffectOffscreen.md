# EffectOffscreen

Group: `Effect` (by the file name only). Source: `sdk/tree_src/EffectOffscreen.cpp`.

Why the file has this name (data/unit_names.json): BeginEffectOffscreenPass / EndEffectOffscreenPass, CMoLfdElem_vf11, the splines

5 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `BeginEffectOffscreenPass` | 0x10054D70 | 502 | no | 0 | - | - |
| `EndEffectOffscreenPass` | 0x10054F80 | 57 | yes | 1 | - | - |
| `EffectOffscreen_Init` | 0x10054FC0 | 17 | yes | - | Sets the object's vtable and clears two fields. | low |
| `EffectOffscreen_FreeSplineSet` | 0x100550F0 | 61 | yes | - | Frees the object holding three splines. | medium |
| `LinkNode_Init` | 0x10055240 | 14 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `BeginEffectOffscreenPass` calls `sub_1006A060`, `sub_1006A420`, `CMoDX::PushViewMatrix`, `sub_10313486`, `sub_1006A4A0`, `sub_102D7FF9`, `CDx::SetTransform`, `MoProcessor_CallVSlot49`, `CMoDX::SetWorldMatrix`
- `EndEffectOffscreenPass` calls `CMoDX::SetViewMatrix`, `CTsZoneMap::DrawProjectedTexture`
- `EffectOffscreen_Init` calls nothing directly
- `EffectOffscreen_FreeSplineSet` calls `CMoSpline::Destructor`, `thunk_sub_10028AA0`
- `LinkNode_Init` calls nothing directly
