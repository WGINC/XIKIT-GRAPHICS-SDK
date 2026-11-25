"""spw_decode.py IN OUT.wav: a sound ("SeWave", the game's se*.spw) or music ("BGMStream", music*.bgw) file to a WAV,
decoded as FFXiMain.dll decodes it (analysed build 6A995428, disassembly; docs/AUDIO.md sections 3 and 4).

- a SeWave header (0x1024A7A0): +0 "SeWave", +8 the file's size (checked on a file, not read in the code), byte +0x2A
  channels, byte +0x2B bits per sample, sample rate (+0x1C + +0x20) & 0x7FFFFFFF; the data from +0x30 (checked on a
  file) in blocks of 9 bytes.
- a BGMStream header (0x1024AFC0, 0x10246D30; the stream object holds it at +8): +0xC the format (only 0 is decoded
  here), +0x18 the length in block rows, +0x1C the loop start in block rows (negative: no loop), sample rate
  (+0x20 + +0x24) & 0x7FFFFFFF, +0x28 the data offset, byte +0x2E channels, byte +0x2F the block parameter: a block is
  (+0x2F >> 1) + 1 bytes (0x10246EA1..0x10246EB0).
- the decode (0x10246AB0, its mono path at 0x10246AF1 and its stereo path at 0x10246B98): one block per channel in
  turn; a header byte (high nibble: one of the five coefficient pairs at 0x10388BF0; low nibble: a shift), then bytes
  of two 4-bit samples each, low nibble first: (nibble << 12 as 16 bits) >> shift + (c0 * s1 + c1 * s2) >> 6, each
  channel with its own last two samples; the game keeps the low 16 bits of each sample (no clamp), and so does this.
- not done here: a music file of format 3 (docs/AUDIO.md section 4: frames combined with a table, then a frame
  decoder that is not read). None of the files checked is format 3; this refuses them.
Game files never enter the repository."""
import struct, sys, wave
C = [(0, 0), (60, 0), (115, -52), (98, -55), (122, -60)]
def s16(v): return ((v & 0xFFFF) ^ 0x8000) - 0x8000
def u32(d, o): return struct.unpack_from('<I', d, o)[0]


def header(d):
    """(kind, channels, rate, data offset, block bytes, rows or None, loop start row or None)"""
    if d[:6] == b'SeWave':
        return 'SeWave', d[0x2A], (u32(d, 0x1C) + u32(d, 0x20)) & 0x7FFFFFFF, 0x30, 9, None, None
    if d[:10] == b'BGMStream\0':
        if u32(d, 0xC) != 0: raise SystemExit('spw_decode: a BGMStream of format %d (only format 0 is read)' % u32(d, 0xC))
        loop = struct.unpack_from('<i', d, 0x1C)[0]
        return ('BGMStream', d[0x2E], (u32(d, 0x20) + u32(d, 0x24)) & 0x7FFFFFFF, u32(d, 0x28), (d[0x2F] >> 1) + 1,
                u32(d, 0x18), loop if loop >= 0 else None)
    raise SystemExit('spw_decode: neither a SeWave nor a BGMStream file')


def decode(d):
    kind, ch, rate, off, bb, rows, loop = header(d)
    if not 1 <= ch <= 8: raise SystemExit('spw_decode: %d channels' % ch)
    nb = (len(d) - off) // bb
    if rows is not None: nb = min(nb, rows * ch)     # the game stops at +0x18 rows
    nb -= nb % ch
    st = [[0, 0] for _ in range(ch)]; outs = [[] for _ in range(ch)]; wrapped = 0
    for i in range(nb):
        c = i % ch; b = d[off + i * bb:off + i * bb + bb]; f, sh = b[0] >> 4, b[0] & 15
        if f > 4: raise SystemExit('spw_decode: block %d has filter %d (the table holds 5)' % (i, f))
        c0, c1 = C[f]; s = st[c]
        for byte in b[1:]:
            for nib in (s16(byte << 12), s16((byte & 0xF0) << 8)):
                v = (nib >> sh) + ((c0 * s[0] + c1 * s[1]) >> 6); s[1] = s[0]; s[0] = v
                if not -32768 <= v <= 32767: wrapped += 1
                outs[c].append(s16(v))
    return kind, ch, rate, outs, loop, (bb - 1) * 2, wrapped


def main(src, dst):
    kind, ch, rate, outs, loop, per_block, wrapped = decode(open(src, 'rb').read())
    n = min(len(o) for o in outs)
    w = wave.open(dst, 'wb'); w.setnchannels(ch); w.setsampwidth(2); w.setframerate(rate)
    w.writeframes(b''.join(struct.pack('<' + 'h' * ch, *(outs[c][i] for c in range(ch))) for i in range(n))); w.close()
    print('spw_decode: %s (%s): %d channels, %d Hz, %d frames (%.2f s)%s; %d samples past 16 bits' % (
        dst, kind, ch, rate, n, n / rate,
        '' if loop is None else ', loops from frame %d (%.2f s)' % (loop * per_block, loop * per_block / rate), wrapped))


if __name__ == '__main__': main(sys.argv[1], sys.argv[2])
