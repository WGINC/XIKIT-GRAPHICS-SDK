# CYyModelDtStreamed

Group: `CYy` (by the file name only). Source: `sdk/tree_src/CYyModelDtStreamed.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CYyModelDtStreamed::Slot11ReturnZero` | 0x10025090 | 3 | yes | - | Returns 0. (reviewed as sub_10025090) | high |
| `CYyModelDtStreamed::ScalarDeletingDtor` | 0x100250A0 | 30 | yes | - | - | - |
| `CYyModelDtStreamed::ScalarDeletingDtor_2` | 0x100252D0 | 30 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CYyModelDtStreamed::Slot11ReturnZero` calls nothing directly
- `CYyModelDtStreamed::ScalarDeletingDtor` calls `sub_100250C0`, `thunk_sub_10028AA0`
- `CYyModelDtStreamed::ScalarDeletingDtor_2` calls `sub_100252F0`, `operator_delete`
