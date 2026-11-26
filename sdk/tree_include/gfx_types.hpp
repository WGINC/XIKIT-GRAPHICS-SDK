// gfx_types.hpp -- game types from the IDB that this tree does not define itself.
#pragma once
class CAcc;
class CApp;
class CAtelIdleTask;
class CDx;
class CEnv;
class CMoActorColorDriveTask;
class CMoActorRotationDriveTask;
class CMoAttachments;
class CMoFloatingNumberTaskAttachments;
class CMoSchOp0DAttachments;
class CMoSchOp0CAttachments;
class CMoGeneratorResAttachments;
class CMoSchOp1DAttachments;
class CMoSchOp1FAttachments;
class CMoSchOp07Attachments;
class CMoSchOp2CAttachments;
class CMoSchOpBFAttachments;
class CMoSchOp62Attachments;
class CMoSchOpSharedAttachments;
class CMoSchOp48Attachments;
class CMoSchOp7FAttachments;
class CMoSchOp42Attachments;
class CMoSchOp40Attachments;
class CMoSchOp75Attachments;
class CMoSchOpB5Attachments;
class CMoSchOpBCAttachments;
class CMoSchOp9BAttachments;
class CMoSchOp7AAttachments;
class CMoSchOpB4Attachments;
class CMoSchOp2EAttachments;
class CMoSchOp2FAttachments;
class CMoSchOp59Attachments;
class CMoResourceWaitTaskAttachments;
class CMoSchedulerResAttachments;
class CMoUseMagicWaitTaskAttachments;
class CMoCamera;
class CMoCameraTask;
class CMoCelestial;
class CMoD3aElem;
class CMoD3aLightmapElem;
class CMoD3mSpecularElem;
class CMoDX;
class CMoDisintegrateProgElem;
class CMoDist;
class CMoDistModelElem;
class CMoDistMorphElem;
class CMoDistRingElem;
class CMoDxStatusMng;
class CMoElem;
class CMoDamValueProgElem;
class CMoGeneratorClone;
class CMoGeneratorRes;
class CMoGeneratorClone;
class CMoLfdElem;
class CMoLockColorDriveTask;
class CMoLockLookAtDriveTask;
class CMoNullProgElem;
class CMoOT;
class CMoOcclusionMng;
class CMoOtTask;
class CMoFloatingNumberTask;
class CMoPathDriveActorTask;
class CMoPathObject;
class CMoPointLightProgElem;
class CMoProcessor;
class CMoProcessor3DNow;
class CMoProcessorSSE;
class CMoProcessorX87;
class CMoResource;
class CMoResourceMng;
class CMoSepRes;
class CMoRmpRes;
class CMoKeyFrameRes;
class CMoResType5F;
class CMoMebRes;
class CMoMsbRes;
class CMoD3bRes;
class CMoD3aRes;
class CMoD3mRes;
class CMoAfbRes;
class CMoResType5E;
class CMoCibRes;
class CMoMo2Res;
class CMoSk2Res;
class CMoOs2Res;
class CMoBpRes;
class CMoBm2Res;
class CMoBm2RefRes;
class CMoMmbRes;
class CMoMzbRes;
class CMoRidRes;
class CMoWeatherRes;
class CMoSchedularTask;
class CMoSkeletonElem;
class CMoSphRes;
class CMoSpline;
class CMoTask;
class CMoTaskMng;
class CMoCameraSetupTask;
class CMoVolumeChangeTask;
class CMoSchOp0DTask;
class CMoSchOp0CTask;
class CMoGeneratorTask;
class CMoSchOp1DTask;
class CMoResourceWaitTask;
class CMoResourceLoadTask;
class CMoAuctionMenuTask;
class CMoUseMagicWaitTask;
class CMoVuAnmElem;
class CMoVuDist;
class CMoVuLineProgElem;
class CShader;
class CTsZoneMap;
class CMoD3bElem;
class CMoD3mElem;
class CMoD3mLightmapElem;
class CMoRingProgElem;
class CXiActor;
class CXiActorDraw;
class CXiActorNameDraw;
class CXiAtelActor;
class CXiCollisionActor;
class CXiControlActor;
class CXiDancerActor;
class CXiMovie;
class CXiOpening;
class CXiSkeletonActor;
class CXiSkeletonActorRes;
class CXiTimerLow;
class CYyCamMng2;
class CYyIcon;
class CYyModel;
class CYyModelBase;
class CYyModelDt;
class CYyModelDtStreamed;
class CYyModelDtBuffered;
class CYyMotionQue;
class CYyMusicLoadTask;
class CYyObject;
class CYyOs2VtxBuffer;
class CYySkl;
class CYySoundElem;
class CYyTex;
class CYyTexBase;
class CYyTexMng;
class CYyVb;
class CYyVbMng;
class FontGlyphs;
class ShapeMng;
class EventTextBlock;
class XiDoorActor;
class XiFurnitureActor;
class XiModelActor;
class XiZone;
class YkFurniture;
class YkJpeg;
class YkJpgBit;
class YkMyroom;
class YkZip;
class YmCombineWeather;
struct CMoProcessor_recon;
struct CMoSchOp82Task;
struct CMoSchOp0FTask;
struct CMoSchOp10Task;
struct CMoSchOp1FTask;
struct CMoSchOp07Task;
struct CMoSchOp6FTask;
struct CMoSchOpBFTask;
struct CMoSchOp62Task;
struct CMoSchOp75Task;
struct CMoSchOpB5Task;
struct CMoSchOpBCTask;
struct CMoSchOp9BTask;
struct CMoSchOp7ATask;
struct CMoSchOpB4Task;
struct CMoSchOp2ETask;
struct CMoSchOp2FTask;
struct CMoSchOp59Task;
struct XiActorTimerTask;
// Game types exported from the IDB (IDA print_decls); D3D types come from xi_d3d8.hpp.

