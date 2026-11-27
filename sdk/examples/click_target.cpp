// click_target.cpp -- clicking on characters in the world: the game's own test made more forgiving, and a click on a
// nameplate picks its character. With ct_show=1 it also draws what a click is tested against (it replaces pick_view).
// Build:  sdk/build_mod.sh click_target.dll sdk/examples/click_target.cpp
//
// What the game's code shows (docs/HOTBAR_CURSOR.md; build 6A995428, the same functions unchanged in 6AE818B4):
// - CXiActor::FindNearestToPoint (0x10083750; cdecl: point, two filter words) is the pick. The point is the cursor,
//   -1..1 over the interface (TargetMenu_SetNormalizedPos: x right, y DOWN). For each actor that passes the filter
//   (CXiActor_ComputeDrawState) it asks vtable +0x3D0 for a screen box (skeleton actors: CXiSkeletonActor::
//   Slot244_Unknown 0x100CFC10, the skeleton file's box turned by heading, moved, projected, y negated); for a box that
//   holds the point (and min.w > 0) a second, finer test (+0x3D4, 0x100CFF40) decides.
// - The owner's session (21 Nov, pick_view's log): over and over 1 or 2 boxes held the point and the game picked
//   nothing: the second test refused them. The owner: the finer test is too strict, and the nameplate should count.
// - Names: CXiSkeletonActor::OnDrawName calls CXiSkeletonActor::DrawNameIfVisible (0x100D0880, this = the actor),
//   which calls Actor_DrawWorldText (0x10086210); that draws each glyph with CDx::DrawPrimitiveUP (0x1000CD00,
//   triangle strip, 28-byte pre-transformed vertices, FVF 0x144) at the name's screen position, which Gfx_NdcToScreen
//   made from NDC with the current render target's size (CDx::GetRenderTargetTop +8 width, +12 height):
//   x = w/2 (ndc_x + 1), y = h/2 (1 - ndc_y). So the glyphs' vertices, recorded while DrawNameIfVisible runs, are the
//   name as drawn, and inverting that gives the rectangle in the pick's units: (2x/w - 1, 2y/h - 1).
//
// - Nameplates have two lines: Actor_DrawWorldText (the name) and, from DrawName2IfVisible right after it in OnDrawName,
//   DrawNameplateSecondString (0x10086900), whose glyphs go through CDx::DrawPrimitiveUP too, from the call at
//   0x10086E27 (return address 0x10086E2C). Both lines are recorded as the actor's nameplate. Whether the mastery stars
//   the owner sees are that second line is not known from the code read (ct_show=1 shows the rectangle).
// - A click: Target_RunActiveCommand (0x101585F0). With a target, a mouse click (command 0x16) picks again
//   (0x101587F0 -> Target_PickNearestToPoint -> FindNearestToPoint); when the target did not change, which is also
//   the case when the pick found nothing, it calls Target_ApplyAction (0x10158DB0): the target's command menu. With no
//   target, a pick that finds nothing opens the main menu ("menu    playermo"). The game's own deselect is a case of
//   0x101587F0 (kinds 17 and 23): if Target_GetCachedIfValid, Target_ClearAll (0x10158FF0).
//
// What this mod does (its own rule, set by the owner's request, not the game's):
// 1. A click inside a nameplate drawn in the last frame, of an actor that passed the game's filter in this pick:
//    that actor (the nearest name centre if several), even if the game chose another.
// 2. Otherwise the game's choice, when it made one.
// 3. Otherwise, the actors whose own screen box (the game's numbers), grown by ct_grow percent about its centre, holds
//    the point: the one whose box centre is nearest the point. A box whose 3D corners cross the camera's near plane
//    is not used (box_crosses_near, below): its projection spans far past the actor.
// 4. ct_deselect=1: a click that picks nobody while a target is selected (and no command waits for a target:
//    target manager +0xC4 and +0xC8 both 0) deselects it, with the game's own deselect, instead of opening the target's
//    command menu. The next click on nothing finds no target, and the game opens its menu as before.
// Settings ([click_target] in xikit_mods.ini): ct_fix (1 on; 0 leaves the game's pick alone), ct_grow (percent,
// default 125), ct_names (1: nameplates count), ct_name_pad (pixels around a name, default 4), ct_show (1: draw the
// boxes as grown, the names' rectangles and the point), ct_log (1: a line when the result changes), ct_deselect.
// Tested offline (kit/xikit/test, mode ctmod): the hooks; the game's own Slot244_Unknown on a stand-in actor recorded;
// the decision on recorded boxes and names. Not run in the game.
#include "xikit_sdk.hpp"
#include "xikit_ui.hpp"
XIKIT_MOD_GLOBALS
XIKIT_MOD_INFO("click_target", "2", 4, "click a whole nameplate to target; a click on nothing deselects")

