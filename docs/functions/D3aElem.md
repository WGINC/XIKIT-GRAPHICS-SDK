# D3aElem

Group: `D3a` (by the file name only). Source: `sdk/tree_src/D3aElem.cpp`.

Why the file has this name (data/unit_names.json): CMoD3aElem, YmElem_DrawD3ASegment / SetD3ADrawState

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `YmElem_DrawD3ASegment` | 0x1003E910 | 133 | yes | 0 | Draws one D3A segment of an element batch with its draw state and vertex batch. | low |
| `YmElem_SetD3ADrawState` | 0x1003E9A0 | 346 | yes | 0 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `YmElem_DrawD3ASegment` calls `TexRef_SetTexture`, `YmElem_SetD3ADrawState`, `CMoVuElem_Draw`
- `YmElem_SetD3ADrawState` calls `MoDX_SetInvalid`, `sub_10313486`, `StateBlock_ApplyTSS`
