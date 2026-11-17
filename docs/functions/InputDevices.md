# InputDevices

Group: `Input` (by the file name only). Source: `sdk/tree_src/InputDevices.cpp`.

Why the file has this name (data/unit_names.json): DirectInput keyboard, mouse and joystick (DirectInput_Install*), input state and buttons, keyboard layout imports; also the debug text overlay (Debug_DrawTextTable)

20 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `InputDevices_DrawActorAxes` | 0x10003890 | 710 | yes | 0 | Draws debug axes and lines for the actors in the list. | medium |
| `Input_SetFlagToggle` | 0x10005600 | 84 | yes | - | Saves and restores an input flag pair. | low |
| `Input_InitState` | 0x10005660 | 180 | yes | - | Clears the input state object's fields and arrays. | low |
| `Input_MapAxisLow` | 0x100059C0 | 61 | yes | - | Maps a raw axis value into the low-range output codes. | low |
| `Input_MapAxisHigh` | 0x10005A00 | 51 | yes | - | Maps a raw axis value into the high-range output codes. | low |
| `InputDevices_FindMapValue` | 0x10007830 | 45 | yes | - | Looks up a value in a key-value string. | low |
| `Input_HandleChar` | 0x10007860 | 638 | yes | - | Handles a typed character for the text input line. | low |
| `DirectInput_InstallKeyboard` | 0x10007E20 | 195 | yes | - | - | - |
| `DirectInput_InstallMouse` | 0x10007EF0 | 297 | yes | - | - | - |
| `InputDevices_JmpGetKeyboardLayout` | 0x10008020 | 882 | yes | - | Jumps to the imported GetKeyboardLayout. | high |
| `DirectInput_InstallJoystick` | 0x100083D0 | 908 | yes | - | - | - |
| `DirectInput_ReleaseDevice` | 0x10008770 | 85 | yes | - | Releases a DirectInput device and its wrapper. | low |
| `Input_SetActive` | 0x100087D0 | 77 | yes | - | Activates or deactivates the input objects by focus state. | low |
| `Input_IsCursorActive` | 0x10008830 | 63 | yes | - | Tests whether the input cursor is active. | low |
| `Input_DispatchButtons` | 0x100088F0 | 213 | yes | - | Dispatches the pressed and released button records to the cursor. | low |
| `DirectInput_PollMouse` | 0x100089D0 | 205 | yes | - | Reads buffered mouse events and recovers the device when it is lost. | medium |
| `XInput_ProbeDll` | 0x10008D90 | 125 | yes | - | Checks whether the XInput DLL can be loaded. | medium |
| `XInput_LoadFunctions` | 0x10008E10 | 95 | yes | - | Loads the XInput DLL and stores its function pointers. | low |
| `InputDevices_CallPtr10456550IfEnabled` | 0x10008EA0 | 44 | yes | - | Calls the function pointer at 0x10456550 with its two arguments when 0x1045654C is set; otherwise returns 1. | low |
| `InputDevices_CallPtr10456558IfEnabled` | 0x10008F00 | 39 | yes | - | Calls the function pointer at 0x10456558 with its argument when 0x1045654C is set; otherwise returns 1. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `InputDevices_DrawActorAxes` calls `MathVector_ReturnThis`, `Mat4_SetIdentity`, `CDx::GetTransformCached`, `Mat4_PostRotateY`, `Mat4_SetTranslation`, `CDx::SetTransform`, `CDx::DrawPrimitiveUP`, `Vec4_Copy`, `Vec3_Sub`, `MathVector_Nop`
- `Input_SetFlagToggle` calls nothing directly
- `Input_InitState` calls nothing directly
- `Input_MapAxisLow` calls nothing directly
- `Input_MapAxisHigh` calls nothing directly
- `InputDevices_FindMapValue` calls nothing directly
- `Input_HandleChar` calls `TextInputFiles_OnChar`, `sub_10312BDB`, `sub_1015DD70`, `Command_RunLine`, `sub_10312AD3`, `sub_1015DD50`
- `DirectInput_InstallKeyboard` calls nothing directly
- `DirectInput_InstallMouse` calls `CDx::ShowCursor`
- `InputDevices_JmpGetKeyboardLayout` calls `LinkedLibraries_JmpImmGetDescriptionA`, `sub_10312940`
- `DirectInput_InstallJoystick` calls `XInput_ProbeDll`, `XInput_LoadFunctions`, `DirectInput_ReleaseDevice`
- `DirectInput_ReleaseDevice` calls nothing directly
- `Input_SetActive` calls nothing directly
- `Input_IsCursorActive` calls `Cursor_GetFlagBit2`
- `Input_DispatchButtons` calls `Cursor_EnterMode4`, `Cursor_EnterMode1`, `Cursor_EnterMode2`, `Cursor_ToggleFlag4`, `Cursor_ToggleFlag1`, `Cursor_ToggleFlag2`
- `DirectInput_PollMouse` calls `DirectInput_InstallMouse`
- `XInput_ProbeDll` calls nothing directly
- `XInput_LoadFunctions` calls nothing directly
- `InputDevices_CallPtr10456550IfEnabled` calls nothing directly
- `InputDevices_CallPtr10456558IfEnabled` calls nothing directly
