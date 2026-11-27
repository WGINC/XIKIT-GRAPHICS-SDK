# CMoPointLightProgElem

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoPointLightProgElem.cpp`.

5 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoPointLightProgElem::GetRuntimeClass` | 0x100562E0 | 6 | yes | - | - | - |
| `CMoPointLightProgElem::Construct` | 0x100562F0 | 101 | yes | - | Constructs a point-light programme element with its type id. (reviewed as game_100562F0) | medium |
| `CMoPointLightProgElem::IsKind11` | 0x10056360 | 15 | yes | - | Returns whether the argument is 11, the kind this element class answers to. (reviewed as game_10056360) | medium |
| `CMoPointLightProgElem::ScalarDeletingDtor` | 0x10056370 | 30 | yes | - | - | - |
| `CMoPointLightProgElem::Update` | 0x10056400 | 237 | yes | - | Creates the point light on first use, then updates its intensity and position each time. (reviewed as game_10056400) | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoPointLightProgElem::GetRuntimeClass` calls nothing directly
- `CMoPointLightProgElem::Construct` calls `CMoElem::Constructor`
- `CMoPointLightProgElem::IsKind11` calls nothing directly
- `CMoPointLightProgElem::ScalarDeletingDtor` calls `game_10056390`, `SharedDeleteHelper`
- `CMoPointLightProgElem::Update` calls `game_10178610`, `game_10178530`
