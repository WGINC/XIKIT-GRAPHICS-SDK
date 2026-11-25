#!/usr/bin/env bash
# package.sh OUT.zip -- the devkit release named in kit/devkit/README.md (its first line): devkit_r<N>/ with
#   kit/        kit/xikit/dist: xikit.dll, gfx_recon_ingame.dll, every manifest, VERSION.txt
#   d3d8on11/   kit/d3d8on11/dist: d3d8.dll, d8x.exe, d8x_arm64.exe
#   sdk/        sdk/package.sh's xikit_sdk (headers, the tree's headers and source, examples, template, build scripts)
#   pdb/        sdk/dist_pdb: FFXiMain.pdb for each known build
#   mods/       the SDK's example mods for players, built (sdk/build_mod.sh)
#   tools/      the frame inspector: kit/fcap/frame_inspect.py, compare.py, fcap_replay.exe, and kit/d3dprof/pictures.py
#   README.md, devkit_check.exe (kit/devkit/check.c) and SHA256SUMS.txt (every file but those two)
# Build first: kit/xikit/build.sh (FFXI_DLL_6AE818B4 set), kit/d3d8on11/build.sh, kit/fcap/build.sh, sdk/package.sh.
set -euo pipefail
H="$(cd "$(dirname "$0")" && pwd)"; ROOT="$H/../.."; OUT="$(realpath -m "$1")"
N="$(sed -n '1s/.*release \([0-9]\+\).*/\1/p' "$H/README.md")"; [ -n "$N" ] || { echo "README.md: no release number on its first line"; exit 1; }
T="$(mktemp -d)"; R="$T/devkit_r$N"; mkdir -p "$R/kit" "$R/d3d8on11" "$R/pdb" "$R/tools/fcap" "$R/tools/d3dprof"
D="$ROOT/kit/xikit/dist"
# a release is built from committed source only: the kit's and the SDK's stamps say +modified otherwise
# (DEVKIT_ALLOW_MODIFIED=1 for a trial package that is not released)
if [ "${DEVKIT_ALLOW_MODIFIED:-0}" != 1 ] && grep -l '+modified' "$D/VERSION.txt" "$ROOT/sdk/dist/xikit_sdk/VERSION.txt" 2>/dev/null; then
  echo "built from a working tree with uncommitted changes (+modified above): commit, rebuild, package again"; exit 1
fi
grep -q '^!swap_set' "$D/xikit_manifest_6AE818B4.txt" || { echo "dist/xikit_manifest_6AE818B4.txt has no !swap_set: build with \$FFXI_DLL_6AE818B4 set"; exit 1; }
for f in xikit.dll gfx_recon_ingame.dll xikit_manifest.txt VERSION.txt; do cp "$D/$f" "$R/kit/"; done
cp "$D"/xikit_manifest_*.txt "$R/kit/"
for f in d3d8.dll d8x.exe d8x_arm64.exe; do cp "$ROOT/kit/d3d8on11/dist/$f" "$R/d3d8on11/"; done
cp -r "$ROOT/sdk/dist/xikit_sdk" "$R/sdk"
for b in "$ROOT"/sdk/dist_pdb/*/; do mkdir -p "$R/pdb/$(basename "$b")"; cp "$b/FFXiMain.pdb" "$b/FFXiMain.pdb.json" "$R/pdb/$(basename "$b")/"; done
cp "$ROOT/kit/fcap/frame_inspect.py" "$ROOT/kit/fcap/compare.py" "$R/tools/fcap/"; mkdir -p "$R/tools/fcap/dist"; cp "$ROOT/kit/fcap/dist/fcap_replay.exe" "$R/tools/fcap/dist/"
cp "$ROOT/kit/d3dprof/pictures.py" "$R/tools/d3dprof/"
mkdir -p "$R/mods"; X="$ROOT/sdk/examples"
for m in texture_replace:texture_replace_core effect_comfort:effect_comfort_core camera_view file_overlay audio_mix world_light \
         photo_mode:photo_mode_core color_filter:color_filter_core ui_layout:ui_layout_core click_target hotbar:hotbar_core status_text:status_text_core; do
  src=(); for s in ${m//:/ }; do src+=("$X/$s.cpp"); done
  extra=(); [ "${m%%:*}" = hotbar ] && extra=(-- -lwindowscodecs -lole32)    # (the hotbar reads icons with WIC)
  "$ROOT/sdk/build_mod.sh" "$R/mods/${m%%:*}.dll" "${src[@]}" "${extra[@]}" >/dev/null
done
cp "$H/README.md" "$R/"
( cd "$R" && find . -type f ! -name README.md ! -name SHA256SUMS.txt | sed 's|^\./||' | sort | xargs sha256sum > SHA256SUMS.txt )
i686-w64-mingw32-gcc -O2 -Wall -std=gnu99 -static-libgcc -Wl,--no-insert-timestamp -o "$R/devkit_check.exe" "$H/check.c" -lbcrypt
find "$R" -name "*.bat" -exec sed -i 's/\r*$/\r/' {} +
rm -f "$OUT"; ( cd "$T" && zip -qr "$OUT" "devkit_r$N" ); rm -rf "$T"
echo "wrote $OUT"; unzip -l "$OUT" | tail -1
