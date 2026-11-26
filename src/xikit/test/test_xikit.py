"""test_xikit.py -- the kit end to end under Wine, with the real FFXiMain.dll ($FFXI_DLL) and the built dist/:
host.exe (host.c) maps the game DLL without running it, fakes the device, loads xikit.dll and plays the render
thread. Runs: the game DLL at its analysed base, loaded elsewhere (0x10000000 occupied first), at its base with
profile=1 (d3dprof built in), with a mod (mod_test.cpp, built with sdk/build_mod.sh; function and device hooks) at its
base and loaded elsewhere, the mod reloaded while running (mod_reload=1), capture= and facts=1; and with a real
Direct3D 8 device instead of the fake one (realdev: Wine's d3d8, then kit/d3d8on11's, in a virtual X server); and
sample=2 (native: the native sampler, kit/xisamp, in a Wine prefix with 64-bit Windows).

    python3 test_xikit.py            (after ../build.sh; needs wine)"""
import json, os, re, shutil, subprocess, sys, tempfile
H = os.path.dirname(os.path.abspath(__file__)); DIST = os.path.join(H, '..', 'dist')
subprocess.run(['i686-w64-mingw32-gcc', '-O1', '-Wall', '-o', os.path.join(H, 'host.exe'), os.path.join(H, 'host.c'), '-static-libgcc'], check=True)
bad = 0
# Wine maps images the Windows loader refuses, so check the Windows layout rules here: sections contiguous from
# SizeOfHeaders (rounded to SectionAlignment), SizeOfImage the end of the last one, raw data aligned and in the file
import pefile
for f in ('xikit.dll', 'gfx_recon_ingame.dll'):
    if not os.path.exists(os.path.join(DIST, f)): print('note: no %s in dist (a public kit)' % f); continue
    p = os.path.join(DIST, f); pe = pefile.PE(p); oh = pe.OPTIONAL_HEADER; al = oh.SectionAlignment
    up = lambda n: (n + al - 1) // al * al; s = sorted(pe.sections, key=lambda x: x.VirtualAddress); n = os.path.getsize(p)
    why = [] if s[0].VirtualAddress == up(oh.SizeOfHeaders) else ['first section does not follow the headers']
    why += ['gap or overlap after %s' % a.Name.rstrip(b'\0').decode() for a, b in zip(s, s[1:])
            if a.VirtualAddress + up(a.Misc_VirtualSize) != b.VirtualAddress]
    why += [] if oh.SizeOfImage == s[-1].VirtualAddress + up(s[-1].Misc_VirtualSize) else ['SizeOfImage']
    why += ['raw data of %s' % x.Name.rstrip(b'\0').decode() for x in s
            if x.SizeOfRawData and (x.PointerToRawData % oh.FileAlignment or x.PointerToRawData + x.SizeOfRawData > n)]
    print('%s: %s the Windows loader\'s layout rules%s' % ('ok' if not why else 'FAIL', f, '' if not why else ': ' + '; '.join(why)))
    bad += bool(why)
SDK = os.path.join(H, '..', '..', '..', 'sdk')
MODDLL = os.path.join(tempfile.mkdtemp(prefix='xikit_mod_'), 'mod_test.dll')
# the mod forks SetColor: fork.py new writes the tree's source of it, unedited
subprocess.run([sys.executable, os.path.join(SDK, 'fork.py'), 'new', 'CXiSkeletonActor::SetColor', os.path.dirname(MODDLL)], check=True)
FORK = os.path.join(os.path.dirname(MODDLL), 'CXiSkeletonActor__SetColor.fork.cpp')
subprocess.run([os.path.join(SDK, 'build_mod.sh'), MODDLL, os.path.join(H, 'mod_test.cpp'), FORK], check=True)
MODDLL2 = os.path.join(os.path.dirname(MODDLL), 'mod_test2.dll')          # the "rebuilt" mod of the reload run
subprocess.run([os.path.join(SDK, 'build_mod.sh'), MODDLL2, os.path.join(H, 'mod_test.cpp'), FORK, '--', '-DMOD_GEN=2'], check=True)
r = subprocess.run([sys.executable, os.path.join(SDK, 'fork.py'), 'gate', FORK, '--trials', '20'], capture_output=True, text=True)
print(r.stdout.strip(), r.stderr.strip()[-1500:])
ok = r.returncode == 0 and ': PASS;' in r.stdout
print('%s: fork.py gate: the unedited fork, compiled as the mod compiles it, PASSes against the game\'s SetColor' % ('ok' if ok else 'FAIL')); bad += not ok
for src in ('examples/overlay.cpp', 'examples/scene_tint.cpp', 'template/my_mod.cpp'):     # the SDK's example and template build (not run here:
    subprocess.run([os.path.join(SDK, 'build_mod.sh'), os.path.join(os.path.dirname(MODDLL), os.path.basename(src) + '.dll'),
                    os.path.join(SDK, src)], check=True)          # the host's fake device has Present only)
# (25 Nov) toolhook_*: another tool's jump at Command_RunLine first (host.c fake_tool_form), mod_cmd.dll's chat command
# in front of it; _pub_: with the public kit's fingerprint manifests (kit/install/public_manifest.py), as gobbiefix ships
CMDDLL = os.path.join(os.path.dirname(MODDLL), 'mod_cmd.dll')
subprocess.run([os.path.join(SDK, 'build_mod.sh'), CMDDLL, os.path.join(H, 'mod_cmd.cpp')], check=True)
TOOL_MODES = tuple('toolhook_' + f for f in ('e9', 'e990', 'ff25', 'pushret', 'bad', 'pub_e9', 'pub_e990', 'pub_ff25', 'pub_pushret', 'pub_bad'))
CHAINDLL = os.path.join(os.path.dirname(MODDLL), 'mod_chain.dll')          # the chain run's second mod (API 5)
subprocess.run([os.path.join(SDK, 'build_mod.sh'), CHAINDLL, os.path.join(H, 'mod_chain.cpp')], check=True)
STATEDLL = os.path.join(os.path.dirname(MODDLL), 'mod_state.dll')            # the staterun's mod (xistate's record, player, zone readers)
subprocess.run([os.path.join(SDK, 'build_mod.sh'), STATEDLL, os.path.join(H, 'mod_state.cpp')], check=True)
FAULTDLL = os.path.join(os.path.dirname(MODDLL), 'mod_fault.dll')          # the modfault run's mod (Prishe P4: a mod that faults stays alone)
subprocess.run([os.path.join(SDK, 'build_mod.sh'), FAULTDLL, os.path.join(H, 'mod_fault.cpp')], check=True)
FACTS = os.path.join(os.path.dirname(MODDLL), 'xikit_facts.txt')
# a facts file is in the analysed build's numbering, with its bytes: made from the analysed DLL ($FFXI_DLL_6A995428
# when the run is on another build). On a build where a site's code moved and its bytes hold a moved address (the
# switch's `jmp [reg*4 + table]`), the kit refuses that site (docs/KIT.md, build translation): expected there.
_an = os.environ.get('FFXI_DLL_6A995428', os.environ['FFXI_DLL'])
subprocess.run([sys.executable, os.path.join(H, '..', '..', '..', 'pipeline', 'fact_sites.py'), 'sites', FACTS, '0x10009716', '0x10009736',
                '--out', '0x10027C7A,0x10027C94', '--jmp', '0x101AFB56'], check=True, env=dict(os.environ, FFXI_DLL=_an))
