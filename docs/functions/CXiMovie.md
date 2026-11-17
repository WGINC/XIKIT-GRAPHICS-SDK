# CXiMovie

Group: `CXi` (by the file name only). Source: `sdk/tree_src/CXiMovie.cpp`.

8 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CXiMovie::Draw` | 0x10026AD0 | 414 | yes | 0 | - | - |
| `CXiMovie::Create` | 0x1021D3D0 | 98 | yes | - | Creates the movie object for a file and stores it as the current movie. (reviewed as sub_1021D3D0) | medium |
| `CXiMovie::UpdateIfPresent` | 0x1021D440 | 18 | yes | - | Runs 0x1021D960 when a movie exists. (reviewed as sub_1021D440) | low |
| `CXiMovie_DestroyGlobal` | 0x1021D460 | 43 | yes | - | Releases the current movie object and clears sub_10666E7C. | medium |
| `CXiMovie::GetField4` | 0x1021D490 | 16 | yes | - | Returns the field at +4 of the current movie. (reviewed as sub_1021D490) | low |
| `CXiMovie::GetDoubleField8` | 0x1021D4A0 | 20 | yes | - | Returns the double at +8 of the current movie. (reviewed as sub_1021D4A0) | low |
| `CXiMovie::DrawFrame` | 0x1021D4C0 | 811 | yes | 0 | - | - |
| `CXiMovie::Construct` | 0x1021D7F0 | 99 | yes | - | Constructs the movie object, clearing its fields and releasing the four held objects. (reviewed as sub_1021D7F0) | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CXiMovie::Draw` calls `CDx::DrawPrimitiveUP`
- `CXiMovie::Create` calls `sub_10311FDE`, `sub_10311F30`, `Mem_AllocDefault`, `CXiMovie::Construct`, `MenuPanels_InitAndMarkReady`, `CXiMovie_DestroyGlobal`
- `CXiMovie::UpdateIfPresent` calls nothing directly
- `CXiMovie_DestroyGlobal` calls `MenuPanels_ReleaseReturnTrue`
- `CXiMovie::GetField4` calls nothing directly
- `CXiMovie::GetDoubleField8` calls nothing directly
- `CXiMovie::DrawFrame` calls `Movie_Update`, `Movie_GetCurrentTexture`, `sub_10311C2C`, `CDx_SetDefaultRenderState`, `CDx::DrawPrimitiveUP`
- `CXiMovie::Construct` calls nothing directly
