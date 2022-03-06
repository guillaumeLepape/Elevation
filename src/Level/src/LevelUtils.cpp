#include "LevelUtils.h"

#include <fmt/core.h>

#include "Languages.h"
#include "Nothing.h"
#include "SaveAndQuit.h"
#include "Selection.h"

void endoflevel() {
  action::Nothing continueAction{data::Menu::statementContinue};
  action::SaveAndQuit quit{data::Menu::statementQuit, data::Menu::resultQuit};

  selection::select(data::Menu::titleContinueMenu, continueAction, quit);

  fmt::print("\n");
}