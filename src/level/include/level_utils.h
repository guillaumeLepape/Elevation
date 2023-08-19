#ifndef LEVEL_UTILS_H
#define LEVEL_UTILS_H

#include "languages.h"
#include "nothing.h"
#include "player.h"
#include "save_and_quit.h"
#include "selection.h"

namespace utils::level {
void end() {
  selection::select(
      data::menu::titleContinueMenu,
      action::Nothing{data::menu::statementContinue},
      action::SaveAndQuit{data::menu::statementQuit, data::menu::resultQuit});

  fmt::print("\n");
}
}  // namespace utils::level

#endif
