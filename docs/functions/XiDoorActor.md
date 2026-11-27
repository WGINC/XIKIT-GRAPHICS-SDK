# XiDoorActor

Group: `Xi` (by the file name only). Source: `sdk/tree_src/XiDoorActor.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `XiDoorActor_NopSlot161` | 0x100AC380 | 1 | yes | - | Does nothing. | low |
| `XiDoorActor::UpdateAndRunTimer` | 0x100AC4E0 | 182 | yes | - | Runs the base update, copies two vectors into the +0x5C4 block, and counts down a frame-scaled timer that fires a stored callback. (reviewed as game_100AC4E0) | low |
| `XiDoorActor_GetPtr5C4` | 0x100AC9C0 | 7 | yes | - | Returns the address of the door actor's member at +0x5C4. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `XiDoorActor_NopSlot161` calls nothing directly
- `XiDoorActor::UpdateAndRunTimer` calls `game_100A57F0`, `Camera_GetFrameScale`, `game_10311C2C`
- `XiDoorActor_GetPtr5C4` calls nothing directly
