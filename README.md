# xikit graphics SDK

A devkit for changing how FINAL FANTASY XI draws. Mods hook the game's graphics functions and its Direct3D 8 device,
draw between the world and the interface, run their own HLSL shaders and read depth through a Direct3D 12 renderer,
with settings that apply while the game runs. It covers the game's builds 6A995428 (3 Sep 2026), 6AC37846 and 6AE818B4
(2 Nov 2026, the current one).

This repository is the devkit's public home: release 1, built and ready to use, and its source.

## Graphics only

This kit names and describes the game's graphics functions and nothing else. A function belongs to it when
`sdk/seams.json` gives it a depth: the fewest direct calls (`call rel32`, read from the game's code) from the function
to one with a Direct3D call site proven in the game. That is 537 functions; the rest of the game is not here.

- **Hookable:** 432 of them are in the manifests of 6A995428 and 6AC37846, and 428 in the manifest of 6AE818B4.
- **Source:** `sdk/tree_src` holds the source of 434 of them, reconstructed and checked against the game's code.
- **Calls outside the set:** that source also calls 1,054 game functions outside the set. Each one is declared in
  `sdk/tree_include/gfx_orig.hpp` as `orig::sub_<address>`, with its address and call signature only: no name and
  no body.
- **Symbols:** the PDBs and symbol lists (`pdb/`, `sdk/symbols/`) name the same 537 functions. They also name the
  globals the kept source uses: 1,134 in 6A995428 and 1,077 in 6AE818B4. 6AC37846's has no globals, because its build
  file has no data ranges. Each holds 410 class, struct and union types, from the kept headers.

The kit does not swap reconstructed code into the game: `gfx_recon_ingame.dll` is not part of it. A mod's hooks run on
the game's own code. Every function in these manifests has a trampoline, so `previous` is always the game's own
function.

## What is here

| Folder | What |
|---|---|
| `kit/` | `xikit.dll` (loads mods, hooks the device, captures frames), its `xikit.ini` (`swap=0`, list your mods on `mods=`), and the manifests of the three builds |
| `d3d8on11/` | the renderer: Direct3D 8 on Direct3D 12 (or 11), with shader passes for mods (`d3d8.dll`, `d8x.exe`, `d8x_arm64.exe`) |
| `sdk/` | the headers (`include/`, `tree_include/`), the source of the graphics functions (`tree_src/`), the examples, the Visual Studio / VS Code template, `build_mod.sh` / `build_mod.bat`, and `SDK.md` |
| `pdb/` | `FFXiMain.pdb` for each build (names, sizes and class types for a debugger) and its symbol list as JSON |
| `tools/` | the frame inspector (`tools/fcap/frame_inspect.py`) and its replayer |
| `src/` | the source of the kit (`src/xikit`), the renderer (`src/d3d8on11`), the device profiler and frame capture (`src/d3dprof`), the replayer (`src/fcap`), and the release's first-run check (`src/devkit`) |
| `devkit_check.exe`, `SHA256SUMS.txt` | the first-run check, and the files it checks |

No file of the game is here. The kit reads the game in memory. The manifests, the source and the PDBs are made from
the game's code in a separate analysis repository, and they name the graphics functions and their addresses.

## First run

    devkit_check.exe "C:\Program Files (x86)\PlayOnline\SquareEnix\FINAL FANTASY XI"

The check does three things:

- checks every file against `SHA256SUMS.txt`;
- reads which build the game's `FFXiMain.dll` is, and whether the kit has a manifest for it;
- says whether the PlayOnlineViewer folder's `d3d8.dll` is d3d8on11, which shader passes need.

The exit code is 0 when every file is right and the build is known.

To use the kit in the game:

1. Copy `kit/` and `d3d8on11/` into the PlayOnlineViewer folder.
2. Put your mod there.
3. List it in `xikit.ini` (`mods=my_mod.dll`).

## Writing a mod (`sdk/SDK.md`)

- Replace any of the manifest's functions (`XI_HOOK`), with the game's own code as `previous`.
- Hook any method of the game's Direct3D 8 device (`XI_DEVICE_HOOK`), and draw every frame (`xikit_mod_frame`).
- Draw between the finished world and the interface by hooking `CDx::CompositeSceneToBackBuffer`
  (`sdk/examples/scene_tint.cpp`).
- Run HLSL pixel shaders over a texture and read the world's depth, with d3d8on11 (`xikit_render.h`;
  `sdk/examples/scene_shader.cpp`, `sdk/examples/depth_view.cpp`). Depth needs `depth_reads=1` in `d3d8on11.ini`.
