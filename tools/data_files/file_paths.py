"""file_paths.py TABLE_DIR [NUMBER ...] : the path of each game file number, as FFXiMain.dll builds it.

TABLE_DIR holds the game's VTABLE.DAT, FTABLE.DAT and ROMn tables (VTABLEn.DAT, FTABLEn.DAT, either in TABLE_DIR or in
TABLE_DIR/ROMn/). The game's files never enter the repository: point this at a local copy.

How the game does it (analysed build 6A995428, disassembly; docs/DATA_FILES.md section 1):
- 0x101C3400 reads /FTABLE.DAT into the words at +0xC4 (+0xC8 = its size / 2, the number of files) and /VTABLE.DAT
  into the bytes at +0xBC (when /VTABLE.DAT cannot be read, every byte is 1: 0x101C3599..0x101C35C9). Then for
  n = 2 .. 13 (0x101C361A, loop end 0x101C37C4) it reads /ROMn/FTABLEn.DAT and /ROMn/VTABLEn.DAT and, for every file i
  whose VTABLEn byte is n, sets VTABLE[i] = n and FTABLE[i] = FTABLEn[i] (0x101C3790..0x101C37BE). A ROM whose
  FTABLEn cannot be opened is skipped (0x101C363E).
- XiFileImpl::_getFileName (0x101C3A90), the mode that reads those tables (mode 1, 0x101C3B02): a number at or past
  +0xC8 or with VTABLE byte 0 has no file (-1); byte 1 gives "/ROM/%d/%d.DAT" (0x1037CD00), byte n > 1
  "/ROM%d/%d/%d.DAT" (0x1037CCEC) with n; the two numbers are FTABLE word >> 7 and word & 0x7F.
"""
import os, struct, sys


def _read(d, name, rom=None):
    for p in ([os.path.join(d, name)] + ([os.path.join(d, 'ROM%d' % rom, name)] if rom else [])):
        if os.path.isfile(p):
            return open(p, 'rb').read()
    return None


def load(d):
    f = _read(d, 'FTABLE.DAT')
    if f is None:
        raise SystemExit('file_paths: no FTABLE.DAT in %s (the game stops here too: 0x101C346E)' % d)
    n = len(f) // 2
    ft = list(struct.unpack('<%dH' % n, f[:2 * n]))
    v = _read(d, 'VTABLE.DAT')
    vt = list(v[:n]) + [0] * max(0, n - len(v)) if v is not None else [1] * n
    roms = []
    for r in range(2, 14):
        fr, vr = _read(d, 'FTABLE%d.DAT' % r, r), _read(d, 'VTABLE%d.DAT' % r, r)
        if fr is None or vr is None:
            continue
        roms.append(r)
        frw = struct.unpack('<%dH' % (len(fr) // 2), fr)
        for i in range(min(n, len(vr), len(frw))):
            if vr[i] == r:
                vt[i] = r
                ft[i] = frw[i]
    return vt, ft, roms


def path(vt, ft, num):
    if num < 0 or num >= len(ft) or vt[num] == 0:
        return None
    w = ft[num]
    return '/ROM/%d/%d.DAT' % (w >> 7, w & 0x7F) if vt[num] == 1 else '/ROM%d/%d/%d.DAT' % (vt[num], w >> 7, w & 0x7F)


if __name__ == '__main__':
    vt, ft, roms = load(sys.argv[1])
    print('# %d file numbers; ROM tables read: 1 %s' % (len(ft), ' '.join(map(str, roms))))
    for a in sys.argv[2:]:
        print(a, path(vt, ft, int(a, 0)) or '(no file)')
