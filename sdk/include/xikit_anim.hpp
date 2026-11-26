// xikit_anim.hpp -- (27 Nov, CLIENT_LIBRARY L21) an actor's motions: each one's frame, speed and weight, read and set;
// an actor frozen (its motions held) and let go. Header only; include it after xikit_sdk.hpp. Render thread only.
//
// From the game's code, as speedfix's limbs read it (kit/speedfix/sf_main.cpp, "Liminality, the limbs"; docs/RENDERER.md
// 3d): OnMove calls CYyModel_ForEachPart130 (0x1002C2A0) on the actor's model at +0x674; its parts are the list at
// model +0x44 (0x1002B5A0), linked at +4; each part's motion lists at +0x24 go to MotionQueList_ProcessAll (0x1001A3E0):
// 7 queues at +0x78, +0x64 ... +0x00, each a list at queue +4 linked at element +4. For an element whose vtable is
// CYyMotionQue's (0x1032A1C0), CYyMotionQue_ComputeFrameAdvance (0x1001A8E0) adds to the frame +0x24 each OnMove
// step * res[+0x36] * 0.5 * speed (+0x28), unless the loop count +0x2C is negative; the weight is +0x10. The drawing
// only samples the pose at that frame. So a motion with speed 0 holds its frame, and a frame written is the frame drawn.
//
// What this does not do: start a motion (L22), or stop the game from starting a new one on a frozen actor (a motion
// that starts while frozen is frozen at the next freeze_frame() call, which a mod makes once a frame).
#pragma once
#include <string.h>
#include "xikit_sdk.hpp"

namespace xianim {

struct Motion { void *el; float frame, speed, weight; int queue; };
// Whether an actor is a CXiSkeletonActor, the only kind with the model at +0x674 walked below. The game asks the same
// before it touches a record's actor's motions: Acter_ResetMotionCounters (0x10087E40) and Acter_AdvanceMotionTimer
// (0x10087E80) call CYyObject_IsKindOf (0x1002C8F0, thiscall) on the record's +0xA0 with CXiSkeletonActor_classdesc
// (0x10330EBC) first. (27 Nov: the owner's crash at prishe.dll+0x10F20 was this walk on a door's actor, which is not
// one: actor +0x6B8 held no part list.)
inline bool is_skeleton_actor(void *actor) {
  if (!actor) return false;
  typedef char (__thiscall *Fn)(void *, void *);
  return reinterpret_cast<Fn>(XI_GAME(0x1002C8F0u))(actor, XI_GAME(0x10330EBCu)) != 0;
}
// The motions of an actor (at most max): CYyMotionQue elements of every part's 7 queues. 0 for an actor that is not a
// CXiSkeletonActor.
inline int motions(void *actor, Motion *out, int max) {
  if (!is_skeleton_actor(actor)) return 0;
  uintptr_t vt = reinterpret_cast<uintptr_t>(xikit::game<void>(0x1032A1C0u));
  uint8_t *model = static_cast<uint8_t *>(actor) + 0x674;
  uint8_t *part = *reinterpret_cast<uint8_t **>(model + 0x44); int n = 0, parts = 0;
  while (part && parts++ < 32) {
    uint8_t *list = part + 0x24;
    for (int q = 0; q < 7; q++) {
      uint8_t *el = *reinterpret_cast<uint8_t **>(list + 0x78 - 0x14 * q + 4); int k = 0;
      while (el && k++ < 64) {
        if (*reinterpret_cast<uintptr_t *>(el) == vt && n < max) {
          Motion &m = out[n++]; m.el = el; m.queue = q;
          m.frame = *reinterpret_cast<float *>(el + 0x24); m.speed = *reinterpret_cast<float *>(el + 0x28); m.weight = *reinterpret_cast<float *>(el + 0x10);
        }
        el = *reinterpret_cast<uint8_t **>(el + 4);
      }
    }
    part = *reinterpret_cast<uint8_t **>(part + 4);
  }
  return n;
}
inline void set_frame(void *el, float f) { if (el) *reinterpret_cast<float *>(static_cast<uint8_t *>(el) + 0x24) = f; }
inline void set_speed(void *el, float s) { if (el) *reinterpret_cast<float *>(static_cast<uint8_t *>(el) + 0x28) = s; }

// Freezing: each motion's speed kept and set to 0; let go puts back the speed of each motion still there (one whose
// speed the game changed meanwhile is left as the game set it). Up to 16 actors, 64 motions each.
struct Freezer {
  struct Held { void *el; float speed; };
  struct Entry { void *actor; Held held[64]; int n; };
  Entry e[16] = {}; int count = 0;
  Entry *find(void *a) { for (int i = 0; i < count; i++) if (e[i].actor == a) return &e[i]; return nullptr; }
  bool frozen(void *a) { return find(a) != nullptr; }
  // freeze an actor, or (called again, once a frame) also hold motions that started since
  bool freeze(void *a) {
    if (!a) return false;
    Entry *x = find(a);
    if (!x) { if (count == 16) return false; x = &e[count++]; x->actor = a; x->n = 0; }
    Motion m[64]; int n = motions(a, m, 64);
    for (int i = 0; i < n; i++) {
      bool have = false; for (int k = 0; k < x->n; k++) have |= x->held[k].el == m[i].el;
      if (!have && x->n < 64) { x->held[x->n].el = m[i].el; x->held[x->n].speed = m[i].speed; x->n++; }
      set_speed(m[i].el, 0.0f);
    }
    return true;
  }
  void freeze_frame() { for (int i = 0; i < count; i++) freeze(e[i].actor); }
  void thaw(void *a) {
    Entry *x = find(a); if (!x) return;
    Motion m[64]; int n = motions(a, m, 64);
    for (int k = 0; k < x->n; k++) for (int i = 0; i < n; i++) if (m[i].el == x->held[k].el && m[i].speed == 0.0f) set_speed(m[i].el, x->held[k].speed);
    *x = e[--count];
  }
  void thaw_all() { while (count) thaw(e[count - 1].actor); }
  // step a frozen actor by df frames (each held motion's frame += df)
  void step(void *a, float df) { Motion m[64]; int n = motions(a, m, 64); for (int i = 0; i < n; i++) set_frame(m[i].el, m[i].frame + df); }
};

}  // namespace xianim