struct _RTL_CRITICAL_SECTION_DEBUG;
struct tagBITMAPINFO;
struct _iobuf;
struct IDirect3D8;
struct IDirect3DVolume8;
struct IDirect3DSwapChain8;
struct IDirect3DSurface8;
struct IDirect3DVertexBuffer8;
struct IDirect3DIndexBuffer8;
struct IDirect3DBaseTexture8;
struct IDirect3DCubeTexture8;
struct IDirect3DTexture8;
struct IDirect3DVolumeTexture8;
struct IDirect3DDevice8;
struct IDirect3D8Vtbl;
struct IDirect3DVolume8Vtbl;
struct IDirect3DSwapChain8Vtbl;
struct IDirect3DSurface8Vtbl;
struct IDirect3DVertexBuffer8Vtbl;
struct IDirect3DIndexBuffer8Vtbl;
struct IDirect3DBaseTexture8Vtbl;
struct IDirect3DCubeTexture8Vtbl;
struct IDirect3DTexture8Vtbl;
struct IDirect3DVolumeTexture8Vtbl;
struct IDirect3DDevice8Vtbl;
struct D3DLOCKED_RECT;
struct D3DLOCKED_BOX;
struct _D3DVIEWPORT9;
struct CDx_vtbl;
struct CMoAttachments_vtbl;
struct CMoCelestial_vtbl;
struct CMoDX_vtbl;
struct CMoDxStatusMng_vtbl;
struct CMoOT_vtbl;
struct CMoOcclusionMng_vtbl;
struct CMoResource_vtbl;
struct CMoResourceMng_vtbl;
struct CMoSpline_vtbl;
struct CMoTask_vtbl;
struct CMoTaskMng_vtbl;
struct CShader_vtbl;
struct CXiOpening_vtbl;
struct CYyModel_vtbl;
struct CYyModelBase_vtbl;
struct CYyModelDt_vtbl;
struct CYyTexBase_vtbl;
struct CYyTexMng_vtbl;

/* 2 */
struct HINSTANCE__
{
  int unused;
};

/* 3 */
typedef unsigned int DWORD;

/* 14 */
typedef unsigned int UINT;

/* 16 */
typedef char CHAR;

/* 19 */
#ifndef __cplusplus   /* C++ has wchar_t built in: g++ ignored this typedef (-fpermissive), clang refuses it */
typedef unsigned short wchar_t;
#endif

/* 18 */
typedef wchar_t WCHAR;

/* 24 */
typedef unsigned int ULONG_PTR;

/* 27 */
struct HKEY__
{
  int unused;
};

/* 33 */
typedef int BOOL;

/* 36 */
typedef struct _RTL_CRITICAL_SECTION_DEBUG *PRTL_CRITICAL_SECTION_DEBUG;

/* 41 */
typedef int LONG;

/* 42 */
typedef void *HANDLE;

/* 35 */
#pragma pack(push, 8)
struct _RTL_CRITICAL_SECTION
{
  PRTL_CRITICAL_SECTION_DEBUG DebugInfo;
  LONG LockCount;
  LONG RecursionCount;
  HANDLE OwningThread;
  HANDLE LockSemaphore;
  ULONG_PTR SpinCount;
};
#pragma pack(pop)

/* 38 */
typedef unsigned short WORD;

/* 40 */
struct _LIST_ENTRY
{
  struct _LIST_ENTRY *Flink;
  struct _LIST_ENTRY *Blink;
};

/* 39 */
typedef struct _LIST_ENTRY LIST_ENTRY;

/* 37 */
struct _RTL_CRITICAL_SECTION_DEBUG
{
  WORD Type;
  WORD CreatorBackTraceIndex;
  struct _RTL_CRITICAL_SECTION *CriticalSection;
  LIST_ENTRY ProcessLocksList;
  DWORD EntryCount;
  DWORD ContentionCount;
  DWORD Flags;
  WORD CreatorBackTraceIndexHigh;
  WORD SpareWORD;
};

/* 62 */
typedef unsigned char BYTE;

/* 64 */
struct tagRECT
{
  LONG left;
  LONG top;
  LONG right;
  LONG bottom;
};

/* 65 */
typedef struct tagBITMAPINFO BITMAPINFO;

/* 68 */
struct tagBITMAPINFOHEADER
{
  DWORD biSize;
  LONG biWidth;
  LONG biHeight;
  WORD biPlanes;
  WORD biBitCount;
  DWORD biCompression;
  DWORD biSizeImage;
  LONG biXPelsPerMeter;
  LONG biYPelsPerMeter;
  DWORD biClrUsed;
  DWORD biClrImportant;
};

/* 67 */
typedef struct tagBITMAPINFOHEADER BITMAPINFOHEADER;

/* 70 */
struct tagRGBQUAD
{
  BYTE rgbBlue;
  BYTE rgbGreen;
  BYTE rgbRed;
  BYTE rgbReserved;
};

/* 69 */
typedef struct tagRGBQUAD RGBQUAD;

/* 66 */
struct tagBITMAPINFO
{
  BITMAPINFOHEADER bmiHeader;
  RGBQUAD bmiColors[1];
};

/* 73 */
struct _SYSTEMTIME
{
  WORD wYear;
  WORD wMonth;
  WORD wDayOfWeek;
  WORD wDay;
  WORD wHour;
  WORD wMinute;
  WORD wSecond;
  WORD wMilliseconds;
};

