# sqgxDlist

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqgxDlist.cpp`.

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqgxDlist_CreateContextList` | 0x1029B5C0 | 82 | yes | - | Creates the display list for the sqgx context and clears its counters. | medium |
| `sqgxDlistEnd` | 0x1029B620 | 792 | yes | 0 | - | - |
| `sqgxDlistDraw` | 0x1029B9D0 | 383 | yes | 0 | - | - |
| `SqgxDlist_Nop` | 0x1029BB50 | 1 | yes | - | Does nothing. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqgxDlist_CreateContextList` calls `game_10275D80`
- `sqgxDlistEnd` calls `sqFree`
- `sqgxDlistDraw` calls `game_1028A730`, `sqgxShapeBegin`, `game_1028BBD0`
- `SqgxDlist_Nop` calls nothing directly
