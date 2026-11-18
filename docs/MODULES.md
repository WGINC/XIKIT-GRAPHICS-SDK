# Groups of source files

The source files (`sdk/tree_src`) grouped by the first part of their names (public_docs.py group_of). A group is only that: the name, as written. What a file holds is in its own page and its evidence.

| Group | Files | Functions |
|---|---|---|
| `Text` | 2 | 568 |
| `Net` | 1 | 493 |
| `CMo` | 109 | 440 |
| `Target` | 1 | 422 |
| `sq` | 93 | 384 |
| `CXi` | 14 | 267 |
| `Yk` | 7 | 241 |
| `Menu` | 1 | 155 |
| `Acter` | 1 | 126 |
| `St` | 11 | 126 |
| `Zone` | 5 | 121 |
| `CYy` | 20 | 103 |
| `Dmsg` | 1 | 90 |
| `Generator` | 5 | 79 |
| `Win` | 1 | 66 |
| `CDx` | 1 | 57 |
| `Math` | 1 | 56 |
| `Xi` | 6 | 53 |
| `Lobby` | 2 | 46 |
| `App` | 2 | 43 |
| `Env` | 4 | 42 |
| `Faq` | 1 | 29 |
| `Fit` | 1 | 27 |
| `Model` | 9 | 27 |
| `Resource` | 4 | 27 |
| `mdl` | 1 | 25 |
| `Elem` | 7 | 24 |
| `Actor` | 8 | 22 |
| `Task` | 2 | 22 |
| `Input` | 1 | 20 |
| `Sound` | 2 | 20 |
| `CTs` | 1 | 19 |
| `Plant` | 1 | 19 |
| `Error` | 1 | 18 |
| `Jpeg` | 2 | 17 |
| `Music` | 1 | 17 |
| `My` | 1 | 16 |
| `Dyn` | 2 | 15 |
| `Bone` | 1 | 14 |
| `Frame` | 1 | 14 |
| `Mem` | 4 | 14 |
| `Mo` | 1 | 14 |
| `Sky` | 1 | 14 |
| `Linked` | 1 | 13 |
| `Skeleton` | 2 | 12 |
| `Tex` | 3 | 12 |
| `Mesh` | 2 | 11 |
| `Occlusion` | 1 | 10 |
| `Scene` | 2 | 10 |
| `Processor` | 5 | 9 |
| `Afterimage` | 1 | 7 |
| `Rand` | 1 | 7 |
| `Auction` | 1 | 6 |
| `Debug` | 1 | 6 |
| `Motion` | 1 | 6 |
| `Opening` | 1 | 6 |
| `Ot` | 2 | 6 |
| `Scheduler` | 1 | 6 |
| `Ym` | 1 | 6 |
| `chn` | 1 | 6 |
| `Control` | 1 | 5 |
| `Effect` | 1 | 5 |
| `Post` | 1 | 5 |
| `Skin` | 1 | 5 |
| `CEnv` | 1 | 4 |
| `Byte` | 1 | 3 |
| `CAtel` | 1 | 3 |
| `CShader` | 1 | 3 |
| `Dist` | 2 | 3 |
| `V` | 1 | 3 |
| `chasm` | 1 | 3 |
| `Attach` | 1 | 2 |
| `CApp` | 1 | 2 |
| `Copy` | 1 | 2 |
| `D3a` | 1 | 2 |
| `Furniture` | 2 | 2 |
| `Kz` | 1 | 2 |
| `List` | 1 | 2 |
| `Os2` | 2 | 2 |
| `Proj` | 1 | 2 |
| `Que` | 1 | 2 |
| `Rab` | 1 | 2 |
| `Script` | 1 | 2 |
| `Shape` | 1 | 2 |
| `Texture` | 1 | 2 |
| `Thread` | 1 | 2 |
| `CAcc` | 1 | 1 |
| `Event` | 1 | 1 |
| `Font` | 1 | 1 |
| `Schedular` | 1 | 1 |
| `Screen` | 1 | 1 |
| `Shader` | 1 | 1 |
| `Skel` | 1 | 1 |
| `Spline` | 1 | 1 |
| `Stream` | 1 | 1 |
| `Timer` | 1 | 1 |
| `Vector` | 1 | 1 |
| `Vertex` | 1 | 1 |

## Acter

- [Acter](functions/Acter.md): 126 functions. Acter_* and ActerBuff_* (the actor buffer: update records, motion timers, globals), the strings "UserName:%s UniqueNo:%d", "/sitchair off"

## Actor

- [ActorBase](functions/ActorBase.md): 3 functions. CXiActor::ConstructBase / Init, CXiActor_LinkIntoDrawList, Actor_ResetDrawLists
- [ActorCamera](functions/ActorCamera.md): 13 functions. Camera_PlaceRelativeToActor, Camera_SetTargetIfMoved, Camera_BuildLookAtView, the actor percent-scale tables; called from CXiSkeletonActor and the camera code
- [ActorCount](functions/ActorCount.md): 1 functions. Actor_CountAll; called from the actor classes and the draw list
- [ActorLights](functions/ActorLights.md): 1 functions. Actor_SelectNearestLights, CXiActor::CorrectOnZoneMap, the light table globals
- [ActorModelFlag](functions/ActorModelFlag.md): 1 functions. GetModelFlag130Bit21 (one model flag); called from actor and skeleton code
- [ActorModelParts](functions/ActorModelParts.md): 1 functions. CXiActor::RequestModelParts, ProcessResidentListEntries
- [ActorModelState](functions/ActorModelState.md): 1 functions. CXiActor::ComputeDrawState and the CXiActor::GetModel* field readers
- [ActorName](functions/ActorName.md): 1 functions. CXiActor::GetName, ProjectThroughCamera; called from CXiActor::NameCalc

## Afterimage

- [AfterimageTask](functions/AfterimageTask.md): 7 functions. AfterimageTask_Execute / Kill / SetCaster / SetTarget, the g_afterimage* textures

## App

- [AppMainLoop](functions/AppMainLoop.md): 36 functions. CApp::RunMainLoop, App_RenderFrameMaskedFPU, the Direct3D device bootstrap (Gfx_D3DBootstrap, Gfx_CreateDevice, Gfx_CreateD3DHolder), the pad settings (padmode000...), the clipboard; called from WndProc and the window code
- [AppStartup](functions/AppStartup.md): 7 functions. App_Constructor, the game-state step (App_SetSeqStep), loads the resource tables is.dat, bs.dat, cl.dat, ti.dat...; called from the main loop and Frame_Render

## Attach

- [AttachNotify](functions/AttachNotify.md): 2 functions. CMoAttachments::NotifyCaster / NotifyTarget

## Auction

- [AuctionMenu](functions/AuctionMenu.md): 6 functions. the string "menu    auc1    " and calls into the menu code (Unit1012AC80_GetMessageFwd): read from the code

## Bone

- [BoneShadow](functions/BoneShadow.md): 14 functions. Quat_* and BoneXform_*, Shadow_DrawByMode, Shadow_SmoothLightDirection, the model offscreen pass