enum : unsigned { FVF_XYZRHW = 0x004, FVF_DIFFUSE = 0x040, TOP_SELECTARG1 = 2, TA_DIFFUSE = 0, BLEND_SRCALPHA = 5,
                  BLEND_INVSRCALPHA = 6, CULL_NONE = 1 };
struct SurfDesc8 { unsigned Format, Type, Usage, Pool, Size, MultiSampleType, Width, Height; };   // d3d8types.h

static const XikitHost *g_host;

struct Box { void *actor; float x0, y0, x1, y1, w0; int ok, near; };   // near: a corner outside 0 <= z <= w (box_crosses_near)
struct Name { void *actor; float x0, y0, x1, y1; };
struct Pick { float px, py; unsigned f1, f2; void *game, *won; int how, n; Box b[256]; };   // how: 0 game, 1 name, 2 box, 3 none
static Pick g_cur, g_shown;
static volatile long g_seq;
static int g_in_pick;
static int g_in_run, g_run_had, g_run_empty;           // inside Target_RunActiveCommand: a target was selected; a pick found nobody
static volatile long g_deselects;
static long g_drawn_seq = -1, g_age;
static Name g_names[2][256]; static int g_nnames[2], g_nw;          // [g_nw]: this frame's, being drawn; [g_nw ^ 1]: the last frame's

static float grow() { return g_host->setting_int("ct_grow", 125) / 100.0f; }
static int holds_grown(const Box &b, float x, float y, float k) {
  if (!b.ok || !(b.w0 > 0) || b.near) return 0;
  float cx = (b.x0 + b.x1) / 2, cy = (b.y0 + b.y1) / 2, hx = (b.x1 - b.x0) / 2 * k, hy = (b.y1 - b.y0) / 2 * k;
  return x >= cx - hx && x <= cx + hx && y >= cy - hy && y <= cy + hy;
}
static int holds(const Box &b, float x, float y) { return holds_grown(b, x, y, 1.0f); }

// the rule above, on a finished pick (the boxes of the actors that passed the game's filter)
static void *decide(Pick &k) {
  void *best = nullptr; float bd = 1e30f;
  if (g_host->setting_int("ct_names", 1)) {
    const Name *nm = g_names[g_nw ^ 1]; int nn = g_nnames[g_nw ^ 1];
    for (int i = 0; i < nn; i++) {
      const Name &n = nm[i];
      if (k.px < n.x0 || k.px > n.x1 || k.py < n.y0 || k.py > n.y1) continue;
      int passed = 0; for (int j = 0; j < k.n && !passed; j++) passed = k.b[j].actor == n.actor;
      if (!passed) continue;
      float dx = k.px - (n.x0 + n.x1) / 2, dy = k.py - (n.y0 + n.y1) / 2, d = dx * dx + dy * dy;
      if (d < bd) { bd = d; best = n.actor; }
    }
    if (best) { k.how = 1; return best; }
  }
  if (k.game) { k.how = 0; return k.game; }
  float g = grow();
  for (int j = 0; j < k.n; j++) {
    const Box &b = k.b[j]; if (!holds_grown(b, k.px, k.py, g)) continue;
    float dx = k.px - (b.x0 + b.x1) / 2, dy = k.py - (b.y0 + b.y1) / 2, d = dx * dx + dy * dy;
    if (d < bd) { bd = d; best = b.actor; }
  }
  k.how = best ? 2 : 3;
  return best;
}