import pefile as _pe1
_ts1 = '%08X' % _pe1.PE(os.environ['FFXI_DLL'], fast_load=True).FILE_HEADER.TimeDateStamp
_bj1 = os.path.join(H, '..', 'builds', _ts1 + '.json')
SWITCH_MOVED = os.path.exists(_bj1) and any(int(lo, 16) <= 0x101AFB56 < int(hi, 16) and dd for lo, hi, dd in json.load(open(_bj1))['ranges'])
if _ts1 != '6A995428' and 'FFXI_DLL_6A995428' not in os.environ:   # (20 Nov: the cause of a misleading kind-jmp FAIL)
    print('note: build %s and no FFXI_DLL_6A995428: the facts file was made from this build\'s DLL, not the analysed one, so the '
          'facts mode\'s kind-jmp check cannot pass; set FFXI_DLL_6A995428 to the analysed DLL' % _ts1)
# host.exe under wine (and xvfb-run): its own process group, so a run past the timeout can be stopped whole (killing
# only xvfb-run leaves wine holding the output pipe). On a timeout what it printed is kept (host.c's stdout is
# unbuffered: its last line is the last check it reached), with the end of xikit.log and the folder's files: the
# evidence of where it stopped. The mode counts as failed and the later modes still run.
def run_host(cmd, d, env, mode, timeout=600):
    import signal
    p = subprocess.Popen(cmd, cwd=d, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, env=env, start_new_session=True)
    try:
        out, err = p.communicate(timeout=timeout)
        return subprocess.CompletedProcess(cmd, p.returncode, out, err)
    except subprocess.TimeoutExpired:
        try: os.killpg(p.pid, signal.SIGKILL)
        except ProcessLookupError: pass
        subprocess.run(['wineserver', '-k'], env=env, capture_output=True, timeout=60)
        try: out, err = p.communicate(timeout=60)
        except subprocess.TimeoutExpired: out, err = '(output not collected: the pipe stayed open after the kill)', ''
    print('== %s: FAIL: host.exe did not finish in %d s; stopped. What it printed:' % (mode, timeout)); print((out or '').strip()[-6000:])
    if (err or '').strip(): print('-- stderr (end):'); print(err.strip()[-2000:])
    lg = os.path.join(d, 'xikit.log')
    if os.path.exists(lg): print('-- xikit.log (end):'); print(open(lg, errors='replace').read()[-4000:].strip())
    print('-- files: ' + ', '.join('%s %d' % (f, os.path.getsize(os.path.join(d, f))) for f in sorted(os.listdir(d)) if os.path.isfile(os.path.join(d, f))))
    print('-- kept for reading: %s' % d)
    return None
ALL_MODES = ('base', 'relocated', 'profile', 'traceblock', 'mod', 'modrel', 'reload', 'chain', 'modfault', 'staterun', 'capture', 'facts', 'ab', 'realdev', 'realdev_ours', 'texmod', 'fxmod', 'cammod', 'ovlmod', 'audmod', 'envmod', 'phomod', 'cfmod', 'uimod', 'ctmod', 'hbmod', 'igmod', 'xtmod', 'fx2mod', 'prishe', 'prishert', 'native', 'measure') + TOOL_MODES
# texmod: sdk/examples/texture_replace through the kit with the game's TexObj_Create/TexObj_Upload on Wine's d3d8
TEXMOD = os.path.join(os.path.dirname(MODDLL), 'texture_replace.dll')
subprocess.run([os.path.join(SDK, 'build_mod.sh'), TEXMOD, os.path.join(SDK, 'examples', 'texture_replace.cpp'),
                os.path.join(SDK, 'examples', 'texture_replace_core.cpp')], check=True)
FXMOD = os.path.join(os.path.dirname(MODDLL), 'effect_comfort.dll')
subprocess.run([os.path.join(SDK, 'build_mod.sh'), FXMOD, os.path.join(SDK, 'examples', 'effect_comfort.cpp'), os.path.join(SDK, 'examples', 'effect_comfort_core.cpp')], check=True)
# Prishe (WGINC/Prishe, a separate repository): its checkout at PRISHE_SRC, else a sibling folder named prishe; without
# one, the modes prishe and prishert are skipped
PRISHE = os.environ.get('PRISHE_SRC', os.path.join(SDK, '..', '..', 'prishe'))
HAVE_PRISHE = os.path.isfile(os.path.join(PRISHE, 'core', 'prishe_core.cpp'))
PRIMOD = os.path.join(os.path.dirname(MODDLL), 'prishe_probe.dll')   # Prishe, phase 0 (probe/)
if HAVE_PRISHE: subprocess.run([os.path.join(SDK, 'build_mod.sh'), PRIMOD, os.path.join(PRISHE, 'probe', 'prishe_probe.cpp')], check=True)
else: print('note: no Prishe checkout at %s (set PRISHE_SRC): modes prishe and prishert skipped' % PRISHE)
PRTMOD = os.path.join(os.path.dirname(MODDLL), 'prishe.dll')         # Prishe's runtime (runtime/)
if HAVE_PRISHE:                        # with Prishe's own build.sh (the in-game panel too, when this SDK has xiimgui)
    subprocess.run([os.path.join(PRISHE, 'build.sh'), os.path.dirname(MODDLL)], check=True, env=dict(os.environ, XIKIT_SDK=os.path.abspath(SDK)))