## Byte

- [ByteSwap](functions/ByteSwap.md): 3 functions. Swap16, Swap32, ByteSwap32 only; called by the zip, file and message readers

## CAcc

- [CAcc](functions/CAcc.md): 1 functions

## CApp

- [CApp](functions/CApp.md): 2 functions

## CAtel

- [CAtelIdleTask](functions/CAtelIdleTask.md): 3 functions

## CDx

- [CDx](functions/CDx.md): 57 functions

## CEnv

- [CEnv](functions/CEnv.md): 4 functions

## CMo

- [CMoActorColorDriveTask](functions/CMoActorColorDriveTask.md): 3 functions
- [CMoActorRotationDriveTask](functions/CMoActorRotationDriveTask.md): 1 functions
- [CMoAfbRes](functions/CMoAfbRes.md): 2 functions
- [CMoAttachments](functions/CMoAttachments.md): 23 functions
- [CMoAuctionMenuTask](functions/CMoAuctionMenuTask.md): 1 functions
- [CMoBm2RefRes](functions/CMoBm2RefRes.md): 1 functions
- [CMoBm2Res](functions/CMoBm2Res.md): 3 functions
- [CMoBpRes](functions/CMoBpRes.md): 3 functions
- [CMoCamera](functions/CMoCamera.md): 5 functions
- [CMoCameraSetupTask](functions/CMoCameraSetupTask.md): 2 functions
- [CMoCameraTask](functions/CMoCameraTask.md): 2 functions
- [CMoCelestial](functions/CMoCelestial.md): 2 functions
- [CMoCibRes](functions/CMoCibRes.md): 3 functions
- [CMoD3aElem](functions/CMoD3aElem.md): 6 functions
- [CMoD3aLightmapElem](functions/CMoD3aLightmapElem.md): 5 functions
- [CMoD3aRes](functions/CMoD3aRes.md): 1 functions
- [CMoD3bElem](functions/CMoD3bElem.md): 1 functions
- [CMoD3bRes](functions/CMoD3bRes.md): 2 functions
- [CMoD3mElem](functions/CMoD3mElem.md): 2 functions
- [CMoD3mLightmapElem](functions/CMoD3mLightmapElem.md): 2 functions
- [CMoD3mRes](functions/CMoD3mRes.md): 1 functions
- [CMoD3mSpecularElem](functions/CMoD3mSpecularElem.md): 5 functions
- [CMoDX](functions/CMoDX.md): 8 functions
- [CMoDamValueProgElem](functions/CMoDamValueProgElem.md): 3 functions
- [CMoDisintegrateProgElem](functions/CMoDisintegrateProgElem.md): 6 functions
- [CMoDist](functions/CMoDist.md): 6 functions
- [CMoDistModelElem](functions/CMoDistModelElem.md): 11 functions
- [CMoDistMorphElem](functions/CMoDistMorphElem.md): 7 functions
- [CMoDistRingElem](functions/CMoDistRingElem.md): 6 functions
- [CMoDxStatusMng](functions/CMoDxStatusMng.md): 3 functions
- [CMoElem](functions/CMoElem.md): 34 functions
- [CMoFloatingNumberTask](functions/CMoFloatingNumberTask.md): 1 functions
- [CMoFloatingNumberTaskAttachments](functions/CMoFloatingNumberTaskAttachments.md): 1 functions
- [CMoGeneratorClone](functions/CMoGeneratorClone.md): 18 functions
- [CMoGeneratorRes](functions/CMoGeneratorRes.md): 1 functions
- [CMoGeneratorResAttachments](functions/CMoGeneratorResAttachments.md): 1 functions
- [CMoGeneratorTask](functions/CMoGeneratorTask.md): 4 functions
- [CMoKeyFrameRes](functions/CMoKeyFrameRes.md): 3 functions
- [CMoLfdElem](functions/CMoLfdElem.md): 4 functions
- [CMoLockColorDriveTask](functions/CMoLockColorDriveTask.md): 3 functions
- [CMoLockLookAtDriveTask](functions/CMoLockLookAtDriveTask.md): 3 functions
- [CMoMebRes](functions/CMoMebRes.md): 1 functions
- [CMoMmbRes](functions/CMoMmbRes.md): 1 functions
- [CMoMo2Res](functions/CMoMo2Res.md): 4 functions
- [CMoMsbRes](functions/CMoMsbRes.md): 1 functions
- [CMoMzbRes](functions/CMoMzbRes.md): 1 functions
- [CMoNullProgElem](functions/CMoNullProgElem.md): 3 functions
- [CMoOT](functions/CMoOT.md): 3 functions
- [CMoOcclusionMng](functions/CMoOcclusionMng.md): 3 functions
- [CMoOs2Res](functions/CMoOs2Res.md): 3 functions
- [CMoOtTask](functions/CMoOtTask.md): 5 functions
- [CMoPathDriveActorTask](functions/CMoPathDriveActorTask.md): 5 functions
- [CMoPathObject](functions/CMoPathObject.md): 1 functions
- [CMoPointLightProgElem](functions/CMoPointLightProgElem.md): 5 functions
- [CMoProcessor](functions/CMoProcessor.md): 9 functions
- [CMoProcessor3DNow](functions/CMoProcessor3DNow.md): 16 functions
- [CMoProcessorSSE](functions/CMoProcessorSSE.md): 5 functions
- [CMoProcessorX87](functions/CMoProcessorX87.md): 10 functions
- [CMoResType5E](functions/CMoResType5E.md): 3 functions
- [CMoResType5F](functions/CMoResType5F.md): 1 functions
- [CMoResource](functions/CMoResource.md): 18 functions
- [CMoResourceLoadTask](functions/CMoResourceLoadTask.md): 1 functions
- [CMoResourceMng](functions/CMoResourceMng.md): 1 functions
- [CMoResourceWaitTask](functions/CMoResourceWaitTask.md): 1 functions
- [CMoResourceWaitTaskAttachments](functions/CMoResourceWaitTaskAttachments.md): 1 functions
- [CMoRidRes](functions/CMoRidRes.md): 1 functions
- [CMoRingProgElem](functions/CMoRingProgElem.md): 1 functions
- [CMoRmpRes](functions/CMoRmpRes.md): 4 functions
- [CMoSchOp07Attachments](functions/CMoSchOp07Attachments.md): 1 functions
- [CMoSchOp0CAttachments](functions/CMoSchOp0CAttachments.md): 1 functions
- [CMoSchOp0CTask](functions/CMoSchOp0CTask.md): 2 functions
- [CMoSchOp0DAttachments](functions/CMoSchOp0DAttachments.md): 1 functions
- [CMoSchOp0DTask](functions/CMoSchOp0DTask.md): 1 functions
- [CMoSchOp1DAttachments](functions/CMoSchOp1DAttachments.md): 1 functions
- [CMoSchOp1DTask](functions/CMoSchOp1DTask.md): 2 functions
- [CMoSchOp1FAttachments](functions/CMoSchOp1FAttachments.md): 1 functions
- [CMoSchOp2CAttachments](functions/CMoSchOp2CAttachments.md): 1 functions
- [CMoSchOp2EAttachments](functions/CMoSchOp2EAttachments.md): 1 functions
- [CMoSchOp2FAttachments](functions/CMoSchOp2FAttachments.md): 1 functions
- [CMoSchOp40Attachments](functions/CMoSchOp40Attachments.md): 1 functions
- [CMoSchOp42Attachments](functions/CMoSchOp42Attachments.md): 1 functions
- [CMoSchOp48Attachments](functions/CMoSchOp48Attachments.md): 1 functions
- [CMoSchOp59Attachments](functions/CMoSchOp59Attachments.md): 1 functions
- [CMoSchOp62Attachments](functions/CMoSchOp62Attachments.md): 1 functions
- [CMoSchOp75Attachments](functions/CMoSchOp75Attachments.md): 1 functions
- [CMoSchOp7AAttachments](functions/CMoSchOp7AAttachments.md): 1 functions
- [CMoSchOp7FAttachments](functions/CMoSchOp7FAttachments.md): 1 functions
- [CMoSchOp9BAttachments](functions/CMoSchOp9BAttachments.md): 1 functions
- [CMoSchOpB4Attachments](functions/CMoSchOpB4Attachments.md): 1 functions
- [CMoSchOpB5Attachments](functions/CMoSchOpB5Attachments.md): 1 functions
- [CMoSchOpBCAttachments](functions/CMoSchOpBCAttachments.md): 1 functions
- [CMoSchOpBFAttachments](functions/CMoSchOpBFAttachments.md): 1 functions
- [CMoSchOpSharedAttachments](functions/CMoSchOpSharedAttachments.md): 1 functions
- [CMoSchedularTask](functions/CMoSchedularTask.md): 8 functions
- [CMoSchedulerResAttachments](functions/CMoSchedulerResAttachments.md): 1 functions
- [CMoSepRes](functions/CMoSepRes.md): 1 functions
- [CMoSk2Res](functions/CMoSk2Res.md): 4 functions
- [CMoSkeletonElem](functions/CMoSkeletonElem.md): 2 functions
- [CMoSphRes](functions/CMoSphRes.md): 4 functions
- [CMoSpline](functions/CMoSpline.md): 12 functions
- [CMoTask](functions/CMoTask.md): 43 functions
- [CMoTaskMng](functions/CMoTaskMng.md): 11 functions
- [CMoUseMagicWaitTask](functions/CMoUseMagicWaitTask.md): 1 functions
- [CMoUseMagicWaitTaskAttachments](functions/CMoUseMagicWaitTaskAttachments.md): 1 functions
- [CMoVolumeChangeTask](functions/CMoVolumeChangeTask.md): 1 functions
- [CMoVuAnmElem](functions/CMoVuAnmElem.md): 5 functions
- [CMoVuDist](functions/CMoVuDist.md): 5 functions
- [CMoVuLineProgElem](functions/CMoVuLineProgElem.md): 5 functions
- [CMoWeatherRes](functions/CMoWeatherRes.md): 2 functions

