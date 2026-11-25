# Tutorial: a mod from start to finish

This builds `sdk/examples/status_text.cpp`: the local time over the game's interface, in the game's font, hidden when
the player hides the interface, with a chat command, `/stext`, to switch it and four settings. Each step says why it is done that way.
`SDK.md` is the reference.

## 1. Set up

- A 32-bit MinGW-w64 g++: on Windows, MSYS2's `mingw32` shell (`pacman -S mingw-w64-i686-gcc`); on Linux,
  `i686-w64-mingw32-g++`.
- This repository, and in the game's PlayOnlineViewer folder the kit (`kit/`). Run `devkit_check.exe` once: it says
  whether the kit knows your game's build.

Check the toolchain by building an example that exists:

    sdk/build_mod.sh overlay.dll sdk/examples/overlay.cpp

## 2. Find where to draw

The time should sit over the interface. So the mod draws right after the game draws its interface windows. Search
`docs/` or `sdk/tree_src/` for the interface's drawing: `Menu_DrawLayers` (0x1015F6A0), called once a frame from
`Frame_Render`. Its declaration is in `sdk/tree_include/gfx_free.hpp`:

    XI_API void __thiscall Menu_DrawLayers(void * self_);  // 0x1015F6A0

`xihook::Menu_DrawLayers` in `include/xikit_game.hpp` says that it can be hooked, and with which flags.

Why there, and not in `xikit_mod_frame`: when `xikit_mod_frame` runs, the game has already ended its scene, and the
device's states are whatever the last draw left. Right after `Menu_DrawLayers` the device is in the state the game's
own text uses.

## 3. The hook

```cpp
#include "xikit_sdk.hpp"
#include "xikit_ui.hpp"
#include "status_text_core.h"
XIKIT_MOD_GLOBALS
XIKIT_MOD_INFO("status_text", "1", 4, "the local time over the interface (the SDK tutorial)")

static xikit::fn<decltype(&Menu_DrawLayers)> prev_DrawLayers;
static void __thiscall my_DrawLayers(void *menus) {
  prev_DrawLayers(menus);                          // the game's windows first
  /* draw here */
}
```

- `XIKIT_MOD_GLOBALS` is needed once per mod. The kit fills its variables in so the mod's game addresses are right on
  every build.
- `XIKIT_MOD_INFO` is optional. It puts the mod's name in `xikit.log`. The `4` is the lowest kit API the mod needs:
  this one uses nothing newer than declared settings.
- `prev_DrawLayers` is the game's own function (or, with another mod hooking it too, that mod's hook first: kit API 5
  chains them). Call it, or the game's interface is not drawn.

## 4. Draw with the game's services

`xikit_ui.hpp` has what most interface mods need, each read from the game's code:

```cpp
  if (!g_host->setting_int("st_show", 1) || xiui::interface_hidden()) return;
  char s[32]; st_clock(s, sizeof s, g_host->setting_int("st_seconds", 0));
  float ux = xiui::unit_x(), uy = xiui::unit_y(), w = xiui::text_width(s);
  int x = g_host->setting_int("st_x", -8), y = g_host->setting_int("st_y", 4);
  float px = x < 0 ? (640 + x) * ux - w : x * ux, py = y < 0 ? (480 + y) * uy - 16 : y * uy;
  xiui::text(px, py, s);
```

- The game lays out its interface in 640x480 units. `unit_x()` and `unit_y()` turn them into pixels, so the text is
  where the setting says at any resolution.
- `interface_hidden()` follows the game's own rule, so the time hides with the rest of the interface.
- `xiui::text` draws with the game's font. It sets the blend states but not the colour operation. This mod draws
  nothing else, so it leaves the game's states as they are. A mod that also draws its own quads puts the game's states
  back first (`hotbar.cpp` shows how).

## 5. System calls go in a file of their own

