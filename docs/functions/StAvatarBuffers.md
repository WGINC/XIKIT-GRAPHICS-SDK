# StAvatarBuffers

Group: `St` (by the file name only). Source: `sdk/tree_src/StAvatarBuffers.cpp`.

Why the file has this name (data/unit_names.json): StAvatar_CheckBuffersReady

1 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `StAvatar_CheckBuffersReady` | 0x10253160 | 79 | yes | - | Checks the two buffer indices against the file manager and marks the buffers ready. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `StAvatar_CheckBuffersReady` calls `TextInputFiles_FileMngFindFileNumKind2`
