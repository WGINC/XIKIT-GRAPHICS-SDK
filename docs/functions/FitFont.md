# FitFont

Group: `Fit` (by the file name only). Source: `sdk/tree_src/FitFont.cpp`.

Why the file has this name (data/unit_names.json): FontGlyphCache_* and the FiT font engine (FiTRodinL-U.fit, FiTWrapperd.dll, CreateFiTWrapper), and a TCP server and client with its own threads (the strings "server start (port %d)", "client accepted(%d)."; its socket code is in data/security_set.json) (an address range between two evidenced source files, holding several of the original files: named for its main contents). Named for the font code: the TCP library is in data/security_set.json (debuglink) and is not in the public kit

27 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `FontGlyphCache_GetDevice` | 0x1025D750 | 9 | yes | - | - | - |
| `FontGlyphCache_CreateTexture` | 0x1025D760 | 74 | yes | 0 | - | - |
| `FontGlyphCache_CreateVertexBuffer` | 0x1025D7B0 | 64 | yes | 0 | - | - |
| `FitFont_ReturnFalse` | 0x1025E020 | 3 | yes | - | Returns false in AL. | medium |
| `FontGlyphCache_IsStateTwo` | 0x1025E050 | 24 | yes | - | Tests whether the object at DAT_1066276C is in state 2. | low |
| `FontGlyphCache_GetCounterBlock` | 0x1025E0B0 | 6 | yes | - | Returns the address of the counter block at DAT_1067A294. | low |
| `FontGlyphCache_ResetCounter` | 0x1025E0C0 | 5 | yes | - | Clears the counter at DAT_1067A298. | low |
| `FontGlyphCache_StepCounter` | 0x1025E0E0 | 5 | yes | - | Moves the counter at DAT_1067A298 one step toward zero. | low |
| `FitFont_ReturnFalseFwd` | 0x1025E0F0 | 5 | yes | - | Returns false in AL, through 0x1025E020. | medium |
| `FontGlyphCache_AddToCounter` | 0x1025E210 | 20 | yes | - | Adds twice the argument to the counter at DAT_1067A298. | low |
| `FontGlyphCache_ClearCounter` | 0x1025E230 | 11 | yes | - | Sets the counter at DAT_1067A298 to zero. | low |
| `FontGlyphCache_DecayCounter` | 0x1025E240 | 25 | yes | - | Moves the counter at DAT_1067A298 one step toward zero. | low |
| `FitFont_BaseCtor` | 0x1025E260 | 248 | yes | - | Constructs the object with three critical sections and three event objects. | low |
| `FitFont_BaseDtor` | 0x1025E380 | 216 | yes | - | Destroys the object built by Unit1025C9E0_BaseCtor. | low |
| `FitFont_ReleaseField6C` | 0x1025F2F0 | 97 | yes | - | Releases the interface held at +0x6C under the object's lock. | low |
| `FitFont_EndTimerPeriodIfActive` | 0x1025F640 | 104 | no | - | If the object's timer period is active, marks it inactive, calls its virtual slot 17 and ends the 1 ms timer period. | medium |
| `FitFont_DerivedCtor` | 0x1025FD50 | 157 | yes | - | Constructs the derived object on top of the base. | low |
| `FitFont_ResetState` | 0x1025FE40 | 191 | yes | - | Resets the derived object's state and records the current time. | low |
| `FontGlyphCache_StoreElapsed158` | 0x1025FF10 | 25 | yes | - | Stores the time elapsed since the last value at +0x158. | low |
| `FontGlyphCache_NoOpZero` | 0x10260360 | 3 | yes | - | Returns 0. | low |
| `FitFont_InnerCtor` | 0x10261210 | 95 | yes | - | Constructs the inner object with a 16-byte value and a lock pointer. | low |
| `FitFont_InnerDtor` | 0x102612D0 | 101 | yes | - | Destroys the inner object. | low |
| `FitFont_AddLibraryRef` | 0x10265940 | 20 | yes | - | Increments the shared count at 0x1067A2A0 that keeps the library at 0x1067A29C loaded. | medium |
| `FitFont_ReleaseLibraryRef` | 0x10265960 | 42 | yes | - | Decrements the shared count and frees the library module at 0x1067A29C when it reaches zero. | high |
| `FitFont_RefObjCtor` | 0x102659B0 | 51 | yes | - | Constructs a reference-counted object with an owner pointer (itself when none). | low |
| `FitFont_CreateEvent` | 0x10265B70 | 28 | yes | - | Creates an unnamed, initially unsignalled event (manual-reset when the argument is set) and stores its handle. | high |
| `FontGlyphCache_MarkState3` | 0x1026DB24 | 29 | yes | - | Sets the state byte at the pointer at +0xC to 3 and returns whether the object exists. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `FontGlyphCache_GetDevice` calls nothing directly
- `FontGlyphCache_CreateTexture` calls nothing directly
- `FontGlyphCache_CreateVertexBuffer` calls nothing directly
- `FitFont_ReturnFalse` calls nothing directly
- `FontGlyphCache_IsStateTwo` calls nothing directly
- `FontGlyphCache_GetCounterBlock` calls nothing directly
- `FontGlyphCache_ResetCounter` calls `FontGlyphCache_ClearCounter`
- `FontGlyphCache_StepCounter` calls `FontGlyphCache_DecayCounter`
- `FitFont_ReturnFalseFwd` calls `FitFont_ReturnFalse`
- `FontGlyphCache_AddToCounter` calls nothing directly
- `FontGlyphCache_ClearCounter` calls nothing directly
- `FontGlyphCache_DecayCounter` calls nothing directly
- `FitFont_BaseCtor` calls `FitFont_InnerCtor`, `FitFont_CreateEvent`, `FitFont_InnerDtor`, `sub_10265B90`, `sub_103162F7`
- `FitFont_BaseDtor` calls `FitFont_EndTimerPeriodIfActive`, `FitFont_ReleaseField6C`, `sub_10265B90`, `FitFont_InnerDtor`, `sub_103162F7`
- `FitFont_ReleaseField6C` calls `sub_103162F7`
- `FitFont_EndTimerPeriodIfActive` calls `sub_103162F7`
- `FitFont_DerivedCtor` calls `FitFont_BaseCtor`, `FitFont_ResetState`, `FitFont_BaseDtor`, `sub_103162F7`
- `FitFont_ResetState` calls nothing directly
- `FontGlyphCache_StoreElapsed158` calls nothing directly
- `FontGlyphCache_NoOpZero` calls nothing directly
- `FitFont_InnerCtor` calls `FitFont_RefObjCtor`
- `FitFont_InnerDtor` calls `operator_delete`, `FitFont_ReleaseLibraryRef`, `sub_103162F7`
- `FitFont_AddLibraryRef` calls nothing directly
- `FitFont_ReleaseLibraryRef` calls nothing directly
- `FitFont_RefObjCtor` calls `FitFont_AddLibraryRef`
- `FitFont_CreateEvent` calls nothing directly
- `FontGlyphCache_MarkState3` calls nothing directly
