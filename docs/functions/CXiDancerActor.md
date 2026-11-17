# CXiDancerActor

Group: `CXi` (by the file name only). Source: `sdk/tree_src/CXiDancerActor.cpp`.

5 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CXiDancerActor::Construct` | 0x100AB700 | 69 | yes | 4 | Constructs a dancer actor and loads its skeleton resource. (reviewed as sub_100AB700) | medium |
| `CXiDancerActor::InitBind` | 0x100AB750 | 183 | yes | - | Binds the dancer actor to its slot or its own sub-object. (reviewed as sub_100AB750) | low |
| `CXiDancerActor::SetPosition` | 0x100AB830 | 68 | yes | - | Sets the dancer actor's position and its stored vector. (reviewed as sub_100AB830) | medium |
| `CXiDancerActor_SetAnglesWrapped` | 0x100AB880 | 282 | yes | - | Sets the dancer's three angles (wrapped to about [-pi, pi]) on its acter and on itself. | medium |
| `CXiDancerActor::ApplyStateBlock` | 0x100AB9A0 | 558 | yes | - | Applies a state block to the dancer actor and marks the changed fields. (reviewed as sub_100AB9A0) | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CXiDancerActor::Construct` calls `CXiSkeletonActor::Constructor_1Arg`, `CXiActor::Construct`, `CXiDancerActor::InitBind`, `CXiSkeletonActor::LoadSkeletonResource`
- `CXiDancerActor::InitBind` calls `CXiDancerActor::ApplyStateBlock`
- `CXiDancerActor::SetPosition` calls `Acter_CopyPosToCached`, `Vec4_Copy`
- `CXiDancerActor_SetAnglesWrapped` calls `Acter_CopyPosToCached`, `Vec4_Copy`
- `CXiDancerActor::ApplyStateBlock` calls `Acter_CopySixDwordsTo7C`, `CopyPair_CopyReturnZ`, `CXiDancerActor::SetPosition`, `CXiDancerActor_SetAnglesWrapped`
