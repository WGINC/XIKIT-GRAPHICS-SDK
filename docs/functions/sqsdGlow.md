# sqsdGlow

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqsdGlow.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqsdGlow_ApplyShader` | 0x102999A0 | 205 | yes | 1 | Sets the glow parameters and applies the glow shader. | low |
| `sqsdGlow_BakeOntoShape` | 0x10299AB0 | 113 | yes | 1 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqsdGlow_ApplyShader` calls `SqsdPassTest_TestSeparationHalf`, `SqgxContext_SetViewportVec4`, `sqgxShader`
- `sqsdGlow_BakeOntoShape` calls `SqsdGlow_ApplyShader`, `SqgxDlist_CreateContextList`, `sqDrawableDraw`, `sqgxDlistEnd`, `SqshDispList_Create`, `SqBounds_Copy`, `SqObject_Release`