/* 88 */
typedef unsigned int size_t;

/* 115 */
typedef struct _iobuf FILE;

/* 116 */
struct _iobuf
{
  char *_ptr;
  int _cnt;
  char *_base;
  int _flag;
  int _file;
  int _charbuf;
  int _bufsiz;
  char *_tmpfname;
};

/* 49 */
typedef unsigned int UINT_PTR;

/* 119 */
typedef UINT_PTR WPARAM;

/* 121 */
typedef int LONG_PTR;

/* 120 */
typedef LONG_PTR LPARAM;

/* 127 */
struct HWND__
{
  int unused;
};

/* 126 */
typedef struct HWND__ *HWND;

/* 130 */
struct tagPOINT
{
  LONG x;
  LONG y;
};

/* 129 */
typedef struct tagPOINT POINT;

/* 128 */
struct tagMSG
{
  HWND hwnd;
  UINT message;
  WPARAM wParam;
  LPARAM lParam;
  DWORD time;
  POINT pt;
};

/* 153 */
typedef int HRESULT;

/* 159 */
typedef LONG_PTR LRESULT;

/* 161 */
struct HICON__
{
  int unused;
};

/* 170 */
struct HBITMAP__
{
  int unused;
};

/* 182 */
typedef ULONG_PTR DWORD_PTR;

/* 222 */
#pragma pack(push, 8)
struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
};
#pragma pack(pop)

/* 632 */
struct CMoTask_vtbl
{
  void *vf0_CMoTask_GetRuntimeClass_variant12;
  void *vf1_CApp_vf001;
  unsigned int (__thiscall *vf2_game_1002C930)(uint32_t *self, char);
  int (__thiscall *vf3_game_1002C920)(uint32_t *self);
  void *vf4_CApp_vf004;
  void *vf5_CApp_vf005;
  uint32_t *(__thiscall *vf6_CMoTask_ScalarDeletingDtor)(CMoTask *C, char);
  void *vf7_CMoTask_vf007;
  void *vf8_CMoTask_vf008;
  void *vf9_CMoTask_vf009;
  void (__stdcall *vf10_CMoTask_vf010)(int);
};

/* 555 */
struct CDx_vtbl
{
  void *vf0_CDx_GetRuntimeClass;
  void *vf1_CApp_vf001;
  unsigned int (__thiscall *vf2_game_1002C930)(uint32_t *self, char);
  int (__thiscall *vf3_game_1002C920)(uint32_t *self);
  void *vf4_CApp_vf004;
  void *vf5_CApp_vf005;
  void *(__thiscall *vf6_CDx_ScalarDeletingDtor)(CDx *C, char);
};

/* 556 */
struct CMoAttachments_vtbl
{
  void *vf0_CMoAttachments_GetRuntimeClass;
  uint32_t *(__thiscall *vf1_CMoAttachments_ScalarDeletingDtor)(CMoAttachments *self, char);
  int (__thiscall *vf2_game_1003C720)(uint32_t *self);
  int (__thiscall *vf3_game_1003C730)(uint32_t *self);
  void *vf4_CMoAttachments_vf004;
  void *vf5_CMoAttachments_vf005;
  void *vf6_CMoAttachments_vf006;
};

/* 583 */
struct CMoCelestial_vtbl
{
  void *vf0_CMoCelestial_GetRuntimeClass;
  void *vf1_CApp_vf001;
  unsigned int (__thiscall *vf2_game_1002C930)(uint32_t *self, char);
  int (__thiscall *vf3_game_1002C920)(uint32_t *self);
  void *vf4_CApp_vf004;
  void *vf5_CApp_vf005;
  uint32_t *(__thiscall *vf6_CMoCelestial_ScalarDeletingDtor)(CMoCelestial *C, char);
};

/* 587 */
struct CMoDX_vtbl
{
  void *vf0_CMoDX_GetRuntimeClass;
  void *vf1_CApp_vf001;
  unsigned int (__thiscall *vf2_game_1002C930)(uint32_t *self, char);
  int (__thiscall *vf3_game_1002C920)(uint32_t *self);
  void *vf4_CApp_vf004;
  void *vf5_CApp_vf005;
  uint8_t *(__thiscall *vf6_CMoDX_ScalarDeletingDtor)(CMoDX *C, char);
};

/* 593 */
struct CMoDxStatusMng_vtbl
{
  void *vf0_CMoDxStatusMng_GetRuntimeClass;
  void *vf1_CApp_vf001;
  unsigned int (__thiscall *vf2_game_1002C930)(uint32_t *self, char);
  int (__thiscall *vf3_game_1002C920)(uint32_t *self);
  void *vf4_CApp_vf004;
  void *vf5_CApp_vf005;
  int *(__thiscall *vf6_CMoDxStatusMng_ScalarDeletingDtor)(CMoDxStatusMng *C, char);
};

/* 606 */
struct CMoResource_vtbl
{
  void *vf0_CMoResource_GetRuntimeClass_variant3;
  short (__thiscall *vf1_CMoCamera_GetLinkedObject)(uint32_t *self, uint32_t *);
  unsigned int (__thiscall *vf2_game_1002C930)(uint32_t *self, char);
  int (__thiscall *vf3_game_1002C920)(uint32_t *self);
  int (__thiscall *vf4_CMoCamera_SetLinkedObject)(uint32_t **self, int);
  void (__stdcall *vf5_CMoResource_vf005)(int);
  unsigned int **(__thiscall *vf6_CMoResource_ScalarDeletingDtor)(CMoResource *C, char);
  unsigned int (__thiscall *vf7_CMoResource_CopyBodyTo20_as_v0)(int self, uint32_t *);
  void *vf8_CMoResource_vf008;
  short (__thiscall *vf9_CMoResource_Destroy)(int self);
  void *vf10_CMoCamera_GetSharedInstance;
};