## CShader

- [CShader](functions/CShader.md): 3 functions

## CTs

- [CTsZoneMap](functions/CTsZoneMap.md): 19 functions

## CXi

- [CXiActor](functions/CXiActor.md): 73 functions
- [CXiActorDraw](functions/CXiActorDraw.md): 2 functions
- [CXiActorNameDraw](functions/CXiActorNameDraw.md): 1 functions
- [CXiAtelActor](functions/CXiAtelActor.md): 6 functions
- [CXiCollisionActor](functions/CXiCollisionActor.md): 4 functions
- [CXiControlActor](functions/CXiControlActor.md): 14 functions
- [CXiDancerActor](functions/CXiDancerActor.md): 5 functions
- [CXiDollActor](functions/CXiDollActor.md): 5 functions
- [CXiMovie](functions/CXiMovie.md): 8 functions
- [CXiOpening](functions/CXiOpening.md): 2 functions
- [CXiSkeletonActor](functions/CXiSkeletonActor.md): 135 functions
- [CXiSkeletonActorRes](functions/CXiSkeletonActorRes.md): 6 functions
- [CXiTimer](functions/CXiTimer.md): 2 functions
- [CXiTimerLow](functions/CXiTimerLow.md): 4 functions

## CYy

- [CYyCamMng2](functions/CYyCamMng2.md): 7 functions
- [CYyIcon](functions/CYyIcon.md): 2 functions
- [CYyModel](functions/CYyModel.md): 14 functions
- [CYyModelBase](functions/CYyModelBase.md): 14 functions
- [CYyModelDt](functions/CYyModelDt.md): 13 functions
- [CYyModelDtBuffered](functions/CYyModelDtBuffered.md): 1 functions
- [CYyModelDtStreamed](functions/CYyModelDtStreamed.md): 3 functions
- [CYyMotionQue](functions/CYyMotionQue.md): 6 functions
- [CYyMotionQueList](functions/CYyMotionQueList.md): 1 functions
- [CYyMusicLoadTask](functions/CYyMusicLoadTask.md): 2 functions
- [CYyObject](functions/CYyObject.md): 1 functions
- [CYyOs2VtxBuffer](functions/CYyOs2VtxBuffer.md): 4 functions
- [CYySkl](functions/CYySkl.md): 1 functions
- [CYySoundElem](functions/CYySoundElem.md): 12 functions
- [CYyTex](functions/CYyTex.md): 3 functions
- [CYyTexBase](functions/CYyTexBase.md): 5 functions
- [CYyTexMng](functions/CYyTexMng.md): 5 functions
- [CYyThreadPool](functions/CYyThreadPool.md): 3 functions
- [CYyVb](functions/CYyVb.md): 4 functions
- [CYyVbMng](functions/CYyVbMng.md): 2 functions

## Control

- [ControlActorView](functions/ControlActorView.md): 5 functions. XiControlActor_UpdateCamera / UpdateView / SetAutoRunning / NormalizeInput

## Copy

- [CopyPair](functions/CopyPair.md): 2 functions. CopyFrom, CopyReturnZ: read from the code

## D3a

- [D3aElem](functions/D3aElem.md): 2 functions. CMoD3aElem, YmElem_DrawD3ASegment / SetD3ADrawState

## Debug

- [Debug](functions/Debug.md): 6 functions

## Dist

- [DistInit](functions/DistInit.md): 2 functions. CMoDist::Init; called from the generator code
- [DistModelElem](functions/DistModelElem.md): 1 functions. CMoDistModelElem::DrawBatches / DrawMesh, the blend weights

## Dmsg

- [DmsgText](functions/DmsgText.md): 90 functions. the strings "d_msg", "Invalid Dmsg", the kana vowels "aieuoAIUEO": the message text tables (an address range between two evidenced source files, holding several of the original files: named for its main contents)

## Dyn

