# Resource

Group: `Resource` (by the file name only). Source: `sdk/tree_src/Resource.cpp`.

Why the file has this name (data/unit_names.json): CMoResource::FindByTypeAndId / FindWorker / ReleaseChain / RegisterInTypeList, YmResourceFile_FindResourceUnder

10 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `MoRes_FindPrevious` | 0x10071FD0 | 46 | yes | - | Returns the resource before this one in the global list. | low |
| `WeatherRes_GetTimeKey` | 0x10072180 | 99 | yes | - | - | - |
| `CMoResource_Destroy` | 0x100721F0 | 70 | yes | - | - | - |
| `Resource_FindSelfLinkedNode` | 0x10072240 | 33 | no | - | Follows the chain at +0x28 to the node that links to itself (its root). | medium |
| `CMoResource_FindInScope` | 0x10072430 | 131 | yes | - | - | - |
| `YmResourceFile_FindResourceUnder` | 0x100724C0 | 127 | yes | - | - | - |
| `Resource_FindInChainByKind` | 0x10072540 | 127 | yes | - | Walks a node chain and returns the first callback result that is true for nodes of a kind. | medium |
| `Resource_InitFieldsTakeFlag1047D12C` | 0x10072990 | 45 | yes | - | Clears two fields of a new resource and moves a pending flag from a global into bit 0 of its flags. | medium |
| `Resource_ResetGlobals` | 0x100729C0 | 10 | yes | - | Clears the resource globals at 0x1047D138 and runs 0x10072970 at scene start. | low |
| `Resource_ClearGlobal1047D138` | 0x100729D0 | 11 | yes | - | Clears the global at 0x1047D138. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `MoRes_FindPrevious` calls nothing directly
- `WeatherRes_GetTimeKey` calls `unknown_libname_158`, `Time_FromHours`, `Time_SetModulo216000Div3600`
- `CMoResource_Destroy` calls `CMoResource::InitAndGetFlag`, `NodePool_ReleaseNode`
- `Resource_FindSelfLinkedNode` calls nothing directly
- `CMoResource_FindInScope` calls nothing directly
- `YmResourceFile_FindResourceUnder` calls nothing directly
- `Resource_FindInChainByKind` calls nothing directly
- `Resource_InitFieldsTakeFlag1047D12C` calls nothing directly
- `Resource_ResetGlobals` calls `Resource_ClearGlobal1047D138`
- `Resource_ClearGlobal1047D138` calls nothing directly
