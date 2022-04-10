#include <iostream>
#include <string_view>
#include <tuple>

#include "languages.h"
#include "load_game.h"
#include "quit.h"
#include "rules.h"
#include "selection.h"
#include "start_game.h"

auto main(int argc, char* argv[]) -> int {
  const utils::Options options{argc, argv};

  // If user selected -h option, print options descriptions
  // and exit program
  if (options.help_) {
    options.print_help();
    return 0;
  }

  rules::write(options);

  selection::select(
      data::menu::titleStartGameMenu,
      action::StartGame{data::menu::statementStartGame, options},
      action::LoadGame{data::menu::statementLoadGame, options},
      action::Quit{data::menu::statementQuit, data::menu::resultQuit});
}