/* 598 */
struct CMoOT_vtbl
{
  void *vf0_CMoOT_GetRuntimeClass;
  void *vf1_CApp_vf001;
  unsigned int (__thiscall *vf2_game_1002C930)(uint32_t *self, char);
  int (__thiscall *vf3_game_1002C920)(uint32_t *self);
  void *vf4_CApp_vf004;
  void *vf5_CApp_vf005;
  int *(__thiscall *vf6_CMoOT_ScalarDeletingDtor)(CMoOT *C, char);
};

/* 599 */
struct CMoOcclusionMng_vtbl
{
  void *vf0_CMoOcclusionMng_GetRuntimeClass;
  void *vf1_CApp_vf001;
  unsigned int (__thiscall *vf2_game_1002C930)(uint32_t *self, char);
  int (__thiscall *vf3_game_1002C920)(uint32_t *self);
  void *vf4_CApp_vf004;
  void *vf5_CApp_vf005;
  int *(__thiscall *vf6_CMoOcclusionMng_ScalarDeletingDtor)(CMoOcclusionMng *C, char);
};

/* 607 */
struct CMoResourceMng_vtbl
{
  void *vf0_CMoResourceMng_GetRuntimeClass;
  void *vf1_CApp_vf001;
  unsigned int (__thiscall *vf2_game_1002C930)(uint32_t *self, char);
  int (__thiscall *vf3_game_1002C920)(uint32_t *self);
  void *vf4_CApp_vf004;
  void *vf5_CApp_vf005;
  uint32_t *(__thiscall *vf6____G__basic_ios_DU__char_traits_D_std___std__UAEPAXI_Z_0_0)(CMoResourceMng *self, char);
};

/* 631 */
struct CMoSpline_vtbl
{
  void *vf0_CMoSpline_GetRuntimeClass;
  void *vf1_CApp_vf001;
  unsigned int (__thiscall *vf2_game_1002C930)(uint32_t *self, char);
  int (__thiscall *vf3_game_1002C920)(uint32_t *self);
  void *vf4_CApp_vf004;
  void *vf5_CApp_vf005;
  int *(__thiscall *vf6_CMoSpline_ScalarDeletingDtor)(CMoSpline *C, char);
};

/* 633 */
struct CMoTaskMng_vtbl
{
  void *vf0_CMoTaskMng_GetRuntimeClass;
  void *vf1_CApp_vf001;
  unsigned int (__thiscall *vf2_game_1002C930)(uint32_t *self, char);
  int (__thiscall *vf3_game_1002C920)(uint32_t *self);
  void *vf4_CApp_vf004;
  void *vf5_CApp_vf005;
  uint32_t *(__thiscall *vf6_CMoTaskMng_ScalarDeletingDtor)(CMoTaskMng *C, char);
};

/* 643 */
struct CShader_vtbl
{
  void *vf0_CShader_GetRuntimeClass;
  void *vf1_CApp_vf001;
  unsigned int (__thiscall *vf2_game_1002C930)(uint32_t *self, char);
  int (__thiscall *vf3_game_1002C920)(uint32_t *self);
  void *vf4_CApp_vf004;
  void *vf5_CApp_vf005;
  unsigned int *(__thiscall *vf6_CShader_ScalarDeletingDtor)(CShader *C, char);
};

/* 646 */
struct CXiOpening_vtbl
{
  void *vf0_CXiOpening_GetRuntimeClass;
  void *vf1_CApp_vf001;
  unsigned int (__thiscall *vf2_game_1002C930)(uint32_t *self, char);
  int (__thiscall *vf3_game_1002C920)(uint32_t *self);
  void *vf4_CApp_vf004;
  void *vf5_CApp_vf005;
  int *(__thiscall *vf6_CXiOpening_ScalarDeletingDtor)(CXiOpening *C, char);
};

/* 649 */
struct CYyModel_vtbl
{
  void *vf0_CYyModel_GetRuntimeClass;
  void *vf1_CApp_vf001;
  unsigned int (__thiscall *vf2_game_1002C930)(uint32_t *self, char);
  int (__thiscall *vf3_game_1002C920)(uint32_t *self);
  void *vf4_CApp_vf004;
  void *vf5_CApp_vf005;
  int *(__thiscall *vf6_CYyModel_ScalarDeletingDtor)(CYyModel *C, char);
};

/* 650 */
struct CYyModelBase_vtbl
{
  void *vf0_CYyModelBase_GetRuntimeClass;
  void *vf1_CApp_vf001;
  unsigned int (__thiscall *vf2_game_1002C930)(uint32_t *self, char);
  int (__thiscall *vf3_game_1002C920)(uint32_t *self);
  void *vf4_CApp_vf004;
  void *vf5_CApp_vf005;
  int *(__thiscall *vf6_CYyModelBase_ScalarDeletingDtor)(CYyModelBase *C, char arg2);
};

/* 651 */
struct CYyModelDt_vtbl
{
  void *vf0_CYyModelDt_GetRuntimeClass;
  void *vf1_CApp_vf001;
  unsigned int (__thiscall *vf2_game_1002C930)(uint32_t *self, char);
  int (__thiscall *vf3_game_1002C920)(uint32_t *self);
  void *vf4_CApp_vf004;
  void *vf5_CApp_vf005;
  uint32_t *(__thiscall *vf6_CYyModelDt_ScalarDeletingDtor)(CYyModelDt *C, char arg2);
  void *vf7___purecall;
  void *vf8___purecall;
  void *vf9___purecall;
  void *vf10___purecall;
  void *vf11___purecall;
};

