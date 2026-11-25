"""dmsg.py FILE [N]: the game's message files ("d_msg"), read as FFXiMain.dll reads them (analysed build 6A995428, tree/src/DmsgText.cpp):
- DmsgText_Bind (0x102579B0): magic "d_msg" (compared with 0x1033CE74), +8 u16 1 (other values are byte-swapped; 0x10 is
  another layout, not read here), +0xA u16 1 = every byte inverted, +0xC u16 3 and +0xE u16 0 (else the file is refused),
  +0x1C index size (0: rows of fixed size +0x20), +0x28 row count; the index of {offset, length} pairs at +0x40, the rows after it.
- DmsgText_GetEntryPtr (0x102574F0): a row is u16 count, then per cell {u32 offset, u32 type}; a cell of type 0 whose first
  short is 1 has its text at +0x1C.
Text is printed as cp932 (the Japanese files); how the other languages' bytes map to characters is not read here.
Game files never enter the repository: point FILE at a local copy."""
import struct,sys
def load(d):
    if d[:6]!=b'd_msg\0': return None
    fmt,inv,k,z=struct.unpack_from('<4H',d,8)
    if fmt!=1 or k!=3 or z!=0: return ('unsupported',fmt,inv,k,z)
    idx,stride,rows=struct.unpack_from('<I I',d,0x1c)+(struct.unpack_from('<I',d,0x28)[0],)
    def iv(b): return bytes(x^0xff for x in b) if inv==1 else b
    out=[]
    if idx:
        tab=iv(d[0x40:0x40+rows*8]); base=0x40+rows*8
        for r in range(rows):
            off,ln=struct.unpack_from('<II',tab,r*8); out.append(iv(d[base+off:base+off+ln]))
    else:
        for r in range(rows): out.append(iv(d[0x40+r*stride:0x40+(r+1)*stride]))
    return out
def cell(row,c):
    if len(row)<2: return None
    n=struct.unpack_from('<H',row,0)[0]
    if c>=n: return None
    off,typ=struct.unpack_from('<II',row,4+8*c)
    if typ!=0 or off+0x1c>len(row) or struct.unpack_from('<h',row,off)[0]!=1: return None
    s=row[off+0x1c:]; s=s[:s.index(0)] if 0 in s else s
    return s
if __name__=='__main__':
    d=open(sys.argv[1],'rb').read(); R=load(d)
    print(type(R), len(R) if isinstance(R,list) else R)
    if isinstance(R,list):
        for i in range(int(sys.argv[2]) if len(sys.argv)>2 else 10):
            c=cell(R[i],0); print(i, c.decode('cp932','replace') if c is not None else None)