def prishert_files(d):                 # what host.c's prishert_run expects (its comment)
    for rel, s in (('ROM/1/2.DAT', 'orig2'), ('ROM/1/3.DAT', 'orig3'), ('prishe/packs/a_one/files/ROM/1/2.DAT', 'packA'),
                   ('prishe/packs/b_two/files/rom/1/2.dat', 'packB'), ('prishe/packs/c_off/files/ROM/1/3.DAT', 'packC')):
        os.makedirs(os.path.dirname(os.path.join(d, rel)), exist_ok=True); open(os.path.join(d, rel), 'w').write(s)
    for f, n in (('a_one', 'One'), ('b_two', 'Two'), ('c_off', 'Off')):
        open(os.path.join(d, 'prishe', 'packs', f, 'prishe.json'), 'w').write('{"prishe": 1, "name": "%s"}' % n)
    os.makedirs(os.path.join(d, 'prishe', 'looks'), exist_ok=True)   # (Prishe C1) Alice's slot 2 (body) as 0x2077
    open(os.path.join(d, 'prishe', 'looks', 'mine.json'), 'w').write('{"prishe_look": 1, "name": "Alice", "race": 2, "slots": {"2": 8311}}')
    open(os.path.join(d, 'prishe', 'profile.json'), 'w').write('{"prishe": 1, "packs": [{"folder": "a_one", "priority": 20}, {"folder": "b_two", "priority": 10}, {"folder": "c_off", "enabled": false}]}')
    import struct                          # textures: prtex01 in a_one (16x16, 0xFF112233) and b_two (0xFF445566): a_one wins
    for f, v in (('a_one', 0xFF112233), ('b_two', 0xFF445566)):
        os.makedirs(os.path.join(d, 'prishe', 'packs', f, 'textures'), exist_ok=True)
        open(os.path.join(d, 'prishe', 'packs', f, 'textures', 'prtex01.dds'), 'wb').write(dds32(16, 16, [struct.pack('<I', v) * 256]))
CAMMOD = os.path.join(os.path.dirname(MODDLL), 'camera_view.dll')
subprocess.run([os.path.join(SDK, 'build_mod.sh'), CAMMOD, os.path.join(SDK, 'examples', 'camera_view.cpp')], check=True)
OVLMOD = os.path.join(os.path.dirname(MODDLL), 'file_overlay.dll')
subprocess.run([os.path.join(SDK, 'build_mod.sh'), OVLMOD, os.path.join(SDK, 'examples', 'file_overlay.cpp')], check=True)
AUDMOD = os.path.join(os.path.dirname(MODDLL), 'audio_mix.dll')
subprocess.run([os.path.join(SDK, 'build_mod.sh'), AUDMOD, os.path.join(SDK, 'examples', 'audio_mix.cpp')], check=True)
ENVMOD = os.path.join(os.path.dirname(MODDLL), 'world_light.dll')
subprocess.run([os.path.join(SDK, 'build_mod.sh'), ENVMOD, os.path.join(SDK, 'examples', 'world_light.cpp')], check=True)
PHOMOD = os.path.join(os.path.dirname(MODDLL), 'photo_mode.dll')
subprocess.run([os.path.join(SDK, 'build_mod.sh'), PHOMOD, os.path.join(SDK, 'examples', 'photo_mode.cpp'), os.path.join(SDK, 'examples', 'photo_mode_core.cpp')], check=True)
CFMOD = os.path.join(os.path.dirname(MODDLL), 'color_filter.dll')
subprocess.run([os.path.join(SDK, 'build_mod.sh'), CFMOD, os.path.join(SDK, 'examples', 'color_filter.cpp'), os.path.join(SDK, 'examples', 'color_filter_core.cpp')], check=True)
UIMOD = os.path.join(os.path.dirname(MODDLL), 'ui_layout.dll')
IGMOD = os.path.join(os.path.dirname(MODDLL), 'imgui_panel.dll')     # Dear ImGui through sdk/xiimgui
subprocess.run([os.path.join(SDK, 'build_mod.sh'), IGMOD] + [os.path.join(SDK, *p) for p in (('examples', 'imgui_panel.cpp'), ('examples', 'imgui_panel_ui.cpp'),
               ('xiimgui', 'xiimgui_game.cpp'), ('xiimgui', 'xiimgui_d3d8.cpp'), ('imgui', 'imgui.cpp'), ('imgui', 'imgui_draw.cpp'),
               ('imgui', 'imgui_tables.cpp'), ('imgui', 'imgui_widgets.cpp'))], check=True)
XT = os.path.join(H, '..', '..', 'sessions', 'experimental_tests')     # the in-game test (xitest), smoke-tested here
XTMOD = os.path.join(os.path.dirname(MODDLL), 'xitest.dll'); XTBMOD = os.path.join(os.path.dirname(MODDLL), 'xitest_b.dll')
subprocess.run([os.path.join(SDK, 'build_mod.sh'), XTMOD] + [os.path.join(XT, f) for f in ('xitest.cpp', 'xitest_ui.cpp', 'xitest_sys.cpp')]
               + [os.path.join(SDK, *p) for p in (('xiimgui', 'xiimgui_game.cpp'), ('xiimgui', 'xiimgui_d3d8.cpp'), ('imgui', 'imgui.cpp'), ('imgui', 'imgui_draw.cpp'),
                                                  ('imgui', 'imgui_tables.cpp'), ('imgui', 'imgui_widgets.cpp'))] + ['--', '-I' + os.path.join(SDK, 'imgui')], check=True)
