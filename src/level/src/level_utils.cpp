#include "level_utils.h"

#include <fmt/core.h>

#include "languages.h"
#include "nothing.h"
#include "save_and_quit.h"
#include "selection.h"

void endoflevel() {
  action::Nothing continueAction{data::menu::statementContinue};
  action::SaveAndQuit quit{data::menu::statementQuit, data::menu::resultQuit};

  selection::select(data::menu::titleContinueMenu, continueAction, quit);

  fmt::print("\n");
}