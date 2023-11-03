#include <iostream>
#include <string_view>
#include <tuple>

#include "elevation/beginning/load_game.h"
#include "elevation/beginning/quit.h"
#include "elevation/beginning/start_game.h"
#include "elevation/data_files/languages.h"
#include "elevation/selection/selection.h"
#include "elevation/writer/rules.h"

using namespace elevation;

auto main(int argc, char* argv[]) -> int {
  const utils::Options options{argc, argv};

  // If user selected -h option, print options descriptions
  // and exit program
  if (options.help()) {
    options.print_help();
    return EXIT_SUCCESS;
  }

  rules::write(options);

  selection::select(
      data::menu::titleStartGameMenu,
      action::StartGame{data::menu::statementStartGame, options},
      action::LoadGame{data::menu::statementLoadGame, options},
      action::Quit{data::menu::statementQuit, data::menu::resultQuit});
}