subprocess.run([os.path.join(SDK, 'build_mod.sh'), XTBMOD, os.path.join(XT, 'xitest_b.cpp')], check=True)
HBMOD = os.path.join(os.path.dirname(MODDLL), 'hotbar.dll')
subprocess.run([os.path.join(SDK, 'build_mod.sh'), HBMOD, os.path.join(SDK, 'examples', 'hotbar.cpp'), os.path.join(SDK, 'examples', 'hotbar_core.cpp'), '--', '-lwindowscodecs', '-lole32'], check=True)
# icons for the hotbar test: XIVhotbar2's own (WGINC/XIVhotbar2-Petit_Trois_Edition at XIVHOTBAR_SRC, else a sibling folder)
XIVHB = os.environ.get('XIVHOTBAR_SRC', os.path.join(SDK, '..', '..', 'xivhotbar2-petit_trois_edition'))
CTMOD = os.path.join(os.path.dirname(MODDLL), 'click_target.dll')
subprocess.run([os.path.join(SDK, 'build_mod.sh'), CTMOD, os.path.join(SDK, 'examples', 'click_target.cpp')], check=True)
subprocess.run([os.path.join(SDK, 'build_mod.sh'), UIMOD, os.path.join(SDK, 'examples', 'ui_layout.cpp'), os.path.join(SDK, 'examples', 'ui_layout_core.cpp')], check=True)
def ovl_files(d):
    for rel, s in (('ROM/1/2.DAT', 'orig2'), ('ROM/1/3.DAT', 'orig3'), ('overlay/10_a/ROM/1/2.DAT', 'packA'), ('overlay/20_b/ROM/1/2.DAT', 'packB')):
        os.makedirs(os.path.dirname(os.path.join(d, rel)), exist_ok=True); open(os.path.join(d, rel), 'w').write(s)
def dds32(w, h, levels):                # A8R8G8B8 DDS (dds.h): levels = [bytes of each level]
    import struct
    hd = [0] * 31; hd[0] = 124; hd[1] = 0x100F | (0x20000 if len(levels) > 1 else 0); hd[2] = h; hd[3] = w; hd[4] = w * 4
    hd[6] = len(levels); hd[18] = 32; hd[19] = 0x41; hd[21] = 32; hd[22:26] = [0xFF0000, 0xFF00, 0xFF, 0xFF000000]; hd[26] = 0x1000
    return b'DDS ' + struct.pack('<31I', *hd) + b''.join(levels)
def texmod_files(d):                    # what host.c's texmod_run expects (its comment)
    import struct, zlib
    os.makedirs(os.path.join(d, 'textures'))
    col = lambda w, h, f: b''.join(struct.pack('<I', f(x, y)) for y in range(h) for x in range(w))
    open(os.path.join(d, 'textures', 'trtest01.dds'), 'wb').write(dds32(16, 16, [col(16, 16, lambda x, y: 0xFF010101 if x % 2 == 0 else 0xFFFFFFFF)]))
    src = b''.join(struct.pack('<I', 0xFF000000 | (0x400000 + k * 0x0301)) for k in range(64))      # object 2's pixels
    lv = [col(max(32 >> i, 1), max(32 >> i, 1), lambda x, y: 0xFF020202) for i in range(6)]
    open(os.path.join(d, 'textures', 'trtest02_%08X.dds' % zlib.crc32(src)), 'wb').write(dds32(32, 32, lv))
    open(os.path.join(d, 'textures', 'trtest02.dds'), 'wb').write(b'not a dds: the keyed file must win')
# the measure run's table: the game's import slots from the kit's own xikit_measure.txt, and three call sites in game
# functions the host can run (host.c, measure mode)
def measure_table(d):
    import pefile
    from capstone import Cs, CS_ARCH_X86, CS_MODE_32
    pe = pefile.PE(os.environ['FFXI_DLL'], fast_load=True); base = pe.OPTIONAL_HEADER.ImageBase; img = pe.get_memory_mapped_image()
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    lines = [l for l in open(os.path.join(DIST, 'xikit_measure.txt')) if l.startswith('I ')]
    for f, t in ((0x10027600, 0x10027530), (0x1001E3B0, 0x10026EB0), (0x100142A0, 0x10010D00)):
        site = next(i.address for i in md.disasm(img[f - base:f - base + 32], f) if i.mnemonic == 'call')
        lines.append('S %08X %08X 0 test t%X\n' % (site, t, t))
    open(os.path.join(d, 'xikit_measure.txt'), 'w').writelines(lines)
    slot = {l.split()[3]: l.split()[1] for l in lines if l.startswith('I ')}
    return {'SLOT_SLEEP': slot['Sleep'], 'SLOT_GFA': slot['GetFileAttributesA'], 'SLOT_TGT': slot['timeGetTime'], 'SLOT_DISPATCH': slot['DispatchMessageA'],
            'SLOT_HEAPALLOC': slot['HeapAlloc'], 'SLOT_HEAPFREE': slot['HeapFree']}