- [DynVB](functions/DynVB.md): 12 functions. DynVB_Create / Lock / Reserve / Unlock, CMoVuElem_Draw, Mo_InitSharedRenderResources, the strings spec, cubemap, map
- [DynVBCtor](functions/DynVBCtor.md): 3 functions. DynVB_Constructor; called from the DynVB code

## Effect

- [EffectOffscreen](functions/EffectOffscreen.md): 5 functions. BeginEffectOffscreenPass / EndEffectOffscreenPass, CMoLfdElem_vf11, the splines

## Elem

- [ElemCtor471011C8](functions/ElemCtor471011C8.md): 1 functions. CMoD3mLightmapElem::Ctor (an element constructor); called from the generator code
- [ElemCurve](functions/ElemCurve.md): 4 functions. Evaluate, EvaluateEaseIn, EvaluateEaseInOut: the element curves
- [ElemFields](functions/ElemFields.md): 1 functions. CMoElem::GetActiveField0A4 / GetAddr78 / GetAddr84
- [ElemFields194](functions/ElemFields194.md): 7 functions. getters and setters of the element fields +0x194 to +0x1A8; called only from the generator code
- [ElemFog](functions/ElemFog.md): 9 functions. Fog_SetRenderStates, Zone_UpdateFogAmbient, YmElem_DrawWithOwnProjection, RegisterWithProcessor
- [ElemInstances](functions/ElemInstances.md): 1 functions. YmElem_ForEachInstance; called from the CMoVu* element destructors
- [ElemOffset](functions/ElemOffset.md): 1 functions. GetOffsetVec, called only from the generator code; evaluates the curve (Unit100544A0_Evaluate)

## Env

- [EnvBlend](functions/EnvBlend.md): 7 functions. Blend_AllocResult / FindPrevious / FreeResult / Update; called from YmCombineWeather
- [EnvKeys](functions/EnvKeys.md): 20 functions. Env_BlendKeys / BlendTimeOfDay / FindNextKey / LerpKeyValues: the time-of-day keys
- [EnvLight](functions/EnvLight.md): 5 functions. Env_ComputeAmbient / ComputeFog, ZoneMap_FillDirLight, WeatherRes_Construct
- [EnvMapProjTex](functions/EnvMapProjTex.md): 10 functions. EnvMap_BeginPass / EndPass, ProjTex_BeginPass / CaptureToTarget / EndPass, Dbg_DrawAxesAt; called from SkinAndDrawV2 and DrawModel

## Error

- [ErrorReport](functions/ErrorReport.md): 18 functions. XiErrMsgGetErrCode, ReportAndHandleError, error callbacks (RegisterCallback, IsRegistered); called from event, menu and actor code

## Event

- [EventTextBlock](functions/EventTextBlock.md): 1 functions

## Faq

- [FaqHelp](functions/FaqHelp.md): 29 functions. the files kb_faq.pib, kb_faq_idx.pib, kb_faq.pfb, the menus "faqmain", "faqsub", the string SELLANG (an address range between two evidenced source files, holding several of the original files: named for its main contents)

## Fit

- [FitFont](functions/FitFont.md): 27 functions. FontGlyphCache_* and the FiT font engine (FiTRodinL-U.fit, FiTWrapperd.dll, CreateFiTWrapper), and a TCP server and client with its own threads (the strings "server start (port %d)", "client accepted(%d)."; its socket code is in data/security_set.json) (an address range between two evidenced source files, holding several of the original files: named for its main contents). Named for the font code: the TCP library is in data/security_set.json (debuglink) and is not in the public kit

## Font

- [FontGlyphs](functions/FontGlyphs.md): 1 functions

## Frame

- [FrameRender](functions/FrameRender.md): 14 functions. Frame_Render and the per-state frame functions (App_StepGameState6-9, App_RunOpening), the afterimage and flash post effects; called from App_RenderFrameMaskedFPU

## Furniture

- [FurnitureRelease](functions/FurnitureRelease.md): 1 functions. ReleaseSlot; called from YkFurniture::Destructor; calls CXiMannequinActor
- [FurnitureSlot](functions/FurnitureSlot.md): 1 functions. Acter_DestroyAndClearSlot; called from YkFurniture::Destructor

## Generator

- [Generator](functions/Generator.md): 6 functions. YmGenerater_Stop / UpdateAttach, Generator_ClearSubobjectOrSetFlag
- [GeneratorClone](functions/GeneratorClone.md): 69 functions. CMoGeneratorClone::* (the effect generator command list), GateEffectBoxProjection
- [GeneratorCloneCtor](functions/GeneratorCloneCtor.md): 1 functions. CMoGeneratorRes_Constructor
- [GeneratorRelease](functions/GeneratorRelease.md): 2 functions. frees resources and attachments (CMoAttachments::ResetAll, YmGenerater_Stop); called from actor destructors
- [GeneratorReset](functions/GeneratorReset.md): 1 functions. SharedConditionalStateReset: stops the generators (YmGenerater_Stop) and resets

## Input

- [InputDevices](functions/InputDevices.md): 20 functions. DirectInput keyboard, mouse and joystick (DirectInput_Install*), input state and buttons, keyboard layout imports; also the debug text overlay (Debug_DrawTextTable)

## Jpeg

- [JpegScreenshot](functions/JpegScreenshot.md): 13 functions. YkJpeg::CaptureAndEncode / PutBits, TakeScreenshot, SaveJpegScreenSize, CopyrightText_Draw, the language strings japanese / english / german / french
- [JpegTables](functions/JpegTables.md): 4 functions. BuildCodeTable, BuildTables; called only from YkJpeg (Encode, InitTables)

## Kz

- [KzMotionQueList](functions/KzMotionQueList.md): 2 functions. KzMotionQueList_AdvanceAll / NotifyAll, CYyMotionQue::AppendSync; called from MotionQueue

## Linked

- [LinkedLibraries](functions/LinkedLibraries.md): 13 functions. libpng (the strings IDAT, PLTE, "Incorrect tRNS chunk length", "Ignoring incorrect gAMA value"), zlib 1.2.5, the C runtime, the import stubs (Direct3DCreate8, DirectInput8Create, the IMM jumps) (an address range between two evidenced source files, holding several of the original files: named for its main contents)

## List

- [ListUtil](functions/ListUtil.md): 2 functions. List_GetTail, PopHead; called from CXiSkeletonActor

## Lobby

- [LobbyScreen](functions/LobbyScreen.md): 29 functions. the lobby menus "loby1win", "partywin", "joblevel", the 3D avatar start (StAvatarInit), and the stream thread (the misnamed LobbyThread_*: its thread 0x10245650 reads files and queues music, sounds and streams; it never reaches Winsock) (an address range between two evidenced source files, holding several of the original files: named for its main contents)
- [LobbyUi](functions/LobbyUi.md): 17 functions. Ui_KeyPrompt_Init, KeyPrompt_Construct, the menus "lobbywin", "netwait", "netbar", "chmkname", "lobyhelp" (an address range between two evidenced source files, holding several of the original files: named for its main contents)

## Math

