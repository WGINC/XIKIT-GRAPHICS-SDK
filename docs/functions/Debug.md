# Debug

Group: `Debug` (by the file name only). Source: `sdk/tree_src/Debug.cpp`.

6 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `DebugOverlay_Draw` | 0x10003650 | 8 | yes | - | - | - |
| `Debug_Construct` | 0x10003660 | 23 | yes | - | Constructs the debug text object and clears its buffers. | low |
| `DebugOverlay_Update` | 0x10003710 | 184 | yes | 1 | Builds the debug overlay buffers on first use and draws it on later frames. | medium |
| `DebugOverlay_SetEntry` | 0x100037D0 | 190 | yes | - | Stores one debug overlay entry (id, four floats, text and colour) at the given index. | medium |
| `Debug_DrawTextTable` | 0x10003B60 | 518 | yes | 0 | - | - |
| `Debug_DrawWorldText` | 0x10003D70 | 654 | yes | 0 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `DebugOverlay_Draw` calls `DebugOverlay_Update`
- `Debug_Construct` calls nothing directly
- `DebugOverlay_Update` calls `InputDevices_DrawActorAxes`, `Debug_DrawTextTable`, `Allocator_Generic`, `DebugOverlay_SetEntry`
- `DebugOverlay_SetEntry` calls `ErrorReport_NoOpVarargsA`, `game_10312050`
- `Debug_DrawTextTable` calls `Debug_DrawWorldText`
- `Debug_DrawWorldText` calls `game_10312150`, `MathVector_ReturnThis`, `ShapeMng::ShapeMng_BindFontTexture`, `Mat4_SetIdentity`, `Mat4_SetTranslation`, `CDx::SetTransform`, `Gfx_ProjectWorldToClip`, `Gfx_NdcToScreen`, `ShapeMng_GetFontGlyph`, `Vec3_Scale`, `Vec3_Add_10026FA0`, `CDx::DrawPrimitiveUP`, `MathVector_Nop`
