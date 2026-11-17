# sqinSkin

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqinSkin.cpp`.

7 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqinSkin_Create` | 0x10299FE0 | 32 | yes | - | Allocates a Squirrel skin object and initialises it. | medium |
| `SqinSkin_Init` | 0x1029A000 | 77 | yes | - | Sets the skin object's type code, callbacks and defaults. | medium |
| `SqinSkin_InitShapeData` | 0x1029A160 | 193 | yes | - | Creates the skin's deform shape and keeps copies of its two 12-byte-per-vertex arrays. | low |
| `SqinSkin_PropagateValue38` | 0x1029A230 | 66 | yes | - | Stores a value in the skin's sub-object and in each matching child. | low |
| `SqinSkin_ResizeItemArray` | 0x1029A330 | 68 | yes | - | Reallocates the skin's item pointer array to a new count. | medium |
| `SqinSkin_BuildPartShapes` | 0x1029A450 | 662 | yes | - | Builds a deform shape for each of the skin's parts and times the steps. | low |
| `SqinSkin_ReleaseIfHasData` | 0x1029A6F0 | 25 | yes | - | Releases the skin when it holds data. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqinSkin_Create` calls `sub_10275D80`, `SqinSkin_Init`
- `SqinSkin_Init` calls `SqinShape_Reset`
- `SqinSkin_InitShapeData` calls `SqdfShape_Create`, `sub_10275D80`
- `SqinSkin_PropagateValue38` calls nothing directly
- `SqinSkin_ResizeItemArray` calls `SqMem_Realloc`
- `SqinSkin_BuildPartShapes` calls `SqTimer_GetMicroseconds`, `sub_10275D80`, `SqskSkeleton_Release`, `sub_1027F0E0`, `SqdfShape_Create`, `SqVec_CopyVec3`, `sqMatrix4_10280140`, `sub_1027EB10`, `sqFree`
- `SqinSkin_ReleaseIfHasData` calls `SqinSkin_BuildPartShapes`