/* 656 */
struct CYyTexBase_vtbl
{
  void *vf0_CYyTexBase_GetRuntimeClass_variant0;
  void *vf1_CApp_vf001;
  unsigned int (__thiscall *vf2_game_1002C930)(uint32_t *self, char);
  int (__thiscall *vf3_game_1002C920)(uint32_t *self);
  void *vf4_CApp_vf004;
  void *vf5_CApp_vf005;
  uint32_t *(__thiscall *vf6_CYyTexBase_ScalarDeletingDtor)(CYyTexBase *C, char);
};

/* 657 */
struct CYyTexMng_vtbl
{
  void *vf0_CYyTexMng_GetRuntimeClass;
  void *vf1_CApp_vf001;
  unsigned int (__thiscall *vf2_game_1002C930)(uint32_t *self, char);
  int (__thiscall *vf3_game_1002C920)(uint32_t *self);
  void *vf4_CApp_vf004;
  void *vf5_CApp_vf005;
  uint32_t *(__thiscall *vf6_CYyTexMng_ScalarDeletingDtor)(CYyTexMng *C, char);
};

/* 513 */
struct D3DHolder
{
  void *vftable;
  IDirect3D8 *pD3D;
  IDirect3DDevice8 *pDevice;
  unsigned char _rest[1132];
};

/* 514 */
struct tagPALETTEENTRY
{
  BYTE peRed;
  BYTE peGreen;
  BYTE peBlue;
  BYTE peFlags;
};

/* 523 */
typedef struct _D3DVIEWPORT9 D3DVIEWPORT9;

/* 524 */
#pragma pack(push, 4)
struct _D3DVIEWPORT9
{
  DWORD X;
  DWORD Y;
  DWORD Width;
  DWORD Height;
  float MinZ;
  float MaxZ;
};
#pragma pack(pop)

/* 525 */
struct /*VFT*/ Vt_1032A460_vtbl
{
  int (__thiscall *vf0_CYyModelDtStreamed_ScalarDeletingDtor_2)(CYyModelDtStreamed *self, int arg2);
};

/* 526 */
struct Vt_1032A460
{
  struct Vt_1032A460_vtbl *vftable;
};

/* 527 */
struct /*VFT*/ Vt_1032AFD4_vtbl
{
  int (__thiscall *vf0_CMoSchOp0CTask_ScalarDeletingDtor_2)(CMoSchOp0CTask *self, int arg2);
};

/* 528 */
struct Vt_1032AFD4
{
  struct Vt_1032AFD4_vtbl *vftable;
};

/* 529 */
struct /*VFT*/ Vt_1032B680_vtbl
{
  int (__thiscall *vf0_CMoGeneratorTask_vf011)(CMoGeneratorTask *self);
  int (__thiscall *vf1_CMoGeneratorTask_vf012)(CMoGeneratorTask *self, int arg2);
  int (__thiscall *vf2_game_1003C720)(uint32_t *self);
  int (__thiscall *vf3_game_1003C730)(uint32_t *self);
  char (__thiscall *vf4_game_10054380)(void *self);
  char (__thiscall *vf5_game_10054390)(void *self);
  char *(__thiscall *vf6_game_10053830)(char *self);
};

/* 530 */
struct Vt_1032B680
{
  struct Vt_1032B680_vtbl *vftable;
};

/* 531 */
struct /*VFT*/ Vt_1032B988_vtbl
{
  int (__thiscall *vf0_CMoSchOp1DTask_vf011)(CMoSchOp1DTask *self);
  int (__thiscall *vf1_CMoSchOp1DTask_vf012)(CMoSchOp1DTask *self, int arg2);
  int (__thiscall *vf2_game_1003C720)(uint32_t *self);
  int (__thiscall *vf3_game_1003C730)(uint32_t *self);
  bool (__thiscall *vf4_game_1005E980)(char *self);
  bool (__thiscall *vf5_game_1005E9A0)(char *self);
  char *(__thiscall *vf6_game_1005E970)(char *self);
};

/* 532 */
struct Vt_1032B988
{
  struct Vt_1032B988_vtbl *vftable;
};

/* 533 */
struct /*VFT*/ Vt_1032B9D0_vtbl
{
  int (__thiscall *vf0_CMoPathDriveActorTask_vf011)(CMoPathDriveActorTask *self);
  int (__thiscall *vf1_CMoPathDriveActorTask_vf012)(CMoPathDriveActorTask *self, int arg2);
  int (__thiscall *vf2_game_1003C720)(uint32_t *self);
  int (__thiscall *vf3_game_1003C730)(uint32_t *self);
  bool (__thiscall *vf4_game_1005F380)(char *self);
  bool (__thiscall *vf5_game_1005F3A0)(char *self);
  char *(__thiscall *vf6_game_1005F370)(char *self);
};

/* 534 */
struct Vt_1032B9D0
{
  struct Vt_1032B9D0_vtbl *vftable;
};

/* 535 */
struct /*VFT*/ Vt_1032BA18_vtbl
{
  int (__thiscall *vf0_CMoLockColorDriveTask_vf011)(CMoLockColorDriveTask *self);
  int (__thiscall *vf1_CMoLockColorDriveTask_vf012)(CMoLockColorDriveTask *self, int arg2);
  int (__thiscall *vf2_game_1003C720)(uint32_t *self);
  int (__thiscall *vf3_game_1003C730)(uint32_t *self);
  bool (__thiscall *vf4_game_1005F500)(char *self);
  bool (__thiscall *vf5_game_1005F520)(char *self);
  char *(__thiscall *vf6_game_1005F4F0)(char *self);
};

