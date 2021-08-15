/*!
 * \file main.cpp
 */

#include <iostream>

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
  StartGame startGame(data::Menu::statementStartGame,
                      data::Menu::resultStartGame, options);
  // // Load previous game from results.json file
  LoadGame loadGame(data::Menu::statementLoadGame, data::Menu::resultLoadGame,
                    options);
  // // Quit the game
  Quit quit(data::Menu::statementQuit, data::Menu::resultLoadGame);

  Selection::select({&startGame, &loadGame, &quit},
                    data::Menu::titleStartGameMenu);

  return 0;
}
