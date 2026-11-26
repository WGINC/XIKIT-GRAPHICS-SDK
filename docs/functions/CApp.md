# CApp

Group: `CApp` (by the file name only). Source: `sdk/tree_src/CApp.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CApp::RunMainLoop` | 0x10001520 | 406 | yes | 1 | - | - |
| `CApp::CopyTextToClipboard` | 0x10001CC0 | 95 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CApp::RunMainLoop` calls `App_ForceForegroundWindow`, `CDx::Initialize`, `App_CreateInputSystem`, `Allocator_Generic`, `App_Constructor`, `App_SetSeqStep`, `App_InitScene`, `App_RenderFrameMaskedFPU`, `CApp::CopyTextToClipboard`, `game_100016C0`, `Camera_ReleaseAll`
- `CApp::CopyTextToClipboard` calls nothing directly
