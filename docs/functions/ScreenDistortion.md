# ScreenDistortion

Group: `Screen` (by the file name only). Source: `sdk/tree_src/ScreenDistortion.cpp`.

Why the file has this name (data/unit_names.json): YmElem_DrawScreenDistortion

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `YmElem_DrawScreenDistortion` | 0x100426F0 | 1504 | yes | 0 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `YmElem_DrawScreenDistortion` calls `sub_10313486`, `RegisterWithProcessor`, `CDx::GetRenderTargetTop`, `DynVB_Reserve`, `DynVB_Lock`, `DynVB_Unlock`, `CDx::PushRenderTargetTexture_Flag1`, `MoDX_SetInvalid`, `sub_1006AE30`, `CMoVuElem_Draw`, `sub_1006A0E0`, `CMoDX::SetWorldMatrix`
