"""menu_layouts.py DAT_ROOT HELP_DMSG TITLE_DMSG LAYOUT_DAT...: the game's window layouts (resource chunks of type 0x30), as
FFXiMain.dll reads them (analysed build 6A995428, disassembly; docs/DATA_FILES.md section 4). Prints JSON.
- 0x1011B010: 16 bytes name (to +0x46), 16 bytes header (byte 1 = item count), then the frame record (0x1011B3B0) and
  the items (0x1011B6B0, each in a 0x14-byte slot); the stream moves on by each record's own length (its first short).
- A record: +2 x, +4 y, +0xA width, +0xC height (0x1011B077..0x1011B0A5); +0x13 anchor and +0x17 "no anchor"
  (0x1011A9AF..0x1011A9E5, the placement, which takes this record through Menu_FindItemByNameAt1C and the frame at +8);
  parts at +0x20, 0x14 bytes each (two shorts, a 16-byte shape name), their count at +0x14 (frame) / +0x1B (item);
  then two ASCII numbers whose lengths are +0x15/+0x16 (frame) or +0x1D/+0x1E (item): rows of message table 14 and 13
  (TargetMenu_GetMessage 0x10152F20; a negative number means none, 0x1011B57A).
- Message table 14 is language-table entry 12 and table 13 entry 13 (the table at 0x10371DA8 and
  TargetMenu_LoadAllMessageTables 0x10153C10).
Game files never enter the repository."""
import struct,sys,os,json
sys.path.insert(0,os.path.dirname(os.path.abspath(__file__))); import dmsg
def walk(d):
    o=0
    while o+16<=len(d):
        w=struct.unpack_from('<I',d,o+4)[0]; sz=((w>>7)&0x7ffff)*16
        if sz<16: break
        yield o,w&0x7f,d[o+16:o+sz]; o+=sz
def texts(rec,p,n1,n2):   # two ASCII numbers, each n bytes + 1 (0x1011B56D..0x1011B5CD)
    out=[]
    for n in (n1,n2):
        s=rec[p:p+n] if n else b''; p+=n+1 if n else 1
        try: out.append(int(s.split(b'\0')[0]) if n else None)
        except ValueError: out.append(None)
    return out
def frame(rec,cnt_off,t1_off):
    nparts=rec[cnt_off]; p=0x20; parts=[]
    for i in range(nparts):
        a,b=struct.unpack_from('<hh',rec,p); parts.append((a,b,rec[p+4:p+20].split(b'\0')[0].decode('latin1'))); p+=20
    t=texts(rec,p,rec[t1_off],rec[t1_off+1])
    return parts,t
def decode(d):
    out=[]
    for o,t,data in walk(d):
        if t!=0x30: continue
        name=data[:16].decode('latin1'); hdr=data[16:32]; nitems=hdr[1]; p=32
        rec=data[p:]; L=struct.unpack_from('<h',rec,0)[0]
        x,y,u6,u8,w,h=struct.unpack_from('<hhhhhh',rec,2)
        parts,(help_,t13)=frame(rec,0x14,0x15)
        win={'name':name,'x':x,'y':y,'w':w,'h':h,'anchor_13':rec[0x13],'byte_17':rec[0x17],'help':help_,'text13':t13,'items':[]}
        p+=L
        for i in range(nitems):
            r=data[p:]; Li=struct.unpack_from('<h',r,0)[0]
            ip,(ih,i13)=frame(r,0x1b,0x1d)
            win['items'].append({'help':ih,'text13':i13}); p+=Li
        out.append(win)
    return out
if __name__=='__main__':
    root,m14,m13=sys.argv[1:4]
    R14=dmsg.load(open(m14,'rb').read()); R13=dmsg.load(open(m13,'rb').read())
    def s(R,n):
        if n is None or n<0 or n>=len(R): return None   # the code skips a negative number (jl at 0x1011B57A)
        c=dmsg.cell(R[n],0); return c.decode('cp932','replace') if c is not None else None
    allw=[]
    for f in sys.argv[4:]:
        for wdef in decode(open(os.path.join(root,f),'rb').read()):
            wdef['file']=f; wdef['help_text']=s(R14,wdef['help']); wdef['text13_text']=s(R13,wdef['text13'])
            for it in wdef['items']: it['help_text']=s(R14,it['help']); it['text13_text']=s(R13,it['text13'])
            allw.append(wdef)
    json.dump(allw,sys.stdout,indent=1,ensure_ascii=False)
