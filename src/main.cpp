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

  // Start the game at the begining
  action::StartGame startGame{data::menu::statementStartGame, options};
  // Load previous game from results.json file
  action::LoadGame loadGame{data::menu::statementLoadGame, options};
  // Quit the game
  action::Quit quit{data::menu::statementQuit, data::menu::resultQuit};

  selection::select(data::menu::titleStartGameMenu, startGame, loadGame, quit);
}