# a build whose manifest says !no_swap (some functions changed there) swaps nothing in: the modes that test the
# reconstruction's swaps do not apply; base and relocated check that nothing is swapped, the mod modes that mods work
import pefile as _pe0
_ts0 = '%08X' % _pe0.PE(os.environ['FFXI_DLL'], fast_load=True).FILE_HEADER.TimeDateStamp
_mf0 = os.path.join(DIST, 'xikit_manifest_%s.txt' % _ts0)
NO_SWAP = os.path.exists(_mf0) and any(l.startswith('!no_swap') for l in open(_mf0)) and not any(l.startswith('!swap_set') for l in open(_mf0))   # (!swap_set: flag 32 decides, the rest swaps)
SWAP_MODES = ('profile', 'traceblock', 'capture', 'ab', 'reload')
if NO_SWAP: print('build %s is no_swap: modes %s skipped (they test the reconstruction swapped in)' % (_ts0, ', '.join(SWAP_MODES)))
for mode in [m for m in ALL_MODES if m in os.environ.get('MODES', ' '.join(ALL_MODES)).split() and not (NO_SWAP and m in SWAP_MODES) and (HAVE_PRISHE or m not in ('prishe', 'prishert'))]:
    d = tempfile.mkdtemp(prefix='xikit_')
    for f in ('xikit.dll', 'gfx_recon_ingame.dll', 'xikit_manifest.txt', 'VERSION.txt'):
        if os.path.exists(os.path.join(DIST, f)): shutil.copy(os.path.join(DIST, f), d)   # (a public kit has no gfx_recon_ingame.dll)
    for f in os.listdir(DIST):                                   # the manifests of other builds (build translation)
        if f.startswith('xikit_manifest_'): shutil.copy(os.path.join(DIST, f), d)
    shutil.copy(os.environ['FFXI_DLL'], os.path.join(d, 'FFXiMain.dll')); shutil.copy(os.path.join(H, 'host.exe'), d)
    if mode.startswith('mod') or mode in ('reload', 'chain'): shutil.copy(MODDLL, d)
    if mode in ('reload', 'chain'): shutil.copy(MODDLL2, d)
    if mode == 'chain': shutil.copy(CHAINDLL, d)
    if mode == 'modfault': shutil.copy(MODDLL, d); shutil.copy(FAULTDLL, d)
    if mode == 'staterun': shutil.copy(STATEDLL, d)
    if mode.startswith('toolhook_'):
        shutil.copy(CMDDLL, d)
        if '_pub_' in mode:                      # the public kit's manifests: fingerprints (H...) and J=, no bytes
            for f in os.listdir(d):
                if f.startswith('xikit_manifest'):
                    subprocess.run([sys.executable, os.path.join(H, '..', '..', 'install', 'public_manifest.py'), os.path.join(d, f), os.path.join(d, f)], check=True)
    if mode == 'facts': shutil.copy(FACTS, d)
    if mode == 'texmod': shutil.copy(TEXMOD, d); texmod_files(d)
    if mode in ('fxmod', 'fx2mod'): shutil.copy(FXMOD, d)
    if mode == 'cammod': shutil.copy(CAMMOD, d)
    if mode == 'prishe': shutil.copy(PRIMOD, d)
    if mode == 'prishert': shutil.copy(PRTMOD, d); prishert_files(d)
    if mode == 'ovlmod': shutil.copy(OVLMOD, d); ovl_files(d)
    if mode == 'audmod': shutil.copy(AUDMOD, d)
    if mode == 'envmod': shutil.copy(ENVMOD, d)
    if mode == 'phomod': shutil.copy(PHOMOD, d)
    if mode == 'uimod': shutil.copy(UIMOD, d)
    if mode == 'ctmod': shutil.copy(CTMOD, d)
    if mode == 'igmod': shutil.copy(IGMOD, d)
    if mode == 'xtmod': shutil.copy(XTMOD, d); shutil.copy(XTBMOD, d)
    if mode == 'hbmod':
        shutil.copy(HBMOD, d)
        for rel in ('images/icons/spells/00001.png', 'images/icons/weapons/02.png', 'images/icons/custom/macro.png', 'images/icons/custom/gear3.png'):
            src = os.path.join(XIVHB, rel)
            if os.path.isfile(src):
                os.makedirs(os.path.join(d, 'xiv', os.path.dirname(rel)), exist_ok=True); shutil.copy(src, os.path.join(d, 'xiv', rel))
    if mode == 'cfmod':                           # on kit/d3d8on11 (shader passes); its own kit load off (realdev_ours says why)
        shutil.copy(CFMOD, d); shutil.copy(os.path.join(H, '..', '..', 'd3d8on11', 'dist', 'd3d8.dll'), d)
        with open(os.path.join(d, 'd3d8on11.ini'), 'w') as f: f.write('[d3d8on11]\r\nload_kit=0\r\n')
    env = dict(os.environ, WINEDEBUG='-all')
    cmd = ['wine', 'host.exe', mode]
    if mode.startswith('toolhook_'): env['XT_TOOL_FORM'] = mode.split('_')[-1]; cmd = ['wine', 'host.exe', 'toolhook']
    if mode == 'native':                          # sample=2 starts xisamp_x64.exe: a Wine prefix with 64-bit Windows
        for f in ('xisamp_x64.exe', 'xisamp_arm64.exe'): shutil.copy(os.path.join(DIST, f), d)
        env['WINEPREFIX'] = os.path.join(d, 'pfx64'); subprocess.run(['wineboot', '-i'], env=env, capture_output=True, timeout=600)
    if mode == 'measure':                         # a window for DispatchMessageA: a virtual X server
        env.update(measure_table(d)); cmd = ['xvfb-run', '-a', '-s', '-screen 0 1024x768x24', 'wine', 'host.exe', 'measure']
    if mode in ('texmod', 'fxmod', 'cammod', 'ovlmod', 'audmod', 'envmod', 'phomod', 'cfmod', 'uimod', 'ctmod', 'hbmod', 'igmod', 'xtmod', 'fx2mod', 'prishe', 'prishert'): cmd = ['xvfb-run', '-a', '-s', '-screen 0 1024x768x24', 'wine', 'host.exe', mode]
    if mode == 'cfmod': env['WINEDLLOVERRIDES'] = 'd3d8=n'
    if mode.startswith('realdev'):                # a real D3D8 device: Wine's d3d8, then kit/d3d8on11's (thread mode)
        cmd = ['xvfb-run', '-a', '-s', '-screen 0 1024x768x24', 'wine', 'host.exe', 'realdev']
        if mode == 'realdev_ours':
            shutil.copy(os.path.join(H, '..', '..', 'd3d8on11', 'dist', 'd3d8.dll'), d); env['WINEDLLOVERRIDES'] = 'd3d8=n'
            # load_kit=0: since 22 Nov d3d8.dll loads xikit.dll itself at Direct3DCreate8, before host.exe writes its
            # xikit.ini, so the kit started with its defaults (log_folder=1: the timing file in xikit_logs\, not here).
            # This mode tests the host's own load on our device; d3d8on11's load_kit has its test (test_d3d8on11.py)
            with open(os.path.join(d, 'd3d8on11.ini'), 'w') as f: f.write('[d3d8on11]\r\nload_kit=0\r\n')
    r = run_host(cmd, d, env, mode)
    if r is None: bad += 1; continue
    print('== %s (exit %d)' % (mode, r.returncode)); print(r.stdout.strip())
    if mode in ('base', 'relocated'):           # build translation: the ranges the reconstruction got are the build's own
        import pefile as _pe
        ts = '%08X' % _pe.PE(os.environ['FFXI_DLL'], fast_load=True).FILE_HEADER.TimeDateStamp
        bj = os.path.join(H, '..', 'builds', ts + '.json')
        # the ranges the kit hands on: the build's code and data ranges that moved, sorted (manifest_for_build.py)
        rr = sorted([tuple(x) for x in json.load(open(bj))['ranges'] + json.load(open(bj)).get('data_ranges', []) if x[2]],
                    key=lambda x: int(x[0], 16)) if os.path.exists(bj) else []
        want = [len(rr)]
        for lo, hi, dd in rr: want += [int(lo, 16) - (1 << 32) if int(lo, 16) >= 1 << 31 else int(lo, 16), int(hi, 16), dd]
        got = re.search(r'^xi_shift:(.*)$', r.stdout, re.M)
        got = [int(x) for x in got.group(1).split()] if got else None
        ok = got == want
        print('%s: %s: the reconstruction\'s xi_shift is build %s\'s moved ranges (%s)' % ('ok' if ok else 'FAIL', mode, ts, got)); bad += not ok
    log = open(os.path.join(d, 'xikit.log')).read() if os.path.exists(os.path.join(d, 'xikit.log')) else ''
    if mode == 'base':
        ok = 'kit build: ' + open(os.path.join(DIST, 'VERSION.txt')).readline().strip() in log
        print('%s: xikit.log names the kit\'s build (VERSION.txt line 1)' % ('ok' if ok else 'FAIL')); bad += not ok
    if mode == 'cfmod' and os.path.exists(os.path.join(d, 'd3d8on11.log')): print('-- d3d8on11.log (end) --'); print(open(os.path.join(d, 'd3d8on11.log'), errors='replace').read()[-2500:])
    if mode == 'fx2mod':
        ok = 'effect_comfort: effect spel/fire (0%)' in log
        print('%s: fx2mod: fx_list logged the element\'s path spel/fire and its percent from effects.txt' % ('ok' if ok else 'FAIL')); bad += not ok
        ok = 'effect_comfort: effect efct/wind from file 4321 (0%)' in log
        print('%s: fx2mod: fx_list logged the second element\'s path efct/wind, its file 4321 and its percent from the file: line' % ('ok' if ok else 'FAIL')); bad += not ok
    if mode == 'cfmod':
        m = re.search(r"color_filter: check: the filtered frame's centre is ([0-9a-f-]+)", log)
        v = int(m.group(1), 16) if m and m.group(1) != '-1' else -1
        # (25 Nov) the matrix applies to linear RGB: pure red is (1,0,0) either way; the result is encoded with the sRGB
        # transfer function (IEC 61966-2-1), as the mod's shader does
        enc = lambda l: 0 if l <= 0 else round(255 * (l * 12.92 if l <= 0.0031308 else 1.055 * l ** (1 / 2.4) - 0.055))
        er, eg = enc(0.367322), enc(0.280085)
        ok = v >= 0 and abs((v >> 16) - er) <= 2 and abs(((v >> 8) & 0xFF) - eg) <= 2 and (v & 0xFF) <= 2
        print('%s: cfmod: pure red through the deuteranopia simulation (Machado et al. 2009: 0.367 0.280 -0.012, linear; sRGB-encoded %02x%02x00) is %s in the filtered frame (within 2)' % ('ok' if ok else 'FAIL', er, eg, m.group(1) if m else 'not logged')); bad += not ok
    print('-- xikit.log --'); print('\n'.join(l for l in log.splitlines() if 'swapped ' not in l and 'restored ' not in l)[-3000:])
    if r.returncode != 0 or 'ALL OK' not in r.stdout: bad += 1
    if mode == 'base':
        ok = re.search(r'cpu: CPUID vendor "\w+", brand ".*"; SSE 1', log) is not None and 'machine: ' in log
        print('%s: the environment is logged (CPUID vendor and features, machine and Windows build)' % ('ok' if ok else 'FAIL')); bad += not ok
        ok = re.search(r'compatibility: kernel version \d+\.\d+ build \d+ \(KUSER_SHARED_DATA; the game is told \d+\.\d+\); __COMPAT_LAYER .*; registry layers for .*host\.exe: user .*, machine ', log) is not None
        print('%s: the compatibility layers are logged (the kernel\'s own version, __COMPAT_LAYER, the registry)' % ('ok' if ok else 'FAIL')); bad += not ok
    if mode == 'profile':
        vs = [f for f in os.listdir(d) if f.startswith('xikit_vshader_')]
        r = subprocess.run([sys.executable, os.path.join(H, '..', '..', 'd3dprof', 'vshader.py')] + [os.path.join(d, f) for f in vs], capture_output=True, text=True)
        print(r.stdout.strip(), r.stderr.strip()[-500:])
        ok = len(vs) == 1 and 'v5 <- D3DCOLOR' in r.stdout and 'm4x4 oPos, v0, c0' in r.stdout and 'mov oD0, v5' in r.stdout
        print('%s: the vertex shader was saved and vshader.py decodes its declaration and code' % ('ok' if ok else 'FAIL')); bad += not ok
        sm = [f for f in os.listdir(d) if f.startswith('xikit_samples_')]
        if sm:
            r = subprocess.run([sys.executable, os.path.join(H, '..', '..', 'd3dprof', 'samples.py'), os.path.join(d, sm[0])], capture_output=True, text=True)
            ok = r.returncode == 0 and 'self: where the render thread was' in r.stdout
            print('\n'.join(r.stdout.splitlines()[:8])); print('%s: samples.py reads the samples' % ('ok' if ok else 'FAIL')); bad += not ok
    if mode == 'profile':
        pics = sorted(f for f in os.listdir(d) if f.endswith('.pic') and '_1_f' in f)
        r = subprocess.run([sys.executable, os.path.join(H, '..', '..', 'd3dprof', 'pictures.py')] + [os.path.join(d, f) for f in pics], capture_output=True, text=True)
        print(r.stdout.strip(), r.stderr.strip()[-800:])
        ok = len(pics) == 5 and "beyond what the control shows" in r.stdout and 'control  frame' in r.stdout and '(0.0000%)' in r.stdout
        print('%s: trace_pictures=1 saved frames 6..10 and pictures.py finds the swapped band in the swapped frames only' % ('ok' if ok else 'FAIL')); bad += not ok
    if mode == 'native':
        sys.path.insert(0, os.path.join(H, '..', '..', 'xisamp')); import read as xread
        nc = [f for f in os.listdir(d) if f.startswith('xikit_native_')]
        head, wins = xread.load(os.path.join(d, nc[0])) if nc else ([], [])
        ok = 'sample=2: native sampler started' in log and len(wins) >= 3
        print('%s: sample=2 started xisamp_x64.exe with the render thread; %d windows written' % ('ok' if ok else 'FAIL', len(wins))); bad += not ok
        # the spin (GetColor through the kit's counting stub, count_calls=1: private memory) and the Sleep after it,
        # each under host.exe's calls on the x86 chain
        hostcall = lambda w, xc: any(w.mod(a) and w.mod(a)[2].lower() == 'host.exe' for a in xc)
        spin = sum(c for w in wins for c, eip, xc, *_ in w.rows if hostcall(w, xc) and (not w.mod(eip) or w.mod(eip)[2].lower() in ('ffximain.dll', 'gfx_recon_ingame.dll')))
        nap = sum(c for w in wins for c, eip, xc, *_ in w.rows if hostcall(w, xc) and w.labels.get(eip, ['', '', ''])[2] in ('NtDelayExecution', 'ZwDelayExecution'))
        rel = [h for h in head if h.startswith('# rel 0x')]
        ok = spin > 100 and nap > 1000 and rel   # (the frame read each sample costs samples: 175 to 336 seen under Wine, the old build included)
        print('%s: %d samples in the GetColor loop and %d in the Sleep after it, each under host.exe\'s calls; header %s' % ('ok' if ok else 'FAIL', spin, nap, rel)); bad += not ok
        r = subprocess.run([sys.executable, os.path.join(H, '..', '..', 'xisamp', 'read.py'), os.path.join(d, nc[0])] if nc else ['false'], capture_output=True, text=True)
        ok = r.returncode == 0 and 'x86: the module the x86 code was in' in r.stdout
        print('\n'.join(r.stdout.splitlines()[:14])); print('%s: read.py reads it' % ('ok' if ok else 'FAIL')); bad += not ok
        # the stutter file: the frame counter's address is in the header, and the frame that holds the 2.5 s Sleep
        # (no present while it sleeps) is written with its own samples, most of them in the Sleep
        st = [f for f in os.listdir(d) if f.startswith('xikit_stutters_')]
        _, sw = xread.load(os.path.join(d, st[0])) if st else ([], [])
        big = [w for w in sw if w.ms and w.ms >= 2000]
        snap = sum(c for w in big for c, eip, *_ in w.rows if w.labels.get(eip, ['', '', ''])[2] in ('NtDelayExecution', 'ZwDelayExecution'))
        sall = sum(c for w in big for c, *_ in w.rows)
        ok = 'xikit_stutters' in log and any(h.startswith('# stutters: frame counter at') for h in head) and len(big) == 1 and snap > 0.9 * sall > 0
        print('%s: the stutter file has the Sleep frame (%s ms) with %d of its %d samples in the Sleep; %d blocks in all' % ('ok' if ok else 'FAIL', big[0].ms if big else '-', snap, sall, len(sw))); bad += not ok
    if mode == 'measure':
        sys.path.insert(0, os.path.join(H, '..')); import measure_read
        raw = [f for f in os.listdir(d) if f.startswith('xikit_raw_')]
        R = measure_read.Raw(os.path.join(d, raw[0])) if raw else None
        rs = [x for x in R.samples if x[5] & 1 and x[3] is not None] if R else []
        oth = [x for x in R.samples if not x[5] & 1 and x[3] is not None and R.where(x[3])[:2] == ('module', 'host.exe')] if R else []
        land = sum(1 for x in R.samples if x[4] and R.mland in x[4]) if R else -1
        mono = all(a[1] <= b[1] for a, b in zip(rs, rs[1:]))
        withra = sum(1 for x in rs if x[4])                 # the stack scan ran (ESP inside the TEB's bounds)
        ok = withra > 0.5 * len(rs) and not any(x[5] & 8 for x in rs)
        print('%s: sample=3: %d of %d render-thread samples carry return addresses; none had ESP outside the TEB\'s stack' % ('ok' if ok else 'FAIL', withra, len(rs))); bad += not ok
        ok = len(rs) > 500 and len(oth) > 20 and land == 0 and mono and R.threads
        print('%s: sample=3: %d render-thread samples (frame numbers in order: %s), %d of the other thread in host.exe, %d stacks still holding the kit\'s m_land, %d thread records' % (
            'ok' if ok else 'FAIL', len(rs), mono, len(oth), land, len(R.threads) if R else 0)); bad += not ok
        # the wrapped Sleep the window procedure makes inside DispatchMessageA is outside DispatchMessageA's exclusive time
        pr = open([os.path.join(d, f) for f in os.listdir(d) if f.startswith('xikit_probes_')][0]).read()
        disp = sorted((l.split(',') for l in pr.splitlines() if ',DispatchMessageA,' in l and ',render,' in l), key=lambda r: -int(r[10]))   # the loop's call site (most calls), not the longjmp's
        # (20 Nov) the Sleep the window procedure makes: its row's return address inside m_wndproc (host.exe's symbols).
        # DispatchMessageA's inclusive minus exclusive time is the time of the wrapped calls inside it, that Sleep's: equal
        # to the Sleep's inclusive time but for the one Sleep under the call the longjmp left (its entry dropped), at most
        # the Sleep's longest call. (Before: exclusive under 1% of inclusive, which also held Wine's own dispatch time,
        # 1 to 5.5 ms over 299 calls on one machine, and failed when Wine was slow.)
        import pefile as _pe2
        hx = os.path.join(d, 'host.exe'); hb = _pe2.PE(hx, fast_load=True).OPTIONAL_HEADER.ImageBase
        nm = [l.split() for l in subprocess.run(['i686-w64-mingw32-nm', '-n', hx], capture_output=True, text=True).stdout.splitlines()]
        nm = [(int(a, 16) - hb, n) for a, t, n in (x for x in nm if len(x) == 3) if t in 'tT']
        wp = [(a, nm[i + 1][0]) for i, (a, n) in enumerate(nm[:-1]) if n.split('@')[0] == '_m_wndproc']
        inwp = lambda rt: rt.startswith('module:host.exe+0x') and wp and wp[0][0] <= int(rt.split('+0x')[1], 16) < wp[0][1]
        slp = [r for r in (l.split(',') for l in pr.splitlines() if ',Sleep,' in l and ',render,' in l) if inwp(r[9])]
        dx = float(disp[0][11]) - float(disp[0][12]) if disp else -1
        ok = bool(disp) and len(slp) == 1 and abs(dx - float(slp[0][11])) <= float(slp[0][13]) and 'stale entries dropped 1,' in pr
        print('%s: nesting: DispatchMessageA inclusive %s ms, exclusive %s ms: the %.3f ms between them is the Sleep inside it (%s ms in %s calls, '
              'one under the call the longjmp left); the entry the longjmp left was dropped' % (
            'ok' if ok else 'FAIL', disp[0][11] if disp else '-', disp[0][12] if disp else '-', dx, slp[0][11] if slp else '-', slp[0][10] if slp else '-')); bad += not ok
        env_txt = open([os.path.join(d, f) for f in os.listdir(d) if f.startswith('xikit_env_')][0]).read()
        ok = '[wine] version' in env_txt and 'Sleep(1), 200 calls:' in env_txt and 'timeGetTime steps' in env_txt and ' ns a call' in env_txt
        print('%s: env=1: xikit_env names Wine, the measured Sleep(1) and timeGetTime steps, and call costs' % ('ok' if ok else 'FAIL')); bad += not ok
        # (23 Nov) the display and window lists are off by default (env_windows=0): said so
        ok = 'not listed (env_windows=0' in env_txt
        print('%s: env=1: no USER32 queries from the environment thread by default (said in the file)' % ('ok' if ok else 'FAIL')); bad += not ok
        r = subprocess.run([sys.executable, os.path.join(H, '..', 'measure_read.py'), d, '--measure', os.path.join(d, 'xikit_measure.txt')], capture_output=True, text=True)
        rep = open(os.path.join(d, 'report.md')).read() if os.path.exists(os.path.join(d, 'report.md')) else ''
        ok = r.returncode == 0 and '## Frames' in rep and '## Wrapped calls on the render thread' in rep and '## Samples' in rep and '| Sleep | I | wait |' in rep
        print(r.stderr.strip()[-1500:]); print('%s: measure_read.py writes report.md (frames, wrapped calls, samples)' % ('ok' if ok else 'FAIL')); bad += not ok
        sm = json.load(open(os.path.join(d, 'summary.json'))) if os.path.exists(os.path.join(d, 'summary.json')) else {}
        cr = sm.get('clock_ratio', {}).get('A (+0x04..)')
        ok = cr is not None and abs(cr - 1.0) < 0.03
        print('%s: the clock test\'s arithmetic: a reference moving a tick a frame and a test moving by real time give test / reference = %s' % ('ok' if ok else 'FAIL', cr)); bad += not ok
    if mode == 'facts':
        fc = [f for f in os.listdir(d) if f.startswith('xikit_facts_')]
        out = os.path.join(d, 'game_sp.json')
        r = subprocess.run([sys.executable, os.path.join(H, '..', '..', '..', 'pipeline', 'fact_sites.py'), 'ingest'] + [os.path.join(d, f) for f in fc] + ['--out', out,
                           '--switch', os.path.join(d, 'sw0.json'), '--outs', os.path.join(d, 'outs0.json')], capture_output=True, text=True)   # never data/
        print(r.stdout.strip(), r.stderr.strip()[-800:])
        g = json.load(open(out)) if os.path.exists(out) else {}
        ok = g.get('0x10009716', {}).get('pops') == 4 and g.get('0x10009736', {}).get('pops') == 4
        print('%s: fact_sites.py ingest records both sites with 4 bytes popped' % ('ok' if ok else 'FAIL')); bad += not ok
        r = subprocess.run([sys.executable, os.path.join(H, '..', '..', '..', 'pipeline', 'fact_sites.py'), 'ingest'] + [os.path.join(d, f) for f in fc]
                           + ['--out', out, '--switch', os.path.join(d, 'sw.json'), '--outs', os.path.join(d, 'outs.json')], capture_output=True, text=True)
        sw = json.load(open(os.path.join(d, 'sw.json'))) if os.path.exists(os.path.join(d, 'sw.json')) else {}
        oj = json.load(open(os.path.join(d, 'outs.json'))) if os.path.exists(os.path.join(d, 'outs.json')) else {}
        ok = (sum(sw.get('0x101AFB56', {}).get('targets_seen', {}).values()) == 13 or SWITCH_MOVED) \
            and not any(c['changed'] for c in oj.get('0x10027C94', {}).get('slots', {}).get('arg0', {}).values()) \
            and set(oj.get('0x10027C7A', {}).get('slots', {})) == {'ecx0'}       # its callee takes no stack argument
        print('%s: ingest writes the switch targets seen and the output slots' % ('ok' if ok else 'FAIL')); bad += not ok
    if mode == 'capture':
        # the capture replayed through the gate: the original and the tree's reconstruction run from that call
        xc = [f for f in os.listdir(d) if f.endswith('.xcap')]
        tree_dll = os.path.join(H, '..', '..', '..', 'tree', 'build', 'gfx_recon.dll')
        if not os.path.exists(tree_dll):                    # the gate's build of the tree (not the kit's in-game one)
            subprocess.run(['./build.sh'], cwd=os.path.join(H, '..', '..', '..', 'tree'), check=True, stdout=subprocess.DEVNULL)
        cases = os.path.join(H, '..', '..', '..', 'verification', 'cases_clean_final.json')
        if len(xc) != 2: print('FAIL: %d .xcap files written, not 2' % len(xc)); bad += 1
        for x in sorted(xc):
            r = subprocess.run([sys.executable, os.path.join(H, '..', '..', '..', 'pipeline', 'xcap.py'), os.path.join(d, x), cases,
                                tree_dll, os.path.join(d, 'replay')], capture_output=True, text=True)
            print(r.stdout.strip(), r.stderr.strip()[-1500:])
            ok = r.returncode == 0 and ': PASS;' in r.stdout and "'return': 8" in r.stdout and 'this 0x' in r.stdout
            if '_A4830_' in x: ok = ok and "args ['0x5566AABB']" in r.stdout          # SetColor's argument, read off the captured stack
            print('%s: %s replays through the gate: PASS on all 8 trials, from the captured this and arguments' % ('ok' if ok else 'FAIL', x))
            bad += not ok
    if os.environ.get("KEEP"): print("kept", d)
    else: shutil.rmtree(d, ignore_errors=True)
sys.exit(1 if bad else 0)
