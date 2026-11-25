# xikit graphics SDK

A devkit for modding FINAL FANTASY XI, made first for how it draws. Mods hook the game's functions and its Direct3D 8
device,
draw between the world and the interface, run their own HLSL shaders and read depth through a Direct3D 12 renderer,
with settings that apply while the game runs. It covers the game's builds 6A995428 (3 Sep 2026), 6AC37846 and 6AE818B4
(2 Nov 2026, the current one).

This repository is the devkit's public home: release 3, built and ready to use, and its source.

## What this kit covers, and what it leaves out

This kit holds the game's code except its network, its encryption and its packets. The functions it leaves out,
1,110 of them, are listed in the analysis repository (`data/security_set.json`, made by `sdk/security_set.py`), each
with its reason from the game's code:

- **Transport:** the code that calls Winsock, and the code that drives the game's connection.
- **Encryption:** the Blowfish, MD5 and SHA-1 code.
- **Outgoing packets:** the game connection's packet queue, and every function that builds an outgoing packet.
- **Incoming packets:** the 191 incoming packet handlers, and the code that registers them.
- **Lobby:** the lobby connection's requests, and the code that drives them (its reply step and the table that installs it).
- **Debug link:** a TCP server and client library the game carries for development, and the game code that sets it up.
- **Helpers:** the functions that only these call, and those that do nothing but call them.

The rest is here:

- **Hookable:** 4,602 functions in the manifests of 6A995428 and 6AC37846, 4,532 in that of 6AE818B4.
- **Source:** `sdk/tree_src` holds the source of 4,635 functions, reconstructed and checked against the game's code,
  in 409 files named for what they hold. A few files are address ranges holding several of the original files; the
  analysis repository's `data/unit_names.json` gives the evidence for each name.
- **Calls into the left-out code:** the kept source calls 36 functions of the left-out code. Each is declared in
  `sdk/tree_include/gfx_orig.hpp` as `orig::XI_<CATEGORY>_<address>`, with its address and call signature only. The
  category says which part of the left-out code it is: `XI_NETWORK`, `XI_PACKET`, `XI_CRYPT`, `XI_LOBBY` or
  `XI_DEBUGLINK` (a helper shared by several parts is `XI_NETWORK`).
- **Symbols:** the PDBs and symbol lists (`pdb/`, `sdk/symbols/`) name every function but the left-out ones: 20,294
  in 6A995428. Of those, 4,635 (every function with source) are named by the source, 425 by other recorded
  evidence, and the rest are `sub_<address>`. They also name the globals: 4,242 in 6A995428 and in 6AC37846, 4,061 in 6AE818B4. Each PDB holds 602 class, struct and union types.

The kit does not swap reconstructed code into the game: `gfx_recon_ingame.dll` is not part of it. A mod's hooks run on
the game's own code. Every function in these manifests has a trampoline, so `previous` is always the game's own
function.

## What is here

