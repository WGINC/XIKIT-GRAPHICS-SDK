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
// the functions run only after the store (0x1001E2B0, 0x1017A3D0) are not in the kit's manifest. zone_known() (below)
// marks it with two hooks on functions that are.
inline void *zone_object() { return *xikit::game<void *>(0x1065CB04u); }
inline int zone() { void *z = zone_object(); return z ? *reinterpret_cast<int *>(static_cast<char *>(z) + 0x1B4) : -1; }

// ---- the zone, known to be stored (27 Nov; RESEARCH.md A9, docs/RECORD.md 3). The zone change (0x1018B3A0) stores
// +0x1B4 and then calls Actor_ResetDrawLists (0x10081A50, in the kit's manifest) from 0x1018B4D3, so that call
// returns to 0x1018B4D8: a hook that sees that return address knows the number of the current zone object is stored.
// XiZone's constructor (0x1018B170) calls XiZone::SetPtr1D8FromTable (0x1018BAE0, in the manifest) from 0x1018B332
// (returning to 0x1018B337): a new zone object, whose +0x1B4 is not stored yet. Both call sites read in the
// disassembly of 6A995428 and 6AE818B4 (where they are 0x1018CAA3 and 0x1018C902; XI_GAME translates). The kit chains
// hooks with jumps only (xikit.c, "hook chains"), so a hook's own return address is the game caller's.
// install_zone_hooks(host) in xikit_mod_init; then zone_known() is the zone number, -1 between zones, or -2 while the
// zone object exists but its number is not stored yet (the 3 s of leftover values the 26 Nov run saw). Without the
// hooks installed, zone_known() is zone().
namespace zone_detail {
inline void *&marked() { static void *p = nullptr; return p; }
inline bool &hooked() { static bool h = false; return h; }
inline xikit::fn<decltype(&::Actor_ResetDrawLists)> &prev_reset() { static xikit::fn<decltype(&::Actor_ResetDrawLists)> p; return p; }
inline xikit::fn<decltype(&::XiZone::SetPtr1D8FromTable)> &prev_set() { static xikit::fn<decltype(&::XiZone::SetPtr1D8FromTable)> p; return p; }
struct Hooks {
  __attribute__((noinline)) static void __cdecl reset() {
    void *ret = __builtin_return_address(0);
    prev_reset()();
    if (ret == reinterpret_cast<void *>(XI_GAME(0x1018B4D8u))) marked() = zone_object();
  }
  __attribute__((noinline)) static void __thiscall set_ptr(void *self, uint32_t which) {
    void *ret = __builtin_return_address(0);
    if (ret == reinterpret_cast<void *>(XI_GAME(0x1018B337u))) marked() = nullptr;
    prev_set()(self, which);
  }
};
}
inline int install_zone_hooks(const XikitHost *host) {
  int a = XI_HOOK(host, Actor_ResetDrawLists, &zone_detail::Hooks::reset, zone_detail::prev_reset());
  int b = XI_HOOK(host, XiZone::SetPtr1D8FromTable, &zone_detail::Hooks::set_ptr, zone_detail::prev_set());
  zone_detail::hooked() = a == XIKIT_OK && b == XIKIT_OK;
  return a != XIKIT_OK ? a : b;
}
inline int zone_known() {
  if (!zone_detail::hooked()) return zone();
  void *z = zone_object();
  if (!z) return -1;
  return zone_detail::marked() == z ? zone() : -2;
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

// ---- equipment and recasts (28 Nov; the analysis repository's docs/HOTBAR_CURSOR.md item 2 has every source). The
// game fills these tables from its messages; a mod only reads them. Checked in both builds: the code of 6AE818B4 uses
// the same offsets at the addresses the build map gives (0x104868D4, 0x10668398).

// The game state block [0x104DFD98] (the menus and the message handlers read it; NULL before the game made it).
inline uint8_t *game_state() { return *xikit::game<uint8_t *>(0x104DFD98u); }

// What is in equipment slot s (0..15): the container and its index, as the equip message 0x050 stores them at game
// state +0x19A54 + 8 x s (+4 the index, +5 the container; the client's own reader sub_10132270 takes an index of 0 as
// nothing there). False when nothing is equipped there or the game state is not there yet. Which slot is which is not
// named in the code (GearSwap's slot list, a lead, has 0 as the main weapon).
inline bool equipped(int s, int *container, int *index) {
  uint8_t *g = game_state();
  if (!g || s < 0 || s >= 16) return false;
  uint8_t *e = g + 0x19A54 + 8 * s;
  if (!e[4]) return false;
  if (container) *container = e[5];
  if (index) *index = e[4];
  return true;
}

// An ability recast: the 1/60 s left for timer id t, from the menus' copy of the player's 31 recast entries (each 8
// bytes at 0x10666EC0, the timer id in byte 3; the counts at 0x10666FB8 + 4 x i, lowered every frame by Menu_DrawAll
// through 0x102250F0). -1 when no entry has that timer id. Seconds: the result / 60.
inline int ability_recast_ticks(int t) {
  const uint8_t *ent = xikit::game<uint8_t>(0x10666EC0u);
  const int32_t *cnt = xikit::game<int32_t>(0x10666FB8u);
  for (int i = 0; i < 31; i++) if (ent[8 * i + 3] == (uint8_t)t && t != 0xFF) return cnt[i];
  return -1;
}

// The same for an ability by its id (below 0xB00): its record in the abilities' table ([0x1066714C], 0x30 bytes each)
// gives its timer id in the word at +8 (MenuPanels_ComputeCount). -1 when the table is not loaded or no entry has it.
inline int ability_recast_ticks_by_id(int id) {
  const uint8_t *tab = *xikit::game<const uint8_t *>(0x1066714Cu);
  if (!tab || id < 0 || id >= 0xB00) return -1;
  return ability_recast_ticks(*reinterpret_cast<const uint16_t *>(tab + 0x30 * id + 8));
}

// The player's two jobs and levels (the analysis repository's HOTBAR_CURSOR.md item 2: player +0x08/+0x09 and
// +0x0A/+0x0B, read by MenuPanels_IsEntryAvailable). which 0: the first pair, 1: the second; level may be NULL.
// Which pair the game shows as the main job is Ashita's lead (the first), not read in the game's code.
inline int job(int which, int *level) {
  const uint8_t *p = xikit::game<uint8_t>(0x10485638u) + (which ? 0x0A : 0x08);
  if (level) *level = p[1];
  return p[0];
}
// A job number's short name as the game's own table gives it (6A995428 0x10332C70, 6AE818B4 0x10333C70: pairs of
// {number, name}, each number twice, the long name then the short; read by the job-name parser sub_10105B80). "" when
// the number is not in it.
inline const char *job_name(int n, bool short_name = true) {
  const uint32_t *t = xikit::game<uint32_t>(0x10332C70u);
  for (int i = 0; i < 64 && t[2 * i] && t[2 * i] < 64; i++)
    if ((int)t[2 * i] == n && i + 1 < 64 && (int)t[2 * i + 2] == n) return reinterpret_cast<const char *>(static_cast<uintptr_t>(t[2 * (i + (short_name ? 1 : 0)) + 1]));   // (a pointer in the game's memory: already relocated)
  return "";
}

// A spell recast: the 1/60 s left for spell id n (0..1023), the game's own countdown at 0x106671E0 + 2 x n
// (MenuPanels_TickCounters lowers it every frame; sub_1022B330 sets it when the cast's effect starts). 0 when ready.
inline int spell_recast_ticks(int n) {
  if (n < 0 || n >= 1024) return -1;
  return xikit::game<int16_t>(0x106671E0u)[n];
}

// (29 Nov) Whether spell n (0..1023) is learned: 1 yes, 0 no, -1 the list has not come (or no game state yet).
// From the game's code (build 6A995428; 6AE818B4 the same offsets, its handler 0x100F0200): the handler of message
// 0xAA (0x100F00C0, registered with 0x100FC3B0 as the 0x050 handler is) copies the message's 128 bytes from +4 to game
// state +0x2CF54 and sets the byte +0x2CFD4 to 1. NetCellFont_GetBlock2CF54IfFlag (0x100F00A0) gives +0x2CF54 only
// while that byte is set, and the magic menu tests spell i as bits[i >> 3] & (1 << (i & 7)), i being the spell's
// record number in the spell table [0x10667A74] (100 bytes a record; 0x1022B6E0; MenuPanels_UpdateIndexList over 0x400
// of them). The record number is the id the recast countdowns use (spell_recast_ticks). That it is the id in
// Windower's and Petit Trois's tables is the same lead as for the recasts.
inline int spell_learned(int n) {
  uint8_t *g = game_state();
  if (!g || n < 0 || n >= 1024 || !g[0x2CFD4]) return -1;
  return (g[0x2CF54 + (n >> 3)] >> (n & 7)) & 1;
}

// ---- (29 Nov) abilities and weapon skills: the game's own lists, records, recasts, charges and checks
// From the game's code (build 6A995428; 6AE818B4 the same, at +0x1610 in this part of the code):
// - The abilities' table [0x1066714C]: 0xB00 records of 0x30 bytes (MenuPanels_ComputeCount takes record numbers below
//   0xB00). A record's word +0 is the id a name lookup returns, byte +2 its type (the menus' lists keep the records of
//   one type), word +8 its timer id (the recast entries'), byte +0xF the level it needs (FUN 0x10224B70 compares it
//   with the main job's level, 0x10485641).
// - Which records are which: MenuPanels_FindEntryByCallback (0x10223240) looks names up in records 0..0x1FF (or
//   0x700..0xAFF with its flag), MenuPanels_FindRecordIdByText (0x10222E20) in 0x200..0x5FF; MenuPanels_HasBitIdPlus200
//   (0x10223360) tests the job ability `id` as the bit id + 0x200. So a job ability (or pet command) id j is record
//   j + 0x200 (the game's rule); a weapon skill is a record below 0x200 (that Petit Trois's weapon skill id w is
//   record w is a lead: record w's word +0 can be compared with w in the game, ability_record_id).
// - The learned list: messages 0xAC (0x100E6120: 0xE0 bytes to game state +0x2CDE8, +0x2CF49 set) and the id list
//   0x100E6080 writes (+0x2CEC8, 0x80 bytes, +0x2CF4A set) make 0x160 bytes of bits, one per record; their accessor
//   0x100E6020 gives them only while both bytes are set; MenuPanels_Refresh (0x10223C90) walks all 0xB00
//   (MenuPanels_UpdateIndexList) and MenuPanels_TestBit (0x10223390) tests record i as bits[i >> 3] & (1 << (i & 7)).
inline int ability_learned(int i) {           // record i: 1, 0, or -1 (the lists have not come)
  uint8_t *g = game_state();
  if (!g || i < 0 || i >= 0xB00 || !g[0x2CF49] || !g[0x2CF4A]) return -1;
  return (g[0x2CDE8 + (i >> 3)] >> (i & 7)) & 1;
}
inline int job_ability_record(int id) { return id + 0x200; }                 // the game's rule (HasBitIdPlus200)
inline const uint8_t *ability_record(int i) {
  const uint8_t *t = *xikit::game<const uint8_t *>(0x1066714Cu);
  return t && i >= 0 && i < 0xB00 ? t + i * 0x30 : nullptr;
}
inline int ability_record_id(int i) { const uint8_t *r = ability_record(i); return r ? *reinterpret_cast<const uint16_t *>(r) : -1; }
inline int ability_type(int i) { const uint8_t *r = ability_record(i); return r ? r[2] : -1; }
inline int ability_timer_id(int i) { const uint8_t *r = ability_record(i); return r ? *reinterpret_cast<const uint16_t *>(r + 8) : -1; }
// The recast the ability menu shows: MenuPanels_GetSlotInfo (0x10222C90, cdecl (record, int *), ret 0: data/purges.json;
// tree/src/MenuPanels.cpp) returns MenuPanels_ComputeCount's seconds ((count + 59) / 60) and puts -1 in *charges;
// for the records of types 9, 0x0F and 0x12 it gives the charges by the jobs and levels at 0x10485640..43 (type 9 with
// job 0x11: 2 charges or 0 below level 40, 120 s; 0x0F with job 0x14: (level - 10) / 20 + 1, 240 s; 0x12 with job 9: 3,
// or 0 below 25, 90 s) and returns the seconds to the next charge, *charges the charges there are (ComputeDelta).
// -1 when the table is not there yet.
inline int ability_recast(int i, int *charges) {
  if (charges) *charges = -1;
  if (!ability_record(i)) return -1;
  uint32_t c = 0xFFFFFFFFu;
  int s = reinterpret_cast<int (__cdecl *)(int, uint32_t *)>(XI_GAME(0x10222C90u))(i, &c);
  if (charges) *charges = (int)c;
  return s;
}
// Whether the ability menu would let it be used: FUN 0x10224B70 (cdecl (record, the list's type), ret 0: data/purges.json;
// two pushes and add esp, 8 at its call 0x10224AD4 in the menu's entry callback 0x10224A80). 0 usable; else the game's
// reason: 1 no table or no player entry, 2 the recast is not ready, 4 the entry's +0x28 (TP, a lead) below the
// record's +0xC, 5 its +0x24 below the cost FUN 0x10101E50 gives, 10 not engaged (YkCommon_IsActorField170(1) false, for
// the lists whose kind is 4), 0xD the main job's level below the record's +0xF, 6..9, 0xB, 0xC statuses and states the
// code tests (not named here). The type passed is the record's own +2, as the menu's lists of one type pass it.
inline int ability_state(int i) {
  const uint8_t *r = ability_record(i); if (!r) return -1;
  return reinterpret_cast<int (__cdecl *)(int, int)>(XI_GAME(0x10224B70u))(i, r[2]);
}
// Whether the magic menu would cast spell n: FUN 0x1022CF30 (cdecl (spell), ret 0; one push and add esp, 4 at its call
// 0x1022C7B0); the menu shows message DAT_103879C8[code] when it is not 0 (0x1022DDB0 in 6AE818B4). 0 castable; 2 the
// job and level check FUN 0x101021A0 failed (or no player), 3 the entry's +0x24 (MP, a lead) below the cost
// FUN 0x10101E50 gives from the record's +10, 4 the recast is not ready (0xC for spells 0x380..0x3FF), 5 a spell 0x200..0x2DF
// not among the 20 the code lists (FUN 0x100FCD10), 6 the timer 0x106679E0 running, 7..11 statuses and states. -1 no table.
inline int spell_state(int n) {
  if (n < 0 || n >= 0x400 || !*xikit::game<void *>(0x10667A74u)) return -1;
  return reinterpret_cast<int (__cdecl *)(int)>(XI_GAME(0x1022CF30u))(n);
}
// ---- (29 Nov) the inventory, as the game's own message handlers keep it (build 6A995428; 6AE818B4 the same offsets at
// the build map's addresses, read in its code). Registered with 0x100FC3B0: 0x01F (0x100EC550) and 0x020 (0x100EC630)
// write item slot (bag b, index i) at game state +0x9868 + (b x 0x51 + i) x 0x2C: word +0 the item id, byte +2 the
// index, dword +4 the count, byte +8 the status, dword +0xC (0x020) the bazaar price, +0x10 0x18 bytes of extra data;
// 0x01E (0x100EC4F0) sets the count and status and clears the slot when the count is 0. 0x01C (0x100EC4A0) copies 18
// bytes from the message to game state +0x19891 (Windower's packet types, a lead, call them the bags' sizes). Which bag
// number is which bag is not in the code read (Windower's leads: 0 inventory, 3 temporary items).
const int kBags = 18, kBagSlots = 0x51;
inline bool item(int bag, int index, int *id, int *count) {
  uint8_t *g = game_state();
  if (!g || bag < 0 || bag >= kBags || index < 0 || index >= kBagSlots) return false;
  const uint8_t *e = g + 0x9868 + (bag * kBagSlots + index) * 0x2C;
  int c = *reinterpret_cast<const int32_t *>(e + 4), i = *reinterpret_cast<const uint16_t *>(e);
  if (id) *id = i;
  if (count) *count = c;
  return i != 0 && c > 0;
}
inline int bag_size(int bag) { uint8_t *g = game_state(); return g && bag >= 0 && bag < kBags ? g[0x19891 + bag] : -1; }
// The item id in equipment slot s (equipped() and item()), 0 for none.
inline int equipped_item(int s) { int c, i, id = 0; return equipped(s, &c, &i) && item(c, i, &id, nullptr) ? id : 0; }

// ---- (29 Nov) the player's statuses
// MenuPanels_IsIdInTable10485A30 (0x1021E670, cdecl (id), ret 0: data/purges.json; tree/src/MenuPanels.cpp) looks the
// word id up in the 32 words at 0x10485A30 and returns 1 in its low byte when it is there. The ability and spell checks
// above test statuses with it (0x10224B70: 0x178, 0x2F, 0x19A, 0x19B). Which number is which status is not in the code
// read (Windower's and Petit Trois's numbers are leads: 164 chain affinity, 165 burst affinity, 470 immanence).
inline bool has_status(int id) {
  return (reinterpret_cast<uint32_t (__cdecl *)(uint32_t)>(XI_GAME(0x1021E670u))((uint32_t)id) & 0xFF) != 0;
}

// ---- (29 Nov) message 0x028 (an action) as the game parses it
// The handler (0x1009E400, registered with 0x100FC3A0) makes a CXiSchStatus and has 0x1018CA40 (thiscall, ret 4) read
// the message with the bit reader 0x1018C570 (LSB first: bit i of a field from the i-th bit read; 0x1018CDF0 points it at
// the message + 4 and 0x1018C550 steps a byte, so the first field starts at the message's byte 5) into a 0x5B5C-byte
// record, dwords:
//   [0] where the actor is in ActerBuffPtr (0x1018C760 of [1]: the slot whose record's +0x78 is the id; 0 for none),
//   [1] the actor's id (32 bits), [6] the targets (6 bits; 0x40 at most read),
//   [5] 4 bits, [2] the category (4 bits; the handler's switch: 1..0xF), [3] 32 bits whose low word is the param (the
//   handler compares [3] & 0xFFFF with 0x6163), [4] 32 bits;
//   target t at dword 7 + 0x5B * t: +0 its ActerBuffPtr slot (as [0]), +1 its id (32), +2 its actions (4 bits; 8 at most read);
//   action k of target t at dword 10 + 0x5B * t + 0xB * k: +0 3 bits, +1 a word of 2 bits and a word of 12, +2 two words
//   of 5 bits, +3 the param (17 bits), +4 the message (10 bits), +5 31 bits, then when a flag bit is set the added
//   effect (+6: words of 6 and 4 bits, +7 its param (17), +8 low word its message (10)) and when another is set the
//   spike (+8 high word 6 bits, +9 words of 4 and 14, +0xA low word its message (10)).
// The record is the argument of fn_1018D170 (0x1018D170, thiscall (status, record), ret 4: data/purges.json), which the
// parser calls for every action message before it looks the actor up; the hotbar hooks it (released from the security
// set for this use: sdk/security_set.py). The field names (category, param, message) are Windower's (a lead); the
// widths and places are the game's reader's.
namespace action {
inline uint32_t dw(const void *rec, int i) { return static_cast<const uint32_t *>(rec)[i]; }
inline uint32_t actor_id(const void *rec) { return dw(rec, 1); }
inline int category(const void *rec) { return (int)dw(rec, 2); }
inline uint32_t param(const void *rec) { return dw(rec, 3) & 0xFFFF; }
inline int targets(const void *rec) { uint32_t n = dw(rec, 6); return n > 0x40 ? 0x40 : (int)n; }
inline uint32_t target_id(const void *rec, int t) { return dw(rec, 7 + 0x5B * t + 1); }
inline int actions(const void *rec, int t) { uint32_t n = dw(rec, 7 + 0x5B * t + 2); return n > 8 ? 8 : (int)n; }
inline uint32_t action_param(const void *rec, int t, int k) { return dw(rec, 10 + 0x5B * t + 0xB * k + 3); }
inline int message(const void *rec, int t, int k) { return (int)dw(rec, 10 + 0x5B * t + 0xB * k + 4); }
inline int added_message(const void *rec, int t, int k) { return (int)(dw(rec, 10 + 0x5B * t + 0xB * k + 8) & 0xFFFF); }
}  // namespace action
}  // namespace xistate

// Not shown by the code read so far, so not offered (each would need its own reading of the game's code first):
// - (27 Nov: the player's record, the zone and positions are read now: self_record, zone, record_position)
// - which of record_angles is the heading (the probe's question);
// - chat lines (a hook on ChatLog_AddMessage, in the manifests; not offered yet);
// - the party, the inventory, recasts, the job: none read (Ashita's patterns are leads: CLIENT_LIBRARY.md section 7).
