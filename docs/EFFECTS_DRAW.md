> Paths in this document are the development repository's: tree/src/ is sdk/tree_src/ here, kit/xikit/ and kit/d3d8on11/ are src/xikit/ and src/d3d8on11/, sdk/examples/ is sdk/examples/; docs/HISTORY.md and kit/sessions/ are not published.

# How the game draws its effects: device set-up, blending, the texture factor, flashes

How FFXiMain.dll sets the device up for its spell and ability effects and for full-screen flashes, from its code
(analysed build 6A995428). The effect files and their command numbers are in docs/FORMATS.md and
docs/EFFECT_COMMANDS.md; this is the drawing. Sources: tree/src/CMoElem.cpp, tree/src/CYyModelDt.cpp,
tree/src/CDx.cpp and the element files named below. **Not known** marks what is not read.

## 1. An element's draw

`YmElem_SetupDevice` (0x100467E0) prepares the device before an effect element draws and `YmElem_RestoreDevice`
(0x100472F0) puts it back (tree/src/CMoElem.cpp). SetupDevice sets alpha blending on and, by the element's mode, one
of the blends ONE/ZERO, SRCALPHA/ONE (adding), SRCALPHA/INVSRCALPHA, ZERO/INVSRCALPHA; then alpha testing (GREATER
96) and the depth test on. It sets no texture stages: the element's own draw does.

## 2. The texture factor carries the element's colour

The model draw the elements use (`CYyModelDt`, tree/src/CYyModelDt.cpp:282-289 and :773) sets stage 0 to the
vertex colour and stage 1 to COLOROP MODULATE2X and ALPHAOP MODULATE4X with argument 2 the texture factor
(D3DTA_TFACTOR). The elements write their colour and alpha into the factor (D3DRS_TEXTUREFACTOR) before drawing:
D3aElem.cpp:54, CMoDistModelElem.cpp:267 and :451, CMoDistMorphElem.cpp:139, CMoDamValueProgElem.cpp:47. So an
effect model's picture is (vertex colour x texture) x 2 x factor colour, its alpha x 4 x factor alpha, and the factor is
the one place that scales all the light an element adds or covers. Other users of the factor: shadows
(BoneShadow.cpp), the character draw (CXiSkeletonActor.cpp), the environment-mapped projection (EnvMapProjTex.cpp).

## 3. Full-screen flashes and fades

`CDx::DrawFadeQuad` (0x1000A820, tree/src/CDx.cpp) is called once a frame by `Frame_Render` with the frame's screen
colour, into which the Lfd element's screen colouring adds (`CMoLfdElem_Draw` -> 0x10014F90). 0x80808080 draws
nothing; an alpha byte up to 0x80 darkens (INVSRCALPHA, SRCALPHA); above 0x80 it adds light (SRCALPHA, ONE): that is a
flash.

## 4. What a mod uses

- Scale an effect: scale the texture factor's alpha (SRCALPHA blends) or colour (ONE) for the element's draws
  (sdk/examples/effect_comfort.cpp since 25 Nov; tested: a draw set up as CYyModelDt's, at 50%, adds a quarter where
  the game's adds half). Because MODULATE2X/4X clamp after the multiply, a draw already at full can stay brighter
  than the percentage.
- Limit a flash: scale DrawFadeQuad's colour in the adding case only.

## 5. Not known

- Which other effect draws set stages of their own: read for the effect files (25 Nov, every `SetTextureStageState`
  in tree/src/CMoDistModelElem.cpp, CMoDistMorphElem.cpp, CMoTask.cpp, ModelTranslucent.cpp, EnvMapProjTex.cpp):
  - `CMoDistModelElem` (0x10040670, 0x100431B0) and `CMoDistMorphElem` (0x1003F440) set only texture coordinates
    and transforms (and disable stage 1 after): their colour stages are the model draw's, so the texture factor (section 2) applies;
  - the environment map and projected texture passes (`EnvMap_BeginPass`/`EndPass`, `ProjTex_BeginPass`/`EndPass`)
    multiply by the factor too (MODULATE2X of CURRENT and TFACTOR);
  - `Model_CompositeTranslucentPass` (from `CXiSkeletonActor::DrawModel`) is diffuse x texture x 2 with no factor:
    a character's draw, not an effect's;
  - `CMoTask::DrawQuadStates` (0x10076030) and `CMoTask::DrawQuadDynVB` (0x10076520) take the texture's colour and the
    vertex's alpha, no factor; their only callers, 0x10075FF0 and 0x100764C0, have no reference anywhere in the image
    (no call, jump or stored pointer): as far as the image shows, not used.
  Files outside these (the scene, UI and shadow draws) are not effects. effect_comfort counts what it leaves, by
  reason, in xikit.log; which draws those are in play is the owner's log.
- Whether a given pulse in play (the owner's thunder spirit) is a DrawFadeQuad flash or an element.
