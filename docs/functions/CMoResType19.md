# CMoResType19

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoResType19.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoResType19::SetupNop` | 0x10054480 | 1 | yes | - | Setup that does nothing. (reviewed as sub_10054480) | high |
| `CMoResType19::Slot9Nop` | 0x10054490 | 1 | yes | - | Does nothing. (reviewed as sub_10054490) | high |
| `CMoResType19::ScalarDeletingDtor` | 0x10071C40 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoResType19::SetupNop` calls nothing directly
- `CMoResType19::Slot9Nop` calls nothing directly
- `CMoResType19::ScalarDeletingDtor` calls `CMoResource::Destructor`, `SharedDeleteHelper`
