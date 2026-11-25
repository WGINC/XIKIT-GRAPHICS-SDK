> Paths in this document are the development repository's: tree/src/ is sdk/tree_src/ here, kit/xikit/ and kit/d3d8on11/ are src/xikit/ and src/d3d8on11/, sdk/examples/ is sdk/examples/; docs/HISTORY.md and kit/sessions/ are not published.

# The game's camera: view, projection, distances

How FFXiMain.dll builds the view and the projection and decides what is far enough to draw, from its code (analysed
build 6A995428). Sources: the tree's C (tree/src/WinMain.cpp, tree/src/ActorCamera.cpp, tree/src/XiZone.cpp,
tree/src/FrameRender.cpp) and the disassembly where the tree has no source. Most of it was read for two example mods,
whose headers keep the detail: sdk/examples/camera_view.cpp and sdk/examples/photo_mode.cpp. **Not known** marks what
is not read.

## 1. The view

`Camera_ApplyViewProjection` (0x10015510, at the end of `Frame_Render`) asks the camera controller whether it moved
(`Camera_DiffersFromSaved` 0x10021AE0: the eye at controller +0x44 and the look-at point at +0x50 against the copies at
+0x60 and +0x6C). If so, `Camera_SnapshotState` (0x10021B70) builds the view at controller +4 with
`Camera_BuildLookAtView` (eye +0x44, look-at +0x50, roll +0x5C), saves the copies, and the view goes to
`CDx::SetTransform` (VIEW). `MoDX_Update` and `Camera_SetupMatrices` cache it for the billboards and the effects.

The view the game culls with is the one last set on the device (`CDx::GetTransformCached(2)`, the copy at CDx +0x97C:
read in `XiZone_Draw` 0x1017BEFC and `CXiSkeletonActor_OnMove` 0x100C7C3C). It is set at the end of `Frame_Render`
(0x10012E1E), before the next frame's `XiZone::DrawScene` (0x10011C97). A mod's eye set in `Camera_SnapshotState` is
therefore also the eye the zone and the actors are culled with.

## 2. The projection (`Camera_BuildPerspectiveFov`, 0x10015490)

Built at camera +0x154 (a copy at +0x1D4) with D3DXMatrixPerspectiveFovLH: vertical field of view
2 x atan(192 / [+0x2F4]), aspect 1 / ([+0x2F0] x [+0x2E8]), near [+0x2DC], far [+0x2E0]. Its callers:
`Camera_BuildProjection`, `Camera_SetField2E4`, 0x10015430. As run, the matrix has _33 = -far / (far - near) and
_34 = -1 (the right-handed form, whatever the routine's name; kit/xikit/test mode cammod). Other readers of
+0x2F4 and +0x2E0: `ZoneMap_SetOverlayProjection` (the zone map's own projection), the effects' fog
(tree/src/ElemFog.cpp), `Camera_GetField2F4`, `Camera_GetFloat2E0`. So changing the fields (not the matrix) changes
every reader alike.

## 3. Draw distance (`XiZone::ComputeFogDistance`, 0x1018B8F0)

The zone's value (100 without a zone record); when the zone's +0x1D0 is above 0, that value times the time-of-day
factor (`Env_FogDistanceFactor` 0x101892B0) but not less than +0x1D0. Used by:
- `XiZone_Draw` (0x1017BF35): kept at zone +0x39420 and its square at +0x39424; a mesh is drawn only when its squared
  distance from the eye is below that (or a smaller per-mesh value); it is also the far distance of the zone's
  culling frustum (`ZoneMap_BuildPerspective` 0x1017BFB4, zone +0x38FDC);
- `CXiSkeletonActor_OnMove` (0x100C7D47) and 0x100AC5A0: beyond it an actor gets bit 1 of its flags word +0xB2, and
  `CXiActorDraw::UpdateDrawList` (0x10082DC7) draws it only while that word is 0.
The fog's own distances are another computation (`Env_ComputeFog`, sdk/examples/world_light.cpp).

### 3a. The floor +0x1D0 (25 Nov, disassembly)

`XiZone::Constructor` (0x1018B170) sets +0x1D0 to 43.0 (0x422C0000). The zone change 0x1018B3A0 (argument: the zone
number, kept at +0x1B4; called from three functions of the game) writes `[g_pXiZone]` +0x1D0 = 0 only for
zone 0xC1, and +0x1D4 = 0.7 only for zone 0x32; nothing in the game sets +0x1D0 back to 43.0 (the scan of every
store to +0x1D0 in XiZone's range: the constructor and this one). So while +0x1D0 is 43.0 the draw distance is the
zone's value times the time-of-day factor, but at least 43.0; in zone 0xC1 the product with no floor. Whether the
XiZone object is made again for each zone (which would restore 43.0 after zone 0xC1): **not read**.

## 4. Not known

- The zone's value is the float at +0xC of the record `[zone + 0x1C]` (`ZoneMap_GetFloatRef1CPlus0C`); which file or
  packet fills that record: **not read**. (+0x1D0, the floor, is read: 3a.) Whether models stay loaded beyond the
  game's distance: **not read**.
- Whether any other drawing (effects, the sky) culls with a camera copy of its own.
- Whether other tools running in the game (Windower, Ashita) write the same camera fields: their code is closed; the
  owner's run with and without Windower (kit/sessions/ltp_25nov R6) is the test.