/* 536 */
struct Vt_1032BA18
{
  struct Vt_1032BA18_vtbl *vftable;
};

/* 537 */
struct /*VFT*/ Vt_1032BA60_vtbl
{
  int (__thiscall *vf0_CMoLockLookAtDriveTask_vf011)(CMoLockLookAtDriveTask *self);
  int (__thiscall *vf1_CMoLockLookAtDriveTask_vf012)(CMoLockLookAtDriveTask *self, int arg2);
  int (__thiscall *vf2_game_1003C720)(uint32_t *self);
  int (__thiscall *vf3_game_1003C730)(uint32_t *self);
  bool (__thiscall *vf4_game_1005F7E0)(char *self);
  bool (__thiscall *vf5_game_1005F800)(char *self);
  char *(__thiscall *vf6_game_1005F7D0)(char *self);
};

/* 538 */
struct Vt_1032BA60
{
  struct Vt_1032BA60_vtbl *vftable;
};

/* 539 */
struct /*VFT*/ Vt_1032BAA8_vtbl
{
  int (__thiscall *vf0_CMoActorColorDriveTask_vf011)(CMoActorColorDriveTask *self);
  tagRECT *(__thiscall *vf1_CMoActorColorDriveTask_vf012)(uint32_t *self, char);
  int (__thiscall *vf2_game_1003C720)(uint32_t *self);
  int (__thiscall *vf3_game_1003C730)(uint32_t *self);
  bool (__thiscall *vf4_game_1005FAF0)(char *self);
  bool (__thiscall *vf5_game_1005FB10)(char *self);
  char *(__thiscall *vf6_game_1005FAE0)(char *self);
};

/* 540 */
struct Vt_1032BAA8
{
  struct Vt_1032BAA8_vtbl *vftable;
};

/* 541 */
struct Vt_1032C5B4_vtbl
{
  int (__thiscall *vf0_CMoRmpRes_vf011)(CMoRmpRes *self);
  int (__thiscall *vf1_CMoRmpRes_vf012)(CMoRmpRes *self, int arg2);
  int (__thiscall *vf2_game_1003C720)(uint32_t *self);
  int (__thiscall *vf3_game_1003C730)(uint32_t *self);
  void *vf4_CMoAttachments_vf004;
  void *vf5_CMoAttachments_vf005;
  void *vf6_CMoAttachments_vf006;
};

/* 542 */
struct Vt_1032C5B4
{
  struct Vt_1032C5B4_vtbl *vftable;
};

/* 179 */
typedef struct _RTL_CRITICAL_SECTION *PRTL_CRITICAL_SECTION;

/* 178 */
typedef PRTL_CRITICAL_SECTION LPCRITICAL_SECTION;

/* 543 */
struct Vt_1033BE90_vtbl
{
  int (__stdcall *vf0_game_10260B30)(int arg1, int arg2, int arg3);
  unsigned int (__stdcall *vf1_game_10265A80)(int);
  int (__stdcall *vf2_game_10265AA0)(volatile LONG *);
  uint32_t *(__thiscall *vf3_game_1021DF70)(uint32_t *self, char);
  int (__thiscall *vf4_game_10261710)(unsigned int *self, unsigned int *);
  int (__thiscall *vf5_game_10261AA0)(uint32_t *self);
  void *vf6_game_1025EAB0;
  int (__thiscall *vf7_game_1025EAC0)(int self, int);
  void *vf8_game_1021DF10;
  int (__fastcall *vf9_game_1025E460)(int, int, int, int);
  int (__thiscall *vf10_game_1025E5E0)(HANDLE *self, int);
  int (__thiscall *vf11_game_1025E610)(HANDLE *self);
  int (__thiscall *vf12_game_1025E750)(HANDLE *self, int);
  void *vf13_nullsub_469;
  DWORD (__thiscall *vf14_game_10260100)(uint32_t *self, int);
  void (__thiscall *vf15_game_10260130)(int *self, int);
  int (__thiscall *vf16_game_1025FF00)(void *self);
  int (__thiscall *vf17_FontGlyphCache_StoreElapsed158_as_v0)(uint32_t *self);
  void *vf18_nullsub_527;
  void *vf19_nullsub_528;
  void *vf20_nullsub_470;
  int (__thiscall *vf21_game_102607F0)(uint32_t *self, BOOL);
  int (__thiscall *vf22_game_1025EDE0)(uint32_t *self, int, uint64_t *, uint64_t *);
  int (__thiscall *vf23_game_10260390)(int self, int, uint32_t *, uint64_t *);
  int (__thiscall *vf24_game_1025F3D0)(DWORD_PTR dwUser);
  int (__thiscall *vf25_game_1025F530)(int self);
  int (__thiscall *vf26_game_1025EC40)(void *self);
  BOOL (__thiscall *vf27_game_1025EE60)(int self);
  int (__thiscall *vf28_FitFont_ReleaseField6C_as_v0)(int self);
  void *vf29_game_1025ED20;
  int (__thiscall *vf30_game_1025ED30)(int *self);
  int (__thiscall *vf31_game_1025F590)(char *self);
  int (__thiscall *vf32_FitFont_EndTimerPeriodIfActive_as_v0)(char *self);
  int (__thiscall *vf33_game_1025EC80)(uint32_t *self);
  int (__thiscall *vf34_game_1025ECC0)(int *self);
  int (__thiscall *vf35_game_1025ED60)(uint32_t *self);
  int (__thiscall *vf36_Movie_CreateFrameTextures)(int self, int);
  int (__thiscall *vf37_game_1025ECE0)(uint32_t *self, int);
  int (__thiscall *vf38_game_1025F000)(char *self, int *);
  int (__thiscall *vf39_game_1025F190)(char *self, LPCRITICAL_SECTION);
  BOOL (__thiscall *vf40_game_1025EF70)(int self);
  int (__thiscall *vf41_game_1025EFA0)(int self);
  int (__thiscall *vf42_game_1025EF20)(uint32_t *self, int);
  int (__thiscall *vf43_game_1021E120)(uint32_t *self, uint8_t *);
  int (__stdcall *vf44_game_1021E000)(int);
  unsigned int (__thiscall *vf45_game_1025FF70)(int self, int, int);
  void (__thiscall *vf46_game_102600C0)(int *self, int);
  int (__thiscall *vf47_FitFont_ResetState_as_v0)(uint32_t *self);
  int (__thiscall *vf48_game_102601E0)(int *self, long long, long long);
};

