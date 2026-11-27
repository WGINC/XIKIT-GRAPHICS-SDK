> Paths in this document are the development repository's: tree/src/ is sdk/tree_src/ here, kit/xikit/ and kit/d3d8on11/ are src/xikit/ and src/d3d8on11/, sdk/examples/ is sdk/examples/; docs/HISTORY.md and kit/sessions/ are not published.

# The game's interface windows: list, placement, drawing

How FFXiMain.dll keeps, places and draws its menu windows, read from its code. Addresses are the analysed build's
(6A995428; the kit translates functions to the build in use). Sources: the tree's C (`tree/src/NetCellFont.cpp`,
`tree/src/TargetMenu.cpp`) and, where the tree has no source, the disassembly of the unpacked 6A995428 DLL. The same
rules as docs/INPUT.md: **not known** marks what has not been read.

Why (24 Nov run): ui_layout "does not work at all". It moved the window's hit rectangle, which is not what is drawn
(section 3).

## 1. The lists

A list is a head pointer; a node is `{+0 next, +0x10 data, +0x14 skip byte}`. `NetCellFont_GetHead` (0x10126500)
returns the head; 0x10126520 returns the next node's data whose skip byte is 0 and advances (disassembly).

- The menu manager `g_menuMng` (0x10621838): its windows at +0. `Menu_DrawLayers` (0x1015F6A0) walks them with
  `Menu_NextVisibleItem` (0x1015EE00) and draws each by its layer (+0x60) with `Menu_DrawWindowItems` (0x101177D0).
- A window: its own node list at +0x14 (the frame, texts, icons ...). Node kind is the node's first short: 0 the
  window's frame, 1 and 2 its parts (`NetCellFont_ComputeOffsets`, `NetCellFont_AttachTo`).

## 2. A window's fields

| Offset | What | Written by / read by |
|---|---|---|
| +0x04 | its menu data; the name is the 16 characters at [+4]+0x46 (e.g. `menu    inventor`) | the game finds windows by `strncmp` of that name |
| +0x14 | the node list | 1 |
| +0x3A, +0x3C, +0x3E, +0x40 | the hit rectangle: left, top, right, bottom | `NetCellFont_SetRectAndUpdateNodes`; read by `NetCellFont_HitTest` (0x10118C10) |
| +0x60 | the layer `Menu_DrawLayers` draws it in | |
| +0x88 | a sub-object placed at the rectangle's top right (right - 6, top) | `NetCellFont_SetRectAndUpdateNodes` |
| +0x8C, +0x8E | **the target position, where it is drawn** | `NetCellFont_SetRectAndUpdateNodes` |
| +0x90, +0x92 | its size | the same |
| +0x94 | an easing timer (set to 0 when placed) | 0x10117520 counts it down by the frame step |
| +0x9A | a byte kept by the placement (its 7th argument) | |
| +0x9C..+0xA2 | the viewport its contents are clipped to (X, Y, right, bottom) | `NetCellFont_SetViewport` (0x1011AA40), when +0x9B is set (never in this build: 5) |
| +0xB8 | a scroll offset added to its items' y | `Menu_DrawWindowItems` |

The frame node (kind 0), as shorts from its start: +0x1A, +0x1C its drawn position, +0x1E, +0x20 moved with the
rectangle, +0x22, +0x24 its size.

## 3. Placing and drawing

**`NetCellFont_SetRectAndUpdateNodes`** (0x1011A5A0; thiscall: window, x, y, width, height, an argument it does not
read, snap, a byte; tree/src/NetCellFont.cpp:15352) is the placement. For the frame node it writes the target
(+0x8C..+0x92), moves the frame node's +0x1E/+0x20 by the change, writes the hit rectangle (+0x3A = x, +0x3C = y,
+0x3E = x + width, +0x40 = y + height), clears +0x94, and with snap 0 puts the frame node's position and size at the
target at once. Kind 1 nodes are laid out again from the frame node's position, kind 2 attached again. In the tree's
source it is the only writer of +0x8C and +0x3A; 40 of the game's functions call it (the menus' layout functions);
the whole game was scanned for other writers: section 5.

**Each frame** `Menu_DrawWindowItems` first calls 0x10117520 (disassembly): for the frame node, the drawn position
(+0x1A, +0x1C) is eased toward the target (+0x8C, +0x8E) by the frame's step (Camera_GetFrameScale) while the timer
+0x94 runs; then the parts are laid out from it. So **where a window is drawn follows +0x8C/+0x8E; the hit rectangle
+0x3A only decides clicks**. Writing +0x3A alone moves where clicks land, not the picture.

