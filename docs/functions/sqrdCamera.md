# sqrdCamera

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqrdCamera.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqrdCamera_Init` | 0x10291110 | 75 | yes | - | Initialises a sqrdCamera with its default near, far and field values. | medium |
| `sqrdCamera_Apply` | 0x102911E0 | 25 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqrdCamera_Init` calls nothing directly
- `sqrdCamera_Apply` calls `SqgxContext_SetPerspective`
