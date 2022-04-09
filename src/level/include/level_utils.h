#ifndef LEVEL_UTILS_H
#define LEVEL_UTILS_H

#include "languages.h"
#include "nothing.h"
#include "player.h"
#include "save_and_quit.h"
#include "selection.h"

namespace utils::level {
void end() {
  action::Nothing continueAction{data::menu::statementContinue};
  action::SaveAndQuit quit{data::menu::statementQuit, data::menu::resultQuit};

  selection::select(data::menu::titleContinueMenu, continueAction, quit);

  fmt::print("\n");
}
}  // namespace utils::level

#endif