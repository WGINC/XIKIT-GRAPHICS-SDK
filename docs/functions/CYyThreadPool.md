# CYyThreadPool

Group: `CYy` (by the file name only). Source: `sdk/tree_src/CYyThreadPool.cpp`.

3 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ThreadPool_StartThread` | 0x100394D0 | 114 | yes | - | - | - |
| `ThreadPool_Shutdown` | 0x10039550 | 53 | yes | - | Signals the pool's workers to stop and waits for them. | low |
| `CYyThreadPool_Construct` | 0x100395D0 | 27 | yes | - | Constructs the thread-pool object and clears its state. (reviewed as sub_100395D0) | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ThreadPool_StartThread` calls `ErrorReport_NoOpVarargsA`, `Allocator_Generic`, `CYyThreadPool_Construct`, `ThreadPool_CreateSuspendedThread`
- `ThreadPool_Shutdown` calls `Thread_ResumeAndWait`
- `CYyThreadPool_Construct` calls nothing directly
