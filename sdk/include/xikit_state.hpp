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
// menu reads it (TargetMenu.cpp: it calls Target_GetCachedIfValid(g_pTargetMng) and returns when the result is 0). The
// same function's result is compared with the actor ActorHandle_Resolve gives for g_targetActorHandle (TargetMenu.cpp:
// ActorHandle_Resolve(&g_targetActorHandle) and Target_GetCachedIfValid(self_) are compared for equality), so it is an
// actor pointer.
inline void *target_actor() {
  void *tm = target_manager();
  if (!tm) return nullptr;
  typedef uintptr_t (__thiscall *Fn)(void *);
  return reinterpret_cast<void *>(reinterpret_cast<Fn>(XI_GAME(0x101598A0u))(tm));
}

// An actor's name as the game draws it (27 Nov, Prishe PER_CHARACTER_LOOKS.md A1): the actor's vtable +0xCC, which for
// a CXiSkeletonActor is GetEnglishName (0x10082F20, CXiSkeletonActor.cpp): a short prefix, then the record's name
// (Entity_BuildDisplayName). It writes one buffer of the game's (g_actorNameBuffer), so copy the name out at once.
// (Until 27 Nov this called 0x10082F60, vtable +0xD0: the nameplate's second string, a marker of at most two
// characters, usually empty. That was the bug behind the empty name in the owner's S1.) GetEnglishName goes through
// Acter_TestFlagsAndUpdateParts; to read a name with no call into the game, use record_name below.
inline void actor_name(void *actor, char *out, size_t n) {
  if (!n) return;
  out[0] = 0;
  if (!actor) return;
  typedef const char *(__thiscall *Fn)(void *);
  Fn f = reinterpret_cast<Fn *>(*reinterpret_cast<void **>(actor))[0xCC / 4];
  const char *s = f ? f(actor) : nullptr;
  if (!s) return;
  size_t k = strlen(s); if (k > n - 1) k = n - 1;
  memcpy(out, s, k); out[k] = 0;
}

// ---- the character record (27 Nov; the analysis repository's docs/RECORD.md has every source)
// An actor's +0x70 is its record (CXiActor.cpp: every accessor reads it, NULL-checked); the record's +0xA0 is its actor.
// The game keeps 0x900 record pointers in ActerBuffPtr (0x10480AF0; ActerBuff_FindByField78 0x10086FE0 loops over
// exactly 0x900), each NULL or a record.
const int kRecords = 0x900;
inline void *record(int i) { return (i >= 0 && i < kRecords) ? xikit::game<void *>(0x10480AF0u)[i] : nullptr; }
inline void *actor_record(void *actor) { return actor ? *reinterpret_cast<void **>(static_cast<char *>(actor) + 0x70) : nullptr; }
inline void *record_actor(void *rec) { return rec ? *reinterpret_cast<void **>(static_cast<char *>(rec) + 0xA0) : nullptr; }
// The record the game treats as the player's: Acter_GetActerAt10485F7A (0x101CC4F0) returns ActerBuffPtr[index at
// 0x10485F7A], or none when the index is 0; Acter_SnapHeightToZoneMap gives that record its own ground query, and the
// menus ask for it with no argument (TargetMenu.cpp, MenuPanels.cpp). That this is you is what those uses show; the
// tester's state probe checks its name against the player's.
inline void *self_record() {
  int16_t i = *xikit::game<int16_t>(0x10485F7Au);
  return i ? record(i) : nullptr;
}
// The record's kind byte (+0xEE; LoadSkeletonSync switches on it; kinds 0, 1, 2, 6, 7, 8 have their position copied
// to the actor). What each value means is not read in the game's code. Seen in the owner's run (26 Nov, probe.log,
// 258 named records): 0 characters with a race and nine gear words (players, and some named NPCs, these with race 0 and
// no words); 1 NPCs drawn with a race and gear words; 2 characters of one model (race 0, the model in the face word:
// chocobos, Carbuncle, goblins); 3 doors and street lamps (no words); 5 one record named "NPC". Ashita's lead (0 a
// player, 1 an NPC) agrees for 1, not wholly for 0.
inline int record_kind(void *rec) { return rec ? *(static_cast<uint8_t *>(rec) + 0xEE) : -1; }
inline int record_race(void *rec) { return rec ? *(static_cast<uint8_t *>(rec) + 0xEF) : -1; }       // GetModelByteEF
// The model word of a slot 0..8 (+0xFC + 2 * slot: CXiActor::GetModelPartWord; LoadSkeletonSync reads all nine)
inline uint16_t record_word(void *rec, int slot) { return (rec && slot >= 0 && slot < 9) ? *reinterpret_cast<uint16_t *>(static_cast<char *>(rec) + 0xFC + 2 * slot) : 0; }
inline uint32_t record_id(void *rec) { return rec ? *reinterpret_cast<uint32_t *>(static_cast<char *>(rec) + 0x78) : 0; }   // +0x78 (ActerBuff_FindByField78)
// The name, with no call into the game: Entity_BuildDisplayName's choice, +0x214 when the word at +0x210 is set,
// else +0x7C. The +0x7C name is at most 24 bytes (Acter_CopySixDwordsTo7C writes 24, then a 0 at +0x94); the
// game copies at most 0x80 from either (its _strncat). Bytes as the game keeps them (Shift-JIS for Japanese names).
inline void record_name(void *rec, char *out, size_t n) {
  if (!n) return;
  out[0] = 0;
  if (!rec) return;
  const char *r = static_cast<const char *>(rec);
  bool alt = *reinterpret_cast<const int16_t *>(r + 0x210) != 0;
  const char *s = alt ? r + 0x214 : r + 0x7C; size_t cap = alt ? 0x80 : 24, k = 0;
  while (k < cap && k < n - 1 && s[k]) { out[k] = s[k]; k++; }
  out[k] = 0;
}
// The position: x, height, z at +0x04, +0x08, +0x0C (floats). Acter_CopyPosAndAnglesToActorA0 copies these 16 bytes
// to the actor's +0x34 (Vec4_Copy 0x10026E90, destination first); Acter_SnapHeightToZoneMap writes the ground's
// height into +0x08.
struct Vec3 { float x, y, z; };
inline Vec3 record_position(void *rec) { Vec3 v = { 0, 0, 0 }; if (rec) memcpy(&v, static_cast<char *>(rec) + 4, 12); return v; }
// The three angles at +0x14, +0x18, +0x1C (the same function copies them to the actor's +0x44 and wraps each into
// -pi..pi). The heading is the second, +0x18 (record_angles().y): in the owner's run (26 Nov, 589 reports of the
// player's record over an hour of standing, walking and zoning) it took 54 values in -pi..pi while the other two
// stayed 0.000. The position's middle value is the height (Acter_SnapHeightToZoneMap's +0x08, above).
inline Vec3 record_angles(void *rec) { Vec3 v = { 0, 0, 0 }; if (rec) memcpy(&v, static_cast<char *>(rec) + 0x14, 12); return v; }

