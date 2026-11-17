# ModelBaseParts

Group: `Model` (by the file name only). Source: `sdk/tree_src/ModelBaseParts.cpp`.

Why the file has this name (data/unit_names.json): CYyModelBase::AddPartFromResource / GetPartList / SetResourceAndRebuild

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ModelBaseParts_FindTailLink` | 0x10029EB0 | 21 | yes | - | Returns the address of the last link of the list at +0x20. | medium |
| `ModelBaseParts_AppendAtTail` | 0x10029F00 | 14 | yes | - | Appends a value at the tail of the list. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ModelBaseParts_FindTailLink` calls nothing directly
- `ModelBaseParts_AppendAtTail` calls `ModelBaseParts_FindTailLink`
