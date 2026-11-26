# CYyMusicLoadTask

Group: `CYy` (by the file name only). Source: `sdk/tree_src/CYyMusicLoadTask.cpp`.

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CYyMusicLoadTask::StartTrack` | 0x100378B0 | 161 | yes | - | Makes the given music track the current one: stops the previous one if different and asks the sound thread to load it with a level of 127 times two stored factors. (reviewed as game_100378B0) | medium |
| `StAvatar_SwitchMusicTask` | 0x10037960 | 146 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CYyMusicLoadTask::StartTrack` calls `LobbyThread_SendCmd9`, `game_10311C2C`, `Music_LoadTrackIfRunning`, `LobbyThread_SendCmd8`
- `StAvatar_SwitchMusicTask` calls `Mem_AllocFromArea`, `CMoTask::ResetFields`, `CMoTask::Constructor`, `game_100749B0`
