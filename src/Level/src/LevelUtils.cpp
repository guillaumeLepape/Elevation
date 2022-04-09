#include "LevelUtils.h"

#include <fmt/core.h>

#include "Languages.h"
#include "Nothing.h"
#include "SaveAndQuit.h"
#include "Selection.h"

void endoflevel() {
  action::Nothing continueAction{data::menu::statementContinue};
  action::SaveAndQuit quit{data::menu::statementQuit, data::menu::resultQuit};

  selection::select(data::menu::titleContinueMenu, continueAction, quit);

  fmt::print("\n");
}