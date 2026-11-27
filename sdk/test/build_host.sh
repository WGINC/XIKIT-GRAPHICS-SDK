#!/bin/sh
# build_host.sh [OUT.exe]: builds mod_host.exe (mod_host.c's header says how to use it) with MinGW-w64.
# On Windows with Visual Studio: cl /O2 mod_host.c user32.lib  (d3d8.dll is loaded at run time; no import library)
cd "$(dirname "$0")" && i686-w64-mingw32-gcc -O2 -Wall -o "${1:-mod_host.exe}" mod_host.c && echo "built ${1:-mod_host.exe}"
