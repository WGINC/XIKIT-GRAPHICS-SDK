# ListUtil

Group: `List` (by the file name only). Source: `sdk/tree_src/ListUtil.cpp`.

Why the file has this name (data/unit_names.json): List_GetTail, PopHead; called from CXiSkeletonActor

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `List_GetTail` | 0x1002C7C0 | 22 | yes | - | - | - |
| `ListUtil_PopHead` | 0x1002C800 | 71 | yes | - | Takes the head entry from one of the object's two lists. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `List_GetTail` calls nothing directly
- `ListUtil_PopHead` calls nothing directly
