# sqopTrack

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqopTrack.cpp`.

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqopTrack_Reset` | 0x10289B40 | 22 | yes | - | Resets the track's first word to -1 and clears its other three fields. | medium |
| `SqopTrack_Free` | 0x10289BA0 | 39 | yes | - | Frees the track's buffer and resets the track. | medium |
| `sqopTrackSetIndex` | 0x10289EF0 | 30 | yes | - | - | - |
| `sqopTrackAdvance` | 0x10289F10 | 18 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqopTrack_Reset` calls nothing directly
- `SqopTrack_Free` calls `sqFree`, `SqopTrack_Reset`
- `sqopTrackSetIndex` calls nothing directly
- `sqopTrackAdvance` calls `sqopTrackSetIndex`
