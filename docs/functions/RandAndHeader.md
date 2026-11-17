# RandAndHeader

Group: `Rand` (by the file name only). Source: `sdk/tree_src/RandAndHeader.cpp`.

Why the file has this name (data/unit_names.json): Rand_SeedMT19937 / NextMod / UniformTimes (the random numbers), Mem_AllocWithHeader12

7 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Rand_SeedMT19937` | 0x1006BD90 | 92 | yes | - | - | - |
| `RandAndHeader_Next` | 0x1006BE20 | 275 | yes | - | Returns the next 32-bit value from the Mersenne Twister. | high |
| `Rand_NextMod` | 0x1006BF40 | 25 | yes | - | Returns a random value in the range 0 to n minus 1. | medium |
| `Rand_NextModUnsigned` | 0x1006BF60 | 26 | yes | - | Returns an unsigned random value in the range 0 to n minus 1. | medium |
| `Rand_UniformTimes` | 0x1006BF80 | 74 | yes | - | Returns a random value in [0, x). | medium |
| `Rand_SignedUniformTimes` | 0x1006BFD0 | 80 | yes | - | Returns a random value in [-x, x). | medium |
| `Mem_AllocWithHeader12` | 0x1006C0F0 | 25 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Rand_SeedMT19937` calls nothing directly
- `RandAndHeader_Next` calls `Rand_SeedMT19937`
- `Rand_NextMod` calls `RandAndHeader_Next`
- `Rand_NextModUnsigned` calls `RandAndHeader_Next`
- `Rand_UniformTimes` calls `RandAndHeader_Next`
- `Rand_SignedUniformTimes` calls `RandAndHeader_Next`
- `Mem_AllocWithHeader12` calls `Mem_AllocObject`
