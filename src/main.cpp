/*!
 * \file main.cpp
 */

#include <iostream>
#include <string_view>
#include <tuple>

#include "Languages.h"
#include "LoadGame.h"
#include "Quit.h"
#include "Rules.h"
#include "SelectionWrapper.h"
#include "StartGame.h"

auto main(int argc, char* argv[]) -> int {
  const utils::Options options(argc, argv);

  // If user selected -h option, print options descriptions
  // and exit program
  if (options.help_) {
    options.print_help();
    return 0;
  }

  Rules::write(options);

  // Start the game at the begining
  action::StartGame startGame(data::Menu::statementStartGame, options);
  // Load previous game from results.json file
  action::LoadGame loadGame(data::Menu::statementLoadGame, options);
  // Quit the game
  action::Quit quit(data::Menu::statementQuit, data::Menu::resultQuit);

  selection::select(data::Menu::titleStartGameMenu, startGame, loadGame, quit);
}
