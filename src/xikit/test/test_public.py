"""test_public.py -- the public kit (sdk/public_prune.py's output) under Wine, as it ships: kit/ without
gfx_recon_ingame.dll, its xikit.ini (swap=0) replaced by host.c's, the cut manifests, and a mod (mod_public.cpp)
built with the cut SDK's build_mod.sh and headers. host.c's "public" mode: the mod loaded, its function hook with the
game's code as previous, its device hook, its setting read and re-read, nothing else patched.

    FFXI_DLL=/path/FFXiMain.dll python3 test_public.py PUBLIC_DIR      (PUBLIC_DIR: the pruner's OUT_DIR)"""
import os, shutil, subprocess, sys, tempfile
H = os.path.dirname(os.path.abspath(__file__)); P = os.path.abspath(sys.argv[1])
subprocess.run(['i686-w64-mingw32-gcc', '-O1', '-Wall', '-o', os.path.join(H, 'host.exe'), os.path.join(H, 'host.c'), '-static-libgcc'], check=True)
d = tempfile.mkdtemp(prefix='xikit_public_')
subprocess.run([os.path.join(P, 'sdk', 'build_mod.sh'), os.path.join(d, 'mod_public.dll'), os.path.join(H, 'mod_public.cpp')], check=True)
for f in os.listdir(os.path.join(P, 'kit')): shutil.copy(os.path.join(P, 'kit', f), d)
assert not os.path.exists(os.path.join(d, 'gfx_recon_ingame.dll')), 'the public kit has a reconstruction DLL'
shutil.copy(os.environ['FFXI_DLL'], os.path.join(d, 'FFXiMain.dll')); shutil.copy(os.path.join(H, 'host.exe'), d)
r = subprocess.run(['wine', 'host.exe', 'public'], cwd=d, env=dict(os.environ, WINEDEBUG='-all'), capture_output=True, text=True, timeout=600)
print(r.stdout.strip())
if r.returncode:
    print('--- xikit.log (end)'); print(''.join(open(os.path.join(d, 'xikit.log'), errors='replace').readlines()[-20:]))
sys.exit(r.returncode)