| Folder | What |
|---|---|
| `kit/` | `xikit.dll` (loads mods, hooks the device, captures frames), its `xikit.ini` (`swap=0`, list your mods on `mods=`), and the manifests of the three builds |
| `d3d8on11/` | the renderer: Direct3D 8 on Direct3D 12 (or 11), with shader passes for mods (`d3d8.dll`, `d8x.exe`, `d8x_arm64.exe`) |
| `sdk/` | the headers (`include/`, `tree_include/`), the reconstructed source (`tree_src/`), the examples, the Visual Studio / VS Code template, `build_mod.sh` / `build_mod.bat`, and `SDK.md` |
| `mods/` | twelve example mods for players, built from `sdk/examples` (below): list one in `kit/xikit.ini`'s `mods=` |
| `docs/` | the reference: a page per source file (every function, its address, whether it is hookable, its review's summary, what it calls), the files by name group, the call trees from the main loop and `Frame_Render`, and the names still generic (`docs/README.md` says where each column comes from) |
| `pdb/` | `FFXiMain.pdb` for each build (names, sizes and class types for a debugger) and its symbol list as JSON |
| `tools/` | the frame inspector (`tools/fcap/frame_inspect.py`) and its replayer |
| `src/` | the source of the kit (`src/xikit`), the renderer (`src/d3d8on11`), the device profiler and frame capture (`src/d3dprof`), the replayer (`src/fcap`), and the release's first-run check (`src/devkit`) |
| `devkit_check.exe`, `SHA256SUMS.txt` | the first-run check, and the files it checks |

No file of the game is here. The kit reads the game in memory. The manifests, the source and the PDBs are made from
the game's code in a separate analysis repository, and they name the game's functions and their addresses.

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

The interface is version 5 (hook chains, mod info) and frozen: fields are only ever added after the last one. `sdk/include/xikit_mod.h`
checks the layout at compile time.

**Not in this kit:**

- swapping the reconstruction in (`swap=1`): without `gfx_recon_ingame.dll` the kit then does nothing;
- forks (`XI_FORK`, `fork.py gate`), and calling a reconstructed member function directly. Both link against the
  reconstruction DLL. `fork.py new` and `fork.py diff` still copy and compare a function's source.

## The example mods (`mods/`, source in `sdk/examples`)

Each source file's first comment says where the mod hooks, what it reads of the game and from which code, and what is
not known. Their settings appear in `xikit_mods.ini` once the mod has run. All of them were tested offline (below);
none has run in the game yet.

| Mod | What it does |
|---|---|
| `texture_replace` | Textures from DDS files (`textures\<name>_<crc>.dds` or `<name>.dds`), any size; `tex_dump=1` writes the game's textures out to find their names. Fonts are textures too |
| `file_overlay` | Any of the game's files from overlay packs (`overlay\<pack>\<path below FINAL FANTASY XI>`): models, zones, effects, sound effects, music. Reads only |
| `effect_comfort` | A limit on full-screen flashes (`flash_limit`, `flash_rise_ms`), an effect intensity (`fx_intensity`), and per-effect percentages from `effects.txt`, by path or by file number (`fx_list=1` names them; `docs/EFFECT_COMMANDS.md` lists the effect commands) |
| `camera_view` | Field of view (`fov_deg`), far clip distance (`far_percent`) and the zone's and actors' draw distance (`draw_percent`) |
| `photo_mode` | A free camera orbiting the game's (`photo`, `photo_yaw`, ...), the interface hidden (`photo_hide_ui`), a picture of the world without it (`photo_shot`); chat commands `/photo ...` |
| `world_light` | Fog distance, colour and off; ambient and light brightness |
| `audio_mix` | Interface, effect, ambient and music volume |
| `color_filter` | Colour-blind correction or simulation of the whole frame (`cb_mode`; needs d3d8on11) |
| `ui_layout` | Interface windows moved, each by name (`ui_layout.txt`) or all together (`ui_dx`, `ui_dy`) |
| `hotbar` | Action bars from XIVhotbar2's job files, icons and keybinds, drawn with the game's font; a slot runs its line through the game's command line, as typed (`hotbar.txt`); default keys 1-0 - = (bar 2 with Ctrl, 3 Alt, 4 Shift); the game's macro keys run bars 2 and 3 (`/hb mode hotbar`) or the game's macros (`/hb mode macro`); `/hb run 1.3` |
| `click_target` | Click anywhere on a nameplate to target its character; a click on nothing deselects (`ct_deselect`) |
| `status_text` | The local time over the interface (the tutorial's mod: `sdk/TUTORIAL.md`); `/stext` shows or hides it |

Each changes how the game looks or sounds on your own screen, except that `hotbar` and `click_target` act as the player's own input does: a hotbar slot runs its line through the game's command line, exactly as typing it and pressing Enter would, and a click targets or deselects as the game's own click does. None reads or sends network data itself, nor shows anything the game hides.

## The frame inspector

Capture one frame in the game: set `fcap=1` in `xikit.ini`, then create `xikit_fcap_now.txt` next to `xikit.dll`.
Then read it with Python 3, numpy, and Windows or Wine:

    python3 tools/fcap/frame_inspect.py list CAPTURE.fcap                  the draws per game function
    python3 tools/fcap/frame_inspect.py at CAPTURE.fcap 120 draw120.png      the picture after the 120th draw
    python3 tools/fcap/frame_inspect.py compare off.fcap on.fcap diff.png   a mod off and on: the pixels that differ

The inspector names a call site's function from `pdb/`. A site in a left-out function is shown by its address.

## What has been run, and what has not

- **This kit as it ships** (no reconstruction, `swap=0`, these manifests and headers): tested offline under Wine on
  builds 6A995428 and 6AE818B4. The test loaded a mod built with this SDK. It checked:
  - a function hook, with the game's code as `previous`;
  - a device hook;
  - a setting, read and then read again after a change;
  - that nothing else in the game is patched.

  Every example and the template compile against these headers, and so does every source file in `sdk/tree_src`.
- **The example mods:** each through the full kit under Wine, with the game's own code where it hooks it (the
  analysis repository's `kit/xikit/test`, modes texmod, fxmod, fx2mod, cammod, ovlmod, audmod, envmod, phomod,
  cfmod, uimod; `src/xikit/test` here): for example the game's own texture creation with a replacement in place, the
  game's own fade pass with the flash limited, the game's own camera build from the free camera's eye, the game's own
  window drawing and hit test with a window moved. Not run in the game.
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
