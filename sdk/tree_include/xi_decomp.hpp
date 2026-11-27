// xi_decomp.hpp -- the helper types and macros Hex-Rays pseudocode uses, so decompiled bodies
// compile as C++ (MinGW i686, matching MSVC6's 32-bit x86 ABI). Written for this project.
#pragma once
#include <stdint.h>
#include <string.h>
#define _mm_pause() __asm__ __volatile__("pause")
// XI_GAME(ea): an address in the analysed image of FFXiMain.dll (base 0x10000000). Built with XI_INGAME, it is
// rebased to where the game's DLL is loaded: xi_rel (rt.c) is that load address minus 0x10000000, set by the
// loader before any reconstructed function runs. Otherwise it is the address itself, as the gate runs the game
// at its analysed base, and the code it compiles to is the same as a plain constant's.
#ifdef XI_INGAME
extern "C" uintptr_t xi_rel;
// Another build of the game (kit/xikit/builds/<stamp>.json, pipeline/build_translate.py): the analysed build's ranges
// that moved there, code and (since build 6AE818B4, 2 Nov) data, set by the kit with xi_rel. xi_shift[0] is the number
// of ranges (at most XI_SHIFT_MAX), then lo, hi, shift for each, sorted by lo and not overlapping. With no ranges (the
// analysed build, and any build whose nothing moved) an address costs one test; otherwise a binary search.
#define XI_SHIFT_MAX 64
extern "C" int32_t xi_shift[1 + 3 * XI_SHIFT_MAX];
static inline uintptr_t xi_code(uint32_t ea) {
  int32_t n = xi_shift[0], d = 0;
  if (n > 0) {
    int32_t lo = 0, hi = n - 1;
    while (lo <= hi) {
      int32_t m = (lo + hi) >> 1; uint32_t a = static_cast<uint32_t>(xi_shift[1 + 3 * m]), b = static_cast<uint32_t>(xi_shift[2 + 3 * m]);
      if (ea < a) hi = m - 1; else if (ea >= b) lo = m + 1; else { d = xi_shift[3 + 3 * m]; break; }
    }
  }
  return static_cast<uintptr_t>(ea) + xi_rel + d;
}
#ifndef XI_PROBE
#define XI_GAME(ea) (xi_code(static_cast<uint32_t>(ea)))
#else
// the probe build (build.sh XI_PROBE=1, never run): every rebased address is moved by 0x01000000 at compile time, so
// a game-range constant (0x10001000-0x10700000) left in its code was not written through XI_GAME
// (pipeline/raw_game_addrs.py, which kit/xikit/make_manifest.py reads)
#define XI_GAME(ea) (static_cast<uintptr_t>(static_cast<uint32_t>(ea) + 0x01000000u) + xi_rel)
#endif
#else
#define XI_GAME(ea) (static_cast<uintptr_t>(ea))
#endif
#define XI_EA(t, ea) (*reinterpret_cast<t *>(XI_GAME(ea)))
static inline uint8_t  rotl8(uint8_t v, int n)  { n &= 7;  return n ? (uint8_t)((v << n) | (v >> (8 - n))) : v; }
static inline uint16_t rotl16(uint16_t v, int n) { n &= 15; return n ? (uint16_t)((v << n) | (v >> (16 - n))) : v; }
static inline uint32_t rotl32(uint32_t v, int n) { n &= 31; return n ? (v << n) | (v >> (32 - n)) : v; }
static inline uint64_t rotl64(uint64_t v, int n) { n &= 63; return n ? (v << n) | (v >> (64 - n)) : v; }
static inline uint8_t  rotr8(uint8_t v, int n)  { return rotl8(v, -n & 7); }
static inline uint16_t rotr16(uint16_t v, int n) { return rotl16(v, -n & 15); }
static inline uint32_t rotr32(uint32_t v, int n) { return rotl32(v, -n & 31); }
static inline uint64_t rotr64(uint64_t v, int n) { return rotl64(v, -n & 63); }
// sign of x as a bool (Hex-Rays: __SETS__)
template <class T> static inline bool is_negative(T x) { return x < 0; }
// carry out of x+y
template <class T, class U> static inline bool add_carries(T x, U y) { return (T)(x) > (T)((T)x + (T)y); }
template <class T, class U> static inline bool sub_borrows(T x, U y) { return (T)x < (T)y; }
template <class T, class U> static inline bool sub_overflows(T x, U y) {
    T r = (T)(x - y); return ((x ^ y) & (x ^ r)) < 0; }
template <class T, class U> static inline bool add_overflows(T x, U y) {
    T r = (T)(x + y); return ((~(x ^ y)) & (x ^ r)) < 0; }
// Hex-Rays prints inline `rep movs` as qmemcpy
// x87 intrinsics as the original executes them (MSVC6 /Oi emits fsin/fcos/fsqrt/fabs/fpatan inline)
static inline double sin(double x)  { double r; __asm__("fsin" : "=t"(r) : "0"(x)); return r; }
static inline double cos(double x)  { double r; __asm__("fcos" : "=t"(r) : "0"(x)); return r; }
static inline double sqrt(double x) { double r; __asm__("fsqrt" : "=t"(r) : "0"(x)); return r; }
static inline double fabs(double x) { double r; __asm__("fabs" : "=t"(r) : "0"(x)); return r; }
static inline double atan2(double y, double x) { double r; __asm__("fpatan" : "=t"(r) : "0"(x), "u"(y) : "st(1)"); return r; }
static inline double atan(double x) { return atan2(x, 1.0); }
static inline double tan(double x)  { double r, one; __asm__("fptan" : "=t"(one), "=u"(r) : "0"(x)); (void)one; return r; }
// the same on an 80-bit value: a `long double` local (Hex-Rays: an x87 register the original never stored) keeps all its
// bits, as in the original's fsin/fcos on st(0); through the double versions it was rounded to 53 bits first, and near a
// zero of cos the sign of the result came out different (Post_DrawRotatingGhostLayers 0x10038E10: -0.0 vs +0.0, 6 Oct)
static inline long double sin(long double x)  { long double r; __asm__("fsin" : "=t"(r) : "0"(x)); return r; }
static inline long double cos(long double x)  { long double r; __asm__("fcos" : "=t"(r) : "0"(x)); return r; }
static inline long double sqrt(long double x) { long double r; __asm__("fsqrt" : "=t"(r) : "0"(x)); return r; }
static inline long double fabs(long double x) { long double r; __asm__("fabs" : "=t"(r) : "0"(x)); return r; }
static inline long double atan2(long double y, long double x) { long double r; __asm__("fpatan" : "=t"(r) : "0"(x), "u"(y) : "st(1)"); return r; }
static inline long double tan(long double x)  { long double r, one; __asm__("fptan" : "=t"(one), "=u"(r) : "0"(x)); (void)one; return r; }
// Hex-Rays bit reinterpretation helpers
template <class To, class From> static inline To bit_copy(From f) { To t; memcpy(&t, &f, sizeof(t)); return t; }
