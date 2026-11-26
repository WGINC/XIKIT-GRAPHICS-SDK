# CopyPair

Group: `Copy` (by the file name only). Source: `sdk/tree_src/CopyPair.cpp`.

Why the file has this name (data/unit_names.json): CopyFrom, CopyReturnZ: read from the code

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CopyPair_CopyFrom` | 0x100ABC20 | 69 | yes | - | Fills an acter record from a template record and a name. | low |
| `CopyPair_CopyReturnZ` | 0x100ABC70 | 25 | yes | - | Copies a three-dword value and returns its last element. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CopyPair_CopyFrom` calls `game_10312050`
- `CopyPair_CopyReturnZ` calls nothing directly
