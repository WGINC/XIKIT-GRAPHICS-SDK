# CXiDollActor

Group: `CXi` (by the file name only). Source: `sdk/tree_src/CXiDollActor.cpp`.

5 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CXiDollActor_GetPtr404` | 0x100ABD90 | 7 | yes | - | Returns the address of the doll actor's member at +0x404. | low |
| `CXiDollActor_GetPtr414` | 0x100ABDA0 | 7 | yes | - | Returns the address of the doll actor's member at +0x414. | low |
| `CXiDollActor_GetFloat434` | 0x100ABE30 | 7 | yes | - | Returns the doll actor's float at +0x434. | low |
| `CXiDollActor_GetFloat438` | 0x100ABE40 | 7 | yes | - | Returns the doll actor's float at +0x438. | low |
| `CXiDollActor_GetVec4At104` | 0x100ABFB0 | 33 | yes | - | Copies the index-th 16-byte vector of the array at +0x104 to the output and returns true. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CXiDollActor_GetPtr404` calls nothing directly
- `CXiDollActor_GetPtr414` calls nothing directly
- `CXiDollActor_GetFloat434` calls nothing directly
- `CXiDollActor_GetFloat438` calls nothing directly
- `CXiDollActor_GetVec4At104` calls `Vec4_Copy`
