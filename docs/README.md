# Reference documentation

Made by `sdk/public_docs.py` in the analysis repository, from this kit's own files and the game's code. Every column has one source, named here; where a source says nothing, the page shows `-`.

- [MODULES.md](MODULES.md): the 409 source files in 98 groups. A group is the first part of the file names, nothing more.
- [FUNCTION_TREE.md](FUNCTION_TREE.md): group, file, function; then the direct-call trees from `CApp::RunMainLoop` and `Frame_Render`.
- [GENERIC.md](GENERIC.md): the names that are still generic.
- The game's systems, read from its code: [INPUT.md](INPUT.md) (keyboard, mouse, pad, the key table, the bindings, macros, the chat line, Command_RunLine) with [INPUT_ACTIONS.md](INPUT_ACTIONS.md) (its actions) and [COMMANDS.md](COMMANDS.md) (its typed commands), [MENUS.md](MENUS.md) (the interface windows), [AUDIO.md](AUDIO.md) (sound volumes), [CAMERA.md](CAMERA.md) (view, projection, distances), [EFFECTS_DRAW.md](EFFECTS_DRAW.md) (how effects are drawn).
- [EFFECT_COMMANDS.md](EFFECT_COMMANDS.md): what each command number of the effect generator and scheduler does, read from their switches (written by `pipeline/effect_commands.py`; security-set calls hidden).
- `functions/<file>.md`: one page per source file.

## The columns

- **Function, Size:** the PDB (`pdb/6A995428/FFXiMain.pdb.json`).
- **Address:** the analysed build, 6A995428. The manifests give each other build's.
- **Hookable:** listed in `kit/xikit_manifest.txt`.
- **D3D depth:** `sdk/seams.json`: the fewest direct calls from the function to one with a Direct3D call site proven in the game's code (0: it has one; `-`: none by direct calls).
- **Summary, Confidence:** the naming review of that function, as written, with the reviewer's confidence (high, medium or low). 3667 of the 4635 functions with source have one. A summary says what the review read in the code; it was not run. Where the review gave another name than the one shown, the summary says so.
- **Direct calls:** the game's code (call or jmp rel32 to a function start). A call through a pointer or a virtual call is not listed.

Functions this kit leaves out (the network, its encryption, the packets and the debug link) appear only as `XI_<CATEGORY>_<address> (left out)` (XI_NETWORK, XI_PACKET, XI_CRYPT, XI_LOBBY, XI_DEBUGLINK) where a kept function calls them: no name, no summary, nothing they call.
