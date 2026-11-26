# Acter

Group: `Acter` (by the file name only). Source: `sdk/tree_src/Acter.cpp`.

Why the file has this name (data/unit_names.json): Acter_* and ActerBuff_* (the actor buffer: update records, motion timers, globals), the strings "UserName:%s UniqueNo:%d", "/sitchair off"

126 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `Acter_IsParamBelow901` | 0x10086FC0 | 12 | yes | - | Returns 1 when its second argument is below 0x901, keeping the first argument's high bits. | low |
| `Acter_FindByField78Fwd` | 0x10086FD0 | 5 | yes | - | Calls ActerBuff_FindByField78_10086FE0 with its argument. | low |
| `ActerBuff_FindByField78` | 0x10086FE0 | 34 | yes | - | Finds the ActerBuff table entry whose +0x78 field equals the argument. | low |
| `Acter_GetGlobalFlag` | 0x10087010 | 23 | yes | - | Returns a value from one of two globals, preferring the first when it is set. | low |
| `Acter_IsEvent` | 0x10087060 | 14 | yes | - | Returns the result of IsEvent for the given argument with 0xff as the first operand. | low |
| `IsEvent` | 0x10087070 | 112 | yes | - | - | - |
| `Menu_HasAnyFlag` | 0x100870E0 | 42 | yes | - | Returns 1 when either global mask shares a bit with the arguments. | low |
| `Acter_GetGlobalByte` | 0x10087110 | 6 | yes | - | Returns a byte global, keeping the argument's high bits. | low |
| `Help_UpdateFromFlags` | 0x100872C0 | 237 | yes | - | Syncs the help object at game_105781F8 with the session flag bits. | medium |
| `Acter_UpdateObject10578184` | 0x100873B0 | 188 | yes | - | Per-frame update of the object at g_10578184, which a callee ties to the 'cnttime' menu. | low |
| `Acter_TargetClearAndSetFlag53` | 0x100875C0 | 11 | yes | - | Target_ClearAndSetFlag53 on the global target manager. | high |
| `Acter_IsIdMatchGlobal` | 0x100875D0 | 31 | yes | - | Returns 1 when the id at +0x1fa of the object from game_101CC4F0 equals a global. | low |
| `Acter_GetByteIfIdMatch` | 0x100875F0 | 20 | yes | - | Returns a byte global when the id test of fn_100875D0 passes, else 0. | low |
| `Acter_GetDwordIfIdMatch` | 0x10087610 | 18 | yes | - | Returns a dword global when the id test of fn_100875D0 passes, else 0. | low |
| `Acter_GetGlobal10482F38IfIdMatch` | 0x10087630 | 18 | yes | - | Returns the value at 0x10482F38 if the acter id matches the global one, else 0. | low |
| `Acter_IsWord104802BASet` | 0x10087650 | 12 | yes | - | Returns whether the word at 0x104802BA is nonzero. | low |
| `Acter_GetMaskedFlagByte` | 0x10087660 | 8 | yes | - | Returns a byte global with bits 1 to 7 cleared, keeping the argument's high bits. | low |
| `Acter_IsGlobalNonzero` | 0x10087670 | 11 | yes | - | Returns 1 when the dword global g_10480818 is nonzero. | low |
| `Acter_GetDword10480800IfFlag` | 0x10087690 | 18 | yes | - | Returns the dword at 0x10480800 when the masked flag byte is set, else 0. | high |
| `Acter_GetByte10480824IfFlag` | 0x100876B0 | 18 | yes | - | Returns the byte at 0x10480824 when the masked flag byte is set, else 0. | high |
| `Acter_GetTable10480828IfFlag` | 0x10087760 | 15 | yes | - | Returns the table at 0x10480828 when the masked flag byte is set, else null. | high |
| `Acter_GetByte10480825IfSet` | 0x10087830 | 18 | yes | - | Returns the byte at 0x10480825 when the global is non-zero, else 0. | high |
| `Acter_GetByte10480826IfFlag` | 0x10087890 | 18 | yes | - | Returns the byte at 0x10480826 when game_10087680 is true, else 0. | high |
| `Acter_IsByte10483158Set` | 0x10087B20 | 11 | yes | - | Returns whether the byte at 0x10483158 is set. | low |
| `Acter_ApplyPair1EC1F4` | 0x10087D40 | 51 | yes | - | Passes the actor's two values at +0x1EC/+0x1F4 to its model object (+0xA0) through vtable slot 0x29C. | medium |
| `Acter_ResetMotionCounters` | 0x10087E40 | 63 | yes | - | Clears two motion counters of the actor, advancing its motion queue first when the flag and type test pass. | low |
| `Acter_AdvanceMotionTimer` | 0x10087E80 | 120 | yes | - | Advances the actor's motion timer by the camera frame scale, or resets its counters when the flag is clear. | low |
| `Acter_UpdateModelPoint848` | 0x10087F00 | 827 | yes | - | Sets (from another actor or from its own angles) or clears the point its model object keeps at +0x848. | low |
| `Acter_UpdateByKind170NotGroup38` | 0x100883E0 | 1780 | yes | - | Frame-scaled per-actor update chosen by the kind at +0x170; what it updates is not established. | low |
| `Acter_UpdateByKind170NotGroup06` | 0x10089100 | 1769 | yes | - | Second frame-scaled per-actor update chosen by +0x170, the counterpart of fn_100883E0 with its own globals. | low |
| `Call1008A0E0With2` | 0x1008A0D0 | 9 | yes | - | - | - |
| `Camera_SetField30` | 0x1008A0E0 | 60 | yes | - | Stores a value in the camera object at +0x30 and in a cached global, when it changes. | medium |
| `Actor_SetDefaultMotionTags` | 0x1008A160 | 51 | yes | - | Stores the default motion tag strings in the actor. | medium |
| `ActerBuff_FindByMaskedId` | 0x1008A8E0 | 69 | yes | - | Finds the ActerBuff entry whose 10-bit id matches the argument, or returns 0. | low |
| `ActerBuff_FindById` | 0x1008A930 | 52 | yes | - | Finds the ActerBuff entry whose id equals the argument, or returns 0. | medium |
| `Acter_StartAutoRunFromZoneMap` | 0x1008B100 | 111 | yes | - | When the zone map returns an entry for the actor's position, starts auto-running with it once and sets scene state 0x70. | medium |
| `Actor_FindByNameEntry` | 0x1008B270 | 49 | yes | - | Returns the entry at +0x74 of an actor whose name at +0x7c matches the given name, or 0. | medium |
| `Actor_CompareNames` | 0x1008B2B0 | 208 | yes | - | Compares two actor names, optionally after converting them to legal PC names, and returns 1 when they are equal. | medium |
| `Actor_FindByField78Entry` | 0x1008B380 | 22 | yes | - | Returns the entry at +0x74 of an actor whose field at +0x78 equals the argument, or 0. | low |
| `Acter_UpdateOnePart1008CD90` | 0x1008CD90 | 2932 | yes | - | A large frame-scaled position/vector update step of Acter_UpdateOne; its exact role is not established. | low |
| `Acter_SetModelField78FromTable` | 0x1008DB40 | 1417 | yes | - | Sets the model's value at +0x78 from the table at 0x104E1B98 by the actor's index at +0x1D8, or by its state otherwise. | medium |
| `CXiActor_IsIdAbove6ff` | 0x1008E130 | 10 | yes | - | Returns 1 when the actor's short id at +0x74 is above 0x6ff. | low |
| `Acter_GetActerAt2A4` | 0x1008E220 | 17 | yes | - | Returns the acter whose index is stored at +0x2A4. | low |
| `Actor_FindByField2a4` | 0x1008E260 | 47 | yes | - | Finds the table entry whose id equals the actor's short at +0x2a4, or returns 0. | low |
| `Acter_UpdateFlags120Bit23` | 0x1008E4D0 | 507 | yes | 8 | Per-frame update around flag bit 23 of +0x120 and the model; its meaning is not established. | low |
| `Acter_PlayChorMotion` | 0x1008E740 | 297 | yes | - | Starts the motion with four-character code 'chor' on the actor's two model objects. | medium |
| `Acter_IsBytes1FFBothIn89NotEqual` | 0x1008E8D0 | 72 | yes | - | Returns 1 when the actor and the argument both have a +0x1FF byte of 8 or 9 and the two bytes differ. | low |
| `Acter_UpdateOne` | 0x1008E9A0 | 1017 | yes | 6 | Runs the per-frame step for one actor and inserts it into its distance bucket. | low |
| `Acter_ReleaseEventRecord` | 0x1008EE30 | 293 | yes | - | Selects the actor's motion tags, then restores and frees its event record at +0xD4 and clears its state bits. | medium |
| `Acter_CallVt180IfState` | 0x1008F2A0 | 57 | yes | - | Calls virtual slot 0x180 of the sub-object at +0xA0 when the actor's flag and state byte match. | low |
| `Acter_ReleaseSlotD0` | 0x100926C0 | 80 | yes | - | Releases the object at +0xD0 and clears its flag when flag 0x80000 is set. | low |
| `Acter_ReleaseSlotCC` | 0x10092710 | 80 | yes | - | Releases the object at +0xCC and clears its flag when flag 0x40000 is set. | low |
| `Acter_ReleaseTenSlots` | 0x10092760 | 23 | yes | - | Releases slots 0 through 9 by calling the per-slot release for each index. | medium |
| `Acter_ReleaseSlotByIndex` | 0x10092780 | 119 | yes | - | Releases the indexed object and its table entry when the matching flag bit is set. | medium |
| `Acter_ReleaseSlotA8` | 0x10092800 | 97 | yes | - | Releases the object at +0xA8 when flag 0x20000 is set and clears the word at +0x202. | low |
| `Acter_ReleaseSlotA4` | 0x10092870 | 139 | yes | - | Releases the object at +0xA4 and calls a helper for flag 0x400 before it. | low |
| `Acter_ReleaseAllSlots` | 0x10092900 | 155 | yes | - | Runs every slot release in order and then clears the state flags. | medium |
| `Acter_CopyPosToCached` | 0x100929A0 | 41 | yes | - | Copies the position and rotation block to the cached copy and calls a helper. | low |
| `Acter_SnapHeightToZoneMap` | 0x100929D0 | 329 | yes | - | Snaps the actor's height to the zone map and copies the position into its sub-object. | medium |
| `Acter_CopyPosAndAnglesToActorA0` | 0x10092C20 | 869 | yes | - | Copies the acter's position and its three angles (wrapped to about [-pi, pi]) into the actor object at +0xA0. | low |
| `Acter_CopyPosAndSnap` | 0x100933C0 | 110 | yes | - | Copies the position into the cached copy and snaps it to the zone map when the flag allows. | low |
| `Acter_CopySixDwordsTo7C` | 0x10093430 | 40 | yes | - | Copies six dwords into the block at +0x7C when a word at +0x210 is zero. | low |
| `Acter_ResetGlobals` | 0x10093720 | 776 | yes | - | - | - |
| `Acter_ClearGlobalBlocks` | 0x10093A30 | 84 | yes | - | Clears the module's global arrays and flags. | low |
| `Acter_ResetGlobalSentinels` | 0x10093A90 | 55 | yes | - | Clears a global block and sets two sentinel words to -1. | low |
| `Acter_ClearGlobalBlock182` | 0x10093AD0 | 17 | yes | - | Zeroes the global block at g_1047FEB8. | low |
| `Acter_ClearGlobalBlock2C` | 0x10093AF0 | 17 | yes | - | Zeroes the global block at g_10480800. | low |
| `Acter_ClearGlobalBlock23` | 0x10093B10 | 17 | yes | - | Zeroes the global block at g_10480900. | low |
| `Acter_ClearGlobalBlock71` | 0x10093B30 | 17 | yes | - | Zeroes the global block at g_10482F98. | low |
| `Acter_ClearTable10488B08` | 0x10093B50 | 17 | yes | - | Zeroes the 128-dword table at 0x10488B08. | low |
| `Acter_ShutdownGlobals` | 0x10093B70 | 557 | yes | - | Tears down the module's global objects and actor slots. | medium |
| `Acter_Nop` | 0x10093DA0 | 1 | yes | - | Does nothing. | low |
| `CallMotd` | 0x100955D0 | 48 | yes | - | - | - |
| `Acter_IsState5` | 0x10095680 | 26 | yes | - | Tests whether the actor's state is 5. | medium |
| `Acter_IsState55` | 0x100956A0 | 26 | yes | - | Tests whether the actor's state is 0x55. | medium |
| `Acter_IsStateGroup06Or38` | 0x100956C0 | 39 | yes | - | Tests whether the actor's state is in the group of fn_100956F0 or of fn_10095750. | medium |
| `Acter_IsStateGroup06` | 0x100956F0 | 82 | yes | - | Tests whether the actor's state is in its state group of 11 values. | medium |
| `Acter_IsStateGroup38` | 0x10095750 | 62 | yes | - | Tests whether the actor's state is in the range 0x38 to 0x3E. | medium |
| `Acter_IsStateGroup3F` | 0x10095790 | 132 | yes | - | Tests whether the actor's state is in the range 0x3F to 0x53. | medium |
| `Acter_CanClearPendingState` | 0x10095850 | 173 | yes | - | Condition Acter_ClearPendingState tests; true only when none of a list of state flags and kinds hold. | low |
| `Acter_UpdateAllLists` | 0x10095900 | 1137 | yes | 5 | Runs the per-frame update over the actor slot and list entries, bounded by a count. | low |
| `Acter_ClearPendingState` | 0x10095DD0 | 84 | yes | - | Clears a pending state flag and releases the slots when the pending word is set. | low |
| `Acter_ClearPending272` | 0x10095E30 | 88 | yes | - | Clears a pending state at +0x272 and +0x274 under the state tests. | low |
| `Acter_UpdateActionState` | 0x10095E90 | 327 | yes | - | Updates the actor's action state from its state value and flags. | low |
| `Acter_OffsetTableEntry` | 0x10096220 | 48 | yes | - | Returns the entry at the index of a table of offsets, or 0 when the index is out of range. | medium |
| `Acter_OffsetTableLastIndex` | 0x10096250 | 22 | yes | - | Returns the last valid index of a table of offsets, or -1 for none. | medium |
| `Acter_NoneOfIdsInTable` | 0x10096270 | 76 | yes | - | Returns true when none of the ids 0, 2, 7, 10, 0x1C is in the table at 0x10485A30. | high |
| `Acter_LookupTable10489908` | 0x100962C0 | 21 | yes | - | Returns the entry of the offset table at 0x10489908 for the index. | medium |
| `Acter_LookupTable10487E58` | 0x100962F0 | 21 | yes | - | Returns the entry of the offset table at 0x10487E58 for the index. | medium |
| `Acter_LookupTable10487E64` | 0x10096350 | 21 | yes | - | Returns the entry of the offset table at 0x10487E64 for the index. | medium |
| `Acter_LookupTable10487E68` | 0x10096380 | 21 | yes | - | Returns the entry of the offset table at 0x10487E68 for the index. | medium |
| `Acter_LookupTable10487E70` | 0x100963B0 | 21 | yes | - | Returns the entry of the offset table at 0x10487E70 for the index. | medium |
| `Acter_LookupTable10487E7C` | 0x100963E0 | 28 | yes | - | Returns the entry of the offset table at 0x10487E7C for the index. | medium |
| `Acter_LookupTable10487E84` | 0x10096410 | 21 | yes | - | Returns the entry of the offset table at 0x10487E84 for the index. | medium |
| `Acter_LookupTable10487E80` | 0x10096470 | 21 | yes | - | Returns the entry of the offset table at 0x10487E80 for the index. | medium |
| `Acter_UpdateFrame` | 0x10096640 | 1613 | yes | 6 | Runs the per-frame update of the actor table, with the camera, target and network steps around it. | low |
| `Acter_UpdateSkeletonParts` | 0x100973F0 | 261 | yes | - | Runs the model's per-part routines (game_100CF100 and related) when the actor's flags call for it. | low |
| `Acter_TestFlagsAndUpdateParts` | 0x100977F0 | 79 | yes | - | Under the acter's flag conditions, runs the skeleton part update and returns whether it returned 0. | low |
| `Entity_BuildDisplayName` | 0x10097840 | 353 | yes | - | - | - |
| `Entity_GetIndexedPtr` | 0x10097A40 | 28 | yes | - | - | - |
| `Acter_HasEntryForWord40D7C` | 0x10097B40 | 11 | yes | - | Returns whether Acter_FindEntryForWord40D7C finds an entry. | low |
| `Acter_FindEntryForWord40D7C` | 0x10097B50 | 105 | yes | - | Returns the 8-byte entry of the table at 0x1035B630 whose four ids include a word of the object at 0x104DFD98, or 0. | low |
| `Acter_GetByte40DB4ByKind` | 0x10097BC0 | 230 | yes | - | Returns the byte at DAT_104DFD98+0x40DB4 or a constant chosen by the value at +0x40D80. | medium |
| `Acter_IsFlag40DB6OrState17` | 0x10097D50 | 33 | yes | - | Returns whether the short at DAT_104DFD98+0x40DB6 is set or the byte at 0x10485640 is 0x17. | high |
| `Acter_TestFlagTable` | 0x10097E50 | 35 | yes | - | Tests a bit mask against an entry of the flag table at g_1047FEB8. | low |
| `Acter_TestFlagBit` | 0x10097E80 | 40 | yes | - | Returns whether bit n of the flag table at 0x1047FEB8 is set. | medium |
| `Acter_IsSpecialIdRange` | 0x10098180 | 130 | yes | - | Tests whether the actor's id word at +0xFC lies in one of several fixed ranges. | low |
| `Acter_ActerTestEE120` | 0x10098210 | 270 | yes | - | A flag test on an actor's state byte +0xEE and flag words; its meaning is not established. | low |
| `Acter_GetPartnerIfKind` | 0x100983A0 | 76 | yes | - | Returns the indexed actor's sub-object when it is of the expected class and flagged. | low |
| `Acter_GetTable10485830IfBit2` | 0x100991F0 | 17 | yes | - | Returns the table at 0x10485830 when bit 2 of 0x10485824 is set, else null. | high |
| `Acter_ResolveEntryNames` | 0x10099730 | 119 | yes | - | Fills in the missing name strings of the 20 entries at DAT_104DFD98+0x57D8 by looking up their ids. | medium |
| `Acter_UpdateFrame997B0` | 0x100997B0 | 226 | yes | - | Per-frame step: resolves entry names and refreshes the 16-entry arrays at 0x10483118. | low |
| `Acter_IsByte123Mask7In234` | 0x1009AAF0 | 43 | yes | - | Tests whether the state is not 0x55 and the low three bits of the byte at +0x123 are 2, 3 or 4. | low |
| `Acter_IsByte123Low3Bits3` | 0x1009AB20 | 14 | yes | - | Returns whether the low three bits of the acter's byte at +0x123 are 3. | low |
| `Acter_SetFieldsAt134And138` | 0x1009ADE0 | 210 | yes | - | Stores the parameters into bit fields of +0x134 and +0x138, looks up the index at +0x2A6, and releases the CC slot when the fields change. | low |
| `Acter_GetField138Clamped` | 0x1009AEC0 | 95 | yes | - | Returns a float from 0 to 40 computed from the actor's field at +0x138. | low |
| `Acter_SetFlagBits138` | 0x1009AF60 | 113 | yes | - | Sets three bit fields in the flags at +0x138. | low |
| `Acter_ClearGlobals10488800` | 0x1009F3F0 | 17 | yes | - | Clears eight global dwords. | low |
| `Acter_IndexIfMatchesKinds` | 0x100A0010 | 109 | yes | - | Returns the acter index if that acter is of one of four given kinds (by its fields), else 0. | low |
| `Acter_FindFirstMatchingKinds` | 0x100A0080 | 52 | yes | - | Returns the index of the first acter of the four kinds, preferring the one the object at 0x104DFD98 names. | low |
| `Acter_FindStringById` | 0x100A1770 | 126 | yes | - | Returns the display string for an acter id, searching the acter list first and then the acter buffers. | medium |
| `Acter_SetFlag8000OfFound` | 0x100A17F0 | 47 | yes | - | Sets or clears flag 0x8000 of the first acter of the four kinds. | low |
| `Acter_CheckIdAgainstBlockBits` | 0x100A19B0 | 68 | yes | - | Compares a table value for an id with two bits of a zone-state block. | low |
| `Acter_MatchActorNameOrKind` | 0x100A1A00 | 152 | yes | - | Tests a string against the name of the actor from game_101CC4F0 and, failing that, with fn_100E0A50 for certain kinds. | low |
| `ActerBuff_GetStringByIdLookup` | 0x100A1D50 | 98 | yes | - | Returns the display string for an acter id from the acter buffers, falling back to a lookup. | medium |
| `Acter_ConstructTask1032D6D4` | 0x100A2790 | 82 | yes | - | Constructs the task with vtable 0x1032D6D4 for a record and makes it the current one at 0x10487F08 if there is none. | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `Acter_IsParamBelow901` calls nothing directly
- `Acter_FindByField78Fwd` calls `ActerBuff_FindByField78`
- `ActerBuff_FindByField78` calls nothing directly
- `Acter_GetGlobalFlag` calls nothing directly
- `Acter_IsEvent` calls `IsEvent`
- `IsEvent` calls `Acter_GetActerAt10485F7A`, `Acter_IsStateGroup06Or38`
- `Menu_HasAnyFlag` calls nothing directly
- `Acter_GetGlobalByte` calls nothing directly
- `Help_UpdateFromFlags` calls `NetCellFont_GetFlags`, `game_10221340`, `game_102212E0`, `game_10221230`, `game_10221320`, `game_102212C0`, `game_102211F0`, `game_102213B0`
- `Acter_UpdateObject10578184` calls `game_1012C900`, `Acter_GetDword10480800IfFlag`, `Acter_GetByte10480824IfFlag`, `game_1012C8C0`, `game_1012C8E0`, `game_100876D0`, `game_10087850`, `game_10087870`, `TargetMenu_GetMessageFwd`, `game_10139F40`, `game_100876E0`, `game_10139FB0`
- `Acter_TargetClearAndSetFlag53` calls `Target_ClearAndSetFlag53`
- `Acter_IsIdMatchGlobal` calls `Acter_GetActerAt10485F7A`
- `Acter_GetByteIfIdMatch` calls `Acter_IsIdMatchGlobal`
- `Acter_GetDwordIfIdMatch` calls `Acter_IsIdMatchGlobal`
- `Acter_GetGlobal10482F38IfIdMatch` calls `Acter_IsIdMatchGlobal`
- `Acter_IsWord104802BASet` calls nothing directly
- `Acter_GetMaskedFlagByte` calls nothing directly
- `Acter_IsGlobalNonzero` calls nothing directly
- `Acter_GetDword10480800IfFlag` calls `Acter_GetMaskedFlagByte`
- `Acter_GetByte10480824IfFlag` calls `Acter_GetMaskedFlagByte`
- `Acter_GetTable10480828IfFlag` calls `Acter_GetMaskedFlagByte`
- `Acter_GetByte10480825IfSet` calls `Acter_IsGlobalNonzero`
- `Acter_GetByte10480826IfFlag` calls `game_10087680`
- `Acter_IsByte10483158Set` calls nothing directly
- `Acter_ApplyPair1EC1F4` calls nothing directly
- `Acter_ResetMotionCounters` calls `CYyObject_IsKindOf`, `CXiSkeletonActor::AdvanceMotionQueue`
- `Acter_AdvanceMotionTimer` calls `Camera_GetFrameScale`, `game_10311C2C`, `CYyObject_IsKindOf`, `game_100CE0E0`, `Acter_ResetMotionCounters`
- `Acter_UpdateModelPoint848` calls `CYyObject_IsKindOf`, `MathVector_ReturnThis`, `Mat4_SetIdentity`, `Mat4_PostRotateZ`, `Mat4_PostRotateY`, `Mat4_PostRotateX`, `Mat4_SetTranslation`, `Mat4_TransformPoint`, `MathVector_Nop`
- `Acter_UpdateByKind170NotGroup38` calls `Acter_IsStateGroup38`, `Camera_SetField30`, `Camera_GetFrameScale`, `game_10311C2C`, `game_10088B50`, `XI_PACKET_10088320 (left out)`, `game_10088B20`, `game_10177730`, `NetCellFont_ClearGlobalLists2150And2154`, `game_10088BD0`, `game_10088BB0`, `operator_delete`
- `Acter_UpdateByKind170NotGroup06` calls `Acter_IsStateGroup06`, `game_10089FF0`, `Camera_GetFrameScale`, `game_10311C2C`, `game_10088B50`, `XI_PACKET_10088380 (left out)`, `game_10088B20`, `game_10177730`, `NetCellFont_ClearGlobalLists2150And2154`, `game_10089850`, `game_10088BB0`, `operator_delete`
- `Call1008A0E0With2` calls `Camera_SetField30`
- `Camera_SetField30` calls `game_10311FF1`
- `Actor_SetDefaultMotionTags` calls nothing directly
- `ActerBuff_FindByMaskedId` calls nothing directly
- `ActerBuff_FindById` calls nothing directly
- `Acter_StartAutoRunFromZoneMap` calls `game_10181510`, `XiControlActor_SetAutoRunning`
- `Actor_FindByNameEntry` calls `Actor_CompareNames`
- `Actor_CompareNames` calls `TaskAndTextArgs_MapNameLetters`
- `Actor_FindByField78Entry` calls nothing directly
- `Acter_UpdateOnePart1008CD90` calls `game_1008D910`, `game_1008AF60`, `NetCellFont_GetIdPair`, `Vec4_Copy`, `XiZone::DrawMarkerForward`, `CYyObject_IsKindOf`, `Vec3_Copy`, `game_100814F0`, `TargetMenu_SetTargetMode`, `XiControlActor_UpdateCamera`, `Camera_GetFrameScale`, `game_10311C2C`, `Acter_CopyPosAndAnglesToActorA0`, `Acter_CopyPosToCached`, `CXiControlActor_SetVec4`
- `Acter_SetModelField78FromTable` calls `game_10097A60`, `Acter_GetActerAt10485F7A`, `CXiActor::IsField78HighZero`, `Acter_IsBytes1FFBothIn89NotEqual`, `game_1008E920`, `game_1008E180`, `NetCellFont_SetByte9800AndGetEntry`, `NetCellFont_SelectNext`, `Vec3_Call100275D0`, `CXiActor::IsFlag1d0Clear`, `game_1008E240`
- `CXiActor_IsIdAbove6ff` calls nothing directly
- `Acter_GetActerAt2A4` calls nothing directly
- `Actor_FindByField2a4` calls `NetCellFont_SetByte9800AndGetEntry`, `NetCellFont_SelectNext`
- `Acter_UpdateFlags120Bit23` calls `Acter_GetActerAt10485F7A`, `game_10085A10`, `game_10085A50`, `TextInputFiles_GetSetting99`, `NetCellFont_SetByte9800AndGetEntry`, `NetCellFont_SelectNext`
- `Acter_PlayChorMotion` calls `XiControlActor_SetAutoRunning`, `game_100D65B0`, `XI_PACKET_10088270 (left out)`
- `Acter_IsBytes1FFBothIn89NotEqual` calls nothing directly
- `Acter_UpdateOne` calls `Acter_GetActerAt10485F7A`, `XI_PACKET_100AEC70 (left out)`, `Camera_GetFrameScale`, `game_10311C2C`, `game_1008E290`, `Acter_SetModelField78FromTable`, `game_1008E3F0`, `Acter_UpdateOnePart1008CD90`, `CXiActor::TickRandomTimer`, `Acter_UpdateModelPoint848`, `Acter_AdvanceMotionTimer`, `Acter_UpdateByKind170NotGroup38`, `Acter_UpdateByKind170NotGroup06`, `Acter_PlayChorMotion`, `game_1008E870`, `XI_PACKET_1009F4C0 (left out)`, `XI_PACKET_1008B410 (left out)`, `game_1008B460`, `CXiSkeletonActor_IsReadCompleteBody`, `NetCellFont_GetFlags`, `game_100FC2B0`, `YkWindows_CloseIfAt14`, `YkWindows_DestroyDrawMenuIfAt14`, `game_10160930`, `game_1008C480`, `game_1008C6C0`, `XiEvent_EventIdle`, `NetCellFont_GetIdPair`, `Acter_UpdateFlags120Bit23`
- `Acter_ReleaseEventRecord` calls `CXiActor::SelectMotionTags`, `XiEvent_RestoreActer`, `operator_delete`
- `Acter_CallVt180IfState` calls nothing directly
- `Acter_ReleaseSlotD0` calls nothing directly
- `Acter_ReleaseSlotCC` calls nothing directly
- `Acter_ReleaseTenSlots` calls `Acter_ReleaseSlotByIndex`
- `Acter_ReleaseSlotByIndex` calls nothing directly
- `Acter_ReleaseSlotA8` calls nothing directly
- `Acter_ReleaseSlotA4` calls `CXiSkeletonActor_ReleaseListEntriesMatching`
- `Acter_ReleaseAllSlots` calls `Acter_ReleaseSlotA4`, `Acter_ReleaseSlotA8`, `Acter_ReleaseTenSlots`, `Acter_ReleaseSlotCC`, `Acter_ReleaseSlotD0`, `CXiSkeletonActor_ReleaseListEntriesMatching`
- `Acter_CopyPosToCached` calls `Acter_CopyPosAndAnglesToActorA0`
- `Acter_SnapHeightToZoneMap` calls `Acter_GetActerAt10485F7A`, `ZoneMap_QueryBoxHeightBand`, `ZoneMap_QueryBoxHeightByRadius`, `Vec4_Copy`, `CXiControlActor_SetVec4`
- `Acter_CopyPosAndAnglesToActorA0` calls `Vec4_Copy`, `CXiControlActor_SetVec4`
- `Acter_CopyPosAndSnap` calls `Acter_SnapHeightToZoneMap`, `Acter_CopyPosAndAnglesToActorA0`
- `Acter_CopySixDwordsTo7C` calls nothing directly
- `Acter_ResetGlobals` calls `XiEvent_GetSingleton_100C3190`, `XiEvent_SetFlag8`, `MenuMng_ReinitState`, `Acter_ClearGlobalBlocks`, `Acter_ResetGlobalSentinels`, `Acter_ClearGlobalBlock182`, `Acter_ClearGlobalBlock2C`, `Acter_ClearGlobalBlock23`, `Acter_ClearGlobalBlock71`, `Acter_ClearTable10488B08`, `AuctionMenu_ResetRecords`, `Scene_GetTableValue`, `YkCommon_Load`
- `Acter_ClearGlobalBlocks` calls nothing directly
- `Acter_ResetGlobalSentinels` calls nothing directly
- `Acter_ClearGlobalBlock182` calls nothing directly
- `Acter_ClearGlobalBlock2C` calls nothing directly
- `Acter_ClearGlobalBlock23` calls nothing directly
- `Acter_ClearGlobalBlock71` calls nothing directly
- `Acter_ClearTable10488B08` calls nothing directly
- `Acter_ShutdownGlobals` calls `LobbyThread_SendCmd11`, `Target_Reset`, `YkMyroom::Destructor`, `thunk_Mem_FreeBlockMergeNeighbours_as_v0`, `operator_delete`, `XiEvent_GetSingleton_100C3190`, `XiEvent_Clear`, `XiEvent_ResetActersAndGlobals`, `XI_PACKET_1008ABE0 (left out)`, `game_1015EEA0`, `CXiActor::Destroy`
- `Acter_Nop` calls nothing directly
- `CallMotd` calls `Command_RunLine`
- `Acter_IsState5` calls nothing directly
- `Acter_IsState55` calls nothing directly
- `Acter_IsStateGroup06Or38` calls `Acter_IsStateGroup06`, `Acter_IsStateGroup38`
- `Acter_IsStateGroup06` calls nothing directly
- `Acter_IsStateGroup38` calls nothing directly
- `Acter_IsStateGroup3F` calls nothing directly
- `Acter_CanClearPendingState` calls `Acter_IsStateGroup06Or38`
- `Acter_UpdateAllLists` calls `game_10095D80`, `Acter_IsEvent`, `CYyObject_IsKindOf`, `game_100C4400`, `Acter_ReleaseAllSlots`, `YkCommon_GetCC4F0ActorByIndexAt1FA`, `game_100961D0`, `game_10096200`, `game_10095DA0`, `Acter_ClearPendingState`, `Acter_ClearPending272`, `Acter_UpdateActionState`, `game_1008F740`, `game_100960F0`, `game_10096040`
- `Acter_ClearPendingState` calls `Acter_CanClearPendingState`, `Acter_ReleaseAllSlots`
- `Acter_ClearPending272` calls `Acter_IsState5`, `Acter_IsState55`, `Acter_IsByte123Mask7In234`, `Acter_ReleaseAllSlots`
- `Acter_UpdateActionState` calls `Acter_IsStateGroup06Or38`, `Acter_IsState5`, `Acter_IsState55`, `Acter_IsStateGroup3F`, `Acter_ReleaseAllSlots`
- `Acter_OffsetTableEntry` calls `Acter_OffsetTableLastIndex`
- `Acter_OffsetTableLastIndex` calls nothing directly
- `Acter_NoneOfIdsInTable` calls `MenuPanels_IsIdInTable10485A30`
- `Acter_LookupTable10489908` calls `Acter_OffsetTableEntry`
- `Acter_LookupTable10487E58` calls `Acter_OffsetTableEntry`
- `Acter_LookupTable10487E64` calls `Acter_OffsetTableEntry`
- `Acter_LookupTable10487E68` calls `Acter_OffsetTableEntry`
- `Acter_LookupTable10487E70` calls `Acter_OffsetTableEntry`
- `Acter_LookupTable10487E7C` calls `Acter_OffsetTableEntry`
- `Acter_LookupTable10487E84` calls `Acter_OffsetTableEntry`
- `Acter_LookupTable10487E80` calls `Acter_OffsetTableEntry`
- `Acter_UpdateFrame` calls `NetCellFont_GetFlags`, `XI_PACKET_10094190 (left out)`, `Acter_GetActerAt10485F7A`, `Camera_SetTargetIfMoved`, `Camera_PlaceRelativeToActor`, `XI_PACKET_10093DB0 (left out)`, `Camera_GetFrameScale`, `game_10311C2C`, `XI_PACKET_1008ABE0 (left out)`, `Cell_SetByte104E1C3E`, `game_100AED00`, `game_100882D0`, `game_100AEA40`, `game_100973B0`, `Acter_ReleaseEventRecord`, `Acter_ReleaseAllSlots`, `game_10095660`, `Acter_StartAutoRunFromZoneMap`, `game_1008B170`, `game_100B37A0`, `game_100BD0E0`, `Acter_UpdateOne`, `Acter_UpdateAllLists`, `SetMusicTrackVolume_B`, `game_100AE960`, `TaskAndTextArgs_ToggleOnKey`, `XI_PACKET_100983F0 (left out)`, `XI_PACKET_100780A0 (left out)`, `game_10096C90`, `game_10093E30`, `game_10093E50`, `game_10097AF0`, `game_100A3D00`, `game_1009F2F0`, `Acter_UpdateFrame997B0`, `game_10087220`, `Help_UpdateFromFlags`, `Acter_UpdateObject10578184`, `NetCellFont_GetWord40DAA`, `NetCellFont_SetWord40DAA`, `NetCellFont_TestCommand36CF60`
- `Acter_UpdateSkeletonParts` calls `Acter_GetActerAt10485F7A`, `game_100CF0B0`, `game_100CF160`, `game_100CF060`, `CXiSkeletonActor::ForParts0To9`
- `Acter_TestFlagsAndUpdateParts` calls `Acter_UpdateSkeletonParts`
- `Entity_BuildDisplayName` calls `Acter_TestFlagsAndUpdateParts`, `game_10097500`, `game_10097730`, `game_100977A0`, `game_10313520`
- `Entity_GetIndexedPtr` calls nothing directly
- `Acter_HasEntryForWord40D7C` calls `Acter_FindEntryForWord40D7C`
- `Acter_FindEntryForWord40D7C` calls nothing directly
- `Acter_GetByte40DB4ByKind` calls nothing directly
- `Acter_IsFlag40DB6OrState17` calls nothing directly
- `Acter_TestFlagTable` calls nothing directly
- `Acter_TestFlagBit` calls `Acter_TestFlagTable`
- `Acter_IsSpecialIdRange` calls nothing directly
- `Acter_ActerTestEE120` calls `Acter_IsSpecialIdRange`
- `Acter_GetPartnerIfKind` calls `CYyObject_IsKindOf`
- `Acter_GetTable10485830IfBit2` calls nothing directly
- `Acter_ResolveEntryNames` calls `TargetMenu_GetCachedOrLoad`, `game_100935C0`
- `Acter_UpdateFrame997B0` calls `Acter_ResolveEntryNames`, `Acter_GetActerAt10485F7A`, `game_100E6080`, `TargetMenu_GetCachedOrLoad`
- `Acter_IsByte123Mask7In234` calls `Acter_IsState55`
- `Acter_IsByte123Low3Bits3` calls nothing directly
- `Acter_SetFieldsAt134And138` calls `Acter_ReleaseSlotCC`, `ActerBuff_FindByField78`, `Acter_GetPartnerIfKind`
- `Acter_GetField138Clamped` calls nothing directly
- `Acter_SetFlagBits138` calls `Acter_ReleaseSlotD0`
- `Acter_ClearGlobals10488800` calls nothing directly
- `Acter_IndexIfMatchesKinds` calls nothing directly
- `Acter_FindFirstMatchingKinds` calls `NetCellFont_GetWord40DAA`, `Acter_IndexIfMatchesKinds`
- `Acter_FindStringById` calls `NetCellFont_SetByte9800AndGetEntry`, `NetCellFont_SelectNext`
- `Acter_SetFlag8000OfFound` calls `Acter_FindFirstMatchingKinds`
- `Acter_CheckIdAgainstBlockBits` calls `NetCellFont_GetBlock2CFD8`
- `Acter_MatchActorNameOrKind` calls `Acter_GetActerAt10485F7A`, `Acter_FindStringById`, `NetCellFont_FindEntryByName`
- `ActerBuff_GetStringByIdLookup` calls `ActerBuff_FindById`
- `Acter_ConstructTask1032D6D4` calls `CMoTask::Constructor`
