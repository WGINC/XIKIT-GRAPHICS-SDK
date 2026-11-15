# xikit devkit, release 1

A kit for changing how FINAL FANTASY XI draws, for the game's builds 6A995428 (3 Sep 2026), 6AC37846 and 6AE818B4
(2 Nov 2026, the current one). It holds no game code or data.

## What is in it

| Folder | What | Details |
|---|---|---|
| `kit/` | `xikit.dll` (the kit: loads mods, swaps in the reconstruction, measures), `gfx_recon_ingame.dll` (the reconstruction: the game's graphics functions as gate-verified C++), the manifests of the three builds | docs/KIT.md |
| `d3d8on11/` | the renderer: Direct3D 8 on Direct3D 12 (or 11), with shader passes for mods | its README in the repository |
| `sdk/` | the headers (`include/`), the reconstruction's headers and source, the examples, the Visual Studio / VS Code template, `build_mod.sh` / `build_mod.bat`, `SDK.md` | `sdk/SDK.md` |
| `pdb/` | `FFXiMain.pdb` for each build: the reconstruction's names, sizes and class types for a debugger, and its symbol list as JSON | docs/DEVKIT.md |
| `tools/` | the frame inspector (`tools/fcap/frame_inspect.py`, with the replayer) | below |
| `devkit_check.exe` | the first-run check | below |

## First run

    devkit_check.exe "C:\Program Files (x86)\PlayOnline\SquareEnix\FINAL FANTASY XI"

It checks every file against `SHA256SUMS.txt`, reads which build the game's `FFXiMain.dll` is and whether the kit
has a manifest for it, and says whether the PlayOnlineViewer folder's `d3d8.dll` is d3d8on11 (needed for shader
passes). Exit code 0 when all files are right and the build is known.

To use the kit in the game: copy `kit/` and `d3d8on11/` into the PlayOnlineViewer folder (gobbiefix, the release of
these for players, installs the same files: its `install.bat` puts its own back afterwards), put your mod there,
and list it in `xikit.ini` (`mods=speedfix.dll,my_mod.dll`).

## What a mod can do (sdk/SDK.md)

- Replace any of the manifest's functions (`XI_HOOK`), with the game's own code as `previous`, or fork a
  reconstructed function and edit it (`fork.py`, `XI_FORK`).
- Hook any method of the game's Direct3D 8 device (`XI_DEVICE_HOOK`), and draw every frame (`xikit_mod_frame`).
- Draw between the finished world and the interface (`CDx::CompositeSceneToBackBuffer`; `examples/scene_tint.cpp`).
- Run its own HLSL pixel shaders over a texture, and read depth (`xikit_render.h`, with d3d8on11;
  `examples/scene_shader.cpp`, `examples/depth_view.cpp`).
- Declare settings, kept in `xikit_mods.ini` and applied while the game runs (`declare_int`; listed in
  `xikit_settings.txt`).
- Be rebuilt and reloaded while the game runs (`mod_reload=1`), and debugged at source level in Visual Studio
  (the template; `XIKIT_PDB=1`).

The interface is version 4 and frozen: fields are only ever added after the last (`xikit_mod.h` checks the layout at
compile time).

## The frame inspector

The kit captures one frame with everything it uses (`fcap=1` in `xikit.ini`, or create `xikit_fcap_now.txt` next to
`xikit.dll` while the game runs: `xikit_fcap_<pid>_<n>.fcap`). Then, with Python 3, numpy, Wine or Windows:

    python3 tools/fcap/frame_inspect.py list CAPTURE.fcap              the draws per game function
    python3 tools/fcap/frame_inspect.py at CAPTURE.fcap 120 draw120.png  the picture after the 120th draw
    python3 tools/fcap/frame_inspect.py compare off.fcap on.fcap diff.png  a mod off and on: the pixels that differ

## What is known and what is not

- Run in the owner's game (build 6AE818B4): the reconstruction swapped in (88 functions kept on the game's code
  there), a mod's frame drawing, the world-and-interface hook, a Visual Studio 2026 build, attach and breakpoint.
- Tested offline only, not yet in the game: shader passes and depth reads, settings applied live, the frame
  inspector's call sites.
- Not known: which depth surface is the world's in the game (`examples/depth_view.cpp` establishes it); whether
  RenderDoc can capture the Direct3D 12 renderer (not tried).
