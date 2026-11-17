# LinkedLibraries

Group: `Linked` (by the file name only). Source: `sdk/tree_src/LinkedLibraries.cpp`.

Why the file has this name (data/unit_names.json): libpng (the strings IDAT, PLTE, "Incorrect tRNS chunk length", "Ignoring incorrect gAMA value"), zlib 1.2.5, the C runtime, the import stubs (Direct3DCreate8, DirectInput8Create, the IMM jumps) (an address range between two evidenced source files, holding several of the original files: named for its main contents)

13 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Imm_GetVirtualKeyJmp` | 0x102BC820 | 6 | yes | - | Jump stub to the imported ImmGetVirtualKey. | high |
| `LinkedLibraries_JmpImmGetDescriptionA` | 0x102BC826 | 6 | yes | - | Jumps to the imported ImmGetDescriptionA. | high |
| `LinkedLibraries_JmpImmGetContext` | 0x102BC82C | 6 | yes | - | Jumps to the imported ImmGetContext. | high |
| `LinkedLibraries_JmpImmReleaseContext` | 0x102BC832 | 6 | yes | - | Jumps to the imported ImmReleaseContext. | high |
| `Imm_NotifyIMEJmp` | 0x102BC838 | 6 | yes | - | Jump stub to the imported ImmNotifyIME. | high |
| `LinkedLibraries_JmpImmSetCandidateWindow` | 0x102BC83E | 6 | yes | - | Jumps to the imported ImmSetCandidateWindow. | high |
| `LinkedLibraries_JmpImmSetCompositionWindow` | 0x102BC844 | 6 | yes | - | Jumps to the imported ImmSetCompositionWindow. | high |
| `Imm_SetOpenStatusJmp` | 0x102BC856 | 6 | yes | - | Jump stub to the imported ImmSetOpenStatus. | high |
| `Imm_GetOpenStatusJmp` | 0x102BC85C | 6 | yes | - | Jump stub to the imported ImmGetOpenStatus. | high |
| `Imm_GetConversionStatusJmp` | 0x102BC862 | 6 | yes | - | Jump stub to the imported ImmGetConversionStatus. | high |
| `Imm_GetCompositionStringAJmp` | 0x102BC868 | 6 | yes | - | Jump stub to the imported ImmGetCompositionStringA. | high |
| `Imm_SetCompositionStringAJmp` | 0x102BC86E | 6 | yes | - | Jump stub to the imported ImmSetCompositionStringA. | high |
| `LinkedLibraries_JmpImmSetConversionStatus` | 0x102BC874 | 6 | yes | - | Jumps to the imported ImmSetConversionStatus. | high |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Imm_GetVirtualKeyJmp` calls nothing directly
- `LinkedLibraries_JmpImmGetDescriptionA` calls nothing directly
- `LinkedLibraries_JmpImmGetContext` calls nothing directly
- `LinkedLibraries_JmpImmReleaseContext` calls nothing directly
- `Imm_NotifyIMEJmp` calls nothing directly
- `LinkedLibraries_JmpImmSetCandidateWindow` calls nothing directly
- `LinkedLibraries_JmpImmSetCompositionWindow` calls nothing directly
- `Imm_SetOpenStatusJmp` calls nothing directly
- `Imm_GetOpenStatusJmp` calls nothing directly
- `Imm_GetConversionStatusJmp` calls nothing directly
- `Imm_GetCompositionStringAJmp` calls nothing directly
- `Imm_SetCompositionStringAJmp` calls nothing directly
- `LinkedLibraries_JmpImmSetConversionStatus` calls nothing directly