## 3b. Hiding each part of the interface (RESEARCH.md E1; read 27 Nov)

Read from build 6AE818B4 with Ghidra 11.4.2's decompiler and capstone; addresses 6A995428's, 6AE818B4's after the slash.

- **Every window (menus, the chat log, the target arrow):** `Menu_DrawLayers` (0x1015F6A0 / 0x10160C70) draws the
  visible windows layer by layer, nine layers (the window's byte +0x60, 0..8), each through `Menu_DrawWindowItems`
  (0x101177D0 / 0x10118C60); when `Menu_IsStateB4Eq1` holds, only windows with bit 0x40 of +0x34 are drawn. Nothing
  else draws a window, so hiding one window is skipping `Menu_DrawWindowItems` for it, found by its name ([+4]+0x46,
  section 4; ui_layout's `ui_list=1` logs the names in the game). Its hit rectangle still takes clicks while hidden
  (section 3): a hidden window should also be moved off the screen, or its clicks refused.
- **The target arrow** is one of those windows: `TargetMenu_UpdateTargetMarker` (0x10150090 / 0x10151660) places it
  over the target each frame from `Target_GetPosShortsMainOrSub` (its +0xBC/+0xBE, and +0xC0/+0xC2 for a sub-target),
  and with no target fades it out with `TargetMenu_MenuInitAndFadeItem` on the window at its +8. So it hides as a
  window. Its name is not read (the in-game log of `ui_list=1` gives it).
- **Nameplates** are not windows: each skeleton actor draws its own in `CXiSkeletonActor::OnDrawName` (0x100D0510 in
  both builds; a virtual method, in seven actor vtables), through `Actor_DrawWorldText` (0x10086210) for the name and
  `DrawNameplateSecondString` (0x10086900) for the second line, each only while the actor's word +0xB2 is 0. It
  returns early for the player in first-person view, when the actor's virtual methods +0x260, +0x34C or +0x358 say so,
  and by the game's own name setting: when the byte 0x1047D694 (6AE818B4 0x1047E844) is set, the next byte chooses
  who has a name (0 everyone; 1 records whose +0x78 top byte is 0; 2 and 3 by bit 13 of +0x120; 4 those whose +0x78
  equals the player's). What each choice is in the game's menus is not read. A hook on `OnDrawName` that returns at
  once hides every nameplate; one that checks the actor hides chosen ones.
- **The chat log** is a window (section 4 gives its placement in the owner's game); its name is not read.

## 3c. Opening a window, and making one of our own (RESEARCH.md E2; read 27 Nov)

`MenuMng_OpenByName` (0x1015E350 / 0x1015F920; name, a flag to place it, a flag) opens a window only when three
lookups by name succeed:
1. **The game's table of windows** (6A995428 0x103722D8, 6AE818B4 0x10373320; `Menu_LookupWindowByName`): 373 entries
   of 0x2C bytes, ended by an empty name; each is a 16-byte name (`menu    logwindo`, `menu    mcr1pall`, ...), a
   pointer to its handler object's slot, flags, a byte, the layer and a word. All 373, with their fields:
   `data/menu_windows.json`. Which window on the screen each name is, the in-game log of ui_layout's `ui_list=1`
   shows; the names alone are not taken as that.
2. **The scene state** allows it (`MenuMng_TestNameForSceneState`).
3. **A definition of that name is loaded** (`Menu_FindItemByNameAt1C`: a walk of the loaded definitions comparing
   +0x46): the definitions come from the game's data files (type-0x30 chunks, docs/DATA_FILES.md section 4).
Then it allocates the 0xD4-byte window (`NetCellFont_MenuCtor`), binds the table's fields into it
(`Menu_FindWindowDefByName`: +0x30, +0x34, +0x60, +0x38, and the handler at +0xC, whose +8 is set to the window),
calls the handler's virtual +4, and inserts the window by layer (`NetCellFont_InsertSortedBy60`).

So a window of a mod's own needs an entry in that table and a loaded definition of the same name, both of which the
game takes from its own data: the table is fixed in the DLL, and a definition comes from a DAT. Neither has been
tried; adding an entry would mean placing a longer copy of the table and pointing the two lookups at it (code
changes at the two functions), and a definition could come from a pack (a DAT with a type-0x30 chunk). **The handler's interface (read 28 Nov: every call through a window's +0xC handler in the window code
0x10115000..0x10165000, 6A995428):** +4 when the window is opened (`MenuMng_OpenByName`); **+0xC when it is freed**
(`NetCellFont_FreeChild` 0x10118F4C, which then clears the handler's +8, its window); **+0x14 when it is placed**
(`game_10119110`, which `Menu_PositionWindow`, `Menu_PositionWindowBySetting`, `TargetMenu_PlaceByLayout` and some 70
other layout functions call); **+0x18 when the selection moves** (`NetCellFont_MenuMoveSelection` 0x101184D1, with the
window and the selected item, +0x4C); **+0x24 when it is made active or not** (`NetCellFont_SetActive` 0x10119293). The
handler's +8 is its window. **`Menu_DrawWindowItems`' parts (read 28 Nov, Ghidra on 6AE818B4's 0x10118C60):** it
walks the window's items (the definition's list, through `game_10126520`); each item of kind 0, 1 or 2 (its first word;
kind 2 only while the window's +0x78 is set) that has a shape is drawn by **0x1011FC80 (analysed; 0x10121110 in
6AE818B4), a method of the shape that draws each of its cells with `Cell_DrawTexturedQuad` over the item's rectangle**
(x, y, width, height and a colour, 0x80808080 by default); the title and edges by 0x1011A150 and 0x1011A250; then,
when the window's +0x6A is set and its +0x10 is not 0xE, **the handler's +0x10, which draws the window's own
contents**; then the viewport is put back when +0x9B is set. So a frame without a window is 0x1011FC80 called on a
frame shape (the shapes `ShapeMng_FindShape` gives from files 14..21, DATA_FILES.md section 3) at a rectangle; it has
not been tried. Until then, the hotbar keeps drawing its own frame (xiui).

## 4. What a mod uses

- To move a window: hook `NetCellFont_SetRectAndUpdateNodes` and change x and y (sdk/examples/ui_layout.cpp since
  25 Nov); to move one already shown, call it again with snap 0 and its +0x9A byte.
- To find a window: its name at [+4]+0x46; the visible ones from `g_menuMng` with `Menu_NextVisibleItem`.
- Units: screen pixels of the UI rectangle, moved, not scaled (25 Nov, disassembly of 0x1011A8F0, the placement from a
  window's definition): a definition's position (+2, +4) and size (+0xA, +0xC) are in a 512 x 448 layout; its byte
  +0x13 anchors it (0 none; 1 right: x += width - 0x200; 2 bottom: y += height - 0x1C0; 3 both), unless its byte
  +0x17 is set. Width and height are the UI rectangle `[0x106218B4]` (left, top, right, bottom shorts), which
  `ZoneMapLoad_CreateUiObjects` sets to 0, 0, `Camera_GetWord14()`, `Camera_GetWord16()` (the +0x14 and +0x16 words of `[0x104568FC]`, which the tree
  calls `g_pCamera` but which holds the App object `CApp::RunMainLoop` makes with `App_Constructor`, 0x10010700, 0x33C
  bytes). Those two words (read 25 Nov): `App_InitScene` (0x100114EF..0x1001150A, called by `CApp::RunMainLoop`)
  writes them from the globals 0x10456AC8 and 0x10456A90, which the configuration table 0x103507DC (records
  {pointer, number, 0}) fills from the game's registry values numbered 0x25 and 0x26 (named `%04d`, so "0037" and
  "0038"; read with RegQueryValueExA by 0x100179E0); both are 0 by default (0x100178B0). When either is 0, equal to
  the screen size (+0x10/+0x12, from CDx +0x15C/+0x160), or its render target cannot be made, the screen size is used
  instead (0x10011712); `Frame_Render` changes it only around `CopyrightText_Draw` and puts it
  back (0x1001262C..0x1001266C). In the owner's game (1512x949) the chat log was placed at 16,863 size 1366,70 (its
  definition's anchor and y not read: a bottom anchor would make its y 362).

Where the definitions come from (read 25 Nov): resource chunks of type 0x30 in the game's DAT files, frames of type
0x31 (docs/DATA_FILES.md section 4, with the file numbers the code loads).

## 5. Not known

- Whether any window is placed by code that writes +0x8C without `NetCellFont_SetRectAndUpdateNodes`. Read so far
  (25 Nov; a scan of every function of the game). A window is a 0xD4-byte object made by `NetCellFont_MenuCtor`
  (`MenuMng_OpenByName`, tree/src/TargetMenu.cpp), and `NetCellFont_SetRectAndUpdateNodes` writes its +0x8C..+0x92 as
  four 16-bit stores (0x1011A632..0x1011A647).
  - The other 16-bit writes at +0x8C/+0x8E are to other objects, as their own fields show:
    `MenuPanels_ConstructInitAt64`/`MenuPanels_ClearMenu` (vtable 0x1033C418; a byte at +0x8C);
    0x1022A660 (a byte at +0x88, where a window keeps a pointer; it opens a window by name with
    `MenuMng_OpenByName`); 0x10232B20 (a byte at +0x90, where a window keeps its width); 0x1015AAB0 (its own
    stack frame, [esp + 0x8E]).
  - 32-bit writes at +0x8C (74 instructions): the one in the window's own unit, `NetCellFont_CursorUpdateEdgeAxes`,
    writes the menu cursor `[0x104E1D4C]` (its callers `Menu_DrawLayers` and 0x10160C60 pass that). The others (26 Nov,
    the whole game scanned again: 80 writes in 67 functions): 60 of the functions neither touch the menu manager
    (0x10621838) nor call the functions that hand out windows (`MenuMng_OpenByName`, `Menu_FindItemByName`,
    `Menu_NextVisibleItem`, `NetCellFont_MenuCtor` and the like); the 7 that do write their own object, not the window:
    0x101E7980, 0x101E7EF0 and 0x101FA550 use fields of it up to +0x174, +0x158 and +0x6C8, past a window's 0xD4 bytes;
    0x10130A80 writes `[0x10663740]`, a 0x9C-byte `YkWindows` object (vtable 0x1033A5D8, made in `YkInit`); 0x101EB660
    runs on `[0x10663684]` (vtable 0x10339D78, made in `YkInit`); 0x10233C30 and 0x10233CD0 are slots of the panel
    vtable 0x1033C720 (`MenuPanels_PanelCtorVt1033C720`). A window has no vtable (`NetCellFont_MenuCtor` writes none).
    So no window is placed by a 32-bit write at +0x8C, as far as where each function gets its object shows (a window
    passed in by a caller of one of the 60 was not ruled out function by function).
- Clamping to the screen (read 25 Nov): neither `NetCellFont_SetRectAndUpdateNodes` nor the per-frame easing
  0x10117520 reads the UI rectangle `[0x106218B4]` or any screen size: they do not clamp. The UI rectangle is read by
  the placement from a definition (0x1011A8F0, its anchoring). The window layout functions (26 Nov, every function
  that calls `NetCellFont_SetRectAndUpdateNodes`: 37 of them): 22 read neither the UI rectangle `[0x106218B4..BA]` nor
  `[0x104568FC]` nor its size getters (0x10015640, 0x10015650), so they cannot clamp to the screen; 0x101626E0 reads
  `[0x104568FC]` (what for: not read); the other 14 read the UI rectangle to anchor (width - 0x200, height - 0x1C0:
  0x1011A8F0, 0x1011ACC0), to centre ((size - 0x200) / 2, (size - 0x1C0) / 2: 0x1011ACC0, 0x10164350, 0x10164430,
  0x102408D0, 0x10240A50, 0x10240DE0, 0x10240E70), to give a window the screen's width (0x102411D0), to right-align it
  (width - 0x98, 0x101E9880), or as a fraction of the width (0x1013A250, with `MenuMng_GetOffsetX`); 0x101376A0,
  0x10162D90 and 0x102418F0 the same way. The only comparison with it near those reads is 0x10162D90's, which limits a
  window's +0x32 (a width) to the screen width - 0xA0 or +0x52, whichever is less: a width, not a position. So no window
  is moved back onto the screen by its layout function, as far as their reads of the screen size show (each function
  was not read in full).
- +0x9B (the viewport switch) and +0x88, read 25 Nov: +0x9B is written by `NetCellFont_MenuCtor` (cleared) and set only
  by 0x1011A7B0, which has no caller and no stored pointer anywhere in the image (the other two byte writes at
  +0x9B are in other units' functions); so no window turns `NetCellFont_SetViewport`'s
  clipping on in this build. 0x1011A7B0 would set the viewport (+0x9C..+0xA2), place the window with it, and give
  the object at +0x88 its x (right - 6), y (top), the visible height, the content height (+0xB4) and the scroll
  offset (+0xB8): the values of a scroll bar. Otherwise the object at +0x88 only gets its position from
  `NetCellFont_SetRectAndUpdateNodes` (right - 6, top). It is made (26 Nov) by `NetCellFont_PlaceCursorObject`
  (0x10118530): 0x2C bytes, set by `MenuPanels_InitDrawRect` (0x10234610) with x = right - 8, y = top, the window's
  height, its row count (+0x58, or the argument) and a second argument; `Menu_DrawWindowItems` draws it
  (`MenuPanels_DrawProgressBar` 0x10234660, at 0x10117EB9) when the window's +0x69 and +0x74 are set and its +0x10 is
  above its +0xC: the scroll bar, drawn only when the rows do not all fit.
