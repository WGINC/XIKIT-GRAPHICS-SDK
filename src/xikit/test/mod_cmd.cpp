// mod_cmd.cpp -- test_xikit.py's "toolhook" runs (host.c): a mod with one chat command (/xtcmd) through xikit_cmd.hpp,
// installed while another tool's jump is already at Command_RunLine's entry (host.c fake_tool_form, XT_TOOL_FORM).
#include "xikit_sdk.hpp"
#include "xikit_cmd.hpp"
XIKIT_MOD_GLOBALS
XIKIT_MOD_INFO("mod_cmd", "1", 5, "the toolhook test's chat command")
extern "C" {
__declspec(dllexport) volatile long cmd_install = -99, cmd_seen;
static void on_cmd(const char *args) { (void)args; cmd_seen++; }
__declspec(dllexport) int xikit_mod_init(const XikitHost *host) {
  xicmd::add("xtcmd", on_cmd);
  cmd_install = xicmd::install(host);
  return 0;
}
}