- [MathVector](functions/MathVector.md): 56 functions. Mat4_*, Vec3_*, Gfx_ProjectWorldToClip, Gfx_NdcToScreen: the vector and matrix code

## Mem

- [MemAllocDefault](functions/MemAllocDefault.md): 2 functions. Mem_AllocDefault (data/allocators.json)
- [MemArea](functions/MemArea.md): 2 functions. Mem_AllocFromArea (the area allocator, data/allocators.json)
- [MemBlock](functions/MemBlock.md): 8 functions. MemBlock_GetSize, Mem_FreeBlockMergeNeighbours: the block allocator
- [MemHeapDebug](functions/MemHeapDebug.md): 2 functions. Mem_DrawHeapUsageBar, the strings CYyDataMcb, CYyElemMcb, CYyMenuMcb...: the heaps drawn as bars

## Menu

- [MenuPanels](functions/MenuPanels.md): 155 functions. Menu_* panels, Movie_CreateFrameTextures / GetCurrentTexture, ActerBuff_DrawNearby, the menus "abisortw", "subwindo", "quest01" (an address range between two evidenced source files, holding several of the original files: named for its main contents)

## Mesh

- [MeshResourceCreate](functions/MeshResourceCreate.md): 8 functions. MeshResourceMng_CreateResourceByKind, ResHandle_FreeIfUnreferenced, ResourceHandle_IsResident
- [MeshResourceMng](functions/MeshResourceMng.md): 3 functions. MeshResourceMng_LoadSystemResources / ResolveTree, CMoResource::FindOrCreateTask, ResourceHandle_Deref

## Mo

- [MoDX](functions/MoDX.md): 14 functions. CMoDX::SetViewMatrix / SetWorldMatrix / Push / PopViewMatrix / CreateTexture, StateBlock_ApplyTSS, Batch_DrawPrimitives, Camera_SetupMatrices

## Model

- [ModelActorDraw](functions/ModelActorDraw.md): 1 functions. XiModelActor::BuildMatrixAndDraw / BuildWorldMatrix / CopyRectFromSlot
- [ModelActorPosition](functions/ModelActorPosition.md): 2 functions. read from the code: sets a model actor's position (actor+0x734, its model +0x24, Acter_CopyPosToCached); called from XiModelActor, XiFurnitureActor and the plant menu
- [ModelBaseDraw](functions/ModelBaseDraw.md): 4 functions. CYyModelBase::DrawLit / RefreshParts / FindPartIndex, Part_* translations
- [ModelBaseParts](functions/ModelBaseParts.md): 2 functions. CYyModelBase::AddPartFromResource / GetPartList / SetResourceAndRebuild
- [ModelCodeIndex](functions/ModelCodeIndex.md): 5 functions. MapCodeIndex, AddOffset*: read from the code
- [ModelDtBase](functions/ModelDtBase.md): 2 functions. CYyModelDtBase_Destructor and a field getter; called from CYyModelDt destructors
- [ModelDtInit](functions/ModelDtInit.md): 2 functions. CYyModelDt::Init / InitBase, CreateSharedVertexBuffers
- [ModelMinMax](functions/ModelMinMax.md): 1 functions. ComputeMinMax; called from StAvatar_InitEntry
- [ModelTranslucent](functions/ModelTranslucent.md): 8 functions. Model_BeginTranslucentPass / CompositeTranslucentPass / CreateTranslucentTargets, TexRes_LoadBm2, the g_translucent* globals; called from CXiSkeletonActor::DrawModel

## Motion

- [MotionQueue](functions/MotionQueue.md): 6 functions. MotionQueue_*, MotionQueList_*, SampleAnimationTrack_*; called from CXiSkeletonActor::SetMotion and CYyMotionQue::StartMotion

## Music

- [MusicFont](functions/MusicFont.md): 17 functions. Music_SetTrackVolume, MusicTrack_SetVolumeId*, and Font_DrawString / Font_QueueText / Font_DrawPass

## My

- [MyRoom](functions/MyRoom.md): 16 functions. YkMyroom::ChangeMode / ReleaseObject38, the menus "roomlist", "bankmenu", "mogdoor"

## Net

- [NetCellFont](functions/NetCellFont.md): 493 functions. the network (604 of its 2,763 functions are in data/security_set.json: the game connection, its packet queue and handlers, the encryption), the UI cells (Cell_*), the cursor, the fonts, the chat log (an address range between two evidenced source files, holding several of the original files: named for its main contents)

## Occlusion

- [Occlusion](functions/Occlusion.md): 10 functions. Occlusion_QueryScreenRect / DrawQuery / ReadbackCount, OcclusionMng_*, CreateProcessorInstance

## Opening

- [OpeningSubtitle](functions/OpeningSubtitle.md): 6 functions. OpeningSubtitle_Constructor / Reset, the strings music999.bgw and FinalFantasyXI, the registry imports; called from CXiOpening and App_RunOpening

## Os2

- [Os2Resource](functions/Os2Resource.md): 1 functions. CMoOs2Res::CheckVersionAndInit with the string "Os2 Version Error %d"
- [Os2VtxBuffer](functions/Os2VtxBuffer.md): 1 functions. FixOffsetsAndCreateVtxBuffer, called only from the Os2 resource check; calls CYyOs2VtxBuffer::Constructor

## Ot

- [OtLink](functions/OtLink.md): 4 functions. the OT task links (ClearLink, RelinkEntries); called from CMoOt_InitSystem and CMoOt_Update
- [OtTask](functions/OtTask.md): 2 functions. CMoOtTask::*, CMoOt_InitSystem, CMoOt_Update

## Plant

- [PlantMenu](functions/PlantMenu.md): 19 functions. the menus "plnt1" to "plnt6"; called from YkFurniture and YkMyroom::ChangeMode: read from the code

## Post

- [PostCapture](functions/PostCapture.md): 5 functions. Post_CaptureSceneToTarget, Post_CreateScreenEffectTargets, Post_DrawRotatingGhostLayers (the aura)

## Processor

- [ProcessorBounds](functions/ProcessorBounds.md): 2 functions. CMoProcessor::CalcScreenBounds, Processor_InitIdentityMatrices, Mat4x4_SafeTranspose
- [ProcessorInit](functions/ProcessorInit.md): 1 functions. InitMatrices; called only from CreateProcessorInstance
- [ProcessorMatrix](functions/ProcessorMatrix.md): 3 functions. CMoProcessorX87_SetIdentity, MultiplyTo
- [ProcessorRotation](functions/ProcessorRotation.md): 1 functions. CMoProcessorX87::RotationFromAnglesXYZ / ZYX, RotationY, RotationZ
- [ProcessorSlot](functions/ProcessorSlot.md): 2 functions. MoProcessor_CallVSlot49, ProcessorSlot41

## Proj

- [ProjTexTarget](functions/ProjTexTarget.md): 2 functions. creates and releases the projected-texture target (g_projTexTarget, CDx::CreateTexture at the viewport size); called from CYyModel::Constructor

## Que

