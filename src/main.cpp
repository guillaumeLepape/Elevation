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

int main(int argc, char* argv[]) {
  const Options options(argc, argv);

  // If user selected -h option, print options descriptions
  // and exit program
  if (options.help_) {
    options.print_help();
    return 0;
  }

  Rules::write(options);

  // // Start the game at the begining
  StartGame startGame(data::Menu::statementStartGame, options);
  // // Load previous game from results.json file
  LoadGame loadGame(data::Menu::statementLoadGame, options);
  // // Quit the game
  Quit quit(data::Menu::statementQuit, data::Menu::resultQuit);

  SelectionWrapper::select(data::Menu::titleStartGameMenu, startGame, loadGame,
                           quit);

  return 0;
}
