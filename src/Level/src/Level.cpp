/*!
 * \file Level.cpp
 */

#include "Level.h"

#include "Languages.h"
#include "Nothing.h"
#include "SaveAndQuit.h"
#include "SelectionWrapper.h"
#include "WriteResults.h"

Level::Level(Player& player, ResultsData& resultsData, const Options& options)
    : player_(player), resultsData_(resultsData), options_(options) {}

void Level::endOfLevel() const {
  player_.nextLevel();

  WriteResults writeResults(player_, resultsData_,
                            data::Menu::statementSaveAndQuit,
                            data::Menu::resultSaveAndQuit);
  writeResults.triggerAction();

  Nothing continueAction(data::Menu::statementContinue);
  SaveAndQuit quit(data::Menu::statementQuit, data::Menu::resultQuit);

  SelectionWrapper::select(data::Menu::titleContinueMenu, continueAction, quit);
}