- [QueTimeStep](functions/QueTimeStep.md): 2 functions. StepStateByTime and Update, called from CYyQue and CYyMotionQue::Update; it calls only Camera_GetFrameScale (the frame time)

## Rab

- [RabRes](functions/RabRes.md): 2 functions. CMoRabRes and CMoResource runtime classes

## Rand

- [RandAndHeader](functions/RandAndHeader.md): 7 functions. Rand_SeedMT19937 / NextMod / UniformTimes (the random numbers), Mem_AllocWithHeader12

## Resource

- [Resource](functions/Resource.md): 10 functions. CMoResource::FindByTypeAndId / FindWorker / ReleaseChain / RegisterInTypeList, YmResourceFile_FindResourceUnder
- [ResourceDtor](functions/ResourceDtor.md): 1 functions. CMoResource::Destructor
- [ResourceIter](functions/ResourceIter.md): 14 functions. ResourceIter_*, MeshResourceMng_AllocHandle / Evict, NodePool_ReleaseNode
- [ResourceLoadTask](functions/ResourceLoadTask.md): 2 functions. Start and Step of the resource load task; called from ResourceIter_FindOrStartTask and CMoResource::FindOrCreateTask

## Scene

- [SceneCamera](functions/SceneCamera.md): 6 functions. scnCameraGetInfo, SelectCamera, UpdateCameraBlend, the file "./cam_restrict.crf"
- [SceneRecord](functions/SceneRecord.md): 4 functions. InitRecord, ClearGroupField4, SetEntryField18; called from StAvatarInit and Mdl_FreeAllSlots

## Schedular

- [SchedularOps](functions/SchedularOps.md): 1 functions. read from the code: all 96 functions are called only from 0x10057FB0, CMoSchedularTask's command dispatch; they call the script reader (ScriptMacro), the attachments and the generators; the first is atan2 (fpatan)

## Scheduler

- [Scheduler](functions/Scheduler.md): 6 functions. Scheduler_AddTask / CreateTask / Kill / RemoveTasksFor

## Screen

- [ScreenDistortion](functions/ScreenDistortion.md): 1 functions. YmElem_DrawScreenDistortion

## Script

- [ScriptMacro](functions/ScriptMacro.md): 2 functions. the strings "enum", "include", "define", "//##mac", " && ", " || ", "Undefined Label !!": a script and macro reader; called from CMoSchedularTask and the afterimage task

## Shader

- [ShaderSetup](functions/ShaderSetup.md): 1 functions. Shader_CreateVertexShader, with the menu resolution settings (g_cfgMenuResX/Y); called from the device code

## Shape

- [ShapeMng](functions/ShapeMng.md): 2 functions

## Skel

- [SkelBind](functions/SkelBind.md): 1 functions. Skel_BindShared, CYyModelBase::AllocMatrixBuffers

## Skeleton

- [Skeleton](functions/Skeleton.md): 11 functions. Skel_* (bones, chains, rotation and translation)
- [SkeletonActorState](functions/SkeletonActorState.md): 1 functions. read from the code: tests and updates skeleton-actor state bytes (+0x878, +0x87A), finds textures by name; called from CXiSkeletonActor::PerActor_FourBucketStaggeredUpdate and the scheduler; the string "t123t123"

## Skin

- [SkinCpu](functions/SkinCpu.md): 5 functions. Model_SkinVerticesCpu, Skin_BlendWeightMatrices, the cached stream source / vertex shader; called from SkinAndDrawV2

## Sky

- [SkyDome](functions/SkyDome.md): 14 functions. Sky_DrawDome, Sky_DrawDomeViewCentered, and the colour byte arithmetic it uses

## Sound

- [SoundElem](functions/SoundElem.md): 15 functions. CYySoundElem::* (the sound queue, UpdateFromCamera), CMoTask::CreateMode*
- [SoundVolume](functions/SoundVolume.md): 5 functions. SetVolumeScalar, SetVolumeVector, CreateSoundElem; calls Music_SetTrackVolume and the stream thread (PushCmd)

## Spline

- [Spline](functions/Spline.md): 1 functions. CMoSpline::* (segment tables, samples, cubic segments)

## St

- [StAvatar](functions/StAvatar.md): 2 functions
- [StAvatarBuffers](functions/StAvatarBuffers.md): 1 functions. StAvatar_CheckBuffersReady
- [StAvatarCore](functions/StAvatarCore.md): 42 functions. StAvatarRender / Fini, StAvatar_* (the 3D avatar of the lobby)
- [StAvatarInfo](functions/StAvatarInfo.md): 10 functions. StAvatar_LoadInfo0 / LoadInfo2 / LoadInfoFile / GetInfoBuffer
- [StAvatarModel](functions/StAvatarModel.md): 5 functions. StAvatar_InitModel / UpdateModels / AllocArrays
- [StAvatarScene](functions/StAvatarScene.md): 28 functions. StAvatar_DrawScene / InitEntry / SetEntryTransform, the strings "static int s_%s_lightLocked[%d"
- [StChannel](functions/StChannel.md): 7 functions
- [StDancer](functions/StDancer.md): 18 functions. Dancer_InitDevice / WorldEnd, StAvatar_SetLevel / SetMode, the dancer memory globals
- [StModel](functions/StModel.md): 3 functions
- [StModelItem](functions/StModelItem.md): 7 functions. Activate, CheckFileRefs, SetPositionAndScale; called from StAvatar_ApplyChannels
- [StTrigger](functions/StTrigger.md): 3 functions

## Stream

- [StreamCmd](functions/StreamCmd.md): 1 functions. calls only the stream thread commands (SendCmd6, 8, 9: the thread at 0x10245650 reads files, never the network)

## Target

- [TargetMenu](functions/TargetMenu.md): 422 functions. Target_* (46 named), Menu_* and MenuMng_*, the menus "money", "level", "jobchang", "iteminfo", the command "/attack %d" (an address range between two evidenced source files, holding several of the original files: named for its main contents)

## Task

- [Task](functions/Task.md): 2 functions. CMoTask::Clone / Release / Destructor / ResetFields, CMoTaskMng::Forward10075120
- [TaskAndTextArgs](functions/TaskAndTextArgs.md): 20 functions. CMoTask::Dispatch / DrawQuad*, CMoTaskMng::AllocTask, the text argument parser (Arg_*), the chat tags <st>, <stpc>, <stnpc>, <stpt>

## Tex

- [TexBase](functions/TexBase.md): 2 functions. CYyTexBase::Constructor, CopyName16, the format "%10d" and "-uniq"
- [TexMgr](functions/TexMgr.md): 6 functions. TexMgr_*, CYyTexMng::FindByName
- [TexObj](functions/TexObj.md): 4 functions. TexObj_CreateAndUpload / Upload / Reupload / Release

## Text

- [TextCommand](functions/TextCommand.md): 25 functions. Command_RunLine, SeekIdByString, the commands "/ver", "echo", Actor_FindByName / GetObjectByName, ActorHandle_*
- [TextInputFiles](functions/TextInputFiles.md): 543 functions. FsTextInput_* (37), FsWordCompletion_* (24), FsLogPage_*, File_* and FileMng, Config_*, Event_Wait / Signal, the menus "keylayou", "macro", the command "/say " (an address range between two evidenced source files, holding several of the original files: named for its main contents)

