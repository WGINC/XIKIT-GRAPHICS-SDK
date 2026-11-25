# SDK API reference

Made by `sdk/api_reference.py` from the headers' own comments; the headers are the source.

## The kit-mod interface (C) (`include/xikit_mod.h`)

xikit_mod.h -- the interface between xikit.dll and a mod DLL (docs/SDK.md). C, so a mod may be C or C++.

- `#define XIKIT_MOD_H`
- `#define XIKIT_API_VERSION 5`: 2: device_hook; 3: hook_keeping_registers; 4: declared settings; 5: hook chains
- `#define XIKIT_OK 0`: hook() results
- `#define XIKIT_E_UNKNOWN -1`: no function of that name / address in the manifest
- `#define XIKIT_E_TAKEN -2`: this mod hooks it already, or 8 mods do (API 5: other mods chain; before 5, any other mod)
- `#define XIKIT_E_REFUSED -3`: the live entry is not the analysed build's, or speedfix_hook patches it
- `#define XIKIT_E_LATE -4`: hook() called outside xikit_mod_init
- `#define XIKIT_E_NOPREV -5`: no way to reach the previous code (no trampoline and no reconstruction export)
- `#define XIKIT_E_OLDKIT -6`: the kit is older than the call (host->size does not reach the field)
- `typedef struct XikitHost`
- `uint32_t version;`: XIKIT_API_VERSION of the kit
- `uint32_t size;`: sizeof(XikitHost) as the kit knows it; fields are only ever added at the end
- `uintptr_t game_base;`: where FFXiMain.dll is loaded
- `intptr_t rel;`: game_base - 0x10000000: add it to an analysed address (the tree's XI_GAME does)
- `void *device;`: the game's IDirect3DDevice8
- `void *recon;`: gfx_recon_ingame.dll (HMODULE)
- `const char *dir;`: the folder of xikit.dll and the mods, no trailing backslash
- `void (__cdecl *log)(const char *fmt, ...);`: a line in xikit.log, prefixed with the mod's name
- `int (__cdecl *hook)(const char *function, void *replacement, void **previous);`: Replace a manifest function (its name as xikit_manifest.txt gives it, e.g. "CDx::DrawFadeQuad", its export symbol, or its analysed address as "0x1000A820"). *previous (may be NULL) receives code that runs the game's own function: a trampoline of its first instructions where the manifest has one (T=), else the reconstruction's export of it. Returns XIKIT_OK or an XIKIT_E_ code (also logged).
- `void *(__cdecl *reconstruction)(const char *function);`: the reconstruction's export of a manifest function (gate-verified C++ of the same function), or NULL
- `int (__cdecl *device_hook)(const char *method, int slot, void *replacement, void **previous);`: --- version 2 --- Intercept a method of the game's IDirect3DDevice8: `method` is its name in the DirectX 8 SDK's d3d8.h and `slot` its index in the vtable (the order of d3d8.h; xikit_sdk.hpp's XI_DEVICE_HOOK computes both from the tree's xi_d3d8.hpp). The kit refuses the hook when the two disagree with its own table. The replacement is __stdcall with the device first, as the vtable entry; *previous receives code that goes on to the next layer (another mod's hook of the same method, then the kit's profiler, then Direct3D). Several mods may hook one method; the one hooked last runs first. Only in xikit_mod_init. Calls the game makes from other threads run the hook too.
- `int (__cdecl *hook_keeping_registers)(const char *function, void *replacement, void **previous);`: --- version 3 --- hook(), also for a function of manifest flag 8 (the game's code reads or hands back a register its declaration does not carry, e.g. bytes of its entry EAX that callers read), which hook() refuses. The mod states that its replacement leaves every register as the game's code would, typically by calling *previous and keeping what it leaves. So *previous is always the game's own code here: without a trampoline the call is refused (XIKIT_E_NOPREV), never answered with the reconstruction. Only in xikit_mod_init.
- `int (__cdecl *declare_int)(const char *key, int def, int lo, int hi, const char *help);`: --- version 4: settings (docs/SDK.md, "Settings") --- Declare an integer setting of this mod (only in xikit_mod_init): `key` in the section named after the mod's file without .dll in xikit_mods.ini (next to xikit.dll); its value now (def when the file has none, else clamped to lo..hi; a key the file lacks is written there with def, to be edited). help goes into xikit_settings.txt, the kit's list of every declared setting. When the file changes the kit reads it again (every 30 frames) and calls the mod's xikit_mod_settings export, if it has one.
- `int (__cdecl *setting_int)(const char *key, int def);`: a declared setting's current value (def for a key this mod did not declare); any thread
- `int (__cdecl *set_int)(const char *key, int value);`: write a declared setting's value to xikit_mods.ini (what an in-game command would do): 1 written, 0 not declared or out of range; the new value is read, and xikit_mod_settings called, at the kit's next check
- `#define XIKIT_EXTERN_C_ extern "C"`
- `#define XIKIT_EXTERN_C_`
- `#define XIKIT_MOD_GLOBALS XIKIT_EXTERN_C_ uintptr_t xi_rel = 0; XIKIT_EXTERN_C_ int32_t xi_shift[1 + 3 * 64] = {0}; \`: (clang refuses dllexport on a definition whose earlier declaration, the tree's `extern "C" uintptr_t xi_rel;`, had none: the three are exported by a linker directive instead)
- `#define XIKIT_MOD_GLOBALS XIKIT_EXTERN_C_ __declspec(dllexport) uintptr_t xi_rel = 0; \`
- `XIKIT_EXTERN_C_ __declspec(dllexport) int32_t xi_shift[1 + 3 * 64] =`
- `#define XIKIT_ABI_ASSERT(c, m) static_assert(c, m)`
- `#define XIKIT_ABI_ASSERT(c, m) _Static_assert(c, m)`
- `typedef int (__cdecl *xikit_mod_init_fn)(const XikitHost *host);`
- `typedef void (__cdecl *xikit_mod_frame_fn)(void *device);`
- `typedef void (__cdecl *xikit_mod_unload_fn)(void);`
- `typedef void (__cdecl *xikit_mod_settings_fn)(void);`
- `typedef struct XikitModInfo`: Optional (kit API 5): what the mod is and the kit API it needs. XIKIT_MOD_INFO("name", "1.2", 5, "what it does"), once at file scope. The kit logs it, and does not start a mod that needs a newer API than its own: the mod would otherwise find a field missing or a call answered XIKIT_E_OLDKIT later. A mod without it is started as before.
- `uint32_t size;`: sizeof(XikitModInfo); fields are only ever added at the end
- `uint32_t api;`: the lowest XIKIT_API_VERSION the mod works with
- `const char *name, *version, *about;`
- `#define XIKIT_MOD_INFO(name_, version_, api_, about_) XIKIT_EXTERN_C_ const XikitModInfo xikit_mod_info = { sizeof(XikitModInfo), (api_), (name_), (version_), (about_) }; \`
- `#define XIKIT_MOD_INFO(name_, version_, api_, about_) XIKIT_EXTERN_C_ __declspec(dllexport) const XikitModInfo xikit_mod_info = { sizeof(XikitModInfo), (api_), (name_), (version_), (about_) };`

## C++ helpers (`include/xikit_sdk.hpp`)

xikit_sdk.hpp -- the one header a C++ mod includes (docs/SDK.md). #include "xikit_sdk.hpp" XIKIT_MOD_GLOBALS                       // in exactly one source file of the mod static xikit::fn<decltype(&CDx::DrawFadeQuad)> prev_fade;            // the game's own function static int __thiscall my_fade(CDx *self, int a1, int a2) { ...; return prev_fade(self, a1, a2); } extern "C" __declspec(dllexport) int xikit_mod_init(const XikitHost *host) { return XI_HOOK(host, CDx::DrawFadeQuad, my_fade, prev_fade);        // 0 = hooked } XI_HOOK checks at compile time that the replacement has the type of the tree's declaration of the function (calling convention, `this`, parameters, return), which is the declaration the gate verified the reconstruction with. Everything the tree declares is visible: its classes with field offsets (static_assert-checked), free functions, orig:: (the game's own code by address), the game's globals (gfx_globals.hpp), Direct3D 8 (xi_d3d8.hpp), and xigame::Name() (a typed pointer to any reconstructed function's game entry). Device hooks (kit API 2): XI_DEVICE_HOOK(host, SetRenderState, my_SetRenderState, prev) intercepts a method of the game's IDirect3DDevice8; the replacement has the vtable entry's type, XI_DEVICE_FN(SetRenderState), i.e. static XI_DEVICE_FN(SetRenderState) prev; static int __stdcall my_SetRenderState(IDirect3DDevice8 *dev, D3DRENDERSTATETYPE s, unsigned v) { ...; return prev(dev, s, v); } Forks (sdk/fork.py): XI_FORK(host, Class::Method) hooks the function with the mod's own definition of it.

- `#define XI_INGAME 1 // game addresses rebased by xi_rel (tree/include/xi_decomp.hpp)`
- `template <class F, class R> inline int hook(const XikitHost *host, const char *name, R replacement, F *previous)`
- `template <class F, class R> inline int device_hook(const XikitHost *host, const char *method, int slot, R replacement, F *previous)`
- `template <class P> inline void *code_of(P p)`: the code address of a function the mod defines (a fork): a free or static function's pointer, or a non-virtual member function's. A pointer to member function is {address, this adjustment} in the Itanium C++ ABI that MinGW's g++ follows, the address odd for a virtual one (then a vtable offset + 1, not code): refused, as is an adjustment
- `template <class T = void> inline T *game(uint32_t analysed)`: an analysed address (as IDA / the tree show it, base 0x10000000) where the game is loaded now
- `#define XI_HOOK(host, function, replacement, previous) \`: Hook `function` (as the tree names it: Class::Method or FreeFunction) with `replacement`; `previous` (a variable of type xikit::fn<decltype(&function)>) receives the code that runs the game's own function. Call it from xikit_mod_init only. Evaluates to XIKIT_OK (0) or an XIKIT_E_ code (xikit_mod.h; the kit logs why).
- `#define XI_DEVICE_FN(method) decltype(IDirect3DDevice8Vtbl::method)`: the type of an IDirect3DDevice8 vtable entry, as the tree's xi_d3d8.hpp declares it (the order of d3d8.h)
- `#define XI_DEVICE_HOOK(host, method, replacement, previous) \`: Hook a device method; `previous` (of type XI_DEVICE_FN(method)) receives what goes on to the next layer. The slot is the entry's place in the vtable; the kit checks it against its own table of d3d8.h's names.
- `#define XI_FORK(host, function) \`: Hook `function` with the mod's own definition of it: a fork (sdk/fork.py) compiled into the mod. Its previous is not kept: a fork is the whole function. Evaluates to XIKIT_OK or an XIKIT_E_ code.

## Game services (`include/xikit_ui.hpp`)

xikit_ui.hpp -- the game services the mods kept finding for themselves, in one place: the game's window, its screen units, whether the interface is hidden, whether the chat line takes typed keys, the cursor, running a command line, and drawing and measuring text in the game's own font. Header only; include it after xikit_sdk.hpp. Every fact is from the game's code, build 6A995428, with the function it was read from. The addresses go through XI_GAME / xikit::game, so build translation applies (6AC37846 and 6AE818B4: the functions below are matched by the kit's build maps; hotbar and click_target, which first read them, are tested on 6A995428 and 6AE818B4). Call these on the render thread (xikit_mod_frame, or a hook of the game's drawing), as the game does.

- `inline void *window()`: The game's main window: the application object [0x103D3C64] +0x18 (the window procedure 0x100016C0's owner; hotbar.cpp). NULL before the game has made it.
- `inline float unit_x()`: The interface's units. The game lays out its menus in 640x480 units and scales them by the screen rectangle's right/bottom over 640 and 480 (the menu manager's +0x80/+0x82 at [0x106218B8]; TargetMenu_GetScaledPos80). unit_x() * 640 is the drawn width in pixels. 1 when the rectangle is not set yet.
- `inline float unit_y()`
- `inline bool render_target_size(float *w, float *h)`: The size of the render target being drawn, in pixels: CDx::GetRenderTargetTop (0x10009E00, this = g_pCDx [0x1045666C]) returns the record whose +8 and +12 are its width and height (click_target.cpp, which maps the game's nameplate glyphs back to the screen with it). False before the device wrapper exists.
- `inline bool interface_hidden()`: The interface hidden by the player: Menu_DrawLayers draws a window only while Menu_IsStateB4Eq1 is false (the menu manager [0x10621838]'s byte +0xB4 is not 1) or the window has flag 0x40.
- `inline const char *chat_line_text()`: The chat line's text. [0x10578490] is the chat line's buffer: Input_HandleChar (tree/src/InputDevices.cpp) writes each typed character into its text at +0x14 (at the cursor, +0x114) and on Enter runs that text through Command_RunLine (InputDevices.cpp:304). NULL before the buffer exists. Not known: whether the chat line is open. (An earlier SDK offered chat_takes_keys(), [0x10578490] and [0x1062193C] both non-zero; read again on 24 Nov, both are objects that exist the whole time once logged in: the buffer above and a menu window. The owner's game showed it true throughout. It was removed.)
- `inline uint32_t chat_line_stamp()`: A fingerprint of the chat line's text and cursor: a key press that typed a character into the chat line changes it. A mod that acts on a key takes the stamp when the key goes down, waits a few frames, and acts only if the stamp is unchanged (sdk/examples/hotbar.cpp). 0 before the buffer exists.
- `inline bool cursor(int *x, int *y)`: The game's cursor, g_pCursor ([0x104E1D4C]) +4 and +8, in pixels of the drawn interface (the same units as unit_x() * 640). False before the cursor object exists.
- `inline int run_line(const char *text)`: Run one line through the game's command line, as typing it and pressing Enter does: Command_RunLine (0x10080DC0, cdecl: line, mode), which the chat line's Enter calls with mode 0 (Input_HandleChar). The game's code may write into the line, so it is copied first; at most 199 characters. Returns what Command_RunLine returns.
- `inline void text(float x, float y, const char *s, unsigned color = 0x80808080u, float scale = 1.0f)`: Text in the game's font: FontGlyphs::FontGlyphs_DrawString (0x1011C080, this = [0x104E1B90]) with flags 0x44, as the game's wrapper 0x10129F00 calls it (125 calls). Colours as Menu_DrawWindowItems: 0x80808080 normal, 0x80805020 focused (0x80 is full intensity: the game's text stage is MODULATE2X). x, y in pixels; scale 1 is the game's size. It sets ALPHAOP and the blend states but not COLOROP: a mod that changed the texture stages puts the game's states back first (hotbar.cpp, HISTORY 81). Draws nothing before the font object exists.
- `inline float text_width(const char *s)`: The width of s in pixels at the game's size: Font_MeasureText (0x1011CF70, cdecl: text, 0). Before the font object exists, 8 pixels a character (an estimate, said as one).

## Game state and watchers (`include/xikit_state.hpp`)

xikit_state.hpp -- what a mod may read of the game's state, and watchers that report when it changes. Header only; include it after xikit_sdk.hpp. Call everything on the render thread. Every read is from the game's code (build 6A995428, the reconstruction's source under the SDK's tree_src), and names the function and line it rests on. Addresses go through XI_GAME / xikit::game, so build translation applies. What a mod might want and the code read so far does not show is listed at the end, not guessed.

- `inline void *target_manager()`: The target manager: g_pTargetMng ([0x1057876C]). The game calls Target_Update on it each frame from Frame_Render (FrameRender.cpp, `if (g_pTargetMng != nullptr) Target_Update(g_pTargetMng)`). NULL before the game has made it.
- `inline void *target_actor()`: The current target's actor, or NULL: Target_GetCachedIfValid (0x101598A0) on the target manager, as the target menu reads it (TargetMenu.cpp: `iVar5 = Target_GetCachedIfValid(g_pTargetMng); if (iVar5 == 0) ... return`). The same function's result is compared with the actor ActorHandle_Resolve gives for g_targetActorHandle (TargetMenu.cpp, `uVar5 = ActorHandle_Resolve(&g_targetActorHandle); iVar3 = Target_GetCachedIfValid(self_); ... if (uVar5 == iVar3)`), so it is an actor pointer.
- `inline void actor_name(void *actor, char *out, size_t n)`: An actor's name, as the game draws it: CXiActor::GetName (0x10082F60, CXiActor.cpp) copies it into one buffer of the game's ([0x1047D4F8]) and returns that buffer. The next call overwrites it, so copy the name out at once. Writes an empty string for a NULL actor.
- `template <class T> struct Watch`: ---- watchers: call poll() once a frame (xikit_mod_frame); it returns true on the frame the value changed. The first poll() reports the value as a change, so a mod's starting state follows the game's.
- `struct TargetWatch : Watch<void *>`: The target changed (another actor, or none). value is the target's actor pointer.
- `struct InterfaceWatch : Watch<bool>`: The player hid or showed the interface (xiui::interface_hidden). value is true while hidden.

## Shader passes (d3d8on11) (`include/xikit_render.h`)

xikit_render.h -- shader passes through d3d8on11 (docs/SDK.md, "Shader passes"; docs/DEVKIT.md D3b, D3c).

- `struct IDirect3DTexture8; struct IDirect3DSurface8;`
- `typedef unsigned (__stdcall *xikit_pass_shader_fn)(const char *hlsl, unsigned bytes);`
- `typedef int (__stdcall *xikit_pass_fn)(unsigned shader, struct IDirect3DTexture8 *src, struct IDirect3DSurface8 *dst, const float *c, unsigned n);`
- `typedef int (__stdcall *xikit_pass_depth_fn)(unsigned shader, struct IDirect3DTexture8 *src, struct IDirect3DSurface8 *depth,`
- `struct IDirect3DSurface8 *dst, const float *c, unsigned n);`
- `typedef struct`
- `static inline int xikit_render_load(XikitRender *r)`: 1 when the d3d8.dll in the process is d3d8on11 with shader passes (PassDepth may still be NULL on an older one)

## Dear ImGui in the game: renderer and input (`xiimgui/xiimgui.h`)

xiimgui.h -- Dear ImGui (sdk/imgui, v1.91.5) inside the game, for mods: a Direct3D 8 renderer and the input it needs. Plain C types only, so a mod's file that includes the game's headers (xikit_sdk.hpp) can include this too; the ImGui calls themselves (ImGui::Begin, ...) go in a file of the mod's own that includes "imgui.h" and not the game's headers (sdk/examples/imgui_panel.cpp and imgui_panel_ui.cpp show the split). Call everything on the render thread.

- `int xiimgui_init(void *device, void *window);`: Once, when the device is known (the device the game draws with, IDirect3DDevice8*; and the game's window, HWND). Makes the ImGui context and the font texture. Returns 0 on success. Calling it again with another device (the game made a new one) frees the old objects and starts over.
- `void xiimgui_new_frame(float width, float height, int have_cursor, int cursor_x, int cursor_y, int window_has_focus);`: Each frame, before the mod's ImGui calls: the drawn size in pixels (xiui::render_target_size), the cursor in the same pixels (xiui::cursor; have_cursor 0 when the game has none), and whether the game's window has the keyboard. The left, right and middle buttons are read here (GetAsyncKeyState) while the window has the keyboard.
- `void xiimgui_render(void);`: After the mod's ImGui calls: draws them. The device's states, its vertex shader, stage 0's texture, the transforms and the viewport are as they were afterwards (a state block of all states, plus the ones it does not hold).
- `int xiimgui_window_focused(void *window);`: What ImGui wants this frame (set by xiimgui_new_frame and the mod's calls): the mouse over an ImGui window (keep the click from the game), keyboard input for a text field. The game's window has the keyboard (GetForegroundWindow), for xiimgui_new_frame's last argument.
- `int xiimgui_wants_mouse(void);`
- `int xiimgui_wants_keyboard(void);`
- `int xiimgui_window_message(void *window, unsigned msg, uintptr_t wparam, intptr_t lparam);`: Typed characters and the mouse wheel come as window messages. xiimgui_window_message passes them on; a mod that subclasses the window (xiimgui_hook_window) has this done for it. Returns 1 when ImGui used the message and the game should not see it (only while xiimgui_wants_keyboard, for key and character messages).
- `int xiimgui_hook_window(void *window);`: Subclass the game's window so that the messages above reach ImGui (SetWindowLongPtrW, chained with CallWindowProcW to what was there). xiimgui_unhook_window puts the previous procedure back if it is still the one this set; if another tool subclassed the window since, this one stays in that chain and only passes messages on, so the mod's DLL must then not be unloaded (a mod using the window hook should not be reloaded with mod_reload).
- `void xiimgui_unhook_window(void);`
- `void xiimgui_shutdown(void);`: Free everything (xikit_mod_unload).

## Dear ImGui in the game: the hooks (`xiimgui/xiimgui_game.h`)

xiimgui_game.h -- Dear ImGui in the game the easy way (xiimgui_game.cpp): the kit's hooks for drawing over the interface and for keeping clicks on an ImGui window from the game, around a draw function of the mod's own. Plain C types; include it from the mod's file that has xikit_mod_init.

- `typedef void (*xiimgui_draw_fn)(void);`: The mod's ImGui calls for one frame (ImGui::Begin ... ImGui::End), in a file that includes "imgui.h".
- `int xiimgui_game_install(const XikitHost *host, xiimgui_draw_fn draw, int window_messages);`: Call once from xikit_mod_init. Hooks Menu_DrawLayers (draws after the game's interface windows), Cursor_EnterMode1 and Cursor_ToggleFlag1 (the left button, kept from the game while the cursor is over an ImGui window) and Target_PickNearestToPoint (no world pick under an ImGui window). With kit API 5 these chain with other mods' hooks of the same functions (hotbar's, for one). window_messages 1 also subclasses the game's window for typed characters, keys and the wheel (xiimgui.h, xiimgui_hook_window). Returns XIKIT_OK or the first hook's error.
- `void xiimgui_game_show(int on);`: 0: draw nothing and take no clicks (the mod's own on/off); 1: as installed. While the player hides the interface, nothing is drawn either (xiui::interface_hidden).
- `long xiimgui_game_frames(void);`: Frames drawn so far, and whether the last frame's ImGui windows had the cursor (for a mod's tests).
- `int xiimgui_game_had_mouse(void);`
- `void xiimgui_game_clicks(long *kept, long *passed);`: Left presses kept from the game (over an ImGui window) and passed on to it, so far.
- `void xiimgui_game_force_focus(int on);`: Tests only: treat the game's window as having the keyboard (a test host has no game window).
- `void xiimgui_game_unload(void);`: xikit_mod_unload: the ImGui objects freed and the window procedure put back.