// Why a box grows as its actor comes near (24 Nov, the owner): Slot244_Unknown (tree/src/CXiSkeletonActor.cpp) takes
// the actor's box (vtable +0x3C8: x in [2]..[3], y in [0]..[1], z in [4]..[5]), turns it by the heading (vtable +0x1C0,
// +4) and moves it (vtable +0x1BC) into a matrix it then multiplies by the pick's (its third argument), and runs each
// of the 8 corners through Mat4_TransformCoordInPlace_v2 (0x10028320; read in 6AE818B4: the row vector times the
// row-major matrix, 0x10028170, then x, y, z times 1/w, w left in [3]). The box is the min and max of the 8 divided
// corners. A corner at or behind the camera's plane (w <= 0), or nearer than the near plane (z < 0, Direct3D's clip
// range is 0 <= z <= w), divides by a small or negative w: the box then spans far past the actor, more the nearer it
// is. So this mod builds the same matrix with the game's own functions and transforms the same corners without the
// division; a box with a corner outside 0 <= z <= w is not used for rule 3 (nameplates and the game's own pick still
// are). (The game's check of corner 0's w, kept in [3], is the w0 > 0 test.)
typedef void *(__thiscall *VtGet)(void *);
typedef float *(__thiscall *VtBox)(void *, int);
typedef void (__thiscall *MatFn)(void *);
typedef void (__thiscall *MatFnF)(void *, float);
typedef void (__thiscall *MatFnP)(void *, void *);
static int box_crosses_near(void *self, int m) {
  if (!self || !m) return 0;
  void **vt = *reinterpret_cast<void ***>(self);
  alignas(16) uint8_t mat[80];
  reinterpret_cast<MatFn>(XI_GAME(0x10027990u))(mat);                         // MathVector_ReturnThis (its constructor)
  reinterpret_cast<MatFn>(XI_GAME(0x100279B0u))(mat);                         // Mat4_SetIdentity_v1
  uint8_t *hd = static_cast<uint8_t *>(reinterpret_cast<VtGet>(vt[0x1C0 / 4])(self));
  if (!hd) return 0;
  reinterpret_cast<MatFnF>(XI_GAME(0x10027BD0u))(mat, *reinterpret_cast<float *>(hd + 4));      // Mat4_PostRotateY_v1
  void *pos = reinterpret_cast<VtGet>(vt[0x1BC / 4])(self);
  if (!pos) return 0;
  reinterpret_cast<MatFnP>(XI_GAME(0x10027CF0u))(mat, pos);                  // Mat4_SetTranslation_v2
  reinterpret_cast<MatFnP>(XI_GAME(0x10027D10u))(mat, reinterpret_cast<void *>(static_cast<uintptr_t>(static_cast<uint32_t>(m))));  // Mat4_PostMultiply_v1
  const float *p = reinterpret_cast<VtBox>(vt[0x3C8 / 4])(self, 0);
  if (!p) return 0;
  float y0 = p[0], y1 = p[1], x0 = p[2], x1 = p[3], z0 = p[4], z1 = p[5];
  if (y0 - y1 == 0) { y0 -= 1; y1 += 1; }                                     // (the game widens a flat box the same way)
  if (x0 - y0 == 0) { x0 -= 1; x1 += 1; }
  const float *M = reinterpret_cast<const float *>(mat);
  for (int c = 0; c < 8; c++) {
    float x = c & 1 ? x1 : x0, y = c & 2 ? y1 : y0, z = c & 4 ? z1 : z0;
    float cz = x * M[2] + y * M[6] + z * M[10] + M[14], cw = x * M[3] + y * M[7] + z * M[11] + M[15];
    if (!(cw > 0) || cz < 0 || cz > cw) return 1;
  }
  return 0;
}
static xikit::fn<decltype(&CXiSkeletonActor::Slot244_Unknown)> prev_Box;
static bits32 __thiscall my_Box(void *self, float *mn, float *mx, int m) {
  bits32 r = prev_Box(self, mn, mx, m);
  if (g_in_pick && g_cur.n < 256) {
    Box &b = g_cur.b[g_cur.n++];
    b.actor = self; b.ok = (char)r != 0; b.near = 0;
    if (b.ok) { b.x0 = mn[0]; b.y0 = mn[1]; b.w0 = mn[3]; b.x1 = mx[0]; b.y1 = mx[1]; b.near = box_crosses_near(self, m); }
  }
  return r;
}

static xikit::fn<decltype(&CXiActor::FindNearestToPoint)> prev_Find;
static int *__cdecl my_Find(float *p, uint32_t f1, uint32_t f2) {
  g_cur.n = 0; g_cur.px = p ? p[0] : 0; g_cur.py = p ? p[1] : 0; g_cur.f1 = f1; g_cur.f2 = f2;
  g_in_pick = 1;
  int *game = prev_Find(p, f1, f2);
  g_in_pick = 0;
  g_cur.game = game;
  void *won = game;
  if (g_host->setting_int("ct_fix", 1)) won = decide(g_cur); else g_cur.how = game ? 0 : 3;
  g_cur.won = won;
  if (g_in_run && !won) g_run_empty = 1;
  g_shown = g_cur;
  InterlockedIncrement(&g_seq);
  return reinterpret_cast<int *>(won);
}