## Texture

- [TexturePreview](functions/TexturePreview.md): 2 functions. Tex_DrawNamedTexturePreview, Gfx_DrawScreenQuad256: a texture drawn to the screen by name (no caller by direct call)

## Thread

- [ThreadPool](functions/ThreadPool.md): 2 functions. ThreadPool_CreateSuspendedThread, Thread_ResumeAndWait (CreateThread, ResumeThread)

## Timer

- [TimerResolution](functions/TimerResolution.md): 1 functions. timeBeginPeriod / timeEndPeriod / timeGetDevCaps, CXiTimerLow::Init; called at App create and destroy

## V

- [VBPool](functions/VBPool.md): 3 functions. VBPool_Constructor, FindMatch, Insert

## Vector

- [VectorCtorIterator](functions/VectorCtorIterator.md): 1 functions. its one named neighbour is the compiler's ??_H (vector constructor iterator, unit_evidence 0x100010A0); its function calls a callback for each element, called from object-array constructors (CreateProcessorInstance, the ZoneMap constructor)

## Vertex

- [VertexBufferList](functions/VertexBufferList.md): 1 functions. VertexBufferList_Register; called from CYyVb::Constructor

## Win

- [WinMain](functions/WinMain.md): 66 functions. App_WinMain*, App_WndProc, the window class FFXiClass / "FINAL FANTASY XI", CreateWindowExA, CoInitialize, the IME UI DLL, the camera projection (Camera_Build*)

## Xi

- [XiCapture](functions/XiCapture.md): 1 functions
- [XiDoorActor](functions/XiDoorActor.md): 3 functions
- [XiEvent](functions/XiEvent.md): 21 functions. XiEvent_* (Init, Spawn, ResetPending), _EventDataReadCallBack, the strings "ERROR!:set Work_Zone Over[%d]", "menu    eventtim"
- [XiFurnitureActor](functions/XiFurnitureActor.md): 1 functions
- [XiModelActor](functions/XiModelActor.md): 5 functions
- [XiZone](functions/XiZone.md): 22 functions

## Yk

- [YkCommon](functions/YkCommon.md): 53 functions. YkCommonInit, CTkSubWindow_DrawTime, the number drawing (DrawFraction*, DrawEasedPercent*), Gfx_ProjectWorldToScreen (an address range between two evidenced source files, holding several of the original files: named for its main contents)
- [YkFurniture](functions/YkFurniture.md): 5 functions
- [YkJpeg](functions/YkJpeg.md): 16 functions
- [YkJpgBit](functions/YkJpgBit.md): 1 functions
- [YkMyroom](functions/YkMyroom.md): 4 functions
- [YkWindows](functions/YkWindows.md): 159 functions. Yk_* (the window lists), YkWndItem_Open, YkWndList_Init, YkWndShop_Constructor, the menus "link*", "mapframe", "msgline", "money" (an address range between two evidenced source files, holding several of the original files: named for its main contents)
- [YkZip](functions/YkZip.md): 3 functions

## Ym

- [YmCombineWeather](functions/YmCombineWeather.md): 6 functions

## Zone

- [ZoneMap](functions/ZoneMap.md): 68 functions. CTsZoneMap::Render / DrawProjectedShadow / DrawProjectedTexture, XiZone_Draw / DrawElement, ModelActor_Draw, Env_*
- [ZoneMapLoad](functions/ZoneMapLoad.md): 49 functions. ParseZoneMeshData, the ZoneMap_* constructors and lookups, the debug boxes (Dbg_DrawOrientedBoxes) (an address range between two evidenced source files, holding several of the original files: named for its main contents)
- [ZoneResWeather](functions/ZoneResWeather.md): 1 functions. called only from MeshResourceMng_CreateResourceByKind, the zone map resource; the string "awanbraccol1sh-usuim": read from the code
- [ZoneResource](functions/ZoneResource.md): 1 functions. called only from MeshResourceMng_CreateResourceByKind; calls the ZoneMap code: read from the code
- [ZoneShaderCompile](functions/ZoneShaderCompile.md): 2 functions. Gfx_AssembleVertexShader, Gfx_CompileVertexShader / PixelShader; called from CTsZoneMap

## chasm

- [chasm](functions/chasm.md): 3 functions

## chn

- [chn](functions/chn.md): 6 functions

## mdl

- [mdl](functions/mdl.md): 25 functions

## sq

