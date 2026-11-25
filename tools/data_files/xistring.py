"""xistring.py FILE [N]: the game's "XISTRING" text files (message tables 8 and 10 are of this kind: TargetMenu_LoadAllMessageTables
0x10153C10 loads language-table entries 8 and 10 through TargetMenu_LoadMessageBlock), read as
TargetMenu_GetEntryPtrByLayout (0x101530C0, tree/src/TargetMenu.cpp) reads them: +0xA short version, +0x24 count; with
version >= 2 the index at +0x38 has 12-byte entries whose first u32 is the text's offset after the index
(+0x38 + count*12); below 2, 4-byte entries whose first short is the offset after a 4-byte index. Text printed as cp932.
Game files never enter the repository."""
import struct, sys
def load(d):
    if d[:8] != b'XISTRING': return None
    ver = struct.unpack_from('<h', d, 0xA)[0]; n = struct.unpack_from('<i', d, 0x24)[0]
    es, base = (12, 0x38 + n * 12) if ver >= 2 else (4, 0x38 + n * 4)
    out = []
    for i in range(n):
        off = struct.unpack_from('<I' if ver >= 2 else '<h', d, 0x38 + i * es)[0]
        s = d[base + off:]; out.append(s[:s.index(0)] if 0 in s else s)
    return out
if __name__ == '__main__':
    R = load(open(sys.argv[1], 'rb').read())
    for i, s in enumerate(R[:int(sys.argv[2]) if len(sys.argv) > 2 else 20]): print(i, s.decode('cp932', 'replace'))
