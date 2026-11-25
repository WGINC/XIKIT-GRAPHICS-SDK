> Paths in this document are the development repository's: tree/src/ is sdk/tree_src/ here, kit/xikit/ and kit/d3d8on11/ are src/xikit/ and src/d3d8on11/, sdk/examples/ is sdk/examples/; docs/HISTORY.md and kit/sessions/ are not published.

# FFXI's input: keyboard, mouse, pad, chat line, macros

How FFXiMain.dll takes input, read from its code. Addresses are the analysed build's (6A995428); the kit translates
functions to the build in use (6AE818B4) through its manifest; data addresses (tables, globals) are given as read in
6A995428 and must be translated the same way before a mod uses them. Sources: the tree's C (`tree/src/...`, generated
from the game's code and gated against it) and, where the tree has no source, the disassembly of the unpacked
6A995428 DLL (WGINC/ffxi-game-builds; capstone, through `get_memory_mapped_image()`). Each section says which.
**Not known** marks what has not been read; nothing here is inferred from behaviour or from other projects.

Why this document exists (24 Nov run): chat commands never reached any mod, the hotbar's number keys could not be kept
from the game, and the Ctrl macro palette behaved as the owner did not expect. Each of those follows from the parts
below (section 9).

## 1. The parts, in the order a frame runs them

| Part | Where | What it does | Source |
|---|---|---|---|
| Input state object | `g_pAppInputState` (0x10455C20), made by `Input_InitState` (0x10005660) | holds the DirectInput devices and every per-frame buffer below | tree/src/InputDevices.cpp, AppMainLoop.cpp:65 |
| The poll | 0x10005A40 (no name yet; called from FrameRender.cpp:562 every frame, before `Input_DispatchButtons`) | reads the keyboard, the mouse and the pad; fills the key table | disassembly |
| The key table | 0x104E1C40: one byte per DirectInput key code (DIK), byte +0x100 "something changed" | the only keyboard state the rest of the game reads | disassembly (section 3) |
| The action query | 0x10123A70 (tree: `NetCellFont_TestCommand36CF60`) | "is action N's key pressed/held/released?", through the key bindings table | disassembly (section 4) |
| The window procedure | 0x100016C0 | typed characters (WM_CHAR) to the chat line; IME; the mouse in a window | disassembly (section 6) |
| The chat line and `Command_RunLine` | `Input_HandleChar` (0x10007860), `Command_RunLine` (0x10080DC0) | Enter runs the line | tree/src/InputDevices.cpp:217-387 |
| The macro palettes | `TextInputFiles_UpdateMenuState` (0x101A2E80) | Ctrl/Alt palettes and their 20 macros | tree/src/TextInputFiles.cpp:5514 (section 5) |

## 2. DirectInput: the devices

`g_pAppInputState` holds (Input_InitState, the Install functions; tree/src/InputDevices.cpp):

| Offset | What |
|---|---|
| +0x84 | the IDirectInput8 interface |
| +0x88 | the keyboard device (`DirectInput_InstallKeyboard`, 0x10007E20) |
| +0x8C | the mouse device (`DirectInput_InstallMouse`, 0x10007EF0) |
| +0x90 | the joystick device (`DirectInput_InstallJoystick`, 0x100083D0); XInput beside it (`XInput_ProbeDll`, `XInput_LoadFunctions`: XInputGetState, XInputSetState, XInputEnable) |
| +0x98 | 256 bytes: the keyboard's state this frame (GetDeviceState) |
| +0x198 | 256 bytes: the same, remapped for the keyboard layout (see 3) |
| +0x298 | 256 bytes: Windows' `GetKeyboardState` (the import at 0x10329388) |
| +0x398 | 256 dwords: each key's auto-repeat counter |
| +0x79C | 16 buffered keyboard events (DIDEVICEOBJECTDATA, 20 bytes each); +0x8DC their count |
| +0x8F0 | 16 buffered mouse events; +0xA30 their count |
| +0x94 | the auto-repeat threshold: 16 (Input_InitState) |
| +0xA34..+0xA40 | the last absolute mouse state |
| +0xDA8 | the keyboard layout kind, from the IME's name (`InputDevices_JmpGetKeyboardLayout`, 0x10008020: the Japanese IMEs by name, else 0xE) |

The keyboard (InstallKeyboard): `CreateDevice(GUID_SysKeyboard)`, buffer size 0x140 (320 events),
`SetDataFormat(c_dfDIKeyboard)`, `SetCooperativeLevel(window, 0x16)` in full screen and `0x06` in a window:
non-exclusive and foreground always, `DISCL_NOWINKEY` in full screen only. **Non-exclusive: other programs and other
hooks still see every key; the game reads the keyboard's state, it does not take keys away from anyone.**

