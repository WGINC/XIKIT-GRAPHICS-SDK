# CMoProcessor3DNow

Group: `CMo` (by the file name only). Source: `sdk/tree_src/CMoProcessor3DNow.cpp`.

16 functions.

| Function | Address | Size | Hookable | D3D depth | Summary (the naming review) | Confidence |
|---|---|---|---|---|---|---|
| `CMoProcessor3DNow::Slot8CallSlot9` | 0x1006CC40 | 5 | yes | - | Slot 8: forwards to slot 9. (reviewed as sub_1006CC40) | high |
| `CMoProcessor3DNow::Slot10CallSlot11` | 0x1006CC50 | 5 | yes | - | Slot 10: forwards to slot 11. (reviewed as sub_1006CC50) | high |
| `CMoProcessor3DNow::Slot40CallSlot41` | 0x1006CC60 | 8 | yes | - | Slot 40: forwards to slot 41. (reviewed as sub_1006CC60) | high |
| `CMoProcessor3DNow::Slot38CallSlot39` | 0x1006CC70 | 8 | yes | - | Slot 38: forwards to slot 39. (reviewed as sub_1006CC70) | high |
| `CMoProcessor3DNow::Slot46CallSlot48` | 0x1006CC80 | 8 | yes | - | Slot 46: forwards to slot 48. (reviewed as sub_1006CC80) | high |
| `CMoProcessor3DNow::Slot45CallSlot47` | 0x1006CC90 | 8 | yes | - | Slot 45: forwards to slot 47. (reviewed as sub_1006CC90) | high |
| `CMoProcessor3DNow::CMoProcessor_GetRuntimeClass` | 0x1006CCD0 | 6 | yes | - | - | - |
| `CMoProcessor3DNow::Vec3AddScaled` | 0x10070780 | 13 | yes | - | Calls CMoProcessor_AddScaled3. (reviewed as sub_10070780) | medium |
| `CMoProcessor3DNow::Vec3Dot` | 0x10070790 | 31 | yes | - | Dot product of two 3-vectors. (reviewed as sub_10070790) | high |
| `CMoProcessor3DNow::Vec4TransformB` | 0x10070AA0 | 5 | yes | - | Calls CMoProcessor_Vec4TransformB. (reviewed as sub_10070AA0) | medium |
| `CMoProcessor3DNow::Vec4Transform` | 0x10070AB0 | 5 | yes | - | Calls CMoProcessor_Vec4Transform. (reviewed as sub_10070AB0) | medium |
| `CMoProcessor3DNow::Vec3Transform` | 0x10070AC0 | 5 | yes | - | Calls CMoProcessor_Vec3Transform. (reviewed as sub_10070AC0) | medium |
| `CMoProcessor3DNow::Vec3Lerp` | 0x10070AD0 | 13 | yes | - | Calls CMoProcessor_Lerp3. (reviewed as sub_10070AD0) | medium |
| `CMoProcessor3DNow::ProjectVertsAndBounds` | 0x10070E20 | 21 | yes | - | Calls CMoProcessor_ProjectVertsAndBounds. (reviewed as sub_10070E20) | medium |
| `CMoProcessor3DNow::CalcScreenBoundsAndVisible` | 0x10070E40 | 21 | yes | - | Calls CMoProcessor_CalcScreenBoundsAndVisible. (reviewed as sub_10070E40) | medium |
| `CMoProcessor3DNow::CalcScreenBounds` | 0x10070E60 | 5 | yes | - | Calls CMoProcessor_CalcScreenBounds. (reviewed as sub_10070E60) | medium |

## Direct calls

Read from the game's code (call/jmp rel32 to a function start).

- `CMoProcessor3DNow::Slot8CallSlot9` calls nothing directly
- `CMoProcessor3DNow::Slot10CallSlot11` calls nothing directly
- `CMoProcessor3DNow::Slot40CallSlot41` calls nothing directly
- `CMoProcessor3DNow::Slot38CallSlot39` calls nothing directly
- `CMoProcessor3DNow::Slot46CallSlot48` calls nothing directly
- `CMoProcessor3DNow::Slot45CallSlot47` calls nothing directly
- `CMoProcessor3DNow::CMoProcessor_GetRuntimeClass` calls nothing directly
- `CMoProcessor3DNow::Vec3AddScaled` calls `CMoProcessorX87::Vec3AddScaled`
- `CMoProcessor3DNow::Vec3Dot` calls nothing directly
- `CMoProcessor3DNow::Vec4TransformB` calls `sub_1006D7E0`
- `CMoProcessor3DNow::Vec4Transform` calls `sub_1006D870`
- `CMoProcessor3DNow::Vec3Transform` calls `sub_1006D900`
- `CMoProcessor3DNow::Vec3Lerp` calls `CMoProcessorX87::Vec3Lerp`
- `CMoProcessor3DNow::ProjectVertsAndBounds` calls `sub_1006EB70`
- `CMoProcessor3DNow::CalcScreenBoundsAndVisible` calls `CMoProcessor::CalcScreenBoundsAndVisible`
- `CMoProcessor3DNow::CalcScreenBounds` calls `CMoProcessor::CalcScreenBounds`