// ---- the zone (27 Nov): the zone change 0x1018B3A0 keeps its argument, the zone number, at [g_pXiZone] + 0x1B4 (its
// store at 0x1018B4C2). g_pXiZone (0x1065CB04) is NULL between zones (released on events 2 and 5: CAMERA.md 3a): -1.
// Until that store, +0x1B4 holds whatever the memory held: XiZone::GetInstance (0x1018B130) allocates the object and
// its constructor (0x1018B170) does not write +0x1B4. The owner's run saw 16777472, 16777728 and 767279312 for about 3 s
// after the object appeared, then the zone. Sometimes the store is in the same frame as the object's making (the
// function calling 0x100B5C30 then 0x1018B3A0 at 0x100B5AF2), so a reader alone cannot tell such a value from a zone;
// the functions run only after the store (0x1001E2B0, 0x1017A3D0) are not in the kit's manifest, so no hook marks it.
inline void *zone_object() { return *xikit::game<void *>(0x1065CB04u); }
inline int zone() { void *z = zone_object(); return z ? *reinterpret_cast<int *>(static_cast<char *>(z) + 0x1B4) : -1; }

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

// The zone changed (the zone number, or -1 between zones).
struct ZoneWatch : Watch<int> { bool poll() { return update(zone()); } };

// Characters appearing, leaving and changing gear (27 Nov): the record array read once a frame. events() after poll()
// lists what changed since the last poll: a slot whose record appeared or left, or whose nine model words changed.
// The first poll() reports every record present as appearing. Cost: 0x900 pointer reads and 9 words per record.
struct RecordWatch {
  enum Kind { appeared, left, gear };
  struct Event { Kind kind; int index; void *rec; uint16_t before[9], after[9]; };
  void *recs[kRecords] = {}; uint16_t words[kRecords][9] = {}; bool started = false;
  Event list[64]; int count = 0, dropped = 0;           // at most 64 events a frame; the rest counted in dropped
  void add(const Event &e) { if (count < 64) list[count++] = e; else dropped++; }
  bool poll() {
    count = dropped = 0;
    for (int i = 0; i < kRecords; i++) {
      void *r = record(i); uint16_t w[9];
      for (int s = 0; s < 9; s++) w[s] = record_word(r, s);
      if (r != recs[i]) {
        if (recs[i]) { Event e = { left, i, recs[i], {}, {} }; memcpy(e.before, words[i], sizeof e.before); add(e); }
        if (r) { Event e = { appeared, i, r, {}, {} }; memcpy(e.after, w, sizeof e.after); add(e); }
      } else if (r && memcmp(w, words[i], sizeof w)) {
        Event e = { gear, i, r, {}, {} }; memcpy(e.before, words[i], sizeof e.before); memcpy(e.after, w, sizeof e.after); add(e);
      }
      recs[i] = r; memcpy(words[i], w, sizeof w);
    }
    started = true;
    return count + dropped > 0;
  }
};
}  // namespace xistate

// Not shown by the code read so far, so not offered (each would need its own reading of the game's code first):
// - (27 Nov: the player's record, the zone and positions are read now: self_record, zone, record_position)
// - which of record_angles is the heading (the probe's question);
// - chat lines (a hook on ChatLog_AddMessage, in the manifests; not offered yet);
// - the party, the inventory, recasts, the job: none read (Ashita's patterns are leads: CLIENT_LIBRARY.md section 7).
