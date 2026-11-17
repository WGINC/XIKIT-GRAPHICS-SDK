# StAvatarInfo

Group: `St` (by the file name only). Source: `sdk/tree_src/StAvatarInfo.cpp`.

Why the file has this name (data/unit_names.json): StAvatar_LoadInfo0 / LoadInfo2 / LoadInfoFile / GetInfoBuffer

10 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `StAvatar_ClearResource` | 0x10253210 | 91 | yes | - | Releases the resource held by an avatar slot and clears its ids. | medium |
| `StAvatarInfo_SubmitInfoBinIfObjSet` | 0x102532C0 | 31 | yes | - | Passes a slot, data and length to 0x102534F0 when the object at 0x10669424 exists. | low |
| `StAvatarInfo_Ctor` | 0x102532E0 | 18 | yes | - | Constructs the object App_InitScene keeps in sub_10669424. | medium |
| `StAvatarInfo_NoOp` | 0x10253330 | 1 | yes | - | Does nothing. | medium |
| `StAvatar_LoadInfoFile` | 0x10253360 | 246 | yes | - | Loads one of the avatar's info files into its slot. | medium |
| `StAvatarInfo_SubmitInfoBinIfChanged` | 0x102534F0 | 187 | yes | - | Updates the cached bytes of one info*.bin slot and, when they changed, hands the file to the file manager as a kind-3 request. | medium |
| `StAvatar_LoadInfo0` | 0x102535B0 | 18 | yes | - | Loads the first avatar info file. | low |
| `StAvatarInfo_SendBytePairKind0` | 0x102535F0 | 34 | yes | - | Sends a two-byte message of kind 0. | low |
| `StAvatar_LoadInfo2` | 0x10253630 | 18 | yes | - | Loads the third avatar info file. | low |
| `StAvatarInfo_SendBytePairKind2` | 0x10253670 | 34 | yes | - | Sends a two-byte message of kind 2. | low |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `StAvatar_ClearResource` calls `CMoResource::ReleaseChain`, `ResHandle_FreeIfUnreferenced`, `SqopSystem_ClearOpcodes`
- `StAvatarInfo_SubmitInfoBinIfObjSet` calls `StAvatarInfo_SubmitInfoBinIfChanged`
- `StAvatarInfo_Ctor` calls `StAvatarInfo_NoOp`
- `StAvatarInfo_NoOp` calls nothing directly
- `StAvatar_LoadInfoFile` calls `Allocator_Generic`, `TextInputFiles_CtorVt10337C60`, `TextInputFiles_FileMngFwd101C2450`, `TextInputFiles_FileMngSubmitPath3F4Kind1`, `TextInputFiles_FileMngSubmitPath3F4Kind6`, `TextInputFiles_SetVtable10337C60`, `operator_delete`
- `StAvatarInfo_SubmitInfoBinIfChanged` calls `Allocator_Generic`, `TextInputFiles_FileMngSubmitPath3F4Kind3`
- `StAvatar_LoadInfo0` calls `StAvatar_LoadInfoFile`
- `StAvatarInfo_SendBytePairKind0` calls `StAvatarInfo_SubmitInfoBinIfObjSet`
- `StAvatar_LoadInfo2` calls `StAvatar_LoadInfoFile`
- `StAvatarInfo_SendBytePairKind2` calls `StAvatarInfo_SubmitInfoBinIfObjSet`
