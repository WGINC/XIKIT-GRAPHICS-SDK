# CYySoundElem

Group: `CYy` (by the file name only). Source: `sdk/tree_src/CYySoundElem.cpp`.

12 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CYySoundElem::UpdateQueue` | 0x10036230 | 297 | yes | 7 | Each frame, rebuilds the sound-element queue from the active list, runs fn_100364A0 on each element, and clears the pending count. (reviewed as sub_10036230) | low |
| `CYySoundElem::QueueIfAbsent` | 0x10036360 | 57 | yes | - | Adds a sound element to the queue unless it is already there. (reviewed as sub_10036360) | medium |
| `CYySoundElem::ClearHandle` | 0x10036420 | 49 | yes | - | Releases the element's handle and clears its count. (reviewed as sub_10036420) | low |
| `CYySoundElem::UpdateOne` | 0x100364A0 | 52 | yes | 6 | Updates one sound element and requeues it while its timer runs. (reviewed as sub_100364A0) | low |
| `CYySoundElem::UpdateTimerAndPosition` | 0x100364E0 | 645 | yes | 5 | Decrements the element's timer, updates its position and related values from the camera-based computation, and runs its generator's command list. (reviewed as sub_100364E0) | low |
| `CYySoundElem::IsFinished` | 0x10036770 | 78 | yes | - | Reports whether the sound element has finished. (reviewed as sub_10036770) | low |
| `CYySoundElem::IsTimerPositive` | 0x100367C0 | 40 | yes | - | Tests whether the element's timer at +0x1E4 is positive. (reviewed as sub_100367C0) | low |
| `CYySoundElem::FindInQueue` | 0x10036830 | 62 | yes | - | Finds the element's value in the sound queue. (reviewed as sub_10036830) | medium |
| `CYySoundElem::AppendToQueue` | 0x10036870 | 57 | yes | - | Appends the element's value to the sound queue. (reviewed as sub_10036870) | medium |
| `CYySoundElem::UpdateFromCamera` | 0x100368B0 | 193 | yes | 5 | Updates the sound element's position from the camera. (reviewed as sub_100368B0) | medium |
| `CYySoundElem::PushActive` | 0x10036980 | 18 | yes | - | Adds the sound element to the head of the active list. (reviewed as sub_10036980) | medium |
| `CYySoundElem::Constructor` | 0x100369F0 | 129 | yes | - | Constructs a CYySoundElem and sets its default state. (reviewed as sub_100369F0) | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CYySoundElem::UpdateQueue` calls `LobbyThread_QueryChannels`, `CYySoundElem::UpdateOne`, `CYySoundElem::QueueIfAbsent`
- `CYySoundElem::QueueIfAbsent` calls `CYySoundElem::FindInQueue`, `CYySoundElem::AppendToQueue`
- `CYySoundElem::ClearHandle` calls `SoundVolume_SendStopToLobby`
- `CYySoundElem::UpdateOne` calls `CYySoundElem::UpdateTimerAndPosition`, `CYySoundElem::IsTimerPositive`, `CYySoundElem::QueueIfAbsent`, `CYySoundElem::ClearHandle`
- `CYySoundElem::UpdateTimerAndPosition` calls `Vec3_Copy`, `CMoElem::GetActiveField0A4`, `SoundVolume_ComputeDistanceVolumeAndPan`, `sub_10311C2C`, `sub_100363B0`, `CYySoundElem::IsTimerPositive`, `LobbyThread_SendCmd3FromFloat`, `Music_SetTrackVolume`, `CYySoundElem::ClearHandle`, `CMoGeneratorClone::ExecuteCmdList`
- `CYySoundElem::IsFinished` calls `Generator_IsFlag400OrField22Zero`
- `CYySoundElem::IsTimerPositive` calls `CYySoundElem_IsHandleInFrameList`
- `CYySoundElem::FindInQueue` calls nothing directly
- `CYySoundElem::AppendToQueue` calls nothing directly
- `CYySoundElem::UpdateFromCamera` calls `Camera_GetFrameScale`, `CMoElem::AdvanceTimer`, `Camera_GetField50`, `RabRes_MinOf10055F60OverIndexPairs`
- `CYySoundElem::PushActive` calls nothing directly
- `CYySoundElem::Constructor` calls `CMoElem::Constructor`, `sub_10044AA0`, `CYySoundElem::PushActive`