/* 544 */
struct Vt_1033BE90
{
  struct Vt_1033BE90_vtbl *vftable;
  unsigned char gap_4[8];
  unsigned int field_C;
  unsigned int field_10;
  unsigned char gap_14[204];
  unsigned int field_E0;
  unsigned int field_E4;
  unsigned char gap_E8[120];
  unsigned int field_160;
  unsigned int field_164;
  unsigned int field_168;
  unsigned int field_16C;
  unsigned int field_170;
};

/* 545 */
struct Vt_1033C8F0_vtbl
{
  int (__thiscall *vf0_game_102391A0)(void *self, int arg2);
  int (__thiscall *vf1_LobbyUi_ResetAndPlaceWindow_as_v0)(int *self);
  void *vf2_YkZip_vf008;
  void *vf3_YkZip_vf009;
  char *(__thiscall *vf4_Ui_DrawKeyPrompt)(char **self);
  void *vf5_YkZip_vf011;
  void *vf6_nullsub_321;
  void *vf7_YkZip_vf013;
  void *vf8_YkZip_vf014;
  void *vf9_YkZip_vf015;
  char (__fastcall *vf10_LobbyUi_StepScreenSwitch_as_v0)(int, int, int);
  void *vf11_YkZip_vf017;
  void *vf12_YkZip_vf018;
  void *vf13_YkZip_vf019;
  void *vf14_YkZip_vf020;
  void *vf15_YkZip_vf021;
  void *vf16_YkZip_vf022;
};

/* 546 */
struct Vt_1033C8F0
{
  struct Vt_1033C8F0_vtbl *vftable;
  unsigned char gap_4[4];
  unsigned int field_8;
  unsigned char gap_C[12];
  unsigned int field_18;
  unsigned int field_1C;
  unsigned int field_20;
  unsigned int field_24;
  unsigned int field_28;
  unsigned int field_2C;
  unsigned int field_30;
  unsigned int field_34;
};

/* 586 */
struct CMoD3mSpecularElem_vtbl
{
  void *vf0_CMoD3mSpecularElem_GetRuntimeClass;
  int (__thiscall *vf1_game_10047520)(void *self, uint32_t *);
  unsigned int (__thiscall *vf2_game_1002C930)(uint32_t *self, char);
  int (__thiscall *vf3_game_1002C920)(uint32_t *self);
  void *vf4_CApp_vf004;
  void *vf5_CApp_vf005;
  uint32_t *(__thiscall *vf6_CMoD3mSpecularElem_ScalarDeletingDtor)(CMoD3mSpecularElem *C, char);
  void *vf7_CMoTask_vf007;
  void *vf8_CMoElem_PrepareDraw;
  void *vf9_CMoTask_vf009;
  void (__stdcall *vf10_CMoTask_vf010)(int);
  void *vf11_YmElem_DrawWithOwnProjection_as_v0;
  BOOL (__stdcall *vf12_CMoD3mSpecularElem_vf012)(int);
  void (__stdcall *vf13_CMoElem_vf013)(int);
  void (__stdcall *vf14_CMoElem_vf014)(int);
  void *vf15_CMoElem_vf015;
  bool (__thiscall *vf16_CMoElem_IsSourceAt0FCTest)(uint32_t *self);
  double (__thiscall *vf17_game_10041A40)(int self);
  void *vf18_YmElem_DrawSpecular;
  char (__thiscall *vf19_CMoD3mSpecularElem_BindTintedTexture)(CMoD3mSpecularElem *self);
  int *(__thiscall *vf20_CMoD3mElem_SubmitVertices)(int **self);
  void *vf21_game_10045AE0;
  void *vf22_game_10045BB0;
};

/* 634 */
struct CMoCameraSetupTask_vtbl
{
  void *vf0_CMoTask_GetRuntimeClass_variant12;
  int (__stdcall *vf1_CMoCameraSetupTask_Slot1NopOnMessage6)(uint32_t *);
  unsigned int (__thiscall *vf2_game_1002C930)(uint32_t *self, char);
  int (__thiscall *vf3_game_1002C920)(uint32_t *self);
  void *vf4_CApp_vf004;
  void *vf5_CApp_vf005;
  uint32_t *(__thiscall *vf6_CMoCameraSetupTask_ScalarDeletingDtor)(CMoCameraSetupTask *C, char);
  void *vf7_CMoTask_vf007;
  char (__thiscall *vf8_CMoCameraSetupTask_Slot8SetupCameraAfterOneTick)(CMoCameraSetupTask *self);
  void *vf9_CMoTask_vf009;
  void (__stdcall *vf10_CMoTask_vf010)(int);
};

