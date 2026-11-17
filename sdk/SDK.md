# XIKIT SDK: writing mods (the public kit)

A mod is a 32-bit DLL that xikit loads into the game. It can:

- **replace** any of the functions in the kit's manifest (4,602, the same on build 6AC37846; 4,532 on 6AE818B4) and
  **call the game's own version** of the function it replaced;
- **intercept the Direct3D 8 device's methods**;
- read and write the game's objects through the class layouts in `tree_include/`;
- **draw every frame** with the game's device;
- with d3d8on11, **run its own HLSL pixel shaders and read depth**;
- **declare settings** that apply while the game runs.

With `mod_reload=1`, a rebuilt mod is loaded again while the game runs.

This kit holds the game's code except its network, its encryption and its packets (`README.md`, "What this kit
covers"). What it says about a function comes from the reconstruction checked against the game's code: its
declaration (`tree_include/`) and its body (`tree_src/`, 4,635 functions). Read the body before you change a function.
`seams.json` gives each function's depth: the fewest direct calls from it to one with a Direct3D call site proven in
the game (0: it has one). The graphics system is the functions with a depth.

The kit does not swap reconstructed code into the game. Every hook's `previous` is the game's own code.

## What you need

- **MinGW-w64, 32-bit (i686) g++.** On Windows, use MSYS2's `mingw32` shell (`pacman -S mingw-w64-i686-gcc`) or a
  WinLibs i686 build. On Linux, use `i686-w64-mingw32-g++`. MSVC cannot compile the headers, because they use GCC
  attributes. clang can, with its `i686-w64-mingw32` target (llvm-mingw on Windows): `XIKIT_PDB=1 build_mod.sh ...`
  builds with it and writes the mod's `.pdb` for Visual Studio's debugger and WinDbg.
- **The kit** (`kit/`: `xikit.dll`, the manifests, `xikit.ini`) in the PlayOnlineViewer folder. Add **d3d8on11**
  (`d3d8on11/`) for shader passes and depth.
- **This SDK** (`sdk/`):

| Folder | What |
|---|---|
| `include/xikit_sdk.hpp` | The one header a mod includes: `XI_HOOK`, `XI_DEVICE_HOOK`, `xikit::fn`, `xikit::game`, `XIKIT_MOD_GLOBALS` |
| `include/xikit_mod.h` | The kit–mod interface in C: `XikitHost`, the exports a mod has, the result codes |
| `include/xikit_render.h` | Shader passes and depth reads through d3d8on11 |
| `include/xikit_game.hpp` | Includes the headers below, and adds two things: `xigame::Name()`, a typed pointer to each function's game entry; and `xihook::Name`, the manifest flags of each hookable function |
| `tree_include/` | The headers of the functions and their classes, whose field offsets are checked by `static_assert`. Also `orig::` (game code by address), the globals the source uses, and Direct3D 8 |
| `tree_src/` | The reconstructed source, one place to read what each function does (files named for what they hold) |
| `template/` | A starting point, with Visual Studio / VS Code projects |
| `examples/` | `overlay.cpp` (a pass-through hook plus a box drawn every frame), `scene_tint.cpp`, `scene_shader.cpp`, `depth_view.cpp` |
| `build_mod.sh`, `build_mod.bat` | Build a mod |
| `symbols/` | `FFXiMain.pdb` and its symbol list for each build (the same as `../pdb/`) |
| `seams.json` | Each function's depth (its distance from the Direct3D device by direct calls) and unit |

## A mod in five steps

1. **Pick the function.** `xihook::` in `include/xikit_game.hpp` lists the ones a mod may hook, with their manifest
   flags. Find its declaration in `tree_include/`. Find its body in `tree_src/` by its name or its address: every
   body starts with `// FUNCTION: FFXIMAIN 0x...`.
2. **Write the replacement** with the same signature. A member function becomes a `__thiscall` function that takes
   the object first:

   ```cpp
   #include "xikit_sdk.hpp"
   XIKIT_MOD_GLOBALS                                   // once per mod

   static xikit::fn<decltype(&CDx::DrawFadeQuad)> prev_DrawFadeQuad;   // the game's own function
   static int __thiscall my_DrawFadeQuad(CDx *self, int a1, int a2) {
     /* before */
     int r = prev_DrawFadeQuad(self, a1, a2);         // leave this out to replace the function outright
     /* after */
     return r;
   }
   ```
