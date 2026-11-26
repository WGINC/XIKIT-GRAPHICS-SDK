# CMoTask

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoTask.cpp`.

43 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoTask::GetRuntimeClass_variant0` | 0x10010310 | 6 | yes | - | - | - |
| `CMoTask::Slot7DoNothing` | 0x10011920 | 1 | yes | - | The default of virtual slot 7: does nothing. (reviewed as game_10011920) | low |
| `CMoTask::Slot9DoNothing` | 0x10011930 | 1 | yes | - | The default of virtual slot 9: does nothing. (reviewed as game_10011930) | low |
| `CMoTask::Slot10DoNothing` | 0x10011940 | 3 | yes | - | The default of virtual slot 10: takes one argument and does nothing. (reviewed as game_10011940) | low |
| `CMoTask::GetRuntimeClass_variant1` | 0x1001B800 | 6 | yes | - | - | - |
| `CMoTask::GetRuntimeClass_variant2` | 0x1002C950 | 6 | yes | - | - | - |
| `CMoTask::CtorByMode` | 0x10035A00 | 186 | yes | - | Constructs a mode task, replacing the one held for its mode. (reviewed as game_10035A00) | low |
| `CMoTask::CreateMode2` | 0x10035D40 | 69 | yes | - | Allocates a task and starts it in mode 2. (reviewed as game_10035D40) | low |
| `CMoTask::CreateMode1` | 0x10035D90 | 69 | yes | - | Allocates a task and starts it in mode 1. (reviewed as game_10035D90) | low |
| `CMoTask::CreateMode4` | 0x10035DE0 | 69 | yes | - | Allocates a task and starts it in mode 4. (reviewed as game_10035DE0) | low |
| `CMoTask::GetRuntimeClass_variant3` | 0x10037280 | 6 | yes | - | - | - |
| `CMoTask::GetRuntimeClass_variant4` | 0x1003CC60 | 6 | yes | - | - | - |
| `CMoTask::Slot8ReturnFalse` | 0x10042640 | 3 | yes | - | The default of virtual slot 8: returns false. (reviewed as game_10042640) | low |
| `CMoTask::Restart` | 0x10053370 | 213 | yes | - | Restarts the task, replacing its current child task with a new one. (reviewed as game_10053370) | low |
| `CMoTask::GetRuntimeClass_variant5` | 0x10055550 | 6 | yes | - | - | - |
| `CMoTask::GetRuntimeClass_variant6` | 0x10056930 | 6 | yes | - | - | - |
| `CMoTask::GetRuntimeClass_variant7` | 0x10056950 | 6 | yes | - | - | - |
| `CMoTask::GetRuntimeClass_variant8` | 0x10056970 | 6 | yes | - | - | - |
| `CMoTask::GetRuntimeClass_variant9` | 0x10056990 | 6 | yes | - | - | - |
| `CMoTask::GetRuntimeClass_variant10` | 0x100569B0 | 6 | yes | - | - | - |
| `CMoTask::GetRuntimeClass_variant11` | 0x10057080 | 6 | yes | - | - | - |
| `CMoTask::InitVariant12` | 0x10070F40 | 25 | yes | - | Constructs the base task and sets the variant-12 CMoTask vtable with its field at 0x3C cleared. (reviewed as game_10070F40) | medium |
| `CMoTask::InitAndRegister` | 0x10070F90 | 38 | yes | - | Sets a task's four parameters and registers it with the task manager. (reviewed as game_10070F90) | low |
| `CMoTask::GetRuntimeClass_variant12` | 0x10074730 | 6 | yes | - | - | - |
| `CMoTask::Constructor` | 0x10074740 | 34 | yes | - | - | - |
| `CMoTask::ScalarDeletingDtor` | 0x10074770 | 30 | yes | - | - | - |
| `CMoTask::Destructor` | 0x100747C0 | 14 | yes | - | - | - |
| `CMoTask::DestroyChain` | 0x10074890 | 33 | yes | - | Destroys a task and every task chained after it. (reviewed as game_10074890) | medium |
| `CMoTask::ResetFields` | 0x100748F0 | 48 | yes | - | - | - |
| `CMoTask::Clone` | 0x10074920 | 135 | yes | - | Allocates a copy of a task of the given size and links it into the task system. (reviewed as game_10074920) | medium |
| `CMoTask::Release` | 0x10074AB0 | 21 | yes | - | Releases a task, deleting it when its owner flag is set. (reviewed as game_10074AB0) | medium |
| `CMoTask::DetachAndRecycle` | 0x10074AD0 | 108 | yes | - | Removes a task from its list, destroys its chained tasks and hands the task back to the manager at 0x1047D140, decrementing its count. (reviewed as game_10074AD0) | low |
| `CMoTask::Dispatch` | 0x10075000 | 26 | yes | - | Calls the task's virtual test and its fallback when the test fails. (reviewed as game_10075000) | low |
| `CMoTask::DrawQuadStates` | 0x10076030 | 1166 | yes | 0 | Draws a textured quad with a fixed render state setup. (reviewed as game_10076030) | low |
| `CMoTask::DrawQuadDynVB` | 0x10076520 | 456 | yes | 0 | Writes a quad into the dynamic vertex buffer and draws it. (reviewed as game_10076520) | low |
| `CMoTask::SetRect30` | 0x10076750 | 30 | yes | - | Copies a four-value rectangle into the task's +0x30 block. (reviewed as game_10076750) | low |
| `CMoTask::GetRuntimeClass_variant13` | 0x10081710 | 6 | yes | - | - | - |
| `CMoTask::GetRuntimeClass_variant14` | 0x10081730 | 6 | yes | - | - | - |
| `CMoTask::GetRuntimeClass_variant15` | 0x10081750 | 6 | yes | - | - | - |
| `CMoTask::GetRuntimeClass_variant16` | 0x10084E50 | 6 | yes | - | - | - |
| `CMoTask::GetRuntimeClass_variant17` | 0x100A8E10 | 6 | yes | - | - | - |
| `CMoTask::GetRuntimeClass_variant18` | 0x100C51A0 | 6 | yes | - | - | - |
| `CMoTask::GetRuntimeClass_variant19` | 0x101773B0 | 6 | yes | - | - | - |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoTask::GetRuntimeClass_variant0` calls nothing directly
- `CMoTask::Slot7DoNothing` calls nothing directly
- `CMoTask::Slot9DoNothing` calls nothing directly
- `CMoTask::Slot10DoNothing` calls nothing directly
- `CMoTask::GetRuntimeClass_variant1` calls nothing directly
- `CMoTask::GetRuntimeClass_variant2` calls nothing directly
- `CMoTask::CtorByMode` calls `CMoTask::Constructor`
- `CMoTask::CreateMode2` calls `Mem_AllocFromArea`, `CMoTask::ResetFields`, `CMoTask::CtorByMode`, `game_100749B0`
- `CMoTask::CreateMode1` calls `Mem_AllocFromArea`, `CMoTask::ResetFields`, `CMoTask::CtorByMode`, `game_100749B0`
- `CMoTask::CreateMode4` calls `Mem_AllocFromArea`, `CMoTask::ResetFields`, `CMoTask::CtorByMode`, `game_100749B0`
- `CMoTask::GetRuntimeClass_variant3` calls nothing directly
- `CMoTask::GetRuntimeClass_variant4` calls nothing directly
- `CMoTask::Slot8ReturnFalse` calls nothing directly
- `CMoTask::Restart` calls `Mem_AllocFromArea`, `CMoTask::ResetFields`, `CMoTask::Constructor`, `game_10074A00`
- `CMoTask::GetRuntimeClass_variant5` calls nothing directly
- `CMoTask::GetRuntimeClass_variant6` calls nothing directly
- `CMoTask::GetRuntimeClass_variant7` calls nothing directly
- `CMoTask::GetRuntimeClass_variant8` calls nothing directly
- `CMoTask::GetRuntimeClass_variant9` calls nothing directly
- `CMoTask::GetRuntimeClass_variant10` calls nothing directly
- `CMoTask::GetRuntimeClass_variant11` calls nothing directly
- `CMoTask::InitVariant12` calls `CMoTask::Constructor`
- `CMoTask::InitAndRegister` calls `game_100749B0`
- `CMoTask::GetRuntimeClass_variant12` calls nothing directly
- `CMoTask::Constructor` calls `CMoTask::ResetFields`, `game_100749F0`
- `CMoTask::ScalarDeletingDtor` calls `CMoTask::Destructor`, `SharedDeleteHelper`
- `CMoTask::Destructor` calls `CMoTask::DetachAndRecycle`
- `CMoTask::DestroyChain` calls nothing directly
- `CMoTask::ResetFields` calls nothing directly
- `CMoTask::Clone` calls `Mem_AllocFromArea`, `CMoTask::Constructor`, `game_10074850`, `game_100749F0`
- `CMoTask::Release` calls `CMoTask::DetachAndRecycle`
- `CMoTask::DetachAndRecycle` calls `Task_Remove`, `CMoTask::DestroyChain`, `game_10074A20`
- `CMoTask::Dispatch` calls nothing directly
- `CMoTask::DrawQuadStates` calls `TexRef_SetTexture`, `CDx::DrawPrimitiveUP`
- `CMoTask::DrawQuadDynVB` calls `DynVB_Reserve`, `DynVB_Lock`, `DynVB_Unlock`, `TexRef_SetTexture`, `CMoVuElem_Draw`
- `CMoTask::SetRect30` calls nothing directly
- `CMoTask::GetRuntimeClass_variant13` calls nothing directly
- `CMoTask::GetRuntimeClass_variant14` calls nothing directly
- `CMoTask::GetRuntimeClass_variant15` calls nothing directly
- `CMoTask::GetRuntimeClass_variant16` calls nothing directly
- `CMoTask::GetRuntimeClass_variant17` calls nothing directly
- `CMoTask::GetRuntimeClass_variant18` calls nothing directly
- `CMoTask::GetRuntimeClass_variant19` calls nothing directly
