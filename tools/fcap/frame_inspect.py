"""frame_inspect.py -- the frame inspector (docs/DEVKIT.md D4): one captured frame's draws by the game's function that made
them, the picture at any draw, and two captures compared (the same scene with a mod on and off).

    python3 frame_inspect.py list CAPTURE.fcap [--d3d8 DLL] [--top 40]
        every call replayed and listed by its call site (the capture's FC_SITE records: the analysed build's address of
        the call's return in FFXiMain.dll), each site named by the function holding it in FFXiMain.pdb's symbol list
        (sdk/dist_pdb/<build>/FFXiMain.pdb.json, the build the capture's header names): draws and primitives per function
    python3 frame_inspect.py at CAPTURE.fcap N OUT.png [--d3d8 DLL]
        the back buffer after the N-th draw (1 = the first), as a PNG (a draw into another target shows once that
        target is drawn in)
    python3 frame_inspect.py compare A.fcap B.fcap OUT.png [--d3d8 DLL]
        both replayed whole and compared (kit/fcap/compare.py: the pixels that differ, and where); the draws per function
        of each, side by side

The replays run kit/fcap/dist/fcap_replay.exe under Wine in a virtual X server, through Wine's d3d8 or, with --d3d8,
the d3d8.dll given (kit/d3d8on11/dist/d3d8.dll). A site whose address no symbol holds is listed as its address. A call
the capture made itself (the start state) has no site. Captures from before FC_SITE (16 Nov) have no sites: every call
is listed under "no site"."""
import argparse, bisect, collections, json, os, re, shutil, struct, subprocess, sys, tempfile
H = os.path.dirname(os.path.abspath(__file__)); ROOT = os.path.join(H, '..', '..')


def replay(cap, d3d8=None, env=None):
    """run the replayer on a copy of the capture; (stdout, folder)"""
    w = tempfile.mkdtemp(prefix='inspect_')
    shutil.copy(os.path.join(H, 'dist', 'fcap_replay.exe'), w); shutil.copy(cap, os.path.join(w, 'c.fcap'))
    e = dict(os.environ, WINEDEBUG='-all', **(env or {}))
    if d3d8:
        shutil.copy(d3d8, os.path.join(w, 'd3d8.dll')); e['WINEDLLOVERRIDES'] = 'd3d8=n'
        x = os.path.join(os.path.dirname(os.path.abspath(d3d8)), 'd8x.exe')
        if os.path.exists(x): shutil.copy(x, w)
    r = subprocess.run(['xvfb-run', '-a', '-s', '-screen 0 1024x768x24', 'wine', 'fcap_replay.exe', 'c.fcap', 'r'], cwd=w,
                       capture_output=True, text=True, timeout=900, env=e)
    return r.stdout, w


def symbols(cap):
    """(starts, entries) of FFXiMain.pdb's function symbols for the build the capture names"""
    ts = struct.unpack_from('<III', open(cap, 'rb').read(12))[2]
    p = next((x for x in (os.path.join(ROOT, 'sdk', 'dist_pdb', '%08X' % ts, 'FFXiMain.pdb.json'),     # (the repository's,
                          os.path.join(ROOT, 'pdb', '%08X' % ts, 'FFXiMain.pdb.json')) if os.path.exists(x)), None)   # the release's)
    if not p: return '%08X' % ts, [], []
    s = sorted((int(x['address'], 16), x.get('size', 0), x['name']) for x in json.load(open(p))['symbols'] if x.get('kind') == 'function')
    return '%08X' % ts, [a for a, _, _ in s], s


def name_of(site, game, starts, syms):
    if not game: return 'outside FFXiMain.dll (0x%08X)' % site if site else 'no site'
    k = bisect.bisect_right(starts, site - 1) - 1          # (the return address is just past the call: the call is in the function)
    if k >= 0 and syms[k][0] <= site - 1 < syms[k][0] + max(syms[k][1], 1): return syms[k][2]
    return '0x%08X' % site


CALL = re.compile(r'^call (\d+) (.*?) site (0x[0-9A-Fa-f]+) game (\d) draw (\d+) prims (\d+)$')