The mouse (InstallMouse): in a window (`g_windowMode` != 0) or with the hardware mouse option, no DirectInput mouse
(`g_mouseAcquired` = 0, the byte at 0x1034F92C); otherwise `GUID_SysMouse`, `c_dfDIMouse`, relative axes, buffer 320,
cooperative level 6 (non-exclusive, foreground). `Input_SetActive` (0x100087D0) acquires or unacquires on WM_ACTIVATE.

Lost devices: the poll and `DirectInput_PollMouse` (0x100089D0) treat DIERR_INPUTLOST/NOTACQUIRED/OTHERAPPHASPRIO as
"reinstall once (flag 0x10456548 / 0x10456549), else re-acquire", and zero that frame's buffers.

## 3. The poll (0x10005A40) and the key table (0x104E1C40)

Read from the disassembly, in order:

1. The frame's step: `Camera_GetFrameScale` (0x10014CF0, the camera's +0x28), rounded to a whole number of ticks. It is
   the getter speedfix's frame_step forks: under frame_step the auto-repeat below advances by the fork's answer.
2. `GetDeviceState(256, +0x98)` then `GetDeviceData(+0x79C, count +0x8DC = 16)`.
3. For keyboard layouts 2 and 3 (`[0x10456A28]+8`), each key code is remapped through `InputDevices_FindMapValue`
   (tables 0x1034F9D4, 0x1034F9B4) into +0x198; otherwise +0x198 is +0x98.
4. Every key code 0..255: "down" = the remapped state's high bit **or** a buffered press this frame. Then:
   - **down, was not held**: bits 0x04 (held, and +0x100 = 1), 0x02 (pressed), 0x01 (trigger); counter = 0; two
     objects are told (`[0x10662770]` and `[0x10662774]`, slot +0x4C (0, key, 0, 0)): the keyboard configuration's two
     key-binding sets (made by `TextInputFiles_CreateConfigObjects` 0x101A8D60 with 0x1019D150 and 0x1019CE00, vtables
     0x10337090 and 0x10337028); slot +0x4C is 0x1019C800, which stores the key at +0x28 while the object's +8 is set
     (the "press a key to bind it" screen), else 0. While one is set, the movement mask (4) answers nothing;
   - **down, held**: bits 0x01, 0x02, 0x08 cleared; counter += the step; past +0x94 (16): bit 0x01 again (a repeat)
     and counter = 16 - 2.0;
   - **up**: the byte cleared; bit 0x08 (released) if it was held.
