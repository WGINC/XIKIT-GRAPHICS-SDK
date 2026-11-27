# CYyVb

Group: `CYy` (by the file name only). Source: `sdk/tree_src/CYyVb.cpp`.

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CYyVb::Init` | 0x1003B420 | 16 | yes | - | Initialises a CYyVb object's vtable and its field at offset 8. (reviewed as game_1003B420) | medium |
| `CYyVb_ScalarDelete` | 0x1003B430 | 30 | yes | - | Destroys a CYyVb object and frees its storage when the delete flag is set. | medium |
| `CYyVb::Constructor` | 0x1003B450 | 69 | yes | - | - | - |
| `CYyVb::Destroy` | 0x1003B4A0 | 48 | yes | - | Releases a CYyVb object's resources and unlinks it from the vertex buffer list. (reviewed as game_1003B4A0) | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CYyVb::Init` calls nothing directly
- `CYyVb_ScalarDelete` calls `CYyVb::Destroy`, `thunk_Mem_FreeBlockMergeNeighbours_as_v0`
- `CYyVb::Constructor` calls `VertexBufferList_Register`
- `CYyVb::Destroy` calls nothing directly