def calls(out):
    """(n, method, site, game, draw, prims) per listed call (a method's name may hold spaces)"""
    return [m.groups() for m in (CALL.match(l.strip()) for l in out.splitlines()) if m]


def by_function(cs, starts, syms):
    t = collections.OrderedDict()
    for c in cs:
        site, game, draw, prims = int(c[2], 16), int(c[3]), int(c[4]), int(c[5])
        e = t.setdefault(name_of(site, game, starts, syms), [0, 0, 0])
        e[0] += 1; e[1] += draw > 0; e[2] += prims
    return t


def main():
    ap = argparse.ArgumentParser(); ap.add_argument('cmd', choices=['list', 'at', 'compare']); ap.add_argument('args', nargs='+')
    ap.add_argument('--d3d8'); ap.add_argument('--top', type=int, default=40)
    a = ap.parse_args()
    if a.cmd == 'list':
        out, w = replay(a.args[0], a.d3d8, {'REPLAY_LIST': '1'}); shutil.rmtree(w, ignore_errors=True)
        build, starts, syms = symbols(a.args[0]); cs = calls(out)
        t = by_function(cs, starts, syms)
        print('%s: build %s, %d calls, %d draws%s' % (a.args[0], build, len(cs), sum(int(c[4]) > 0 for c in cs), '' if syms else ' (no symbol list for this build)'))
        print('%7s %6s %9s  %s' % ('calls', 'draws', 'prims', 'function'))
        for n, (k, v) in enumerate(sorted(t.items(), key=lambda kv: (-kv[1][1], -kv[1][0]))):
            if n >= a.top: print('  ... %d more' % (len(t) - a.top)); break
            print('%7d %6d %9d  %s' % (v[0], v[1], v[2], k))
    elif a.cmd == 'at':
        cap, n, png = a.args[0], int(a.args[1]), a.args[2]
        out, w = replay(cap, a.d3d8, {'REPLAY_STOP': str(n), 'REPLAY_LIST': '1'})
        if 'stopped after draw %d' % n not in out: print('the capture has fewer than %d draws' % n); shutil.rmtree(w, ignore_errors=True); sys.exit(1)
        build, starts, syms = symbols(cap); last = [c for c in calls(out) if int(c[4]) == n][0]
        sys.path.insert(0, H); from compare import png as write_png
        sys.path.insert(0, os.path.join(H, '..', 'd3dprof')); from pictures import load
        _, _, pic = load(os.path.join(w, 'r_replay.pic')); write_png(png, pic)
        print('draw %d (%s, %s prims) by %s: %s' % (n, last[1], last[5], name_of(int(last[2], 16), int(last[3]), starts, syms), png))
        shutil.rmtree(w, ignore_errors=True)
    else:
        A, B, png = a.args[0], a.args[1], a.args[2]
        oa, wa = replay(A, a.d3d8, {'REPLAY_LIST': '1'}); ob, wb = replay(B, a.d3d8, {'REPLAY_LIST': '1'})
        r = subprocess.run([sys.executable, os.path.join(H, 'compare.py'), os.path.join(wa, 'r_replay.pic'), os.path.join(wb, 'r_replay.pic'),
                            '--png', png, '--maxfrac', '1'], capture_output=True, text=True)
        print('pictures: %s (%s: A | B | the difference)' % (r.stdout.strip(), png))
        _, sa, ya = symbols(A); _, sb, yb = symbols(B)
        ta, tb = by_function(calls(oa), sa, ya), by_function(calls(ob), sb, yb)
        print('%6s %6s  %s' % ('draws A', 'B', 'function (where the draws differ)'))
        for k in sorted(set(ta) | set(tb), key=lambda k: -abs(ta.get(k, [0, 0])[1] - tb.get(k, [0, 0])[1])):
            da, db = ta.get(k, [0, 0])[1], tb.get(k, [0, 0])[1]
            if da != db: print('%7d %6d  %s' % (da, db, k))
        shutil.rmtree(wa, ignore_errors=True); shutil.rmtree(wb, ignore_errors=True)


if __name__ == '__main__':
    main()
