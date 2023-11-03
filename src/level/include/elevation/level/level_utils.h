#pragma once

#include "elevation/action/nothing.h"
#include "elevation/action/save_and_quit.h"
#include "elevation/data_files/languages.h"
#include "elevation/entity/player.h"
#include "elevation/selection/selection.h"

namespace utils::level {
void end() {
  selection::select(
      data::menu::titleContinueMenu,
      action::Nothing{data::menu::statementContinue},
      action::SaveAndQuit{data::menu::statementQuit, data::menu::resultQuit});

  fmt::print("\n");
}
}  // namespace utils::level