`st_clock` lives in `status_text_core.cpp`. The game's headers declare their own Windows and C
runtime types (`DWORD`, `struct tm`, ...), because they describe the game as it was compiled. So `<windows.h>` and
`<time.h>` cannot be included in the same file as them. Put such code in another `.cpp`, with a small header of plain
types between the two, and build both:

    sdk/build_mod.sh status_text.dll sdk/examples/status_text.cpp sdk/examples/status_text_core.cpp

## 6. A chat command, not a key

```cpp
#include "xikit_cmd.hpp"

static void command(const char *args) {           // "/stext ..." typed in the chat line
  if (!strcmp(args, "show")) g_host->set_int("st_show", 1);
  else if (!strcmp(args, "hide")) g_host->set_int("st_show", 0);
  else if (!strcmp(args, "seconds")) g_host->set_int("st_seconds", !g_host->setting_int("st_seconds", 0));
  else g_host->set_int("st_show", !g_host->setting_int("st_show", 1));
}
```

- Why a command and not a key: a key can clash with the game's own keys or another mod's, and the player cannot see
  which are taken. A command is typed in the chat line, works from the game's macros, and clashes with nothing.
- `xikit_cmd.hpp` hooks the game's `Command_RunLine`. A line whose first word is the mod's (`/stext`, any case)
  reaches the handler and not the game; every other line goes on to the game unchanged.
- Choose a word the game does not have. Its own commands are `/word` strings in FFXiMain.dll:
  `strings FFXiMain.dll | grep '^/'` lists them, and `/stext` is not among them.
- `set_int` writes the setting to `xikit_mods.ini`, where the player can change it too. The kit reads the file back
  within 30 frames, so the change shows half a second later at most.

## 7. Settings, and init

```cpp
extern "C" __declspec(dllexport) int xikit_mod_init(const XikitHost *host) {
  g_host = host;
  host->declare_int("st_show", 1, 0, 1, "1: show the time (/stext switches it)");
  host->declare_int("st_x", -8, -640, 640, "where, across, in 640-wide interface units; negative: from the right edge");
  host->declare_int("st_y", 4, -480, 480, "where, down, in 480-high units; negative: from the bottom");
  host->declare_int("st_seconds", 0, 0, 1, "1: with seconds");
  xicmd::add("stext", command);
  if (xicmd::install(host) != XIKIT_OK) host->log("status_text: Command_RunLine not hooked: no /stext (st_show in xikit_mods.ini still works)");
  return XI_HOOK(host, Menu_DrawLayers, my_DrawLayers, prev_DrawLayers);
}
```

- `xicmd::add` names the command and `xicmd::install` hooks the game's command line. If another mod hooks it too, kit
  API 5 chains the two, and each takes only its own words.
- Declared settings appear in `xikit_mods.ini` under `[status_text]`, with their help in `xikit_settings.txt`. A change
  to the file applies while the game runs.
- `XI_HOOK` does not compile if `my_DrawLayers`'s type differs from the declaration. If the hook is refused at run
  time, `xikit.log` says why.

## 8. Run it

1. Copy `status_text.dll` next to `xikit.dll`.
2. Add it to `xikit.ini`: `mods=status_text.dll`. Separate several mods with commas.
3. Start the game and look in `xikit.log` for these lines:
   - `mod status_text.dll: status_text 1 (kit API 4 or later): ...`
   - `hooked Menu_DrawLayers (0x1015F6A0)...`, followed by what its `previous` is
4. In the game, type `/stext` in the chat line: the time hides. Type it again to show it, or `/stext seconds`.

To work faster, set `mod_reload=1` in `xikit.ini`. Rebuild while the game runs, and the kit loads the new build once the
file has stopped changing. It checks every 30 frames (`SDK.md`, "Reloading").

## Where next

- Hook the device itself: `SDK.md`, "Device hooks".
- Draw between the world and the interface, or with shaders: `scene_tint.cpp`, `scene_shader.cpp`, `depth_view.cpp`.
- Take clicks from the game over your own window: `hotbar.cpp`, and `SDK.md`, "Input".
- What the kit promises between versions: `COMPATIBILITY.md`.
