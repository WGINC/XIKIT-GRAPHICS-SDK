# DmsgText

Group: `Dmsg` (by the file name only). Source: `sdk/tree_src/DmsgText.cpp`.

Why the file has this name (data/unit_names.json): the strings "d_msg", "Invalid Dmsg", the kana vowels "aieuoAIUEO": the message text tables (an address range between two evidenced source files, holding several of the original files: named for its main contents)

90 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Gfx_DrawSpriteAlphaTested` | 0x10253F60 | 260 | yes | 0 | - | - |
| `DmsgText_InvertBytes` | 0x102572E0 | 38 | yes | - | Inverts each byte of a block when the mode argument is 1. | medium |
| `DmsgText_SwapEndianPair` | 0x102573C0 | 32 | yes | - | Byte-swaps the two dwords of a table header. | medium |
| `DmsgText_GetEntryPtr` | 0x102574F0 | 57 | yes | - | Returns the data pointer of a valid table entry, or null. | low |
| `DmsgText_GetCellData` | 0x10257550 | 64 | yes | - | Returns the data pointer of a cell in a row of the table, or null. | low |
| `DmsgText_Align4` | 0x10257590 | 20 | yes | - | Rounds a size up to the next multiple of four. | medium |
| `DmsgText_IsNotHashOrDot` | 0x102575B0 | 24 | yes | - | Reports whether a string does not start with '#' or '.'. | low |
| `DmsgText_GetWord40` | 0x102575D0 | 11 | yes | - | Returns the word stored at offset 0x40 of the table. | low |
| `DmsgText_ComputeTotalSize` | 0x102575E0 | 130 | yes | - | Computes the total size of the table's data block. | medium |
| `DmsgText_Clone` | 0x10257670 | 333 | yes | - | Allocates and fills a compact copy of the table. | medium |
| `DmsgText_GetDataOrDefault` | 0x102577C0 | 56 | yes | - | Returns a cell's data, or the default string when the table or cell is empty. | low |
| `DmsgText_GetDwordEntry` | 0x10257800 | 43 | yes | - | Returns the dword stored in a table entry, or 0 when the entry is not valid. | low |
| `DmsgText_GetDMsgTable` | 0x10257830 | 6 | yes | - | Returns the d_msg table object. | medium |
| `DmsgText_CallFreeData` | 0x10257840 | 5 | yes | - | Frees the table's data. | low |
| `DmsgText_FreeData` | 0x10257850 | 14 | yes | - | Frees the data block held by the object. | medium |
| `DmsgText_GetRowBase` | 0x10257870 | 54 | yes | - | Returns the base address of a row of the table. | medium |
| `DmsgText_GetCell` | 0x102578B0 | 77 | yes | - | Returns the cell at a row and column of the table. | medium |
| `DmsgText_GetDwordCell` | 0x10257920 | 44 | yes | - | Returns the dword stored in a cell of the table. | low |
| `DmsgText_GetCellCol0` | 0x10257950 | 15 | yes | - | Returns the first cell of a table row. | medium |
| `DmsgText_Assign` | 0x10257980 | 33 | yes | - | Binds the table to a new source and returns the source pointer. | low |
| `DmsgText_Bind` | 0x102579B0 | 318 | yes | - | Binds the table's source to the given table header and locates its data. | low |
| `DmsgText_GetRowCount` | 0x10257AF0 | 7 | yes | - | Returns the number of rows in the table. | medium |
| `DmsgText_IsBound` | 0x10257B10 | 9 | yes | - | Reports whether the table has a source bound. | medium |
| `DmsgText_Clear` | 0x10257B60 | 16 | yes | - | Clears the table's source and data fields. | medium |
| `DmsgText_BindSource` | 0x10257BA0 | 24 | yes | - | Stores the table source and byte-swaps its header when needed. | low |
| `DmsgText_GetRowBytes` | 0x10257BC0 | 10 | yes | - | Returns the size in bytes of the table's row index. | low |
| `DmsgText_BindDataAndMark` | 0x10257BD0 | 21 | yes | - | Binds the table's data block and marks it bound. | low |
| `DmsgText_BindData` | 0x10257BF0 | 92 | yes | - | Stores the table's data block and prepares its row index. | medium |
| `DmsgText_GetDataField28` | 0x10257C60 | 7 | yes | - | Returns a field of the bound data block. | low |
| `DmsgText_GetStride` | 0x10257C70 | 7 | yes | - | Returns the row stride of the table. | low |
| `DmsgText_GetRowInfo` | 0x10257C80 | 83 | yes | - | Returns the offset and size of a row of the table. | low |
| `DmsgText_IsTypeOne` | 0x10257FE0 | 13 | yes | - | Reports whether a value's type byte is 1. | low |
| `DmsgText_IsTypeRange` | 0x10257FF0 | 23 | yes | - | Reports whether a value's type byte is in the range 2 to 15. | low |
| `DmsgText_GetFormString` | 0x10258040 | 179 | yes | - | Returns the word-form string for a type and two flags. | low |
| `DmsgText_PickFormString` | 0x10258150 | 125 | yes | - | Selects a string from fixed tables by kind, index and flags. | low |
| `DmsgText_FindFirstTypeByte` | 0x102581D0 | 61 | yes | - | Returns the first control byte (2-15) in a Shift-JIS string. | medium |
| `DmsgText_ExpandFormCodes` | 0x10258430 | 361 | yes | - | Copies a Shift-JIS text into a buffer, replacing its control bytes 1..15 with the word-form strings they select. | medium |
| `DmsgText_FindFirstTypeByteInText` | 0x102586D0 | 18 | yes | - | Returns the first control byte of the node's text. | low |
| `DmsgText_GetDataPtr` | 0x102586F0 | 4 | yes | - | Returns the source pointer stored at offset 4 of the table. | low |
| `DmsgText_FormatTextAtC` | 0x10258740 | 35 | yes | - | Formats the node's text at +0xC into an output buffer. | low |
| `DmsgText_IsInSjisSet` | 0x10258990 | 95 | yes | - | Reports whether the string's first character is in a Shift-JIS character set. | medium |
| `DmsgText_GetText14` | 0x10258AD0 | 8 | yes | - | Returns the node's text at +0x14. | medium |
| `DmsgText_PickFormString2` | 0x10258D00 | 106 | yes | - | Selects a string from a second set of fixed tables. | low |
| `DmsgText_SelectQuantifierForm` | 0x10258D70 | 131 | yes | - | Selects a quantifier word form from the argument values. | low |
| `DmsgText_GetSolchForm` | 0x10258E10 | 41 | yes | - | Returns one of three word forms (the third "solch...") by an index. | low |
| `DmsgText_SelectNounForm` | 0x10258E50 | 121 | yes | - | Selects a noun form from a table by the argument values. | low |
| `DmsgText_GetQuantifierByIndex` | 0x10258ED0 | 39 | yes | - | Returns the quantifier string for an index from 0 to 2. | low |
| `DmsgText_SelectAdjectiveForm` | 0x10258F00 | 96 | yes | - | Selects an adjective form from the argument values. | low |
| `DmsgText_SelectGenderForm` | 0x10258F60 | 56 | yes | - | Selects a gendered form from the argument values. | low |
| `DmsgText_ClearListHeader` | 0x102590F0 | 13 | yes | - | Clears a node list's three header fields. | low |
| `DmsgText_Append` | 0x10259100 | 33 | yes | - | Appends a node to the end of a text list. | medium |
| `DmsgText_IsEmpty` | 0x10259130 | 10 | yes | - | Reports whether a text list has no nodes. | medium |
| `DmsgText_FindNextTyped` | 0x10259150 | 35 | yes | - | Finds the next node of a non-empty type after the given node. | low |
| `DmsgText_AppendNodeType2` | 0x10259180 | 72 | yes | - | Appends a type-2 node holding a value to a text list. | low |
| `DmsgText_AppendString` | 0x102593F0 | 102 | yes | - | Appends a string node to a text list. | medium |
| `DmsgText_AppendValueNode` | 0x10259460 | 218 | yes | - | Appends a value node that takes its value from an object. | low |
| `DmsgText_ComposeTextA` | 0x10259990 | 1063 | yes | - | Builds the text of a message template into a string buffer, choosing word forms by the values (first form set). | low |
| `DmsgText_DeleteNodesA` | 0x10259DE0 | 48 | yes | - | Deletes all nodes of a template list. | low |
| `DmsgText_IsTypeTwoZero` | 0x1025A580 | 29 | yes | - | Reports whether a type is 2 and a flag is clear. | low |
| `DmsgText_GetFormById` | 0x1025A5A0 | 110 | yes | - | Returns the text form selected by a type and two flags. | low |
| `DmsgText_GetFormAlt` | 0x1025A610 | 176 | yes | - | Returns the alternative text form selected by a type and two flags. | low |
| `DmsgText_GetSuffixByFlag` | 0x1025A6C0 | 33 | yes | - | Returns one of two suffix strings selected by a flag. | low |
| `DmsgText_GetEntryById` | 0x1025A6F0 | 60 | yes | - | Returns the text entry for an id from 9 to 11. | low |
| `DmsgText_GetPrefixByFlags` | 0x1025A730 | 47 | yes | - | Returns the prefix string selected by three flags. | low |
| `DmsgText_GetPrefixByFlags2` | 0x1025A760 | 148 | yes | - | Returns the prefix string selected by a type and three flags. | low |
| `DmsgText_ClearHead` | 0x1025A810 | 13 | yes | - | Clears a text list's head, tail and count. | low |
| `DmsgText_DeleteNodesB` | 0x1025A820 | 48 | yes | - | Deletes all nodes of a template list. | low |
| `DmsgText_AppendNode` | 0x1025A860 | 33 | yes | - | Appends a node to the end of a text list. | medium |
| `DmsgText_FindNextTyped9` | 0x1025A890 | 35 | yes | - | Finds the next node of a non-empty type, other than 9, after the given node. | low |
| `DmsgText_ContainsChar` | 0x1025A8C0 | 104 | yes | - | Reports whether the first character of the argument occurs in the reference string. | medium |
| `DmsgText_BuildNodeString` | 0x1025A930 | 337 | yes | - | Builds the display string for a text node and reports whether it should be shown. | low |
| `DmsgText_HasNoHead` | 0x1025AA90 | 10 | yes | - | Reports whether a text list has no head. | low |
| `DmsgText_ComposeTextB` | 0x1025AAA0 | 971 | yes | - | Builds the text of a message template into a string buffer (second form set). | low |
| `DmsgText_AppendStringNode` | 0x1025AEF0 | 186 | yes | - | Appends a string node to a text list, with a special node for leading spaces. | medium |
| `DmsgText_AppendIdString` | 0x1025AFB0 | 133 | yes | - | Appends a node holding an id and a string to a text list. | low |
| `DmsgText_LinkNode` | 0x1025B100 | 95 | yes | - | Links a node into a text list and fills the pending values of the matching nodes. | medium |
| `DmsgText_AppendTypeTwo` | 0x1025B1E0 | 72 | yes | - | Appends a type-2 node holding a value to a text list. | low |
| `DmsgText_SelectTableByLanguage` | 0x1025B4F0 | 95 | yes | - | Selects the language's table of file numbers. | medium |
| `Scene_GetTableValue` | 0x1025B560 | 54 | yes | - | Returns the scene-specific table value for an index. | low |
| `Scene_GetMenuFrameName` | 0x1025B5A0 | 60 | yes | - | Returns the menu frame name for an index in the current scene. | low |
| `DmsgText_CopyWithoutMarker` | 0x1025B5E0 | 158 | yes | - | Copies a string up to a length, dropping the marker byte 0x15. | low |
| `DmsgText_CountChars` | 0x1025B680 | 58 | yes | - | Counts the characters in a string up to a byte length, ignoring markers. | low |
| `DmsgText_WrapLine` | 0x1025B6C0 | 1078 | yes | - | Cuts the next line of a text to the width that fits, by the language's break rules. | low |
| `DmsgText_HasKnownPrefix` | 0x1025BB00 | 85 | yes | - | Reports whether a string starts with one of the known two-byte prefixes. | low |
| `DmsgText_IsDashNotDigit` | 0x1025BB60 | 32 | yes | - | Reports whether a string starts with a dash that is not followed by a digit. | medium |
| `DmsgText_FindPrefixEntry` | 0x1025BB80 | 89 | yes | - | Finds the table entry whose text starts the given string and returns its length. | low |
| `DmsgText_FindMarker` | 0x1025BDE0 | 63 | yes | - | Returns the offset of the first marker byte in a string, or -1. | low |
| `DmsgText_IsWrapBreak` | 0x1025BE20 | 83 | yes | - | Tests whether a character is a line break or the 7 control code. | low |
| `DmsgText_ConvertCharByLanguage` | 0x1025BFB0 | 258 | yes | - | Converts a character by the current language's rules. | low |
| `DmsgText_WrapSjisAt` | 0x1025C0F0 | 75 | yes | - | Wraps a Shift-JIS string at a byte limit and returns the wrapped length. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Gfx_DrawSpriteAlphaTested` calls `CYyIcon::DrawSubRect`
- `DmsgText_InvertBytes` calls nothing directly
- `DmsgText_SwapEndianPair` calls `ByteSwap_ByteSwap32`
- `DmsgText_GetEntryPtr` calls nothing directly
- `DmsgText_GetCellData` calls nothing directly
- `DmsgText_Align4` calls nothing directly
- `DmsgText_IsNotHashOrDot` calls nothing directly
- `DmsgText_GetWord40` calls nothing directly
- `DmsgText_ComputeTotalSize` calls `DmsgText_GetWord40`, `DmsgText_GetCellData`, `DmsgText_IsNotHashOrDot`, `DmsgText_Align4`
- `DmsgText_Clone` calls `DmsgText_ComputeTotalSize`, `Allocator_Generic`, `DmsgText_GetWord40`, `DmsgText_GetCellData`, `DmsgText_IsNotHashOrDot`, `DmsgText_Align4`
- `DmsgText_GetDataOrDefault` calls nothing directly
- `DmsgText_GetDwordEntry` calls nothing directly
- `DmsgText_GetDMsgTable` calls nothing directly
- `DmsgText_CallFreeData` calls `DmsgText_FreeData`
- `DmsgText_FreeData` calls `operator_delete`
- `DmsgText_GetRowBase` calls nothing directly
- `DmsgText_GetCell` calls `DmsgText_GetDataOrDefault`, `DmsgText_GetRowBase`, `DmsgText_GetEntryPtr`
- `DmsgText_GetDwordCell` calls `DmsgText_GetRowBase`, `DmsgText_GetDwordEntry`
- `DmsgText_GetCellCol0` calls `DmsgText_GetCell`
- `DmsgText_Assign` calls `DmsgText_Bind`
- `DmsgText_Bind` calls `game_10257310`, `DmsgText_InvertBytes`, `DmsgText_SwapEndianPair`, `game_102573E0`
- `DmsgText_GetRowCount` calls nothing directly
- `DmsgText_IsBound` calls nothing directly
- `DmsgText_Clear` calls nothing directly
- `DmsgText_BindSource` calls `game_10257310`
- `DmsgText_GetRowBytes` calls nothing directly
- `DmsgText_BindDataAndMark` calls `DmsgText_BindData`
- `DmsgText_BindData` calls `DmsgText_InvertBytes`, `DmsgText_SwapEndianPair`
- `DmsgText_GetDataField28` calls nothing directly
- `DmsgText_GetStride` calls nothing directly
- `DmsgText_GetRowInfo` calls nothing directly
- `DmsgText_IsTypeOne` calls nothing directly
- `DmsgText_IsTypeRange` calls nothing directly
- `DmsgText_GetFormString` calls nothing directly
- `DmsgText_PickFormString` calls nothing directly
- `DmsgText_FindFirstTypeByte` calls `DmsgText_IsTypeRange`, `Sjis_GetCharByteLen`
- `DmsgText_ExpandFormCodes` calls `DmsgText_IsTypeOne`, `DmsgText_FindFirstTypeByte`, `DmsgText_PickFormString`, `TextInputFiles_Append`, `DmsgText_IsTypeRange`, `DmsgText_GetFormString`, `Sjis_GetCharByteLen`, `TextInputFiles_AppendN`
- `DmsgText_FindFirstTypeByteInText` calls `TextInputFiles_GetCStr`, `DmsgText_FindFirstTypeByte`
- `DmsgText_GetDataPtr` calls nothing directly
- `DmsgText_FormatTextAtC` calls `TextInputFiles_GetCStr`, `DmsgText_ExpandFormCodes`
- `DmsgText_IsInSjisSet` calls `Sjis_GetCharByteLen`
- `DmsgText_GetText14` calls `TextInputFiles_GetCStr`
- `DmsgText_PickFormString2` calls nothing directly
- `DmsgText_SelectQuantifierForm` calls nothing directly
- `DmsgText_GetSolchForm` calls nothing directly
- `DmsgText_SelectNounForm` calls nothing directly
- `DmsgText_GetQuantifierByIndex` calls nothing directly
- `DmsgText_SelectAdjectiveForm` calls nothing directly
- `DmsgText_SelectGenderForm` calls nothing directly
- `DmsgText_ClearListHeader` calls nothing directly
- `DmsgText_Append` calls nothing directly
- `DmsgText_IsEmpty` calls nothing directly
- `DmsgText_FindNextTyped` calls nothing directly
- `DmsgText_AppendNodeType2` calls `Allocator_Generic`, `DmsgText_Append`, `DmsgText_IsEmpty`
- `DmsgText_AppendString` calls `Allocator_Generic`, `TextInputFiles_AssignCStr`, `DmsgText_Append`, `DmsgText_IsEmpty`
- `DmsgText_AppendValueNode` calls `Allocator_Generic`, `TextInputFiles_AssignCStr`, `DmsgText_Append`, `DmsgText_IsEmpty`
- `DmsgText_ComposeTextA` calls `DmsgText_IsEmpty`, `TextInputFiles_Init`, `game_1018D3D0`, `TextInputFiles_Append`, `TextInputFiles_AppendBuf`, `DmsgText_FindNextTyped`, `DmsgText_GetSolchForm`, `DmsgText_SelectNounForm`, `DmsgText_PickFormString`, `DmsgText_SelectAdjectiveForm`, `DmsgText_SelectGenderForm`, `TextInputFiles_AssignWhole`, `TextInputFiles_GetLength`, `DmsgText_GetQuantifierByIndex`, `TextInputFiles_GetCStr`, `DmsgText_PickFormString2`, `DmsgText_SelectQuantifierForm`, `DmsgText_GetDataPtr`, `DmsgText_FindFirstTypeByteInText`, `DmsgText_FormatTextAtC`, `TextInputFiles_Free`
- `DmsgText_DeleteNodesA` calls nothing directly
- `DmsgText_IsTypeTwoZero` calls nothing directly
- `DmsgText_GetFormById` calls `DmsgText_GetCellCol0`
- `DmsgText_GetFormAlt` calls `DmsgText_GetCellCol0`
- `DmsgText_GetSuffixByFlag` calls nothing directly
- `DmsgText_GetEntryById` calls `DmsgText_GetCellCol0`
- `DmsgText_GetPrefixByFlags` calls nothing directly
- `DmsgText_GetPrefixByFlags2` calls nothing directly
- `DmsgText_ClearHead` calls nothing directly
- `DmsgText_DeleteNodesB` calls nothing directly
- `DmsgText_AppendNode` calls nothing directly
- `DmsgText_FindNextTyped9` calls nothing directly
- `DmsgText_ContainsChar` calls `DmsgText_GetCellCol0`, `Sjis_GetCharByteLen`
- `DmsgText_BuildNodeString` calls `DmsgText_FindNextTyped9`, `TextInputFiles_GetCStr`, `DmsgText_GetText14`, `Sjis_IsCodeInSet`, `NetCellFont_LowercaseCharThen1011DAE0`, `Sjis_GetCharByteLen`, `game_10312050`, `DmsgText_ContainsChar`
- `DmsgText_HasNoHead` calls nothing directly
- `DmsgText_ComposeTextB` calls `DmsgText_HasNoHead`, `game_1018D3D0`, `TextInputFiles_Append`, `TextInputFiles_AppendBuf`, `DmsgText_BuildNodeString`, `DmsgText_GetSuffixByFlag`, `DmsgText_GetPrefixByFlags`, `DmsgText_GetPrefixByFlags2`, `DmsgText_FindNextTyped9`, `TextInputFiles_GetCStr`, `DmsgText_GetEntryById`, `DmsgText_IsTypeTwoZero`, `DmsgText_GetFormAlt`, `DmsgText_GetFormById`, `DmsgText_GetText14`, `TextInputFiles_AssignWhole`
- `DmsgText_AppendStringNode` calls `Allocator_Generic`, `TextInputFiles_AssignCStr`, `DmsgText_AppendNode`, `DmsgText_HasNoHead`
- `DmsgText_AppendIdString` calls `DmsgText_HasNoHead`, `Allocator_Generic`, `TextInputFiles_AssignCStr`, `DmsgText_LinkNode`
- `DmsgText_LinkNode` calls `DmsgText_AppendNode`, `DmsgText_HasNoHead`
- `DmsgText_AppendTypeTwo` calls `Allocator_Generic`, `DmsgText_AppendNode`, `DmsgText_HasNoHead`
- `DmsgText_SelectTableByLanguage` calls nothing directly
- `Scene_GetTableValue` calls `DmsgText_SelectTableByLanguage`
- `Scene_GetMenuFrameName` calls nothing directly
- `DmsgText_CopyWithoutMarker` calls `Sjis_GetCharByteLen`
- `DmsgText_CountChars` calls `Sjis_GetCharByteLen`
- `DmsgText_WrapLine` calls `DmsgText_IsWrapBreak`, `Sjis_GetCharByteLen`, `DmsgText_CopyWithoutMarker`, `game_1025BBE0`, `DmsgText_CountChars`, `DmsgText_FindMarker`, `DmsgText_HasKnownPrefix`
- `DmsgText_HasKnownPrefix` calls `game_10312940`
- `DmsgText_IsDashNotDigit` calls nothing directly
- `DmsgText_FindPrefixEntry` calls `game_10312940`
- `DmsgText_FindMarker` calls `Sjis_GetCharByteLen`
- `DmsgText_IsWrapBreak` calls nothing directly
- `DmsgText_ConvertCharByLanguage` calls `game_1011DAA0`, `NetCellFont_UppercaseCharThen1011DAE0`, `Sjis_GetCharByteLen`
- `DmsgText_WrapSjisAt` calls `game_1025BE80`, `DmsgText_ConvertCharByLanguage`, `Sjis_GetCharByteLen`, `Sjis_CopyPrefix`
