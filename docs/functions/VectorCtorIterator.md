# VectorCtorIterator

Group: `Vector` (by the file name only). Source: `sdk/tree_src/VectorCtorIterator.cpp`.

Why the file has this name (data/unit_names.json): its one named neighbour is the compiler's ??_H (vector constructor iterator, unit_evidence 0x100010A0); its function calls a callback for each element, called from object-array constructors (CreateProcessorInstance, the ZoneMap constructor)

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `VectorCtorIterator_CallForEachElement` | 0x10001070 | 42 | yes | - | Calls a thiscall function on each element of an array, given its base, element size and count. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `VectorCtorIterator_CallForEachElement` calls nothing directly
