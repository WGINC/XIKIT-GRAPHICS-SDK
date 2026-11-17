# SkeletonActorState

Group: `Skeleton` (by the file name only). Source: `sdk/tree_src/SkeletonActorState.cpp`.

Why the file has this name (data/unit_names.json): read from the code: tests and updates skeleton-actor state bytes (+0x878, +0x87A), finds textures by name; called from CXiSkeletonActor::PerActor_FourBucketStaggeredUpdate and the scheduler; the string "t123t123"

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SkeletonActorState_SetFlag8ACBit1` | 0x100D6F50 | 28 | yes | - | Sets or clears bit 1 of the actor's flag byte at +0x8AC from its argument and returns the old byte. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SkeletonActorState_SetFlag8ACBit1` calls nothing directly
