# What stays the same between kit versions

There are two parts. The first is what the kit's code guarantees, with where it is enforced. The second is a policy
for what the code cannot enforce: it is proposed, and the project's owner has not yet confirmed it.

## Guaranteed by the code

- **The interface layout.** `XikitHost` only ever gains fields at its end. No field moves or changes type.
  `xikit_mod.h` checks the layout of release 1 at compile time (`XIKIT_ABI_ASSERT`), in every mod and in the kit.
- **New fields are detected, not assumed.** A mod uses a field only when `host->size` reaches past it. A call the kit
  is too old for answers `XIKIT_E_OLDKIT`; `XI_DEVICE_HOOK` checks this for the mod.
- **A mod built for a newer kit does not start on an older one** when it declares `XIKIT_MOD_INFO` with the API it
  needs (kit API 5 and later). The log says why.
- **The exports** (`xikit_mod_init`, `xikit_mod_frame`, `xikit_mod_settings`, `xikit_mod_unload`, `xi_rel`,
  `xi_shift`, `xikit_mod_info`) and **the result codes** keep their names and meanings. A code's meaning can widen, as
  `XIKIT_E_TAKEN` did with hook chains (version 5); the kit's version says which meaning applies.
- **Game builds.** A function is hooked by name or by its analysed address (build 6A995428). On another build, the kit
  translates through that build's manifest. A mod built with `XIKIT_MOD_GLOBALS` gets its addresses translated too.
  On a build the kit does not know, it changes nothing and the log says so.

## Not guaranteed

- **The game's headers** (`sdk/tree_include`) are the reconstruction's current reading of the game. A later release
  can name a field that was unnamed, correct a type, or split a class. A mod that compiled against one release may need
  small edits to compile against the next. What it does in the game does not change: the game's code is the same.
- **What a function is called.** Names come from the evidence the analysis has. A better name can replace a generic
  one (`sub_...`, `Slot244_Unknown`). Hook by address (`"0x1015F6A0"`) if a mod must not depend on a name.
- **xikit_ui.hpp** is header-only: a mod carries the version it was built with. A fact found wrong is fixed in the next
  release, and the mod picks the fix up when it is rebuilt.

## Proposed policy (not yet confirmed by the owner)

- A name that changes keeps its old spelling as an alias for one release, listed in the release notes.
- Each release's notes list every header change that can break a build, with the edit it needs.
- A new game build is supported by a new manifest in a kit update, not by a new SDK. Mods are not rebuilt for it.
