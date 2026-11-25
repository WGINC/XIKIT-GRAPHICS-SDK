"""spw_decode.py IN.spw OUT.wav: a "SeWave" sound file to a WAV, decoded as FFXiMain.dll decodes it (analysed build
6A995428, disassembly; docs/AUDIO.md section 4):
- the header (0x1024A7A0): +0 "SeWave", +8 the file's size (checked on a file, not read in the code), byte +0x2A channels,
  byte +0x2B bits per sample, sample rate (+0x1C + +0x20) & 0x7FFFFFFF;
- the data from +0x30 (checked on a file) in blocks of 9 bytes, one block per channel in turn (0x10246AB0, its mono path
  at 0x10246AF1 and its stereo path at 0x10246B98): a header byte (high nibble: one of the five coefficient pairs at
  0x10388BF0; low nibble: a shift), then 8 bytes of two 4-bit samples each, low nibble first:
  (nibble << 12 as 16 bits) >> shift + (c0 * s1 + c1 * s2) >> 6, each channel with its own last two samples; no clamp.
- not done here: 0x10246A70, which first combines a block with the words of a table at the decoder object's +8 (when
  it has one; the viewer's files decode without it).
Game files never enter the repository."""
import struct, sys, wave
C = [(0, 0), (60, 0), (115, -52), (98, -55), (122, -60)]
def s16(v): return ((v & 0xFFFF) ^ 0x8000) - 0x8000
def main(src, dst):
    d = open(src, 'rb').read()
    if d[:6] != b'SeWave': raise SystemExit('spw_decode: not a SeWave file')
    ch, bits = d[0x2A], d[0x2B]
    rate = (struct.unpack_from('<I', d, 0x1C)[0] + struct.unpack_from('<I', d, 0x20)[0]) & 0x7FFFFFFF
    data = d[0x30:]; nb = len(data) // 9
    st = [[0, 0] for _ in range(ch)]; outs = [[] for _ in range(ch)]
    for i in range(nb):
        c = i % ch; b = data[i * 9:i * 9 + 9]; f, sh = b[0] >> 4, b[0] & 15
        if f > 4: raise SystemExit('spw_decode: block %d has filter %d (the table holds 5)' % (i, f))
        c0, c1 = C[f]; s = st[c]
        for byte in b[1:]:
            for nib in (s16(byte << 12), s16((byte & 0xF0) << 8)):
                v = (nib >> sh) + ((c0 * s[0] + c1 * s[1]) >> 6); s[1] = s[0]; s[0] = v
                outs[c].append(max(-32768, min(32767, v)))
    n = min(len(o) for o in outs)
    w = wave.open(dst, 'wb'); w.setnchannels(ch); w.setsampwidth(bits // 8); w.setframerate(rate)
    w.writeframes(b''.join(struct.pack('<' + 'h' * ch, *(outs[c][i] for c in range(ch))) for i in range(n))); w.close()
    print('spw_decode: %s: %d channels, %d bits, %d Hz, %d frames (%.2f s)' % (dst, ch, bits, rate, n, n / rate))
if __name__ == '__main__': main(sys.argv[1], sys.argv[2])
