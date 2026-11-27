# CEnv

Group: `CEnv` (by the file name only). Source: `sdk/tree_src/CEnv.cpp`.

4 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `j_CEnv_UpdateDualTargetMode` | 0x1000D3F0 | 5 | yes | - | - | - |
| `CEnv::Nop` | 0x1000D620 | 1 | yes | - | Does nothing. (reviewed as game_1000D620) | low |
| `CEnv::UpdateStereoMode` | 0x1000D630 | 42 | yes | - | - | - |
| `CEnv::IsStereoMode` | 0x1000D660 | 9 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `j_CEnv_UpdateDualTargetMode` calls `CEnv::UpdateStereoMode`
- `CEnv::Nop` calls nothing directly
- `CEnv::UpdateStereoMode` calls `CEnv::IsStereoMode`
- `CEnv::IsStereoMode` calls nothing directly
