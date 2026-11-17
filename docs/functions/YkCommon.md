# YkCommon

Group: `Yk` (by the file name only). Source: `sdk/tree_src/YkCommon.cpp`.

Why the file has this name (data/unit_names.json): YkCommonInit, CTkSubWindow_DrawTime, the number drawing (DrawFraction*, DrawEasedPercent*), Gfx_ProjectWorldToScreen (an address range between two evidenced source files, holding several of the original files: named for its main contents)

53 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `YkCommon_InitFourSlots` | 0x101C7C50 | 37 | yes | - | Clears two four-dword arrays and sets four words to -1. | low |
| `YkCommon_Construct` | 0x101C7F80 | 23 | yes | - | Sets the object's vtable pointer and zeroes its four fields. | medium |
| `YkCommon_Clear` | 0x101C8070 | 35 | yes | - | Clears the object's source and data fields and empties its entry array. | medium |
| `YkCommon_FreeBuffer` | 0x101C80A0 | 32 | yes | - | Frees the buffer at +0x54 and resets its size and status fields. | medium |
| `YkCommon_Load` | 0x101C80C0 | 130 | yes | - | Loads a file entry's header and allocates its buffer. | low |
| `YkCommon_Init` | 0x101C8260 | 42 | yes | - | Sets up the object's entry arrays and clears its table source. | medium |
| `YkCommon_ResizeEntries` | 0x101C8290 | 227 | yes | - | Resizes a table of 0x1C-byte entries, keeping the existing ones. | low |
| `YkCommon_LoadTable` | 0x101C8380 | 198 | yes | - | Loads a table's header and row data from a file entry and binds them to the table at +0x58. | medium |
| `YkCommon_MapChar` | 0x101C87A0 | 247 | yes | - | Maps one character through a translation table and returns the number of bytes it used. | low |
| `YkCommon_CompareMapped` | 0x101C88A0 | 108 | yes | - | Compares two strings after mapping both through the same translation table. | low |
| `YkCommonInit` | 0x101C8950 | 474 | yes | - | - | - |
| `YkCommon_GetIndexed` | 0x101C8C30 | 24 | yes | - | Returns the pointer stored at the given index of the 18-entry global array at 0x10662E50, or 0 when the index is out of range. | low |
| `YkCommon_Checksum` | 0x101C8C50 | 52 | yes | - | Computes a table-driven 32-bit checksum over a byte range. | medium |
| `YkCommon_TimeToTmWrap28Years` | 0x101C8D10 | 84 | yes | - | Converts a time value with sub_10314D91, stepping times past 0x7FE8177F back by 28-year cycles and adding the years back to the result. | medium |
| `YkCommon_GetOffset` | 0x101C8D70 | 33 | yes | - | Returns the offset 0x76C plus a field of a looked-up record, or 0x76C when there is no record. | low |
| `Gfx_ProjectWorldToScreen` | 0x101C8DA0 | 322 | yes | 1 | - | - |
| `YkCommon_FormatDateTime` | 0x101C8FD0 | 667 | yes | - | Formats a time value as date and/or time text (by flags in arg2) into a static buffer and returns it. | medium |
| `YkCommon_FindShortKeyEntry` | 0x101C9270 | 55 | yes | - | Finds the entry in a 6-byte table whose first short key matches the argument. | low |
| `CTkSubWindow_DrawTime` | 0x101C93C0 | 120 | yes | - | - | - |
| `YkCommon_MeasureText` | 0x101C9550 | 159 | yes | - | Returns the width of a string using item 0 (Unit101C72E0_GetIndexed(0)) (used to centre text). | low |
| `YkCommon_DrawUnscaled` | 0x101C9780 | 41 | yes | 3 | Calls the text draw routine at unit scale. | low |
| `YkCommon_DrawTextItem0` | 0x101C97B0 | 628 | yes | 2 | Draws a string using item 0 (Unit101C72E0_GetIndexed(0)) at a position and scale, optionally centred. | low |
| `YkCommon_DrawString` | 0x101C9D50 | 580 | yes | 2 | Draws a string glyph by glyph and returns the end position. | medium |
| `YkCommon_DrawTruncated` | 0x101CA180 | 193 | yes | 2 | Draws a string unscaled, truncated to 7 characters with a trailing shape when it is longer than 8 bytes. | medium |
| `YkCommon_DrawFractionRange` | 0x101CAD00 | 436 | yes | 2 | Draws a bar gauge filled to the first fraction, with a band from the first fraction to the second and an optional marker. | medium |
| `YkCommon_DrawFractionDefault` | 0x101CAEC0 | 59 | yes | 3 | Draws a fraction gauge at unit scale. | low |
| `YkCommon_DrawSmoothed` | 0x101CAF00 | 255 | yes | 3 | Draws a gauge and moves its stored value toward the target. | low |
| `YkCommon_DrawSmoothedDefault` | 0x101CB000 | 59 | yes | 4 | Draws a smoothed gauge at unit scale. | low |
| `YkCommon_DrawFractionItem1A` | 0x101CB040 | 65 | yes | 4 | DrawFractionDefault with the +0x184/+0x98 resources of item 1, the value in the first or second slot. | medium |
| `YkCommon_DrawSmoothedItem1A` | 0x101CB090 | 52 | yes | 5 | DrawSmoothedDefault with the +0x184/+0x98 resources of item 1. | medium |
| `YkCommon_DrawSmoothedItem1B` | 0x101CB1B0 | 52 | yes | 5 | DrawSmoothedDefault with the +0x188/+0x9C resources of item 1. | medium |
| `YkCommon_DrawSmoothedExItem1B` | 0x101CB230 | 72 | yes | 4 | DrawSmoothed with the +0x188/+0x9C resources of item 1. | medium |
| `YkCommon_DrawEasedPercent` | 0x101CB430 | 196 | yes | 3 | Draws a 0..100 value as a fraction and eases the stored displayed value toward the target by 15% per call. | medium |
| `YkCommon_DrawEasedPercentUnitScale` | 0x101CB500 | 69 | yes | 4 | Unit101C72E0_DrawEasedPercent with all four scales 1.0. | high |
| `YkCommon_DrawEasedPercentItem1A` | 0x101CB550 | 62 | yes | 5 | DrawEasedPercentUnitScale with the +0x184/+0x98 resources of item 1 and colours 0x80001080/0x80801000. | medium |
| `YkCommon_BeginCapture` | 0x101CB770 | 31 | yes | 1 | Starts a capture on sub_10456C0C for the given rectangle and returns true. | medium |
| `YkCommon_Forward10097E80` | 0x101CBC60 | 5 | yes | - | Calls the function at 0x10097E80 with its argument and returns its result. | low |
| `YkCommon_IsActorField170` | 0x101CBDF0 | 44 | yes | - | Returns whether the actor sub_10480AF0[DAT_10485F7A] has the value param_1 at +0x170. | medium |
| `YkCommon_IsActorField170Is5` | 0x101CBE50 | 11 | yes | - | Unit101C72E0_IsActorField170(5). | high |
| `YkCommon_IsActorField170Is55` | 0x101CBE60 | 11 | yes | - | Unit101C72E0_IsActorField170(0x55). | high |
| `YkCommon_IsActorField170Is6` | 0x101CBE70 | 11 | yes | - | Unit101C72E0_IsActorField170(6). | high |
| `YkCommon_TestFlags100Or40DAC` | 0x101CC070 | 41 | yes | - | Tests Unit100D7420 flag 0x100, or (when asked) bit 0x40 at +0x40DAC of the object DAT_104DFD98. | medium |
| `YkCommon_Test104DFD98Field40C3CZero` | 0x101CC0A0 | 40 | yes | - | Returns whether the object at 0x104DFD98 passes the check at 0x100F9680 and its dword at +0x40C3C is zero. | low |
| `YkCommon_GetByte1048098D` | 0x101CC1B0 | 6 | yes | - | Returns the byte at 0x1048098D. | low |
| `YkCommon_ActorTest1D0` | 0x101CC1D0 | 77 | yes | - | Flag test on an actor combining fn_101CC220 and bits at +0x1D0/+0x128/+0x130; its meaning is not established. | low |
| `YkCommon_ActorPairTest1FF` | 0x101CC220 | 253 | yes | - | Compares the +0x1FF bytes of an actor and the actor sub_10480AF0[DAT_10485F7A] when both have flag 0x400; its meaning is not established. | low |
| `YkCommon_IsNotD3` | 0x101CC320 | 12 | yes | - | Returns whether its argument is not 0xD3. | low |
| `YkCommon_CC4F0ActorTest400` | 0x101CC350 | 72 | yes | - | Tests flag 0x400 and the +0x1FF byte of the actor from sub_101CC4F0. | low |
| `Acter_GetActerAt10485F7A` | 0x101CC4F0 | 28 | yes | - | Returns the acter in the table slot whose index is held at 0x10485F7A, or 0. | medium |
| `YkCommon_GetCC4F0ActorByIndexAt1FA` | 0x101CC510 | 15 | yes | - | Acter_GetByIndexAt1FA of the actor from sub_101CC4F0. | high |
| `Acter_GetByIndexAt1FA` | 0x101CC520 | 36 | yes | - | Returns the actor-table entry indexed by the 16-bit field at +0x1FA of the given actor, or 0. | medium |
| `YkCommon_GetCC4F0ActorAt2A0` | 0x101CC550 | 15 | yes | - | Unit101C72E0_GetActorAt2A0 of the actor from sub_101CC4F0. | high |
| `YkCommon_GetActorAt2A0` | 0x101CC560 | 36 | yes | - | Returns the actor whose index the object holds at +0x2A0. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `YkCommon_InitFourSlots` calls nothing directly
- `YkCommon_Construct` calls nothing directly
- `YkCommon_Clear` calls `DmsgText_Clear`, `TextInputFiles_EntriesCtorEmpty`
- `YkCommon_FreeBuffer` calls `operator_delete`
- `YkCommon_Load` calls `YkCommon_FreeBuffer`, `TextInputFiles_ForwardOrExit`, `TextInputFiles_AllocEntries`, `TextInputFiles_EntriesSetCount`, `DmsgText_BindSource`, `DmsgText_GetRowInfo`, `Allocator_Generic`
- `YkCommon_Init` calls `TextInputFiles_EntriesCtor`, `DmsgText_Clear`, `YkCommon_ResizeEntries`
- `YkCommon_ResizeEntries` calls `Allocator_Generic`, `operator_delete`
- `YkCommon_LoadTable` calls `TextInputFiles_EntriesSetCount`, `FileMng_ResolveOrExit`, `TextInputFiles_ForwardOrExit`, `DmsgText_BindSource`, `DmsgText_GetRowBytes`, `Allocator_Generic`, `operator_delete`, `DmsgText_BindDataAndMark`, `DmsgText_GetDataField28`
- `YkCommon_MapChar` calls nothing directly
- `YkCommon_CompareMapped` calls `YkCommon_MapChar`
- `YkCommonInit` calls `TargetMenu_GetMessageFwd`, `ShapeMng_FindShape`, `Scene_GetMenuFrameName`, `sub_101CC620`
- `YkCommon_GetIndexed` calls nothing directly
- `YkCommon_Checksum` calls nothing directly
- `YkCommon_TimeToTmWrap28Years` calls `sub_10314D91`
- `YkCommon_GetOffset` calls `sub_100DBE10`, `YkCommon_TimeToTmWrap28Years`
- `Gfx_ProjectWorldToScreen` calls `MathVector_ReturnThis`, `CDx::GetTransformCached`, `Mat4_SetIdentity`, `Mat4_SetTranslation`, `Camera_GetViewMatrixPtr`, `CDx::SetTransform`, `Vec4_Set`, `Gfx_ProjectWorldToClip`, `Gfx_NdcToScreen`, `sub_10311C2C`, `MathVector_Nop`
- `YkCommon_FormatDateTime` calls `YkCommon_TimeToTmWrap28Years`, `YkCommon_FindShortKeyEntry`, `TargetMenu_FormatMessage4`, `TargetMenu_FormatMessage5`, `sub_10311FF1`, `TargetMenu_GetMessageFwd`
- `YkCommon_FindShortKeyEntry` calls nothing directly
- `CTkSubWindow_DrawTime` calls `sub_10311FF1`
- `YkCommon_MeasureText` calls `YkCommon_GetIndexed`
- `YkCommon_DrawUnscaled` calls `YkCommon_DrawTextItem0`
- `YkCommon_DrawTextItem0` calls `YkCommon_MeasureText`, `YkCommon_GetIndexed`, `sub_10311C2C`, `sub_1011FB60`, `sub_1011FC80`
- `YkCommon_DrawString` calls `YkCommon_GetIndexed`, `sub_1011FB60`, `sub_1011FC80`
- `YkCommon_DrawTruncated` calls `YkCommon_GetIndexed`, `YkCommon_DrawUnscaled`, `sub_1011FC80`
- `YkCommon_DrawFractionRange` calls `sub_10311C2C`, `sub_1011FC80`
- `YkCommon_DrawFractionDefault` calls `YkCommon_DrawFractionRange`
- `YkCommon_DrawSmoothed` calls `YkCommon_DrawFractionRange`, `sub_10311C2C`
- `YkCommon_DrawSmoothedDefault` calls `YkCommon_DrawSmoothed`
- `YkCommon_DrawFractionItem1A` calls `YkCommon_GetIndexed`, `YkCommon_DrawFractionDefault`
- `YkCommon_DrawSmoothedItem1A` calls `YkCommon_GetIndexed`, `YkCommon_DrawSmoothedDefault`
- `YkCommon_DrawSmoothedItem1B` calls `YkCommon_GetIndexed`, `YkCommon_DrawSmoothedDefault`
- `YkCommon_DrawSmoothedExItem1B` calls `YkCommon_GetIndexed`, `YkCommon_DrawSmoothed`
- `YkCommon_DrawEasedPercent` calls `sub_101CB280`, `sub_10311C2C`
- `YkCommon_DrawEasedPercentUnitScale` calls `YkCommon_DrawEasedPercent`
- `YkCommon_DrawEasedPercentItem1A` calls `YkCommon_GetIndexed`, `YkCommon_DrawEasedPercentUnitScale`
- `YkCommon_BeginCapture` calls `ErrorReport_Begin`
- `YkCommon_Forward10097E80` calls `Acter_TestFlagBit`
- `YkCommon_IsActorField170` calls nothing directly
- `YkCommon_IsActorField170Is5` calls `YkCommon_IsActorField170`
- `YkCommon_IsActorField170Is55` calls `YkCommon_IsActorField170`
- `YkCommon_IsActorField170Is6` calls `YkCommon_IsActorField170`
- `YkCommon_TestFlags100Or40DAC` calls `NetCellFont_GetFlags`
- `YkCommon_Test104DFD98Field40C3CZero` calls `NetCellFont_IsReadyBy3C350`, `NetCellFont_GetDword40C3C`
- `YkCommon_GetByte1048098D` calls nothing directly
- `YkCommon_ActorTest1D0` calls `YkCommon_ActorPairTest1FF`, `CXiActor::IsFlag1d0Clear`
- `YkCommon_ActorPairTest1FF` calls `CXiActor::IsFlag1d0Clear`
- `YkCommon_IsNotD3` calls nothing directly
- `YkCommon_CC4F0ActorTest400` calls `Acter_GetActerAt10485F7A`
- `Acter_GetActerAt10485F7A` calls nothing directly
- `YkCommon_GetCC4F0ActorByIndexAt1FA` calls `Acter_GetActerAt10485F7A`, `Acter_GetByIndexAt1FA`
- `Acter_GetByIndexAt1FA` calls nothing directly
- `YkCommon_GetCC4F0ActorAt2A0` calls `Acter_GetActerAt10485F7A`, `YkCommon_GetActorAt2A0`
- `YkCommon_GetActorAt2A0` calls nothing directly
