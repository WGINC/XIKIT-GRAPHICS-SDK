# ThreadPool

Group: `Thread` (by the file name only). Source: `sdk/tree_src/ThreadPool.cpp`.

Why the file has this name (data/unit_names.json): ThreadPool_CreateSuspendedThread, Thread_ResumeAndWait (CreateThread, ResumeThread)

2 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `ThreadPool_CreateSuspendedThread` | 0x10039670 | 48 | yes | - | Creates a suspended thread for the given start routine and argument and records its handle and id in the object. | high |
| `Thread_ResumeAndWait` | 0x100396A0 | 93 | yes | - | Resumes a worker thread when requested and waits for it to finish. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `ThreadPool_CreateSuspendedThread` calls nothing directly
- `Thread_ResumeAndWait` calls nothing directly
