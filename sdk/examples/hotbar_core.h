// hotbar_core.h -- shared between hotbar.cpp (the tree's headers) and hotbar_core.cpp (Windows' headers)
#pragma once
#define HB_BARS 10
#define HB_SLOTS 12
#define HB_LINES 8
#define HB_SETS 8
struct HbKey { int vk, ctrl, alt, shift; char name[16]; int dflt; };   // dflt: one of the default keys (hb_read)
// one slot's action, resolved to command lines
struct HbAct {
  int used;
  char label[48];
  char kind[12];                        // ma ja ws pet item input macro ct line hb
  char icon[260];                       // an image file, "" for none
  int nlines; char line[HB_LINES][200]; int wait_ms[HB_LINES];    // line i runs wait_ms[i] after line i-1
  int mp, tp;                           // costs from XIVhotbar2's resource tables (0: none)
  int id, recast_id;                    // (28 Nov) its id and recast_id in XIVhotbar2's resource tables (Windower's), 0: none
  char tip[200];                        // the tooltip's second line
  char source[24];                      // where it came from: hotbar.txt, Root, Base, a job or set name
  char spec[320];                       // (29 Nov) what makes it again (hb_make_spec): "xiv|type|action|target|alias|icon"
                                        // or "line|label|command|icon"; layout mode and /htb set write these
};
// cols: slots in a row (29 Nov; FFXIV's hotbar shapes: 12x1, 6x2, 4x3, 3x4, 2x6, 1x12); vertical is cols == 1 (the old "v").
// shared: the bar's slots are kept for every job (hotbar_slots.txt), not the job's (FFXIV's "shared" hotbars)
struct HbBar { int used, slots, x, y, vertical, cols, shared; HbKey key[HB_SLOTS]; };
struct HbConfig {
  int nbars; HbBar bar[HB_BARS];
  char job[16], sub[16];
  char sets[HB_SETS][32]; int nsets;
  int env;                              // 0 field, 1 battle (the starting one: hotbar.txt's env line)
  char xiv[260];                        // XIVhotbar2's folder (with data/, images/, priv_res/), "" for none
  char windower[260];                   // (29 Nov) Windower's folder (res\monster_abilities.lua), "": the one holding xiv
  int xiv_keys;                         // 1: keys from <xiv>/data/default_keybinds.lua
  HbKey env_key;                        // toggles field/battle
};
// the slots as shown: [env][bar][slot]
struct HbLayout { HbAct a[2][HB_BARS][HB_SLOTS]; };
extern "C" {
// hotbar.txt (and the XIVhotbar2 files it names) into cfg and the layout; err gets the first problem; 0: no hotbar.txt.
// ovr (or NULL): the job, subjob and sets to read instead of hotbar.txt's own ("htb job", "htb set", the game's job).
// Then hotbar_layout.txt (the bars as layout mode left them) and hotbar_slots_<job>.txt (the slots layout mode, the
// picker and /htb set, clear, rename changed, for that job; hotbar_slots.txt with no job), each later file winning.
int hb_read(const char *dir, HbConfig *cfg, HbLayout *lay, char *err, int errlen, char *note, int notelen, const HbConfig *ovr);
// (29 Nov) a slot from its spec (HbAct.spec); 0 if the spec makes nothing runnable
int hb_make_spec(HbAct *a, const char *spec);
// the bars of cfg into hotbar_layout.txt (every bar: "bar ..." or "off N"); 1 written
int hb_save_bars(const char *dir, const HbConfig *cfg);
// one slot of one environment (0 field, 1 battle) for a job ("" none) into its hotbar_slots file: spec, or NULL/""
// to empty the slot; 1 written
int hb_save_slot(const char *dir, const char *job, int env, int bar, int slot, const char *spec);
// The picker's lists (29 Nov), from XIVhotbar2's resource tables (priv_res): tab 0 magic (not trusts), 1 trusts,
// 2 job abilities, 3 weapon skills. Spells and abilities whose tables give levels are listed when the main job
// (number by the game, its short name ens matched in priv_res/jobs.lua) or the subjob has the level; with no job
// known, all. learned (or NULL): the game's learned-spell list (xistate::spell_learned: 1, 0, -1 not come); while it
// has come, spells and trusts are listed as Petit Trois lists them: learned, and (not trusts) a job of the two has the
// spell at some level (action_picker.lua build_actions); before, by the levels as above.
struct HbPick { char name[48], type[8], target[8], group[24], sub[24], icon[260]; int id; };
// (29 Nov) learned(tab, id): the game's lists (xistate: spells by id; job abilities as record id + 0x200; weapon skills
// as record id); 1, 0, -1 not come. Abilities and weapon skills the game lists are listed as they are (no level filter).
int hb_pick_list(int tab, const char *main_job, int main_lv, const char *sub_job, int sub_lv, int (*learned)(int, int), HbPick *out, int max);
// (29 Nov) what XIVhotbar2's tables say of an action, for the tooltip (Petit Trois's text_formatter: name, target,
// description, skillchains, range, MP cost; and cast time and recast from spells.lua). kind ma, ja, pet, ws. 0: not found
struct HbInfo { char name[48], type[24], sc[64], desc[480]; int mp, tp; float range, cast, recast; int id, recast_id; };
int hb_action_info(const char *kind, const char *action, HbInfo *out);
// (29 Nov) skillchains, ported from Petit Trois's lib/skillchains.lua (its rules: hotbar_core.cpp). Times in ms (hb_now_ms).
// hb_sc_action: one 0x028 action (the actor's id, the message's param, the first target's id, its first action's message);
// 1 when a target's properties changed. hb_sc_attempt: properties applied to a target as a weapon skill's would be.
// hb_sc_chain: 1 when the slot's action would make a skillchain on the target now (out: the property and its level).
// hb_sc_burst: 1 when a spell would magic burst (element: the spell's). hb_sc_state: the target's properties, the ms
// left of the chain window and of the burst window.
struct HbChain { char property[16]; int level; };
int hb_sc_action(unsigned actor, unsigned param, unsigned target, int message, unsigned now);
void hb_sc_attempt(unsigned target, const char inc[][16], int ninc, unsigned now);
int hb_sc_chain(unsigned target, const char *kind, const char *action, int chain_affinity, int immanence, unsigned now, HbChain *out);
int hb_sc_burst(unsigned target, const char *kind, const char *action, int burst_affinity, unsigned now, int *element);
int hb_sc_state(unsigned target, unsigned now, char *props, int n, int *window_ms, int *burst_ms);
void hb_sc_reset(void);
// (29 Nov) items. hb_set_inventory: the inventory hotbar.cpp reads from the game (xistate::item), the temporary items then
// the inventory (Petit Trois's order), before hb_read (autoitem slots are made from it). hb_item_id: an item's id by name
// in Windower's res/items.lua. hb_weapon_set: Petit Trois's weapon set name for an item's skill ("Sword"...), "" none.
// hb_set_horizon: Petit Trois's PlayingHorizonXI (priv_res/horizon_spells.lua for the spells). hb_set_learned: the game's
// learned lists (as hb_pick_list's learned), which bstpet slots are made from.
const char *hb_dat_note(void);                                       // what the game's item files gave last (for the log)
void hb_set_horizon(int on);
void hb_set_learned(int (*learned)(int, int));
struct HbInvItem { int id, count; };
void hb_set_inventory(const HbInvItem *items, int n);
int hb_item_id(const char *name);
const char *hb_weapon_set(int item_id);
long long hb_mtime(const char *dir);                                  // hotbar.txt's time and size, 0 without one
int hb_key_down(const HbKey *k);                                      // the key with exactly its modifiers held (polling)
// Key presses from the game window's messages (no system call per frame): the window is subclassed once; each fresh
// WM_KEYDOWN / WM_SYSKEYDOWN (not auto-repeat, not a modifier key) is queued with its modifiers and the stamp() taken
// at that moment (the chat line's text before the WM_CHAR that may follow). hb_msg_next pops one press.
struct HbPress { HbKey key; unsigned stamp; };
int hb_msg_install(void *hwnd, unsigned (*stamp)(void));             // 1: subclassed (or already)
void hb_msg_uninstall(void);
int hb_msg_next(HbPress *out);
long hb_msg_seen(void);                                               // key messages seen since install
int hb_is_foreground(void *hwnd);                                     // the game's window (or a window it owns) has focus
unsigned hb_now_ms(void);
void hb_clock_add(int ms);                                            // (tests) the clock hb_now_ms gives moved on
void hb_copy(char *dst, int n, const char *src);
int hb_write_file(const char *dir, const char *name, const char *text);
int hb_fmt(char *dst, int n, const char *fmt, ...);
int hb_ieq(const char *a, const char *b);                             // equal, ignoring case
// an image file as 32-bit BGRA (straight alpha), w x h, caller frees with hb_image_free; 0 on failure
int hb_image_load(const char *path, int *w, int *h, unsigned **pixels);
void hb_image_free(unsigned *pixels);
}
