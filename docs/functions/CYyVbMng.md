# CYyVbMng

Group: `CYy` (by the file name only). Source: `sdk/tree_src/CYyVbMng.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CYyVbMng::AcquireVertexBuffer` | 0x1003B210 | 420 | yes | 0 | - | - |
| `CYyVbMng::ReleaseVertexBuffer` | 0x1003B3C0 | 59 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CYyVbMng::AcquireVertexBuffer` calls `Mem_AllocDefault`, `CYyVb::Constructor`
- `CYyVbMng::ReleaseVertexBuffer` calls nothing directly
