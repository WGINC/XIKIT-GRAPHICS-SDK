# SqinSkinAppend

Group: `sq` (by the file name only). Source: `sdk/tree_src/SqinSkinAppend.cpp`.

Why the file has this name (data/unit_names.json): Append; calls SqinSkin_ResizeItemArray

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqinSkinAppend_Append` | 0x1029A380 | 92 | yes | - | Appends an entry to a growable pointer array and returns its index. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqinSkinAppend_Append` calls `SqinSkin_ResizeItemArray`
