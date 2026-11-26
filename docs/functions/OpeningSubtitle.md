# OpeningSubtitle

Group: `Opening` (by the file name only). Source: `sdk/tree_src/OpeningSubtitle.cpp`.

Why the file has this name (data/unit_names.json): OpeningSubtitle_Constructor / Reset, the strings music999.bgw and FinalFantasyXI, the registry imports; called from CXiOpening and App_RunOpening

6 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `OpeningSubtitle_IsStateFour` | 0x10018840 | 11 | yes | - | Reports whether the object's state at offset 0x108 is 4. | low |
| `OpeningSubtitle_Constructor` | 0x10018A50 | 141 | yes | - | - | - |
| `OpeningSubtitle_Reset` | 0x10018B30 | 24 | yes | - | - | - |
| `OpeningSubtitle_UpdateRangeEntries` | 0x10018B50 | 241 | yes | 2 | Positions the timed UI entries whose time range the current value falls in and advances the index past finished ranges. | low |
| `Vt10329FE0_Constructor` | 0x10018C50 | 41 | yes | - | - | - |
| `Vt10329FE0_Reset` | 0x10018CE0 | 21 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `OpeningSubtitle_IsStateFour` calls nothing directly
- `OpeningSubtitle_Constructor` calls `game_100731B0`, `game_10071E90`, `ShapeMng_FindShape`, `OpeningSubtitle_Reset`
- `OpeningSubtitle_Reset` calls nothing directly
- `OpeningSubtitle_UpdateRangeEntries` calls `game_10311C2C`, `game_1011FB60`
- `Vt10329FE0_Constructor` calls `Vt10329FE0_Reset`
- `Vt10329FE0_Reset` calls nothing directly
