# YkZip

Group: `Yk` (by the file name only). Source: `sdk/tree_src/YkZip.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `YkZip_DoNothing` | 0x1012AC50 | 1 | yes | - | Does nothing. | low |
| `YkZip::Construct` | 0x10244DF0 | 45 | yes | - | Constructs the zip object and sets its vtable and defaults. (reviewed as game_10244DF0) | medium |
| `YkZip_SetGlobal2CTo31Or32` | 0x10244E60 | 42 | yes | - | When its argument is set, stores 0x32 or 0x31 at +0x2C of the object at 0x10669078, depending on whether a short in this object's +8 member is 2. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `YkZip_DoNothing` calls nothing directly
- `YkZip::Construct` calls `NetCellFont_ClearWords`, `LobbyThread_NoOp`
- `YkZip_SetGlobal2CTo31Or32` calls nothing directly
