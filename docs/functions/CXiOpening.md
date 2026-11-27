# CXiOpening

Group: `CXi` (by the file name only). Source: `sdk/tree_src/CXiOpening.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CXiOpening::Constructor` | 0x100186C0 | 260 | yes | - | - | - |
| `CXiOpening::CXiOpening_Destructor` | 0x100187D0 | 110 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CXiOpening::Constructor` calls `GammaRamp_GetRGB`, `GammaRamp_SetRGB`, `game_10312050`, `Allocator_Generic`, `OpeningSubtitle_Constructor`, `OpeningSubtitle_Reset`, `Vt10329FE0_Constructor`, `Vt10329FE0_Reset`
- `CXiOpening::CXiOpening_Destructor` calls `GammaRamp_SetRGB`