// names: the glyph quads Actor_DrawWorldText draws while DrawNameIfVisible runs for an actor
static void *g_name_actor; static float g_nx0, g_ny0, g_nx1, g_ny1; static int g_nany;
static xikit::fn<decltype(&CDx::DrawPrimitiveUP)> prev_DPUP;
static void *g_plate_actor; static int g_plate_index = -1;          // the last DrawNameIfVisible's actor and its record
static void plate_extend(float x0, float y0, float x1, float y1);
static int __thiscall my_DPUP(CDx *self, int type, int count, int verts, int stride) {
  if (!g_name_actor && g_plate_actor && verts && stride == 28 && type == 5 && count > 0 && count < 64 &&
      __builtin_return_address(0) == reinterpret_cast<void *>(XI_GAME(0x10086E2Cu))) {
    const float *v = reinterpret_cast<const float *>(static_cast<uintptr_t>(static_cast<uint32_t>(verts)));
    float a0 = v[0], b0 = v[1], a1 = v[0], b1 = v[1];
    for (int i = 1; i < count + 2; i++) { float x = v[i * 7], y = v[i * 7 + 1]; if (x < a0) a0 = x; if (x > a1) a1 = x; if (y < b0) b0 = y; if (y > b1) b1 = y; }
    plate_extend(a0, b0, a1, b1);
  }
  if (g_name_actor && verts && stride == 28 && type == 5 && count > 0 && count < 64) {
    const float *v = reinterpret_cast<const float *>(static_cast<uintptr_t>(static_cast<uint32_t>(verts)));
    for (int i = 0; i < count + 2; i++) {
      float x = v[i * 7], y = v[i * 7 + 1];
      if (!g_nany) { g_nx0 = g_nx1 = x; g_ny0 = g_ny1 = y; g_nany = 1; }
      else { if (x < g_nx0) g_nx0 = x; if (x > g_nx1) g_nx1 = x; if (y < g_ny0) g_ny0 = y; if (y > g_ny1) g_ny1 = y; }
    }
  }
  return prev_DPUP(self, type, count, verts, stride);
}
static xikit::fn<decltype(&CXiSkeletonActor::DrawNameIfVisible)> prev_Name;
static void __thiscall my_Name(void *self, bits32 *pos, char *text, float scale, uint32_t color, uint32_t c2) {
  if (!g_host->setting_int("ct_names", 1)) { prev_Name(self, pos, text, scale, color, c2); return; }
  g_name_actor = self; g_nany = 0; g_plate_actor = self; g_plate_index = -1;
  prev_Name(self, pos, text, scale, color, c2);
  g_name_actor = nullptr;
  if (!g_nany || g_nnames[g_nw] >= 256) return;
  float w, h;
  if (!xiui::render_target_size(&w, &h)) return;
  float pad = (float)g_host->setting_int("ct_name_pad", 4);
  g_plate_index = g_nnames[g_nw];
  Name &n = g_names[g_nw][g_nnames[g_nw]++];
  n.actor = self;
  n.x0 = 2 * (g_nx0 - pad) / w - 1; n.x1 = 2 * (g_nx1 + pad) / w - 1;
  n.y0 = 2 * (g_ny0 - pad) / h - 1; n.y1 = 2 * (g_ny1 + pad) / h - 1;
}

// a glyph of the nameplate's second line, in render-target pixels: the record of the same actor grows to hold it
static void plate_extend(float x0, float y0, float x1, float y1) {
  if (g_plate_index < 0 || g_plate_index >= g_nnames[g_nw] || g_names[g_nw][g_plate_index].actor != g_plate_actor) return;
  float w, h;
  if (!xiui::render_target_size(&w, &h)) return;
  float pad = (float)g_host->setting_int("ct_name_pad", 4);
  Name &n = g_names[g_nw][g_plate_index];
  float nx0 = 2 * (x0 - pad) / w - 1, nx1 = 2 * (x1 + pad) / w - 1, ny0 = 2 * (y0 - pad) / h - 1, ny1 = 2 * (y1 + pad) / h - 1;
  n.x0 = nx0 < n.x0 ? nx0 : n.x0; n.x1 = nx1 > n.x1 ? nx1 : n.x1;
  n.y0 = ny0 < n.y0 ? ny0 : n.y0; n.y1 = ny1 > n.y1 ? ny1 : n.y1;
}