3. **Hook it** in `xikit_mod_init`. Hooks can only be made there:

   ```cpp
   extern "C" __declspec(dllexport) int xikit_mod_init(const XikitHost *host) {
     return XI_HOOK(host, CDx::DrawFadeQuad, my_DrawFadeQuad, prev_DrawFadeQuad);   // 0 = hooked
   }
   ```
   `XI_HOOK` fails to compile when the replacement's type differs from the declaration's. That includes the calling
   convention, `this`, the parameters and the return type.
4. **Build** with `build_mod.sh my_mod.dll my_mod.cpp` (or `build_mod.bat`).
5. **Install.** Put the DLL next to `xikit.dll` and add it to `xikit.ini` as `mods=my_mod.dll` (comma-separated for
   several). Start the game. `xikit.log` shows each mod's load, every hook it made, and why any hook was refused.

## The interface (`xikit_mod.h`)

A mod exports:

| Export | |
|---|---|
| `int xikit_mod_init(const XikitHost *host)` | Required. Called once, after the game has made its Direct3D device and before the kit's first frame. Return 0. |
| `void xikit_mod_frame(void *device)` | Optional. Called every frame on the render thread, just before Present. The game has already ended its scene by then, so wrap any drawing in `BeginScene`/`EndScene` (see the overlay example). |
| `void xikit_mod_settings(void)` | Optional. Called on the render thread after the kit has read a change to `xikit_mods.ini` |
| `void xikit_mod_unload(void)` | Optional. Called before a reload replaces this build (`mod_reload=1`): release what the mod created (textures, threads). Its hooks are already off. |
| `uintptr_t xi_rel` | Defined by `XIKIT_MOD_GLOBALS`. The kit sets it to the game's load delta before init. The headers' `XI_GAME`, `orig::` and globals rebase through it. |

`XikitHost` gives the mod:

| Field | |
|---|---|
| `version`, `size` | `XIKIT_API_VERSION` (4). Fields are only ever added at the end; a field exists when `size` reaches past it (`XI_DEVICE_HOOK` checks). |
| `game_base`, `rel` | Where `FFXiMain.dll` is loaded; `rel` is `game_base - 0x10000000` |
| `device` | The game's `IDirect3DDevice8` when the mod was loaded. If the game ever makes a new device, the kit hooks that one too, so use the argument of `xikit_mod_frame`, which is always the current one |
| `recon`, `dir` | `recon` is NULL in this kit (there is no reconstruction DLL); `dir` is the kit's folder |
| `log(fmt, ...)` | A line in `xikit.log`, prefixed with the mod's name |
| `hook(name, replacement, &previous)` | What `XI_HOOK` calls. The name is as the manifest gives it (`CDx::DrawFadeQuad`), its export symbol, or `"0x1000A820"`. |
| `reconstruction(name)` | NULL in this kit |
| `device_hook(method, slot, replacement, &previous)` | Version 2. What `XI_DEVICE_HOOK` calls (below) |
| `hook_keeping_registers(name, replacement, &previous)` | Version 3. `hook`, also for a function with manifest flag 8, which `hook` refuses. The mod states that its replacement leaves every register as the game's code would, typically by calling `previous` and keeping what it leaves |
| `declare_int(key, default, lo, hi, help)`, `setting_int(key, default)`, `set_int(key, value)` | Version 4. Settings (below) |

`hook` results:

| Result | Meaning |
|---|---|
| `XIKIT_OK` | Hooked |
| `XIKIT_E_UNKNOWN` | Not in the manifest |
| `XIKIT_E_TAKEN` | Another mod hooks it |
| `XIKIT_E_REFUSED` | Its live entry differs from the analysed build, `speedfix_hook` patches it, or it has a register input (flag 8, below) |
| `XIKIT_E_LATE` | Called outside init |
| `XIKIT_E_NOPREV` | No way to reach its previous code |
| `XIKIT_E_OLDKIT` | The kit predates the call (`device_hook` on a version 1 kit, `hook_keeping_registers` before version 3) |

## What `previous` is

**A trampoline to the game's own code, for every function in these manifests.** The kit copies the first whole
instructions of the function out of the live entry, after checking them against the analysed build. It copies at
least the 5 bytes its `jmp` overwrites and at most 16. It re-aims any `call`/`jmp rel32` among them, and appends a
jump back to the rest of the function.

