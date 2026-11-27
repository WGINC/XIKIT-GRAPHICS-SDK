# ActorBase

Group: `Actor` (by the file name only). Source: `sdk/tree_src/ActorBase.cpp`.

Why the file has this name (data/unit_names.json): CXiActor::ConstructBase / Init, CXiActor_LinkIntoDrawList, Actor_ResetDrawLists

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ActorBase_ReleaseQueued` | 0x10081A30 | 28 | yes | - | Releases each object that game_10085240 returns, until none remain. | low |
| `Actor_ResetDrawLists` | 0x10081A50 | 101 | yes | - | - | - |
| `CXiActor_LinkIntoDrawList` | 0x10081AE0 | 69 | yes | - | Puts the actor at the head of the actor draw list once, recording the list's count. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ActorBase_ReleaseQueued` calls `game_10085240`
- `Actor_ResetDrawLists` calls `game_100814F0`
- `CXiActor_LinkIntoDrawList` calls `Actor_CountAll`
