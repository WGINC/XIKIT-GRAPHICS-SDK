# CShader

Group: `CShader` (by the file name only). Source: `sdk/tree_src/CShader.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CShader::GetRuntimeClass` | 0x10017750 | 6 | yes | - | - | - |
| `CShader::ScalarDeletingDtor` | 0x10017780 | 30 | yes | 1 | - | - |
| `CShader::CShader_Destructor` | 0x100177A0 | 57 | yes | 0 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CShader::GetRuntimeClass` calls nothing directly
- `CShader::ScalarDeletingDtor` calls `CShader::CShader_Destructor`, `thunk_Mem_FreeBlockMergeNeighbours_as_v0`
- `CShader::CShader_Destructor` calls nothing directly