The manifest's `T=` says, per function, that this is safe. It is decided from the game's code, and it is "no" when:

- one of the first instructions branches relatively or returns;
- the copied bytes pass the end of the function;
- any code in the game jumps into them.

`xihook::Name_TRAMP` says it at compile time.

## Calling other game code

| Call | What it runs |
|---|---|
| `xigame::CDx__SetTexture()(cdx, stage, tex)` | Whatever is at the game's entry: the game's code, or another mod's hook. The type comes from the declaration. |
| `orig::Name(...)` (`tree_include/gfx_orig.hpp`) | The same, for the game functions the source calls. A function of the left-out code is `orig::XI_<CATEGORY>_<address>` (`XI_NETWORK_...`, `XI_PACKET_...`, `XI_CRYPT_...`): its category, address and call signature, nothing else |
| Game globals (`tree_include/gfx_globals.hpp`) and objects | Use the class layouts; `xikit::game<T>(0x1045666C)` turns any analysed address into a pointer |

A member function of a tree class called directly (`cdx->SetTexture(...)`) would run the reconstruction's code, which
this kit does not have: the mod would not link. Call it through `xigame::` instead.

## Device hooks (`XI_DEVICE_HOOK`)

A mod can intercept any method of the game's `IDirect3DDevice8`, without touching the game's functions. Uses include
filtering or batching state, timing calls, and changing what a draw asks for.

```cpp
static XI_DEVICE_FN(SetRenderState) prev_SetRenderState;
static int __stdcall my_SetRenderState(IDirect3DDevice8 *dev, D3DRENDERSTATETYPE s, unsigned v) {
  /* ... */
  return prev_SetRenderState(dev, s, v);           // leave this out to keep the call from the device
}
// in xikit_mod_init:
XI_DEVICE_HOOK(host, SetRenderState, my_SetRenderState, prev_SetRenderState);
```

- **The type comes from `xi_d3d8.hpp`**, a copy of d3d8.h's method order. `XI_DEVICE_FN(method)` is the vtable
  entry's type: `__stdcall`, with the device first. `XI_DEVICE_HOOK` fails to compile when the replacement's type
  differs.
- **The slot is checked twice.** The macro computes it from the entry's place in `IDirect3DDevice8Vtbl`. The kit
  then refuses the hook if that slot is not the method it names in its own table (from d3d8.h).
- **Several mods may hook one method.** The one hooked last runs first. Each one's `previous` goes on to the next,
  then to the kit's profiler, then to Direct3D.
- **Calls from every thread run the hook.** A hook that keeps state must allow for calls from more than one thread.
- **A method no mod hooks costs nothing.** Its entry in the front vtable is the layer below's.

## Between the world and the interface (`CDx::CompositeSceneToBackBuffer`)

`Frame_Render` (0x10011A00) draws the world into the game's own scene texture and runs the post effects on it. It then
calls `CDx::CompositeSceneToBackBuffer` (0x1000C0B0) to copy it to the bound target, before the menus, the cursor and
the text are drawn. Its source (`tree_src/CDx.cpp`) shows what its first argument holds:

- **outside stereo mode,** the texture at `a1 + 4` is drawn as a screen quad;
- **in stereo mode,** the same value goes to the device's vtable +244 (slot 61, `SetTexture`).

So a mod that hooks it sees the finished world picture before it calls `previous`, with nothing of the interface in
it. It can draw into that picture with the Direct3D 8 device (`CDx` +0x0C).

`examples/scene_tint.cpp` does that: one full-screen quad into the texture's level 0, which multiplies the world by a
warm colour. At run time it checks that the value is a texture (`GetType() == D3DRTYPE_TEXTURE`), and it skips stereo
mode using the game's own test. It then puts back the render target, the depth surface and the viewport. Setting a
render target resets the viewport in Direct3D 8, and the game set its own viewport just before the call.

## Shader passes (`xikit_render.h`)

With d3d8on11 as the game's d3d8.dll, a mod can run its own HLSL pixel shader over a texture into a surface.
`xikit_render_load(&r)` finds d3d8on11's exports (`D8ON11_PassShader`, `D8ON11_Pass`, `D8ON11_PassDepth`). Any other
d3d8.dll has none, and it returns 0.

The header states the shader's entry and bindings:

