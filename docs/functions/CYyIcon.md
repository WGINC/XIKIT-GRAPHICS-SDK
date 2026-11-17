# CYyIcon

Group: `CYy` (by the file name only). Source: `sdk/tree_src/CYyIcon.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CYyIcon::Draw` | 0x10026990 | 311 | yes | 0 | - | - |
| `CYyIcon::DrawSubRect` | 0x10026C70 | 361 | yes | 0 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CYyIcon::Draw` calls `CDx::DrawPrimitiveUP`
- `CYyIcon::DrawSubRect` calls `CDx::DrawPrimitiveUP`
