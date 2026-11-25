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
| +0x9C..+0xA2 | the viewport its contents are clipped to (X, Y, right, bottom) | `NetCellFont_SetViewport` (0x1011AA40), when +0x9B is set |
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

## 4. What a mod uses

- To move a window: hook `NetCellFont_SetRectAndUpdateNodes` and change x and y (sdk/examples/ui_layout.cpp since
  25 Nov); to move one already shown, call it again with snap 0 and its +0x9A byte.
- To find a window: its name at [+4]+0x46; the visible ones from `g_menuMng` with `Menu_NextVisibleItem`.
- Units: screen pixels of the UI rectangle, moved, not scaled (25 Nov, disassembly of 0x1011A8F0, the placement from a
  window's definition): a definition's position (+2, +4) and size (+0xA, +0xC) are in a 512 x 448 layout; its byte
  +0x13 anchors it (0 none; 1 right: x += width - 0x200; 2 bottom: y += height - 0x1C0; 3 both), unless its byte
  +0x17 is set. Width and height are the UI rectangle `[0x106218B4]` (left, top, right, bottom shorts), which
  `ZoneMapLoad_CreateUiObjects` sets to 0, 0, `Camera_GetWord14()`, `Camera_GetWord16()` (the camera's +0x14 and
  +0x16 words; what sets those: **not read**); `Frame_Render` changes it only around `CopyrightText_Draw` and puts it
  back (0x1001262C..0x1001266C). In the owner's game (1512x949) the chat log was placed at 16,863 size 1366,70 (its
  definition's anchor and y not read: a bottom anchor would make its y 362).

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
    writes the menu cursor `[0x104E1D4C]` (its callers `Menu_DrawLayers` and 0x10160C60 pass that). The other 73 are
    in functions of other classes by their names (`YkWindows_*` of other vtables, `Target_Reset`, `MenuMng_Init`,
    `CMoGeneratorClone::ResolveCmdTargets`, ...); each one's object has not been followed.
- Whether a window's own code clamps it to the screen after it is moved.
- What +0x9B (the viewport switch) is set from; what the sub-object at +0x88 is.