- the entry is `float4 ps(float4 pos : SV_Position, float2 uv : TEXCOORD0)`;
- t0 is the source, as a copy, so the source may also be the destination;
- s0 is LINEAR / CLAMP;
- b0 holds 64 float4 constants;
- with `PassDepth`, t1 is the depth.

Write for ps_4_0: Direct3D 11 compiles ps_4_0 and Direct3D 12 compiles ps_5_0. A pass runs in order with the mod's
other device calls.

- `examples/scene_shader.cpp`: a grade and a vignette over the world picture at `CDx::CompositeSceneToBackBuffer`,
  with two settings.
- `examples/depth_view.cpp`: needs `depth_reads=1` in d3d8on11.ini, which is off by default; with it, every depth
  surface is made readable. The mod records the depth surface the game binds together with the world's target (the
  scene texture's level 0), using a device hook on SetRenderTarget, and shows it in the top-left quarter. In the
  owner's game (build 6AE818B4) that was one depth surface for the whole run, D24S8, the size of the scene.

## Settings (version 4)

A mod declares its integer settings in `xikit_mod_init`:

```cpp
int lvl = host->declare_int("level", 3, 0, 9, "how strong");
```

- **Where the values live:** `xikit_mods.ini` next to xikit.dll, in a section named after the mod's file without
  `.dll` (`[my_mod]`). A key the file lacks is written with its default.
- **The list:** `xikit_settings.txt` has every declared setting, with its value, default, range and help.
- **Changes while the game runs:** the kit reads the file again when it changes (it checks every 30 frames). It then
  calls the mod's `xikit_mod_settings()` export, if the mod has one, on the render thread. The mod reads the new value
  with `setting_int`.
- **Writing a value:** `set_int` writes one, and refuses a value out of range. It is what an in-game command would
  call.

## Reloading (`mod_reload=1`)

With `mod_reload=1` in `xikit.ini` (read at the start), the kit loads each mod from a copy in `xikit_mods_loaded\`.
The build can then write `my_mod.dll` while the game runs.

- **When:** within 60 frames of the build. The kit looks every 30 frames, and loads a changed file only once it is
  unchanged at the next look. Creating `xikit_reload_now.txt` reloads every mod.
- **What happens:** the old build's `xikit_mod_unload` runs and all its function and device hooks are taken off. Then
  the new build's `xikit_mod_init` runs and hooks again. If the new build cannot be loaded, the old one stays.
- **The new build starts with fresh statics.** Nothing carries over except what the mod keeps outside itself.
- **Old builds stay loaded but are never called again.** A thread may still be returning through one. Each reload
  costs one copy of the DLL in memory.
- **Trampolines are built once,** from the untouched entry, so a reloaded hook's `previous` is the same code.

## Limits

- **Only manifest functions can be hooked:** the functions the kit has verified are safe to patch at the entry. The
  network, encryption and packet code is not among them. Other game code can be called (`orig::`, `xigame::`) but
  not replaced.
- **No reconstruction:** with `swap=1` the kit finds no `gfx_recon_ingame.dll` and does nothing at all, mods
  included. Keep `swap=0`.
- **No forks.** `XI_FORK` and `fork.py gate` need the reconstruction DLL, so neither works in this kit. `fork.py new`
  and `fork.py diff` still copy a function's source and compare an edit against it.
- **How much a declaration is worth depends on the gate.** Flag 4 marks incomplete gate coverage, which means less
  evidence behind the declaration: 4,055 functions in the manifest of 6A995428, 3,926 in that of 6AC37846 and 4,018
  in that of 6AE818B4.
- **Register inputs (flag 8).** Flag 8 marks a function whose game code reads a register its declaration does not
  carry. `hook` refuses these, because the replacement could neither see the register nor pass it on.
  `hook_keeping_registers` accepts them. 321 functions in the manifest of 6A995428 have the flag (`xihook::` shows
  each function's flags).
- **A mod's code is not quarantined.** A crash in it is a crash of the game.
- **What is tested.** The public kit was tested under Wine (the analysis repository's `kit/xikit/test/test_public.py`)
  on builds 6A995428 and 6AE818B4. A mod built with this SDK was loaded, and the test checked:
  - its function hook, with a trampoline to the game's own code as `previous`;
  - its device hook, passing on to the device;
  - a setting, read and then read again after a change;
  - that nothing else in the game is patched.

  The examples and the template compile against these headers; their drawing has not been run in this
  configuration.
