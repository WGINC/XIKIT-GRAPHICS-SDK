# chasm

Group: `chasm` (by the file name only). Source: `sdk/tree_src/chasm.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `chasm_10273920` | 0x10273920 | 160 | yes | - | - | - |
| `Chasm_ApplyAtCurrentIndex` | 0x10273D60 | 41 | yes | - | Applies an operation to the current chasm entry when its index is valid. | low |
| `Chasm_ToggleLayerState` | 0x10273E80 | 189 | yes | - | Switches an entry's layer state, updating its linked entries and the current index. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `chasm_10273920` calls `sqFree`, `Chn_ReleaseIfSet`
- `Chasm_ApplyAtCurrentIndex` calls `SqVec_GetInterpolated`
- `Chasm_ToggleLayerState` calls `Mdl_SetChannelActive`
