# tools/data_files: the game's data files, read the way the game reads them

Python 3 readers made from FFXiMain.dll's own code (analysed build 6A995428; each file's header names the functions
it follows). They read your local copy of the game's files; no game file or text is in this kit. The facts behind
them: docs/DATA_FILES.md, docs/AUDIO.md (sound), docs/CAMERA.md (the zone record).

| Tool | What |
|---|---|
| `file_paths.py TABLE_DIR NUMBER...` | a file number to its path (`ROM/0/71.DAT`), from the game's VTABLE.DAT, FTABLE.DAT and ROMn tables |
| `lang_files.py FFXiMain.dll OUT.json` | the four language tables of file numbers (0 Japanese, 1 English, 2 German, 3 French), from the 6A995428 DLL |
| `dmsg.py FILE [N]` | a `d_msg` text file's rows (most of the game's labels and messages) |
| `xistring.py FILE [N]` | an `XISTRING` text file's rows |
| `menu_layouts.py DAT_ROOT HELP_DMSG TITLE_DMSG LAYOUT_DAT...` | every window layout (type-0x30 chunks): name, position, size, anchor, title, help; JSON |
| `spw_decode.py IN.spw OUT.wav` | a `SeWave` sound file to a WAV (the game's 4-bit ADPCM) |

Example (English window titles): `file_paths.py <game folder> 55651 55652 39542` gives the help table, the title table
and the layout file; then `menu_layouts.py <game folder> <help path> <title path> <layout path>`.
