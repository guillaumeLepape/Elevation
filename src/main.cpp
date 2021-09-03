/*!
 * \file main.cpp
 */

#include <iostream>
#include <string_view>

#include "Languages.h"
#include "LoadGame.h"
#include "Quit.h"
#include "Rules.h"
#include "Selection.h"
#include "StartGame.h"

int main(int argc, char* argv[]) {
  const Options options(argc, argv);

  // If user selected -h option, print options descriptions
  // and exit program
  if (options.help_) {
    options.print_help();
    return 0;
  }

  Rules::displayRules(options);

  // // Start the game at the begining
  StartGame startGame(data::Menu::statementStartGame, options);
  // // Load previous game from results.json file
  LoadGame loadGame(data::Menu::statementLoadGame, options);
  // // Quit the game
  Quit quit(data::Menu::statementQuit, data::Menu::resultQuit);

  auto result = Select::select(
      data::Menu::titleStartGameMenu,
      {startGame.statement(), loadGame.statement(), quit.statement()});

  switch (result) {
    case 0:
      startGame.triggerAction();
      break;
    case 1:
      loadGame.triggerAction();
      break;
    case 2:
      quit.triggerAction();
      break;
  }

  return 0;
}
