/*!
 * \file Level.cpp
 */

#include "Level.h"

#include "Languages.h"
#include "Nothing.h"
#include "SaveAndQuit.h"
#include "Selection.h"
#include "WriteResults.h"

Level::Level(Player* const player, ResultsData* const resultsData,
             const Options& options)
    : player_(player), resultsData_(resultsData), options_(options) {}

void Level::endOfLevel() const {
  player_->nextLevel();

  WriteResults writeResults(player_, resultsData_,
                            data::Menu::statementSaveAndQuit,
                            data::Menu::resultSaveAndQuit);
  writeResults.triggerAction();

  Nothing continueAction(data::Menu::statementContinue);
  SaveAndQuit quit(data::Menu::statementQuit, data::Menu::resultQuit);

  auto result = Select::select(data::Menu::titleContinueMenu,
                               {continueAction.statement(), quit.statement()});

  switch (result) {
    case 0:
      break;
    case 1:
      quit.triggerAction();
      break;
  }
}