- [SqBoneTransform](functions/SqBoneTransform.md): 3 functions. ComputeTransform, TransformPoint; called from the sqmo channels
- [SqBounds](functions/SqBounds.md): 5 functions. ComputeBounds, GetCenter, SumAxis; called from the sqsh meshes
- [SqChannelDefaults](functions/SqChannelDefaults.md): 1 functions. InitDefaults; called from sqmoUtil and Mdl_ChannelRegister
- [SqChannelHandler](functions/SqChannelHandler.md): 1 functions. SetHandlerByType; called from sqmoPlaybackChannel
- [SqChannelMotion](functions/SqChannelMotion.md): 1 functions. CreateWithOwner; calls SqmoChannelMotion_Create
- [SqConnector](functions/SqConnector.md): 1 functions. CreateFromFields; calls SqcoConnector_Create
- [SqDebug](functions/SqDebug.md): 4 functions. sqDebugPrintf, sqDrawableDraw
- [SqDrawableTwoPass](functions/SqDrawableTwoPass.md): 1 functions. Drawable_DrawTwoPass
- [SqIOHooks](functions/SqIOHooks.md): 3 functions. CallHook2C / 3C / 40; called from sqinIO, sqmdIO, the image readers
- [SqItemValue](functions/SqItemValue.md): 2 functions. GetValueByItemKind, SetValueByType; called from Mdl_* and the sqmo channels
- [SqMatrixConnect](functions/SqMatrixConnect.md): 14 functions. M4fTransform, M4fTranspose, IsConnected, ReleaseConnection, SetCallback
- [SqMatrixSet](functions/SqMatrixSet.md): 1 functions. Set; called from sqMatrix3 and sqMatrix4
- [SqMem](functions/SqMem.md): 12 functions. sqMemInit, sqFree, SqMem_*: the dancer libraries' memory
- [SqNibbleSwap](functions/SqNibbleSwap.md): 1 functions. SwapNibblesXor; called from the readers (sqIO, sqimImage)
- [SqPlanarShadow](functions/SqPlanarShadow.md): 5 functions. sqsnPlanarShadowDraw, RenderShadowTexture, DrawShadowedShape
- [SqPlaybackChannelLoad](functions/SqPlaybackChannelLoad.md): 1 functions. PlaybackChannel_Load, the string "Error: PlaybackChannel version"
- [SqQuat](functions/SqQuat.md): 12 functions. QuatFromEuler, FromAxisAngle, FromRotationX/Y/Z, ToMatrix3
- [SqQuatMul](functions/SqQuatMul.md): 4 functions. Mul, NegateInPlace, RotateVec, Sq_PrintFloat4Indented
- [SqScriptRead](functions/SqScriptRead.md): 4 functions. sqScript_TokenEquals, ReadBlock, Sq_PrintIndent
- [SqShaderFlag](functions/SqShaderFlag.md): 1 functions. Shader_SetFlagBit0; called from sqmdIO and sqmdScript
- [SqShadowVolume](functions/SqShadowVolume.md): 5 functions. sqsnShadowVolumeBeginVB / SetPass, sqgxShadowPlaneMatrix, sqgxShadowStencilEnable
- [SqShadowVolumeDraw](functions/SqShadowVolumeDraw.md): 3 functions. sqsnShadowVolumeDraw
- [SqSkelNode](functions/SqSkelNode.md): 6 functions. CopyQuatAt68, CopyVec3At5C, SetFloatAt94: the skeleton node fields; called from sqskSkeleton
- [SqSnapRef](functions/SqSnapRef.md): 1 functions. CreateRef; calls SqmdSnap_Create
- [SqTextureBind](functions/SqTextureBind.md): 2 functions. Texture_BindFromObject, Texture_CreateEntry
- [SqVec](functions/SqVec.md): 11 functions. PackVec4, CopyVec3, CrossProduct, LerpFactor, the string "Error: Couldn't find link %d"
- [SqgxContext](functions/SqgxContext.md): 44 functions. SqgxContext_* (the dancer device context), SetPerspective
- [SqgxContextField](functions/SqgxContextField.md): 1 functions. Sqgx_SetContextFieldE24
- [SqgxLighting](functions/SqgxLighting.md): 4 functions. ApplyLighting, Sqgx_IncCounter / ResetCounter
- [SqgxPending](functions/SqgxPending.md): 4 functions. Sqgx_AddPendingEntry / ResetPendingList / CopyBlockToContext
- [SqgxTextureImage](functions/SqgxTextureImage.md): 5 functions. sqgxTextureCreateFromImage, sqgxTextureAddZ, CompositeBlendPasses
- [SqgxVertexShader](functions/SqgxVertexShader.md): 2 functions. sqgxVertexShaderCreate / Select
- [SqgxVertexShaderRelease](functions/SqgxVertexShaderRelease.md): 3 functions. sqgxVertexShaderRelease
- [SqinBuild](functions/SqinBuild.md): 1 functions. SqinBuild_BuildSQO
- [SqinSkinAppend](functions/SqinSkinAppend.md): 1 functions. Append; calls SqinSkin_ResizeItemArray
- [SqmdDMBUpdaters](functions/SqmdDMBUpdaters.md): 2 functions. SqmdDMB_BuildUpdaters, ResolveSkelRefs
- [SqsdPassTest](functions/SqsdPassTest.md): 1 functions. TestSeparationHalf; called from the sqsd shaders and Drawable_DrawTwoPass
- [SqshBuild](functions/SqshBuild.md): 1 functions. SqshBuild_BuildSQO
- [SqskBuild](functions/SqskBuild.md): 2 functions. SqskSkeleton_BuildBinary / BuildSQO
- [sqIO](functions/sqIO.md): 1 functions
- [sqMatrix3](functions/sqMatrix3.md): 1 functions
- [sqMatrix4](functions/sqMatrix4.md): 4 functions
- [sqObject](functions/sqObject.md): 1 functions
- [sqQuat](functions/sqQuat.md): 1 functions
- [sqTimer](functions/sqTimer.md): 1 functions
- [sqVtx](functions/sqVtx.md): 6 functions
- [sqcoConnector](functions/sqcoConnector.md): 2 functions
- [sqdfShape](functions/sqdfShape.md): 3 functions
- [sqgxContext](functions/sqgxContext.md): 3 functions
- [sqgxDlist](functions/sqgxDlist.md): 4 functions
- [sqgxShape](functions/sqgxShape.md): 3 functions
- [sqgxTexture](functions/sqgxTexture.md): 14 functions
- [sqhiNode](functions/sqhiNode.md): 5 functions
- [sqimImage](functions/sqimImage.md): 2 functions
- [sqinBuild](functions/sqinBuild.md): 1 functions
- [sqinCluster](functions/sqinCluster.md): 2 functions
- [sqinShape](functions/sqinShape.md): 1 functions
- [sqinSkin](functions/sqinSkin.md): 7 functions
- [sqmdDMB](functions/sqmdDMB.md): 11 functions
- [sqmdModel](functions/sqmdModel.md): 27 functions
- [sqmdSnap](functions/sqmdSnap.md): 2 functions
- [sqmdSort](functions/sqmdSort.md): 4 functions
- [sqmoBuild](functions/sqmoBuild.md): 2 functions
- [sqmoChannel](functions/sqmoChannel.md): 1 functions
- [sqmoChannelMotion](functions/sqmoChannelMotion.md): 2 functions
- [sqmoFrameChannel](functions/sqmoFrameChannel.md): 3 functions
- [sqmoKeyChannel](functions/sqmoKeyChannel.md): 2 functions
- [sqmoPlaybackChannel](functions/sqmoPlaybackChannel.md): 3 functions
- [sqmoUtil](functions/sqmoUtil.md): 1 functions
- [sqopOpcode](functions/sqopOpcode.md): 1 functions
- [sqopSystem](functions/sqopSystem.md): 3 functions
- [sqopTrack](functions/sqopTrack.md): 4 functions
- [sqrdCamera](functions/sqrdCamera.md): 2 functions
- [sqrdLight](functions/sqrdLight.md): 1 functions
- [sqrdMaterial](functions/sqrdMaterial.md): 1 functions
- [sqrdTexture](functions/sqrdTexture.md): 2 functions
- [sqsdAniso](functions/sqsdAniso.md): 2 functions
- [sqsdAnisoCommon](functions/sqsdAnisoCommon.md): 1 functions
- [sqsdCartoon](functions/sqsdCartoon.md): 2 functions
- [sqsdGeneric](functions/sqsdGeneric.md): 3 functions
- [sqsdGlow](functions/sqsdGlow.md): 2 functions
- [sqsdSampling](functions/sqsdSampling.md): 2 functions
- [sqshBuild](functions/sqshBuild.md): 4 functions
- [sqshCurves](functions/sqshCurves.md): 5 functions
- [sqshDispList](functions/sqshDispList.md): 2 functions
- [sqshPoints](functions/sqshPoints.md): 2 functions
- [sqshTriStrip](functions/sqshTriStrip.md): 4 functions
- [sqskJoint](functions/sqskJoint.md): 3 functions
- [sqskSkeleton](functions/sqskSkeleton.md): 7 functions
- [sqsnScene](functions/sqsnScene.md): 31 functions
- [sqsnShadow](functions/sqsnShadow.md): 1 functions
- [sqxfXformM](functions/sqxfXformM.md): 1 functions
- [sqxfXformTD](functions/sqxfXformTD.md): 2 functions
