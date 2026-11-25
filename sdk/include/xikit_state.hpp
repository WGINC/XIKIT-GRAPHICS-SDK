// xikit_state.hpp -- what a mod may read of the game's state, and watchers that report when it changes. Header only;
// include it after xikit_sdk.hpp. Call everything on the render thread.
//
// Every read is from the game's code (build 6A995428, the reconstruction's source under the SDK's tree_src), and
// names the function and line it rests on. Addresses go through XI_GAME / xikit::game, so build translation applies.
// What a mod might want and the code read so far does not show is listed at the end, not guessed.
#pragma once
#include <string.h>
#include "xikit_sdk.hpp"
#include "xikit_ui.hpp"

namespace xistate {

// The target manager: g_pTargetMng ([0x1057876C]). The game calls Target_Update on it each frame from Frame_Render
// (FrameRender.cpp, `if (g_pTargetMng != nullptr) Target_Update(g_pTargetMng)`). NULL before the game has made it.
inline void *target_manager() { return *xikit::game<void *>(0x1057876Cu); }

// The current target's actor, or NULL: Target_GetCachedIfValid (0x101598A0) on the target manager, as the target
// menu reads it (TargetMenu.cpp: `iVar5 = Target_GetCachedIfValid(g_pTargetMng); if (iVar5 == 0) ... return`). The
// same function's result is compared with the actor ActorHandle_Resolve gives for g_targetActorHandle (TargetMenu.cpp,
// `uVar5 = ActorHandle_Resolve(&g_targetActorHandle); iVar3 = Target_GetCachedIfValid(self_); ... if (uVar5 == iVar3)`),
// so it is an actor pointer.
inline void *target_actor() {
  void *tm = target_manager();
  if (!tm) return nullptr;
  typedef uintptr_t (__thiscall *Fn)(void *);
  return reinterpret_cast<void *>(reinterpret_cast<Fn>(XI_GAME(0x101598A0u))(tm));
}

// An actor's name, as the game draws it: CXiActor::GetName (0x10082F60, CXiActor.cpp) copies it into one buffer of the
// game's ([0x1047D4F8]) and returns that buffer. The next call overwrites it, so copy the name out at once. Writes
// an empty string for a NULL actor.
inline void actor_name(void *actor, char *out, size_t n) {
  if (!n) return;
  out[0] = 0;
  if (!actor) return;
  typedef const char *(__thiscall *Fn)(void *);
  const char *s = reinterpret_cast<Fn>(XI_GAME(0x10082F60u))(actor);
  if (!s) return;
  size_t k = strlen(s); if (k > n - 1) k = n - 1;
  memcpy(out, s, k); out[k] = 0;
}

// ---- watchers: call poll() once a frame (xikit_mod_frame); it returns true on the frame the value changed.
// The first poll() reports the value as a change, so a mod's starting state follows the game's.
template <class T> struct Watch {
  T value{}; bool started = false;
  bool update(const T &now) {
    if (started && now == value) return false;
    value = now; started = true; return true;
  }
};
// The target changed (another actor, or none). value is the target's actor pointer.
struct TargetWatch : Watch<void *> { bool poll() { return update(target_actor()); } };
// The player hid or showed the interface (xiui::interface_hidden). value is true while hidden.
struct InterfaceWatch : Watch<bool> { bool poll() { return update(xiui::interface_hidden()); } };

}  // namespace xistate

// Not shown by the code read so far, so not offered (each would need its own reading of the game's code first):
// - the player's own actor (no global of it is named in the tree's globals);
// - the zone the player is in (no zone number is read in the reconstructed source; ZoneMapLoad_* load its map);
// - an actor's position: the actor's vtable has accessors the kit's tests fake at +0x1BC and +0x1C0 (host.c), but
//   what they return has not been read from their code;
// - the party, the inventory, recasts, the job: none read.
