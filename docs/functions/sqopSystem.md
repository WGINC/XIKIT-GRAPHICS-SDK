# sqopSystem

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqopSystem.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `sqopSystemActivate` | 0x102531B0 | 84 | yes | - | - | - |
| `SqopSystem_Init` | 0x10289620 | 57 | yes | - | Initialises the opcode system and its function table. | medium |
| `SqopSystem_ClearOpcodes` | 0x102896A0 | 85 | yes | - | Frees the opcode entries and re-initialises the system. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `sqopSystemActivate` calls `sqopTrackSetIndex`
- `SqopSystem_Init` calls nothing directly
- `SqopSystem_ClearOpcodes` calls `SqopTrack_Free`, `sqFree`, `SqopSystem_Init`
