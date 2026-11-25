#!/usr/bin/env bash
# build_examples.sh -- compile every example mod and the template against this kit's headers (the public repository's
# CI runs it: .github/workflows/build.yml). It needs MinGW-w64's i686-w64-mingw32-g++ and nothing of the game: it
# checks that the headers, the examples and build_mod.sh agree, not that a mod works in the game.
set -euo pipefail
S="$(cd "$(dirname "$0")/../sdk" && pwd)"; O="${1:-$(mktemp -d)}"; mkdir -p "$O"
X="$S/examples"; fails=0
build() { local out="$1"; shift; if "$S/build_mod.sh" "$O/$out" "$@" >"$O/$out.log" 2>&1; then echo "ok: $out"; else echo "FAIL: $out"; tail -20 "$O/$out.log"; fails=$((fails + 1)); fi; }
for m in texture_replace:texture_replace_core effect_comfort:effect_comfort_core camera_view file_overlay audio_mix world_light \
         photo_mode:photo_mode_core color_filter:color_filter_core ui_layout:ui_layout_core click_target hotbar:hotbar_core \
         status_text:status_text_core overlay scene_tint scene_shader depth_view; do
  n="${m%%:*}"; [ -f "$X/$n.cpp" ] || continue
  src=("$X/$n.cpp"); [ "$m" != "$n" ] && src+=("$X/${m#*:}.cpp")
  extra=(); [ "$n" = hotbar ] && extra=(-- -lwindowscodecs -lole32)
  build "$n.dll" "${src[@]}" "${extra[@]}"
done
build my_mod.dll "$S/template/my_mod.cpp"
echo "$fails failed"; exit $((fails > 0))