- Declare settings (`declare_int`). They are kept in `xikit_mods.ini`, listed in `xikit_settings.txt`, and applied
  while the game runs.
- Rebuild and reload while the game runs (`mod_reload=1`).
- Debug at source level in Visual Studio. The template builds with clang from llvm-mingw, because Visual Studio's own
  compiler cannot read the headers.

The interface is version 4 and frozen: fields are only ever added after the last one. `sdk/include/xikit_mod.h`
checks the layout at compile time.

**Not in this kit:**

- swapping the reconstruction in (`swap=1`): without `gfx_recon_ingame.dll` the kit then does nothing;
- forks (`XI_FORK`, `fork.py gate`), and calling a reconstructed member function directly. Both link against the
  reconstruction DLL. `fork.py new` and `fork.py diff` still copy and compare a function's source.

## The frame inspector

Capture one frame in the game: set `fcap=1` in `xikit.ini`, then create `xikit_fcap_now.txt` next to `xikit.dll`.
Then read it with Python 3, numpy, and Windows or Wine:

    python3 tools/fcap/frame_inspect.py list CAPTURE.fcap                  the draws per game function
    python3 tools/fcap/frame_inspect.py at CAPTURE.fcap 120 draw120.png      the picture after the 120th draw
    python3 tools/fcap/frame_inspect.py compare off.fcap on.fcap diff.png   a mod off and on: the pixels that differ

The inspector names a call site's function from `pdb/`. A site in a function outside the graphics set is shown by
its address.

## What has been run, and what has not

- **This kit as it ships** (no reconstruction, `swap=0`, the cut manifests and headers): tested offline under Wine on
  builds 6A995428 and 6AE818B4. The test loaded a mod built with this SDK. It checked:
  - a function hook, with the game's code as `previous`;
  - a device hook;
  - a setting, read and then read again after a change;
  - that nothing else in the game is patched.

  Every example and the template compile against the cut headers, and so does every source file in `sdk/tree_src`.
- **In the game, not yet in this configuration:** the same `xikit.dll` and d3d8on11 ran in the owner's game (build
  6AE818B4) with the full kit, which had the reconstruction swapped in. There, these ran:
  - mods drawing each frame;
  - the world-and-interface hook;
  - an HLSL shader pass, with its settings changed while the game ran;
  - the world's depth read through `depth_view`;
  - a captured frame listed by the inspector;
  - a Visual Studio 2026 build, attach and breakpoint.
- **Not run:** this kit on build 6AC37846 (the copy here is packed, and the test host maps only an unpacked DLL);
  RenderDoc on the Direct3D 12 renderer; VS Code; WinDbg.

## Building from `src/`

The renderer builds on its own: `src/d3d8on11/build.sh`. It uses MinGW-w64 i686 g++, and zig 0.16.0 (which the
script installs from PyPI as `ziglang`) for the ARM64 executor. Its tests are `src/d3d8on11/test/test_d3d8on11.py`,
run under Wine and Xvfb. The kit's build (`src/xikit/build.sh`) also makes the manifests, which need the analysis
repository's pipeline and a copy of the game's DLL. Its sources here are those of the shipped `kit/`.

## Licence

The devkit's own work is under the GNU Affero General Public License, version 3 (`LICENSE`). That covers the kit, the
renderer, the SDK, the tools and their source. FINAL FANTASY XI and everything of it belong to SQUARE ENIX. Nothing
here is affiliated with or endorsed by them.

## Credits

- **Dellingr:** the devkit (the kit, the renderer, the SDK and the tools).
- **Geno:** help with gobbiefix's Linux side (coming soon).
