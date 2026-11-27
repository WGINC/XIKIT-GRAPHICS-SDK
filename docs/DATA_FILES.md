> Paths in this document are the development repository's: tree/src/ is sdk/tree_src/ here, kit/xikit/ and kit/d3d8on11/ are src/xikit/ and src/d3d8on11/, sdk/examples/ is sdk/examples/; docs/HISTORY.md and kit/sessions/ are not published.

# The game's data files the interface reads: how a number becomes a file, and which numbers

Read 25 Nov from the analysed build 6A995428 (disassembly; the tree's names). This is what the code says; which
file holds which text is only known once the files themselves are read (section 4).

## 1. A file number to a path

- The tables (0x101C3400, disassembly): `/FTABLE.DAT` is read into the words at +0xC4 (+0xC8 = its size / 2, the
  number of files; without it the game stops loading, 0x101C346E) and `/VTABLE.DAT` into the bytes at +0xBC (when it
  cannot be read, every byte is 1: 0x101C3599..0x101C35C9). Then for n = 2 .. 13 it reads `/ROM%d/FTABLE%d.DAT` and
  `/ROM%d/VTABLE%d.DAT` (strings 0x1037CC48, 0x1037CC34) and, for every file i whose VTABLEn byte is n, sets
  VTABLE[i] = n and FTABLE[i] = FTABLEn[i] (0x101C3790..0x101C37BE); a ROM whose FTABLEn cannot be opened is
  skipped (0x101C363E).
- `XiFileImpl::_getFileName` (0x101C3A90), in its table mode (mode 1, 0x101C3B02): a number at or past +0xC8, or
  whose VTABLE byte is 0, has no file; byte 1 gives `/ROM/%d/%d.DAT` (0x1037CD00), byte n > 1 `/ROM%d/%d/%d.DAT`
  (0x1037CCEC) with n; the two numbers are the FTABLE word >> 7 and word & 0x7F. `TextInputFiles_FormatPathByKind`
  (0x101C3E90) puts the game's folder in front.
- `pipeline/file_paths.py TABLE_DIR NUMBER...` does the same from a local copy of the tables (the game's files never
  enter the repository). With the owner's tables of 10 Nov (109,701 file numbers, ROMs 1-9; 25 Nov): file 14 is
  `/ROM/0/14.DAT`, 92 `/ROM/216/123.DAT`, 39551 `/ROM/280/15.DAT`.
- The owner's archive also held a second pair dated 10 Sep (`More tables/FTABLE.DAT`, `More tables/one more/VTABLE.DAT`);
  each pair agrees with itself (VTABLE byte 1 exactly where the FTABLE word is not 0, but for one file) and the two
  pairs differ in 97 files. The 10 Nov pair, the top-level one, is used.

## 2. Files picked by language

`Scene_GetTableValue` (0x1025B560) returns entry N of the table `DmsgText_SelectTableByLanguage` (0x1025B4F0)
picks by the language number at `[0x10456A28]+8` (its case table 0x1025B550):

| Language number | Table | When |
|---|---|---|
| 0 | 0x1038AB08 | |
| 1 | 0x1038A548 | |
| 2 | 0x1038A388 | 0x1038A548 when the byte `[0x10456A28]+0x18` has its top bit set |
| 3 | 0x1038A708 | the same |

Which language each number is (read 25 Nov from the owner's files: the text of entry 12 in each table): 0 Japanese,
1 English, 2 German, 3 French. Each table is 112 file numbers; 82
constant entries are asked for by name in the code (callers of `Scene_GetTableValue`, `push imm` before the call),
6 calls in 4 functions pass a register (not followed). The entries and who asks for them (all 112 x 4 numbers:
data/lang_file_tables.json, written by `python3 pipeline/lang_files.py $FFXI_DLL`):

| Entry | Lang 0 | Lang 1 | Lang 2 | Lang 3 | Asked for by |
|---|---|---|---|---|---|
| 0 | 39532 | 39542 | 55746 | 56166 | `App_InitScene` (index in ebx = 0; kept as g_appMeshResC) |
| 2-4, 6-19, 21-23, 25, 61 | (21 numbers each: data/lang_file_tables.json) | | | | `TargetMenu_LoadAllMessageTables` |
| 20 | 55537 | 55657 | 55777 | 56197 | `ZoneMapLoad_LoadSceneFileAndBind` |
| 24 | 55545 | 55665 | 55785 | 56205 | `FsWordCompletion_LoadData` |
| 27, 28 | 55572, 55568 | 55692, 55688 | 55812, 55808 | 56232, 56228 | `TargetMenu_InitFromTables` |
| 33 | 55569 | 55689 | 55809 | 56229 | `YkInit` |
| 37 | 55570 | 55690 | 55810 | 56230 | `Acter_ResetGlobals` |
| 39-55, 60 | (18 numbers each: data/lang_file_tables.json) | | | | `TargetMenu_FillSceneTable` |
| 56, 57, 58 | 10, 11, 12 | 85, 86, 87 | 85, 86, 55823 | 85, 86, 56243 | `MenuPanels_ConstructFromScene`, `MenuPanels_CtorVt1033C50C`, `MenuPanels_LoadNamedEntries` |
| 62, 63 | 55584, 55585 | 55704, 55705 | 55824, 55825 | 56244, 56245 | `TargetMenu_LoadTable`, `TargetMenu_LoadMessageSet` |
| 90, 91 | 80, 81 | 82, 81 | 82, 81 | 82, 81 | `App_InitScene` (0x5A, 0x5B), `MenuPanels_ReadChunk` |
| 92 | 55612 | 55732 | 55852 | 56272 | `MenuPanels_LoadNamedEntries` |
| 93, 94 | 55582, 55614 | 55702, 55734 | 55822, 55854 | 56242, 56274 | `MenuPanels_LoadMessageTable` |
| 95, 96 | 55581, 55613 | 55701, 55733 | 55821, 55853 | 56241, 56273 | `MenuPanels_LoadFromFile` |
| 97, 98 | 55561, 55562 | 55681, 55682 | 55801, 55802 | 56221, 56222 | `MenuPanels_LoadDMsgTable` |

**The spells' and abilities' tables (28 Nov, Ghidra on 6AE818B4's `ZoneMapLoad_InitGlobalTables`):** not files of
their own but resource chunks already loaded, found with `ResourceIter_Start` by type: **type 0x49** is the spells'
table (kept at [0x10667A74] + 0x30 past the chunk's header; 1,024 records of 100 bytes), **type 0x53** the abilities'
([0x1066714C], 0xB00 records of 0x30 bytes); each record is decoded in place with `MenuPanels_RotateBytesByBitCount`
(0x1021E870). Type 4 chunks named `mon_` (0x5F6E6F6D), `mnc2` and `levc` are kept at [0x1057829C], [0x105782A0] and
[0x10667A78]. In a record: the spells' byte +0xD is the recast in quarter seconds (it is multiplied by 15 to 1/60 s:
HOTBAR_CURSOR.md item 2); the abilities' word +8 is the recast timer id and byte +2 a kind the charge code tests. Which
file holds those chunks, and the records' other fields (names are in the message tables above; icons), are not read.

## 3. Files named by number in the code

| File number | Loaded by | What the code does with it |
|---|---|---|
| 14 + the window-style setting | `Menu_ReloadResource` (0x10160440: `0x101CC620(value + 0xE)`); at start value 0 (`App_InitScene`), on a change setting 0x12 (`TextInputFiles_ApplyUiSetting`, its case for 0x12) | finds the resource chunk of type 0x31 and hands it to `ShapeMng_FindShape`: the window frame shapes |
| 92 (0x5C) | `YkCommonInit` (0x101C8B1B, `0x101CC620`) | the same (type 0x31 chunk, shapes) |
| 53442 (0xD0C2) | `YkWindows_SetMapView` (0x101F8404, `0x101CC620`) | the same |
| 39551, 39560 (0x9A7F, 0x9A88) | `App_InitScene` (0x10072FD0) | kept as g_appMeshRes_39551 / _39560 |
| 27 (0x1B), 52743 (0xCE07) | `MeshResourceMng_LoadSystemResources` | |
| 7052 (0x1B8C) | 0x10178DF0 | |

Two more constant loads are in functions of the security set and are not listed. The window-style setting 0x12 is
defined with range 0..7 (`TextInputFiles_DefineEntry` at 0x10193E27; docs/INPUT.md, 26 Nov): files 14..21.

## 4. Where the window layouts and texts are inside a file (read 25 Nov, with the owner's files)

- A window's layout (the record `Menu_FindItemByNameAt1C` finds by its 16-character name, e.g. `menu    inventor`) is a
  resource chunk of **type 0x30**. Its setup is slot 8 of the type's vtable 0x1032C69C (the factory's table in
  docs/FORMATS.md section 1), 0x10116FA0: it passes the chunk data (object +0x30) to 0x1015DF80, which makes a 0x68-byte
  record (0x1011AEB0; 0x1011B010 fills it) and adds it to `g_menuMng`+0x1C with `NetCellFont_PushBack`.
- The chunk data, as 0x1011B010 reads it (each read advances a pointer, 0x1011B1B0):
  - 16 bytes: the name (to +0x46); 16 bytes: a header whose byte 1 is the number of items;
  - the frame record (0x1011B3B0; kept at the record's +8): +0 its length (the next record starts there, 0x1011B5D6),
    +2 x, +4 y, +0xA width, +0xC height, +0x13 the anchor, +0x17 anchor off (these six are what the placement
    0x1011A8F0 reads, 0x1011A9AF..0x1011A9E5, after finding the record by name and taking its +8), +0x14 the number
    of parts, each 0x14 bytes from +0x20 (two shorts and a 16-byte shape name; four given names are replaced, three by
    `Scene_GetMenuFrameName` and one by a fixed name, 0x1011B45B..0x1011B536), then two numbers written as ASCII whose lengths are +0x15 and +0x16: a row of message
    table 14 and a row of table 13 (`TargetMenu_GetMessage`, 0x10152F20; a negative number is none, 0x1011B57A);
  - then the items (0x1011B6B0): the same, with the part count at +0x1B and the two text lengths at +0x1D, +0x1E.
- Message table 14 is language-table entry 12 and table 13 entry 13: `TargetMenu_GetMessage` finds the table id in the
  28 pairs at 0x10371DA8 ({id, text object}), and `TargetMenu_LoadAllMessageTables` (0x10153C10) loads each of those
  objects from a language-table entry (12 -> 0x10578508 = table 14, 13 -> 0x10578518 = table 13). In the owner's
  English files table 13 holds window titles ("Items" for `inventor`) and table 14 help lines.
- `pipeline/menu_layouts.py` decodes this. In the owner's English files: 407 windows in entry 0 (ROM/119/51.DAT), 56 in
  entry 1 (ROM/119/50.DAT), 2 in file 92; 219 with a title, 57 with a help line. Anchors: 183 none, 166 right, 102
  bottom, 14 both. Example: `logwindo` at 16, 298, 366 x 134, anchor bottom with anchor off set, so the placement
  leaves it where the definition puts it; where the owner's game showed it (16, 863 at 1512 x 949) is therefore set
  by other code (not read).
- The window frames are type 0x31 chunks: files 14-21 (window styles 0-7, all 10,880 bytes; files 22-29 hold no type-0x31
  chunk; the setting's range is 0..7, so they are never asked for as frames), 92, 53442 and the two layout files.
- The text files: language-table entries are of four kinds in the owner's English set. `d_msg` files (DmsgText,
  `pipeline/dmsg.py`, read as `DmsgText_Bind` 0x102579B0 and `DmsgText_GetEntryPtr` 0x102574F0 read them: magic,
  +0xA = 1 all bytes inverted, an index of {offset, length} pairs at +0x40, cells with their text at +0x1C);
  `XISTRING` files (entries 5, 8, 10; `pipeline/xistring.py`, as `TargetMenu_GetEntryPtrByLayout` 0x101530C0 reads
  them); the two resource files (`menu`, `lobb`: entries 0 and 1, and 90, 91); others (39-60, 99-110) not read. The
  inline codes in the texts (`DmsgText_ExpandFormCodes`) are not decoded.

## 5. Asked of the owner (25 Nov)

1. Done 25 Nov: the tables (section 1).
2. The 434 files at the numbers of sections 2 and 3 (all four language tables, since which one the owner's game uses
   is not read; and files 14-29 for the window styles, more than the setting may reach, its range not being read):
   a list of paths and a PowerShell script that copies them, given to the owner (collect_files_25nov.zip; the list
   is made by pipeline/file_paths.py from data/lang_file_tables.json and the constants of section 3). Received 25 Nov,
   all 416 different paths (several numbers share a path).