// clicks: Target_RunActiveCommand around the click's pick, and its call of Target_ApplyAction
typedef bits32 (__thiscall *TmFn)(void *);
static xikit::fn<decltype(&Target_RunActiveCommand)> prev_Run;
static bits32 __thiscall my_Run(void *self) {
  g_in_run = 1; g_run_empty = 0;
  g_run_had = self && (char)reinterpret_cast<TmFn>(XI_GAME(0x10158470u))(self) != 0;          // Target_HasActor
  bits32 r = prev_Run(self);
  g_in_run = 0;
  return r;
}
static int would_deselect(void *self) {
  if (!g_host->setting_int("ct_deselect", 1) || !g_in_run || !g_run_had || !g_run_empty || !self) return 0;
  const uint8_t *t = reinterpret_cast<const uint8_t *>(self);
  return *reinterpret_cast<const uint32_t *>(t + 0xC4) == 0 && *reinterpret_cast<const uint32_t *>(t + 0xC8) == 0;
}
static xikit::fn<decltype(&Target_ApplyAction)> prev_Apply;
static bits32 __thiscall my_Apply(void *self, bits32 a) {
  if (!would_deselect(self)) return prev_Apply(self, a);
  g_run_empty = 0;
  // the game's deselect (0x101587F0, kinds 17 and 23): if Target_GetCachedIfValid, Target_ClearAll
  if (reinterpret_cast<TmFn>(XI_GAME(0x101598A0u))(self)) reinterpret_cast<TmFn>(XI_GAME(0x10158FF0u))(self);
  g_deselects++;
  if (g_host->setting_int("ct_log", 0)) g_host->log("click_target: a click on nothing: the target deselected (not its menu)");
  return 0;
}

static void log_pick(const Pick &k) {
  static void *last_won = (void *)1; static int last_how = -1; static long last_frame = -1000, frame;
  frame++;
  if ((k.won == last_won && k.how == last_how) || frame - last_frame < 30) return;
  last_won = k.won; last_how = k.how; last_frame = frame;
  int in = 0; for (int i = 0; i < k.n; i++) in += holds(k.b[i], k.px, k.py);
  static const char *how[] = { "the game's pick", "a nameplate", "a grown box", "nothing" };
  int nr = 0; for (int i = 0; i < k.n; i++) nr += k.b[i].ok && k.b[i].near;
  g_host->log("click_target: point %.3f,%.3f: %d boxes (%d crossing the near plane, not used), %d hold the point; the game picked %p; result %p (%s)",
              k.px, k.py, k.n, nr, in, k.game, k.won, how[k.how & 3]);
}

struct Vtx { float x, y, z, rhw; unsigned color; };
static Vtx g_v[(256 * 2) * 8 + 16]; static int g_nv;
static void line(float x0, float y0, float x1, float y1, unsigned c) {
  if (g_nv + 2 > (int)(sizeof g_v / sizeof *g_v)) return;
  g_v[g_nv++] = { x0, y0, 0, 1, c }; g_v[g_nv++] = { x1, y1, 0, 1, c };
}
static void rect(float x0, float y0, float x1, float y1, unsigned c) {
  line(x0, y0, x1, y0, c); line(x1, y0, x1, y1, c); line(x1, y1, x0, y1, c); line(x0, y1, x0, y0, c);
}