/* 644 */
struct CTsZoneMap_vtbl
{
  void *vf0_CTsZoneMap_GetRuntimeClass;
  int (__thiscall *vf1_game_10178D40)(CTsZoneMap *self, int *);
  unsigned int (__thiscall *vf2_game_1002C930)(uint32_t *self, char);
  int (__thiscall *vf3_game_1002C920)(uint32_t *self);
  void *vf4_CApp_vf004;
  void *vf5_CApp_vf005;
  void *(__thiscall *vf6_CTsZoneMap_ScalarDeletingDtor)(CTsZoneMap *C, char);
  void *vf7_CMoTask_vf007;
  void *vf8_CTsZoneMap_Render;
  void *vf9_CMoTask_vf009;
  void (__stdcall *vf10_CMoTask_vf010)(int);
};

/* 654 */
struct CYyOs2VtxBuffer_vtbl
{
  void *vf0_CYyOs2VtxBuffer_GetRuntimeClass;
  void *vf1_CApp_vf001;
  unsigned int (__thiscall *vf2_game_1002C930)(uint32_t *self, char);
  int (__thiscall *vf3_game_1002C920)(uint32_t *self);
  void *vf4_CApp_vf004;
  void *vf5_CApp_vf005;
  void *(__thiscall *vf6_CYyOs2VtxBuffer_ScalarDeletingDtor)(CYyOs2VtxBuffer *C, char);
  void *vf7_CMoTask_vf007;
  char (__thiscall *vf8_game_1002C990)(CYyOs2VtxBuffer *self);
  void *vf9_CMoTask_vf009;
  void (__stdcall *vf10_CMoTask_vf010)(int);
};

/* 669 */
struct CMoSchOp82Task_vtbl
{
  void *vf0_CMoTask_GetRuntimeClass_variant12;
  void *vf1_CApp_vf001;
  unsigned int (__thiscall *vf2_game_1002C930)(uint32_t *self, char);
  int (__thiscall *vf3_game_1002C920)(uint32_t *self);
  void *vf4_CApp_vf004;
  void *vf5_CApp_vf005;
  int (__thiscall *vf6_game_10060590)(int C, char);
  void *vf7_CMoTask_vf007;
  char (__thiscall *vf8_CMoSchOp82Task_vf8)(void *self);
  void *vf9_CMoTask_vf009;
  void (__stdcall *vf10_CMoTask_vf010)(int);
};

/* 670 */
struct CMoSchOp0FTask_vtbl
{
  void *vf0_CMoTask_GetRuntimeClass_variant12;
  void *vf1_CApp_vf001;
  unsigned int (__thiscall *vf2_game_1002C930)(uint32_t *self, char);
  int (__thiscall *vf3_game_1002C920)(uint32_t *self);
  void *vf4_CApp_vf004;
  void *vf5_CApp_vf005;
  int *(__thiscall *vf6_game_10060750)(int *C, char);
  void *vf7_CMoTask_vf007;
  char (__thiscall *vf8_CMoSchOp0FTask_vf8)(short *self);
  void *vf9_CMoTask_vf009;
  void (__stdcall *vf10_CMoTask_vf010)(int);
};

/* 671 */
struct CMoSchOp0ETask_vtbl
{
  void *vf0_CMoTask_GetRuntimeClass_variant12;
  void *vf1_CApp_vf001;
  unsigned int (__thiscall *vf2_game_1002C930)(uint32_t *self, char);
  int (__thiscall *vf3_game_1002C920)(uint32_t *self);
  void *vf4_CApp_vf004;
  void *vf5_CApp_vf005;
  int (__thiscall *vf6_game_10060450)(int C, char);
  void *vf7_CMoTask_vf007;
  char (__thiscall *vf8_CMoSchOp0ETask_vf8)(float *self);
  void *vf9_CMoTask_vf009;
  void (__stdcall *vf10_CMoTask_vf010)(int);
};

/* 672 */
struct CMoSchOp10Task_vtbl
{
  void *vf0_CMoTask_GetRuntimeClass_variant12;
  void *vf1_CApp_vf001;
  unsigned int (__thiscall *vf2_game_1002C930)(uint32_t *self, char);
  int (__thiscall *vf3_game_1002C920)(uint32_t *self);
  void *vf4_CApp_vf004;
  void *vf5_CApp_vf005;
  uint32_t *(__thiscall *vf6_AfterimageTask_Destructor)(uint32_t *C, char);
  void *vf7_CMoTask_vf007;
  char (__thiscall *vf8_AfterimageTask_OnMove)(float *self);
  void *vf9_CMoTask_vf009;
  void (__stdcall *vf10_CMoTask_vf010)(int);
};

/* 673 */
struct CMoSchOp1DTask_vtbl
{
  void *vf0_CMoTask_GetRuntimeClass_variant12;
  void *vf1_CApp_vf001;
  unsigned int (__thiscall *vf2_game_1002C930)(uint32_t *self, char);
  int (__thiscall *vf3_game_1002C920)(uint32_t *self);
  void *vf4_CApp_vf004;
  void *vf5_CApp_vf005;
  uint32_t *(__thiscall *vf6_CMoSchOp1DAttachments_ScalarDeletingDtor)(uint32_t *C, char);
  void *vf7_CMoTask_vf007;
  char (__thiscall *vf8_CMoSchOp1DTask_vf8)(void *self);
  void *vf9_CMoTask_vf009;
  void (__stdcall *vf10_CMoTask_vf010)(int);
};


