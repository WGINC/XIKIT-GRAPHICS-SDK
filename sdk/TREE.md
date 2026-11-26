# Reading the tree (`tree_src/`, `tree_include/`)

`tree_src/` is the game's code rebuilt as C++ and checked against the game, function by function. It was made by
decompilers. Their vocabulary has been replaced, and every replacement was kept only where the file compiles to the
same machine code as before. So the text is new, but the code it stands for is what was checked.

This page says what the notation means. You do not need reverse-engineering experience to read it. You do need
patience where the code has no names: the game's own names are not known, and where nothing in the code names a
thing, the tree does not make a name up.

## A function

```cpp
// FUNCTION: FFXIMAIN 0x102993B0
// GATE: PASS -- 100 trials, 93 returned normally, 0 D3D calls compared ...
XI_API void __cdecl SqsdAniso_DrawPasses(int * arg1, int * arg2)
{
```

- **`FUNCTION:`** the function's address in the game (build 6A995428). `docs/functions/<file>.md` has a summary of
  each function, and what it calls.
- **`GATE:`** how it was checked. The rebuilt function was run against the game's own code on random inputs.
  `PASS` means they agreed every time. "D3D calls compared" counts the Direct3D calls that were compared as well.
- **`XI_API`, `__cdecl`, `__thiscall`, `__stdcall`:** how the function is called. A method of a class (`CDx::...`)
  gets the object as `this`. A free function written `__thiscall` gets it as its first parameter, usually named
  `self` or `self_`.

## Names

| You see | It means |
|---|---|
| `CDx::Initialize`, `Camera_SetPosition`, `g_pD3DHolder` | a real name, from evidence in the game's code (docs say which) |
| `pDevice`, `Width`, `Format`, `caps` | a variable named by evidence: the D3D8 header's parameter it is passed as, or the one field it is always loaded from. `sdk/public_clean_report.json` ("evidence") says which, for every one |
| `arg1`, `arg2` ... | a parameter with no known name, numbered by its place in the list |
| `i1`, `u2`, `f3`, `p4`, `c5`, `b6`, `buf7`, `val8` | a local with no known name: `i` signed integer, `u` unsigned, `f` floating point, `p` pointer, `c` char, `b` bool, `buf` array, `val` anything else; the number counts them in order |
| `obj1` | an object pointer the code calls methods on |
| `L1`, `L2` | a label (the target of a `goto`) |
| `g_1045EC28` | a global variable with no known name, at that address |
| `game_10002840` | a function of the game with no known name, at that address |
| `code_10292590` | an address inside the game's code, used as data (a table of handlers, for example) |
| `str_<text>_103BB254` | a constant string; its text is in the name |
| `ptr_to_<name>_10329A3C` | a global holding a pointer to `<name>` |
| `<name>_as_v0` | the same global as `<name>`, read as another type |
| `field_834` | a member of a class whose name is not known, at that offset |

## Types and helpers

| You see | It means |
|---|---|
| `uint32_t`, `int16_t` ... | integers of that many bits (`<stdint.h>`) |
| `bits32` | four bytes whose type the code does not settle: it holds whatever was stored, bit for bit (a float stays a float's bits) |
| `untyped_fn *` | a pointer to a function whose type is not known |
| `bit_cast<float>(x)` | the bits of `x` read as a float (no conversion) |
| `orig::Name(...)` | a call into the game's own code, at the address `Name` stands for |
| `XI_GAME(0x10330EBC)` | an address in the game, moved to where the game is loaded |
| `XI_ANY` | one 4-byte argument slot, passed as the game passes it |
| `xi_strunc24(x)`, `xi_trunc24(x)` | the low 24 bits of `x`, sign- or zero-extended |
| `x87_fsqrt`, `x87_fsin` ... | the x87 instruction the game uses for that maths (same result, bit for bit) |
| `union ... { ... } frame;` | locals whose addresses the code takes, at the same places as in the game's stack frame; `frame.f1` is one of them |
| `*(int *)(p + 0x24)`, `at<uint8_t>(this, 0x834)` | a member read by its offset, where the type that has it is not known yet |
| `(long double)` | kept only where it changes the result (x87 precision); elsewhere it was taken out |

## What is still rough, and why

- **`goto`s.** Most of them jump into a `switch` case, or to a point that several jumps share. Taking them out means
  copying code or adding flags, and then the code is no longer the same.
- **Offsets.** `*(int *)(p + 0x24)` becomes a named member once the type of `p` is proven. That work goes on in the
  analysis repository; each round of it reaches this tree.
- **Names.** A name comes only from evidence: a string in the game, a declared API, a class descriptor, a field.
  What a thing does is not, on its own, a name for it. The function summaries in `docs/functions/` describe what
  the code does; the names wait for evidence.