extern "C" __declspec(dllexport) void xikit_mod_frame(void *device) {
  // the names drawn this frame become the last frame's
  g_nw ^= 1; g_nnames[g_nw] = 0;
  IDirect3DDevice8 *dev = static_cast<IDirect3DDevice8 *>(device);
  long seq = g_seq;
  if (seq != g_drawn_seq) { g_drawn_seq = seq; g_age = 0; if (g_host->setting_int("ct_log", 0)) log_pick(g_shown); }
  else g_age++;
  if (!g_host->setting_int("ct_show", 0) || seq == 0 || g_age > 30) return;
  IDirect3DSurface8 *bb = nullptr; SurfDesc8 d = {};
  if (dev->GetBackBuffer(0, D3DBACKBUFFER_TYPE_MONO, &bb) < 0 || !bb) return;
  bb->GetDesc(&d); bb->Release();
  float W = (float)d.Width, H = (float)d.Height;
  auto sx = [&](float x) { return (x + 1) * 0.5f * W; };
  auto sy = [&](float y) { return (y + 1) * 0.5f * H; };
  const Pick &k = g_shown; g_nv = 0; float g = grow();
  for (int i = 0; i < k.n; i++) {
    const Box &b = k.b[i]; if (!b.ok || b.w0 <= 0 || b.near) continue;      // (a box crossing the near plane is not drawn: not used)
    float cx = (b.x0 + b.x1) / 2, cy = (b.y0 + b.y1) / 2, hx = (b.x1 - b.x0) / 2 * g, hy = (b.y1 - b.y0) / 2 * g;
    unsigned c = b.actor == k.won ? 0xFF20FF20u : holds_grown(b, k.px, k.py, g) ? 0xFFFFE020u : 0xC0A0A0A0u;
    rect(sx(cx - hx), sy(cy - hy), sx(cx + hx), sy(cy + hy), c);
  }
  for (int i = 0; i < g_nnames[g_nw ^ 1]; i++) {
    const Name &n = g_names[g_nw ^ 1][i];
    rect(sx(n.x0), sy(n.y0), sx(n.x1), sy(n.y1), n.actor == k.won ? 0xFF20FF20u : 0xC060A0FFu);
  }
  float cx = sx(k.px), cy = sy(k.py);
  line(cx - 12, cy, cx - 3, cy, 0xFFFFFFFFu); line(cx + 3, cy, cx + 12, cy, 0xFFFFFFFFu);
  line(cx, cy - 12, cx, cy - 3, 0xFFFFFFFFu); line(cx, cy + 3, cx, cy + 12, 0xFFFFFFFFu);
  if (!g_nv) return;
  static const D3DRENDERSTATETYPE rs[] = { D3DRS_ZENABLE, D3DRS_ZWRITEENABLE, D3DRS_LIGHTING, D3DRS_FOGENABLE, D3DRS_CULLMODE,
                                           D3DRS_ALPHATESTENABLE, D3DRS_ALPHABLENDENABLE, D3DRS_SRCBLEND, D3DRS_DESTBLEND };
  static const D3DTEXTURESTAGESTATETYPE ts[] = { D3DTSS_COLOROP, D3DTSS_COLORARG1, D3DTSS_ALPHAOP, D3DTSS_ALPHAARG1 };
  unsigned rsv[sizeof rs / sizeof *rs], tsv[sizeof ts / sizeof *ts], vs = 0; IDirect3DBaseTexture8 *tex = nullptr;
  for (unsigned i = 0; i < sizeof rs / sizeof *rs; i++) dev->GetRenderState(rs[i], &rsv[i]);
  for (unsigned i = 0; i < sizeof ts / sizeof *ts; i++) dev->GetTextureStageState(0, ts[i], &tsv[i]);
  dev->GetVertexShader(&vs); dev->GetTexture(0, &tex);
  if (dev->BeginScene() >= 0) {
    const unsigned rsn[] = { 0, 0, 0, 0, CULL_NONE, 0, 1, BLEND_SRCALPHA, BLEND_INVSRCALPHA };
    for (unsigned i = 0; i < sizeof rs / sizeof *rs; i++) dev->SetRenderState(rs[i], rsn[i]);
    dev->SetTextureStageState(0, D3DTSS_COLOROP, TOP_SELECTARG1); dev->SetTextureStageState(0, D3DTSS_COLORARG1, TA_DIFFUSE);
    dev->SetTextureStageState(0, D3DTSS_ALPHAOP, TOP_SELECTARG1); dev->SetTextureStageState(0, D3DTSS_ALPHAARG1, TA_DIFFUSE);
    dev->SetTexture(0, nullptr); dev->SetVertexShader(FVF_XYZRHW | FVF_DIFFUSE);
    dev->DrawPrimitiveUP(D3DPT_LINELIST, g_nv / 2, g_v, sizeof(Vtx));
    dev->EndScene();
  }
  for (unsigned i = 0; i < sizeof rs / sizeof *rs; i++) dev->SetRenderState(rs[i], rsv[i]);
  for (unsigned i = 0; i < sizeof ts / sizeof *ts; i++) dev->SetTextureStageState(0, ts[i], tsv[i]);
  dev->SetVertexShader(vs); dev->SetTexture(0, tex);
  if (tex) tex->Release();
}