5. Enter (0x1C), keypad Enter (0x9C) and Esc (0x01) pressed: `TextInputFiles_HandleKeyDownWithIme(0x0D or 0x1B)`
   (the chat line's editing); on a yes, their edges are cleared.
6. `GetKeyboardState(+0x298)`; for NumLock, LAlt, RAlt, LShift, RShift, LCtrl, RCtrl (VK 0x90, 0xA4, 0xA5, 0xA0,
   0xA1, 0xA2, 0xA3) **bit 0 (Windows' toggle bit, not the down bit)** sets bit 0x10 on DIK 0x45, 0x38, 0xB8, 0x2A,
   0x36, 0x1D, 0x9D. Only NumLock's 0x10 is read anywhere (the plain key query, 4 below: the keypad with NumLock).
7. The mouse (when `g_mouseAcquired`): GetDeviceState, the change since the last state to `Cursor_HandleMouseMove`;
   then `DirectInput_PollMouse` (buffered buttons, dispatched by `Input_DispatchButtons` 0x100088F0 to the cursor's
   modes: buttons 0xC/0xD swapped by the "swap buttons" byte 0x10455C3A, 0xE the third).
8. The pad: the joystick (`Poll`, then `GetDeviceState(0x110, +0xA44)`: DIJOYSTATE2, the DirectInput SDK's layout:
   axes +0xA44..+0xA58, sliders +0xA5C/+0xA60, the POV +0xA64, buttons from +0xA74) or XInput
   (`InputDevices_CallPtr10456550IfEnabled` = XInputGetState, ...58 = XInputEnable), each mapped through the option
   bytes 0x10455C34..0x10455C3E (`Input_MapAxisLow/High` for the dead zones) into the virtual pad (3b).
   **The buttons** (0x1000624C..): for each of the 32 buttons pressed (rgbButtons[i] & 0x80), the 64-bit mask of
   table 0x10455C48 + 8*i is ORed into the pad's +0x220. If a pressed button's mask is exactly 0x4_00000000 (bit 34),
   every button uses the second table, 0x10456048, instead: a layer button. Both tables are uninitialised data,
   filled at start by 0x10005130 and 0x10005320 from the registry values **`padsin000`** and **`padexsin000`**
   (0x10002840; the value names at 0x1034F424 and 0x1034F3D0; beside them `padmode000` and `padguid000`). Each value is
   a list of button numbers separated by spaces or commas; the n-th number is the button for pad bit
   ORDER[n] = 8, 9, 14, 13, 10, 3, 1, 0, 2, 16, 25, 26, 15, 23, 24, 22, 21, 19, 20, 18, 17, 6, 7, 5, 4, 12, 31, 32, 33, 34,
   35, 36 (the table at 0x1034F930), a negative number giving the mask -1 << ... (0x10005209: the bits from it up).
   **The axes and the POV** (0x1000641B..0x10006630): the eight axes and sliders and the POV read, the option bytes
   0x10455C35 (POV), 0x10455C36 (sliders), 0x10455C3B, 0x10455C3C, 0x10455C3E (a word) deciding which; the result into
   the stick bytes +0x250..+0x253 and bits of +0x220. Read line by line in 3c. What each pad bit does in play is
   the action that answers to it (docs/INPUT_ACTIONS.md, its "Pad / mouse" column, from each handler's code); the
   names the game's pad configuration screen shows for them are its data files, not in FFXiMain.dll.
9. The keyboard's movement and camera keys: the second table (4, 0x10123700) ORs their bits into the virtual pad's
   +0x220 and sets its stick bytes (+0x250..+0x253: 0x00 or 0xFF, 0x80 centred) for the four held directions.

### 3b. The virtual pad (`[0x104E1D44]`)

The game drives play from a pad state, as on the PS2: every frame the poll clears it, the joystick or XInput fills it,
and the keyboard's movement keys are added to it as buttons and stick deflections. Fields (every reader and writer
found by scanning the game's code for loads of 0x104E1D44 and these offsets):

| Offset | What | Read by |
|---|---|---|
| +0x220 (64 bits) | buttons held | kind 4 of the handlers below |
| +0x228 (64 bits), +0x22C | pressed this frame | kind 1; kinds 2 and 3 set +0x228 to +0x228 AND the button's bit and +0x22C to 0 |
| +0x230 (64 bits) | released this frame | kind 5 |
| +0x238 (64 bits), +0x23C | trigger (press and repeat) | kind 0 |
| +0x248 | the buttons' auto-repeat timer (3c) | the poll |
| +0x250, +0x251, +0x252, +0x253 | the two sticks' axes, 0x80 centred | 0x10120C70, 0x10120CA0, 0x10120C10, `Cell_GetByte253Scaled`, `StAvatar_UpdateInput` |

The readers are the action handlers of the bindings table (4: 0x1036DB18), one per action: each answers the action's
kind from one bit of these words (e.g. 0x10121000: bit 0x2; its jump table 0x101210D4: kind 0 +0x238, 1 +0x228,
2 and 3 as above, 4 +0x220, 5 +0x230). So an action is "its keys (the key table) or its pad button (the handler)".

The key table's bits (the methods at 0x10123F40-0x10124130, each a one-line read or write of `[0x104E1C40 + key]`):

| Bit | Meaning | Read by |
|---|---|---|
| 0x01 | trigger: the press, and each auto-repeat | 0x101240D0 (test), 0x101240F0 (test and clear) |
| 0x02 | pressed this frame | 0x10124070 (test), 0x10124090 (test and clear) |
| 0x04 | held | 0x10124130 (test; the tree calls it `Cursor_GetFlagBit2`) |
| 0x08 | released this frame | 0x101240B0 |
| 0x10 | the modifier's toggle (6 above) | 0x10124110 |

Only 66 places read the table directly; everything else goes through the queries below.


### 3c. The pad poll, line by line (0x10005A40, 0x1000624C..0x10007787; disassembly)

1. **Buttons.** For each of the 32 DirectInput buttons pressed (`rgbButtons` at +0xA74 of the device's state, bit
   0x80): its 64-bit mask from the table 0x10455C48 (8 bytes a button), or from the layer table 0x10456048 when a
   pressed button's mask is bit 34 (the layer button). The mask is ORed into the held word +0x220. A mask that is
   one of these single bits also drives an axis at full deflection (-127 or +127): bits 4 and 5 (0x10, 0x20) the
   d-pad pair's x (+, -), bits 6 and 7 its y (-, +); bits 17-20 the second stick (x +, x -, y -, y +), bits 21-24
   the first stick (x +, x -, y -, y +).
2. **Axes.** For each entry of the axis table 0x10456448 (8 bytes an entry, to 0x104564A8; uninitialised data,
   filled from the pad configuration), a source -10..10: 1..6 the six axes of DirectInput's DIJOYSTATE (lX, lY, lZ,
   lRx, lRy, lRz: +0xA44..+0xA58, the layout of dinput.h), 7 and 8 the two sliders (+0xA5C, +0xA60) when the byte
   0x10455C36 is set, 9 and 10 the POV (+0xA64) through `Input_MapAxisLow` / `Input_MapAxisHigh` when 0x10455C35 is
   set (a POV angle in 1/100 degree, -1 centred: Low gives +127 for 22.5..157.5, -127 for 202.5..337.5, else 0;
   High gives -127 below 67.5 or above 292.5, +127 for 112.5..247.5, else 0; both 0 when centred or the byte is
   off); a negative source is the same axis negated; 0 none.
   The option byte 0x10455C3B clears the d-pad pair and 0x10455C3C the second stick before the next step.
3. **Stick modes.** If pad bit 25 is held, or the mode word 0x10455C3E is 1, the first stick's values move to the
   d-pad pair (the stick reads 0); if bit 26 is held, or the mode is 2, they move to the second stick. Pad bit 31
   pressed steps the mode 0 -> 1 -> 2 -> 0, skipping mode 1 unless 0x10455C3B is set and mode 2 unless 0x10455C3C is.
4. **Dead zone and shape.** Every value under 42 in magnitude becomes 0. For the first stick, when x^2 + y^2 is over
   9677 (98.4^2), both are multiplied by r^2 / (the larger of x^2, y^2) (a circle pushed out toward the square's
   corners), then each is clamped to +-127 (`v / |v| * 127`).
5. **Stick bytes.** +0x252 = first stick x + 0x80, +0x253 = its y + 0x80, +0x250 = second stick x + 0x80, +0x251 =
   its y + 0x80.
6. **The d-pad pair as buttons.** Its x over 63 sets bit 4 (0x10) held, and pressed and trigger when it was not
   held; under -63 bit 5; its y the same for bits 7 and 6.
7. **Auto-repeat** (+0x248): while some button is held and none released, the timer adds the frame step
   (`Camera_GetFrameScale`); the first frame only arms it (device +0xDAC); once it reaches the device's +0x94 the
   trigger word gets every held button (a repeat) and the timer goes back to that value minus 2.0 (0x10329990), so
   repeats come every 2.0 frame steps; a release resets it to 0.

The range the device's axes are set to: no `DIPROP_RANGE` call was found in the input unit; the code's own
thresholds are 42 (dead zone) and 127 (clamp).

**The mouse** as actions: actions 139, 140 and 150 are the left, right and middle buttons (their handlers read the
cursor object `[0x104E1D4C]` +0x58 held, +0x5C trigger, +0x60 pressed, +0x64 released, bits 0, 1, 2; the window
procedure sets those bits on WM_LBUTTONDOWN, WM_RBUTTONDOWN and WM_MBUTTONDOWN (message - 0x200 = 1, 4, 7) through
`Cursor_EnterMode1/2/4`, and clears the held bit on the button's up message).

## 4. Keys to actions: the bindings

**The plain key query**, 0x10123380 (key, kind); kind 0 trigger, 1 pressed, 2 take trigger, 3 take pressed, 4 held,
5 released (its jump table at 0x10123434). With the chat line in mode 4 or 5 (`TextInputFiles_IsModeFourOrFive`) and
NumLock on, the keypad keys (0x47-0x52) are answered by another table. 0x10123160 is the same behind "Ctrl held"
(LCtrl or RCtrl), 0x10123220 behind "Alt held"; 0x10123120 is "Alt, else Ctrl".

**The action query**, 0x10123A70 (unused, action, kind, binding): 188 table entries (0..0xBB; the query does not bound the action: the size is the
binding table's, which at 3 words per action ends where the handler table starts, 0x1036D6B0 + 6*188 = 0x1036DB18; no
call in the game's code pushes an action above 0xBA; entry 187 (0xBB) has no contexts, no keys and a handler word,
0x00040011, that is not code: the last action in use is 186). Per action:
- a word of contexts at 0x1036CF60 + 2*action, ANDed with the context mask at 0x1036E3A0 (0xFFFF in the file); flags
  0x41 in it mean "not while the chat line is in mode 4 or 5";
- an optional handler pair at 0x1036DB18 + 8*action (pad or mouse equivalents: called first, a yes counts);
- **three key bindings** at 0x1036D6B0 + 2*(3*action + i): low byte the DIK key, high byte its conditions:
  0x01 Shift held, 0x02 Ctrl held, 0x04 Alt held, 0x08 Ctrl and Alt held, 0x10 Ctrl or Alt held and the byte
  0x1036CF5C set, 0x20 Shift not held, 0x40 not while typing (mode 4/5), 0x80 neither Ctrl nor Alt held. "Typing" is
  the text input's mode word ([0x10662D40]+0xF108) being 4 or 5 (`TextInputFiles_IsModeFourOrFive` 0x101B5C90).
  The mode word's values (25 Nov, tree/src/TextInputFiles.cpp:10616-10856): 1 when `FsTextInput_init` could not
  load the word-completion data (then `TextInputFiles_BeginInput` and `FsTextInput_copyDecidedString` refuse);
  2 after a good init, and from `TextInputFiles_BeginInput` with its first argument 2 (the line cleared, cursor
  reset); 3 from argument 3, and from `TextInputFiles_EndMode4Or5` when the mode was 4; 4 from argument 4 unless
  `TargetMenu_GetByteAE(menuMng, 2)` is set (also sets byte +0x10D of `[0x1066268C]`); 5 from argument 5 (the line
  cleared, the 0x58 slot called, +0x8C80 set). `TextInputFiles_BeginInput` is called only by
  `TextInputFiles_BeginInputWithIme` (0x101B4360), slot +0x28 of the object's own vtable 0x10337A98 (its
  constructor 0x101B8E70, from `App_InitScene`, replaces the base vtable 0x10337A40, where it is slot +0x80). Every
  call through that slot (a scan of the game's functions for 8-argument calls through +0x28): mode 3 from the
  constructor (the start) and from the ByteTable panels' close (0x1019D090, 0x1019D450); mode 2 from their open
  (0x1019CFF0, 0x1019D3B0) and from 0x1023FE20 and 0x102450C0; **mode 4, typing**, from the text input's own key
  handling: `TextInputFiles_HandleKeyDownWithIme` (twice), `TextInputFiles_OnChar`, 0x101B13F0, 0x101B20E0,
  0x101B5760 (twice), each with (4, 0, 5, 0x78, 0, 0, 0, 0xA); mode 5 from 0x101C69C0 (called by 0x101C6870; on
  which object and screen: **not read**). So 3 is the line at rest, 2 the line held while a config panel takes the
  keys, 4 the player typing. `TextInputFiles_EndMode4Or5` returns 4 to 3. Mode 1 is also set by 0x101B5300 (from
  0x101B0040).
  A binding of a modifier key itself (LCtrl, LShift, LAlt) with kind 4 is answered by "either side held".
- the byte 0x104E1C3C = 1 allows only kind 4 (held) for every action: set (`Cell_SetFlag104E1C3C` 0x10123EA0) by the
  menu and target code when one of their steps takes the input (`Target_CycleMenuStep`, `Target_RunActiveCommand`,
  `MenuMng_UpdateForSceneState`, 0x10138230, 0x1015E530, 0x1015E6E0), cleared once a frame by `Frame_Render`;
- the option byte 0x1036CF5C (the 0x10 condition) is 1 in the file and written only by 0x10123EF0 (read only by
  `Cell_GetByte1036CF5C`). It is cleared by 0x1019CFF0 and 0x1019D3B0 and set again by 0x1019D090 and 0x1019D450
  (25 Nov, disassembly): slots of the vtables 0x10337028 and 0x10337090 of the config panels
  `TextInputFiles_ByteTableDefaultCtor` and `TextInputFiles_ByteTableAltCtor` (both made by
  `TextInputFiles_CreateConfigObjects`). The clearing slot opens the panel (cursor, help, a 0x1D/0x1E state); the
  setting slot first stores the panel's 32 bytes as settings 0x6A..0x89 (`SetConfig`). So the 0x10 bindings work
  except while one of those panels is open. Which screen of the game the panels are, and what settings
  0x6A..0x89 hold: **not read**.

**The analog query**, 0x10123970 (unused, action): a float. Per action, a pair of analog handlers at
0x1036D0D8 + 8*action (the table runs from the context table's end to the binding table's start: 187 entries).
With one handler its value; with two, the one of larger magnitude. The forms (each read; per action in
docs/INPUT_ACTIONS.md, "Analog"): a stick byte (0x10120C10 first stick x = (+0x252 - 0x80) / 128, 0x10120C40 its y
+0x253, 0x10120C70 and 0x10120CA0 the second stick +0x250, +0x251); 1.0 while a pad bit is held; +1 / -1 from two
pad bits (0x10120CD0: bit 6 / bit 7; 0x10120D20: bit 4 / bit 5); +1 / -1 from two actions held (0x101230B0: 164 /
165); and the keyboard's or mouse's axis n, 0x10122E30(n): with the cursor in its mode 4 or 5 (cursor +0x4D) the
mouse's movement (`Cursor_GetNormalizedDeltaY` and its siblings), otherwise the key table's value for axis n
(0x10124150), with actions 160 and 161 held giving -1 and +1 for axis 2. Actions 4, 5 are the first stick (movement)
and 6, 7 the second (camera), each with the keyboard/mouse axis as its second handler; 121-124 and 157, 158 the same
sticks in other contexts.

These tables are in `.data`: the game's key configuration rewrites them at run time; the values below are the file's
defaults (6A995428). **The full list of the actions** (contexts, default keys, handler, and every function that
asks for each, with the kind): docs/INPUT_ACTIONS.md, made by `pipeline/input_actions.py`.

| Actions | Default keys | Meaning, where known from the code that asks |
|---|---|---|
| 0-3 | Up, Down, Right, Left | pad bits 6, 7, 4, 5 (the d-pad: the poll's d-pad pair, 3c); as analog, 1.0 while held; asked held (kind 4) by 0x1013A5B0 and `MenuPanels_SetMode`, as trigger (kind 0) by 0x101E5280 |
| 14, 143, 145, 147 | Enter, keypad Enter | pad bit 0, the same action in four contexts (docs/INPUT_ACTIONS.md lists each one's askers) |
| 15, 144, 146, 148, 149 | Esc | pad bit 3; asked by `Acter_UpdateFrame`, `MenuMng_UpdateForSceneState`, `Target_CycleMenuStep`, `StAvatar_UpdateSteer` (held) and others (INPUT_ACTIONS) |
| 70-78, 82 | F1-F10 | targeting: `Target_RunActiveCommand` (0x101585F0) walks the table 0x10371EE0 ({context word, action, kind, command}, 16 bytes each, ended by action -1) with `TargetMenu_FindActiveCommand` and acts on the first action that fires: F1-F6 (70-75, kind 1) commands 6-11, F7 (76) 6, F8 (77) 28, F9 (78) 21, F10 (82) 18; the same table maps actions 176-179 (24-27), 145 (1), 39-42 (2, 2, 3, 4), 83, 84, 132, 151, 146 (13-17), 171, 172 (19, 20), 139 and 140 released (22, 23), 184 (28). What each command number does: `Target_ActOrTrySubSelect` and the code after, **not read** |
| 88-97 | 0-9 with Shift and the 0x10 condition | `TextInputFiles_HandleReadPosKeys` (0x101A3550): each sets `TextInputFiles_SetReadPos([self + 4], 0, 2, 4, ... 18)`; what that position is on screen: **not read** |
| 98-107 | Alt+0..Alt+9 | the Alt macro palette's slots (5) |
| 108-117 | Ctrl+0..Ctrl+9 | the Ctrl macro palette's slots (5) |
| 118 | LCtrl, with Ctrl | "Ctrl held": opens the Ctrl palette (5) |
| 119 | LAlt, with Alt | "Alt held": opens the Alt palette (5) |
| 169, 170 | Q, E | an axis: 0x1025E1E0 returns E - Q (0x1025E170 and 0x1025E100: 1.0 while held, only when the option byte 0x1036CF5C is 1 and analog actions 6 and 7, the second stick, both read 0), used by the camera update 0x1001EE60 (`Camera_SetPosition`) and the player-control code 0x100A6240 |

A second, older table walked by 0x10123700 (from the poll; 16-byte records at 0x1036E0F0, 42 in the file: key,
condition 0 none / 1 Ctrl / 2 Alt / 4 Shift / 8 no Shift / 7 any, focus class 4 always / 6 no menu focused / 5 a menu
focused, then a 64-bit action mask) gives the movement and camera keys held this frame as a bit mask (W 0x800000,
S 0x1000000, A 0x400000, D 0x200000, I/J/K/L by Shift, ...); it also sets the camera bytes `[0x104E1D44]+0x250..+0x253`
for four of the bits. Which bit is which movement (25 Nov, 0x10123870..0x10123939): for a single-bit mask it writes
the stick bytes itself, bit 21 +0x252 = 0xFF, 22 +0x252 = 0, 23 +0x253 = 0, 24 +0x253 = 0xFF, and bits 17-20 the
second stick's +0x250 (0xFF, 0) and +0x251 (0, 0xFF) the same way: the directions the joystick poll gives the same
bits (3c, step 1). So W (0x800000, bit 23) puts the first stick's y at its minimum, S (bit 24) at its maximum, A
(bit 22) x at its minimum, D (bit 21) at its maximum; the first stick is analog actions 4 and 5 (4, the analog
query).

## 5. Macros and the palettes

`TextInputFiles_UpdateMenuState` (0x101A2E80; tree/src/TextInputFiles.cpp:5514) runs each frame:
- Action 137 or 138 pressed (no default keys; pad buttons through their handlers): open or close palette 1 or 2
  (`menu    mcr1pall`, `menu    mcr2pall`).
- **Action 118 (LCtrl) or 119 (LAlt) held**: the first frame stores `ntGameTimeGet()` in +0x10 and sets +0xD to 1
  (Ctrl) or 2 (Alt); **the palette opens only on a later frame whose game time differs** (+0xC = 1 or 2,
  `MenuMng_OpenByName_v2`). A short tap ends before that and no palette is shown. Released: +0xC, +0xD cleared and
  the palettes closed.
- While +0xC or +0xD is 1, `TextInputFiles_ApplyKeyAction` asks actions 108-117 (Ctrl+0..9, kind 1 pressed), and
  while 2, actions 98-107: a press runs `TextInputFiles_SetSlot(1 or 2, slot)` → `TextInputFiles_QueueEntry(slot)`
  with slots 0-9 for Ctrl and 10-19 for Alt (key 0 is slot 9). **A macro runs on the press whether or not the
  palette has opened yet.**
- `TextInputFiles_CanOpenMenuShortcut` (0x101A33E0) must say yes: scene state 0x60 (in the field), no blocking menu,
  no event, the player not in states 2 or 3, ...
- The queued macro's lines run one per step through `TextInputFiles_StepScript`, with `/wait`, calling
  `Command_RunLine` with mode 2 (docs/HOTBAR_CURSOR.md).

## 6. The window procedure (0x100016C0) and the chat line

Messages it handles (disassembly):

| Message | What it does |
|---|---|
| WM_ACTIVATE (6) | `Input_SetActive(6, ...)`: acquire or unacquire the keyboard and the pad |
| WM_KEYDOWN (0x100) | IME bookkeeping (VK_PROCESSKEY 0xE5); then, except Enter, Esc and VK_SEPARATOR, `TextInputFiles_HandleKeyDownWithIme(vk, lparam)`: the chat line's editing keys (cursor, delete, history) |
| WM_CHAR (0x102) | `Input_HandleChar`: a character into the chat line (+0x14 text, +0x114 caret, in the object `[0x10578490]`, only while it is open: `[0x1062193C]` != 0); **Enter: `Command_RunLine(text, 0)`**; Esc: the line cleared; Backspace with double-byte handling |
| WM_SYSKEYDOWN (0x105) | F10 to the text input (when 0x100164B0 says so) |
| 0x10D, 0x10F, 0x281-0x286 | IME composition and notifications to the text input |
| 0x200-0x20A (mouse) | only while `g_mouseAcquired` is 0 (a window, or the hardware mouse): client pixels to the interface's units, to `Cursor_HandleMouseMove`, and the buttons to the cursor's modes (docs/HOTBAR_CURSOR.md) |

So: **keys reach the game twice.** Their state comes from DirectInput (the poll), which drives every game action and
the macros; their characters come from WM_CHAR, which drives only the chat line. Holding Shift, Ctrl, Alt is read
from DirectInput too.

## 7. Command_RunLine (0x10080DC0) and other tools

`Command_RunLine(char *line, int mode)` (tree/src/TextCommand.cpp): the game's command line. Callers
(docs/HOTBAR_CURSOR.md): the chat line on Enter (mode 0), the macro runner (mode 2), `TextInputFiles_DefaultRunLine`
(mode 1), the game's own menus. What the mode changes, from its source:
- while a target or menu selection is active (target manager +0x59 or +0xC4): mode 1 refuses a command word without
  flag 2 (+0x16) with message 0xA4 in the chat log; mode 2 refuses it without a message; mode 0 is not restricted;
- mode 2 sets the byte 0x1047D497 (on only for mode 2; read only by `preprocessArg` 0x10076AB0, which copies it to
  0x1047D496 when a line's argument opens the sub-target window (`YkWindows_SetModeFwd` with the callback 0x10077A20,
  which, with 0x10077A00, is that byte's only reader)); modes 1 and 2 clear 0x1047D3FE;
- modes 3-7 turn the line into one of the game's sub-target tokens: `<st>`, `<stpc>`, `<stnpc>`, `<stpt>`, `<stal>`
  (the strings at 0x10357F88 down to 0x10357F68).
- **The commands** (25 Nov): it looks the line's first word up (`Arg_LookupWord`) in the word table 0x10355408
  (24-byte records: the word; +0x14 its command number; +0x16, +0x17 flags, +0x16 bit 0x2 the test above) and runs the
  command's handler from the table 0x10356E30 ({command, handler, a third word}, 12 bytes each). All 277 words and
  215 commands: docs/COMMANDS.md (made by `pipeline/commands.py`; handlers of the security set left out).

Its first instruction in the game is `sub esp, 0x404` (81 EC 04 04 00 00: 6 bytes; the kit's manifest has T=6, the
trampoline's length). **Windower's Hook.dll replaces that start with a jump into Hook.dll** (prishe_probe under
Windower, 24 Nov: "Command_RunLine 16AF0DC0 starts with a jump to 676D5B50 in Hook.dll"). What its handler does with a
line before calling the game's code: **not known** (Hook.dll is closed). What bytes it leaves after its jump (a 5-byte
jmp leaves the instruction's sixth byte, 00, or Windower may pad it): **not known**; the kit now logs them (section 9).

Ashita: not run with the kit yet beyond prishe_probe (P1); how it hooks input is in its closed core.

## 8. What a mod can use

- **To run a line**: `Command_RunLine(line, 0)` (as Enter does). Under Windower, call the entry (Windower's jump),
  so its own commands still work.
- **To read a key**: the key table at 0x104E1C40 (bits in 3) after the poll, or the action query for "what the
  player bound" (an action, not a key: the player's key configuration then applies).
- **To take a key from the game** (a hotbar key that must not also do its game action): the game never asks Windows
  for key messages, so swallowing WM_KEYDOWN changes nothing but the chat line. The places that work, from the code:
  (a) after the poll, clear the key's byte in the table (the game's actions and macros read only the table; the two
  listeners told inside the poll, 4 above, have already heard the press); (b) wrap the keyboard device's
  GetDeviceState/GetDeviceData (the device at `[g_pAppInputState]+0x88`, its slots +0x24 and +0x28) and remove the key
  before the poll sees it: then nothing in the game sees it. (b) is the complete one.
- **The macro palettes**: their opening is `TextInputFiles_UpdateMenuState`; their macros start at
  `TextInputFiles_QueueEntry` (slots 0-19).

## 9. What this explains in the 24 Nov run

- **No chat command worked** (status_text, hotbar, prishe, photo_mode, xitest U9: "Command_RunLine not hooked"): every
  start had Windower's jump at the entry. The kit's code for hooking in front of another tool's jump
  (`foreign_jmp`, kit/xikit/xikit.c) refuses (a) whenever the manifest has only fingerprints (gobbiefix's public
  manifests: the "+99 (a jmp: another tool's hook ...)" lines) and (b) when any byte after the 5-byte jump differs from
  the game's: with the test kit's byte manifest it refused at +0 with no other information. Which byte it was is not
  known (the live bytes were not logged). Fixed: section 10.
- **"The macro book shows after holding Ctrl, not on a tap"**: that is the game's own rule (5): the palette opens once
  Ctrl has been held into a later game-time tick; the macros run on Ctrl+digit either way. The hotbar's "hotbar mode"
  takes the Ctrl/Alt digits at `TextInputFiles_QueueEntry` (the macro runs bar 2 or 3 instead), but the palette window
  is the game's and still opened on a hold. The owner (25 Nov): in hotbar mode it stays hidden. Done (10).
- **Number keys** pressed for the hotbar also reach the game's own bindings (the table is read from DirectInput); the
  default binds nothing to plain 0-9 (88-97 need Shift), so with the default configuration nothing else happens.

## 10. Changes made from this document

- 25 Nov, the hotbar (sdk/examples/hotbar.cpp): in hotbar mode the game's macro palettes are never shown. The only
  code that opens them is `TextInputFiles_UpdateMenuState` (5), through `MenuMng_OpenByName` (0x1015E350) with the
  requested names `menu    mcr1pall` and `menu    mcr2pall` (every reference to the two strings in the code: that
  function, `TextInputFiles_SetSlot`'s close, the name builder 0x10160760 that maps them to `mcr1long`/`mcr2long`, and
  a test at 0x101AE010 that allows its case while a palette, or no window, has the focus). The mod refuses those two
  opens (returning 0, what the function returns when it opens nothing) and closes any open palette when hotbar mode
  starts. `UpdateMenuState` sets its Ctrl/Alt state (+0xC, +0xD) whether or not the window opens, and the macro keys
  read that state, so they still reach `TextInputFiles_QueueEntry` and the hotbar. Tested offline (hbmod): the
  game's entry with the two names returns 0, counted by the mod.
- 25 Nov, the kit (kit/xikit/xikit.c `foreign_jmp`): another tool's jump at an entry is taken in its three forms
  (E9 rel32, FF 25 [abs], 68 imm32 C3); the entry's first whole instructions (the manifest's T=) are left out of the
  comparison, the rest compared one by one with a byte manifest or through the public manifest's J= fingerprint
  (kit/install/public_manifest.py); a refusal logs why and the live bytes entry-4..+15. Tested offline
  (kit/xikit/test, modes toolhook_*: each form in front of a stand-in tool at Command_RunLine, byte and fingerprint
  manifests, a changed byte refused). Whether Windower's real patch is one of these forms is not known until the
  owner's next run: the log then names its bytes either way.
- The hotbar: unchanged. Taking a hotbar key from the game (section 8 (b)) is not built yet.

## Tools

`pipeline/input_actions.py` makes docs/INPUT_ACTIONS.md. The other readings were made with capstone over
`get_memory_mapped_image()` of the unpacked 6A995428 DLL (a disassembly, a scan of the calls into the key table, the
callers of a function with their pushed arguments, the references to an address, the loads of 0x104E1D44 and the
fields used after them); each line above names the address it was read at.
