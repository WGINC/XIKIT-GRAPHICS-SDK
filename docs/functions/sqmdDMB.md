# sqmdDMB

Group: `sq` (by the file name only). Source: `sdk/tree_src/sqmdDMB.cpp`.

11 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `SqmdDMB_Resolve` | 0x10287FB0 | 1702 | yes | 2 | sqmdDMBResolve: checks a loaded 'DMB' model image and fixes up its pointers in place. | high |
| `SqmdDMB_TraceDelta` | 0x10288660 | 25 | yes | - | Returns the offset of a value from the first value recorded. | low |
| `SqmdDMB_AlignMem` | 0x10288680 | 66 | yes | - | Rounds a memory offset up to 16 bytes, logging the padding when tracing. | medium |
| `SqmdDMB_ResolveTextures` | 0x102886D0 | 633 | yes | 1 | sqmdDMBResolveTextures: fixes up and registers each texture of a DMB model. | high |
| `SqmdDMB_ResolveShaders` | 0x10288950 | 540 | yes | - | sqmdDMBResolveShaders: fixes up each shader of a DMB model and links its textures. | high |
| `SqmdDMB_TextureLink` | 0x10288B70 | 58 | yes | - | sqmdDMBTextureLink: turns a texture index into the texture pointer, 0 for the unset marker or an invalid index. | high |
| `SqmdDMB_ResolveMatrices` | 0x10288BB0 | 102 | yes | - | Assigns memory slots to the matrices of a deform block. | medium |
| `SqmdDMB_ResolveStrings` | 0x10288C20 | 416 | yes | - | Copies a deform block's tag and file strings into its buffer. | medium |
| `SqmdDMB_ClearTables` | 0x10288DC0 | 59 | yes | - | Clears the first two tables of a deform block. | low |
| `SqmdDMB_ResetCounts` | 0x10288E00 | 94 | yes | - | Resets the counters and two tables of a deform block. | low |
| `sqmdDMBBuildShapes` | 0x10288E60 | 371 | yes | 2 | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `SqmdDMB_Resolve` calls `sqDebugPrintf`, `SqmdDMB_TraceDelta`, `game_10314D55`, `SqmdDMB_AlignMem`, `SqTimer_GetMicroseconds`, `SqmdDMB_ResolveTextures`, `SqmdDMB_ResolveShaders`, `SqmdDMB_ResolveMatrices`, `SqmdDMB_ResolveStrings`, `SqmdDMB_ClearTables`, `SqmdDMB_ResetCounts`, `sqmdDMBBuildShapes`, `SqmdDMB_BuildUpdaters`, `SqMem_HexDump`
- `SqmdDMB_TraceDelta` calls nothing directly
- `SqmdDMB_AlignMem` calls `SqmdDMB_TraceDelta`, `game_10314D55`
- `SqmdDMB_ResolveTextures` calls `SqmdDMB_TraceDelta`, `game_10314D55`, `SqmdDMB_AlignMem`, `sqgxTextureAdd`, `sqDebugPrintf`, `sqgxTextureClutAdd`
- `SqmdDMB_ResolveShaders` calls `SqmdDMB_TraceDelta`, `game_10314D55`, `SqmdDMB_AlignMem`, `SqmdDMB_TextureLink`, `sqDebugPrintf`
- `SqmdDMB_TextureLink` calls `sqDebugPrintf`
- `SqmdDMB_ResolveMatrices` calls `SqmdDMB_TraceDelta`, `game_10314D55`, `SqmdDMB_AlignMem`
- `SqmdDMB_ResolveStrings` calls `SqmdDMB_TraceDelta`, `game_10314D55`, `SqmdDMB_AlignMem`
- `SqmdDMB_ClearTables` calls nothing directly
- `SqmdDMB_ResetCounts` calls nothing directly
- `sqmdDMBBuildShapes` calls `SqmdDMB_TraceDelta`, `game_10314D55`, `SqmdDMB_AlignMem`, `SqshBuild_BuildSQO`, `sqsdSampling_BakeOntoShape`, `sqsdAniso_BakeOntoShape`, `sqsdGeneric_BakeOntoShape`, `sqsdGlow_BakeOntoShape`, `sqsdCartoon_BakeOntoShape_Stub`, `SqmdModel_AppendPair68Flag100`, `sqDebugPrintf`