// for the offline test (kit/xikit/test, mode ctmod)
extern "C" __declspec(dllexport) void ct_test_inpick(int on) { if (on) g_cur.n = 0; else g_shown = g_cur; g_in_pick = on; }
extern "C" __declspec(dllexport) int ct_test_box(int i, float *out5) {
  if (i < 0 || i >= g_shown.n) return 0;
  const Box &b = g_shown.b[i]; out5[0] = b.x0; out5[1] = b.y0; out5[2] = b.x1; out5[3] = b.y1; out5[4] = b.w0; return b.ok ? 1 : -1;
}
extern "C" __declspec(dllexport) int ct_test_near(int i) { return i >= 0 && i < g_shown.n ? g_shown.b[i].near : -1; }
extern "C" __declspec(dllexport) int ct_test_last(float *px, float *py, int *n, void **game, void **won) {
  const Pick &k = g_shown; *px = k.px; *py = k.py; *n = k.n; *game = k.game; *won = k.won; return (int)g_seq;
}
extern "C" __declspec(dllexport) int ct_test_would_deselect(void *self, int in_run, int had, int empty) {
  int a = g_in_run, b = g_run_had, c = g_run_empty; g_in_run = in_run; g_run_had = had; g_run_empty = empty;
  int r = would_deselect(self); g_in_run = a; g_run_had = b; g_run_empty = c; return r;
}
// a pick made of the given boxes (x0 y0 x1 y1 per actor, w 1) and the game's choice; names as the last frame's
extern "C" __declspec(dllexport) void *ct_test_decide(float px, float py, int n, void **actors, const float *boxes, void *game,
                                                      int nn, void **nactors, const float *nrects, int *how) {
  static Pick k; k = Pick(); k.px = px; k.py = py; k.game = game; k.n = n;
  for (int i = 0; i < n; i++) { Box &b = k.b[i]; b.actor = actors[i]; b.x0 = boxes[i * 4]; b.y0 = boxes[i * 4 + 1]; b.x1 = boxes[i * 4 + 2]; b.y1 = boxes[i * 4 + 3]; b.w0 = 1; b.ok = 1; }
  int last = g_nw ^ 1; g_nnames[last] = nn;
  for (int i = 0; i < nn; i++) { Name &m = g_names[last][i]; m.actor = nactors[i]; m.x0 = nrects[i * 4]; m.y0 = nrects[i * 4 + 1]; m.x1 = nrects[i * 4 + 2]; m.y1 = nrects[i * 4 + 3]; }
  void *r = decide(k); *how = k.how; return r;
}

extern "C" __declspec(dllexport) int xikit_mod_init(const XikitHost *host) {
  g_host = host;
  host->declare_int("ct_fix", 1, 0, 1, "1: forgiving clicks (nameplates, then the game's pick, then the grown box); 0: the game's pick alone");
  host->declare_int("ct_grow", 125, 100, 300, "percent: how much larger than the game's own box a click may land, when the game picks nothing");
  host->declare_int("ct_names", 1, 0, 1, "1: a click on a nameplate picks its character");
  host->declare_int("ct_name_pad", 4, 0, 32, "pixels added around a nameplate");
  host->declare_int("ct_show", 0, 0, 1, "1: draw the boxes, the nameplates' rectangles and the click point (pick_view)");
  host->declare_int("ct_log", 0, 0, 1, "1: a line in xikit.log when the click's result changes");
  host->declare_int("ct_deselect", 1, 0, 1, "1: a click on nothing deselects the target (the next click opens the menu); 0: the game's (the target's menu)");
  int r = XI_HOOK(host, CXiSkeletonActor::Slot244_Unknown, my_Box, prev_Box);
  if (!r) r = XI_HOOK(host, CXiActor::FindNearestToPoint, my_Find, prev_Find);
  if (r) return r;
  if (XI_HOOK(host, CXiSkeletonActor::DrawNameIfVisible, my_Name, prev_Name) ||
      XI_HOOK(host, CDx::DrawPrimitiveUP, my_DPUP, prev_DPUP))
    host->log("click_target: the nameplate hooks were refused: nameplates do not count (the rest works)");
  if (XI_HOOK(host, Target_RunActiveCommand, my_Run, prev_Run) || XI_HOOK(host, Target_ApplyAction, my_Apply, prev_Apply))
    host->log("click_target: the click hooks were refused: a click on nothing does what the game does");
  return 0;
}
